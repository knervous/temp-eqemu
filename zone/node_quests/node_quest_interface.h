#ifndef _EQE_NODE_PARSER_H
#define _EQE_NODE_PARSER_H

#include <thread>
#include <chrono>
#include <string>
#include <list>
#include <map>
#include <exception>

#include "../quest_parser_collection.h"
#include "../quest_interface.h"
#include "../zone_config.h"

#ifdef _WIN32
#ifdef NODE_QUEST_EXPORT
#define NODE_QUEST_API_DECL(returnvalue) __declspec(dllexport) returnvalue
#define NODE_QUEST_API_EXT_CLASS __declspec(dllexport)
#else
#define NODE_QUEST_API_DECL(returnvalue) __declspec(dllimport) returnvalue
#define NODE_QUEST_API_EXT_CLASS __declspec(dllimport)
#endif
#else
#define NODE_QUEST_API_DECL(returnvalue) returnvalue
#define NODE_QUEST_API_EXT_CLASS
#endif

extern const ZoneConfig *Config;

class Client;
class NPC;

namespace EQ
{
    class ItemInstance;
}

struct npc_event {
    int event;
    NPC* npc;
    Mob* mob;
    std::string data;
};

class NODE_QUEST_API_EXT_CLASS NodeParser : public QuestInterface
{
public:
    ~NodeParser();

    virtual int EventNPC(
        QuestEventID evt,
        NPC *npc,
        Mob *init,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int EventGlobalNPC(
        QuestEventID evt,
        NPC *npc,
        Mob *init,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int EventPlayer(
        QuestEventID evt,
        Client *client,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int EventGlobalPlayer(
        QuestEventID evt,
        Client *client,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int EventItem(
        QuestEventID evt,
        Client *client,
        EQ::ItemInstance *item,
        Mob *mob,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int EventSpell(
        QuestEventID evt,
        Mob *mob,
        Client *client,
        uint32 spell_id,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int EventEncounter(
        QuestEventID evt,
        std::string encounter_name,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int EventBot(
        QuestEventID evt,
        Bot *bot,
        Mob *init,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int EventGlobalBot(
        QuestEventID evt,
        Bot *bot,
        Mob *init,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);

    virtual bool HasQuestSub(uint32 npc_id, QuestEventID evt);
    virtual bool HasGlobalQuestSub(QuestEventID evt);
    virtual bool PlayerHasQuestSub(QuestEventID evt);
    virtual bool GlobalPlayerHasQuestSub(QuestEventID evt);
    virtual bool SpellHasQuestSub(uint32 spell_id, QuestEventID evt);
    virtual bool ItemHasQuestSub(EQ::ItemInstance *itm, QuestEventID evt);
    virtual bool EncounterHasQuestSub(std::string encounter_name, QuestEventID evt);
    virtual bool HasEncounterSub(const std::string &package_name, QuestEventID evt);
    virtual bool BotHasQuestSub(QuestEventID evt);
    virtual bool GlobalBotHasQuestSub(QuestEventID evt);

    virtual void LoadNPCScript(std::string filename, int npc_id);
    virtual void LoadGlobalNPCScript(std::string filename);
    virtual void LoadPlayerScript(std::string filename);
    virtual void LoadGlobalPlayerScript(std::string filename);
    virtual void LoadItemScript(std::string filename, EQ::ItemInstance *item);
    virtual void LoadSpellScript(std::string filename, uint32 spell_id);
    virtual void LoadEncounterScript(std::string filename, std::string encounter_name);
    virtual void LoadBotScript(std::string filename);
    virtual void LoadGlobalBotScript(std::string filename);

    virtual void AddVar(std::string name, std::string val);
    virtual std::string GetVar(std::string name);
    virtual void Init();
    virtual void ReloadQuests();
    virtual void RemoveEncounter(const std::string &name);
    virtual uint32 GetIdentifier() { return 0xb0712acc; }

    virtual int DispatchEventNPC(
        QuestEventID evt,
        NPC *npc,
        Mob *init,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int DispatchEventPlayer(
        QuestEventID evt,
        Client *client,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int DispatchEventItem(
        QuestEventID evt,
        Client *client,
        EQ::ItemInstance *item,
        Mob *mob,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int DispatchEventSpell(
        QuestEventID evt,
        Mob *mob,
        Client *client,
        uint32 spell_id,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    virtual int DispatchEventBot(
        QuestEventID evt,
        Bot *bot,
        Mob *init,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);

    static NodeParser *Instance()
    {
        static NodeParser inst;
        return &inst;
    }

    bool HasFunction(std::string function, std::string package_name);
    void NodeLoad();

private:

    NodeParser();
    NodeParser(const NodeParser &);
    NodeParser &operator=(const NodeParser &);

    void StopAndJoin();

    void NodeEval() {}

    void NodeStop()
    {
        StopAndJoin();
    }

    int _EventNPC(
        std::string package_name,
        QuestEventID evt,
        NPC *npc,
        Mob *init,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    int _EventPlayer(
        std::string package_name,
        QuestEventID evt,
        Client *client,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    int _EventItem(
        std::string package_name,
        QuestEventID evt,
        Client *client,
        EQ::ItemInstance *item,
        Mob *mob,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    int _EventSpell(
        std::string package_name,
        QuestEventID evt,
        Mob *mob,
        Client *client,
        uint32 spell_id,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    int _EventEncounter(
        std::string package_name,
        QuestEventID evt,
        std::string encounter_name,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);
    int _EventBot(
        std::string package_name,
        QuestEventID evt,
        Bot *bot,
        Mob *init,
        std::string data,
        uint32 extra_data,
        std::vector<std::any> *extra_pointers);

    void LoadScript(std::string filename, std::string package_name);

    std::map<std::string, std::string> vars_;
    std::map<std::string, bool> loaded_;

    std::thread runtime_thread;
};

extern "C" NODE_QUEST_API_DECL(NodeParser*) GetNodeParserInstance();

#endif