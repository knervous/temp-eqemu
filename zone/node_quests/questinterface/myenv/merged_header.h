/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2016 EQEMu Development Team (http://eqemulator.org)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef RULE_CATEGORY
#define RULE_CATEGORY(name)
#endif
#ifndef RULE_INT
#define RULE_INT(cat, rule, default_value, notes)
#endif
#ifndef RULE_REAL
#define RULE_REAL(cat, rule, default_value, notes)
#endif
#ifndef RULE_BOOL
#define RULE_BOOL(cat, rule, default_value, notes)
#endif
#ifndef RULE_CATEGORY_END
#define RULE_CATEGORY_END()
#endif




RULE_CATEGORY(Character)
RULE_INT(Character, MaxLevel, 65, "Sets the highest level for players that can be reached through experience")
RULE_BOOL(Character, PerCharacterQglobalMaxLevel, false, "Check for qglobal 'CharMaxLevel' character qglobal (Type 5, \"\"), if player tries to level beyond that point, it will not go beyond that level")
RULE_BOOL(Character, PerCharacterBucketMaxLevel, false, "Check for data bucket 'CharMaxLevel', if player tries to level beyond that point, it will not go beyond that level")
RULE_INT(Character, MaxExpLevel, 0, "Defines the maximum level that can be reached through experience")
RULE_INT(Character, DeathExpLossLevel, 10, "Any level equal to or greater than this will lose experience at death")
RULE_INT(Character, DeathExpLossMaxLevel, 255, "Every higher level will no longer lose experience at death")
RULE_INT(Character, DeathItemLossLevel, 10, "From this level on, items are left in the corpse when LeaveCorpses is activated")
RULE_INT(Character, DeathExpLossMultiplier, 3, "Adjust how much experience is lost. Default 3.5% (0=0.5%, 1=1.5%, 2=2.5%, 3=3.5%, 4=4.5%, 5=5.5%, 6=6.5%, 7=7.5%, 8=8.5%, 9=9.5%, 10=11%)")
RULE_BOOL(Character, DeathKeepLevel, false, "Players can not drop below 0% experience from death.")
RULE_BOOL(Character, UseDeathExpLossMult, false, "Setting to control whether DeathExpLossMultiplier or the code default is used: (Level x Level / 18.0) x 12000")
RULE_BOOL(Character, UseOldRaceRezEffects, false, "Older clients had ID 757 for races with high starting STR, but it doesn't seem used anymore")
RULE_INT(Character, CorpseDecayTime, 604800000, "Time after which the corpse decays (milliseconds) DEFAULT: 604800000 (7 Days)")
RULE_INT(Character, EmptyCorpseDecayTime, 10800000, "Time after which an empty corpse decays (milliseconds) DEFAULT: 10800000 (3 Hours)")
RULE_INT(Character, CorpseResTime, 10800000, "Time after which the corpse can no longer be resurrected (milliseconds) DEFAULT: 10800000 (3 Hours)")
RULE_INT(Character, DuelCorpseResTime, 600000, "Time before cant res corpse after a duel (milliseconds) DEFAULT: 600000 (10 Minutes)")
RULE_INT(Character, CorpseOwnerOnlineTime, 30000, "How often corpse will check if its owner is online DEFAULT: 30000 (30 Seconds)")
RULE_BOOL(Character, LeaveCorpses, true, "Setting whether you leave a corpse behind")
RULE_BOOL(Character, LeaveNakedCorpses, false, "Setting whether you leave a corpse without items")
RULE_INT(Character, MaxDraggedCorpses, 2, "Maximum number of corpses you can drag at once")
RULE_REAL(Character, DragCorpseDistance, 400, "If a player is using /corpsedrag and moving, the corpse will not move until the player exceeds this distance")
RULE_REAL(Character, FinalExpMultiplier, 1, "Added on top of everything else, easy for setting EXP events")
RULE_REAL(Character, ExpMultiplier, 0.5, "If greater than 0, the experience gained is multiplied by this value. ")
RULE_REAL(Character, AAExpMultiplier, 0.5, "If greater than 0, the AA experience gained is multiplied by this value. ")
RULE_REAL(Character, GroupExpMultiplier, 0.5, "The experience in a group is multiplied by this value in addition to the group multiplier. The group multiplier is: 2 members=x 1.2, 3=x1.4, 4=x1.6, 5=x1.8, 6=x2.16")
RULE_REAL(Character, RaidExpMultiplier, 0.2, "The experience gained in raids is multiplied by (1-RaidExpMultiplier) ")
RULE_REAL(Character, FinalRaidExpMultiplier, 1.0, "Multiplies all raid experience by this value. Default: 1.0")
RULE_BOOL(Character, UseXPConScaling, true, "When activated, the experience is modified depending on the difference between player level and NPC level. The values from the rules GreenModifier to RedModifier are used")
RULE_INT(Character, ShowExpValues, 0, "Show experience values. 0=normal, 1=show raw experience values, 2=show raw experience values and percent")
RULE_INT(Character, GreenModifier, 20, "The experience obtained for green con mobs is multiplied by value/100")
RULE_INT(Character, LightBlueModifier, 40, "The experience obtained for light-blue con mobs is multiplied by value/100")
RULE_INT(Character, BlueModifier, 90, "The experience obtained for blue con mobs is multiplied by value/100")
RULE_INT(Character, WhiteModifier, 100, "The experience obtained for white con mobs is multiplied by value/100")
RULE_INT(Character, YellowModifier, 125, "The experience obtained for yellow con mobs is multiplied by value/100")
RULE_INT(Character, RedModifier, 150, "The experience obtained for red con mobs is multiplied by value/100")
RULE_INT(Character, AutosaveIntervalS, 300, "Number of seconds after which a timer is triggered which stores the character data. The value 0 means no periodic automatic saving.")
RULE_INT(Character, HPRegenMultiplier, 100, "The hitpoint regeneration is multiplied by value/100 (up to the caps)")
RULE_INT(Character, ManaRegenMultiplier, 100, "The mana regeneration is multiplied by value/100 (up to the caps)")
RULE_INT(Character, EnduranceRegenMultiplier, 100, "The endurance regeneration is multiplied by value/100 (up to the caps)")
RULE_BOOL(Character, OldMinMana, false, "This is used for servers that want to follow older skill cap formulas so they can still have some regen w/o mediate")
RULE_BOOL(Character, HealOnLevel, false, "Setting whether a player should heal completely when leveling")
RULE_BOOL(Character, FeignKillsPet, false, "Setting whether Feign Death kills the player pet")
RULE_INT(Character, ItemManaRegenCap, 15, "Limit on mana regeneration granted by items")
RULE_INT(Character, ItemHealthRegenCap, 30, "Limit on health regeneration granted by items")
RULE_INT(Character, ItemDamageShieldCap, 30, "Limit on damage shields granted by items")
RULE_INT(Character, ItemAccuracyCap, 150, "Limit on accuracy granted by items")
RULE_INT(Character, ItemAvoidanceCap, 100, "Limit on avoidance granted by items")
RULE_INT(Character, ItemCombatEffectsCap, 100, "Limit on combat effects granted by items")
RULE_INT(Character, ItemShieldingCap, 35, "Limit on shielding granted by items")
RULE_INT(Character, ItemSpellShieldingCap, 35, "Limit on spell shielding granted by items")
RULE_INT(Character, ItemDoTShieldingCap, 35, "Limit on DoT shielding granted by items")
RULE_INT(Character, ItemStunResistCap, 35, "Limit on resistance granted by items")
RULE_INT(Character, ItemStrikethroughCap, 35, "Limit on strikethrough granted by items")
RULE_INT(Character, ItemATKCap, 250, "Limit on ATK granted by items")
RULE_INT(Character, ItemHealAmtCap, 250, "Limit on heal amount granted by items")
RULE_INT(Character, ItemSpellDmgCap, 250, "Limit on spell damage granted by items")
RULE_INT(Character, ItemClairvoyanceCap, 250, "Limit on clairvoyance granted by items")
RULE_INT(Character, ItemDSMitigationCap, 50, "Limit on damageshield mitigation granted by items")
RULE_INT(Character, ItemEnduranceRegenCap, 15, "Limit on endurance regeneration granted by items")
RULE_INT(Character, ItemExtraDmgCap, 150, "Cap for bonuses to melee skills like Bash, Frenzy, etc.")
RULE_INT(Character, HasteCap, 100, "Haste cap for non-v3(over haste) haste")
RULE_INT(Character, Hastev3Cap, 25, "Haste cap for v3(over haste) haste")
RULE_BOOL(Character, HeroicStatsUseDataBucketsToScale, false, "Allows scaling the benefits a character receives from Heroic Stats using Data Buckets. Stacks with other Heroic Stats Mulitplier Rules.")
RULE_REAL(Character, HeroicIntelligenceIncreaseSpellDmgMultiplier, 0.00, "Allows Heroic Intelligence to increase a Players Worn Spell Damage Stat from Equipment, for example, setting this rule to 1.00 will always grant 1 Spell Damage per 1 Heroic Intelligence")
RULE_REAL(Character, HeroicWisdomIncreaseHealAmtMultiplier, 0.00, "Allows Heroic Wisdom to increase a Players Worn Heal Amount Stat from Equipment, for example, setting this rule to 1.00 will always grant 1 Heal Amount per 1 Heroic Wisdom")
RULE_REAL(Character, HeroicStrengthMultiplier, 1.00, "Multplier scales benefits from Heroic Strength. Grants 25 Base Endurance, 0.05 Endurance Regen, 1 Melee Damage each Hit, and 1 Shield AC per 10 Heroic Strength.")
RULE_REAL(Character, HeroicStaminaMultiplier, 1.00, "Multplier scales benefits from Heroic Stamina. Grants 25 Base Endurance, 0.05 Endurance Regen, 100 Base HP, and 0.5 HP Regen per 10 Heroic Stamina.")
RULE_REAL(Character, HeroicAgilityMultiplier, 1.00, "Multplier scales benefits from Heroic Agility. Grants 25 Base Endurance, 0.05 Endurance Regen, and 1 Avoidance AC per 10 Heroic Agility. (Rule does not change Dodge Chance)")
RULE_REAL(Character, HeroicDexterityMultiplier, 1.00, "Multplier scales benefits from Heroic Dexterity. Grants 25 Base Endurance, 0.05 Endurance Regen, and 1 Archery/Throwing Damage each hit per 10 Heroic Dexterity. (Rule does not change Assassinate/Headshot/Block/Parry/Riposte Chances)")
RULE_REAL(Character, HeroicWisdomMultiplier, 1.00, "Multplier scales benefits from Heroic Wisdom. Grants 250 Base Mana, 1 Mana Regen per 25 Heroic Wisdom.")
RULE_REAL(Character, HeroicIntelligenceMultiplier, 1.00, "Multplier scales benefits from Heroic Intelligence. Grants 250 Base Mana, 1 Mana Regen per 25 Heroic Intelligence.")
RULE_INT(Character, SkillUpModifier, 100, "The probability for a skill-up is multiplied by value/100")
RULE_BOOL(Character, SharedBankPlat, false, "Shared bank platinum. Off by default to prevent duplication")
RULE_BOOL(Character, BindAnywhere, false, "Allows players to bind their soul anywhere in the world")
RULE_BOOL(Character, RestRegenEnabled, true, "Setting to activate out-of-combat regeneration")
RULE_INT(Character, RestRegenTimeToActivate, 30, "Time in seconds for rest state regen to kick in")
RULE_INT(Character, RestRegenRaidTimeToActivate, 300, "Time in seconds for rest state regen to kick in with a raid target")
RULE_INT(Character, KillsPerGroupLeadershipAA, 250, "Minimum number of dark blue mobs that must be killed to get a Group Leadership AA")
RULE_INT(Character, KillsPerRaidLeadershipAA, 250, "Minimum number of dark blue mobs that must be killed to get a Raid Leadership AAA")
RULE_INT(Character, MaxFearDurationForPlayerCharacter, 4, "Maximum number of tics a player can be feared. 1 tic equls 6 seconds")
RULE_INT(Character, MaxCharmDurationForPlayerCharacter, 15, "Maximum number of tics a player can be charmed. 1 tic equls 6 seconds")
RULE_INT(Character, BaseHPRegenBonusRaces, 4352, "A bitmask of race(s) that receive the regen bonus. Iksar (4096) & Troll (256) = 4352. See common/races.h for the bitmask values")
RULE_BOOL(Character, SoDClientUseSoDHPManaEnd, false, "Setting this to true will allow SoD clients to use the SoD HP/Mana/End formulas and previous clients will use the old formulas")
RULE_BOOL(Character, UseRaceClassExpBonuses, true, "Setting this to true will enable Class and Racial experience rate bonuses")
RULE_BOOL(Character, UseOldRaceExpPenalties, false, "Setting this to true will enable racial experience penalties for Iksar, Troll, Ogre, and Barbarian, as well as the bonus for Halflings")
RULE_BOOL(Character, UseOldClassExpPenalties, false, "Setting this to true will enable old class experience penalties for Paladin, SK, Ranger, Bard, Monk, Wizard, Enchanter, Magician, and Necromancer, as well as the bonus for Rogues and Warriors")
RULE_BOOL(Character, RespawnFromHover, false, "Setting whether the respawn window should be used")
RULE_INT(Character, RespawnFromHoverTimer, 300, "Respawn Window countdown timer, in seconds")
RULE_BOOL(Character, UseNewStatsWindow, true, "Setting whether the new Stats window, which displays all information, should be used")
RULE_BOOL(Character, ItemCastsUseFocus, false, "If true, this allows item clickies to use focuses that have limited maximum levels on them")
RULE_INT(Character, MinStatusForNoDropExemptions, 80, "This allows status x and higher to trade no drop items")
RULE_INT(Character, SkillCapMaxLevel, 75, "Sets the Maximum Level used for Skill Caps (from skill_caps table). -1 makes it use MaxLevel rule value. It is set to 75 because PEQ only has skill caps up to that level, and grabbing the players' skill past 75 will return 0, breaking all skills past that level. This helps servers with obsurd level caps (75+ level cap) function without any modifications")
RULE_INT(Character, StatCap, 0, "If StatCap > 0 then this value is used. If it is 0, the value of the following code is used: If Level < 61: 255. If Level >= 61 and the client SoF or newer: 255 + 5 x (level -60).  If the client is older than SoF and the level < 71 then: 255 + x (level-60). In all other cases: 330.")
RULE_BOOL(Character, CheckCursorEmptyWhenLooting, true, "If true, a player cannot loot a corpse (player or NPC) with an item on their cursor")
RULE_BOOL(Character, MaintainIntoxicationAcrossZones, true, "If true, alcohol effects are maintained across zoning and logging out/in")
RULE_BOOL(Character, EnableDiscoveredItems, true, "If enabled, it enables EVENT_DISCOVER_ITEM and also saves character names and timestamps for the first time an item is discovered")
RULE_BOOL(Character, EnableXTargetting, true, "Enable Extended Targeting Window, for users with UF and later clients")
RULE_BOOL(Character, EnableAggroMeter, true, "Enable Aggro Meter, for users with RoF and later clients")
RULE_BOOL(Character, KeepLevelOverMax, false, "Don't de-level a character that has somehow gone over the level cap")
RULE_INT(Character, FoodLossPerUpdate, 32, "How much food/water you lose per stamina update")
RULE_BOOL(Character, EnableHungerPenalties, false, "Being hungry/thirsty has negative effects -- it does appear normal live servers do not have penalties")
RULE_BOOL(Character, EnableFoodRequirement, true, "If disabled, food is no longer required")
RULE_INT(Character, BaseInstrumentSoftCap, 36, "Softcap for instrument mods, 36 commonly referred to as 3.6 as well")
RULE_BOOL(Character, UseSpellFileSongCap, true, "When they removed the AA that increased the cap they removed the above and just use the spell field")
RULE_INT(Character, BaseRunSpeedCap, 158, "Base Run Speed Cap, on live it's 158% which will give you a runspeed of 1.580 hard capped to 225")
RULE_REAL(Character, EnvironmentDamageMulipliter, 1, "Multiplier for environmental damage like fall damage.")
RULE_BOOL(Character, UnmemSpellsOnDeath, true, "Setting whether at death all memorized Spells are forgotten")
RULE_REAL(Character, TradeskillUpAlchemy, 2.0, "Alchemy skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpBaking, 2.0, "Baking skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpBlacksmithing, 2.0, "Blacksmithing skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpBrewing, 3.0, "Brewing skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpFletching, 2.0, "Fletching skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpJewelcrafting, 2.0, "Jewelcrafting skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpMakePoison, 2.0, "Make Poison skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpPottery, 4.0, "Pottery skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpResearch, 1.0, "Research skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpTinkering, 2.0, "Tinkering skillup rate adjustment. Lower is faster")
RULE_REAL(Character, TradeskillUpTailoring, 2.0, "Tailoring skillup rate adjustment. Lower is faster")
RULE_BOOL(Character, MarqueeHPUpdates, false, "Will show health percentage in center of screen if health lesser than 100%")
RULE_INT(Character, IksarCommonTongue, 95, "Starting value for Common Tongue for Iksars")
RULE_INT(Character, OgreCommonTongue, 95, "Starting value for Common Tongue for Ogres")
RULE_INT(Character, TrollCommonTongue, 95, "Starting value for Common Tongue for Trolls")
RULE_BOOL(Character, ActiveInvSnapshots, false, "Takes a periodic snapshot of inventory contents from online players")
RULE_INT(Character, InvSnapshotMinIntervalM, 180, "Minimum time between inventory snapshots (minutes)")
RULE_INT(Character, InvSnapshotMinRetryM, 30, "Time to re-attempt an inventory snapshot after a failure  (minutes)")
RULE_INT(Character, InvSnapshotHistoryD, 30, "Time to keep snapshot entries (days)")
RULE_BOOL(Character, RestrictSpellScribing, false, "Setting whether to restrict spell scribing to allowable races/classes of spell scroll")
RULE_BOOL(Character, UseStackablePickPocketing, true, "Allows stackable pickpocketed items to stack instead of only being allowed in empty inventory slots")
RULE_BOOL(Character, AllowMQTarget, false, "Disables putting players in the 'hackers' list for targeting beyond the clip plane or attempting to target something untargetable")
RULE_BOOL(Character, UseOldBindWound, false, "Uses the original bind wound behavior")
RULE_BOOL(Character, GrantHoTTOnCreate, false, "Grant Health of Target's Target leadership AA on character creation")
RULE_BOOL(Character, UseOldConSystem, false, "Setting whether the pre SoF era consider system should be used")
RULE_BOOL(Character, OPClientUpdateVisualDebug, false, "Shows a pulse and forward directional particle each time the client sends its position to server")
RULE_BOOL(Character, AllowCrossClassTrainers, false, "If the value is true, a player can also train with other class Guildmasters.")
RULE_BOOL(Character, PetsUseReagents, true, "Conjuring pets consumes reagents")
RULE_BOOL(Character, DismountWater, true, "Dismount horses when entering water")
RULE_BOOL(Character, NoSkillsOnHorse, false, "Enabling this will prevent Bind Wound and Foraging while on a mount")
RULE_BOOL(Character, UseNoJunkFishing, false, "Disregards junk items when fishing")
RULE_BOOL(Character, SoftDeletes, true, "When characters are deleted in character select, they are only soft deleted")
RULE_INT(Character, DefaultGuild, 0, "If not 0, new characters placed into the guild # indicated")
RULE_BOOL(Character, ProcessFearedProximity, false, "Processes proximity checks when feared")
RULE_BOOL(Character, EnableCharacterEXPMods, false, "Enables character zone-based experience modifiers.")
RULE_BOOL(Character, PVPEnableGuardFactionAssist, true, "Enables faction based assisting against the aggresor in pvp.")
RULE_BOOL(Character, SkillUpFromItems, true, "Allow Skill ups from clickable items")
RULE_BOOL(Character, EnableTestBuff, false, "Allow the use of /testbuff")
RULE_BOOL(Character, UseResurrectionSickness, true, "Use Resurrection Sickness based on Resurrection spell cast, set to false to disable Resurrection Sickness.")
RULE_INT(Character, OldResurrectionSicknessSpellID, 757, "757 is Default Old Resurrection Sickness Spell ID")
RULE_INT(Character, ResurrectionSicknessSpellID, 756, "756 is Default Resurrection Sickness Spell ID")
RULE_BOOL(Character, EnableBardMelody, true, "Enable Bard /melody by default, to disable change to false for a classic experience.")
RULE_BOOL(Character, EnableRangerAutoFire, true, "Enable Ranger /autofire by default, to disable change to false for a classic experience.")
RULE_BOOL(Character, EnableTGB, true, "Enable /tgb (Target Group Buff) by default, to disable change to false for a classic experience.")
RULE_INT(Character, SkillUpMaximumChancePercentage, 25, "Maximum chance to improve a combat skill, before skill-specific modifiers.  This should be greater than SkillUpMinimumChancePercentage.")
RULE_INT(Character, SkillUpMinimumChancePercentage, 2, "Minimum chance to improve a combat skill, after skill-specific modifiers.  This should be lesser than SkillUpMaximumChancePercentage.")
RULE_INT(Character, WarriorTrackingDistanceMultiplier, 0, "If you want warriors to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, ClericTrackingDistanceMultiplier, 0, "If you want clerics to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, PaladinTrackingDistanceMultiplier, 0, "If you want paladins to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, RangerTrackingDistanceMultiplier, 12, "If you want rangers to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, ShadowKnightTrackingDistanceMultiplier, 0, "If you want shadow knights to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, DruidTrackingDistanceMultiplier, 10, "If you want druids to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, MonkTrackingDistanceMultiplier, 0, "If you want monks to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, BardTrackingDistanceMultiplier, 7, "If you want bards to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, RogueTrackingDistanceMultiplier, 0, "If you want rogues to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, ShamanTrackingDistanceMultiplier, 0, "If you want shaman to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, NecromancerTrackingDistanceMultiplier, 0, "If you want necromancers to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, WizardTrackingDistanceMultiplier, 0, "If you want wizards to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, MagicianTrackingDistanceMultiplier, 0, "If you want magicians to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, EnchanterTrackingDistanceMultiplier, 0, "If you want enchanters to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, BeastlordTrackingDistanceMultiplier, 0, "If you want beastlords to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_INT(Character, BerserkerTrackingDistanceMultiplier, 0, "If you want berserkers to be able to track, increase this above 0.  0 disables tracking packets.")
RULE_BOOL(Character, OnInviteReceiveAlreadyinGroupMessage, true, "If you want clients to receive a message when trying to invite a player into a group that is currently in another group.")
RULE_BOOL(Character, PetZoneWithOwner, true, "Should Pets Zone with Owner")
RULE_BOOL(Character, FullManaOnDeath, true, "On death set mana to full")
RULE_BOOL(Character, FullEndurOnDeath, true, "On death set endurance to full")
RULE_INT(Character, ExperiencePercentCapPerKill, -1, "Caps the percentage of experience that can be gained per kill. -1 disables the cap; 0 blocks all (non-aa) xp.")
RULE_BOOL(Character, EnableGroupEXPModifier, true, "Enable or disable the group experience modifier in group, default is true")
RULE_BOOL(Character, EnableGroupMemberEXPModifier, true, "Enable or disable the group member experience modifier based on number of players in group, default is true")
RULE_REAL(Character, GroupMemberEXPModifier, 0.2, "Sets the group experience modifier per members between 2 and 5, default is 0.2")
RULE_REAL(Character, FullGroupEXPModifier, 2.16, "Sets the group experience modifier for a full group, default is 2.16")
RULE_BOOL(Character, IgnoreLevelBasedHasteCaps, false, "Ignores hard coded level based haste caps.")
RULE_BOOL(Character, EnableRaidEXPModifier, true, "Enable or disable the raid experience modifier, default is true")
RULE_BOOL(Character, EnableRaidMemberEXPModifier, true, "Enable or disable the raid experience modifier based on members in raid, default is true")
RULE_BOOL(Character, LeaveCursorMoneyOnCorpse, false, "Enable or disable leaving cursor money on player corpses")
RULE_BOOL(Character, ItemExtraSkillDamageCalcAsPercent, false, "If enabled, apply Item Extra Skill Damage as Percentage-based modifiers")
RULE_BOOL(Character, UseForageCommonFood, true, "If enabled, use the common foods specified in the code.")
RULE_INT(Character, ClearXTargetDelay, 10, "Seconds between uses of the #clearxtargets command (Set to 0 to disable)")
RULE_BOOL(Character, PreventMountsFromZoning, false, "Enable to prevent mounts from zoning - Prior to December 15, 2004 this is enabled.")
RULE_BOOL(Character, GroupInvitesRequireTarget, false, "Enable to require players to have invitee on target (Disables /invite name) - Classic Style")
RULE_BOOL(Character, PlayerTradingLoreFeedback, true, "If enabled, during a player to player trade, if lore items exist, it will output which items.")
RULE_CATEGORY_END()

RULE_CATEGORY(Mercs)
RULE_INT(Mercs, SuspendIntervalMS, 10000, "Time interval for merc suspend (milliseconds)")
RULE_INT(Mercs, UpkeepIntervalMS, 180000, "Time interval for merc upkeep (milliseconds)")
RULE_INT(Mercs, SuspendIntervalS, 10, "Time interval for merc suspend command (seconds)")
RULE_BOOL(Mercs, AllowMercs, false, "Allow the use of mercs")
RULE_BOOL(Mercs, ChargeMercPurchaseCost, false, "Turns Mercenary purchase costs on or off")
RULE_BOOL(Mercs, ChargeMercUpkeepCost, false, "Turns Mercenary upkeep costs on or off")
RULE_INT(Mercs, AggroRadius, 100, "Determines the distance from which a merc will aggro group member's target(also used to determine the distance at which a healer merc will begin healing a group member)")
RULE_INT(Mercs, AggroRadiusPuller, 25, "Determines the distance from which a merc will aggro group member's target, if they have the group role of puller (also used to determine the distance at which a healer merc will begin healing a group member, if they have the group role of puller)")
RULE_INT(Mercs, ResurrectRadius, 50, "Determines the distance from which a healer merc will attempt to resurrect a group member's corpse")
RULE_INT(Mercs, ScaleRate, 100, "Merc scale factor")
RULE_BOOL(Mercs, AllowMercSuspendInCombat, true, "Allow merc suspend in combat")
RULE_CATEGORY_END()

RULE_CATEGORY(Guild)
RULE_BOOL(Guild, PlayerCreationAllowed, false, "Allow players to create a guild using the window in Underfoot+")
RULE_INT(Guild, PlayerCreationLimit, 1, "Only allow use of the UF+ window if the account has < than this number of guild leaders on it")
RULE_INT(Guild, PlayerCreationRequiredStatus, 0, "Required status to create a guild")
RULE_INT(Guild, PlayerCreationRequiredLevel, 0, "Required level of the player attempting to create the guild")
RULE_INT(Guild, PlayerCreationRequiredTime, 0, "Time needed online on the account to create a guild (in minutes)")
RULE_INT(Guild, TributeTime, 600000, "Time in ms for guild tributes.  Default is 10 mins.")
RULE_INT(Guild, TributeTimeRefreshInterval, 180000, "Time in ms to send all guild members a Tribute Time refresh. Default is 3 mins.")
RULE_INT(Guild, TributePlatConversionRate, 10, "The conversion rate of platinum donations.  Default is 10 guild favor to 1 platinum.")
RULE_BOOL(Guild, UseCharacterMaxLevelForGuildTributes, true, "Guild Tributes will adhere to Character:MaxLevel.  Default is true.")
RULE_CATEGORY_END()

RULE_CATEGORY(Skills)
RULE_INT(Skills, MaxTrainTradeskills, 21, "Highest level for trade skills that can be taught by the trainer")
RULE_INT(Skills, MaxTrainResearch, 21, "Highest level for training research from a GM.")
RULE_BOOL(Skills, UseLimitTradeskillSearchSkillDiff, true, "Enables the limit for the maximum difference between trivial and skill for recipe searches and favorites")
RULE_BOOL(Skills, TrivialTradeskillCombinesNoFail, false, "Enable to make all trivial tradeskill combines unable to fail")
RULE_INT(Skills, MaxTradeskillSearchSkillDiff, 50, "The maximum difference in skill between the trivial of an item and the skill of the player if the trivial is higher than the skill. Recipes that have not been learnt or made at least once via the Experiment mode will be removed from searches based on this criteria.")
RULE_INT(Skills, MaxTrainSpecializations, 50, "Maximum level a GM trainer will train casting specializations")
RULE_INT(Skills, SwimmingStartValue, 100, "Start value of swimming skill")
RULE_BOOL(Skills, TrainSenseHeading, false, "Switch whether SenseHeading is trained by use")
RULE_INT(Skills, SenseHeadingStartValue, 200, "Start value of sense heading skill")
RULE_BOOL(Skills, SelfLanguageLearning, true, "Enabling self-learning of languages")
RULE_BOOL(Skills, RequireTomeHandin, false, "Disable click-to-learn and force hand in to Guild Master")
RULE_INT(Skills, TradeSkillClamp, 0, "Legacy tradeskills would clamp at 252 regardless of item modifiers and skill combination. DEFAULT: 0 will bypass clamp. Legacy value 252")
RULE_BOOL(Skills, UseAltSinisterStrikeFormula, false, "Enabling will utilize a formula derived from 2004 monkey business post which makes the AA actually worth something.")
RULE_BOOL(Skills, TrackingAutoRefreshSkillUps, true, "Disable to prevent tracking auto-refresh from giving skill-ups. Classic Style")
RULE_INT(Skills, MaximumTauntDistance, 150, "Maximum player taunt distance.")
RULE_CATEGORY_END()

RULE_CATEGORY(Pets)
RULE_REAL(Pets, AttackCommandRange, 150, "Range at which a pet will respond to attack commands")
RULE_BOOL(Pets, UnTargetableSwarmPet, false, "Setting whether swarm pets should be targetable")
RULE_REAL(Pets, PetPowerLevelCap, 10, "Maximum number of levels a player pet can go up with pet power")
RULE_BOOL(Pets, CanTakeNoDrop, false, "Setting whether anyone can give no-drop items to pets")
RULE_BOOL(Pets, CanTakeQuestItems, true, "Setting whether anyone can give quest items to pets")
RULE_BOOL(Pets, LivelikeBreakCharmOnInvis, true, "Default: true will break charm on any type of invis (hide/ivu/iva/etc) false will only break if the pet can not see you (ex. you have an undead pet and cast IVU")
RULE_BOOL(Pets, ClientPetsUseOwnerNameInLastName, true, "Disable this to keep client pet's last names from being owner_name's pet")
RULE_INT(Pets, PetTauntRange, 150, "Range at which a pet will taunt targets.")
RULE_CATEGORY_END()

RULE_CATEGORY(GM)
RULE_INT(GM, MinStatusToSummonItem, 250, "Minimum required status to summon items")
RULE_INT(GM, MinStatusToZoneAnywhere, 250, "Minimum required status to zone anywhere")
RULE_INT(GM, MinStatusToLevelTarget, 100, "Minimum required status to set the level of a player")
RULE_INT(GM, MinStatusToBypassLockedServer, 100, "Players >= this status can log in to the server even when it is locked")
RULE_INT(GM, MinStatusToBypassCheckSumVerification, 100, "Players >= this status can bypass the eqgame.exe and spells_us.txt checksum verification")
RULE_CATEGORY_END()

RULE_CATEGORY(World)
RULE_INT(World, ZoneAutobootTimeoutMS, 60000, "Time out for automatic booting of zones in milliseconds")
RULE_BOOL(World, UseBannedIPsTable, false, "Toggle whether or not to check incoming client connections against the banned_ips table. Set this value to false to disable this feature")
RULE_BOOL(World, EnableTutorialButton, true, "Setting whether the Tutorial button should be active. At least in RoF2 you can always press the button, but it loses its effect")
RULE_BOOL(World, EnableReturnHomeButton, true, "Setting whether the Return Home button should be active")
RULE_INT(World, MaxLevelForTutorial, 10, "The highest level with which you can enter the tutorial")
RULE_INT(World, TutorialZoneID, 189, "Zone ID of the tutorial")
RULE_INT(World, MinOfflineTimeToReturnHome, 21600, "Minimum offline time to activate the Return Home button. 21600 seconds is 6 Hours")
RULE_INT(World, MaxClientsPerIP, -1, "Maximum number of clients allowed to connect per IP address if account status is < AddMaxClientsStatus. Default value: -1 (feature disabled)")
RULE_INT(World, ExemptMaxClientsStatus, -1, "Exempt accounts from the MaxClientsPerIP and AddMaxClientsStatus rules, if their status is >= this value. Default value: -1 (feature disabled)")
RULE_INT(World, AddMaxClientsPerIP, -1, "Maximum number of clients allowed to connect per IP address if account status is < ExemptMaxClientsStatus. Default value: -1 (feature disabled)")
RULE_INT(World, AddMaxClientsStatus, -1, "Accounts with status >= this rule will be allowed to use the amount of accounts defined in the AddMaxClientsPerIP. Default value: -1 (feature disabled)")
RULE_BOOL(World, MaxClientsSetByStatus, false, "If true, IP Limiting will be set to the status on the account as long as the status is > MaxClientsPerIP")
RULE_BOOL(World, EnableIPExemptions, false, "If true, ip_exemptions table is used, if there is no entry for the IP it will default to RuleI(World, MaxClientsPerIP)")
RULE_BOOL(World, ClearTempMerchantlist, true, "Clears temp merchant items when world boots")
RULE_BOOL(World, GMAccountIPList, false, "Check IP list against GM accounts. This increases the security of GM accounts, e.g. if you only allow localhost '127.0.0.1' for GM accounts. Think carefully about what you enter!")
RULE_INT(World, MinGMAntiHackStatus, 1, "Minimum status to check against AntiHack list")
RULE_INT(World, SoFStartZoneID, -1, "Sets the Starting Zone for SoF Clients separate from Titanium Clients (-1 is disabled)")
RULE_INT(World, TitaniumStartZoneID, -1, "Sets the Starting Zone for Titanium Clients (-1 is disabled). Replaces the old method")
RULE_INT(World, ExpansionSettings, 16383, "Sets the expansion settings bitmask for the server, This is sent on login to world and affects client expansion settings. Defaults to all expansions enabled up to TSS, value is bitmask")
RULE_INT(World, CharacterSelectExpansionSettings, -1, "Sets the expansion settings bitmask for character select if you wish to override. -1 is off")
RULE_BOOL(World, UseClientBasedExpansionSettings, true, "If true it will overrule World, ExpansionSettings and set someone's expansion based on the client they're using")
RULE_INT(World, PVPSettings, 0, "Sets the PVP settings for the server. 1=Rallos Zek RuleSet, 2=Tallon/Vallon Zek Ruleset, 4=Sullon Zek Ruleset, 6=Discord Ruleset, anything above 6 is the Discord Ruleset without the no-drop restrictions removed. NOTE: edit IsAttackAllowed in Zone-table to accomodate for these rules")
RULE_INT(World, PVPMinLevel, 0, "Minimum level to pvp")
RULE_BOOL (World, IsGMPetitionWindowEnabled, false, "Setting whether the GM petition window is available")
RULE_INT (World, FVNoDropFlag, 0, "Sets the Firiona Vie settings on the client, allowing trading of no-drop items. 1=for all players, 2=for GM only")
RULE_BOOL (World, IPLimitDisconnectAll, false, "Disconnect all current clients by IP if they go over the IP limit.  This should allow people to quickly reconnect in the case of dead sessions waiting to timeout")
RULE_INT (World, TellQueueSize, 20, "Maximum tell queue size")
RULE_BOOL(World, StartZoneSameAsBindOnCreation, true, "Should the start zone always be the same location as your bind?")
RULE_BOOL(World, EnforceCharacterLimitAtLogin, false, "Enforce the limit for characters that are online at login")
RULE_BOOL(World, EnableDevTools, true, "Enable or Disable the Developer Tools globally (Most of the time you want this enabled)")
RULE_BOOL(World, EnableChecksumVerification, false, "Enable or Disable the Checksum Verification for eqgame.exe and spells_us.txt")
RULE_INT(World, MaximumQuestErrors, 30, "Changes the maximum number of quest errors that can be displayed in #questerrors, default is 30")
RULE_INT(World, BootHour, 0, "Sets the in-game hour world will set when it first boots. 0-24 are valid options, where 0 disables this rule")
RULE_BOOL(World, UseItemLinksForKeyRing, false, "Uses item links for Key Ring Listing instead of item name")
RULE_BOOL(World, UseOldShadowKnightClassExport, true, "Disable to have Shadowknight show as Shadow Knight (live-like)")
RULE_CATEGORY_END()

RULE_CATEGORY(Zone)
RULE_INT(Zone, ClientLinkdeadMS, 90000, "The time a client remains link dead on the server after a sudden disconnection (milliseconds)")
RULE_INT(Zone, GraveyardTimeMS, 1200000, "Time until a player corpse is moved to a zone's graveyard, if one is specified for the zone (milliseconds)")
RULE_BOOL(Zone, EnableShadowrest, 1, "Enables or disables the Shadowrest zone feature for player corpses. Default is turned on")
RULE_INT(Zone, AutoShutdownDelay, 60000, "How long a dynamic zone stays loaded while empty (milliseconds)")
RULE_INT(Zone, PEQZoneReuseTime, 900, "Seconds between two uses of the #peqzone command (Set to 0 to disable)")
RULE_INT(Zone, PEQZoneDebuff1, 4454, "First debuff casted by #peqzone Default is Cursed Keeper's Blight")
RULE_INT(Zone, PEQZoneDebuff2, 2209, "Second debuff casted by #peqzone Default is Tendrils of Apathy")
RULE_BOOL(Zone, UsePEQZoneDebuffs, true, "Setting if the command #peqzone applies the defined debuffs")
RULE_INT(Zone, PEQZoneHPRatio, 75, "Required HP Ratio to use #peqzone")
RULE_REAL(Zone, HotZoneBonus, 0.75, "Value which is added to the experience multiplier. This also applies to AA experience.")
RULE_INT(Zone, EbonCrystalItemID, 40902, "Item ID for Ebon Crystal")
RULE_INT(Zone, RadiantCrystalItemID, 40903, "Item ID for Radiant Crystal")
RULE_BOOL(Zone, LevelBasedEXPMods, false, "Allows you to use the level_exp_mods table in consideration to your players experience hits")
RULE_INT(Zone, WeatherTimer, 600, "Weather timer when no duration is available")
RULE_BOOL(Zone, EnableLoggedOffReplenishments, true, "'Replenish mana/hp/end if logged off for MinOfflineTimeToReplenishments")
RULE_INT(Zone, MinOfflineTimeToReplenishments, 21600, "Minimum time a player must be offline before LoggedOffReplenishments becomes active (seconds)")
RULE_BOOL(Zone, UseZoneController, true, "Enables the ability to use persistent quest based zone controllers (zone_controller.pl/lua)")
RULE_BOOL(Zone, EnableZoneControllerGlobals, false, "Enables the ability to use quest globals with the zone controller NPC")
RULE_INT(Zone, GlobalLootMultiplier, 1, "Sets Global Loot drop multiplier for database based drops, useful for double, triple loot etc")
RULE_BOOL(Zone, KillProcessOnDynamicShutdown, true, "When process has booted a zone and has hit its zone shut down timer, it will hard kill the process to free memory back to the OS")
RULE_INT(Zone, SpawnEventMin, 3, "When strict is set in spawn_events, specifies the max EQ minutes into the trigger hour a spawn_event will fire. Going below 3 may cause the spawn_event to not fire.")
RULE_INT(Zone, ForageChance, 25, "Chance of foraging from zone table vs global table")
RULE_BOOL(Zone, AllowCrossZoneSpellsOnBots, false, "Set to true to allow cross zone spells (cast/remove) to affect bots")
RULE_BOOL(Zone, AllowCrossZoneSpellsOnMercs, false, "Set to true to allow cross zone spells (cast/remove) to affect mercenaries")
RULE_BOOL(Zone, AllowCrossZoneSpellsOnPets, false, "Set to true to allow cross zone spells (cast/remove) to affect pets")
RULE_CATEGORY_END()

RULE_CATEGORY(Map)
RULE_BOOL(Map, FixPathingZOnSendTo, false, "Try to repair Z coordinates in the SendTo routine as well")
RULE_BOOL(Map, FixZWhenPathing, true, "Automatically fix NPC Z coordinates when moving/pathing/engaged (Far less CPU intensive than its predecessor)")
RULE_BOOL(Map, MobZVisualDebug, false, "Displays spell effects determining whether or not NPC is hitting Best Z calcs (blue for hit, red for miss)")
RULE_BOOL(Map, MobPathingVisualDebug, false, "Displays nodes in pathing points in realtime to help with visual debugging")
RULE_REAL(Map, FixPathingZMaxDeltaSendTo, 20, "At runtime in SendTo: maximum change in Z to allow the BestZ code to apply")
RULE_INT(Map, FindBestZHeightAdjust, 1, "Adds this to the current Z before seeking the best Z position")
RULE_CATEGORY_END()

RULE_CATEGORY(Pathing)
RULE_BOOL(Pathing, Find, true, "Enable pathing for FindPerson requests from the client")
RULE_BOOL(Pathing, Fear, true, "Enable pathing for fear")
RULE_REAL(Pathing, NavmeshStepSize, 100.0f, "Step size for the movement manager")
RULE_REAL(Pathing, ShortMovementUpdateRange, 130.0f, "Range for short movement updates")
RULE_INT(Pathing, MaxNavmeshNodes, 4092, "Maximum navmesh nodes in a traversable path")
RULE_CATEGORY_END()

RULE_CATEGORY(Watermap)
// enable these to use the water detection code. Requires Water Maps generated by awater utility
RULE_BOOL(Watermap, CheckForWaterOnSendTo, false, "Checks if a mob has moved into/out of water on SendTo")
RULE_BOOL(Watermap, CheckForWaterWhenFishing, false, "Only lets a player fish near water (if a water map exists for the zone)")
RULE_REAL(Watermap, FishingRodLength, 30, "How far in front of player water must be for fishing to work")
RULE_REAL(Watermap, FishingLineLength, 100, "If water is more than this far below the player, it is considered too far to fish")
RULE_REAL(Watermap, FishingLineStepSize, 1, "Basic step size for fishing calc, too small and it will eat cpu, too large and it will miss potential water")
RULE_CATEGORY_END()

RULE_CATEGORY(Spells)
RULE_BOOL(Spells, AllowExtraDmgSkill, false, "Allow ExtraDmgSkill from Items, Spells, and AAs to apply ExtraDmgAmt when the ExtraDmgSkill matches the casted Spells Skill Type.")
RULE_INT(Spells, BaseCritChance, 0, "Base percentage chance that everyone has to crit a spell")
RULE_INT(Spells, BaseCritRatio, 100, "Base percentage bonus to damage on a successful spell crit. 100=2xdamage")
RULE_INT(Spells, WizCritLevel, 12, "Level wizards first get spell crits")
RULE_INT(Spells, WizCritChance, 7, "Wizards crit chance, on top of BaseCritChance")
RULE_INT(Spells, WizCritRatio, 0, "Wizards crit bonus, on top of BaseCritRatio (should be 0 for Live-like)")
RULE_INT(Spells, TranslocateTimeLimit, 0, "If not zero, time in seconds to accept a Translocate")
RULE_INT(Spells, SacrificeMinLevel, 46, "First level the spell Sacrifice will work on")
RULE_INT(Spells, SacrificeMaxLevel, 69, "Last level the spell Sacrifice will work on")
RULE_INT(Spells, SacrificeItemID, 9963, "Item ID of the item Sacrifice will return (defaults to an Essence Emerald)")
RULE_BOOL(Spells, EnableSpellGlobals, false, "If enabled, spells check the spell_globals table and compare character data from their quest globals before allowing the spell to scribe with scribespells/traindiscs")
RULE_BOOL(Spells, EnableSpellBuckets, false, "If enabled, spells check the spell_buckets table and compare character data from their data buckets before allowing the spell to scribe with scribespells/traindiscs")
RULE_INT(Spells, MaxBuffSlotsNPC, 60, "Maximum number of NPC buff slots. The default value is the limit of the Titanium client")
RULE_INT(Spells, MaxSongSlotsNPC, 0, "Maximum number of NPC song slots. NPC don't have songs, so it should be 0")
RULE_INT(Spells, MaxDiscSlotsNPC, 0, "Maximum number of NPC disc slots. NPC don't have discs, so it should be 0")
RULE_INT(Spells, MaxTotalSlotsNPC, 60, "Maximum total of NPC slots. The default value is the limit of the Titanium client")
RULE_INT(Spells, MaxTotalSlotsPET, 30, "Maximum total of pet slots. The default value is the limit of the Titanium client")
RULE_BOOL (Spells, EnableBlockedBuffs, true, "Allow blocked spells")
RULE_INT(Spells, ReflectType, 4, "Reflect type. 0=disabled, 1=single target player spells only, 2=all player spells, 3=all single target spells, 4=all spells")
RULE_BOOL(Spells, ReflectMessagesClose, true, "True (Live functionality) is for Reflect messages to show to players within close proximity. False shows just player reflecting")
RULE_BOOL(Spells, LiveLikeFocusEffects, true, "Determines whether specific healing, dmg and mana reduction focuses are randomized")
RULE_INT(Spells, BaseImmunityLevel, 55, "The level that targets start to be immune to stun, fear and mez spells with a maximum level of 0")
RULE_BOOL(Spells, NPCIgnoreBaseImmunity, true, "Whether or not NPC get to ignore the BaseImmunityLevel for their spells")
RULE_REAL(Spells, AvgSpellProcsPerMinute, 6.0, "Adjust rate for sympathetic spell procs")
RULE_INT(Spells, ResistFalloff, 67, "Maximum that level that will adjust our resist chance based on level modifiers")
RULE_INT(Spells, CharismaEffectiveness, 10, "Determines how much resist modification charisma applies to charm/pacify checks. Default 10 CHA = -1 resist mod")
RULE_INT(Spells, CharismaEffectivenessCap, 255, "Determines how much resist modification charisma applies to charm/pacify checks. Default 10 CHA = -1 resist mod")
RULE_BOOL(Spells, CharismaCharmDuration, false, "Allow CHA resist mod to extend charm duration")
RULE_INT(Spells, CharmBreakCheckChance, 25, "Determines chance for a charm break check to occur each buff tick")
RULE_BOOL(Spells, CharmDisablesSpecialAbilities, false, "When charm is cast on an NPC, strip their special abilities")
RULE_INT(Spells, RootBreakFromSpells, 55, "Chance for root to break when cast on")
RULE_INT(Spells, DeathSaveCharismaMod, 3, "Determines how much charisma effects chance of death save firing")
RULE_INT(Spells, DivineInterventionHeal, 8000, "Divine intervention heal amount")
RULE_INT(Spells, AdditiveBonusWornType, 0, "Calc worn bonuses to add together (instead of taking highest) if set to THIS worn type. (2=Will covert live items automatically)")
RULE_BOOL(Spells, UseCHAScribeHack, false, "ScribeSpells and TrainDiscs quest functions will ignore entries where field 12 is CHA")
RULE_BOOL(Spells, BuffLevelRestrictions, true, "Buffs will not land on low level toons like live")
RULE_INT(Spells, RootBreakCheckChance, 70, "Determines chance for a root break check to occur each buff tick")
RULE_INT(Spells, FearBreakCheckChance, 70, "Determines chance for a fear break check to occur each buff tick")
RULE_INT(Spells, SuccorFailChance, 2, "Determines chance for a succor spell not to teleport an invidual player")
RULE_INT(Spells, FRProjectileItem_Titanium, 1113, "Item id for Titanium clients for Fire 'spell projectile'")
RULE_INT(Spells, FRProjectileItem_SOF, 80684, "Item id for SOF clients for Fire 'spell projectile'")
RULE_INT(Spells, FRProjectileItem_NPC, 80684, "Item id for NPC Fire 'spell projectile'")
RULE_BOOL(Spells, UseLiveSpellProjectileGFX, false, "Use spell projectile graphics set in the spells_new table (player_1). Server must be using UF+ spell file")
RULE_BOOL(Spells, FocusCombatProcs, false, "Allow all combat procs to receive focus effects")
RULE_BOOL(Spells, PreNerfBardAEDoT, false, "Allow bard AOE dots to damage targets when moving")
RULE_INT(Spells, AI_SpellCastFinishedFailRecast, 800, "AI spell recast time  when an spell is cast but fails, ie if stunned (milliseconds)")
RULE_INT(Spells, AI_EngagedNoSpellMinRecast, 500, "AI spell recast time check when no spell is cast while engaged. Min time in random (milliseconds)")
RULE_INT(Spells, AI_EngagedNoSpellMaxRecast, 1000, "AI spell recast time check when no spell is cast engaged. Mmaximum time in random (milliseconds)")
RULE_INT(Spells, AI_EngagedBeneficialSelfChance, 100, "Chance during first AI Cast check to do a beneficial spell on self")
RULE_INT(Spells, AI_EngagedBeneficialOtherChance, 25, "Chance during second AI Cast check to do a beneficial spell on others")
RULE_INT(Spells, AI_EngagedDetrimentalChance, 20, "Chance during third AI Cast check to do a determental spell on others")
RULE_INT(Spells, AI_PursueNoSpellMinRecast, 500, "AI spell recast time check when no spell is cast while chasing target. Mmin time in random (milliseconds)")
RULE_INT(Spells, AI_PursueNoSpellMaxRecast, 2000, "AI spell recast time check when no spell is cast while chasing target. Maximum time in random (milliseconds)")
RULE_INT(Spells, AI_PursueDetrimentalChance, 90, "Chance while chasing target to cast a detrimental spell")
RULE_INT(Spells, AI_IdleNoSpellMinRecast, 6000, "AI spell recast time check when no spell is cast while idle. Mmin time in random (milliseconds)")
RULE_INT(Spells, AI_IdleNoSpellMaxRecast, 60000, "AI spell recast time check when no spell is cast while chasing target. Maximum time in random (milliseconds)")
RULE_INT(Spells, AI_IdleBeneficialChance, 100, "Chance while idle to do a beneficial spell on self or others")
RULE_INT(Spells, AI_HealHPPct, 50, "Hitpoint percentage at which NPC starts healing when max_hp of the spell is not set (inside and outside combat)")
RULE_BOOL(Spells, SHDProcIDOffByOne, true, "Pre June 2009 SHD spell procs were off by 1, they stopped doing this in June 2009 (UF+ spell files need this false)")
RULE_BOOL(Spells, Jun182014HundredHandsRevamp, false, "This should be true for if you import a spell file newer than June 18, 2014")
RULE_BOOL(Spells, SwarmPetTargetLock, false, "Use old method of swarm pets target locking till target dies then despawning")
RULE_BOOL(Spells, NPC_UseFocusFromSpells, true, "Allow NPC to use most spell derived focus effects")
RULE_BOOL(Spells, NPC_UseFocusFromItems, false, "Allow NPC to use most item derived focus effects")
RULE_BOOL(Spells, UseAdditiveFocusFromWornSlot, false, "Allows an additive focus effect to be calculated from worn slot")
RULE_BOOL(Spells, AlwaysSendTargetsBuffs, false, "Ignore Leadership Alternate Abilities level if true")
RULE_BOOL(Spells, FlatItemExtraSpellAmt, false, "Allow SpellDmg stat to affect all spells, regardless of cast time/cooldown/etc")
RULE_BOOL(Spells, IgnoreSpellDmgLvlRestriction, false, "Ignore the 5 level spread on applying SpellDmg")
RULE_BOOL(Spells, ItemExtraSpellAmtCalcAsPercent, false, "Apply the Item stats Spell Dmg and Heal Amount as Percentage-based modifiers instead of flat additions")
RULE_REAL(Spells, BreakFeignDeathWhenCastOn, 2.0, "Percentage that Feign Death will break when you resist a spell")
RULE_REAL(Spells, BreakSneakWhenCastOn, 2.0, "Percentage that Sneak will break when you resist a spell")
RULE_BOOL(Spells, EnableResistSoftCap, false, "Enabled resist softcap and can be adjusted by rule, SpellResistSoftCap")
RULE_INT(Spells, SpellResistSoftCap, 255, "Softcap for spell resists.")
RULE_BOOL(Spells, AllowItemTGB, false, "Target group buff (/tgb) doesn't work with items on live, custom servers want it though")
RULE_BOOL(Spells, NPCInnateProcOverride, true, "NPC innate procs override the target type to single target")
RULE_BOOL(Spells, OldRainTargets, false, "Use old incorrectly implemented maximum targets for rains")
RULE_REAL(Spells, CallOfTheHeroAggroClearDist, 250.0, "Distance at which CoTH will wipe aggro. To disable and always enable aggro wipe on any distance of CoTH, set to 0.")
RULE_BOOL(Spells, NPCSpellPush, false, "Enable spell push on NPCs")
RULE_BOOL(Spells, July242002PetResists, true, "Enable Pets using PCs resist change from July 24 2002")
RULE_INT(Spells, AOEMaxTargets, 0, "Max number of targets a Targeted AOE spell can cast on. Set to 0 for no limit.")
RULE_BOOL(Spells, CazicTouchTargetsPetOwner, true, "If True, causes Cazic Touch to swap targets from pet to pet owner if a pet is tanking.")
RULE_BOOL(Spells, PreventFactionWarOnCharmBreak, false, "Enable spell interupts and dot removal on charm break to prevent faction wars.")
RULE_BOOL(Spells, AllowDoubleInvis, true, "Allows you to cast invisibility spells on a player that is already invisible, live like behavior.")
RULE_BOOL(Spells, AllowSpellMemorizeFromItem, false, "Allows players to memorize spells by right-clicking spell scrolls")
RULE_BOOL(Spells, InvisRequiresGroup, false, "Invis requires the the target to be in group.")
RULE_INT(Spells, ClericInnateHealFocus, 5, "Clerics on live get a 5 pct innate heal focus")
RULE_BOOL(Spells, DOTsScaleWithSpellDmg, false, "Allow SpellDmg stat to affect DoT spells")
RULE_BOOL(Spells, HOTsScaleWithHealAmt, false, "Allow HealAmt stat to affect HoT spells")
RULE_BOOL(Spells, CompoundLifetapHeals, true, "True: Lifetap heals calculate damage bonuses and then heal bonuses.  False:  Lifetaps heal using the amount damaged to mob.")
RULE_BOOL(Spells, UseFadingMemoriesMaxLevel, false, "Enables to limit field in spell data to set the max level that over which an NPC will ignore fading memories effect and not lose aggro.")
RULE_BOOL(Spells, FixBeaconHeading, false, "Beacon spells use casters heading to fix live bug.  False: Live like heading always 0.")
RULE_BOOL(Spells, UseSpellImpliedTargeting, false, "Replicates EQ2-style targeting behavior for spells. Spells will 'pass through' inappropriate targets to target's target if it is appropriate.")
RULE_BOOL(Spells, BuffsFadeOnDeath, true, "Disable to keep buffs from fading on death")
RULE_BOOL(Spells, IllusionsAlwaysPersist, false, "Allows Illusions to persist beyond death and zoning always.")
RULE_BOOL(Spells, UseItemCastMessage, false, "Enable to use the \"item begins to glow\" messages when casting from an item.")
RULE_BOOL(Spells, TargetsTargetRequiresCombatRange, true, "Disable to remove combat range requirement from Target's Target Spell Target Type")
RULE_BOOL(Spells, NPCBuffLevelRestrictions, false, "Impose BuffLevelRestrictions on NPCs if true")
RULE_INT(Spells, ResurrectionEffectBlock, 2, "0 = allow overwrites/rule disabled. If set to 1 = Block all buffs that would overwrite Resurrection Effects. If set to 2 = Will not overwrite Resurrection Effects, instead moves new buff to an empty slot if available. Default is 2.")
RULE_BOOL(Spells, WaterMatchRequiredForLoS, true, "Enable/Disable the requirement of both the attacker/victim being both in or out of water for spells LoS to pass.")
RULE_INT(Spells, WizardCritMinimumRandomRatio, 20, "The minimum value for the random range which Wizards and Caster DPS Mercs innately have for spell crit ratio. Set to 20 for vanilla values.")
RULE_INT(Spells, WizardCritMaximumRandomRatio, 70, "The maximum value for the random range which Wizards and Caster DPS Mercs innately have for spell crit ratio. Set to 70 for vanilla values.")
RULE_INT(Spells, DefensiveProcPenaltyLevelGap, 6, "Defensive Proc Penalty Level Gap where procs start losing their proc rate at RuleR(Spells, DefensiveProcPenaltyModifier)% per level difference")
RULE_REAL(Spells, DefensiveProcPenaltyLevelGapModifier, 10.0f, "Defensive Proc Penalty Level Gap Modifier where procs start losing their proc rate at defined % after RuleI(Spells, DefensiveProcLevelGap) level difference")
RULE_BOOL(Spells, DOTBonusDamageSplitOverDuration, true, "Disable to have Damage Over Time total bonus damage added to each tick instead of divided across duration")
RULE_BOOL(Spells, HOTBonusHealingSplitOverDuration, true, "Disable to have Heal Over Time total bonus healing added to each tick instead of divided across duration")
RULE_BOOL(Spells, UseLegacyFizzleCode, false, "Enable will turn on the legacy fizzle code which is far stricter and more accurate to 2001/2002 testing.")
RULE_BOOL(Spells, LegacyManaburn, false, "Enable to have the legacy manaburn system from 2003 and earlier.")
RULE_INT(Spells, LegacyManaburnCap, 9492, "Adjusted the hard cap (Normal or Crit) for the Legacy Manaburn system. DEFAULT: 9492")
RULE_BOOL(Spells, EvacClearAggroInSameZone, false, "Enable to clear aggro on clients when evacing in same zone.")
RULE_BOOL(Spells, CharmAggroOverLevel, false, "Enabling this rule will cause Charm casts over level to show resisted and cause aggro. Early EQ style.")
RULE_BOOL(Spells, RequireMnemonicRetention, true, "Enabling will require spell slots 9-12 to have the appropriate Mnemonic Retention AA learned.")
RULE_BOOL(Spells, EvacClearCharmPet, false, "Enable to have evac in zone clear charm from charm pets and detach buffs.")
RULE_BOOL(Spells, ManaTapsRequireNPCMana, false, "Enabling will require target to have mana to tap. Default off as many npc's are caster class with 0 mana and need fixed.")
RULE_INT(Spells, HarmTouchCritRatio, 200, "Harmtouch crit bonus, on top of BaseCritRatio")
RULE_BOOL(Spells, UseClassicSpellFocus, false, "Enabling will tell the server to handle random focus damage as classic spell imports lack the limit values.")
RULE_CATEGORY_END()

RULE_CATEGORY(Combat)
RULE_REAL(Combat, AERampageMaxDistance, 70, "Max AERampage range (% of max combat distance)")
RULE_INT(Combat, PetBaseCritChance, 0, "Pet base crit chance")
RULE_INT(Combat, NPCBashKickLevel, 6, "The level that NPCcan KICK/BASH")
RULE_INT(Combat, MeleeCritDifficulty, 8900, "Value against which is rolled to check if a melee crit is triggered. Lower is easier")
RULE_INT(Combat, ArcheryCritDifficulty, 3400, "Value against which is rolled to check if an archery crit is triggered. Lower is easier")
RULE_INT(Combat, ThrowingCritDifficulty, 1100, "Value against which is rolled to check if a throwing crit is triggered. Lower is easier")
RULE_BOOL(Combat, NPCCanCrit, false, "Setting whether an NPC can land critical hits")
RULE_BOOL(Combat, UseIntervalAC, true, "Switch whether bonuses, armour class, multipliers, classes and caps should be considered in the calculation of damage values")
RULE_INT(Combat, PetAttackMagicLevel, 10, "Level at which pets can cause magic damage, no longer used")
RULE_INT(Combat, NPCAttackMagicLevel, 10, "Level at which NPC and pets can cause magic damage")
RULE_BOOL(Combat, EnableFearPathing, true, "Setting whether to use pathing during fear")
RULE_BOOL(Combat, FleeGray, true, "If true FleeGrayHPRatio will be used")
RULE_INT(Combat, FleeGrayHPRatio, 50, "HP percentage when a Gray NPC begins to flee")
RULE_INT(Combat, FleeGrayMaxLevel, 18, "NPC above this level won't do gray/green con flee")
RULE_INT(Combat, FleeHPRatio, 25, "HP percentage when a NPC begins to flee")
RULE_BOOL(Combat, FleeIfNotAlone, false, "If false, mobs won't flee if other mobs are in combat with it")
RULE_BOOL(Combat, AdjustProcPerMinute, true, "Adapt the average proc rate to the speed of the weapon")
RULE_REAL(Combat, AvgProcsPerMinute, 2.0, "Average proc rate per minute")
RULE_REAL(Combat, ProcPerMinDexContrib, 0.075, "Increases the probability of a proc increased by DEX by the value indicated")
RULE_REAL(Combat, BaseProcChance, 0.035, "Base chance for procs")
RULE_REAL(Combat, ProcDexDivideBy, 11000, "Divisor for the probability of a proc increased by dexterity")
RULE_INT(Combat, MinRangedAttackDist, 25, "Minimum Distance to use Ranged Attacks")
RULE_BOOL(Combat, ArcheryBonusRequiresStationary, true, "does the 2x archery bonus chance require a stationary npc")
RULE_REAL(Combat, ArcheryNPCMultiplier, 1.0, "Value is multiplied by the regular dmg to get the archery dmg")
RULE_BOOL(Combat, AssistNoTargetSelf, true, "When assisting a target that does not have a target: true = target self, false = leave target as was before assist (false = live like)")
RULE_INT(Combat, MaxRampageTargets, 3, "Maximum number of people hit with rampage")
RULE_INT(Combat, DefaultRampageTargets, 1, "Default number of people to hit with rampage")
RULE_BOOL(Combat, RampageHitsTarget, false, "Rampage will hit the target if it still has targets left")
RULE_INT(Combat, MaxFlurryHits, 2, "Maximum number of extra hits from flurry")
RULE_INT(Combat, MinHastedDelay, 400, "Minimum hasted combat delay")
RULE_REAL(Combat, AvgDefProcsPerMinute, 2.0, "Average defense procs per minute")
RULE_REAL(Combat, DefProcPerMinAgiContrib, 0.075, "How much agility contributes to defensive proc rate")
RULE_INT(Combat, NPCFlurryChance, 20, "Chance for NPC to flurry")
RULE_BOOL(Combat, TauntOverLevel, 1, "Allows you to taunt NPC's over warriors level")
RULE_INT(Combat, TauntOverAggro, 0, "+ amount over hate_top it will add before any bonus hate.")
RULE_INT(Combat, TauntChanceBonus, 0, "Bonus to taunt chance")
RULE_BOOL(Combat, ClassicTauntSystem, false, "Enable to use the pre 2006 taunt system.")
RULE_REAL(Combat, TauntSkillFalloff, 0.33, "For every taunt skill point that's not maxed you lose this percentage chance to taunt")
RULE_BOOL(Combat, EXPFromDmgShield, false, "Determine if damage from a damage shield counts for experience gain")
RULE_INT(Combat, QuiverHasteCap, 1000, "Quiver haste cap 1000 on live for a while, currently 700 on live")
RULE_INT(Combat, BerserkerFrenzyStart, 35, "Percentage Health Points below which Warrior and Berserker start frenzy")
RULE_INT(Combat, BerserkerFrenzyEnd, 45, "Percentage Health Points above which Warrior and Berserker end frenzy")
RULE_BOOL(Combat, OneProcPerWeapon, true, "If enabled, One proc per weapon per round")
RULE_BOOL(Combat, ProjectileDmgOnImpact, true, "If enabled, projectiles (i.e. arrows) will hit on impact, instead of instantly")
RULE_BOOL(Combat, MeleePush, true, "Enable melee push")
RULE_INT(Combat, MeleePushChance, 50, "NPC chance the target will be pushed. Made up, 100 actually isn't that bad")
RULE_REAL(Combat, MeleePushForceClientPercent, 0.00, "Percent to add or remove from push for players")
RULE_REAL(Combat, MeleePushForcePetPercent, 0.00, "Percent to add or remove from push for pets")
RULE_BOOL(Combat, NPCtoNPCPush, false, "Disabled prevents NPC to NPC pushing per the 2013+ patch.")
RULE_BOOL(Combat, UseLiveCombatRounds, true, "Turn this false if you don't want to worry about fixing up combat rounds for NPCs")
RULE_INT(Combat, NPCAssistCap, 5, "Maximum number of NPC that will assist another NPC at once")
RULE_INT(Combat, NPCAssistCapTimer, 6000, "Time a NPC will take to clear assist aggro cap space (milliseconds)")
RULE_BOOL(Combat, UseRevampHandToHand, false, "Use h2h revamped dmg/delays I believe this was implemented during SoF")
RULE_BOOL(Combat, ClassicMasterWu, false, "Classic Master Wu uses a random special, modern doesn't")
RULE_REAL(Combat, HitBoxMod, 1.00, "Added to test hit boxes.")
RULE_INT(Combat, LevelToStopDamageCaps, 0, "Level to stop damage caps. 1 will effectively disable them, 20 should give basically same results as old incorrect system")
RULE_INT(Combat, LevelToStopACTwinkControl, 50, "Level to stop armorclass twink control. 1 will effectively disable it, 50 should give basically same results as current system")
RULE_BOOL(Combat, ClassicNPCBackstab, false, "True disables NPC facestab - NPC get normal attack if not behind")
RULE_BOOL(Combat, UseNPCDamageClassLevelMods, true, "Uses GetClassLevelDamageMod calc in npc_scale_manager")
RULE_BOOL(Combat, UseExtendedPoisonProcs, false, "Allow old school poisons to last until characrer zones, at a lower proc rate")
RULE_BOOL(Combat, EnableSneakPull, false, "Enable implementation of Sneak Pull")
RULE_INT(Combat, SneakPullAssistRange, 400, "Modified range of assist for sneak pull")
RULE_BOOL(Combat, Classic2HBAnimation, false, "2HB will use the 2 hand piercing animation instead of the overhead slashing animation")
RULE_BOOL(Combat, ArcheryConsumesAmmo, true, "Set to false to disable Archery Ammo Consumption")
RULE_BOOL(Combat, ThrowingConsumesAmmo, true, "Set to false to disable Throwing Ammo Consumption")
RULE_BOOL(Combat, UseLiveRiposteMechanics, false, "Set to true to disable SPA 173 SE_RiposteChance from making those with the effect on them immune to enrage, can longer riposte from a riposte.")
RULE_INT(Combat, FrontalStunImmunityClasses, 0, "Bitmask for Classes than have frontal stun immunity, No Races (0) by default.")
RULE_BOOL(Combat, NPCsUseFrontalStunImmunityClasses, false, "Enable or disable NPCs using frontal stun immunity Classes from Combat:FrontalStunImmunityClasses, false by default.")
RULE_INT(Combat, FrontalStunImmunityRaces, 512, "Bitmask for Races than have frontal stun immunity, Ogre (512) only by default.")
RULE_BOOL(Combat, NPCsUseFrontalStunImmunityRaces, true, "Enable or disable NPCs using frontal stun immunity Races from Combat:FrontalStunImmunityRaces, true by default.")
RULE_BOOL(Combat, AssassinateOnlyHumanoids, true, "Enable or disable Assassinate only being allowed on Humanoids, true by default.")
RULE_BOOL(Combat, HeadshotOnlyHumanoids, true, "Enable or disable Headshot only being allowed on Humanoids, true by default.")
RULE_BOOL(Combat, EnableWarriorShielding, true, "Enable or disable Warrior Shielding Ability (/shield), true by default.")
RULE_BOOL(Combat, BackstabIgnoresElemental, false, "Enable or disable Elemental weapon damage affecting backstab damage, false by default.")
RULE_BOOL(Combat, BackstabIgnoresBane, false, "Enable or disable Bane weapon damage affecting backstab damage, false by default.")
RULE_BOOL(Combat, SummonMeleeRange, true, "Enable or disable summoning of a player when already in melee range of the summoner.")
RULE_BOOL(Combat, WaterMatchRequiredForAutoFireLoS, true, "Enable/Disable the requirement of both the attacker/victim being both in or out of water for AutoFire LoS to pass.")
RULE_INT(Combat, ExtraAllowedKickClassesBitmask, 0, "Bitmask for allowing extra classes beyond Warrior, Ranger, Beastlord, and Berserker to kick, No Extra Classes (0) by default")
RULE_INT(Combat, MaxProcs, 4, "Adjustable maximum number of procs per round, the hard cap is MAX_PROCS (11). Requires mob repop or client zone when changed")
RULE_BOOL(Combat, FinishingBlowOnlyWhenFleeing, false, "Enable to only allow Finishing Blow when fleeing (Original Style Finishing Blow)")
RULE_BOOL(Combat, ClassicTripleAttack, false, "enable to use non-skill based classic triple attack. Originally it was Warrior Only but was expanded, can use the TripleAttackChance to tune the classes out.")
RULE_INT(Combat, ClassicTripleAttackChanceWarrior, 100, "Innate Chance for Warrior to Triple Attack after a Double Attack (125 = 12.5%). DEFAULT: 100")
RULE_INT(Combat, ClassicTripleAttackChanceMonk, 100, "Innate Chance for Monk to Triple Attack after a Double Attack (200 = 20%). DEFAULT: 100")
RULE_INT(Combat, ClassicTripleAttackChanceBerserker, 100, "Innate Chance for Berserker to Triple Attack after a Double Attack (200 = 20%). DEFAULT: 100")
RULE_INT(Combat, ClassicTripleAttackChanceRanger, 100, "Innate Chance for Ranger to Triple Attack after a Double Attack (200 = 20%). DEFAULT: 100")
RULE_INT(Combat, StunChance, 12, "Percent chance that client will be stunned when mob is behind player. DEFAULT: 12")
RULE_BOOL(Combat, BashTwoHanderUseShoulderAC, false, "Enable to use shoulder AC for bash calculations when two hander is equipped. Unproven if accurate DEFAULT: false")
RULE_REAL(Combat, BashACBonusDivisor, 25.0, "this divides the AC value contribution to bash damage, lower to increase damage")
RULE_CATEGORY_END()

RULE_CATEGORY(NPC)
RULE_INT(NPC, MinorNPCCorpseDecayTime, 450000, "NPC corpse decay time, if NPC below level 55 (milliseconds)")
RULE_INT(NPC, MajorNPCCorpseDecayTime, 1500000, "NPC corpse decay time, if NPC equal or greater than level 55 (milliseconds)")
RULE_INT(NPC, CorpseUnlockTimer, 150000, "Time after which corpses are unlocked for everyone to loot (milliseconds)")
RULE_INT(NPC, EmptyNPCCorpseDecayTime, 0, "NPC corpse decay time, if no items are left on the corpse (milliseconds)")
RULE_BOOL(NPC, UseItemBonusesForNonPets, true, "Switch whether item bonuses should be used for NPCs who are not pets")
RULE_BOOL(NPC, UseBaneDamage, false, "If NPCs can't inherently hit the target we don't add bane/magic dmg which isn't exactly the same as PCs")
RULE_INT(NPC, SayPauseTimeInSec, 5, "Time span in which an NPC pauses his movement after a Say event without aggro (seconds)")
RULE_INT(NPC, OOCRegen, 0, "Enable out-of-combat regeneration for NPC")
RULE_BOOL(NPC, BuffFriends, false, "Setting whether NPC should buff other NPC")
RULE_BOOL(NPC, EnableNPCQuestJournal, false, "Setting whether the NPC Quest Journal is active")
RULE_INT(NPC, LastFightingDelayMovingMin, 10000, "Minimum time before mob goes home after all aggro loss (milliseconds)")
RULE_INT(NPC, LastFightingDelayMovingMax, 20000, "Maximum time before mob goes home after all aggro loss (milliseconds)")
RULE_BOOL(NPC, SmartLastFightingDelayMoving, true, "When true, mobs that started going home previously will do so again immediately if still on FD hate list")
RULE_BOOL(NPC, ReturnNonQuestNoDropItems, false, "Returns NO DROP items on NPC that don't have an EVENT_TRADE sub in their script")
RULE_BOOL(NPC, ReturnQuestItemsFromNonQuestNPCs, false, "Returns Quest items traded to NPCs that are not flagged as a Quest NPC")
RULE_INT(NPC, StartEnrageValue, 9, " Percentage HP that an NPC will begin to enrage")
RULE_BOOL(NPC, LiveLikeEnrage, false, "If set to true then only player controlled pets will enrage")
RULE_BOOL(NPC, EnableMeritBasedFaction, false, "If set to true, faction will be given in the same way as experience (solo/group/raid)")
RULE_INT(NPC, NPCToNPCAggroTimerMin, 500, "Minimum time span after which one NPC aggro another NPC (milliseconds)")
RULE_INT(NPC, NPCToNPCAggroTimerMax, 6000, "Maximum time span after which one NPC aggro another NPC (milliseconds)")
RULE_BOOL(NPC, UseClassAsLastName, true, "Uses class archetype as LastName for NPC with none")
RULE_BOOL(NPC, NewLevelScaling, true, "Better level scaling, use old if new formulas would break your server")
RULE_REAL(NPC,NPCBackstabMod, 1.9, "Multiplier for NPC Backstab, Higher = Lower backstab amount")
RULE_INT(NPC, NPCGatePercent, 20, " Percentage at which the NPC Will attempt to gate at")
RULE_BOOL(NPC, NPCGateNearBind, false, "Will NPC attempt to gate when near bind location?")
RULE_INT(NPC, NPCGateDistanceBind, 75, "Distance from bind before NPC will attempt to gate")
RULE_BOOL(NPC, NPCHealOnGate, true, "Will the NPC Heal on Gate")
RULE_BOOL(NPC, UseMeditateBasedManaRegen, false, "Based NPC ooc regen on Meditate skill")
RULE_REAL(NPC, NPCHealOnGateAmount, 25, "How much the NPC will heal on gate if enabled")
RULE_BOOL(NPC, AnimalsOpenDoors, true, "Determines or not whether animals open doors or not when they approach them")
RULE_INT(NPC, MaxRaceID, 732, "Maximum Race ID, RoF2 by default supports up to 732")
RULE_BOOL(NPC, DisableLastNames, false, "Enable to disable NPC Last Names")
RULE_CATEGORY_END()

RULE_CATEGORY(Aggro)
RULE_BOOL(Aggro, SmartAggroList, true, "Smart aggro list attempts to choose targets in a much smarter fashion, prefering players to pets, sitting and critically injured players to normal players, and players in melee range to players not")
RULE_INT(Aggro, SittingAggroMod, 35, "Aggro increase against sitting targets. 35=35%")
RULE_INT(Aggro, MeleeRangeAggroMod, 10, "Aggro increase against targets in melee range. 10=10%")
RULE_INT(Aggro, CurrentTargetAggroMod, 0, "Aggro increase against current target. 0% = prefer the current target to any other. Makes it harder for our NPC to switch targets")
RULE_INT(Aggro, CriticallyWoundedAggroMod, 100, "Aggro increase against critical wounded targets")
RULE_INT(Aggro, SpellAggroMod, 100, "Aggro increase for spells")
RULE_INT(Aggro, PetSpellAggroMod, 10, "Aggro increase for pet spells")
RULE_REAL(Aggro, TunnelVisionAggroMod, 0.75, "People not currently the top hate generate this much hate on a Tunnel Vision mob")
RULE_INT(Aggro, MaxScalingProcAggro, 400, "Set to -1 for no limit. Maximum amount of aggro that HP scaling SPA effect in a proc will add")
RULE_INT(Aggro, IntAggroThreshold, 75, "Int lesser or equal the value will aggro regardless of level difference")
RULE_BOOL(Aggro, AllowTickPulling, false, "tick pulling is an exploit in an NPC's call for help fixed sometime in 2006 on live")
RULE_INT(Aggro, MinAggroLevel, 18, "Minimum level for use with UseLevelAggro")
RULE_BOOL(Aggro, UseLevelAggro, true, "MinAggroLevel rule value+ and Undead will aggro regardless of level difference. This will disabled Rule:IntAggroThreshold if set to true")
RULE_INT(Aggro, ClientAggroCheckMovingInterval, 1000, "Interval in which clients actually check for aggro while moving - in milliseconds - this should be lower than ClientAggroCheckIdleInterval")
RULE_INT(Aggro, ClientAggroCheckIdleInterval, 6000, "Interval in which clients actually check for aggro while idle - in milliseconds - this should be higher than ClientAggroCheckMovingInterval")
RULE_REAL(Aggro, PetAttackRange, 40000.0, "Maximum squared range /pet attack works at default is 200")
RULE_BOOL(Aggro, NPCAggroMaxDistanceEnabled, true, "If enabled, NPC's will drop aggro beyond 600 units or what is defined at the zone level")
RULE_BOOL(Aggro, AggroPlayerPets, false, "If enabled, NPCs will aggro player pets")
RULE_BOOL(Aggro, UndeadAlwaysAggro, true, "should undead always aggro?")
RULE_INT(Aggro, BardAggroCap, 40, "per song bard aggro cap.")
RULE_CATEGORY_END()

RULE_CATEGORY(TaskSystem)
RULE_BOOL(TaskSystem, EnableTaskSystem, true, "Globally enable or disable the Task system")
RULE_INT(TaskSystem, PeriodicCheckTimer, 5, "Seconds between checks for failed tasks. Also used by the 'Touch' activity")
RULE_BOOL(TaskSystem, RecordCompletedTasks, true, "Record completed tasks")
RULE_BOOL(TaskSystem, RecordCompletedOptionalActivities, false, "Record completed optional activities")
RULE_BOOL(TaskSystem, KeepOneRecordPerCompletedTask, true, "Keep only one record per completed task")
RULE_BOOL(TaskSystem, EnableTaskProximity, true, "Enable task proximity system")
RULE_INT(TaskSystem, RequestCooldownTimerSeconds, 15, "Seconds between allowing characters to request tasks (live-like default: 15 seconds)")
RULE_BOOL(TaskSystem, ExpRewardsIgnoreLevelBasedEXPMods, false, "Rewarding Level Based Exp will ignore Rule LevelBasedEXPMods if true")
RULE_INT(TaskSystem, SharedTasksWorldProcessRate, 6000, "Timer interval (milliseconds) that shared tasks are processed in world")
RULE_INT(TaskSystem, SharedTasksTerminateTimerMS, 120000, "Delay (milliseconds) until a shared task is terminated if requirements are no longer met after member removal (default: 2 minutes)")
RULE_BOOL(TaskSystem, UpdateOneElementPerTask, true, "If true (live-like) task updates only increment the first matching activity. If false all matching elements will be incremented.")
RULE_CATEGORY_END()

RULE_CATEGORY(Range)
RULE_INT(Range, Say, 15, "The range that is required before /say or hail messages will work to an NPC")
RULE_INT(Range, Emote, 135, "The packet range in which emote messages are sent'")
RULE_INT(Range, BeginCast, 200, "The packet range in which begin cast messages are sent")
RULE_INT(Range, Anims, 135, "The packet range in which begin cast messages are sent")
RULE_INT(Range, SpellParticles, 135, "The packet range in which spell particles are sent")
RULE_INT(Range, DamageMessages, 50, "The packet range in which damage messages are sent (non-crit)")
RULE_INT(Range, SpellMessages, 75, "The packet range in which spell damage messages are sent")
RULE_INT(Range, SongMessages, 75, "The packet range in which song messages are sent")
RULE_INT(Range, ClientPositionUpdates, 300, "Distance in which the own changed position is communicated to other clients")
RULE_INT(Range, CriticalDamage, 80, "The packet range in which critical hit messages are sent")
RULE_INT(Range, MobCloseScanDistance, 600, "Close scan distance")
RULE_INT(Range, MaxDistanceToClickDoors, 100, "Max distance that a client can click a door from (Client says 'You can't reach that' at roughly 25-50 for most doors)")
RULE_CATEGORY_END()

RULE_CATEGORY(Bots)
RULE_BOOL(Bots, Enabled, false, "Enable of disable bot functionality, default is false")
RULE_INT(Bots, BotExpansionSettings, 16383, "Sets the expansion settings for bot use. Defaults to all expansions enabled up to TSS")
RULE_BOOL(Bots, AllowCamelCaseNames, false, "Allows the use of 'MyBot' type names")
RULE_BOOL(Bots, AllowBotEquipAnyRaceGear, false, "Allows Bots to wear Equipment even if their race is not valid")
RULE_INT(Bots, CommandSpellRank, 1, "Filters bot command spells by rank. 1, 2 and 3 are valid filters - any other number allows all ranks")
RULE_INT(Bots, CreationLimit, 150, "Number of bots that each account can create")
RULE_BOOL(Bots, FinishBuffing, false, "Allow for buffs to complete even if the bot caster is out of mana. Only affects buffing out of combat")
RULE_BOOL(Bots, GroupBuffing, false, "Bots will cast single target buffs as group buffs, default is false for single. Does not make single target buffs work for MGB")
RULE_INT(Bots, HealRotationMaxMembers, 24, "Maximum number of heal rotation members")
RULE_INT(Bots, HealRotationMaxTargets, 12, "Maximum number of heal rotation targets")
RULE_REAL(Bots, ManaRegen, 2.0, "Adjust mana regen. Acts as a final multiplier, stacks with Rule Character:ManaRegenMultiplier.")
RULE_BOOL(Bots, PreferNoManaCommandSpells, true, "Give sorting priority to newer no-mana spells (i.e., 'Bind Affinity')")
RULE_BOOL(Bots, QuestableSpawnLimit, false, "Optional quest method to manage bot spawn limits using the quest_globals name bot_spawn_limit, see: /bazaar/Aediles_Thrall.pl")
RULE_INT(Bots, SpawnLimit, 71, "Number of bots a character can have spawned at one time, You + 71 bots is a 12 group pseudo-raid")
RULE_BOOL(Bots, BotGroupXP, false, "Determines whether client gets experience for bots outside their group")
RULE_BOOL(Bots, BotLevelsWithOwner, false, "Auto-updates spawned bots as owner levels/de-levels (false is original behavior)")
RULE_INT(Bots, BotCharacterLevel, 0, "If level is greater that value player can spawn bots if BotCharacterLevelEnabled is true")
RULE_INT(Bots, CasterStopMeleeLevel, 13, "Level at which caster bots stop melee attacks")
RULE_BOOL(Bots, AllowOwnerOptionAutoDefend, true, "When option is enabled, bots will defend their owner on enemy aggro")
RULE_REAL(Bots, LeashDistance, 562500.0f, "Distance a bot is allowed to travel from leash owner before being pulled back (squared value)")
RULE_BOOL(Bots, AllowApplyPoisonCommand, true, "Allows the use of the bot command 'applypoison'")
RULE_BOOL(Bots, AllowApplyPotionCommand, true, "Allows the use of the bot command 'applypotion'")
RULE_BOOL(Bots, RestrictApplyPotionToRogue, true, "Restricts the bot command 'applypotion' to rogue-usable potions (i.e., poisons)")
RULE_BOOL(Bots, OldRaceRezEffects, false, "Older clients had ID 757 for races with high starting STR, but it doesn't seem used anymore")
RULE_BOOL(Bots, ResurrectionSickness, true, "Use Resurrection Sickness based on Resurrection spell cast, set to false to disable Resurrection Sickness.")
RULE_INT(Bots, OldResurrectionSicknessSpell, 757, "757 is Default Old Resurrection Sickness Spell")
RULE_INT(Bots, ResurrectionSicknessSpell, 756, "756 is Default Resurrection Sickness Spell")
RULE_BOOL(Bots, AllowPickpocketCommand, true, "Allows the use of the bot command 'pickpocket'")
RULE_BOOL(Bots, BotHealOnLevel, false, "Setting whether a bot should heal completely when leveling. Default FALSE.")
RULE_INT(Bots, AutosaveIntervalSeconds, 300, "Number of seconds after which a timer is triggered which stores the bot data. The value 0 means no periodic automatic saving.")
RULE_BOOL(Bots, CazicTouchBotsOwner, true, "Default True. Cazic Touch/DT will hit bot owner rather than bot.")
RULE_INT(Bots, BotsClickItemsMinLvl, 1, "Minimum level for bots to be able to use ^clickitem. Default 1.")
RULE_BOOL(Bots, BotsCanClickItems, true, "Enabled the ability for bots to click items they have equipped. Default TRUE")
RULE_BOOL(Bots, CanClickMageEpicV1, true, "Whether or not bots are allowed to click Mage Epic 1.0. Default TRUE")
RULE_CATEGORY_END()

RULE_CATEGORY(Chat)
RULE_BOOL(Chat, ServerWideOOC, true, "Enable server wide ooc-chat")
RULE_BOOL(Chat, ServerWideAuction, true, "Enable server wide auction-chat")
RULE_BOOL(Chat, EnableVoiceMacros, true, "Enable voice macros")
RULE_BOOL(Chat, EnableMailKeyIPVerification, true, "Setting whether the authenticity of the client should be verified via its IP address when accessing the InGame mailbox")
RULE_BOOL(Chat, EnableAntiSpam, true, "Enable anti-spam system for chat")
RULE_BOOL(Chat, SuppressCommandErrors, false, "Do not suppress command errors by default")
RULE_BOOL(Chat, ChannelsIgnoreNameFilter, false, "Ignore name filtering when creating new chat channels")
RULE_INT(Chat, MaxPermanentPlayerChannels, 0, "Maximum number of permanent chat channels a player can make. Default 0.")
RULE_INT(Chat, MinStatusToBypassAntiSpam, 100, "Minimum status to bypass the anti-spam system")
RULE_INT(Chat, MinimumMessagesPerInterval, 4, "Minimum number of chat messages allowed per interval. The karma value is added to this value")
RULE_INT(Chat, MaximumMessagesPerInterval, 12, "Maximum value of chat messages allowed per interval")
RULE_INT(Chat, MaxMessagesBeforeKick, 20, "If an attempt is made to send more than the maximum allowed number of chat messages per interval, the client will be disconnected after this absolute number of messages")
RULE_INT(Chat, IntervalDurationMS, 60000, "Interval length in milliseconds")
RULE_INT(Chat, KarmaUpdateIntervalMS, 1200000, "Karma update interval in milliseconds")
RULE_INT(Chat, KarmaGlobalChatLimit, 72, "Amount of karma you need to be able to talk in ooc/auction/chat below the level limit")
RULE_INT(Chat, GlobalChatLevelLimit, 8, "Level limit you need to of reached to talk in ooc/auction/chat if your karma is too low")
RULE_BOOL(Chat, AutoInjectSaylinksToSay, true, "Automatically injects saylinks into dialogue that has [brackets in them]")
RULE_BOOL(Chat, AutoInjectSaylinksToClientMessage, true, "Automatically injects saylinks into dialogue that has [brackets in them]")
RULE_BOOL(Chat, QuestDialogueUsesDialogueWindow, false, "Pipes all quest dialogue to dialogue window")
RULE_BOOL(Chat, DialogueWindowAnimatesNPCsIfNoneSet, true, "If there is no animation specified in the dialogue window markdown then it will choose a random greet animation such as wave or salute")
RULE_CATEGORY_END()

RULE_CATEGORY(Merchant)
RULE_BOOL(Merchant, UsePriceMod, true, "Use faction/charisma price modifiers")
RULE_REAL(Merchant, SellCostMod, 1.05, "Modifier for NPC sell price")
RULE_REAL(Merchant, BuyCostMod, 0.95, "Modifier for NPC buy price")
RULE_INT(Merchant, PriceBonusPct, 4, "Determines maximum price bonus from having good faction/CHA. Value is a percent")
RULE_INT(Merchant, PricePenaltyPct, 4, "Determines maximum price penalty from having bad faction/CHA. Value is a percent")
RULE_REAL(Merchant, ChaBonusMod, 3.45, "Determines CHA cap, from 104 CHA. 3.45 is 132 CHA at apprehensive. 0.34 is 400 CHA at apprehensive")
RULE_REAL(Merchant, ChaPenaltyMod, 1.52, "Determines CHA bottom, up to 102 CHA. 1.52 is 37 CHA at apprehensive. 0.98 is 0 CHA at apprehensive")
RULE_BOOL(Merchant, EnableAltCurrencySell, true, "Enables the ability to resell items to alternate currency merchants")
RULE_BOOL(Merchant, AllowCorpse, false, "Setting whether dealers leave a corpse behind ")
RULE_CATEGORY_END()

RULE_CATEGORY(Bazaar)
RULE_BOOL(Bazaar, AuditTrail, false, "Setting whether a path to the trader should be displayed in the bazaar")
RULE_INT(Bazaar, MaxSearchResults, 50, "Maximum number of search results in Bazaar")
RULE_BOOL(Bazaar, EnableWarpToTrader, true, "Setting whether teleport to the selected trader should be active")
RULE_INT(Bazaar, MaxBarterSearchResults, 200, "The maximum results returned in the /barter search")
RULE_CATEGORY_END()

RULE_CATEGORY(Mail)
RULE_BOOL(Mail, EnableMailSystem, true, "Setting whether the mail system is activated. If false, client won't bring up the Mail window")
RULE_INT(Mail, ExpireTrash, 0, "Setting when the mail trash is emptied. Time in seconds. 0 will delete all messages in the trash when the mailserver starts")
RULE_INT(Mail, ExpireRead, 31536000, "Setting when read mails expire. 31536000=1 Year. Set to -1 for never")
RULE_INT(Mail, ExpireUnread, 31536000, "Setting when unread mails expire. 31536000=1 Year. Set to -1 for never")
RULE_CATEGORY_END()

RULE_CATEGORY(Channels)
RULE_INT(Channels, RequiredStatusAdmin, 251, "Required status to administer chat channels")
RULE_INT(Channels, RequiredStatusListAll, 251, "Required status to list all chat channels")
RULE_INT(Channels, DeleteTimer, 1440, "Empty password protected channels will be deleted after this many minutes")
RULE_CATEGORY_END()

RULE_CATEGORY(EventLog)
RULE_BOOL(EventLog, RecordSellToMerchant, false, "Record sales from a player to an NPC merchant in eventlog table")
RULE_BOOL(EventLog, RecordBuyFromMerchant, false, "Record purchases by a player from an NPC merchant in eventlog table")
RULE_CATEGORY_END()

RULE_CATEGORY(Adventure)
RULE_INT(Adventure, MinNumberForGroup, 2, "Minimum members for adventure group")
RULE_INT(Adventure, MaxNumberForGroup, 6, "Maximum members for adventure group")
RULE_INT(Adventure, MaxLevelRange, 9, "Maximum level range for adventure")
RULE_INT(Adventure, NumberKillsForBossSpawn, 45, "Number of adventure kills to make the boss spawn")
RULE_REAL(Adventure, DistanceForRescueAccept, 10000.0, "Distance for adventure rescue accept")
RULE_REAL(Adventure, DistanceForRescueComplete, 2500.0, "Distance for adventure rescue complete")
RULE_INT(Adventure, ItemIDToEnablePorts, 41000, "ItemID to enable adventure ports. 0 to disable, otherwise using a LDoN portal will require the user to have this item")
RULE_INT(Adventure, LDoNTrapDistanceUse, 625, "LDoN trap distance use")
RULE_REAL(Adventure, LDoNBaseTrapDifficulty, 15.0, "LDoN base trap difficulty")
RULE_REAL(Adventure, LDoNCriticalFailTrapThreshold, 10.0, "LDoN critical fail trap threshold")
RULE_INT(Adventure, LDoNLootCountModifier, 10, "LDoN Loot Count Modifier, lower is better (default is 10)")
RULE_CATEGORY_END()

RULE_CATEGORY(AA)
RULE_INT(AA, ExpPerPoint, 23976503, "Amount of experience per AA. Is the same as the amount of experience to go from level 51 to level 52")
RULE_BOOL(AA, NormalizedAAEnabled, false, "TSS+ change to AA that normalizes AA experience to a fixed # of white con kills independent of level")
RULE_INT(AA, NormalizedAANumberOfWhiteConPerAA, 25, "The number of white con kills per AA point")
RULE_BOOL(AA, ModernAAScalingEnabled, false, "Are we linearly scaling AA experience based on total # of earned AA?")
RULE_REAL(AA, ModernAAScalingStartPercent, 1000, "1000% or 10x AA experience at the start of the scaling range")
RULE_INT(AA, ModernAAScalingAAMinimum, 0, "The minimum number of earned AA before AA experience scaling begins")
RULE_INT(AA, ModernAAScalingAALimit, 4000, "The number of earned AA when AA experience scaling ends")
RULE_BOOL(AA, SoundForAAEarned, false, "Play sound when AA point earned")
RULE_INT(AA, UnusedAAPointCap, -1, "Cap for Unused AA Points.  Default: -1.  NOTE: DO NOT LOWER THIS WITHOUT KNOWING WHAT YOU ARE DOING. MAY RESULT IN PLAYERS LOSING AAs.")
RULE_CATEGORY_END()

RULE_CATEGORY(Console)
RULE_INT(Console, SessionTimeOut, 600000, "Amount of time in ms for the console session to time out")
RULE_CATEGORY_END()

RULE_CATEGORY(Network)
RULE_INT(Network, ResendDelayBaseMS, 100, "Base delay for resending data in EQStreamManager (milliseconds)")
RULE_REAL(Network, ResendDelayFactor, 1.5, "Multiplier for the base delay when resending data in EQStreamManager")
RULE_INT(Network, ResendDelayMinMS, 300, "Minimum timespan between two send retries (milliseconds)")
RULE_INT(Network, ResendDelayMaxMS, 5000, "Maximum timespan between two send retries (milliseconds)")
RULE_REAL(Network, ClientDataRate, 0.0, "KB / sec, 0.0 disabled")
RULE_BOOL(Network, CompressZoneStream, true, "Setting whether the zone stream should be compressed for transmission")
RULE_CATEGORY_END()

RULE_CATEGORY(QueryServ)
RULE_BOOL(QueryServ, PlayerLogChat, false, "Log player chat")
RULE_BOOL(QueryServ, PlayerLogTrades, false, "Log player trades")
RULE_BOOL(QueryServ, PlayerDropItems, false, "Log player dropping items")
RULE_BOOL(QueryServ, PlayerLogHandins, false, "Log player hand ins")
RULE_BOOL(QueryServ, PlayerLogNPCKills, false, "Log player NPC kills")
RULE_BOOL(QueryServ, PlayerLogDeletes, false, "Log player deletes")
RULE_BOOL(QueryServ, PlayerLogMoves, false, "Log player moves")
RULE_BOOL(QueryServ, PlayerLogMerchantTransactions, false, "Log merchant transactions")
RULE_BOOL(QueryServ, PlayerLogZone, false, "Log player zone events")
RULE_BOOL(QueryServ, PlayerLogDeaths, false, "Log player deaths")
RULE_BOOL(QueryServ, PlayerLogConnectDisconnect, false, "Logs player connect/disconnect state")
RULE_BOOL(QueryServ, PlayerLogLevels, false, "Log player leveling/deleveling")
RULE_BOOL(QueryServ, PlayerLogAARate, false, "Log player AA experience rates")
RULE_BOOL(QueryServ, PlayerLogQGlobalUpdate, false, "Log player QGlobal updates")
RULE_BOOL(QueryServ, PlayerLogTaskUpdates, false, "Log player Task updates")
RULE_BOOL(QueryServ, PlayerLogAAPurchases, false, "Log player AA purchases")
RULE_BOOL(QueryServ, PlayerLogTradeSkillEvents, false, "Log player tradeskill transactions")
RULE_BOOL(QueryServ, PlayerLogIssuedCommandes, false, "Log player issued commands")
RULE_BOOL(QueryServ, PlayerLogAlternateCurrencyTransactions, false, "Log player alternate currency transactions")
RULE_CATEGORY_END()

RULE_CATEGORY(Inventory)
RULE_BOOL(Inventory, EnforceAugmentRestriction, true, "Forces augment slot restrictions")
RULE_BOOL(Inventory, EnforceAugmentUsability, true, "Forces augmented item usability")
RULE_BOOL(Inventory, EnforceAugmentWear, true, "Forces augment wear slot validation")
RULE_BOOL(Inventory, DeleteTransformationMold, true, "False if you want mold to last forever")
RULE_BOOL(Inventory, AllowAnyWeaponTransformation, false, "Weapons can use any weapon transformation")
RULE_BOOL(Inventory, TransformSummonedBags, false, "Transforms summoned bags into disenchanted ones instead of deleting")
RULE_BOOL(Inventory, AllowMultipleOfSameAugment, false, "Allows multiple of the same augment to be placed in an item via #augmentitem or MQ2, set to true to allow")
RULE_INT(Inventory, AlternateAugmentationSealer, 53, "Allows RoF+ clients to augment items from a special container type")
RULE_CATEGORY_END()

RULE_CATEGORY(Client)
RULE_BOOL(Client, UseLiveFactionMessage, false, "Allows players to see detailed faction adjustments as on the live servers")
RULE_BOOL(Client, UseLiveBlockedMessage, false, "Setting whether detailed spell block messages should be used as on the live servers")
RULE_CATEGORY_END()

RULE_CATEGORY(Bugs)
RULE_BOOL(Bugs, ReportingSystemActive, true, "Activates bug reporting")
RULE_CATEGORY_END()

RULE_CATEGORY(Faction)
RULE_INT(Faction, AllyFactionMinimum, 1100, "Minimum faction for ally")
RULE_INT(Faction, WarmlyFactionMinimum, 750, "Minimum faction for warmly")
RULE_INT(Faction, KindlyFactionMinimum, 500, "Minimum faction for kindly")
RULE_INT(Faction, AmiablyFactionMinimum, 100, "Minimum faction for amiably")
RULE_INT(Faction, IndifferentlyFactionMinimum, 0, "Minimum faction for indifferently")
RULE_INT(Faction, ApprehensivelyFactionMinimum, -100, "Minimum faction for apprehensively")
RULE_INT(Faction, DubiouslyFactionMinimum, -500, "Minimum faction for dubiously")
RULE_INT(Faction, ThreateninglyFactionMinimum, -750, "Minimum faction for threateningly")
RULE_CATEGORY_END()

RULE_CATEGORY(Analytics)
RULE_BOOL(Analytics, CrashReporting, true, "Automatic crash reporting analytics for EQEmu Server developers")
RULE_CATEGORY_END()

RULE_CATEGORY(Logging)
RULE_BOOL(Logging, PrintFileFunctionAndLine, false, "Ex: [World Server] [net.cpp::main:309] Loading variables...")
RULE_BOOL(Logging, WorldGMSayLogging, true, "Relay worldserver logging to zone processes via GM say output")
RULE_BOOL(Logging, PlayerEventsQSProcess, false, "Have query server process player events instead of world. Useful when wanting to use a dedicated server and database for processing player events on separate disk")
RULE_INT(Logging, BatchPlayerEventProcessIntervalSeconds, 5, "This is the interval in which player events are processed in world or qs")
RULE_INT(Logging, BatchPlayerEventProcessChunkSize, 10000, "This is the cap of events that can be inserted into the queue before a force flush. This is to keep from hitting MySQL max_allowed_packet and killing the connection")
RULE_CATEGORY_END()

RULE_CATEGORY(HotReload)
RULE_BOOL(HotReload, QuestsRepopWithReload, true, "When a hot reload is triggered, the zone will repop")
RULE_BOOL(HotReload, QuestsRepopWhenPlayersNotInCombat, true, "When a hot reload is triggered, the zone will repop when no clients are in combat")
RULE_BOOL(HotReload, QuestsResetTimersWithReload, true, "When a hot reload is triggered, quest timers will be reset")
RULE_BOOL(HotReload, QuestsAutoReloadGlobalScripts, false, "When a quest, plugin, or global script changes, auto reload.")
RULE_CATEGORY_END()

RULE_CATEGORY(Expansion)
RULE_INT(Expansion, CurrentExpansion, -1, "The current expansion enabled for the server [-1 = ALL, 0 = Classic, 1 = Kunark etc.]")
RULE_BOOL(Expansion, UseCurrentExpansionAAOnly, false, "When true will only load AA ranks that match CurrentExpansion rule")
RULE_INT(Expansion, AutoGrantAAExpansion, -1, "Expansion to auto grant AAs up to, [-1 = Disabled, 0 = Classic, 1 = Kunark etc.]")
RULE_CATEGORY_END()

RULE_CATEGORY(Instances)
RULE_INT(Instances, ReservedInstances, 100, "Number of instance IDs which are reserved for globals. This value should not be changed while a server is running")
RULE_BOOL(Instances, RecycleInstanceIds, true, "Setting whether free instance IDs should be recycled to prevent them from gradually running out at 32k")
RULE_INT(Instances, GuildHallExpirationDays, 90, "Amount of days before a Guild Hall instance expires")
RULE_CATEGORY_END()

RULE_CATEGORY(Expedition)
RULE_INT(Expedition, MinStatusToBypassPlayerCountRequirements, 80, "Minimum GM status to bypass minimum player requirements for Expedition creation")
RULE_BOOL(Expedition, AlwaysNotifyNewLeaderOnChange, false, "Always notify clients when made expedition leader. If false (live-like) new leaders are only notified when made leader via /dzmakeleader")
RULE_REAL(Expedition, LockoutDurationMultiplier, 1.0, "Multiplies lockout duration by this value when new lockouts are added")
RULE_INT(Expedition, ChooseLeaderCooldownTime, 2000, "Cooldown time (milliseconds) between choosing a new leader for automatic leader changes")
RULE_CATEGORY_END()

RULE_CATEGORY(DynamicZone)
RULE_INT(DynamicZone, ClientRemovalDelayMS, 60000, "Delay (milliseconds) until a client is teleported out of dynamic zone after being removed as member")
RULE_BOOL(DynamicZone, EmptyShutdownEnabled, true, "Enable early instance shutdown for dynamic zones that have no members")
RULE_INT(DynamicZone, EmptyShutdownDelaySeconds, 1500, "Seconds to set dynamic zone instance expiration if early shutdown enabled")
RULE_BOOL(DynamicZone, EnableInDynamicZoneStatus, false, "Enables the 'In Dynamic Zone' member status in dynamic zone window. If false (live-like) players inside the dynamic zone will show as 'Online'")
RULE_INT(DynamicZone, WorldProcessRate, 6000, "Timer interval (milliseconds) that systems check their dynamic zone states")
RULE_CATEGORY_END()

RULE_CATEGORY(Cheat)
RULE_REAL(Cheat, MQWarpDetectionDistanceFactor, 9.0, "clients move at 4.4 about if in a straight line but with movement and to acct for lag we raise it a bit")
RULE_INT(Cheat, MQWarpExemptStatus, -1, "Required status level to exempt the MQWarpDetector. Set to -1 to disable this feature.")
RULE_INT(Cheat, MQZoneExemptStatus, -1, "Required status level to exempt the MQZoneDetector. Set to -1 to disable this feature.")
RULE_INT(Cheat, MQGateExemptStatus, -1, "Required status level to exempt the MQGateDetector. Set to -1 to disable this feature.")
RULE_INT(Cheat, MQGhostExemptStatus, -1, "Required status level to exempt the MQGhostDetector. Set to -1 to disable this feature.")
RULE_INT(Cheat, MQFastMemExemptStatus, -1, "Required status level to exempt the MQFastMemDetector. Set to -1 to disable this feature.")
RULE_BOOL(Cheat, EnableMQWarpDetector, true, "Enable the MQWarp Detector. Set to False to disable this feature.")
RULE_BOOL(Cheat, EnableMQZoneDetector, true, "Enable the MQZone Detector. Set to False to disable this feature.")
RULE_BOOL(Cheat, EnableMQGateDetector, true, "Enable the MQGate Detector. Set to False to disable this feature.")
RULE_BOOL(Cheat, EnableMQGhostDetector, true, "Enable the MQGhost Detector. Set to False to disable this feature.")
RULE_BOOL(Cheat, EnableMQFastMemDetector, true, "Enable the MQFastMem Detector. Set to False to disable this feature.")
RULE_BOOL(Cheat, MarkMQWarpLT, false, "Mark clients makeing smaller warps")
RULE_CATEGORY_END()

RULE_CATEGORY(Command)
RULE_BOOL(Command, DyeCommandRequiresDyes, false, "Enable this to require a Prismatic Dye (32557) each time someone uses #dye.")
RULE_BOOL(Command, HideMeCommandDisablesTells, true, "Disable this to allow tells to be received when using #hideme.")
RULE_CATEGORY_END()

RULE_CATEGORY(Doors)
RULE_BOOL(Doors, RequireKeyOnCursor, false, "Enable this to require pre-keyring keys to be on player cursor to open doors.")
RULE_CATEGORY_END()

RULE_CATEGORY(Items)
RULE_BOOL(Items, DisableAttuneable, false, "Enable this to disable Attuneable Items")
RULE_BOOL(Items, DisableBardFocusEffects, false, "Enable this to disable Bard Focus Effects on Items")
RULE_BOOL(Items, DisableLore, false, "Enable this to disable Lore Items")
RULE_BOOL(Items, DisableNoDrop, false, "Enable this to disable No Drop Items")
RULE_BOOL(Items, DisableNoPet, false, "Enable this to disable No Pet Items")
RULE_BOOL(Items, DisableNoRent, false, "Enable this to disable No Rent Items")
RULE_BOOL(Items, DisableNoTransfer, false, "Enable this to disable No Transfer Items")
RULE_BOOL(Items, DisablePotionBelt, false, "Enable this to disable Potion Belt Items")
RULE_BOOL(Items, DisableSpellFocusEffects, false, "Enable this to disable Spell Focus Effects on Items")
RULE_CATEGORY_END()

#undef RULE_CATEGORY
#undef RULE_INT
#undef RULE_REAL
#undef RULE_BOOL
#undef RULE_CATEGORY_END

/**
 * EQEmulator: Everquest Server Emulator
 * Copyright (C) 2001-2020 EQEmulator Development Team (https://github.com/EQEmu/Server)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY except by those people which sell it, which
 * are required to give you total support for your newly bought product;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#ifndef EXPEDITION_LOCKOUT_TIMER_H
#define EXPEDITION_LOCKOUT_TIMER_H

#include <chrono>
#include <string>

extern const char* const DZ_REPLAY_TIMER_NAME;

class ExpeditionLockoutTimer
{
public:
	ExpeditionLockoutTimer() = default;
	ExpeditionLockoutTimer(
		std::string expedition_uuid, std::string expedition_name,
		std::string event_name, uint64_t expire_time, uint32_t duration);

	static ExpeditionLockoutTimer CreateLockout(
		const std::string& expedition_name, const std::string& event_name,
		uint32_t seconds, std::string uuid = {});

	struct DaysHoursMinutes
	{
		std::string days;
		std::string hours;
		std::string mins;
	};

	void AddLockoutTime(int seconds);
	uint32_t GetDuration() const { return static_cast<uint32_t>(m_duration.count()); }
	uint64_t GetExpireTime() const { return std::chrono::system_clock::to_time_t(m_expire_time); }
	uint64_t GetStartTime() const { return std::chrono::system_clock::to_time_t(m_expire_time - m_duration); }
	uint32_t GetSecondsRemaining() const;
	DaysHoursMinutes GetDaysHoursMinutesRemaining() const;
	const std::string& GetExpeditionName() const { return m_expedition_name; }
	const std::string& GetExpeditionUUID() const { return m_expedition_uuid; }
	const std::string& GetEventName() const { return m_event_name; }
	bool IsExpired() const { return GetSecondsRemaining() == 0; }
	bool IsFromExpedition(const std::string& uuid) const { return uuid == m_expedition_uuid; }
	bool IsReplayTimer() const { return m_is_replay_timer; }
	bool IsSameLockout(const ExpeditionLockoutTimer& compare_lockout) const;
	bool IsSameLockout(const std::string& expedition_name, const std::string& event_name) const;
	void Reset() { m_expire_time = std::chrono::system_clock::now() + m_duration; }
	void SetDuration(uint32_t seconds) { m_duration = std::chrono::seconds(seconds); }
	void SetExpireTime(uint64_t expire_time) { m_expire_time = std::chrono::system_clock::from_time_t(expire_time); }
	void SetUUID(const std::string& uuid) { m_expedition_uuid = uuid; }

private:
	bool m_is_replay_timer = false;
	std::string m_expedition_uuid; // expedition received in
	std::string m_expedition_name;
	std::string m_event_name;
	std::chrono::seconds m_duration;
	std::chrono::time_point<std::chrono::system_clock> m_expire_time;
};

#endif

#ifndef __EQEMU_ZONE_COMMON_H
#define __EQEMU_ZONE_COMMON_H

#include "../common/types.h"
#include "../common/spdat.h"

#define	HIGHEST_RESIST 9 //Max resist type value
#define MAX_SPELL_PROJECTILE 10 //Max amount of spell projectiles that can be active by a single mob.

/* macros for IsAttackAllowed, IsBeneficialAllowed */
#define _CLIENT(x) (x && x->IsClient() && !x->CastToClient()->IsBecomeNPC())
#define _NPC(x) (x && x->IsNPC() && !x->CastToMob()->GetOwnerID())
#define _BECOMENPC(x) (x && x->IsClient() && x->CastToClient()->IsBecomeNPC())
#define _CLIENTCORPSE(x) (x && x->IsCorpse() && x->CastToCorpse()->IsPlayerCorpse() && !x->CastToCorpse()->IsBecomeNPCCorpse())
#define _NPCCORPSE(x) (x && x->IsCorpse() && (x->CastToCorpse()->IsNPCCorpse() || x->CastToCorpse()->IsBecomeNPCCorpse()))
#define _CLIENTPET(x) (x && x->CastToMob()->GetOwner() && x->CastToMob()->GetOwner()->IsClient())

//LOS Parameters:
#define HEAD_POSITION 0.9f	//ratio of GetSize() where NPCs see from
#define SEE_POSITION 0.5f	//ratio of GetSize() where NPCs try to see for LOS

#define ARCHETYPE_HYBRID	1
#define ARCHETYPE_CASTER	2
#define ARCHETYPE_MELEE		3

#define CON_GREEN		2
#define CON_LIGHTBLUE	18
#define CON_BLUE		4
#define CON_WHITE		10
#define CON_WHITE_TITANIUM		20
#define CON_YELLOW		15
#define CON_RED			13
#define CON_GRAY		6

#define DMG_BLOCKED		-1
#define DMG_PARRIED		-2
#define DMG_RIPOSTED		-3
#define DMG_DODGED		-4
#define DMG_INVULNERABLE	-5
#define DMG_RUNE		-6

//Spell specialization parameters, not sure of a better place for them
#define SPECIALIZE_FIZZLE 11		//% fizzle chance reduce at 200 specialized

//these are large right now because the x,y,z coords of the zone
//lines do not make a lot of sense
//Maximum distance from a zone point given that the request didnt
//know what zone that the line was for
#define ZONEPOINT_NOZONE_RANGE 40000.0f
//Maximum distance from a zone point if zone was specified
#define ZONEPOINT_ZONE_RANGE 40000.0f

// Defines based on the RoF2 Client
#define PET_HEALTHREPORT	0	// 0x00 - /pet health or Pet Window
#define PET_LEADER			1	// 0x01 - /pet leader or Pet Window
#define PET_ATTACK			2	// 0x02 - /pet attack or Pet Window
#define PET_QATTACK			3	// 0x03 - /pet qattack or Pet Window
#define PET_FOLLOWME		4	// 0x04 - /pet follow or Pet Window
#define PET_GUARDHERE		5	// 0x05 - /pet guard or Pet Window
#define PET_SIT				6	// 0x06 - /pet sit or Pet Window
#define PET_SITDOWN			7	// 0x07 - /pet sit on
#define PET_STANDUP			8	// 0x08 - /pet sit off
#define PET_STOP			9	// 0x09 - /pet stop or Pet Window - Not implemented
#define PET_STOP_ON			10	// 0x0a - /pet stop on - Not implemented
#define PET_STOP_OFF		11	// 0x0b - /pet stop off - Not implemented
#define PET_TAUNT			12	// 0x0c - /pet taunt or Pet Window
#define PET_TAUNT_ON		13	// 0x0d - /pet taunt on
#define PET_TAUNT_OFF		14	// 0x0e - /pet taunt off
#define PET_HOLD			15	// 0x0f - /pet hold or Pet Window, won't add to hate list unless attacking
#define PET_HOLD_ON			16	// 0x10 - /pet hold on
#define PET_HOLD_OFF		17	// 0x11 - /pet hold off
#define PET_GHOLD			18	// 0x12 - /pet ghold, will never add to hate list unless told to
#define PET_GHOLD_ON		19	// 0x13 - /pet ghold on
#define PET_GHOLD_OFF		20	// 0x14 - /pet ghold off
#define PET_SPELLHOLD		21	// 0x15 - /pet no cast or /pet spellhold or Pet Window
#define PET_SPELLHOLD_ON	22	// 0x16 - /pet spellhold on
#define PET_SPELLHOLD_OFF	23	// 0x17 - /pet spellhold off
#define PET_FOCUS			24	// 0x18 - /pet focus or Pet Window
#define PET_FOCUS_ON		25	// 0x19 - /pet focus on
#define PET_FOCUS_OFF		26	// 0x1a - /pet focus off
#define PET_FEIGN			27	// 0x1b - /pet feign
#define PET_BACKOFF			28	// 0x1c - /pet back off
#define PET_GETLOST			29	// 0x1d - /pet get lost
#define PET_GUARDME			30	// 0x1e - Same as /pet follow, but different message in older clients - define not from client /pet target in modern clients but doesn't send packet
#define PET_REGROUP			31	// 0x1f - /pet regroup, acts like classic hold. Stops attack and moves back to guard/you but doesn't clear hate list
#define PET_REGROUP_ON		32	// 0x20 - /pet regroup on, turns on regroup
#define PET_REGROUP_OFF		33	// 0x21 - /pet regroup off, turns off regroup
#define PET_MAXCOMMANDS		PET_REGROUP_OFF + 1

// can change the state of these buttons with a packet
#define PET_BUTTON_SIT			0
#define PET_BUTTON_STOP			1
#define PET_BUTTON_REGROUP		2
#define PET_BUTTON_FOLLOW		3
#define PET_BUTTON_GUARD		4
#define PET_BUTTON_TAUNT		5
#define PET_BUTTON_HOLD			6
#define PET_BUTTON_GHOLD		7
#define PET_BUTTON_FOCUS		8
#define PET_BUTTON_SPELLHOLD	9

#define AURA_HARDCAP		2
#define WEAPON_STANCE_TYPE_MAX 2


#define SHIELD_ABILITY_RECAST_TIME 180

typedef enum {	//focus types
	focusSpellHaste = 1,				//@Fc, SPA: 127, SE_IncreaseSpellHaste,				On Caster, cast time mod pct, base: pct
	focusSpellDuration,					//@Fc, SPA: 128, SE_IncreaseSpellDuration,			On Caster, spell duration mod pct, base: pct
	focusRange,							//@Fc, SPA: 129, SE_IncreaseRange,					On Caster, spell range mod pct, base: pct
	focusReagentCost,					//@Fc, SPA: 131, SE_ReduceReagentCost,				On Caster, do not consume reagent pct chance, base: min pct, limit: max pct
	focusManaCost,						//@Fc, SPA: 132, SE_ReduceManaCost,					On Caster, reduce mana cost by pct, base: min pct, limt: max pct
	focusImprovedHeal,					//@Fc, SPA: 125, SE_ImprovedHeal,					On Caster, spell healing mod pct, base: min pct, limit: max pct
	focusImprovedDamage,				//@Fc, SPA: 124, SE_ImprovedDamage,					On Caster, spell damage mod pct, base: min pct, limit: max pct
	focusImprovedDamage2,				//@Fc, SPA: 461, SE_ImprovedDamage2,				On Caster, spell damage mod pct, base: min pct, limit: max pct
	focusFcDamagePctCrit,				//@Fc, SPA: 302, SE_FcDamagePctCrit,				On Caster, spell damage mod pct, base: min pct, limit: max pct
	focusPetPower,						//@Fc, SPA: 167, SE_PetPowerIncrease,				On Caster, pet power mod, base: value
	focusResistRate,					//@Fc, SPA: 126, SE_SpellResistReduction,			On Caster, casted spell resist mod pct, base: min pct, limit: max pct
	focusSpellHateMod,					//@Fc, SPA: 130, SE_SpellHateMod,					On Caster, spell hate mod pct, base: min pct, limit: max pct
	focusTriggerOnCast,					//@Fc, SPA: 339, SE_TriggerOnCast,					On Caster, cast on spell use, base: chance pct limit: spellid
	focusSpellVulnerability,			//@Fc, SPA: 296, SE_FcSpellVulnerability,			On Target, spell damage taken mod pct, base: min pct, limit: max pct
	focusFcSpellDamagePctIncomingPC,	//@Fc, SPA: 483, SE_Fc_Spell_Damage_Pct_IncomingPC, On Target, spell damage taken mod pct, base: min pct, limit: max pct
	focusTwincast,						//@Fc, SPA: 399, SE_FcTwincast,						On Caster, chance cast spell twice, base: chance pct
	focusSympatheticProc,				//@Fc, SPA: 383, SE_SympatheticProc,				On Caster, cast on spell use, base: variable proc chance on cast time, limit: spellid
	focusFcDamageAmt,					//@Fc, SPA: 286, SE_FcDamageAmt,					On Caster, spell damage mod flat amt, base: amt
	focusFcDamageAmt2,					//@Fc, SPA: 462, SE_FcDamageAmt2,					On Caster, spell damage mod flat amt, base: amt
	focusFcDamageAmtCrit,				//@Fc, SPA: 303, SE_FFcDamageAmtCrit,				On Caster, spell damage mod flat amt, base: amt
	focusSpellDurByTic,					//@Fc, SPA: 287, SE_SpellDurationIncByTic,			On Caster, spell buff duration mod, base: tics
	focusSwarmPetDuration,				//@Fc, SPA: 398, SE_SwarmPetDuration,				On Caster, swarm pet duration mod, base: milliseconds
	focusReduceRecastTime,				//@Fc, SPA: 310, SE_ReduceReuseTimer,				On Caster, disc reuse time mod, base: milliseconds
	focusBlockNextSpell,				//@Fc, SPA: 335, SE_BlockNextSpellFocus,			On Caster, chance to block next spell, base: chance
	focusFcHealPctIncoming,				//@Fc, SPA: 393, SE_FcHealPctIncoming,   			On Target, heal received mod pct, base: pct
	focusFcDamageAmtIncoming,			//@Fc, SPA: 297, SE_FcDamageAmtIncoming,			On Target, damage taken flat amt, base: amt
	focusFcSpellDamageAmtIncomingPC,	//@Fc, SPA: 484, SE_Fc_Spell_Damage_Amt_IncomingPC,	On Target, damage taken flat amt, base: amt
	focusFcCastSpellOnLand,				//@Fc, SPA: 481, SE_Fc_Cast_Spell_On_Land,			On Target, cast spell if hit by spell, base: chance pct, limit: spellid
	focusFcHealAmtIncoming,				//@Fc, SPA: 394, SE_FcHealAmtIncoming,				On Target, heal received mod flat amt, base: amt
	focusFcBaseEffects,					//@Fc, SPA: 413, SE_FcBaseEffects,					On Caster, base spell effectiveness mod pct, base: pct
	focusIncreaseNumHits,				//@Fc, SPA: 421, SE_FcIncreaseNumHits,				On Caster, numhits mod flat amt, base: amt
	focusFcLimitUse,					//@Fc, SPA: 420, SE_FcLimitUse,						On Caster, numhits mod pct, base: pct
	focusFcMute,						//@Fc, SPA: 357, SE_FcMute,							On Caster, prevents spell casting, base: chance pct
	focusFcTimerRefresh,				//@Fc, SPA: 389, SE_FcTimerRefresh,					On Caster, reset spell recast timer, base: 1
	focusFcTimerLockout,				//@Fc, SPA: 390, SE_FcTimerLockout,					On Caster, set a spell to be on recast timer, base: recast duration milliseconds
	focusFcStunTimeMod,					//@Fc, SPA: 133, SE_FcStunTimeMod,					On Caster, stun time mod pct, base: chance pct
	focusFcResistIncoming,				//@Fc, SPA: 510, SE_Fc_Resist_Incoming,				On Target, resist modifier, base: amt
	focusFcAmplifyMod,					//@Fc, SPA: 507, SE_Fc_Amplify_Mod,					On Caster, damage-heal-dot mod pct, base: pct
	focusFcAmplifyAmt,					//@Fc, SPA: 508, SE_Fc_Amplify_Amt,					On Caster, damage-heal-dot mod flat amt, base: amt
	focusFcCastTimeMod2,				//@Fc, SPA: 500, SE_Fc_CastTimeMod2,				On Caster, cast time mod pct, base: pct
	focusFcCastTimeAmt,					//@Fc, SPA: 501, SE_Fc_CastTimeAmt,					On Caster, cast time mod flat amt, base: milliseconds
	focusFcHealPctCritIncoming,			//@Fc, SPA: 395, SE_FcHealPctCritIncoming,			On Target, spell healing mod pct, base: pct
	focusFcHealAmt,						//@Fc, SPA: 392, SE_FcHealAmt,						On Caster, spell healing mod flat amt, base: amt
	focusFcHealAmtCrit,					//@Fc, SPA: 396, SE_FcHealAmtCrit,					On Caster, spell healing mod flat amt, base: amt
} focusType; //Any new FocusType needs to be added to the Mob::IsFocus function
#define HIGHEST_FOCUS	focusFcHealAmtCrit //Should always be last focusType in enum

typedef enum {	//fear states
	fearStateNotFeared = 0,
	fearStateRunning,		//I am running, hoping to find a grid at my WP
	fearStateRunningForever,	//can run straight until spell ends
	fearStateGrid,			//I am allready on a fear grid
	fearStateStuck			//I cannot move somehow...
} FearState;

// This is actually FlyMode, from MQ2
enum GravityBehavior {
	Ground,
	Flying,
	Levitating,
	Water,
	Floating, // boat
	LevitateWhileRunning
};

class Trade;
enum TradeState {
	TradeNone,
	Trading,
	TradeAccepted,
	TradeCompleting
};

enum class NumHit {		  // Numhits type
	IncomingHitAttempts = 1,  // Attempted incoming melee attacks (hit or miss) on YOU.
	OutgoingHitAttempts = 2,  // Attempted outgoing melee attacks (hit or miss) on YOUR TARGET.
	IncomingSpells = 3,       // Incoming detrimental spells
	OutgoingSpells = 4,       // Outgoing detrimental spells
	OutgoingHitSuccess = 5,   // Successful outgoing melee attack HIT on YOUR TARGET.
	IncomingHitSuccess = 6,   // Successful incoming melee attack HIT on YOU.
	MatchingSpells = 7,       // Any casted spell matching/triggering a focus effect.
	IncomingDamage = 8,       // Successful incoming spell or melee dmg attack on YOU
	ReflectSpell = 9,	 // Incoming Reflected spells.
	DefensiveSpellProcs = 10, // Defensive buff procs
	OffensiveSpellProcs = 11  // Offensive buff procs
};

enum class PlayerState : uint32 {
	None = 0,
	Open = 1,
	WeaponSheathed = 2,
	Aggressive = 4,
	ForcedAggressive = 8,
	InstrumentEquipped = 16,
	Stunned = 32,
	PrimaryWeaponEquipped = 64,
	SecondaryWeaponEquipped = 128
};

enum class LootResponse : uint8 {
	SomeoneElse = 0,
	Normal = 1,
	NotAtThisTime = 2,
	Normal2 = 3, // acts exactly the same as Normal, maybe group vs ungroup? No idea
	Hostiles = 4,
	TooFar = 5,
	LootAll = 6 // SoD+
};

enum class LootRequestType : uint8 {
	Forbidden = 0,
	GMPeek,
	GMAllowed,
	Self,
	AllowedPVE,
	AllowedPVPAll,
	AllowedPVPSingle, // can make this 'AllowedPVPVariable' and allow values between 1 and EQ::invtype::POSSESSIONS_SIZE
	AllowedPVPDefined,
};

enum class KilledByTypes : uint8 {
	Killed_NPC = 0,
	Killed_DUEL = 1,
	Killed_PVP = 2
};

namespace Journal {
	enum class SpeakMode : uint8 {
		Raw = 0,	// this just uses the raw message
		Say = 1,	// prints with "%1 says,%2 '%3'" if in another language else "%1 says '%2'"
		Shout = 2,	// prints with "%1 shouts,%2 '%3'" if in another language else "%1 shouts '%2'"
		EmoteAlt = 3,	// prints "%2", this should just be the same as raw ...
		Emote = 4,	// prints "%1 %2" if message doesn't start with "\" or "@", else "%1%2"
		Group = 5	// prints "%1 tells the group,%2 '%3'"
	};

	enum class Mode : uint8 {
		None = 0,
		Log1 = 1, // 1 and 2 log to journal
		Log2 = 2, // our current code uses 2
	};

	struct Options {
		SpeakMode speak_mode;
		Mode journal_mode;
		int8 language;
		uint32 message_type;
		uint32 target_spawn_id; // who the message is talking to (limits journaling)
	};
};

//this is our internal representation of the BUFF struct, can put whatever we want in it
struct Buffs_Struct {
	uint16	spellid;
	uint8	casterlevel;
	uint16	casterid;		// Maybe change this to a pointer sometime, but gotta make sure it's 0'd when it no longer points to anything
	char	caster_name[64];
	int32	ticsremaining;
	uint32	counters;
	uint32	hit_number; //the number of physical hits this buff can take before it fades away, lots of druid armor spells take advantage of this mixed with powerful effects
	uint32	melee_rune;
	uint32	magic_rune;
	uint32	dot_rune;
	int32	caston_x;
	int32	caston_y;
	int32	caston_z;
	int32	ExtraDIChance;
	int16	RootBreakChance; //Not saved to dbase
	uint32	instrument_mod;
	int32	virus_spread_time; //time till next attempted viral spread
	bool	persistant_buff;
	bool	client; //True if the caster is a client
	bool	UpdateClient;
};

struct StatBonuses {
	int32	AC;
	int64	HP;
	int64	HPRegen;
	int64	MaxHP;
	int64	ManaRegen;
	int64	EnduranceRegen;
	int64	Mana;
	int64	Endurance;
	int32	ATK;
	//would it be worth it to create a Stat_Struct?
	int32	STR;
	int32	STRCapMod;
	int32	HeroicSTR;
	int32	STA;
	int32	STACapMod;
	int32	HeroicSTA;
	int32	DEX;
	int32	DEXCapMod;
	int32	HeroicDEX;
	int32	AGI;
	int32	AGICapMod;
	int32	HeroicAGI;
	int32	INT;
	int32	INTCapMod;
	int32	HeroicINT;
	int32	WIS;
	int32	WISCapMod;
	int32	HeroicWIS;
	int32	CHA;
	int32	CHACapMod;
	int32	HeroicCHA;
	int32	MR;
	int32	MRCapMod;
	int32	HeroicMR;
	int32	FR;
	int32	FRCapMod;
	int32	HeroicFR;
	int32	CR;
	int32	CRCapMod;
	int32	HeroicCR;
	int32	PR;
	int32	PRCapMod;
	int32	HeroicPR;
	int32	DR;
	int32	DRCapMod;
	int32	HeroicDR;
	int32	Corrup;
	int32	CorrupCapMod;
	int32	HeroicCorrup;
	uint16	DamageShieldSpellID;
	int		DamageShield;						// this is damage done to mobs that attack this
	DmgShieldType	DamageShieldType;
	int		SpellDamageShield;
	int		SpellShield;
	int		ReverseDamageShield;				// this is damage done to the mob when it attacks
	uint16	ReverseDamageShieldSpellID;
	DmgShieldType	ReverseDamageShieldType;
	int		movementspeed;
	int32	haste;
	int32	hastetype2;
	int32	hastetype3;
	int32	inhibitmelee;
	float	AggroRange;							// when calculate just replace original value with this
	float	AssistRange;
	int32	skillmod[EQ::skills::HIGHEST_SKILL + 1];
	int32	skillmodmax[EQ::skills::HIGHEST_SKILL + 1];
	int		effective_casting_level;
	int		adjusted_casting_skill;				// SPA 112 for fizzles
	int		reflect[3];					// chance to reflect incoming spell [0]=Chance [1]=Resist Mod [2]= % of Base Dmg
	uint32	singingMod;
	uint32	Amplification;						// stacks with singingMod
	uint32	brassMod;
	uint32	percussionMod;
	uint32	windMod;
	uint32	stringedMod;
	uint32	songModCap;
	int32	hatemod;
	int64	EnduranceReduction;

	int32	StrikeThrough;						// PoP: Strike Through %
	int32	MeleeMitigation;					//i = Shielding
	int32	MeleeMitigationEffect;				//i = Spell Effect Melee Mitigation
	int32	CriticalHitChance[EQ::skills::HIGHEST_SKILL + 2];	//i
	int32	CriticalSpellChance;				//i
	int32	SpellCritDmgIncrease;				//i
	int32	SpellCritDmgIncNoStack;				// increase
	int32	DotCritDmgIncrease;					//i
	int32	CriticalHealChance;					//i
	int32	CriticalHealOverTime;				//i
	int32	CriticalDoTChance;					//i
	int32	CrippBlowChance;					//
	int32	AvoidMeleeChance;					//AvoidMeleeChance/10 == % chance i = Avoidance (item mod)
	int32	AvoidMeleeChanceEffect;				//AvoidMeleeChance Spell Effect
	int32	RiposteChance;						//i
	int32	DodgeChance;						//i
	int32	ParryChance;						//i
	int32	DualWieldChance;					//i
	int32	DoubleAttackChance;					//i
	int32	TripleAttackChance;					//i
	int32   DoubleRangedAttack;				//i
	int32	ResistSpellChance;					//i
	int32	ResistFearChance;					//i
	bool	Fearless;							//i
	bool	IsFeared;							//i
	bool	IsBlind;							//i
	int32	StunResist;							//i
	int32	MeleeSkillCheck;					//i
	uint8	MeleeSkillCheckSkill;
	int32	HitChance;							//HitChance/15 == % increase i = Accuracy (Item: Accuracy)
	int32	HitChanceEffect[EQ::skills::HIGHEST_SKILL + 2];	//Spell effect Chance to Hit, straight percent increase
	int32	DamageModifier[EQ::skills::HIGHEST_SKILL + 2];	//i
	int32	DamageModifier2[EQ::skills::HIGHEST_SKILL + 2];	//i
	int32	DamageModifier3[EQ::skills::HIGHEST_SKILL + 2];	//i
	int32	MinDamageModifier[EQ::skills::HIGHEST_SKILL + 2]; //i
	int32	ProcChance;							// ProcChance/10 == % increase i = CombatEffects
	int32	ProcChanceSPA;						// ProcChance from spell effects
	int32	ExtraAttackChance[2];				// base chance(w/ 2H weapon)=0, amt of extra attacks=1
	int32	ExtraAttackChancePrimary[2];		// base chance=0, , amt of extra attacks=1
	int32	ExtraAttackChanceSecondary[2];		// base chance=0, , amt of extra attacks=1
	int32	DoubleMeleeRound[2];				// base chance=0, damage mod=1
	int32	DoTShielding;
	int32	DivineSaveChance[2];				// Second Chance (base1 = chance, base2 = spell on trigger)
	uint32	DeathSave[4];						// Death Pact [0](value = 1 partial 2 = full) [1]=slot [2]=LvLimit [3]=HealAmt
	int32	FlurryChance;
	int32	Accuracy[EQ::skills::HIGHEST_SKILL + 2];			//Accuracy/15 == % increase	[Spell Effect: Accuracy)
	int32	HundredHands;						//extra haste, stacks with all other haste	i
	int32	MeleeLifetap;						//i
	int32	Vampirism;							//i
	int32	HealRate;							// Spell effect that influences effectiveness of heals
	int32	MaxHPChange;						// Spell Effect
	int16	SkillDmgTaken[EQ::skills::HIGHEST_SKILL + 2];		// All Skills + -1
	int32	HealAmt;							// Item Effect
	int32	SpellDmg;							// Item Effect
	int32	Clairvoyance;						// Item Effect
	int32	DSMitigation;						// Item Effect
	int32	DSMitigationOffHand;				// Lowers damage shield from off hand attacks.
	uint32	SpellTriggers[MAX_SPELL_TRIGGER];	// Innate/Spell/Item Spells that trigger when you cast
	uint32	SpellOnKill[MAX_SPELL_TRIGGER*3];	// Chance to proc after killing a mob
	uint32	SpellOnDeath[MAX_SPELL_TRIGGER*2];	// Chance to have effect cast when you die
	int32	CritDmgMod[EQ::skills::HIGHEST_SKILL + 2];		// All Skills + -1
	int32	CritDmgModNoStack[EQ::skills::HIGHEST_SKILL + 2];// Critical melee damage modifier by percent, does not stack.
	int32	SkillReuseTime[EQ::skills::HIGHEST_SKILL + 1];	// Reduces skill timers
	int32	SkillDamageAmount[EQ::skills::HIGHEST_SKILL + 2];	// All Skills + -1
	int32	TwoHandBluntBlock;					// chance to block when wielding two hand blunt weapon
	uint32	ItemManaRegenCap;					// Increases the amount of mana you have can over the cap(aa effect)
	int32	GravityEffect;						// Indictor of spell effect
	bool	AntiGate;							// spell effect that prevents gating
	bool	MagicWeapon;						// spell effect that makes weapon magical
	int32	IncreaseBlockChance;				// overall block chance modifier
	uint32	PersistantCasting;					// chance to continue casting through a stun
	int	XPRateMod;							//i
	int		HPPercCap[2];						//Spell effect that limits you to being healed/regening beyond a % of your max
	int		ManaPercCap[2];						// ^^ 0 = % Cap 1 = Flat Amount Cap
	int		EndPercCap[2];						// ^^
	bool	ImmuneToFlee;						// Bypass the fleeing flag
	uint32	VoiceGraft;							// Stores the ID of the mob with which to talk through
	int32	SpellProcChance;					// chance to proc from sympathetic spell effects
	int32	CharmBreakChance;					// chance to break charm
	int32	SongRange;							// increases range of beneficial bard songs
	uint32	HPToManaConvert;					// Uses HP to cast spells at specific conversion
	int32	FocusEffects[HIGHEST_FOCUS+1];		// Stores the focus effectid for each focustype you have.
	int16	FocusEffectsWorn[HIGHEST_FOCUS+1];	// Optional to allow focus effects to be applied additively from worn slot
	bool	NegateEffects;						// Check if you contain a buff with negate effect. (only spellbonuses)
	int32	SkillDamageAmount2[EQ::skills::HIGHEST_SKILL + 2];	// Adds skill specific damage
	uint32	NegateAttacks[3];					// 0 = bool HasEffect 1 = Buff Slot 2 = Max damage absorbed per hit
	uint32	MitigateMeleeRune[4];				// 0 = Mitigation value 1 = Buff Slot 2 = Max mitigation per hit 3 = Rune Amt
	uint32	MeleeThresholdGuard[3];				// 0 = Mitigation value 1 = Buff Slot 2 = Min damage to trigger.
	uint32	SpellThresholdGuard[3];				// 0 = Mitigation value 1 = Buff Slot 2 = Min damage to trigger.
	uint32	MitigateSpellRune[4];				// 0 = Mitigation value 1 = Buff Slot 2 = Max mitigation per spell 3 = Rune Amt
	uint32	MitigateDotRune[4];					// 0 = Mitigation value 1 = Buff Slot 2 = Max mitigation per tick 3 = Rune Amt
	bool	TriggerMeleeThreshold;				// Has Melee Threshhold
	bool	TriggerSpellThreshold;				// Has Spell Threshhold
	uint32	ManaAbsorbPercentDamage;			// 0 = Mitigation value
	int32	EnduranceAbsorbPercentDamage[2];	// 0 = Mitigation value 1 = Percent Endurance drain per HP lost
	int32	ShieldBlock;						// Chance to Shield Block
	int32	BlockBehind;						// Chance to Block Behind (with our without shield)
	bool	CriticalRegenDecay;					// increase critical regen chance, decays based on spell level cast
	bool	CriticalHealDecay;					// increase critical heal chance, decays based on spell level cast
	bool	CriticalDotDecay;					// increase critical dot chance, decays based on spell level cast
	bool	DivineAura;							// invulnerability
	bool	DistanceRemoval;					// Check if Cancle if Moved effect is present
	int32	ImprovedTaunt[3];					// 0 = Max Level 1 = Aggro modifier 2 = buff slot
	int8	Root[2];							// The lowest buff slot a root can be found. [0] = Bool if has root [1] = buff slot
	int32	FrenziedDevastation;				// base1= AArank(used) base2= chance increase spell criticals + all DD spells 2x mana.
	uint32	AbsorbMagicAtt[2];					// 0 = magic rune value 1 = buff slot
	uint32	MeleeRune[2];						// 0 = rune value 1 = buff slot
	bool	NegateIfCombat;						// Bool Drop buff if cast or melee
	int8	Screech;							// -1 = Will be blocked if another Screech is +(1)
	int32	AlterNPCLevel;						// amount of lvls +/-
	int32	AStacker[2];						// For buff stack blocking 0=Exists 1=Effect_value
	int32	BStacker[2];						// For buff stack blocking 0=Exists 1=Effect_value
	int32	CStacker[2];						// For buff stack blocking 0=Exists 1=Effect_value
	int32	DStacker[2];						// For buff stack blocking 0=Exists 1=Effect_value
	bool	BerserkSPA;							// berserk effect
	int32	Metabolism;							// Food/drink consumption rates.
	bool	Sanctuary;							// Sanctuary effect, lowers place on hate list until cast on others.
	int32   FactionModPct;						// Modifies amount of faction gained.
	bool	LimitToSkill[EQ::skills::HIGHEST_SKILL + 3];		// Determines if we need to search for a skill proc.
	int32  SkillProc[MAX_SKILL_PROCS];			// Max number of spells containing skill_procs.
	int32  SkillProcSuccess[MAX_SKILL_PROCS];	// Max number of spells containing skill_procs_success.
	int32   SpellProc[MAX_AA_PROCS];		// Max number of spells containing melee spell procs.
	int32   RangedProc[MAX_AA_PROCS];	    // Max number of spells containing ranged spell procs.
	int32   DefensiveProc[MAX_AA_PROCS];	// Max number of spells containing defensive spell procs.
	bool	Proc_Timer_Modifier;				// Used to check if this exists, to avoid any further unnncessary checks.
	uint32  PC_Pet_Rampage[2];					// 0= % chance to rampage, 1=damage modifier
	uint32  PC_Pet_AE_Rampage[2];				// 0= % chance to AE rampage, 1=damage modifier
	uint32  PC_Pet_Flurry;						// Percent chance flurry from double attack
	int32   Attack_Accuracy_Max_Percent;		// Increase ATK accuracy by percent.
	int32   AC_Mitigation_Max_Percent;			// Increase AC mitigation by percent
	int32   AC_Avoidance_Max_Percent;			// Increase AC avoidance by percent
	int32   Damage_Taken_Position_Mod[2];		// base = percent melee damage reduction base2 0=back 1=front. [0]Back[1]Front
	int32   Melee_Damage_Position_Mod[2];		// base = percent melee damage increase base2 0=back 1=front. [0]Back[1]Front
	int32   Damage_Taken_Position_Amt[2];		// base = flat amt melee damage reduction base2 0=back 1=front. [0]Back[1]Front
	int32   Melee_Damage_Position_Amt[2];		// base = flat amt melee damage increase base2 0=back 1=front. [0]Back[1]Front
	int32   Double_Backstab_Front;				// base = percent chance to double back stab front
	int32   DS_Mitigation_Amount;				// base = flat amt DS mitigation. Negative value to reduce
	int32	DS_Mitigation_Percentage;			// base = percent amt of DS mitigation. Negative value to reduce
	int32   Pet_Crit_Melee_Damage_Pct_Owner;	// base = percent mod for pet critcal damage from owner
	int32	Pet_Add_Atk;						// base = Pet ATK bonus from owner
	int32	ItemEnduranceRegenCap;				// modify endurance regen cap
	int32   WeaponStance[WEAPON_STANCE_TYPE_MAX +1];// base = trigger spell id, base2 = 0 is 2h, 1 is shield, 2 is dual wield, [0]spid 2h, [1]spid shield, [2]spid DW
	bool	ZoneSuspendMinion;					// base 1 allows suspended minions to zone
	bool	CompleteHealBuffBlocker;			// Use in SPA 101 to prevent recast of complete heal from this effect till blocker buff is removed.
	int32	Illusion;							// illusion spell id
	uint8	invisibility;						// invisibility level
	uint8	invisibility_verse_undead;			// IVU level
	uint8	invisibility_verse_animal;			// IVA level

	// AAs
	int32	TrapCircumvention;					// reduce chance to trigger a trap.
	uint16  SecondaryForte;						// allow a second skill to be specialized with a cap of this value.
	int32	ShieldDuration;						// extends duration of /shield ability
	int32	ExtendedShielding;					// extends range of /shield ability
	int8	Packrat;							// weight reduction for items, 1 point = 10%
	uint8	BuffSlotIncrease;					// Increases number of available buff slots
	uint32	DelayDeath;							// how far below 0 hp you can go
	int8	BaseMovementSpeed;					// Adjust base run speed, does not stack with other movement bonuses.
	uint8	IncreaseRunSpeedCap;				// Increase max run speed above cap.
	int32	DoubleSpecialAttack;				// Chance to to perform a double special attack (ie flying kick 2x)
	int32	SkillAttackProc[MAX_CAST_ON_SKILL_USE];					// [0] chance to proc [2] spell on [1] skill usage
	bool	HasSkillAttackProc[EQ::skills::HIGHEST_SKILL + 1]; //check if any skill proc is present before assessing for all skill procs
	uint8	FrontalStunResist;					// Chance to resist a frontal stun
	int32	BindWound;							// Increase amount of HP by percent.
	int32	MaxBindWound;						// Increase max amount of HP you can bind wound.
	int32	ChannelChanceSpells;				// Modify chance to channel a spell.
	int32	ChannelChanceItems;					// Modify chance to channel a items.
	uint8	SeeInvis;							// See Invs.
	uint8	TripleBackstab;						// Chance to triple backstab
	bool	FrontalBackstabMinDmg;				// Allow frontal backstabs for min damage
	uint8	FrontalBackstabChance;				// Chance to backstab from the front for full damage
	uint8	ConsumeProjectile;					// Chance to not consume arrow.
	uint8	ForageAdditionalItems;				// Chance to forage another item.
	uint8	SalvageChance;						// Chance to salvage a tradeskill components on fail.
	uint32	ArcheryDamageModifier;				// Increase Archery Damage by percent
	bool	SecondaryDmgInc;					// Allow off hand weapon to recieve damage bonus.
	uint32	GiveDoubleAttack;					// Allow classes to double attack with a specified chance.
	int32	SlayUndead[2];						// Allow classes to do extra damage verse undead.(base1 = rate, base2 = damage mod)
	int32	PetCriticalHit;						// Allow pets to critical hit with % value.
	int32	PetAvoidance;						// Pet avoidance chance.
	int32	CombatStability;					// Melee damage mitigation.
	int32	DoubleRiposte;						// Chance to double riposte
	int32	GiveDoubleRiposte[3];				// 0=Regular Chance, 1=Skill Attack Chance, 2=Skill
	uint32	RaiseSkillCap[EQ::skills::HIGHEST_SKILL + 1];		// Raise a specific skill cap (base1= value, base2=skill)
	int32	Ambidexterity;						// Increase chance to duel wield by adding bonus 'skill'.
	int32	PetMaxHP;							// Increase the max hp of your pet.
	int32	PetFlurry;							// Chance for pet to flurry.
	uint8	MasteryofPast;						// Can not fizzle spells below this level specified in value.
	bool	GivePetGroupTarget;					// All pets to recieve group buffs. (Pet Affinity)
	int32	RootBreakChance;					// Chance root will break;
	int32	UnfailingDivinity;					// Improves chance that DI will fire + increase partial heal.
	int32	ItemHPRegenCap;						// Increase item regen cap.
	int32	SEResist[MAX_RESISTABLE_EFFECTS*2];	// Resist chance by specific spell effects.
	int32	OffhandRiposteFail;					// chance for opponent to fail riposte with offhand attack.
	int32	ItemATKCap;							// Raise item attack cap
	int32	FinishingBlow[2];					// Chance to do a finishing blow for specified damage amount.
	uint32	FinishingBlowLvl[2];				// Sets max level an NPC can be affected by FB. (base1 = lv, base2= hit point ratio)
	int32	ShieldEquipDmgMod;					// Increases weapon's base damage by base1 % when shield is equipped (indirectly increasing hate)
	bool	TriggerOnCastRequirement;			// Triggers off various different conditions defined as emum SpellRestrictions
	int8	StunBashChance;						// chance to stun with bash.
	int8	IncreaseChanceMemwipe;				// increases chance to memory wipe
	int8	CriticalMend;						// chance critical monk mend
	int32	ImprovedReclaimEnergy;				// Modifies amount of mana returned from reclaim energy
	uint32	HeadShot[2];						// Headshot AA (Massive dmg vs humaniod w/ archery) 0= ? 1= Dmg
	uint8	HSLevel[2];							// Max Level Headshot will be effective at. and chance mod
	uint32	Assassinate[2];						// Assassinate AA (Massive dmg vs humaniod w/ assassinate) 0= ? 1= Dmg
	uint8	AssassinateLevel[2];				// Max Level Assassinate will be effective at.
	int32	PetMeleeMitigation;					// Add AC to owner's pet.
	int		IllusionPersistence;				// 1=Causes illusions not to fade when zoning 2=Allow to persist after death.
	uint16	extra_xtargets;						// extra xtarget entries
	bool	ShroudofStealth;					// rogue improved invisiblity
	uint16  ReduceFallDamage;					// reduce fall damage by percent
	int32	ReduceTradeskillFail[EQ::skills::HIGHEST_SKILL + 1]; // Reduces chance for trade skills to fail by percent.
	uint8	TradeSkillMastery;					// Allow number of tradeskills to exceed 200 skill.
	int16	NoBreakAESneak;						// Percent value
	int16	FeignedCastOnChance;				// Percent Value
	bool	PetCommands[PET_MAXCOMMANDS];		// SPA 267
	int	FeignedMinionChance;				// SPA 281 base1 = chance, just like normal FD
	int	GrantForage; // affects max skill of forage as well as granting non-forage classes forage
	int aura_slots;
	int trap_slots;
	bool hunger; // Song of Sustenance -- min caps to 3500
	int64 heroic_max_hp;
	int64 heroic_max_mana;
	int64 heroic_max_end;
	int64 heroic_hp_regen;
	int64 heroic_mana_regen;
	int64 heroic_end_regen;
	int32 heroic_str_shield_ac;
	int32 heroic_str_melee_damage;
	int32 heroic_agi_avoidance;
	int32 heroic_dex_ranged_damage;
};

// StatBonus Indexes
namespace SBIndex {
	constexpr uint16 BUFFSTACKER_EXISTS                     = 0; // SPA 446-449
	constexpr uint16 BUFFSTACKER_VALUE                      = 1; // SPA 446-449
	constexpr uint16 EXTRA_ATTACK_CHANCE                    = 0; // SPA 266,498,499
	constexpr uint16 EXTRA_ATTACK_NUM_ATKS                  = 1; // SPA 266,498,499
	constexpr uint16 DIVINE_SAVE_CHANCE                     = 0; // SPA 232
	constexpr uint16 DIVINE_SAVE_SPELL_TRIGGER_ID           = 1; // SPA 232
	constexpr uint16 DEATH_SAVE_TYPE                        = 0; // SPA 150
	constexpr uint16 DEATH_SAVE_BUFFSLOT                    = 1; // SPA 150
	constexpr uint16 DEATH_SAVE_MIN_LEVEL_FOR_HEAL          = 2; // SPA 150
	constexpr uint16 DEATH_SAVE_HEAL_AMT                    = 3; // SPA 150
	constexpr uint16 RESOURCE_PERCENT_CAP                   = 0; // SPA 408-410
	constexpr uint16 RESOURCE_AMOUNT_CAP                    = 1; // SPA 408-419
	constexpr uint16 NEGATE_ATK_EXISTS                      = 0; // SPA 163
	constexpr uint16 NEGATE_ATK_BUFFSLOT                    = 1; // SPA 163
	constexpr uint16 NEGATE_ATK_MAX_DMG_ABSORB_PER_HIT      = 2; // SPA 163
	constexpr uint16 MITIGATION_RUNE_PERCENT                = 0; // SPA 161,162,450
	constexpr uint16 MITIGATION_RUNE_BUFFSLOT               = 1; // SPA 161,162,450
	constexpr uint16 MITIGATION_RUNE_MAX_DMG_ABSORB_PER_HIT = 2; // SPA 161,162,450
	constexpr uint16 MITIGATION_RUNE_MAX_HP_AMT             = 3; // SPA 161,162,450
	constexpr uint16 THRESHOLDGUARD_MITIGATION_PERCENT      = 0; // SPA 451,452
	constexpr uint16 THRESHOLDGUARD_BUFFSLOT                = 1; // SPA 451,452
	constexpr uint16 THRESHOLDGUARD_MIN_DMG_TO_TRIGGER      = 2; // SPA 451,452
	constexpr uint16 ENDURANCE_ABSORD_MITIGIATION           = 0; // SPA 521
	constexpr uint16 ENDURANCE_ABSORD_DRAIN_PER_HP          = 1; // SPA 521
	constexpr uint16 IMPROVED_TAUNT_MAX_LVL                 = 0; // SPA 444
	constexpr uint16 IMPROVED_TAUNT_AGGRO_MOD               = 1; // SPA 444
	constexpr uint16 IMPROVED_TAUNT_BUFFSLOT                = 2; // SPA 444
	constexpr uint16 ROOT_EXISTS                            = 0; // SPA 99
	constexpr uint16 ROOT_BUFFSLOT                          = 1; // SPA 99
	constexpr uint16 RUNE_AMOUNT                            = 0; // SPA 55
	constexpr uint16 RUNE_BUFFSLOT                          = 1; // SPA 78
	constexpr uint16 POSITION_BACK							= 0; // SPA 503-506
	constexpr uint16 POSITION_FRONT							= 1; // SPA 503-506
	constexpr uint16 PET_RAMPAGE_CHANCE                     = 0; // SPA 464,465
	constexpr uint16 PET_RAMPAGE_DMG_MOD                    = 1; // SPA 465,465
	constexpr uint16 SKILLATK_PROC_SPELL_ID                 = 0; // SPA 288
	constexpr uint16 SKILLATK_PROC_CHANCE                   = 1; // SPA 288
	constexpr uint16 SKILLATK_PROC_SKILL                    = 2; // SPA 288
	constexpr uint16 SLAYUNDEAD_RATE_MOD                    = 0; // SPA 219
	constexpr uint16 SLAYUNDEAD_DMG_MOD                     = 1; // SPA 219
	constexpr uint16 DOUBLE_RIPOSTE_CHANCE                  = 0; // SPA 223
	constexpr uint16 DOUBLE_RIPOSTE_SKILL_ATK_CHANCE        = 1; // SPA 223
	constexpr uint16 DOUBLE_RIPOSTE_SKILL                   = 2; // SPA 223
	constexpr uint16 FINISHING_EFFECT_PROC_CHANCE           = 0; // SPA 278, 439, 217
	constexpr uint16 FINISHING_EFFECT_DMG                   = 1; // SPA 278, 439, 217
	constexpr uint16 FINISHING_EFFECT_LEVEL_MAX             = 0; // SPA 440, 345, 346
	constexpr uint16 FINISHING_EFFECT_LEVEL_CHANCE_BONUS    = 1; // SPA 345, 346
	constexpr uint16 FINISHING_BLOW_LEVEL_HP_RATIO			= 1; // SPA 440
	constexpr uint16 DOUBLE_MELEE_ROUND_CHANCE              = 0; // SPA 471
	constexpr uint16 DOUBLE_MELEE_ROUND_DMG_BONUS			= 1; // SPA 471
	constexpr uint16 REFLECT_CHANCE                         = 0; // SPA 158
	constexpr uint16 REFLECT_RESISTANCE_MOD                 = 1; // SPA 158
	constexpr uint16 REFLECT_DMG_EFFECTIVENESS              = 2; // SPA 158
	constexpr uint16 COMBAT_PROC_ORIGIN_ID                  = 0; // SPA
	constexpr uint16 COMBAT_PROC_SPELL_ID                   = 1; // SPA
	constexpr uint16 COMBAT_PROC_RATE_MOD                   = 2; // SPA
	constexpr uint16 COMBAT_PROC_REUSE_TIMER                = 3; // SPA
};


typedef struct
{
	int32 spellID;
	uint16 chance;
	int32 base_spellID;
	int level_override;
	uint32 proc_reuse_time;
} tProc;


struct WeaponStance_Struct {
	bool enabled;
	bool spellbonus_enabled;
	bool itembonus_enabled;
	bool aabonus_enabled;
	int spellbonus_buff_spell_id;
	int itembonus_buff_spell_id;
	int aabonus_buff_spell_id;
};

constexpr uint16 WEAPON_STANCE_TYPE_2H = 0;
constexpr uint16 WEAPON_STANCE_TYPE_SHIELD = 1;
constexpr uint16 WEAPON_STANCE_TYPE_DUAL_WIELD = 2;

typedef struct
{
	uint16 increment;
	uint16 hit_increment;
	uint16 target_id;
	int32 wpn_dmg;
	float origin_x;
	float origin_y;
	float origin_z;
	float tlast_x;
	float tlast_y;
	uint32 ranged_id;
	uint32 ammo_id;
	int ammo_slot;
	uint8 skill;
	float speed_mod;
	bool disable_procs;
} tProjatk;

//eventually turn this into a typedef and
//make DoAnim take it instead of int, to enforce its use.
enum {	//type arguments to DoAnim
	animKick				= 1,
	anim1HPiercing			= 2,	//might be piercing?
	anim2HSlashing			= 3,
	anim2HWeapon			= 4,
	anim1HWeapon			= 5,
	animDualWield			= 6,
	animTailRake			= 7,	//slam & Dpunch too
	animHand2Hand			= 8,
	animShootBow			= 9,
	animRoundKick			= 11,
	animSwarmAttack			= 20,	//dunno about this one..
	animFlyingKick			= 45,
	animTigerClaw			= 46,
	animEagleStrike			= 47,

};

enum {
	SKILLUP_UNKNOWN = 0,
	SKILLUP_SUCCESS = 1,
	SKILLUP_FAILURE = 2
};

enum {
	GridCircular,
	GridRandom10,
	GridRandom,
	GridPatrol,
	GridOneWayRepop,
	GridRand5LoS,
	GridOneWayDepop,
	GridCenterPoint,
	GridRandomCenterPoint,
	GridRandomPath
};

typedef enum {
	petFamiliar,		//only listens to /pet get lost
	petAnimation,		//does not listen to any commands
	petOther,
	petCharmed,
	petNPCFollow,
	petTargetLock,			//remain active as long something is on the hatelist. Don't listen to any commands
	petNone = 0xFF // not a pet
} PetType;

typedef enum {
	SingleTarget,	// causes effect to spell_target
	AETarget,			// causes effect in aerange of target + target
	AECaster,			// causes effect in aerange of 'this'
	GroupSpell,		// causes effect to caster + target's group
	CAHateList,		// causes effect to all people on caster's hate list within some range
	DirectionalAE,
	Beam,
	TargetRing,
	CastActUnknown
} CastAction_type;


struct MercType {
	uint32	Type;
	uint32	ClientVersion;
};

struct MercData {
	uint32	MercTemplateID;
	uint32	MercType;				// From dbstr_us.txt - Apprentice (330000100), Journeyman (330000200), Master (330000300)
	uint32	MercSubType;			// From dbstr_us.txt - 330020105^23^Race: Guktan<br>Type: Healer<br>Confidence: High<br>Proficiency: Apprentice, Tier V...
	uint32	CostFormula;			// To determine cost to client
	uint32	ClientVersion;				// Only send valid mercs per expansion
	uint32	NPCID;
};

namespace EQ
{
	class ItemInstance;
}

class Mob;
// All data associated with a single trade
class Trade
{
public:
	Trade(Mob* in_owner);
	virtual ~Trade();

	void Reset();

	// Initiate a trade with another mob
	// Also puts other mob into trader mode with this mob
	void Start(uint32 mob_id, bool initiate_with=true);

	// Mob the owner is trading with
	Mob* With();

	// Add item from cursor slot to trade bucket (automatically does bag data too)
	void AddEntity(uint16 trade_slot_id, uint32 stack_size);


public:
	// Object state
	TradeState state;
	int32 pp;
	int32 gp;
	int32 sp;
	int32 cp;

private:
	// Send item data for trade item to other person involved in trade
	void SendItemData(const EQ::ItemInstance* inst, int16 dest_slot_id);

	uint32 with_id;
	Mob* owner;
public:
	Mob *GetOwner() const;
};

struct ExtraAttackOptions {
	ExtraAttackOptions()
		: damage_percent(1.0f), damage_flat(0),
		armor_pen_percent(0.0f), armor_pen_flat(0),
		crit_percent(1.0f), crit_flat(0.0f),
		hate_percent(1.0f), hate_flat(0), hit_chance(0),
		melee_damage_bonus_flat(0), skilldmgtaken_bonus_flat(0)
	{ }

	float damage_percent;
	int64 damage_flat;
	float armor_pen_percent;
	int armor_pen_flat;
	float crit_percent;
	float crit_flat;
	float hate_percent;
	int hate_flat;
	int hit_chance;
	int melee_damage_bonus_flat;
	int skilldmgtaken_bonus_flat;
	int range_percent;
};

struct DamageTable {
	int32 max_extra; // max extra damage
	int32 chance; // chance not to apply?
	int32 minusfactor; // difficulty of rolling
};

struct DamageHitInfo {
	//uint16 attacker; // id
	//uint16 defender; // id
	int64 base_damage;
	int64 min_damage;
	int64 damage_done;
	int offense;
	int tohit;
	int hand;
	EQ::skills::SkillType skill;
};

struct ExpeditionInvite
{
	uint32_t    expedition_id;
	std::string inviter_name;
	std::string swap_remove_name;
};

struct DataBucketCache
{
	uint64_t      bucket_id;
	std::string   bucket_key;
	std::string   bucket_value;
	uint32_t      bucket_expires;
};


#endif


/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2016 EQEMu Development Team (http://eqemulator.net)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef ENTITY_H
#define ENTITY_H

#include <unordered_map>
#include <queue>

#include "../common/types.h"
#include "../common/linked_list.h"
#include "../common/servertalk.h"
#include "../common/bodytypes.h"
#include "../common/eq_constants.h"
#include "../common/emu_constants.h"

#include "position.h"
#include "zonedump.h"
#include "common.h"

class Encounter;
class Beacon;
class Client;
class Corpse;
class Doors;
class EQApplicationPacket;
class Entity;
class EntityList;
class Group;
class Merc;
class Mob;
class NPC;
class Object;
class Petition;
class Raid;
class Spawn2;
class Trap;

struct GuildBankItemUpdate_Struct;
struct NewSpawn_Struct;
struct QGlobal;
struct UseAA_Struct;
struct Who_All_Struct;

class Bot;

extern EntityList entity_list;

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual bool IsClient()			    const { return false; }
	virtual bool IsNPC()			    const { return false; }
	virtual bool IsMob()			    const { return false; }
	virtual bool IsMerc()			    const { return false; }
	virtual bool IsCorpse()			    const { return false; }
	virtual bool IsPlayerCorpse()	    const { return false; }
	virtual bool IsNPCCorpse()		    const { return false; }
	virtual bool IsObject()			    const { return false; }
	virtual bool IsDoor()			    const { return false; }
	virtual bool IsTrap()			    const { return false; }
	virtual bool IsBeacon()			    const { return false; }
	virtual bool IsEncounter()		    const { return false; }
	virtual bool IsBot()                const { return false; }
	virtual bool IsAura()			    const { return false; }
	virtual bool IsOfClientBot()        const { return false; }
	virtual bool IsOfClientBotMerc()    const { return false; }

	virtual bool Process() { return false; }
	virtual bool Save() { return true; }
	virtual void Depop(bool StartSpawnTimer = false) {}

	Client	*CastToClient();
	NPC		*CastToNPC();
	Mob		*CastToMob();
	Merc	*CastToMerc();
	Corpse	*CastToCorpse();
	Object	*CastToObject();
	Doors	*CastToDoors();
	Trap	*CastToTrap();
	Beacon	*CastToBeacon();
	Encounter *CastToEncounter();

	const Client	*CastToClient() const;
	const NPC		*CastToNPC() const;
	const Mob		*CastToMob() const;
	const Merc		*CastToMerc() const;
	const Corpse	*CastToCorpse() const;
	const Object	*CastToObject() const;
	const Doors		*CastToDoors() const;
	const Trap		*CastToTrap() const;
	const Beacon	*CastToBeacon() const;
	const Encounter *CastToEncounter() const;

	inline const uint16& GetInitialId() const { return initial_id; }
	inline const uint16& GetID() const { return id; }
	inline const time_t& GetSpawnTimeStamp() const { return spawn_timestamp; }

	virtual const char* GetName() { return ""; }

	Bot* CastToBot();
	const Bot* CastToBot() const;

protected:
	friend class EntityList;
	inline virtual void SetID(uint16 set_id) {
		id = set_id;

		if (initial_id == 0 && set_id > 0) {
			initial_id = set_id;
		}
	}
private:
	uint16 id;
	uint16 initial_id;
	time_t spawn_timestamp;
};

class EntityList
{
public:
	struct Area {
		int id;
		int type;
		float min_x, max_x;
		float min_y, max_y;
		float min_z, max_z;
	};

	EntityList();
	~EntityList();

	Entity* GetID(uint16 id);
	Mob *GetMob(uint16 id);
	inline Mob *GetMobID(uint16 id) { return(GetMob(id)); }	//for perl
	Mob *GetMob(const char* name);
	Mob *GetMobByNpcTypeID(uint32 get_id);
	bool IsMobSpawnedByNpcTypeID(uint32 get_id);
	bool IsNPCSpawned(std::vector<uint32> npc_ids);
	uint32 CountSpawnedNPCs(std::vector<uint32> npc_ids);
	inline NPC *GetNPCByID(uint16 id)
	{
		auto it = npc_list.find(id);
		if (it != npc_list.end())
			return it->second;
		return nullptr;
	}
	NPC *GetNPCByNPCTypeID(uint32 npc_id);
	NPC *GetNPCBySpawnID(uint32 spawn_id);
	inline Merc *GetMercByID(uint16 id)
	{
		auto it = merc_list.find(id);
		if (it != merc_list.end())
			return it->second;
		return nullptr;
	}
	Client *GetClientByName(const char* name);
	Client *GetClientByAccID(uint32 accid);
	inline Client *GetClientByID(uint16 id)
	{
		auto it = client_list.find(id);
		if (it != client_list.end())
			return it->second;
		return nullptr;
	}
	Client *GetClientByCharID(uint32 iCharID);
	Client *GetClientByWID(uint32 iWID);
	Client *GetClientByLSID(uint32 iLSID);

	Bot* GetRandomBot(const glm::vec3& location = glm::vec3(0.f), float distance = 0, Bot* exclude_bot = nullptr);
	Client* GetRandomClient(const glm::vec3& location = glm::vec3(0.f), float distance = 0, Client* exclude_client = nullptr);
	NPC* GetRandomNPC(const glm::vec3& location = glm::vec3(0.f), float distance = 0, NPC* exclude_npc = nullptr);
	Mob* GetRandomMob(const glm::vec3& location = glm::vec3(0.f), float distance = 0, Mob* exclude_mob = nullptr);
	Group* GetGroupByMob(Mob* mob);
	Group* GetGroupByMobName(const char* name);
	bool IsInSameGroupOrRaidGroup(Client *client1, Client *client2);
	Group *GetGroupByClient(Client* client);
	Group *GetGroupByID(uint32 id);
	Group *GetGroupByLeaderName(const char* leader);
	Raid *GetRaidByClient(Client* client);
	Raid *GetRaidByID(uint32 id);
	Raid* GetRaidByBotName(const char* name);
	Raid* GetRaidByBot(const Bot* bot);
	Raid* GetRaidByName(const char* name);

	Corpse *GetCorpseByOwner(Client* client);
	Corpse *GetCorpseByOwnerWithinRange(Client* client, Mob* center, int range);
	inline Corpse *GetCorpseByID(uint16 id)
	{
		auto it = corpse_list.find(id);
		if (it != corpse_list.end())
			return it->second;
		return nullptr;
	}
	Corpse *GetCorpseByDBID(uint32 dbid);
	Corpse *GetCorpseByName(const char* name);

	Spawn2* GetSpawnByID(uint32 id);

	Client* FindCorpseDragger(uint16 CorpseID);

	inline Object *GetObjectByID(uint16 id)
	{
		auto it = object_list.find(id);
		if (it != object_list.end())
			return it->second;
		return nullptr;
	}
	Object *GetObjectByDBID(uint32 id);
	inline Doors *GetDoorsByID(uint16 id)
	{
		auto it = door_list.find(id);
		if (it != door_list.end())
			return it->second;
		return nullptr;
	}
	Doors *GetDoorsByDoorID(uint32 id);
	Doors *GetDoorsByDBID(uint32 id);
	void RemoveAllCorpsesByCharID(uint32 charid);
	void RemoveCorpseByDBID(uint32 dbid);
	int RezzAllCorpsesByCharID(uint32 charid);
	void DespawnGridNodes(int32 grid_id);
	bool IsMobInZone(Mob *who);
	void ClearClientPetitionQueue();
	bool CanAddHateForMob(Mob *p);
	void SendGuildMOTD(uint32 guild_id);
	void SendGuildChannel(uint32 guild_id);
	void SendGuildURL(uint32 guild_id);
	void SendGuildSpawnAppearance(uint32 guild_id);
	void SendGuildMembers(uint32 guild_id);
	void SendGuildMembersList(uint32 guild_id);
	void SendGuildMemberAdd(uint32 guild_id, uint32 level, uint32 _class, uint32 rank, uint32 spirit, uint32 zone_id, std::string player_name);
	void SendGuildMemberRename(uint32 guild_id, std::string player_name, std::string new_player_name);
	void SendGuildMemberRemove(uint32 guild_id, std::string player_name);
	void SendGuildMemberLevel(uint32 guild_id, uint32 level, std::string player_name);
	void SendGuildMemberRankAltBanker(uint32 guild_id, uint32 rank, std::string player_name, bool alt, bool banker);
	void SendGuildMemberPublicNote(uint32 guild_id, std::string player_name, std::string public_note);
	void SendGuildMemberDetails(uint32 guild_id, uint32 zone_id, uint32 offline_mode, std::string player_name);
	void SendGuildRenameGuild(uint32 guild_id, std::string new_guild_name);

	void	RefreshAllGuildInfo(uint32 guild_id);
	void	SendGuildList();
	void    GuildSetPreRoFBankerFlag(uint32 guild_id, uint32 guild_rank, bool banker_status);
	void	CheckGroupList (const char *fname, const int fline);
	void	GroupProcess();
	void	RaidProcess();
	void	DoorProcess();
	void	ObjectProcess();
	void	CorpseProcess();
	void	MobProcess();
	void	TrapProcess();
	void	BeaconProcess();
	void	EncounterProcess();
	void	ProcessMove(Client *c, const glm::vec3& location);
	void	ProcessMove(NPC *n, float x, float y, float z);
	void	AddArea(int id, int type, float min_x, float max_x, float min_y, float max_y, float min_z, float max_z);
	void	RemoveArea(int id);
	void	ClearAreas();
	void	ReloadMerchants();
	void	ProcessProximitySay(const char *message, Client *c, uint8 language = 0);
	Doors *FindDoor(uint8 door_id);
	Object *FindObject(uint32 object_id);
	Object*	FindNearbyObject(float x, float y, float z, float radius);
	bool	MakeDoorSpawnPacket(EQApplicationPacket* app, Client *client);
	bool	MakeTrackPacket(Client* client);
	void	SendTraders(Client* client);
	void	AddClient(Client*);
	void	AddNPC(NPC*, bool send_spawn_packet = true, bool dont_queue = false);
	void	AddMerc(Merc*, bool SendSpawnPacket = true, bool dontqueue = false);
	void	AddCorpse(Corpse* pc, uint32 in_id = 0xFFFFFFFF);
	void	AddObject(Object*, bool SendSpawnPacket = true);
	void	AddGroup(Group*);
	void	AddGroup(Group*, uint32 id);
	void	AddRaid(Raid *raid);
	void	AddRaid(Raid*, uint32 id);
	void	AddDoor(Doors* door);
	void	AddTrap(Trap* trap);
	void	AddBeacon(Beacon *beacon);
	void	AddEncounter(Encounter *encounter);
	void	AddProximity(NPC *proximity_for);
	void	Clear();
	bool	RemoveMob(uint16 delete_id);
	bool	RemoveClient(uint16 delete_id);
	bool	RemoveClient(Client* delete_client);
	bool	RemoveNPC(uint16 delete_id);
	bool	RemoveMerc(uint16 delete_id);
	bool	RemoveGroup(uint32 delete_id);
	bool	RemoveCorpse(uint16 delete_id);
	bool	RemoveDoor(uint16 delete_id);
	bool	RemoveTrap(uint16 delete_id);
	bool	RemoveObject(uint16 delete_id);
	bool	RemoveProximity(uint16 delete_npc_id);
	bool	RemoveMobFromCloseLists(Mob *mob);
	void    RemoveAuraFromMobs(Mob *aura);
	void	RemoveAllMobs();
	void	RemoveAllClients();
	void	RemoveAllNPCs();
	void	RemoveAllBots();
	void	RemoveAllMercs();
	void	RemoveAllGroups();
	void	RemoveAllCorpses();
	void	RemoveAllDoors();
	void	DespawnAllDoors();
	void	RespawnAllDoors();
	void	RemoveAllTraps();
	void	RemoveAllObjects();
	void	RemoveAllLocalities();
	void	RemoveAllRaids();
	void	RemoveAllEncounters();
	void	DestroyTempPets(Mob *owner);
	void	AddTempPetsToHateList(Mob *owner, Mob* other, bool bFrenzy = false);
	void	AddTempPetsToHateListOnOwnerDamage(Mob *owner, Mob* attacker, int32 spell_id);
	Entity *GetEntityMob(uint16 id);
	Entity *GetEntityMerc(uint16 id);
	Entity *GetEntityDoor(uint16 id);
	Entity *GetEntityObject(uint16 id);
	Entity *GetEntityCorpse(uint16 id);
	Entity *GetEntityTrap(uint16 id);
	Entity *GetEntityBeacon(uint16 id);
	Entity *GetEntityEncounter(uint16 id);
	Entity *GetEntityMob(const char *name);
	Entity *GetEntityCorpse(const char *name);

	void	StopMobAI();

	void DescribeAggro(Client *to_who, NPC *from_who, float dist, bool verbose);

	std::vector<Mob*> GetFilteredEntityList(
		Mob* sender,
		uint32 distance = 0,
		EntityFilterType filter_type = EntityFilterType::All
	);

	void DamageArea(
		Mob* sender,
		int64 damage,
		uint32 distance = 0,
		EntityFilterType filter_type = EntityFilterType::All,
		bool is_percentage = false
	);

	void	Marquee(uint32 type, std::string message, uint32 duration = 3000);
	void	Marquee(uint32 type, uint32 priority, uint32 fade_in, uint32 fade_out, uint32 duration, std::string message);
	void	Message(uint32 to_guilddbid, uint32 type, const char* message, ...);
	void	MessageStatus(uint32 to_guilddbid, int to_minstatus, uint32 type, const char* message, ...);
	void	MessageClose(Mob* sender, bool skipsender, float dist, uint32 type, const char* message, ...);
	void	FilteredMessageClose(Mob* sender, bool skipsender, float dist, uint32 type, eqFilterType filter, const char* message, ...);
	void	MessageString(Mob *sender, bool skipsender, uint32 type, uint32 string_id, const char* message1=0,const char* message2=0,const char* message3=0,const char* message4=0,const char* message5=0,const char* message6=0,const char* message7=0,const char* message8=0,const char* message9=0);
	void	FilteredMessageString(Mob *sender, bool skipsender, uint32 type, eqFilterType filter, uint32 string_id, const char* message1=0,const char* message2=0,const char* message3=0,const char* message4=0,const char* message5=0,const char* message6=0,const char* message7=0,const char* message8=0,const char* message9=0);
	void	MessageCloseString(
		Mob *sender,
		bool skipsender,
		float dist,
		uint32 type,
		uint32 string_id,
		const char *message1 = 0,
		const char *message2 = 0,
		const char *message3 = 0,
		const char *message4 = 0,
		const char *message5 = 0,
		const char *message6 = 0,
		const char *message7 = 0,
		const char *message8 = 0,
		const char *message9 = 0);
	void	FilteredMessageCloseString(
		Mob *sender,
		bool skipsender,
		float dist,
		uint32 type,
		eqFilterType filter,
		uint32 string_id,
		Mob *skip = 0,
		const char *message1 = 0,
		const char *message2 = 0,
		const char *message3 = 0,
		const char *message4 = 0,
		const char *message5 = 0,
		const char *message6 = 0,
		const char *message7 = 0,
		const char *message8 = 0,
		const char *message9 = 0);
	void	ChannelMessageFromWorld(const char* from, const char* to, uint8 chan_num, uint32 guilddbid, uint8 language, uint8 lang_skill, const char* message);
	void	ChannelMessage(Mob* from, uint8 chan_num, uint8 language, const char* message, ...);
	void	ChannelMessage(Mob* from, uint8 chan_num, uint8 language, uint8 lang_skill, const char* message, ...);
	void	SendZoneSpawns(Client*);
	void	SendZonePVPUpdates(Client *);
	void	SendZoneSpawnsBulk(Client* client);
	void	Save();
	void	SendZoneCorpses(Client*);
	void	SendZoneCorpsesBulk(Client*);
	void	SendZoneObjects(Client* client);
	void	SendZoneAppearance(Client *c);
	void	SendNimbusEffects(Client *c);
	void	SendUntargetable(Client *c);
	void	SendAppearanceEffects(Client *c);
	void    SendIllusionWearChange(Client *c);
	void	DuelMessage(Mob* winner, Mob* loser, bool flee);
	void	QuestJournalledSayClose(Mob *sender, float dist, const char* mobname, const char* message, Journal::Options &opts);
	void	GroupMessage(uint32 gid, const char *from, const char *message);
	void	ExpeditionWarning(uint32 minutes_left);
	void    UpdateGuildTributes(uint32 guild_id);

	void	RemoveFromTargets(Mob* mob, bool RemoveFromXTargets = false);
	void	RemoveFromTargetsFadingMemories(Mob* spell_target, bool RemoveFromXTargets = false, uint32 max_level = 0);
	void	RemoveFromXTargets(Mob* mob);
	void	RemoveFromAutoXTargets(Mob* mob);
	void	ReplaceWithTarget(Mob* pOldMob, Mob*pNewTarget);
	void	QueueCloseClients(Mob* sender, const EQApplicationPacket* app, bool ignore_sender=false, float distance=200, Mob* skipped_mob = 0, bool is_ack_required = true, eqFilterType filter=FilterNone);
	void	QueueClients(Mob* sender, const EQApplicationPacket* app, bool ignore_sender=false, bool ackreq = true);
	void	QueueClientsStatus(Mob* sender, const EQApplicationPacket* app, bool ignore_sender = false, uint8 minstatus = AccountStatus::Player, uint8 maxstatus = AccountStatus::Player);
	void	QueueClientsGuild(const EQApplicationPacket* app, uint32 guildeqid = 0);
	void	QueueClientsGuildBankItemUpdate(const GuildBankItemUpdate_Struct *gbius, uint32 GuildID);
	void	QueueClientsByTarget(Mob* sender, const EQApplicationPacket* app, bool iSendToSender = true, Mob* SkipThisMob = 0, bool ackreq = true, bool HoTT = true, uint32 ClientVersionBits = 0xFFFFFFFF, bool inspect_buffs = false, bool clear_target_window  = false);

	void	QueueClientsByXTarget(Mob* sender, const EQApplicationPacket* app, bool iSendToSender = true, EQ::versions::ClientVersionBitmask client_version_bits = EQ::versions::ClientVersionBitmask::maskAllClients);
	void	QueueToGroupsForNPCHealthAA(Mob* sender, const EQApplicationPacket* app);

	void AEAttack(
		Mob *attacker,
		float distance,
		int Hand = EQ::invslot::slotPrimary,
		int count = 0,
		bool is_from_spell = false,
		int attack_rounds = 1
	);
	void AETaunt(Client *caster, float range = 0, int32 bonus_hate = 0);
	void AESpell(
		Mob *caster,
		Mob *center,
		uint16 spell_id,
		bool affect_caster = true,
		int16 resist_adjust = 0,
		int *max_targets = nullptr
	);
	void MassGroupBuff(Mob *caster, Mob *center, uint16 spell_id, bool affect_caster = true);

	//trap stuff
	Mob*	GetTrapTrigger(Trap* trap);
	void	SendAlarm(Trap* trap, Mob* currenttarget, uint8 kos);
	Trap*	FindNearbyTrap(Mob* searcher, float max_dist, float &curdist, bool detected = false);

	void	AddHealAggro(Mob* target, Mob* caster, uint16 hate);
	void	OpenDoorsNear(Mob* opener);
	void	UpdateWho(bool iSendFullUpdate = false);
	char*	MakeNameUnique(char* name);
	static char* RemoveNumbers(char* name);
	void	SignalMobsByNPCID(uint32 npc_type, int signal_id);
	void	RemoveEntity(uint16 id);
	void	SendPetitionToAdmins(Petition* pet);
	void	SendPetitionToAdmins();
	void	AddLootToNPCS(uint32 item_id, uint32 count);

	void	ListNPCCorpses(Client* client);
	void	ListPlayerCorpses(Client* client);
	uint32	DeleteNPCCorpses();
	uint32	DeletePlayerCorpses();
	void	CorpseFix(Client* c);
	void	HalveAggro(Mob* who);
	void	DoubleAggro(Mob* who);
	void	UpdateHoTT(Mob* target);

	void	Process();
	void	ClearAggro(Mob* targ, bool clear_caster_id = false);
	void    ClearWaterAggro(Mob* targ);
	void	ClearFeignAggro(Mob* targ);
	void	ClearZoneFeignAggro(Mob* targ);
	void	AggroZone(Mob* who, int64 hate = 0);

	bool	Fighting(Mob* targ);
	void	RemoveFromHateLists(Mob* mob, bool settoone = false);
	void	RemoveDebuffs(Mob* caster);


	void	MessageGroup(Mob* sender, bool skipclose, uint32 type, const char* message, ...);

	void	LimitAddNPC(NPC *npc);
	void	LimitRemoveNPC(NPC *npc);
	bool	LimitCheckType(uint32 npc_type, int count);
	bool	LimitCheckGroup(uint32 spawngroup_id, int count);
	bool	LimitCheckName(const char* npc_name);

	int		GetHatedCount(Mob *attacker, Mob *exclude, bool inc_gray_con);
	bool	Merc_AICheckCloseBeneficialSpells(Merc* caster, uint8 iChance, float iRange, uint32 iSpellTypes);
	Mob*	GetTargetForMez(Mob* caster);
	uint32	CheckNPCsClose(Mob *center);

	Corpse* GetClosestCorpse(Mob* sender, const char *Name);
	void	TryWakeTheDead(Mob* sender, Mob* target, int32 spell_id, uint32 max_distance, uint32 duration, uint32 amount_pets);
	NPC* GetClosestBanker(Mob* sender, uint32 &distance);
	void	CameraEffect(uint32 duration, float intensity);
	Mob*	GetClosestMobByBodyType(Mob* sender, bodyType BodyType, bool skip_client_pets=false);
	void	ForceGroupUpdate(uint32 gid);
	void	SendGroupLeave(uint32 gid, const char *name);
	void	SendGroupJoin(uint32 gid, const char *name);

	void	SaveAllClientsTaskState();
	void	ReloadAllClientsTaskState(int task_id=0);
	uint16	CreateGroundObject(uint32 itemid, const glm::vec4& position, uint32 decay_time = 300000);
	uint16	CreateGroundObjectFromModel(const char *model, const glm::vec4& position, uint8 type = 0x00, uint32 decay_time = 0);
	uint16	CreateDoor(const char *model, const glm::vec4& position, uint8 type = 0, uint16 size = 100);
	void	ZoneWho(Client *c, Who_All_Struct* Who);
	void	UnMarkNPC(uint16 ID);

	void	SignalAllClients(int signal_id);
	void	UpdateQGlobal(uint32 qid, QGlobal newGlobal);
	void	DeleteQGlobal(std::string name, uint32 npcID, uint32 charID, uint32 zoneID);
	void	SendFindableNPCList(Client *c);
	void	UpdateFindableNPCState(NPC *n, bool Remove);
	void	HideCorpses(Client *c, uint8 CurrentMode, uint8 NewMode);

	void GateAllClientsToSafeReturn();

	void GetMobList(std::list<Mob*> &m_list);
	void GetNPCList(std::list<NPC*> &n_list);
	//void GetMercList(std::list<Merc*> &n_list);
	void GetClientList(std::list<Client*> &c_list);
	void GetCorpseList(std::list<Corpse*> &c_list);
	void GetObjectList(std::list<Object*> &o_list);
	void GetDoorsList(std::list<Doors*> &d_list);
	void GetSpawnList(std::list<Spawn2*> &d_list);
	void GetTargetsForConeArea(Mob *start, float min_radius, float radius, float height, int pcnpc, std::list<Mob*> &m_list);
	std::vector<Mob*> GetTargetsForVirusEffect(Mob *spreader, Mob *orginal_caster, int range, int pcnpc, int32 spell_id);

	inline const std::unordered_map<uint16, Mob *> &GetMobList() { return mob_list; }
	inline const std::unordered_map<uint16, NPC *> &GetNPCList() { return npc_list; }
	inline const std::unordered_map<uint16, Merc *> &GetMercList() { return merc_list; }
	inline const std::unordered_map<uint16, Client *> &GetClientList() { return client_list; }
	inline const std::list<Bot *> &GetBotList() { return bot_list; }
	std::vector<Bot *> GetBotListByCharacterID(uint32 character_id, uint8 class_id = Class::None);
	std::vector<Bot *> GetBotListByClientName(std::string client_name, uint8 class_id = Class::None);
	void SignalAllBotsByOwnerCharacterID(uint32 character_id, int signal_id);
	void SignalAllBotsByOwnerName(std::string owner_name, int signal_id);
	void SignalBotByBotID(uint32 bot_id, int signal_id);
	void SignalBotByBotName(std::string bot_name, int signal_id);
	inline const std::unordered_map<uint16, Corpse *> &GetCorpseList() { return corpse_list; }
	inline const std::unordered_map<uint16, Object *> &GetObjectList() { return object_list; }
	inline const std::unordered_map<uint16, Doors *> &GetDoorsList() { return door_list; }

	std::unordered_map<uint16, Mob *> &GetCloseMobList(Mob *mob, float distance = 0.0f);

	void	DepopAll(int NPCTypeID, bool StartSpawnTimer = true);

	uint16 GetFreeID();
	void RefreshAutoXTargets(Client *c);
	void RefreshClientXTargets(Client *c);
	void SendAlternateAdvancementStats();
	void ScanCloseMobs(
		std::unordered_map<uint16, Mob *> &close_mobs,
		Mob *scanning_mob,
		bool add_self_to_other_lists = false
	);

	void GetTrapInfo(Client* c);
	bool IsTrapGroupSpawned(uint32 trap_id, uint8 group);
	void UpdateAllTraps(bool respawn, bool repopnow = false);
	void ClearTrapPointers();

	int MovePlayerCorpsesToGraveyard(bool force_move_from_instance = false);

protected:
	friend class Zone;
	void	Depop(bool StartSpawnTimer = false);
	void	AddToSpawnQueue(uint16 entityid, NewSpawn_Struct** app);
	void	CheckSpawnQueue();

	//used for limiting spawns
	class SpawnLimitRecord { public: uint32 spawngroup_id; uint32 npc_type; };
	std::map<uint16, SpawnLimitRecord> npc_limit_list;		//entity id -> npc type

	uint32	tsFirstSpawnOnQueue; // timestamp that the top spawn on the spawnqueue was added, should be 0xFFFFFFFF if queue is empty
	uint32	NumSpawnsOnQueue;
	LinkedList<NewSpawn_Struct*> SpawnQueue;

	std::unordered_map<uint16, Client *> client_list;
	std::unordered_map<uint16, Mob *> mob_list;
	std::unordered_map<uint16, NPC *> npc_list;
	std::unordered_map<uint16, Merc *> merc_list;
	std::unordered_map<uint16, Corpse *> corpse_list;
	std::unordered_map<uint16, Object *> object_list;
	std::unordered_map<uint16, Doors *> door_list;
	std::unordered_map<uint16, Trap *> trap_list;
	std::unordered_map<uint16, Beacon *> beacon_list;
	std::unordered_map<uint16, Encounter *> encounter_list;
	std::list<NPC *> proximity_list;
	std::list<Group *> group_list;
	std::list<Raid *> raid_list;
	std::list<Area> area_list;
	std::queue<uint16> free_ids;

	Timer object_timer;
	Timer door_timer;
	Timer corpse_timer;
	Timer group_timer;
	Timer raid_timer;
	Timer trap_timer;


	public:
		void AddBot(Bot* new_bot, bool send_spawn_packet = true, bool dont_queue = false);
		bool RemoveBot(uint16 entityID);
		Mob* GetMobByBotID(uint32 botID);
		Bot* GetBotByBotID(uint32 botID);
		Bot* GetBotByBotName(std::string_view botName);
		Client* GetBotOwnerByBotEntityID(uint32 entity_id);
		Client* GetBotOwnerByBotID(const uint32 bot_id);
		std::list<Bot*> GetBotsByBotOwnerCharacterID(uint32 botOwnerCharacterID);

		bool Bot_AICheckCloseBeneficialSpells(Bot* caster, uint8 iChance, float iRange, uint32 iSpellTypes); // TODO: Evaluate this closesly in hopes to eliminate
		void ShowSpawnWindow(Client* client, int Distance, bool NamedOnly); // TODO: Implement ShowSpawnWindow in the bot class but it needs entity list stuff

		void ScanCloseClientMobs(std::unordered_map<uint16, Mob*>& close_mobs, Mob* scanning_mob);

		void GetBotList(std::list<Bot*> &b_list);
	private:
		std::list<Bot*> bot_list;
};

class BulkZoneSpawnPacket {
public:
	BulkZoneSpawnPacket(Client* iSendTo, uint32 iMaxSpawnsPerPacket);	// 0 = send zonewide
	virtual ~BulkZoneSpawnPacket();

	bool	AddSpawn(NewSpawn_Struct* ns);
	void	SendBuffer();	// Sends the buffer and cleans up everything - can safely re-use the object after this function call (no need to free and do another new)
private:
	uint32	pMaxSpawnsPerPacket;
	uint32	index;
	NewSpawn_Struct* data;
	Client* pSendTo;
};

#endif



/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2016 EQEMu Development Team (http://eqemu.org)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef MOB_H
#define MOB_H

#include "common.h"
#include "data_bucket.h"
#include "entity.h"
#include "hate_list.h"
#include "pathfinder_interface.h"
#include "position.h"
#include "aa_ability.h"
#include "aa.h"
#include "../common/light_source.h"
#include "../common/emu_constants.h"
#include "combat_record.h"
#include "event_codes.h"

#include <any>
#include <set>
#include <vector>
#include <memory>

#include "heal_rotation.h"

char* strn0cpy(char* dest, const char* source, uint32 size);

#define MAX_SPECIAL_ATTACK_PARAMS 9

class Client;
class EQApplicationPacket;
class Group;
class NPC;
class Raid;
class Aura;
struct AuraRecord;
struct NewSpawn_Struct;
struct PlayerPositionUpdateServer_Struct;
class MobMovementManager;

const int COLLISION_BOX_SIZE = 8;

namespace EQ
{
	struct ItemData;
	class ItemInstance;
}

namespace DeathSave {
    constexpr uint32 HP300  = 1;
    constexpr uint32 HP8000 = 2;
}

enum class eSpecialAttacks : int {
	None,
	Rampage,
	AERampage,
	ChaoticStab
};

struct AppearanceStruct {
	uint8  aa_title         = UINT8_MAX;
	uint8  beard            = UINT8_MAX;
	uint8  beard_color      = UINT8_MAX;
	uint32 drakkin_details  = UINT32_MAX;
	uint32 drakkin_heritage = UINT32_MAX;
	uint32 drakkin_tattoo   = UINT32_MAX;
	uint8  eye_color_one    = UINT8_MAX;
	uint8  eye_color_two    = UINT8_MAX;
	uint8  face             = UINT8_MAX;
	uint8  gender_id        = UINT8_MAX;
	uint8  hair             = UINT8_MAX;
	uint8  hair_color       = UINT8_MAX;
	uint8  helmet_texture   = UINT8_MAX;
	uint16 race_id          = Race::Doug;
	bool   send_effects     = true;
	float  size             = -1.0f;
	Client *target          = nullptr;
	uint8  texture          = UINT8_MAX;
};

class DataBucketKey;
class Mob : public Entity {
public:
	enum CLIENT_CONN_STATUS { CLIENT_CONNECTING, CLIENT_CONNECTED, CLIENT_LINKDEAD,
						CLIENT_KICKED, DISCONNECTED, CLIENT_ERROR, CLIENT_CONNECTINGALL };
	enum eStandingPetOrder { SPO_Follow, SPO_Sit, SPO_Guard, SPO_FeignDeath };

	struct SpecialAbility {
		SpecialAbility() {
			level = 0;
			timer = nullptr;
			for(int i = 0; i < MAX_SPECIAL_ATTACK_PARAMS; ++i) {
				params[i] = 0;
			}
		}

		~SpecialAbility() {
			safe_delete(timer);
		}

		int level;
		Timer *timer;
		int params[MAX_SPECIAL_ATTACK_PARAMS];
	};

	struct AuraInfo {
		char name[64];
		int spawn_id;
		int icon;
		Aura *aura;
		AuraInfo() : spawn_id(0), icon(0), aura(nullptr)
		{
			memset(name, 0, 64);
		}
	};

	struct AuraMgr {
		int count; // active auras
		AuraInfo auras[AURA_HARDCAP];
		AuraMgr() : count(0) { }
	};

	Mob(
		const char *in_name,
		const char *in_lastname,
		int64 in_cur_hp,
		int64 in_max_hp,
		uint8 in_gender,
		uint16 in_race,
		uint8 in_class,
		bodyType in_bodytype,
		uint8 in_deity,
		uint8 in_level,
		uint32 in_npctype_id,
		float in_size,
		float in_runspeed,
		const glm::vec4 &position,
		uint8 in_light,
		uint8 in_texture,
		uint8 in_helmtexture,
		uint16 in_ac,
		uint16 in_atk,
		uint16 in_str,
		uint16 in_sta,
		uint16 in_dex,
		uint16 in_agi,
		uint16 in_int,
		uint16 in_wis,
		uint16 in_cha,
		uint8 in_haircolor,
		uint8 in_beardcolor,
		uint8 in_eyecolor1, // the eyecolors always seem to be the same, maybe left and right eye?
		uint8 in_eyecolor2,
		uint8 in_hairstyle,
		uint8 in_luclinface,
		uint8 in_beard,
		uint32 in_drakkin_heritage,
		uint32 in_drakkin_tattoo,
		uint32 in_drakkin_details,
		EQ::TintProfile in_armor_tint,
		uint8 in_aa_title,
		uint16 in_see_invis, // see through invis
		uint16 in_see_invis_undead, // see through invis vs. undead
		uint8 in_see_hide,
		uint8 in_see_improved_hide,
		int64 in_hp_regen,
		int64 in_mana_regen,
		uint8 in_qglobal,
		uint8 in_maxlevel,
		uint32 in_scalerate,
		uint8 in_armtexture,
		uint8 in_bracertexture,
		uint8 in_handtexture,
		uint8 in_legtexture,
		uint8 in_feettexture,
		uint16 in_usemodel,
		bool in_always_aggros_foes,
		int32 in_heroic_strikethrough,
		bool keeps_sold_items,
		int64 in_hp_regen_per_second = 0
	);
	virtual ~Mob();

	inline virtual bool IsMob() const { return true; }
	inline virtual bool InZone() const { return true; }

	void DisplayInfo(Mob *mob);

	std::unordered_map<uint16, Mob *> close_mobs;
	Timer                             mob_close_scan_timer;
	Timer                             mob_check_moving_timer;

	//Somewhat sorted: needs documenting!

	//Attack
	virtual void RogueBackstab(Mob* other, bool min_damage = false, int ReuseTime = 10);
	virtual void RogueAssassinate(Mob* other);
	float MobAngle(Mob *other = 0, float ourx = 0.0f, float oury = 0.0f) const;
	// greater than 90 is behind
	inline bool BehindMob(Mob *other = 0, float ourx = 0.0f, float oury = 0.0f) const
		{ return (!other || other == this) ? true : MobAngle(other, ourx, oury) > 90.0f; }
	// less than 56 is in front, greater than 56 is usually where the client generates the messages
	inline bool InFrontMob(Mob *other = 0, float ourx = 0.0f, float oury = 0.0f) const
		{ return (!other || other == this) ? true : MobAngle(other, ourx, oury) < 56.0f; }
	bool IsFacingMob(Mob *other); // kind of does the same as InFrontMob, but derived from client
	float HeadingAngleToMob(Mob *other) { return HeadingAngleToMob(other->GetX(), other->GetY()); }
	float HeadingAngleToMob(float other_x, float other_y); // to keep consistent with client generated messages
	virtual void RangedAttack(Mob* other) { }
	virtual void ThrowingAttack(Mob* other) { }
	// 13 = Primary (default), 14 = secondary
	virtual bool Attack(Mob* other, int Hand = EQ::invslot::slotPrimary, bool FromRiposte = false, bool IsStrikethrough = false,
	bool IsFromSpell = false, ExtraAttackOptions *opts = nullptr);
	void DoAttack(Mob *other, DamageHitInfo &hit, ExtraAttackOptions *opts = nullptr, bool FromRiposte = false);
	int MonkSpecialAttack(Mob* other, uint8 skill_used);
	virtual void TryBackstab(Mob *other,int ReuseTime = 10);
	bool AvoidDamage(Mob *attacker, DamageHitInfo &hit);
	int compute_tohit(EQ::skills::SkillType skillinuse);
	int GetTotalToHit(EQ::skills::SkillType skill, int chance_mod); // compute_tohit + spell bonuses
	int compute_defense();
	int GetTotalDefense(); // compute_defense + spell bonuses
	bool CheckHitChance(Mob* attacker, DamageHitInfo &hit);
	void TryCriticalHit(Mob *defender, DamageHitInfo &hit, ExtraAttackOptions *opts = nullptr);
	void TryPetCriticalHit(Mob *defender, DamageHitInfo &hit);
	virtual bool TryFinishingBlow(Mob *defender, int64 &damage);
	int TryHeadShot(Mob* defender, EQ::skills::SkillType skillInUse);
	int TryAssassinate(Mob* defender, EQ::skills::SkillType skillInUse);
	virtual void DoRiposte(Mob* defender);
	void ApplyMeleeDamageMods(uint16 skill, int64 &damage, Mob * defender = nullptr, ExtraAttackOptions *opts = nullptr);
	int ACSum(bool skip_caps = false);
	inline int GetDisplayAC() { return 1000 * (ACSum(true) + compute_defense()) / 847; }
	int offense(EQ::skills::SkillType skill);
	int GetBestMeleeSkill();
	void CalcAC() { mitigation_ac = ACSum(); }
	int GetACSoftcap();
	double GetSoftcapReturns();
	int GetClassRaceACBonus();
	inline int GetMitigationAC() { return mitigation_ac; }
	void MeleeMitigation(Mob *attacker, DamageHitInfo &hit, ExtraAttackOptions *opts = nullptr);
	double RollD20(int offense, int mitigation); // CALL THIS FROM THE DEFENDER
	bool CombatRange(Mob* other, float fixed_size_mod = 1.0, bool aeRampage = false, ExtraAttackOptions *opts = nullptr);
	virtual inline bool IsBerserk() { return false; } // only clients
	void RogueEvade(Mob *other);
	void CommonOutgoingHitSuccess(Mob *defender, DamageHitInfo &hit, ExtraAttackOptions *opts = nullptr);
	bool HasDied();
	virtual bool CheckDualWield();
	void DoMainHandAttackRounds(Mob *target, ExtraAttackOptions *opts = nullptr, bool rampage = false);
	void DoOffHandAttackRounds(Mob *target, ExtraAttackOptions *opts = nullptr, bool rampage = false);
	virtual bool CheckDoubleAttack();
	// inline process for places where we need to do them outside of the AI_Process
	void ProcessAttackRounds(Mob *target, ExtraAttackOptions *opts = nullptr, bool rampage = false)
	{
		if (target) {
			DoMainHandAttackRounds(target, opts, rampage);
			if (CanThisClassDualWield()) {
				DoOffHandAttackRounds(target, opts, rampage);
			}
		}
		return;
	}

	bool HasAnInvisibilityEffect();
	void BreakCharmPetIfConditionsMet();
	//Invisible
	bool IsInvisible(Mob* other = 0) const;
	void SetInvisible(uint8 state, bool set_on_bonus_calc = false);

	void CalcSeeInvisibleLevel();
	void CalcInvisibleLevel();
	void ZeroInvisibleVars(uint8 invisible_type);

	inline uint8 GetSeeInvisibleLevelFromNPCStat(uint16 in_see_invis);

	void BreakInvisibleSpells();
	virtual void CancelSneakHide();
	void CommonBreakInvisible();
	void CommonBreakInvisibleFromCombat();

	inline uint8 GetInvisibleLevel() const { return invisible; }
	inline uint8 GetInvisibleUndeadLevel() const { return invisible_undead; }

	inline bool SeeHide() const { return see_hide; }
	inline bool SeeImprovedHide() const { return see_improved_hide; }
	inline uint8 SeeInvisibleUndead() const { return see_invis_undead; }
	inline uint8 SeeInvisible() const { return see_invis; }

	inline void SetInnateSeeInvisible(uint8 val) { innate_see_invis = val; }
	inline void SetSeeInvisibleUndead(uint8 val) { see_invis_undead = val; }

	uint32 tmHidden; // timestamp of hide, only valid while hidden == true
	uint8 invisible, nobuff_invisible, invisible_undead, invisible_animals;
	uint8 see_invis, innate_see_invis, see_invis_undead; //TODO: do we need a see_invis_animal ?

	bool sneaking, hidden, improved_hidden;
	bool see_hide, see_improved_hide;

	/**
	 ************************************************
	 * Appearance
	 ************************************************
	 */

	EQ::InternalTextureProfile mob_texture_profile = {};

	EQ::skills::SkillType AttackAnimation(int Hand, const EQ::ItemInstance* weapon, EQ::skills::SkillType skillinuse = EQ::skills::Skill1HBlunt);

	uint32 GetTextureProfileMaterial(uint8 material_slot) const;
	uint32 GetTextureProfileColor(uint8 material_slot) const;
	uint32 GetTextureProfileHeroForgeModel(uint8 material_slot) const;

	virtual void SendArmorAppearance(Client *one_client = nullptr);
	virtual void SendTextureWC(uint8 slot, uint32 texture, uint32 hero_forge_model = 0, uint32 elite_material = 0, uint32 unknown06 = 0, uint32 unknown18 = 0);
	virtual void SendWearChange(uint8 material_slot, Client *one_client = nullptr);
	virtual void SetSlotTint(uint8 material_slot, uint8 red_tint, uint8 green_tint, uint8 blue_tint);
	virtual void WearChange(uint8 material_slot, uint32 texture, uint32 color = 0, uint32 hero_forge_model = 0);

	void ChangeSize(float in_size, bool unrestricted = false);
	void DoAnim(const int animation_id, int animation_speed = 0, bool ackreq = true, eqFilterType filter = FilterNone);
	void ProjectileAnimation(Mob* to, int item_id, bool IsArrow = false, float speed = 0, float angle = 0, float tilt = 0, float arc = 0, const char *IDFile = nullptr, EQ::skills::SkillType skillInUse = EQ::skills::SkillArchery);
	void SendAppearanceEffect(uint32 parm1, uint32 parm2, uint32 parm3, uint32 parm4, uint32 parm5, Client *specific_target=nullptr, uint32 value1slot = 1, uint32 value1ground = 1, uint32 value2slot = 1, uint32 value2ground = 1,
		uint32 value3slot = 1, uint32 value3ground = 1, uint32 value4slot = 1, uint32 value4ground = 1, uint32 value5slot = 1, uint32 value5ground = 1);
	void SendLevelAppearance();
	void SendTargetable(bool on, Client *specific_target = nullptr);
	void SetMobTextureProfile(uint8 material_slot, uint32 texture, uint32 color = 0, uint32 hero_forge_model = 0);

	//Spell
	void SendSpellEffect(uint32 effect_id, uint32 duration, uint32 finish_delay, bool zone_wide,
		uint32 unk020, bool perm_effect = false, Client *c = nullptr, uint32 caster_id = 0, uint32 target_id = 0);
	bool IsBeneficialAllowed(Mob *target);
	virtual int GetCasterLevel(uint16 spell_id);
	void ApplySpellsBonuses(uint16 spell_id, uint8 casterlevel, StatBonuses* newbon, uint16 casterID = 0,
		uint8 WornType = 0, int32 ticsremaining = 0, int buffslot = -1, int instrument_mod = 10,
		bool IsAISpellEffect = false, uint16 effect_id = 0, int32 se_base = 0, int32 se_limit = 0, int32 se_max = 0);
	void NegateSpellEffectBonuses(uint16 spell_id);
	bool NegateSpellEffect(uint16 spell_id, int effect_id);
	float GetActSpellRange(uint16 spell_id, float range);
	int64 GetActSpellDamage(uint16 spell_id, int64 value, Mob* target = nullptr);
	int64 GetActDoTDamage(uint16 spell_id, int64 value, Mob* target, bool from_buff_tic = true);
	int64 GetActSpellHealing(uint16 spell_id, int64 value, Mob* target = nullptr, bool from_buff_tic = false);
	int32 GetActSpellCost(uint16 spell_id, int32 cost);
	virtual int32 GetActSpellDuration(uint16 spell_id, int32 duration);
	int32 GetActSpellCasttime(uint16 spell_id, int32 casttime);
	virtual int64 GetActReflectedSpellDamage(uint16 spell_id, int64 value, int effectiveness);
	float ResistSpell(uint8 resist_type, uint16 spell_id, Mob *caster, bool use_resist_override = false,
		int resist_override = 0, bool CharismaCheck = false, bool CharmTick = false, bool IsRoot = false,
		int level_override = -1);
	int GetResist(uint8 resist_type);
	int ResistPhysical(int level_diff, uint8 caster_level);
	int ResistElementalWeaponDmg(const EQ::ItemInstance *item);
	int CheckBaneDamage(const EQ::ItemInstance *item);
	uint16 GetSpecializeSkillValue(uint16 spell_id) const;
	void SendSpellBarDisable();
	void SendSpellBarEnable(uint16 spellid);
	void ZeroCastingVars();
	virtual void SpellProcess();
	virtual bool CastSpell(uint16 spell_id, uint16 target_id, EQ::spells::CastingSlot slot = EQ::spells::CastingSlot::Item, int32 casttime = -1,
		int32 mana_cost = -1, uint32* oSpellWillFinish = 0, uint32 item_slot = 0xFFFFFFFF,
		uint32 timer = 0xFFFFFFFF, uint32 timer_duration = 0, int16 *resist_adjust = nullptr,
		uint32 aa_id = 0);
	virtual bool DoCastSpell(uint16 spell_id, uint16 target_id, EQ::spells::CastingSlot slot = EQ::spells::CastingSlot::Item, int32 casttime = -1,
		int32 mana_cost = -1, uint32* oSpellWillFinish = 0, uint32 item_slot = 0xFFFFFFFF,
		uint32 timer = 0xFFFFFFFF, uint32 timer_duration = 0, int16 resist_adjust = 0,
		uint32 aa_id = 0);
	void CastedSpellFinished(uint16 spell_id, uint32 target_id, EQ::spells::CastingSlot slot, int mana_used,
		uint32 inventory_slot = 0xFFFFFFFF, int16 resist_adjust = 0);
	bool SpellFinished(uint16 spell_id, Mob *target, EQ::spells::CastingSlot slot = EQ::spells::CastingSlot::Item, int mana_used = 0,
		uint32 inventory_slot = 0xFFFFFFFF, int16 resist_adjust = 0, bool isproc = false, int level_override = -1, uint32 timer = 0xFFFFFFFF, uint32 timer_duration = 0, bool from_casted_spell = false, uint32 aa_id = 0);
	void SendBeginCast(uint16 spell_id, uint32 casttime);
	virtual bool SpellOnTarget(
		uint16 spell_id,
		Mob* spelltar,
		int reflect_effectiveness = 0,
		bool use_resist_adjust = false,
		int16 resist_adjust = 0,
		bool isproc = false,
		int level_override = -1,
		int duration_override = 0,
		bool disable_buff_overwrite = false
	);
	virtual bool SpellEffect(Mob* caster, uint16 spell_id, float partial = 100, int level_override = -1, int reflect_effectiveness = 0, int32 duration_override = 0, bool disable_buff_overwrite = false);
	virtual bool DetermineSpellTargets(uint16 spell_id, Mob *&spell_target, Mob *&ae_center,
		CastAction_type &CastAction, EQ::spells::CastingSlot slot, bool isproc = false);
	bool DoCastingChecksOnCaster(int32 spell_id, EQ::spells::CastingSlot slot);
	bool DoCastingChecksZoneRestrictions(bool check_on_casting, int32 spell_id);
	bool DoCastingChecksOnTarget(bool check_on_casting, int32 spell_id, Mob* spell_target);
	virtual bool CheckFizzle(uint16 spell_id);
	virtual bool CheckSpellLevelRestriction(Mob *caster, uint16 spell_id);
	virtual bool IsImmuneToSpell(uint16 spell_id, Mob *caster);
	virtual float GetAOERange(uint16 spell_id);
	void InterruptSpell(uint16 spellid = SPELL_UNKNOWN);
	void InterruptSpell(uint16, uint16, uint16 spellid = SPELL_UNKNOWN);
	void StopCasting();
	void StopCastSpell(int32 spell_id, bool send_spellbar_enable);
	inline bool IsCasting() const { return((casting_spell_id != 0)); }
	uint16 CastingSpellID() const { return casting_spell_id; }
	bool TryDispel(uint8 caster_level, uint8 buff_level, int level_modifier);
	bool TrySpellProjectile(Mob* spell_target,  uint16 spell_id, float speed = 1.5f);
	void ResourceTap(int64 damage, uint16 spell_id);
	void TryTriggerThreshHold(int64 damage, int effect_id, Mob* attacker);
	void CalcDestFromHeading(float heading, float distance, float MaxZDiff, float StartX, float StartY, float &dX, float &dY, float &dZ);
	void BeamDirectional(uint16 spell_id, int16 resist_adjust);
	void ConeDirectional(uint16 spell_id, int16 resist_adjust);
	void ApplyHealthTransferDamage(Mob *caster, Mob *target, uint16 spell_id);
	void ApplySpellEffectIllusion(int32 spell_id, Mob* caster, int buffslot, int base, int limit, int max);
	void ApplyIllusionToCorpse(int32 spell_id, Corpse* new_corpse);
	void SendIllusionWearChange(Client* c);
	int16 GetItemSlotToConsumeCharge(int32 spell_id, uint32 inventory_slot);
	bool CheckItemRaceClassDietyRestrictionsOnCast(uint32 inventory_slot);
	bool IsFromTriggeredSpell(EQ::spells::CastingSlot slot, uint32 item_slot = 0xFFFFFFFF);

	//Bard
	bool ApplyBardPulse(int32 spell_id, Mob *spell_target, EQ::spells::CastingSlot slot);
	bool IsActiveBardSong(int32 spell_id);
	bool HasActiveSong() const { return(bardsong != 0); }
	void ZeroBardPulseVars();
	void DoBardCastingFromItemClick(bool is_casting_bard_song, uint32 cast_time, int32 spell_id, uint16 target_id, EQ::spells::CastingSlot slot, uint32 item_slot,
		uint32 recast_type , uint32 recast_delay);
	bool UseBardSpellLogic(uint16 spell_id = 0xffff, int slot = -1);

	//Buff
	void BuffProcess();
	virtual void DoBuffTic(const Buffs_Struct &buff, int slot, Mob* caster = nullptr);
	void BuffFadeBySpellID(uint16 spell_id);
	void BuffFadeBySpellIDAndCaster(uint16 spell_id, uint16 caster_id);
	void BuffFadeByEffect(int effect_id, int slot_to_skip = -1);
	void BuffFadeAll();
	void BuffFadeBeneficial();
	void BuffFadeNonPersistDeath();
	void BuffFadeDetrimental();
	void BuffFadeBySlot(int slot, bool iRecalcBonuses = true);
	void BuffFadeDetrimentalByCaster(Mob *caster);
	void BuffFadeBySitModifier();
	void BuffDetachCaster(Mob *caster);
	bool IsAffectedByBuffByGlobalGroup(GlobalGroup group);
	void BuffModifyDurationBySpellID(uint16 spell_id, int32 newDuration);
	int AddBuff(Mob *caster, const uint16 spell_id, int duration = 0, int32 level_override = -1, bool disable_buff_overwrite = false);
	int CanBuffStack(uint16 spellid, uint8 caster_level, bool iFailIfOverwrite = false);
	int CalcBuffDuration(Mob *caster, Mob *target, uint16 spell_id, int32 caster_level_override = -1);
	void SendPetBuffsToClient();
	virtual int GetCurrentBuffSlots() const { return 0; }
	virtual int GetCurrentSongSlots() const { return 0; }
	virtual int GetCurrentDiscSlots() const { return 0; }
	virtual int GetMaxBuffSlots() const { return 0; }
	virtual int GetMaxSongSlots() const { return 0; }
	virtual int GetMaxDiscSlots() const { return 0; }
	virtual int GetMaxTotalSlots() const { return 0; }
	bool HasDiscBuff();
	virtual uint32 GetFirstBuffSlot(bool disc, bool song);
	virtual uint32 GetLastBuffSlot(bool disc, bool song);
	virtual void InitializeBuffSlots() { buffs = nullptr; }
	virtual void UninitializeBuffSlots() { }
	EQApplicationPacket *MakeBuffsPacket(bool for_target = true, bool clear_buffs = false);
	void SendBuffsToClient(Client *c);
	inline Buffs_Struct* GetBuffs() { return buffs; }
	void DoGravityEffect();
	void DamageShield(Mob* other, bool spell_ds = false);
	int32 RuneAbsorb(int64 damage, uint16 type);
	std::vector<uint16> GetBuffSpellIDs();
	bool FindBuff(uint16 spell_id, uint16 caster_id = 0);
	uint16 FindBuffBySlot(int slot);
	uint32 BuffCount(bool is_beneficial = true, bool is_detrimental = true);
	bool FindType(uint16 type, bool bOffensive = false, uint16 threshold = 100);
	int16 GetBuffSlotFromType(uint16 type);
	uint16 GetSpellIDFromSlot(uint8 slot);
	int CountDispellableBuffs();
	void CheckNumHitsRemaining(NumHit type, int32 buff_slot = -1, uint16 spell_id = SPELL_UNKNOWN);
	bool HasNumhits() const { return has_numhits; }
	inline void Numhits(bool val) { has_numhits = val; }
	bool HasMGB() const { return has_MGB; }
	inline void SetMGB(bool val) { has_MGB = val; }
	bool HasProjectIllusion() const { return has_ProjectIllusion ; }
	inline void SetProjectIllusion(bool val) { has_ProjectIllusion  = val; }
	bool IsNimbusEffectActive(uint32 nimbus_effect);
	void SetNimbusEffect(uint32 nimbus_effect);
	inline virtual uint32 GetNimbusEffect1() const { return nimbus_effect1; }
	inline virtual uint32 GetNimbusEffect2() const { return nimbus_effect2; }
	inline virtual uint32 GetNimbusEffect3() const { return nimbus_effect3; }
	void AddNimbusEffect(int effect_id);
	void RemoveNimbusEffect(int effect_id);
	void RemoveAllNimbusEffects();
	inline const glm::vec3& GetTargetRingLocation() const { return m_TargetRing; }
	inline float GetTargetRingX() const { return m_TargetRing.x; }
	inline float GetTargetRingY() const { return m_TargetRing.y; }
	inline float GetTargetRingZ() const { return m_TargetRing.z; }
	inline bool HasEndurUpkeep() const { return endur_upkeep; }
	inline void SetEndurUpkeep(bool val) { endur_upkeep = val; }
	bool HasBuffWithSpellGroup(int spell_group);
	void SetAppearanceEffects(int32 slot, int32 value);
	void ListAppearanceEffects(Client* c);
	void ClearAppearanceEffects();
	void SendSavedAppearanceEffects(Client *receiver);
	void SetBuffDuration(int spell_id, int duration = 0, int level_override = -1);
	void ApplySpellBuff(int spell_id, int duration = 0, int level_override = -1);
	int GetBuffStatValueBySpell(int32 spell_id, const char* stat_identifier);
	int GetBuffStatValueBySlot(uint8 slot, const char* stat_identifier);

	//Basic Stats/Inventory
	virtual void SetLevel(uint8 in_level, bool command = false) { level = in_level; }
	void TempName(const char *newname = nullptr);
	void SetTargetable(bool on);
	bool IsTargetable() const { return m_targetable; }
	bool HasShieldEquipped() const { return has_shield_equipped; }
	inline void SetShieldEquipped(bool val) { has_shield_equipped = val; }
	bool HasTwoHandBluntEquipped() const { return has_two_hand_blunt_equipped; }
	inline void SetTwoHandBluntEquipped(bool val) { has_two_hand_blunt_equipped = val; }
	bool HasTwoHanderEquipped() { return has_two_hander_equipped; }
	void SetTwoHanderEquipped(bool val) { has_two_hander_equipped = val; }
	bool HasDualWeaponsEquipped() const { return has_dual_weapons_equipped; }
	bool HasBowEquipped() const { return has_bowequipped; }
	void SetBowEquipped(bool val) { has_bowequipped = val; }
	bool HasArrowEquipped() const { return has_arrowequipped; }
	void SetArrowEquipped(bool val) { has_arrowequipped = val; }
	bool HasBowAndArrowEquipped() const { return HasBowEquipped() && HasArrowEquipped(); }
	inline void SetDualWeaponsEquipped(bool val) { has_dual_weapons_equipped = val; }
	bool CanFacestab() { return can_facestab; }
	void SetFacestab(bool val) { can_facestab = val; }
	virtual uint8 ConvertItemTypeToSkillID(uint8 item_type);
	virtual uint16 GetSkill(EQ::skills::SkillType skill_num) const { return 0; }
	virtual uint32 GetEquippedItemFromTextureSlot(uint8 material_slot) const { return(0); }
	virtual uint32 GetEquipmentMaterial(uint8 material_slot) const;
	virtual uint8 GetEquipmentType(uint8 material_slot) const;
	virtual uint32 GetHerosForgeModel(uint8 material_slot) const;
	virtual uint32 GetEquipmentColor(uint8 material_slot) const;
	virtual uint32 IsEliteMaterialItem(uint8 material_slot) const;
	bool CanClassEquipItem(uint32 item_id);
	bool CanRaceEquipItem(uint32 item_id);
	bool AffectedBySpellExcludingSlot(int slot, int effect);
	virtual bool Death(Mob* killer_mob, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill, KilledByTypes killed_by = KilledByTypes::Killed_NPC) = 0;
	virtual void Damage(Mob* from, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill,
		bool avoidable = true, int8 buffslot = -1, bool iBuffTic = false, eSpecialAttacks special = eSpecialAttacks::None) = 0;
	void SetHP(int64 hp);
	inline void SetOOCRegen(int64 new_ooc_regen) { ooc_regen = new_ooc_regen; }
	virtual void Heal();
	virtual void HealDamage(uint64 ammount, Mob* caster = nullptr, uint16 spell_id = SPELL_UNKNOWN);
	virtual void SetMaxHP() { current_hp = max_hp; }
	virtual inline uint16 GetBaseRace() const { return base_race; }
	virtual inline uint8 GetBaseGender() const { return base_gender; }
	virtual uint16 GetFactionRace();
	virtual inline uint16 GetDeity() const { return deity; }
	virtual EQ::deity::DeityTypeBit GetDeityBit() { return EQ::deity::GetDeityBitmask((EQ::deity::DeityType)deity); }
	inline uint16 GetRace() const { return race; }
	inline uint16 GetModel() const { return (use_model == 0) ? race : use_model; }
	inline uint8 GetGender() const { return gender; }
	inline uint8 GetTexture() const { return texture; }
	inline uint8 GetHelmTexture() const { return helmtexture; }
	inline uint8 GetHairColor() const { return haircolor; }
	inline uint8 GetBeardColor() const { return beardcolor; }
	inline uint8 GetEyeColor1() const { return eyecolor1; }
	inline uint8 GetEyeColor2() const { return eyecolor2; }
	inline uint8 GetHairStyle() const { return hairstyle; }
	inline uint8 GetLuclinFace() const { return luclinface; }
	inline uint8 GetBeard() const { return beard; }
	inline uint8 GetDrakkinHeritage() const { return drakkin_heritage; }
	inline uint8 GetDrakkinTattoo() const { return drakkin_tattoo; }
	inline uint8 GetDrakkinDetails() const { return drakkin_details; }
	inline void ChangeRace(uint16 in) { race = in; }
	inline void ChangeGender(uint8 in) { gender = in;}
	inline void ChangeTexture(uint8 in) { texture = in; }
	inline void ChangeHelmTexture(uint8 in) { helmtexture = in; }
	inline void ChangeHairColor(uint8 in) { haircolor = in; }
	inline void ChangeBeardColor(uint8 in) { beardcolor = in; }
	inline void ChangeEyeColor1(uint8 in) { eyecolor1 = in; }
	inline void ChangeEyeColor2(uint8 in) { eyecolor2 = in; }
	inline void ChangeHairStyle(uint8 in) { hairstyle = in; }
	inline void ChangeLuclinFace(uint8 in) { luclinface = in; }
	inline void ChangeBeard(uint8 in) { beard = in; }
	inline void ChangeDrakkinHeritage(uint8 in) { drakkin_heritage = in; }
	inline void ChangeDrakkinTattoo(uint8 in) { drakkin_tattoo = in; }
	inline void ChangeDrakkinDetails(uint8 in) { drakkin_details = in; }
	inline uint32 GetArmorTint(uint8 i) const { return armor_tint.Slot[(i < EQ::textures::materialCount) ? i : 0].Color; }
	inline uint8 GetClass() const { return class_; }
	inline uint8 GetLevel() const { return level; }
	inline uint8 GetOrigLevel() const { return orig_level; }
	inline const char* GetName() const { return name; }
	inline const char* GetOrigName() const { return orig_name; }
	inline const char* GetLastName() const { return lastname; }
	const char *GetCleanName();
	virtual void SetName(const char *new_name = nullptr) { new_name ? strn0cpy(name, new_name, 64) :
		strn0cpy(name, GetName(), 64); return; };
	inline Mob* GetTarget() const { return target; }
	std::string GetTargetDescription(Mob* target, uint8 description_type = TargetDescriptionType::LCSelf, uint16 entity_id_override = 0);
	virtual void SetTarget(Mob* mob);
	inline bool HasTargetReflection() const { return (target && target != this && target->target == this); }
	virtual inline float GetHPRatio() const { return max_hp == 0 ? 0 : ((float) current_hp / max_hp * 100); }
	virtual inline int GetIntHPRatio() const { return max_hp == 0 ? 0 : static_cast<int>(GetHPRatio()); }
	inline int32 GetAC() const { return AC; }
	inline virtual int32 GetATK() const { return ATK + itembonuses.ATK + spellbonuses.ATK; }
	inline virtual int32 GetATKBonus() const { return itembonuses.ATK + spellbonuses.ATK; }
	inline virtual int32 GetSTR() const { return STR + itembonuses.STR + spellbonuses.STR; }
	inline virtual int32 GetSTA() const { return STA + itembonuses.STA + spellbonuses.STA; }
	inline virtual int32 GetDEX() const { return DEX + itembonuses.DEX + spellbonuses.DEX; }
	inline virtual int32 GetAGI() const { return AGI + itembonuses.AGI + spellbonuses.AGI; }
	inline virtual int32 GetINT() const { return INT + itembonuses.INT + spellbonuses.INT; }
	inline virtual int32 GetWIS() const { return WIS + itembonuses.WIS + spellbonuses.WIS; }
	inline virtual int32 GetCHA() const { return CHA + itembonuses.CHA + spellbonuses.CHA; }
	inline virtual int32 GetHeroicMR() const { return 0; }
	inline virtual int32 GetHeroicFR() const { return 0; }
	inline virtual int32 GetHeroicDR() const { return 0; }
	inline virtual int32 GetHeroicPR() const { return 0; }
	inline virtual int32 GetHeroicCR() const { return 0; }
	inline virtual int32 GetMR() const { return MR + itembonuses.MR + spellbonuses.MR; }
	inline virtual int32 GetFR() const { return FR + itembonuses.FR + spellbonuses.FR; }
	inline virtual int32 GetDR() const { return DR + itembonuses.DR + spellbonuses.DR; }
	inline virtual int32 GetPR() const { return PR + itembonuses.PR + spellbonuses.PR; }
	inline virtual int32 GetCR() const { return CR + itembonuses.CR + spellbonuses.CR; }
	inline virtual int32 GetCorrup() const { return Corrup + itembonuses.Corrup + spellbonuses.Corrup; }
	inline virtual int32 GetPhR() const { return PhR; } // PhR bonuses not implemented yet
	inline StatBonuses GetItemBonuses() const { return itembonuses; }
	inline StatBonuses GetSpellBonuses() const { return spellbonuses; }
	inline StatBonuses GetAABonuses() const { return aabonuses; }
	inline StatBonuses* GetItemBonusesPtr() { return &itembonuses; }
	inline StatBonuses* GetSpellBonusesPtr() { return &spellbonuses; }
	inline StatBonuses* GetAABonusesPtr() { return &aabonuses; }
	inline virtual int32 GetHeroicSTR() const { return 0; }
	inline virtual int32 GetHeroicSTA() const { return 0; }
	inline virtual int32 GetHeroicDEX() const { return 0; }
	inline virtual int32 GetHeroicAGI() const { return 0; }
	inline virtual int32 GetHeroicINT() const { return 0; }
	inline virtual int32 GetHeroicWIS() const { return 0; }
	inline virtual int32 GetHeroicCHA() const { return 0; }
	inline virtual int32 GetMaxSTR() const { return GetSTR(); }
	inline virtual int32 GetMaxSTA() const { return GetSTA(); }
	inline virtual int32 GetMaxDEX() const { return GetDEX(); }
	inline virtual int32 GetMaxAGI() const { return GetAGI(); }
	inline virtual int32 GetMaxINT() const { return GetINT(); }
	inline virtual int32 GetMaxWIS() const { return GetWIS(); }
	inline virtual int32 GetMaxCHA() const { return GetCHA(); }
	inline virtual int32 GetMaxMR() const { return 255; }
	inline virtual int32 GetMaxPR() const { return 255; }
	inline virtual int32 GetMaxDR() const { return 255; }
	inline virtual int32 GetMaxCR() const { return 255; }
	inline virtual int32 GetMaxFR() const { return 255; }
	inline virtual int32 GetDelayDeath() const { return 0; }
	inline int64 GetHP() const { return current_hp; }
	inline int64 GetMaxHP() const { return max_hp; }
	virtual int64 CalcMaxHP();
	virtual int64 CalcHPRegenCap() { return 0; }
	inline int64 GetMaxMana() const { return max_mana; }
	virtual int64 CalcManaRegenCap() { return 0; }
	inline int64 GetMana() const { return current_mana; }
	virtual int64 GetEndurance() const { return 0; }
	virtual int64 GetMaxEndurance() const { return 0; }
	virtual int64 CalcEnduranceRegenCap() { return 0; }
	virtual void SetEndurance(int32 newEnd) { return; }
	int64 GetItemHPBonuses();
	int64 GetSpellHPBonuses();
	const int64& SetMana(int64 amount);
	inline float GetManaRatio() const { return max_mana == 0 ? 100 :
		((static_cast<float>(current_mana) / max_mana) * 100); }
	virtual int64 CalcMaxMana();
	uint32 GetNPCTypeID() const { return npctype_id; }
	void SetNPCTypeID(uint32 npctypeid) { npctype_id = npctypeid; }
	inline const glm::vec4& GetPosition() const { return m_Position; }
	inline void SetPosition(const float x, const float y, const float z) { m_Position.x = x; m_Position.y = y; m_Position.z = z; }
	inline const float GetX() const { return m_Position.x; }
	inline const float GetY() const { return m_Position.y; }
	inline const float GetZ() const { return m_Position.z; }
	inline const float GetHeading() const { return m_Position.w; }
	inline const glm::vec4& GetRelativePosition() const { return m_RelativePosition; }
	inline void SetRelativePosition(const float x, const float y, const float z) { m_RelativePosition.x = x; m_RelativePosition.y = y; m_RelativePosition.z = z; }
	inline const float GetRelativeX() const { return m_RelativePosition.x; }
	inline const float GetRelativeY() const { return m_RelativePosition.y; }
	inline const float GetRelativeZ() const { return m_RelativePosition.z; }
	inline const float GetRelativeHeading() const { return m_RelativePosition.w; }
	inline const float GetSize() const { return size; }
	inline const float GetBaseSize() const { return base_size; }
	inline const GravityBehavior GetFlyMode() const { return flymode; }
	bool IsBoat() const; // Checks races - used on mob instantiation
	bool GetIsBoat() const { return is_boat; } // Set on instantiation for speed
	void SetIsBoat(bool boat) { is_boat = boat; }
	bool IsControllableBoat() const;
	inline const bool AlwaysAggro() const { return always_aggro; }
	inline int32 GetHeroicStrikethrough() const  { return heroic_strikethrough; }
	inline const bool GetKeepsSoldItems() const { return keeps_sold_items; }
	inline void SetKeepsSoldItems(bool in_keeps_sold_items)  { keeps_sold_items = in_keeps_sold_items; }
	virtual int32 GetHealAmt() const { return 0; }
	virtual int32 GetSpellDmg() const { return 0; }
	void ProcessItemCaps();
	virtual int32 CalcItemATKCap() { return 0; }
	virtual bool IsSitting() const { return false; }

	void CopyHateList(Mob* to);

	//Group
	virtual bool HasRaid() = 0;
	virtual bool HasGroup() = 0;
	virtual Raid* GetRaid() = 0;
	virtual Group* GetGroup() = 0;

	//Faction
	virtual inline int32 GetPrimaryFaction() const { return 0; }

	//Movement
	inline bool IsMoving() const { return moving; }
	virtual void SetMoving(bool move) { moving = move; m_Delta = glm::vec4(); }
	virtual void GoToBind(uint8 bindnum = 0) { }
	virtual void Gate(uint8 bindnum = 0);
	virtual int GetWalkspeed() const { return(_GetWalkSpeed()); }
	virtual int GetRunspeed() const { return(_GetRunSpeed()); }
	int GetBaseRunspeed() const { return base_runspeed; }
	int GetBaseWalkspeed() const { return base_walkspeed; }
	int GetBaseFearSpeed() const { return base_fearspeed; }
	float GetMovespeed() const { return IsRunning() ? GetRunspeed() : GetWalkspeed(); }
	bool IsRunning() const { return m_is_running; }
	void SetRunning(bool val) { m_is_running = val; }
	virtual void GMMove(float x, float y, float z, float heading = 0.01, bool save_guard_spot = true);
	virtual void GMMove(const glm::vec4 &position, bool save_guard_spot = true);
	void SetDelta(const glm::vec4& delta);
	void MakeSpawnUpdate(PlayerPositionUpdateServer_Struct* spu);
	void SentPositionPacket(float dx, float dy, float dz, float dh, int anim, bool send_to_self = false);
	virtual void StopMoving();
	virtual void StopMoving(float new_heading);
	void SetSpawned() { spawned = true; };
	bool Spawned() { return spawned; };
	virtual bool ShouldISpawnFor(Client *c) { return true; }
	void SetFlyMode(GravityBehavior in_flymode);
	void Teleport(const glm::vec3 &pos);
	void Teleport(const glm::vec4 &pos);
	void TryMoveAlong(float distance, float angle, bool send = true);
	glm::vec4 TryMoveAlong(const glm::vec4 &start, float distance, float angle);
	void ProcessForcedMovement();
	inline void IncDeltaX(float in) { m_Delta.x += in; }
	inline void IncDeltaY(float in) { m_Delta.y += in; }
	inline void IncDeltaZ(float in) { m_Delta.z += in; }
	inline void SetForcedMovement(int in) { ForcedMovement = in; }
	void SetHeading(float iHeading) { m_Position.w = iHeading; }

	//AI
	static uint32 GetLevelCon(uint8 mylevel, uint8 iOtherLevel);
	inline uint32 GetLevelCon(uint8 iOtherLevel) const { return GetLevelCon(GetLevel(), iOtherLevel); }
	void AddToHateList(Mob* other, int64 hate = 0, int64 damage = 0, bool iYellForHelp = true,
		bool bFrenzy = false, bool iBuffTic = false, uint16 spell_id = SPELL_UNKNOWN, bool pet_comand = false);
	bool RemoveFromHateList(Mob* mob);
	void SetHateAmountOnEnt(Mob* other, int64 hate = 0, int64 damage = 0) { hate_list.SetHateAmountOnEnt(other,hate,damage);}
	void HalveAggro(Mob *other) { int64 in_hate = GetHateAmount(other); SetHateAmountOnEnt(other, (in_hate > 1 ? in_hate / 2 : 1)); }
	void DoubleAggro(Mob *other) { int64 in_hate = GetHateAmount(other); SetHateAmountOnEnt(other, (in_hate ? in_hate * 2 : 1)); }
	int64 GetHateAmount(Mob* tmob, bool is_dam = false) { return hate_list.GetEntHateAmount(tmob,is_dam);}
	int64 GetDamageAmount(Mob* tmob) { return hate_list.GetEntHateAmount(tmob, true);}
	int GetHateRatio(Mob *first, Mob *with) { return hate_list.GetHateRatio(first, with); }
	Mob* GetHateTop() { return hate_list.GetMobWithMostHateOnList(this);}
	Bot* GetHateTopBot() { return hate_list.GetMobWithMostHateOnList(this, nullptr, false, EntityFilterType::Bots)->CastToBot();}
	Client* GetHateTopClient() { return hate_list.GetMobWithMostHateOnList(this, nullptr, false, EntityFilterType::Clients)->CastToClient();}
	NPC* GetHateTopNPC() { return hate_list.GetMobWithMostHateOnList(this, nullptr, false, EntityFilterType::NPCs)->CastToNPC();}
	Mob* GetSecondaryHate(Mob *skip) { return hate_list.GetMobWithMostHateOnList(this, skip); }
	Mob* GetHateDamageTop(Mob* other) { return hate_list.GetDamageTopOnHateList(other);}
	Mob* GetHateRandom() { return hate_list.GetRandomMobOnHateList(); }
	Bot* GetHateRandomBot() { return hate_list.GetRandomMobOnHateList(EntityFilterType::Bots)->CastToBot(); }
	Client* GetHateRandomClient() { return hate_list.GetRandomMobOnHateList(EntityFilterType::Clients)->CastToClient(); }
	NPC* GetHateRandomNPC() { return hate_list.GetRandomMobOnHateList(EntityFilterType::NPCs)->CastToNPC(); }
	Mob* GetHateMost() { return hate_list.GetMobWithMostHateOnList();}
	Mob* GetHateClosest(bool skip_mezzed = false) { return hate_list.GetClosestEntOnHateList(this, skip_mezzed); }
	Bot* GetHateClosestBot(bool skip_mezzed = false) { return hate_list.GetClosestEntOnHateList(this, skip_mezzed, EntityFilterType::Bots)->CastToBot(); }
	Client* GetHateClosestClient(bool skip_mezzed = false) { return hate_list.GetClosestEntOnHateList(this, skip_mezzed, EntityFilterType::Clients)->CastToClient(); }
	NPC* GetHateClosestNPC(bool skip_mezzed = false) { return hate_list.GetClosestEntOnHateList(this, skip_mezzed, EntityFilterType::NPCs)->CastToNPC(); }
	bool IsEngaged() { return(!hate_list.IsHateListEmpty()); }
	inline uint32 GetHateListCount(HateListCountType count_type = HateListCountType::All) { return hate_list.GetHateListCount(count_type); }
	bool HasPrimaryAggro() { return PrimaryAggro; }
	bool HasAssistAggro() { return AssistAggro; }
	void SetPrimaryAggro(bool value) { PrimaryAggro = value; if (value) AssistAggro = false; }
	void SetAssistAggro(bool value) { AssistAggro = value; if (PrimaryAggro) AssistAggro = false; }
	bool HateSummon();
	void FaceTarget(Mob* mob_to_face = 0);
	void WipeHateList(bool npc_only = false);
	void AddFeignMemory(Mob* attacker);
	void RemoveFromFeignMemory(Mob* attacker);
	void ClearFeignMemory();
	bool IsOnFeignMemory(Mob *attacker) const;
	void PrintHateListToClient(Client *who) { hate_list.PrintHateListToClient(who); }
	std::list<struct_HateList*>& GetHateList() { return hate_list.GetHateList(); }
	bool CheckLosFN(Mob* other);
	bool CheckLosFN(float posX, float posY, float posZ, float mobSize);
	static bool CheckLosFN(glm::vec3 posWatcher, float sizeWatcher, glm::vec3 posTarget, float sizeTarget);
	virtual bool CheckWaterLoS(Mob* m);
	inline void SetLastLosState(bool value) { last_los_check = value; }
	inline bool CheckLastLosState() const { return last_los_check; }
	std::string GetMobDescription();

	std::list<struct_HateList*> GetFilteredHateList(
		EntityFilterType filter_type = EntityFilterType::All,
		uint32 distance = 0
	) {
		return hate_list.GetFilteredHateList(filter_type, distance);
	}

	void DamageHateList(
		int64 damage,
		uint32 distance = 0,
		EntityFilterType filter_type = EntityFilterType::All,
		bool is_percentage = false
	) {
		hate_list.DamageHateList(damage, distance, filter_type, is_percentage);
	}

	void DamageArea(
		int64 damage,
		uint32 distance = 0,
		EntityFilterType filter_type = EntityFilterType::All,
		bool is_percentage = false
	) {
		entity_list.DamageArea(this, damage, distance, filter_type, is_percentage);
	}

	//Quest
	void CameraEffect(uint32 duration, float intensity, Client *c = nullptr, bool global = false);
	inline bool GetQglobal() const { return qglobal; }

	//Other Packet
	void CreateDespawnPacket(EQApplicationPacket* app, bool Decay);
	void CreateHorseSpawnPacket(EQApplicationPacket* app, Mob* m = nullptr);
	void CreateSpawnPacket(EQApplicationPacket* app, Mob* ForWho = 0);
	static void CreateSpawnPacket(EQApplicationPacket* app, NewSpawn_Struct* ns);
	virtual void FillSpawnStruct(NewSpawn_Struct* ns, Mob* ForWho);
	void CreateHPPacket(EQApplicationPacket* app);
	void SendHPUpdate(bool force_update_all = false);
	virtual void ResetHPUpdateTimer() {}; // does nothing
	static void SetSpawnLastNameByClass(NewSpawn_Struct* ns);

	//Util
	static uint32 RandomTimer(int min, int max);
	static uint8 GetDefaultGender(uint16 in_race, uint8 in_gender = 0xFF);
	EQ::skills::SkillType GetSkillByItemType(int ItemType);
	uint8 GetItemTypeBySkill(EQ::skills::SkillType skill);
	virtual void MakePet(uint16 spell_id, const char* pettype, const char *petname = nullptr);
	virtual void MakePoweredPet(uint16 spell_id, const char* pettype, int16 petpower, const char *petname = nullptr, float in_size = 0.0f);
	bool IsWarriorClass() const;
	char GetCasterClass() const;
	uint8 GetArchetype() const;
	void SetZone(uint32 zone_id, uint32 instance_id);
	void SendStatsWindow(Client* c, bool use_window);
	void ShowStats(Client* client);
	void ShowBuffs(Client* c);
	bool PlotPositionAroundTarget(Mob* target, float &x_dest, float &y_dest, float &z_dest, bool lookForAftArc = true);
	virtual int GetKillExpMod() const { return 100; }

	// aura functions
	void MakeAura(uint16 spell_id);
	inline int GetAuraSlots() { return 1 + aabonuses.aura_slots + itembonuses.aura_slots + spellbonuses.aura_slots; }
	inline int GetTrapSlots() { return 1 + aabonuses.trap_slots + itembonuses.trap_slots + spellbonuses.trap_slots; }
	inline bool HasFreeAuraSlots() { return aura_mgr.count < GetAuraSlots(); }
	inline bool HasFreeTrapSlots() { return trap_mgr.count < GetTrapSlots(); }
	void AddAura(Aura *aura, AuraRecord &record);
	void AddTrap(Aura *aura, AuraRecord &record);
	bool CanSpawnAura(bool trap);
	void RemoveAura(int spawn_id, bool skip_strip = false, bool expired = false);
	void RemoveAllAuras();
	inline AuraMgr &GetAuraMgr() { return aura_mgr; } // mainly used for zone db loading/saving

	//Procs
	void TriggerDefensiveProcs(Mob *on, uint16 hand = EQ::invslot::slotPrimary, bool FromSkillProc = false, int64 damage = 0);
	bool AddRangedProc(uint16 spell_id, uint16 iChance = 3, uint16 base_spell_id = SPELL_UNKNOWN, uint32 proc_reuse_time = 0);
	bool RemoveRangedProc(uint16 spell_id, bool bAll = false);
	bool HasRangedProcs() const;
	bool AddDefensiveProc(uint16 spell_id, uint16 iChance = 3, uint16 base_spell_id = SPELL_UNKNOWN, uint32 proc_reuse_time = 0);
	bool RemoveDefensiveProc(uint16 spell_id, bool bAll = false);
	bool HasDefensiveProcs() const;
	bool HasSkillProcs() const;
	bool HasSkillProcSuccess() const;
	bool AddProcToWeapon(uint16 spell_id, bool bPerma = false, uint16 iChance = 3, uint16 base_spell_id = SPELL_UNKNOWN, int level_override = -1, uint32 proc_reuse_time = 0);
	bool RemoveProcFromWeapon(uint16 spell_id, bool bAll = false);
	bool HasProcs() const;
	bool IsCombatProc(uint16 spell_id);

	//More stuff to sort:
	virtual bool IsRaidTarget() const { return false; };
	virtual bool IsAttackAllowed(Mob *target, bool isSpellAttack = false);
	bool IsTargeted() const { return (targeted > 0); }
	inline void IsTargeted(int in_tar) { targeted += in_tar; if(targeted < 0) targeted = 0;}
	void SetFollowID(uint32 id) { follow_id = id; }
	void SetFollowDistance(uint32 dist) { follow_dist = dist; }
	void SetFollowCanRun(bool v) { follow_run = v; }
	uint32 GetFollowID() const { return follow_id; }
	uint32 GetFollowDistance() const { return follow_dist; }
	bool GetFollowCanRun() const { return follow_run; }
	inline bool IsRareSpawn() const { return rare_spawn; }
	inline void SetRareSpawn(bool in) { rare_spawn = in; }

	virtual void Message(uint32 type, const char* message, ...) { }
	virtual void MessageString(uint32 type, uint32 string_id, uint32 distance = 0) { }
	virtual void MessageString(uint32 type, uint32 string_id, const char* message, const char* message2 = 0,
		const char* message3 = 0, const char* message4 = 0, const char* message5 = 0, const char* message6 = 0,
		const char* message7 = 0, const char* message8 = 0, const char* message9 = 0, uint32 distance = 0) { }
	virtual void FilteredMessageString(Mob *sender, uint32 type, eqFilterType filter, uint32 string_id) { }
	virtual void FilteredMessageString(Mob *sender, uint32 type, eqFilterType filter,
			uint32 string_id, const char *message1, const char *message2 = nullptr,
			const char *message3 = nullptr, const char *message4 = nullptr,
			const char *message5 = nullptr, const char *message6 = nullptr,
			const char *message7 = nullptr, const char *message8 = nullptr,
			const char *message9 = nullptr) { }
	void Say(const char *format, ...);
	void SayString(uint32 string_id, const char *message3 = 0, const char *message4 = 0, const char *message5 = 0,
		const char *message6 = 0, const char *message7 = 0, const char *message8 = 0, const char *message9 = 0);
	void SayString(uint32 type, uint32 string_id, const char *message3 = 0, const char *message4 = 0, const char *message5 = 0,
		const char *message6 = 0, const char *message7 = 0, const char *message8 = 0, const char *message9 = 0);
	void SayString(Client *to, uint32 string_id, const char *message3 = 0, const char *message4 = 0, const char *message5 = 0,
		const char *message6 = 0, const char *message7 = 0, const char *message8 = 0, const char *message9 = 0);
	void SayString(Client *to, uint32 type, uint32 string_id, const char *message3 = 0, const char *message4 = 0, const char *message5 = 0,
		const char *message6 = 0, const char *message7 = 0, const char *message8 = 0, const char *message9 = 0);
	void Shout(const char *format, ...);
	void Emote(const char *format, ...);
	void QuestJournalledSay(Client *QuestInitiator, const char *str, Journal::Options &opts);
	const int GetItemStat(uint32 item_id, std::string identifier);

	int64 CalcFocusEffect(focusType type, uint16 focus_id, uint16 spell_id, bool best_focus=false, uint16 casterid = 0, Mob *caster = nullptr);
	uint8 IsFocusEffect(uint16 spellid, int effect_index, bool AA=false,uint32 aa_effect=0);
	void SendIllusionPacket(const AppearanceStruct& a);
	void CloneAppearance(Mob* other, bool clone_name = false);
	void SetFaceAppearance(const FaceChange_Struct& face, bool skip_sender = false);
	bool RandomizeFeatures(bool send_illusion = true, bool set_variables = true);
	virtual void Stun(int duration);
	virtual void UnStun();
	inline void Silence(bool newval) { silenced = newval; }
	inline void Amnesia(bool newval) { amnesiad = newval; }
	void TemporaryPets(uint16 spell_id, Mob *target, const char *name_override = nullptr, uint32 duration_override = 0, bool followme=true, bool sticktarg=false, uint16 *controlled_pet_id = nullptr);
	void TypesTemporaryPets(uint32 typesid, Mob *target, const char *name_override = nullptr, uint32 duration_override = 0, bool followme=true, bool sticktarg=false);
	void WakeTheDead(uint16 spell_id, Corpse *corpse_to_use, Mob *target, uint32 duration);
	void Spin();
	void Kill();
	bool PassCharismaCheck(Mob* caster, uint16 spell_id);
	bool TryDeathSave();
	bool TryDivineSave();
	void TryTriggerOnCastFocusEffect(focusType type, uint16 spell_id);
	bool TryTriggerOnCastProc(uint16 focusspellid, uint16 spell_id, uint16 proc_spellid);
	bool TrySpellTrigger(Mob *target, uint32 spell_id, int effect);
	void TryTriggerOnCastRequirement();
	void TryTwincast(Mob *caster, Mob *target, uint32 spell_id);
	void TrySympatheticProc(Mob *target, uint32 spell_id);
	uint16 GetSympatheticFocusEffect(focusType type, uint16 spell_id);
	bool TryFadeEffect(int slot);
	void DispelMagic(Mob* casterm, uint16 spell_id, int effect_value);
	uint16 GetSpellEffectResistChance(uint16 spell_id);
	int32 GetVulnerability(Mob *caster, uint32 spell_id, uint32 ticsremaining, bool from_buff_tic = false);
	int64 GetFcDamageAmtIncoming(Mob *caster, int32 spell_id, bool from_buff_tic = false);
	int64 GetFocusIncoming(focusType type, int effect, Mob *caster, uint32 spell_id); //**** This can be removed when bot healing focus code is updated ****
	int32 GetSkillDmgTaken(const EQ::skills::SkillType skill_used, ExtraAttackOptions *opts = nullptr);
	int32 GetPositionalDmgTaken(Mob *attacker);
	int32 GetPositionalDmgTakenAmt(Mob *attacker);
	void DoKnockback(Mob *caster, uint32 push_back, uint32 push_up);
	int16 CalcResistChanceBonus();
	int16 CalcFearResistChance();
	void TrySpellOnKill(uint8 level, uint16 spell_id);
	bool TrySpellOnDeath();
	void CastOnCurer(uint32 spell_id);
	void CastOnCure(uint32 spell_id);
	void CastOnNumHitFade(uint32 spell_id);
	void SlowMitigation(Mob* caster);
	int16 GetCritDmgMod(uint16 skill, Mob* owner = nullptr);
	int16 GetMeleeDamageMod_SE(uint16 skill);
	int16 GetMeleeMinDamageMod_SE(uint16 skill);
	int16 GetCrippBlowChance();
	int16 GetMeleeDmgPositionMod(Mob* defender);
	int16 GetSkillReuseTime(uint16 skill);
	int GetCriticalChanceBonus(uint16 skill);
	int GetSkillDmgAmt(int skill_id);
	int16 GetPositionalDmgAmt(Mob* defender);
	inline bool CanBlockSpell() const { return(spellbonuses.FocusEffects[focusBlockNextSpell]); }
	bool DoHPToManaCovert(int32 mana_cost = 0);
	int8 GetDecayEffectValue(uint16 spell_id, uint16 spelleffect);
	int64 GetExtraSpellAmt(uint16 spell_id, int64 extra_spell_amt, int64 base_spell_dmg);
	void MeleeLifeTap(int64 damage);
	bool PassCastRestriction(int value);
	void SendCastRestrictionMessage(int requirement_id, bool is_target_requirement = true, bool is_discipline = false);
	bool ImprovedTaunt();
	bool TryRootFadeByDamage(int buffslot, Mob* attacker);
	float GetSlowMitigation() const { return slow_mitigation; }
	void CalcSpellPowerDistanceMod(uint16 spell_id, float range, Mob* caster = nullptr);
	inline int16 GetSpellPowerDistanceMod() const { return SpellPowerDistanceMod; };
	inline void SetSpellPowerDistanceMod(int16 value) { SpellPowerDistanceMod = value; };
	int32 GetSpellStat(uint32 spell_id, const char *identifier, uint8 slot = 0);
	bool HarmonySpellLevelCheck(int32 spell_id, Mob* target = nullptr);
	bool PassCharmTargetRestriction(Mob *target);
	bool CanFocusUseRandomEffectivenessByType(focusType type);
	int GetFocusRandomEffectivenessValue(int focus_base, int focus_base2, bool best_focus = 0);
	int GetHealRate() const { return itembonuses.HealRate + spellbonuses.HealRate + aabonuses.HealRate; }
	int GetMemoryBlurChance(int base_chance);
	inline bool HasBaseEffectFocus() const { return (spellbonuses.FocusEffects[focusFcBaseEffects] || aabonuses.FocusEffects[focusFcBaseEffects] || itembonuses.FocusEffects[focusFcBaseEffects]); }
	int32 GetDualWieldingSameDelayWeapons() const { return dw_same_delay; }
	inline void SetDualWieldingSameDelayWeapons(int32 val) { dw_same_delay = val; }
	bool IsTargetedFocusEffect(int focus_type);
	bool HasPersistDeathIllusion(int32 spell_id);


	bool TryDoubleMeleeRoundEffect();
	bool GetUseDoubleMeleeRoundDmgBonus() const { return use_double_melee_round_dmg_bonus; }
	inline void SetUseDoubleMeleeRoundDmgBonus(bool val) { use_double_melee_round_dmg_bonus = val; }

	void CastSpellOnLand(Mob* caster, int32 spell_id);

	bool IsFocusProcLimitTimerActive(int32 focus_spell_id);
	void SetFocusProcLimitTimer(int32 focus_spell_id, uint32 focus_reuse_time);
	bool IsProcLimitTimerActive(int32 base_spell_id, uint32 proc_reuse_time, int proc_type);
	void SetProcLimitTimer(int32 base_spell_id, uint32 proc_reuse_time, int proc_type);

	void VirusEffectProcess();
	void SpreadVirusEffect(int32 spell_id, uint32 caster_id, int32 buff_tics_remaining);

	void ModSkillDmgTaken(EQ::skills::SkillType skill_num, int value);
	int16 GetModSkillDmgTaken(const EQ::skills::SkillType skill_num);
	void ModVulnerability(uint8 resist, int16 value);
	int16 GetModVulnerability(const uint8 resist);

	void SetAllowBeneficial(bool value) { m_AllowBeneficial = value; }
	bool GetAllowBeneficial() { if (m_AllowBeneficial || GetSpecialAbility(ALLOW_BENEFICIAL)){return true;} return false; }
	void SetDisableMelee(bool value) { m_DisableMelee = value; }
	bool IsMeleeDisabled() { if (m_DisableMelee || GetSpecialAbility(DISABLE_MELEE)){return true;} return false; }

	bool IsOffHandAtk() const { return offhand; }
	inline void OffHandAtk(bool val) { offhand = val; }

	void SetFlurryChance(uint8 value) { SetSpecialAbilityParam(SPECATK_FLURRY, 0, value); }
	uint8 GetFlurryChance() { return GetSpecialAbilityParam(SPECATK_FLURRY, 0); }

	static uint32 GetAppearanceValue(EmuAppearance in_appearance);
	void SendAppearancePacket(uint32 type, uint32 value, bool whole_zone = true, bool ignore_self = false, Client* target = nullptr);
	void SetAppearance(EmuAppearance app, bool ignore_self = true);
	inline EmuAppearance GetAppearance() const { return _appearance; }
	inline const int GetAnimation() const { return animation; }
	inline void SetAnimation(int a) { animation = a; }
	inline const uint8 GetRunAnimSpeed() const { return pRunAnimSpeed; }
	inline void SetRunAnimSpeed(int8 in) { pRunAnimSpeed = in; }
	bool IsDestructibleObject() { return destructibleobject; }
	void SetDestructibleObject(bool in) { destructibleobject = in; }

	inline uint8 GetInnateLightType() { return m_Light.Type[EQ::lightsource::LightInnate]; }
	inline uint8 GetEquipmentLightType() { return m_Light.Type[EQ::lightsource::LightEquipment]; }
	inline uint8 GetSpellLightType() { return m_Light.Type[EQ::lightsource::LightSpell]; }

	virtual void UpdateEquipmentLight() { m_Light.Type[EQ::lightsource::LightEquipment] = 0; m_Light.Level[EQ::lightsource::LightEquipment] = 0; }
	inline void SetSpellLightType(uint8 light_type) { m_Light.Type[EQ::lightsource::LightSpell] = (light_type & 0x0F); m_Light.Level[EQ::lightsource::LightSpell] = EQ::lightsource::TypeToLevel(m_Light.Type[EQ::lightsource::LightSpell]); }

	void SendWearChangeAndLighting(int8 last_texture);
	inline uint8 GetActiveLightType() { return m_Light.Type[EQ::lightsource::LightActive]; }
	bool UpdateActiveLight(); // returns true if change, false if no change

	EQ::LightSourceProfile* GetLightProfile() { return &m_Light; }

	Mob* GetPet();
	void SetPet(Mob* newpet);
	virtual Mob* GetOwner();
	virtual Mob* GetOwnerOrSelf();
	Mob* GetUltimateOwner();
	void SetPetID(uint16 NewPetID);
	inline uint16 GetPetID() const { return petid; }
	inline PetType GetPetType() const { return type_of_pet; }
	void SetPetType(PetType p) { type_of_pet = p; }
	inline int16 GetPetPower() const { return (petpower < 0) ? 0 : petpower; }
	void SetPetPower(int16 p) { if (p < 0) petpower = 0; else petpower = p; }
	bool IsFamiliar() const { return type_of_pet == petFamiliar; }
	bool IsAnimation() const { return type_of_pet == petAnimation; }
	bool IsCharmed() const { return type_of_pet == petCharmed; }
	bool IsTargetLockPet() const { return type_of_pet == petTargetLock; }
	inline uint32 GetPetTargetLockID() { return pet_targetlock_id; };
	inline void SetPetTargetLockID(uint32 value) { pet_targetlock_id = value; };
	void SetOwnerID(uint16 new_owner_id);
	inline uint16 GetOwnerID() const { return ownerid; }
	inline virtual bool HasOwner() { if (!GetOwnerID()){ return false; } return entity_list.GetMob(GetOwnerID()) != 0; }
	inline virtual bool IsPet() { return HasOwner() && !IsMerc(); }
	bool HasPet() const;
	inline bool HasTempPetsActive() const { return(hasTempPet); }
	inline void SetTempPetsActive(bool i) { hasTempPet = i; }
	inline int16 GetTempPetCount() const { return count_TempPet; }
	inline void SetTempPetCount(int16 i) { count_TempPet = i; }
	bool HasPetAffinity() { if (aabonuses.GivePetGroupTarget || itembonuses.GivePetGroupTarget || spellbonuses.GivePetGroupTarget) return true; return false; }
	inline bool IsPetOwnerBot() const { return pet_owner_bot; }
	inline void SetPetOwnerBot(bool b) { pet_owner_bot = b; }
	inline bool IsPetOwnerClient() const { return pet_owner_client; }
	inline void SetPetOwnerClient(bool b) { pet_owner_client = b; }
	inline bool IsPetOwnerNPC() const { return pet_owner_npc; }
	inline void SetPetOwnerNPC(bool b) { pet_owner_npc = b; }
	inline bool IsTempPet() const { return _IsTempPet; }
	inline void SetTempPet(bool value) { _IsTempPet = value; }
	inline bool IsHorse() { return is_horse; }
	int GetPetAvoidanceBonusFromOwner();
	int GetPetACBonusFromOwner();
	int GetPetATKBonusFromOwner();

	inline const bodyType GetBodyType() const { return bodytype; }
	inline const bodyType GetOrigBodyType() const { return orig_bodytype; }
	void SetBodyType(bodyType new_body, bool overwrite_orig);

	bool invulnerable;
	bool qglobal;

	virtual void SetAttackTimer();
	inline void SetInvul(bool invul) { invulnerable=invul; }
	inline bool GetInvul(void) { return invulnerable; }
	inline void SetExtraHaste(int Haste) { ExtraHaste = Haste; }
	virtual int GetHaste();
	int32 GetMeleeMitigation();

	uint8 GetWeaponDamageBonus(const EQ::ItemData* weapon, bool offhand = false);
	const DamageTable &GetDamageTable() const;
	void ApplyDamageTable(DamageHitInfo &hit);
	virtual int GetHandToHandDamage(void);

	bool CanThisClassDoubleAttack(void) const;
	bool CanThisClassTripleAttack() const;
	bool CanThisClassDualWield(void) const;
	bool CanThisClassRiposte(void) const;
	bool CanThisClassDodge(void) const;
	bool CanThisClassParry(void) const;
	bool CanThisClassBlock(void) const;

	int GetHandToHandDelay(void);
	uint32 GetClassLevelFactor();
	void Mesmerize();
	inline bool IsMezzed() const { return mezzed; }
	inline bool IsStunned() const { return stunned; }
	inline bool IsSilenced() const { return silenced; }
	inline bool IsAmnesiad() const { return amnesiad; }

	int64 ReduceDamage(int64 damage);
	int64 AffectMagicalDamage(int64 damage, uint16 spell_id, const bool iBuffTic, Mob* attacker);
	int64 ReduceAllDamage(int64 damage);

	void DoSpecialAttackDamage(Mob *who, EQ::skills::SkillType skill, int base_damage, int min_damage = 0, int32 hate_override = -1, int ReuseTime = 10);
	void DoThrowingAttackDmg(Mob* other, const EQ::ItemInstance* RangeWeapon = nullptr, const EQ::ItemData* AmmoItem = nullptr, int32 weapon_damage = 0, int16 chance_mod = 0, int16 focus = 0, int ReuseTime = 0, uint32 range_id = 0, int AmmoSlot = 0, float speed = 4.0f, bool DisableProcs = false);
	void DoMeleeSkillAttackDmg(Mob* other, int32 weapon_damage, EQ::skills::SkillType skillinuse, int16 chance_mod = 0, int16 focus = 0, bool can_riposte = false, int ReuseTime = 0);
	void DoArcheryAttackDmg(Mob* other, const EQ::ItemInstance* RangeWeapon = nullptr, const EQ::ItemInstance* Ammo = nullptr, int32 weapon_damage = 0, int16 chance_mod = 0, int16 focus = 0, int ReuseTime = 0, uint32 range_id = 0, uint32 ammo_id = 0, const EQ::ItemData *AmmoItem = nullptr, int AmmoSlot = 0, float speed = 4.0f, bool DisableProcs = false);
	bool TryProjectileAttack(Mob* other, const EQ::ItemData *item, EQ::skills::SkillType skillInUse, uint64 weapon_dmg, const EQ::ItemInstance* RangeWeapon, const EQ::ItemInstance* Ammo, int AmmoSlot, float speed, bool DisableProcs = false);
	void ProjectileAttack();
	inline bool HasProjectileAttack() const { return ActiveProjectileATK; }
	inline void SetProjectileAttack(bool value) { ActiveProjectileATK = value; }
	float GetRangeDistTargetSizeMod(Mob* other);
	bool CanDoSpecialAttack(Mob *other);
	bool Flurry(ExtraAttackOptions *opts);
	bool Rampage(ExtraAttackOptions *opts);
	bool AddRampage(Mob*);
	void ClearRampage();
	void RemoveFromRampageList(Mob* mob, bool remove_feigned = false);
	void SetBottomRampageList();
	void SetTopRampageList();
	void AreaRampage(ExtraAttackOptions *opts);
	inline bool IsSpecialAttack(eSpecialAttacks in) { return m_specialattacks == in; }

	void StartEnrage();
	void ProcessEnrage();
	bool IsEnraged();
	void Taunt(NPC *who, bool always_succeed, int chance_bonus = 0, bool from_spell = false, int32 bonus_hate = 0);

	virtual void AI_Init();
	virtual void AI_Start(uint32 iMoveDelay = 0);
	virtual void AI_Stop();
	virtual void AI_ShutDown();
	virtual void AI_Process();

	bool ClearEntityVariables();
	bool DeleteEntityVariable(std::string variable_name);
	std::string GetEntityVariable(std::string variable_name);
	std::vector<std::string> GetEntityVariables();
	void SetEntityVariable(std::string variable_name, std::string variable_value);
	bool EntityVariableExists(std::string variable_name);

	void AI_Event_Engaged(Mob* attacker, bool yell_for_help = true);
	void AI_Event_NoLongerEngaged();

	FACTION_VALUE GetSpecialFactionCon(Mob* iOther);
	inline const bool IsAIControlled() const { return pAIControlled; }
	inline const float GetAggroRange() const { return (spellbonuses.AggroRange == -1) ? pAggroRange : spellbonuses.AggroRange; }
	inline const float GetAssistRange() const { return (spellbonuses.AssistRange == -1) ? pAssistRange : spellbonuses.AssistRange; }


	inline void SetPetOrder(eStandingPetOrder i) { pStandingPetOrder = i; }
	inline const eStandingPetOrder GetPetOrder() const { return pStandingPetOrder; }
	inline void SetHeld(bool nState) { held = nState; }
	inline const bool IsHeld() const { return held; }
	inline void SetGHeld(bool nState) { gheld = nState; }
	inline const bool IsGHeld() const { return gheld; }
	inline void SetNoCast(bool nState) { nocast = nState; }
	inline const bool IsNoCast() const { return nocast; }
	inline void SetFocused(bool nState) { focused = nState; }
	inline const bool IsFocused() const { return focused; }
	inline void SetPetStop(bool nState) { pet_stop = nState; }
	inline const bool IsPetStop() const { return pet_stop; }
	inline void SetPetRegroup(bool nState) { pet_regroup = nState; }
	inline const bool IsPetRegroup() const { return pet_regroup; }
	inline const bool IsRoamer() const { return roamer; }
	inline const int GetWanderType() const { return wandertype; }
	inline const bool IsRooted() const { return rooted || permarooted; }
	inline const bool IsPermaRooted() const { return permarooted; }
	int GetSnaredAmount();
	inline const bool IsPseudoRooted() const { return pseudo_rooted; }
	inline void SetPseudoRoot(bool prState) { pseudo_rooted = prState; }

	int GetCurWp() { return cur_wp; }

	//old fear function
	//void SetFeared(Mob *caster, uint32 duration, bool flee = false);
	int GetFearSpeed() { return _GetFearSpeed(); }
	bool IsFeared() { return (spellbonuses.IsFeared || flee_mode); } // This returns true if the mob is feared or fleeing due to low HP
	inline void StartFleeing() { flee_mode = true; CalculateNewFearpoint(); }
	void ProcessFlee();
	void CheckFlee();
	inline bool IsBlind() { return spellbonuses.IsBlind; }

	inline bool			CheckAggro(Mob* other) {return hate_list.IsEntOnHateList(other);}
	float				CalculateHeadingToTarget(float in_x, float in_y) { return HeadingAngleToMob(in_x, in_y); }
	virtual void		WalkTo(float x, float y, float z);
	virtual void		RunTo(float x, float y, float z);
	void				NavigateTo(float x, float y, float z);
	void				RotateTo(float new_heading);
	void				RotateToWalking(float new_heading);
	void				RotateToRunning(float new_heading);
	void				StopNavigation();
	float				CalculateDistance(float x, float y, float z);
	float				CalculateDistance(Mob* mob);
	float				GetGroundZ(float new_x, float new_y, float z_offset=0.0);
	void				SendTo(float new_x, float new_y, float new_z);
	void				SendToFixZ(float new_x, float new_y, float new_z);
	float				GetZOffset() const;
	float               GetDefaultRaceSize(int race_id = -1, int gender_id = -1) const;
	void 				FixZ(int32 z_find_offset = 5, bool fix_client_z = false);
	float				GetFixedZ(const glm::vec3 &destination, int32 z_find_offset = 5);
	virtual int			GetStuckBehavior() const { return 0; }

	void				NPCSpecialAttacks(const char* parse, int permtag, bool reset = true, bool remove = false);
	inline uint32		DontHealMeBefore() const { return pDontHealMeBefore; }
	inline uint32		DontBuffMeBefore() const { return pDontBuffMeBefore; }
	inline uint32		DontDotMeBefore() const { return pDontDotMeBefore; }
	inline uint32		DontRootMeBefore() const { return pDontRootMeBefore; }
	inline uint32		DontSnareMeBefore() const { return pDontSnareMeBefore; }
	inline uint32		DontCureMeBefore() const { return pDontCureMeBefore; }
	void				SetDontRootMeBefore(uint32 time) { pDontRootMeBefore = time; }
	void				SetDontHealMeBefore(uint32 time) { pDontHealMeBefore = time; }
	void				SetDontBuffMeBefore(uint32 time) { pDontBuffMeBefore = time; }
	void				SetDontDotMeBefore(uint32 time) { pDontDotMeBefore = time; }
	void				SetDontSnareMeBefore(uint32 time) { pDontSnareMeBefore = time; }
	void				SetDontCureMeBefore(uint32 time) { pDontCureMeBefore = time; }

	// calculate interruption of spell via movement of mob
	void SaveSpellLoc() { m_SpellLocation = glm::vec3(m_Position); }
	inline float GetSpellX() const {return m_SpellLocation.x;}
	inline float GetSpellY() const {return m_SpellLocation.y;}
	inline float GetSpellZ() const {return m_SpellLocation.z;}
	inline bool IsGrouped() const { return isgrouped; }
	void SetGrouped(bool v);
	inline bool IsRaidGrouped() const { return israidgrouped; }
	void SetRaidGrouped(bool v);
	inline uint16 IsLooting() const { return entity_id_being_looted; }
	void SetLooting(uint16 val) { entity_id_being_looted = val; }

	bool CheckWillAggro(Mob *mob);

	void InstillDoubt(Mob *who);
	bool Charmed() const { return type_of_pet == petCharmed; }
	static uint32 GetLevelHP(uint8 tlevel);
	uint32 GetZoneID() const; //for perl
	uint16 GetInstanceVersion() const; //for perl
	virtual int32 CheckAggroAmount(uint16 spell_id, Mob *target, bool isproc = false);
	virtual int32 CheckHealAggroAmount(uint16 spell_id, Mob *target, uint32 heal_possible = 0);

	//uint32 GetInstrumentMod(uint16 spell_id) const;
	uint32 GetInstrumentMod(uint16 spell_id);
	int64 CalcSpellEffectValue(uint16 spell_id, int effect_id, int caster_level = 1, uint32 instrument_mod = 10, Mob *caster = nullptr, int ticsremaining = 0,uint16 casterid=0);
	int64 CalcSpellEffectValue_formula(uint32 formula, int64 base_value, int64 max_value, int caster_level, uint16 spell_id, int ticsremaining = 0);
	virtual int CheckStackConflict(uint16 spellid1, int caster_level1, uint16 spellid2, int caster_level2, Mob* caster1 = nullptr, Mob* caster2 = nullptr, int buffslot = -1);
	uint32 GetCastedSpellInvSlot() const { return casting_spell_inventory_slot; }

	// HP Event
	inline int GetNextHPEvent() const { return nexthpevent; }
	void SetNextHPEvent( int hpevent );
	void SendItemAnimation(Mob *to, const EQ::ItemData *item, EQ::skills::SkillType skillInUse, float velocity = 4.0);
	inline int& GetNextIncHPEvent() { return nextinchpevent; }
	void SetNextIncHPEvent( int inchpevent );

	inline bool DivineAura() const { return spellbonuses.DivineAura; }
 	inline bool Sanctuary() const { return spellbonuses.Sanctuary; }

	bool HasNPCSpecialAtk(const char* parse);
	bool HasSpecialAbilities();
	int GetSpecialAbility(int ability);
	int GetSpecialAbilityParam(int ability, int param);
	void SetSpecialAbility(int ability, int level);
	void SetSpecialAbilityParam(int ability, int param, int value);
	void StartSpecialAbilityTimer(int ability, uint32 time);
	void StopSpecialAbilityTimer(int ability);
	Timer *GetSpecialAbilityTimer(int ability);
	void ClearSpecialAbilities();
	void ProcessSpecialAbilities(const std::string &str);
	bool IsMoved() { return moved; }
	void SetMoved(bool moveflag) { moved = moveflag; }

	Trade* trade;

	bool ShieldAbility(uint32 target_id, int shielder_max_distance = 15, int shield_duration = 12000, int shield_target_mitigation = 50, int shielder_mitigation = 75, bool use_aa = false, bool can_shield_npc = true);
	void DoShieldDamageOnShielder(Mob *shield_target, int64 hit_damage_done, EQ::skills::SkillType skillInUse);
	void ShieldAbilityFinish();
	void ShieldAbilityClearVariables();
	inline uint32 GetShielderID() const { return m_shielder_id; }
	inline void SetShielderID(uint32 val) { m_shielder_id = val; }
	inline uint32 GetShieldTargetID() const { return m_shield_target_id; }
	inline void SetShieldTargetID(uint32 val) { m_shield_target_id = val; }
	inline int GetShieldTargetMitigation() const { return m_shield_target_mitigation; }
	inline void SetShieldTargetMitigation(int val) { m_shield_target_mitigation = val; }
	inline int GetShielderMitigation() const { return m_shielder_mitigation; }
	inline void SetShielderMitigation(int val) { m_shielder_mitigation = val; }
	inline int GetMaxShielderDistance() const { return m_shielder_max_distance; }
	inline void SetShielderMaxDistance(int val) { m_shielder_max_distance = val; }

	WeaponStance_Struct weaponstance;
	bool IsWeaponStanceEnabled() const { return weaponstance.enabled; }
	inline void SetWeaponStanceEnabled(bool val) { weaponstance.enabled = val; }


	inline glm::vec4 GetCurrentWayPoint() const { return m_CurrentWayPoint; }
	inline float GetCWPP() const { return(static_cast<float>(cur_wp_pause)); }
	inline int GetCWP() const { return(cur_wp); }
	void SetCurrentWP(int waypoint) { cur_wp = waypoint; }
	virtual FACTION_VALUE GetReverseFactionCon(Mob* iOther) { return FACTION_INDIFFERENTLY; }

	virtual const bool IsUnderwaterOnly() const { return false; }
	inline bool IsTrackable() const { return(trackable); }
	Timer* GetAIThinkTimer() { return AI_think_timer.get(); }
	Timer* GetAIMovementTimer() { return AI_movement_timer.get(); }
	Timer GetAttackTimer() { return attack_timer; }
	Timer GetAttackDWTimer() { return attack_dw_timer; }
	inline bool IsFindable() { return findable; }
	inline uint8 GetManaPercent() { return (uint8)((float)current_mana / (float)max_mana * 100.0f); }
	virtual uint8 GetEndurancePercent() { return 0; }

	inline virtual bool IsBlockedBuff(int32 SpellID) { return false; }
	inline virtual bool IsBlockedPetBuff(int32 SpellID) { return false; }

	std::string GetGlobal(const char *varname);
	void SetGlobal(const char *varname, const char *newvalue, int options, const char *duration, Mob *other = nullptr);
	void TarGlobal(const char *varname, const char *value, const char *duration, int npcid, int charid, int zoneid);
	void DelGlobal(const char *varname);

	inline void SetEmoteID(uint32 emote) { emoteid = emote; }
	inline uint32 GetEmoteID() { return emoteid; }

	bool HasSpellEffect(int effect_id);

	std::string GetRacePlural();
	std::string GetClassPlural();

	//Command #Tune functions
	void TuneGetStats(Mob* defender, Mob *attacker);
	void TuneGetACByPctMitigation(Mob* defender, Mob *attacker, float pct_mitigation, int interval = 10, int max_loop = 1000, int atk_override = 0, int Msg = 0);
	void TuneGetATKByPctMitigation(Mob* defender, Mob *attacker, float pct_mitigation, int interval = 10, int max_loop = 1000, int ac_override = 0, int Msg = 0);
	void TuneGetAvoidanceByHitChance(Mob* defender, Mob *attacker, float hit_chance, int interval, int max_loop, int accuracy_override, int Msg);
	void TuneGetAccuracyByHitChance(Mob* defender, Mob *attacker, float hit_chance, int interval, int max_loop, int avoidance_override, int Msg);
	/*support functions*/
	int64 TuneClientGetMeanDamage(Mob* other, int ac_override = 0, int atk_override = 0, int add_ac = 0, int add_atk = 0);
	int64 TuneClientGetMaxDamage(Mob* other);
	int64 TuneClientGetMinDamage(Mob* other, int max_hit);
	float TuneGetACMitigationPct(Mob* defender, Mob *attacker);
	int64 TuneGetOffense(Mob* defender, Mob *attacker, int atk_override = 0);
	int64 TuneGetAccuracy(Mob* defender, Mob *attacker, int accuracy_override = 0, int add_accuracy = 0);
	int64 TuneGetAvoidance(Mob* defender, Mob *attacker, int avoidance_override = 0, int add_avoidance = 0);
	float TuneGetHitChance(Mob* defender, Mob *attacker, int avoidance_override = 0, int accuracy_override = 0, int add_avoidance = 0, int add_accuracy = 0);
	float TuneGetAvoidMeleeChance(Mob* defender, Mob *attacker, int type);
	int64 TuneCalcEvasionBonus(int final_avoidance, int base_avoidance);
	/*modified combat code - These SYNC to attack.cpp, relevant changes to these functions in attack.cpp should be changed to the below as well*/
	int64 TuneNPCAttack(Mob* other, bool no_avoid = true, bool no_hit_chance = true, int hit_chance_bonus = 10000, int ac_override = 0, int atk_override = 0, int add_ac = 0, int add_atk = 0,
		bool get_offense = false, bool get_accuracy = false, int avoidance_override = 0, int accuracy_override = 0, int add_avoidance = 0, int add_accuracy = 0);
	int64 TuneClientAttack(Mob* other, bool no_avoid = true, bool no_hit_chance = true, int hit_chance_bonus = 10000, int ac_override = 0, int atk_override = 0, int add_ac = 0, int add_atk = 0,
		bool get_offense = false, bool get_accuracy = false, int avoidance_override = 0, int accuracy_override = 0, int add_avoidance = 0, int add_accuracy = 0);
	void TuneDoAttack(Mob *other, DamageHitInfo &hit, ExtraAttackOptions *opts = nullptr, bool no_avoid = true, bool no_hit_chance = true, int ac_override = 0, int add_ac = 0,
		int avoidance_override = 0, int accuracy_override = 0, int add_avoidance = 0, int add_accuracy = 0);
	void TuneMeleeMitigation(Mob *attacker, DamageHitInfo &hit, int ac_override, int add_ac);
	int64 Tuneoffense(EQ::skills::SkillType skill, int atk_override = 0, int add_atk = 0);
	int64 TuneACSum(bool skip_caps=false, int ac_override = 0, int add_ac = 0);
	int64 TuneGetTotalToHit(EQ::skills::SkillType skill, int chance_mod, int accuracy_override = 0, int add_accurracy = 0); // compute_tohit + spell bonuses
	int64 Tunecompute_tohit(EQ::skills::SkillType skillinuse, int accuracy_override = 0, int add_accuracy = 0);
	int64 TuneGetTotalDefense(int avoidance_override = 0, int add_avoidance = 0);
	int64 Tunecompute_defense(int avoidance_override = 0, int add_avoidance = 0);
	bool TuneCheckHitChance(Mob* other, DamageHitInfo &hit, int avoidance_override = 0, int add_avoidance = 0);
	EQ::skills::SkillType TuneAttackAnimation(int Hand, const EQ::ItemInstance* weapon, EQ::skills::SkillType skillinuse = EQ::skills::Skill1HBlunt);
	void TuneCommonOutgoingHitSuccess(Mob *defender, DamageHitInfo &hit, ExtraAttackOptions *opts = nullptr);

	//aa new
	uint32 GetAA(uint32 rank_id, uint32 *charges = nullptr) const;
	uint32 GetAAByAAID(uint32 aa_id, uint32 *charges = nullptr) const;
	bool SetAA(uint32 rank_id, uint32 new_value, uint32 charges = 0);
	void ClearAAs() { aa_ranks.clear(); }
	bool CanUseAlternateAdvancementRank(AA::Rank *rank);
	bool CanPurchaseAlternateAdvancementRank(AA::Rank *rank, bool check_price, bool check_grant);
	int GetAlternateAdvancementCooldownReduction(AA::Rank *rank_in);
	void ExpendAlternateAdvancementCharge(uint32 aa_id);
	void CalcAABonuses(StatBonuses* newbon);
	int64 CalcAAFocus(focusType type, const AA::Rank &rank, uint16 spell_id);
	void ApplyAABonuses(const AA::Rank &rank, StatBonuses* newbon);
	bool CheckAATimer(int timer);

	void CalcItemBonuses(StatBonuses* b);
	void AddItemBonuses(const EQ::ItemInstance* inst, StatBonuses* b, bool is_augment = false, bool is_tribute = false, int recommended_level_override = 0, bool is_ammo_item = false);
	void AdditiveWornBonuses(const EQ::ItemInstance* inst, StatBonuses* b, bool is_augment = false);
	int CalcRecommendedLevelBonus(uint8 current_level, uint8 recommended_level, int base_stat);

	int NPCAssistCap() { return npc_assist_cap; }
	void AddAssistCap() { ++npc_assist_cap; }
	void DelAssistCap() { --npc_assist_cap; }
	void ResetAssistCap() { npc_assist_cap = 0; }
	int64 GetWeaponDamage(Mob *against, const EQ::ItemData *weapon_item);
	int64 GetWeaponDamage(Mob *against, const EQ::ItemInstance *weapon_item, int64 *hate = nullptr);
	int64 DoDamageCaps(int64 base_damage);

	int64 GetHPRegen() const;
	int64 GetHPRegenPerSecond() const;
	int64 GetManaRegen() const;
	int64 GetEnduranceRegen() const;

	bool CanOpenDoors() const;
	void SetCanOpenDoors(bool can_open);

	void SetFeigned(bool in_feigned);
	/// this cures timing issues cuz dead animation isn't done but server side feigning is?
	inline bool GetFeigned() const { return(feigned); }

	// Data Bucket Methods
	void DeleteBucket(std::string bucket_name);
	std::string GetBucket(std::string bucket_name);
	std::string GetBucketExpires(std::string bucket_name);
	std::string GetBucketRemaining(std::string bucket_name);
	void SetBucket(std::string bucket_name, std::string bucket_value, std::string expiration = "");

	uint32 GetMobTypeIdentifier();

	// Heroic Stat Benefits
	float CheckHeroicBonusesDataBuckets(std::string bucket_name);

	int DispatchZoneControllerEvent(QuestEventID evt, Mob* init, const std::string& data, uint32 extra, std::vector<std::any>* pointers);

	// Bots HealRotation methods
	bool IsHealRotationTarget() { return (m_target_of_heal_rotation.use_count() && m_target_of_heal_rotation.get()); }
	bool JoinHealRotationTargetPool(std::shared_ptr<HealRotation>* heal_rotation);
	bool LeaveHealRotationTargetPool();

	uint32 HealRotationHealCount();
	uint32 HealRotationExtendedHealCount();
	float HealRotationHealFrequency();
	float HealRotationExtendedHealFrequency();

	const std::shared_ptr<HealRotation>* TargetOfHealRotation() const { return &m_target_of_heal_rotation; }


	// not Bots HealRotation methods
	void SetManualFollow(bool flag) { m_manual_follow = flag; }
	bool GetManualFollow() const { return m_manual_follow; }

	void DrawDebugCoordinateNode(std::string node_name, const glm::vec4 vec);

	void CalcHeroicBonuses(StatBonuses* newbon);

	DataBucketKey GetScopedBucketKeys();

protected:
	void CommonDamage(Mob* other, int64 &damage, const uint16 spell_id, const EQ::skills::SkillType attack_skill, bool &avoidable, const int8 buffslot, const bool iBuffTic, eSpecialAttacks specal = eSpecialAttacks::None);
	static uint16 GetProcID(uint16 spell_id, uint8 effect_index);
	int _GetWalkSpeed() const;
	int _GetRunSpeed() const;
	int _GetFearSpeed() const;

	Timer m_z_clip_check_timer;

	// dynamically set via memory on constructor
	int8 m_max_procs = 0;

	virtual bool AI_EngagedCastCheck() { return(false); }
	virtual bool AI_PursueCastCheck() { return(false); }
	virtual bool AI_IdleCastCheck() { return(false); }

	bool moved;

	std::vector<uint16> RampageArray;
	std::map<std::string, std::string> m_EntityVariables;

	int16 SkillDmgTaken_Mod[EQ::skills::HIGHEST_SKILL + 2];
	int16 Vulnerability_Mod[HIGHEST_RESIST+2];
	bool m_AllowBeneficial;
	bool m_DisableMelee;

	bool isgrouped;
	bool israidgrouped;
	uint16 entity_id_being_looted; //the id of the entity being looted, 0 if not looting.
	uint8 texture;
	uint8 helmtexture;
	uint8 armtexture;
	uint8 bracertexture;
	uint8 handtexture;
	uint8 legtexture;
	uint8 feettexture;
	bool multitexture;

	int AC;
	int mitigation_ac; // cached Mob::ACSum
	int32 ATK;
	int32 STR;
	int32 STA;
	int32 DEX;
	int32 AGI;
	int32 INT;
	int32 WIS;
	int32 CHA;
	int32 MR;
	int32 CR;
	int32 FR;
	int32 DR;
	int32 PR;
	int32 Corrup;
	int32 PhR;
	bool moving;
	int targeted;
	bool findable;
	bool trackable;
	int64 current_hp;
	int64 max_hp;
	int64 base_hp;
	int64 current_mana;
	int64 max_mana;
	int64 hp_regen;
	int64 hp_regen_per_second;
	int64 mana_regen;
	int64 ooc_regen;
	uint8 maxlevel;
	uint32 scalerate;
	Buffs_Struct *buffs;
	StatBonuses itembonuses;
	StatBonuses spellbonuses;
	StatBonuses aabonuses;
	uint16 petid;
	uint16 ownerid;
	PetType type_of_pet;
	int16 petpower;
	uint32 follow_id;
	uint32 follow_dist;
	bool follow_run;
	bool no_target_hotkey;
	bool rare_spawn;
	int32 heroic_strikethrough;
	bool keeps_sold_items;

	uint32 m_PlayerState;
	uint32 GetPlayerState() { return m_PlayerState; }
	void AddPlayerState(uint32 new_state) { m_PlayerState |= new_state; }
	void RemovePlayerState(uint32 old_state) { m_PlayerState &= ~old_state; }
	void SendAddPlayerState(PlayerState new_state);
	void SendRemovePlayerState(PlayerState old_state);

	uint8 gender;
	uint16 race;
	uint16 use_model;
	uint8 base_gender;
	uint16 base_race;
	uint8 class_;
	bodyType bodytype;
	bodyType orig_bodytype;
	uint16 deity;
	uint8 level;
	uint8 orig_level;
	uint32 npctype_id;

	glm::vec4 m_Position;
	glm::vec4 m_RelativePosition;
	int animation; // this is really what MQ2 calls SpeedRun just packed like (int)(SpeedRun * 40.0f)
	float base_size;
	float size;
	float runspeed;
	float walkspeed;
	float fearspeed;
	int base_runspeed;
	int base_walkspeed;
	int base_fearspeed;
	int current_speed;
	eSpecialAttacks m_specialattacks;

	bool held;
	bool gheld;
	bool nocast;
	bool focused;
	bool pet_stop;
	bool pet_regroup;
	bool spawned;
	void CalcSpellBonuses(StatBonuses* newbon);
	virtual void CalcBonuses();
	void TrySkillProc(Mob *on, EQ::skills::SkillType skill, uint16 ReuseTime, bool Success = false, uint16 hand = 0, bool IsDefensive = false); // hand if 0 means its a skill ability for proc rate checks, otherwise hand is passed.
	bool PassLimitToSkill(EQ::skills::SkillType skill, int32 spell_id, int proc_type, int aa_id=0);
	bool PassLimitClass(uint32 Classes_, uint16 Class_);
	void TryCastOnSkillUse(Mob *on, EQ::skills::SkillType skill);
	void TryDefensiveProc(Mob *on, uint16 hand = EQ::invslot::slotPrimary);
	void TryWeaponProc(const EQ::ItemInstance* inst, const EQ::ItemData* weapon, Mob *on, uint16 hand = EQ::invslot::slotPrimary);
	void TrySpellProc(const EQ::ItemInstance* inst, const EQ::ItemData* weapon, Mob *on, uint16 hand = EQ::invslot::slotPrimary);
	void TryCombatProcs(const EQ::ItemInstance* weapon, Mob *on, uint16 hand = EQ::invslot::slotPrimary, const EQ::ItemData* weapon_data = nullptr);
	void ExecWeaponProc(const EQ::ItemInstance* weapon, uint16 spell_id, Mob *on, int level_override = -1);
	virtual float GetProcChances(float ProcBonus, uint16 hand = EQ::invslot::slotPrimary);
	virtual float GetDefensiveProcChances(float &ProcBonus, float &ProcChance, uint16 hand = EQ::invslot::slotPrimary, Mob *on = nullptr);
	virtual float GetSkillProcChances(uint16 ReuseTime, uint16 hand = 0); // hand = MainCharm?
	uint16 GetWeaponSpeedbyHand(uint16 hand);
	virtual int GetBaseSkillDamage(EQ::skills::SkillType skill, Mob *target = nullptr);
	virtual int64 GetFocusEffect(focusType type, uint16 spell_id, Mob *caster = nullptr, bool from_buff_tic = false);
	virtual EQ::InventoryProfile& GetInv() { return m_inv; }
	void CalculateNewFearpoint();
	float FindGroundZ(float new_x, float new_y, float z_offset=0.0);
	float FindDestGroundZ(glm::vec3 dest, float z_offset=0.0);

	virtual float GetSympatheticProcChances(uint16 spell_id, int16 ProcRateMod, int32 ItemProcRate = 0);
	int16 GetSympatheticSpellProcRate(uint16 spell_id);
	uint16 GetSympatheticSpellProcID(uint16 spell_id);

	enum {MAX_PROCS = 10};
	tProc PermaProcs[MAX_PROCS];
	tProc SpellProcs[MAX_PROCS];
	tProc DefensiveProcs[MAX_PROCS];
	tProc RangedProcs[MAX_PROCS];

	char name[64];
	char orig_name[64];
	char clean_name[64];
	char lastname[64];

	glm::vec4 m_Delta;
	// just locs around them to double check, if we do expand collision this should be cached on movement
	// ideally we should use real models, but this should be quick and work mostly
	glm::vec4 m_CollisionBox[COLLISION_BOX_SIZE];

	EQ::LightSourceProfile m_Light;

	EmuAppearance _appearance;
	uint8 pRunAnimSpeed;
	bool m_is_running;

	Timer attack_timer;
	Timer attack_dw_timer;
	Timer ranged_timer;
	float attack_speed; //% increase/decrease in attack speed (not haste)
	int attack_delay; //delay between attacks in 10ths of seconds
	bool always_aggro;
	int16 slow_mitigation; // Allows for a slow mitigation (100 = 100%, 50% = 50%)
	Timer hp_regen_per_second_timer;
	Timer tic_timer;
	Timer mana_timer;
	int32 dw_same_delay;

	Timer focusproclimit_timer[MAX_FOCUS_PROC_LIMIT_TIMERS];	//SPA 511
	int32 focusproclimit_spellid[MAX_FOCUS_PROC_LIMIT_TIMERS];	//SPA 511

	Timer spell_proclimit_timer[MAX_PROC_LIMIT_TIMERS];			//SPA 512
	int32 spell_proclimit_spellid[MAX_PROC_LIMIT_TIMERS];		//SPA 512
	Timer ranged_proclimit_timer[MAX_PROC_LIMIT_TIMERS];		//SPA 512
	int32 ranged_proclimit_spellid[MAX_PROC_LIMIT_TIMERS];		//SPA 512
	Timer def_proclimit_timer[MAX_PROC_LIMIT_TIMERS];			//SPA 512
	int32 def_proclimit_spellid[MAX_PROC_LIMIT_TIMERS];			//SPA 512

	int32 appearance_effects_id[MAX_APPEARANCE_EFFECTS];
	int32 appearance_effects_slot[MAX_APPEARANCE_EFFECTS];

	int queue_wearchange_slot;

	Timer shield_timer;
	uint32 m_shield_target_id;
	uint32 m_shielder_id;
	int m_shield_target_mitigation;
	int m_shielder_mitigation;
	int m_shielder_max_distance;

	//spell casting vars
	Timer spellend_timer;
	uint16 casting_spell_id;
	glm::vec3 m_SpellLocation;
	int attacked_count;
	bool delaytimer;
	uint16 casting_spell_targetid;
	EQ::spells::CastingSlot casting_spell_slot;
	int32 casting_spell_mana;
	uint32 casting_spell_inventory_slot;
	uint32 casting_spell_timer;
	uint32 casting_spell_timer_duration;
	int16 casting_spell_resist_adjust;
	uint32 casting_spell_aa_id;
	uint32 casting_spell_recast_adjust;
	bool casting_spell_checks;
	uint16 bardsong;
	EQ::spells::CastingSlot bardsong_slot;
	uint32 bardsong_target_id;

	bool ActiveProjectileATK;
	tProjatk ProjectileAtk[MAX_SPELL_PROJECTILE];

	glm::vec3 m_RewindLocation;

	Timer rewind_timer;

	// Currently 3 max nimbus particle effects at a time
	uint32 nimbus_effect1;
	uint32 nimbus_effect2;
	uint32 nimbus_effect3;

	uint8 haircolor;
	uint8 beardcolor;
	uint8 eyecolor1; // the eyecolors always seem to be the same, maybe left and right eye?
	uint8 eyecolor2;
	uint8 hairstyle;
	uint8 luclinface; //
	uint8 beard;
	uint32 drakkin_heritage;
	uint32 drakkin_tattoo;
	uint32 drakkin_details;
	EQ::TintProfile armor_tint;

	uint8 aa_title;

	int ExtraHaste; // for the #haste command
	bool mezzed;
	bool stunned;
	bool charmed; //this isnt fully implemented yet
	bool rooted;
	bool silenced;
	bool amnesiad;
	bool offhand;
	bool has_shield_equipped;
	bool has_two_hand_blunt_equipped;
	bool has_two_hander_equipped;
	bool has_dual_weapons_equipped;
	bool has_bowequipped = false;
	bool has_arrowequipped = false;
	bool use_double_melee_round_dmg_bonus;
	bool can_facestab;
	bool has_numhits;
	bool has_MGB;
	bool has_ProjectIllusion;
	int16 SpellPowerDistanceMod;
	bool last_los_check;
	bool pseudo_rooted;
	bool endur_upkeep;
	bool degenerating_effects; // true if we have a buff that needs to be recalced every tick
	bool spawned_in_water;
	bool is_boat;

	CombatRecord m_combat_record{};

public:
	const CombatRecord &GetCombatRecord() const;

public:
	bool GetWasSpawnedInWater() const;

	void SetSpawnedInWater(bool spawned_in_water);
	bool turning;

protected:

	// Bind wound
	Timer bindwound_timer;
	Mob* bindwound_target;

	Timer stunned_timer;
	Timer spun_timer;
	Timer bardsong_timer;
	Timer gravity_timer;
	Timer viral_timer;

	// MobAI stuff
	eStandingPetOrder pStandingPetOrder;
	uint32 minLastFightingDelayMoving;
	uint32 maxLastFightingDelayMoving;
	float pAggroRange = 0;
	float pAssistRange = 0;
	std::unique_ptr<Timer> AI_think_timer;
	std::unique_ptr<Timer> AI_movement_timer;
	std::unique_ptr<Timer> AI_target_check_timer;
	int8 ForcedMovement; // push
	bool permarooted;
	std::unique_ptr<Timer> AI_scan_area_timer;
	std::unique_ptr<Timer> AI_walking_timer;
	std::unique_ptr<Timer> AI_feign_remember_timer;
	std::unique_ptr<Timer> AI_check_signal_timer;
	std::unique_ptr<Timer> AI_scan_door_open_timer;
	uint32 time_until_can_move;
	HateList hate_list;
	std::set<uint32> feign_memory_list;
	// This is to keep track of the current (one only) faction mod (alliance)
	uint32 current_alliance_faction;
	int32 current_alliance_mod;
	void AddFactionBonus(uint32 pFactionID,int32 bonus);
	int32 GetFactionBonus(uint32 pFactionID);
	// This is to keep track of item faction modifiers
	std::map<uint32,int32> item_faction_bonuses; // Primary FactionID, Bonus
	void AddItemFactionBonus(uint32 pFactionID,int32 bonus);
	int32 GetItemFactionBonus(uint32 pFactionID);
	void ClearItemFactionBonuses();
	Timer hate_list_cleanup_timer;

	bool flee_mode;
	Timer flee_timer;
	Timer attack_anim_timer;
	Timer position_update_melee_push_timer;

	bool pAIControlled;
	bool roamer;

	int wandertype;
	int pausetype;

	int8 last_hp_percent;
	int32 last_hp;

	int cur_wp;
	glm::vec4 m_CurrentWayPoint;
	int cur_wp_pause;

	bool PrimaryAggro;
	bool AssistAggro;
	int npc_assist_cap;
	Timer assist_cap_timer; // clear assist cap so more nearby mobs can be called for help

	int patrol;
	glm::vec3 m_FearWalkTarget;
	bool currently_fleeing;

	bool pause_timer_complete;
	bool DistractedFromGrid;
	uint32 pDontHealMeBefore;
	uint32 pDontBuffMeBefore;
	uint32 pDontDotMeBefore;
	uint32 pDontRootMeBefore;
	uint32 pDontSnareMeBefore;
	uint32 pDontCureMeBefore;

	// hp event
	int nexthpevent;
	int nextinchpevent;

	//temppet
	bool hasTempPet;
	bool _IsTempPet;
	int16 count_TempPet;
	bool pet_owner_bot;    // Flags pets as belonging to a Bot
	bool pet_owner_client; // Flags pets as belonging to a Client
	bool pet_owner_npc;    // Flags pets as belonging to an NPC
	uint32 pet_targetlock_id;

	glm::vec3 m_TargetRing;

	GravityBehavior flymode;
	bool m_targetable;
	int QGVarDuration(const char *fmt);
	void InsertQuestGlobal(int charid, int npcid, int zoneid, const char *name, const char *value, int expdate);
	uint32 emoteid;

	SpecialAbility SpecialAbilities[MAX_SPECIAL_ATTACK];
	bool bEnraged;
	bool destructibleobject;

	std::unordered_map<uint32, std::pair<uint32, uint32>> aa_ranks;
	Timer aa_timers[aaTimerMax];

	bool is_horse;

	AuraMgr aura_mgr;
	AuraMgr trap_mgr;

	bool feigned;
	Timer forget_timer; // our 2 min everybody forgets you timer

	bool m_can_open_doors;

	MobMovementManager *mMovementManager;

private:
	Mob* target;
	EQ::InventoryProfile m_inv;
	std::shared_ptr<HealRotation> m_target_of_heal_rotation;
	bool m_manual_follow;

	void SetHeroicStrBonuses(StatBonuses* n);
	void SetHeroicStaBonuses(StatBonuses* n);
	void SetHeroicAgiBonuses(StatBonuses* n);
	void SetHeroicDexBonuses(StatBonuses* n);
	void SetHeroicIntBonuses(StatBonuses* n);
	void SetHeroicWisBonuses(StatBonuses* n);

	void DoSpellInterrupt(uint16 spell_id, int32 mana_cost, int my_curmana);
	void HandleDoorOpen();
};

#endif


/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2002 EQEMu Development Team (http://eqemu.org)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef NPC_H
#define NPC_H

#include "../common/rulesys.h"

#include "mob.h"
#include "qglobals.h"
#include "zonedb.h"
#include "../common/zone_store.h"
#include "zonedump.h"
#include "../common/repositories/npc_faction_entries_repository.h"
#include "../common/repositories/loottable_repository.h"
#include "../common/repositories/loottable_entries_repository.h"
#include "../common/repositories/lootdrop_repository.h"
#include "../common/repositories/lootdrop_entries_repository.h"

#include <deque>
#include <list>


#ifdef _WINDOWS
	#define M_PI	3.141592
#endif

typedef struct {
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;
	float	min_z;
	float	max_z;
	bool	say;
	bool	proximity_set;
} NPCProximity;

struct AISpells_Struct {
	uint32	type;			// 0 = never, must be one (and only one) of the defined values
	uint16	spellid;		// <= 0 = no spell
	int16	manacost;		// -1 = use spdat, -2 = no cast time
	uint32	time_cancast;	// when we can cast this spell next
	int32	recast_delay;
	int16	priority;
	int16	resist_adjust;
	int8	min_hp; // >0 won't cast if HP is below
	int8	max_hp; // >0 won't cast if HP is above
};

struct AISpellsEffects_Struct {
	uint16	spelleffectid;
	int32	base_value;
	int32	limit;
	int32	max_value;
};

struct AISpellsVar_Struct {
	uint32	fail_recast;
	uint32	engaged_no_sp_recast_min;
	uint32	engaged_no_sp_recast_max;
	uint8	engaged_beneficial_self_chance;
	uint8	engaged_beneficial_other_chance;
	uint8	engaged_detrimental_chance;
	uint32	pursue_no_sp_recast_min;
	uint32	pursue_no_sp_recast_max;
	uint8	pursue_detrimental_chance;
	uint32	idle_no_sp_recast_min;
	uint32	idle_no_sp_recast_max;
	uint8	idle_beneficial_chance;
};

struct Roambox {
	float  max_x;
	float  max_y;
	float  min_x;
	float  min_y;
	float  distance;
	float  dest_x;
	float  dest_y;
	float  dest_z;
	uint32 delay;
	uint32 min_delay;
};

class SwarmPet;
class Client;
class Group;
class Raid;
class Spawn2;
class Aura;

namespace EQ
{
	struct ItemData;
}

class NPC : public Mob
{
public:
	static NPC* SpawnNPC(const char* spawncommand, const glm::vec4& position, Client* client = nullptr);
	static bool	SpawnZoneController();

	// loot recording / simulator
	bool IsRecordLootStats() const;
	void SetRecordLootStats(bool record_loot_stats);
	const std::vector<uint32> &GetRolledItems() const;
	int GetRolledItemCount(uint32 item_id);

	NPC(const NPCType* npc_type_data, Spawn2* respawn, const glm::vec4& position, GravityBehavior iflymode, bool IsCorpse = false);

	virtual ~NPC();

	static NPC *SpawnNodeNPC(std::string name, std::string last_name, const glm::vec4 &position);
	static void SpawnGridNodeNPC(const glm::vec4 &position, int32 grid_id, int32 grid_number, int32 zoffset);
	static NPC * SpawnZonePointNodeNPC(std::string name, const glm::vec4 &position);

	//abstract virtual function implementations requird by base abstract class
	virtual bool Death(Mob* killer_mob, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill, KilledByTypes killed_by = KilledByTypes::Killed_NPC);
	virtual void Damage(Mob* from, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill, bool avoidable = true, int8 buffslot = -1, bool iBuffTic = false, eSpecialAttacks special = eSpecialAttacks::None);
	bool Attack(Mob* other, int Hand = EQ::invslot::slotPrimary, bool FromRiposte = false, bool IsStrikethrough = false,
		bool IsFromSpell = false, ExtraAttackOptions *opts = nullptr) override;
	virtual bool HasRaid() { return false; }
	virtual bool HasGroup() { return false; }
	virtual Raid* GetRaid() { return 0; }
	virtual Group* GetGroup() { return 0; }

	virtual bool IsNPC() const { return true; }

	virtual bool Process();
	virtual void	AI_Init();
	virtual void	AI_Start(uint32 iMoveDelay = 0);
	virtual void	AI_Stop();
	void			AI_DoMovement();
	void			AI_SetupNextWaypoint();
	bool			AI_AddNPCSpells(uint32 iDBSpellsID);
	bool			AI_AddNPCSpellsEffects(uint32 iDBSpellsEffectsID);
	virtual bool	AI_EngagedCastCheck();
	bool			AI_HasSpells() { return HasAISpell; }
	bool			AI_HasSpellsEffects() { return HasAISpellEffects; }
	void			ApplyAISpellEffects(StatBonuses* newbon);

	virtual bool	AI_PursueCastCheck();
	virtual bool	AI_IdleCastCheck();
	virtual void	AI_Event_SpellCastFinished(bool iCastSucceeded, uint16 slot);

	bool AICheckCloseBeneficialSpells(NPC* caster, uint8 chance, float cast_range, uint32 spell_types);
	void AIYellForHelp(Mob* sender, Mob* attacker);

	void LevelScale();

	virtual void SetTarget(Mob* mob);
	virtual uint16 GetSkill(EQ::skills::SkillType skill_num) const { if (skill_num <= EQ::skills::HIGHEST_SKILL) { return skills[skill_num]; } return 0; }

	virtual void CalcBonuses();
	virtual int GetCurrentBuffSlots() const { return RuleI(Spells, MaxBuffSlotsNPC); }
	virtual int GetCurrentSongSlots() const { return RuleI(Spells, MaxSongSlotsNPC); }
	virtual int GetCurrentDiscSlots() const { return RuleI(Spells, MaxDiscSlotsNPC); }
	virtual int GetMaxBuffSlots() const { return RuleI(Spells, MaxBuffSlotsNPC); }
	virtual int GetMaxSongSlots() const { return RuleI(Spells, MaxSongSlotsNPC); }
	virtual int GetMaxDiscSlots() const { return RuleI(Spells, MaxDiscSlotsNPC); }
	virtual int GetMaxTotalSlots() const { return RuleI(Spells, MaxTotalSlotsNPC); }
	virtual int GetPetMaxTotalSlots() const { return RuleI(Spells, MaxTotalSlotsPET); }
	virtual void InitializeBuffSlots();
	virtual void UninitializeBuffSlots();

	virtual void	SetAttackTimer();
	virtual void	RangedAttack(Mob* other);
	virtual void	ThrowingAttack(Mob* other) { }
	int32 GetNumberOfAttacks() const { return attack_count; }
	void DoRangedAttackDmg(Mob* other, bool Launch = true, int16 damage_mod = 0, int16 chance_mod = 0, EQ::skills::SkillType skill = EQ::skills::SkillArchery, float speed = 4.0f, const char *IDFile = nullptr);
	bool	IsFactionListAlly(uint32 other_faction);
	bool	IsGuard();
	FACTION_VALUE CheckNPCFactionAlly(int32 other_faction);
	virtual FACTION_VALUE GetReverseFactionCon(Mob* iOther);

	void	GoToBind(uint8 bind_number = 0)	{ GMMove(m_SpawnPoint.x, m_SpawnPoint.y, m_SpawnPoint.z, m_SpawnPoint.w); }
	void	Gate(uint8 bind_number = 0);

	void	GetPetState(SpellBuff_Struct *buffs, uint32 *items, char *name);
	void	SetPetState(SpellBuff_Struct *buffs, uint32 *items);
	virtual void SpellProcess();
	virtual void FillSpawnStruct(NewSpawn_Struct* ns, Mob* ForWho);

	// loot
	void AddItem(const EQ::ItemData *item, uint16 charges, bool equip_item = true);
	void AddItem(
		uint32 item_id,
		uint16 charges,
		bool equip_item = true,
		uint32 augment_one = 0,
		uint32 augment_two = 0,
		uint32 augment_three = 0,
		uint32 augment_four = 0,
		uint32 augment_five = 0,
		uint32 augment_six = 0
	);
	void AddLootTable();
	void AddLootTable(uint32 loottable_id, bool is_global = false);
	void AddLootDropTable(uint32 lootdrop_id, uint8 drop_limit, uint8 min_drop);
	void CheckGlobalLootTables();
	void RemoveItem(uint32 item_id, uint16 quantity = 0, uint16 slot = 0);
	void CheckTrivialMinMaxLevelDrop(Mob *killer);
	void ClearLootItems();
	inline const LootItems &GetLootItems() { return m_loot_items; }
	LootItem *GetItem(int slot_id);
	void AddLootCash(uint32 in_copper, uint32 in_silver, uint32 in_gold, uint32 in_platinum);
	void RemoveLootCash();
	void QueryLoot(Client *to, bool is_pet_query = false);
	bool HasItem(uint32 item_id);
	uint16 CountItem(uint32 item_id);
	uint32 GetLootItemIDBySlot(uint16 loot_slot);
	uint16 GetFirstLootSlotByItemID(uint32 item_id);
	std::vector<int> GetLootList();
	uint32 CountLoot();
	inline uint32 GetLoottableID() const { return m_loottable_id; }
	inline bool DropsGlobalLoot() const { return !m_skip_global_loot; }
	inline uint32 GetCopper() const { return m_loot_copper; }
	inline uint32 GetSilver() const { return m_loot_silver; }
	inline uint32 GetGold() const { return m_loot_gold; }
	inline uint32 GetPlatinum() const { return m_loot_platinum; }
	inline void SetCopper(uint32 amt) { m_loot_copper = amt; }
	inline void SetSilver(uint32 amt) { m_loot_silver = amt; }
	inline void SetGold(uint32 amt) { m_loot_gold = amt; }
	inline void SetPlatinum(uint32 amt) { m_loot_platinum = amt; }

	void DescribeAggro(Client *to_who, Mob *mob, bool verbose);
	virtual void UpdateEquipmentLight();
	virtual int64 CalcMaxMana();
	void SetGrid(int32 grid_){ grid=grid_; }
	void SetSpawnGroupId(uint32 sg2){ spawn_group_id =sg2; }
	void SetWaypointMax(uint16 wp_){ wp_m=wp_; }
	void SetSaveWaypoint(uint16 wp_){ save_wp=wp_; }

	uint16 GetWaypointMax() const { return wp_m; }
	int32 GetGrid() const { return grid; }
	uint32 GetSpawnGroupId() const { return spawn_group_id; }
	uint32 GetSpawnPointID() const;

	glm::vec4 const GetSpawnPoint() const { return m_SpawnPoint; }
	glm::vec4 const GetGuardPoint() const { return m_GuardPoint; }
	EmuAppearance GetGuardPointAnim() const { return guard_anim; }
	void SaveGuardPointAnim(EmuAppearance anim) { guard_anim = anim; }

	uint8 GetPrimSkill()	const { return prim_melee_type; }
	uint8 GetSecSkill()	const { return sec_melee_type; }
	uint8 GetRangedSkill() const { return ranged_type; }
	void SetPrimSkill(uint8 skill_type)	{ prim_melee_type = skill_type; }
	void SetSecSkill(uint8 skill_type)	{ sec_melee_type = skill_type; }
	void SetRangedSkill(uint8 skill_type)	{ ranged_type = skill_type; }

	uint32	MerchantType;
	bool	merchant_open;
	inline void	MerchantOpenShop() { merchant_open = true; }
	inline void	MerchantCloseShop() { merchant_open = false; }
	inline bool	IsMerchantOpen() { return merchant_open; }
	void	Depop(bool start_spawn_timer = false);
	void	Stun(int duration);
	void	UnStun();
	uint32	GetSwarmOwner();
	uint32	GetSwarmTarget();
	void	SetSwarmTarget(int target_id = 0);
	void	DepopSwarmPets();
	void	TryDepopTargetLockedPets(Mob* current_target);
	void	PetOnSpawn(NewSpawn_Struct* ns);

	void	SignalNPC(int _signal_id);
	void	SendPayload(int payload_id, std::string payload_value = std::string());

	inline int32 GetNPCFactionID() const
	{ return npc_faction_id; }

	inline int32 GetPrimaryFaction() const
	{ return primary_faction; }

	inline int32 GetFactionAmount() const
	{ return faction_amount; }

	int64 GetNPCHate(Mob *in_ent)
	{ return hate_list.GetEntHateAmount(in_ent); }

	bool IsOnHatelist(Mob *p)
	{ return hate_list.IsEntOnHateList(p); }

	void SetNPCFactionID(int32 in)
	{
		npc_faction_id = in;
		content_db.GetFactionIDsForNPC(npc_faction_id, &faction_list, &primary_faction);
	}

    glm::vec4 m_SpawnPoint;

	uint32	GetMaxDMG() const {return max_dmg;}
	uint32	GetMinDMG() const {return min_dmg;}
	int GetBaseDamage() const { return base_damage; }
	int GetMinDamage() const { return min_damage; }
	float GetSlowMitigation() const { return slow_mitigation; }
	float	GetAttackSpeed() const {return attack_speed;}
	int		GetAttackDelay() const {return attack_delay;}
	bool	IsAnimal() const { return(bodytype == BT_Animal); }
	uint16	GetPetSpellID() const {return pet_spell_id;}
	void	SetPetSpellID(uint16 amt) {pet_spell_id = amt;}
	uint32	GetMaxDamage(uint8 tlevel);
	void	SetTaunting(bool is_taunting);
	bool	IsTaunting() const { return taunting; }
	void	PickPocket(Client* thief);
	void	Disarm(Client* client, int chance);
	void	StartSwarmTimer(uint32 duration) { swarm_timer.Start(duration); }
	void	DisableSwarmTimer() { swarm_timer.Disable(); }

	void AddLootDrop(
		const EQ::ItemData *item2,
		LootdropEntriesRepository::LootdropEntries loot_drop,
		bool wear_change = false,
		uint32 augment_one = 0,
		uint32 augment_two = 0,
		uint32 augment_three = 0,
		uint32 augment_four = 0,
		uint32 augment_five = 0,
		uint32 augment_six = 0
	);

	bool MeetsLootDropLevelRequirements(LootdropEntriesRepository::LootdropEntries loot_drop, bool verbose=false);

	void CheckSignal();

	virtual void DoClassAttacks(Mob *target);
	inline bool IsNotTargetableWithHotkey() const { return no_target_hotkey; }
	int64 GetNPCHPRegen() const { return hp_regen + itembonuses.HPRegen + spellbonuses.HPRegen; }
	inline const char* GetAmmoIDfile() const { return ammo_idfile; }

	void ModifyStatsOnCharm(bool is_charm_removed);

	//waypoint crap
	int					GetMaxWp() const { return max_wp; }
	void				DisplayWaypointInfo(Client *client);
	void				CalculateNewWaypoint();
	void				AssignWaypoints(int32 grid_id, int start_wp = 0);
	void				SetWaypointPause();
	void				UpdateWaypoint(int wp_index);

	// quest wandering commands
	void				StopWandering();
	void				ResumeWandering();
	void				PauseWandering(int pausetime);
	void				MoveTo(const glm::vec4& position, bool saveguardspot);
	void				GetClosestWaypoints(std::list<wplist> &wp_list, int count, const glm::vec3& location);
	int					GetClosestWaypoint(const glm::vec3& location);

	uint32				GetEquippedItemFromTextureSlot(uint8 material_slot) const;	// returns item id
	uint32				GetEquipmentMaterial(uint8 material_slot) const;

	void				NextGuardPosition();
	void				SaveGuardSpot(bool ClearGuardSpot = false);
	void				SaveGuardSpot(const glm::vec4 &pos);
	inline bool			IsGuarding() const { return(m_GuardPoint.w != 0); }
	void				SaveGuardSpotCharm();

	void DescribeSpecialAbilities(Client* c);

	uint16 GetMeleeTexture1() const;
	uint16 GetMeleeTexture2() const;

	void RestoreGuardSpotCharm();

	void AI_SetRoambox(
		float max_distance,
		float roam_distance_variance,
		uint32 delay = 2500,
		uint32 min_delay = 2500
	);

	void				AI_SetRoambox(float distance, float max_x, float min_x, float max_y, float min_y, uint32 delay = 2500, uint32 min_delay = 2500);

	//mercenary stuff
	void	LoadMercenaryTypes();
	void	LoadMercenaries();
	std::list<MercType> GetMercenaryTypesList() {return mercTypeList; };
	std::list<MercType> GetMercenaryTypesList( uint32 expansion );
	std::list<MercData> GetMercenariesList() {return mercDataList; };
	std::list<MercData> GetMercenariesList( uint32 expansion );
	int		GetNumMercenaryTypes() { return static_cast<int>(mercTypeList.size()); };
	int		GetNumMercenaryTypes( uint32 expansion );
	int		GetNumberOfMercenaries() { return static_cast<int>(mercDataList.size()); };
	int		GetNumberOfMercenaries( uint32 expansion );

	inline bool GetNPCAggro() const { return npc_aggro; }
	inline void SetNPCAggro(bool in_npc_aggro) { npc_aggro = in_npc_aggro; }

	inline void GiveNPCTypeData(NPCType *ours) { NPCTypedata_ours = ours; }
	inline const uint32 GetNPCSpellsID()	const { return npc_spells_id; }
	inline const uint32 GetNPCSpellsEffectsID()	const { return npc_spells_effects_id; }

	float GetProximityMinX();
	float GetProximityMaxX();
	float GetProximityMinY();
	float GetProximityMaxY();
	float GetProximityMinZ();
	float GetProximityMaxZ();
	bool  IsProximitySet();

	NPCProximity* proximity;
	Spawn2*	respawn2;
	QGlobalCache *GetQGlobals() { return qGlobals; }
	QGlobalCache *CreateQGlobals() { qGlobals = new QGlobalCache(); return qGlobals; }

	SwarmPet *GetSwarmInfo() { return (swarmInfoPtr); }
	void SetSwarmInfo(SwarmPet *mSwarmInfo) { swarmInfoPtr = mSwarmInfo; }

	int32	GetAccuracyRating() const { return (accuracy_rating); }
	void	SetAccuracyRating(int32 d) { accuracy_rating = d;}
	int32	GetAvoidanceRating() const { return (avoidance_rating); }
	void	SetAvoidanceRating(int32 d) { avoidance_rating = d;}
	int32 GetRawAC() const { return AC; }

	float	GetNPCStat(const std::string& stat);
	void	ModifyNPCStat(const std::string& stat, const std::string& value);
	virtual void SetLevel(uint8 in_level, bool command = false);

	bool IsLDoNTrapped() const { return ldon_trapped; }
	void SetLDoNTrapped(bool n) { ldon_trapped = n; }

	uint8 GetLDoNTrapType() const { return ldon_trap_type; }
	void SetLDoNTrapType(uint8 n) { ldon_trap_type = n; }

	uint16 GetLDoNTrapSpellID() const { return ldon_spell_id; }
	void SetLDoNTrapSpellID(uint16 n) { ldon_spell_id = n; }

	bool IsLDoNLocked() const { return ldon_locked; }
	void SetLDoNLocked(bool n) { ldon_locked = n; }

	uint16 GetLDoNLockedSkill() const { return ldon_locked_skill; }
	void SetLDoNLockedSkill(uint16 n) { ldon_locked_skill = n; }

	bool IsLDoNTrapDetected() const { return ldon_trap_detected; }
	void SetLDoNTrapDetected(bool n) { ldon_trap_detected = n; }

	const bool GetCombatEvent() const { return combat_event; }
	void SetCombatEvent(bool b) { combat_event = b; }

	/* Only allows players that killed corpse to loot */
	const bool HasPrivateCorpse() const { return NPCTypedata_ours ? NPCTypedata_ours->private_corpse : NPCTypedata->private_corpse; }

	virtual const bool IsUnderwaterOnly() const { return m_is_underwater_only; }
	virtual const bool IsQuestNPC() const { return m_is_quest_npc; }
	const char* GetRawNPCTypeName() const { return NPCTypedata_ours ? NPCTypedata_ours->name : NPCTypedata->name; }

	virtual int GetKillExpMod() const { return NPCTypedata_ours ? NPCTypedata_ours->exp_mod : NPCTypedata->exp_mod; }

	void ChangeLastName(std::string last_name);
	void ClearLastName();

	bool GetDepop() { return p_depop; }

	void NPCSlotTexture(uint8 slot, uint32 texture);	// Sets new material values for slots

	uint32 GetAdventureTemplate() const { return adventure_template_id; }
	void AddSpellToNPCList(int16 iPriority, uint16 iSpellID, uint32 iType, int16 iManaCost, int32 iRecastDelay, int16 iResistAdjust, int8 min_hp, int8 max_hp);
	void AddSpellEffectToNPCList(uint16 iSpellEffectID, int32 base_value, int32 limit, int32 max_value, bool apply_bonus = false);
	void RemoveSpellFromNPCList(uint16 spell_id);
	void RemoveSpellEffectFromNPCList(uint16 iSpellEffectID, bool apply_bonus = false);
	bool HasAISpellEffect(uint16 spell_effect_id);
	Timer *GetRefaceTimer() const { return reface_timer; }
	const uint32 GetAltCurrencyType() const { return NPCTypedata->alt_currency_type; }

	NPC_Emote_Struct* GetNPCEmote(uint32 emote_id, uint8 event_);
	void DoNPCEmote(uint8 event_, uint32 emote_id, Mob* t = nullptr);
	bool CanTalk();
	void DoQuestPause(Mob *other);

	inline void SetSpellScale(float amt)		{ spellscale = amt; }
	inline float GetSpellScale()				{ return spellscale; }

	inline void SetHealScale(float amt)		{ healscale = amt; }
	inline float GetHealScale()					{ return healscale; }

	inline void SetSpellFocusDMG(int32 NewSpellFocusDMG) {SpellFocusDMG = NewSpellFocusDMG;}
	inline int32 GetSpellFocusDMG() const { return SpellFocusDMG;}

	inline void SetSpellFocusHeal(int32 NewSpellFocusHeal) {SpellFocusHeal = NewSpellFocusHeal;}
	inline int32 GetSpellFocusHeal() const {return SpellFocusHeal;}

	uint32	GetSpawnKillCount();
	int	GetScore();
	void	AISpellsList(Client *c);
	uint16 GetInnateProcSpellID() const { return innate_proc_spell_id; }

	uint32	GetHeroForgeModel() const { return herosforgemodel; }
	void	SetHeroForgeModel(uint32 model) { herosforgemodel = model; }

	bool IsRaidTarget() const { return raid_target; };
	bool IsRareSpawn() const { return rare_spawn; }
	void ResetHPUpdateTimer() { send_hp_update_timer.Start(); }

	bool IgnoreDespawn() { return ignore_despawn; }

	void SetSimpleRoamBox(float box_size, float move_distance = 0, int move_delay = 0);

	float GetRoamboxMaxX() const;
	float GetRoamboxMaxY() const;
	float GetRoamboxMinX() const;
	float GetRoamboxMinY() const;
	float GetRoamboxDistance() const;
	float GetRoamboxDestinationX() const;
	float GetRoamboxDestinationY() const;
	float GetRoamboxDestinationZ() const;
	uint32 GetRoamboxDelay() const;
	uint32 GetRoamboxMinDelay() const;

	inline uint8 GetArmTexture() { return armtexture; }
	inline uint8 GetBracerTexture() { return bracertexture; }
	inline uint8 GetHandTexture() { return handtexture; }
	inline uint8 GetFeetTexture() { return feettexture; }
	inline uint8 GetLegTexture() { return legtexture; }

	inline int GetCharmedAccuracy() { return charm_accuracy_rating; }
	inline int GetCharmedArmorClass() { return charm_ac; }
	inline int GetCharmedAttack() { return charm_atk; }
	inline int GetCharmedAttackDelay() { return charm_attack_delay; }
	inline int GetCharmedAvoidance() { return charm_avoidance_rating; }
	inline int GetCharmedMaxDamage() { return charm_max_dmg; }
	inline int GetCharmedMinDamage() { return charm_min_dmg; }

	inline bool GetAlwaysAggro() { return always_aggro; }
	inline bool GetNPCAggro() { return npc_aggro; }
	inline bool GetIgnoreDespawn() { return ignore_despawn; }
	inline bool GetSkipGlobalLoot() { return m_skip_global_loot; }

	std::unique_ptr<Timer> AIautocastspell_timer;

	virtual int GetStuckBehavior() const { return NPCTypedata_ours ? NPCTypedata_ours->stuck_behavior : NPCTypedata->stuck_behavior; }

	inline bool IsSkipAutoScale() const { return m_skip_auto_scale; }

	void ScaleNPC(uint8 npc_level, bool always_scale = false, bool override_special_abilities = false);

	void RecalculateSkills();
	void ReloadSpells();

	void SendPositionToClients();

	bool CanPathTo(float x, float y, float z);

protected:

	void HandleRoambox();

	const NPCType*	NPCTypedata;
	NPCType*	NPCTypedata_ours;	//special case for npcs with uniquely created data.

	friend class EntityList;
	friend class Aura;

	int32  grid;
	uint32 spawn_group_id;
	uint16 wp_m;

	// loot
	uint32    m_loot_copper;
	uint32    m_loot_silver;
	uint32    m_loot_gold;
	uint32    m_loot_platinum;
	LootItems m_loot_items;

	std::list<NpcFactionEntriesRepository::NpcFactionEntries> faction_list;

	int32	npc_faction_id;
	int32	primary_faction;
	int32	faction_amount;

	Timer	attacked_timer;		//running while we are being attacked (damaged)
	Timer	swarm_timer;
	Timer	monkattack_timer;	//additional timer for tiger claw usage
	Timer	classattack_timer;
	Timer	knightattack_timer;
	Timer	assist_timer;		//ask for help from nearby mobs
	Timer	qglobal_purge_timer;

	bool	combat_event;	//true if we are in combat, false otherwise
	Timer	send_hp_update_timer;
	Timer	enraged_timer;
	Timer *reface_timer;

	uint32	npc_spells_id;
	uint8	casting_spell_AIindex;

	std::vector<AISpells_Struct> AIspells;
	bool HasAISpell;
	virtual bool AICastSpell(Mob* tar, uint8 iChance, uint32 iSpellTypes, bool bInnates = false);
	virtual bool AIDoSpellCast(int32 i, Mob* tar, int32 mana_cost, uint32* oDontDoAgainBefore = 0);
	AISpellsVar_Struct AISpellVar;
	int64 GetFocusEffect(focusType type, uint16 spell_id, Mob *caster = nullptr, bool from_buff_tic = false) override;
	uint16 innate_proc_spell_id;

	uint32	npc_spells_effects_id;
	std::vector<AISpellsEffects_Struct> AIspellsEffects;
	bool HasAISpellEffects;

	uint32	max_dmg;
	uint32	min_dmg;
	int		base_damage;
	int		min_damage;
	int32	accuracy_rating;
	int32	avoidance_rating;
	int16	attack_count;
	uint64	npc_mana;
	float	spellscale;
	float	healscale;
	int32 SpellFocusDMG;
	int32 SpellFocusHeal;

	// stats to switch back to after charm wears off
	// could probably pick a better name, but these probably aren't taken so ...
	int default_ac;
	int default_min_dmg;
	int default_max_dmg;
	int default_attack_delay;
	int default_accuracy_rating;
	int default_avoidance_rating;
	int default_atk;
	char default_special_abilities[512];

	// when charmed, switch to these
	int charm_ac;
	int charm_min_dmg;
	int charm_max_dmg;
	int charm_attack_delay;
	int charm_accuracy_rating;
	int charm_avoidance_rating;
	int charm_atk;

	//pet crap:
	uint16	pet_spell_id;
	bool	taunting;
	Timer	taunt_timer;		//for pet taunting

	bool npc_aggro;

	std::deque<int> signal_q;

	//waypoint crap:
	std::vector<wplist> Waypoints;
	int max_wp;
	int save_wp;
	glm::vec4 m_GuardPoint;
	glm::vec4 m_GuardPointSaved;
	EmuAppearance guard_anim;

	Roambox m_roambox = {};

	uint16	skills[EQ::skills::HIGHEST_SKILL + 1];

	uint32	equipment[EQ::invslot::EQUIPMENT_COUNT];	//this is an array of item IDs

	uint32	herosforgemodel;			//this is the Hero Forge Armor Model (i.e 63 or 84 or 203)
	uint32	d_melee_texture1;
	//this is an item Material value
	uint32	d_melee_texture2;			//this is an item Material value (offhand)
	const char*	ammo_idfile;			//this determines projectile graphic "IT###" (see item field 'idfile')
	uint8	prim_melee_type;			//Sets the Primary Weapon attack message and animation
	uint8	sec_melee_type;				//Sets the Secondary Weapon attack message and animation
	uint8   ranged_type;				//Sets the Ranged Weapon attack message and animation

	SwarmPet *swarmInfoPtr;

	bool ldon_trapped;
	uint8 ldon_trap_type;
	uint16 ldon_spell_id;
	bool ldon_locked;
	uint16 ldon_locked_skill;
	bool ldon_trap_detected;
	QGlobalCache *qGlobals;
	uint32 adventure_template_id;

	bool m_is_underwater_only = false;
	bool m_is_quest_npc = false;

	//mercenary stuff
	std::list<MercType> mercTypeList;
	std::list<MercData> mercDataList;

	bool raid_target;
	bool ignore_despawn; //NPCs with this set to 1 will ignore the despawn value in spawngroup


private:
	uint32              m_loottable_id;
	bool                m_skip_global_loot;
	bool                m_skip_auto_scale;
	bool                p_depop;
	bool                m_record_loot_stats;
	std::vector<uint32> m_rolled_items = {};
};

#endif


/*	EQEMu: Everquest Server Emulator
Copyright (C) 2001-2003 EQEMu Development Team (http://eqemulator.net)

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY except by those people which sell it, which
are required to give you total support for your newly bought product;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include "mob.h"
#include "../common/types.h"
#include "../common/timer.h"

class Group;
class Raid;
struct ExtraAttackOptions;

class Encounter : public Mob
{
public:
	Encounter(const char* enc_name);
	~Encounter();

	//abstract virtual function implementations required by base abstract class
	virtual bool Death(Mob* killer_mob, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill, KilledByTypes killed_by = KilledByTypes::Killed_NPC) { return true; }
	virtual void Damage(Mob* from, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill, bool avoidable = true, int8 buffslot = -1, bool iBuffTic = false, eSpecialAttacks special = eSpecialAttacks::None) { return; }
	bool Attack(Mob* other, int Hand = EQ::invslot::slotPrimary, bool FromRiposte = false, bool IsStrikethrough = false,
		bool IsFromSpell = false, ExtraAttackOptions *opts = nullptr) override {
		return false;
	}
	virtual bool HasRaid() { return false; }
	virtual bool HasGroup() { return false; }
	virtual Raid* GetRaid() { return 0; }
	virtual Group* GetGroup() { return 0; }

	bool IsEncounter() const { return true; }
	const char* GetEncounterName() const { return encounter_name; }

	bool	Process();
	virtual void	Depop(bool not_used = true)	{ remove_me = true; }


protected:
	bool remove_me;
	char encounter_name[64];

private:
};

#endif

/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2002 EQEMu Development Team (http://eqemu.org)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef BEACON_H
#define BEACON_H

#include "mob.h"
#include "../common/types.h"
#include "../common/timer.h"

class Group;
class Raid;
struct ExtraAttackOptions;

class Beacon : public Mob
{
public:
	Beacon(const glm::vec4 &in_pos, int lifetime);
	~Beacon();

	//abstract virtual function implementations requird by base abstract class
	virtual bool Death(Mob* killer_mob, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill, KilledByTypes killed_by = KilledByTypes::Killed_NPC) { return true; }
	virtual void Damage(Mob* from, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill, bool avoidable = true, int8 buffslot = -1, bool iBuffTic = false, eSpecialAttacks special = eSpecialAttacks::None) { return; }
	virtual bool HasRaid() { return false; }
	virtual bool HasGroup() { return false; }
	virtual Raid* GetRaid() { return 0; }
	virtual Group* GetGroup() { return 0; }
	bool Attack(Mob* other, int Hand = EQ::invslot::slotPrimary, bool FromRiposte = false, bool IsStrikethrough = false, bool IsFromSpell = false,
		ExtraAttackOptions *opts = nullptr) override { return false; }

	bool	IsBeacon()			const { return true; }
	bool	Process();
	virtual void	Depop(bool not_used = true)	{ remove_me = true; }
	void AELocationSpell(Mob *caster, uint16 cast_spell_id, int16 in_resist_adjust);

protected:
	Timer remove_timer;
	bool remove_me;

	uint16 spell_id;
	int16 resist_adjust;
	int spell_iterations;
	Timer spell_timer;
	int max_targets;

	uint16 caster_id;
private:
};

#endif

/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2002 EQEMu Development Team (http://eqemu.org)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef ZONE_H
#define ZONE_H

#include "../common/eqtime.h"
#include "../common/linked_list.h"
#include "../common/rulesys.h"
#include "../common/types.h"
#include "../common/random.h"
#include "../common/strings.h"
#include "zonedb.h"
#include "../common/zone_store.h"
#include "../common/repositories/grid_repository.h"
#include "../common/repositories/grid_entries_repository.h"
#include "../common/repositories/zone_points_repository.h"
#include "qglobals.h"
#include "spawn2.h"
#include "spawngroup.h"
#include "aa_ability.h"
#include "pathfinder_interface.h"
#include "global_loot_manager.h"
#include "queryserv.h"
#include "../common/discord/discord.h"
#include "../common/repositories/dynamic_zone_templates_repository.h"
#include "../common/repositories/npc_faction_repository.h"
#include "../common/repositories/npc_faction_entries_repository.h"
#include "../common/repositories/faction_association_repository.h"
#include "../common/repositories/loottable_repository.h"
#include "../common/repositories/loottable_entries_repository.h"
#include "../common/repositories/lootdrop_repository.h"
#include "../common/repositories/lootdrop_entries_repository.h"
#include "../common/repositories/base_data_repository.h"

struct EXPModifier
{
	float aa_modifier;
	float exp_modifier;
};

class DynamicZone;

struct ZonePoint {
	float  x;
	float  y;
	float  z;
	float  heading;
	uint16 number;
	float  target_x;
	float  target_y;
	float  target_z;
	float  target_heading;
	uint16 target_zone_id;
	int32  target_zone_instance;
	uint32 client_version_mask;
	bool   is_virtual;
	int    height;
	int    width;
};

struct ZoneClientAuth_Struct {
	uint32 ip;            // client's IP address
	uint32 wid;        // client's WorldID#
	uint32 accid;
	int16  admin;
	uint32 charid;
	uint32 lsid;
	bool   tellsoff;
	char   charname[64];
	char   lskey[30];
	bool   stale;
};

struct ZoneEXPModInfo {
	float ExpMod;
	float AAExpMod;
};

class Client;
class Expedition;
class Map;
class Mob;
class WaterMap;
extern EntityList entity_list;
struct NPCType;
struct ServerZoneIncomingClient_Struct;
class MobMovementManager;

class Zone {
public:
	static bool Bootup(uint32 iZoneID, uint32 iInstanceID, bool is_static = false);
	static void Shutdown(bool quiet = false);

	Zone(uint32 in_zoneid, uint32 in_instanceid, const char *in_short_name);
	~Zone();

	AA::Ability *GetAlternateAdvancementAbility(int id);
	AA::Ability *GetAlternateAdvancementAbilityByRank(int rank_id);
	AA::Rank *GetAlternateAdvancementRank(int rank_id);
	bool is_zone_time_localized;
	bool quest_idle_override;
	bool IsIdleWhenEmpty() const;
	void SetIdleWhenEmpty(bool idle_when_empty);
	uint32 GetSecondsBeforeIdle() const;
	void SetSecondsBeforeIdle(uint32 seconds_before_idle);
	bool AggroLimitReached() { return (aggroedmobs > 10) ? true : false; }
	bool AllowMercs() const { return (allow_mercs); }
	bool CanBind() const { return (can_bind); }
	bool CanCastOutdoor() const { return (can_castoutdoor); } //qadar
	bool CanDoCombat() const { return (can_combat); }
	bool CanLevitate() const { return (can_levitate); } // Magoth78
	bool Depop(bool StartSpawnTimer = false);
	bool did_adventure_actions;
	bool GetAuth(
		uint32 iIP,
		const char *iCharName,
		uint32 *oWID = 0,
		uint32 *oAccID = 0,
		uint32 *oCharID = 0,
		int16 *oStatus = 0,
		char *oLSKey = 0,
		bool *oTellsOff = 0
	);
	bool HasGraveyard();
	bool HasWeather();
	bool Init(bool is_static);
	bool IsCity() const { return (is_city); }
	bool IsHotzone() const { return (is_hotzone); }
	bool IsLoaded();
	bool IsPVPZone() { return pvpzone; }
	bool IsSpellBlocked(uint32 spell_id, const glm::vec3 &location);
	bool IsUCSServerAvailable() { return m_ucss_available; }
	bool IsZone(uint32 zone_id, uint16 instance_id) const;
	bool LoadGroundSpawns();
	bool LoadZoneCFG(const char *filename, uint16 instance_version);
	bool LoadZoneObjects();
	bool IsSpecialBindLocation(const glm::vec4& location);
	bool Process();
	bool SaveZoneCFG();

	int GetNpcPositionUpdateDistance() const;
	void SetNpcPositionUpdateDistance(int in_npc_position_update_distance);

	char *adv_data;

	const char *GetSpellBlockedMessage(uint32 spell_id, const glm::vec3 &location);

	EQ::Random random;
	EQTime     zone_time;

	ZonePoint *
	GetClosestZonePoint(const glm::vec3 &location, const char *to_name, Client *client, float max_distance = 40000.0f);

	inline bool BuffTimersSuspended() const { return newzone_data.suspend_buffs != 0; };
	inline bool HasMap() { return zonemap != nullptr; }
	inline bool HasWaterMap() { return watermap != nullptr; }
	inline bool InstantGrids() { return (!initgrids_timer.Enabled()); }
	inline bool IsStaticZone() { return staticzone; }
	inline const bool IsInstancePersistent() const { return pers_instance; }
	inline const char *GetFileName() { return file_name; }
	inline const char *GetLongName() { return long_name; }
	inline const char *GetShortName() { return short_name; }
	inline const uint8 GetZoneType() const { return zone_type; }
	inline const uint16 GetInstanceVersion() const { return instanceversion; }
	inline const uint32 &GetMaxClients() { return m_max_clients; }
	inline const uint32 &graveyard_id() { return m_graveyard_id; }
	inline const uint32 &graveyard_zoneid() { return pgraveyard_zoneid; }
	inline const uint32 GetInstanceID() const { return instanceid; }
	inline const uint32 GetZoneID() const { return zoneid; }
	inline glm::vec4 GetSafePoint() { return m_safe_points; }
	inline glm::vec4 GetGraveyardPoint() { return m_graveyard; }
	inline std::vector<int> GetGlobalLootTables(NPC *mob) const { return m_global_loot.GetGlobalLootTables(mob); }
	inline Timer *GetInstanceTimer() { return Instance_Timer; }
	inline void AddGlobalLootEntry(GlobalLootEntry &in) { return m_global_loot.AddEntry(in); }
	inline void SetZoneHasCurrentTime(bool time) { zone_has_current_time = time; }
	inline void ShowNPCGlobalLoot(Client *c, NPC *t) { m_global_loot.ShowNPCGlobalLoot(c, t); }
	inline void ShowZoneGlobalLoot(Client *c) { m_global_loot.ShowZoneGlobalLoot(c); }
	int GetZoneTotalBlockedSpells() { return zone_total_blocked_spells; }
	int SaveTempItem(uint32 merchantid, uint32 npcid, uint32 item, int32 charges, bool sold = false);
	int32 MobsAggroCount() { return aggroedmobs; }
	DynamicZone *GetDynamicZone();

	IPathfinder                                   *pathing;
	std::vector<NPC_Emote_Struct *>               npc_emote_list;
	LinkedList<Spawn2 *>                          spawn2_list;
	LinkedList<ZonePoint *>                       zone_point_list;
	std::vector<ZonePointsRepository::ZonePoints> virtual_zone_point_list;

	Map                   *zonemap;
	MercTemplate *GetMercTemplate(uint32 template_id);
	NewZone_Struct        newzone_data;
	QGlobalCache *CreateQGlobals()
	{
		qGlobals = new QGlobalCache();
		return qGlobals;
	}
	QGlobalCache *GetQGlobals() { return qGlobals; }
	SpawnConditionManager spawn_conditions;
	SpawnGroupList        spawn_group_list;

	std::list<AltCurrencyDefinition_Struct>          AlternateCurrencies;
	std::list<InternalVeteranReward>                 VeteranRewards;
	std::map<uint32, LDoNTrapTemplate *>             ldon_trap_list;
	std::map<uint32, MercTemplate>                   merc_templates;
	std::map<uint32, NPCType *>                      merctable;
	std::map<uint32, NPCType *>                      npctable;
	std::map<uint32, std::list<LDoNTrapTemplate *> > ldon_trap_entry_list;
	std::map<uint32, std::list<MerchantList> >       merchanttable;
	std::map<uint32, std::list<MercSpellEntry> >     merc_spells_list;
	std::map<uint32, std::list<MercStanceInfo> >     merc_stance_list;
	std::map<uint32, std::list<TempMerchantList> >   tmpmerchanttable;
	std::map<uint32, std::string>                    adventure_entry_list_flavor;
	std::map<uint32, ZoneEXPModInfo>                 level_exp_mod;

	std::pair<AA::Ability *, AA::Rank *> GetAlternateAdvancementAbilityAndRank(int id, int points_spent);

	std::unordered_map<int, std::unique_ptr<AA::Ability>> aa_abilities;
	std::unordered_map<int, std::unique_ptr<AA::Rank>>    aa_ranks;

	std::vector<GridRepository::Grid>               zone_grids;
	std::vector<GridEntriesRepository::GridEntries> zone_grid_entries;

	std::unordered_map<uint32, std::unique_ptr<DynamicZone>> dynamic_zone_cache;
	std::unordered_map<uint32, std::unique_ptr<Expedition>>  expedition_cache;
	std::unordered_map<uint32, DynamicZoneTemplatesRepository::DynamicZoneTemplates> dz_template_cache;

	std::unordered_map<uint32, EXPModifier> exp_modifiers;

	time_t weather_timer;
	Timer  spawn2_timer;
	Timer  hot_reload_timer;

	uint8  weather_intensity;
	uint8  zone_weather;
	uint8  loglevelvar;
	uint8  lootvar;
	uint8  merchantvar;
	uint8  tradevar;
	uint32 numzonepoints;
	uint32 CountAuth();
	uint32 CountSpawn2();
	uint32 GetSpawnKillCount(uint32 in_spawnid);
	uint32 GetTempMerchantQuantity(uint32 NPCID, uint32 Slot);

	uint32 GetCurrencyID(uint32 item_id);
	uint32 GetCurrencyItemID(uint32 currency_id);

	std::string GetAAName(int aa_id);

	inline bool IsRaining() { return zone_weather == EQ::constants::WeatherTypes::Raining; }
	inline bool IsSnowing() { return zone_weather == EQ::constants::WeatherTypes::Snowing; }

	std::string GetZoneDescription();
	void SendReloadMessage(std::string reload_type);

	void ClearEXPModifier(Client* c);
	float GetAAEXPModifier(Client* c);
	float GetEXPModifier(Client* c);
	void SetAAEXPModifier(Client* c, float aa_modifier);
	void SetEXPModifier(Client* c, float exp_modifier);

	void AddAggroMob() { aggroedmobs++; }
	void AddAuth(ServerZoneIncomingClient_Struct *szic);
	void ChangeWeather();
	void ClearBlockedSpells();
	void ClearNPCTypeCache(int id);
	void CalculateNpcUpdateDistanceSpread();
	void DelAggroMob() { aggroedmobs--; }
	void DeleteQGlobal(std::string name, uint32 npcID, uint32 charID, uint32 zoneID);
	void Despawn(uint32 spawngroupID);
	void DoAdventureActions();
	void DoAdventureAssassinationCountIncrease();
	void DoAdventureCountIncrease();
	void LoadMerchants();
	void GetTimeSync();
	void LoadAdventureFlavor();
	void LoadAlternateAdvancement();
	void LoadAlternateCurrencies();
	void LoadDynamicZoneTemplates();
	void LoadZoneBlockedSpells();
	void LoadLDoNTrapEntries();
	void LoadLDoNTraps();
	void LoadLevelEXPMods();
	void LoadGrids();
	void LoadMercenarySpells();
	void LoadMercenaryTemplates();
	void LoadNewMerchantData(uint32 merchantid);
	void LoadNPCEmotes(std::vector<NPC_Emote_Struct*>* v);
	void LoadTempMerchantData();
	void LoadVeteranRewards();
	void LoadZoneDoors();
	void ReloadStaticData();
	void ReloadWorld(uint8 global_repop);
	void RemoveAuth(const char *iCharName, const char *iLSKey);
	void RemoveAuth(uint32 lsid);
	void Repop(bool is_forced = false);
	void RequestUCSServerStatus();
	void ResetAuth();
	void SetDate(uint16 year, uint8 month, uint8 day, uint8 hour, uint8 minute);
	void SetInstanceTimer(uint32 new_duration);
	void SetStaticZone(bool sz) { staticzone = sz; }
	void SetTime(uint8 hour, uint8 minute, bool update_world = true);
	void SetUCSServerAvailable(bool ucss_available, uint32 update_timestamp);
	void SpawnConditionChanged(const SpawnCondition &c, int16 old_value);
	void StartShutdownTimer(uint32 set_time = (RuleI(Zone, AutoShutdownDelay)));
	void ResetShutdownTimer();
	void StopShutdownTimer();
	void UpdateQGlobal(uint32 qid, QGlobal newGlobal);
	void weatherSend(Client *client = nullptr);
	void ClearSpawnTimers();

	bool IsQuestHotReloadQueued() const;
	void SetQuestHotReloadQueued(bool in_quest_hot_reload_queued);

	bool CompareDataBucket(uint8 bucket_comparison, const std::string& bucket_value, const std::string& player_value);

	WaterMap *watermap;
	ZonePoint *GetClosestZonePoint(const glm::vec3 &location, uint32 to, Client *client, float max_distance = 40000.0f);
	ZonePoint *GetClosestZonePointWithoutZone(float x, float y, float z, Client *client, float max_distance = 40000.0f);

	Timer GetInitgridsTimer();
	uint32 GetInstanceTimeRemaining() const;
	void SetInstanceTimeRemaining(uint32 instance_time_remaining);

	/**
	 * GMSay Callback for LogSys
	 *
	 * @param log_category
	 * @param message
	 */
	static void GMSayHookCallBackProcess(uint16 log_category, const char *func, std::string message)
	{
		// we don't want to loop up with chat messages
		if (message.find("OP_SpecialMesg") != std::string::npos) {
			return;
		}

		/**
		 * Cut messages down to 4000 max to prevent client crash
		 */
		if (!message.empty()) {
			message = message.substr(0, 4000);
		}

		/**
		 * Replace Occurrences of % or MessageStatus will crash
		 */
		Strings::FindReplace(message, std::string("%"), std::string("."));

		if (message.find('\n') != std::string::npos) {
			auto message_split = Strings::Split(message, '\n');
			entity_list.MessageStatus(
				0,
				AccountStatus::QuestTroupe,
				LogSys.GetGMSayColorFromCategory(log_category),
				message_split[0].c_str()
			);

			for (size_t iter = 1; iter < message_split.size(); ++iter) {
				entity_list.MessageStatus(
					0,
					AccountStatus::QuestTroupe,
					LogSys.GetGMSayColorFromCategory(log_category),
					fmt::format(
						"--- {}",
						message_split[iter]
					).c_str()
				);
			}
		}
		else {
			entity_list.MessageStatus(
				0,
				AccountStatus::QuestTroupe,
				LogSys.GetGMSayColorFromCategory(log_category),
				fmt::format("[{}] [{}] {}", Logs::LogCategoryName[log_category], func, message).c_str()
			);
		}
	}

	static void SendDiscordMessage(int webhook_id, const std::string& message);
	static void SendDiscordMessage(const std::string& webhook_name, const std::string& message);
	static void DiscordWebhookMessageHandler(uint16 log_category, int webhook_id, const std::string &message)
	{
		std::string message_prefix;
		if (!LogSys.origination_info.zone_short_name.empty()) {
			message_prefix = fmt::format(
				"[**{}**] **Zone** [**{}**] ",
				Logs::LogCategoryName[log_category],
				LogSys.origination_info.zone_short_name
			);
		}

		SendDiscordMessage(webhook_id, message_prefix + Discord::FormatDiscordMessage(log_category, message));
	};

	double GetMaxMovementUpdateRange() const { return max_movement_update_range; }

	void SetIsHotzone(bool is_hotzone);

	void ReloadContentFlags();

	void LoadNPCFaction(const uint32 npc_faction_id);
	void LoadNPCFactions(const std::vector<uint32>& npc_faction_ids);
	void ClearNPCFactions();
	void ReloadNPCFactions();
	NpcFactionRepository::NpcFaction* GetNPCFaction(const uint32 npc_faction_id);
	std::vector<NpcFactionEntriesRepository::NpcFactionEntries> GetNPCFactionEntries(const uint32 npc_faction_id) const;

	void LoadNPCFactionAssociation(const uint32 npc_faction_id);
	void LoadNPCFactionAssociations(const std::vector<uint32>& npc_faction_ids);
	void LoadFactionAssociation(const uint32 faction_id);
	void LoadFactionAssociations(const std::vector<uint32>& faction_ids);
	void ClearFactionAssociations();
	void ReloadFactionAssociations();
	FactionAssociationRepository::FactionAssociation* GetFactionAssociation(const uint32 faction_id);

	// loot
	void LoadLootTable(const uint32 loottable_id);
	void LoadLootTables(const std::vector<uint32>& loottable_ids);
	void ClearLootTables();
	void ReloadLootTables();
	LoottableRepository::Loottable *GetLootTable(const uint32 loottable_id);
	std::vector<LoottableEntriesRepository::LoottableEntries> GetLootTableEntries(const uint32 loottable_id) const;
	LootdropRepository::Lootdrop GetLootdrop(const uint32 lootdrop_id) const;
	std::vector<LootdropEntriesRepository::LootdropEntries> GetLootdropEntries(const uint32 lootdrop_id) const;

	// Base Data
	inline void ClearBaseData() { m_base_data.clear(); };
	BaseDataRepository::BaseData GetBaseData(uint8 level, uint8 class_id);
	void LoadBaseData();
	void ReloadBaseData();

private:
	bool      allow_mercs;
	bool      can_bind;
	bool      can_castoutdoor;
	bool      can_combat;
	bool      can_levitate;
	bool      is_city;
	bool      is_hotzone;
	bool      pers_instance;
	bool      pvpzone;
	bool      m_ucss_available;
	bool      staticzone;
	bool      zone_has_current_time;
	bool      quest_hot_reload_queued;
	double    max_movement_update_range;
	char      *long_name;
	char      *map_name;
	char      *short_name;
	char      file_name[32];
	glm::vec4 m_safe_points;
	glm::vec4 m_graveyard;
	int       default_ruleset;
	int       zone_total_blocked_spells;
	int       npc_position_update_distance;
	int32     aggroedmobs;
	uint8     zone_type;
	uint16    instanceversion;
	uint32    instanceid;
	uint32    instance_time_remaining;
	uint32    m_graveyard_id, pgraveyard_zoneid;
	uint32    m_max_clients;
	uint32    zoneid;
	uint32    m_last_ucss_update;
	bool      m_idle_when_empty;
	uint32    m_seconds_before_idle;

	GlobalLootManager                   m_global_loot;
	LinkedList<ZoneClientAuth_Struct *> client_auth_list;
	MobMovementManager                  *mMovementManager;
	QGlobalCache                        *qGlobals;
	Timer                               *Instance_Shutdown_Timer;
	Timer                               *Instance_Timer;
	Timer                               *Instance_Warning_timer;
	Timer                               *Weather_Timer;
	Timer                               autoshutdown_timer;
	Timer                               clientauth_timer;
	Timer                               initgrids_timer;
	Timer                               qglobal_purge_timer;
	ZoneSpellsBlocked                   *blocked_spells;

	// Factions
	std::vector<NpcFactionRepository::NpcFaction>                 m_npc_factions         = { };
	std::vector<NpcFactionEntriesRepository::NpcFactionEntries>   m_npc_faction_entries  = { };
	std::vector<FactionAssociationRepository::FactionAssociation> m_faction_associations = { };

	// loot
	std::vector<LoottableRepository::Loottable>               m_loottables        = {};
	std::vector<LoottableEntriesRepository::LoottableEntries> m_loottable_entries = {};
	std::vector<LootdropRepository::Lootdrop>                 m_lootdrops         = {};
	std::vector<LootdropEntriesRepository::LootdropEntries>   m_lootdrop_entries  = {};

	// Base Data
	std::vector<BaseDataRepository::BaseData> m_base_data = { };
};

#endif

/* EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2003 EQEMu Development Team (http://eqemulator.org)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef CLIENT_H
#define CLIENT_H

class Client;
class EQApplicationPacket;
class DynamicZone;
class Expedition;
class ExpeditionLockoutTimer;
class ExpeditionRequest;
class Group;
class NPC;
class Object;
class Raid;
class Seperator;
class ServerPacket;
struct DynamicZoneLocation;
enum WaterRegionType : int;

namespace EQ
{
	struct ItemData;
}

#include "../common/timer.h"
#include "../common/ptimer.h"
#include "../common/emu_opcodes.h"
#include "../common/eq_packet_structs.h"
#include "../common/emu_constants.h"
#include "../common/eq_stream_intf.h"
#include "../common/eq_packet.h"
#include "../common/linked_list.h"
#include "../common/extprofile.h"
#include "../common/races.h"
#include "../common/seperator.h"
#include "../common/inventory_profile.h"
#include "../common/guilds.h"
//#include "../common/item_data.h"
#include "xtargetautohaters.h"
#include "aggromanager.h"

#include "common.h"
#include "merc.h"
#include "mob.h"
#include "qglobals.h"
#include "questmgr.h"
#include "zone.h"
#include "zonedb.h"
#include "../common/zone_store.h"
#include "task_manager.h"
#include "task_client_state.h"
#include "cheat_manager.h"
#include "../common/events/player_events.h"
#include "../common/data_verification.h"

#ifdef _WINDOWS
	// since windows defines these within windef.h (which windows.h include)
	// we are required to undefine these to use min and max from <algorithm>
	#undef min
	#undef max
#endif

#include <float.h>
#include <set>
#include <algorithm>
#include <memory>
#include <deque>
#include <ctime>


#define CLIENT_LD_TIMEOUT 30000 // length of time client stays in zone after LDing
#define TARGETING_RANGE 200 // range for /assist and /target
#define XTARGET_HARDCAP 20
#define MAX_SPECIALIZED_SKILL 50

extern Zone* zone;
extern TaskManager *task_manager;

class CLIENTPACKET
{
public:
	CLIENTPACKET();
	~CLIENTPACKET();
	EQApplicationPacket *app;
	bool ack_req;
};

#define SPELLBAR_UNLOCK 0x2bc
enum { //scribing argument to MemorizeSpell
	memSpellUnknown = -1, // this modifies some state data
	memSpellScribing = 0,
	memSpellMemorize = 1,
	memSpellForget = 2,
	memSpellSpellbar = 3
};

//Modes for the zoning state of the client.
typedef enum {
	ZoneToSafeCoords,	// Always send ZonePlayerToBind_Struct to client: Succor/Evac
	GMSummon,			// Always send ZonePlayerToBind_Struct to client: Only a GM Summon
	GMHiddenSummon,		// Always send ZonePlayerToBind_Struct to client silently: Only a GM Summon
	ZoneToBindPoint,	// Always send ZonePlayerToBind_Struct to client: Death Only
	ZoneSolicited,		// Always send ZonePlayerToBind_Struct to client: Portal, Translocate, Evac spells that have a x y z coord in the spell data
	ZoneUnsolicited,
	GateToBindPoint,	// Always send RequestClientZoneChange_Struct to client: Gate spell or Translocate To Bind Point spell
	SummonPC,			// In-zone GMMove() always: Call of the Hero spell or some other type of in zone only summons
	Rewind,				// Summon to /rewind location.
	EvacToSafeCoords
} ZoneMode;

// translate above enum to a string
std::string GetZoneModeString(ZoneMode mode);

enum {
	HideCorpseNone = 0,
	HideCorpseAll = 1,
	HideCorpseAllButGroup = 2,
	HideCorpseLooted = 3,
	HideCorpseNPC = 5
};

typedef enum
{
	Disciplines,
	Spells
} ShowSpellType;

typedef enum
{
	Empty = 0,
	Auto = 1,
	CurrentTargetPC = 2,
	CurrentTargetNPC = 3,
	TargetsTarget = 4,
	GroupTank = 5,
	GroupTankTarget = 6,
	GroupAssist = 7,
	GroupAssistTarget = 8,
	Puller = 9,
	PullerTarget = 10,
	GroupMarkTarget1 = 11,
	GroupMarkTarget2 = 12,
	GroupMarkTarget3 = 13,
	RaidAssist1 = 14,
	RaidAssist2 = 15,
	RaidAssist3 = 16,
	RaidAssist1Target = 17,
	RaidAssist2Target = 18,
	RaidAssist3Target = 19,
	RaidMarkTarget1 = 20,
	RaidMarkTarget2 = 21,
	RaidMarkTarget3 = 22,
	MyPet = 23,
	MyPetTarget = 24,
	MyMercenary = 25,
	MyMercenaryTarget = 26

} XTargetType;

struct XTarget_Struct
{
	XTargetType Type;
	bool dirty;
	uint16 ID;
	char Name[65];
};

struct RespawnOption
{
	std::string name;
	uint32 zone_id;
	uint16 instance_id;
	float x;
	float y;
	float z;
	float heading;
};

// do not ask what all these mean because I have no idea!
// named from the client's CEverQuest::GetInnateDesc, they're missing some
enum eInnateSkill {
	InnateEnabled = 0,
	InnateAwareness = 1,
	InnateBashDoor = 2,
	InnateBreathFire = 3,
	InnateHarmony = 4,
	InnateInfravision = 6,
	InnateLore = 8,
	InnateNoBash = 9,
	InnateRegen = 10,
	InnateSlam = 11,
	InnateSurprise = 12,
	InnateUltraVision = 13,
	InnateInspect = 14,
	InnateOpen = 15,
	InnateReveal = 16,
	InnateSkillMax = 25, // size of array in client
	InnateDisabled = 255
};

inline const std::string DIAWIND_RESPONSE_ONE_KEY       = "diawind_npc_response_one";
inline const std::string DIAWIND_RESPONSE_TWO_KEY       = "diawind_npc_response_two";
const uint32      POPUPID_DIAWIND_ONE            = 99999;
const uint32      POPUPID_DIAWIND_TWO            = 100000;
const uint32      POPUPID_UPDATE_SHOWSTATSWINDOW = 1000000;
const uint32      POPUPID_REPLACE_SPELLWINDOW    = 1000001;

struct ClientReward
{
	uint32 id;
	uint32 amount;
};

class Client : public Mob
{
public:
	//pull in opcode mappings:
	#include "client_packet.h"

	Client(EQStreamInterface * ieqs);
	~Client();

	void ReconnectUCS();
	void RecordStats();

	void SetDisplayMobInfoWindow(bool display_mob_info_window);
	bool GetDisplayMobInfoWindow() const;

	bool IsDevToolsEnabled() const;
	void SetDevToolsEnabled(bool in_dev_tools_enabled);

	bool IsEXPEnabled() const;
	void SetEXPEnabled(bool is_exp_enabled);

	std::vector<EXPModifier> GetEXPModifiers();
	void SetEXPModifiers(std::vector<EXPModifier> exp_modifiers);

	void SetPrimaryWeaponOrnamentation(uint32 model_id);
	void SetSecondaryWeaponOrnamentation(uint32 model_id);

	void SendChatLineBreak(uint16 color = Chat::White);

	bool GotoPlayer(std::string player_name);
	bool GotoPlayerGroup(const std::string& player_name);
	bool GotoPlayerRaid(const std::string& player_name);

	//abstract virtual function implementations required by base abstract class
	virtual bool Death(Mob* killer_mob, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill, KilledByTypes killed_by = KilledByTypes::Killed_NPC);
	virtual void Damage(Mob* from, int64 damage, uint16 spell_id, EQ::skills::SkillType attack_skill, bool avoidable = true, int8 buffslot = -1, bool iBuffTic = false, eSpecialAttacks special = eSpecialAttacks::None);
	virtual bool HasRaid() { return (GetRaid() ? true : false); }
	virtual bool HasGroup() { return (GetGroup() ? true : false); }
	virtual Raid* GetRaid() { return entity_list.GetRaidByClient(this); }
	virtual Group* GetGroup() { return entity_list.GetGroupByClient(this); }
	virtual inline bool IsBerserk() { return berserk; }
	virtual void SetAttackTimer();
	int GetQuiverHaste(int delay);
	void DoAttackRounds(Mob *target, int hand, bool IsFromSpell = false);

	void AI_Init();
	void AI_Start(uint32 iMoveDelay = 0);
	void AI_Stop();
	void AI_Process();
	void AI_SpellCast();
	void Trader_ShowItems();
	void Trader_CustomerBrowsing(Client *Customer);
	void Trader_EndTrader();
	void Trader_StartTrader();
	uint8 WithCustomer(uint16 NewCustomer);
	void KeyRingLoad();
	void KeyRingAdd(uint32 item_id);
	bool KeyRingCheck(uint32 item_id);
	void KeyRingList();
	bool IsClient() const override { return true; }
	bool IsOfClientBot() const override { return true; }
	bool IsOfClientBotMerc() const override { return true; }
	void CompleteConnect();
	bool TryStacking(EQ::ItemInstance* item, uint8 type = ItemPacketTrade, bool try_worn = true, bool try_cursor = true);
	void SendTraderPacket(Client* trader, uint32 Unknown72 = 51);
	void SendBuyerPacket(Client* Buyer);
	GetItems_Struct* GetTraderItems();
	void SendBazaarWelcome();
	void DyeArmor(EQ::TintProfile* dye);
	void DyeArmorBySlot(uint8 slot, uint8 red, uint8 green, uint8 blue, uint8 use_tint = 0x00);
	uint8 SlotConvert(uint8 slot,bool bracer=false);
	void MessageString(uint32 type, uint32 string_id, uint32 distance = 0);
	void MessageString(uint32 type, uint32 string_id, const char* message,const char* message2=0,const char* message3=0,const char* message4=0,const char* message5=0,const char* message6=0,const char* message7=0,const char* message8=0,const char* message9=0, uint32 distance = 0);
	void MessageString(const CZClientMessageString_Struct* msg);
	bool FilteredMessageCheck(Mob *sender, eqFilterType filter);
	void FilteredMessageString(Mob *sender, uint32 type, eqFilterType filter, uint32 string_id);
	void FilteredMessageString(Mob *sender, uint32 type, eqFilterType filter,
					uint32 string_id, const char *message1, const char *message2 = nullptr,
					const char *message3 = nullptr, const char *message4 = nullptr,
					const char *message5 = nullptr, const char *message6 = nullptr,
					const char *message7 = nullptr, const char *message8 = nullptr,
					const char *message9 = nullptr);
	void Tell_StringID(uint32 string_id, const char *who, const char *message);
	void SendColoredText(uint32 color, std::string message);
	void SendBazaarResults(uint32 trader_id, uint32 in_class, uint32 in_race, uint32 item_stat, uint32 item_slot, uint32 item_type, char item_name[64], uint32 min_price, uint32 max_price);
	void SendTraderItem(uint32 item_id,uint16 quantity);
	uint16 FindTraderItem(int32 SerialNumber,uint16 Quantity);
	uint32 FindTraderItemSerialNumber(int32 ItemID);
	EQ::ItemInstance* FindTraderItemBySerialNumber(int32 SerialNumber);
	void FindAndNukeTraderItem(int32 item_id,int16 quantity,Client* customer,uint16 traderslot);
	void NukeTraderItem(uint16 slot, int16 charges, int16 quantity, Client* customer, uint16 traderslot, int32 uniqueid, int32 itemid = 0);
	void ReturnTraderReq(const EQApplicationPacket* app,int16 traderitemcharges, uint32 itemid = 0);
	void TradeRequestFailed(const EQApplicationPacket* app);
	void BuyTraderItem(TraderBuy_Struct* tbs,Client* trader,const EQApplicationPacket* app);
	void FinishTrade(Mob* with, bool finalizer = false, void* event_entry = nullptr, std::list<void*>* event_details = nullptr);
	void SendZonePoints();

	void SendBuyerResults(char *SearchQuery, uint32 SearchID);
	void ShowBuyLines(const EQApplicationPacket *app);
	void SellToBuyer(const EQApplicationPacket *app);
	void ToggleBuyerMode(bool TurnOn);
	void UpdateBuyLine(const EQApplicationPacket *app);
	void BuyerItemSearch(const EQApplicationPacket *app);
	void SetBuyerWelcomeMessage(const char* WelcomeMessage) { BuyerWelcomeMessage = WelcomeMessage; }
	const char* GetBuyerWelcomeMessage() { return BuyerWelcomeMessage.c_str(); }

	void FillSpawnStruct(NewSpawn_Struct* ns, Mob* ForWho);
	bool ShouldISpawnFor(Client *c) { return !GMHideMe(c) && !IsHoveringForRespawn(); }
	virtual bool Process();
	void QueuePacket(const EQApplicationPacket* app, bool ack_req = true, CLIENT_CONN_STATUS = CLIENT_CONNECTINGALL, eqFilterType filter=FilterNone);
	void FastQueuePacket(EQApplicationPacket** app, bool ack_req = true, CLIENT_CONN_STATUS = CLIENT_CONNECTINGALL);
	void ChannelMessageReceived(uint8 chan_num, uint8 language, uint8 lang_skill, const char* orig_message, const char* targetname = nullptr, bool is_silent = false);
	void ChannelMessageSend(const char* from, const char* to, uint8 channel_id, uint8 language_id, uint8 language_skill, const char* message, ...);
	void Message(uint32 type, const char* message, ...);
	void FilteredMessage(Mob *sender, uint32 type, eqFilterType filter, const char* message, ...);
	void VoiceMacroReceived(uint32 Type, char *Target, uint32 MacroNumber);
	void SendSound();
	void LearnRecipe(uint32 recipe_id);
	int GetRecipeMadeCount(uint32 recipe_id);
	bool HasRecipeLearned(uint32 recipe_id);
	bool CanIncreaseTradeskill(EQ::skills::SkillType tradeskill);

	bool GetRevoked() const { return revoked; }
	void SetRevoked(bool rev) { revoked = rev; }
	inline uint32 GetIP() const { return ip; }
	std::string GetIPString();
	int GetIPExemption();
	void SetIPExemption(int exemption_amount);
	inline bool GetHideMe() const { return gm_hide_me; }
	void SetHideMe(bool flag);
	inline uint16 GetPort() const { return port; }
	bool IsDead() const { return(dead); }
	bool IsUnconscious() const { return ((current_hp <= 0) ? true : false); }
	inline bool IsLFP() { return LFP; }
	void UpdateLFP();

	virtual bool Save() { return Save(0); }
	bool Save(uint8 iCommitNow); // 0 = delayed, 1=async now, 2=sync now

	/* New PP Save Functions */
	bool SaveCurrency(){ return database.SaveCharacterCurrency(this->CharacterID(), &m_pp); }
	bool SaveAA();
	void RemoveExpendedAA(int aa_id);

	inline bool ClientDataLoaded() const { return client_data_loaded; }
	inline bool Connected() const { return (client_state == CLIENT_CONNECTED); }
	inline bool InZone() const { return (client_state == CLIENT_CONNECTED || client_state == CLIENT_LINKDEAD); }
	inline void Disconnect() { eqs->Close(); client_state = DISCONNECTED; }
	inline bool IsLD() const { return (bool) (client_state == CLIENT_LINKDEAD); }
	void Kick(const std::string &reason);
	void WorldKick();
	inline uint8 GetAnon() const { return m_pp.anon; }
	inline uint8 GetAFK() const { return AFK; }
	void SetAnon(uint8 anon_flag);
	void SetAFK(uint8 afk_flag);
	inline PlayerProfile_Struct& GetPP() { return m_pp; }
	inline ExtendedProfile_Struct& GetEPP() { return m_epp; }
	inline EQ::InventoryProfile& GetInv() { return m_inv; }
	inline const EQ::InventoryProfile& GetInv() const { return m_inv; }
	inline PetInfo* GetPetInfo(int pet_info_type) { return pet_info_type == PetInfoType::Suspended ? &m_suspendedminion : &m_petinfo; }
	inline InspectMessage_Struct& GetInspectMessage() { return m_inspect_message; }
	inline const InspectMessage_Struct& GetInspectMessage() const { return m_inspect_message; }
	void ReloadExpansionProfileSetting();

	void SetPetCommandState(int button, int state);

	bool AutoAttackEnabled() const { return auto_attack; }
	bool AutoFireEnabled() const { return auto_fire; }

	bool ChangeFirstName(const char* in_firstname,const char* gmname);

	void Duck();
	void Stand();
	void Sit();

	virtual void SetMaxHP();
	int32 LevelRegen();
	void SetGM(bool toggle);
	void SetPVP(bool toggle, bool message = true);

	inline bool GetPVP(bool inc_temp = true) const { return m_pp.pvp != 0 || (inc_temp && temp_pvp); }
	inline bool GetGM() const { return m_pp.gm != 0; }

	inline void SetBaseClass(uint32 i) { m_pp.class_=i; }
	inline void SetBaseRace(uint32 i) { m_pp.race=i; }
	inline void SetBaseGender(uint32 i) { m_pp.gender=i; }
	inline void SetDeity(uint32 i) {m_pp.deity=i;deity=i;}

	void SetTrackingID(uint32 entity_id);

	inline uint8 GetLevel2() const { return m_pp.level2; }
	inline uint16 GetBaseRace() const { return m_pp.race; }
	inline uint16 GetBaseClass() const { return m_pp.class_; }
	inline uint8 GetBaseGender() const { return m_pp.gender; }
	inline uint8 GetBaseFace() const { return m_pp.face; }
	inline uint8 GetBaseHairColor() const { return m_pp.haircolor; }
	inline uint8 GetBaseBeardColor() const { return m_pp.beardcolor; }
	inline uint8 GetBaseEyeColor() const { return m_pp.eyecolor1; }
	inline uint8 GetBaseHairStyle() const { return m_pp.hairstyle; }
	inline uint8 GetBaseBeard() const { return m_pp.beard; }
	inline uint8 GetBaseHeritage() const { return m_pp.drakkin_heritage; }
	inline uint8 GetBaseTattoo() const { return m_pp.drakkin_tattoo; }
	inline uint8 GetBaseDetails() const { return m_pp.drakkin_details; }
	inline const float GetBindX(uint32 index = 0) const { return m_pp.binds[index].x; }
	inline const float GetBindY(uint32 index = 0) const { return m_pp.binds[index].y; }
	inline const float GetBindZ(uint32 index = 0) const { return m_pp.binds[index].z; }
	inline const float GetBindHeading(uint32 index = 0) const { return m_pp.binds[index].heading; }
	inline uint32 GetBindZoneID(uint32 index = 0) const { return m_pp.binds[index].zone_id; }
	inline uint32 GetBindInstanceID(uint32 index = 0) const { return m_pp.binds[index].instance_id; }
	int64 CalcMaxMana();
	int64 CalcBaseMana();
	const int64& SetMana(int64 amount);
	int64 CalcManaRegenCap() final;

	// guild pool regen shit. Sends a SpawnAppearance with a value that regens to value * 0.001
	void EnableAreaHPRegen(int value);
	void DisableAreaHPRegen();
	void EnableAreaManaRegen(int value);
	void DisableAreaManaRegen();
	void EnableAreaEndRegen(int value);
	void DisableAreaEndRegen();
	void EnableAreaRegens(int value);
	void DisableAreaRegens();

	void ServerFilter(SetServerFilter_Struct* filter);
	void BulkSendTraderInventory(uint32 char_id);
	void SendSingleTraderItem(uint32 char_id, int uniqueid);
	void BulkSendMerchantInventory(int merchant_id, int npcid);

	inline uint8 GetLanguageSkill(uint8 language_id) const { return m_pp.languages[language_id]; }

	void SendPickPocketResponse(Mob *from, uint32 amt, int type, const EQ::ItemData* item = nullptr);

	inline const char* GetLastName() const { return lastname; }

	inline float ProximityX() const { return m_Proximity.x; }
	inline float ProximityY() const { return m_Proximity.y; }
	inline float ProximityZ() const { return m_Proximity.z; }
	inline void ClearAllProximities() { entity_list.ProcessMove(this, glm::vec3(FLT_MAX, FLT_MAX, FLT_MAX)); m_Proximity = glm::vec3(FLT_MAX,FLT_MAX,FLT_MAX); }

	void CheckVirtualZoneLines();

	/*
			Begin client modifiers
	*/

	virtual void CalcBonuses();
	//these are all precalculated now
	inline virtual int32 GetATKBonus() const { return itembonuses.ATK + spellbonuses.ATK; }
	inline virtual int GetHaste() const { return Haste; }
	int GetRawACNoShield(int &shield_ac) const;

	inline virtual int32 GetSTR() const { return STR; }
	inline virtual int32 GetSTA() const { return STA; }
	inline virtual int32 GetDEX() const { return DEX; }
	inline virtual int32 GetAGI() const { return AGI; }
	inline virtual int32 GetINT() const { return INT; }
	inline virtual int32 GetWIS() const { return WIS; }
	inline virtual int32 GetCHA() const { return CHA; }
	inline virtual int32 GetMR() const { return MR; }
	inline virtual int32 GetFR() const { return FR; }
	inline virtual int32 GetDR() const { return DR; }
	inline virtual int32 GetPR() const { return PR; }
	inline virtual int32 GetCR() const { return CR; }
	inline virtual int32 GetCorrup() const { return Corrup; }
	inline virtual int32 GetPhR() const { return PhR; }

	int32 GetMaxStat() const;
	int32 GetMaxResist() const;
	int32 GetMaxSTR() const;
	int32 GetMaxSTA() const;
	int32 GetMaxDEX() const;
	int32 GetMaxAGI() const;
	int32 GetMaxINT() const;
	int32 GetMaxWIS() const;
	int32 GetMaxCHA() const;
	int32 GetMaxMR() const;
	int32 GetMaxPR() const;
	int32 GetMaxDR() const;
	int32 GetMaxCR() const;
	int32 GetMaxFR() const;
	int32 GetMaxCorrup() const;
	inline uint8 GetBaseSTR() const { return m_pp.STR; }
	inline uint8 GetBaseSTA() const { return m_pp.STA; }
	inline uint8 GetBaseCHA() const { return m_pp.CHA; }
	inline uint8 GetBaseDEX() const { return m_pp.DEX; }
	inline uint8 GetBaseINT() const { return m_pp.INT; }
	inline uint8 GetBaseAGI() const { return m_pp.AGI; }
	inline uint8 GetBaseWIS() const { return m_pp.WIS; }
	inline uint8 GetBaseCorrup() const { return 15; } // Same for all
	inline uint8 GetBasePhR() const { return 0; } // Guessing at 0 as base

	inline virtual int32 GetHeroicSTR() const { return itembonuses.HeroicSTR; }
	inline virtual int32 GetHeroicSTA() const { return itembonuses.HeroicSTA; }
	inline virtual int32 GetHeroicDEX() const { return itembonuses.HeroicDEX; }
	inline virtual int32 GetHeroicAGI() const { return itembonuses.HeroicAGI; }
	inline virtual int32 GetHeroicINT() const { return itembonuses.HeroicINT; }
	inline virtual int32 GetHeroicWIS() const { return itembonuses.HeroicWIS; }
	inline virtual int32 GetHeroicCHA() const { return itembonuses.HeroicCHA; }
	inline virtual int32 GetHeroicMR() const { return itembonuses.HeroicMR; }
	inline virtual int32 GetHeroicFR() const { return itembonuses.HeroicFR; }
	inline virtual int32 GetHeroicDR() const { return itembonuses.HeroicDR; }
	inline virtual int32 GetHeroicPR() const { return itembonuses.HeroicPR; }
	inline virtual int32 GetHeroicCR() const { return itembonuses.HeroicCR; }
	inline virtual int32 GetHeroicCorrup() const { return itembonuses.HeroicCorrup; }
	inline virtual int32 GetHeroicPhR() const { return 0; } // Heroic PhR not implemented yet
	// Mod2
	inline virtual int32 GetShielding() const { return itembonuses.MeleeMitigation; }
	inline virtual int32 GetSpellShield() const { return itembonuses.SpellShield; }
	inline virtual int32 GetDoTShield() const { return itembonuses.DoTShielding; }
	inline virtual int32 GetStunResist() const { return itembonuses.StunResist; }
	inline virtual int32 GetStrikeThrough() const { return itembonuses.StrikeThrough; }
	inline virtual int32 GetAvoidance() const { return itembonuses.AvoidMeleeChance; }
	inline virtual int32 GetAccuracy() const { return itembonuses.HitChance; }
	inline virtual int32 GetCombatEffects() const { return itembonuses.ProcChance; }
	inline virtual int32 GetDS() const { return itembonuses.DamageShield; }
	// Mod3
	inline int32 GetHealAmt() const override { return itembonuses.HealAmt; }
	inline int32 GetSpellDmg() const final { return itembonuses.SpellDmg; }
	inline virtual int32 GetClair() const { return itembonuses.Clairvoyance; }
	inline virtual int32 GetDSMit() const { return itembonuses.DSMitigation; }

	inline virtual int32 GetSingMod() const { return itembonuses.singingMod; }
	inline virtual int32 GetBrassMod() const { return itembonuses.brassMod; }
	inline virtual int32 GetPercMod() const { return itembonuses.percussionMod; }
	inline virtual int32 GetStringMod() const { return itembonuses.stringedMod; }
	inline virtual int32 GetWindMod() const { return itembonuses.windMod; }

	inline virtual int32 GetDelayDeath() const { return aabonuses.DelayDeath + spellbonuses.DelayDeath + itembonuses.DelayDeath + 11; }

	virtual bool CheckFizzle(uint16 spell_id);
	virtual int GetCurrentBuffSlots() const;
	virtual int GetCurrentSongSlots() const;
	virtual int GetCurrentDiscSlots() const { return 1; }
	virtual int GetMaxBuffSlots() const { return EQ::spells::LONG_BUFFS; }
	virtual int GetMaxSongSlots() const { return EQ::spells::SHORT_BUFFS; }
	virtual int GetMaxDiscSlots() const { return EQ::spells::DISC_BUFFS; }
	virtual int GetMaxTotalSlots() const { return EQ::spells::TOTAL_BUFFS; }
	virtual uint32 GetFirstBuffSlot(bool disc, bool song);
	virtual uint32 GetLastBuffSlot(bool disc, bool song);
	virtual void InitializeBuffSlots();
	virtual void UninitializeBuffSlots();

	inline const int32 GetBaseHP() const { return base_hp; }

	uint32 GetWeight() const { return(weight); }
	inline void RecalcWeight() { weight = CalcCurrentWeight(); }
	uint32 CalcCurrentWeight();
	inline uint32 GetCopper() const { return m_pp.copper; }
	inline uint32 GetSilver() const { return m_pp.silver; }
	inline uint32 GetGold() const { return m_pp.gold; }
	inline uint32 GetPlatinum() const { return m_pp.platinum; }


	/*Endurance and such*/
	void CalcMaxEndurance(); //This calculates the maximum endurance we can have
	int64 CalcBaseEndurance(); //Calculates Base End
	int64 CalcEnduranceRegen(bool bCombat = false); //Calculates endurance regen used in DoEnduranceRegen()
	int64 GetEndurance() const {return current_endurance;} //This gets our current endurance
	int64 GetMaxEndurance() const {return max_end;} //This gets our endurance from the last CalcMaxEndurance() call
	int64 CalcEnduranceRegenCap() final;
	int64 CalcHPRegenCap() final;
	inline uint8 GetEndurancePercent() { return (uint8)((float)current_endurance / (float)max_end * 100.0f); }
	void SetEndurance(int32 newEnd); //This sets the current endurance to the new value
	void DoEnduranceRegen(); //This Regenerates endurance
	void DoEnduranceUpkeep(); //does the endurance upkeep

	//This calculates total Attack Rating to match very close to what the client should show
	uint32 GetTotalATK();
	uint32 GetATKRating();
	//This gets the skill value of the item type equipped in the Primary Slot
	uint16 GetPrimarySkillValue();

	bool Flurry();
	bool Rampage();

	inline uint32 GetEXP() const { return m_pp.exp; }

	float GetAAEXPModifier(uint32 zone_id, int16 instance_version = -1);
	float GetEXPModifier(uint32 zone_id, int16 instance_version = -1);
	void SetAAEXPModifier(uint32 zone_id, float aa_modifier, int16 instance_version = -1);
	void SetEXPModifier(uint32 zone_id, float exp_modifier, int16 instance_version = -1);

	bool UpdateLDoNPoints(uint32 theme_id, int points);
	void SetLDoNPoints(uint32 theme_id, uint32 points);
	void SetPVPPoints(uint32 Points) { m_pp.PVPCurrentPoints = Points; }
	uint32 GetPVPPoints() { return m_pp.PVPCurrentPoints; }
	void AddPVPPoints(uint32 Points);
	void AddEbonCrystals(uint32 amount, bool is_reclaim = false);
	void AddRadiantCrystals(uint32 amount, bool is_reclaim = false);
	void RemoveEbonCrystals(uint32 amount, bool is_reclaim = false);
	void RemoveRadiantCrystals(uint32 amount, bool is_reclaim = false);
	uint32 GetRadiantCrystals() { return m_pp.currentRadCrystals; }
	void SetRadiantCrystals(uint32 value);
	uint32 GetEbonCrystals() { return m_pp.currentEbonCrystals; }
	void SetEbonCrystals(uint32 value);
	void SendCrystalCounts();

	uint64 GetExperienceForKill(Mob *against);
	void AddEXP(uint64 in_add_exp, uint8 conlevel = 0xFF, bool resexp = false);
	uint64 CalcEXP(uint8 conlevel = 0xFF, bool ignore_mods = false);
	void CalculateNormalizedAAExp(uint64 &add_aaxp, uint8 conlevel, bool resexp);
	void CalculateStandardAAExp(uint64 &add_aaxp, uint8 conlevel, bool resexp);
	void CalculateLeadershipExp(uint64 &add_exp, uint8 conlevel);
	void CalculateExp(uint64 in_add_exp, uint64 &add_exp, uint64 &add_aaxp, uint8 conlevel, bool resexp);
	void SetEXP(uint64 set_exp, uint64 set_aaxp, bool resexp=false);
	void AddLevelBasedExp(uint8 exp_percentage, uint8 max_level = 0, bool ignore_mods = false);
	void SetLeadershipEXP(uint64 group_exp, uint64 raid_exp);
	void AddLeadershipEXP(uint64 group_exp, uint64 raid_exp);
	void SendLeadershipEXPUpdate();
	bool IsLeadershipEXPOn();
	inline int GetLeadershipAA(int AAID) { return m_pp.leader_abilities.ranks[AAID]; }
	inline LeadershipAA_Struct &GetLeadershipAA() { return m_pp.leader_abilities; }
	inline GroupLeadershipAA_Struct &GetGroupLeadershipAA() { return m_pp.leader_abilities.group; }
	inline RaidLeadershipAA_Struct &GetRaidLeadershipAA() { return m_pp.leader_abilities.raid; }
	int GroupLeadershipAAHealthEnhancement();
	int GroupLeadershipAAManaEnhancement();
	int GroupLeadershipAAHealthRegeneration();
	int GroupLeadershipAAOffenseEnhancement();
	void InspectBuffs(Client* Inspector, int Rank);
	uint32 GetRaidPoints() { return(m_pp.raid_leadership_points); }
	uint32 GetGroupPoints() { return(m_pp.group_leadership_points); }
	uint32 GetRaidEXP() { return(m_pp.raid_leadership_exp); }
	uint32 GetGroupEXP() { return(m_pp.group_leadership_exp); }
	uint32 GetTotalSecondsPlayed() { return(TotalSecondsPlayed); }
	virtual void SetLevel(uint8 set_level, bool command = false);

	void GoToBind(uint8 bindnum = 0);
	void GoToSafeCoords(uint16 zone_id, uint16 instance_id);
	void Gate(uint8 bindnum = 0);
	void SetBindPoint(int bind_num = 0, int to_zone = -1, int to_instance = 0, const glm::vec3& location = glm::vec3());
	void SetBindPoint2(int bind_num = 0, int to_zone = -1, int to_instance = 0, const glm::vec4& location = glm::vec4());
	void SetStartZone(uint32 zoneid, float x = 0.0f, float y =0.0f, float z = 0.0f, float heading = 0.0f);
	uint32 GetStartZone(void);
	void MovePC(const char* zonename, float x, float y, float z, float heading, uint8 ignorerestrictions = 0, ZoneMode zm = ZoneSolicited);
	void MovePC(uint32 zoneID, float x, float y, float z, float heading, uint8 ignorerestrictions = 0, ZoneMode zm = ZoneSolicited);
	void MovePC(float x, float y, float z, float heading, uint8 ignorerestrictions = 0, ZoneMode zm = ZoneSolicited);
	void MovePC(uint32 zoneID, uint32 instanceID, float x, float y, float z, float heading, uint8 ignorerestrictions = 0, ZoneMode zm = ZoneSolicited);
	void MoveZone(const char *zone_short_name, const glm::vec4& location = glm::vec4(0.f));
	void MoveZoneGroup(const char *zone_short_name, const glm::vec4& location = glm::vec4(0.f));
	void MoveZoneRaid(const char *zone_short_name, const glm::vec4& location = glm::vec4(0.f));
	void MoveZoneInstance(uint16 instance_id, const glm::vec4& location = glm::vec4(0.f));
	void MoveZoneInstanceGroup(uint16 instance_id, const glm::vec4& location = glm::vec4(0.f));
	void MoveZoneInstanceRaid(uint16 instance_id, const glm::vec4& location = glm::vec4(0.f));
	void SendToGuildHall();
	void SendToInstance(std::string instance_type, std::string zone_short_name, uint32 instance_version, float x, float y, float z, float heading, std::string instance_identifier, uint32 duration);
	void AssignToInstance(uint16 instance_id);
	void RemoveFromInstance(uint16 instance_id);
	void WhoAll();
	bool CheckLoreConflict(const EQ::ItemData* item);
	void ChangeLastName(std::string last_name);
	void GetGroupAAs(GroupLeadershipAA_Struct *into) const;
	void GetRaidAAs(RaidLeadershipAA_Struct *into) const;
	void ClearGroupAAs();
	void UpdateGroupAAs(int32 points, uint32 type);
	void SacrificeConfirm(Client* caster);
	void Sacrifice(Client* caster);
	void GoToDeath();
	inline const int32 GetInstanceID() const { return zone->GetInstanceID(); }
	void SetZoning(bool in) { bZoning = in; }

	void ShowSpells(Client* c, ShowSpellType show_spell_type);

	FACTION_VALUE GetReverseFactionCon(Mob* iOther);
	FACTION_VALUE GetFactionLevel(uint32 char_id, uint32 npc_id, uint32 p_race, uint32 p_class, uint32 p_deity, int32 pFaction, Mob* tnpc);
	bool ReloadCharacterFaction(Client *c, uint32 facid, uint32 charid);
	int32 GetCharacterFactionLevel(int32 faction_id);
	int32 GetModCharacterFactionLevel(int32 faction_id);
	void MerchantRejectMessage(Mob *merchant, int primaryfaction);
	void SendFactionMessage(int32 tmpvalue, int32 faction_id, int32 faction_before_hit, int32 totalvalue, uint8 temp,  int32 this_faction_min, int32 this_faction_max);

	void UpdatePersonalFaction(int32 char_id, int32 npc_value, int32 faction_id, int32 *current_value, int32 temp, int32 this_faction_min, int32 this_faction_max);
	void SetFactionLevel(uint32 char_id, uint32 npc_faction_id, uint8 char_class, uint8 char_race, uint8 char_deity, bool quest = false);
	void SetFactionLevel2(uint32 char_id, int32 faction_id, uint8 char_class, uint8 char_race, uint8 char_deity, int32 value, uint8 temp);
	int32 GetRawItemAC();

	inline uint32 LSAccountID() const { return lsaccountid; }
	inline uint32 GetWID() const { return WID; }
	inline void SetWID(uint32 iWID) { WID = iWID; }
	inline uint32 AccountID() const { return account_id; }

	inline const char* AccountName()const { return account_name; }
	inline int GetAccountCreation() const { return account_creation; }
	inline int16 Admin() const { return admin; }
	inline uint32 CharacterID() const { return character_id; }
	void UpdateAdmin(bool from_database = true);
	void UpdateWho(uint8 remove = 0);
	bool GMHideMe(Client* client = 0);

	inline bool IsInAGuild() const { return(guild_id != GUILD_NONE && guild_id != 0); }
	inline bool IsInGuild(uint32 in_gid) const { return(in_gid == guild_id && IsInAGuild()); }
	inline bool GetGuildListDirty() { return guild_dirty; }
	inline void SetGuildListDirty(bool state) { guild_dirty = state; }
	inline uint32 GuildID() const { return guild_id; }
	inline uint8 GuildRank() const { return guildrank; }
	inline bool GuildTributeOptIn() const { return guild_tribute_opt_in; }
	void SetGuildTributeOptIn(bool state);
	void SendGuildTributeDonateItemReply(GuildTributeDonateItemRequest_Struct* in, uint32 favor);
	void SendGuildTributeDonatePlatReply(GuildTributeDonatePlatRequest_Struct* in, uint32 favor);
	void SetGuildRank(uint32 rank);
	void SetGuildID(uint32 guild_id);
	void SendGuildMOTD(bool GetGuildMOTDReply = false);
	void SendGuildURL();
	void SendGuildChannel();
	void SendGuildSpawnAppearance();
	void SendGuildRanks();
	void SendGuildMembers();
	void SendGuildList();
	void SendGuildJoin(GuildJoin_Struct* gj);
	void RefreshGuildInfo();
	void SendGuildRankNames();
	void SendGuildTributeDetails(uint32 tribute_id, uint32 tier);
	void DoGuildTributeUpdate();
	void SendGuildActiveTributes(uint32 guild_id);
	void SendGuildFavorAndTimer(uint32 guild_id);
	void SendGuildTributeOptInToggle(const GuildTributeMemberToggle* in);
	void RequestGuildActiveTributes(uint32 guild_id);
	void RequestGuildFavorAndTimer(uint32 guild_id);
	void SendGuildMembersList();
	void SendGuildMemberAdd(uint32 guild_id, uint32 level, uint32 _class, uint32 rank, uint32 guild_show, uint32 zone_id, std::string player_name);
	void SendGuildMemberRename(uint32 guild_id, std::string player_name, std::string new_player_name);
	void SendGuildMemberDelete(uint32 guild_id, std::string player_name);
	void SendGuildMemberLevel(uint32 guild_id, uint32 level, std::string player_name);
	void SendGuildMemberRankAltBanker(uint32 guild_id, uint32 rank, std::string player_name, bool alt, bool banker);
	void SendGuildMemberPublicNote(uint32 guild_id, std::string player_name, std::string public_note);
	void SendGuildMemberDetails(uint32 guild_id, uint32 zone_id, uint32 offline_mode, std::string player_name);
	void SendGuildRenameGuild(uint32 guild_id, std::string new_guild_name);
	void SendGuildDeletePacket(uint32 guild_id);

	uint8 GetClientMaxLevel() const { return client_max_level; }
	void SetClientMaxLevel(uint8 max_level) { client_max_level = max_level; }

	void CheckManaEndUpdate();
	void SendManaUpdate();
	void SendEnduranceUpdate();
	uint8 GetFace() const { return m_pp.face; }
	void WhoAll(Who_All_Struct* whom);
	void FriendsWho(char *FriendsString);

	void Stun(int duration);
	void UnStun();
	void ReadBook(BookRequest_Struct *book);
	void ReadBookByName(std::string book_name, uint8 book_type);
	void QuestReadBook(const char* text, uint8 type);
	void SendMoneyUpdate();
	bool TakeMoneyFromPP(uint64 copper, bool update_client = false);
	bool TakePlatinum(uint32 platinum, bool update_client = false);
	void AddMoneyToPP(uint64 copper, bool update_client = false);
	void AddMoneyToPP(uint32 copper, uint32 silver, uint32 gold, uint32 platinum, bool update_client = false);
	void AddPlatinum(uint32 platinu, bool update_client = false);
	bool HasMoney(uint64 copper);
	uint64 GetCarriedMoney();
	uint32 GetCarriedPlatinum();
	uint64 GetAllMoney();
	uint32 GetMoney(uint8 type, uint8 subtype);
	int GetAccountAge();

	void SendPath(Mob* target);

	bool IsDiscovered(uint32 itemid);
	void DiscoverItem(uint32 itemid);

	bool TGB() const { return tgb; }

	void OnDisconnect(bool hard_disconnect);

	uint16 GetSkillPoints() { return m_pp.points;}
	void SetSkillPoints(int inp) { m_pp.points = inp;}

	void IncreaseSkill(int skill_id, int value = 1) { if (skill_id <= EQ::skills::HIGHEST_SKILL) { m_pp.skills[skill_id] += value; } }
	void IncreaseLanguageSkill(uint8 language_id, uint8 increase = 1);
	virtual uint16 GetSkill(EQ::skills::SkillType skill_id) const { if (skill_id <= EQ::skills::HIGHEST_SKILL) { return(itembonuses.skillmod[skill_id] > 0 ? (itembonuses.skillmodmax[skill_id] > 0 ? std::min(m_pp.skills[skill_id] + itembonuses.skillmodmax[skill_id], m_pp.skills[skill_id] * (100 + itembonuses.skillmod[skill_id]) / 100) : m_pp.skills[skill_id] * (100 + itembonuses.skillmod[skill_id]) / 100) : m_pp.skills[skill_id]); } return 0; }
	uint32 GetRawSkill(EQ::skills::SkillType skill_id) const { if (skill_id <= EQ::skills::HIGHEST_SKILL) { return(m_pp.skills[skill_id]); } return 0; }
	bool HasSkill(EQ::skills::SkillType skill_id) const;
	bool CanHaveSkill(EQ::skills::SkillType skill_id) const;
	void SetSkill(EQ::skills::SkillType skill_num, uint16 value);
	void AddSkill(EQ::skills::SkillType skillid, uint16 value);
	void CheckSpecializeIncrease(uint16 spell_id);
	void CheckSongSkillIncrease(uint16 spell_id);
	bool CheckIncreaseSkill(EQ::skills::SkillType skillid, Mob *against_who, int chancemodi = 0);
	void CheckLanguageSkillIncrease(uint8 language_id, uint8 teacher_skill);
	void SetLanguageSkill(uint8 language_id, uint8 language_skill);
	void SetHoTT(uint32 mobid);
	void ShowSkillsWindow();

	uint16 MaxSkill(EQ::skills::SkillType skillid, uint16 class_, uint16 level) const;
	inline uint16 MaxSkill(EQ::skills::SkillType skillid) const { return MaxSkill(skillid, GetClass(), GetLevel()); }
	uint8 SkillTrainLevel(EQ::skills::SkillType skillid, uint16 class_);
	void MaxSkills();

	void SendTradeskillSearchResults(const std::string &query, unsigned long objtype, unsigned long someid);
	void SendTradeskillDetails(uint32 recipe_id);
	bool TradeskillExecute(DBTradeskillRecipe_Struct *spec);
	void CheckIncreaseTradeskill(int16 bonusstat, int16 stat_modifier, float skillup_modifier, uint16 success_modifier, EQ::skills::SkillType tradeskill);
	bool CheckTradeskillLoreConflict(int32 recipe_id);
	void InitInnates();

	void GMKill();
	inline bool IsMedding() const {return medding;}
	inline uint32 GetDuelTarget() const { return duel_target; }
	inline bool IsDueling() const { return duelaccepted; }
	inline void SetDuelTarget(uint32 set_id) { duel_target = set_id; }
	inline void SetDueling(bool duel) { duelaccepted = duel; }
	// use this one instead
	void MemSpell(uint16 spell_id, int slot, bool update_client = true);
	void UnmemSpell(int slot, bool update_client = true);
	void UnmemSpellBySpellID(int32 spell_id);
	void UnmemSpellAll(bool update_client = true);
	int FindEmptyMemSlot();
	uint16 FindMemmedSpellBySlot(int slot);
	int FindMemmedSpellBySpellID(uint16 spell_id);
	int MemmedCount();
	std::vector<int> GetLearnableDisciplines(uint8 min_level = 1, uint8 max_level = 0);
	std::vector<int> GetLearnedDisciplines();
	std::vector<int> GetMemmedSpells();
	std::vector<int> GetScribeableSpells(uint8 min_level = 1, uint8 max_level = 0);
	std::vector<int> GetScribedSpells();
	// defer save used when bulk saving
	void ScribeSpell(uint16 spell_id, int slot, bool update_client = true, bool defer_save = false);
	void SaveSpells();
	void SaveDisciplines();

	// Bulk Scribe/Learn
	uint16 ScribeSpells(uint8 min_level, uint8 max_level);
	uint16 LearnDisciplines(uint8 min_level, uint8 max_level);

	// Configurable Tracking Skill
	uint16 GetClassTrackingDistanceMultiplier(uint16 class_);

	bool CanThisClassTrack();

	// defer save used when bulk saving
	void UnscribeSpell(int slot, bool update_client = true, bool defer_save = false);
	void UnscribeSpellAll(bool update_client = true);
	void UnscribeSpellBySpellID(uint16 spell_id, bool update_client = true);
	void UntrainDisc(int slot, bool update_client = true, bool defer_save = false);
	void UntrainDiscAll(bool update_client = true);
	void UntrainDiscBySpellID(uint16 spell_id, bool update_client = true);
	bool SpellGlobalCheck(uint16 spell_id, uint32 char_id);
	bool SpellBucketCheck(uint16 spell_id, uint32 char_id);
	uint8 GetCharMaxLevelFromQGlobal();
	uint8 GetCharMaxLevelFromBucket();

	void Fling(float value, float target_x, float target_y, float target_z, bool ignore_los = false, bool clip_through_walls = false, bool calculate_speed = false);

	inline bool IsStanding() const { return (playeraction == 0); }
	inline bool IsSitting() const override { return (playeraction == 1); }
	inline bool IsCrouching() const { return (playeraction == 2); }
	inline bool IsBecomeNPC() const { return npcflag; }
	inline uint8 GetBecomeNPCLevel() const { return npclevel; }
	inline void SetBecomeNPC(bool flag) { npcflag = flag; }
	inline void SetBecomeNPCLevel(uint8 level) { npclevel = level; }
	EQStreamInterface* Connection() { return eqs; }
	uint32 GetEquippedItemFromTextureSlot(uint8 material_slot) const; // returns item id
	uint32 GetEquipmentColor(uint8 material_slot) const;
	virtual void UpdateEquipmentLight() { m_Light.Type[EQ::lightsource::LightEquipment] = m_inv.FindBrightestLightType(); m_Light.Level[EQ::lightsource::LightEquipment] = EQ::lightsource::TypeToLevel(m_Light.Type[EQ::lightsource::LightEquipment]); }

	inline bool AutoSplitEnabled() { return m_pp.autosplit != 0; }
	inline bool AutoConsentGroupEnabled() const { return m_pp.groupAutoconsent != 0; }
	inline bool AutoConsentRaidEnabled() const { return m_pp.raidAutoconsent != 0; }
	inline bool AutoConsentGuildEnabled() const { return m_pp.guildAutoconsent != 0; }

	void SummonHorse(uint16 spell_id);
	void SetHorseId(uint16 horseid_in);
	inline void SetControlledMobId(uint16 mob_id_in) { controlled_mob_id = mob_id_in; }
	uint16 GetControlledMobId() const{ return controlled_mob_id; }
	uint16 GetHorseId() const { return horseId; }
	bool CanMedOnHorse();

	bool CanFastRegen() const { return ooc_regen; }

	void NPCSpawn(NPC *target_npc, const char *identifier, uint32 extra = 0);

	void Disarm(Client* disarmer, int chance);
	bool BindWound(Mob* bindmob, bool start, bool fail = false);
	void SetTradeskillObject(Object* object) { m_tradeskill_object = object; }
	Object* GetTradeskillObject() { return m_tradeskill_object; }
	void SendTributes();
	void SendGuildTributes();
	void DoTributeUpdate();
	void SendTributeDetails(uint32 client_id, uint32 tribute_id);
	int32 TributeItem(uint32 slot, uint32 quantity);
	int32 TributeMoney(uint32 platinum);
	void AddTributePoints(int32 ammount);
	void ChangeTributeSettings(TributeInfo_Struct *t);
	void SendTributeTimer();
	void ToggleTribute(bool enabled);
	void SendPathPacket(const std::vector<FindPerson_Point> &path);

	inline PTimerList &GetPTimers() { return(p_timers); }

	//New AA Methods
	void SendAlternateAdvancementRank(int aa_id, int level);
	void SendAlternateAdvancementTable();
	void SendAlternateAdvancementStats();
	void PurchaseAlternateAdvancementRank(int rank_id);
	bool GrantAlternateAdvancementAbility(int aa_id, int points, bool ignore_cost = false);
	void IncrementAlternateAdvancementRank(int rank_id);
	void ActivateAlternateAdvancementAbility(int rank_id, int target_id);
	void SendAlternateAdvancementPoints();
	void SendAlternateAdvancementTimer(int ability, int begin, int end);
	void SendAlternateAdvancementTimers();
	void ResetAlternateAdvancementTimer(int ability);
	void ResetAlternateAdvancementTimers();
	void ResetOnDeathAlternateAdvancement();

	void SetAAPoints(uint32 points) { m_pp.aapoints = points; SendAlternateAdvancementStats(); }
	void AddAAPoints(uint32 points);
	int GetAAPoints() { return m_pp.aapoints; }
	int GetSpentAA() { return m_pp.aapoints_spent; }
	uint32 GetRequiredAAExperience();
	void AutoGrantAAPoints();
	void GrantAllAAPoints(uint8 unlock_level = 0);
	bool HasAlreadyPurchasedRank(AA::Rank* rank);
	void ListPurchasedAAs(Client *to, std::string search_criteria = std::string());

	bool SendGMCommand(std::string message, bool ignore_status = false);

	void RegisterBug(BugReport_Struct* r);

	std::vector<Mob*> GetApplySpellList(
		ApplySpellType apply_type,
		bool allow_pets,
		bool is_raid_group_only,
		bool allow_bots
	);

	void ApplySpell(
		int spell_id,
		int duration = 0,
		int level = -1,
		ApplySpellType apply_type = ApplySpellType::Solo,
		bool allow_pets = false,
		bool is_raid_group_only = true,
		bool allow_bots = false
	);

	void SetSpellDuration(
		int spell_id,
		int duration = 0,
		int level = -1,
		ApplySpellType apply_type = ApplySpellType::Solo,
		bool allow_pets = false,
		bool is_raid_group_only = true,
		bool allow_bots = false
	);

	//old AA methods that we still use
	void ResetAA();
	void RefundAA();
	void SendClearAA();
	void SendClearLeadershipAA();
	void SendClearPlayerAA();
	inline uint32 GetAAXP() const { return m_pp.expAA; }
	inline uint32 GetAAPercent() const { return m_epp.perAA; }
	void SetAATitle(std::string title);
	void SetTitleSuffix(std::string suffix);
	void MemorizeSpell(uint32 slot, uint32 spell_id, uint32 scribing, uint32 reduction = 0);

	int GetAAEXPPercentage();
	int GetEXPPercentage();

	// Item methods
	void UseAugmentContainer(int container_slot);
	void EVENT_ITEM_ScriptStopReturn();
	uint32 NukeItem(uint32 itemnum, uint8 where_to_check =
			(invWhereWorn | invWherePersonal | invWhereBank | invWhereSharedBank | invWhereTrading | invWhereCursor));
	void SetTint(int16 slot_id, uint32 color);
	void SetTint(int16 slot_id, EQ::textures::Tint_Struct& color);
	void SetMaterial(int16 slot_id, uint32 item_id);
	void Undye();
	int32 GetItemIDAt(int16 slot_id);
	int32 GetAugmentIDAt(int16 slot_id, uint8 augslot);
	bool PutItemInInventory(int16 slot_id, const EQ::ItemInstance& inst, bool client_update = false);
	bool PushItemOnCursor(const EQ::ItemInstance& inst, bool client_update = false);
	void SendCursorBuffer();
	void DeleteItemInInventory(int16 slot_id, int16 quantity = 0, bool client_update = false, bool update_db = true);
	int CountItem(uint32 item_id);
	void ResetItemCooldown(uint32 item_id);
	void SetItemCooldown(uint32 item_id, bool use_saved_timer = false, uint32 in_seconds = 1);
	uint32 GetItemCooldown(uint32 item_id);
	void RemoveItem(uint32 item_id, uint32 quantity = 1);
	bool SwapItem(MoveItem_Struct* move_in);
	void SwapItemResync(MoveItem_Struct* move_slots);
	void QSSwapItemAuditor(MoveItem_Struct* move_in, bool postaction_call = false);
	void PutLootInInventory(int16 slot_id, const EQ::ItemInstance &inst, LootItem** bag_item_data = 0);
	bool AutoPutLootInInventory(EQ::ItemInstance& inst, bool try_worn = false, bool try_cursor = true, LootItem** bag_item_data = 0);
	bool SummonItem(uint32 item_id, int16 charges = -1, uint32 aug1 = 0, uint32 aug2 = 0, uint32 aug3 = 0, uint32 aug4 = 0, uint32 aug5 = 0, uint32 aug6 = 0, bool attuned = false, uint16 to_slot = EQ::invslot::slotCursor, uint32 ornament_icon = 0, uint32 ornament_idfile = 0, uint32 ornament_hero_model = 0);
	void SummonItemIntoInventory(uint32 item_id, int16 charges = -1, uint32 aug1 = 0, uint32 aug2 = 0, uint32 aug3 = 0, uint32 aug4 = 0, uint32 aug5 = 0, uint32 aug6 = 0, bool is_attuned = false);
	void SummonBaggedItems(uint32 bag_item_id, const std::vector<LootItem>& bag_items);
	void SetStats(uint8 type,int16 set_val);
	void IncStats(uint8 type,int16 increase_val);
	void DropItem(int16 slot_id, bool recurse = true);
	void DropItemQS(EQ::ItemInstance* inst, bool pickup);
	bool HasItemOnCorpse(uint32 item_id);

	bool IsAugmentRestricted(uint8 item_type, uint32 augment_restriction);

	int GetItemLinkHash(const EQ::ItemInstance* inst); // move to ItemData..or make use of the pre-calculated database field

	void SendItemLink(const EQ::ItemInstance* inst, bool sendtoall=false);
	void SendLootItemInPacket(const EQ::ItemInstance* inst, int16 slot_id);
	void SendItemPacket(int16 slot_id, const EQ::ItemInstance* inst, ItemPacketType packet_type);
	bool IsValidSlot(uint32 slot);
	bool IsBankSlot(uint32 slot);

	inline bool IsTrader() const { return(Trader); }
	inline bool IsBuyer() const { return(Buyer); }
	eqFilterMode GetFilter(eqFilterType filter_id) const { return ClientFilters[filter_id]; }
	void SetFilter(eqFilterType filter_id, eqFilterMode filter_mode) { ClientFilters[filter_id] = filter_mode; }

	void CancelSneakHide();
	void BreakInvis();
	void BreakSneakWhenCastOn(Mob* caster, bool IsResisted);
	void BreakFeignDeathWhenCastOn(bool IsResisted);
	void LeaveGroup();

	bool Hungry() const {if (GetGM() || !RuleB(Character, EnableFoodRequirement)) return false; return m_pp.hunger_level <= 3000;}
	bool Thirsty() const {if (GetGM() || !RuleB(Character, EnableFoodRequirement)) return false; return m_pp.thirst_level <= 3000;}
	int32 GetHunger() const { return m_pp.hunger_level; }
	int32 GetThirst() const { return m_pp.thirst_level; }
	void SetHunger(int32 in_hunger);
	void SetThirst(int32 in_thirst);
	void SetConsumption(int32 in_hunger, int32 in_thirst);
	bool IsStarved() const { if (GetGM() || !RuleB(Character, EnableFoodRequirement) || !RuleB(Character, EnableHungerPenalties)) return false; return m_pp.hunger_level == 0 || m_pp.thirst_level == 0; }
	int32 GetIntoxication() const { return m_pp.intoxication; }

	bool CheckTradeLoreConflict(Client* other);
	bool CheckTradeNonDroppable();
	void LinkDead();
	bool CheckDoubleAttack();
	bool CheckTripleAttack();
	bool CheckDoubleRangedAttack();
	bool CheckDualWield();

	//remove charges/multiple objects from inventory:
	//bool DecreaseByType(uint32 type, uint8 amt);
	bool DecreaseByID(uint32 type, int16 quantity);
	uint8 SlotConvert2(uint8 slot); //Maybe not needed.
	void Escape(); //keep or quest function
	void DisenchantSummonedBags(bool client_update = true);
	void RemoveNoRent(bool client_update = true);
	void RemoveDuplicateLore(bool client_update = true);
	void MoveSlotNotAllowed(bool client_update = true);
	virtual void RangedAttack(Mob* other, bool CanDoubleAttack = false);
	virtual void ThrowingAttack(Mob* other, bool CanDoubleAttack = false);
	void DoClassAttacks(Mob *ca_target, uint16 skill = -1, bool IsRiposte=false);

	void ClearZoneFlag(uint32 zone_id);
	inline std::set<uint32> GetZoneFlags() { return zone_flags; } ;
	bool HasZoneFlag(uint32 zone_id) const;
	void LoadZoneFlags();
	void SendZoneFlagInfo(Client *to) const;
	void SetZoneFlag(uint32 zone_id);

	void ClearPEQZoneFlag(uint32 zone_id);
	inline std::set<uint32> GetPEQZoneFlags() { return peqzone_flags; };
	bool HasPEQZoneFlag(uint32 zone_id) const;
	void LoadPEQZoneFlags();
	void SendPEQZoneFlagInfo(Client *to) const;
	void SetPEQZoneFlag(uint32 zone_id);

	bool CanFish();
	void GoFish();
	void ForageItem(bool guarantee = false);
	//Calculate vendor price modifier based on CHA: (reverse==selling)
	float CalcPriceMod(Mob* other = 0, bool reverse = false);
	void ResetTrade();
	void DropInst(const EQ::ItemInstance* inst);
	bool TrainDiscipline(uint32 itemid);
	bool MemorizeSpellFromItem(uint32 item_id);
	void TrainDiscBySpellID(int32 spell_id);
	uint32 GetDisciplineTimer(uint32 timer_id);
	void ResetAllDisciplineTimers();
	int GetDiscSlotBySpellID(int32 spellid);
	void ResetDisciplineTimer(uint32 timer_id);
	void SendDisciplineUpdate();
	void SendDisciplineTimer(uint32 timer_id, uint32 duration);
	bool UseDiscipline(uint32 spell_id, uint32 target);
	bool HasDisciplineLearned(uint16 spell_id);

	void SetLinkedSpellReuseTimer(uint32 timer_id, uint32 duration);
	bool IsLinkedSpellReuseTimerReady(uint32 timer_id);

	void ResetCastbarCooldownBySlot(int slot);
	void ResetAllCastbarCooldowns();
	void ResetCastbarCooldownBySpellID(uint32 spell_id);

	bool CheckTitle(int titleset);
	void EnableTitle(int titleset);
	void RemoveTitle(int titleset);

	void EnteringMessages(Client* client);
	void SendRules();

	const bool GetGMSpeed() const { return (gmspeed > 0); }
	const bool GetGMInvul() const { return gminvul; }
	bool CanUseReport;

	//This is used to later set the buff duration of the spell, in slot to duration.
	//Doesn't appear to work directly after the client recieves an action packet.
	void SendBuffDurationPacket(Buffs_Struct &buff, int slot);
	void SendBuffNumHitPacket(Buffs_Struct &buff, int slot);

	void ProcessInspectRequest(Client* requestee, Client* requester);
	bool ClientFinishedLoading() { return (conn_state == ClientConnectFinished); }
	int FindSpellBookSlotBySpellID(uint16 spellid);
	uint32 GetSpellIDByBookSlot(int book_slot);
	int GetNextAvailableSpellBookSlot(int starting_slot = 0);
	int GetNextAvailableDisciplineSlot(int starting_slot = 0);
	inline uint32 GetSpellByBookSlot(int book_slot) { return m_pp.spell_book[book_slot]; }
	inline bool HasSpellScribed(int spellid) { return FindSpellBookSlotBySpellID(spellid) != -1; }
	uint32 GetHighestScribedSpellinSpellGroup(uint32 spell_group);
	std::unordered_map<uint32, std::vector<uint16>> LoadSpellGroupCache(uint8 min_level, uint8 max_level);
	uint16 GetMaxSkillAfterSpecializationRules(EQ::skills::SkillType skillid, uint16 maxSkill);
	void SendPopupToClient(const char *Title, const char *Text, uint32 PopupID = 0, uint32 Buttons = 0, uint32 Duration = 0);
	void SendFullPopup(const char *Title, const char *Text, uint32 PopupID = 0, uint32 NegativeID = 0, uint32 Buttons = 0, uint32 Duration = 0, const char *ButtonName0 = 0, const char *ButtonName1 = 0, uint32 SoundControls = 0);
	void SendWindow(uint32 button_one_id, uint32 button_two_id, uint32 button_type, const char* button_one_text, const char* button_two_text, uint32 duration, int title_type, Mob* target, const char* title, const char* text, ...);
	bool PendingTranslocate;
	time_t TranslocateTime;
	bool PendingSacrifice;
	std::string SacrificeCaster;
	PendingTranslocate_Struct PendingTranslocateData;
	void SendOPTranslocateConfirm(Mob *Caster, uint16 SpellID);

	// Task System Methods
	void LoadClientTaskState();
	void RemoveClientTaskState();
	void SendTaskActivityComplete(int task_id, int activity_id, int task_index, TaskType task_type, int task_incomplete=1);
	void SendTaskFailed(int task_id, int task_index, TaskType task_type);
	void SendTaskComplete(int task_index);
	bool HasTaskRequestCooldownTimer();
	void SendTaskRequestCooldownTimerMessage();
	void StartTaskRequestCooldownTimer();
	inline ClientTaskState *GetTaskState() const { return task_state; }
	inline bool HasTaskState() { if (task_state) { return true; } return false; }
	inline void CancelTask(int task_index, TaskType task_type)
	{
		if (task_state) {
			task_state->CancelTask(
				this,
				task_index,
				task_type
			);
		}
	}
	inline bool SaveTaskState()
	{
		return task_manager != nullptr && task_manager->SaveClientState(this, task_state);
	}
	inline bool IsTaskStateLoaded() { return task_state != nullptr; }
	inline bool IsTaskActive(int task_id) { return task_state != nullptr && task_state->IsTaskActive(task_id); }
	inline bool IsTaskActivityActive(int task_id, int activity_id)
	{
		return task_state != nullptr &&
			   task_state->IsTaskActivityActive(
				   task_id,
				   activity_id
			   );
	}
	inline ActivityState GetTaskActivityState(TaskType task_type, int index, int activity_id)
	{
		return (task_state ? task_state->GetTaskActivityState(task_type, index, activity_id) : ActivityHidden);
	}
	inline void UpdateTaskActivity(
		int task_id,
		int activity_id,
		int count,
		bool ignore_quest_update = false
	)
	{
		if (task_state) {
			task_state->UpdateTaskActivity(this, task_id, activity_id, count, ignore_quest_update);
		}
	}
	inline void RemoveTaskByTaskID(uint32 task_id) {
		if (task_state) {
			task_state->RemoveTaskByTaskID(this, task_id);
		}
	}
	inline void ResetTaskActivity(int task_id, int activity_id)
	{
		if (task_state) {
			task_state->ResetTaskActivity(
				this,
				task_id,
				activity_id
			);
		}
	}
	inline void UpdateTasksForItem(TaskActivityType type, int item_id, int count = 1)
	{
		if (task_state) {
			task_state->UpdateTasksForItem(this, type, item_id, count);
		}
	}
	inline void UpdateTasksOnLoot(Corpse* corpse, int item_id, int count = 1)
	{
		if (task_state) {
			task_state->UpdateTasksOnLoot(this, corpse, item_id, count);
		}
	}
	inline void UpdateTasksOnExplore(const glm::vec4& pos)
	{
		if (task_state) {
			task_state->UpdateTasksOnExplore(this, pos);
		}
	}
	inline bool UpdateTasksOnSpeakWith(NPC* npc)
	{
		return task_state && task_state->UpdateTasksOnSpeakWith(this, npc);
	}
	inline bool UpdateTasksOnDeliver(std::vector<EQ::ItemInstance*>& items, Trade& trade, NPC* npc)
	{
		return task_state && task_state->UpdateTasksOnDeliver(this, items, trade, npc);
	}
	void UpdateTasksOnTouchSwitch(int dz_switch_id)
	{
		if (task_state) { task_state->UpdateTasksOnTouch(this, dz_switch_id); }
	}
	inline void TaskSetSelector(Mob* mob, int task_set_id, bool ignore_cooldown)
	{
		if (task_manager && task_state) {
			task_manager->TaskSetSelector(this, mob, task_set_id, ignore_cooldown);
		}
	}
	inline void TaskQuestSetSelector(Mob* mob, const std::vector<int>& tasks, bool ignore_cooldown)
	{
		if (task_manager && task_state) {
			task_manager->TaskQuestSetSelector(this, mob, tasks, ignore_cooldown);
		}
	}
	inline void EnableTask(int task_count, int *task_list)
	{
		if (task_state) {
			task_state->EnableTask(
				CharacterID(),
				task_count,
				task_list
			);
		}
	}
	inline void DisableTask(int task_count, int *task_list)
	{
		if (task_state) {
			task_state->DisableTask(
				CharacterID(),
				task_count,
				task_list
			);
		}
	}
	inline bool IsTaskEnabled(int task_id) {
		return task_state != nullptr && task_state->IsTaskEnabled(task_id);
	}
	inline void ProcessTaskProximities(float x, float y, float z)
	{
		if (task_state) {
			task_state->ProcessTaskProximities(this, x, y, z);
		}
	}
	inline void AssignTask(
		int task_id,
		int npc_id = 0,
		bool enforce_level_requirement = false
	) {
		if (task_state) {
			task_state->AcceptNewTask(this, task_id, npc_id, std::time(nullptr), enforce_level_requirement);
		}
	}
	inline int ActiveSpeakTask(NPC* npc)
	{
		if (task_state) {
			return task_state->ActiveSpeakTask(this, npc);
		}
		else {
			return 0;
		}
	}
	inline int ActiveSpeakActivity(NPC* npc, int task_id)
	{
		if (task_state) {
			return task_state->ActiveSpeakActivity(this, npc, task_id);
		}
		else { return 0; }
	}
	inline bool CompleteTask(uint32 task_id)
	{
		return task_state ? task_state->CompleteTask(this, task_id) : false;
	}
	inline void FailTask(int task_id) { if (task_state) { task_state->FailTask(this, task_id); }}
	inline int TaskTimeLeft(int task_id) { return (task_state ? task_state->TaskTimeLeft(task_id) : 0); }
	inline int EnabledTaskCount(int task_set_id)
	{
		return (task_state ? task_state->EnabledTaskCount(task_set_id) : -1);
	}
	inline int IsTaskCompleted(int task_id) { return (task_state ? task_state->IsTaskCompleted(task_id) : -1); }
	inline void ShowClientTasks(Client *client) { if (task_state) { task_state->ShowClientTasks(this, client); }}
	inline void CancelAllTasks() { if (task_state) { task_state->CancelAllTasks(this); }}
	inline int GetActiveTaskCount() { return (task_state ? task_state->GetActiveTaskCount() : 0); }
	inline int GetActiveTaskID(int index) { return (task_state ? task_state->GetActiveTaskID(index) : -1); }
	inline int GetTaskStartTime(TaskType task_type, int index)
	{
		return (task_state ? task_state->GetTaskStartTime(
			task_type,
			index
		) : -1);
	}
	inline bool IsTaskActivityCompleted(TaskType task_type, int index, int activity_id)
	{
		return task_state != nullptr && task_state->IsTaskActivityCompleted(task_type, index, activity_id);
	}
	inline int GetTaskActivityDoneCount(TaskType task_type, int client_task_index, int activity_id)
	{
		return (task_state ? task_state->GetTaskActivityDoneCount(task_type, client_task_index, activity_id) : 0);
	}
	inline int GetTaskActivityDoneCountFromTaskID(int task_id, int activity_id)
	{
		return (task_state ? task_state->GetTaskActivityDoneCountFromTaskID(task_id, activity_id) : 0);
	}
	inline int ActiveTasksInSet(int task_set_id)
	{
		return (task_state ? task_state->ActiveTasksInSet(task_set_id) : 0);
	}
	inline int CompletedTasksInSet(int task_set_id)
	{
		return (task_state ? task_state->CompletedTasksInSet(task_set_id) : 0);
	}
	void PurgeTaskTimers();
	void LockSharedTask(bool lock) { if (task_state) { task_state->LockSharedTask(this, lock); } }
	void EndSharedTask(bool fail = false) { if (task_state) { task_state->EndSharedTask(this, fail); } }

	// shared task shims / middleware
	// these variables are used as a shim to intercept normal localized task functionality
	// and pipe it into zone -> world and back to world -> zone
	// world is authoritative
	bool m_requesting_shared_task        = false;
	bool m_shared_task_update            = false;
	bool m_requested_shared_task_removal = false;

	std::vector<Client*> GetPartyMembers();

	inline const EQ::versions::ClientVersion ClientVersion() const { return m_ClientVersion; }
	inline const uint32 ClientVersionBit() const { return m_ClientVersionBit; }
	inline void SetClientVersion(EQ::versions::ClientVersion client_version) { m_ClientVersion = client_version; }

	/** Adventure Stuff **/
	void SendAdventureError(const char *error);
	void SendAdventureDetails();
	void SendAdventureCount(uint32 count, uint32 total);
	void NewAdventure(int id, int theme, const char *text, int member_count, const char *members);
	bool IsOnAdventure();
	void LeaveAdventure();
	void AdventureFinish(bool win, int theme, int points);
	void SetAdventureData(char *data) { adv_data = data; }
	void ClearAdventureData() { safe_delete(adv_data); }
	bool HasAdventureData() { return adv_data != nullptr; }
	void ClearCurrentAdventure();
	void PendingAdventureRequest() { adventure_request_timer = new Timer(8000); }
	bool GetPendingAdventureRequest() const { return (adventure_request_timer != nullptr); }
	void ClearPendingAdventureRequest() { safe_delete(adventure_request_timer); }
	void PendingAdventureCreate() { adventure_create_timer = new Timer(8000); }
	bool GetPendingAdventureCreate() const { return (adventure_create_timer != nullptr); }
	void ClearPendingAdventureCreate() { safe_delete(adventure_create_timer); }
	void PendingAdventureLeave() { adventure_leave_timer = new Timer(8000); }
	bool GetPendingAdventureLeave() const { return (adventure_leave_timer != nullptr); }
	void ClearPendingAdventureLeave() { safe_delete(adventure_leave_timer); }
	void PendingAdventureDoorClick() { adventure_door_timer = new Timer(8000); }
	bool GetPendingAdventureDoorClick() const { return (adventure_door_timer != nullptr); }
	void ClearPendingAdventureDoorClick() { safe_delete(adventure_door_timer); }
	void ClearPendingAdventureData();

	bool CanEnterZone(const std::string& zone_short_name = "", int16 instance_version = -1);

	uint32 GetAggroCount();
	void IncrementAggroCount(bool raid_target = false);
	void DecrementAggroCount();
	void SendPVPStats();
	void SendDisciplineTimers();
	void SendRespawnBinds();

	uint32 GetLDoNWins() { return (m_pp.ldon_wins_guk + m_pp.ldon_wins_mir + m_pp.ldon_wins_mmc + m_pp.ldon_wins_ruj + m_pp.ldon_wins_tak); }
	uint32 GetLDoNLosses() { return (m_pp.ldon_losses_guk + m_pp.ldon_losses_mir + m_pp.ldon_losses_mmc + m_pp.ldon_losses_ruj + m_pp.ldon_losses_tak); }
	uint32 GetLDoNWinsTheme(uint32 t);
	uint32 GetLDoNLossesTheme(uint32 t);
	uint32 GetLDoNPointsTheme(uint32 t);
	void UpdateLDoNWinLoss(uint32 theme_id, bool win = false, bool remove = false);
	void CheckLDoNHail(NPC* n);
	void CheckEmoteHail(NPC* n, const char* message);

	void HandleLDoNOpen(NPC *target);
	void HandleLDoNSenseTraps(NPC *target, uint16 skill, uint8 type);
	void HandleLDoNDisarm(NPC *target, uint16 skill, uint8 type);
	void HandleLDoNPickLock(NPC *target, uint16 skill, uint8 type);
	int LDoNChest_SkillCheck(NPC *target, int skill);

	void MarkSingleCompassLoc(float in_x, float in_y, float in_z, uint8 count=1);

	// cross zone client messaging helpers (null client argument will fallback to messaging by name)
	static void SendCrossZoneMessage(
		Client* client, const std::string& client_name, uint16_t chat_type, const std::string& message);
	static void SendCrossZoneMessageString(
		Client* client, const std::string& client_name, uint16_t chat_type,
		uint32_t string_id, const std::initializer_list<std::string>& arguments = {});

	void AddExpeditionLockout(const ExpeditionLockoutTimer& lockout, bool update_db = false);
	void AddExpeditionLockoutDuration(const std::string& expedition_name,
		const std::string& event_Name, int seconds, const std::string& uuid = {}, bool update_db = false);
	void AddNewExpeditionLockout(const std::string& expedition_name,
		const std::string& event_name, uint32_t duration, std::string uuid = {});
	Expedition* CreateExpedition(DynamicZone& dz, bool disable_messages = false);
	Expedition* CreateExpedition(const std::string& zone_name,
		uint32 version, uint32 duration, const std::string& expedition_name,
		uint32 min_players, uint32 max_players, bool disable_messages = false);
	Expedition* CreateExpeditionFromTemplate(uint32_t dz_template_id);
	Expedition* GetExpedition() const;
	uint32 GetExpeditionID() const { return m_expedition_id; }
	const ExpeditionLockoutTimer* GetExpeditionLockout(
		const std::string& expedition_name, const std::string& event_name, bool include_expired = false) const;
	const std::vector<ExpeditionLockoutTimer>& GetExpeditionLockouts() const { return m_expedition_lockouts; };
	std::vector<ExpeditionLockoutTimer> GetExpeditionLockouts(const std::string& expedition_name, bool include_expired = false);
	uint32 GetPendingExpeditionInviteID() const { return m_pending_expedition_invite.expedition_id; }
	bool HasExpeditionLockout(const std::string& expedition_name, const std::string& event_name, bool include_expired = false);
	bool IsInExpedition() const { return m_expedition_id != 0; }
	void RemoveAllExpeditionLockouts(const std::string& expedition_name, bool update_db = false);
	void RemoveExpeditionLockout(const std::string& expedition_name,
		const std::string& event_name, bool update_db = false);
	void RequestPendingExpeditionInvite();
	void SendExpeditionLockoutTimers();
	void SetExpeditionID(uint32 expedition_id) { m_expedition_id = expedition_id; };
	void SetPendingExpeditionInvite(ExpeditionInvite&& invite) { m_pending_expedition_invite = invite; }
	void DzListTimers();
	void SetDzRemovalTimer(bool enable_timer);
	void SendDzCompassUpdate();
	void GoToDzSafeReturnOrBind(const DynamicZone* dynamic_zone);
	void MovePCDynamicZone(uint32 zone_id, int zone_version = -1, bool msg_if_invalid = false);
	void MovePCDynamicZone(const std::string& zone_name, int zone_version = -1, bool msg_if_invalid = false);
	bool TryMovePCDynamicZoneSwitch(int dz_switch_id);
	std::vector<DynamicZone*> GetDynamicZones(uint32_t zone_id = 0, int zone_version = -1);
	std::unique_ptr<EQApplicationPacket> CreateDzSwitchListPacket(const std::vector<DynamicZone*>& dzs);
	std::unique_ptr<EQApplicationPacket> CreateCompassPacket(const std::vector<DynamicZoneCompassEntry_Struct>& entries);
	void AddDynamicZoneID(uint32_t dz_id);
	void RemoveDynamicZoneID(uint32_t dz_id);
	void SendDynamicZoneUpdates();
	void SetDynamicZoneMemberStatus(DynamicZoneMemberStatus status);
	void CreateTaskDynamicZone(int task_id, DynamicZone& dz_request);

	void CalcItemScale();
	bool CalcItemScale(uint32 slot_x, uint32 slot_y); // behavior change: 'slot_y' is now [RANGE]_END and not [RANGE]_END + 1
	void DoItemEnterZone();
	bool DoItemEnterZone(uint32 slot_x, uint32 slot_y); // behavior change: 'slot_y' is now [RANGE]_END and not [RANGE]_END + 1
	void SummonAndRezzAllCorpses();
	void SummonAllCorpses(const glm::vec4& position);
	void DepopAllCorpses();
	void DepopPlayerCorpse(uint32 dbid);
	void BuryPlayerCorpses();
	int64 GetCorpseCount() { return database.GetCharacterCorpseCount(CharacterID()); }
	uint32 GetCorpseID(int corpse) { return database.GetCharacterCorpseID(CharacterID(), corpse); }
	uint32 GetCorpseItemAt(int corpse_id, int slot_id) {
		if (!corpse_id) {
			return 0;
		}
		return database.GetCharacterCorpseItemAt(corpse_id, slot_id);
	}

	void SuspendMinion(int value);
	void Doppelganger(uint16 spell_id, Mob *target, const char *name_override, int pet_count, int pet_duration);
	void NotifyNewTitlesAvailable();
	void Signal(int signal_id);
	void SendPayload(int payload_id, std::string payload_value = std::string());
	Mob *GetBindSightTarget() { return bind_sight_target; }
	void SetBindSightTarget(Mob *n) { bind_sight_target = n; }
	const uint16 GetBoatID() const { return controlling_boat_id; }
	void SendRewards();
	bool TryReward(uint32 claim_id);
	QGlobalCache *GetQGlobals() { return qGlobals; }
	QGlobalCache *CreateQGlobals() { qGlobals = new QGlobalCache(); return qGlobals; }
	void GuildBankAck();
	void GuildBankDepositAck(bool Fail, int8 action);
	inline bool IsGuildBanker() { return GuildBanker; }
	inline void SetGuildBanker(bool banker) { GuildBanker = banker; }
	void ClearGuildBank();
	void SendGroupCreatePacket();
	void SendGroupLeaderChangePacket(const char *LeaderName);
	void SendGroupJoinAcknowledge();
	void DoTracking();
	inline bool IsTracking() { return (TrackingID > 0); }
	inline void SetPendingGuildInvitation(bool inPendingGuildInvitation) { PendingGuildInvitation = inPendingGuildInvitation; }
	inline bool GetPendingGuildInvitation() { return PendingGuildInvitation; }
	void LocateCorpse();
	void SendTargetCommand(uint32 EntityID);
	bool MoveItemToInventory(EQ::ItemInstance *BInst, bool UpdateClient = false);
	void HandleRespawnFromHover(uint32 Option);
	bool IsHoveringForRespawn() { return RespawnFromHoverTimer.Enabled(); }
	std::list<RespawnOption> respawn_options;
	void AddRespawnOption(std::string option_name, uint32 zoneid, uint16 instance_id, float x, float y, float z, float h = 0, bool initial_selection = false, int8 position = -1);
	bool RemoveRespawnOption(std::string option_name);
	bool RemoveRespawnOption(uint8 position);
	void ClearRespawnOptions() { respawn_options.clear(); }
	void SetPendingRezzData(int XP, uint32 DBID, uint16 SpellID, const char *CorpseName) { PendingRezzXP = XP; PendingRezzDBID = DBID; PendingRezzSpellID = SpellID; PendingRezzCorpseName = CorpseName; }
	bool IsRezzPending() { return PendingRezzSpellID > 0; }
	void ClearHover();
	inline bool IsBlockedBuff(int32 SpellID) { return PlayerBlockedBuffs.find(SpellID) != PlayerBlockedBuffs.end(); }
	inline bool IsBlockedPetBuff(int32 SpellID) { return PetBlockedBuffs.find(SpellID) != PetBlockedBuffs.end(); }
	bool IsDraggingCorpse(uint16 CorpseID);
	inline bool IsDraggingCorpse() { return (DraggedCorpses.size() > 0); }
	void DragCorpses();
	inline void ClearDraggedCorpses() { DraggedCorpses.clear(); }
	void ConsentCorpses(std::string consent_name, bool deny = false);
	void SendAltCurrencies();
	void SetAlternateCurrencyValue(uint32 currency_id, uint32 new_amount);
	int AddAlternateCurrencyValue(uint32 currency_id, int amount, bool is_scripted = false);
	void SendAlternateCurrencyValues();
	void SendAlternateCurrencyValue(uint32 currency_id, bool send_if_null = true);
	uint32 GetAlternateCurrencyValue(uint32 currency_id) const;
	void ProcessAlternateCurrencyQueue();
	void OpenLFGuildWindow();
	void HandleLFGuildResponse(ServerPacket *pack);
	void SendLFGuildStatus();
	void SendGuildLFGuildStatus();
	inline bool XTargettingAvailable() const { return ((m_ClientVersionBit & EQ::versions::maskUFAndLater) && RuleB(Character, EnableXTargetting)); }
	inline uint8 GetMaxXTargets() const { return MaxXTargets; }
	void SetMaxXTargets(uint8 NewMax);
	bool IsXTarget(const Mob *m) const;
	bool IsClientXTarget(const Client *c) const;
	void UpdateClientXTarget(Client *c);
	void UpdateXTargetType(XTargetType Type, Mob *m, const char *Name = nullptr);
	void AddAutoXTarget(Mob *m, bool send = true);
	void RemoveXTarget(Mob *m, bool OnlyAutoSlots);
	void SendXTargetPacket(uint32 Slot, Mob *m);
	void SendXTargetUpdates();
	void RemoveGroupXTargets();
	void RemoveAutoXTargets();
	void ShowXTargets(Client *c);
	inline XTargetAutoHaters *GetXTargetAutoMgr() { return m_activeautohatermgr; } // will be either raid or group or self
	inline void SetXTargetAutoMgr(XTargetAutoHaters *in) { if (in) m_activeautohatermgr = in; else m_activeautohatermgr = &m_autohatermgr; }
	inline void SetDirtyAutoHaters() { m_dirtyautohaters = true; }
	void ProcessXTargetAutoHaters(); // fixes up our auto haters
	void JoinGroupXTargets(Group *g);
	void LeaveGroupXTargets(Group *g);
	void LeaveRaidXTargets(Raid *r);
	void ClearXTargets();
	bool GroupFollow(Client* inviter);
	inline bool  GetRunMode() const { return runmode; }

	virtual bool CheckWaterAutoFireLoS(Mob* m);

	void SendReloadCommandMessages();

	void SendItemRecastTimer(int32 recast_type, uint32 recast_delay = 0, bool in_ignore_casting_requirement = false);
	void SetItemRecastTimer(int32 spell_id, uint32 inventory_slot);
	void DeleteItemRecastTimer(uint32 item_id);
	bool HasItemRecastTimer(int32 spell_id, uint32 inventory_slot);

	inline bool AggroMeterAvailable() const { return ((m_ClientVersionBit & EQ::versions::maskRoF2AndLater)) && RuleB(Character, EnableAggroMeter); } // RoF untested
	inline void SetAggroMeterLock(int in) { m_aggrometer.set_lock_id(in); }

	void ProcessAggroMeter(); // builds packet and sends

	void InitializeMercInfo();
	bool CheckCanSpawnMerc(uint32 template_id);
	bool CheckCanHireMerc(Mob* merchant, uint32 template_id);
	bool CheckCanRetainMerc(uint32 upkeep);
	bool CheckCanUnsuspendMerc();
	bool DismissMerc(uint32 MercID);
	bool MercOnlyOrNoGroup();
	inline uint32 GetMercenaryID() const { return mercid; }
	inline uint8 GetMercSlot() const { return mercSlot; }
	void SetMercID( uint32 newmercid) { mercid = newmercid; }
	void SetMercSlot( uint8 newmercslot) { mercSlot = newmercslot; }
	Merc* GetMerc();
	MercInfo& GetMercInfo(uint8 slot) { return m_mercinfo[slot]; }
	MercInfo& GetMercInfo() { return m_mercinfo[mercSlot]; }
	uint8 GetNumberOfMercenaries();
	void SetMerc(Merc* newmerc);
	void SendMercResponsePackets(uint32 ResponseType);
	void SendMercMerchantResponsePacket(int32 response_type);
	void SendMercenaryUnknownPacket(uint8 type);
	void SendMercenaryUnsuspendPacket(uint8 type);
	void SendMercTimer(Merc* merc = nullptr);
	void SendMercTimerPacket(int32 entity_id, int32 merc_state, int32 suspended_time, int32 update_interval = 900000, int32 unk01 = 180000);
	void SendMercSuspendResponsePacket(uint32 suspended_time);
	void SendMercAssignPacket(uint32 entityID, uint32 unk01, uint32 unk02);
	void SendMercPersonalInfo();
	void SendClearMercInfo();
	void SuspendMercCommand();
	void SpawnMercOnZone();
	void SpawnMerc(Merc* merc, bool setMaxStats);
	void UpdateMercTimer();
	void UpdateMercLevel();
	void CheckMercSuspendTimer();
	Timer* GetMercTimer() { return &merc_timer; };
	Timer* GetPickLockTimer() { return &pick_lock_timer; };

	void SendWebLink(const char* website);
	void SendMarqueeMessage(uint32 type, std::string message, uint32 duration = 3000);
	void SendMarqueeMessage(uint32 type, uint32 priority, uint32 fade_in, uint32 fade_out, uint32 duration, std::string message);
	void SendSpellAnim(uint16 targetid, uint16 spell_id);

	void DuplicateLoreMessage(uint32 ItemID);
	void GarbleMessage(char *, uint8);

	void ItemTimerCheck();
	void TryItemTimer(int slot);
	void SendItemScale(EQ::ItemInstance *inst);

	int32 GetActSTR() { return( std::min(GetMaxSTR(), GetSTR()) ); }
	int32 GetActSTA() { return( std::min(GetMaxSTA(), GetSTA()) ); }
	int32 GetActDEX() { return( std::min(GetMaxDEX(), GetDEX()) ); }
	int32 GetActAGI() { return( std::min(GetMaxAGI(), GetAGI()) ); }
	int32 GetActINT() { return( std::min(GetMaxINT(), GetINT()) ); }
	int32 GetActWIS() { return( std::min(GetMaxWIS(), GetWIS()) ); }
	int32 GetActCHA() { return( std::min(GetMaxCHA(), GetCHA()) ); }
	void LoadAccountFlags();
	void ClearAccountFlag(const std::string& flag);
	void SetAccountFlag(const std::string& flag, const std::string& value);
	std::string GetAccountFlag(const std::string& flag);
	std::vector<std::string> GetAccountFlags();
	void SetGMStatus(int new_status);
	void Consume(const EQ::ItemData *item, uint8 type, int16 slot, bool auto_consume);
	void PlayMP3(const char* fname);
	void ExpeditionSay(const char *str, int ExpID);

	inline int32 GetEnvironmentDamageModifier() const { return environment_damage_modifier; }
	void SetEnvironmentDamageModifier(int32 val) { environment_damage_modifier = val; }
	inline bool GetInvulnerableEnvironmentDamage() const { return invulnerable_environment_damage; }
	void SetInvulnerableEnvironmentDamage(bool val) { invulnerable_environment_damage = val; }
	void SetIntoxication(int32 in_intoxication);

	void ApplyWeaponsStance();
	void TogglePassiveAlternativeAdvancement(const AA::Rank &rank, uint32 ability_id);
	bool UseTogglePassiveHotkey(const AA::Rank &rank);
	void TogglePurchaseAlternativeAdvancementRank(int rank_id);
	void ResetAlternateAdvancementRank(uint32 aa_id);
	bool IsEffectinAlternateAdvancementRankEffects(const AA::Rank &rank, int effect_id);

	void TripInterrogateInvState() { interrogateinv_flag = true; }
	bool GetInterrogateInvState() { return interrogateinv_flag; }

	bool InterrogateInventory(Client* requester, bool log, bool silent, bool allowtrip, bool& error, bool autolog = true);

	void SetNextInvSnapshot(uint32 interval_in_min) {
		m_epp.last_invsnapshot_time = time(nullptr);
		m_epp.next_invsnapshot_time = m_epp.last_invsnapshot_time + (interval_in_min * 60);
	}
	uint32 GetLastInvSnapshotTime() { return m_epp.last_invsnapshot_time; }
	uint32 GetNextInvSnapshotTime() { return m_epp.next_invsnapshot_time; }

	void QuestReward(Mob* target, uint32 copper = 0, uint32 silver = 0, uint32 gold = 0, uint32 platinum = 0, uint32 itemid = 0, uint32 exp = 0, bool faction = false);
	void QuestReward(Mob* target, const QuestReward_Struct &reward, bool faction = false);
	void CashReward(uint32 copper, uint32 silver, uint32 gold, uint32 platinum);
	void RewardFaction(int id, int amount);

	void ResetHPUpdateTimer() { hpupdate_timer.Start(); }

	void SendHPUpdateMarquee();

	void CheckRegionTypeChanges();

	 WaterRegionType GetLastRegion() { return last_region_type; }

	int32 CalcATK();

	uint32 trapid; //ID of trap player has triggered. This is cleared when the player leaves the trap's radius, or it despawns.

	void SetLastPositionBeforeBulkUpdate(glm::vec4 in_last_position_before_bulk_update);
	glm::vec4 &GetLastPositionBeforeBulkUpdate();

	Raid *p_raid_instance;

	void ShowDevToolsMenu();
	CheatManager cheat_manager;

	// rate limit
	Timer m_list_task_timers_rate_limit = {};

	std::string GetGuildPublicNote();

	PlayerEvent::PlayerEvent GetPlayerEvent();
	void RecordKilledNPCEvent(NPC *n);

	uint32 GetEXPForLevel(uint16 check_level);
protected:
	friend class Mob;
	void CalcEdibleBonuses(StatBonuses* newbon);
	void MakeBuffFadePacket(uint16 spell_id, int slot_id, bool send_message = true);
	bool client_data_loaded;


	void FinishAlternateAdvancementPurchase(AA::Rank *rank, bool ignore_cost, bool send_message_and_save);

	Mob* bind_sight_target;

	glm::vec4 m_AutoAttackPosition;
	glm::vec3 m_AutoAttackTargetLocation;
	Mob *aa_los_them_mob;
	bool los_status;
	bool los_status_facing;
	QGlobalCache *qGlobals;

	/** Adventure Variables **/
	Timer *adventure_request_timer;
	Timer *adventure_create_timer;
	Timer *adventure_leave_timer;
	Timer *adventure_door_timer;
	Timer *adventure_stats_timer;
	Timer *adventure_leaderboard_timer;
	int adv_requested_theme;
	int adv_requested_id;
	char *adv_requested_data;
	int adv_requested_member_count;
	char *adv_data;

private:

	eqFilterMode ClientFilters[_FilterCount];
	int32 HandlePacket(const EQApplicationPacket *app);
	void OPTGB(const EQApplicationPacket *app);
	void OPRezzAnswer(uint32 Action, uint32 SpellID, uint16 ZoneID, uint16 InstanceID, float x, float y, float z);
	void OPMemorizeSpell(const EQApplicationPacket *app);
	void OPMoveCoin(const EQApplicationPacket* app);
	void MoveItemCharges(EQ::ItemInstance &from, int16 to_slot, uint8 type);
	void OPGMTraining(const EQApplicationPacket *app);
	void OPGMEndTraining(const EQApplicationPacket *app);
	void OPGMTrainSkill(const EQApplicationPacket *app);
	void OPGMSummon(const EQApplicationPacket *app);
	void OPCombatAbility(const CombatAbility_Struct *ca_atk);

	// Bandolier Methods
	void CreateBandolier(const EQApplicationPacket *app);
	void RemoveBandolier(const EQApplicationPacket *app);
	void SetBandolier(const EQApplicationPacket *app);

	void HandleTraderPriceUpdate(const EQApplicationPacket *app);

	int32 CalcItemATKCap() final;
	int32 CalcHaste();

	int32 CalcAlcoholPhysicalEffect();
	int32 CalcSTR();
	int32 CalcSTA();
	int32 CalcDEX();
	int32 CalcAGI();
	int32 CalcINT();
	int32 CalcWIS();
	int32 CalcCHA();

	int32 CalcMR();
	int32 CalcFR();
	int32 CalcDR();
	int32 CalcPR();
	int32 CalcCR();
	int32 CalcCorrup();
	int64 CalcMaxHP();
	int64 CalcBaseHP();
	int64 CalcHPRegen(bool bCombat = false);
	int64 CalcManaRegen(bool bCombat = false);
	int64 CalcBaseManaRegen();
	void DoHPRegen();
	void DoManaRegen();
	void DoStaminaHungerUpdate();
	void CalcRestState();
	// if they have aggro (AggroCount != 0) their timer is saved in m_pp.RestTimer, else we need to get current timer
	inline uint32 GetRestTimer() const { return AggroCount ? m_pp.RestTimer : rest_timer.GetRemainingTime() / 1000; }
	void UpdateRestTimer(uint32 new_timer);

	uint8 playeraction;

	EQStreamInterface* eqs;

	uint32 ip;
	uint16 port;
	CLIENT_CONN_STATUS client_state;
	uint32 character_id;
	uint32 WID;
	uint32 account_id;
	char account_name[30];
	char loginserver[64];
	uint32 lsaccountid;
	char lskey[30];
	int16 admin;
	uint32 guild_id;
	uint8 guildrank; // player's rank in the guild, 1- Leader 8 Recruit
	bool guild_tribute_opt_in;
	bool guild_dirty{ true };	//used to control add/delete opcodes due to client bug in Ti thru RoF2
	bool GuildBanker;
	uint16 duel_target;
	bool duelaccepted;
	std::list<uint32> keyring;
	bool tellsoff; // GM /toggle
	bool gm_hide_me;
	bool LFG;
	bool LFP;
	uint8 LFGFromLevel;
	uint8 LFGToLevel;
	bool LFGMatchFilter;
	char LFGComments[64];
	bool AFK;
	bool auto_attack;
	bool auto_fire;
	bool runmode;
	uint8 gmspeed;
	bool gminvul;
	bool medding;
	uint16 horseId;
	bool revoked;
	uint16 pClientSideTarget;
	uint32 weight;
	bool berserk;
	bool dead;
	uint16 controlling_boat_id;
	uint16 controlled_mob_id;
	uint16 TrackingID;
	uint16 CustomerID;
	uint16 TraderID;
	uint32 account_creation;
	uint8 firstlogon;
	uint32 mercid; // current merc
	uint8 mercSlot; // selected merc slot
	bool Trader;
	bool Buyer;
	std::string BuyerWelcomeMessage;
	int Haste; //precalced value
	uint32 tmSitting; // time stamp started sitting, used for HP regen bonus added on MAY 5, 2004

	int32 environment_damage_modifier;
	bool invulnerable_environment_damage;

	// dev tools
	bool display_mob_info_window;
	bool dev_tools_enabled;

	uint16 m_door_tool_entity_id;
	uint16 m_object_tool_entity_id;
public:
	uint16 GetDoorToolEntityId() const;
	void SetDoorToolEntityId(uint16 door_tool_entity_id);
	uint16 GetObjectToolEntityId() const;
	void SetObjectToolEntityId(uint16 object_tool_entity_id);
private:

	int32 max_end;
	int32 current_endurance;

	// https://github.com/EQEmu/Server/pull/2479
	bool m_lock_save_position = false;
public:
	bool IsLockSavePosition() const;
	void SetLockSavePosition(bool lock_save_position);
private:

	PlayerProfile_Struct m_pp;
	ExtendedProfile_Struct m_epp;
	EQ::InventoryProfile m_inv;
	Object* m_tradeskill_object;
	PetInfo m_petinfo; // current pet data, used while loading from and saving to DB
	PetInfo m_suspendedminion; // pet data for our suspended minion.
	MercInfo m_mercinfo[MAXMERCS]; // current mercenary
	InspectMessage_Struct m_inspect_message;
	bool temp_pvp;

	void NPCSpawn(const Seperator* sep);

	void SendLogoutPackets();
	void SendZoneInPackets();
	bool AddPacket(const EQApplicationPacket *, bool);
	bool AddPacket(EQApplicationPacket**, bool);
	bool SendAllPackets();
	std::deque<std::unique_ptr<CLIENTPACKET>> clientpackets;

	//Zoning related stuff
	void SendZoneCancel(ZoneChange_Struct *zc);
	void SendZoneError(ZoneChange_Struct *zc, int8 err);
	void DoZoneSuccess(ZoneChange_Struct *zc, uint16 zone_id, uint32 instance_id, float dest_x, float dest_y, float dest_z, float dest_h, int8 ignore_r);
	void ZonePC(uint32 zoneID, uint32 instance_id, float x, float y, float z, float heading, uint8 ignorerestrictions, ZoneMode zm);
	void ProcessMovePC(uint32 zoneID, uint32 instance_id, float x, float y, float z, float heading, uint8 ignorerestrictions = 0, ZoneMode zm = ZoneSolicited);

	glm::vec4 m_ZoneSummonLocation;
	uint16 zonesummon_id;
	uint8 zonesummon_ignorerestrictions;
	ZoneMode zone_mode;

	WaterRegionType last_region_type;

	PTimerList p_timers; //persistent timers
	Timer hpupdate_timer;
	Timer camp_timer;
	Timer process_timer;
	Timer consume_food_timer;
	Timer zoneinpacket_timer;
	Timer linkdead_timer;
	Timer dead_timer;
	Timer global_channel_timer;
	Timer fishing_timer;
	Timer endupkeep_timer;
	Timer autosave_timer;
	Timer client_scan_npc_aggro_timer;
	Timer client_zone_wide_full_position_update_timer;
	Timer tribute_timer;

	Timer proximity_timer;
	Timer TaskPeriodic_Timer;
	Timer charm_update_timer;
	Timer rest_timer;
	Timer charm_class_attacks_timer;
	Timer charm_cast_timer;
	Timer qglobal_purge_timer;
	Timer TrackingTimer;
	Timer RespawnFromHoverTimer;
	Timer merc_timer;
	Timer anon_toggle_timer;
	Timer afk_toggle_timer;
	Timer helm_toggle_timer;
	Timer aggro_meter_timer;
	Timer mob_close_scan_timer;
	Timer position_update_timer; /* Timer used when client hasn't updated within a 10 second window */
	Timer consent_throttle_timer;
	Timer dynamiczone_removal_timer;
	Timer task_request_timer;
	Timer pick_lock_timer;

	Timer heroforge_wearchange_timer;

	glm::vec3 m_Proximity;
	glm::vec4 last_position_before_bulk_update;

	void BulkSendInventoryItems();

	faction_map factionvalues;

	uint32 tribute_master_id;

	bool npcflag;
	uint8 npclevel;
	bool bZoning;
	bool tgb;
	bool instalog;
	int32 last_reported_mana;
	int32 last_reported_endurance;

	int8 last_reported_mana_percent;
	int8 last_reported_endurance_percent;

	uint32 AggroCount; // How many mobs are aggro on us.

	bool ooc_regen;
	float AreaHPRegen;
	float AreaManaRegen;
	float AreaEndRegen;

	std::set<uint32> zone_flags;
	std::set<uint32> peqzone_flags;

	ClientTaskState *task_state;
	int TotalSecondsPlayed;

	// we use this very sparingly at the zone level
	// used for keeping clients in donecount sync before world sends absolute confirmations of state
	int64 m_shared_task_id = 0;
public:
	void SetSharedTaskId(int64 shared_task_id);
	int64 GetSharedTaskId() const;
	struct XTarget_Struct XTargets[XTARGET_HARDCAP];
private:

	bool m_exp_enabled;

	std::vector<EXPModifier> m_exp_modifiers;

	//Anti Spam Stuff
	Timer *KarmaUpdateTimer;
	uint32 TotalKarma;

	Timer *GlobalChatLimiterTimer; //60 seconds
	uint32 AttemptedMessages;

	EQ::versions::ClientVersion m_ClientVersion;
	uint32 m_ClientVersionBit;

	int XPRate;

	bool alternate_currency_loaded;
	std::map<uint32, uint32> alternate_currency;
	std::queue<std::pair<uint32, int32>> alternate_currency_queued_operations;

	//Connecting debug code.
	enum { //connecting states, used for debugging only
			NoPacketsReceived, //havent gotten anything
			//this is the point where the client changes to the loading screen
			ReceivedZoneEntry, //got the first packet, loading up PP
			PlayerProfileLoaded, //our DB work is done, sending it
			ZoneInfoSent, //includes PP, tributes, tasks, spawns, time and weather
			//this is the point where the client shows a status bar zoning in
			NewZoneRequested, //received and sent new zone request
			ClientSpawnRequested, //client sent ReqClientSpawn
			ZoneContentsSent, //objects, doors, zone points
			ClientReadyReceived, //client told us its ready, send them a bunch of crap like guild MOTD, etc
			//this is the point where the client releases the mouse
			ClientConnectFinished //client finally moved to finished state, were done here
	} conn_state;
	void ReportConnectingState();

	uint8 HideCorpseMode;
	bool PendingGuildInvitation;
	int PendingRezzXP;
	uint32 PendingRezzDBID;
	uint16 PendingRezzSpellID; // Only used for resurrect while hovering.
	std::string PendingRezzCorpseName; // Only used for resurrect while hovering.

	std::set<uint32> PlayerBlockedBuffs;
	std::set<uint32> PetBlockedBuffs;
	std::list<std::pair<std::string, uint16> > DraggedCorpses;

	uint8 MaxXTargets;
	bool XTargetAutoAddHaters;
	bool m_dirtyautohaters;

	XTargetAutoHaters m_autohatermgr;
	XTargetAutoHaters *m_activeautohatermgr;

	AggroMeter m_aggrometer;

	Timer ItemQuestTimer;
	std::map<std::string,std::string> accountflags;

	uint8 initial_respawn_selection;

	bool interrogateinv_flag; // used to minimize log spamming by players

	void InterrogateInventory_(bool errorcheck, Client* requester, int16 head, int16 index, const EQ::ItemInstance* inst, const EQ::ItemInstance* parent, bool log, bool silent, bool &error, int depth);
	bool InterrogateInventory_error(int16 head, int16 index, const EQ::ItemInstance* inst, const EQ::ItemInstance* parent, int depth);

	uint8 client_max_level;

	uint32 m_expedition_id = 0;
	ExpeditionInvite m_pending_expedition_invite { 0 };
	std::vector<ExpeditionLockoutTimer> m_expedition_lockouts;
	glm::vec3 m_quest_compass;
	bool m_has_quest_compass = false;
	std::vector<uint32_t> m_dynamic_zone_ids;


public:
	enum BotOwnerOption : size_t {
		booDeathMarquee,
		booStatsUpdate,
		booSpawnMessageSay,
		booSpawnMessageTell,
		booSpawnMessageClassSpecific,
		booUnused,
		booAutoDefend,
		booBuffCounter,
		booMonkWuMessage,
		_booCount
	};

	bool GetBotOption(BotOwnerOption boo) const;
	void SetBotOption(BotOwnerOption boo, bool flag = true);

	bool GetBotPulling() { return m_bot_pulling; }
	void SetBotPulling(bool flag = true) { m_bot_pulling = flag; }

	bool GetBotPrecombat() { return m_bot_precombat; }
	void SetBotPrecombat(bool flag = true) { m_bot_precombat = flag; }

	int GetBotRequiredLevel(uint8 class_id = Class::None);
	uint32 GetBotCreationLimit(uint8 class_id = Class::None);
	int GetBotSpawnLimit(uint8 class_id = Class::None);
	void SetBotCreationLimit(uint32 new_creation_limit, uint8 class_id = Class::None);
	void SetBotRequiredLevel(int new_required_level, uint8 class_id = Class::None);
	void SetBotSpawnLimit(int new_spawn_limit, uint8 class_id = Class::None);

	void CampAllBots(uint8 class_id = Class::None);
	void SpawnRaidBotsOnConnect(Raid* raid);

private:
	bool bot_owner_options[_booCount];
	bool m_bot_pulling;
	bool m_bot_precombat;

	bool CanTradeFVNoDropItem();
	void SendMobPositions();
	void PlayerTradeEventLog(Trade *t, Trade *t2);

	// full and partial mail key cache
	std::string m_mail_key_full;
	std::string m_mail_key;
public:
	const std::string &GetMailKeyFull() const;
	const std::string &GetMailKey() const;
};

#endif

#ifndef CORPSE_H
#define CORPSE_H

#include "mob.h"
#include "client.h"
#include "../common/loot.h"
#include "../common/repositories/character_corpses_repository.h"

class EQApplicationPacket;
class Group;
class NPC;
class Raid;

struct ExtraAttackOptions;
struct NPCType;

namespace EQ {
	class ItemInstance;
}

#define MAX_LOOTERS 72

class Corpse : public Mob {
public:

	static void SendEndLootErrorPacket(Client *client);
	static void SendLootReqErrorPacket(Client *client, LootResponse response = LootResponse::NotAtThisTime);

	Corpse(
		NPC *npc,
		LootItems *item_list,
		uint32 npc_type_id,
		const NPCType **npc_type_data,
		uint32 decay_time = 600000
	);
	Corpse(Client *c, int32 rez_exp, KilledByTypes killed_by = KilledByTypes::Killed_NPC);
	Corpse(
		uint32 corpse_id,
		uint32 character_id,
		const char *character_name,
		LootItems *item_list,
		uint32 copper,
		uint32 silver,
		uint32 gold,
		uint32 platinum,
		const glm::vec4 &position,
		float size,
		uint8 gender,
		uint16 race,
		uint8 class_,
		uint8 deity,
		uint8 level,
		uint8 texture,
		uint8 helm_texture,
		uint32 rez_exp,
		uint32 gm_rez_exp,
		KilledByTypes killed_by,
		bool is_rezzable,
		uint32 rez_remaining_time,
		bool was_at_graveyard = false
	);

	~Corpse();

	/* Corpse: General */
	virtual bool Death(
		Mob *killer_mob,
		int64 damage,
		uint16 spell_id,
		EQ::skills::SkillType attack_skill,
		KilledByTypes killed_by = KilledByTypes::Killed_NPC
	) { return true; }

	virtual void Damage(
		Mob *from,
		int64 damage,
		uint16 spell_id,
		EQ::skills::SkillType attack_skill,
		bool avoidable = true,
		int8 buffslot = -1,
		bool iBuffTic = false,
		eSpecialAttacks special = eSpecialAttacks::None
	) { }

	bool Attack(
		Mob *other, int Hand = EQ::invslot::slotPrimary, bool FromRiposte = false, bool IsStrikethrough = true,
		bool IsFromSpell = false, ExtraAttackOptions *opts = nullptr
	) override
	{
		return false;
	}

	virtual bool HasRaid() { return false; }
	virtual bool HasGroup() { return false; }
	virtual Raid *GetRaid() { return nullptr; }
	virtual Group *GetGroup() { return nullptr; }
	inline uint32 GetCorpseDBID() { return m_corpse_db_id; }
	inline char *GetOwnerName() { return corpse_name; }
	bool IsEmpty() const;
	bool IsCorpse() const { return true; }
	bool IsPlayerCorpse() const { return m_is_player_corpse; }
	bool IsNPCCorpse() const { return !m_is_player_corpse; }
	bool IsBecomeNPCCorpse() const { return m_become_npc; }
	virtual void DepopNPCCorpse();
	virtual void DepopPlayerCorpse();
	bool Process();
	bool Save();

	uint32 GetCharID() { return m_character_id; }

	uint32 SetCharID(uint32 iCharID)
	{
		if (IsPlayerCorpse()) {
			return (m_character_id = iCharID);
		}
		return 0xFFFFFFFF;
	};

	uint32 GetDecayTime()
	{
		if (!m_corpse_decay_timer.Enabled()) {
			return 0xFFFFFFFF;
		}
		else {
			return m_corpse_decay_timer.GetRemainingTime();
		}
	}
	uint32 GetRezTime()
	{
		if (!m_corpse_rezzable_timer.Enabled()) {
			return 0;
		}
		else {
			return m_corpse_rezzable_timer.GetRemainingTime();
		}
	}

	void ResetDecayTimer();
	void SetDecayTimer(uint32 decay_time);
	void SetConsentGroupID(uint32 group_id) { if (IsPlayerCorpse()) { m_consented_group_id = group_id; }}
	void SetConsentRaidID(uint32 raid_id) { if (IsPlayerCorpse()) { m_consented_raid_id = raid_id; }}
	void SetConsentGuildID(uint32 guild_id) { if (IsPlayerCorpse()) { m_consented_guild_id = guild_id; }}
	void AddConsentName(const std::string& consent_player_name);
	void RemoveConsentName(const std::string& consent_player_name);
	void SendWorldSpawnPlayerCorpseInZone(uint32_t zone_id);
	bool MovePlayerCorpseToGraveyard();
	bool MovePlayerCorpseToNonInstance();

	void Delete();
	void Bury();
	void CalcCorpseName();
	void LoadPlayerCorpseDecayTime(uint32 dbid);

	/* Corpse: Items */
	uint32 GetWornItem(int16 equip_slot) const;
	LootItem *GetItem(uint16 lootslot, LootItem **bag_item_data = 0);
	void SetPlayerKillItemID(int32 pk_item_id) { m_player_kill_item = pk_item_id; }
	int32 GetPlayerKillItem() { return m_player_kill_item; }
	void RemoveItem(uint16 lootslot);
	void RemoveItem(LootItem *item_data);
	void RemoveItemByID(uint32 item_id, int quantity = 1);
	void AddItem(
		uint32 itemnum,
		uint16 charges,
		int16 slot = 0,
		uint32 aug1 = 0,
		uint32 aug2 = 0,
		uint32 aug3 = 0,
		uint32 aug4 = 0,
		uint32 aug5 = 0,
		uint32 aug6 = 0,
		bool attuned = false,
		const std::string &custom_data = std::string(),
		uint32 ornamenticon = 0,
		uint32 ornamentidfile = 0,
		uint32 ornament_hero_model = 0
	);

	/* Corpse: Coin */
	void SetCash(uint32 in_copper, uint32 in_silver, uint32 in_gold, uint32 in_platinum);
	void RemoveCash();
	uint32 GetCopper() { return m_copper; }
	uint32 GetSilver() { return m_silver; }
	uint32 GetGold() { return m_gold; }
	uint32 GetPlatinum() { return m_platinum; }

	/* Corpse: Resurrection */
	bool IsRezzed() { return m_rez; }
	void IsRezzed(bool in_rez) { m_rez = in_rez; }
	void CastRezz(uint16 spell_id, Mob *caster);
	void CompleteResurrection(bool timer_expired = false);
	bool IsRezzable() { return m_is_rezzable; }
	void SetRezTimer(bool initial_timer = false);

	/* Corpse: Loot */
	void QueryLoot(Client *to);
	bool HasItem(uint32 item_id);
	uint16 CountItem(uint32 item_id);
	uint32 GetItemIDBySlot(uint16 loot_slot);
	uint16 GetFirstLootSlotByItemID(uint32 item_id);
	std::vector<int> GetLootList();
	void LootCorpseItem(Client *c, const EQApplicationPacket *app);
	void EndLoot(Client *c, const EQApplicationPacket *app);
	void MakeLootRequestPackets(Client *c, const EQApplicationPacket *app);
	void AllowPlayerLoot(Mob *them, uint8 slot);
	void AddLooter(Mob *who);
	uint32 CountItems();
	bool CanPlayerLoot(int character_id);

	inline void Lock() { m_is_locked = true; }
	inline void UnLock() { m_is_locked = false; }
	inline bool IsLocked() { return m_is_locked; }
	inline void ResetLooter()
	{
		m_being_looted_by_entity_id = 0xFFFFFFFF;
		m_loot_request_type         = LootRequestType::Forbidden;
	}
	inline bool IsBeingLooted() { return (m_being_looted_by_entity_id != 0xFFFFFFFF); }
	inline bool IsBeingLootedBy(Client *c) { return m_being_looted_by_entity_id == c->GetID(); }

	/* Mob */
	void FillSpawnStruct(NewSpawn_Struct *ns, Mob *ForWho);
	bool Summon(Client *c, bool spell, bool CheckDistance);
	void Spawn();

	char corpse_name[64];
	uint32 GetEquippedItemFromTextureSlot(uint8 material_slot) const;
	uint32 GetEquipmentColor(uint8 material_slot) const;
	inline int64 GetRezExp() { return m_rezzed_experience; }
	inline int64 GetGMRezExp() { return m_gm_rezzed_experience; }
	uint8 GetKilledBy() { return m_killed_by_type; }
	uint32 GetRemainingRezTime() { return m_remaining_rez_time; }

	virtual void UpdateEquipmentLight();

	void CheckIsOwnerOnline();
	void SetOwnerOnline(bool value) { m_is_owner_online = value; }
	bool GetOwnerOnline() { return m_is_owner_online; }

	static Corpse *LoadCharacterCorpse(
		const CharacterCorpsesRepository::CharacterCorpses &cc,
		const glm::vec4 &position
	);

protected:
	void MoveItemToCorpse(Client *client, EQ::ItemInstance *inst, int16 equipSlot, std::list<uint32> &removedList);

private:
	bool                     m_is_player_corpse;
	bool                     m_is_corpse_changed;
	bool                     m_is_locked;
	int32                    m_player_kill_item;
	uint32                   m_corpse_db_id;
	uint32                   m_character_id;
	uint32                   m_consented_group_id = 0;
	uint32                   m_consented_raid_id  = 0;
	uint32                   m_consented_guild_id = 0;
	LootItems                m_item_list;
	uint32                   m_copper;
	uint32                   m_silver;
	uint32                   m_gold;
	uint32                   m_platinum;
	bool                     m_player_corpse_depop;
	uint32                   m_being_looted_by_entity_id;
	uint64                   m_rezzed_experience;
	uint64                   m_gm_rezzed_experience;
	uint64                   m_gm_exp;
	bool                     m_rez;
	bool                     m_become_npc;
	int                      m_allowed_looters[MAX_LOOTERS];
	Timer                    m_corpse_decay_timer;
	Timer                    m_corpse_rezzable_timer;
	Timer                    m_corpse_delay_timer;
	Timer                    m_corpse_graveyard_timer;
	Timer                    m_loot_cooldown_timer;
	Timer                    m_check_owner_online_timer;
	Timer                    m_check_rezzable_timer;
	uint8                    m_killed_by_type;
	bool                     m_is_rezzable;
	EQ::TintProfile          m_item_tint;
	uint32                   m_remaining_rez_time;
	bool                     m_is_owner_online;
	std::vector<std::string> m_consented_player_names;
	LootRequestType          m_loot_request_type;
	uint32                   m_account_id;
};

#endif

#ifndef DOORS_H
#define DOORS_H

#include "mob.h"
#include "../common/repositories/doors_repository.h"

class Client;
class Mob;
class NPC;
struct Door;

class Doors : public Entity
{
public:
	~Doors();

	Doors(const char *model, const glm::vec4& position, uint8 open_type = 58, uint16 size = 100);
	Doors(const DoorsRepository::Doors& door);

	bool GetDisableTimer() { return m_disable_timer; }
	bool IsDoor() const { return true; }
	bool IsDoorOpen() { return m_is_open; }
	bool Process();
	bool triggered;
	char *GetDoorName() { return m_door_name; }
	const glm::vec4 &GetPosition() const { return m_position; }
	int GetDzSwitchID() const { return m_dz_switch_id; }
	int GetIncline() { return m_incline; }
	int GetInvertState() { return m_invert_state; }
	uint8 GetDoorID() { return m_door_id; }
	uint8 GetNoKeyring() { return m_no_key_ring; }
	uint8 GetOpenType() { return m_open_type; }
	uint8 GetTriggerDoorID() { return m_trigger_door; }
	uint8 GetTriggerType() { return m_trigger_type; }
	uint8 IsLDoNDoor() { return m_is_ldon_door; }
	uint16 GetLockpick() { return m_lockpick; }
	uint16 GetSize() { return m_size; }
	uint32 GetClientVersionMask() { return m_client_version_mask; }
	uint32 GetDoorDBID() { return m_database_id; }
	int32 GetDoorParam() { return m_door_param; }
	uint32 GetEntityID() { return m_entity_id; }
	uint32 GetGuildID() { return m_guild_id; }
	uint32 GetKeyItem() { return m_key_item_id; }
	void CreateDatabaseEntry();
	void ForceClose(Mob *sender, bool alt_mode = false);
	void ForceOpen(Mob *sender, bool alt_mode = false);
	void HandleClick(Client *sender, uint8 trigger);
	void Open(Mob *sender, bool alt_mode = false);
	void SetDisableTimer(bool flag);
	void SetDoorName(const char *name);
	void SetEntityID(uint32 entity) { m_entity_id = entity; }
	void SetIncline(int in);
	void SetInvertState(int in);
	void SetKeyItem(uint32 in) { m_key_item_id = in; }
	void SetLocation(float x, float y, float z);
	void SetLockpick(uint16 in) { m_lockpick = in; }
	void SetNoKeyring(uint8 in) { m_no_key_ring = in; }
	void SetOpenState(bool st) { m_is_open = st; }
	void SetOpenType(uint8 in);
	void SetPosition(const glm::vec4 &position);
	void SetSize(uint16 size);
	void ToggleState(Mob *sender);

	float GetX();
	float GetY();
	float GetZ();
	float GetHeading();

	bool HasDestinationZone() const;
	bool IsDestinationZoneSame() const;

	bool IsDoorBlacklisted();

private:
	bool GetIsDoorBlacklisted();

	bool      m_has_destination_zone = false;
	bool      m_same_destination_zone = false;
	uint32    m_database_id;
	uint8     m_door_id;
	char      m_zone_name[32];
	char      m_door_name[32];
	glm::vec4 m_position;
	int       m_incline;
	uint8     m_open_type;
	uint32    m_guild_id;
	uint16    m_lockpick;
	uint32    m_key_item_id;
	uint8     m_no_key_ring;
	uint8     m_trigger_door;
	uint8     m_trigger_type;
	int32     m_door_param;
	uint16    m_size;
	int       m_invert_state;
	uint32    m_entity_id;
	bool      m_disable_timer;
	bool      m_is_open;
	Timer     m_close_timer;
	char      m_destination_zone_name[16];
	int       m_destination_instance_id;
	glm::vec4 m_destination;
	uint8     m_is_ldon_door;
	int       m_dz_switch_id = 0;
	uint32    m_client_version_mask;
	bool      m_is_blacklisted_to_open = false; // is door blacklisted to open by npcs
};
#endif

/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2016 EQEMu Development Team (http://eqemu.org)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef GROUPS_H
#define GROUPS_H

#include "../common/eq_packet_structs.h"
#include "../common/types.h"

#include "mob.h"
#include "xtargetautohaters.h"

class Client;
class EQApplicationPacket;
class Mob;

#define MAX_MARKED_NPCS 3

enum { RoleAssist = 1, RoleTank = 2, RolePuller = 4 };

class GroupIDConsumer {
public:
	GroupIDConsumer() { id = 0; }
	GroupIDConsumer(uint32 gid) { id = gid; }
	inline const uint32 GetID()	const { return id; }

protected:
	friend class EntityList;
	//use of this function is highly discouraged
	inline void SetID(uint32 set_id) { id = set_id; }
private:
	uint32 id;
};

class Group : public GroupIDConsumer {
public:
	Group(Mob* leader);
	Group(uint32 gid);
	~Group();

	bool	AddMember(Mob* newmember, const char* NewMemberName = nullptr, uint32 CharacterID = 0, bool ismerc = false);
	void	AddMember(const char* NewMemberName);
	void	SendUpdate(uint32 type,Mob* member);
	void	SendLeadershipAAUpdate();
	void	SendWorldGroup(uint32 zone_id,Mob* zoningmember);
	bool	DelMemberOOZ(const char *Name);
	bool	DelMember(Mob* oldmember,bool ignoresender = false);
	void	DisbandGroup(bool joinraid = false);
	void	GetMemberList(std::list<Mob*>& member_list, bool clear_list = true);
	void	GetClientList(std::list<Client*>& client_list, bool clear_list = true);
	void	GetBotList(std::list<Bot*>& bot_list, bool clear_list = true);
	bool	IsGroupMember(Mob* c);
	bool	IsGroupMember(const char* name);
	bool	Process();
	bool	IsGroup()			{ return true; }
	void	SendGroupJoinOOZ(Mob* NewMember);
	void	CastGroupSpell(Mob* caster,uint16 spellid);
	void	SplitExp(const uint64 exp, Mob* other);
	void	GroupMessage(Mob* sender,uint8 language,uint8 lang_skill,const char* message);
	void	GroupMessageString(Mob* sender, uint32 type, uint32 string_id, const char* message,const char* message2=0,const char* message3=0,const char* message4=0,const char* message5=0,const char* message6=0,const char* message7=0,const char* message8=0,const char* message9=0, uint32 distance = 0);
	uint32	GetTotalGroupDamage(Mob* other);
	void	SplitMoney(uint32 copper, uint32 silver, uint32 gold, uint32 platinum, Client *splitter = nullptr);
	inline	void SetLeader(Mob* c){ leader = c; };
	inline	Mob* GetLeader() { return leader; };
	const char*	GetLeaderName() { return GetGroupLeaderName(GetID()).c_str(); };
	void	SendHPManaEndPacketsTo(Mob* newmember);
	void	SendHPPacketsFrom(Mob* member);
	void	SendManaPacketFrom(Mob* member);
	void	SendEndurancePacketFrom(Mob* member);
	bool	UpdatePlayer(Mob* update);
	void	MemberZoned(Mob* removemob);
	bool	IsLeader(const char* name);
	inline bool IsLeader(Mob* m) { return m == leader; };
	uint8	GroupCount();
	uint32	GetHighestLevel();
	uint32	GetLowestLevel();
	void	QueuePacket(const EQApplicationPacket *app, bool ack_req = true);
	void	TeleportGroup(Mob* sender, uint32 zoneID, uint16 instance_id, float x, float y, float z, float heading);
	uint16	GetAvgLevel();
	bool	LearnMembers();
	void	VerifyGroup();
	void	BalanceHP(int32 penalty, float range = 0, Mob* caster = nullptr, int32 limit = 0);
	void	BalanceMana(int32 penalty, float range = 0, Mob* caster = nullptr, int32 limit = 0);
	void	HealGroup(uint32 heal_amt, Mob* caster, float range = 0);
	inline	void SetGroupAAs(GroupLeadershipAA_Struct *From) { memcpy(&LeaderAbilities, From, sizeof(GroupLeadershipAA_Struct)); }
	inline	void GetGroupAAs(GroupLeadershipAA_Struct *Into) { memcpy(Into, &LeaderAbilities, sizeof(GroupLeadershipAA_Struct)); }
	void	UpdateGroupAAs();
	void	SaveGroupLeaderAA();
	void	MarkNPC(Mob* Target, int Number);
	int8	GetNumberNeedingHealedInGroup(int8 hpr, bool includePets);
	void	DelegateMainTank(const char *NewMainAssistName, uint8 toggle = 0);
	void	DelegateMainAssist(const char *NewMainAssistName, uint8 toggle = 0);
	void	DelegatePuller(const char *NewMainAssistName, uint8 toggle = 0);
	void	UnDelegateMainTank(const char *OldMainAssistName, uint8 toggle = 0);
	void	UnDelegateMainAssist(const char *OldMainAssistName, uint8 toggle = 0);
	void	UnDelegatePuller(const char *OldMainAssistName, uint8 toggle = 0);
	bool	IsNPCMarker(Client *c);
	void	SetGroupAssistTarget(Mob *m);
	void	SetGroupTankTarget(Mob *m);
	void	SetGroupPullerTarget(Mob *m);
	bool	HasRole(Mob *m, uint8 Role);
	void	NotifyAssistTarget(Client *c);
	void	NotifyTankTarget(Client *c);
	void	NotifyPullerTarget(Client *c);
	void	DelegateMarkNPC(const char *NewNPCMarkerName);
	void	UnDelegateMarkNPC(const char *OldNPCMarkerName);
	void	NotifyMainTank(Client *c, uint8 toggle = 0);
	void	NotifyMainAssist(Client *c, uint8 toggle = 0);
	void	NotifyPuller(Client *c, uint8 toggle = 0);
	void	NotifyMarkNPC(Client *c);
	inline	uint32 GetNPCMarkerID() { return NPCMarkerID; }
	void	SetMainTank(const char *NewMainTankName);
	void	SetMainAssist(const char *NewMainAssistName);
	void	SetPuller(const char *NewPullerName);
	const char *GetMainTankName() { return MainTankName.c_str(); }
	const char *GetMainAssistName() { return MainAssistName.c_str(); }
	const char *GetPullerName() { return PullerName.c_str(); }
	bool	AmIMainTank(const char *mob_name);
	bool	AmIMainAssist(const char *mob_name);
	bool	AmIPuller(const char *mob_name);
	void	SetNPCMarker(const char *NewNPCMarkerName);
	void	UnMarkNPC(uint16 ID);
	void	SendMarkedNPCsToMember(Client *c, bool Clear = false);
	inline int GetLeadershipAA(int AAID) { return LeaderAbilities.ranks[AAID]; }
	void	ClearAllNPCMarks();
	void	QueueHPPacketsForNPCHealthAA(Mob* sender, const EQApplicationPacket* app);
	void	QueueClients(Mob *sender, const EQApplicationPacket *app, bool ack_required = true, bool ignore_sender = true, float distance = 0);
	void	ChangeLeader(Mob* newleader);
	const char *GetClientNameByIndex(uint8 index);
	void	UpdateXTargetMarkedNPC(uint32 Number, Mob *m);
	void	SetDirtyAutoHaters();
	inline XTargetAutoHaters *GetXTargetAutoMgr() { return &m_autohatermgr; }
	void	JoinRaidXTarget(Raid *raid, bool first = false);

	void SetGroupMentor(int percent, char *name);
	void ClearGroupMentor();
	inline int GetMentorPercent() { return mentor_percent; }
	inline Client *GetMentoree() { return mentoree; }

	bool DoesAnyMemberHaveExpeditionLockout(const std::string& expedition_name, const std::string& event_name, int max_check_count = 0);

	Mob*	members[MAX_GROUP_MEMBERS] {nullptr};
	char	membername[MAX_GROUP_MEMBERS][64] {""};
	uint8	MemberRoles[MAX_GROUP_MEMBERS] {0};
	bool	disbandcheck {false};
	bool	castspell {false};

private:
	Mob*	leader;
	GroupLeadershipAA_Struct LeaderAbilities;
	std::string	MainTankName;
	std::string	MainAssistName;
	std::string	PullerName;
	std::string	NPCMarkerName;
	uint16	NPCMarkerID;
	uint16	AssistTargetID;
	uint16	TankTargetID;
	uint16	PullerTargetID;
	uint16	MarkedNPCs[MAX_MARKED_NPCS];

	std::string mentoree_name;
	Client *mentoree;
	int mentor_percent;

	XTargetAutoHaters m_autohatermgr;

	std::string GetGroupLeaderName(uint32 group_id);
};

#endif

/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2003 EQEMu Development Team (http://eqemulator.net)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef OBJECT_H
#define OBJECT_H

// Object Class:
// Represents Zone Objects (forges, ovens, brew barrels, items dropped to ground, etc)

#include "../common/eq_packet_structs.h"
#include "../common/timer.h"
#include "../common/types.h"

#include "entity.h"

class Client;
class EQApplicationPacket;

namespace EQ
{
	class ItemInstance;
}

/*
item icon numbers (showeq)
IT1_ACTORDEF=Long Sword
IT5_ACTORDEF=Throwing Knife
IT8_ACTORDEF=Basic Staff
IT10_ACTORDEF=Arrow
IT14_ACTORDEF=Basic Hammer
IT16_ACTORDEF=Basic Spear
IT27_ACTORDEF=Book
IT35_ACTORDEF=Mod Rod
IT62_ACTORDEF=Flaming Sword
IT63_ACTORDEF=Small Bag
IT64_ACTORDEF=Large Bag
IT65_ACTORDEF=Scroll
IT66_ACTORDEF=Forge
IT67_ACTORDEF=Voodoo Doll
IT68_ACTORDEF=Glowing Black Stone
IT69_ACTORDEF=Oven
IT70_ACTORDEF=Brew Barrel
IT73_ACTORDEF=Kiln
IT74_ACTORDEF=Pottery Wheel
IT78_ACTORDEF=Campfire (Oven)
IT128_ACTORDEF=Loom
IT177_ACTORDEF=Shattering Hammer
IT203_ACTORDEF=Round Shield
IT210_ACTORDEF=Shimmering Orb
IT400_ACTORDEF=Globe of Slush Water
IT401_ACTORDEF=Red Mushroom
IT402_ACTORDEF=Blue Mushroom
IT403_ACTORDEF=Yew Leaf
IT10511_ACTORDEF=A Soulstone Shard
IT10512_ACTORDEF=Orb of Exploration
IT10630_ACTORDEF=Fish Sword
IT10661_ACTORDEF=Blade of Walnan
IT10714_ACTORDEF=Augmentation Sealer
IT10725_ACTORDEF=Shuriken
*/

// Icon values:
//0x0453 a pie
//0x0454 cookies?
//0x0455 is a piece of meat?
//0x0456 is fletching sticks
//0x0457 looks like a burnt cookie or something :/
//0x0458 is a pottery wheel
//0x0459 is a oven
//0x045A is an oven
//0x045B is a forge
//0x045C is brewing barrel
//0x045D is a hammer
//0x045E is a wierd rope shape

enum ObjectTypes {
	StaticLocked = 0,
	Temporary = 1,
	ToolBox = 10,
	Research = 11,
	Mortar = 12,
	SelfDusting = 13,
	Baking1 = 14,
	Baking2 = 15,
	Tailoring = 16,
	Forge = 17,
	Fletching = 18,
	BrewBarrel = 19,
	Jewelcrafting = 20,
	PotteryWheel = 21,
	PotteryKiln = 22,
	WizardResearch = 24,
	MagicianResearch = 25,
	NecromancerResearch = 26,
	EnchanterResearch = 27,
	Invalid1 = 28,
	Invalid2 = 29,
	Experimental = 30,
	HighElfForge = 31,
	DarkElfForge = 32,
	OgreForge = 33,
	DwarfForge = 34,
	GnomeForge = 35,
	BarbarianForge = 36,
	IksarForge = 38,
	HumanForge = 39,
	HumanForge2 = 40,
	HalflingTailoring = 41,
	EruditeTailoring = 42,
	WoodElfTailoring = 43,
	WoodElfFletching = 44,
	IksarPotteryWheel = 45,
	TrollForge = 47,
	WoodElfForge = 48,
	HalflingForge = 49,
	EruditeForge = 50,
	AugmentationPool = 53,
	StaticUnlocked = 255
};

class Object: public Entity
{
public:
	// Loading object from database
	Object(uint32 id, uint32 type, uint32 icon, const Object_Struct& data, const EQ::ItemInstance* inst = nullptr, bool fix_z = true);
	Object(const EQ::ItemInstance* inst, const std::string& name, float max_x, float min_x, float max_y, float min_y, float z, float heading, uint32 respawn_timer, bool fix_z);
	// Loading object from client dropping item on ground
	Object(Client* client, const EQ::ItemInstance* inst);
	Object(const EQ::ItemInstance *inst, float x, float y, float z, float heading, uint32 decay_time = 300000, bool fix_z = true);
	Object(const std::string& model, float x, float y, float z, float heading, uint8 type, uint32 decay_time = 0);

// Destructor
	~Object();
	bool Process();
	bool IsGroundSpawn() { return m_ground_spawn; }
	// Event handlers
	bool HandleClick(Client* sender, const ClickObject_Struct* click_object);
	void Close();
	void Delete(bool reset_state=false); // Object itself
	static void HandleCombine(Client* user, const NewCombine_Struct* in_combine, Object *worldo);
	static void HandleAugmentation(Client* user, const AugmentItem_Struct* in_augment, Object *worldo);
	static void HandleAutoCombine(Client* user, const RecipeAutoCombine_Struct* rac);

	// Packet functions
	void CreateSpawnPacket(EQApplicationPacket* app);
	void CreateDeSpawnPacket(EQApplicationPacket* app);
	void Depop();
	void Repop();

	// Floating
	inline bool IsFixZEnabled() const { return m_fix_z; };
	inline void SetFixZ(bool fix_z) { m_fix_z = fix_z; };

	//Decay functions
	void StartDecay() {decay_timer.Start();}

	// Container functions
	const EQ::ItemInstance* GetItem(uint8 index);
	void PutItem(uint8 index, const EQ::ItemInstance* inst);
	void DeleteItem(uint8 index); // Item inside container
	EQ::ItemInstance* PopItem(uint8 index); // Pop item out of container

	// Override base class implementations
	virtual bool IsObject()	const { return true; }
	virtual bool Save();
	virtual uint16 VarSave();
	virtual void SetID(uint16 set_id);

	void ClearUser() { user = nullptr; }

	uint32 GetDBID();
	uint32 GetType();
	void SetType(uint32 type);
	uint32 GetIcon();
	void SetIcon(uint32 icon);
	uint32 GetItemID();
	void SetItemID(uint32 itemid);
	void GetObjectData(Object_Struct* Data);
	void SetObjectData(Object_Struct* Data);
	void GetLocation(float* x, float* y, float* z);
	void SetLocation(float x, float y, float z);
	void GetHeading(float* heading);
	void SetHeading(float heading);
	float GetX();
	float GetY();
	float GetZ();
	float GetHeadingData();
	void SetX(float pos);
	void SetY(float pos);
	void SetZ(float pos);
	void SetTiltX(float pos);
	void SetTiltY(float pos);
	float GetTiltX();
	float GetTiltY();
	void SetModelName(const char* modelname);
	const char* GetModelName();
	float GetSize();
	void SetSize(float size);
	uint16 GetSolidType();
	void SetSolidType(uint16 size);
	void SetDisplayName(const char *in_name);
	const char *GetDisplayName() const { return m_display_name; }

	bool ClearEntityVariables();
	bool DeleteEntityVariable(std::string variable_name);
	std::string GetEntityVariable(std::string variable_name);
	std::vector<std::string> GetEntityVariables();
	void SetEntityVariable(std::string variable_name, std::string variable_value);
	bool EntityVariableExists(std::string variable_name);

protected:
	void	ResetState();	// Set state back to original
	void	RandomSpawn(bool send_packet = false);		//spawn this ground spawn at a random place

	Object_Struct m_data;        // Packet data
	EQ::ItemInstance *m_inst;        // Item representing object
	uint32 m_id;        // Database key, different than drop_id
	uint32 m_type;        // Object Type, ie, forge, oven, dropped item, etc (ref: ContainerUseTypes)
	uint32 m_icon;        // Icon to use for forge, oven, etc
	float  m_max_x;
	float  m_max_y;
	float  m_min_x;
	float  m_min_y;
	bool   m_ground_spawn;
	char   m_display_name[64];
	bool   m_fix_z;
protected:

	std::map<std::string, std::string> o_EntityVariables;

	Client *user;
	Client *last_user;

	Timer respawn_timer;
	Timer decay_timer;
	void FixZ();
};

#endif

/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2005 EQEMu Development Team (http://eqemulator.net)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef RAIDS_H
#define RAIDS_H

#include "../common/types.h"
#include "groups.h"
#include "xtargetautohaters.h"
#include "client.h"

class Client;
class EQApplicationPacket;
class Mob;

enum {
	FindNextMarkerSlot     = 1,
	FindNextAssisterSlot   = 2,
	RaidDelegateMainAssist = 3,
	RaidDelegateMainMarker = 4
};

typedef enum {
	MAIN_ASSIST_1_SLOT = 0,
	MAIN_ASSIST_2_SLOT = 1,
	MAIN_ASSIST_3_SLOT = 2,
	MAIN_ASSIST_1 = 1,
	MAIN_ASSIST_2 = 2,
	MAIN_ASSIST_3 = 3,
} MainAssistType;

typedef enum {
	MAIN_MARKER_1_SLOT = 0,
	MAIN_MARKER_2_SLOT = 1,
	MAIN_MARKER_3_SLOT = 2,
	MAIN_MARKER_1 = 1,
	MAIN_MARKER_2 = 2,
	MAIN_MARKER_3 = 3,
} MainMarkerType;

enum {
	ClearDelegate = 1,
	SetDelegate = 0,
	FindNextRaidMainMarkerSlot = 1,
	FindNextRaidMainAssisterSlot = 2,
	DELEGATE_OFF = 0,
	DELEGATE_ON  = 1
};

struct Raid_Marked_NPC {
	uint32	entity_id;
	uint32	zone_id;
	uint32	instance_id;
};


constexpr uint8_t MAX_RAID_GROUPS = 12;
constexpr uint8_t MAX_RAID_MEMBERS = 72;
const uint32 RAID_GROUPLESS = 0xFFFFFFFF;
#define MAX_NO_RAID_MAIN_ASSISTERS 3
#define MAX_NO_RAID_MAIN_MARKERS 3

struct RaidMember{
	char member_name[64]{ 0 };
	Client* member{ nullptr };
	uint32 group_number{ RAID_GROUPLESS };
	uint8 _class{ 0 };
	uint8 level{ 0 };
	std::string note{};
	bool is_group_leader{ false };
	bool is_raid_leader{ false };
	bool is_looter{ false };
	uint8 main_marker{ 0 };
	uint8 main_assister{ 0 };
	bool is_bot{ false };
	bool is_raid_main_assist_one{false};
};

struct GroupMentor {
	std::string name;
	Client *mentoree;
	int mentor_percent;
};

class Raid : public GroupIDConsumer {
public:
	Raid(Client *nLeader);
	Raid(uint32 raidID);
	~Raid();

	void SetLeader(Client* c) { leader = c; }
	Client* GetLeader() { return leader; }
	std::string GetLeaderName() { return leadername; }
	bool IsLeader(Client* c) { return c == leader; }
	bool IsLeader(const char* name) { return !strcmp(leadername, name); }
	void SetRaidLeader(const char *wasLead, const char *name);

	bool	Process();

	void	AddMember(Client *c, uint32 group = 0xFFFFFFFF, bool rleader=false, bool groupleader=false, bool looter=false);
	void	AddBot(Bot* b, uint32 group = 0xFFFFFFFF, bool raid_leader=false, bool group_leader=false, bool looter=false);
	void	RaidGroupSay(const char* msg, const char* from, uint8 language, uint8 lang_skill);
	void	RaidSay(const char* msg, const char* from, uint8 language, uint8 lang_skill);
	bool	IsEngaged();
	Mob*	GetRaidMainAssistOne();
	void	RemoveMember(const char *character_name);
	void	DisbandRaid();
	void	MoveMember(const char *name, uint32 newGroup);
	void	SetGroupLeader(const char *who, bool glFlag = true);
	Client	*GetGroupLeader(uint32 group_id);
	void	RemoveGroupLeader(const char *who);
	bool	IsGroupLeader(const char* name);
	bool	IsGroupLeader(Client *c);
	bool	IsRaidMember(const char* name);
	bool	IsRaidMember(Client *c);
	void	UpdateLevel(const char *name, int newLevel);
	void	SetNewRaidLeader(uint32 i);
	bool    IsAssister(const char* who);
	bool    IsMarker(const char* who);
	void    EmptyRaidMembers();

	uint32	GetFreeGroup();
	uint8	GroupCount(uint32 gid);
	uint8	RaidCount();
	uint32	GetHighestLevel();
	uint32	GetLowestLevel();
	uint32	GetGroup(const char *name);
	uint32	GetGroup(Client *c);
	uint16	GetAvgLevel();

	uint32	GetLootType() { return LootType; }
	void	ChangeLootType(uint32 type);
	void	AddRaidLooter(const char* looter);
	void	RemoveRaidLooter(const char* looter);

	inline void	SetRaidMOTD(const std::string& in_motd) { motd = in_motd; };

	//util func
	//keeps me from having to keep iterating through the list
	//when I want lots of data from the same entry
	uint32	GetPlayerIndex(const char *name);
	uint32	GetPlayerIndex(Client *c);
	//for perl interface
	Client *GetClientByIndex(uint16 index);
	const char *GetClientNameByIndex(uint8 index);

	void	LockRaid(bool lockFlag);
	bool	IsLocked() { return locked; }

	//Actual Implementation Stuff

	void	RaidMessageString(Mob* sender, uint32 type, uint32 string_id, const char* message,const char* message2=0,const char* message3=0,const char* message4=0,const char* message5=0,const char* message6=0,const char* message7=0,const char* message8=0,const char* message9=0, uint32 distance = 0);
	void	CastGroupSpell(Mob* caster,uint16 spellid, uint32 gid);
	void	SplitExp(const uint64 exp, Mob* other);
	uint32	GetTotalRaidDamage(Mob* other);
	void	BalanceHP(int32 penalty, uint32 gid, float range = 0, Mob* caster = nullptr, int32 limit = 0);
	void	BalanceMana(int32 penalty, uint32 gid,  float range = 0, Mob* caster = nullptr, int32 limit = 0);
	void	HealGroup(uint32 heal_amt, Mob* caster, uint32 gid, float range = 0);
	void	SplitMoney(uint32 gid, uint32 copper, uint32 silver, uint32 gold, uint32 platinum, Client *splitter = nullptr);

	void	TeleportGroup(Mob* sender, uint32 zoneID, uint16 instance_id, float x, float y, float z, float heading, uint32 gid);
	void	TeleportRaid(Mob* sender, uint32 zoneID, uint16 instance_id, float x, float y, float z, float heading);

	//updates the list of Client* objects based on who's in and not in the zone.
	//also learns raid structure based on db.
	void	SetRaidDetails();
	void	GetRaidDetails();
	void	SaveRaidMOTD();
	bool	LearnMembers();
	void	VerifyRaid();
	void	MemberZoned(Client *c);
	void	SendHPManaEndPacketsTo(Client *c);
	void	SendHPManaEndPacketsFrom(Mob *mob);
	void	SendManaPacketFrom(Mob *mob);
	void	SendEndurancePacketFrom(Mob *mob);
	void	RaidSay(const char *msg, Client *c, uint8 language, uint8 lang_skill);
	void	RaidGroupSay(const char *msg, Client *c, uint8 language, uint8 lang_skill);
	void    SaveRaidNote(std::string who, std::string note);
	std::vector<RaidMember> GetMembersWithNotes();
	void	DelegateAbilityAssist(Mob* mob, const char* who);
	void	DelegateAbilityMark(Mob* mob, const char* who);
	void    RaidMarkNPC(Mob* mob, uint32 parameter);
	void    UpdateXTargetType(XTargetType Type, Mob* m, const char* name = (const char*)nullptr);
	int     FindNextRaidDelegateSlot(int option);
	void    UpdateXtargetMarkedNPC();
	void    RaidClearNPCMarks(Client* c);
	void    RemoveRaidDelegates(const char* delegatee);
	void	UpdateRaidXTargets();

	//Packet Functions
	void	SendRaidCreate(Client *to);
	void	SendRaidAdd(const char *who, Client *to);
	void	SendRaidAddAll(const char *who);
	void	SendRaidRemove(const char *who, Client *to);
	void	SendRaidRemoveAll(const char *who);
	void	SendRaidDisband(Client *to);
	void	SendRaidDisbandAll();
	void	SendRaidMove(const char* who, Client *to);
	void	SendRaidMoveAll(const char* who);
	void	SendBulkRaid(Client *to);
	void    SendRaidNotes();
	void    SendRaidNotesToWorld();
	void    SendRemoveRaidXTargets(XTargetType Type);
	void    SendRemoveAllRaidXTargets();
	void    SendRemoveAllRaidXTargets(const char* client_name);
	void    SendRaidAssistTarget();
	void    SendAssistTarget(Client* c);
	void	GroupUpdate(uint32 gid, bool initial = true);
	void	SendGroupUpdate(Client *to);
	void	SendGroupDisband(Client *to);
	void	SendRaidLock();
	void	SendRaidUnlock();
	void	SendRaidLockTo(Client *c);
	void	SendRaidUnlockTo(Client *c);
	void	SendRaidGroupAdd(const char *who, uint32 gid);
	void	SendRaidGroupRemove(const char *who, uint32 gid);
	void	SendMakeLeaderPacket(const char *who); //30
	void	SendMakeLeaderPacketTo(const char *who, Client *to);
	void	SendMakeGroupLeaderPacketAll();
	void	SendMakeGroupLeaderPacket(const char *who); //13
	void	SendMakeGroupLeaderPacketTo(const char *who, Client *to);
	void	SendRaidMOTD(Client *c);
	void	SendRaidMOTD();
	void	SendRaidMOTDToWorld();
	void    SendRaidAssisterTo(const char* assister, Client* to);
	void    SendRaidAssister(const char* assister);
	void    SendRaidMarkerTo(const char* marker, Client* to);
	void    SendRaidMarker(const char* marker);
	void    SendMarkTargets(Client* c);

	void	QueuePacket(const EQApplicationPacket *app, bool ack_req = true);

	// Leadership
	void	UpdateGroupAAs(uint32 gid);
	void	SaveGroupLeaderAA(uint32 gid);
	void	UpdateRaidAAs();
	void	SaveRaidLeaderAA();
	void	SendGroupLeadershipAA(Client *c, uint32 gid);
	void	SendGroupLeadershipAA(uint32 gid);
	void	SendAllRaidLeadershipAA();
	void	LoadLeadership();
	inline int GetLeadershipAA(int AAID, uint32 gid = 0)
		{ if (AAID >= 16) return raid_aa.ranks[AAID - 16]; else return group_aa[gid].ranks[AAID]; }
	inline void SetGroupAAs(uint32 gid, GroupLeadershipAA_Struct *glaa)
		{ memcpy(&group_aa[gid], glaa, sizeof(GroupLeadershipAA_Struct)); }
	inline void SetRaidAAs(RaidLeadershipAA_Struct *rlaa)
		{ memcpy(&raid_aa, rlaa, sizeof(RaidLeadershipAA_Struct)); }

	void	SetGroupMentor(uint32 group_id, int percent, char *name);
	void	ClearGroupMentor(uint32 group_id);
	void	CheckGroupMentor(uint32 group_id, Client *c); // this just checks if we should be fixing the pointer in group mentor struct on zone
	inline int GetMentorPercent(uint32 group_id) { return group_mentor[group_id].mentor_percent; }
	inline Client *GetMentoree(uint32 group_id) { return group_mentor[group_id].mentoree; }

	void SetDirtyAutoHaters();
	inline XTargetAutoHaters *GetXTargetAutoMgr() { return &m_autohatermgr; }

	void	QueueClients(Mob *sender, const EQApplicationPacket *app, bool ack_required = true, bool ignore_sender = true, float distance = 0, bool group_only = true);

	bool DoesAnyMemberHaveExpeditionLockout(const std::string& expedition_name, const std::string& event_name, int max_check_count = 0);

	std::vector<RaidMember> GetMembers() const;
	std::vector<RaidMember> GetRaidGroupMembers(uint32 gid);
	std::vector<Bot*> GetRaidGroupBotMembers(uint32 gid);
	std::vector<Bot*> GetRaidBotMembers(uint32 owner = 0);
	void HandleBotGroupDisband(uint32 owner, uint32 gid = RAID_GROUPLESS);
	void HandleOfflineBots(uint32 owner);

	RaidMember members[MAX_RAID_MEMBERS];
	char leadername[64];
	char main_assister_pcs[MAX_NO_RAID_MAIN_ASSISTERS][64];
	char main_marker_pcs[MAX_NO_RAID_MAIN_MARKERS][64];
	Raid_Marked_NPC	marked_npcs[MAX_MARKED_NPCS];
protected:
	Client *leader;
	bool locked;
	uint32 LootType;
	bool disbandCheck;
	bool forceDisband;
	std::string motd;
	RaidLeadershipAA_Struct raid_aa;
	GroupLeadershipAA_Struct group_aa[MAX_RAID_GROUPS];

	GroupMentor group_mentor[MAX_RAID_GROUPS];

	XTargetAutoHaters m_autohatermgr;
};


#endif


/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2004 EQEMu Development Team (http://eqemulator.net)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef _TRAP_H
#define _TRAP_H

#include "entity.h"

class Mob;
class NPC;

//ID of the NPC type to spawn when a trap is set off, to do the damage
#define TRAP_NPC_TYPE 1586

enum TrapTypes
{
	trapTypeDebuff = 0,
	trapTypeAlarm = 1,
	trapTypeMysticSpawn = 2,
	trapTypeBanditSpawn = 3,
	trapTypeDamage = 4,
};

class Trap: public Entity
{
public:
	Trap();
	virtual ~Trap();
	virtual bool Process();
	virtual bool IsTrap() const { return true; }
	void	Trigger(Mob* trigger);

	void	SpellOnTarget(Mob* trigger, uint32 spell_id);

	NPC * GetHiddenTrigger() { return hiddenTrigger; }
	void SetHiddenTrigger(NPC* n) { hiddenTrigger = n; }
	void CreateHiddenTrigger();
	void DestroyHiddenTrigger() { hiddenTrigger = nullptr; }
	void UpdateTrap(bool respawn = true, bool repopnow = false);
	//Trap data, leave this unprotected
	Timer	respawn_timer; //Respawn Time when Trap's been disarmed
	Timer	chkarea_timer;
	Timer	reset_timer; //How long a trap takes to reset before triggering again.
	uint32	trap_id; //Original ID of the trap from DB. This value never changes.
	uint32	db_id; //The DB ID of the trap that currently is spawned.
	glm::vec3 m_Position;
	float	maxzdiff;	//maximum z diff to be triggerable
	float	radius;		//radius around trap to be triggerable
	uint8	chance;		//%chance that the trap is triggered each 'tick'
	uint8	effect; //Effect ID
	int32	effectvalue; //Value of Effect
	int32	effectvalue2; //Value of Effect
	uint8	skill; //Skill to detect/disarm with rogue.
	uint8	level;
	bool	detected;
	bool	disarmed;
	uint32	respawn_time;
	uint32	respawn_var;
	uint8	triggered_number;
	uint8	times_triggered;
	uint8	group;
	bool	despawn_when_triggered;
	uint32  charid; //ID of character that triggered trap. This is cleared when the trap despawns are resets.
	bool	undetectable;

	std::string message;
protected:
	NPC *hiddenTrigger;
};

#endif


