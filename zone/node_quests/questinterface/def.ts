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

  class ArrayLike<T> {
    filter(predicate: (item?: T, index?: number) => boolean): Array<T>;
    find(predicate: (item?: T, index?: number) => boolean): T;
    findIndex(predicate: (item?: T, index?: number) => boolean): number;
    forEach(predicate: (item?: T, index?: number) => void): void;
    includes(item: T): boolean;
    indexOf(item: T): number;
    length: number;
    flatMap(predicate: (item?: T, index?: number) => any): Array<any>;
    map(predicate: (item?: T, index?: number) => any): Array<any>;
    reverse(): Array<T>;
    slice(start: number, end: number): Array<T>;
    toArray(): Array<T>;
  }

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

  /** Static functions **/


  /** Enums and Enum Class Wrappers **/
  const NumHitEnum = {
    ncomingHitAttempts: 1,
    ttempted: 2,
    utgoing: 4,
    ny: 7,
    uccessful: 8,
    ncoming: 9,
    efensive: 10
  } as const;
  export const NumHit: EnumInstance<typeof NumHitEnum>;
  export class NumHitPtr extends EnumPtr<typeof NumHitEnum> {}

  const GravityBehaviorEnum = {
    round: 0,
    lying: 1,
    evitating: 2,
    ater: 3,
    loating: 4,
    oat: 5
  } as const;
  export const GravityBehavior: EnumInstance<typeof GravityBehaviorEnum>;
  export class GravityBehaviorPtr extends EnumPtr<typeof GravityBehaviorEnum> {}

  const TradeStateEnum = {
    radeNone: 0,
    rading: 1,
    radeAccepted: 2,
    radeCompleting: 3
  } as const;
  export const TradeState: EnumInstance<typeof TradeStateEnum>;
  export class TradeStatePtr extends EnumPtr<typeof TradeStateEnum> {}

  const CLIENT_CONN_STATUSEnum = {
    LIENT_CONNECTING: 0,
    LIENT_CONNECTED: 1,
    LIENT_LINKDEAD: 2,
    LIENT_KICKED: 3,
    ISCONNECTED: 4,
    LIENT_ERROR: 5,
    LIENT_CONNECTINGALL: 6,
    PO_Sit: 7,
    PO_Guard: 8,
    PO_FeignDeath: 9,
    con: 10,
    ura: 11,
    odyType: 20,
    he: 42,
    ee: 54,
    urx: 82,
    ury: 83,
    ut: 84,
    ther: 85,
    pts: 125,
    ampage: 126,
    nly: 128,
    obuff_invisible: 129,
    nvisible_undead: 130,
    nvisible_animals: 131,
    nnate_see_invis: 132,
    ee_invis_undead: 133,
    idden: 134,
    mproved_hidden: 135,
    ee_improved_hide: 136,
    astAction_type: 279,
    illedByTypes: 365,
    nt8: 370,
    ew_name: 375,
    etName: 377,
    4: 378,
    OtherLevel: 400,
    ate: 410,
    n_hate: 413,
    s_dam: 415,
    rue: 416,
    ith: 418,
    ullptr: 425,
    kip: 428,
    kip_mezzed: 434,
    lm: 440,
    ntityFilterType: 451,
    amage: 453,
    istance: 454,
    ilter_type: 455,
    s_percentage: 456,
    ewSpawn_Struct: 463,
    uraRecord: 480,
    irtual: 502,
    qFilterType: 520,
    oid: 565,
    ournal: 567,
    orpse: 591,
    alue: 643,
    lient: 648,
    alse: 650,
    int64: 691,
    n_y: 705,
    elevant: 819,
    amageHitInfo: 875,
    xtraAttackOptions: 876,
    tatBonuses: 891,
    nt64: 905,
    SpecialAttacks: 911,
    int8: 912,
    : 914,
    therwise: 920,
    Q: 925,
    int16: 945,
    ob: 946,
    ool: 947,
    loat: 950,
    nt16: 951,
    0: 953,
    aybe: 954,
    onus: 957,
    onst: 962,
    td: 964,
    int32: 965,
    nt32: 966,
    nt: 967
  } as const;
  export const CLIENT_CONN_STATUS: EnumInstance<typeof CLIENT_CONN_STATUSEnum>;
  export class CLIENT_CONN_STATUSPtr extends EnumPtr<typeof CLIENT_CONN_STATUSEnum> {}

  const eInnateSkillEnum = {
    nnateEnabled: 0,
    nnateAwareness: 1,
    nnateBashDoor: 2,
    nnateBreathFire: 3,
    nnateHarmony: 4,
    nnateInfravision: 6,
    nnateLore: 8,
    nnateNoBash: 9,
    nnateRegen: 10,
    nnateSlam: 11,
    nnateSurprise: 12,
    nnateUltraVision: 13,
    nnateInspect: 14,
    nnateOpen: 15,
    nnateReveal: 16,
    ize: 16,
    nnateSkillMax: 25
  } as const;
  export const eInnateSkill: EnumInstance<typeof eInnateSkillEnum>;
  export class eInnateSkillPtr extends EnumPtr<typeof eInnateSkillEnum> {}

  const ObjectTypesEnum = {
    taticLocked: 0,
    emporary: 1,
    oolBox: 10,
    esearch: 11,
    ortar: 12,
    elfDusting: 13,
    aking1: 14,
    aking2: 15,
    ailoring: 16,
    orge: 17,
    letching: 18,
    rewBarrel: 19,
    ewelcrafting: 20,
    otteryWheel: 21,
    otteryKiln: 22,
    izardResearch: 24,
    agicianResearch: 25,
    ecromancerResearch: 26,
    nchanterResearch: 27,
    nvalid1: 28,
    nvalid2: 29,
    xperimental: 30,
    ighElfForge: 31,
    arkElfForge: 32,
    greForge: 33,
    warfForge: 34,
    nomeForge: 35,
    arbarianForge: 36,
    ksarForge: 38,
    umanForge: 39,
    umanForge2: 40,
    alflingTailoring: 41,
    ruditeTailoring: 42,
    oodElfTailoring: 43,
    oodElfFletching: 44,
    ksarPotteryWheel: 45,
    rollForge: 47,
    oodElfForge: 48,
    alflingForge: 49,
    ruditeForge: 50,
    ugmentationPool: 53,
    taticUnlocked: 255
  } as const;
  export const ObjectTypes: EnumInstance<typeof ObjectTypesEnum>;
  export class ObjectTypesPtr extends EnumPtr<typeof ObjectTypesEnum> {}

  const TrapTypesEnum = {
    rapTypeDebuff: 0,
    rapTypeAlarm: 1,
    rapTypeMysticSpawn: 2,
    rapTypeBanditSpawn: 3,
    rapTypeDamage: 4
  } as const;
  export const TrapTypes: EnumInstance<typeof TrapTypesEnum>;
  export class TrapTypesPtr extends EnumPtr<typeof TrapTypesEnum> {}

  /** Structs **/

  /** Class Interfaces **/
  export class BulkZoneSpawnPacket {
  

  }

  export class Corpse extends Mob {
  
    Corpse(*c: Client, rez_exp: int32, killed_by: KilledByTypes): );;
    SetDecayTimer(decay_time: uint32): void;
    AddConsentName(consent_player_name: std::string): void;
    RemoveConsentName(consent_player_name: std::string): void;
    SendWorldSpawnPlayerCorpseInZone(zone_id: uint32_t): void;
    LoadPlayerCorpseDecayTime(dbid: uint32): void;
    GetWornItem(equip_slot: int16): uint32;
    RemoveItem(lootslot: uint16): void;
    RemoveItem(*item_data: LootItem): void;
    RemoveItemByID(item_id: uint32, quantity: number): void;
    SetCash(in_copper: uint32, in_silver: uint32, in_gold: uint32, in_platinum: uint32): void;
    CastRezz(spell_id: uint16, *caster: Mob): void;
    CompleteResurrection(timer_expired: boolean): void;
    SetRezTimer(initial_timer: boolean): void;
    QueryLoot(*to: Client): void;
    HasItem(item_id: uint32): boolean;
    CountItem(item_id: uint32): uint16;
    GetItemIDBySlot(loot_slot: uint16): uint32;
    GetFirstLootSlotByItemID(item_id: uint32): uint16;
    LootCorpseItem(*c: Client, *app: EQApplicationPacket): void;
    EndLoot(*c: Client, *app: EQApplicationPacket): void;
    MakeLootRequestPackets(*c: Client, *app: EQApplicationPacket): void;
    AllowPlayerLoot(*them: Mob, slot: uint8): void;
    AddLooter(*who: Mob): void;
    CanPlayerLoot(character_id: number): boolean;
    FillSpawnStruct(*ns: NewSpawn_Struct, *ForWho: Mob): void;
    Summon(*c: Client, spell: boolean, CheckDistance: boolean): boolean;
    GetEquippedItemFromTextureSlot(material_slot: uint8): uint32;
    GetEquipmentColor(material_slot: uint8): uint32
  }

  export class Group extends GroupIDConsumer {
    constructor(arg0: Mob);;
  constructor(arg0: uint32);
    AddMember(NewMemberName: string): void;
    SendUpdate(type: uint32, member: Mob): void;
    SendWorldGroup(zone_id: uint32, zoningmember: Mob): void;
    DelMemberOOZ(*Name: char): boolean;
    DelMember(oldmember: Mob, ignoresender: boolean): boolean;
    DisbandGroup(joinraid: boolean): void;
    GetMemberList(member_list: std::list<Mob>, clear_list: boolean): void;
    GetClientList(client_list: std::list<Client>, clear_list: boolean): void;
    GetBotList(bot_list: std::list<Bot>, clear_list: boolean): void;
    IsGroupMember(c: Mob): boolean;
    IsGroupMember(name: string): boolean;
    SendGroupJoinOOZ(NewMember: Mob): void;
    CastGroupSpell(caster: Mob, spellid: uint16): void;
    SplitExp(exp: uint64, other: Mob): void;
    GroupMessage(sender: Mob, language: uint8, lang_skill: uint8, message: string): void;
    GroupMessageString(sender: Mob, type: uint32, string_id: uint32, message: string, message2: string, message3: string, message4: string, message5: string, message6: string, message7: string, message8: string, message9: string, distance: uint32): void;
    GetTotalGroupDamage(other: Mob): uint32;
    SplitMoney(copper: uint32, silver: uint32, gold: uint32, platinum: uint32, *splitter: Client): void;
    SendHPManaEndPacketsTo(newmember: Mob): void;
    SendHPPacketsFrom(member: Mob): void;
    SendManaPacketFrom(member: Mob): void;
    SendEndurancePacketFrom(member: Mob): void;
    UpdatePlayer(update: Mob): boolean;
    MemberZoned(removemob: Mob): void;
    IsLeader(name: string): boolean;
    QueuePacket(*app: EQApplicationPacket, ack_req: boolean): void;
    TeleportGroup(sender: Mob, zoneID: uint32, instance_id: uint16, x: float, y: float, z: float, heading: float): void;
    BalanceHP(penalty: int32, range: float, caster: Mob, limit: int32): void;
    BalanceMana(penalty: int32, range: float, caster: Mob, limit: int32): void;
    HealGroup(heal_amt: uint32, caster: Mob, range: float): void;
    MarkNPC(Target: Mob, Number: number): void;
    GetNumberNeedingHealedInGroup(hpr: int8, includePets: boolean): int8;
    DelegateMainTank(*NewMainAssistName: char, toggle: uint8): void;
    DelegateMainAssist(*NewMainAssistName: char, toggle: uint8): void;
    DelegatePuller(*NewMainAssistName: char, toggle: uint8): void;
    UnDelegateMainTank(*OldMainAssistName: char, toggle: uint8): void;
    UnDelegateMainAssist(*OldMainAssistName: char, toggle: uint8): void;
    UnDelegatePuller(*OldMainAssistName: char, toggle: uint8): void;
    IsNPCMarker(*c: Client): boolean;
    SetGroupAssistTarget(*m: Mob): void;
    SetGroupTankTarget(*m: Mob): void;
    SetGroupPullerTarget(*m: Mob): void;
    HasRole(*m: Mob, Role: uint8): boolean;
    NotifyAssistTarget(*c: Client): void;
    NotifyTankTarget(*c: Client): void;
    NotifyPullerTarget(*c: Client): void;
    DelegateMarkNPC(*NewNPCMarkerName: char): void;
    UnDelegateMarkNPC(*OldNPCMarkerName: char): void;
    NotifyMainTank(*c: Client, toggle: uint8): void;
    NotifyMainAssist(*c: Client, toggle: uint8): void;
    NotifyPuller(*c: Client, toggle: uint8): void;
    NotifyMarkNPC(*c: Client): void;
    SetMainTank(*NewMainTankName: char): void;
    SetMainAssist(*NewMainAssistName: char): void;
    SetPuller(*NewPullerName: char): void;
    AmIMainTank(*mob_name: char): boolean;
    AmIMainAssist(*mob_name: char): boolean;
    AmIPuller(*mob_name: char): boolean;
    SetNPCMarker(*NewNPCMarkerName: char): void;
    UnMarkNPC(ID: uint16): void;
    SendMarkedNPCsToMember(*c: Client, Clear: boolean): void;
    QueueHPPacketsForNPCHealthAA(sender: Mob, app: EQApplicationPacket): void;
    QueueClients(*sender: Mob, *app: EQApplicationPacket, ack_required: boolean, ignore_sender: boolean, distance: float): void;
    ChangeLeader(newleader: Mob): void;
    UpdateXTargetMarkedNPC(Number: uint32, *m: Mob): void;
    JoinRaidXTarget(*raid: Raid, first: boolean): void;
    SetGroupMentor(percent: number, *name: number): void;
    DoesAnyMemberHaveExpeditionLockout(expedition_name: std::string, event_name: std::string, max_check_count: number): boolean
  }

  export class GroupIDConsumer {
    constructor(arg0: uint32);

  }

  export class Mob extends Entity {
    memset(name: , 0: , 64: ): {;
    DisplayInfo(*mob: Mob): void;
    RogueBackstab(other: Mob, min_damage: boolean, ReuseTime: number): void;
    RogueAssassinate(other: Mob): void;
    MobAngle(*other: Mob, ourx: float, oury: float): float;
    IsFacingMob(*other: Mob): boolean;
    HeadingAngleToMob(HeadingAngleToMob(other->GetX(): Mob other) { return, other->GetY(): ): float;
    HeadingAngleToMob(other_x: float, other_y: float): float;
    Attack(other: Mob, Hand: number, FromRiposte: boolean, IsStrikethrough: boolean, IsFromSpell: boolean, *opts: ExtraAttackOptions): boolean;
    DoAttack(*other: Mob, &hit: DamageHitInfo, *opts: ExtraAttackOptions, FromRiposte: boolean): void;
    MonkSpecialAttack(other: Mob, skill_used: uint8): number;
    TryBackstab(*other: Mob, ReuseTime: number): void;
    AvoidDamage(*attacker: Mob, &hit: DamageHitInfo): boolean;
    compute_tohit(skillinuse: EQ::skills::SkillType): number;
    GetTotalToHit(skill: EQ::skills::SkillType, chance_mod: number): number;
    CheckHitChance(attacker: Mob, &hit: DamageHitInfo): boolean;
    TryCriticalHit(*defender: Mob, &hit: DamageHitInfo, *opts: ExtraAttackOptions): void;
    TryPetCriticalHit(*defender: Mob, &hit: DamageHitInfo): void;
    TryFinishingBlow(*defender: Mob, &damage: int64): boolean;
    TryHeadShot(defender: Mob, skillInUse: EQ::skills::SkillType): number;
    TryAssassinate(defender: Mob, skillInUse: EQ::skills::SkillType): number;
    DoRiposte(defender: Mob): void;
    ApplyMeleeDamageMods(skill: uint16, &damage: int64, defender: Mob , *opts: ExtraAttackOptions): void;
    ACSum(skip_caps: boolean): number;
    offense(skill: EQ::skills::SkillType): number;
    CalcAC(mitigation_ac: ) {): void;
    MeleeMitigation(*attacker: Mob, &hit: DamageHitInfo, *opts: ExtraAttackOptions): void;
    RollD20(offense: number, mitigation: number): number;
    CombatRange(other: Mob, fixed_size_mod: float, aeRampage: boolean, *opts: ExtraAttackOptions): boolean;
    RogueEvade(*other: Mob): void;
    CommonOutgoingHitSuccess(*defender: Mob, &hit: DamageHitInfo, *opts: ExtraAttackOptions): void;
    DoMainHandAttackRounds(*target: Mob, *opts: ExtraAttackOptions, rampage: boolean): void;
    DoOffHandAttackRounds(*target: Mob, *opts: ExtraAttackOptions, rampage: boolean): void;
    IsInvisible(other: Mob): boolean;
    SetInvisible(state: uint8, set_on_bonus_calc: boolean): void;
    ZeroInvisibleVars(invisible_type: uint8): void;
    AttackAnimation(Hand: number, weapon: EQ::ItemInstance, skillinuse: EQ::skills::SkillType): EQ::skills::SkillType;
    GetTextureProfileMaterial(material_slot: uint8): uint32;
    GetTextureProfileColor(material_slot: uint8): uint32;
    GetTextureProfileHeroForgeModel(material_slot: uint8): uint32;
    SendArmorAppearance(*one_client: Client): void;
    SendTextureWC(slot: uint8, texture: uint32, hero_forge_model: uint32, elite_material: uint32, unknown06: uint32, unknown18: uint32): void;
    SendWearChange(material_slot: uint8, *one_client: Client): void;
    SetSlotTint(material_slot: uint8, red_tint: uint8, green_tint: uint8, blue_tint: uint8): void;
    WearChange(material_slot: uint8, texture: uint32, color: uint32, hero_forge_model: uint32): void;
    ChangeSize(in_size: float, unrestricted: boolean): void;
    DoAnim(animation_id: int, animation_speed: number, ackreq: boolean, filter: eqFilterType): void;
    ProjectileAnimation(to: Mob, item_id: number, IsArrow: boolean, speed: float, angle: float, tilt: float, arc: float, *IDFile: char, skillInUse: EQ::skills::SkillType): void;
    SendAppearanceEffect(parm1: uint32, parm2: uint32, parm3: uint32, parm4: uint32, parm5: uint32, *specific_target: Client, value1slot: uint32, value1ground: uint32, value2slot: uint32, value2ground: uint32, value3slot: uint32, value3ground: uint32, value4slot: uint32, value4ground: uint32, value5slot: uint32, value5ground: uint32): void;
    SendTargetable(on: boolean, *specific_target: Client): void;
    SetMobTextureProfile(material_slot: uint8, texture: uint32, color: uint32, hero_forge_model: uint32): void;
    SendSpellEffect(effect_id: uint32, duration: uint32, finish_delay: uint32, zone_wide: boolean, unk020: uint32, perm_effect: boolean, *c: Client, caster_id: uint32, target_id: uint32): void;
    IsBeneficialAllowed(*target: Mob): boolean;
    GetCasterLevel(spell_id: uint16): number;
    ApplySpellsBonuses(spell_id: uint16, casterlevel: uint8, newbon: StatBonuses, casterID: uint16, WornType: uint8, ticsremaining: int32, buffslot: number, instrument_mod: number, IsAISpellEffect: boolean, effect_id: uint16, se_base: int32, se_limit: int32, se_max: int32): void;
    NegateSpellEffectBonuses(spell_id: uint16): void;
    NegateSpellEffect(spell_id: uint16, effect_id: number): boolean;
    GetActSpellRange(spell_id: uint16, range: float): float;
    GetActSpellDamage(spell_id: uint16, value: int64, target: Mob): int64;
    GetActDoTDamage(spell_id: uint16, value: int64, target: Mob, from_buff_tic: boolean): int64;
    GetActSpellHealing(spell_id: uint16, value: int64, target: Mob, from_buff_tic: boolean): int64;
    GetActSpellCost(spell_id: uint16, cost: int32): int32;
    GetActSpellDuration(spell_id: uint16, duration: int32): int32;
    GetActSpellCasttime(spell_id: uint16, casttime: int32): int32;
    GetActReflectedSpellDamage(spell_id: uint16, value: int64, effectiveness: number): int64;
    ResistSpell(resist_type: uint8, spell_id: uint16, *caster: Mob, use_resist_override: boolean, resist_override: number, CharismaCheck: boolean, CharmTick: boolean, IsRoot: boolean, level_override: number): float;
    GetResist(resist_type: uint8): number;
    ResistPhysical(level_diff: number, caster_level: uint8): number;
    ResistElementalWeaponDmg(*item: EQ::ItemInstance): number;
    CheckBaneDamage(*item: EQ::ItemInstance): number;
    GetSpecializeSkillValue(spell_id: uint16): uint16;
    SendSpellBarEnable(spellid: uint16): void;
    CastSpell(spell_id: uint16, target_id: uint16, slot: EQ::spells::CastingSlot, casttime: int32, mana_cost: int32, oSpellWillFinish: uint32, item_slot: uint32, timer: uint32, timer_duration: uint32, *resist_adjust: int16, aa_id: uint32): boolean;
    DoCastSpell(spell_id: uint16, target_id: uint16, slot: EQ::spells::CastingSlot, casttime: int32, mana_cost: int32, oSpellWillFinish: uint32, item_slot: uint32, timer: uint32, timer_duration: uint32, resist_adjust: int16, aa_id: uint32): boolean;
    CastedSpellFinished(spell_id: uint16, target_id: uint32, slot: EQ::spells::CastingSlot, mana_used: number, inventory_slot: uint32, resist_adjust: int16): void;
    SpellFinished(spell_id: uint16, *target: Mob, slot: EQ::spells::CastingSlot, mana_used: number, inventory_slot: uint32, resist_adjust: int16, isproc: boolean, level_override: number, timer: uint32, timer_duration: uint32, from_casted_spell: boolean, aa_id: uint32): boolean;
    SendBeginCast(spell_id: uint16, casttime: uint32): void;
    DetermineSpellTargets(spell_id: uint16, *&spell_target: Mob, *&ae_center: Mob, &CastAction: CastAction_type, slot: EQ::spells::CastingSlot, isproc: boolean): boolean;
    DoCastingChecksOnCaster(spell_id: int32, slot: EQ::spells::CastingSlot): boolean;
    DoCastingChecksZoneRestrictions(check_on_casting: boolean, spell_id: int32): boolean;
    DoCastingChecksOnTarget(check_on_casting: boolean, spell_id: int32, spell_target: Mob): boolean;
    CheckFizzle(spell_id: uint16): boolean;
    CheckSpellLevelRestriction(*caster: Mob, spell_id: uint16): boolean;
    IsImmuneToSpell(spell_id: uint16, *caster: Mob): boolean;
    GetAOERange(spell_id: uint16): float;
    InterruptSpell(spellid: uint16): void;
    InterruptSpell(uint16: , uint16: , spellid: uint16): void;
    StopCastSpell(spell_id: int32, send_spellbar_enable: boolean): void;
    TryDispel(caster_level: uint8, buff_level: uint8, level_modifier: number): boolean;
    TrySpellProjectile(spell_target: Mob, spell_id: uint16, speed: float): boolean;
    ResourceTap(damage: int64, spell_id: uint16): void;
    TryTriggerThreshHold(damage: int64, effect_id: number, attacker: Mob): void;
    CalcDestFromHeading(heading: float, distance: float, MaxZDiff: float, StartX: float, StartY: float, &dX: float, &dY: float, &dZ: float): void;
    BeamDirectional(spell_id: uint16, resist_adjust: int16): void;
    ConeDirectional(spell_id: uint16, resist_adjust: int16): void;
    ApplyHealthTransferDamage(*caster: Mob, *target: Mob, spell_id: uint16): void;
    ApplySpellEffectIllusion(spell_id: int32, caster: Mob, buffslot: number, base: number, limit: number, max: number): void;
    ApplyIllusionToCorpse(spell_id: int32, new_corpse: Corpse): void;
    SendIllusionWearChange(c: Client): void;
    GetItemSlotToConsumeCharge(spell_id: int32, inventory_slot: uint32): int16;
    CheckItemRaceClassDietyRestrictionsOnCast(inventory_slot: uint32): boolean;
    IsFromTriggeredSpell(slot: EQ::spells::CastingSlot, item_slot: uint32): boolean;
    ApplyBardPulse(spell_id: int32, *spell_target: Mob, slot: EQ::spells::CastingSlot): boolean;
    IsActiveBardSong(spell_id: int32): boolean;
    HasActiveSong(!: ) { return(bardsong): boolean;
    DoBardCastingFromItemClick(is_casting_bard_song: boolean, cast_time: uint32, spell_id: int32, target_id: uint16, slot: EQ::spells::CastingSlot, item_slot: uint32, recast_type: uint32, recast_delay: uint32): void;
    UseBardSpellLogic(spell_id: uint16, slot: number): boolean;
    DoBuffTic(&buff: Buffs_Struct, slot: number, caster: Mob): void;
    BuffFadeBySpellID(spell_id: uint16): void;
    BuffFadeBySpellIDAndCaster(spell_id: uint16, caster_id: uint16): void;
    BuffFadeByEffect(effect_id: number, slot_to_skip: number): void;
    BuffFadeBySlot(slot: number, iRecalcBonuses: boolean): void;
    BuffFadeDetrimentalByCaster(*caster: Mob): void;
    BuffDetachCaster(*caster: Mob): void;
    IsAffectedByBuffByGlobalGroup(group: GlobalGroup): boolean;
    BuffModifyDurationBySpellID(spell_id: uint16, newDuration: int32): void;
    AddBuff(*caster: Mob, spell_id: uint16, duration: number, level_override: int32, disable_buff_overwrite: boolean): number;
    CanBuffStack(spellid: uint16, caster_level: uint8, iFailIfOverwrite: boolean): number;
    CalcBuffDuration(*caster: Mob, *target: Mob, spell_id: uint16, caster_level_override: int32): number;
    GetFirstBuffSlot(disc: boolean, song: boolean): uint32;
    GetLastBuffSlot(disc: boolean, song: boolean): uint32;
    SendBuffsToClient(*c: Client): void;
    DamageShield(other: Mob, spell_ds: boolean): void;
    RuneAbsorb(damage: int64, type: uint16): int32;
    FindBuff(spell_id: uint16, caster_id: uint16): boolean;
    FindBuffBySlot(slot: number): uint16;
    BuffCount(is_beneficial: boolean, is_detrimental: boolean): uint32;
    FindType(type: uint16, bOffensive: boolean, threshold: uint16): boolean;
    GetBuffSlotFromType(type: uint16): int16;
    GetSpellIDFromSlot(slot: uint8): uint16;
    CheckNumHitsRemaining(type: NumHit, buff_slot: int32, spell_id: uint16): void;
    IsNimbusEffectActive(nimbus_effect: uint32): boolean;
    SetNimbusEffect(nimbus_effect: uint32): void;
    AddNimbusEffect(effect_id: number): void;
    RemoveNimbusEffect(effect_id: number): void;
    HasBuffWithSpellGroup(spell_group: number): boolean;
    SetAppearanceEffects(slot: int32, value: int32): void;
    ListAppearanceEffects(c: Client): void;
    SendSavedAppearanceEffects(*receiver: Client): void;
    SetBuffDuration(spell_id: number, duration: number, level_override: number): void;
    ApplySpellBuff(spell_id: number, duration: number, level_override: number): void;
    GetBuffStatValueBySpell(spell_id: int32, stat_identifier: string): number;
    GetBuffStatValueBySlot(slot: uint8, stat_identifier: string): number;
    TempName(*newname: char): void;
    SetTargetable(on: boolean): void;
    HasBowAndArrowEquipped(HasArrowEquipped(: ) { return HasBowEquipped() ): boolean;
    ConvertItemTypeToSkillID(item_type: uint8): uint8;
    GetEquippedItemFromTextureSlot(return(0: uint8 material_slot) {): uint32;
    GetEquipmentMaterial(material_slot: uint8): uint32;
    GetEquipmentType(material_slot: uint8): uint8;
    GetHerosForgeModel(material_slot: uint8): uint32;
    GetEquipmentColor(material_slot: uint8): uint32;
    IsEliteMaterialItem(material_slot: uint8): uint32;
    CanClassEquipItem(item_id: uint32): boolean;
    CanRaceEquipItem(item_id: uint32): boolean;
    AffectedBySpellExcludingSlot(slot: number, effect: number): boolean;
    Death(killer_mob: Mob, damage: int64, spell_id: uint16, attack_skill: EQ::skills::SkillType, killed_by: KilledByTypes): boolean;
    Damage(from: Mob, damage: int64, spell_id: uint16, attack_skill: EQ::skills::SkillType, avoidable: boolean, buffslot: int8, iBuffTic: boolean, special: eSpecialAttacks): void;
    SetHP(hp: int64): void;
    HealDamage(ammount: uint64, caster: Mob, spell_id: uint16): void;
    GetDeityBit(EQ::deity::GetDeityBitmask((EQ::deity::DeityType)deity: ) { return): EQ::deity::DeityTypeBit;
    GetTargetDescription(target: Mob, description_type: uint8, entity_id_override: uint16): std::string;
    SetTarget(mob: Mob): void;
    SetMana(amount: int64): int64;
    CopyHateList(to: Mob): void;
    SetMoving(moving: bool move) {): void;
    Gate(bindnum: uint8): void;
    GetWalkspeed(return(_GetWalkSpeed(): ) {): number;
    GetRunspeed(return(_GetRunSpeed(): ) {): number;
    GetMovespeed(GetWalkspeed(: ) { return IsRunning() ? GetRunspeed() :): float;
    GMMove(x: float, y: float, z: float, heading: float, save_guard_spot: boolean): void;
    GMMove(&position: glm::vec4, save_guard_spot: boolean): void;
    SetDelta(delta: glm::vec4): void;
    MakeSpawnUpdate(spu: PlayerPositionUpdateServer_Struct): void;
    SentPositionPacket(dx: float, dy: float, dz: float, dh: float, anim: number, send_to_self: boolean): void;
    StopMoving(new_heading: float): void;
    SetFlyMode(in_flymode: GravityBehavior): void;
    Teleport(&pos: glm::vec3): void;
    Teleport(&pos: glm::vec4): void;
    TryMoveAlong(distance: float, angle: float, send: boolean): void;
    TryMoveAlong(&start: glm::vec4, distance: float, angle: float): glm::vec4;
    AddToHateList(other: Mob, hate: int64, damage: int64, iYellForHelp: boolean, bFrenzy: boolean, iBuffTic: boolean, spell_id: uint16, pet_comand: boolean): void;
    RemoveFromHateList(mob: Mob): boolean;
    SetHateAmountOnEnt(other: Mob, hate: int64, damage: int64, hate: , damage: ): void;
    HalveAggro(in_hate: Mob other) { int64, 1): (in_hate > 1 ? in_hate / 2 :): void;
    DoubleAggro(in_hate: Mob other) { int64, 1): (in_hate ? in_hate  2 :): void;
    GetHateAmount(tmob: Mob, is_dam: boolean, is_dam: ): int64;
    GetDamageAmount(hate_list.GetEntHateAmount(tmob: Mob tmob) { return, true: ): int64;
    GetHateRatio(*first: Mob, hate_list.GetHateRatio(first: Mob with) { return, with: ): number;
    GetHateTop(hate_list.GetMobWithMostHateOnList(this: ) { return): Mob;
    GetHateTopBot(hate_list.GetMobWithMostHateOnList(this: ) { return, nullptr: , false: , EntityFilterType::Bots)->CastToBot(: ): Bot;
    GetHateTopClient(hate_list.GetMobWithMostHateOnList(this: ) { return, nullptr: , false: , EntityFilterType::Clients)->CastToClient(: ): Client;
    GetHateTopNPC(hate_list.GetMobWithMostHateOnList(this: ) { return, nullptr: , false: , EntityFilterType::NPCs)->CastToNPC(: ): NPC;
    GetSecondaryHate(hate_list.GetMobWithMostHateOnList(this: Mob skip) { return, skip: ): Mob;
    GetHateDamageTop(hate_list.GetDamageTopOnHateList(other: Mob other) { return): Mob;
    GetHateRandom(hate_list.GetRandomMobOnHateList(: ) { return): Mob;
    GetHateRandomBot(hate_list.GetRandomMobOnHateList(EntityFilterType::Bots)->CastToBot(: ) { return): Bot;
    GetHateRandomClient(hate_list.GetRandomMobOnHateList(EntityFilterType::Clients)->CastToClient(: ) { return): Client;
    GetHateRandomNPC(hate_list.GetRandomMobOnHateList(EntityFilterType::NPCs)->CastToNPC(: ) { return): NPC;
    GetHateMost(hate_list.GetMobWithMostHateOnList(: ) { return): Mob;
    GetHateClosest(skip_mezzed: boolean, skip_mezzed: ): Mob;
    GetHateClosestBot(skip_mezzed: boolean, skip_mezzed: , EntityFilterType::Bots)->CastToBot(: ): Bot;
    GetHateClosestClient(skip_mezzed: boolean, skip_mezzed: , EntityFilterType::Clients)->CastToClient(: ): Client;
    GetHateClosestNPC(skip_mezzed: boolean, skip_mezzed: , EntityFilterType::NPCs)->CastToNPC(: ): NPC;
    IsEngaged(return(!hate_list.IsHateListEmpty(): ) {): boolean;
    FaceTarget(mob_to_face: Mob): void;
    WipeHateList(npc_only: boolean): void;
    AddFeignMemory(attacker: Mob): void;
    RemoveFromFeignMemory(attacker: Mob): void;
    IsOnFeignMemory(*attacker: Mob): boolean;
    PrintHateListToClient(hate_list.PrintHateListToClient(who: Client who) {): void;
    GetHateList(hate_list.GetHateList(: ) { return): std::list<struct_HateList>;
    CheckLosFN(other: Mob): boolean;
    CheckLosFN(posX: float, posY: float, posZ: float, mobSize: float): boolean;
    CheckWaterLoS(m: Mob): boolean;
    CreateDespawnPacket(app: EQApplicationPacket, Decay: boolean): void;
    CreateHorseSpawnPacket(app: EQApplicationPacket, m: Mob): void;
    CreateSpawnPacket(app: EQApplicationPacket, ForWho: Mob): void;
    FillSpawnStruct(ns: NewSpawn_Struct, ForWho: Mob): void;
    CreateHPPacket(app: EQApplicationPacket): void;
    SendHPUpdate(force_update_all: boolean): void;
    GetSkillByItemType(ItemType: number): EQ::skills::SkillType;
    GetItemTypeBySkill(skill: EQ::skills::SkillType): uint8;
    MakePet(spell_id: uint16, pettype: string, *petname: char): void;
    MakePoweredPet(spell_id: uint16, pettype: string, petpower: int16, *petname: char, in_size: float): void;
    SetZone(zone_id: uint32, instance_id: uint32): void;
    SendStatsWindow(c: Client, use_window: boolean): void;
    ShowStats(client: Client): void;
    ShowBuffs(c: Client): void;
    PlotPositionAroundTarget(target: Mob, &x_dest: float, &y_dest: float, &z_dest: float, lookForAftArc: boolean): boolean;
    MakeAura(spell_id: uint16): void;
    AddAura(*aura: Aura, &record: AuraRecord): void;
    AddTrap(*aura: Aura, &record: AuraRecord): void;
    CanSpawnAura(trap: boolean): boolean;
    RemoveAura(spawn_id: number, skip_strip: boolean, expired: boolean): void;
    TriggerDefensiveProcs(*on: Mob, hand: uint16, FromSkillProc: boolean, damage: int64): void;
    AddRangedProc(spell_id: uint16, iChance: uint16, base_spell_id: uint16, proc_reuse_time: uint32): boolean;
    RemoveRangedProc(spell_id: uint16, bAll: boolean): boolean;
    AddDefensiveProc(spell_id: uint16, iChance: uint16, base_spell_id: uint16, proc_reuse_time: uint32): boolean;
    RemoveDefensiveProc(spell_id: uint16, bAll: boolean): boolean;
    AddProcToWeapon(spell_id: uint16, bPerma: boolean, iChance: uint16, base_spell_id: uint16, level_override: number, proc_reuse_time: uint32): boolean;
    RemoveProcFromWeapon(spell_id: uint16, bAll: boolean): boolean;
    IsCombatProc(spell_id: uint16): boolean;
    IsAttackAllowed(*target: Mob, isSpellAttack: boolean): boolean;
    IsTargeted(0: ) { return (targeted >): boolean;
    Say(*format: char, ...: ): void;
    SayString(string_id: uint32, *message3: char, *message4: char, *message5: char, *message6: char, *message7: char, *message8: char, *message9: char): void;
    SayString(type: uint32, string_id: uint32, *message3: char, *message4: char, *message5: char, *message6: char, *message7: char, *message8: char, *message9: char): void;
    SayString(*to: Client, string_id: uint32, *message3: char, *message4: char, *message5: char, *message6: char, *message7: char, *message8: char, *message9: char): void;
    SayString(*to: Client, type: uint32, string_id: uint32, *message3: char, *message4: char, *message5: char, *message6: char, *message7: char, *message8: char, *message9: char): void;
    Shout(*format: char, ...: ): void;
    Emote(*format: char, ...: ): void;
    QuestJournalledSay(*QuestInitiator: Client, *str: char, &opts: Journal::Options): void;
    GetItemStat(item_id: uint32, identifier: std::string): number;
    CalcFocusEffect(type: focusType, focus_id: uint16, spell_id: uint16, best_focus: boolean, casterid: uint16, *caster: Mob): int64;
    IsFocusEffect(spellid: uint16, effect_index: number, AA: boolean, aa_effect: uint32): uint8;
    SendIllusionPacket(a: AppearanceStruct): void;
    CloneAppearance(other: Mob, clone_name: boolean): void;
    SetFaceAppearance(face: FaceChange_Struct, skip_sender: boolean): void;
    RandomizeFeatures(send_illusion: boolean, set_variables: boolean): boolean;
    Stun(duration: number): void;
    TemporaryPets(spell_id: uint16, *target: Mob, *name_override: char, duration_override: uint32, followme: boolean, sticktarg: boolean, *controlled_pet_id: uint16): void;
    TypesTemporaryPets(typesid: uint32, *target: Mob, *name_override: char, duration_override: uint32, followme: boolean, sticktarg: boolean): void;
    WakeTheDead(spell_id: uint16, *corpse_to_use: Corpse, *target: Mob, duration: uint32): void;
    PassCharismaCheck(caster: Mob, spell_id: uint16): boolean;
    TryTriggerOnCastFocusEffect(type: focusType, spell_id: uint16): void;
    TryTriggerOnCastProc(focusspellid: uint16, spell_id: uint16, proc_spellid: uint16): boolean;
    TrySpellTrigger(*target: Mob, spell_id: uint32, effect: number): boolean;
    TryTwincast(*caster: Mob, *target: Mob, spell_id: uint32): void;
    TrySympatheticProc(*target: Mob, spell_id: uint32): void;
    GetSympatheticFocusEffect(type: focusType, spell_id: uint16): uint16;
    TryFadeEffect(slot: number): boolean;
    DispelMagic(casterm: Mob, spell_id: uint16, effect_value: number): void;
    GetSpellEffectResistChance(spell_id: uint16): uint16;
    GetVulnerability(*caster: Mob, spell_id: uint32, ticsremaining: uint32, from_buff_tic: boolean): int32;
    GetFcDamageAmtIncoming(*caster: Mob, spell_id: int32, from_buff_tic: boolean): int64;
    GetFocusIncoming(type: focusType, effect: number, *caster: Mob, spell_id: uint32): int64;
    GetSkillDmgTaken(skill_used: EQ::skills::SkillType, *opts: ExtraAttackOptions): int32;
    GetPositionalDmgTaken(*attacker: Mob): int32;
    GetPositionalDmgTakenAmt(*attacker: Mob): int32;
    DoKnockback(*caster: Mob, push_back: uint32, push_up: uint32): void;
    TrySpellOnKill(level: uint8, spell_id: uint16): void;
    CastOnCurer(spell_id: uint32): void;
    CastOnCure(spell_id: uint32): void;
    CastOnNumHitFade(spell_id: uint32): void;
    SlowMitigation(caster: Mob): void;
    GetCritDmgMod(skill: uint16, owner: Mob): int16;
    GetMeleeDamageMod_SE(skill: uint16): int16;
    GetMeleeMinDamageMod_SE(skill: uint16): int16;
    GetMeleeDmgPositionMod(defender: Mob): int16;
    GetSkillReuseTime(skill: uint16): int16;
    GetCriticalChanceBonus(skill: uint16): number;
    GetSkillDmgAmt(skill_id: number): number;
    GetPositionalDmgAmt(defender: Mob): int16;
    DoHPToManaCovert(mana_cost: int32): boolean;
    GetDecayEffectValue(spell_id: uint16, spelleffect: uint16): int8;
    GetExtraSpellAmt(spell_id: uint16, extra_spell_amt: int64, base_spell_dmg: int64): int64;
    MeleeLifeTap(damage: int64): void;
    PassCastRestriction(value: number): boolean;
    SendCastRestrictionMessage(requirement_id: number, is_target_requirement: boolean, is_discipline: boolean): void;
    TryRootFadeByDamage(buffslot: number, attacker: Mob): boolean;
    CalcSpellPowerDistanceMod(spell_id: uint16, range: float, caster: Mob): void;
    GetSpellStat(spell_id: uint32, *identifier: char, slot: uint8): int32;
    HarmonySpellLevelCheck(spell_id: int32, target: Mob): boolean;
    PassCharmTargetRestriction(*target: Mob): boolean;
    CanFocusUseRandomEffectivenessByType(type: focusType): boolean;
    GetFocusRandomEffectivenessValue(focus_base: number, focus_base2: number, best_focus: boolean): number;
    GetMemoryBlurChance(base_chance: number): number;
    IsTargetedFocusEffect(focus_type: number): boolean;
    HasPersistDeathIllusion(spell_id: int32): boolean;
    CastSpellOnLand(caster: Mob, spell_id: int32): void;
    IsFocusProcLimitTimerActive(focus_spell_id: int32): boolean;
    SetFocusProcLimitTimer(focus_spell_id: int32, focus_reuse_time: uint32): void;
    IsProcLimitTimerActive(base_spell_id: int32, proc_reuse_time: uint32, proc_type: number): boolean;
    SetProcLimitTimer(base_spell_id: int32, proc_reuse_time: uint32, proc_type: number): void;
    SpreadVirusEffect(spell_id: int32, caster_id: uint32, buff_tics_remaining: int32): void;
    ModSkillDmgTaken(skill_num: EQ::skills::SkillType, value: number): void;
    GetModSkillDmgTaken(skill_num: EQ::skills::SkillType): int16;
    ModVulnerability(resist: uint8, value: int16): void;
    GetModVulnerability(resist: uint8): int16;
    SetFlurryChance(SetSpecialAbilityParam(SPECATK_FLURRY: uint8 value) {, 0: , value: ): void;
    GetFlurryChance(GetSpecialAbilityParam(SPECATK_FLURRY: ) { return, 0: ): uint8;
    SendAppearancePacket(type: uint32, value: uint32, whole_zone: boolean, ignore_self: boolean, target: Client): void;
    SetAppearance(app: EmuAppearance, ignore_self: boolean): void;
    SendWearChangeAndLighting(last_texture: int8): void;
    SetPet(newpet: Mob): void;
    SetPetID(NewPetID: uint16): void;
    SetOwnerID(new_owner_id: uint16): void;
    SetBodyType(new_body: bodyType, overwrite_orig: boolean): void;
    GetWeaponDamageBonus(weapon: EQ::ItemData, offhand: boolean): uint8;
    ApplyDamageTable(&hit: DamageHitInfo): void;
    GetHandToHandDamage(void: ): number;
    CanThisClassDoubleAttack(void: ): boolean;
    CanThisClassDualWield(void: ): boolean;
    CanThisClassRiposte(void: ): boolean;
    CanThisClassDodge(void: ): boolean;
    CanThisClassParry(void: ): boolean;
    CanThisClassBlock(void: ): boolean;
    GetHandToHandDelay(void: ): number;
    ReduceDamage(damage: int64): int64;
    AffectMagicalDamage(damage: int64, spell_id: uint16, iBuffTic: bool, attacker: Mob): int64;
    ReduceAllDamage(damage: int64): int64;
    DoSpecialAttackDamage(*who: Mob, skill: EQ::skills::SkillType, base_damage: number, min_damage: number, hate_override: int32, ReuseTime: number): void;
    DoThrowingAttackDmg(other: Mob, RangeWeapon: EQ::ItemInstance, AmmoItem: EQ::ItemData, weapon_damage: int32, chance_mod: int16, focus: int16, ReuseTime: number, range_id: uint32, AmmoSlot: number, speed: float, DisableProcs: boolean): void;
    DoMeleeSkillAttackDmg(other: Mob, weapon_damage: int32, skillinuse: EQ::skills::SkillType, chance_mod: int16, focus: int16, can_riposte: boolean, ReuseTime: number): void;
    DoArcheryAttackDmg(other: Mob, RangeWeapon: EQ::ItemInstance, Ammo: EQ::ItemInstance, weapon_damage: int32, chance_mod: int16, focus: int16, ReuseTime: number, range_id: uint32, ammo_id: uint32, *AmmoItem: EQ::ItemData, AmmoSlot: number, speed: float, DisableProcs: boolean): void;
    TryProjectileAttack(other: Mob, *item: EQ::ItemData, skillInUse: EQ::skills::SkillType, weapon_dmg: uint64, RangeWeapon: EQ::ItemInstance, Ammo: EQ::ItemInstance, AmmoSlot: number, speed: float, DisableProcs: boolean): boolean;
    GetRangeDistTargetSizeMod(other: Mob): float;
    CanDoSpecialAttack(*other: Mob): boolean;
    Flurry(*opts: ExtraAttackOptions): boolean;
    Rampage(*opts: ExtraAttackOptions): boolean;
    AddRampage(Mob*: ): boolean;
    RemoveFromRampageList(mob: Mob, remove_feigned: boolean): void;
    AreaRampage(*opts: ExtraAttackOptions): void;
    Taunt(*who: NPC, always_succeed: boolean, chance_bonus: number, from_spell: boolean, bonus_hate: int32): void;
    AI_Start(iMoveDelay: uint32): void;
    DeleteEntityVariable(variable_name: std::string): boolean;
    GetEntityVariable(variable_name: std::string): std::string;
    SetEntityVariable(variable_name: std::string, variable_value: std::string): void;
    EntityVariableExists(variable_name: std::string): boolean;
    AI_Event_Engaged(attacker: Mob, yell_for_help: boolean): void;
    GetSpecialFactionCon(iOther: Mob): FACTION_VALUE;
    GetFearSpeed(_GetFearSpeed(: ) { return): number;
    IsFeared(flee_mode: ) { return (spellbonuses.IsFeared ||): boolean;
    CalculateHeadingToTarget(in_x: float, HeadingAngleToMob(in_x: float in_y) { return, in_y: ): float;
    WalkTo(x: float, y: float, z: float): void;
    RunTo(x: float, y: float, z: float): void;
    NavigateTo(x: float, y: float, z: float): void;
    RotateTo(new_heading: float): void;
    RotateToWalking(new_heading: float): void;
    RotateToRunning(new_heading: float): void;
    CalculateDistance(x: float, y: float, z: float): float;
    CalculateDistance(mob: Mob): float;
    GetGroundZ(new_x: float, new_y: float, z_offset: float): float;
    SendTo(new_x: float, new_y: float, new_z: float): void;
    SendToFixZ(new_x: float, new_y: float, new_z: float): void;
    GetDefaultRaceSize(race_id: number, gender_id: number): float;
    FixZ(z_find_offset: int32, fix_client_z: boolean): void;
    GetFixedZ(&destination: glm::vec3, z_find_offset: int32): float;
    NPCSpecialAttacks(parse: string, permtag: number, reset: boolean, remove: boolean): void;
    SaveSpellLoc(m_SpellLocation: ) {): void;
    SetGrouped(v: boolean): void;
    SetRaidGrouped(v: boolean): void;
    CheckWillAggro(*mob: Mob): boolean;
    InstillDoubt(*who: Mob): void;
    CheckAggroAmount(spell_id: uint16, *target: Mob, isproc: boolean): int32;
    CheckHealAggroAmount(spell_id: uint16, *target: Mob, heal_possible: uint32): int32;
    GetInstrumentMod(spell_id: uint16): uint32;
    CalcSpellEffectValue(spell_id: uint16, effect_id: number, caster_level: number, instrument_mod: uint32, *caster: Mob, ticsremaining: number, casterid: uint16): int64;
    CalcSpellEffectValue_formula(formula: uint32, base_value: int64, max_value: int64, caster_level: number, spell_id: uint16, ticsremaining: number): int64;
    CheckStackConflict(spellid1: uint16, caster_level1: number, spellid2: uint16, caster_level2: number, caster1: Mob, caster2: Mob, buffslot: number): number;
    SetNextHPEvent(hpevent: number): void;
    SendItemAnimation(*to: Mob, *item: EQ::ItemData, skillInUse: EQ::skills::SkillType, velocity: float): void;
    SetNextIncHPEvent(inchpevent: number): void;
    HasNPCSpecialAtk(parse: string): boolean;
    GetSpecialAbility(ability: number): number;
    GetSpecialAbilityParam(ability: number, param: number): number;
    SetSpecialAbility(ability: number, level: number): void;
    SetSpecialAbilityParam(ability: number, param: number, value: number): void;
    StartSpecialAbilityTimer(ability: number, time: uint32): void;
    StopSpecialAbilityTimer(ability: number): void;
    ProcessSpecialAbilities(&str: std::string): void;
    ShieldAbility(target_id: uint32, shielder_max_distance: number, shield_duration: number, shield_target_mitigation: number, shielder_mitigation: number, use_aa: boolean, can_shield_npc: boolean): boolean;
    DoShieldDamageOnShielder(*shield_target: Mob, hit_damage_done: int64, skillInUse: EQ::skills::SkillType): void;
    GetAIThinkTimer(AI_think_timer.get(: ) { return): Timer;
    GetAIMovementTimer(AI_movement_timer.get(: ) { return): Timer;
    GetGlobal(*varname: char): std::string;
    SetGlobal(*varname: char, *newvalue: char, options: number, *duration: char, *other: Mob): void;
    TarGlobal(*varname: char, *value: char, *duration: char, npcid: number, charid: number, zoneid: number): void;
    DelGlobal(*varname: char): void;
    HasSpellEffect(effect_id: number): boolean;
    TuneGetStats(defender: Mob, *attacker: Mob): void;
    TuneGetACByPctMitigation(defender: Mob, *attacker: Mob, pct_mitigation: float, interval: number, max_loop: number, atk_override: number, Msg: number): void;
    TuneGetATKByPctMitigation(defender: Mob, *attacker: Mob, pct_mitigation: float, interval: number, max_loop: number, ac_override: number, Msg: number): void;
    TuneGetAvoidanceByHitChance(defender: Mob, *attacker: Mob, hit_chance: float, interval: number, max_loop: number, accuracy_override: number, Msg: number): void;
    TuneGetAccuracyByHitChance(defender: Mob, *attacker: Mob, hit_chance: float, interval: number, max_loop: number, avoidance_override: number, Msg: number): void;
    TuneClientGetMeanDamage(other: Mob, ac_override: number, atk_override: number, add_ac: number, add_atk: number): int64;
    TuneClientGetMaxDamage(other: Mob): int64;
    TuneClientGetMinDamage(other: Mob, max_hit: number): int64;
    TuneGetACMitigationPct(defender: Mob, *attacker: Mob): float;
    TuneGetOffense(defender: Mob, *attacker: Mob, atk_override: number): int64;
    TuneGetAccuracy(defender: Mob, *attacker: Mob, accuracy_override: number, add_accuracy: number): int64;
    TuneGetAvoidance(defender: Mob, *attacker: Mob, avoidance_override: number, add_avoidance: number): int64;
    TuneGetHitChance(defender: Mob, *attacker: Mob, avoidance_override: number, accuracy_override: number, add_avoidance: number, add_accuracy: number): float;
    TuneGetAvoidMeleeChance(defender: Mob, *attacker: Mob, type: number): float;
    TuneCalcEvasionBonus(final_avoidance: number, base_avoidance: number): int64;
    TuneNPCAttack(other: Mob, no_avoid: boolean, no_hit_chance: boolean, hit_chance_bonus: number, ac_override: number, atk_override: number, add_ac: number, add_atk: number, get_offense: boolean, get_accuracy: boolean, avoidance_override: number, accuracy_override: number, add_avoidance: number, add_accuracy: number): int64;
    TuneClientAttack(other: Mob, no_avoid: boolean, no_hit_chance: boolean, hit_chance_bonus: number, ac_override: number, atk_override: number, add_ac: number, add_atk: number, get_offense: boolean, get_accuracy: boolean, avoidance_override: number, accuracy_override: number, add_avoidance: number, add_accuracy: number): int64;
    TuneDoAttack(*other: Mob, &hit: DamageHitInfo, *opts: ExtraAttackOptions, no_avoid: boolean, no_hit_chance: boolean, ac_override: number, add_ac: number, avoidance_override: number, accuracy_override: number, add_avoidance: number, add_accuracy: number): void;
    TuneMeleeMitigation(*attacker: Mob, &hit: DamageHitInfo, ac_override: number, add_ac: number): void;
    Tuneoffense(skill: EQ::skills::SkillType, atk_override: number, add_atk: number): int64;
    TuneACSum(skip_caps: boolean, ac_override: number, add_ac: number): int64;
    TuneGetTotalToHit(skill: EQ::skills::SkillType, chance_mod: number, accuracy_override: number, add_accurracy: number): int64;
    Tunecompute_tohit(skillinuse: EQ::skills::SkillType, accuracy_override: number, add_accuracy: number): int64;
    TuneGetTotalDefense(avoidance_override: number, add_avoidance: number): int64;
    Tunecompute_defense(avoidance_override: number, add_avoidance: number): int64;
    TuneCheckHitChance(other: Mob, &hit: DamageHitInfo, avoidance_override: number, add_avoidance: number): boolean;
    TuneAttackAnimation(Hand: number, weapon: EQ::ItemInstance, skillinuse: EQ::skills::SkillType): EQ::skills::SkillType;
    TuneCommonOutgoingHitSuccess(*defender: Mob, &hit: DamageHitInfo, *opts: ExtraAttackOptions): void;
    GetAA(rank_id: uint32, *charges: uint32): uint32;
    GetAAByAAID(aa_id: uint32, *charges: uint32): uint32;
    SetAA(rank_id: uint32, new_value: uint32, charges: uint32): boolean;
    ClearAAs(aa_ranks.clear(: ) {): void;
    CanUseAlternateAdvancementRank(*rank: AA::Rank): boolean;
    CanPurchaseAlternateAdvancementRank(*rank: AA::Rank, check_price: boolean, check_grant: boolean): boolean;
    GetAlternateAdvancementCooldownReduction(*rank_in: AA::Rank): number;
    ExpendAlternateAdvancementCharge(aa_id: uint32): void;
    CalcAABonuses(newbon: StatBonuses): void;
    CalcAAFocus(type: focusType, &rank: AA::Rank, spell_id: uint16): int64;
    ApplyAABonuses(&rank: AA::Rank, newbon: StatBonuses): void;
    CheckAATimer(timer: number): boolean;
    CalcItemBonuses(b: StatBonuses): void;
    AddItemBonuses(inst: EQ::ItemInstance, b: StatBonuses, is_augment: boolean, is_tribute: boolean, recommended_level_override: number, is_ammo_item: boolean): void;
    AdditiveWornBonuses(inst: EQ::ItemInstance, b: StatBonuses, is_augment: boolean): void;
    CalcRecommendedLevelBonus(current_level: uint8, recommended_level: uint8, base_stat: number): number;
    GetWeaponDamage(*against: Mob, *weapon_item: EQ::ItemData): int64;
    GetWeaponDamage(*against: Mob, *weapon_item: EQ::ItemInstance, *hate: int64): int64;
    DoDamageCaps(base_damage: int64): int64;
    SetCanOpenDoors(can_open: boolean): void;
    SetFeigned(in_feigned: boolean): void;
    DeleteBucket(bucket_name: std::string): void;
    GetBucket(bucket_name: std::string): std::string;
    GetBucketExpires(bucket_name: std::string): std::string;
    GetBucketRemaining(bucket_name: std::string): std::string;
    SetBucket(bucket_name: std::string, bucket_value: std::string, expiration: std::string): void;
    CheckHeroicBonusesDataBuckets(bucket_name: std::string): float;
    DispatchZoneControllerEvent(evt: QuestEventID, init: Mob, data: std::string, extra: uint32, pointers: std::vector<std::any>): number;
    IsHealRotationTarget(m_target_of_heal_rotation.get(): ) { return (m_target_of_heal_rotation.use_count() ): boolean;
    JoinHealRotationTargetPool(heal_rotation: std::shared_ptr<HealRotation>): boolean;
    DrawDebugCoordinateNode(node_name: std::string, vec: glm::vec4): void;
    CalcHeroicBonuses(newbon: StatBonuses): void
  }

  export class QuestInterface {
    LogQuests("{}": , error: ): {
  }

  export class Raid extends GroupIDConsumer {
    constructor(arg0: Client);;
  constructor(arg0: uint32);
    IsLeader(!strcmp(leadername: char name) { return, name: ): boolean;
    SetRaidLeader(*wasLead: char, *name: char): void;
    AddMember(*c: Client, group: uint32, rleader: boolean, groupleader: boolean, looter: boolean): void;
    AddBot(b: Bot, group: uint32, raid_leader: boolean, group_leader: boolean, looter: boolean): void;
    RaidGroupSay(msg: string, from: string, language: uint8, lang_skill: uint8): void;
    RaidGroupSay(*msg: char, *c: Client, language: uint8, lang_skill: uint8): void;
    RaidSay(msg: string, from: string, language: uint8, lang_skill: uint8): void;
    RaidSay(*msg: char, *c: Client, language: uint8, lang_skill: uint8): void;
    RemoveMember(*character_name: char): void;
    MoveMember(*name: char, newGroup: uint32): void;
    SetGroupLeader(*who: char, glFlag: boolean): void;
    RemoveGroupLeader(*who: char): void;
    IsGroupLeader(name: string): boolean;
    IsGroupLeader(*c: Client): boolean;
    IsRaidMember(name: string): boolean;
    IsRaidMember(*c: Client): boolean;
    UpdateLevel(*name: char, newLevel: number): void;
    SetNewRaidLeader(i: uint32): void;
    IsAssister(who: string): boolean;
    IsMarker(who: string): boolean;
    GroupCount(gid: uint32): uint8;
    GetGroup(*name: char): uint32;
    GetGroup(*c: Client): uint32;
    ChangeLootType(type: uint32): void;
    AddRaidLooter(looter: string): void;
    RemoveRaidLooter(looter: string): void;
    GetPlayerIndex(*name: char): uint32;
    GetPlayerIndex(*c: Client): uint32;
    LockRaid(lockFlag: boolean): void;
    RaidMessageString(sender: Mob, type: uint32, string_id: uint32, message: string, message2: string, message3: string, message4: string, message5: string, message6: string, message7: string, message8: string, message9: string, distance: uint32): void;
    CastGroupSpell(caster: Mob, spellid: uint16, gid: uint32): void;
    SplitExp(exp: uint64, other: Mob): void;
    GetTotalRaidDamage(other: Mob): uint32;
    BalanceHP(penalty: int32, gid: uint32, range: float, caster: Mob, limit: int32): void;
    BalanceMana(penalty: int32, gid: uint32, range: float, caster: Mob, limit: int32): void;
    HealGroup(heal_amt: uint32, caster: Mob, gid: uint32, range: float): void;
    SplitMoney(gid: uint32, copper: uint32, silver: uint32, gold: uint32, platinum: uint32, *splitter: Client): void;
    TeleportGroup(sender: Mob, zoneID: uint32, instance_id: uint16, x: float, y: float, z: float, heading: float, gid: uint32): void;
    TeleportRaid(sender: Mob, zoneID: uint32, instance_id: uint16, x: float, y: float, z: float, heading: float): void;
    MemberZoned(*c: Client): void;
    SendHPManaEndPacketsTo(*c: Client): void;
    SendHPManaEndPacketsFrom(*mob: Mob): void;
    SendManaPacketFrom(*mob: Mob): void;
    SendEndurancePacketFrom(*mob: Mob): void;
    SaveRaidNote(who: std::string, note: std::string): void;
    DelegateAbilityAssist(mob: Mob, who: string): void;
    DelegateAbilityMark(mob: Mob, who: string): void;
    RaidMarkNPC(mob: Mob, parameter: uint32): void;
    UpdateXTargetType(Type: XTargetType, m: Mob, name: string): void;
    FindNextRaidDelegateSlot(option: number): number;
    RaidClearNPCMarks(c: Client): void;
    RemoveRaidDelegates(delegatee: string): void;
    SendRaidCreate(*to: Client): void;
    SendRaidAdd(*who: char, *to: Client): void;
    SendRaidAddAll(*who: char): void;
    SendRaidRemove(*who: char, *to: Client): void;
    SendRaidRemoveAll(*who: char): void;
    SendRaidDisband(*to: Client): void;
    SendRaidMove(who: string, *to: Client): void;
    SendRaidMoveAll(who: string): void;
    SendBulkRaid(*to: Client): void;
    SendRemoveRaidXTargets(Type: XTargetType): void;
    SendRemoveAllRaidXTargets(client_name: string): void;
    SendAssistTarget(c: Client): void;
    GroupUpdate(gid: uint32, initial: boolean): void;
    SendGroupUpdate(*to: Client): void;
    SendGroupDisband(*to: Client): void;
    SendRaidLockTo(*c: Client): void;
    SendRaidUnlockTo(*c: Client): void;
    SendRaidGroupAdd(*who: char, gid: uint32): void;
    SendRaidGroupRemove(*who: char, gid: uint32): void;
    SendMakeLeaderPacket(*who: char): void;
    SendMakeLeaderPacketTo(*who: char, *to: Client): void;
    SendMakeGroupLeaderPacket(*who: char): void;
    SendMakeGroupLeaderPacketTo(*who: char, *to: Client): void;
    SendRaidMOTD(*c: Client): void;
    SendRaidAssisterTo(assister: string, to: Client): void;
    SendRaidAssister(assister: string): void;
    SendRaidMarkerTo(marker: string, to: Client): void;
    SendRaidMarker(marker: string): void;
    SendMarkTargets(c: Client): void;
    QueuePacket(*app: EQApplicationPacket, ack_req: boolean): void;
    UpdateGroupAAs(gid: uint32): void;
    SaveGroupLeaderAA(gid: uint32): void;
    SendGroupLeadershipAA(*c: Client, gid: uint32): void;
    SendGroupLeadershipAA(gid: uint32): void;
    memcpy(&group_aa[gid]: , glaa: , sizeof(GroupLeadershipAA_Struct): ): {;
    memcpy(&raid_aa: , rlaa: , sizeof(RaidLeadershipAA_Struct): ): {;
    SetGroupMentor(group_id: uint32, percent: number, *name: number): void;
    ClearGroupMentor(group_id: uint32): void;
    CheckGroupMentor(group_id: uint32, *c: Client): void;
    QueueClients(*sender: Mob, *app: EQApplicationPacket, ack_required: boolean, ignore_sender: boolean, distance: float, group_only: boolean): void;
    DoesAnyMemberHaveExpeditionLockout(expedition_name: std::string, event_name: std::string, max_check_count: number): boolean;
    GetRaidGroupMembers(gid: uint32): std::vector<RaidMember>;
    GetRaidGroupBotMembers(gid: uint32): std::vector<Bot>;
    GetRaidBotMembers(owner: uint32): std::vector<Bot>;
    HandleBotGroupDisband(owner: uint32, gid: uint32): void;
    HandleOfflineBots(owner: uint32): void
  }

  export class Zone {
  
    SetIdleWhenEmpty(idle_when_empty: boolean): void;
    SetSecondsBeforeIdle(seconds_before_idle: uint32): void;
    AllowMercs((allow_mercs: ) { return): boolean;
    CanBind((can_bind: ) { return): boolean;
    CanCastOutdoor((can_castoutdoor: ) { return): boolean;
    CanDoCombat((can_combat: ) { return): boolean;
    CanLevitate((can_levitate: ) { return): boolean;
    Depop(StartSpawnTimer: boolean): boolean;
    Init(is_static: boolean): boolean;
    IsCity((is_city: ) { return): boolean;
    IsHotzone((is_hotzone: ) { return): boolean;
    IsSpellBlocked(spell_id: uint32, &location: glm::vec3): boolean;
    IsZone(zone_id: uint32, instance_id: uint16): boolean;
    LoadZoneCFG(*filename: char, instance_version: uint16): boolean;
    IsSpecialBindLocation(location: glm::vec4): boolean;
    SetNpcPositionUpdateDistance(in_npc_position_update_distance: number): void;
    SaveTempItem(merchantid: uint32, npcid: uint32, item: uint32, charges: int32, sold: boolean): number;
    GetSpawnKillCount(in_spawnid: uint32): uint32;
    GetTempMerchantQuantity(NPCID: uint32, Slot: uint32): uint32;
    GetCurrencyID(item_id: uint32): uint32;
    GetCurrencyItemID(currency_id: uint32): uint32;
    GetAAName(aa_id: number): std::string;
    SendReloadMessage(reload_type: std::string): void;
    ClearEXPModifier(c: Client): void;
    GetAAEXPModifier(c: Client): float;
    GetEXPModifier(c: Client): float;
    SetAAEXPModifier(c: Client, aa_modifier: float): void;
    SetEXPModifier(c: Client, exp_modifier: float): void;
    AddAuth(*szic: ServerZoneIncomingClient_Struct): void;
    ClearNPCTypeCache(id: number): void;
    DeleteQGlobal(name: std::string, npcID: uint32, charID: uint32, zoneID: uint32): void;
    Despawn(spawngroupID: uint32): void;
    LoadNewMerchantData(merchantid: uint32): void;
    LoadNPCEmotes(v: std::vector<NPC_Emote_Struct>): void;
    ReloadWorld(global_repop: uint8): void;
    RemoveAuth(*iCharName: char, *iLSKey: char): void;
    RemoveAuth(lsid: uint32): void;
    Repop(is_forced: boolean): void;
    SetDate(year: uint16, month: uint8, day: uint8, hour: uint8, minute: uint8): void;
    SetInstanceTimer(new_duration: uint32): void;
    SetTime(hour: uint8, minute: uint8, update_world: boolean): void;
    SetUCSServerAvailable(ucss_available: boolean, update_timestamp: uint32): void;
    SpawnConditionChanged(&c: SpawnCondition, old_value: int16): void;
    StartShutdownTimer(set_time: uint32, AutoShutdownDelay)): ): void;
    UpdateQGlobal(qid: uint32, newGlobal: QGlobal): void;
    weatherSend(*client: Client): void;
    SetQuestHotReloadQueued(in_quest_hot_reload_queued: boolean): void;
    CompareDataBucket(bucket_comparison: uint8, bucket_value: std::string, player_value: std::string): boolean;
    SetInstanceTimeRemaining(instance_time_remaining: uint32): void;
    SendDiscordMessage(webhook_id: , Discord::FormatDiscordMessage(log_category: message_prefix +, message): ): };
    SetIsHotzone(is_hotzone: boolean): void;
    LoadNPCFaction(npc_faction_id: uint32): void;
    LoadNPCFactions(npc_faction_ids: std::vector<uint32>): void;
    GetNPCFaction(npc_faction_id: uint32): NpcFactionRepository::NpcFaction;
    GetNPCFactionEntries(npc_faction_id: uint32): std::vector<NpcFactionEntriesRepository::NpcFactionEntries>;
    LoadNPCFactionAssociation(npc_faction_id: uint32): void;
    LoadNPCFactionAssociations(npc_faction_ids: std::vector<uint32>): void;
    LoadFactionAssociation(faction_id: uint32): void;
    LoadFactionAssociations(faction_ids: std::vector<uint32>): void;
    GetFactionAssociation(faction_id: uint32): FactionAssociationRepository::FactionAssociation;
    LoadLootTable(loottable_id: uint32): void;
    LoadLootTables(loottable_ids: std::vector<uint32>): void;
    GetLootTableEntries(loottable_id: uint32): std::vector<LoottableEntriesRepository::LoottableEntries>;
    GetLootdrop(lootdrop_id: uint32): LootdropRepository::Lootdrop;
    GetLootdropEntries(lootdrop_id: uint32): std::vector<LootdropEntriesRepository::LootdropEntries>;
    GetBaseData(level: uint8, class_id: uint8): BaseDataRepository::BaseData
  }
}
