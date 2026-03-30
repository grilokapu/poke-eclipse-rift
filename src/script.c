#include "global.h"
#include "script.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_weather.h"
#include "menu.h"
#include "metaprogram.h"
#include "mystery_gift.h"
#include "naming_screen.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trainer_see.h"
#include "trainer_pokemon_sprites.h"
#include "util.h"
#include "window.h"
#include "constants/characters.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/map_scripts.h"
#include "constants/script_commands.h"
#include "constants/species.h"
#include "field_message_box.h"

#include "gba/types.h"

#include "dexnav.h"

#define RAM_SCRIPT_MAGIC 51

enum {
    SCRIPT_MODE_STOPPED,
    SCRIPT_MODE_BYTECODE,
    SCRIPT_MODE_NATIVE,
};

enum {
    CONTEXT_RUNNING,
    CONTEXT_WAITING,
    CONTEXT_SHUTDOWN,
};

extern const u8 *gRamScriptRetAddr;

static u8 sGlobalScriptContextStatus;
static struct ScriptContext sGlobalScriptContext;
static struct ScriptContext sImmediateScriptContext;
static bool8 sLockFieldControls;
EWRAM_DATA u8 gMsgIsSignPost = FALSE;
EWRAM_DATA u8 gMsgBoxIsCancelable = FALSE;

extern ScrCmdFunc gScriptCmdTable[];
extern ScrCmdFunc gScriptCmdTableEnd[];
extern void *const gNullScriptPtr;

void ClearMiniBox(void);
static void SpriteCB_Sparkle(struct Sprite *sprite);
u8 CreateMonSprite_PicBox2(u16 species, bool8 isShiny, s16 x, s16 y, u8 subpriority);
void SpriteCB_ShakePokemonPic(struct Sprite *sprite);

const u16 gSprite_SparkleGfx[] = INCBIN_U16("graphics/field_effects/pics/sparkle2.4bpp");
const u16 gSprite_SparklePal[] = INCBIN_U16("graphics/field_effects/palettes/sparkle2.gbapal");

void InitScriptContext(struct ScriptContext *ctx, void *cmdTable, void *cmdTableEnd)
{
    s32 i;

    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
    ctx->stackDepth = 0;
    ctx->nativePtr = NULL;
    ctx->cmdTable = cmdTable;
    ctx->cmdTableEnd = cmdTableEnd;

    for (i = 0; i < (int)ARRAY_COUNT(ctx->data); i++)
        ctx->data[i] = 0;

    for (i = 0; i < (int)ARRAY_COUNT(ctx->stack); i++)
        ctx->stack[i] = NULL;

    ctx->breakOnTrainerBattle = FALSE;
}

u8 SetupBytecodeScript(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
    ctx->mode = SCRIPT_MODE_BYTECODE;
    return 1;
}

void SetupNativeScript(struct ScriptContext *ctx, bool8 (*ptr)(void))
{
    ctx->mode = SCRIPT_MODE_NATIVE;
    ctx->nativePtr = ptr;
}

void StopScript(struct ScriptContext *ctx)
{
    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
}

bool8 RunScriptCommand(struct ScriptContext *ctx)
{
    if (ctx->mode == SCRIPT_MODE_STOPPED)
        return FALSE;

    switch (ctx->mode)
    {
    case SCRIPT_MODE_STOPPED:
        return FALSE;
    case SCRIPT_MODE_NATIVE:
        // Try to call a function in C
        // Continue to bytecode if no function or it returns TRUE
        if (ctx->nativePtr)
        {
            if (ctx->nativePtr() == TRUE)
                ctx->mode = SCRIPT_MODE_BYTECODE;
            return TRUE;
        }
        ctx->mode = SCRIPT_MODE_BYTECODE;
        // fallthrough
    case SCRIPT_MODE_BYTECODE:
        while (1)
        {
            u8 cmdCode;
            ScrCmdFunc *func;

            if (!ctx->scriptPtr)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            if (ctx->scriptPtr == gNullScriptPtr)
            {
                while (1)
                    asm("svc 2"); // HALT
            }

            cmdCode = *(ctx->scriptPtr);
            ctx->scriptPtr++;
            func = &ctx->cmdTable[cmdCode];

            if (func >= ctx->cmdTableEnd)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            if ((*func)(ctx) == TRUE)
                return TRUE;
        }
    }

    return TRUE;
}

static bool8 ScriptPush(struct ScriptContext *ctx, const u8 *ptr)
{
    if (ctx->stackDepth + 1 >= (int)ARRAY_COUNT(ctx->stack))
    {
        return TRUE;
    }
    else
    {
        ctx->stack[ctx->stackDepth] = ptr;
        ctx->stackDepth++;
        return FALSE;
    }
}

