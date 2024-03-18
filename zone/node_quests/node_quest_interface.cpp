
#include <ctype.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <future>
#include <thread>
#include <chrono>

#include "node_runtime.h"
#include "node_quest_interface.h"
#include "../common/spdat.h"
#include "masterentity.h"
#include "questmgr.h"
#include "zone.h"
#include "zone_config.h"

extern Zone *zone;

std::unique_ptr<NodeRuntime> node_runtime = nullptr;

NodeParser::NodeParser()
{
}

NodeParser::~NodeParser()
{
}

void NodeParser::StopAndJoin()
{
    if (node_runtime->GetIsRunning())
    {
        node_runtime->StopExecution();
        runtime_thread.join();
    }
}

void NodeParser::NodeLoad()
{
    if (!zone) {
        return;
    }
    std::string quest_entrypoint = fmt::format(
        "node_quests/quest_entrypoint.js",
        path.GetQuestsPath());
    if (node_runtime != nullptr)
    {
        node_runtime->Reload();
    }
    else
    {
        node_runtime = std::make_unique<NodeRuntime>(this);
        node_runtime->Init();
        std::promise<void> shutdownPromise;
        std::future<void> shutdownFuture = shutdownPromise.get_future();

        runtime_thread = std::thread([quest_entrypoint](std::promise<void> shutdownPromise)
                                        {
                                        node_runtime->ModuleLoad(quest_entrypoint); 
                                        shutdownPromise.set_value(); },
                                        std::move(shutdownPromise));
    }
}

int NodeParser::EventNPC(QuestEventID evt, NPC *npc, Mob *init, std::string data, uint32 extra_data,
                         std::vector<std::any> *extra_pointers)
{

    std::string package_name = "npc_" + std::to_string(npc->GetNPCTypeID());
    return _EventNPC(package_name, evt, npc, init, data, extra_data, extra_pointers);
}

int NodeParser::EventGlobalNPC(QuestEventID evt, NPC *npc, Mob *init, std::string data, uint32 extra_data,
                               std::vector<std::any> *extra_pointers)
{
    return _EventNPC("global_npc", evt, npc, init, data, extra_data, extra_pointers);
}

int NodeParser::_EventNPC(std::string package_name, QuestEventID evt, NPC *npc, Mob *init, std::string data, uint32 extra_data,
                          std::vector<std::any> *extra_pointers)
{

    Client *c = (init && init->IsClient()) ? init->CastToClient() : nullptr;

    quest_manager.StartQuest(npc, c);
    node_runtime->OnNpcEvent(evt, npc, init, data);
    quest_manager.EndQuest();

    return 0;
}

int NodeParser::EventPlayer(QuestEventID evt, Client *client, std::string data, uint32 extra_data,
                            std::vector<std::any> *extra_pointers)
{

    return _EventPlayer("player", evt, client, data, extra_data, extra_pointers);
}

int NodeParser::EventGlobalPlayer(QuestEventID evt, Client *client, std::string data, uint32 extra_data,
                                  std::vector<std::any> *extra_pointers)
{

    return _EventPlayer("global_player", evt, client, data, extra_data, extra_pointers);
}

int NodeParser::_EventPlayer(std::string package_name, QuestEventID evt, Client *client, std::string data, uint32 extra_data,
                             std::vector<std::any> *extra_pointers)
{

    quest_manager.StartQuest(client, client);
    quest_manager.EndQuest();

    return 0;
}

int NodeParser::EventItem(QuestEventID evt, Client *client, EQ::ItemInstance *item, Mob *mob, std::string data, uint32 extra_data,
                          std::vector<std::any> *extra_pointers)
{
    std::string package_name = "item_";
    package_name += std::to_string(item->GetID());
    return _EventItem(package_name, evt, client, item, mob, data, extra_data, extra_pointers);
}

