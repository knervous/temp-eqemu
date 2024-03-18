/** NodeQuest API definitions **/

export default NodeQuest

export declare module NodeQuest {
  class RegisteredPointer {
    delete(): void;
  }
  class Owned<T> extends RegisteredPointer {}
  class NodeQuestVector<T, U> extends RegisteredPointer {
    /**
     * Always call delete on registered pointers when finished.
     */
    constructor(size?: number);
    get(index: number): T;
    set(index: number, el :T): boolean;
    size(): number;
    push_back(el: T): void;
    resize(sise: number): void;
    toJS(): U;
  }

  class ByteVector extends NodeQuestVector<any, Uint8Array> {}
  class CharVector extends NodeQuestVector<any, string> {}
  class IntVector extends NodeQuestVector<number, Int32Array> {}
  class DoubleVector extends NodeQuestVector<number, Float64Array> {}

  type EnumInstance<T> = { get values(): { [V in T[keyof T]]: { get value(): V } } } & { [P in keyof T]: { get value(): T[P] } }
  export class EnumPtr<T> extends RegisteredPointer {
    /**
     * Always call delete on registered pointers when finished.
     */
    constructor(param?: T);
    get() : { get value(): T[keyof T] };
  }

  export interface SmartPtr<T> extends RegisteredPointer {
    get() : T;
  }

  /** Enums and Enum Class Wrappers **/
  const focusTypeEnum = {
    focusSpellHaste: 1,
    focusSpellDuration: 2,
    focusRange: 3,
    focusReagentCost: 4,
    focusManaCost: 5,
    focusImprovedHeal: 6,
    focusImprovedDamage: 7,
    focusImprovedDamage2: 8,
    focusFcDamagePctCrit: 9,
    focusPetPower: 10,
    focusResistRate: 11,
    focusSpellHateMod: 12,
    focusTriggerOnCast: 13,
    focusSpellVulnerability: 14,
    focusFcSpellDamagePctIncomingPC: 15,
    focusTwincast: 16,
    focusSympatheticProc: 17,
    focusFcDamageAmt: 18,
    focusFcDamageAmt2: 19,
    focusFcDamageAmtCrit: 20,
    focusSpellDurByTic: 21,
    focusSwarmPetDuration: 22,
    focusReduceRecastTime: 23,
    focusBlockNextSpell: 24,
    focusFcHealPctIncoming: 25,
    focusFcDamageAmtIncoming: 26,
    focusFcSpellDamageAmtIncomingPC: 27,
    focusFcCastSpellOnLand: 28,
    focusFcHealAmtIncoming: 29,
    focusFcBaseEffects: 30,
    focusIncreaseNumHits: 31,
    focusFcLimitUse: 32,
    focusFcMute: 33,
    focusFcTimerRefresh: 34,
    focusFcTimerLockout: 35,
    focusFcStunTimeMod: 36,
    focusFcResistIncoming: 37,
    focusFcAmplifyMod: 38,
    focusFcAmplifyAmt: 39,
    focusFcCastTimeMod2: 40,
    focusFcCastTimeAmt: 41,
    focusFcHealPctCritIncoming: 42,
    focusFcHealAmt: 43,
    focusFcHealAmtCrit: 44
  } as const;
  export const focusType: EnumInstance<typeof focusTypeEnum>;
  export class focusTypePtr extends EnumPtr<typeof focusTypeEnum> {}

  const FearStateEnum = {
    fearStateNotFeared: 0,
    fearStateRunning: 1,
    fearStateRunningForever: 2,
    fearStateGrid: 3,
    fearStateStuck: 4
  } as const;
  export const FearState: EnumInstance<typeof FearStateEnum>;
  export class FearStatePtr extends EnumPtr<typeof FearStateEnum> {}

  const GravityBehaviorEnum = {
    Ground: 0,
    Flying: 1,
    Levitating: 2,
    Water: 3,
    Floating: 4,
    LevitateWhileRunning: 5
  } as const;
  export const GravityBehavior: EnumInstance<typeof GravityBehaviorEnum>;
  export class GravityBehaviorPtr extends EnumPtr<typeof GravityBehaviorEnum> {}

  const TradeStateEnum = {
    TradeNone: 0,
    Trading: 1,
    TradeAccepted: 2,
    TradeCompleting: 3
  } as const;
  export const TradeState: EnumInstance<typeof TradeStateEnum>;
  export class TradeStatePtr extends EnumPtr<typeof TradeStateEnum> {}

  const NumHitEnum = {
    IncomingHitAttempts: 1,
    OutgoingHitAttempts: 2,
    IncomingSpells: 3,
    OutgoingSpells: 4,
    OutgoingHitSuccess: 5,
    IncomingHitSuccess: 6,
    MatchingSpells: 7,
    IncomingDamage: 8,
    ReflectSpell: 9,
    DefensiveSpellProcs: 10,
    OffensiveSpellProcs: 11
  } as const;
  export const NumHit: EnumInstance<typeof NumHitEnum>;
  export class NumHitPtr extends EnumPtr<typeof NumHitEnum> {}

  const PlayerStateEnum = {
    None: 0,
    Open: 1,
    WeaponSheathed: 2,
    Aggressive: 4,
    ForcedAggressive: 8,
    InstrumentEquipped: 16,
    Stunned: 32,
    PrimaryWeaponEquipped: 64,
    SecondaryWeaponEquipped: 128
  } as const;
  export const PlayerState: EnumInstance<typeof PlayerStateEnum>;
  export class PlayerStatePtr extends EnumPtr<typeof PlayerStateEnum> {}

  const LootResponseEnum = {
    SomeoneElse: 0,
    Normal: 1,
    NotAtThisTime: 2,
    Normal2: 3,
    Hostiles: 4,
    TooFar: 5,
    LootAll: 6
  } as const;
  export const LootResponse: EnumInstance<typeof LootResponseEnum>;
  export class LootResponsePtr extends EnumPtr<typeof LootResponseEnum> {}

  const LootRequestTypeEnum = {
    Forbidden: 0,
    GMPeek: 1,
    GMAllowed: 2,
    Self: 3,
    AllowedPVE: 4,
    AllowedPVPAll: 5,
    AllowedPVPSingle: 6,
    AllowedPVPDefined: 7
  } as const;
  export const LootRequestType: EnumInstance<typeof LootRequestTypeEnum>;
  export class LootRequestTypePtr extends EnumPtr<typeof LootRequestTypeEnum> {}

  const KilledByTypesEnum = {
    Killed_NPC: 0,
    Killed_DUEL: 1,
    Killed_PVP: 2
  } as const;
  export const KilledByTypes: EnumInstance<typeof KilledByTypesEnum>;
  export class KilledByTypesPtr extends EnumPtr<typeof KilledByTypesEnum> {}

  const SpeakModeEnum = {
    Raw: 0,
    Say: 1,
    Shout: 2,
    EmoteAlt: 3,
    Emote: 4,
    Group: 5
  } as const;
  export const SpeakMode: EnumInstance<typeof SpeakModeEnum>;
  export class SpeakModePtr extends EnumPtr<typeof SpeakModeEnum> {}

  const ModeEnum = {
    None: 0,
    Log1: 1,
    Log2: 2
  } as const;
  export const Mode: EnumInstance<typeof ModeEnum>;
  export class ModePtr extends EnumPtr<typeof ModeEnum> {}

  const PetTypeEnum = {
    petFamiliar: 0,
    petAnimation: 1,
    petOther: 2,
    petCharmed: 3,
    petNPCFollow: 4,
    petTargetLock: 5,
    petNone: 255
  } as const;
  export const PetType: EnumInstance<typeof PetTypeEnum>;
  export class PetTypePtr extends EnumPtr<typeof PetTypeEnum> {}

  const CastAction_typeEnum = {
    SingleTarget: 0,
    AETarget: 1,
    AECaster: 2,
    GroupSpell: 3,
    CAHateList: 4,
    DirectionalAE: 5,
    Beam: 6,
    TargetRing: 7,
    CastActUnknown: 8
  } as const;
  export const CastAction_type: EnumInstance<typeof CastAction_typeEnum>;
  export class CastAction_typePtr extends EnumPtr<typeof CastAction_typeEnum> {}

  const eSpecialAttacksEnum = {
    None: 0,
    Rampage: 1,
    AERampage: 2,
    ChaoticStab: 3
  } as const;
  export const eSpecialAttacks: EnumInstance<typeof eSpecialAttacksEnum>;
  export class eSpecialAttacksPtr extends EnumPtr<typeof eSpecialAttacksEnum> {}

  const WaterRegionTypeEnum = {

  } as const;
  export const WaterRegionType: EnumInstance<typeof WaterRegionTypeEnum>;
  export class WaterRegionTypePtr extends EnumPtr<typeof WaterRegionTypeEnum> {}

  const ZoneModeEnum = {
    ZoneToSafeCoords: 0,
    GMSummon: 1,
    GMHiddenSummon: 2,
    ZoneToBindPoint: 3,
    ZoneSolicited: 4,
    ZoneUnsolicited: 5,
    GateToBindPoint: 6,
    SummonPC: 7,
    Rewind: 8,
    EvacToSafeCoords: 9
  } as const;
  export const ZoneMode: EnumInstance<typeof ZoneModeEnum>;
  export class ZoneModePtr extends EnumPtr<typeof ZoneModeEnum> {}

  const ShowSpellTypeEnum = {
    Disciplines: 0,
    Spells: 1
  } as const;
  export const ShowSpellType: EnumInstance<typeof ShowSpellTypeEnum>;
  export class ShowSpellTypePtr extends EnumPtr<typeof ShowSpellTypeEnum> {}

  const XTargetTypeEnum = {
    Empty: 0,
    Auto: 1,
    CurrentTargetPC: 2,
    CurrentTargetNPC: 3,
    TargetsTarget: 4,
    GroupTank: 5,
    GroupTankTarget: 6,
    GroupAssist: 7,
    GroupAssistTarget: 8,
    Puller: 9,
    PullerTarget: 10,
    GroupMarkTarget1: 11,
    GroupMarkTarget2: 12,
    GroupMarkTarget3: 13,
    RaidAssist1: 14,
    RaidAssist2: 15,
    RaidAssist3: 16,
    RaidAssist1Target: 17,
    RaidAssist2Target: 18,
    RaidAssist3Target: 19,
    RaidMarkTarget1: 20,
    RaidMarkTarget2: 21,
    RaidMarkTarget3: 22,
    MyPet: 23,
    MyPetTarget: 24,
    MyMercenary: 25,
    MyMercenaryTarget: 26
  } as const;
  export const XTargetType: EnumInstance<typeof XTargetTypeEnum>;
  export class XTargetTypePtr extends EnumPtr<typeof XTargetTypeEnum> {}

  const eInnateSkillEnum = {
    InnateEnabled: 0,
    InnateAwareness: 1,
    InnateBashDoor: 2,
    InnateBreathFire: 3,
    InnateHarmony: 4,
    InnateInfravision: 6,
    InnateLore: 8,
    InnateNoBash: 9,
    InnateRegen: 10,
    InnateSlam: 11,
    InnateSurprise: 12,
    InnateUltraVision: 13,
    InnateInspect: 14,
    InnateOpen: 15,
    InnateReveal: 16,
    InnateSkillMax: 25,
    InnateDisabled: 255
  } as const;
  export const eInnateSkill: EnumInstance<typeof eInnateSkillEnum>;
  export class eInnateSkillPtr extends EnumPtr<typeof eInnateSkillEnum> {}

  const ObjectTypesEnum = {
    StaticLocked: 0,
    Temporary: 1,
    ToolBox: 10,
    Research: 11,
    Mortar: 12,
    SelfDusting: 13,
    Baking1: 14,
    Baking2: 15,
    Tailoring: 16,
    Forge: 17,
    Fletching: 18,
    BrewBarrel: 19,
    Jewelcrafting: 20,
    PotteryWheel: 21,
    PotteryKiln: 22,
    WizardResearch: 24,
    MagicianResearch: 25,
    NecromancerResearch: 26,
    EnchanterResearch: 27,
    Invalid1: 28,
    Invalid2: 29,
    Experimental: 30,
    HighElfForge: 31,
    DarkElfForge: 32,
    OgreForge: 33,
    DwarfForge: 34,
    GnomeForge: 35,
    BarbarianForge: 36,
    IksarForge: 38,
    HumanForge: 39,
    HumanForge2: 40,
    HalflingTailoring: 41,
    EruditeTailoring: 42,
    WoodElfTailoring: 43,
    WoodElfFletching: 44,
    IksarPotteryWheel: 45,
    TrollForge: 47,
    WoodElfForge: 48,
    HalflingForge: 49,
    EruditeForge: 50,
    AugmentationPool: 53,
    StaticUnlocked: 255
  } as const;
  export const ObjectTypes: EnumInstance<typeof ObjectTypesEnum>;
  export class ObjectTypesPtr extends EnumPtr<typeof ObjectTypesEnum> {}

  const MainAssistTypeEnum = {
    MAIN_ASSIST_1_SLOT: 0,
    MAIN_ASSIST_2_SLOT: 1,
    MAIN_ASSIST_3_SLOT: 2,
    MAIN_ASSIST_1: 1,
    MAIN_ASSIST_2: 2,
    MAIN_ASSIST_3: 3
  } as const;
  export const MainAssistType: EnumInstance<typeof MainAssistTypeEnum>;
  export class MainAssistTypePtr extends EnumPtr<typeof MainAssistTypeEnum> {}

  const MainMarkerTypeEnum = {
    MAIN_MARKER_1_SLOT: 0,
    MAIN_MARKER_2_SLOT: 1,
    MAIN_MARKER_3_SLOT: 2,
    MAIN_MARKER_1: 1,
    MAIN_MARKER_2: 2,
    MAIN_MARKER_3: 3
  } as const;
  export const MainMarkerType: EnumInstance<typeof MainMarkerTypeEnum>;
  export class MainMarkerTypePtr extends EnumPtr<typeof MainMarkerTypeEnum> {}

  const TrapTypesEnum = {
    trapTypeDebuff: 0,
    trapTypeAlarm: 1,
    trapTypeMysticSpawn: 2,
    trapTypeBanditSpawn: 3,
    trapTypeDamage: 4
  } as const;
  export const TrapTypes: EnumInstance<typeof TrapTypesEnum>;
  export class TrapTypesPtr extends EnumPtr<typeof TrapTypesEnum> {}

  /** Structs **/
  export interface DaysHoursMinutes {
    days: string,
    hours: string,
    mins: string
  }

  export interface Options {
    speak_mode: SpeakMode,
    journal_mode: Mode,
    language: number,
    message_type: number,
    target_spawn_id: number
  }

  export interface Buffs_Struct {
    spellid: number,
    casterlevel: number,
    casterid: number,
    caster_name: number,
    ticsremaining: number,
    counters: number,
    hit_number: number,
    melee_rune: number,
    magic_rune: number,
    dot_rune: number,
    caston_x: number,
    caston_y: number,
    caston_z: number,
    ExtraDIChance: number,
    RootBreakChance: number,
    instrument_mod: number,
    virus_spread_time: number,
    persistant_buff: boolean,
    client: boolean,
    UpdateClient: boolean
  }

  export interface StatBonuses {
    AC: number,
    HP: number,
    HPRegen: number,
    MaxHP: number,
    ManaRegen: number,
    EnduranceRegen: number,
    Mana: number,
    Endurance: number,
    ATK: number,
    STR: number,
    STRCapMod: number,
    HeroicSTR: number,
    STA: number,
    STACapMod: number,
    HeroicSTA: number,
    DEX: number,
    DEXCapMod: number,
    HeroicDEX: number,
    AGI: number,
    AGICapMod: number,
    HeroicAGI: number,
    INT: number,
    INTCapMod: number,
    HeroicINT: number,
    WIS: number,
    WISCapMod: number,
    HeroicWIS: number,
    CHA: number,
    CHACapMod: number,
    HeroicCHA: number,
    MR: number,
    MRCapMod: number,
    HeroicMR: number,
    FR: number,
    FRCapMod: number,
    HeroicFR: number,
    CR: number,
    CRCapMod: number,
    HeroicCR: number,
    PR: number,
    PRCapMod: number,
    HeroicPR: number,
    DR: number,
    DRCapMod: number,
    HeroicDR: number,
    Corrup: number,
    CorrupCapMod: number,
    HeroicCorrup: number,
    DamageShieldSpellID: number,
    DamageShield: number,
    DamageShieldType: DmgShieldType,
    SpellDamageShield: number,
    SpellShield: number,
    ReverseDamageShield: number,
    ReverseDamageShieldSpellID: number,
    ReverseDamageShieldType: DmgShieldType,
    movementspeed: number,
    haste: number,
    hastetype2: number,
    hastetype3: number,
    inhibitmelee: number,
    AggroRange: float,
    AssistRange: float,
    skillmod: number,
    skillmodmax: number,
    effective_casting_level: number,
    adjusted_casting_skill: number,
    reflect: number,
    singingMod: number,
    Amplification: number,
    brassMod: number,
    percussionMod: number,
    windMod: number,
    stringedMod: number,
    songModCap: number,
    hatemod: number,
    EnduranceReduction: number,
    StrikeThrough: number,
    MeleeMitigation: number,
    MeleeMitigationEffect: number,
    CriticalHitChance: number,
    CriticalSpellChance: number,
    SpellCritDmgIncrease: number,
    SpellCritDmgIncNoStack: number,
    DotCritDmgIncrease: number,
    CriticalHealChance: number,
    CriticalHealOverTime: number,
    CriticalDoTChance: number,
    CrippBlowChance: number,
    AvoidMeleeChance: number,
    AvoidMeleeChanceEffect: number,
    RiposteChance: number,
    DodgeChance: number,
    ParryChance: number,
    DualWieldChance: number,
    DoubleAttackChance: number,
    TripleAttackChance: number,
    DoubleRangedAttack: number,
    ResistSpellChance: number,
    ResistFearChance: number,
    Fearless: boolean,
    IsFeared: boolean,
    IsBlind: boolean,
    StunResist: number,
    MeleeSkillCheck: number,
    MeleeSkillCheckSkill: number,
    HitChance: number,
    HitChanceEffect: number,
    DamageModifier: number,
    DamageModifier2: number,
    DamageModifier3: number,
    MinDamageModifier: number,
    ProcChance: number,
    ProcChanceSPA: number,
    ExtraAttackChance: number,
    ExtraAttackChancePrimary: number,
    ExtraAttackChanceSecondary: number,
    DoubleMeleeRound: number,
    DoTShielding: number,
    DivineSaveChance: number,
    DeathSave: number,
    FlurryChance: number,
    Accuracy: number,
    HundredHands: number,
    MeleeLifetap: number,
    Vampirism: number,
    HealRate: number,
    MaxHPChange: number,
    SkillDmgTaken: number,
    HealAmt: number,
    SpellDmg: number,
    Clairvoyance: number,
    DSMitigation: number,
    DSMitigationOffHand: number,
    SpellTriggers: number,
    SpellOnKill: number,
    SpellOnDeath: number,
    CritDmgMod: number,
    CritDmgModNoStack: number,
    SkillReuseTime: number,
    SkillDamageAmount: number,
    TwoHandBluntBlock: number,
    ItemManaRegenCap: number,
    GravityEffect: number,
    AntiGate: boolean,
    MagicWeapon: boolean,
    IncreaseBlockChance: number,
    PersistantCasting: number,
    XPRateMod: number,
    HPPercCap: number,
    ManaPercCap: number,
    EndPercCap: number,
    ImmuneToFlee: boolean,
    VoiceGraft: number,
    SpellProcChance: number,
    CharmBreakChance: number,
    SongRange: number,
    HPToManaConvert: number,
    FocusEffects: number,
    FocusEffectsWorn: number,
    NegateEffects: boolean,
    SkillDamageAmount2: number,
    NegateAttacks: number,
    MitigateMeleeRune: number,
    MeleeThresholdGuard: number,
    SpellThresholdGuard: number,
    MitigateSpellRune: number,
    MitigateDotRune: number,
    TriggerMeleeThreshold: boolean,
    TriggerSpellThreshold: boolean,
    ManaAbsorbPercentDamage: number,
    EnduranceAbsorbPercentDamage: number,
    ShieldBlock: number,
    BlockBehind: number,
    CriticalRegenDecay: boolean,
    CriticalHealDecay: boolean,
    CriticalDotDecay: boolean,
    DivineAura: boolean,
    DistanceRemoval: boolean,
    ImprovedTaunt: number,
    Root: number,
    FrenziedDevastation: number,
    AbsorbMagicAtt: number,
    MeleeRune: number,
    NegateIfCombat: boolean,
    Screech: number,
    AlterNPCLevel: number,
    AStacker: number,
    BStacker: number,
    CStacker: number,
    DStacker: number,
    BerserkSPA: boolean,
    Metabolism: number,
    Sanctuary: boolean,
    FactionModPct: number,
    LimitToSkill: boolean,
    SkillProc: number,
    SkillProcSuccess: number,
    SpellProc: number,
    RangedProc: number,
    DefensiveProc: number,
    Proc_Timer_Modifier: boolean,
    PC_Pet_Rampage: number,
    PC_Pet_AE_Rampage: number,
    PC_Pet_Flurry: number,
    Attack_Accuracy_Max_Percent: number,
    AC_Mitigation_Max_Percent: number,
    AC_Avoidance_Max_Percent: number,
    Damage_Taken_Position_Mod: number,
    Melee_Damage_Position_Mod: number,
    Damage_Taken_Position_Amt: number,
    Melee_Damage_Position_Amt: number,
    Double_Backstab_Front: number,
    DS_Mitigation_Amount: number,
    DS_Mitigation_Percentage: number,
    Pet_Crit_Melee_Damage_Pct_Owner: number,
    Pet_Add_Atk: number,
    ItemEnduranceRegenCap: number,
    WeaponStance: number,
    ZoneSuspendMinion: boolean,
    CompleteHealBuffBlocker: boolean,
    Illusion: number,
    invisibility: number,
    invisibility_verse_undead: number,
    invisibility_verse_animal: number,
    TrapCircumvention: number,
    SecondaryForte: number,
    ShieldDuration: number,
    ExtendedShielding: number,
    Packrat: number,
    BuffSlotIncrease: number,
    DelayDeath: number,
    BaseMovementSpeed: number,
    IncreaseRunSpeedCap: number,
    DoubleSpecialAttack: number,
    SkillAttackProc: number,
    HasSkillAttackProc: boolean,
    FrontalStunResist: number,
    BindWound: number,
    MaxBindWound: number,
    ChannelChanceSpells: number,
    ChannelChanceItems: number,
    SeeInvis: number,
    TripleBackstab: number,
    FrontalBackstabMinDmg: boolean,
    FrontalBackstabChance: number,
    ConsumeProjectile: number,
    ForageAdditionalItems: number,
    SalvageChance: number,
    ArcheryDamageModifier: number,
    SecondaryDmgInc: boolean,
    GiveDoubleAttack: number,
    SlayUndead: number,
    PetCriticalHit: number,
    PetAvoidance: number,
    CombatStability: number,
    DoubleRiposte: number,
    GiveDoubleRiposte: number,
    RaiseSkillCap: number,
    Ambidexterity: number,
    PetMaxHP: number,
    PetFlurry: number,
    MasteryofPast: number,
    GivePetGroupTarget: boolean,
    RootBreakChance: number,
    UnfailingDivinity: number,
    ItemHPRegenCap: number,
    SEResist: number,
    OffhandRiposteFail: number,
    ItemATKCap: number,
    FinishingBlow: number,
    FinishingBlowLvl: number,
    ShieldEquipDmgMod: number,
    TriggerOnCastRequirement: boolean,
    StunBashChance: number,
    IncreaseChanceMemwipe: number,
    CriticalMend: number,
    ImprovedReclaimEnergy: number,
    HeadShot: number,
    HSLevel: number,
    Assassinate: number,
    AssassinateLevel: number,
    PetMeleeMitigation: number,
    IllusionPersistence: number,
    extra_xtargets: number,
    ShroudofStealth: boolean,
    ReduceFallDamage: number,
    ReduceTradeskillFail: number,
    TradeSkillMastery: number,
    NoBreakAESneak: number,
    FeignedCastOnChance: number,
    PetCommands: boolean,
    FeignedMinionChance: number,
    GrantForage: number,
    aura_slots: number,
    trap_slots: number,
    hunger: boolean,
    heroic_max_hp: number,
    heroic_max_mana: number,
    heroic_max_end: number,
    heroic_hp_regen: number,
    heroic_mana_regen: number,
    heroic_end_regen: number,
    heroic_str_shield_ac: number,
    heroic_str_melee_damage: number,
    heroic_agi_avoidance: number,
    heroic_dex_ranged_damage: number
  }

  export interface tProc {
    spellID: number,
    chance: number,
    base_spellID: number,
    level_override: number,
    proc_reuse_time: number
  }

  export interface WeaponStance_Struct {
    enabled: boolean,
    spellbonus_enabled: boolean,
    itembonus_enabled: boolean,
    aabonus_enabled: boolean,
    spellbonus_buff_spell_id: number,
    itembonus_buff_spell_id: number,
    aabonus_buff_spell_id: number
  }

  export interface tProjatk {
    increment: number,
    hit_increment: number,
    target_id: number,
    wpn_dmg: number,
    origin_x: float,
    origin_y: float,
    origin_z: float,
    tlast_x: float,
    tlast_y: float,
    ranged_id: number,
    ammo_id: number,
    ammo_slot: number,
    skill: number,
    speed_mod: float,
    disable_procs: boolean
  }

  export interface MercType {
    Type: number,
    ClientVersion: number
  }

  export interface MercData {
    MercTemplateID: number,
    MercType: number,
    MercSubType: number,
    CostFormula: number,
    ClientVersion: number,
    NPCID: number
  }

  export interface ExtraAttackOptions {
    damage_percent: float,
    damage_flat: number,
    armor_pen_percent: float,
    armor_pen_flat: number,
    crit_percent: float,
    crit_flat: float,
    hate_percent: float,
    hate_flat: number,
    hit_chance: number,
    melee_damage_bonus_flat: number,
    skilldmgtaken_bonus_flat: number,
    range_percent: number
  }

  export interface DamageTable {
    max_extra: number,
    chance: number,
    minusfactor: number
  }

  export interface DamageHitInfo {
    base_damage: number,
    min_damage: number,
    damage_done: number,
    offense: number,
    tohit: number,
    hand: number,
    skill: SkillType
  }

  export interface ExpeditionInvite {
    expedition_id: number,
    inviter_name: string,
    swap_remove_name: string
  }

  export interface DataBucketCache {
    bucket_id: number,
    bucket_key: string,
    bucket_value: string,
    bucket_expires: number
  }

  export interface Area {
    id: number,
    type: number,
    min_x: float,
    max_x: float,
    min_y: float,
    max_y: float,
    min_z: float,
    max_z: float
  }

  export interface AppearanceStruct {
    aa_title: number,
    beard: number,
    beard_color: number,
    drakkin_details: number,
    drakkin_heritage: number,
    drakkin_tattoo: number,
    eye_color_one: number,
    eye_color_two: number,
    face: number,
    gender_id: number,
    hair: number,
    hair_color: number,
    helmet_texture: number,
    race_id: number,
    send_effects: boolean,
    size: float,
    target: Client ,
    texture: number
  }

  export interface SpecialAbility {
    level: number,
    timer: Timer ,
    params: number
  }

  export interface AuraInfo {
    name: number,
    spawn_id: number,
    icon: number,
    aura: Aura 
  }

  export interface AuraMgr {
    count: number,
    auras: AuraInfo
  }

  export interface NPCProximity {
    min_x: float,
    max_x: float,
    min_y: float,
    max_y: float,
    min_z: float,
    max_z: float,
    say: boolean,
    proximity_set: boolean
  }

  export interface AISpells_Struct {
    type: number,
    spellid: number,
    manacost: number,
    time_cancast: number,
    recast_delay: number,
    priority: number,
    resist_adjust: number,
    min_hp: number,
    max_hp: number
  }

  export interface AISpellsEffects_Struct {
    spelleffectid: number,
    base_value: number,
    limit: number,
    max_value: number
  }

  export interface AISpellsVar_Struct {
    fail_recast: number,
    engaged_no_sp_recast_min: number,
    engaged_no_sp_recast_max: number,
    engaged_beneficial_self_chance: number,
    engaged_beneficial_other_chance: number,
    engaged_detrimental_chance: number,
    pursue_no_sp_recast_min: number,
    pursue_no_sp_recast_max: number,
    pursue_detrimental_chance: number,
    idle_no_sp_recast_min: number,
    idle_no_sp_recast_max: number,
    idle_beneficial_chance: number
  }

  export interface Roambox {
    max_x: float,
    max_y: float,
    min_x: float,
    min_y: float,
    distance: float,
    dest_x: float,
    dest_y: float,
    dest_z: float,
    delay: number,
    min_delay: number
  }

  export interface EXPModifier {
    aa_modifier: float,
    exp_modifier: float
  }

  export interface ZonePoint {
    x: float,
    y: float,
    z: float,
    heading: float,
    number: number,
    target_x: float,
    target_y: float,
    target_z: float,
    target_heading: float,
    target_zone_id: number,
    target_zone_instance: number,
    client_version_mask: number,
    is_virtual: boolean,
    height: number,
    width: number
  }

  export interface ZoneClientAuth_Struct {
    ip: number,
    wid: number,
    accid: number,
    admin: number,
    charid: number,
    lsid: number,
    tellsoff: boolean,
    charname: number,
    lskey: number,
    stale: boolean
  }

  export interface ZoneEXPModInfo {
    ExpMod: float,
    AAExpMod: float
  }

  export interface XTarget_Struct {
    Type: XTargetType,
    dirty: boolean,
    ID: number,
    Name: number
  }

  export interface RespawnOption {
    name: string,
    zone_id: number,
    instance_id: number,
    x: float,
    y: float,
    z: float,
    heading: float
  }

  export interface ClientReward {
    id: number,
    amount: number
  }

  export interface Raid_Marked_NPC {
    entity_id: number,
    zone_id: number,
    instance_id: number
  }