static const u8 *ScriptPop(struct ScriptContext *ctx)
{
    if (ctx->stackDepth == 0)
        return NULL;

    ctx->stackDepth--;
    return ctx->stack[ctx->stackDepth];
}

void ScriptJump(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
}

void ScriptCall(struct ScriptContext *ctx, const u8 *ptr)
{
    bool32 failed = ScriptPush(ctx, ctx->scriptPtr);
    assertf(!failed, "could not push %p", ptr)
    {
        return;
    }
    ctx->scriptPtr = ptr;
}

void ScriptReturn(struct ScriptContext *ctx)
{
    ctx->scriptPtr = ScriptPop(ctx);
}

u16 ScriptReadHalfword(struct ScriptContext *ctx)
{
    u16 value = *(ctx->scriptPtr++);
    value |= *(ctx->scriptPtr++) << 8;
    return value;
}

u16 ScriptPeekHalfword(struct ScriptContext *ctx)
{
    u16 value = *(ctx->scriptPtr);
    value |= *(ctx->scriptPtr + 1) << 8;
    return value;
}

u32 ScriptReadWord(struct ScriptContext *ctx)
{
    u32 value0 = *(ctx->scriptPtr++);
    u32 value1 = *(ctx->scriptPtr++);
    u32 value2 = *(ctx->scriptPtr++);
    u32 value3 = *(ctx->scriptPtr++);
    return (((((value3 << 8) + value2) << 8) + value1) << 8) + value0;
}

u32 ScriptPeekWord(struct ScriptContext *ctx)
{
    u32 value0 = *(ctx->scriptPtr);
    u32 value1 = *(ctx->scriptPtr + 1);
    u32 value2 = *(ctx->scriptPtr + 2);
    u32 value3 = *(ctx->scriptPtr + 3);
    return (((((value3 << 8) + value2) << 8) + value1) << 8) + value0;
}

void LockPlayerFieldControls(void)
{
    sLockFieldControls = TRUE;
    EndDexNavSearch();
}

void UnlockPlayerFieldControls(void)
{
    sLockFieldControls = FALSE;
}

bool8 ArePlayerFieldControlsLocked(void)
{
    return sLockFieldControls;
}

// The ScriptContext_* functions work with the primary script context,
// which yields control back to native code should the script make a wait call.

// Checks if the global script context is able to be run right now.
bool8 ScriptContext_IsEnabled(void)
{
    if (sGlobalScriptContextStatus == CONTEXT_RUNNING)
        return TRUE;
    else
        return FALSE;
}

// Re-initializes the global script context to zero.
void ScriptContext_Init(void)
{
    InitScriptContext(&sGlobalScriptContext, gScriptCmdTable, gScriptCmdTableEnd);
    sGlobalScriptContextStatus = CONTEXT_SHUTDOWN;
}

// Runs the script until the script makes a wait* call, then returns true if
// there's more script to run, or false if the script has hit the end.
// This function also returns false if the context is finished
// or waiting (after a call to _Stop)
bool8 ScriptContext_RunScript(void)
{
    if (sGlobalScriptContextStatus == CONTEXT_SHUTDOWN)
        return FALSE;

    if (sGlobalScriptContextStatus == CONTEXT_WAITING)
        return FALSE;

    LockPlayerFieldControls();

    if (!RunScriptCommand(&sGlobalScriptContext))
    {
        sGlobalScriptContextStatus = CONTEXT_SHUTDOWN;
        UnlockPlayerFieldControls();
        return FALSE;
    }

    return TRUE;
}

// Sets up a new script in the global context and enables the context
void ScriptContext_SetupScript(const u8 *ptr)
{
    InitScriptContext(&sGlobalScriptContext, gScriptCmdTable, gScriptCmdTableEnd);
    SetupBytecodeScript(&sGlobalScriptContext, ptr);
    LockPlayerFieldControls();
    if (OW_FOLLOWERS_SCRIPT_MOVEMENT)
        FlagSet(FLAG_SAFE_FOLLOWER_MOVEMENT);
    sGlobalScriptContextStatus = CONTEXT_RUNNING;
}

// Moves a script from a local context to the global context and enables it.
void ScriptContext_ContinueScript(struct ScriptContext *ctx)
{
    sGlobalScriptContext = *ctx;
    LockPlayerFieldControls();
    sGlobalScriptContextStatus = CONTEXT_RUNNING;
}

// Puts the script into waiting mode; usually called from a wait* script command.
void ScriptContext_Stop(void)
{
    sGlobalScriptContextStatus = CONTEXT_WAITING;
}