int NodeParser::_EventItem(std::string package_name, QuestEventID evt, Client *client, EQ::ItemInstance *item, Mob *mob,
                           std::string data, uint32 extra_data, std::vector<std::any> *extra_pointers)
{

    quest_manager.StartQuest(client, client, item);
    quest_manager.EndQuest();

    return 0;
}

int NodeParser::EventSpell(QuestEventID evt, Mob *mob, Client *client, uint32 spell_id, std::string data, uint32 extra_data,
                           std::vector<std::any> *extra_pointers)
{

    std::string package_name = "spell_" + std::to_string(spell_id);
    return _EventSpell(package_name, evt, mob, client, spell_id, data, extra_data, extra_pointers);
}

int NodeParser::_EventSpell(std::string package_name, QuestEventID evt, Mob *mob, Client *client, uint32 spell_id, std::string data, uint32 extra_data,
                            std::vector<std::any> *extra_pointers)
{

    quest_manager.StartQuest(mob, client, nullptr, const_cast<SPDat_Spell_Struct *>(&spells[spell_id]));
    quest_manager.EndQuest();
    return 0;
}

int NodeParser::EventEncounter(QuestEventID evt, std::string encounter_name, std::string data, uint32 extra_data, std::vector<std::any> *extra_pointers)
{
    std::string package_name = "encounter_" + encounter_name;
    return _EventEncounter(package_name, evt, encounter_name, data, extra_data, extra_pointers);
}

int NodeParser::_EventEncounter(std::string package_name, QuestEventID evt, std::string encounter_name, std::string data, uint32 extra_data,
                                std::vector<std::any> *extra_pointers)
{

    // quest_manager.StartQuest(enc, nullptr, nullptr, nullptr, encounter_name);

    // quest_manager.EndQuest();

    return 0;
}

bool NodeParser::HasQuestSub(uint32 npc_id, QuestEventID evt)
{
    return true;
}

bool NodeParser::HasGlobalQuestSub(QuestEventID evt)
{
    return true;
}

bool NodeParser::PlayerHasQuestSub(QuestEventID evt)
{
    return true;
}

bool NodeParser::GlobalPlayerHasQuestSub(QuestEventID evt)
{
    return true;
}

bool NodeParser::SpellHasQuestSub(uint32 spell_id, QuestEventID evt)
{
    return true;
}

bool NodeParser::ItemHasQuestSub(EQ::ItemInstance *itm, QuestEventID evt)
{
    return true;
}

bool NodeParser::EncounterHasQuestSub(std::string encounter_name, QuestEventID evt)
{
    return true;
}

void NodeParser::LoadNPCScript(std::string filename, int npc_id)
{
    std::string package_name = "npc_" + std::to_string(npc_id);

    LoadScript(filename, package_name);
}

void NodeParser::LoadGlobalNPCScript(std::string filename)
{
    LoadScript(filename, "global_npc");
}

void NodeParser::LoadPlayerScript(std::string filename)
{
    LoadScript(filename, "player");
}

void NodeParser::LoadGlobalPlayerScript(std::string filename)
{
    LoadScript(filename, "global_player");
}

void NodeParser::LoadItemScript(std::string filename, EQ::ItemInstance *item)
{
    if (item == nullptr)
        return;
    std::string package_name = "item_";
    package_name += std::to_string(item->GetID());

    LoadScript(filename, package_name);
}

void NodeParser::LoadSpellScript(std::string filename, uint32 spell_id)
{
    std::string package_name = "spell_" + std::to_string(spell_id);

    LoadScript(filename, package_name);
}

void NodeParser::LoadEncounterScript(std::string filename, std::string encounter_name)
{
    std::string package_name = "encounter_" + encounter_name;

    LoadScript(filename, package_name);
}

void NodeParser::AddVar(std::string name, std::string val)
{
    vars_[name] = val;
}

std::string NodeParser::GetVar(std::string name)
{
    auto iter = vars_.find(name);
    if (iter != vars_.end())
    {
        return iter->second;
    }

    return std::string();
}

void NodeParser::Init()
{
    ReloadQuests();
}

void NodeParser::ReloadQuests()
{
    this->NodeLoad();
}

