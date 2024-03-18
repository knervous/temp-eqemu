#include "dotnet_quest_interface.h"

int npc_event(QuestEventID event, NPC *npc, Mob *init, std::string data);
int initialize(Zone* zone, EntityList* entity_list);
int reload_quests();