// Puts the script into running mode.
void ScriptContext_Enable(void)
{
    sGlobalScriptContextStatus = CONTEXT_RUNNING;
    LockPlayerFieldControls();
}

// Sets up and runs a script in its own context immediately. The script will be
// finished when this function returns. Used mainly by all of the map header
// scripts (except the frame table scripts).
void RunScriptImmediately(const u8 *ptr)
{
    InitScriptContext(&sImmediateScriptContext, gScriptCmdTable, gScriptCmdTableEnd);
    SetupBytecodeScript(&sImmediateScriptContext, ptr);
    while (RunScriptCommand(&sImmediateScriptContext) == TRUE);
}

const u8 *MapHeaderGetScriptTable(u8 tag)
{
    const u8 *mapScripts = gMapHeader.mapScripts;

    if (!mapScripts)
        return NULL;

    while (1)
    {
        if (!*mapScripts)
            return NULL;
        if (*mapScripts == tag)
        {
            mapScripts++;
            return T2_READ_PTR(mapScripts);
        }
        mapScripts += 5;
    }
}

void MapHeaderRunScriptType(u8 tag)
{
    const u8 *ptr = MapHeaderGetScriptTable(tag);
    if (ptr)
        RunScriptImmediately(ptr);
}

const u8 *MapHeaderCheckScriptTable(u8 tag)
{
    const u8 *ptr = MapHeaderGetScriptTable(tag);

    if (!ptr)
        return NULL;

    while (1)
    {
        u16 varIndex1;
        u16 varIndex2;

        // Read first var (or .2byte terminal value)
        varIndex1 = T1_READ_16(ptr);
        if (!varIndex1)
            return NULL; // Reached end of table
        ptr += 2;

        // Read second var
        varIndex2 = T1_READ_16(ptr);
        ptr += 2;

        // Run map script if vars are equal
        if (VarGet(varIndex1) == VarGet(varIndex2))
        {
            const u8 *mapScript = T2_READ_PTR(ptr);
            if (!Script_HasNoEffect(mapScript))
                return mapScript;
        }

        ptr += 4;
    }
}

void RunOnLoadMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_LOAD);
}

void RunOnTransitionMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_TRANSITION);
}

void RunOnResumeMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_RESUME);
}

void RunOnReturnToFieldMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_RETURN_TO_FIELD);
}

void RunOnDiveWarpMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_DIVE_WARP);
}

bool8 TryRunOnFrameMapScript(void)
{
    const u8 *ptr = MapHeaderCheckScriptTable(MAP_SCRIPT_ON_FRAME_TABLE);

    if (!ptr)
        return FALSE;

    ScriptContext_SetupScript(ptr);
    return TRUE;
}

void TryRunOnWarpIntoMapScript(void)
{
    const u8 *ptr = MapHeaderCheckScriptTable(MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE);
    if (ptr)
        RunScriptImmediately(ptr);
}

u32 CalculateRamScriptChecksum(void)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    return CalcCRC16WithTable((u8 *)(&gSaveBlock1Ptr->ramScript.data), sizeof(gSaveBlock1Ptr->ramScript.data));
#else
    return 0;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

void ClearRamScript(void)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    CpuFill32(0, &gSaveBlock1Ptr->ramScript, sizeof(struct RamScript));
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

bool8 InitRamScript(const u8 *script, u16 scriptSize, u8 mapGroup, u8 mapNum, u8 localId)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;

    ClearRamScript();

    if (scriptSize > sizeof(scriptData->script))
        return FALSE;

    scriptData->magic = RAM_SCRIPT_MAGIC;
    scriptData->mapGroup = mapGroup;
    scriptData->mapNum = mapNum;
    scriptData->localId = localId;
    memcpy(scriptData->script, script, scriptSize);
    gSaveBlock1Ptr->ramScript.checksum = CalculateRamScriptChecksum();
    return TRUE;
#else
    return FALSE;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

const u8 *GetRamScript(u8 localId, const u8 *script)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    gRamScriptRetAddr = NULL;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return script;
    if (scriptData->mapGroup != gSaveBlock1Ptr->location.mapGroup)
        return script;
    if (scriptData->mapNum != gSaveBlock1Ptr->location.mapNum)
        return script;
    if (scriptData->localId != localId)
        return script;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
    {
        ClearRamScript();
        return script;
    }
    else
    {
        gRamScriptRetAddr = script;
        return scriptData->script;
    }
#else
    return script;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

#define NO_OBJECT LOCALID_PLAYER