void NodeParser::RemoveEncounter(const std::string &name)
{
}

void NodeParser::LoadScript(std::string filename, std::string package_name)
{
}

bool NodeParser::HasFunction(std::string subname, std::string package_name)
{
    // std::transform(subname.begin(), subname.end(), subname.begin(), ::tolower);

    auto iter = loaded_.find(package_name);
    if (iter == loaded_.end())
    {
        return false;
    }

    return false;
}

bool NodeParser::HasEncounterSub(const std::string &package_name, QuestEventID evt)
{

    return false;
}

int NodeParser::DispatchEventNPC(QuestEventID evt, NPC *npc, Mob *init, std::string data, uint32 extra_data,
                                 std::vector<std::any> *extra_pointers)
{

    if (!npc)
        return 0;

    std::string package_name = "npc_" + std::to_string(npc->GetNPCTypeID());
    int ret = 0;

    return ret;
}

int NodeParser::DispatchEventPlayer(QuestEventID evt, Client *client, std::string data, uint32 extra_data,
                                    std::vector<std::any> *extra_pointers)
{

    std::string package_name = "player";

    int ret = 0;

    return ret;
}

int NodeParser::DispatchEventItem(QuestEventID evt, Client *client, EQ::ItemInstance *item, Mob *mob, std::string data, uint32 extra_data,
                                  std::vector<std::any> *extra_pointers)
{
    if (!item)
        return 0;

    std::string package_name = "item_";
    package_name += std::to_string(item->GetID());
    int ret = 0;
    return ret;
}

int NodeParser::DispatchEventSpell(QuestEventID evt, Mob *mob, Client *client, uint32 spell_id, std::string data, uint32 extra_data,
                                   std::vector<std::any> *extra_pointers)
{

    std::string package_name = "spell_" + std::to_string(spell_id);

    int ret = 0;
    return ret;
}

int NodeParser::EventBot(
    QuestEventID evt,
    Bot *bot,
    Mob *init,
    std::string data,
    uint32 extra_data,
    std::vector<std::any> *extra_pointers)
{

    if (!bot)
    {
        return 0;
    }

    if (!BotHasQuestSub(evt))
    {
        return 0;
    }

    return _EventBot("bot", evt, bot, init, data, extra_data, extra_pointers);
}

int NodeParser::EventGlobalBot(
    QuestEventID evt,
    Bot *bot,
    Mob *init,
    std::string data,
    uint32 extra_data,
    std::vector<std::any> *extra_pointers)
{

    if (!bot)
    {
        return 0;
    }

    if (!GlobalBotHasQuestSub(evt))
    {
        return 0;
    }

    return _EventBot("global_bot", evt, bot, init, data, extra_data, extra_pointers);
}

int NodeParser::_EventBot(
    std::string package_name,
    QuestEventID evt,
    Bot *bot,
    Mob *init,
    std::string data,
    uint32 extra_data,
    std::vector<std::any> *extra_pointers)
{
    auto *c = (init && init->IsClient()) ? init->CastToClient() : nullptr;
    quest_manager.StartQuest(bot, c);
    quest_manager.EndQuest();

    return 0;
}

int NodeParser::DispatchEventBot(
    QuestEventID evt,
    Bot *bot,
    Mob *init,
    std::string data,
    uint32 extra_data,
    std::vector<std::any> *extra_pointers)
{

    return 0;
}

bool NodeParser::BotHasQuestSub(QuestEventID evt)
{

    return false;
}

bool NodeParser::GlobalBotHasQuestSub(QuestEventID evt)
{
    return false;
}

void NodeParser::LoadBotScript(std::string filename)
{
    LoadScript(filename, "bot");
}

void NodeParser::LoadGlobalBotScript(std::string filename)
{
    LoadScript(filename, "global_bot");
}

extern "C" NODE_QUEST_API_DECL(NodeParser *) GetNodeParserInstance()
{
    const auto &inst = NodeParser::Instance();
    return inst;
};