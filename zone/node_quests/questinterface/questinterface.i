



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

%include typemaps.swg

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
#include "../../common.h"
#include "../../entity.h"
#include "../../mob.h"
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
#include "../../quest_interface.h"
#include "../../quest_parser_collection.h"
#include "../node_quest_interface.h"
%}

%include "../../../common/ruletypes.h"
%include "../../../common/expedition_lockout_timer.h"
%include "../../common.h"
%include "../../entity.h"
%include "../../mob.h"
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
%include "../../quest_interface.h"
%include "../../quest_parser_collection.h"
%include "../node_quest_interface.h"
%include "../../../common/linked_list.h"

%template(LinkedListNewSpawn) LinkedList<NewSpawn_Struct*>;