bool32 ValidateSavedRamScript(void)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return FALSE;
    if (scriptData->mapGroup != MAP_GROUP(MAP_UNDEFINED))
        return FALSE;
    if (scriptData->mapNum != MAP_NUM(MAP_UNDEFINED))
        return FALSE;
    if (scriptData->localId != NO_OBJECT)
        return FALSE;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
        return FALSE;
    return TRUE;
#else
    return FALSE;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

u8 *GetSavedRamScriptIfValid(void)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    if (!ValidateSavedWonderCard())
        return NULL;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return NULL;
    if (scriptData->mapGroup != MAP_GROUP(MAP_UNDEFINED))
        return NULL;
    if (scriptData->mapNum != MAP_NUM(MAP_UNDEFINED))
        return NULL;
    if (scriptData->localId != NO_OBJECT)
        return NULL;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
    {
        ClearRamScript();
        return NULL;
    }
    else
    {
        return scriptData->script;
    }
#else
    return NULL;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

void InitRamScript_NoObjectEvent(u8 *script, u16 scriptSize)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    if (scriptSize > sizeof(gSaveBlock1Ptr->ramScript.data.script))
        scriptSize = sizeof(gSaveBlock1Ptr->ramScript.data.script);
    InitRamScript(script, scriptSize, MAP_GROUP(MAP_UNDEFINED), MAP_NUM(MAP_UNDEFINED), NO_OBJECT);
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

bool8 LoadTrainerObjectScript(void)
{
    sGlobalScriptContext.scriptPtr = gApproachingTrainers[gNoOfApproachingTrainers - 1].trainerScriptPtr;
    return TRUE;
}

struct ScriptEffectContext {
    u32 breakOn;
    intptr_t breakTo[5];
    const u8 *nextCmd;
};

struct ScriptEffectContext *gScriptEffectContext = NULL;

static bool32 Script_IsEffectInstrumentedCommand(ScrCmdFunc func)
{
    // In ROM mirror 1.
    return (((uintptr_t)func) & 0xE000000) == 0xA000000;
}

/* 'setjmp' and 'longjmp' cause link errors, so we use
 * '__builtin_setjmp' and '__builtin_longjmp' instead.
 * See https://gcc.gnu.org/onlinedocs/gcc/Nonlocal-Gotos.html */
static bool32 RunScriptImmediatelyUntilEffect_InternalLoop(struct ScriptContext *ctx)
{
    if (__builtin_setjmp(gScriptEffectContext->breakTo) == 0)
    {
        while (TRUE)
        {
            u32 cmdCode;
            ScrCmdFunc *func;

            gScriptEffectContext->nextCmd = ctx->scriptPtr;

            if (!ctx->scriptPtr)
                return FALSE;

            cmdCode = *ctx->scriptPtr;
            ctx->scriptPtr++;
            func = &ctx->cmdTable[cmdCode];

            // Invalid script command.
            if (func >= ctx->cmdTableEnd)
                return TRUE;

            if (!Script_IsEffectInstrumentedCommand(*func))
                return TRUE;

            // Command which waits for a frame.
            if ((*func)(ctx))
            {
                gScriptEffectContext->nextCmd = ctx->scriptPtr;
                return TRUE;
            }
        }
    }
    else
    {
        return TRUE;
    }
}

void Script_GotoBreak_Internal(void)
{
    __builtin_longjmp(gScriptEffectContext->breakTo, 1);
}

bool32 RunScriptImmediatelyUntilEffect_Internal(u32 effects, const u8 *ptr, struct ScriptContext *ctx)
{
    bool32 result;
    struct ScriptEffectContext seCtx;
    seCtx.breakOn = effects & 0x7FFFFFFF;

    if (ctx == NULL)
        ctx = &sImmediateScriptContext;

    InitScriptContext(ctx, gScriptCmdTable, gScriptCmdTableEnd);
    if (effects & SCREFF_TRAINERBATTLE)
        ctx->breakOnTrainerBattle = TRUE;
    SetupBytecodeScript(ctx, ptr);

    rng_value_t rngValue = gRngValue;
    gScriptEffectContext = &seCtx;
    result = RunScriptImmediatelyUntilEffect_InternalLoop(ctx);
    gScriptEffectContext = NULL;
    gRngValue = rngValue;

    if (result)
        ctx->scriptPtr = seCtx.nextCmd;

    return result;
}

bool32 Script_HasNoEffect(const u8 *ptr)
{
    return !RunScriptImmediatelyUntilEffect(SCREFF_V1 | SCREFF_SAVE | SCREFF_HARDWARE, ptr, NULL);
}

void Script_RequestEffects_Internal(u32 effects)
{
    if (gScriptEffectContext->breakOn & effects)
        __builtin_longjmp(gScriptEffectContext->breakTo, 1);
}

