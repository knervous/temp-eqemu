using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp.Scripting;
using Microsoft.CodeAnalysis.Scripting;
using System.Reflection;
using System.Reflection.Metadata.Ecma335;
using System.Runtime.InteropServices;
using System.Security.Cryptography.X509Certificates;

public static class DotNetQuest
{
    public static Zone? zone = null;
    public static EntityList? entityList = null;
    public static InitArgs? initArgs = null;

    [StructLayout(LayoutKind.Sequential)]
    public struct InitArgs
    {
        public IntPtr Zone;
        public IntPtr EntityList;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct NpcEventArgs
    {
        public int QuestEventId;
        public IntPtr Npc;
        public IntPtr Mob;
        public IntPtr Data;
    }

    public static NPC? GetNPCByName(EntityList entityList, string name)
    {
        foreach (var npc in entityList.npc_list)
        {
            if (npc.Value.GetOrigName() == name)
            {
                return npc.Value;
            }
        }
        return null;
    }

    private static Dictionary<string, object> NpcMap = new Dictionary<string, object>();

    public delegate void InitializeDelegate(InitArgs initArgs);
    public delegate void ReloadDelegate();
    public delegate void NpcEventDelegate(NpcEventArgs npcEventArgs);

    public static void Initialize(InitArgs initArgs)
    {
        zone = EqFactory.CreateZone(initArgs.Zone, false);
        entityList = EqFactory.CreateEntityList(initArgs.EntityList, false);
        DotNetQuest.initArgs = initArgs;
    }

    public static void Reload()
    {
        NpcMap.Clear();
    }

