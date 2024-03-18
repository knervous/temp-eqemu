



%module questinterface

%ignore Mob::GetSeeInvisibleLevelFromNPCStat;
%ignore Raid::RemoveGroupLeader;
%ignore Trap::SpellOnTarget;
%ignore Group::SendWorldGroup;
%ignore Client::GetEXPModifiers;
%ignore Client::SetEXPModifiers;
%ignore Client::SendTaskComplete;
%ignore Client::Flurry;
%ignore Client::WhoAll;
%ignore Client::Rampage;
%ignore Client::LoadSpellGroupCache;
%ignore Zone::GetAuth;
%ignore Zone::aa_abilities;
%ignore Zone::aa_ranks;
%ignore Zone::ldon_trap_list;
%ignore Zone::ldon_trap_entry_list;
%ignore Zone::merc_templates;
%ignore Zone::merchanttable;
%ignore Zone::merc_spells_list;
%ignore Zone::merc_stance_list;
%ignore Zone::tmpmerchanttable;
%ignore Zone::adventure_entry_list_flavor;
%ignore Zone::GetAlternateAdvancementAbilityAndRank;
%ignore Zone::expedition_cache;
%ignore Zone::dynamic_zone_cache;
%ignore Zone::dz_template_cache;
%ignore NPC::AIautocastspell_timer;
%ignore ZoneDatabase::AddLootTableToNPC;
%ignore ZoneDatabase::AddLootDropToNPC;
%ignore ZoneDatabase::GetServerFilters;
%ignore ZoneDatabase::SetServerFilters;
%ignore QuestEventSubroutines;

%ignore ListElement::ListElement();

%ignore ListElement::ListElement(const NewSpawn_Struct*&);
%ignore ListElement::ListElement(const Spawn2*&);
%ignore ListElement::ListElement(const ZonePoint*&);

%ignore ListElement::ListElement(const ListElement<NewSpawn_Struct*>&);
%ignore ListElement::ListElement(const ListElement<Spawn2*>&);
%ignore ListElement::ListElement(const ListElement<ZonePoint*>&);

// %include typemaps.swg

%{
#include <string>
#include <list>
#include <any>
#include <set>
#include <vector>
#include <memory>
#undef EMBPERL
#undef LUA_EQEMU
#undef USE_PERL_SWITCH_LOCALE_CONTEXT
#include "../../../common/ruletypes.h"
#include "../../../common/expedition_lockout_timer.h"
#include "../../../common/timer.h"
#include "../../../common/linked_list.h"
//#include "../../../common/emu_constants.h"

#include "../../common.h"
#include "../../entity.h"
#include "../../mob.h"
#include "../../event_codes.h"
#include "../../npc.h"
#include "../../encounter.h"
#include "../../beacon.h"
#include "../../zone.h"
#include "../../client.h"
#include "../../corpse.h"
#include "../../doors.h"
#include "../../groups.h"
#include "../../object.h"
#include "../../raids.h"
#include "../../trap.h"
#include "../../spawn2.h"
#include "../../spawngroup.h"
#include "../../zonedb.h"

%}


%include <std_list.i>
%include <std_vector.i>
%include <std_unordered_map.i>
%include <std_shared_ptr.i>


%include "../../../common/ruletypes.h"
%include "../../../common/expedition_lockout_timer.h"
%include "../../../common/linked_list.h"
//%include "../../../common/emu_constants.h"

%include "../../common.h"
%include "../../entity.h"
%include "../../mob.h"
%include "../../event_codes.h"
%include "../../npc.h"
%include "../../encounter.h"
%include "../../beacon.h"
%include "../../client.h"
%include "../../corpse.h"
%include "../../doors.h"
%include "../../groups.h"
%include "../../object.h"
%include "../../raids.h"
%include "../../trap.h"
%include "../../zone.h"
%include "../../spawn2.h"
%include "../../spawngroup.h"
%include "../../zonedb.h"

// Typedefs
%include <stdint.i>

typedef uint8_t byte;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

%template(LinkedListNewSpawn) LinkedList<NewSpawn_Struct*>;
%template(LinkedListSpawn2) LinkedList<Spawn2*>;
%template(LinkedListZonePoint) LinkedList<ZonePoint*>;

%template(LinkedListElementNewSpawn) ListElement<NewSpawn_Struct*>;
%template(LinkedListElementSpawn2) ListElement<Spawn2*>;
%template(LinkedListElementZonePoint) ListElement<ZonePoint*>;

%extend ListElement<Spawn2*> {
    Spawn2* GetObject() {
        return $self->GetData();
    }
}

%extend ListElement<NewSpawn_Struct*> {
    NewSpawn_Struct* GetObject() {
        return $self->GetData();
    }
}

%template(IntVector) std::vector<int>;
%template(DoubleVector) std::vector<double>;

%template(IntList) std::list<int>;
%template(DoubleList) std::list<double>;
%template(AltCurrencyDefinitionList) std::list<AltCurrencyDefinition_Struct>;
%template(InternalVeteranRewardList) std::list<InternalVeteranReward>;

%template(IntStringMap) std::unordered_map<int, std::string>;
%template(IntDoubleMap) std::unordered_map<int, double>;
%template(IntExpModifierMap) std::unordered_map<unsigned int, EXPModifier>;
%template(IntNpcMap) std::unordered_map<unsigned int, NPCType*>;
%template(IntClientMap) std::unordered_map<unsigned short, Client*>;
%template(IntMobMap) std::unordered_map<unsigned short, Mob *>;
%template(IntNpcMap2) std::unordered_map<unsigned short, NPC *>;
%template(IntMercMap) std::unordered_map<unsigned short, Merc *>;
%template(IntCorpseMap) std::unordered_map<unsigned short, Corpse *>;
%template(IntObjectMap) std::unordered_map<unsigned short, Object *>;
%template(IntDoorMap) std::unordered_map<unsigned short, Doors *>;
%template(IntTrapMap) std::unordered_map<unsigned short, Trap *>;
%template(IntBeaconMap) std::unordered_map<unsigned short, Beacon *>;
%template(IntEncounterMap) std::unordered_map<unsigned short, Encounter *>;
%template(ProximityList) std::list<NPC *>;
%template(GroupList) std::list<Group *>;
%template(RaidList) std::list<Raid *>;
%template(AreaList) std::list<Area>;