void Script_RequestWriteVar_Internal(u32 varId)
{
    if (varId == 0)
        return;
    if (SPECIAL_VARS_START <= varId && varId <= SPECIAL_VARS_END)
        return;
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
}

bool32 Script_MatchesCallNative(const u8 *script, void *funcPtr, bool32 requestEffects)
{
    if (script[0] != SCR_OP_CALLNATIVE)
        return FALSE;
    u32 callnativeFunc = (((((script[4] << 8) + script[3]) << 8) + script[2]) << 8) + script[1];
    u32 targetFunc = (u32)funcPtr;
    if (requestEffects)
        targetFunc |= 0xA000000;
    if (callnativeFunc == targetFunc)
        return TRUE;
    return FALSE;
}

bool32 Script_MatchesSpecial(const u8 *script, void *funcPtr)
{
    if (script[0] != SCR_OP_SPECIAL)
        return FALSE;
    typedef u16 (*SpecialFunc)(void);
    extern const SpecialFunc gSpecials[];
    SpecialFunc specialFunc = gSpecials[(script[2] << 8) + script[1]];
    if ((u32)specialFunc == ((u32)funcPtr))
        return TRUE;
    return FALSE;
}

// FRLG
void DisableMsgBoxWalkaway(void)
{
    // sMsgBoxWalkawayDisabled = TRUE;
}

void SetWalkingIntoSignVars(void)
{
    // gWalkAwayFromSignInhibitTimer = 6;
    // sMsgBoxIsCancelable = TRUE;
}

// DW Scripts Start

const u8 gText_Name_Barry[] = _("Barry");

void EnterRivalName(void)
{
    StringCopy(gSaveBlock1Ptr->rivalName, gText_Name_Barry);
    
    DoNamingScreen(NAMING_SCREEN_RIVAL, gSaveBlock1Ptr->rivalName, 0, 0, 0, CB2_ReturnToFieldContinueScript);
}

const u8 gText_Letter_O[] = _("o");
const u8 gText_Letter_A[] = _("a");

void CheckGenderString(void)
{
    u8 gender = gPlayerAvatar.gender;

    StringCopy(gStringVar1, (gender == MALE) ? gText_Letter_O : gText_Letter_A);
}

void GetMapTVScript(void)
{
    gSpecialVar_Result = 0;

    if (MAP_IS(MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F)) {
        gSpecialVar_Result = 1;
    }
    else if (MAP_IS(MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F)) {
        gSpecialVar_Result = 2;
    }
}

static const struct OamData sSparkleOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = ST_OAM_SIZE_2,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSparkleAnim0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(80, 5),
    ANIMCMD_END,
};

static const union AffineAnimCmd sSparkleAffineAnim0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(4, 4, 8, 30),
    AFFINEANIMCMD_END,
};

static const union AnimCmd *const sSparkleAnimTable[] =
{
    sSparkleAnim0,
};

static const union AffineAnimCmd *const sSparkleAffineAnimTable[] =
{
    sSparkleAffineAnim0,
};

static const struct SpriteSheet sSparkleTileData =
{
    .data = gSprite_SparkleGfx,
    .size = (192 * 32) / 2,
    .tag = 12,
};

static const struct SpritePalette sSparklePalData =
{
    .data = gSprite_SparklePal,
    .tag = 12,
};

static const struct SpriteTemplate sSparkleTemplate =
{
    .tileTag = 12,
    .paletteTag = 12,
    .oam = &sSparkleOamData,
    .anims = sSparkleAnimTable,
    .images = NULL,
    .affineAnims = sSparkleAffineAnimTable,
    .callback = SpriteCB_Sparkle,
};

static void SpriteCB_Sparkle(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroySprite(sprite);
    FreeSpritePaletteByTag(12);
    FreeSpriteTilesByTag(12);
}

void CreateStarterSparkle(u8 localId)
{
    u16 objId = GetObjectEventIdByLocalId(localId);
    if (objId == OBJECT_EVENTS_COUNT) return;

    u16 spriteId = gObjectEvents[objId].spriteId;
    u16 x = gSprites[spriteId].x - 16;
    u16 y = gSprites[spriteId].y - 10;

    LoadSpriteSheet(&sSparkleTileData);
    LoadSpritePalette(&sSparklePalData);

    u8 sparkleId = CreateSprite(&sSparkleTemplate, x, y, 0);
    if (sparkleId != MAX_SPRITES)
    {
        gSprites[sparkleId].data[0] = 0;
        gSprites[sparkleId].centerToCornerVecX = 0;
        gSprites[sparkleId].centerToCornerVecY = 0;
        gSprites[sparkleId].coordOffsetEnabled = TRUE;
    }
}