  export interface RaidMember {

  }

  export interface GroupMentor {
    name: string,
    mentoree: Client ,
    mentor_percent: number
  }

  /** Class Interfaces **/
  export class ExpeditionLockoutTimer {
    constructor();;
  constructor(expedition_uuid: string, expedition_name: string, event_name: string, expire_time: number, duration: number);
  
    CreateLockout(expedition_name: string , event_name: string , seconds: number, uuid: string): ExpeditionLockoutTimer;
    AddLockoutTime(seconds: number): void;
    GetDuration(): number;
    GetExpireTime(): number;
    GetStartTime(): number;
    GetSecondsRemaining(): number;
    GetDaysHoursMinutesRemaining(): DaysHoursMinutes;
    GetExpeditionName(): string ;
    GetExpeditionUUID(): string ;
    GetEventName(): string ;
    IsExpired(): boolean;
    IsFromExpedition(uuid: string ): boolean;
    IsReplayTimer(): boolean;
    IsSameLockout(compare_lockout: ExpeditionLockoutTimer ): boolean;
    IsSameLockout(expedition_name: string , event_name: string ): boolean;
    Reset(): void;
    SetDuration(seconds: number): void;
    SetExpireTime(expire_time: number): void;
    SetUUID(uuid: string ): void
  }

  export class Trade {
    constructor(in_owner: Mob );;
  constructor();
      state : TradeState;
    pp : number;
    gp : number;
    sp : number;
    cp : number;
    Reset(): void;
    Start(mob_id: number, initiate_with: boolean): void;
    With(): Mob ;
    AddEntity(trade_slot_id: number, stack_size: number): void;
    GetOwner(): Mob ;
    SendItemData(inst: ItemInstance , dest_slot_id: number): void
  }

  export class Entity {
    constructor();;
  constructor();
  
    IsClient(): boolean;
    IsNPC(): boolean;
    IsMob(): boolean;
    IsMerc(): boolean;
    IsCorpse(): boolean;
    IsPlayerCorpse(): boolean;
    IsNPCCorpse(): boolean;
    IsObject(): boolean;
    IsDoor(): boolean;
    IsTrap(): boolean;
    IsBeacon(): boolean;
    IsEncounter(): boolean;
    IsBot(): boolean;
    IsAura(): boolean;
    IsOfClientBot(): boolean;
    IsOfClientBotMerc(): boolean;
    Process(): boolean;
    Save(): boolean;
    Depop(StartSpawnTimer: boolean): void;
    CastToClient(): Client ;
    CastToNPC(): NPC ;
    CastToMob(): Mob ;
    CastToMerc(): Merc ;
    CastToCorpse(): Corpse ;
    CastToObject(): Object ;
    CastToDoors(): Doors ;
    CastToTrap(): Trap ;
    CastToBeacon(): Beacon ;
    CastToEncounter(): Encounter ;
    CastToClient(): Client ;
    CastToNPC(): NPC ;
    CastToMob(): Mob ;
    CastToMerc(): Merc ;
    CastToCorpse(): Corpse ;
    CastToObject(): Object ;
    CastToDoors(): Doors ;
    CastToTrap(): Trap ;
    CastToBeacon(): Beacon ;
    CastToEncounter(): Encounter ;
    GetInitialId(): number;
    GetID(): number;
    GetSpawnTimeStamp(): time_t ;
    GetName(): char ;
    CastToBot(): Bot ;
    CastToBot(): Bot ;
    SetID(set_id: number): void
  }

  export class EntityList {
    constructor();;
  constructor();
  
