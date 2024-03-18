
public class EqFactory
{
    public static Zone CreateZone(nint Cptr, bool own)
    {
        return new Zone(Cptr, own);
    }
    public static EntityList CreateEntityList(nint Cptr, bool own)
    {
        return new EntityList(Cptr, own);
    }
    public static NPC CreateNPC(nint Cptr, bool own)
    {
        return new NPC(Cptr, own);
    }

    public static Mob CreateMob(nint Cptr, bool own)
    {
        return new Mob(Cptr, own);
    }

    public static NpcEvent CreateNpcEvent(nint zonePtr, nint entityPtr, nint npcPtr, nint mobPtr, string message) {
        return new NpcEvent
        {
            zone = new Zone(zonePtr, false),
            entityList = new EntityList(entityPtr, false),
            npc = new NPC(npcPtr, false),
            mob = new Mob(mobPtr, false),
            data = message ?? ""
        };
    }
}

public interface INpcEvent
{
    Task Say(NpcEvent e) => Task.CompletedTask;
    Task Trade(NpcEvent e) => Task.CompletedTask;
    Task Death(NpcEvent e) => Task.CompletedTask;
    Task Spawn(NpcEvent e) => Task.CompletedTask;
    Task Attack(NpcEvent e) => Task.CompletedTask;
    Task Combat(NpcEvent e) => Task.CompletedTask;
    Task Aggro(NpcEvent e) => Task.CompletedTask;
    Task Slay(NpcEvent e) => Task.CompletedTask;
    Task NpcSlay(NpcEvent e) => Task.CompletedTask;
    Task WaypointArrive(NpcEvent e) => Task.CompletedTask;
    Task WaypointDepart(NpcEvent e) => Task.CompletedTask;
    Task Timer(NpcEvent e) => Task.CompletedTask;
    Task Signal(NpcEvent e) => Task.CompletedTask;
    Task Hp(NpcEvent e) => Task.CompletedTask;
    Task Enter(NpcEvent e) => Task.CompletedTask;
    Task Exit(NpcEvent e) => Task.CompletedTask;
    Task EnterZone(NpcEvent e) => Task.CompletedTask;
    Task ClickDoor(NpcEvent e) => Task.CompletedTask;
    Task Loot(NpcEvent e) => Task.CompletedTask;
    Task Zone(NpcEvent e) => Task.CompletedTask;
    Task LevelUp(NpcEvent e) => Task.CompletedTask;
    Task KilledMerit(NpcEvent e) => Task.CompletedTask;
    Task CastOn(NpcEvent e) => Task.CompletedTask;
    Task TaskAccepted(NpcEvent e) => Task.CompletedTask;
    Task TaskStageComplete(NpcEvent e) => Task.CompletedTask;
    Task TaskUpdate(NpcEvent e) => Task.CompletedTask;
    Task TaskComplete(NpcEvent e) => Task.CompletedTask;
    Task TaskFail(NpcEvent e) => Task.CompletedTask;
    Task AggroSay(NpcEvent e) => Task.CompletedTask;
    Task PlayerPickup(NpcEvent e) => Task.CompletedTask;
    Task PopupResponse(NpcEvent e) => Task.CompletedTask;
    Task EnvironmentalDamage(NpcEvent e) => Task.CompletedTask;
    Task ProximitySay(NpcEvent e) => Task.CompletedTask;
    Task Cast(NpcEvent e) => Task.CompletedTask;
    Task CastBegin(NpcEvent e) => Task.CompletedTask;
    Task ScaleCalc(NpcEvent e) => Task.CompletedTask;
    Task ItemEnterZone(NpcEvent e) => Task.CompletedTask;
    Task TargetChange(NpcEvent e) => Task.CompletedTask;
    Task HateList(NpcEvent e) => Task.CompletedTask;
    Task SpellEffectClient(NpcEvent e) => Task.CompletedTask;
    Task SpellEffectNpc(NpcEvent e) => Task.CompletedTask;
    Task SpellEffectBuffTicClient(NpcEvent e) => Task.CompletedTask;
    Task SpellEffectBuffTicNpc(NpcEvent e) => Task.CompletedTask;
    Task SpellFade(NpcEvent e) => Task.CompletedTask;
    Task SpellEffectTranslocateComplete(NpcEvent e) => Task.CompletedTask;
    Task CombineSuccess(NpcEvent e) => Task.CompletedTask;
    Task CombineFailure(NpcEvent e) => Task.CompletedTask;
    Task ItemClick(NpcEvent e) => Task.CompletedTask;
    Task ItemClickCast(NpcEvent e) => Task.CompletedTask;
    Task GroupChange(NpcEvent e) => Task.CompletedTask;
    Task ForageSuccess(NpcEvent e) => Task.CompletedTask;
    Task ForageFailure(NpcEvent e) => Task.CompletedTask;
    Task FishStart(NpcEvent e) => Task.CompletedTask;
    Task FishSuccess(NpcEvent e) => Task.CompletedTask;
    Task FishFailure(NpcEvent e) => Task.CompletedTask;
    Task ClickObject(NpcEvent e) => Task.CompletedTask;
    Task DiscoverItem(NpcEvent e) => Task.CompletedTask;
    Task Disconnect(NpcEvent e) => Task.CompletedTask;
    Task Connect(NpcEvent e) => Task.CompletedTask;
    Task ItemTick(NpcEvent e) => Task.CompletedTask;
    Task DuelWin(NpcEvent e) => Task.CompletedTask;
    Task DuelLose(NpcEvent e) => Task.CompletedTask;
    Task EncounterLoad(NpcEvent e) => Task.CompletedTask;
    Task EncounterUnload(NpcEvent e) => Task.CompletedTask;
    Task Command(NpcEvent e) => Task.CompletedTask;
    Task DropItem(NpcEvent e) => Task.CompletedTask;
    Task DestroyItem(NpcEvent e) => Task.CompletedTask;
    Task FeignDeath(NpcEvent e) => Task.CompletedTask;
    Task WeaponProc(NpcEvent e) => Task.CompletedTask;
    Task EquipItem(NpcEvent e) => Task.CompletedTask;
    Task UnequipItem(NpcEvent e) => Task.CompletedTask;
    Task AugmentItem(NpcEvent e) => Task.CompletedTask;
    Task UnaugmentItem(NpcEvent e) => Task.CompletedTask;
    Task AugmentInsert(NpcEvent e) => Task.CompletedTask;
    Task AugmentRemove(NpcEvent e) => Task.CompletedTask;
    Task EnterArea(NpcEvent e) => Task.CompletedTask;
    Task LeaveArea(NpcEvent e) => Task.CompletedTask;
    Task Respawn(NpcEvent e) => Task.CompletedTask;
    Task DeathComplete(NpcEvent e) => Task.CompletedTask;
    Task UnhandledOpcode(NpcEvent e) => Task.CompletedTask;
    Task Tick(NpcEvent e) => Task.CompletedTask;
    Task SpawnZone(NpcEvent e) => Task.CompletedTask;
    Task DeathZone(NpcEvent e) => Task.CompletedTask;
    Task UseSkill(NpcEvent e) => Task.CompletedTask;
    Task CombineValidate(NpcEvent e) => Task.CompletedTask;
    Task BotCommand(NpcEvent e) => Task.CompletedTask;
    Task Warp(NpcEvent e) => Task.CompletedTask;
    Task TestBuff(NpcEvent e) => Task.CompletedTask;
    Task Combine(NpcEvent e) => Task.CompletedTask;
    Task Consider(NpcEvent e) => Task.CompletedTask;
    Task ConsiderCorpse(NpcEvent e) => Task.CompletedTask;
    Task LootZone(NpcEvent e) => Task.CompletedTask;
    Task EquipItemClient(NpcEvent e) => Task.CompletedTask;
    Task UnequipItemClient(NpcEvent e) => Task.CompletedTask;
    Task SkillUp(NpcEvent e) => Task.CompletedTask;
    Task LanguageSkillUp(NpcEvent e) => Task.CompletedTask;
    Task AltCurrencyMerchantBuy(NpcEvent e) => Task.CompletedTask;
    Task AltCurrencyMerchantSell(NpcEvent e) => Task.CompletedTask;
    Task MerchantBuy(NpcEvent e) => Task.CompletedTask;
    Task MerchantSell(NpcEvent e) => Task.CompletedTask;
    Task Inspect(NpcEvent e) => Task.CompletedTask;
    Task TaskBeforeUpdate(NpcEvent e) => Task.CompletedTask;
    Task AaBuy(NpcEvent e) => Task.CompletedTask;
    Task AaGain(NpcEvent e) => Task.CompletedTask;
    Task AaExpGain(NpcEvent e) => Task.CompletedTask;
    Task ExpGain(NpcEvent e) => Task.CompletedTask;
    Task Payload(NpcEvent e) => Task.CompletedTask;
    Task LevelDown(NpcEvent e) => Task.CompletedTask;
    Task GmCommand(NpcEvent e) => Task.CompletedTask;
    Task Despawn(NpcEvent e) => Task.CompletedTask;
    Task DespawnZone(NpcEvent e) => Task.CompletedTask;
    Task BotCreate(NpcEvent e) => Task.CompletedTask;
    Task AugmentInsertClient(NpcEvent e) => Task.CompletedTask;
    Task AugmentRemoveClient(NpcEvent e) => Task.CompletedTask;
    Task EquipItemBot(NpcEvent e) => Task.CompletedTask;
    Task UnequipItemBot(NpcEvent e) => Task.CompletedTask;
    Task DamageGiven(NpcEvent e) => Task.CompletedTask;
    Task DamageTaken(NpcEvent e) => Task.CompletedTask;
    Task ItemClickClient(NpcEvent e) => Task.CompletedTask;
    Task ItemClickCastClient(NpcEvent e) => Task.CompletedTask;
    Task DestroyItemClient(NpcEvent e) => Task.CompletedTask;
    Task DropItemClient(NpcEvent e) => Task.CompletedTask;
    Task MemorizeSpell(NpcEvent e) => Task.CompletedTask;
    Task UnmemorizeSpell(NpcEvent e) => Task.CompletedTask;
    Task ScribeSpell(NpcEvent e) => Task.CompletedTask;
    Task UnscribeSpell(NpcEvent e) => Task.CompletedTask;
    Task LootAdded(NpcEvent e) => Task.CompletedTask;
    Task LdonPointsGain(NpcEvent e) => Task.CompletedTask;
    Task LdonPointsLoss(NpcEvent e) => Task.CompletedTask;
    Task AltCurrencyGain(NpcEvent e) => Task.CompletedTask;
    Task AltCurrencyLoss(NpcEvent e) => Task.CompletedTask;
    Task CrystalGain(NpcEvent e) => Task.CompletedTask;
    Task CrystalLoss(NpcEvent e) => Task.CompletedTask;
    Task TimerPause(NpcEvent e) => Task.CompletedTask;
    Task TimerResume(NpcEvent e) => Task.CompletedTask;
    Task TimerStart(NpcEvent e) => Task.CompletedTask;
    Task TimerStop(NpcEvent e) => Task.CompletedTask;
    Task EntityVariableDelete(NpcEvent e) => Task.CompletedTask;
    Task EntityVariableSet(NpcEvent e) => Task.CompletedTask;
    Task EntityVariableUpdate(NpcEvent e) => Task.CompletedTask;
    Task SpellEffectBot(NpcEvent e) => Task.CompletedTask;
    Task SpellEffectBuffTicBot(NpcEvent e) => Task.CompletedTask;
}

public struct NpcEvent
{
    public Zone zone;
    public EntityList entityList;
    public NPC npc;
    public Mob mob;
    public string data;
}