u16 GetGrassStarterSprite(void)
{
    switch (gSpecialVar_0x8000)
    {
        case 0: return OBJ_EVENT_GFX_SPECIES(BULBASAUR);   // Gen 1
        case 1: return OBJ_EVENT_GFX_SPECIES(CHIKORITA);   // Gen 2
        case 2: return OBJ_EVENT_GFX_SPECIES(TREECKO);     // Gen 3
        case 3: return OBJ_EVENT_GFX_SPECIES(TURTWIG);     // Gen 4
        case 4: return OBJ_EVENT_GFX_SPECIES(SNIVY);       // Gen 5
        case 5: return OBJ_EVENT_GFX_SPECIES(CHESPIN);     // Gen 6
        case 6: return OBJ_EVENT_GFX_SPECIES(ROWLET);      // Gen 7
        case 7: return OBJ_EVENT_GFX_SPECIES(GROOKEY);     // Gen 8
        case 8: return OBJ_EVENT_GFX_SPECIES(SPRIGATITO);  // Gen 9

        default:
            return OBJ_EVENT_GFX_POKE_BALL;
    }
}

u16 GetFireStarterSprite(void)
{
    switch (gSpecialVar_0x8000)
    {
        case 0: return OBJ_EVENT_GFX_SPECIES(CHARMANDER); // Gen 1
        case 1: return OBJ_EVENT_GFX_SPECIES(CYNDAQUIL);  // Gen 2
        case 2: return OBJ_EVENT_GFX_SPECIES(TORCHIC);    // Gen 3
        case 3: return OBJ_EVENT_GFX_SPECIES(CHIMCHAR);   // Gen 4
        case 4: return OBJ_EVENT_GFX_SPECIES(TEPIG);      // Gen 5
        case 5: return OBJ_EVENT_GFX_SPECIES(FENNEKIN);   // Gen 6
        case 6: return OBJ_EVENT_GFX_SPECIES(LITTEN);     // Gen 7
        case 7: return OBJ_EVENT_GFX_SPECIES(SCORBUNNY);  // Gen 8
        case 8: return OBJ_EVENT_GFX_SPECIES(FUECOCO);    // Gen 9

        default:
            return OBJ_EVENT_GFX_POKE_BALL;
    }
}

u16 GetWaterStarterSprite(void)
{
    switch (gSpecialVar_0x8000)
    {
        case 0: return OBJ_EVENT_GFX_SPECIES(SQUIRTLE);  // Gen 1
        case 1: return OBJ_EVENT_GFX_SPECIES(TOTODILE);  // Gen 2
        case 2: return OBJ_EVENT_GFX_SPECIES(MUDKIP);    // Gen 3
        case 3: return OBJ_EVENT_GFX_SPECIES(PIPLUP);    // Gen 4
        case 4: return OBJ_EVENT_GFX_SPECIES(OSHAWOTT);  // Gen 5
        case 5: return OBJ_EVENT_GFX_SPECIES(FROAKIE);   // Gen 6
        case 6: return OBJ_EVENT_GFX_SPECIES(POPPLIO);   // Gen 7
        case 7: return OBJ_EVENT_GFX_SPECIES(SOBBLE);    // Gen 8
        case 8: return OBJ_EVENT_GFX_SPECIES(QUAXLY);    // Gen 9

        default:
            return OBJ_EVENT_GFX_POKE_BALL;
    }
}

void CreateGrassStarterEventObject(void)
{
    u16 sprite = GetGrassStarterSprite();

    if (sprite == 0)
        return;

    struct ObjectEventTemplate obj =
    {
        .localId = LOCALID_LAB_BALL_1,
        .graphicsId = sprite,
        .kind = OBJ_KIND_NORMAL,
        .x = 1,
        .y = 4,
        .elevation = 3,
        .movementType = MOVEMENT_TYPE_WALK_IN_PLACE_DOWN,
        .movementRangeX = 0,
        .movementRangeY = 0,
        .trainerType = 0,
        .trainerRange_berryTreeId = 0,
        .script = NULL,
        .flagId = 0,
    };
    
    SpawnSpecialObjectEvent(&obj);
}

void CreateFireStarterEventObject(void)
{
    u16 sprite = GetFireStarterSprite();

    if (sprite == 0)
        return;

    struct ObjectEventTemplate obj =
    {
        .localId = LOCALID_LAB_BALL_2,
        .graphicsId = sprite,
        .kind = OBJ_KIND_NORMAL,
        .x = 2,
        .y = 4,
        .elevation = 3,
        .movementType = MOVEMENT_TYPE_WALK_IN_PLACE_DOWN,
        .movementRangeX = 0,
        .movementRangeY = 0,
        .trainerType = 0,
        .trainerRange_berryTreeId = 0,
        .script = NULL,
        .flagId = 0,
    };
    
    SpawnSpecialObjectEvent(&obj);
}