    public static void NpcEvent(NpcEventArgs npcEventArgs)
    {
        if (zone == null || entityList == null)
        {
            return;
        }
        Console.WriteLine($"NpcEvent Invoked");

        QuestEventID id = (QuestEventID)npcEventArgs.QuestEventId;
        var npc = EqFactory.CreateNPC(npcEventArgs.Npc, false);
        var mob = EqFactory.CreateMob(npcEventArgs.Mob, false);

        string? message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
            ? Marshal.PtrToStringUni(npcEventArgs.Data)
            : Marshal.PtrToStringUTF8(npcEventArgs.Data);

        NpcEvent p = new NpcEvent
        {
            zone = zone,
            entityList = entityList,
            mob = mob,
            npc = npc,
            data = message ?? ""
        };

        var npcName = npc.GetOrigName();
        // if (NpcMap.ContainsKey(npcName))
        // {
        //     Task.Run(() =>
        //     {
        //         var instance = NpcMap[npcName];
        //         var createNpcEvent = instance.GetType()?.GetInterfaces()[0]?.Assembly.ExportedTypes.FirstOrDefault(f => f.FullName == "EqFactory")?.GetMethod("CreateNpcEvent");
        //         if (createNpcEvent != null)
        //         {
        //             var npcEvent = createNpcEvent.Invoke(instance, [initArgs?.Zone, initArgs?.EntityList, npcEventArgs.Npc, npcEventArgs.Mob, message ?? ""]);
        //             var methodInfo = instance.GetType().GetMethod(MethodMap[id]);
        //             if (methodInfo != null)
        //             {
        //                 methodInfo.Invoke(instance, [npcEvent]);
        //             }
        //         }
        //     });

        //     return;
        // }
        var path = Assembly.GetExecutingAssembly().Location;

        var directory = Path.GetDirectoryName(path);
        var scriptName = $"{directory}/dotnet_quests/{zone.GetShortName()}/{npcName}.csx";
        if (File.Exists(scriptName))
        {
            Task.Run(async () =>
            {
                var text = File.ReadAllText(scriptName);
                text = text.Replace("#r \"../../DotNetTypes.dll\"", "");
                // Idea for wrapping class
                // text = @$"
                //        public class TypeWrapper<NpcEvent>
                //         {{
                //             {text}
                //             public Npc GenerateWrapper()
                //             {{
                //                 return new Npc();
                //             }}
                //         }}
                //         return typeof(TypeWrapper);
                // ";
                
                var scriptOptions = ScriptOptions.Default.WithReferences(MetadataReference.CreateFromFile($"{directory}/DotNetTypes.dll"));
                var state = await CSharpScript.RunAsync(text, scriptOptions);
                // var retValue = state.ReturnValue;
                NpcMap[npcName] = state.ReturnValue;
                var instance = NpcMap[npcName];
                var createNpcEvent = instance.GetType()?.GetInterfaces()[0]?.Assembly.ExportedTypes.FirstOrDefault(f => f.FullName == "EqFactory")?.GetMethod("CreateNpcEvent");
                if (createNpcEvent != null)
                {
                    var npcEvent = createNpcEvent.Invoke(instance, [initArgs?.Zone, initArgs?.EntityList, npcEventArgs.Npc, npcEventArgs.Mob, message ?? ""]);
                    var methodInfo = instance.GetType().GetMethod(MethodMap[id]);
                    if (methodInfo != null)
                    {
                        methodInfo.Invoke(instance, [npcEvent]);
                    }
                }
            });
        }
    }


 
    private static readonly Dictionary<QuestEventID, string> MethodMap = new Dictionary<QuestEventID, string> {
       {QuestEventID.EVENT_SAY, "Say"},
       {QuestEventID.EVENT_TRADE, "Trade"},
        {QuestEventID.EVENT_DEATH, "Death"},
        {QuestEventID.EVENT_SPAWN, "Spawn"},
        {QuestEventID.EVENT_ATTACK, "Attack"},
        {QuestEventID.EVENT_COMBAT, "Combat"},
        {QuestEventID.EVENT_AGGRO, "Aggro"},
        {QuestEventID.EVENT_SLAY, "Slay"},
        {QuestEventID.EVENT_NPC_SLAY, "NpcSlay"},
        {QuestEventID.EVENT_WAYPOINT_ARRIVE, "WaypointArrive"},
        {QuestEventID.EVENT_WAYPOINT_DEPART, "WaypointDepart"},
        {QuestEventID.EVENT_TIMER, "Timer"},
        {QuestEventID.EVENT_SIGNAL, "Signal"},
        {QuestEventID.EVENT_HP, "Hp"},
        {QuestEventID.EVENT_ENTER, "Enter"},
        {QuestEventID.EVENT_EXIT, "Exit"},
        {QuestEventID.EVENT_ENTER_ZONE, "EnterZone"},
        {QuestEventID.EVENT_CLICK_DOOR, "ClickDoor"},
        {QuestEventID.EVENT_LOOT, "Loot"},
        {QuestEventID.EVENT_ZONE, "Zone"},
        {QuestEventID.EVENT_LEVEL_UP, "LevelUp"},
        {QuestEventID.EVENT_KILLED_MERIT, "KilledMerit"},
        {QuestEventID.EVENT_CAST_ON, "CastOn"},
        {QuestEventID.EVENT_TASK_ACCEPTED, "TaskAccepted"},
        {QuestEventID.EVENT_TASK_STAGE_COMPLETE, "TaskStageComplete"},
        {QuestEventID.EVENT_TASK_UPDATE, "TaskUpdate"},
        {QuestEventID.EVENT_TASK_COMPLETE, "TaskComplete"},
        {QuestEventID.EVENT_TASK_FAIL, "TaskFail"},
        {QuestEventID.EVENT_AGGRO_SAY, "AggroSay"},
        {QuestEventID.EVENT_PLAYER_PICKUP, "PlayerPickup"},
        {QuestEventID.EVENT_POPUP_RESPONSE, "PopupResponse"},
        {QuestEventID.EVENT_ENVIRONMENTAL_DAMAGE, "EnvironmentalDamage"},
        {QuestEventID.EVENT_PROXIMITY_SAY, "ProximitySay"},
        {QuestEventID.EVENT_CAST, "Cast"},
        {QuestEventID.EVENT_CAST_BEGIN, "CastBegin"},
        {QuestEventID.EVENT_SCALE_CALC, "ScaleCalc"},
        {QuestEventID.EVENT_ITEM_ENTER_ZONE, "ItemEnterZone"},
        {QuestEventID.EVENT_TARGET_CHANGE, "TargetChange"},
        {QuestEventID.EVENT_HATE_LIST, "HateList"},
        {QuestEventID.EVENT_SPELL_EFFECT_CLIENT, "SpellEffectClient"},
        {QuestEventID.EVENT_SPELL_EFFECT_NPC, "SpellEffectNpc"},
        {QuestEventID.EVENT_SPELL_EFFECT_BUFF_TIC_CLIENT, "SpellEffectBuffTicClient"},
        {QuestEventID.EVENT_SPELL_EFFECT_BUFF_TIC_NPC, "SpellEffectBuffTicNpc"},
        {QuestEventID.EVENT_SPELL_FADE, "SpellFade"},
        {QuestEventID.EVENT_SPELL_EFFECT_TRANSLOCATE_COMPLETE, "SpellEffectTranslocateComplete"},
        {QuestEventID.EVENT_COMBINE_SUCCESS, "CombineSuccess"},
        {QuestEventID.EVENT_COMBINE_FAILURE, "CombineFailure"},
        {QuestEventID.EVENT_ITEM_CLICK, "ItemClick"},
        {QuestEventID.EVENT_ITEM_CLICK_CAST, "ItemClickCast"},
        {QuestEventID.EVENT_GROUP_CHANGE, "GroupChange"},
        {QuestEventID.EVENT_FORAGE_SUCCESS, "ForageSuccess"},
        {QuestEventID.EVENT_FORAGE_FAILURE, "ForageFailure"},
        {QuestEventID.EVENT_FISH_START, "FishStart"},
        {QuestEventID.EVENT_FISH_SUCCESS, "FishSuccess"},
        {QuestEventID.EVENT_FISH_FAILURE, "FishFailure"},
        {QuestEventID.EVENT_CLICK_OBJECT, "ClickObject"},
        {QuestEventID.EVENT_DISCOVER_ITEM, "DiscoverItem"},
        {QuestEventID.EVENT_DISCONNECT, "Disconnect"},
        {QuestEventID.EVENT_CONNECT, "Connect"},
        {QuestEventID.EVENT_ITEM_TICK, "ItemTick"},
        {QuestEventID.EVENT_DUEL_WIN, "DuelWin"},
        {QuestEventID.EVENT_DUEL_LOSE, "DuelLose"},
        {QuestEventID.EVENT_ENCOUNTER_LOAD, "EncounterLoad"},
        {QuestEventID.EVENT_ENCOUNTER_UNLOAD, "EncounterUnload"},
        {QuestEventID.EVENT_COMMAND, "Command"},
        {QuestEventID.EVENT_DROP_ITEM, "DropItem"},
        {QuestEventID.EVENT_DESTROY_ITEM, "DestroyItem"},
        {QuestEventID.EVENT_FEIGN_DEATH, "FeignDeath"},
        {QuestEventID.EVENT_WEAPON_PROC, "WeaponProc"},
        {QuestEventID.EVENT_EQUIP_ITEM, "EquipItem"},
        {QuestEventID.EVENT_UNEQUIP_ITEM, "UnequipItem"},
        {QuestEventID.EVENT_AUGMENT_ITEM, "AugmentItem"},
        {QuestEventID.EVENT_UNAUGMENT_ITEM, "UnaugmentItem"},
        {QuestEventID.EVENT_AUGMENT_INSERT, "AugmentInsert"},
        {QuestEventID.EVENT_AUGMENT_REMOVE, "AugmentRemove"},
        {QuestEventID.EVENT_ENTER_AREA, "EnterArea"},
        {QuestEventID.EVENT_LEAVE_AREA, "LeaveArea"},
        {QuestEventID.EVENT_RESPAWN, "Respawn"},
        {QuestEventID.EVENT_DEATH_COMPLETE, "DeathComplete"},
        {QuestEventID.EVENT_UNHANDLED_OPCODE, "UnhandledOpcode"},
        {QuestEventID.EVENT_TICK, "Tick"},
        {QuestEventID.EVENT_SPAWN_ZONE, "SpawnZone"},
        {QuestEventID.EVENT_DEATH_ZONE, "DeathZone"},
        {QuestEventID.EVENT_USE_SKILL, "UseSkill"},
        {QuestEventID.EVENT_COMBINE_VALIDATE, "CombineValidate"},
        {QuestEventID.EVENT_BOT_COMMAND, "BotCommand"},
        {QuestEventID.EVENT_WARP, "Warp"},
        {QuestEventID.EVENT_TEST_BUFF, "TestBuff"},
        {QuestEventID.EVENT_COMBINE, "Combine"},
        {QuestEventID.EVENT_CONSIDER, "Consider"},
        {QuestEventID.EVENT_CONSIDER_CORPSE, "ConsiderCorpse"},
        {QuestEventID.EVENT_LOOT_ZONE, "LootZone"},
        {QuestEventID.EVENT_EQUIP_ITEM_CLIENT, "EquipItemClient"},
        {QuestEventID.EVENT_UNEQUIP_ITEM_CLIENT, "UnequipItemClient"},
        {QuestEventID.EVENT_SKILL_UP, "SkillUp"},
        {QuestEventID.EVENT_LANGUAGE_SKILL_UP, "LanguageSkillUp"},
        {QuestEventID.EVENT_ALT_CURRENCY_MERCHANT_BUY, "AltCurrencyMerchantBuy"},
        {QuestEventID.EVENT_ALT_CURRENCY_MERCHANT_SELL, "AltCurrencyMerchantSell"},
        {QuestEventID.EVENT_MERCHANT_BUY, "MerchantBuy"},
        {QuestEventID.EVENT_MERCHANT_SELL, "MerchantSell"},
        {QuestEventID.EVENT_INSPECT, "Inspect"},
        {QuestEventID.EVENT_TASK_BEFORE_UPDATE, "TaskBeforeUpdate"},
        {QuestEventID.EVENT_AA_BUY, "AaBuy"},
        {QuestEventID.EVENT_AA_GAIN, "AaGain"},
        {QuestEventID.EVENT_AA_EXP_GAIN, "AaExpGain"},
        {QuestEventID.EVENT_EXP_GAIN, "ExpGain"},
        {QuestEventID.EVENT_PAYLOAD, "Payload"},
        {QuestEventID.EVENT_LEVEL_DOWN, "LevelDown"},
        {QuestEventID.EVENT_GM_COMMAND, "GmCommand"},
        {QuestEventID.EVENT_DESPAWN, "Despawn"},
        {QuestEventID.EVENT_DESPAWN_ZONE, "DespawnZone"},
        {QuestEventID.EVENT_BOT_CREATE, "BotCreate"},
        {QuestEventID.EVENT_AUGMENT_INSERT_CLIENT, "AugmentInsertClient"},
        {QuestEventID.EVENT_AUGMENT_REMOVE_CLIENT, "AugmentRemoveClient"},
        {QuestEventID.EVENT_EQUIP_ITEM_BOT, "EquipItemBot"},
        {QuestEventID.EVENT_UNEQUIP_ITEM_BOT, "UnequipItemBot"},
        {QuestEventID.EVENT_DAMAGE_GIVEN, "DamageGiven"},
        {QuestEventID.EVENT_DAMAGE_TAKEN, "DamageTaken"},
        {QuestEventID.EVENT_ITEM_CLICK_CLIENT, "ItemClickClient"},
        {QuestEventID.EVENT_ITEM_CLICK_CAST_CLIENT, "ItemClickCastClient"},
        {QuestEventID.EVENT_DESTROY_ITEM_CLIENT, "DestroyItemClient"},
        {QuestEventID.EVENT_DROP_ITEM_CLIENT, "DropItemClient"},
        {QuestEventID.EVENT_MEMORIZE_SPELL, "MemorizeSpell"},
        {QuestEventID.EVENT_UNMEMORIZE_SPELL, "UnmemorizeSpell"},
        {QuestEventID.EVENT_SCRIBE_SPELL, "ScribeSpell"},
        {QuestEventID.EVENT_UNSCRIBE_SPELL, "UnscribeSpell"},
        {QuestEventID.EVENT_LOOT_ADDED, "LootAdded"},
        {QuestEventID.EVENT_LDON_POINTS_GAIN, "LdonPointsGain"},
        {QuestEventID.EVENT_LDON_POINTS_LOSS, "LdonPointsLoss"},
        {QuestEventID.EVENT_ALT_CURRENCY_GAIN, "AltCurrencyGain"},
        {QuestEventID.EVENT_ALT_CURRENCY_LOSS, "AltCurrencyLoss"},
        {QuestEventID.EVENT_CRYSTAL_GAIN, "CrystalGain"},
        {QuestEventID.EVENT_CRYSTAL_LOSS, "CrystalLoss"},
        {QuestEventID.EVENT_TIMER_PAUSE, "TimerPause"},
        {QuestEventID.EVENT_TIMER_RESUME, "TimerResume"},
        {QuestEventID.EVENT_TIMER_START, "TimerStart"},
        {QuestEventID.EVENT_TIMER_STOP, "TimerStop"},
        {QuestEventID.EVENT_ENTITY_VARIABLE_DELETE, "EntityVariableDelete"},
        {QuestEventID.EVENT_ENTITY_VARIABLE_SET, "EntityVariableSet"},
        {QuestEventID.EVENT_ENTITY_VARIABLE_UPDATE, "EntityVariableUpdate"},
        {QuestEventID.EVENT_SPELL_EFFECT_BOT, "SpellEffectBot"},
        {QuestEventID.EVENT_SPELL_EFFECT_BUFF_TIC_BOT, "SpellEffectBuffTicBot"},
    };
}