    GetID(id: number): Entity ;
    GetMob(id: number): Mob ;
    GetMobID(id: number): Mob ;
    GetMob(name: char ): Mob ;
    GetMobByNpcTypeID(get_id: number): Mob ;
    IsMobSpawnedByNpcTypeID(get_id: number): boolean;
    IsNPCSpawned(npc_ids: number): boolean;
    CountSpawnedNPCs(npc_ids: number): number;
    GetNPCByID(id: number): NPC ;
    GetNPCByNPCTypeID(npc_id: number): NPC ;
    GetNPCBySpawnID(spawn_id: number): NPC ;
    GetMercByID(id: number): Merc ;
    GetClientByName(name: char ): Client ;
    GetClientByAccID(accid: number): Client ;
    GetClientByID(id: number): Client ;
    GetClientByCharID(iCharID: number): Client ;
    GetClientByWID(iWID: number): Client ;
    GetClientByLSID(iLSID: number): Client ;
    GetRandomBot(location: vec3 , distance: float, exclude_bot: Bot ): Bot ;
    GetRandomClient(location: vec3 , distance: float, exclude_client: Client ): Client ;
    GetRandomNPC(location: vec3 , distance: float, exclude_npc: NPC ): NPC ;
    GetRandomMob(location: vec3 , distance: float, exclude_mob: Mob ): Mob ;
    GetGroupByMob(mob: Mob ): Group ;
    GetGroupByMobName(name: char ): Group ;
    IsInSameGroupOrRaidGroup(client1: Client , client2: Client ): boolean;
    GetGroupByClient(client: Client ): Group ;
    GetGroupByID(id: number): Group ;
    GetGroupByLeaderName(leader: char ): Group ;
    GetRaidByClient(client: Client ): Raid ;
    GetRaidByID(id: number): Raid ;
    GetRaidByBotName(name: char ): Raid ;
    GetRaidByBot(bot: Bot ): Raid ;
    GetRaidByName(name: char ): Raid ;
    GetCorpseByOwner(client: Client ): Corpse ;
    GetCorpseByOwnerWithinRange(client: Client , center: Mob , range: number): Corpse ;
    GetCorpseByID(id: number): Corpse ;
    GetCorpseByDBID(dbid: number): Corpse ;
    GetCorpseByName(name: char ): Corpse ;
    GetSpawnByID(id: number): Spawn2 ;
    FindCorpseDragger(CorpseID: number): Client ;
    GetObjectByID(id: number): Object ;
    GetObjectByDBID(id: number): Object ;
    GetDoorsByID(id: number): Doors ;
    GetDoorsByDoorID(id: number): Doors ;
    GetDoorsByDBID(id: number): Doors ;
    RemoveAllCorpsesByCharID(charid: number): void;
    RemoveCorpseByDBID(dbid: number): void;
    RezzAllCorpsesByCharID(charid: number): number;
    DespawnGridNodes(grid_id: number): void;
    IsMobInZone(who: Mob ): boolean;
    ClearClientPetitionQueue(): void;
    CanAddHateForMob(p: Mob ): boolean;
    SendGuildMOTD(guild_id: number): void;
    SendGuildChannel(guild_id: number): void;
    SendGuildURL(guild_id: number): void;
    SendGuildSpawnAppearance(guild_id: number): void;
    SendGuildMembers(guild_id: number): void;
    SendGuildMembersList(guild_id: number): void;
    SendGuildMemberAdd(guild_id: number, level: number, _class: number, rank: number, spirit: number, zone_id: number, player_name: string): void;
    SendGuildMemberRename(guild_id: number, player_name: string, new_player_name: string): void;
    SendGuildMemberRemove(guild_id: number, player_name: string): void;
    SendGuildMemberLevel(guild_id: number, level: number, player_name: string): void;
    SendGuildMemberRankAltBanker(guild_id: number, rank: number, player_name: string, alt: boolean, banker: boolean): void;
    SendGuildMemberPublicNote(guild_id: number, player_name: string, public_note: string): void;
    SendGuildMemberDetails(guild_id: number, zone_id: number, offline_mode: number, player_name: string): void;
    SendGuildRenameGuild(guild_id: number, new_guild_name: string): void;
    RefreshAllGuildInfo(guild_id: number): void;
    SendGuildList(): void;
    GuildSetPreRoFBankerFlag(guild_id: number, guild_rank: number, banker_status: boolean): void;
    CheckGroupList(fname: char , fline: number): void;
    GroupProcess(): void;
    RaidProcess(): void;
    DoorProcess(): void;
    ObjectProcess(): void;
    CorpseProcess(): void;
    MobProcess(): void;
    TrapProcess(): void;
    BeaconProcess(): void;
    EncounterProcess(): void;
    ProcessMove(c: Client , location: vec3 ): void;
    ProcessMove(n: NPC , x: float, y: float, z: float): void;
    AddArea(id: number, type: number, min_x: float, max_x: float, min_y: float, max_y: float, min_z: float, max_z: float): void;
    RemoveArea(id: number): void;
    ClearAreas(): void;
    ReloadMerchants(): void;
    ProcessProximitySay(message: char , c: Client , language: number): void;
    FindDoor(door_id: number): Doors ;
    FindObject(object_id: number): Object ;
    FindNearbyObject(x: float, y: float, z: float, radius: float): Object ;
    MakeDoorSpawnPacket(app: EQApplicationPacket , client: Client ): boolean;
    MakeTrackPacket(client: Client ): boolean;
    SendTraders(client: Client ): void;
    AddClient(arg0: Client ): void;
    AddNPC(arg0: NPC , send_spawn_packet: boolean, dont_queue: boolean): void;
    AddMerc(arg0: Merc , SendSpawnPacket: boolean, dontqueue: boolean): void;
    AddCorpse(pc: Corpse , in_id: number): void;
    AddObject(arg0: Object , SendSpawnPacket: boolean): void;
    AddGroup(arg0: Group ): void;
    AddGroup(arg0: Group , id: number): void;
    AddRaid(raid: Raid ): void;
    AddRaid(arg0: Raid , id: number): void;
    AddDoor(door: Doors ): void;
    AddTrap(trap: Trap ): void;
    AddBeacon(beacon: Beacon ): void;
    AddEncounter(encounter: Encounter ): void;
    AddProximity(proximity_for: NPC ): void;
    Clear(): void;
    RemoveMob(delete_id: number): boolean;
    RemoveClient(delete_id: number): boolean;
    RemoveClient(delete_client: Client ): boolean;
    RemoveNPC(delete_id: number): boolean;
    RemoveMerc(delete_id: number): boolean;
    RemoveGroup(delete_id: number): boolean;
    RemoveCorpse(delete_id: number): boolean;
    RemoveDoor(delete_id: number): boolean;
    RemoveTrap(delete_id: number): boolean;
    RemoveObject(delete_id: number): boolean;
    RemoveProximity(delete_npc_id: number): boolean;
    RemoveMobFromCloseLists(mob: Mob ): boolean;
    RemoveAuraFromMobs(aura: Mob ): void;
    RemoveAllMobs(): void;
    RemoveAllClients(): void;
    RemoveAllNPCs(): void;
    RemoveAllBots(): void;
    RemoveAllMercs(): void;
    RemoveAllGroups(): void;
    RemoveAllCorpses(): void;
    RemoveAllDoors(): void;
    DespawnAllDoors(): void;
    RespawnAllDoors(): void;
    RemoveAllTraps(): void;
    RemoveAllObjects(): void;
    RemoveAllLocalities(): void;
    RemoveAllRaids(): void;
    RemoveAllEncounters(): void;
    DestroyTempPets(owner: Mob ): void;
    AddTempPetsToHateList(owner: Mob , other: Mob , bFrenzy: boolean): void;
    AddTempPetsToHateListOnOwnerDamage(owner: Mob , attacker: Mob , spell_id: number): void;
    GetEntityMob(id: number): Entity ;
    GetEntityMerc(id: number): Entity ;
    GetEntityDoor(id: number): Entity ;
    GetEntityObject(id: number): Entity ;
    GetEntityCorpse(id: number): Entity ;
    GetEntityTrap(id: number): Entity ;
    GetEntityBeacon(id: number): Entity ;
    GetEntityEncounter(id: number): Entity ;
    GetEntityMob(name: char ): Entity ;
    GetEntityCorpse(name: char ): Entity ;
    StopMobAI(): void;
    DescribeAggro(to_who: Client , from_who: NPC , dist: float, verbose: boolean): void;
    GetFilteredEntityList(sender: Mob , distance: number, filter_type: EntityFilterType): vector<Mob  >;
    DamageArea(sender: Mob , damage: number, distance: number, filter_type: EntityFilterType, is_percentage: boolean): void;
    Marquee(type: number, message: string, duration: number): void;
    Marquee(type: number, priority: number, fade_in: number, fade_out: number, duration: number, message: string): void;
    Message(to_guilddbid: number, type: number, message: char ): void;
    MessageStatus(to_guilddbid: number, to_minstatus: number, type: number, message: char ): void;
    MessageClose(sender: Mob , skipsender: boolean, dist: float, type: number, message: char ): void;
    FilteredMessageClose(sender: Mob , skipsender: boolean, dist: float, type: number, filter: eqFilterType, message: char ): void;
    MessageString(sender: Mob , skipsender: boolean, type: number, string_id: number, message1: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    FilteredMessageString(sender: Mob , skipsender: boolean, type: number, filter: eqFilterType, string_id: number, message1: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    MessageCloseString(sender: Mob , skipsender: boolean, dist: float, type: number, string_id: number, message1: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    FilteredMessageCloseString(sender: Mob , skipsender: boolean, dist: float, type: number, filter: eqFilterType, string_id: number, skip: Mob , message1: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    ChannelMessageFromWorld(from: char , to: char , chan_num: number, guilddbid: number, language: number, lang_skill: number, message: char ): void;
    ChannelMessage(from: Mob , chan_num: number, language: number, message: char ): void;
    ChannelMessage(from: Mob , chan_num: number, language: number, lang_skill: number, message: char ): void;
    SendZoneSpawns(arg0: Client ): void;
    SendZonePVPUpdates(arg0: Client ): void;
    SendZoneSpawnsBulk(client: Client ): void;
    Save(): void;
    SendZoneCorpses(arg0: Client ): void;
    SendZoneCorpsesBulk(arg0: Client ): void;
    SendZoneObjects(client: Client ): void;
    SendZoneAppearance(c: Client ): void;
    SendNimbusEffects(c: Client ): void;
    SendUntargetable(c: Client ): void;
    SendAppearanceEffects(c: Client ): void;
    SendIllusionWearChange(c: Client ): void;
    DuelMessage(winner: Mob , loser: Mob , flee: boolean): void;
    QuestJournalledSayClose(sender: Mob , dist: float, mobname: char , message: char , opts: Options ): void;
    GroupMessage(gid: number, from: char , message: char ): void;
    ExpeditionWarning(minutes_left: number): void;
    UpdateGuildTributes(guild_id: number): void;
    RemoveFromTargets(mob: Mob , RemoveFromXTargets: boolean): void;
    RemoveFromTargetsFadingMemories(spell_target: Mob , RemoveFromXTargets: boolean, max_level: number): void;
    RemoveFromXTargets(mob: Mob ): void;
    RemoveFromAutoXTargets(mob: Mob ): void;
    ReplaceWithTarget(pOldMob: Mob , pNewTarget: Mob ): void;
    QueueCloseClients(sender: Mob , app: EQApplicationPacket , ignore_sender: boolean, distance: float, skipped_mob: Mob , is_ack_required: boolean, filter: eqFilterType): void;
    QueueClients(sender: Mob , app: EQApplicationPacket , ignore_sender: boolean, ackreq: boolean): void;
    QueueClientsStatus(sender: Mob , app: EQApplicationPacket , ignore_sender: boolean, minstatus: number, maxstatus: number): void;
    QueueClientsGuild(app: EQApplicationPacket , guildeqid: number): void;
    QueueClientsGuildBankItemUpdate(gbius: GuildBankItemUpdate_Struct , GuildID: number): void;
    QueueClientsByTarget(sender: Mob , app: EQApplicationPacket , iSendToSender: boolean, SkipThisMob: Mob , ackreq: boolean, HoTT: boolean, ClientVersionBits: number, inspect_buffs: boolean, clear_target_window: boolean): void;
    QueueClientsByXTarget(sender: Mob , app: EQApplicationPacket , iSendToSender: boolean, client_version_bits: ClientVersionBitmask): void;
    QueueToGroupsForNPCHealthAA(sender: Mob , app: EQApplicationPacket ): void;
    AEAttack(attacker: Mob , distance: float, Hand: number, count: number, is_from_spell: boolean, attack_rounds: number): void;
    AETaunt(caster: Client , range: float, bonus_hate: number): void;
    AESpell(caster: Mob , center: Mob , spell_id: number, affect_caster: boolean, resist_adjust: number, max_targets: number): void;
    MassGroupBuff(caster: Mob , center: Mob , spell_id: number, affect_caster: boolean): void;
    GetTrapTrigger(trap: Trap ): Mob ;
    SendAlarm(trap: Trap , currenttarget: Mob , kos: number): void;
    FindNearbyTrap(searcher: Mob , max_dist: float, curdist: float , detected: boolean): Trap ;
    AddHealAggro(target: Mob , caster: Mob , hate: number): void;
    OpenDoorsNear(opener: Mob ): void;
    UpdateWho(iSendFullUpdate: boolean): void;
    MakeNameUnique(name: char ): char ;
    RemoveNumbers(name: char ): char ;
    SignalMobsByNPCID(npc_type: number, signal_id: number): void;
    RemoveEntity(id: number): void;
    SendPetitionToAdmins(pet: Petition ): void;
    SendPetitionToAdmins(): void;
    AddLootToNPCS(item_id: number, count: number): void;
    ListNPCCorpses(client: Client ): void;
    ListPlayerCorpses(client: Client ): void;
    DeleteNPCCorpses(): number;
    DeletePlayerCorpses(): number;
    CorpseFix(c: Client ): void;
    HalveAggro(who: Mob ): void;
    DoubleAggro(who: Mob ): void;
    UpdateHoTT(target: Mob ): void;
    Process(): void;
    ClearAggro(targ: Mob , clear_caster_id: boolean): void;
    ClearWaterAggro(targ: Mob ): void;
    ClearFeignAggro(targ: Mob ): void;
    ClearZoneFeignAggro(targ: Mob ): void;
    AggroZone(who: Mob , hate: number): void;
    Fighting(targ: Mob ): boolean;
    RemoveFromHateLists(mob: Mob , settoone: boolean): void;
    RemoveDebuffs(caster: Mob ): void;
    MessageGroup(sender: Mob , skipclose: boolean, type: number, message: char ): void;
    LimitAddNPC(npc: NPC ): void;
    LimitRemoveNPC(npc: NPC ): void;
    LimitCheckType(npc_type: number, count: number): boolean;
    LimitCheckGroup(spawngroup_id: number, count: number): boolean;
    LimitCheckName(npc_name: char ): boolean;
    GetHatedCount(attacker: Mob , exclude: Mob , inc_gray_con: boolean): number;
    Merc_AICheckCloseBeneficialSpells(caster: Merc , iChance: number, iRange: float, iSpellTypes: number): boolean;
    GetTargetForMez(caster: Mob ): Mob ;
    CheckNPCsClose(center: Mob ): number;
    GetClosestCorpse(sender: Mob , Name: char ): Corpse ;
    TryWakeTheDead(sender: Mob , target: Mob , spell_id: number, max_distance: number, duration: number, amount_pets: number): void;
    GetClosestBanker(sender: Mob , distance: number): NPC ;
    CameraEffect(duration: number, intensity: float): void;
    GetClosestMobByBodyType(sender: Mob , BodyType: bodyType, skip_client_pets: boolean): Mob ;
    ForceGroupUpdate(gid: number): void;
    SendGroupLeave(gid: number, name: char ): void;
    SendGroupJoin(gid: number, name: char ): void;
    SaveAllClientsTaskState(): void;
    ReloadAllClientsTaskState(task_id: number): void;
    CreateGroundObject(itemid: number, position: vec4 , decay_time: number): number;
    CreateGroundObjectFromModel(model: char , position: vec4 , type: number, decay_time: number): number;
    CreateDoor(model: char , position: vec4 , type: number, size: number): number;
    ZoneWho(c: Client , Who: Who_All_Struct ): void;
    UnMarkNPC(ID: number): void;
    SignalAllClients(signal_id: number): void;
    UpdateQGlobal(qid: number, newGlobal: QGlobal): void;
    DeleteQGlobal(name: string, npcID: number, charID: number, zoneID: number): void;
    SendFindableNPCList(c: Client ): void;
    UpdateFindableNPCState(n: NPC , Remove: boolean): void;
    HideCorpses(c: Client , CurrentMode: number, NewMode: number): void;
    GateAllClientsToSafeReturn(): void;
    GetMobList(m_list: list<Mob > ): void;
    GetNPCList(n_list: list<NPC > ): void;
    GetClientList(c_list: list<Client > ): void;
    GetCorpseList(c_list: list<Corpse > ): void;
    GetObjectList(o_list: list<Object > ): void;
    GetDoorsList(d_list: list<Doors > ): void;
    GetSpawnList(d_list: list<Spawn2 > ): void;
    GetTargetsForConeArea(start: Mob , min_radius: float, radius: float, height: float, pcnpc: number, m_list: list<Mob > ): void;
    GetTargetsForVirusEffect(spreader: Mob , orginal_caster: Mob , range: number, pcnpc: number, spell_id: number): vector<Mob  >;
    GetMobList(): number;
    GetNPCList(): number;
    GetMercList(): number;
    GetClientList(): number;
    GetBotList(): list<Bot > ;
    GetBotListByCharacterID(character_id: number, class_id: number): vector<Bot  >;
    GetBotListByClientName(client_name: string, class_id: number): vector<Bot  >;
    SignalAllBotsByOwnerCharacterID(character_id: number, signal_id: number): void;
    SignalAllBotsByOwnerName(owner_name: string, signal_id: number): void;
    SignalBotByBotID(bot_id: number, signal_id: number): void;
    SignalBotByBotName(bot_name: string, signal_id: number): void;
    GetCorpseList(): number;
    GetObjectList(): number;
    GetDoorsList(): number;
    GetCloseMobList(mob: Mob , distance: float): number;
    DepopAll(NPCTypeID: number, StartSpawnTimer: boolean): void;
    GetFreeID(): number;
    RefreshAutoXTargets(c: Client ): void;
    RefreshClientXTargets(c: Client ): void;
    SendAlternateAdvancementStats(): void;
    ScanCloseMobs(close_mobs: number, scanning_mob: Mob , add_self_to_other_lists: boolean): void;
    GetTrapInfo(c: Client ): void;
    IsTrapGroupSpawned(trap_id: number, group: number): boolean;
    UpdateAllTraps(respawn: boolean, repopnow: boolean): void;
    ClearTrapPointers(): void;
    MovePlayerCorpsesToGraveyard(force_move_from_instance: boolean): number;
    AddBot(new_bot: Bot , send_spawn_packet: boolean, dont_queue: boolean): void;
    RemoveBot(entityID: number): boolean;
    GetMobByBotID(botID: number): Mob ;
    GetBotByBotID(botID: number): Bot ;
    GetBotByBotName(botName: string_view): Bot ;
    GetBotOwnerByBotEntityID(entity_id: number): Client ;
    GetBotOwnerByBotID(bot_id: number): Client ;
    GetBotsByBotOwnerCharacterID(botOwnerCharacterID: number): list<Bot  >;
    Bot_AICheckCloseBeneficialSpells(caster: Bot , iChance: number, iRange: float, iSpellTypes: number): boolean;
    ShowSpawnWindow(client: Client , Distance: number, NamedOnly: boolean): void;
    ScanCloseClientMobs(close_mobs: number, scanning_mob: Mob ): void;
    GetBotList(b_list: list<Bot > ): void;
    Depop(StartSpawnTimer: boolean): void;
    AddToSpawnQueue(entityid: number, app: NewSpawn_Struct  ): void;
    CheckSpawnQueue(): void
  }

  export class SpawnLimitRecord {
      spawngroup_id : number;
    npc_type : number;

  }

  export class BulkZoneSpawnPacket {
    constructor(iSendTo: Client , iMaxSpawnsPerPacket: number);;
  constructor();
  
    AddSpawn(ns: NewSpawn_Struct ): boolean;
    SendBuffer(): void
  }

  export class Mob extends Entity {
    constructor(in_name: char , in_lastname: char , in_cur_hp: number, in_max_hp: number, in_gender: number, in_race: number, in_class: number, in_bodytype: bodyType, in_deity: number, in_level: number, in_npctype_id: number, in_size: float, in_runspeed: float, position: vec4 , in_light: number, in_texture: number, in_helmtexture: number, in_ac: number, in_atk: number, in_str: number, in_sta: number, in_dex: number, in_agi: number, in_int: number, in_wis: number, in_cha: number, in_haircolor: number, in_beardcolor: number, in_eyecolor1: number, in_eyecolor2: number, in_hairstyle: number, in_luclinface: number, in_beard: number, in_drakkin_heritage: number, in_drakkin_tattoo: number, in_drakkin_details: number, in_armor_tint: number, in_aa_title: number, in_see_invis: number, in_see_invis_undead: number, in_see_hide: number, in_see_improved_hide: number, in_hp_regen: number, in_mana_regen: number, in_qglobal: number, in_maxlevel: number, in_scalerate: number, in_armtexture: number, in_bracertexture: number, in_handtexture: number, in_legtexture: number, in_feettexture: number, in_usemodel: number, in_always_aggros_foes: boolean, in_heroic_strikethrough: number, keeps_sold_items: boolean, in_hp_regen_per_second: number);;
  constructor();
      close_mobs : number;
    mob_close_scan_timer : Timer;
    mob_check_moving_timer : Timer;
    tmHidden : number;
    invisible : number;
    nobuff_invisible : number;
    invisible_undead : number;
    invisible_animals : number;
    see_invis : number;
    innate_see_invis : number;
    see_invis_undead : number;
    sneaking : boolean;
    hidden : boolean;
    improved_hidden : boolean;
    see_hide : boolean;
    see_improved_hide : boolean;
    invulnerable : boolean;
    qglobal : boolean;
    trade : Trade ;
    weaponstance : WeaponStance_Struct;
    turning : boolean;
    IsMob(): boolean;
    InZone(): boolean;
    DisplayInfo(mob: Mob ): void;
    RogueBackstab(other: Mob , min_damage: boolean, ReuseTime: number): void;
    RogueAssassinate(other: Mob ): void;
    MobAngle(other: Mob , ourx: float, oury: float): float;
    BehindMob(other: Mob , ourx: float, oury: float): boolean;
    InFrontMob(other: Mob , ourx: float, oury: float): boolean;
    IsFacingMob(other: Mob ): boolean;
    HeadingAngleToMob(other: Mob ): float;
    HeadingAngleToMob(other_x: float, other_y: float): float;
    RangedAttack(other: Mob ): void;
    ThrowingAttack(other: Mob ): void;
    Attack(other: Mob , Hand: number, FromRiposte: boolean, IsStrikethrough: boolean, IsFromSpell: boolean, opts: ExtraAttackOptions ): boolean;
    DoAttack(other: Mob , hit: DamageHitInfo , opts: ExtraAttackOptions , FromRiposte: boolean): void;
    MonkSpecialAttack(other: Mob , skill_used: number): number;
    TryBackstab(other: Mob , ReuseTime: number): void;
    AvoidDamage(attacker: Mob , hit: DamageHitInfo ): boolean;
    compute_tohit(skillinuse: SkillType): number;
    GetTotalToHit(skill: SkillType, chance_mod: number): number;
    compute_defense(): number;
    GetTotalDefense(): number;
    CheckHitChance(attacker: Mob , hit: DamageHitInfo ): boolean;
    TryCriticalHit(defender: Mob , hit: DamageHitInfo , opts: ExtraAttackOptions ): void;
    TryPetCriticalHit(defender: Mob , hit: DamageHitInfo ): void;
    TryFinishingBlow(defender: Mob , damage: number): boolean;
    TryHeadShot(defender: Mob , skillInUse: SkillType): number;
    TryAssassinate(defender: Mob , skillInUse: SkillType): number;
    DoRiposte(defender: Mob ): void;
    ApplyMeleeDamageMods(skill: number, damage: number, defender: Mob , opts: ExtraAttackOptions ): void;
    ACSum(skip_caps: boolean): number;
    GetDisplayAC(): number;
    offense(skill: SkillType): number;
    GetBestMeleeSkill(): number;
    CalcAC(): void;
    GetACSoftcap(): number;
    GetSoftcapReturns(): number;
    GetClassRaceACBonus(): number;
    GetMitigationAC(): number;
    MeleeMitigation(attacker: Mob , hit: DamageHitInfo , opts: ExtraAttackOptions ): void;
    RollD20(offense: number, mitigation: number): number;
    CombatRange(other: Mob , fixed_size_mod: float, aeRampage: boolean, opts: ExtraAttackOptions ): boolean;
    IsBerserk(): boolean;
    RogueEvade(other: Mob ): void;
    CommonOutgoingHitSuccess(defender: Mob , hit: DamageHitInfo , opts: ExtraAttackOptions ): void;
    HasDied(): boolean;
    CheckDualWield(): boolean;
    DoMainHandAttackRounds(target: Mob , opts: ExtraAttackOptions , rampage: boolean): void;
    DoOffHandAttackRounds(target: Mob , opts: ExtraAttackOptions , rampage: boolean): void;
    CheckDoubleAttack(): boolean;
    ProcessAttackRounds(target: Mob , opts: ExtraAttackOptions , rampage: boolean): void;
    HasAnInvisibilityEffect(): boolean;
    BreakCharmPetIfConditionsMet(): void;
    IsInvisible(other: Mob ): boolean;
    SetInvisible(state: number, set_on_bonus_calc: boolean): void;
    CalcSeeInvisibleLevel(): void;
    CalcInvisibleLevel(): void;
    ZeroInvisibleVars(invisible_type: number): void;
    GetSeeInvisibleLevelFromNPCStat(in_see_invis: number): number;
    BreakInvisibleSpells(): void;
    CancelSneakHide(): void;
    CommonBreakInvisible(): void;
    CommonBreakInvisibleFromCombat(): void;
    GetInvisibleLevel(): number;
    GetInvisibleUndeadLevel(): number;
    SeeHide(): boolean;
    SeeImprovedHide(): boolean;
    SeeInvisibleUndead(): number;
    SeeInvisible(): number;
    SetInnateSeeInvisible(val: number): void;
    SetSeeInvisibleUndead(val: number): void;
    AttackAnimation(Hand: number, weapon: ItemInstance , skillinuse: SkillType): SkillType;
    GetTextureProfileMaterial(material_slot: number): number;
    GetTextureProfileColor(material_slot: number): number;
    GetTextureProfileHeroForgeModel(material_slot: number): number;
    SendArmorAppearance(one_client: Client ): void;
    SendTextureWC(slot: number, texture: number, hero_forge_model: number, elite_material: number, unknown06: number, unknown18: number): void;
    SendWearChange(material_slot: number, one_client: Client ): void;
    SetSlotTint(material_slot: number, red_tint: number, green_tint: number, blue_tint: number): void;
    WearChange(material_slot: number, texture: number, color: number, hero_forge_model: number): void;
    ChangeSize(in_size: float, unrestricted: boolean): void;
    DoAnim(animation_id: number, animation_speed: number, ackreq: boolean, filter: eqFilterType): void;
    ProjectileAnimation(to: Mob , item_id: number, IsArrow: boolean, speed: float, angle: float, tilt: float, arc: float, IDFile: char , skillInUse: SkillType): void;
    SendAppearanceEffect(parm1: number, parm2: number, parm3: number, parm4: number, parm5: number, specific_target: Client , value1slot: number, value1ground: number, value2slot: number, value2ground: number, value3slot: number, value3ground: number, value4slot: number, value4ground: number, value5slot: number, value5ground: number): void;
    SendLevelAppearance(): void;
    SendTargetable(on: boolean, specific_target: Client ): void;
    SetMobTextureProfile(material_slot: number, texture: number, color: number, hero_forge_model: number): void;
    SendSpellEffect(effect_id: number, duration: number, finish_delay: number, zone_wide: boolean, unk020: number, perm_effect: boolean, c: Client , caster_id: number, target_id: number): void;
    IsBeneficialAllowed(target: Mob ): boolean;
    GetCasterLevel(spell_id: number): number;
    ApplySpellsBonuses(spell_id: number, casterlevel: number, newbon: StatBonuses , casterID: number, WornType: number, ticsremaining: number, buffslot: number, instrument_mod: number, IsAISpellEffect: boolean, effect_id: number, se_base: number, se_limit: number, se_max: number): void;
    NegateSpellEffectBonuses(spell_id: number): void;
    NegateSpellEffect(spell_id: number, effect_id: number): boolean;
    GetActSpellRange(spell_id: number, range: float): float;
    GetActSpellDamage(spell_id: number, value: number, target: Mob ): number;
    GetActDoTDamage(spell_id: number, value: number, target: Mob , from_buff_tic: boolean): number;
    GetActSpellHealing(spell_id: number, value: number, target: Mob , from_buff_tic: boolean): number;
    GetActSpellCost(spell_id: number, cost: number): number;
    GetActSpellDuration(spell_id: number, duration: number): number;
    GetActSpellCasttime(spell_id: number, casttime: number): number;
    GetActReflectedSpellDamage(spell_id: number, value: number, effectiveness: number): number;
    ResistSpell(resist_type: number, spell_id: number, caster: Mob , use_resist_override: boolean, resist_override: number, CharismaCheck: boolean, CharmTick: boolean, IsRoot: boolean, level_override: number): float;
    GetResist(resist_type: number): number;
    ResistPhysical(level_diff: number, caster_level: number): number;
    ResistElementalWeaponDmg(item: ItemInstance ): number;
    CheckBaneDamage(item: ItemInstance ): number;
    GetSpecializeSkillValue(spell_id: number): number;
    SendSpellBarDisable(): void;
    SendSpellBarEnable(spellid: number): void;
    ZeroCastingVars(): void;
    SpellProcess(): void;
    CastSpell(spell_id: number, target_id: number, slot: CastingSlot, casttime: number, mana_cost: number, oSpellWillFinish: number, item_slot: number, timer: number, timer_duration: number, resist_adjust: number, aa_id: number): boolean;
    DoCastSpell(spell_id: number, target_id: number, slot: CastingSlot, casttime: number, mana_cost: number, oSpellWillFinish: number, item_slot: number, timer: number, timer_duration: number, resist_adjust: number, aa_id: number): boolean;
    CastedSpellFinished(spell_id: number, target_id: number, slot: CastingSlot, mana_used: number, inventory_slot: number, resist_adjust: number): void;
    SpellFinished(spell_id: number, target: Mob , slot: CastingSlot, mana_used: number, inventory_slot: number, resist_adjust: number, isproc: boolean, level_override: number, timer: number, timer_duration: number, from_casted_spell: boolean, aa_id: number): boolean;
    SendBeginCast(spell_id: number, casttime: number): void;
    SpellOnTarget(spell_id: number, spelltar: Mob , reflect_effectiveness: number, use_resist_adjust: boolean, resist_adjust: number, isproc: boolean, level_override: number, duration_override: number, disable_buff_overwrite: boolean): boolean;
    SpellEffect(caster: Mob , spell_id: number, partial: float, level_override: number, reflect_effectiveness: number, duration_override: number, disable_buff_overwrite: boolean): boolean;
    DetermineSpellTargets(spell_id: number, spell_target: Mob  , ae_center: Mob  , CastAction: CastAction_type , slot: CastingSlot, isproc: boolean): boolean;
    DoCastingChecksOnCaster(spell_id: number, slot: CastingSlot): boolean;
    DoCastingChecksZoneRestrictions(check_on_casting: boolean, spell_id: number): boolean;
    DoCastingChecksOnTarget(check_on_casting: boolean, spell_id: number, spell_target: Mob ): boolean;
    CheckFizzle(spell_id: number): boolean;
    CheckSpellLevelRestriction(caster: Mob , spell_id: number): boolean;
    IsImmuneToSpell(spell_id: number, caster: Mob ): boolean;
    GetAOERange(spell_id: number): float;
    InterruptSpell(spellid: number): void;
    InterruptSpell(arg0: number, arg1: number, spellid: number): void;
    StopCasting(): void;
    StopCastSpell(spell_id: number, send_spellbar_enable: boolean): void;
    IsCasting(): boolean;
    CastingSpellID(): number;
    TryDispel(caster_level: number, buff_level: number, level_modifier: number): boolean;
    TrySpellProjectile(spell_target: Mob , spell_id: number, speed: float): boolean;
    ResourceTap(damage: number, spell_id: number): void;
    TryTriggerThreshHold(damage: number, effect_id: number, attacker: Mob ): void;
    CalcDestFromHeading(heading: float, distance: float, MaxZDiff: float, StartX: float, StartY: float, dX: float , dY: float , dZ: float ): void;
    BeamDirectional(spell_id: number, resist_adjust: number): void;
    ConeDirectional(spell_id: number, resist_adjust: number): void;
    ApplyHealthTransferDamage(caster: Mob , target: Mob , spell_id: number): void;
    ApplySpellEffectIllusion(spell_id: number, caster: Mob , buffslot: number, base: number, limit: number, max: number): void;
    ApplyIllusionToCorpse(spell_id: number, new_corpse: Corpse ): void;
    SendIllusionWearChange(c: Client ): void;
    GetItemSlotToConsumeCharge(spell_id: number, inventory_slot: number): number;
    CheckItemRaceClassDietyRestrictionsOnCast(inventory_slot: number): boolean;
    IsFromTriggeredSpell(slot: CastingSlot, item_slot: number): boolean;
    ApplyBardPulse(spell_id: number, spell_target: Mob , slot: CastingSlot): boolean;
    IsActiveBardSong(spell_id: number): boolean;
    HasActiveSong(): boolean;
    ZeroBardPulseVars(): void;
    DoBardCastingFromItemClick(is_casting_bard_song: boolean, cast_time: number, spell_id: number, target_id: number, slot: CastingSlot, item_slot: number, recast_type: number, recast_delay: number): void;
    UseBardSpellLogic(spell_id: number, slot: number): boolean;
    BuffProcess(): void;
    DoBuffTic(buff: Buffs_Struct , slot: number, caster: Mob ): void;
    BuffFadeBySpellID(spell_id: number): void;
    BuffFadeBySpellIDAndCaster(spell_id: number, caster_id: number): void;
    BuffFadeByEffect(effect_id: number, slot_to_skip: number): void;
    BuffFadeAll(): void;
    BuffFadeBeneficial(): void;
    BuffFadeNonPersistDeath(): void;
    BuffFadeDetrimental(): void;
    BuffFadeBySlot(slot: number, iRecalcBonuses: boolean): void;
    BuffFadeDetrimentalByCaster(caster: Mob ): void;
    BuffFadeBySitModifier(): void;
    BuffDetachCaster(caster: Mob ): void;
    IsAffectedByBuffByGlobalGroup(group: GlobalGroup): boolean;
    BuffModifyDurationBySpellID(spell_id: number, newDuration: number): void;
    AddBuff(caster: Mob , spell_id: number, duration: number, level_override: number, disable_buff_overwrite: boolean): number;
    CanBuffStack(spellid: number, caster_level: number, iFailIfOverwrite: boolean): number;
    CalcBuffDuration(caster: Mob , target: Mob , spell_id: number, caster_level_override: number): number;
    SendPetBuffsToClient(): void;
    GetCurrentBuffSlots(): number;
    GetCurrentSongSlots(): number;
    GetCurrentDiscSlots(): number;
    GetMaxBuffSlots(): number;
    GetMaxSongSlots(): number;
    GetMaxDiscSlots(): number;
    GetMaxTotalSlots(): number;
    HasDiscBuff(): boolean;
    GetFirstBuffSlot(disc: boolean, song: boolean): number;
    GetLastBuffSlot(disc: boolean, song: boolean): number;
    InitializeBuffSlots(): void;
    UninitializeBuffSlots(): void;
    MakeBuffsPacket(for_target: boolean, clear_buffs: boolean): EQApplicationPacket ;
    SendBuffsToClient(c: Client ): void;
    GetBuffs(): Buffs_Struct ;
    DoGravityEffect(): void;
    DamageShield(other: Mob , spell_ds: boolean): void;
    RuneAbsorb(damage: number, type: number): number;
    GetBuffSpellIDs(): number;
    FindBuff(spell_id: number, caster_id: number): boolean;
    FindBuffBySlot(slot: number): number;
    BuffCount(is_beneficial: boolean, is_detrimental: boolean): number;
    FindType(type: number, bOffensive: boolean, threshold: number): boolean;
    GetBuffSlotFromType(type: number): number;
    GetSpellIDFromSlot(slot: number): number;
    CountDispellableBuffs(): number;
    CheckNumHitsRemaining(type: NumHit, buff_slot: number, spell_id: number): void;
    HasNumhits(): boolean;
    Numhits(val: boolean): void;
    HasMGB(): boolean;
    SetMGB(val: boolean): void;
    HasProjectIllusion(): boolean;
    SetProjectIllusion(val: boolean): void;
    IsNimbusEffectActive(nimbus_effect: number): boolean;
    SetNimbusEffect(nimbus_effect: number): void;
    GetNimbusEffect1(): number;
    GetNimbusEffect2(): number;
    GetNimbusEffect3(): number;
    AddNimbusEffect(effect_id: number): void;
    RemoveNimbusEffect(effect_id: number): void;
    RemoveAllNimbusEffects(): void;
    GetTargetRingLocation(): vec3 ;
    GetTargetRingX(): float;
    GetTargetRingY(): float;
    GetTargetRingZ(): float;
    HasEndurUpkeep(): boolean;
    SetEndurUpkeep(val: boolean): void;
    HasBuffWithSpellGroup(spell_group: number): boolean;
    SetAppearanceEffects(slot: number, value: number): void;
    ListAppearanceEffects(c: Client ): void;
    ClearAppearanceEffects(): void;
    SendSavedAppearanceEffects(receiver: Client ): void;
    SetBuffDuration(spell_id: number, duration: number, level_override: number): void;
    ApplySpellBuff(spell_id: number, duration: number, level_override: number): void;
    GetBuffStatValueBySpell(spell_id: number, stat_identifier: char ): number;
    GetBuffStatValueBySlot(slot: number, stat_identifier: char ): number;
    SetLevel(in_level: number, command: boolean): void;
    TempName(newname: char ): void;
    SetTargetable(on: boolean): void;
    IsTargetable(): boolean;
    HasShieldEquipped(): boolean;
    SetShieldEquipped(val: boolean): void;
    HasTwoHandBluntEquipped(): boolean;
    SetTwoHandBluntEquipped(val: boolean): void;
    HasTwoHanderEquipped(): boolean;
    SetTwoHanderEquipped(val: boolean): void;
    HasDualWeaponsEquipped(): boolean;
    HasBowEquipped(): boolean;
    SetBowEquipped(val: boolean): void;
    HasArrowEquipped(): boolean;
    SetArrowEquipped(val: boolean): void;
    HasBowAndArrowEquipped(): boolean;
    SetDualWeaponsEquipped(val: boolean): void;
    CanFacestab(): boolean;
    SetFacestab(val: boolean): void;
    ConvertItemTypeToSkillID(item_type: number): number;
    GetSkill(skill_num: SkillType): number;
    GetEquippedItemFromTextureSlot(material_slot: number): number;
    GetEquipmentMaterial(material_slot: number): number;
    GetEquipmentType(material_slot: number): number;
    GetHerosForgeModel(material_slot: number): number;
    GetEquipmentColor(material_slot: number): number;
    IsEliteMaterialItem(material_slot: number): number;
    CanClassEquipItem(item_id: number): boolean;
    CanRaceEquipItem(item_id: number): boolean;
    AffectedBySpellExcludingSlot(slot: number, effect: number): boolean;
    Death(killer_mob: Mob , damage: number, spell_id: number, attack_skill: SkillType, killed_by: KilledByTypes): boolean;
    Damage(from: Mob , damage: number, spell_id: number, attack_skill: SkillType, avoidable: boolean, buffslot: number, iBuffTic: boolean, special: eSpecialAttacks): void;
    SetHP(hp: number): void;
    SetOOCRegen(new_ooc_regen: number): void;
    Heal(): void;
    HealDamage(ammount: number, caster: Mob , spell_id: number): void;
    SetMaxHP(): void;
    GetBaseRace(): number;
    GetBaseGender(): number;
    GetFactionRace(): number;
    GetDeity(): number;
    GetDeityBit(): DeityTypeBit;
    GetRace(): number;
    GetModel(): number;
    GetGender(): number;
    GetTexture(): number;
    GetHelmTexture(): number;
    GetHairColor(): number;
    GetBeardColor(): number;
    GetEyeColor1(): number;
    GetEyeColor2(): number;
    GetHairStyle(): number;
    GetLuclinFace(): number;
    GetBeard(): number;
    GetDrakkinHeritage(): number;
    GetDrakkinTattoo(): number;
    GetDrakkinDetails(): number;
    ChangeRace(arg0: number): void;
    ChangeGender(arg0: number): void;
    ChangeTexture(arg0: number): void;
    ChangeHelmTexture(arg0: number): void;
    ChangeHairColor(arg0: number): void;
    ChangeBeardColor(arg0: number): void;
    ChangeEyeColor1(arg0: number): void;
    ChangeEyeColor2(arg0: number): void;
    ChangeHairStyle(arg0: number): void;
    ChangeLuclinFace(arg0: number): void;
    ChangeBeard(arg0: number): void;
    ChangeDrakkinHeritage(arg0: number): void;
    ChangeDrakkinTattoo(arg0: number): void;
    ChangeDrakkinDetails(arg0: number): void;
    GetArmorTint(i: number): number;
    GetClass(): number;
    GetLevel(): number;
    GetOrigLevel(): number;
    GetName(): char ;
    GetOrigName(): char ;
    GetLastName(): char ;
    GetCleanName(): char ;
    SetName(new_name: char ): void;
    GetTarget(): Mob ;
    GetTargetDescription(target: Mob , description_type: number, entity_id_override: number): string;
    SetTarget(mob: Mob ): void;
    HasTargetReflection(): boolean;
    GetHPRatio(): float;
    GetIntHPRatio(): number;
    GetAC(): number;
    GetATK(): number;
    GetATKBonus(): number;
    GetSTR(): number;
    GetSTA(): number;
    GetDEX(): number;
    GetAGI(): number;
    GetINT(): number;
    GetWIS(): number;
    GetCHA(): number;
    GetHeroicMR(): number;
    GetHeroicFR(): number;
    GetHeroicDR(): number;
    GetHeroicPR(): number;
    GetHeroicCR(): number;
    GetMR(): number;
    GetFR(): number;
    GetDR(): number;
    GetPR(): number;
    GetCR(): number;
    GetCorrup(): number;
    GetPhR(): number;
    GetItemBonuses(): StatBonuses;
    GetSpellBonuses(): StatBonuses;
    GetAABonuses(): StatBonuses;
    GetItemBonusesPtr(): StatBonuses ;
    GetSpellBonusesPtr(): StatBonuses ;
    GetAABonusesPtr(): StatBonuses ;
    GetHeroicSTR(): number;
    GetHeroicSTA(): number;
    GetHeroicDEX(): number;
    GetHeroicAGI(): number;
    GetHeroicINT(): number;
    GetHeroicWIS(): number;
    GetHeroicCHA(): number;
    GetMaxSTR(): number;
    GetMaxSTA(): number;
    GetMaxDEX(): number;
    GetMaxAGI(): number;
    GetMaxINT(): number;
    GetMaxWIS(): number;
    GetMaxCHA(): number;
    GetMaxMR(): number;
    GetMaxPR(): number;
    GetMaxDR(): number;
    GetMaxCR(): number;
    GetMaxFR(): number;
    GetDelayDeath(): number;
    GetHP(): number;
    GetMaxHP(): number;
    CalcMaxHP(): number;
    CalcHPRegenCap(): number;
    GetMaxMana(): number;
    CalcManaRegenCap(): number;
    GetMana(): number;
    GetEndurance(): number;
    GetMaxEndurance(): number;
    CalcEnduranceRegenCap(): number;
    SetEndurance(newEnd: number): void;
    GetItemHPBonuses(): number;
    GetSpellHPBonuses(): number;
    SetMana(amount: number): number;
    GetManaRatio(): float;
    CalcMaxMana(): number;
    GetNPCTypeID(): number;
    SetNPCTypeID(npctypeid: number): void;
    GetPosition(): vec4 ;
    SetPosition(x: float, y: float, z: float): void;
    GetX(): float;
    GetY(): float;
    GetZ(): float;
    GetHeading(): float;
    GetRelativePosition(): vec4 ;
    SetRelativePosition(x: float, y: float, z: float): void;
    GetRelativeX(): float;
    GetRelativeY(): float;
    GetRelativeZ(): float;
    GetRelativeHeading(): float;
    GetSize(): float;
    GetBaseSize(): float;
    GetFlyMode(): GravityBehavior;
    IsBoat(): boolean;
    GetIsBoat(): boolean;
    SetIsBoat(boat: boolean): void;
    IsControllableBoat(): boolean;
    AlwaysAggro(): bool;
    GetHeroicStrikethrough(): number;
    GetKeepsSoldItems(): bool;
    SetKeepsSoldItems(in_keeps_sold_items: boolean): void;
    GetHealAmt(): number;
    GetSpellDmg(): number;
    ProcessItemCaps(): void;
    CalcItemATKCap(): number;
    IsSitting(): boolean;
    CopyHateList(to: Mob ): void;
    HasRaid(): boolean;
    HasGroup(): boolean;
    GetRaid(): Raid ;
    GetGroup(): Group ;
    GetPrimaryFaction(): number;
    IsMoving(): boolean;
    SetMoving(move: boolean): void;
    GoToBind(bindnum: number): void;
    Gate(bindnum: number): void;
    GetWalkspeed(): number;
    GetRunspeed(): number;
    GetBaseRunspeed(): number;
    GetBaseWalkspeed(): number;
    GetBaseFearSpeed(): number;
    GetMovespeed(): float;
    IsRunning(): boolean;
    SetRunning(val: boolean): void;
    GMMove(x: float, y: float, z: float, heading: float, save_guard_spot: boolean): void;
    GMMove(position: vec4 , save_guard_spot: boolean): void;
    SetDelta(delta: vec4 ): void;
    MakeSpawnUpdate(spu: PlayerPositionUpdateServer_Struct ): void;
    SentPositionPacket(dx: float, dy: float, dz: float, dh: float, anim: number, send_to_self: boolean): void;
    StopMoving(): void;
    StopMoving(new_heading: float): void;
    SetSpawned(): void;
    Spawned(): boolean;
    ShouldISpawnFor(c: Client ): boolean;
    SetFlyMode(in_flymode: GravityBehavior): void;
    Teleport(pos: vec3 ): void;
    Teleport(pos: vec4 ): void;
    TryMoveAlong(distance: float, angle: float, send: boolean): void;
    TryMoveAlong(start: vec4 , distance: float, angle: float): vec4;
    ProcessForcedMovement(): void;
    IncDeltaX(arg0: float): void;
    IncDeltaY(arg0: float): void;
    IncDeltaZ(arg0: float): void;
    SetForcedMovement(arg0: number): void;
    SetHeading(iHeading: float): void;
    GetLevelCon(mylevel: number, iOtherLevel: number): number;
    GetLevelCon(iOtherLevel: number): number;
    AddToHateList(other: Mob , hate: number, damage: number, iYellForHelp: boolean, bFrenzy: boolean, iBuffTic: boolean, spell_id: number, pet_comand: boolean): void;
    RemoveFromHateList(mob: Mob ): boolean;
    SetHateAmountOnEnt(other: Mob , hate: number, damage: number): void;
    HalveAggro(other: Mob ): void;
    DoubleAggro(other: Mob ): void;
    GetHateAmount(tmob: Mob , is_dam: boolean): number;
    GetDamageAmount(tmob: Mob ): number;
    GetHateRatio(first: Mob , arg1: Mob ): number;
    GetHateTop(): Mob ;
    GetHateTopBot(): Bot ;
    GetHateTopClient(): Client ;
    GetHateTopNPC(): NPC ;
    GetSecondaryHate(skip: Mob ): Mob ;
    GetHateDamageTop(other: Mob ): Mob ;
    GetHateRandom(): Mob ;
    GetHateRandomBot(): Bot ;
    GetHateRandomClient(): Client ;
    GetHateRandomNPC(): NPC ;
    GetHateMost(): Mob ;
    GetHateClosest(skip_mezzed: boolean): Mob ;
    GetHateClosestBot(skip_mezzed: boolean): Bot ;
    GetHateClosestClient(skip_mezzed: boolean): Client ;
    GetHateClosestNPC(skip_mezzed: boolean): NPC ;
    IsEngaged(): boolean;
    GetHateListCount(count_type: HateListCountType): number;
    HasPrimaryAggro(): boolean;
    HasAssistAggro(): boolean;
    SetPrimaryAggro(value: boolean): void;
    SetAssistAggro(value: boolean): void;
    HateSummon(): boolean;
    FaceTarget(mob_to_face: Mob ): void;
    WipeHateList(npc_only: boolean): void;
    AddFeignMemory(attacker: Mob ): void;
    RemoveFromFeignMemory(attacker: Mob ): void;
    ClearFeignMemory(): void;
    IsOnFeignMemory(attacker: Mob ): boolean;
    PrintHateListToClient(who: Client ): void;
    GetHateList(): list<struct_HateList > ;
    CheckLosFN(other: Mob ): boolean;
    CheckLosFN(posX: float, posY: float, posZ: float, mobSize: float): boolean;
    CheckLosFN(posWatcher: vec3, sizeWatcher: float, posTarget: vec3, sizeTarget: float): boolean;
    CheckWaterLoS(m: Mob ): boolean;
    SetLastLosState(value: boolean): void;
    CheckLastLosState(): boolean;
    GetMobDescription(): string;
    GetFilteredHateList(filter_type: EntityFilterType, distance: number): list<struct_HateList  >;
    DamageHateList(damage: number, distance: number, filter_type: EntityFilterType, is_percentage: boolean): void;
    DamageArea(damage: number, distance: number, filter_type: EntityFilterType, is_percentage: boolean): void;
    CameraEffect(duration: number, intensity: float, c: Client , global: boolean): void;
    GetQglobal(): boolean;
    CreateDespawnPacket(app: EQApplicationPacket , Decay: boolean): void;
    CreateHorseSpawnPacket(app: EQApplicationPacket , m: Mob ): void;
    CreateSpawnPacket(app: EQApplicationPacket , ForWho: Mob ): void;
    CreateSpawnPacket(app: EQApplicationPacket , ns: NewSpawn_Struct ): void;
    FillSpawnStruct(ns: NewSpawn_Struct , ForWho: Mob ): void;
    CreateHPPacket(app: EQApplicationPacket ): void;
    SendHPUpdate(force_update_all: boolean): void;
    ResetHPUpdateTimer(): void;
    SetSpawnLastNameByClass(ns: NewSpawn_Struct ): void;
    RandomTimer(min: number, max: number): number;
    GetDefaultGender(in_race: number, in_gender: number): number;
    GetSkillByItemType(ItemType: number): SkillType;
    GetItemTypeBySkill(skill: SkillType): number;
    MakePet(spell_id: number, pettype: char , petname: char ): void;
    MakePoweredPet(spell_id: number, pettype: char , petpower: number, petname: char , in_size: float): void;
    IsWarriorClass(): boolean;
    GetCasterClass(): number;
    GetArchetype(): number;
    SetZone(zone_id: number, instance_id: number): void;
    SendStatsWindow(c: Client , use_window: boolean): void;
    ShowStats(client: Client ): void;
    ShowBuffs(c: Client ): void;
    PlotPositionAroundTarget(target: Mob , x_dest: float , y_dest: float , z_dest: float , lookForAftArc: boolean): boolean;
    GetKillExpMod(): number;
    MakeAura(spell_id: number): void;
    GetAuraSlots(): number;
    GetTrapSlots(): number;
    HasFreeAuraSlots(): boolean;
    HasFreeTrapSlots(): boolean;
    AddAura(aura: Aura , record: AuraRecord ): void;
    AddTrap(aura: Aura , record: AuraRecord ): void;
    CanSpawnAura(trap: boolean): boolean;
    RemoveAura(spawn_id: number, skip_strip: boolean, expired: boolean): void;
    RemoveAllAuras(): void;
    GetAuraMgr(): AuraMgr;
    TriggerDefensiveProcs(on: Mob , hand: number, FromSkillProc: boolean, damage: number): void;
    AddRangedProc(spell_id: number, iChance: number, base_spell_id: number, proc_reuse_time: number): boolean;
    RemoveRangedProc(spell_id: number, bAll: boolean): boolean;
    HasRangedProcs(): boolean;
    AddDefensiveProc(spell_id: number, iChance: number, base_spell_id: number, proc_reuse_time: number): boolean;
    RemoveDefensiveProc(spell_id: number, bAll: boolean): boolean;
    HasDefensiveProcs(): boolean;
    HasSkillProcs(): boolean;
    HasSkillProcSuccess(): boolean;
    AddProcToWeapon(spell_id: number, bPerma: boolean, iChance: number, base_spell_id: number, level_override: number, proc_reuse_time: number): boolean;
    RemoveProcFromWeapon(spell_id: number, bAll: boolean): boolean;
    HasProcs(): boolean;
    IsCombatProc(spell_id: number): boolean;
    IsRaidTarget(): boolean;
    IsAttackAllowed(target: Mob , isSpellAttack: boolean): boolean;
    IsTargeted(): boolean;
    IsTargeted(in_tar: number): void;
    SetFollowID(id: number): void;
    SetFollowDistance(dist: number): void;
    SetFollowCanRun(v: boolean): void;
    GetFollowID(): number;
    GetFollowDistance(): number;
    GetFollowCanRun(): boolean;
    IsRareSpawn(): boolean;
    SetRareSpawn(arg0: boolean): void;
    Message(type: number, message: char ): void;
    MessageString(type: number, string_id: number, distance: number): void;
    MessageString(type: number, string_id: number, message: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char , distance: number): void;
    FilteredMessageString(sender: Mob , type: number, filter: eqFilterType, string_id: number): void;
    FilteredMessageString(sender: Mob , type: number, filter: eqFilterType, string_id: number, message1: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    Say(format: char ): void;
    SayString(string_id: number, message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    SayString(type: number, string_id: number, message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    SayString(to: Client , string_id: number, message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    SayString(to: Client , type: number, string_id: number, message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    Shout(format: char ): void;
    Emote(format: char ): void;
    QuestJournalledSay(QuestInitiator: Client , str: char , opts: Options ): void;
    GetItemStat(item_id: number, identifier: string): number;
    CalcFocusEffect(type: focusType, focus_id: number, spell_id: number, best_focus: boolean, casterid: number, caster: Mob ): number;
    IsFocusEffect(spellid: number, effect_index: number, AA: boolean, aa_effect: number): number;
    SendIllusionPacket(a: AppearanceStruct ): void;
    CloneAppearance(other: Mob , clone_name: boolean): void;
    SetFaceAppearance(face: FaceChange_Struct , skip_sender: boolean): void;
    RandomizeFeatures(send_illusion: boolean, set_variables: boolean): boolean;
    Stun(duration: number): void;
    UnStun(): void;
    Silence(newval: boolean): void;
    Amnesia(newval: boolean): void;
    TemporaryPets(spell_id: number, target: Mob , name_override: char , duration_override: number, followme: boolean, sticktarg: boolean, controlled_pet_id: number): void;
    TypesTemporaryPets(typesid: number, target: Mob , name_override: char , duration_override: number, followme: boolean, sticktarg: boolean): void;
    WakeTheDead(spell_id: number, corpse_to_use: Corpse , target: Mob , duration: number): void;
    Spin(): void;
    Kill(): void;
    PassCharismaCheck(caster: Mob , spell_id: number): boolean;
    TryDeathSave(): boolean;
    TryDivineSave(): boolean;
    TryTriggerOnCastFocusEffect(type: focusType, spell_id: number): void;
    TryTriggerOnCastProc(focusspellid: number, spell_id: number, proc_spellid: number): boolean;
    TrySpellTrigger(target: Mob , spell_id: number, effect: number): boolean;
    TryTriggerOnCastRequirement(): void;
    TryTwincast(caster: Mob , target: Mob , spell_id: number): void;
    TrySympatheticProc(target: Mob , spell_id: number): void;
    GetSympatheticFocusEffect(type: focusType, spell_id: number): number;
    TryFadeEffect(slot: number): boolean;
    DispelMagic(casterm: Mob , spell_id: number, effect_value: number): void;
    GetSpellEffectResistChance(spell_id: number): number;
    GetVulnerability(caster: Mob , spell_id: number, ticsremaining: number, from_buff_tic: boolean): number;
    GetFcDamageAmtIncoming(caster: Mob , spell_id: number, from_buff_tic: boolean): number;
    GetFocusIncoming(type: focusType, effect: number, caster: Mob , spell_id: number): number;
    GetSkillDmgTaken(skill_used: SkillType, opts: ExtraAttackOptions ): number;
    GetPositionalDmgTaken(attacker: Mob ): number;
    GetPositionalDmgTakenAmt(attacker: Mob ): number;
    DoKnockback(caster: Mob , push_back: number, push_up: number): void;
    CalcResistChanceBonus(): number;
    CalcFearResistChance(): number;
    TrySpellOnKill(level: number, spell_id: number): void;
    TrySpellOnDeath(): boolean;
    CastOnCurer(spell_id: number): void;
    CastOnCure(spell_id: number): void;
    CastOnNumHitFade(spell_id: number): void;
    SlowMitigation(caster: Mob ): void;
    GetCritDmgMod(skill: number, owner: Mob ): number;
    GetMeleeDamageMod_SE(skill: number): number;
    GetMeleeMinDamageMod_SE(skill: number): number;
    GetCrippBlowChance(): number;
    GetMeleeDmgPositionMod(defender: Mob ): number;
    GetSkillReuseTime(skill: number): number;
    GetCriticalChanceBonus(skill: number): number;
    GetSkillDmgAmt(skill_id: number): number;
    GetPositionalDmgAmt(defender: Mob ): number;
    CanBlockSpell(): boolean;
    DoHPToManaCovert(mana_cost: number): boolean;
    GetDecayEffectValue(spell_id: number, spelleffect: number): number;
    GetExtraSpellAmt(spell_id: number, extra_spell_amt: number, base_spell_dmg: number): number;
    MeleeLifeTap(damage: number): void;
    PassCastRestriction(value: number): boolean;
    SendCastRestrictionMessage(requirement_id: number, is_target_requirement: boolean, is_discipline: boolean): void;
    ImprovedTaunt(): boolean;
    TryRootFadeByDamage(buffslot: number, attacker: Mob ): boolean;
    GetSlowMitigation(): float;
    CalcSpellPowerDistanceMod(spell_id: number, range: float, caster: Mob ): void;
    GetSpellPowerDistanceMod(): number;
    SetSpellPowerDistanceMod(value: number): void;
    GetSpellStat(spell_id: number, identifier: char , slot: number): number;
    HarmonySpellLevelCheck(spell_id: number, target: Mob ): boolean;
    PassCharmTargetRestriction(target: Mob ): boolean;
    CanFocusUseRandomEffectivenessByType(type: focusType): boolean;
    GetFocusRandomEffectivenessValue(focus_base: number, focus_base2: number, best_focus: boolean): number;
    GetHealRate(): number;
    GetMemoryBlurChance(base_chance: number): number;
    HasBaseEffectFocus(): boolean;
    GetDualWieldingSameDelayWeapons(): number;
    SetDualWieldingSameDelayWeapons(val: number): void;
    IsTargetedFocusEffect(focus_type: number): boolean;
    HasPersistDeathIllusion(spell_id: number): boolean;
    TryDoubleMeleeRoundEffect(): boolean;
    GetUseDoubleMeleeRoundDmgBonus(): boolean;
    SetUseDoubleMeleeRoundDmgBonus(val: boolean): void;
    CastSpellOnLand(caster: Mob , spell_id: number): void;
    IsFocusProcLimitTimerActive(focus_spell_id: number): boolean;
    SetFocusProcLimitTimer(focus_spell_id: number, focus_reuse_time: number): void;
    IsProcLimitTimerActive(base_spell_id: number, proc_reuse_time: number, proc_type: number): boolean;
    SetProcLimitTimer(base_spell_id: number, proc_reuse_time: number, proc_type: number): void;
    VirusEffectProcess(): void;
    SpreadVirusEffect(spell_id: number, caster_id: number, buff_tics_remaining: number): void;
    ModSkillDmgTaken(skill_num: SkillType, value: number): void;
    GetModSkillDmgTaken(skill_num: SkillType): number;
    ModVulnerability(resist: number, value: number): void;
    GetModVulnerability(resist: number): number;
    SetAllowBeneficial(value: boolean): void;
    GetAllowBeneficial(): boolean;
    SetDisableMelee(value: boolean): void;
    IsMeleeDisabled(): boolean;
    IsOffHandAtk(): boolean;
    OffHandAtk(val: boolean): void;
    SetFlurryChance(value: number): void;
    GetFlurryChance(): number;
    GetAppearanceValue(in_appearance: EmuAppearance): number;
    SendAppearancePacket(type: number, value: number, whole_zone: boolean, ignore_self: boolean, target: Client ): void;
    SetAppearance(app: EmuAppearance, ignore_self: boolean): void;
    GetAppearance(): EmuAppearance;
    GetAnimation(): number;
    SetAnimation(a: number): void;
    GetRunAnimSpeed(): number;
    SetRunAnimSpeed(arg0: number): void;
    IsDestructibleObject(): boolean;
    SetDestructibleObject(arg0: boolean): void;
    GetInnateLightType(): number;
    GetEquipmentLightType(): number;
    GetSpellLightType(): number;
    UpdateEquipmentLight(): void;
    SetSpellLightType(light_type: number): void;
    SendWearChangeAndLighting(last_texture: number): void;
    GetActiveLightType(): number;
    UpdateActiveLight(): boolean;
    GetLightProfile(): LightSourceProfile ;
    GetPet(): Mob ;
    SetPet(newpet: Mob ): void;
    GetOwner(): Mob ;
    GetOwnerOrSelf(): Mob ;
    GetUltimateOwner(): Mob ;
    SetPetID(NewPetID: number): void;
    GetPetID(): number;
    GetPetType(): PetType;
    SetPetType(p: PetType): void;
    GetPetPower(): number;
    SetPetPower(p: number): void;
    IsFamiliar(): boolean;
    IsAnimation(): boolean;
    IsCharmed(): boolean;
    IsTargetLockPet(): boolean;
    GetPetTargetLockID(): number;
    SetPetTargetLockID(value: number): void;
    SetOwnerID(new_owner_id: number): void;
    GetOwnerID(): number;
    HasOwner(): boolean;
    IsPet(): boolean;
    HasPet(): boolean;
    HasTempPetsActive(): boolean;
    SetTempPetsActive(i: boolean): void;
    GetTempPetCount(): number;
    SetTempPetCount(i: number): void;
    HasPetAffinity(): boolean;
    IsPetOwnerBot(): boolean;
    SetPetOwnerBot(b: boolean): void;
    IsPetOwnerClient(): boolean;
    SetPetOwnerClient(b: boolean): void;
    IsPetOwnerNPC(): boolean;
    SetPetOwnerNPC(b: boolean): void;
    IsTempPet(): boolean;
    SetTempPet(value: boolean): void;
    IsHorse(): boolean;
    GetPetAvoidanceBonusFromOwner(): number;
    GetPetACBonusFromOwner(): number;
    GetPetATKBonusFromOwner(): number;
    GetBodyType(): bodyType;
    GetOrigBodyType(): bodyType;
    SetBodyType(new_body: bodyType, overwrite_orig: boolean): void;
    SetAttackTimer(): void;
    SetInvul(invul: boolean): void;
    GetInvul(): boolean;
    SetExtraHaste(Haste: number): void;
    GetHaste(): number;
    GetMeleeMitigation(): number;
    GetWeaponDamageBonus(weapon: ItemData , offhand: boolean): number;
    GetDamageTable(): DamageTable ;
    ApplyDamageTable(hit: DamageHitInfo ): void;
    GetHandToHandDamage(): number;
    CanThisClassDoubleAttack(): boolean;
    CanThisClassTripleAttack(): boolean;
    CanThisClassDualWield(): boolean;
    CanThisClassRiposte(): boolean;
    CanThisClassDodge(): boolean;
    CanThisClassParry(): boolean;
    CanThisClassBlock(): boolean;
    GetHandToHandDelay(): number;
    GetClassLevelFactor(): number;
    Mesmerize(): void;
    IsMezzed(): boolean;
    IsStunned(): boolean;
    IsSilenced(): boolean;
    IsAmnesiad(): boolean;
    ReduceDamage(damage: number): number;
    AffectMagicalDamage(damage: number, spell_id: number, iBuffTic: bool, attacker: Mob ): number;
    ReduceAllDamage(damage: number): number;
    DoSpecialAttackDamage(who: Mob , skill: SkillType, base_damage: number, min_damage: number, hate_override: number, ReuseTime: number): void;
    DoThrowingAttackDmg(other: Mob , RangeWeapon: ItemInstance , AmmoItem: ItemData , weapon_damage: number, chance_mod: number, focus: number, ReuseTime: number, range_id: number, AmmoSlot: number, speed: float, DisableProcs: boolean): void;
    DoMeleeSkillAttackDmg(other: Mob , weapon_damage: number, skillinuse: SkillType, chance_mod: number, focus: number, can_riposte: boolean, ReuseTime: number): void;
    DoArcheryAttackDmg(other: Mob , RangeWeapon: ItemInstance , Ammo: ItemInstance , weapon_damage: number, chance_mod: number, focus: number, ReuseTime: number, range_id: number, ammo_id: number, AmmoItem: ItemData , AmmoSlot: number, speed: float, DisableProcs: boolean): void;
    TryProjectileAttack(other: Mob , item: ItemData , skillInUse: SkillType, weapon_dmg: number, RangeWeapon: ItemInstance , Ammo: ItemInstance , AmmoSlot: number, speed: float, DisableProcs: boolean): boolean;
    ProjectileAttack(): void;
    HasProjectileAttack(): boolean;
    SetProjectileAttack(value: boolean): void;
    GetRangeDistTargetSizeMod(other: Mob ): float;
    CanDoSpecialAttack(other: Mob ): boolean;
    Flurry(opts: ExtraAttackOptions ): boolean;
    Rampage(opts: ExtraAttackOptions ): boolean;
    AddRampage(arg0: Mob ): boolean;
    ClearRampage(): void;
    RemoveFromRampageList(mob: Mob , remove_feigned: boolean): void;
    SetBottomRampageList(): void;
    SetTopRampageList(): void;
    AreaRampage(opts: ExtraAttackOptions ): void;
    IsSpecialAttack(arg0: eSpecialAttacks): boolean;
    StartEnrage(): void;
    ProcessEnrage(): void;
    IsEnraged(): boolean;
    Taunt(who: NPC , always_succeed: boolean, chance_bonus: number, from_spell: boolean, bonus_hate: number): void;
    AI_Init(): void;
    AI_Start(iMoveDelay: number): void;
    AI_Stop(): void;
    AI_ShutDown(): void;
    AI_Process(): void;
    ClearEntityVariables(): boolean;
    DeleteEntityVariable(variable_name: string): boolean;
    GetEntityVariable(variable_name: string): string;
    GetEntityVariables(): string;
    SetEntityVariable(variable_name: string, variable_value: string): void;
    EntityVariableExists(variable_name: string): boolean;
    AI_Event_Engaged(attacker: Mob , yell_for_help: boolean): void;
    AI_Event_NoLongerEngaged(): void;
    GetSpecialFactionCon(iOther: Mob ): FACTION_VALUE;
    IsAIControlled(): bool;
    GetAggroRange(): float;
    GetAssistRange(): float;
    SetPetOrder(i: eStandingPetOrder): void;
    GetPetOrder(): eStandingPetOrder;
    SetHeld(nState: boolean): void;
    IsHeld(): bool;
    SetGHeld(nState: boolean): void;
    IsGHeld(): bool;
    SetNoCast(nState: boolean): void;
    IsNoCast(): bool;
    SetFocused(nState: boolean): void;
    IsFocused(): bool;
    SetPetStop(nState: boolean): void;
    IsPetStop(): bool;
    SetPetRegroup(nState: boolean): void;
    IsPetRegroup(): bool;
    IsRoamer(): bool;
    GetWanderType(): number;
    IsRooted(): bool;
    IsPermaRooted(): bool;
    GetSnaredAmount(): number;
    IsPseudoRooted(): bool;
    SetPseudoRoot(prState: boolean): void;
    GetCurWp(): number;
    GetFearSpeed(): number;
    IsFeared(): boolean;
    StartFleeing(): void;
    ProcessFlee(): void;
    CheckFlee(): void;
    IsBlind(): boolean;
    CheckAggro(other: Mob ): boolean;
    CalculateHeadingToTarget(in_x: float, in_y: float): float;
    WalkTo(x: float, y: float, z: float): void;
    RunTo(x: float, y: float, z: float): void;
    NavigateTo(x: float, y: float, z: float): void;
    RotateTo(new_heading: float): void;
    RotateToWalking(new_heading: float): void;
    RotateToRunning(new_heading: float): void;
    StopNavigation(): void;
    CalculateDistance(x: float, y: float, z: float): float;
    CalculateDistance(mob: Mob ): float;
    GetGroundZ(new_x: float, new_y: float, z_offset: float): float;
    SendTo(new_x: float, new_y: float, new_z: float): void;
    SendToFixZ(new_x: float, new_y: float, new_z: float): void;
    GetZOffset(): float;
    GetDefaultRaceSize(race_id: number, gender_id: number): float;
    FixZ(z_find_offset: number, fix_client_z: boolean): void;
    GetFixedZ(destination: vec3 , z_find_offset: number): float;
    GetStuckBehavior(): number;
    NPCSpecialAttacks(parse: char , permtag: number, reset: boolean, remove: boolean): void;
    DontHealMeBefore(): number;
    DontBuffMeBefore(): number;
    DontDotMeBefore(): number;
    DontRootMeBefore(): number;
    DontSnareMeBefore(): number;
    DontCureMeBefore(): number;
    SetDontRootMeBefore(time: number): void;
    SetDontHealMeBefore(time: number): void;
    SetDontBuffMeBefore(time: number): void;
    SetDontDotMeBefore(time: number): void;
    SetDontSnareMeBefore(time: number): void;
    SetDontCureMeBefore(time: number): void;
    SaveSpellLoc(): void;
    GetSpellX(): float;
    GetSpellY(): float;
    GetSpellZ(): float;
    IsGrouped(): boolean;
    SetGrouped(v: boolean): void;
    IsRaidGrouped(): boolean;
    SetRaidGrouped(v: boolean): void;
    IsLooting(): number;
    SetLooting(val: number): void;
    CheckWillAggro(mob: Mob ): boolean;
    InstillDoubt(who: Mob ): void;
    Charmed(): boolean;
    GetLevelHP(tlevel: number): number;
    GetZoneID(): number;
    GetInstanceVersion(): number;
    CheckAggroAmount(spell_id: number, target: Mob , isproc: boolean): number;
    CheckHealAggroAmount(spell_id: number, target: Mob , heal_possible: number): number;
    GetInstrumentMod(spell_id: number): number;
    CalcSpellEffectValue(spell_id: number, effect_id: number, caster_level: number, instrument_mod: number, caster: Mob , ticsremaining: number, casterid: number): number;
    CalcSpellEffectValue_formula(formula: number, base_value: number, max_value: number, caster_level: number, spell_id: number, ticsremaining: number): number;
    CheckStackConflict(spellid1: number, caster_level1: number, spellid2: number, caster_level2: number, caster1: Mob , caster2: Mob , buffslot: number): number;
    GetCastedSpellInvSlot(): number;
    GetNextHPEvent(): number;
    SetNextHPEvent(hpevent: number): void;
    SendItemAnimation(to: Mob , item: ItemData , skillInUse: SkillType, velocity: float): void;
    GetNextIncHPEvent(): number;
    SetNextIncHPEvent(inchpevent: number): void;
    DivineAura(): boolean;
    Sanctuary(): boolean;
    HasNPCSpecialAtk(parse: char ): boolean;
    HasSpecialAbilities(): boolean;
    GetSpecialAbility(ability: number): number;
    GetSpecialAbilityParam(ability: number, param: number): number;
    SetSpecialAbility(ability: number, level: number): void;
    SetSpecialAbilityParam(ability: number, param: number, value: number): void;
    StartSpecialAbilityTimer(ability: number, time: number): void;
    StopSpecialAbilityTimer(ability: number): void;
    GetSpecialAbilityTimer(ability: number): Timer ;
    ClearSpecialAbilities(): void;
    ProcessSpecialAbilities(str: string ): void;
    IsMoved(): boolean;
    SetMoved(moveflag: boolean): void;
    ShieldAbility(target_id: number, shielder_max_distance: number, shield_duration: number, shield_target_mitigation: number, shielder_mitigation: number, use_aa: boolean, can_shield_npc: boolean): boolean;
    DoShieldDamageOnShielder(shield_target: Mob , hit_damage_done: number, skillInUse: SkillType): void;
    ShieldAbilityFinish(): void;
    ShieldAbilityClearVariables(): void;
    GetShielderID(): number;
    SetShielderID(val: number): void;
    GetShieldTargetID(): number;
    SetShieldTargetID(val: number): void;
    GetShieldTargetMitigation(): number;
    SetShieldTargetMitigation(val: number): void;
    GetShielderMitigation(): number;
    SetShielderMitigation(val: number): void;
    GetMaxShielderDistance(): number;
    SetShielderMaxDistance(val: number): void;
    IsWeaponStanceEnabled(): boolean;
    SetWeaponStanceEnabled(val: boolean): void;
    GetCurrentWayPoint(): vec4;
    GetCWPP(): float;
    GetCWP(): number;
    SetCurrentWP(waypoint: number): void;
    GetReverseFactionCon(iOther: Mob ): FACTION_VALUE;
    IsUnderwaterOnly(): bool;
    IsTrackable(): boolean;
    GetAIThinkTimer(): Timer ;
    GetAIMovementTimer(): Timer ;
    GetAttackTimer(): Timer;
    GetAttackDWTimer(): Timer;
    IsFindable(): boolean;
    GetManaPercent(): number;
    GetEndurancePercent(): number;
    IsBlockedBuff(SpellID: number): boolean;
    IsBlockedPetBuff(SpellID: number): boolean;
    GetGlobal(varname: char ): string;
    SetGlobal(varname: char , newvalue: char , options: number, duration: char , other: Mob ): void;
    TarGlobal(varname: char , value: char , duration: char , npcid: number, charid: number, zoneid: number): void;
    DelGlobal(varname: char ): void;
    SetEmoteID(emote: number): void;
    GetEmoteID(): number;
    HasSpellEffect(effect_id: number): boolean;
    GetRacePlural(): string;
    GetClassPlural(): string;
    TuneGetStats(defender: Mob , attacker: Mob ): void;
    TuneGetACByPctMitigation(defender: Mob , attacker: Mob , pct_mitigation: float, interval: number, max_loop: number, atk_override: number, Msg: number): void;
    TuneGetATKByPctMitigation(defender: Mob , attacker: Mob , pct_mitigation: float, interval: number, max_loop: number, ac_override: number, Msg: number): void;
    TuneGetAvoidanceByHitChance(defender: Mob , attacker: Mob , hit_chance: float, interval: number, max_loop: number, accuracy_override: number, Msg: number): void;
    TuneGetAccuracyByHitChance(defender: Mob , attacker: Mob , hit_chance: float, interval: number, max_loop: number, avoidance_override: number, Msg: number): void;
    TuneClientGetMeanDamage(other: Mob , ac_override: number, atk_override: number, add_ac: number, add_atk: number): number;
    TuneClientGetMaxDamage(other: Mob ): number;
    TuneClientGetMinDamage(other: Mob , max_hit: number): number;
    TuneGetACMitigationPct(defender: Mob , attacker: Mob ): float;
    TuneGetOffense(defender: Mob , attacker: Mob , atk_override: number): number;
    TuneGetAccuracy(defender: Mob , attacker: Mob , accuracy_override: number, add_accuracy: number): number;
    TuneGetAvoidance(defender: Mob , attacker: Mob , avoidance_override: number, add_avoidance: number): number;
    TuneGetHitChance(defender: Mob , attacker: Mob , avoidance_override: number, accuracy_override: number, add_avoidance: number, add_accuracy: number): float;
    TuneGetAvoidMeleeChance(defender: Mob , attacker: Mob , type: number): float;
    TuneCalcEvasionBonus(final_avoidance: number, base_avoidance: number): number;
    TuneNPCAttack(other: Mob , no_avoid: boolean, no_hit_chance: boolean, hit_chance_bonus: number, ac_override: number, atk_override: number, add_ac: number, add_atk: number, get_offense: boolean, get_accuracy: boolean, avoidance_override: number, accuracy_override: number, add_avoidance: number, add_accuracy: number): number;
    TuneClientAttack(other: Mob , no_avoid: boolean, no_hit_chance: boolean, hit_chance_bonus: number, ac_override: number, atk_override: number, add_ac: number, add_atk: number, get_offense: boolean, get_accuracy: boolean, avoidance_override: number, accuracy_override: number, add_avoidance: number, add_accuracy: number): number;
    TuneDoAttack(other: Mob , hit: DamageHitInfo , opts: ExtraAttackOptions , no_avoid: boolean, no_hit_chance: boolean, ac_override: number, add_ac: number, avoidance_override: number, accuracy_override: number, add_avoidance: number, add_accuracy: number): void;
    TuneMeleeMitigation(attacker: Mob , hit: DamageHitInfo , ac_override: number, add_ac: number): void;
    Tuneoffense(skill: SkillType, atk_override: number, add_atk: number): number;
    TuneACSum(skip_caps: boolean, ac_override: number, add_ac: number): number;
    TuneGetTotalToHit(skill: SkillType, chance_mod: number, accuracy_override: number, add_accurracy: number): number;
    Tunecompute_tohit(skillinuse: SkillType, accuracy_override: number, add_accuracy: number): number;
    TuneGetTotalDefense(avoidance_override: number, add_avoidance: number): number;
    Tunecompute_defense(avoidance_override: number, add_avoidance: number): number;
    TuneCheckHitChance(other: Mob , hit: DamageHitInfo , avoidance_override: number, add_avoidance: number): boolean;
    TuneAttackAnimation(Hand: number, weapon: ItemInstance , skillinuse: SkillType): SkillType;
    TuneCommonOutgoingHitSuccess(defender: Mob , hit: DamageHitInfo , opts: ExtraAttackOptions ): void;
    GetAA(rank_id: number, charges: number): number;
    GetAAByAAID(aa_id: number, charges: number): number;
    SetAA(rank_id: number, new_value: number, charges: number): boolean;
    ClearAAs(): void;
    CanUseAlternateAdvancementRank(rank: Rank ): boolean;
    CanPurchaseAlternateAdvancementRank(rank: Rank , check_price: boolean, check_grant: boolean): boolean;
    GetAlternateAdvancementCooldownReduction(rank_in: Rank ): number;
    ExpendAlternateAdvancementCharge(aa_id: number): void;
    CalcAABonuses(newbon: StatBonuses ): void;
    CalcAAFocus(type: focusType, rank: Rank , spell_id: number): number;
    ApplyAABonuses(rank: Rank , newbon: StatBonuses ): void;
    CheckAATimer(timer: number): boolean;
    CalcItemBonuses(b: StatBonuses ): void;
    AddItemBonuses(inst: ItemInstance , b: StatBonuses , is_augment: boolean, is_tribute: boolean, recommended_level_override: number, is_ammo_item: boolean): void;
    AdditiveWornBonuses(inst: ItemInstance , b: StatBonuses , is_augment: boolean): void;
    CalcRecommendedLevelBonus(current_level: number, recommended_level: number, base_stat: number): number;
    NPCAssistCap(): number;
    AddAssistCap(): void;
    DelAssistCap(): void;
    ResetAssistCap(): void;
    GetWeaponDamage(against: Mob , weapon_item: ItemData ): number;
    GetWeaponDamage(against: Mob , weapon_item: ItemInstance , hate: number): number;
    DoDamageCaps(base_damage: number): number;
    GetHPRegen(): number;
    GetHPRegenPerSecond(): number;
    GetManaRegen(): number;
    GetEnduranceRegen(): number;
    CanOpenDoors(): boolean;
    SetCanOpenDoors(can_open: boolean): void;
    SetFeigned(in_feigned: boolean): void;
    GetFeigned(): boolean;
    DeleteBucket(bucket_name: string): void;
    GetBucket(bucket_name: string): string;
    GetBucketExpires(bucket_name: string): string;
    GetBucketRemaining(bucket_name: string): string;
    SetBucket(bucket_name: string, bucket_value: string, expiration: string): void;
    GetMobTypeIdentifier(): number;
    CheckHeroicBonusesDataBuckets(bucket_name: string): float;
    DispatchZoneControllerEvent(evt: QuestEventID, init: Mob , data: string , extra: number, pointers: vector<any> ): number;
    IsHealRotationTarget(): boolean;
    JoinHealRotationTargetPool(heal_rotation: shared_ptr<HealRotation> ): boolean;
    LeaveHealRotationTargetPool(): boolean;
    HealRotationHealCount(): number;
    HealRotationExtendedHealCount(): number;
    HealRotationHealFrequency(): float;
    HealRotationExtendedHealFrequency(): float;
    TargetOfHealRotation(): shared_ptr<HealRotation> ;
    SetManualFollow(flag: boolean): void;
    GetManualFollow(): boolean;
    DrawDebugCoordinateNode(node_name: string, vec: vec4): void;
    CalcHeroicBonuses(newbon: StatBonuses ): void;
    GetScopedBucketKeys(): DataBucketKey;
    GetCombatRecord(): CombatRecord ;
    GetWasSpawnedInWater(): boolean;
    SetSpawnedInWater(spawned_in_water: boolean): void;
    CommonDamage(other: Mob , damage: number, spell_id: number, attack_skill: SkillType, avoidable: bool , buffslot: number, iBuffTic: bool, specal: eSpecialAttacks): void;
    GetProcID(spell_id: number, effect_index: number): number;
    _GetWalkSpeed(): number;
    _GetRunSpeed(): number;
    _GetFearSpeed(): number;
    AI_EngagedCastCheck(): boolean;
    AI_PursueCastCheck(): boolean;
    AI_IdleCastCheck(): boolean;
    GetPlayerState(): number;
    AddPlayerState(new_state: number): void;
    RemovePlayerState(old_state: number): void;
    SendAddPlayerState(new_state: PlayerState): void;
    SendRemovePlayerState(old_state: PlayerState): void;
    CalcSpellBonuses(newbon: StatBonuses ): void;
    CalcBonuses(): void;
    TrySkillProc(on: Mob , skill: SkillType, ReuseTime: number, Success: boolean, hand: number, IsDefensive: boolean): void;
    PassLimitToSkill(skill: SkillType, spell_id: number, proc_type: number, aa_id: number): boolean;
    PassLimitClass(Classes_: number, Class_: number): boolean;
    TryCastOnSkillUse(on: Mob , skill: SkillType): void;
    TryDefensiveProc(on: Mob , hand: number): void;
    TryWeaponProc(inst: ItemInstance , weapon: ItemData , on: Mob , hand: number): void;
    TrySpellProc(inst: ItemInstance , weapon: ItemData , on: Mob , hand: number): void;
    TryCombatProcs(weapon: ItemInstance , on: Mob , hand: number, weapon_data: ItemData ): void;
    ExecWeaponProc(weapon: ItemInstance , spell_id: number, on: Mob , level_override: number): void;
    GetProcChances(ProcBonus: float, hand: number): float;
    GetDefensiveProcChances(ProcBonus: float , ProcChance: float , hand: number, on: Mob ): float;
    GetSkillProcChances(ReuseTime: number, hand: number): float;
    GetWeaponSpeedbyHand(hand: number): number;
    GetBaseSkillDamage(skill: SkillType, target: Mob ): number;
    GetFocusEffect(type: focusType, spell_id: number, caster: Mob , from_buff_tic: boolean): number;
    GetInv(): InventoryProfile ;
    CalculateNewFearpoint(): void;
    FindGroundZ(new_x: float, new_y: float, z_offset: float): float;
    FindDestGroundZ(dest: vec3, z_offset: float): float;
    GetSympatheticProcChances(spell_id: number, ProcRateMod: number, ItemProcRate: number): float;
    GetSympatheticSpellProcRate(spell_id: number): number;
    GetSympatheticSpellProcID(spell_id: number): number;
    AddFactionBonus(pFactionID: number, bonus: number): void;
    GetFactionBonus(pFactionID: number): number;
    AddItemFactionBonus(pFactionID: number, bonus: number): void;
    GetItemFactionBonus(pFactionID: number): number;
    ClearItemFactionBonuses(): void;
    QGVarDuration(fmt: char ): number;
    InsertQuestGlobal(charid: number, npcid: number, zoneid: number, name: char , value: char , expdate: number): void;
    SetHeroicStrBonuses(n: StatBonuses ): void;
    SetHeroicStaBonuses(n: StatBonuses ): void;
    SetHeroicAgiBonuses(n: StatBonuses ): void;
    SetHeroicDexBonuses(n: StatBonuses ): void;
    SetHeroicIntBonuses(n: StatBonuses ): void;
    SetHeroicWisBonuses(n: StatBonuses ): void;
    DoSpellInterrupt(spell_id: number, mana_cost: number, my_curmana: number): void;
    HandleDoorOpen(): void
  }

  export class NPC extends Mob {
    constructor(npc_type_data: NPCType , respawn: Spawn2 , position: vec4 , iflymode: GravityBehavior, IsCorpse: boolean);;
  constructor();
      MerchantType : number;
    merchant_open : boolean;
    m_SpawnPoint : vec4;
    proximity : NPCProximity ;
    respawn2 : Spawn2 ;
    AIautocastspell_timer : unique_ptr<Timer >;
    SpawnNPC(spawncommand: char , position: vec4 , client: Client ): NPC ;
    SpawnZoneController(): boolean;
    IsRecordLootStats(): boolean;
    SetRecordLootStats(record_loot_stats: boolean): void;
    GetRolledItems(): number;
    GetRolledItemCount(item_id: number): number;
    SpawnNodeNPC(name: string, last_name: string, position: vec4 ): NPC ;
    SpawnGridNodeNPC(position: vec4 , grid_id: number, grid_number: number, zoffset: number): void;
    SpawnZonePointNodeNPC(name: string, position: vec4 ): NPC ;
    Death(killer_mob: Mob , damage: number, spell_id: number, attack_skill: SkillType, killed_by: KilledByTypes): boolean;
    Damage(from: Mob , damage: number, spell_id: number, attack_skill: SkillType, avoidable: boolean, buffslot: number, iBuffTic: boolean, special: eSpecialAttacks): void;
    Attack(other: Mob , Hand: number, FromRiposte: boolean, IsStrikethrough: boolean, IsFromSpell: boolean, opts: ExtraAttackOptions ): boolean;
    HasRaid(): boolean;
    HasGroup(): boolean;
    GetRaid(): Raid ;
    GetGroup(): Group ;
    IsNPC(): boolean;
    Process(): boolean;
    AI_Init(): void;
    AI_Start(iMoveDelay: number): void;
    AI_Stop(): void;
    AI_DoMovement(): void;
    AI_SetupNextWaypoint(): void;
    AI_AddNPCSpells(iDBSpellsID: number): boolean;
    AI_AddNPCSpellsEffects(iDBSpellsEffectsID: number): boolean;
    AI_EngagedCastCheck(): boolean;
    AI_HasSpells(): boolean;
    AI_HasSpellsEffects(): boolean;
    ApplyAISpellEffects(newbon: StatBonuses ): void;
    AI_PursueCastCheck(): boolean;
    AI_IdleCastCheck(): boolean;
    AI_Event_SpellCastFinished(iCastSucceeded: boolean, slot: number): void;
    AICheckCloseBeneficialSpells(caster: NPC , chance: number, cast_range: float, spell_types: number): boolean;
    AIYellForHelp(sender: Mob , attacker: Mob ): void;
    LevelScale(): void;
    SetTarget(mob: Mob ): void;
    GetSkill(skill_num: SkillType): number;
    CalcBonuses(): void;
    GetCurrentBuffSlots(): number;
    GetCurrentSongSlots(): number;
    GetCurrentDiscSlots(): number;
    GetMaxBuffSlots(): number;
    GetMaxSongSlots(): number;
    GetMaxDiscSlots(): number;
    GetMaxTotalSlots(): number;
    GetPetMaxTotalSlots(): number;
    InitializeBuffSlots(): void;
    UninitializeBuffSlots(): void;
    SetAttackTimer(): void;
    RangedAttack(other: Mob ): void;
    ThrowingAttack(other: Mob ): void;
    GetNumberOfAttacks(): number;
    DoRangedAttackDmg(other: Mob , Launch: boolean, damage_mod: number, chance_mod: number, skill: SkillType, speed: float, IDFile: char ): void;
    IsFactionListAlly(other_faction: number): boolean;
    IsGuard(): boolean;
    CheckNPCFactionAlly(other_faction: number): FACTION_VALUE;
    GetReverseFactionCon(iOther: Mob ): FACTION_VALUE;
    GoToBind(bind_number: number): void;
    Gate(bind_number: number): void;
    GetPetState(buffs: SpellBuff_Struct , items: number, name: char ): void;
    SetPetState(buffs: SpellBuff_Struct , items: number): void;
    SpellProcess(): void;
    FillSpawnStruct(ns: NewSpawn_Struct , ForWho: Mob ): void;
    AddItem(item: ItemData , charges: number, equip_item: boolean): void;
    AddItem(item_id: number, charges: number, equip_item: boolean, augment_one: number, augment_two: number, augment_three: number, augment_four: number, augment_five: number, augment_six: number): void;
    AddLootTable(): void;
    AddLootTable(loottable_id: number, is_global: boolean): void;
    AddLootDropTable(lootdrop_id: number, drop_limit: number, min_drop: number): void;
    CheckGlobalLootTables(): void;
    RemoveItem(item_id: number, quantity: number, slot: number): void;
    CheckTrivialMinMaxLevelDrop(killer: Mob ): void;
    ClearLootItems(): void;
    GetLootItems(): LootItems ;
    GetItem(slot_id: number): LootItem ;
    AddLootCash(in_copper: number, in_silver: number, in_gold: number, in_platinum: number): void;
    RemoveLootCash(): void;
    QueryLoot(to: Client , is_pet_query: boolean): void;
    HasItem(item_id: number): boolean;
    CountItem(item_id: number): number;
    GetLootItemIDBySlot(loot_slot: number): number;
    GetFirstLootSlotByItemID(item_id: number): number;
    GetLootList(): number;
    CountLoot(): number;
    GetLoottableID(): number;
    DropsGlobalLoot(): boolean;
    GetCopper(): number;
    GetSilver(): number;
    GetGold(): number;
    GetPlatinum(): number;
    SetCopper(amt: number): void;
    SetSilver(amt: number): void;
    SetGold(amt: number): void;
    SetPlatinum(amt: number): void;
    DescribeAggro(to_who: Client , mob: Mob , verbose: boolean): void;
    UpdateEquipmentLight(): void;
    CalcMaxMana(): number;
    SetGrid(grid_: number): void;
    SetSpawnGroupId(sg2: number): void;
    SetWaypointMax(wp_: number): void;
    SetSaveWaypoint(wp_: number): void;
    GetWaypointMax(): number;
    GetGrid(): number;
    GetSpawnGroupId(): number;
    GetSpawnPointID(): number;
    GetSpawnPoint(): vec4 const;
    GetGuardPoint(): vec4 const;
    GetGuardPointAnim(): EmuAppearance;
    SaveGuardPointAnim(anim: EmuAppearance): void;
    GetPrimSkill(): number;
    GetSecSkill(): number;
    GetRangedSkill(): number;
    SetPrimSkill(skill_type: number): void;
    SetSecSkill(skill_type: number): void;
    SetRangedSkill(skill_type: number): void;
    MerchantOpenShop(): void;
    MerchantCloseShop(): void;
    IsMerchantOpen(): boolean;
    Depop(start_spawn_timer: boolean): void;
    Stun(duration: number): void;
    UnStun(): void;
    GetSwarmOwner(): number;
    GetSwarmTarget(): number;
    SetSwarmTarget(target_id: number): void;
    DepopSwarmPets(): void;
    TryDepopTargetLockedPets(current_target: Mob ): void;
    PetOnSpawn(ns: NewSpawn_Struct ): void;
    SignalNPC(_signal_id: number): void;
    SendPayload(payload_id: number, payload_value: string): void;
    GetNPCFactionID(): number;
    GetPrimaryFaction(): number;
    GetFactionAmount(): number;
    GetNPCHate(in_ent: Mob ): number;
    IsOnHatelist(p: Mob ): boolean;
    SetNPCFactionID(arg0: number): void;
    GetMaxDMG(): number;
    GetMinDMG(): number;
    GetBaseDamage(): number;
    GetMinDamage(): number;
    GetSlowMitigation(): float;
    GetAttackSpeed(): float;
    GetAttackDelay(): number;
    IsAnimal(): boolean;
    GetPetSpellID(): number;
    SetPetSpellID(amt: number): void;
    GetMaxDamage(tlevel: number): number;
    SetTaunting(is_taunting: boolean): void;
    IsTaunting(): boolean;
    PickPocket(thief: Client ): void;
    Disarm(client: Client , chance: number): void;
    StartSwarmTimer(duration: number): void;
    DisableSwarmTimer(): void;
    AddLootDrop(item2: ItemData , loot_drop: LootdropEntries, wear_change: boolean, augment_one: number, augment_two: number, augment_three: number, augment_four: number, augment_five: number, augment_six: number): void;
    MeetsLootDropLevelRequirements(loot_drop: LootdropEntries, verbose: boolean): boolean;
    CheckSignal(): void;
    DoClassAttacks(target: Mob ): void;
    IsNotTargetableWithHotkey(): boolean;
    GetNPCHPRegen(): number;
    GetAmmoIDfile(): char ;
    ModifyStatsOnCharm(is_charm_removed: boolean): void;
    GetMaxWp(): number;
    DisplayWaypointInfo(client: Client ): void;
    CalculateNewWaypoint(): void;
    AssignWaypoints(grid_id: number, start_wp: number): void;
    SetWaypointPause(): void;
    UpdateWaypoint(wp_index: number): void;
    StopWandering(): void;
    ResumeWandering(): void;
    PauseWandering(pausetime: number): void;
    MoveTo(position: vec4 , saveguardspot: boolean): void;
    GetClosestWaypoints(wp_list: list<wplist> , count: number, location: vec3 ): void;
    GetClosestWaypoint(location: vec3 ): number;
    GetEquippedItemFromTextureSlot(material_slot: number): number;
    GetEquipmentMaterial(material_slot: number): number;
    NextGuardPosition(): void;
    SaveGuardSpot(ClearGuardSpot: boolean): void;
    SaveGuardSpot(pos: vec4 ): void;
    IsGuarding(): boolean;
    SaveGuardSpotCharm(): void;
    DescribeSpecialAbilities(c: Client ): void;
    GetMeleeTexture1(): number;
    GetMeleeTexture2(): number;
    RestoreGuardSpotCharm(): void;
    AI_SetRoambox(max_distance: float, roam_distance_variance: float, delay: number, min_delay: number): void;
    AI_SetRoambox(distance: float, max_x: float, min_x: float, max_y: float, min_y: float, delay: number, min_delay: number): void;
    LoadMercenaryTypes(): void;
    LoadMercenaries(): void;
    GetMercenaryTypesList(): list<MercType >;
    GetMercenaryTypesList(expansion: number): list<MercType >;
    GetMercenariesList(): list<MercData >;
    GetMercenariesList(expansion: number): list<MercData >;
    GetNumMercenaryTypes(): number;
    GetNumMercenaryTypes(expansion: number): number;
    GetNumberOfMercenaries(): number;
    GetNumberOfMercenaries(expansion: number): number;
    GetNPCAggro(): boolean;
    SetNPCAggro(in_npc_aggro: boolean): void;
    GiveNPCTypeData(ours: NPCType ): void;
    GetNPCSpellsID(): number;
    GetNPCSpellsEffectsID(): number;
    GetProximityMinX(): float;
    GetProximityMaxX(): float;
    GetProximityMinY(): float;
    GetProximityMaxY(): float;
    GetProximityMinZ(): float;
    GetProximityMaxZ(): float;
    IsProximitySet(): boolean;
    GetQGlobals(): QGlobalCache ;
    CreateQGlobals(): QGlobalCache ;
    GetSwarmInfo(): SwarmPet ;
    SetSwarmInfo(mSwarmInfo: SwarmPet ): void;
    GetAccuracyRating(): number;
    SetAccuracyRating(d: number): void;
    GetAvoidanceRating(): number;
    SetAvoidanceRating(d: number): void;
    GetRawAC(): number;
    GetNPCStat(stat: string ): float;
    ModifyNPCStat(stat: string , value: string ): void;
    SetLevel(in_level: number, command: boolean): void;
    IsLDoNTrapped(): boolean;
    SetLDoNTrapped(n: boolean): void;
    GetLDoNTrapType(): number;
    SetLDoNTrapType(n: number): void;
    GetLDoNTrapSpellID(): number;
    SetLDoNTrapSpellID(n: number): void;
    IsLDoNLocked(): boolean;
    SetLDoNLocked(n: boolean): void;
    GetLDoNLockedSkill(): number;
    SetLDoNLockedSkill(n: number): void;
    IsLDoNTrapDetected(): boolean;
    SetLDoNTrapDetected(n: boolean): void;
    GetCombatEvent(): bool;
    SetCombatEvent(b: boolean): void;
    HasPrivateCorpse(): bool;
    IsUnderwaterOnly(): bool;
    IsQuestNPC(): bool;
    GetRawNPCTypeName(): char ;
    GetKillExpMod(): number;
    ChangeLastName(last_name: string): void;
    ClearLastName(): void;
    GetDepop(): boolean;
    NPCSlotTexture(slot: number, texture: number): void;
    GetAdventureTemplate(): number;
    AddSpellToNPCList(iPriority: number, iSpellID: number, iType: number, iManaCost: number, iRecastDelay: number, iResistAdjust: number, min_hp: number, max_hp: number): void;
    AddSpellEffectToNPCList(iSpellEffectID: number, base_value: number, limit: number, max_value: number, apply_bonus: boolean): void;
    RemoveSpellFromNPCList(spell_id: number): void;
    RemoveSpellEffectFromNPCList(iSpellEffectID: number, apply_bonus: boolean): void;
    HasAISpellEffect(spell_effect_id: number): boolean;
    GetRefaceTimer(): Timer ;
    GetAltCurrencyType(): number;
    GetNPCEmote(emote_id: number, event_: number): NPC_Emote_Struct ;
    DoNPCEmote(event_: number, emote_id: number, t: Mob ): void;
    CanTalk(): boolean;
    DoQuestPause(other: Mob ): void;
    SetSpellScale(amt: float): void;
    GetSpellScale(): float;
    SetHealScale(amt: float): void;
    GetHealScale(): float;
    SetSpellFocusDMG(NewSpellFocusDMG: number): void;
    GetSpellFocusDMG(): number;
    SetSpellFocusHeal(NewSpellFocusHeal: number): void;
    GetSpellFocusHeal(): number;
    GetSpawnKillCount(): number;
    GetScore(): number;
    AISpellsList(c: Client ): void;
    GetInnateProcSpellID(): number;
    GetHeroForgeModel(): number;
    SetHeroForgeModel(model: number): void;
    IsRaidTarget(): boolean;
    IsRareSpawn(): boolean;
    ResetHPUpdateTimer(): void;
    IgnoreDespawn(): boolean;
    SetSimpleRoamBox(box_size: float, move_distance: float, move_delay: number): void;
    GetRoamboxMaxX(): float;
    GetRoamboxMaxY(): float;
    GetRoamboxMinX(): float;
    GetRoamboxMinY(): float;
    GetRoamboxDistance(): float;
    GetRoamboxDestinationX(): float;
    GetRoamboxDestinationY(): float;
    GetRoamboxDestinationZ(): float;
    GetRoamboxDelay(): number;
    GetRoamboxMinDelay(): number;
    GetArmTexture(): number;
    GetBracerTexture(): number;
    GetHandTexture(): number;
    GetFeetTexture(): number;
    GetLegTexture(): number;
    GetCharmedAccuracy(): number;
    GetCharmedArmorClass(): number;
    GetCharmedAttack(): number;
    GetCharmedAttackDelay(): number;
    GetCharmedAvoidance(): number;
    GetCharmedMaxDamage(): number;
    GetCharmedMinDamage(): number;
    GetAlwaysAggro(): boolean;
    GetNPCAggro(): boolean;
    GetIgnoreDespawn(): boolean;
    GetSkipGlobalLoot(): boolean;
    GetStuckBehavior(): number;
    IsSkipAutoScale(): boolean;
    ScaleNPC(npc_level: number, always_scale: boolean, override_special_abilities: boolean): void;
    RecalculateSkills(): void;
    ReloadSpells(): void;
    SendPositionToClients(): void;
    CanPathTo(x: float, y: float, z: float): boolean;
    HandleRoambox(): void;
    AICastSpell(tar: Mob , iChance: number, iSpellTypes: number, bInnates: boolean): boolean;
    AIDoSpellCast(i: number, tar: Mob , mana_cost: number, oDontDoAgainBefore: number): boolean;
    GetFocusEffect(type: focusType, spell_id: number, caster: Mob , from_buff_tic: boolean): number
  }

  export class Encounter extends Mob {
    constructor(enc_name: char );;
  constructor();
  
    Death(killer_mob: Mob , damage: number, spell_id: number, attack_skill: SkillType, killed_by: KilledByTypes): boolean;
    Damage(from: Mob , damage: number, spell_id: number, attack_skill: SkillType, avoidable: boolean, buffslot: number, iBuffTic: boolean, special: eSpecialAttacks): void;
    Attack(other: Mob , Hand: number, FromRiposte: boolean, IsStrikethrough: boolean, IsFromSpell: boolean, opts: ExtraAttackOptions ): boolean;
    HasRaid(): boolean;
    HasGroup(): boolean;
    GetRaid(): Raid ;
    GetGroup(): Group ;
    IsEncounter(): boolean;
    GetEncounterName(): char ;
    Process(): boolean;
    Depop(not_used: boolean): void
  }

  export class Beacon extends Mob {
    constructor(in_pos: vec4 , lifetime: number);;
  constructor();
  
    Death(killer_mob: Mob , damage: number, spell_id: number, attack_skill: SkillType, killed_by: KilledByTypes): boolean;
    Damage(from: Mob , damage: number, spell_id: number, attack_skill: SkillType, avoidable: boolean, buffslot: number, iBuffTic: boolean, special: eSpecialAttacks): void;
    HasRaid(): boolean;
    HasGroup(): boolean;
    GetRaid(): Raid ;
    GetGroup(): Group ;
    Attack(other: Mob , Hand: number, FromRiposte: boolean, IsStrikethrough: boolean, IsFromSpell: boolean, opts: ExtraAttackOptions ): boolean;
    IsBeacon(): boolean;
    Process(): boolean;
    Depop(not_used: boolean): void;
    AELocationSpell(caster: Mob , cast_spell_id: number, in_resist_adjust: number): void
  }

  export class Zone {
    constructor(in_zoneid: number, in_instanceid: number, in_short_name: char );;
  constructor();
      is_zone_time_localized : boolean;
    quest_idle_override : boolean;
    did_adventure_actions : boolean;
    adv_data : char ;
    random : Random;
    zone_time : EQTime;
    pathing : IPathfinder ;
    npc_emote_list : vector<NPC_Emote_Struct  >;
    spawn2_list : LinkedList<Spawn2  >;
    zone_point_list : number;
    virtual_zone_point_list : number;
    zonemap : Map ;
    newzone_data : NewZone_Struct;
    spawn_conditions : SpawnConditionManager;
    spawn_group_list : SpawnGroupList;
    AlternateCurrencies : list<AltCurrencyDefinition_Struct >;
    VeteranRewards : list<InternalVeteranReward >;
    ldon_trap_list : number;
    merc_templates : number;
    merctable : number;
    npctable : number;
    ldon_trap_entry_list : number;
    merchanttable : number;
    merc_spells_list : number;
    merc_stance_list : number;
    tmpmerchanttable : number;
    adventure_entry_list_flavor : number;
    level_exp_mod : number;
    aa_abilities : number;
    aa_ranks : number;
    zone_grids : vector<Grid >;
    zone_grid_entries : vector<GridEntries >;
    dynamic_zone_cache : number;
    expedition_cache : number;
    dz_template_cache : number;
    exp_modifiers : number;
    weather_timer : time_t;
    spawn2_timer : Timer;
    hot_reload_timer : Timer;
    weather_intensity : number;
    zone_weather : number;
    loglevelvar : number;
    lootvar : number;
    merchantvar : number;
    tradevar : number;
    numzonepoints : number;
    watermap : WaterMap ;
    Bootup(iZoneID: number, iInstanceID: number, is_static: boolean): boolean;
    Shutdown(quiet: boolean): void;
    GetAlternateAdvancementAbility(id: number): Ability ;
    GetAlternateAdvancementAbilityByRank(rank_id: number): Ability ;
    GetAlternateAdvancementRank(rank_id: number): Rank ;
    IsIdleWhenEmpty(): boolean;
    SetIdleWhenEmpty(idle_when_empty: boolean): void;
    GetSecondsBeforeIdle(): number;
    SetSecondsBeforeIdle(seconds_before_idle: number): void;
    AggroLimitReached(): boolean;
    AllowMercs(): boolean;
    CanBind(): boolean;
    CanCastOutdoor(): boolean;
    CanDoCombat(): boolean;
    CanLevitate(): boolean;
    Depop(StartSpawnTimer: boolean): boolean;
    GetAuth(iIP: number, iCharName: char , oWID: number, oAccID: number, oCharID: number, oStatus: number, oLSKey: char , oTellsOff: bool ): boolean;
    HasGraveyard(): boolean;
    HasWeather(): boolean;
    Init(is_static: boolean): boolean;
    IsCity(): boolean;
    IsHotzone(): boolean;
    IsLoaded(): boolean;
    IsPVPZone(): boolean;
    IsSpellBlocked(spell_id: number, location: vec3 ): boolean;
    IsUCSServerAvailable(): boolean;
    IsZone(zone_id: number, instance_id: number): boolean;
    LoadGroundSpawns(): boolean;
    LoadZoneCFG(filename: char , instance_version: number): boolean;
    LoadZoneObjects(): boolean;
    IsSpecialBindLocation(location: vec4 ): boolean;
    Process(): boolean;
    SaveZoneCFG(): boolean;
    GetNpcPositionUpdateDistance(): number;
    SetNpcPositionUpdateDistance(in_npc_position_update_distance: number): void;
    GetSpellBlockedMessage(spell_id: number, location: vec3 ): char ;
    GetClosestZonePoint(location: vec3 , to_name: char , client: Client , max_distance: float): number;
    BuffTimersSuspended(): boolean;
    HasMap(): boolean;
    HasWaterMap(): boolean;
    InstantGrids(): boolean;
    IsStaticZone(): boolean;
    IsInstancePersistent(): bool;
    GetFileName(): char ;
    GetLongName(): char ;
    GetShortName(): char ;
    GetZoneType(): number;
    GetInstanceVersion(): number;
    GetMaxClients(): number;
    graveyard_id(): number;
    graveyard_zoneid(): number;
    GetInstanceID(): number;
    GetZoneID(): number;
    GetSafePoint(): vec4;
    GetGraveyardPoint(): vec4;
    GetGlobalLootTables(mob: NPC ): number;
    GetInstanceTimer(): Timer ;
    AddGlobalLootEntry(arg0: GlobalLootEntry ): void;
    SetZoneHasCurrentTime(time: boolean): void;
    ShowNPCGlobalLoot(c: Client , t: NPC ): void;
    ShowZoneGlobalLoot(c: Client ): void;
    GetZoneTotalBlockedSpells(): number;
    SaveTempItem(merchantid: number, npcid: number, item: number, charges: number, sold: boolean): number;
    MobsAggroCount(): number;
    GetDynamicZone(): DynamicZone ;
    GetMercTemplate(template_id: number): MercTemplate ;
    CreateQGlobals(): QGlobalCache ;
    GetQGlobals(): QGlobalCache ;
    GetAlternateAdvancementAbilityAndRank(id: number, points_spent: number): pair<Ability , AA::Rank  >;
    CountAuth(): number;
    CountSpawn2(): number;
    GetSpawnKillCount(in_spawnid: number): number;
    GetTempMerchantQuantity(NPCID: number, Slot: number): number;
    GetCurrencyID(item_id: number): number;
    GetCurrencyItemID(currency_id: number): number;
    GetAAName(aa_id: number): string;
    IsRaining(): boolean;
    IsSnowing(): boolean;
    GetZoneDescription(): string;
    SendReloadMessage(reload_type: string): void;
    ClearEXPModifier(c: Client ): void;
    GetAAEXPModifier(c: Client ): float;
    GetEXPModifier(c: Client ): float;
    SetAAEXPModifier(c: Client , aa_modifier: float): void;
    SetEXPModifier(c: Client , exp_modifier: float): void;
    AddAggroMob(): void;
    AddAuth(szic: ServerZoneIncomingClient_Struct ): void;
    ChangeWeather(): void;
    ClearBlockedSpells(): void;
    ClearNPCTypeCache(id: number): void;
    CalculateNpcUpdateDistanceSpread(): void;
    DelAggroMob(): void;
    DeleteQGlobal(name: string, npcID: number, charID: number, zoneID: number): void;
    Despawn(spawngroupID: number): void;
    DoAdventureActions(): void;
    DoAdventureAssassinationCountIncrease(): void;
    DoAdventureCountIncrease(): void;
    LoadMerchants(): void;
    GetTimeSync(): void;
    LoadAdventureFlavor(): void;
    LoadAlternateAdvancement(): void;
    LoadAlternateCurrencies(): void;
    LoadDynamicZoneTemplates(): void;
    LoadZoneBlockedSpells(): void;
    LoadLDoNTrapEntries(): void;
    LoadLDoNTraps(): void;
    LoadLevelEXPMods(): void;
    LoadGrids(): void;
    LoadMercenarySpells(): void;
    LoadMercenaryTemplates(): void;
    LoadNewMerchantData(merchantid: number): void;
    LoadNPCEmotes(v: vector<NPC_Emote_Struct > ): void;
    LoadTempMerchantData(): void;
    LoadVeteranRewards(): void;
    LoadZoneDoors(): void;
    ReloadStaticData(): void;
    ReloadWorld(global_repop: number): void;
    RemoveAuth(iCharName: char , iLSKey: char ): void;
    RemoveAuth(lsid: number): void;
    Repop(is_forced: boolean): void;
    RequestUCSServerStatus(): void;
    ResetAuth(): void;
    SetDate(year: number, month: number, day: number, hour: number, minute: number): void;
    SetInstanceTimer(new_duration: number): void;
    SetStaticZone(sz: boolean): void;
    SetTime(hour: number, minute: number, update_world: boolean): void;
    SetUCSServerAvailable(ucss_available: boolean, update_timestamp: number): void;
    SpawnConditionChanged(c: SpawnCondition , old_value: number): void;
    StartShutdownTimer(set_time: number): void;
    ResetShutdownTimer(): void;
    StopShutdownTimer(): void;
    UpdateQGlobal(qid: number, newGlobal: QGlobal): void;
    weatherSend(client: Client ): void;
    ClearSpawnTimers(): void;
    IsQuestHotReloadQueued(): boolean;
    SetQuestHotReloadQueued(in_quest_hot_reload_queued: boolean): void;
    CompareDataBucket(bucket_comparison: number, bucket_value: string , player_value: string ): boolean;
    GetClosestZonePoint(location: vec3 , to: number, client: Client , max_distance: float): number;
    GetClosestZonePointWithoutZone(x: float, y: float, z: float, client: Client , max_distance: float): number;
    GetInitgridsTimer(): Timer;
    GetInstanceTimeRemaining(): number;
    SetInstanceTimeRemaining(instance_time_remaining: number): void;
    GMSayHookCallBackProcess(log_category: number, func: char , message: string): void;
    SendDiscordMessage(webhook_id: number, message: string ): void;
    SendDiscordMessage(webhook_name: string , message: string ): void;
    DiscordWebhookMessageHandler(log_category: number, webhook_id: number, message: string ): void;
    GetMaxMovementUpdateRange(): number;
    SetIsHotzone(is_hotzone: boolean): void;
    ReloadContentFlags(): void;
    LoadNPCFaction(npc_faction_id: number): void;
    LoadNPCFactions(npc_faction_ids: number): void;
    ClearNPCFactions(): void;
    ReloadNPCFactions(): void;
    GetNPCFaction(npc_faction_id: number): NpcFaction ;
    GetNPCFactionEntries(npc_faction_id: number): vector<NpcFactionEntries >;
    LoadNPCFactionAssociation(npc_faction_id: number): void;
    LoadNPCFactionAssociations(npc_faction_ids: number): void;
    LoadFactionAssociation(faction_id: number): void;
    LoadFactionAssociations(faction_ids: number): void;
    ClearFactionAssociations(): void;
    ReloadFactionAssociations(): void;
    GetFactionAssociation(faction_id: number): FactionAssociation ;
    LoadLootTable(loottable_id: number): void;
    LoadLootTables(loottable_ids: number): void;
    ClearLootTables(): void;
    ReloadLootTables(): void;
    GetLootTable(loottable_id: number): Loottable ;
    GetLootTableEntries(loottable_id: number): vector<LoottableEntries >;
    GetLootdrop(lootdrop_id: number): Lootdrop;
    GetLootdropEntries(lootdrop_id: number): vector<LootdropEntries >;
    ClearBaseData(): void;
    GetBaseData(level: number, class_id: number): BaseData;
    LoadBaseData(): void;
    ReloadBaseData(): void
  }

  export class CLIENTPACKET {
    constructor();;
  constructor();
      app : EQApplicationPacket ;
    ack_req : boolean;

  }

  export class Client extends Mob {
    constructor(ieqs: EQStreamInterface );;
  constructor();
      CanUseReport : boolean;
    PendingTranslocate : boolean;
    TranslocateTime : time_t;
    PendingSacrifice : boolean;
    SacrificeCaster : string;
    PendingTranslocateData : PendingTranslocate_Struct;
    m_requesting_shared_task : boolean;
    m_shared_task_update : boolean;
    m_requested_shared_task_removal : boolean;
    respawn_options : list<RespawnOption >;
    trapid : number;
    p_raid_instance : Raid ;
    cheat_manager : CheatManager;
    XTargets : struct XTarget_Struct;
    ReconnectUCS(): void;
    RecordStats(): void;
    SetDisplayMobInfoWindow(display_mob_info_window: boolean): void;
    GetDisplayMobInfoWindow(): boolean;
    IsDevToolsEnabled(): boolean;
    SetDevToolsEnabled(in_dev_tools_enabled: boolean): void;
    IsEXPEnabled(): boolean;
    SetEXPEnabled(is_exp_enabled: boolean): void;
    GetEXPModifiers(): vector<EXPModifier >;
    SetEXPModifiers(exp_modifiers: vector<EXPModifier >): void;
    SetPrimaryWeaponOrnamentation(model_id: number): void;
    SetSecondaryWeaponOrnamentation(model_id: number): void;
    SendChatLineBreak(color: number): void;
    GotoPlayer(player_name: string): boolean;
    GotoPlayerGroup(player_name: string ): boolean;
    GotoPlayerRaid(player_name: string ): boolean;
    Death(killer_mob: Mob , damage: number, spell_id: number, attack_skill: SkillType, killed_by: KilledByTypes): boolean;
    Damage(from: Mob , damage: number, spell_id: number, attack_skill: SkillType, avoidable: boolean, buffslot: number, iBuffTic: boolean, special: eSpecialAttacks): void;
    HasRaid(): boolean;
    HasGroup(): boolean;
    GetRaid(): Raid ;
    GetGroup(): Group ;
    IsBerserk(): boolean;
    SetAttackTimer(): void;
    GetQuiverHaste(delay: number): number;
    DoAttackRounds(target: Mob , hand: number, IsFromSpell: boolean): void;
    AI_Init(): void;
    AI_Start(iMoveDelay: number): void;
    AI_Stop(): void;
    AI_Process(): void;
    AI_SpellCast(): void;
    Trader_ShowItems(): void;
    Trader_CustomerBrowsing(Customer: Client ): void;
    Trader_EndTrader(): void;
    Trader_StartTrader(): void;
    WithCustomer(NewCustomer: number): number;
    KeyRingLoad(): void;
    KeyRingAdd(item_id: number): void;
    KeyRingCheck(item_id: number): boolean;
    KeyRingList(): void;
    IsClient(): boolean;
    IsOfClientBot(): boolean;
    IsOfClientBotMerc(): boolean;
    CompleteConnect(): void;
    TryStacking(item: ItemInstance , type: number, try_worn: boolean, try_cursor: boolean): boolean;
    SendTraderPacket(trader: Client , Unknown72: number): void;
    SendBuyerPacket(Buyer: Client ): void;
    GetTraderItems(): GetItems_Struct ;
    SendBazaarWelcome(): void;
    DyeArmor(dye: number): void;
    DyeArmorBySlot(slot: number, red: number, green: number, blue: number, use_tint: number): void;
    SlotConvert(slot: number, bracer: boolean): number;
    MessageString(type: number, string_id: number, distance: number): void;
    MessageString(type: number, string_id: number, message: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char , distance: number): void;
    MessageString(msg: CZClientMessageString_Struct ): void;
    FilteredMessageCheck(sender: Mob , filter: eqFilterType): boolean;
    FilteredMessageString(sender: Mob , type: number, filter: eqFilterType, string_id: number): void;
    FilteredMessageString(sender: Mob , type: number, filter: eqFilterType, string_id: number, message1: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char ): void;
    Tell_StringID(string_id: number, who: char , message: char ): void;
    SendColoredText(color: number, message: string): void;
    SendBazaarResults(trader_id: number, in_class: number, in_race: number, item_stat: number, item_slot: number, item_type: number, item_name: number, min_price: number, max_price: number): void;
    SendTraderItem(item_id: number, quantity: number): void;
    FindTraderItem(SerialNumber: number, Quantity: number): number;
    FindTraderItemSerialNumber(ItemID: number): number;
    FindTraderItemBySerialNumber(SerialNumber: number): ItemInstance ;
    FindAndNukeTraderItem(item_id: number, quantity: number, customer: Client , traderslot: number): void;
    NukeTraderItem(slot: number, charges: number, quantity: number, customer: Client , traderslot: number, uniqueid: number, itemid: number): void;
    ReturnTraderReq(app: EQApplicationPacket , traderitemcharges: number, itemid: number): void;
    TradeRequestFailed(app: EQApplicationPacket ): void;
    BuyTraderItem(tbs: TraderBuy_Struct , trader: Client , app: EQApplicationPacket ): void;
    FinishTrade(arg0: Mob , finalizer: boolean, event_entry: void , event_details: list<void > ): void;
    SendZonePoints(): void;
    SendBuyerResults(SearchQuery: char , SearchID: number): void;
    ShowBuyLines(app: EQApplicationPacket ): void;
    SellToBuyer(app: EQApplicationPacket ): void;
    ToggleBuyerMode(TurnOn: boolean): void;
    UpdateBuyLine(app: EQApplicationPacket ): void;
    BuyerItemSearch(app: EQApplicationPacket ): void;
    SetBuyerWelcomeMessage(WelcomeMessage: char ): void;
    GetBuyerWelcomeMessage(): char ;
    FillSpawnStruct(ns: NewSpawn_Struct , ForWho: Mob ): void;
    ShouldISpawnFor(c: Client ): boolean;
    Process(): boolean;
    QueuePacket(app: EQApplicationPacket , ack_req: boolean, CLIENT_CONN_STATUS: , filter: eqFilterType): void;
    FastQueuePacket(app: EQApplicationPacket  , ack_req: boolean, CLIENT_CONN_STATUS: ): void;
    ChannelMessageReceived(chan_num: number, language: number, lang_skill: number, orig_message: char , targetname: char , is_silent: boolean): void;
    ChannelMessageSend(from: char , to: char , channel_id: number, language_id: number, language_skill: number, message: char ): void;
    Message(type: number, message: char ): void;
    FilteredMessage(sender: Mob , type: number, filter: eqFilterType, message: char ): void;
    VoiceMacroReceived(Type: number, Target: char , MacroNumber: number): void;
    SendSound(): void;
    LearnRecipe(recipe_id: number): void;
    GetRecipeMadeCount(recipe_id: number): number;
    HasRecipeLearned(recipe_id: number): boolean;
    CanIncreaseTradeskill(tradeskill: SkillType): boolean;
    GetRevoked(): boolean;
    SetRevoked(rev: boolean): void;
    GetIP(): number;
    GetIPString(): string;
    GetIPExemption(): number;
    SetIPExemption(exemption_amount: number): void;
    GetHideMe(): boolean;
    SetHideMe(flag: boolean): void;
    GetPort(): number;
    IsDead(): boolean;
    IsUnconscious(): boolean;
    IsLFP(): boolean;
    UpdateLFP(): void;
    Save(): boolean;
    Save(iCommitNow: number): boolean;
    SaveCurrency(): boolean;
    SaveAA(): boolean;
    RemoveExpendedAA(aa_id: number): void;
    ClientDataLoaded(): boolean;
    Connected(): boolean;
    InZone(): boolean;
    Disconnect(): void;
    IsLD(): boolean;
    Kick(reason: string ): void;
    WorldKick(): void;
    GetAnon(): number;
    GetAFK(): number;
    SetAnon(anon_flag: number): void;
    SetAFK(afk_flag: number): void;
    GetPP(): PlayerProfile_Struct ;
    GetEPP(): ExtendedProfile_Struct ;
    GetInv(): InventoryProfile ;
    GetInv(): InventoryProfile ;
    GetPetInfo(pet_info_type: number): PetInfo ;
    GetInspectMessage(): InspectMessage_Struct ;
    GetInspectMessage(): InspectMessage_Struct ;
    ReloadExpansionProfileSetting(): void;
    SetPetCommandState(button: number, state: number): void;
    AutoAttackEnabled(): boolean;
    AutoFireEnabled(): boolean;
    ChangeFirstName(in_firstname: char , gmname: char ): boolean;
    Duck(): void;
    Stand(): void;
    Sit(): void;
    SetMaxHP(): void;
    LevelRegen(): number;
    SetGM(toggle: boolean): void;
    SetPVP(toggle: boolean, message: boolean): void;
    GetPVP(inc_temp: boolean): boolean;
    GetGM(): boolean;
    SetBaseClass(i: number): void;
    SetBaseRace(i: number): void;
    SetBaseGender(i: number): void;
    SetDeity(i: number): void;
    SetTrackingID(entity_id: number): void;
    GetLevel2(): number;
    GetBaseRace(): number;
    GetBaseClass(): number;
    GetBaseGender(): number;
    GetBaseFace(): number;
    GetBaseHairColor(): number;
    GetBaseBeardColor(): number;
    GetBaseEyeColor(): number;
    GetBaseHairStyle(): number;
    GetBaseBeard(): number;
    GetBaseHeritage(): number;
    GetBaseTattoo(): number;
    GetBaseDetails(): number;
    GetBindX(index: number): float;
    GetBindY(index: number): float;
    GetBindZ(index: number): float;
    GetBindHeading(index: number): float;
    GetBindZoneID(index: number): number;
    GetBindInstanceID(index: number): number;
    CalcMaxMana(): number;
    CalcBaseMana(): number;
    SetMana(amount: number): number;
    CalcManaRegenCap(): number;
    EnableAreaHPRegen(value: number): void;
    DisableAreaHPRegen(): void;
    EnableAreaManaRegen(value: number): void;
    DisableAreaManaRegen(): void;
    EnableAreaEndRegen(value: number): void;
    DisableAreaEndRegen(): void;
    EnableAreaRegens(value: number): void;
    DisableAreaRegens(): void;
    ServerFilter(filter: SetServerFilter_Struct ): void;
    BulkSendTraderInventory(char_id: number): void;
    SendSingleTraderItem(char_id: number, uniqueid: number): void;
    BulkSendMerchantInventory(merchant_id: number, npcid: number): void;
    GetLanguageSkill(language_id: number): number;
    SendPickPocketResponse(from: Mob , amt: number, type: number, item: ItemData ): void;
    GetLastName(): char ;
    ProximityX(): float;
    ProximityY(): float;
    ProximityZ(): float;
    ClearAllProximities(): void;
    CheckVirtualZoneLines(): void;
    CalcBonuses(): void;
    GetATKBonus(): number;
    GetHaste(): number;
    GetRawACNoShield(shield_ac: number): number;
    GetSTR(): number;
    GetSTA(): number;
    GetDEX(): number;
    GetAGI(): number;
    GetINT(): number;
    GetWIS(): number;
    GetCHA(): number;
    GetMR(): number;
    GetFR(): number;
    GetDR(): number;
    GetPR(): number;
    GetCR(): number;
    GetCorrup(): number;
    GetPhR(): number;
    GetMaxStat(): number;
    GetMaxResist(): number;
    GetMaxSTR(): number;
    GetMaxSTA(): number;
    GetMaxDEX(): number;
    GetMaxAGI(): number;
    GetMaxINT(): number;
    GetMaxWIS(): number;
    GetMaxCHA(): number;
    GetMaxMR(): number;
    GetMaxPR(): number;
    GetMaxDR(): number;
    GetMaxCR(): number;
    GetMaxFR(): number;
    GetMaxCorrup(): number;
    GetBaseSTR(): number;
    GetBaseSTA(): number;
    GetBaseCHA(): number;
    GetBaseDEX(): number;
    GetBaseINT(): number;
    GetBaseAGI(): number;
    GetBaseWIS(): number;
    GetBaseCorrup(): number;
    GetBasePhR(): number;
    GetHeroicSTR(): number;
    GetHeroicSTA(): number;
    GetHeroicDEX(): number;
    GetHeroicAGI(): number;
    GetHeroicINT(): number;
    GetHeroicWIS(): number;
    GetHeroicCHA(): number;
    GetHeroicMR(): number;
    GetHeroicFR(): number;
    GetHeroicDR(): number;
    GetHeroicPR(): number;
    GetHeroicCR(): number;
    GetHeroicCorrup(): number;
    GetHeroicPhR(): number;
    GetShielding(): number;
    GetSpellShield(): number;
    GetDoTShield(): number;
    GetStunResist(): number;
    GetStrikeThrough(): number;
    GetAvoidance(): number;
    GetAccuracy(): number;
    GetCombatEffects(): number;
    GetDS(): number;
    GetHealAmt(): number;
    GetSpellDmg(): number;
    GetClair(): number;
    GetDSMit(): number;
    GetSingMod(): number;
    GetBrassMod(): number;
    GetPercMod(): number;
    GetStringMod(): number;
    GetWindMod(): number;
    GetDelayDeath(): number;
    CheckFizzle(spell_id: number): boolean;
    GetCurrentBuffSlots(): number;
    GetCurrentSongSlots(): number;
    GetCurrentDiscSlots(): number;
    GetMaxBuffSlots(): number;
    GetMaxSongSlots(): number;
    GetMaxDiscSlots(): number;
    GetMaxTotalSlots(): number;
    GetFirstBuffSlot(disc: boolean, song: boolean): number;
    GetLastBuffSlot(disc: boolean, song: boolean): number;
    InitializeBuffSlots(): void;
    UninitializeBuffSlots(): void;
    GetBaseHP(): number;
    GetWeight(): number;
    RecalcWeight(): void;
    CalcCurrentWeight(): number;
    GetCopper(): number;
    GetSilver(): number;
    GetGold(): number;
    GetPlatinum(): number;
    CalcMaxEndurance(): void;
    CalcBaseEndurance(): number;
    CalcEnduranceRegen(bCombat: boolean): number;
    GetEndurance(): number;
    GetMaxEndurance(): number;
    CalcEnduranceRegenCap(): number;
    CalcHPRegenCap(): number;
    GetEndurancePercent(): number;
    SetEndurance(newEnd: number): void;
    DoEnduranceRegen(): void;
    DoEnduranceUpkeep(): void;
    GetTotalATK(): number;
    GetATKRating(): number;
    GetPrimarySkillValue(): number;
    Flurry(): boolean;
    Rampage(): boolean;
    GetEXP(): number;
    GetAAEXPModifier(zone_id: number, instance_version: number): float;
    GetEXPModifier(zone_id: number, instance_version: number): float;
    SetAAEXPModifier(zone_id: number, aa_modifier: float, instance_version: number): void;
    SetEXPModifier(zone_id: number, exp_modifier: float, instance_version: number): void;
    UpdateLDoNPoints(theme_id: number, points: number): boolean;
    SetLDoNPoints(theme_id: number, points: number): void;
    SetPVPPoints(Points: number): void;
    GetPVPPoints(): number;
    AddPVPPoints(Points: number): void;
    AddEbonCrystals(amount: number, is_reclaim: boolean): void;
    AddRadiantCrystals(amount: number, is_reclaim: boolean): void;
    RemoveEbonCrystals(amount: number, is_reclaim: boolean): void;
    RemoveRadiantCrystals(amount: number, is_reclaim: boolean): void;
    GetRadiantCrystals(): number;
    SetRadiantCrystals(value: number): void;
    GetEbonCrystals(): number;
    SetEbonCrystals(value: number): void;
    SendCrystalCounts(): void;
    GetExperienceForKill(against: Mob ): number;
    AddEXP(in_add_exp: number, conlevel: number, resexp: boolean): void;
    CalcEXP(conlevel: number, ignore_mods: boolean): number;
    CalculateNormalizedAAExp(add_aaxp: number, conlevel: number, resexp: boolean): void;
    CalculateStandardAAExp(add_aaxp: number, conlevel: number, resexp: boolean): void;
    CalculateLeadershipExp(add_exp: number, conlevel: number): void;
    CalculateExp(in_add_exp: number, add_exp: number, add_aaxp: number, conlevel: number, resexp: boolean): void;
    SetEXP(set_exp: number, set_aaxp: number, resexp: boolean): void;
    AddLevelBasedExp(exp_percentage: number, max_level: number, ignore_mods: boolean): void;
    SetLeadershipEXP(group_exp: number, raid_exp: number): void;
    AddLeadershipEXP(group_exp: number, raid_exp: number): void;
    SendLeadershipEXPUpdate(): void;
    IsLeadershipEXPOn(): boolean;
    GetLeadershipAA(AAID: number): number;
    GetLeadershipAA(): LeadershipAA_Struct ;
    GetGroupLeadershipAA(): GroupLeadershipAA_Struct ;
    GetRaidLeadershipAA(): RaidLeadershipAA_Struct ;
    GroupLeadershipAAHealthEnhancement(): number;
    GroupLeadershipAAManaEnhancement(): number;
    GroupLeadershipAAHealthRegeneration(): number;
    GroupLeadershipAAOffenseEnhancement(): number;
    InspectBuffs(Inspector: Client , Rank: number): void;
    GetRaidPoints(): number;
    GetGroupPoints(): number;
    GetRaidEXP(): number;
    GetGroupEXP(): number;
    GetTotalSecondsPlayed(): number;
    SetLevel(set_level: number, command: boolean): void;
    GoToBind(bindnum: number): void;
    GoToSafeCoords(zone_id: number, instance_id: number): void;
    Gate(bindnum: number): void;
    SetBindPoint(bind_num: number, to_zone: number, to_instance: number, location: vec3 ): void;
    SetBindPoint2(bind_num: number, to_zone: number, to_instance: number, location: vec4 ): void;
    SetStartZone(zoneid: number, x: float, y: float, z: float, heading: float): void;
    GetStartZone(): number;
    MovePC(zonename: char , x: float, y: float, z: float, heading: float, ignorerestrictions: number, zm: ZoneMode): void;
    MovePC(zoneID: number, x: float, y: float, z: float, heading: float, ignorerestrictions: number, zm: ZoneMode): void;
    MovePC(x: float, y: float, z: float, heading: float, ignorerestrictions: number, zm: ZoneMode): void;
    MovePC(zoneID: number, instanceID: number, x: float, y: float, z: float, heading: float, ignorerestrictions: number, zm: ZoneMode): void;
    MoveZone(zone_short_name: char , location: vec4 ): void;
    MoveZoneGroup(zone_short_name: char , location: vec4 ): void;
    MoveZoneRaid(zone_short_name: char , location: vec4 ): void;
    MoveZoneInstance(instance_id: number, location: vec4 ): void;
    MoveZoneInstanceGroup(instance_id: number, location: vec4 ): void;
    MoveZoneInstanceRaid(instance_id: number, location: vec4 ): void;
    SendToGuildHall(): void;
    SendToInstance(instance_type: string, zone_short_name: string, instance_version: number, x: float, y: float, z: float, heading: float, instance_identifier: string, duration: number): void;
    AssignToInstance(instance_id: number): void;
    RemoveFromInstance(instance_id: number): void;
    WhoAll(): void;
    CheckLoreConflict(item: ItemData ): boolean;
    ChangeLastName(last_name: string): void;
    GetGroupAAs(into: GroupLeadershipAA_Struct ): void;
    GetRaidAAs(into: RaidLeadershipAA_Struct ): void;
    ClearGroupAAs(): void;
    UpdateGroupAAs(points: number, type: number): void;
    SacrificeConfirm(caster: Client ): void;
    Sacrifice(caster: Client ): void;
    GoToDeath(): void;
    GetInstanceID(): number;
    SetZoning(arg0: boolean): void;
    ShowSpells(c: Client , show_spell_type: ShowSpellType): void;
    GetReverseFactionCon(iOther: Mob ): FACTION_VALUE;
    GetFactionLevel(char_id: number, npc_id: number, p_race: number, p_class: number, p_deity: number, pFaction: number, tnpc: Mob ): FACTION_VALUE;
    ReloadCharacterFaction(c: Client , facid: number, charid: number): boolean;
    GetCharacterFactionLevel(faction_id: number): number;
    GetModCharacterFactionLevel(faction_id: number): number;
    MerchantRejectMessage(merchant: Mob , primaryfaction: number): void;
    SendFactionMessage(tmpvalue: number, faction_id: number, faction_before_hit: number, totalvalue: number, temp: number, this_faction_min: number, this_faction_max: number): void;
    UpdatePersonalFaction(char_id: number, npc_value: number, faction_id: number, current_value: number, temp: number, this_faction_min: number, this_faction_max: number): void;
    SetFactionLevel(char_id: number, npc_faction_id: number, char_class: number, char_race: number, char_deity: number, quest: boolean): void;
    SetFactionLevel2(char_id: number, faction_id: number, char_class: number, char_race: number, char_deity: number, value: number, temp: number): void;
    GetRawItemAC(): number;
    LSAccountID(): number;
    GetWID(): number;
    SetWID(iWID: number): void;
    AccountID(): number;
    AccountName(): char ;
    GetAccountCreation(): number;
    Admin(): number;
    CharacterID(): number;
    UpdateAdmin(from_database: boolean): void;
    UpdateWho(remove: number): void;
    GMHideMe(client: Client ): boolean;
    IsInAGuild(): boolean;
    IsInGuild(in_gid: number): boolean;
    GetGuildListDirty(): boolean;
    SetGuildListDirty(state: boolean): void;
    GuildID(): number;
    GuildRank(): number;
    GuildTributeOptIn(): boolean;
    SetGuildTributeOptIn(state: boolean): void;
    SendGuildTributeDonateItemReply(arg0: GuildTributeDonateItemRequest_Struct , favor: number): void;
    SendGuildTributeDonatePlatReply(arg0: GuildTributeDonatePlatRequest_Struct , favor: number): void;
    SetGuildRank(rank: number): void;
    SetGuildID(guild_id: number): void;
    SendGuildMOTD(GetGuildMOTDReply: boolean): void;
    SendGuildURL(): void;
    SendGuildChannel(): void;
    SendGuildSpawnAppearance(): void;
    SendGuildRanks(): void;
    SendGuildMembers(): void;
    SendGuildList(): void;
    SendGuildJoin(gj: GuildJoin_Struct ): void;
    RefreshGuildInfo(): void;
    SendGuildRankNames(): void;
    SendGuildTributeDetails(tribute_id: number, tier: number): void;
    DoGuildTributeUpdate(): void;
    SendGuildActiveTributes(guild_id: number): void;
    SendGuildFavorAndTimer(guild_id: number): void;
    SendGuildTributeOptInToggle(arg0: GuildTributeMemberToggle ): void;
    RequestGuildActiveTributes(guild_id: number): void;
    RequestGuildFavorAndTimer(guild_id: number): void;
    SendGuildMembersList(): void;
    SendGuildMemberAdd(guild_id: number, level: number, _class: number, rank: number, guild_show: number, zone_id: number, player_name: string): void;
    SendGuildMemberRename(guild_id: number, player_name: string, new_player_name: string): void;
    SendGuildMemberDelete(guild_id: number, player_name: string): void;
    SendGuildMemberLevel(guild_id: number, level: number, player_name: string): void;
    SendGuildMemberRankAltBanker(guild_id: number, rank: number, player_name: string, alt: boolean, banker: boolean): void;
    SendGuildMemberPublicNote(guild_id: number, player_name: string, public_note: string): void;
    SendGuildMemberDetails(guild_id: number, zone_id: number, offline_mode: number, player_name: string): void;
    SendGuildRenameGuild(guild_id: number, new_guild_name: string): void;
    SendGuildDeletePacket(guild_id: number): void;
    GetClientMaxLevel(): number;
    SetClientMaxLevel(max_level: number): void;
    CheckManaEndUpdate(): void;
    SendManaUpdate(): void;
    SendEnduranceUpdate(): void;
    GetFace(): number;
    WhoAll(whom: Who_All_Struct ): void;
    FriendsWho(FriendsString: char ): void;
    Stun(duration: number): void;
    UnStun(): void;
    ReadBook(book: BookRequest_Struct ): void;
    ReadBookByName(book_name: string, book_type: number): void;
    QuestReadBook(text: char , type: number): void;
    SendMoneyUpdate(): void;
    TakeMoneyFromPP(copper: number, update_client: boolean): boolean;
    TakePlatinum(platinum: number, update_client: boolean): boolean;
    AddMoneyToPP(copper: number, update_client: boolean): void;
    AddMoneyToPP(copper: number, silver: number, gold: number, platinum: number, update_client: boolean): void;
    AddPlatinum(platinu: number, update_client: boolean): void;
    HasMoney(copper: number): boolean;
    GetCarriedMoney(): number;
    GetCarriedPlatinum(): number;
    GetAllMoney(): number;
    GetMoney(type: number, subtype: number): number;
    GetAccountAge(): number;
    SendPath(target: Mob ): void;
    IsDiscovered(itemid: number): boolean;
    DiscoverItem(itemid: number): void;
    TGB(): boolean;
    OnDisconnect(hard_disconnect: boolean): void;
    GetSkillPoints(): number;
    SetSkillPoints(inp: number): void;
    IncreaseSkill(skill_id: number, value: number): void;
    IncreaseLanguageSkill(language_id: number, increase: number): void;
    GetSkill(skill_id: SkillType): number;
    GetRawSkill(skill_id: SkillType): number;
    HasSkill(skill_id: SkillType): boolean;
    CanHaveSkill(skill_id: SkillType): boolean;
    SetSkill(skill_num: SkillType, value: number): void;
    AddSkill(skillid: SkillType, value: number): void;
    CheckSpecializeIncrease(spell_id: number): void;
    CheckSongSkillIncrease(spell_id: number): void;
    CheckIncreaseSkill(skillid: SkillType, against_who: Mob , chancemodi: number): boolean;
    CheckLanguageSkillIncrease(language_id: number, teacher_skill: number): void;
    SetLanguageSkill(language_id: number, language_skill: number): void;
    SetHoTT(mobid: number): void;
    ShowSkillsWindow(): void;
    MaxSkill(skillid: SkillType, class_: number, level: number): number;
    MaxSkill(skillid: SkillType): number;
    SkillTrainLevel(skillid: SkillType, class_: number): number;
    MaxSkills(): void;
    SendTradeskillSearchResults(query: string , objtype: number, someid: number): void;
    SendTradeskillDetails(recipe_id: number): void;
    TradeskillExecute(spec: DBTradeskillRecipe_Struct ): boolean;
    CheckIncreaseTradeskill(bonusstat: number, stat_modifier: number, skillup_modifier: float, success_modifier: number, tradeskill: SkillType): void;
    CheckTradeskillLoreConflict(recipe_id: number): boolean;
    InitInnates(): void;
    GMKill(): void;
    IsMedding(): boolean;
    GetDuelTarget(): number;
    IsDueling(): boolean;
    SetDuelTarget(set_id: number): void;
    SetDueling(duel: boolean): void;
    MemSpell(spell_id: number, slot: number, update_client: boolean): void;
    UnmemSpell(slot: number, update_client: boolean): void;
    UnmemSpellBySpellID(spell_id: number): void;
    UnmemSpellAll(update_client: boolean): void;
    FindEmptyMemSlot(): number;
    FindMemmedSpellBySlot(slot: number): number;
    FindMemmedSpellBySpellID(spell_id: number): number;
    MemmedCount(): number;
    GetLearnableDisciplines(min_level: number, max_level: number): number;
    GetLearnedDisciplines(): number;
    GetMemmedSpells(): number;
    GetScribeableSpells(min_level: number, max_level: number): number;
    GetScribedSpells(): number;
    ScribeSpell(spell_id: number, slot: number, update_client: boolean, defer_save: boolean): void;
    SaveSpells(): void;
    SaveDisciplines(): void;
    ScribeSpells(min_level: number, max_level: number): number;
    LearnDisciplines(min_level: number, max_level: number): number;
    GetClassTrackingDistanceMultiplier(class_: number): number;
    CanThisClassTrack(): boolean;
    UnscribeSpell(slot: number, update_client: boolean, defer_save: boolean): void;
    UnscribeSpellAll(update_client: boolean): void;
    UnscribeSpellBySpellID(spell_id: number, update_client: boolean): void;
    UntrainDisc(slot: number, update_client: boolean, defer_save: boolean): void;
    UntrainDiscAll(update_client: boolean): void;
    UntrainDiscBySpellID(spell_id: number, update_client: boolean): void;
    SpellGlobalCheck(spell_id: number, char_id: number): boolean;
    SpellBucketCheck(spell_id: number, char_id: number): boolean;
    GetCharMaxLevelFromQGlobal(): number;
    GetCharMaxLevelFromBucket(): number;
    Fling(value: float, target_x: float, target_y: float, target_z: float, ignore_los: boolean, clip_through_walls: boolean, calculate_speed: boolean): void;
    IsStanding(): boolean;
    IsSitting(): boolean;
    IsCrouching(): boolean;
    IsBecomeNPC(): boolean;
    GetBecomeNPCLevel(): number;
    SetBecomeNPC(flag: boolean): void;
    SetBecomeNPCLevel(level: number): void;
    Connection(): EQStreamInterface ;
    GetEquippedItemFromTextureSlot(material_slot: number): number;
    GetEquipmentColor(material_slot: number): number;
    UpdateEquipmentLight(): void;
    AutoSplitEnabled(): boolean;
    AutoConsentGroupEnabled(): boolean;
    AutoConsentRaidEnabled(): boolean;
    AutoConsentGuildEnabled(): boolean;
    SummonHorse(spell_id: number): void;
    SetHorseId(horseid_in: number): void;
    SetControlledMobId(mob_id_in: number): void;
    GetControlledMobId(): number;
    GetHorseId(): number;
    CanMedOnHorse(): boolean;
    CanFastRegen(): boolean;
    NPCSpawn(target_npc: NPC , identifier: char , extra: number): void;
    Disarm(disarmer: Client , chance: number): void;
    BindWound(bindmob: Mob , start: boolean, fail: boolean): boolean;
    SetTradeskillObject(object: Object ): void;
    GetTradeskillObject(): Object ;
    SendTributes(): void;
    SendGuildTributes(): void;
    DoTributeUpdate(): void;
    SendTributeDetails(client_id: number, tribute_id: number): void;
    TributeItem(slot: number, quantity: number): number;
    TributeMoney(platinum: number): number;
    AddTributePoints(ammount: number): void;
    ChangeTributeSettings(t: TributeInfo_Struct ): void;
    SendTributeTimer(): void;
    ToggleTribute(enabled: boolean): void;
    SendPathPacket(path: number): void;
    GetPTimers(): PTimerList ;
    SendAlternateAdvancementRank(aa_id: number, level: number): void;
    SendAlternateAdvancementTable(): void;
    SendAlternateAdvancementStats(): void;
    PurchaseAlternateAdvancementRank(rank_id: number): void;
    GrantAlternateAdvancementAbility(aa_id: number, points: number, ignore_cost: boolean): boolean;
    IncrementAlternateAdvancementRank(rank_id: number): void;
    ActivateAlternateAdvancementAbility(rank_id: number, target_id: number): void;
    SendAlternateAdvancementPoints(): void;
    SendAlternateAdvancementTimer(ability: number, begin: number, end: number): void;
    SendAlternateAdvancementTimers(): void;
    ResetAlternateAdvancementTimer(ability: number): void;
    ResetAlternateAdvancementTimers(): void;
    ResetOnDeathAlternateAdvancement(): void;
    SetAAPoints(points: number): void;
    AddAAPoints(points: number): void;
    GetAAPoints(): number;
    GetSpentAA(): number;
    GetRequiredAAExperience(): number;
    AutoGrantAAPoints(): void;
    GrantAllAAPoints(unlock_level: number): void;
    HasAlreadyPurchasedRank(rank: Rank ): boolean;
    ListPurchasedAAs(to: Client , search_criteria: string): void;
    SendGMCommand(message: string, ignore_status: boolean): boolean;
    RegisterBug(r: BugReport_Struct ): void;
    GetApplySpellList(apply_type: ApplySpellType, allow_pets: boolean, is_raid_group_only: boolean, allow_bots: boolean): vector<Mob  >;
    ApplySpell(spell_id: number, duration: number, level: number, apply_type: ApplySpellType, allow_pets: boolean, is_raid_group_only: boolean, allow_bots: boolean): void;
    SetSpellDuration(spell_id: number, duration: number, level: number, apply_type: ApplySpellType, allow_pets: boolean, is_raid_group_only: boolean, allow_bots: boolean): void;
    ResetAA(): void;
    RefundAA(): void;
    SendClearAA(): void;
    SendClearLeadershipAA(): void;
    SendClearPlayerAA(): void;
    GetAAXP(): number;
    GetAAPercent(): number;
    SetAATitle(title: string): void;
    SetTitleSuffix(suffix: string): void;
    MemorizeSpell(slot: number, spell_id: number, scribing: number, reduction: number): void;
    GetAAEXPPercentage(): number;
    GetEXPPercentage(): number;
    UseAugmentContainer(container_slot: number): void;
    EVENT_ITEM_ScriptStopReturn(): void;
    NukeItem(itemnum: number, where_to_check: number): number;
    SetTint(slot_id: number, color: number): void;
    SetTint(slot_id: number, color: number): void;
    SetMaterial(slot_id: number, item_id: number): void;
    Undye(): void;
    GetItemIDAt(slot_id: number): number;
    GetAugmentIDAt(slot_id: number, augslot: number): number;
    PutItemInInventory(slot_id: number, inst: ItemInstance , client_update: boolean): boolean;
    PushItemOnCursor(inst: ItemInstance , client_update: boolean): boolean;
    SendCursorBuffer(): void;
    DeleteItemInInventory(slot_id: number, quantity: number, client_update: boolean, update_db: boolean): void;
    CountItem(item_id: number): number;
    ResetItemCooldown(item_id: number): void;
    SetItemCooldown(item_id: number, use_saved_timer: boolean, in_seconds: number): void;
    GetItemCooldown(item_id: number): number;
    RemoveItem(item_id: number, quantity: number): void;
    SwapItem(move_in: MoveItem_Struct ): boolean;
    SwapItemResync(move_slots: MoveItem_Struct ): void;
    QSSwapItemAuditor(move_in: MoveItem_Struct , postaction_call: boolean): void;
    PutLootInInventory(slot_id: number, inst: ItemInstance , bag_item_data: LootItem  ): void;
    AutoPutLootInInventory(inst: ItemInstance , try_worn: boolean, try_cursor: boolean, bag_item_data: LootItem  ): boolean;
    SummonItem(item_id: number, charges: number, aug1: number, aug2: number, aug3: number, aug4: number, aug5: number, aug6: number, attuned: boolean, to_slot: number, ornament_icon: number, ornament_idfile: number, ornament_hero_model: number): boolean;
    SummonItemIntoInventory(item_id: number, charges: number, aug1: number, aug2: number, aug3: number, aug4: number, aug5: number, aug6: number, is_attuned: boolean): void;
    SummonBaggedItems(bag_item_id: number, bag_items: vector<LootItem> ): void;
    SetStats(type: number, set_val: number): void;
    IncStats(type: number, increase_val: number): void;
    DropItem(slot_id: number, recurse: boolean): void;
    DropItemQS(inst: ItemInstance , pickup: boolean): void;
    HasItemOnCorpse(item_id: number): boolean;
    IsAugmentRestricted(item_type: number, augment_restriction: number): boolean;
    GetItemLinkHash(inst: ItemInstance ): number;
    SendItemLink(inst: ItemInstance , sendtoall: boolean): void;
    SendLootItemInPacket(inst: ItemInstance , slot_id: number): void;
    SendItemPacket(slot_id: number, inst: ItemInstance , packet_type: ItemPacketType): void;
    IsValidSlot(slot: number): boolean;
    IsBankSlot(slot: number): boolean;
    IsTrader(): boolean;
    IsBuyer(): boolean;
    GetFilter(filter_id: eqFilterType): eqFilterMode;
    SetFilter(filter_id: eqFilterType, filter_mode: eqFilterMode): void;
    CancelSneakHide(): void;
    BreakInvis(): void;
    BreakSneakWhenCastOn(caster: Mob , IsResisted: boolean): void;
    BreakFeignDeathWhenCastOn(IsResisted: boolean): void;
    LeaveGroup(): void;
    Hungry(): boolean;
    Thirsty(): boolean;
    GetHunger(): number;
    GetThirst(): number;
    SetHunger(in_hunger: number): void;
    SetThirst(in_thirst: number): void;
    SetConsumption(in_hunger: number, in_thirst: number): void;
    IsStarved(): boolean;
    GetIntoxication(): number;
    CheckTradeLoreConflict(other: Client ): boolean;
    CheckTradeNonDroppable(): boolean;
    LinkDead(): void;
    CheckDoubleAttack(): boolean;
    CheckTripleAttack(): boolean;
    CheckDoubleRangedAttack(): boolean;
    CheckDualWield(): boolean;
    DecreaseByID(type: number, quantity: number): boolean;
    SlotConvert2(slot: number): number;
    Escape(): void;
    DisenchantSummonedBags(client_update: boolean): void;
    RemoveNoRent(client_update: boolean): void;
    RemoveDuplicateLore(client_update: boolean): void;
    MoveSlotNotAllowed(client_update: boolean): void;
    RangedAttack(other: Mob , CanDoubleAttack: boolean): void;
    ThrowingAttack(other: Mob , CanDoubleAttack: boolean): void;
    DoClassAttacks(ca_target: Mob , skill: number, IsRiposte: boolean): void;
    ClearZoneFlag(zone_id: number): void;
    GetZoneFlags(): number;
    HasZoneFlag(zone_id: number): boolean;
    LoadZoneFlags(): void;
    SendZoneFlagInfo(to: Client ): void;
    SetZoneFlag(zone_id: number): void;
    ClearPEQZoneFlag(zone_id: number): void;
    GetPEQZoneFlags(): number;
    HasPEQZoneFlag(zone_id: number): boolean;
    LoadPEQZoneFlags(): void;
    SendPEQZoneFlagInfo(to: Client ): void;
    SetPEQZoneFlag(zone_id: number): void;
    CanFish(): boolean;
    GoFish(): void;
    ForageItem(guarantee: boolean): void;
    CalcPriceMod(other: Mob , reverse: boolean): float;
    ResetTrade(): void;
    DropInst(inst: ItemInstance ): void;
    TrainDiscipline(itemid: number): boolean;
    MemorizeSpellFromItem(item_id: number): boolean;
    TrainDiscBySpellID(spell_id: number): void;
    GetDisciplineTimer(timer_id: number): number;
    ResetAllDisciplineTimers(): void;
    GetDiscSlotBySpellID(spellid: number): number;
    ResetDisciplineTimer(timer_id: number): void;
    SendDisciplineUpdate(): void;
    SendDisciplineTimer(timer_id: number, duration: number): void;
    UseDiscipline(spell_id: number, target: number): boolean;
    HasDisciplineLearned(spell_id: number): boolean;
    SetLinkedSpellReuseTimer(timer_id: number, duration: number): void;
    IsLinkedSpellReuseTimerReady(timer_id: number): boolean;
    ResetCastbarCooldownBySlot(slot: number): void;
    ResetAllCastbarCooldowns(): void;
    ResetCastbarCooldownBySpellID(spell_id: number): void;
    CheckTitle(titleset: number): boolean;
    EnableTitle(titleset: number): void;
    RemoveTitle(titleset: number): void;
    EnteringMessages(client: Client ): void;
    SendRules(): void;
    GetGMSpeed(): bool;
    GetGMInvul(): bool;
    SendBuffDurationPacket(buff: Buffs_Struct , slot: number): void;
    SendBuffNumHitPacket(buff: Buffs_Struct , slot: number): void;
    ProcessInspectRequest(requestee: Client , requester: Client ): void;
    ClientFinishedLoading(): boolean;
    FindSpellBookSlotBySpellID(spellid: number): number;
    GetSpellIDByBookSlot(book_slot: number): number;
    GetNextAvailableSpellBookSlot(starting_slot: number): number;
    GetNextAvailableDisciplineSlot(starting_slot: number): number;
    GetSpellByBookSlot(book_slot: number): number;
    HasSpellScribed(spellid: number): boolean;
    GetHighestScribedSpellinSpellGroup(spell_group: number): number;
    LoadSpellGroupCache(min_level: number, max_level: number): number;
    GetMaxSkillAfterSpecializationRules(skillid: SkillType, maxSkill: number): number;
    SendPopupToClient(Title: char , Text: char , PopupID: number, Buttons: number, Duration: number): void;
    SendFullPopup(Title: char , Text: char , PopupID: number, NegativeID: number, Buttons: number, Duration: number, ButtonName0: char , ButtonName1: char , SoundControls: number): void;
    SendWindow(button_one_id: number, button_two_id: number, button_type: number, button_one_text: char , button_two_text: char , duration: number, title_type: number, target: Mob , title: char , text: char ): void;
    SendOPTranslocateConfirm(Caster: Mob , SpellID: number): void;
    LoadClientTaskState(): void;
    RemoveClientTaskState(): void;
    SendTaskActivityComplete(task_id: number, activity_id: number, task_index: number, task_type: TaskType, task_incomplete: number): void;
    SendTaskFailed(task_id: number, task_index: number, task_type: TaskType): void;
    SendTaskComplete(task_index: number): void;
    HasTaskRequestCooldownTimer(): boolean;
    SendTaskRequestCooldownTimerMessage(): void;
    StartTaskRequestCooldownTimer(): void;
    GetTaskState(): ClientTaskState ;
    HasTaskState(): boolean;
    CancelTask(task_index: number, task_type: TaskType): void;
    SaveTaskState(): boolean;
    IsTaskStateLoaded(): boolean;
    IsTaskActive(task_id: number): boolean;
    IsTaskActivityActive(task_id: number, activity_id: number): boolean;
    GetTaskActivityState(task_type: TaskType, index: number, activity_id: number): ActivityState;
    UpdateTaskActivity(task_id: number, activity_id: number, count: number, ignore_quest_update: boolean): void;
    RemoveTaskByTaskID(task_id: number): void;
    ResetTaskActivity(task_id: number, activity_id: number): void;
    UpdateTasksForItem(type: TaskActivityType, item_id: number, count: number): void;
    UpdateTasksOnLoot(corpse: Corpse , item_id: number, count: number): void;
    UpdateTasksOnExplore(pos: vec4 ): void;
    UpdateTasksOnSpeakWith(npc: NPC ): boolean;
    UpdateTasksOnDeliver(items: vector<ItemInstance > , trade: Trade , npc: NPC ): boolean;
    UpdateTasksOnTouchSwitch(dz_switch_id: number): void;
    TaskSetSelector(mob: Mob , task_set_id: number, ignore_cooldown: boolean): void;
    TaskQuestSetSelector(mob: Mob , tasks: number, ignore_cooldown: boolean): void;
    EnableTask(task_count: number, task_list: number): void;
    DisableTask(task_count: number, task_list: number): void;
    IsTaskEnabled(task_id: number): boolean;
    ProcessTaskProximities(x: float, y: float, z: float): void;
    AssignTask(task_id: number, npc_id: number, enforce_level_requirement: boolean): void;
    ActiveSpeakTask(npc: NPC ): number;
    ActiveSpeakActivity(npc: NPC , task_id: number): number;
    CompleteTask(task_id: number): boolean;
    FailTask(task_id: number): void;
    TaskTimeLeft(task_id: number): number;
    EnabledTaskCount(task_set_id: number): number;
    IsTaskCompleted(task_id: number): number;
    ShowClientTasks(client: Client ): void;
    CancelAllTasks(): void;
    GetActiveTaskCount(): number;
    GetActiveTaskID(index: number): number;
    GetTaskStartTime(task_type: TaskType, index: number): number;
    IsTaskActivityCompleted(task_type: TaskType, index: number, activity_id: number): boolean;
    GetTaskActivityDoneCount(task_type: TaskType, client_task_index: number, activity_id: number): number;
    GetTaskActivityDoneCountFromTaskID(task_id: number, activity_id: number): number;
    ActiveTasksInSet(task_set_id: number): number;
    CompletedTasksInSet(task_set_id: number): number;
    PurgeTaskTimers(): void;
    LockSharedTask(lock: boolean): void;
    EndSharedTask(fail: boolean): void;
    GetPartyMembers(): vector<Client  >;
    ClientVersion(): ClientVersion;
    ClientVersionBit(): number;
    SetClientVersion(client_version: ClientVersion): void;
    SendAdventureError(error: char ): void;
    SendAdventureDetails(): void;
    SendAdventureCount(count: number, total: number): void;
    NewAdventure(id: number, theme: number, text: char , member_count: number, members: char ): void;
    IsOnAdventure(): boolean;
    LeaveAdventure(): void;
    AdventureFinish(win: boolean, theme: number, points: number): void;
    SetAdventureData(data: char ): void;
    ClearAdventureData(): void;
    HasAdventureData(): boolean;
    ClearCurrentAdventure(): void;
    PendingAdventureRequest(): void;
    GetPendingAdventureRequest(): boolean;
    ClearPendingAdventureRequest(): void;
    PendingAdventureCreate(): void;
    GetPendingAdventureCreate(): boolean;
    ClearPendingAdventureCreate(): void;
    PendingAdventureLeave(): void;
    GetPendingAdventureLeave(): boolean;
    ClearPendingAdventureLeave(): void;
    PendingAdventureDoorClick(): void;
    GetPendingAdventureDoorClick(): boolean;
    ClearPendingAdventureDoorClick(): void;
    ClearPendingAdventureData(): void;
    CanEnterZone(zone_short_name: string , instance_version: number): boolean;
    GetAggroCount(): number;
    IncrementAggroCount(raid_target: boolean): void;
    DecrementAggroCount(): void;
    SendPVPStats(): void;
    SendDisciplineTimers(): void;
    SendRespawnBinds(): void;
    GetLDoNWins(): number;
    GetLDoNLosses(): number;
    GetLDoNWinsTheme(t: number): number;
    GetLDoNLossesTheme(t: number): number;
    GetLDoNPointsTheme(t: number): number;
    UpdateLDoNWinLoss(theme_id: number, win: boolean, remove: boolean): void;
    CheckLDoNHail(n: NPC ): void;
    CheckEmoteHail(n: NPC , message: char ): void;
    HandleLDoNOpen(target: NPC ): void;
    HandleLDoNSenseTraps(target: NPC , skill: number, type: number): void;
    HandleLDoNDisarm(target: NPC , skill: number, type: number): void;
    HandleLDoNPickLock(target: NPC , skill: number, type: number): void;
    LDoNChest_SkillCheck(target: NPC , skill: number): number;
    MarkSingleCompassLoc(in_x: float, in_y: float, in_z: float, count: number): void;
    SendCrossZoneMessage(client: Client , client_name: string , chat_type: number, message: string ): void;
    SendCrossZoneMessageString(client: Client , client_name: string , chat_type: number, string_id: number, arguments: string): void;
    AddExpeditionLockout(lockout: ExpeditionLockoutTimer , update_db: boolean): void;
    AddExpeditionLockoutDuration(expedition_name: string , event_Name: string , seconds: number, uuid: string , update_db: boolean): void;
    AddNewExpeditionLockout(expedition_name: string , event_name: string , duration: number, uuid: string): void;
    CreateExpedition(dz: DynamicZone , disable_messages: boolean): Expedition ;
    CreateExpedition(zone_name: string , version: number, duration: number, expedition_name: string , min_players: number, max_players: number, disable_messages: boolean): Expedition ;
    CreateExpeditionFromTemplate(dz_template_id: number): Expedition ;
    GetExpedition(): Expedition ;
    GetExpeditionID(): number;
    GetExpeditionLockout(expedition_name: string , event_name: string , include_expired: boolean): ExpeditionLockoutTimer ;
    GetExpeditionLockouts(): vector<ExpeditionLockoutTimer> ;
    GetExpeditionLockouts(expedition_name: string , include_expired: boolean): vector<ExpeditionLockoutTimer >;
    GetPendingExpeditionInviteID(): number;
    HasExpeditionLockout(expedition_name: string , event_name: string , include_expired: boolean): boolean;
    IsInExpedition(): boolean;
    RemoveAllExpeditionLockouts(expedition_name: string , update_db: boolean): void;
    RemoveExpeditionLockout(expedition_name: string , event_name: string , update_db: boolean): void;
    RequestPendingExpeditionInvite(): void;
    SendExpeditionLockoutTimers(): void;
    SetExpeditionID(expedition_id: number): void;
    SetPendingExpeditionInvite(invite: ExpeditionInvite  ): void;
    DzListTimers(): void;
    SetDzRemovalTimer(enable_timer: boolean): void;
    SendDzCompassUpdate(): void;
    GoToDzSafeReturnOrBind(dynamic_zone: DynamicZone ): void;
    MovePCDynamicZone(zone_id: number, zone_version: number, msg_if_invalid: boolean): void;
    MovePCDynamicZone(zone_name: string , zone_version: number, msg_if_invalid: boolean): void;
    TryMovePCDynamicZoneSwitch(dz_switch_id: number): boolean;
    GetDynamicZones(zone_id: number, zone_version: number): vector<DynamicZone  >;
    CreateDzSwitchListPacket(dzs: vector<DynamicZone > ): unique_ptr<EQApplicationPacket >;
    CreateCompassPacket(entries: vector<DynamicZoneCompassEntry_Struct> ): unique_ptr<EQApplicationPacket >;
    AddDynamicZoneID(dz_id: number): void;
    RemoveDynamicZoneID(dz_id: number): void;
    SendDynamicZoneUpdates(): void;
    SetDynamicZoneMemberStatus(status: DynamicZoneMemberStatus): void;
    CreateTaskDynamicZone(task_id: number, dz_request: DynamicZone ): void;
    CalcItemScale(): void;
    CalcItemScale(slot_x: number, slot_y: number): boolean;
    DoItemEnterZone(): void;
    DoItemEnterZone(slot_x: number, slot_y: number): boolean;
    SummonAndRezzAllCorpses(): void;
    SummonAllCorpses(position: vec4 ): void;
    DepopAllCorpses(): void;
    DepopPlayerCorpse(dbid: number): void;
    BuryPlayerCorpses(): void;
    GetCorpseCount(): number;
    GetCorpseID(corpse: number): number;
    GetCorpseItemAt(corpse_id: number, slot_id: number): number;
    SuspendMinion(value: number): void;
    Doppelganger(spell_id: number, target: Mob , name_override: char , pet_count: number, pet_duration: number): void;
    NotifyNewTitlesAvailable(): void;
    Signal(signal_id: number): void;
    SendPayload(payload_id: number, payload_value: string): void;
    GetBindSightTarget(): Mob ;
    SetBindSightTarget(n: Mob ): void;
    GetBoatID(): number;
    SendRewards(): void;
    TryReward(claim_id: number): boolean;
    GetQGlobals(): QGlobalCache ;
    CreateQGlobals(): QGlobalCache ;
    GuildBankAck(): void;
    GuildBankDepositAck(Fail: boolean, action: number): void;
    IsGuildBanker(): boolean;
    SetGuildBanker(banker: boolean): void;
    ClearGuildBank(): void;
    SendGroupCreatePacket(): void;
    SendGroupLeaderChangePacket(LeaderName: char ): void;
    SendGroupJoinAcknowledge(): void;
    DoTracking(): void;
    IsTracking(): boolean;
    SetPendingGuildInvitation(inPendingGuildInvitation: boolean): void;
    GetPendingGuildInvitation(): boolean;
    LocateCorpse(): void;
    SendTargetCommand(EntityID: number): void;
    MoveItemToInventory(BInst: ItemInstance , UpdateClient: boolean): boolean;
    HandleRespawnFromHover(Option: number): void;
    IsHoveringForRespawn(): boolean;
    AddRespawnOption(option_name: string, zoneid: number, instance_id: number, x: float, y: float, z: float, h: float, initial_selection: boolean, position: number): void;
    RemoveRespawnOption(option_name: string): boolean;
    RemoveRespawnOption(position: number): boolean;
    ClearRespawnOptions(): void;
    SetPendingRezzData(XP: number, DBID: number, SpellID: number, CorpseName: char ): void;
    IsRezzPending(): boolean;
    ClearHover(): void;
    IsBlockedBuff(SpellID: number): boolean;
    IsBlockedPetBuff(SpellID: number): boolean;
    IsDraggingCorpse(CorpseID: number): boolean;
    IsDraggingCorpse(): boolean;
    DragCorpses(): void;
    ClearDraggedCorpses(): void;
    ConsentCorpses(consent_name: string, deny: boolean): void;
    SendAltCurrencies(): void;
    SetAlternateCurrencyValue(currency_id: number, new_amount: number): void;
    AddAlternateCurrencyValue(currency_id: number, amount: number, is_scripted: boolean): number;
    SendAlternateCurrencyValues(): void;
    SendAlternateCurrencyValue(currency_id: number, send_if_null: boolean): void;
    GetAlternateCurrencyValue(currency_id: number): number;
    ProcessAlternateCurrencyQueue(): void;
    OpenLFGuildWindow(): void;
    HandleLFGuildResponse(pack: ServerPacket ): void;
    SendLFGuildStatus(): void;
    SendGuildLFGuildStatus(): void;
    XTargettingAvailable(): boolean;
    GetMaxXTargets(): number;
    SetMaxXTargets(NewMax: number): void;
    IsXTarget(m: Mob ): boolean;
    IsClientXTarget(c: Client ): boolean;
    UpdateClientXTarget(c: Client ): void;
    UpdateXTargetType(Type: XTargetType, m: Mob , Name: char ): void;
    AddAutoXTarget(m: Mob , send: boolean): void;
    RemoveXTarget(m: Mob , OnlyAutoSlots: boolean): void;
    SendXTargetPacket(Slot: number, m: Mob ): void;
    SendXTargetUpdates(): void;
    RemoveGroupXTargets(): void;
    RemoveAutoXTargets(): void;
    ShowXTargets(c: Client ): void;
    GetXTargetAutoMgr(): XTargetAutoHaters ;
    SetXTargetAutoMgr(arg0: XTargetAutoHaters ): void;
    SetDirtyAutoHaters(): void;
    ProcessXTargetAutoHaters(): void;
    JoinGroupXTargets(g: Group ): void;
    LeaveGroupXTargets(g: Group ): void;
    LeaveRaidXTargets(r: Raid ): void;
    ClearXTargets(): void;
    GroupFollow(inviter: Client ): boolean;
    GetRunMode(): boolean;
    CheckWaterAutoFireLoS(m: Mob ): boolean;
    SendReloadCommandMessages(): void;
    SendItemRecastTimer(recast_type: number, recast_delay: number, in_ignore_casting_requirement: boolean): void;
    SetItemRecastTimer(spell_id: number, inventory_slot: number): void;
    DeleteItemRecastTimer(item_id: number): void;
    HasItemRecastTimer(spell_id: number, inventory_slot: number): boolean;
    AggroMeterAvailable(): boolean;
    SetAggroMeterLock(arg0: number): void;
    ProcessAggroMeter(): void;
    InitializeMercInfo(): void;
    CheckCanSpawnMerc(template_id: number): boolean;
    CheckCanHireMerc(merchant: Mob , template_id: number): boolean;
    CheckCanRetainMerc(upkeep: number): boolean;
    CheckCanUnsuspendMerc(): boolean;
    DismissMerc(MercID: number): boolean;
    MercOnlyOrNoGroup(): boolean;
    GetMercenaryID(): number;
    GetMercSlot(): number;
    SetMercID(newmercid: number): void;
    SetMercSlot(newmercslot: number): void;
    GetMerc(): Merc ;
    GetMercInfo(slot: number): MercInfo ;
    GetMercInfo(): MercInfo ;
    GetNumberOfMercenaries(): number;
    SetMerc(newmerc: Merc ): void;
    SendMercResponsePackets(ResponseType: number): void;
    SendMercMerchantResponsePacket(response_type: number): void;
    SendMercenaryUnknownPacket(type: number): void;
    SendMercenaryUnsuspendPacket(type: number): void;
    SendMercTimer(merc: Merc ): void;
    SendMercTimerPacket(entity_id: number, merc_state: number, suspended_time: number, update_interval: number, unk01: number): void;
    SendMercSuspendResponsePacket(suspended_time: number): void;
    SendMercAssignPacket(entityID: number, unk01: number, unk02: number): void;
    SendMercPersonalInfo(): void;
    SendClearMercInfo(): void;
    SuspendMercCommand(): void;
    SpawnMercOnZone(): void;
    SpawnMerc(merc: Merc , setMaxStats: boolean): void;
    UpdateMercTimer(): void;
    UpdateMercLevel(): void;
    CheckMercSuspendTimer(): void;
    GetMercTimer(): Timer ;
    GetPickLockTimer(): Timer ;
    SendWebLink(website: char ): void;
    SendMarqueeMessage(type: number, message: string, duration: number): void;
    SendMarqueeMessage(type: number, priority: number, fade_in: number, fade_out: number, duration: number, message: string): void;
    SendSpellAnim(targetid: number, spell_id: number): void;
    DuplicateLoreMessage(ItemID: number): void;
    GarbleMessage(arg0: char , arg1: number): void;
    ItemTimerCheck(): void;
    TryItemTimer(slot: number): void;
    SendItemScale(inst: ItemInstance ): void;
    GetActSTR(): number;
    GetActSTA(): number;
    GetActDEX(): number;
    GetActAGI(): number;
    GetActINT(): number;
    GetActWIS(): number;
    GetActCHA(): number;
    LoadAccountFlags(): void;
    ClearAccountFlag(flag: string ): void;
    SetAccountFlag(flag: string , value: string ): void;
    GetAccountFlag(flag: string ): string;
    GetAccountFlags(): string;
    SetGMStatus(new_status: number): void;
    Consume(item: ItemData , type: number, slot: number, auto_consume: boolean): void;
    PlayMP3(fname: char ): void;
    ExpeditionSay(str: char , ExpID: number): void;
    GetEnvironmentDamageModifier(): number;
    SetEnvironmentDamageModifier(val: number): void;
    GetInvulnerableEnvironmentDamage(): boolean;
    SetInvulnerableEnvironmentDamage(val: boolean): void;
    SetIntoxication(in_intoxication: number): void;
    ApplyWeaponsStance(): void;
    TogglePassiveAlternativeAdvancement(rank: Rank , ability_id: number): void;
    UseTogglePassiveHotkey(rank: Rank ): boolean;
    TogglePurchaseAlternativeAdvancementRank(rank_id: number): void;
    ResetAlternateAdvancementRank(aa_id: number): void;
    IsEffectinAlternateAdvancementRankEffects(rank: Rank , effect_id: number): boolean;
    TripInterrogateInvState(): void;
    GetInterrogateInvState(): boolean;
    InterrogateInventory(requester: Client , log: boolean, silent: boolean, allowtrip: boolean, error: bool , autolog: boolean): boolean;
    SetNextInvSnapshot(interval_in_min: number): void;
    GetLastInvSnapshotTime(): number;
    GetNextInvSnapshotTime(): number;
    QuestReward(target: Mob , copper: number, silver: number, gold: number, platinum: number, itemid: number, exp: number, faction: boolean): void;
    QuestReward(target: Mob , reward: QuestReward_Struct , faction: boolean): void;
    CashReward(copper: number, silver: number, gold: number, platinum: number): void;
    RewardFaction(id: number, amount: number): void;
    ResetHPUpdateTimer(): void;
    SendHPUpdateMarquee(): void;
    CheckRegionTypeChanges(): void;
    GetLastRegion(): WaterRegionType;
    CalcATK(): number;
    SetLastPositionBeforeBulkUpdate(in_last_position_before_bulk_update: vec4): void;
    GetLastPositionBeforeBulkUpdate(): vec4 ;
    ShowDevToolsMenu(): void;
    GetGuildPublicNote(): string;
    GetPlayerEvent(): PlayerEvent;
    RecordKilledNPCEvent(n: NPC ): void;
    GetEXPForLevel(check_level: number): number;
    GetDoorToolEntityId(): number;
    SetDoorToolEntityId(door_tool_entity_id: number): void;
    GetObjectToolEntityId(): number;
    SetObjectToolEntityId(object_tool_entity_id: number): void;
    IsLockSavePosition(): boolean;
    SetLockSavePosition(lock_save_position: boolean): void;
    SetSharedTaskId(shared_task_id: number): void;
    GetSharedTaskId(): number;
    GetBotOption(boo: BotOwnerOption): boolean;
    SetBotOption(boo: BotOwnerOption, flag: boolean): void;
    GetBotPulling(): boolean;
    SetBotPulling(flag: boolean): void;
    GetBotPrecombat(): boolean;
    SetBotPrecombat(flag: boolean): void;
    GetBotRequiredLevel(class_id: number): number;
    GetBotCreationLimit(class_id: number): number;
    GetBotSpawnLimit(class_id: number): number;
    SetBotCreationLimit(new_creation_limit: number, class_id: number): void;
    SetBotRequiredLevel(new_required_level: number, class_id: number): void;
    SetBotSpawnLimit(new_spawn_limit: number, class_id: number): void;
    CampAllBots(class_id: number): void;
    SpawnRaidBotsOnConnect(raid: Raid ): void;
    GetMailKeyFull(): string ;
    GetMailKey(): string ;
    CalcEdibleBonuses(newbon: StatBonuses ): void;
    MakeBuffFadePacket(spell_id: number, slot_id: number, send_message: boolean): void;
    FinishAlternateAdvancementPurchase(rank: Rank , ignore_cost: boolean, send_message_and_save: boolean): void;
    HandlePacket(app: EQApplicationPacket ): number;
    OPTGB(app: EQApplicationPacket ): void;
    OPRezzAnswer(Action: number, SpellID: number, ZoneID: number, InstanceID: number, x: float, y: float, z: float): void;
    OPMemorizeSpell(app: EQApplicationPacket ): void;
    OPMoveCoin(app: EQApplicationPacket ): void;
    MoveItemCharges(from: ItemInstance , to_slot: number, type: number): void;
    OPGMTraining(app: EQApplicationPacket ): void;
    OPGMEndTraining(app: EQApplicationPacket ): void;
    OPGMTrainSkill(app: EQApplicationPacket ): void;
    OPGMSummon(app: EQApplicationPacket ): void;
    OPCombatAbility(ca_atk: CombatAbility_Struct ): void;
    CreateBandolier(app: EQApplicationPacket ): void;
    RemoveBandolier(app: EQApplicationPacket ): void;
    SetBandolier(app: EQApplicationPacket ): void;
    HandleTraderPriceUpdate(app: EQApplicationPacket ): void;
    CalcItemATKCap(): number;
    CalcHaste(): number;
    CalcAlcoholPhysicalEffect(): number;
    CalcSTR(): number;
    CalcSTA(): number;
    CalcDEX(): number;
    CalcAGI(): number;
    CalcINT(): number;
    CalcWIS(): number;
    CalcCHA(): number;
    CalcMR(): number;
    CalcFR(): number;
    CalcDR(): number;
    CalcPR(): number;
    CalcCR(): number;
    CalcCorrup(): number;
    CalcMaxHP(): number;
    CalcBaseHP(): number;
    CalcHPRegen(bCombat: boolean): number;
    CalcManaRegen(bCombat: boolean): number;
    CalcBaseManaRegen(): number;
    DoHPRegen(): void;
    DoManaRegen(): void;
    DoStaminaHungerUpdate(): void;
    CalcRestState(): void;
    GetRestTimer(): number;
    UpdateRestTimer(new_timer: number): void;
    NPCSpawn(sep: Seperator ): void;
    SendLogoutPackets(): void;
    SendZoneInPackets(): void;
    AddPacket(arg0: EQApplicationPacket , arg1: boolean): boolean;
    AddPacket(arg0: EQApplicationPacket  , arg1: boolean): boolean;
    SendAllPackets(): boolean;
    SendZoneCancel(zc: ZoneChange_Struct ): void;
    SendZoneError(zc: ZoneChange_Struct , err: number): void;
    DoZoneSuccess(zc: ZoneChange_Struct , zone_id: number, instance_id: number, dest_x: float, dest_y: float, dest_z: float, dest_h: float, ignore_r: number): void;
    ZonePC(zoneID: number, instance_id: number, x: float, y: float, z: float, heading: float, ignorerestrictions: number, zm: ZoneMode): void;
    ProcessMovePC(zoneID: number, instance_id: number, x: float, y: float, z: float, heading: float, ignorerestrictions: number, zm: ZoneMode): void;
    BulkSendInventoryItems(): void;
    ReportConnectingState(): void;
    InterrogateInventory_(errorcheck: boolean, requester: Client , head: number, index: number, inst: ItemInstance , parent: ItemInstance , log: boolean, silent: boolean, error: bool , depth: number): void;
    InterrogateInventory_error(head: number, index: number, inst: ItemInstance , parent: ItemInstance , depth: number): boolean;
    CanTradeFVNoDropItem(): boolean;
    SendMobPositions(): void;
    PlayerTradeEventLog(t: Trade , t2: Trade ): void
  }

  export class Corpse extends Mob {
    constructor(npc: NPC , item_list: LootItems , npc_type_id: number, npc_type_data: NPCType  , decay_time: number);;
  constructor(c: Client , rez_exp: number, killed_by: KilledByTypes);;
  constructor(corpse_id: number, character_id: number, character_name: char , item_list: LootItems , copper: number, silver: number, gold: number, platinum: number, position: vec4 , size: float, gender: number, race: number, class_: number, deity: number, level: number, texture: number, helm_texture: number, rez_exp: number, gm_rez_exp: number, killed_by: KilledByTypes, is_rezzable: boolean, rez_remaining_time: number, was_at_graveyard: boolean);;
  constructor();
      corpse_name : number;
    SendEndLootErrorPacket(client: Client ): void;
    SendLootReqErrorPacket(client: Client , response: LootResponse): void;
    Death(killer_mob: Mob , damage: number, spell_id: number, attack_skill: SkillType, killed_by: KilledByTypes): boolean;
    Damage(from: Mob , damage: number, spell_id: number, attack_skill: SkillType, avoidable: boolean, buffslot: number, iBuffTic: boolean, special: eSpecialAttacks): void;
    Attack(other: Mob , Hand: number, FromRiposte: boolean, IsStrikethrough: boolean, IsFromSpell: boolean, opts: ExtraAttackOptions ): boolean;
    HasRaid(): boolean;
    HasGroup(): boolean;
    GetRaid(): Raid ;
    GetGroup(): Group ;
    GetCorpseDBID(): number;
    GetOwnerName(): char ;
    IsEmpty(): boolean;
    IsCorpse(): boolean;
    IsPlayerCorpse(): boolean;
    IsNPCCorpse(): boolean;
    IsBecomeNPCCorpse(): boolean;
    DepopNPCCorpse(): void;
    DepopPlayerCorpse(): void;
    Process(): boolean;
    Save(): boolean;
    GetCharID(): number;
    SetCharID(iCharID: number): number;
    GetDecayTime(): number;
    GetRezTime(): number;
    ResetDecayTimer(): void;
    SetDecayTimer(decay_time: number): void;
    SetConsentGroupID(group_id: number): void;
    SetConsentRaidID(raid_id: number): void;
    SetConsentGuildID(guild_id: number): void;
    AddConsentName(consent_player_name: string ): void;
    RemoveConsentName(consent_player_name: string ): void;
    SendWorldSpawnPlayerCorpseInZone(zone_id: number): void;
    MovePlayerCorpseToGraveyard(): boolean;
    MovePlayerCorpseToNonInstance(): boolean;
    Delete(): void;
    Bury(): void;
    CalcCorpseName(): void;
    LoadPlayerCorpseDecayTime(dbid: number): void;
    GetWornItem(equip_slot: number): number;
    GetItem(lootslot: number, bag_item_data: LootItem  ): LootItem ;
    SetPlayerKillItemID(pk_item_id: number): void;
    GetPlayerKillItem(): number;
    RemoveItem(lootslot: number): void;
    RemoveItem(item_data: LootItem ): void;
    RemoveItemByID(item_id: number, quantity: number): void;
    AddItem(itemnum: number, charges: number, slot: number, aug1: number, aug2: number, aug3: number, aug4: number, aug5: number, aug6: number, attuned: boolean, custom_data: string , ornamenticon: number, ornamentidfile: number, ornament_hero_model: number): void;
    SetCash(in_copper: number, in_silver: number, in_gold: number, in_platinum: number): void;
    RemoveCash(): void;
    GetCopper(): number;
    GetSilver(): number;
    GetGold(): number;
    GetPlatinum(): number;
    IsRezzed(): boolean;
    IsRezzed(in_rez: boolean): void;
    CastRezz(spell_id: number, caster: Mob ): void;
    CompleteResurrection(timer_expired: boolean): void;
    IsRezzable(): boolean;
    SetRezTimer(initial_timer: boolean): void;
    QueryLoot(to: Client ): void;
    HasItem(item_id: number): boolean;
    CountItem(item_id: number): number;
    GetItemIDBySlot(loot_slot: number): number;
    GetFirstLootSlotByItemID(item_id: number): number;
    GetLootList(): number;
    LootCorpseItem(c: Client , app: EQApplicationPacket ): void;
    EndLoot(c: Client , app: EQApplicationPacket ): void;
    MakeLootRequestPackets(c: Client , app: EQApplicationPacket ): void;
    AllowPlayerLoot(them: Mob , slot: number): void;
    AddLooter(who: Mob ): void;
    CountItems(): number;
    CanPlayerLoot(character_id: number): boolean;
    Lock(): void;
    UnLock(): void;
    IsLocked(): boolean;
    ResetLooter(): void;
    IsBeingLooted(): boolean;
    IsBeingLootedBy(c: Client ): boolean;
    FillSpawnStruct(ns: NewSpawn_Struct , ForWho: Mob ): void;
    Summon(c: Client , spell: boolean, CheckDistance: boolean): boolean;
    Spawn(): void;
    GetEquippedItemFromTextureSlot(material_slot: number): number;
    GetEquipmentColor(material_slot: number): number;
    GetRezExp(): number;
    GetGMRezExp(): number;
    GetKilledBy(): number;
    GetRemainingRezTime(): number;
    UpdateEquipmentLight(): void;
    CheckIsOwnerOnline(): void;
    SetOwnerOnline(value: boolean): void;
    GetOwnerOnline(): boolean;
    LoadCharacterCorpse(cc: CharacterCorpses , position: vec4 ): Corpse ;
    MoveItemToCorpse(client: Client , inst: ItemInstance , equipSlot: number, removedList: number): void
  }

  export class Doors extends Entity {
    constructor();;
  constructor(model: char , position: vec4 , open_type: number, size: number);;
  constructor(door: Doors );
      triggered : boolean;
    GetDisableTimer(): boolean;
    IsDoor(): boolean;
    IsDoorOpen(): boolean;
    Process(): boolean;
    GetDoorName(): char ;
    GetPosition(): vec4 ;
    GetDzSwitchID(): number;
    GetIncline(): number;
    GetInvertState(): number;
    GetDoorID(): number;
    GetNoKeyring(): number;
    GetOpenType(): number;
    GetTriggerDoorID(): number;
    GetTriggerType(): number;
    IsLDoNDoor(): number;
    GetLockpick(): number;
    GetSize(): number;
    GetClientVersionMask(): number;
    GetDoorDBID(): number;
    GetDoorParam(): number;
    GetEntityID(): number;
    GetGuildID(): number;
    GetKeyItem(): number;
    CreateDatabaseEntry(): void;
    ForceClose(sender: Mob , alt_mode: boolean): void;
    ForceOpen(sender: Mob , alt_mode: boolean): void;
    HandleClick(sender: Client , trigger: number): void;
    Open(sender: Mob , alt_mode: boolean): void;
    SetDisableTimer(flag: boolean): void;
    SetDoorName(name: char ): void;
    SetEntityID(entity: number): void;
    SetIncline(arg0: number): void;
    SetInvertState(arg0: number): void;
    SetKeyItem(arg0: number): void;
    SetLocation(x: float, y: float, z: float): void;
    SetLockpick(arg0: number): void;
    SetNoKeyring(arg0: number): void;
    SetOpenState(st: boolean): void;
    SetOpenType(arg0: number): void;
    SetPosition(position: vec4 ): void;
    SetSize(size: number): void;
    ToggleState(sender: Mob ): void;
    GetX(): float;
    GetY(): float;
    GetZ(): float;
    GetHeading(): float;
    HasDestinationZone(): boolean;
    IsDestinationZoneSame(): boolean;
    IsDoorBlacklisted(): boolean;
    GetIsDoorBlacklisted(): boolean
  }

  export class GroupIDConsumer {
    constructor();;
  constructor(gid: number);
  
    GetID(): number;
    SetID(set_id: number): void
  }

  export class Group extends GroupIDConsumer {
    constructor(leader: Mob );;
  constructor(gid: number);;
  constructor();
  
    AddMember(newmember: Mob , NewMemberName: char , CharacterID: number, ismerc: boolean): boolean;
    AddMember(NewMemberName: char ): void;
    SendUpdate(type: number, member: Mob ): void;
    SendLeadershipAAUpdate(): void;
    SendWorldGroup(zone_id: number, zoningmember: Mob ): void;
    DelMemberOOZ(Name: char ): boolean;
    DelMember(oldmember: Mob , ignoresender: boolean): boolean;
    DisbandGroup(joinraid: boolean): void;
    GetMemberList(member_list: list<Mob > , clear_list: boolean): void;
    GetClientList(client_list: list<Client > , clear_list: boolean): void;
    GetBotList(bot_list: list<Bot > , clear_list: boolean): void;
    IsGroupMember(c: Mob ): boolean;
    IsGroupMember(name: char ): boolean;
    Process(): boolean;
    IsGroup(): boolean;
    SendGroupJoinOOZ(NewMember: Mob ): void;
    CastGroupSpell(caster: Mob , spellid: number): void;
    SplitExp(exp: number, other: Mob ): void;
    GroupMessage(sender: Mob , language: number, lang_skill: number, message: char ): void;
    GroupMessageString(sender: Mob , type: number, string_id: number, message: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char , distance: number): void;
    GetTotalGroupDamage(other: Mob ): number;
    SplitMoney(copper: number, silver: number, gold: number, platinum: number, splitter: Client ): void;
    SetLeader(c: Mob ): void;
    GetLeader(): Mob ;
    GetLeaderName(): char ;
    SendHPManaEndPacketsTo(newmember: Mob ): void;
    SendHPPacketsFrom(member: Mob ): void;
    SendManaPacketFrom(member: Mob ): void;
    SendEndurancePacketFrom(member: Mob ): void;
    UpdatePlayer(update: Mob ): boolean;
    MemberZoned(removemob: Mob ): void;
    IsLeader(name: char ): boolean;
    IsLeader(m: Mob ): boolean;
    GroupCount(): number;
    GetHighestLevel(): number;
    GetLowestLevel(): number;
    QueuePacket(app: EQApplicationPacket , ack_req: boolean): void;
    TeleportGroup(sender: Mob , zoneID: number, instance_id: number, x: float, y: float, z: float, heading: float): void;
    GetAvgLevel(): number;
    LearnMembers(): boolean;
    VerifyGroup(): void;
    BalanceHP(penalty: number, range: float, caster: Mob , limit: number): void;
    BalanceMana(penalty: number, range: float, caster: Mob , limit: number): void;
    HealGroup(heal_amt: number, caster: Mob , range: float): void;
    SetGroupAAs(From: GroupLeadershipAA_Struct ): void;
    GetGroupAAs(Into: GroupLeadershipAA_Struct ): void;
    UpdateGroupAAs(): void;
    SaveGroupLeaderAA(): void;
    MarkNPC(Target: Mob , Number: number): void;
    GetNumberNeedingHealedInGroup(hpr: number, includePets: boolean): number;
    DelegateMainTank(NewMainAssistName: char , toggle: number): void;
    DelegateMainAssist(NewMainAssistName: char , toggle: number): void;
    DelegatePuller(NewMainAssistName: char , toggle: number): void;
    UnDelegateMainTank(OldMainAssistName: char , toggle: number): void;
    UnDelegateMainAssist(OldMainAssistName: char , toggle: number): void;
    UnDelegatePuller(OldMainAssistName: char , toggle: number): void;
    IsNPCMarker(c: Client ): boolean;
    SetGroupAssistTarget(m: Mob ): void;
    SetGroupTankTarget(m: Mob ): void;
    SetGroupPullerTarget(m: Mob ): void;
    HasRole(m: Mob , Role: number): boolean;
    NotifyAssistTarget(c: Client ): void;
    NotifyTankTarget(c: Client ): void;
    NotifyPullerTarget(c: Client ): void;
    DelegateMarkNPC(NewNPCMarkerName: char ): void;
    UnDelegateMarkNPC(OldNPCMarkerName: char ): void;
    NotifyMainTank(c: Client , toggle: number): void;
    NotifyMainAssist(c: Client , toggle: number): void;
    NotifyPuller(c: Client , toggle: number): void;
    NotifyMarkNPC(c: Client ): void;
    GetNPCMarkerID(): number;
    SetMainTank(NewMainTankName: char ): void;
    SetMainAssist(NewMainAssistName: char ): void;
    SetPuller(NewPullerName: char ): void;
    GetMainTankName(): char ;
    GetMainAssistName(): char ;
    GetPullerName(): char ;
    AmIMainTank(mob_name: char ): boolean;
    AmIMainAssist(mob_name: char ): boolean;
    AmIPuller(mob_name: char ): boolean;
    SetNPCMarker(NewNPCMarkerName: char ): void;
    UnMarkNPC(ID: number): void;
    SendMarkedNPCsToMember(c: Client , Clear: boolean): void;
    GetLeadershipAA(AAID: number): number;
    ClearAllNPCMarks(): void;
    QueueHPPacketsForNPCHealthAA(sender: Mob , app: EQApplicationPacket ): void;
    QueueClients(sender: Mob , app: EQApplicationPacket , ack_required: boolean, ignore_sender: boolean, distance: float): void;
    ChangeLeader(newleader: Mob ): void;
    GetClientNameByIndex(index: number): char ;
    UpdateXTargetMarkedNPC(Number: number, m: Mob ): void;
    SetDirtyAutoHaters(): void;
    GetXTargetAutoMgr(): XTargetAutoHaters ;
    JoinRaidXTarget(raid: Raid , first: boolean): void;
    SetGroupMentor(percent: number, name: char ): void;
    ClearGroupMentor(): void;
    GetMentorPercent(): number;
    GetMentoree(): Client ;
    DoesAnyMemberHaveExpeditionLockout(expedition_name: string , event_name: string , max_check_count: number): boolean;
    GetGroupLeaderName(group_id: number): string
  }

  export class Object extends Entity {
    constructor(id: number, type: number, icon: number, data: Object_Struct , inst: ItemInstance , fix_z: boolean);;
  constructor(inst: ItemInstance , name: string , max_x: float, min_x: float, max_y: float, min_y: float, z: float, heading: float, respawn_timer: number, fix_z: boolean);;
  constructor(client: Client , inst: ItemInstance );;
  constructor(inst: ItemInstance , x: float, y: float, z: float, heading: float, decay_time: number, fix_z: boolean);;
  constructor(model: string , x: float, y: float, z: float, heading: float, type: number, decay_time: number);;
  constructor();
  
    Process(): boolean;
    IsGroundSpawn(): boolean;
    HandleClick(sender: Client , click_object: ClickObject_Struct ): boolean;
    Close(): void;
    Delete(reset_state: boolean): void;
    HandleCombine(user: Client , in_combine: NewCombine_Struct , worldo: Object ): void;
    HandleAugmentation(user: Client , in_augment: AugmentItem_Struct , worldo: Object ): void;
    HandleAutoCombine(user: Client , rac: RecipeAutoCombine_Struct ): void;
    CreateSpawnPacket(app: EQApplicationPacket ): void;
    CreateDeSpawnPacket(app: EQApplicationPacket ): void;
    Depop(): void;
    Repop(): void;
    IsFixZEnabled(): boolean;
    SetFixZ(fix_z: boolean): void;
    StartDecay(): void;
    GetItem(index: number): ItemInstance ;
    PutItem(index: number, inst: ItemInstance ): void;
    DeleteItem(index: number): void;
    PopItem(index: number): ItemInstance ;
    IsObject(): boolean;
    Save(): boolean;
    VarSave(): number;
    SetID(set_id: number): void;
    ClearUser(): void;
    GetDBID(): number;
    GetType(): number;
    SetType(type: number): void;
    GetIcon(): number;
    SetIcon(icon: number): void;
    GetItemID(): number;
    SetItemID(itemid: number): void;
    GetObjectData(Data: Object_Struct ): void;
    SetObjectData(Data: Object_Struct ): void;
    GetLocation(x: float , y: float , z: float ): void;
    SetLocation(x: float, y: float, z: float): void;
    GetHeading(heading: float ): void;
    SetHeading(heading: float): void;
    GetX(): float;
    GetY(): float;
    GetZ(): float;
    GetHeadingData(): float;
    SetX(pos: float): void;
    SetY(pos: float): void;
    SetZ(pos: float): void;
    SetTiltX(pos: float): void;
    SetTiltY(pos: float): void;
    GetTiltX(): float;
    GetTiltY(): float;
    SetModelName(modelname: char ): void;
    GetModelName(): char ;
    GetSize(): float;
    SetSize(size: float): void;
    GetSolidType(): number;
    SetSolidType(size: number): void;
    SetDisplayName(in_name: char ): void;
    GetDisplayName(): char ;
    ClearEntityVariables(): boolean;
    DeleteEntityVariable(variable_name: string): boolean;
    GetEntityVariable(variable_name: string): string;
    GetEntityVariables(): string;
    SetEntityVariable(variable_name: string, variable_value: string): void;
    EntityVariableExists(variable_name: string): boolean;
    ResetState(): void;
    RandomSpawn(send_packet: boolean): void;
    FixZ(): void
  }

  export class Raid extends GroupIDConsumer {
    constructor(nLeader: Client );;
  constructor(raidID: number);;
  constructor();
      members : RaidMember;
    leadername : number;
    main_assister_pcs : number;
    main_marker_pcs : number;
    marked_npcs : Raid_Marked_NPC;
    SetLeader(c: Client ): void;
    GetLeader(): Client ;
    GetLeaderName(): string;
    IsLeader(c: Client ): boolean;
    IsLeader(name: char ): boolean;
    SetRaidLeader(wasLead: char , name: char ): void;
    Process(): boolean;
    AddMember(c: Client , group: number, rleader: boolean, groupleader: boolean, looter: boolean): void;
    AddBot(b: Bot , group: number, raid_leader: boolean, group_leader: boolean, looter: boolean): void;
    RaidGroupSay(msg: char , from: char , language: number, lang_skill: number): void;
    RaidSay(msg: char , from: char , language: number, lang_skill: number): void;
    IsEngaged(): boolean;
    GetRaidMainAssistOne(): Mob ;
    RemoveMember(character_name: char ): void;
    DisbandRaid(): void;
    MoveMember(name: char , newGroup: number): void;
    SetGroupLeader(who: char , glFlag: boolean): void;
    GetGroupLeader(group_id: number): Client ;
    RemoveGroupLeader(who: char ): void;
    IsGroupLeader(name: char ): boolean;
    IsGroupLeader(c: Client ): boolean;
    IsRaidMember(name: char ): boolean;
    IsRaidMember(c: Client ): boolean;
    UpdateLevel(name: char , newLevel: number): void;
    SetNewRaidLeader(i: number): void;
    IsAssister(who: char ): boolean;
    IsMarker(who: char ): boolean;
    EmptyRaidMembers(): void;
    GetFreeGroup(): number;
    GroupCount(gid: number): number;
    RaidCount(): number;
    GetHighestLevel(): number;
    GetLowestLevel(): number;
    GetGroup(name: char ): number;
    GetGroup(c: Client ): number;
    GetAvgLevel(): number;
    GetLootType(): number;
    ChangeLootType(type: number): void;
    AddRaidLooter(looter: char ): void;
    RemoveRaidLooter(looter: char ): void;
    SetRaidMOTD(in_motd: string ): void;
    GetPlayerIndex(name: char ): number;
    GetPlayerIndex(c: Client ): number;
    GetClientByIndex(index: number): Client ;
    GetClientNameByIndex(index: number): char ;
    LockRaid(lockFlag: boolean): void;
    IsLocked(): boolean;
    RaidMessageString(sender: Mob , type: number, string_id: number, message: char , message2: char , message3: char , message4: char , message5: char , message6: char , message7: char , message8: char , message9: char , distance: number): void;
    CastGroupSpell(caster: Mob , spellid: number, gid: number): void;
    SplitExp(exp: number, other: Mob ): void;
    GetTotalRaidDamage(other: Mob ): number;
    BalanceHP(penalty: number, gid: number, range: float, caster: Mob , limit: number): void;
    BalanceMana(penalty: number, gid: number, range: float, caster: Mob , limit: number): void;
    HealGroup(heal_amt: number, caster: Mob , gid: number, range: float): void;
    SplitMoney(gid: number, copper: number, silver: number, gold: number, platinum: number, splitter: Client ): void;
    TeleportGroup(sender: Mob , zoneID: number, instance_id: number, x: float, y: float, z: float, heading: float, gid: number): void;
    TeleportRaid(sender: Mob , zoneID: number, instance_id: number, x: float, y: float, z: float, heading: float): void;
    SetRaidDetails(): void;
    GetRaidDetails(): void;
    SaveRaidMOTD(): void;
    LearnMembers(): boolean;
    VerifyRaid(): void;
    MemberZoned(c: Client ): void;
    SendHPManaEndPacketsTo(c: Client ): void;
    SendHPManaEndPacketsFrom(mob: Mob ): void;
    SendManaPacketFrom(mob: Mob ): void;
    SendEndurancePacketFrom(mob: Mob ): void;
    RaidSay(msg: char , c: Client , language: number, lang_skill: number): void;
    RaidGroupSay(msg: char , c: Client , language: number, lang_skill: number): void;
    SaveRaidNote(who: string, note: string): void;
    GetMembersWithNotes(): vector<RaidMember >;
    DelegateAbilityAssist(mob: Mob , who: char ): void;
    DelegateAbilityMark(mob: Mob , who: char ): void;
    RaidMarkNPC(mob: Mob , parameter: number): void;
    UpdateXTargetType(Type: XTargetType, m: Mob , name: char ): void;
    FindNextRaidDelegateSlot(option: number): number;
    UpdateXtargetMarkedNPC(): void;
    RaidClearNPCMarks(c: Client ): void;
    RemoveRaidDelegates(delegatee: char ): void;
    UpdateRaidXTargets(): void;
    SendRaidCreate(to: Client ): void;
    SendRaidAdd(who: char , to: Client ): void;
    SendRaidAddAll(who: char ): void;
    SendRaidRemove(who: char , to: Client ): void;
    SendRaidRemoveAll(who: char ): void;
    SendRaidDisband(to: Client ): void;
    SendRaidDisbandAll(): void;
    SendRaidMove(who: char , to: Client ): void;
    SendRaidMoveAll(who: char ): void;
    SendBulkRaid(to: Client ): void;
    SendRaidNotes(): void;
    SendRaidNotesToWorld(): void;
    SendRemoveRaidXTargets(Type: XTargetType): void;
    SendRemoveAllRaidXTargets(): void;
    SendRemoveAllRaidXTargets(client_name: char ): void;
    SendRaidAssistTarget(): void;
    SendAssistTarget(c: Client ): void;
    GroupUpdate(gid: number, initial: boolean): void;
    SendGroupUpdate(to: Client ): void;
    SendGroupDisband(to: Client ): void;
    SendRaidLock(): void;
    SendRaidUnlock(): void;
    SendRaidLockTo(c: Client ): void;
    SendRaidUnlockTo(c: Client ): void;
    SendRaidGroupAdd(who: char , gid: number): void;
    SendRaidGroupRemove(who: char , gid: number): void;
    SendMakeLeaderPacket(who: char ): void;
    SendMakeLeaderPacketTo(who: char , to: Client ): void;
    SendMakeGroupLeaderPacketAll(): void;
    SendMakeGroupLeaderPacket(who: char ): void;
    SendMakeGroupLeaderPacketTo(who: char , to: Client ): void;
    SendRaidMOTD(c: Client ): void;
    SendRaidMOTD(): void;
    SendRaidMOTDToWorld(): void;
    SendRaidAssisterTo(assister: char , to: Client ): void;
    SendRaidAssister(assister: char ): void;
    SendRaidMarkerTo(marker: char , to: Client ): void;
    SendRaidMarker(marker: char ): void;
    SendMarkTargets(c: Client ): void;
    QueuePacket(app: EQApplicationPacket , ack_req: boolean): void;
    UpdateGroupAAs(gid: number): void;
    SaveGroupLeaderAA(gid: number): void;
    UpdateRaidAAs(): void;
    SaveRaidLeaderAA(): void;
    SendGroupLeadershipAA(c: Client , gid: number): void;
    SendGroupLeadershipAA(gid: number): void;
    SendAllRaidLeadershipAA(): void;
    LoadLeadership(): void;
    GetLeadershipAA(AAID: number, gid: number): number;
    SetGroupAAs(gid: number, glaa: GroupLeadershipAA_Struct ): void;
    SetRaidAAs(rlaa: RaidLeadershipAA_Struct ): void;
    SetGroupMentor(group_id: number, percent: number, name: char ): void;
    ClearGroupMentor(group_id: number): void;
    CheckGroupMentor(group_id: number, c: Client ): void;
    GetMentorPercent(group_id: number): number;
    GetMentoree(group_id: number): Client ;
    SetDirtyAutoHaters(): void;
    GetXTargetAutoMgr(): XTargetAutoHaters ;
    QueueClients(sender: Mob , app: EQApplicationPacket , ack_required: boolean, ignore_sender: boolean, distance: float, group_only: boolean): void;
    DoesAnyMemberHaveExpeditionLockout(expedition_name: string , event_name: string , max_check_count: number): boolean;
    GetMembers(): vector<RaidMember >;
    GetRaidGroupMembers(gid: number): vector<RaidMember >;
    GetRaidGroupBotMembers(gid: number): vector<Bot  >;
    GetRaidBotMembers(owner: number): vector<Bot  >;
    HandleBotGroupDisband(owner: number, gid: number): void;
    HandleOfflineBots(owner: number): void
  }

  export class Trap extends Entity {
    constructor();;
  constructor();
      respawn_timer : Timer;
    chkarea_timer : Timer;
    reset_timer : Timer;
    trap_id : number;
    db_id : number;
    m_Position : vec3;
    maxzdiff : float;
    radius : float;
    chance : number;
    effect : number;
    effectvalue : number;
    effectvalue2 : number;
    skill : number;
    level : number;
    detected : boolean;
    disarmed : boolean;
    respawn_time : number;
    respawn_var : number;
    triggered_number : number;
    times_triggered : number;
    group : number;
    despawn_when_triggered : boolean;
    charid : number;
    undetectable : boolean;
    message : string;
    Process(): boolean;
    IsTrap(): boolean;
    Trigger(trigger: Mob ): void;
    SpellOnTarget(trigger: Mob , spell_id: number): void;
    GetHiddenTrigger(): NPC ;
    SetHiddenTrigger(n: NPC ): void;
    CreateHiddenTrigger(): void;
    DestroyHiddenTrigger(): void;
    UpdateTrap(respawn: boolean, repopnow: boolean): void
  }
}