void CreateWaterStarterEventObject(void)
{
    u16 sprite = GetWaterStarterSprite();

    if (sprite == 0)
        return;

    struct ObjectEventTemplate obj =
    {
        .localId = LOCALID_LAB_BALL_3,
        .graphicsId = sprite,
        .kind = OBJ_KIND_NORMAL,
        .x = 3,
        .y = 4,
        .elevation = 3,
        .movementType = MOVEMENT_TYPE_WALK_IN_PLACE_DOWN,
        .movementRangeX = 0,
        .movementRangeY = 0,
        .trainerType = 0,
        .trainerRange_berryTreeId = 0,
        .script = NULL,
        .flagId = 0,
    };
    
    SpawnSpecialObjectEvent(&obj);
}

void ShowMonInsidePokeball(void)
{
    u16 map = MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB;

    RemoveObjectEventByLocalIdAndMap(LOCALID_LAB_BALL_1, MAP_NUM(map), MAP_GROUP(map));
    RemoveObjectEventByLocalIdAndMap(LOCALID_LAB_BALL_2, MAP_NUM(map), MAP_GROUP(map));
    RemoveObjectEventByLocalIdAndMap(LOCALID_LAB_BALL_3, MAP_NUM(map), MAP_GROUP(map));

    CreateGrassStarterEventObject();
    CreateFireStarterEventObject();
    CreateWaterStarterEventObject();

    CreateStarterSparkle(LOCALID_LAB_BALL_1);
    CreateStarterSparkle(LOCALID_LAB_BALL_2);
    CreateStarterSparkle(LOCALID_LAB_BALL_3);
}

const u8 gText_LabKanto[]  = _("KANTO");
const u8 gText_LabJohto[]  = _("JOHTO");
const u8 gText_LabHoenn[]  = _("HOENN");
const u8 gText_LabSinnoh[] = _("SINNOH");
const u8 gText_LabUnova[]  = _("UNOVA");
const u8 gText_LabKalos[]  = _("KALOS");
const u8 gText_LabAlola[]  = _("ALOLA");
const u8 gText_LabGalar[]  = _("GALAR");
const u8 gText_LabPaldea[] = _("PALDEA");
const u8 gText_LabUnknown[] = _("UNKNOWN");

const u8 *GetRegionNameIntoLab(void)
{
    if (FlagGet(FLAG_STARTER_KANTO))
        return gText_LabKanto;
    else if (FlagGet(FLAG_STARTER_JOHTO))
        return gText_LabJohto;
    else if (FlagGet(FLAG_STARTER_HOENN))
        return gText_LabHoenn;
    else if (FlagGet(FLAG_STARTER_SINNOH))
        return gText_LabSinnoh;
    else if (FlagGet(FLAG_STARTER_UNOVA))
        return gText_LabUnova;
    else if (FlagGet(FLAG_STARTER_KALOS))
        return gText_LabKalos;
    else if (FlagGet(FLAG_STARTER_ALOLA))
        return gText_LabAlola;
    else if (FlagGet(FLAG_STARTER_GALAR))
        return gText_LabGalar;
    else if (FlagGet(FLAG_STARTER_PALDEA))
        return gText_LabPaldea;

    return gText_LabUnknown;
}

void SetHikariLabRegionName(void)
{
    const u8 *name = GetRegionNameIntoLab();
    StringCopy(gStringVar1, name);
}

#define tState        data[0]
#define tSpecies      data[1]
#define tSpriteId     data[2]
#define tWindowId     data[5]

bool8 ShowMonMugshot(u16 species, u8 position)
{
    struct Pokemon* mon = &gPlayerParty[0];
    bool8 isShiny = IsMonShiny(mon);
    u8 spriteId;
    u8 taskId;
	
	u8 x = 0;
	u8 y = 0;

	if (position == MUGSHOT_CENTER)
	{
		x = 10;
		y = 3;
	}
    else if (position == MUGSHOT_DOWN_LEFT)
    {
        x = 18;
		y = 6;
    }

    if (FindTaskIdByFunc(Task_PokemonPicWindow) != TASK_NONE)
	{
        return FALSE;
	}
    else
    {
        if (isShiny == TRUE && FlagGet(FLAG_SYS_POKEMON_GET))
            spriteId = CreateMonSprite_PicBox2(species, TRUE, 8 * x + 40, 8 * y + 40, 0);
        else
            spriteId = CreateMonSprite_PicBox2(species, FALSE, 8 * x + 40, 8 * y + 40, 0);
        taskId = CreateTask(Task_PokemonPicWindow, 80);

        gTasks[taskId].tState = 0;
        gTasks[taskId].tSpecies = species;
        gTasks[taskId].tSpriteId = spriteId;
        gSprites[spriteId].callback = SpriteCB_ShakePokemonPic;
        gSprites[spriteId].oam.priority = 0;
        ScheduleBgCopyTilemapToVram(0);
        if (!FlagGet(FLAG_OBTAIN_EGG))
            PlayCry_Normal(species, 0);
        return TRUE;
    }
}

void RemoveMonMugshot(void)
{
    u8 taskId = FindTaskIdByFunc(Task_PokemonPicWindow);
    
    if (taskId != TASK_NONE)
    {
        u8 spriteId = gTasks[taskId].tSpriteId;

        if (spriteId < MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[spriteId];

            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
            FreeSpriteTiles(sprite);
            FreeSpritePalette(sprite);
        }
        DestroyTask(taskId);
    }
}

static const union AffineAnimCmd sAffineAnim_ShakePokemon[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 128, 1), //Start rotated left
	AFFINEANIMCMD_FRAME(16, 16, -8, 16), //Double sprite size + rotate right
	AFFINEANIMCMD_FRAME(0, 0, -3, 8), //End at right 24
	AFFINEANIMCMD_FRAME(0, 0, 3, 16), //End at left 24
	AFFINEANIMCMD_FRAME(0, 0, -3, 16), //End at right 24
	AFFINEANIMCMD_FRAME(0, 0, 3, 16), //End at left 24
	AFFINEANIMCMD_FRAME(0, 0, -3, 8), //End at 0
	AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sAffineAnimTable_ShakePokemon[] =
{
    sAffineAnim_ShakePokemon,
};

void StartShakeAffineAnimForPokemon(struct Sprite* sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
    sprite->oam.matrixNum = AllocOamMatrix();
    sprite->affineAnims = sAffineAnimTable_ShakePokemon;
    StartSpriteAffineAnim(sprite, 0);
}

void SpriteCB_ShakePokemonPic(struct Sprite *sprite)
{
	if (FlagGet(FLAG_OBTAIN_EGG))
	{
		StartShakeAffineAnimForPokemon(sprite);
		sprite->callback = SpriteCallbackDummy;
	}
	else
	{
		if (sprite->data[0] < 30)
		{
			sprite->x2 = (sprite->data[0] % 6) - 3;
			sprite->data[0]++;
		}
		else
		{
			sprite->x2 = 0;
			sprite->callback = SpriteCallbackDummy;
		}
	}
}

u8 CreateMonSprite_PicBox2(u16 species, bool8 isShiny, s16 x, s16 y, u8 subpriority)
{
    s32 spriteId = CreateMonPicSprite(species, isShiny, 0x8000, TRUE, x, y, 0, species);
    PreservePaletteInWeather(IndexOfSpritePaletteTag(species) + 0x10);
    if (spriteId == 0xFFFF)
        return MAX_SPRITES;
    else
        return spriteId;
}

const u8 gText_TypeGrass[] = _("Grass-Type");
const u8 gText_TypeFire[] = _("Fire-Type");
const u8 gText_TypeWater[] = _("Water-Type");
const u8 gText_TypeGrama[] = _("Tipo Grama");
const u8 gText_TypeFogo[] = _("Tipo Fogo");
const u8 gText_TypeAgua[] = _("Tipo Água");
const u8 gText_TypePlanta[] = _("Tipo Planta");
const u8 gText_TypeFuego[]  = _("Tipo Fuego");
const u8 gText_TypeAguaEs[] = _("Tipo Agua");

const u8 *const gTypeNames[3][3] =
{
    { gText_TypeGrama, gText_TypeGrass, gText_TypePlanta },
    { gText_TypeFogo,  gText_TypeFire,  gText_TypeFuego  },
    { gText_TypeAgua,  gText_TypeWater, gText_TypeAguaEs }
};

void BufferTypeName(void)
{
    u8 typeVar = VarGet(VAR_STORE_FIST_MON_TYPE);
    u8 langVar = VarGet(VAR_LANGUAGE);

    u8 typeIndex;

    switch (typeVar)
    {
        case TYPE_GRASS: typeIndex = 0; break;
        case TYPE_FIRE:  typeIndex = 1; break;
        case TYPE_WATER: typeIndex = 2; break;
        default:         typeIndex = 0; break;
    }

    if (langVar > 2)
        langVar = EN; // fallback

    StringCopy(gStringVar1, gTypeNames[typeIndex][langVar]);
}
// DW Scripts End
