#include "global.h"
#include "config/save.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "bg.h"
#include "debug.h"
#include "decompress.h"
#include "dppt_start_menu.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "frontier_pass.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "item_use.h"
#include "list_menu.h"
#include "link.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "new_game.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "pokenav.h"
#include "rtc.h"
#include "safari_zone.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "start_menu.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "window.h"
#include "union_room.h"
#include "dexnav.h"
#include "wild_encounter.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// Menu actions
enum
{
    MENU_ACTION_POKEDEX,
    MENU_ACTION_POKEMON,
    MENU_ACTION_BAG,
    MENU_ACTION_POKENAV,
    MENU_ACTION_PLAYER,
    MENU_ACTION_SAVE,
    MENU_ACTION_OPTION,
    MENU_ACTION_EXIT,
    MENU_ACTION_RETIRE_SAFARI,
    MENU_ACTION_PLAYER_LINK,
    MENU_ACTION_REST_FRONTIER,
    MENU_ACTION_RETIRE_FRONTIER,
    MENU_ACTION_PYRAMID_BAG,
    MENU_ACTION_DEBUG,
    MENU_ACTION_DEXNAV,
};

// Save status
enum
{
    SAVE_IN_PROGRESS,
    SAVE_SUCCESS,
    SAVE_CANCELED,
    SAVE_ERROR
};

#define START_MENU_MAX_VISIBLE_ACTIONS 7
#define TAG_START_MENU_SCROLL_ARROW 1262

// IWRAM common
COMMON_DATA bool8 (*gMenuCallback)(void) = NULL;

// EWRAM
EWRAM_DATA static u8 sSafariBallsWindowId = 0;
EWRAM_DATA static u8 sBattlePyramidFloorWindowId = 0;
EWRAM_DATA static u8 sStartMenuCursorPos = 0;
EWRAM_DATA static u8 sNumStartMenuActions = 0;
EWRAM_DATA static u16 sStartMenuScrollOffset = 0;
EWRAM_DATA static u8 sStartMenuScrollArrowTaskId = 0;
EWRAM_DATA static bool8 sStartMenuScrollArrowsActive = FALSE;
EWRAM_DATA static u8 sCurrentStartMenuActions[9] = {0};
EWRAM_DATA static s8 sInitStartMenuData[2] = {0};

EWRAM_DATA static u8 (*sSaveDialogCallback)(void) = NULL;
EWRAM_DATA static u8 sSaveDialogTimer = 0;
EWRAM_DATA static bool8 sSavingComplete = FALSE;
EWRAM_DATA static u8 sSaveInfoWindowId = 0;
EWRAM_DATA static u8 sSavePartyIconSpriteIds[PARTY_SIZE] = {};
EWRAM_DATA static bool8 sSavePartyIconsActive = FALSE;
EWRAM_DATA static u8 sSelectorSpriteIds[2];
EWRAM_DATA static u8 sSpriteIds[8];
EWRAM_DATA static u8 sSpriteIdCount;
EWRAM_DATA static u8 sStartClockWindowId = 0;
EWRAM_DATA static bool8 sStartClockWindowActive = FALSE;

// Menu action callbacks
static bool8 StartMenuPokedexCallback(void);
static bool8 StartMenuPokemonCallback(void);
static bool8 StartMenuBagCallback(void);
static bool8 StartMenuPokeNavCallback(void);
static bool8 StartMenuPlayerNameCallback(void);
static bool8 StartMenuSaveCallback(void);
static bool8 StartMenuOptionCallback(void);
static bool8 StartMenuExitCallback(void);
static bool8 StartMenuSafariZoneRetireCallback(void);
static bool8 StartMenuLinkModePlayerNameCallback(void);
static bool8 StartMenuBattlePyramidRetireCallback(void);
static bool8 StartMenuBattlePyramidBagCallback(void);
static bool8 StartMenuDebugCallback(void);
static bool8 StartMenuDexNavCallback(void);

// Menu callbacks
static bool8 SaveStartCallback(void);
static bool8 SaveCallback(void);
static bool8 BattlePyramidRetireStartCallback(void);
static bool8 BattlePyramidRetireReturnCallback(void);
static bool8 BattlePyramidRetireCallback(void);
static bool8 HandleStartMenuInput(void);

// Save dialog callbacks
static u8 SaveConfirmSaveCallback(void);
static u8 SaveYesNoCallback(void);
static u8 SaveConfirmInputCallback(void);
static u8 SaveFileExistsCallback(void);
static u8 SaveConfirmOverwriteDefaultNoCallback(void);
static u8 SaveConfirmOverwriteCallback(void);
static u8 SaveOverwriteInputCallback(void);
static u8 SaveSavingMessageCallback(void);
static u8 SaveDoSaveCallback(void);
static u8 SaveSuccessCallback(void);
static u8 SaveReturnSuccessCallback(void);
static u8 SaveErrorCallback(void);
static u8 SaveReturnErrorCallback(void);
static u8 BattlePyramidConfirmRetireCallback(void);
static u8 BattlePyramidRetireYesNoCallback(void);
static u8 BattlePyramidRetireInputCallback(void);
static void ShowTimeWindow(void);
static void RemoveTimeWindow(void);

// Task callbacks
static void StartMenuTask(u8 taskId);
static void SaveGameTask(u8 taskId);
static void Task_SaveAfterLinkBattle(u8 taskId);
static void Task_WaitForBattleTowerLinkSave(u8 taskId);
static bool8 FieldCB_ReturnToFieldStartMenu(void);

#if DPPT_START_MENU == TRUE
// NEW!
// Config
#define DPPT_START_MENU_DISABLE_EXIT TRUE // This is required to fit everything on screen if every action is on screen at once.
                                          // While multi-page start screen implementation is not included here, it should be pretty simple to make your own compatible with this menu.

// Sprites
// A lot of this sprite defining code is referenced from Voluptua's start menu, credits to him: https://github.com/Voluptua/pokeemerald/blob/start_menu_1/src/heat_start_menu.c
static void SpriteCB_Pokedex(struct Sprite *sprite);
static void SpriteCB_Pokeball(struct Sprite *sprite);
static void SpriteCB_Bag(struct Sprite *sprite);
static void SpriteCB_Pokenav(struct Sprite *sprite);
static void SpriteCB_Dexnav(struct Sprite *sprite);
static void SpriteCB_TrainerCard(struct Sprite *sprite);
static void SpriteCB_Save(struct Sprite *sprite);
static void SpriteCB_Options(struct Sprite *sprite);
static void SpriteCB_Cancel(struct Sprite *sprite);
static void SpriteCB_Retire(struct Sprite *sprite);
static void LoadStartMenuGfx(void);
static void DestroyStartMenuGfx(void);

//--SPRITE-GFX--
#define TAG_SELECTOR_GFX           1251
#define TAG_POKEBALL_GFX           1252
#define TAG_POKEDEX_GFX            1253
#define TAG_BAG_GFX                1254
#define TAG_POKENAV_GFX            1255
#define TAG_TRAINER_CARD_GFX       1256
#define TAG_SAVE_GFX               1257
#define TAG_OPTIONS_GFX            1258
#define TAG_CANCEL_GFX             1259
#define TAG_RETIRE_GFX             1260
#define TAG_DEXNAV_GFX             1261
#define TAG_MENU_PAL               (BLEND_IMMUNE_FLAG | 0x4650)

static const u32 sSelector_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/selector.4bpp.lz");
static const u16 sMenu_Pal[] = INCBIN_U16("graphics/dppt_start_menu/menu.gbapal");

static const u32 sPokeball_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/pokeball.4bpp.lz");
static const u32 sPokedex_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/pokedex.4bpp.lz");
static const u32 sBag_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/bag.4bpp.lz");
static const u32 sPokenav_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/pokenav.4bpp.lz");
static const u32 sDexnav_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/dexnav.4bpp.lz");
static const u32 sTrainerCard_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/trainer_card.4bpp.lz");
static const u32 sSave_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/save.4bpp.lz");
static const u32 sOptions_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/options.4bpp.lz");
static const u32 sCancel_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/cancel.4bpp.lz");
static const u32 sRetire_Gfx[] = INCBIN_U32("graphics/dppt_start_menu/retire.4bpp.lz");

static const struct OamData sOamData_Selector =
{
    .size = SPRITE_SIZE(64x32),
    .shape = SPRITE_SHAPE(64x32),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_Selector =
{
    .data = sSelector_Gfx,
    .size = 64*32*4/2,
    .tag = TAG_SELECTOR_GFX,
};

static const struct SpritePalette sSpritePal_Selector =
{
    .data = sMenu_Pal,
    .tag = TAG_MENU_PAL
};

static const union AnimCmd sSpriteAnim_Selector[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_Selector[] =
{
    sSpriteAnim_Selector,
};

static const struct SpriteTemplate sSpriteTemplate_Selector =
{
    .tileTag = TAG_SELECTOR_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Selector,
    .anims = sSpriteAnimTable_Selector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct CompressedSpriteSheet sSpriteSheet_PokeballIcon[] = 
{
    {sPokeball_Gfx, 32*64/2 , TAG_POKEBALL_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_PokedexIcon[] = 
{
    {sPokedex_Gfx, 32*64/2 , TAG_POKEDEX_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_BagIcon[] = 
{
    {sBag_Gfx, 32*64/2 , TAG_BAG_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_PokenavIcon[] = 
{
    {sPokenav_Gfx, 32*64/2 , TAG_POKENAV_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_DexnavIcon[] = 
{
    {sDexnav_Gfx, 32*64/2 , TAG_DEXNAV_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_TrainerCardIcon[] = 
{
    {sTrainerCard_Gfx, 32*64/2 , TAG_TRAINER_CARD_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_SaveIcon[] = 
{
    {sSave_Gfx, 32*64/2 , TAG_SAVE_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_OptionsIcon[] = 
{
    {sOptions_Gfx, 32*64/2 , TAG_OPTIONS_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_CancelIcon[] = 
{
    {sCancel_Gfx, 32*64/2 , TAG_CANCEL_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_RetireIcon[] = 
{
    {sRetire_Gfx, 32*64/2 , TAG_RETIRE_GFX},
    {NULL},
};

static const struct OamData sOamData_Icon = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const union AnimCmd sSpriteAnim_Icon_Grey[] = {
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_Icon_Default[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_Icon[] = {
    sSpriteAnim_Icon_Grey,
    sSpriteAnim_Icon_Default,
};

static const union AffineAnimCmd sSpriteAffineAnim_IconNone[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 60),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_Icon[] =
{
    AFFINEANIMCMD_FRAME(12, 12, 0, 8),
    AFFINEANIMCMD_FRAME(-12, -12, 0, 8),
    // This is taken from Voluptua's start menu, huge credits to him: https://github.com/Voluptua/pokeemerald/blob/start_menu_1/src/heat_start_menu.c#L358
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),      // Begin rotating

    AFFINEANIMCMD_FRAME(0, 0, -1, 4),     // Loop starts from here ; Rotate/Tilt left 
    AFFINEANIMCMD_FRAME(0, 0, 0, 2),
    AFFINEANIMCMD_FRAME(0, 0, -1, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 2),
    AFFINEANIMCMD_FRAME(0, 0, -1, 4),

    AFFINEANIMCMD_FRAME(0, 0, 1, 4),      // Rotate/Tilt Right
    AFFINEANIMCMD_FRAME(0, 0, 0, 2),
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 2),
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),

    AFFINEANIMCMD_JUMP(3),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnimCmds_Icon[] =
{   
    sSpriteAffineAnim_IconNone,
    sSpriteAffineAnim_Icon,
};

static const struct SpriteTemplate sSpriteTemplate_Pokeball = {
    .tileTag = TAG_POKEBALL_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_Pokeball,
};

static const struct SpriteTemplate sSpriteTemplate_Pokedex = {
    .tileTag = TAG_POKEDEX_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_Pokedex,
};

static const struct SpriteTemplate sSpriteTemplate_Bag = {
    .tileTag = TAG_BAG_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_Bag,
};

static const struct SpriteTemplate sSpriteTemplate_Pokenav = {
    .tileTag = TAG_POKENAV_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_Pokenav,
};

static const struct SpriteTemplate sSpriteTemplate_Dexnav = {
    .tileTag = TAG_DEXNAV_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_Dexnav,
};

static const struct SpriteTemplate sSpriteTemplate_TrainerCard = {
    .tileTag = TAG_TRAINER_CARD_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_TrainerCard,
};

static const struct SpriteTemplate sSpriteTemplate_Save = {
    .tileTag = TAG_SAVE_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_Save,
};

static const struct SpriteTemplate sSpriteTemplate_Options = {
    .tileTag = TAG_OPTIONS_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_Options,
};

static const struct SpriteTemplate sSpriteTemplate_Cancel = {
    .tileTag = TAG_CANCEL_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_Cancel,
};

static const struct SpriteTemplate sSpriteTemplate_Retire = {
    .tileTag = TAG_RETIRE_GFX,
    .paletteTag = TAG_MENU_PAL,
    .oam = &sOamData_Icon,
    .anims = sSpriteAnimTable_Icon,
    .images = NULL,
    .affineAnims = sAffineAnimCmds_Icon,
    .callback = SpriteCB_Retire,
};
#endif

static const struct WindowTemplate sWindowTemplate_SafariBalls = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 9,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x8
};

static const struct WindowTemplate sWindowTemplate_StartClock = {
    .bg = 0, 
    .tilemapLeft = 1, 
    .tilemapTop = 1, 
    .width = 13, // If you want to shorten the dates to Sat., Sun., etc., change this to 9
    .height = 2, 
    .paletteNum = 15,
    .baseBlock = 0x30
};

static const u8 *const sPyramidFloorNames[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    gText_Floor1,
    gText_Floor2,
    gText_Floor3,
    gText_Floor4,
    gText_Floor5,
    gText_Floor6,
    gText_Floor7,
    gText_Peak
};

static const struct WindowTemplate sWindowTemplate_PyramidFloor = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 10,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x8
};

static const struct WindowTemplate sWindowTemplate_PyramidPeak = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 12,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x8
};

static const u8 sText_MenuDebug[] = _("DEBUG");

static const struct MenuAction sStartMenuItems[] =
{
    [MENU_ACTION_POKEDEX]         = {gText_MenuPokedex, {.u8_void = StartMenuPokedexCallback}},
    [MENU_ACTION_POKEMON]         = {gText_MenuPokemon, {.u8_void = StartMenuPokemonCallback}},
    [MENU_ACTION_BAG]             = {gText_MenuBag,     {.u8_void = StartMenuBagCallback}},
    [MENU_ACTION_POKENAV]         = {gText_MenuPokenav, {.u8_void = StartMenuPokeNavCallback}},
    [MENU_ACTION_PLAYER]          = {gText_MenuPlayer,  {.u8_void = StartMenuPlayerNameCallback}},
    [MENU_ACTION_SAVE]            = {gText_MenuSave,    {.u8_void = StartMenuSaveCallback}},
    [MENU_ACTION_OPTION]          = {gText_MenuOption,  {.u8_void = StartMenuOptionCallback}},
    [MENU_ACTION_EXIT]            = {gText_MenuExit,    {.u8_void = StartMenuExitCallback}},
    [MENU_ACTION_RETIRE_SAFARI]   = {gText_MenuRetire,  {.u8_void = StartMenuSafariZoneRetireCallback}},
    [MENU_ACTION_PLAYER_LINK]     = {gText_MenuPlayer,  {.u8_void = StartMenuLinkModePlayerNameCallback}},
    [MENU_ACTION_REST_FRONTIER]   = {gText_MenuRest,    {.u8_void = StartMenuSaveCallback}},
    [MENU_ACTION_RETIRE_FRONTIER] = {gText_MenuRetire,  {.u8_void = StartMenuBattlePyramidRetireCallback}},
    [MENU_ACTION_PYRAMID_BAG]     = {gText_MenuBag,     {.u8_void = StartMenuBattlePyramidBagCallback}},
    [MENU_ACTION_DEBUG]           = {sText_MenuDebug,   {.u8_void = StartMenuDebugCallback}},
    [MENU_ACTION_DEXNAV]          = {gText_MenuDexNav,  {.u8_void = StartMenuDexNavCallback}},
};

static const struct SpriteTemplate * const sIconTemplates[] =
{
    [MENU_ACTION_POKEDEX]         = &sSpriteTemplate_Pokedex,
    [MENU_ACTION_POKEMON]         = &sSpriteTemplate_Pokeball,
    [MENU_ACTION_BAG]             = &sSpriteTemplate_Bag,
    [MENU_ACTION_POKENAV]         = &sSpriteTemplate_Pokenav,
    [MENU_ACTION_PLAYER]          = &sSpriteTemplate_TrainerCard,
    [MENU_ACTION_SAVE]            = &sSpriteTemplate_Save,
    [MENU_ACTION_OPTION]          = &sSpriteTemplate_Options,
    [MENU_ACTION_EXIT]            = &sSpriteTemplate_Cancel,
    [MENU_ACTION_RETIRE_SAFARI]   = &sSpriteTemplate_Retire,
    [MENU_ACTION_PLAYER_LINK]     = &sSpriteTemplate_TrainerCard,
    [MENU_ACTION_REST_FRONTIER]   = &sSpriteTemplate_Pokeball,
    [MENU_ACTION_RETIRE_FRONTIER] = &sSpriteTemplate_Retire,
    [MENU_ACTION_PYRAMID_BAG]     = &sSpriteTemplate_Bag,
    [MENU_ACTION_DEBUG]           = &sSpriteTemplate_Cancel,
    [MENU_ACTION_DEXNAV]          = &sSpriteTemplate_Dexnav,
};


static const struct BgTemplate sBgTemplates_LinkBattleSave[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates_LinkBattleSave[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x194
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sSaveInfoWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 18,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 8
};

// Local functions
static void BuildStartMenuActions(void);
static void AddStartMenuAction(u8 action);
static void BuildNormalStartMenu(void);
static void BuildDebugStartMenu(void);
static void BuildSafariZoneStartMenu(void);
static void BuildLinkModeStartMenu(void);
static void BuildUnionRoomStartMenu(void);
static void BuildBattlePikeStartMenu(void);
static void BuildBattlePyramidStartMenu(void);
static void BuildMultiPartnerRoomStartMenu(void);
static void ShowSafariBallsWindow(void);
static void ShowPyramidFloorWindow(void);
static void RemoveExtraStartMenuWindows(void);
static u8 GetStartMenuVisibleActionCount(void);
static u8 GetStartMenuCursorVisiblePos(void);
static void UpdateStartMenuScrollOffset(void);
static void AddStartMenuScrollIndicators(void);
static void RemoveStartMenuScrollIndicators(void);
#if DPPT_START_MENU == TRUE
static void DestroyStartMenuActionSprites(void);
#endif
static bool32 PrintStartMenuActions(s8 *pIndex, u32 count);
static void RedrawStartMenuActions(void);
static void MoveStartMenuCursor(s8 cursorDelta);
static bool32 InitStartMenuStep(void);
static void InitStartMenu(void);
static void CreateStartMenuTask(TaskFunc followupFunc);
static void InitSave(void);
static u8 RunSaveCallback(void);
static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void));
static void HideSaveMessageWindow(void);
static void HideSaveInfoWindow(void);
static void SaveStartTimer(void);
static bool8 SaveSuccesTimer(void);
static bool8 SaveErrorTimer(void);
static void InitBattlePyramidRetire(void);
static void VBlankCB_LinkBattleSave(void);
static bool32 InitSaveWindowAfterLinkBattle(u8 *par1);
static void CB2_SaveAfterLinkBattle(void);
static void ShowSaveInfoWindow(void);
static void RemoveSaveInfoWindow(void);
static void HideStartMenuWindow(void);
static void HideStartMenuDebug(void);

void SetDexPokemonPokenavFlags(void) // unused
{
    FlagSet(FLAG_SYS_POKEDEX_GET);
    FlagSet(FLAG_SYS_POKEMON_GET);
    FlagSet(FLAG_SYS_POKENAV_GET);
}

static void BuildStartMenuActions(void)
{
    sNumStartMenuActions = 0;

    if (IsOverworldLinkActive() == TRUE)
    {
        BuildLinkModeStartMenu();
    }
    else if (InUnionRoom() == TRUE)
    {
        BuildUnionRoomStartMenu();
    }
    else if (GetSafariZoneFlag() == TRUE)
    {
        BuildSafariZoneStartMenu();
    }
    else if (InBattlePike())
    {
        BuildBattlePikeStartMenu();
    }
    else if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        BuildBattlePyramidStartMenu();
    }
    else if (InMultiPartnerRoom())
    {
        BuildMultiPartnerRoomStartMenu();
    }
    else
    {
        if (DEBUG_OVERWORLD_MENU == TRUE && DEBUG_OVERWORLD_IN_MENU == TRUE)
            BuildDebugStartMenu();
        else
            BuildNormalStartMenu();
    }
}

static void AddStartMenuAction(u8 action)
{
    AppendToList(sCurrentStartMenuActions, &sNumStartMenuActions, action);
}

static void BuildNormalStartMenu(void)
{
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);

    if (DN_FLAG_DEXNAV_GET != 0 && FlagGet(DN_FLAG_DEXNAV_GET))
        AddStartMenuAction(MENU_ACTION_DEXNAV);

    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);

    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
    #if DPPT_START_MENU_DISABLE_EXIT == TRUE
    if (!(FlagGet(FLAG_SYS_POKEDEX_GET) && FlagGet(FLAG_SYS_POKEMON_GET) && FlagGet(FLAG_SYS_POKENAV_GET)))
        AddStartMenuAction(MENU_ACTION_EXIT);
    #endif
}

static void BuildDebugStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_DEBUG);
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);
    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildSafariZoneStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_RETIRE_SAFARI);
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildLinkModeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER_LINK);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildUnionRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePikeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePyramidStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PYRAMID_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_REST_FRONTIER);
    AddStartMenuAction(MENU_ACTION_RETIRE_FRONTIER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildMultiPartnerRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void ShowSafariBallsWindow(void)
{
    sSafariBallsWindowId = AddWindow(&sWindowTemplate_SafariBalls);
    PutWindowTilemap(sSafariBallsWindowId);
    DrawStdWindowFrame(sSafariBallsWindowId, FALSE);
    if (IS_FRLG)
    {
        ConvertIntToDecimalStringN(gStringVar1, gSafariZoneStepCounter, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, 600, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar3, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, gText_MenuSafariStats);
        AddTextPrinterParameterized(sSafariBallsWindowId, FONT_NORMAL, gStringVar4, 4, 3, 0xFF, NULL);
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, gText_SafariBallStock);
        AddTextPrinterParameterized(sSafariBallsWindowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    }
    CopyWindowToVram(sSafariBallsWindowId, COPYWIN_GFX);
}

static void ShowPyramidFloorWindow(void)
{
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum == FRONTIER_STAGES_PER_CHALLENGE)
        sBattlePyramidFloorWindowId = AddWindow(&sWindowTemplate_PyramidPeak);
    else
        sBattlePyramidFloorWindowId = AddWindow(&sWindowTemplate_PyramidFloor);

    PutWindowTilemap(sBattlePyramidFloorWindowId);
    DrawStdWindowFrame(sBattlePyramidFloorWindowId, FALSE);
    StringCopy(gStringVar1, sPyramidFloorNames[gSaveBlock2Ptr->frontier.curChallengeBattleNum]);
    StringExpandPlaceholders(gStringVar4, gText_BattlePyramidFloor);
    AddTextPrinterParameterized(sBattlePyramidFloorWindowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sBattlePyramidFloorWindowId, COPYWIN_GFX);
}

static void RemoveExtraStartMenuWindows(void)
{
    if (GetSafariZoneFlag())
    {
        ClearStdWindowAndFrameToTransparent(sSafariBallsWindowId, FALSE);
        //CopyWindowToVram(sSafariBallsWindowId, COPYWIN_GFX);
        RemoveWindow(sSafariBallsWindowId);
    }
    else if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        ClearStdWindowAndFrameToTransparent(sBattlePyramidFloorWindowId, FALSE);
        RemoveWindow(sBattlePyramidFloorWindowId);
    }

    RemoveTimeWindow();
}

static u8 GetStartMenuVisibleActionCount(void)
{
    return min(sNumStartMenuActions, START_MENU_MAX_VISIBLE_ACTIONS);
}

static u8 GetStartMenuCursorVisiblePos(void)
{
    return sStartMenuCursorPos - sStartMenuScrollOffset;
}

static void UpdateStartMenuScrollOffset(void)
{
    u8 visibleCount = GetStartMenuVisibleActionCount();

    if (visibleCount == 0)
    {
        sStartMenuScrollOffset = 0;
        return;
    }

    if (sStartMenuCursorPos < sStartMenuScrollOffset)
        sStartMenuScrollOffset = sStartMenuCursorPos;
    else if (sStartMenuCursorPos >= sStartMenuScrollOffset + visibleCount)
        sStartMenuScrollOffset = sStartMenuCursorPos - visibleCount + 1;
}

static void AddStartMenuScrollIndicators(void)
{
    u8 visibleCount = GetStartMenuVisibleActionCount();

    if (sNumStartMenuActions <= visibleCount || sStartMenuScrollArrowsActive)
        return;

    sStartMenuScrollArrowTaskId = AddScrollIndicatorArrowPairParameterized(
        SCROLL_ARROW_UP,
        230,
        14,
        142,
        sNumStartMenuActions - visibleCount,
        TAG_START_MENU_SCROLL_ARROW,
        TAG_START_MENU_SCROLL_ARROW,
        &sStartMenuScrollOffset);
    sStartMenuScrollArrowsActive = TRUE;
}

static void RemoveStartMenuScrollIndicators(void)
{
    if (sStartMenuScrollArrowsActive)
    {
        RemoveScrollIndicatorArrowPair(sStartMenuScrollArrowTaskId);
        sStartMenuScrollArrowTaskId = 0;
        sStartMenuScrollArrowsActive = FALSE;
    }
}

#if DPPT_START_MENU == TRUE
static void DestroyStartMenuActionSprites(void)
{
    u32 i;

    for (i = 0; i < sSpriteIdCount; i++)
    {
        if (sSpriteIds[i] != SPRITE_NONE)
        {
            FreeSpriteOamMatrix(&gSprites[sSpriteIds[i]]);
            DestroySprite(&gSprites[sSpriteIds[i]]);
            sSpriteIds[i] = SPRITE_NONE;
        }
    }

    sSpriteIdCount = 0;
}
#endif

static bool32 PrintStartMenuActions(s8 *pIndex, u32 count)
{
    s8 index = *pIndex;
    u8 x = 168;
    u8 visibleCount = GetStartMenuVisibleActionCount();
    u8 end = sStartMenuScrollOffset + visibleCount;

    do
    {
        u8 visibleIndex = index - sStartMenuScrollOffset;

        if (sStartMenuItems[sCurrentStartMenuActions[index]].func.u8_void == StartMenuPlayerNameCallback)
        {
            #if DPPT_START_MENU == TRUE
            PrintPlayerNameOnWindow(GetStartMenuWindowId(), sStartMenuItems[sCurrentStartMenuActions[index]].text, 32, visibleIndex*20);
            #else
            PrintPlayerNameOnWindow(GetStartMenuWindowId(), sStartMenuItems[sCurrentStartMenuActions[index]].text, 8, (visibleIndex << 4) + 9);
            #endif
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, sStartMenuItems[sCurrentStartMenuActions[index]].text);
            #if DPPT_START_MENU == TRUE
            AddTextPrinterParameterized(GetStartMenuWindowId(), FONT_NORMAL, gStringVar4, 32, visibleIndex*20, TEXT_SKIP_DRAW, NULL);
        }

        if (sIconTemplates[sCurrentStartMenuActions[index]] != NULL && sCurrentStartMenuActions[index] < ARRAY_COUNT(sIconTemplates))
        {
            sSpriteIds[sSpriteIdCount] = CreateSprite(sIconTemplates[sCurrentStartMenuActions[index]], x, 16+(visibleIndex*20), 0);
            sSpriteIdCount++;
            #else
            AddTextPrinterParameterized(GetStartMenuWindowId(), FONT_NORMAL, gStringVar4, 8, (visibleIndex << 4) + 9, TEXT_SKIP_DRAW, NULL);
            #endif
        }

        index++;
        if (index >= sNumStartMenuActions || index >= end)
        {
            *pIndex = index;
            return TRUE;
        }

        count--;
    }
    while (count != 0);

    *pIndex = index;
    return FALSE;
}

static void RedrawStartMenuActions(void)
{
    s8 index = sStartMenuScrollOffset;

    #if DPPT_START_MENU == TRUE
    DestroyStartMenuActionSprites();
    #endif

    FillWindowPixelBuffer(GetStartMenuWindowId(), PIXEL_FILL(1));
    DrawStdWindowFrame(GetStartMenuWindowId(), FALSE);
    PrintStartMenuActions(&index, GetStartMenuVisibleActionCount());
    CopyWindowToVram(GetStartMenuWindowId(), COPYWIN_FULL);
}

static void MoveStartMenuCursor(s8 cursorDelta)
{
    u16 oldScrollOffset = sStartMenuScrollOffset;

    if (cursorDelta < 0)
    {
        if (sStartMenuCursorPos == 0)
            return;

        sStartMenuCursorPos--;
    }
    else
    {
        if (sStartMenuCursorPos >= sNumStartMenuActions - 1)
            return;

        sStartMenuCursorPos++;
    }

    UpdateStartMenuScrollOffset();

    if (sStartMenuScrollOffset != oldScrollOffset)
        RedrawStartMenuActions();

    #if DPPT_START_MENU == TRUE
    gSprites[sSelectorSpriteIds[0]].y = 16 + (20 * GetStartMenuCursorVisiblePos());
    gSprites[sSelectorSpriteIds[1]].y = 16 + (20 * GetStartMenuCursorVisiblePos());
    #else
    InitMenuNormal(GetStartMenuWindowId(), FONT_NORMAL, 0, 9, 16, GetStartMenuVisibleActionCount(), GetStartMenuCursorVisiblePos());
    #endif
}

static bool32 InitStartMenuStep(void)
{
    s8 state = sInitStartMenuData[0];

    switch (state)
    {
    case 0:
        sInitStartMenuData[0]++;
        break;
    case 1:
        BuildStartMenuActions();
        if (sStartMenuCursorPos >= sNumStartMenuActions)
            sStartMenuCursorPos = 0;
        sStartMenuScrollOffset = 0;
        UpdateStartMenuScrollOffset();
        sInitStartMenuData[0]++;
        break;
    case 2:
        LoadMessageBoxAndBorderGfx();
        DrawStdWindowFrame(AddStartMenuWindow(GetStartMenuVisibleActionCount()), FALSE);
        #if DPPT_START_MENU == TRUE
        sSpriteIdCount = 0;
        LoadStartMenuGfx();
        #endif
        sInitStartMenuData[1] = sStartMenuScrollOffset;
        sInitStartMenuData[0]++;
        break;
    case 3:
        if (GetSafariZoneFlag())
            ShowSafariBallsWindow();
        else if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
            ShowPyramidFloorWindow();
        sInitStartMenuData[0]++;
        break;
    case 4:
        ShowTimeWindow();
        sInitStartMenuData[0]++;
        break;
    case 5:
        if (PrintStartMenuActions(&sInitStartMenuData[1], 2))
            sInitStartMenuData[0]++;
        break;
    case 6:
        #if DPPT_START_MENU == TRUE
        sSelectorSpriteIds[0] = CreateSprite(&sSpriteTemplate_Selector, 181, 16+(20*GetStartMenuCursorVisiblePos()), 0);
        gSprites[sSelectorSpriteIds[0]].hFlip = TRUE;
        sSelectorSpriteIds[1] = CreateSprite(&sSpriteTemplate_Selector, 203, 16+(20*GetStartMenuCursorVisiblePos()), 0);
        InitMenuNormal(GetStartMenuWindowId(), FONT_NORMAL, -1, -1, -1, GetStartMenuVisibleActionCount(), GetStartMenuCursorVisiblePos());
        #else
        InitMenuNormal(GetStartMenuWindowId(), FONT_NORMAL, 0, 9, 16, GetStartMenuVisibleActionCount(), GetStartMenuCursorVisiblePos());
        #endif
        AddStartMenuScrollIndicators();
        CopyWindowToVram(GetStartMenuWindowId(), COPYWIN_MAP);
        return TRUE;
    }

    return FALSE;
}

static void InitStartMenu(void)
{
    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    while (!InitStartMenuStep())
        ;
}

static void StartMenuTask(u8 taskId)
{
    if (InitStartMenuStep() == TRUE)
        SwitchTaskToFollowupFunc(taskId);
}

static void CreateStartMenuTask(TaskFunc followupFunc)
{
    u8 taskId;

    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    taskId = CreateTask(StartMenuTask, 0x50);
    SetTaskFuncWithFollowupFunc(taskId, StartMenuTask, followupFunc);
}

static bool8 FieldCB_ReturnToFieldStartMenu(void)
{
    #if VOL_START_MENU == TRUE
    HeatStartMenu_Init();
    #else
    if (InitStartMenuStep() == FALSE)
    {
        return FALSE;
    }
    #endif
    
    ReturnToFieldOpenStartMenu();
    return TRUE;
}

void ShowReturnToFieldStartMenu(void)
{
    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    gFieldCallback2 = FieldCB_ReturnToFieldStartMenu;
}

void Task_ShowStartMenu(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (InUnionRoom() == TRUE)
            SetUsingUnionRoomStartMenu();

        gMenuCallback = HandleStartMenuInput;
        task->data[0]++;
        break;
    case 1:
        if (gMenuCallback() == TRUE)
            DestroyTask(taskId);
        break;
    }
}

void ShowStartMenu(void)
{
    if (!IsOverworldLinkActive())
    {
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }
    CreateStartMenuTask(Task_ShowStartMenu);
    LockPlayerFieldControls();
}

static bool8 HandleStartMenuInput(void)
{
    if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        MoveStartMenuCursor(-1);
    }

    if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        MoveStartMenuCursor(1);
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void == StartMenuPokedexCallback)
        {
            if (GetNationalPokedexCount(FLAG_GET_SEEN) == 0)
                return FALSE;
        }
        if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_DEXNAV
          && MapHasNoEncounterData())
            return FALSE;

        RemoveStartMenuScrollIndicators();
        gMenuCallback = sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void;

        if (gMenuCallback != StartMenuSaveCallback
            && gMenuCallback != StartMenuExitCallback
            && gMenuCallback != StartMenuDebugCallback
            && gMenuCallback != StartMenuSafariZoneRetireCallback
            && gMenuCallback != StartMenuBattlePyramidRetireCallback)
        {
           FadeScreen(FADE_TO_BLACK, 0);
        }

        return FALSE;
    }

    if (JOY_NEW(START_BUTTON | B_BUTTON))
    {
        RemoveExtraStartMenuWindows();
        HideStartMenu();
        return TRUE;
    }

    ShowTimeWindow();
    return FALSE;
}

bool8 StartMenuPokedexCallback(void)
{
    if (!gPaletteFade.active)
    {
        IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OpenPokedex);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokemonCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PartyMenuFromStartMenu); // Display party menu

        return TRUE;
    }

    if (!GetSafariZoneFlag() && CurrentBattlePyramidLocation() == PYRAMID_LOCATION_NONE && gSaveBlock2Ptr->playTimeSeconds == 0) 
    {
        RemoveExtraStartMenuWindows();
        ShowTimeWindow();
    }

    return FALSE;
}

static bool8 StartMenuBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_BagMenuFromStartMenu); // Display bag menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokeNavCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitPokeNav);  // Display PokéNav

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();

        if (IsOverworldLinkActive() || InUnionRoom())
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card
        else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
            ShowFrontierPass(CB2_ReturnToFieldWithOpenMenu); // Display frontier pass
        else
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card

        return TRUE;
    }

    return FALSE;
}

const u8 gText_DisabledFunc[]   = _("You can't save here.\p");
const u8 gText_DisabledFuncPt[] = _("Você não pode salvar aqui.\p");
const u8 gText_DisabledFuncEs[] = _("No puedes guardar aquí.\p");

static void Task_CloseDisabledFuncMessage(u8 taskId)
{
    ClearDialogWindowAndFrame(0, TRUE);
    DestroyTask(taskId);
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}

static bool8 StartMenuSaveCallback(void)
{
    u8 language = GET_LANGUAGE();
    if (MAP_IS(MAP_SILENT_FOREST))
    {
        if (language == PT)
            StringExpandPlaceholders(gStringVar4, gText_DisabledFuncPt);
        else if (language == ES)
            StringExpandPlaceholders(gStringVar4, gText_DisabledFuncEs);
        else
            StringExpandPlaceholders(gStringVar4, gText_DisabledFunc);

        RemoveExtraStartMenuWindows();
        HideStartMenuWindow();
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
        LockPlayerFieldControls();

        DisplayItemMessageOnField(CreateTask(TaskDummy, 0), gStringVar4, Task_CloseDisabledFuncMessage);
        return TRUE;
    }

    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        RemoveExtraStartMenuWindows();

    gMenuCallback = SaveStartCallback; // Display save menu

    return FALSE;
}

static bool8 StartMenuOptionCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitOptionMenu); // Display option menu
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuExitCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenu(); // Hide start menu

    return TRUE;
}

static bool8 StartMenuDebugCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenuDebug(); // Hide start menu without enabling movement

    if (DEBUG_OVERWORLD_MENU)
    {
        FreezeObjectEvents();
        Debug_ShowMainMenu();
    }

return TRUE;
}

static bool8 StartMenuSafariZoneRetireCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenu();
    SafariZoneRetirePrompt();

    return TRUE;
}

static void HideStartMenuDebug(void)
{
    PlaySE(SE_SELECT);
    RemoveStartMenuScrollIndicators();
    ClearStdWindowAndFrame(GetStartMenuWindowId(), TRUE);
    RemoveStartMenuWindow();
}

static bool8 StartMenuLinkModePlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        ShowTrainerCardInLink(gLocalLinkPlayerId, CB2_ReturnToFieldWithOpenMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBattlePyramidRetireCallback(void)
{
    gMenuCallback = BattlePyramidRetireStartCallback; // Confirm retire

    return FALSE;
}

// Functionally unused
void ShowBattlePyramidStartMenu(void)
{
    ClearDialogWindowAndFrameToTransparent(0, FALSE);
    ScriptUnfreezeObjectEvents();
    CreateStartMenuTask(Task_ShowStartMenu);
    LockPlayerFieldControls();
}

static bool8 StartMenuBattlePyramidBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PyramidBagMenuFromStartMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 SaveStartCallback(void)
{
    InitSave();
    #if DPPT_START_MENU == TRUE
    DestroyStartMenuGfx();
    #endif
    gMenuCallback = SaveCallback;

    return FALSE;
}

static bool8 SaveCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Back to start menu
        ClearDialogWindowAndFrameToTransparent(0, FALSE);
        InitStartMenu();
        gMenuCallback = HandleStartMenuInput;
        return FALSE;
    case SAVE_SUCCESS:
    case SAVE_ERROR:    // Close start menu
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        SoftResetInBattlePyramid();
        return TRUE;
    }

    return FALSE;
}

static bool8 BattlePyramidRetireStartCallback(void)
{
    InitBattlePyramidRetire();
    gMenuCallback = BattlePyramidRetireCallback;

    return FALSE;
}

static bool8 BattlePyramidRetireReturnCallback(void)
{
    InitStartMenu();
    gMenuCallback = HandleStartMenuInput;

    return FALSE;
}

static bool8 BattlePyramidRetireCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_SUCCESS: // No (Stay in battle pyramid)
        RemoveExtraStartMenuWindows();
        gMenuCallback = BattlePyramidRetireReturnCallback;
        return FALSE;
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Yes (Retire from battle pyramid)
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        ScriptContext_SetupScript(BattlePyramid_Retire);
        return TRUE;
    }

    return FALSE;
}

static void InitSave(void)
{
    SaveMapView();
    sSaveDialogCallback = SaveConfirmSaveCallback;
    sSavingComplete = FALSE;
}

static u8 RunSaveCallback(void)
{
    // True if text is still printing
    if (RunTextPrintersAndIsPrinter0Active() == TRUE)
    {
        return SAVE_IN_PROGRESS;
    }

    sSavingComplete = FALSE;
    return sSaveDialogCallback();
}

void SaveGame(void)
{
    InitSave();
    CreateTask(SaveGameTask, 0x50);
}

static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void))
{
    StringExpandPlaceholders(gStringVar4, message);
    LoadMessageBoxAndFrameGfx(0, TRUE);
    AddTextPrinterForMessage(TRUE);
    sSavingComplete = TRUE;
    sSaveDialogCallback = saveCallback;
}

static void SaveGameTask(u8 taskId)
{
    u8 status = RunSaveCallback();

    switch (status)
    {
    case SAVE_CANCELED:
    case SAVE_ERROR:
        gSpecialVar_Result = 0;
        break;
    case SAVE_SUCCESS:
        gSpecialVar_Result = status;
        break;
    case SAVE_IN_PROGRESS:
        return;
    }

    DestroyTask(taskId);
    ScriptContext_Enable();
}

static void HideSaveMessageWindow(void)
{
    ClearDialogWindowAndFrame(0, TRUE);
}

static void HideSaveInfoWindow(void)
{
    RemoveSaveInfoWindow();
}

static void SaveStartTimer(void)
{
    sSaveDialogTimer = 60;
}

static bool8 SaveSuccesTimer(void)
{
    sSaveDialogTimer--;

    if (JOY_HELD(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return TRUE;
    }
    if (sSaveDialogTimer == 0)
    {
        return TRUE;
    }

    return FALSE;
}

static bool8 SaveErrorTimer(void)
{
    if (sSaveDialogTimer != 0)
    {
        sSaveDialogTimer--;
    }
    else if (JOY_HELD(A_BUTTON))
    {
        return TRUE;
    }

    return FALSE;
}

static u8 SaveConfirmSaveCallback(void)
{
    ClearStdWindowAndFrame(GetStartMenuWindowId(), FALSE);
    RemoveStartMenuWindow();
    ShowSaveInfoWindow();

    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        ShowSaveMessage(gText_BattlePyramidConfirmRest, SaveYesNoCallback);
    }
    else
    {
        const u8 *confirmSaveText;

        switch (GET_LANGUAGE())
        {
        case PT:
            confirmSaveText = gText_ConfirmSavePt;
            break;
        case ES:
            confirmSaveText = gText_ConfirmSaveEs;
            break;
        default:
            confirmSaveText = gText_ConfirmSave;
            break;
        }
        ShowSaveMessage(confirmSaveText, SaveYesNoCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveYesNoCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveConfirmInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        switch (gSaveFileStatus)
        {
        case SAVE_STATUS_EMPTY:
        case SAVE_STATUS_CORRUPT:
            if (gDifferentSaveFile == FALSE && !SKIP_SAVE_CONFIRMATION)
            {
                sSaveDialogCallback = SaveFileExistsCallback;
                return SAVE_IN_PROGRESS;
            }

            sSaveDialogCallback = SaveSavingMessageCallback;
            return SAVE_IN_PROGRESS;
        default:
            if (SKIP_SAVE_CONFIRMATION)
                sSaveDialogCallback = SaveSavingMessageCallback;
            else
                sSaveDialogCallback = SaveFileExistsCallback;
            return SAVE_IN_PROGRESS;
        }
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

// A different save file exists
static u8 SaveFileExistsCallback(void)
{
    if (gDifferentSaveFile == TRUE)
    {
        ShowSaveMessage(gText_DifferentSaveFile, SaveConfirmOverwriteDefaultNoCallback);
    }
    else
    {
        ShowSaveMessage(gText_AlreadySavedFile, SaveConfirmOverwriteCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteDefaultNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveOverwriteInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        sSaveDialogCallback = SaveSavingMessageCallback;
        return SAVE_IN_PROGRESS;
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveSavingMessageCallback(void)
{
    ShowSaveMessage(gText_SavingDontTurnOff, SaveDoSaveCallback);
    return SAVE_IN_PROGRESS;
}

static u8 SaveDoSaveCallback(void)
{
    u8 saveStatus;

    IncrementGameStat(GAME_STAT_SAVED_GAME);
    PausePyramidChallenge();

    if (gDifferentSaveFile == TRUE)
    {
        saveStatus = TrySavingData(SAVE_OVERWRITE_DIFFERENT_FILE);
        gDifferentSaveFile = FALSE;
    }
    else
    {
        saveStatus = TrySavingData(SAVE_NORMAL);
    }

    if (saveStatus == SAVE_STATUS_OK)
        ShowSaveMessage(gText_PlayerSavedGame, SaveSuccessCallback);
    else
        ShowSaveMessage(gText_SaveError, SaveErrorCallback);

    SaveStartTimer();
    return SAVE_IN_PROGRESS;
}

static u8 SaveSuccessCallback(void)
{
    if (!IsTextPrinterActiveOnWindow(0))
    {
        PlaySE(SE_SAVE);
        sSaveDialogCallback = SaveReturnSuccessCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnSuccessCallback(void)
{
    if (!IsSEPlaying() && SaveSuccesTimer())
    {
        HideSaveInfoWindow();
        return SAVE_SUCCESS;
    }
    else
    {
        return SAVE_IN_PROGRESS;
    }
}

static u8 SaveErrorCallback(void)
{
    if (!IsTextPrinterActiveOnWindow(0))
    {
        PlaySE(SE_BOO);
        sSaveDialogCallback = SaveReturnErrorCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnErrorCallback(void)
{
    if (!SaveErrorTimer())
    {
        return SAVE_IN_PROGRESS;
    }
    else
    {
        HideSaveInfoWindow();
        return SAVE_ERROR;
    }
}

static void InitBattlePyramidRetire(void)
{
    sSaveDialogCallback = BattlePyramidConfirmRetireCallback;
    sSavingComplete = FALSE;
}

static u8 BattlePyramidConfirmRetireCallback(void)
{
    ClearStdWindowAndFrame(GetStartMenuWindowId(), FALSE);
    RemoveStartMenuWindow();
    ShowSaveMessage(gText_BattlePyramidConfirmRetire, BattlePyramidRetireYesNoCallback);

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireYesNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = BattlePyramidRetireInputCallback;

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        return SAVE_CANCELED;
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveMessageWindow();
        return SAVE_SUCCESS;
    }

    return SAVE_IN_PROGRESS;
}

static void VBlankCB_LinkBattleSave(void)
{
    TransferPlttBuffer();
}

static bool32 InitSaveWindowAfterLinkBattle(u8 *state)
{
    switch (*state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        DmaClear16(3, PLTT, PLTT_SIZE);
        DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
        break;
    case 1:
        ResetSpriteData();
        ResetTasks();
        ResetPaletteFade();
        ScanlineEffect_Clear();
        break;
    case 2:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates_LinkBattleSave, ARRAY_COUNT(sBgTemplates_LinkBattleSave));
        InitWindows(sWindowTemplates_LinkBattleSave);
        LoadUserWindowBorderGfx_(0, 8, BG_PLTT_ID(14));
        Menu_LoadStdPalAt(BG_PLTT_ID(15));
        break;
    case 3:
        ShowBg(0);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        SetVBlankCallback(VBlankCB_LinkBattleSave);
        EnableInterrupts(1);
        break;
    case 4:
        return TRUE;
    }

    (*state)++;
    return FALSE;
}

void CB2_SetUpSaveAfterLinkBattle(void)
{
    if (InitSaveWindowAfterLinkBattle(&gMain.state))
    {
        CreateTask(Task_SaveAfterLinkBattle, 0x50);
        SetMainCallback2(CB2_SaveAfterLinkBattle);
    }
}

static void CB2_SaveAfterLinkBattle(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void Task_SaveAfterLinkBattle(u8 taskId)
{
    s16 *state = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (*state)
        {
        case 0:
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0,
                                        FONT_NORMAL,
                                        gText_SavingDontTurnOffPower,
                                        TEXT_SKIP_DRAW,
                                        NULL,
                                        TEXT_COLOR_DARK_GRAY,
                                        TEXT_COLOR_WHITE,
                                        TEXT_COLOR_LIGHT_GRAY);
            DrawTextBorderOuter(0, 8, 14);
            PutWindowTilemap(0);
            CopyWindowToVram(0, COPYWIN_FULL);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

            if (gWirelessCommType != 0 && InUnionRoom())
            {
                if (Link_AnyPartnersPlayingFRLG_JP())
                {
                    *state = 1;
                }
                else
                {
                    *state = 5;
                }
            }
            else
            {
                gSoftResetDisabled = TRUE;
                *state = 1;
            }
            break;
        case 1:
            SetContinueGameWarpStatusToDynamicWarp();
            WriteSaveBlock2();
            *state = 2;
            break;
        case 2:
            if (WriteSaveBlock1Sector())
            {
                ClearContinueGameWarpStatus2();
                *state = 3;
                gSoftResetDisabled = FALSE;
            }
            break;
        case 3:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            *state = 4;
            break;
        case 4:
            FreeAllWindowBuffers();
            SetMainCallback2(gMain.savedCallback);
            DestroyTask(taskId);
            break;
        case 5:
            CreateTask(Task_LinkFullSave, 5);
            *state = 6;
            break;
        case 6:
            if (!FuncIsActiveTask(Task_LinkFullSave))
            {
                *state = 3;
            }
            break;
        }
    }
}

static void ShowSaveInfoWindow(void)
{
    static const u8 sText_DateTime[] = _("{STR_VAR_1}/{STR_VAR_2}/{STR_VAR_3} - ");
    u8 dateTime[64];
    enum Gender gender = gSaveBlock2Ptr->playerGender;
    u8 color = (gender == MALE) ? TEXT_COLOR_BLUE : TEXT_COLOR_RED;
    const u8 *badgesText;
    const u8 *timeText;
    u32 i;
    u32 xOffset;

    switch (GET_LANGUAGE())
    {
    case PT:
        badgesText = gText_SavingBadgesPt;
        timeText = gText_SavingTimePt;
        break;
    case ES:
        badgesText = gText_SavingBadgesEs;
        timeText = gText_SavingTimeEs;
        break;
    default:
        badgesText = gText_SavingBadges;
        timeText = gText_SavingTime;
        break;
    }

    sSaveInfoWindowId = AddWindow(&sSaveInfoWindowTemplate);
    DrawStdWindowFrame(sSaveInfoWindowId, FALSE);

    // Print current date and time.
    ConvertIntToDecimalStringN(gStringVar1, GetDay(), STR_CONV_MODE_LEADING_ZEROS, 2);
    ConvertIntToDecimalStringN(gStringVar2, GetMonth(), STR_CONV_MODE_LEADING_ZEROS, 2);
    ConvertIntToDecimalStringN(gStringVar3, GetFullYear(), STR_CONV_MODE_LEADING_ZEROS, 4);
    FormatDecimalTimeWithoutSeconds(gStringVar4, gLocalTime.hours, gLocalTime.minutes, TRUE);
    StringExpandPlaceholders(dateTime, sText_DateTime);
    StringAppend(dateTime, gStringVar4);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, dateTime, 0, 1, TEXT_SKIP_DRAW, NULL);

    // Print location name.
    BufferSaveMenuText(SAVE_MENU_LOCATION, gStringVar4, TEXT_COLOR_GREEN);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, 0, 17, TEXT_SKIP_DRAW, NULL);

    // Create the party icons in the space between the location and save stats.
    LoadMonIconPalettes();
    sSavePartyIconsActive = TRUE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        sSavePartyIconSpriteIds[i] = SPRITE_NONE;
        if (i < gPartiesCount[B_TRAINER_PLAYER])
        {
            struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
            enum Species species = GetMonData(mon, MON_DATA_SPECIES);
            u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
            bool32 isEgg = GetMonData(mon, MON_DATA_IS_EGG);

            sSavePartyIconSpriteIds[i] = CreateMonIconIsEgg(species, SpriteCallbackDummy,
                                                            20 + 24 * i, 60, 0,
                                                            personality, isEgg);
            if (sSavePartyIconSpriteIds[i] == MAX_SPRITES)
            {
                sSavePartyIconSpriteIds[i] = SPRITE_NONE;
            }
            else
            {
                gSprites[sSavePartyIconSpriteIds[i]].oam.priority = 0;
            }
        }
    }

    // Print badge count and Pokédex count on the same line.
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, badgesText, 0, 69, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_BADGES, gStringVar4, color);
    xOffset = GetStringWidth(FONT_NORMAL, badgesText, 0) + 3;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, 69, TEXT_SKIP_DRAW, NULL);

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingPokedex, 76, 69, TEXT_SKIP_DRAW, NULL);
        BufferSaveMenuText(SAVE_MENU_CAUGHT, gStringVar4, color);
        xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 136);
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, 69, TEXT_SKIP_DRAW, NULL);
    }

    // Print play time.
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, timeText, 0, 81, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_PLAY_TIME, gStringVar4, color);
    xOffset = GetStringWidth(FONT_NORMAL, timeText, 0) + 3;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, 81, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(sSaveInfoWindowId, COPYWIN_GFX);
}

static void RemoveSaveInfoWindow(void)
{
    u32 i;

    if (sSavePartyIconsActive)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sSavePartyIconSpriteIds[i] != SPRITE_NONE)
            {
                FreeAndDestroyMonIconSprite(&gSprites[sSavePartyIconSpriteIds[i]]);
                sSavePartyIconSpriteIds[i] = SPRITE_NONE;
            }
        }
        FreeMonIconPalettes();
        sSavePartyIconsActive = FALSE;
    }
    ClearStdWindowAndFrame(sSaveInfoWindowId, FALSE);
    RemoveWindow(sSaveInfoWindowId);
}

static void Task_WaitForBattleTowerLinkSave(u8 taskId)
{
    if (!FuncIsActiveTask(Task_LinkFullSave))
    {
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

#define tInBattleTower data[2]

void SaveForBattleTowerLink(void)
{
    u8 taskId = CreateTask(Task_LinkFullSave, 5);
    gTasks[taskId].tInBattleTower = TRUE;
    gTasks[CreateTask(Task_WaitForBattleTowerLinkSave, 6)].data[1] = taskId;
}

#undef tInBattleTower

static void HideStartMenuWindow(void)
{
    RemoveStartMenuScrollIndicators();
    ClearStdWindowAndFrame(GetStartMenuWindowId(), TRUE);
    RemoveStartMenuWindow();
    ScriptUnfreezeObjectEvents();
    #if DPPT_START_MENU == TRUE
    DestroyStartMenuGfx();
    #endif
    UnlockPlayerFieldControls();
}

void HideStartMenu(void)
{
    PlaySE(SE_SELECT);
    HideStartMenuWindow();
}

void AppendToList(u8 *list, u8 *pos, u8 newEntry)
{
    list[*pos] = newEntry;
    (*pos)++;
}

static bool8 StartMenuDexNavCallback(void)
{
    CreateTask(Task_OpenDexNavFromStartMenu, 0);
    return TRUE;
}

void Script_ForceSaveGame(struct ScriptContext *ctx)
{
    SaveGame();
    ShowSaveInfoWindow();
    gMenuCallback = SaveCallback;
    sSaveDialogCallback = SaveSavingMessageCallback;
}

// NEW

static void SpriteCB_Pokedex(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_POKEDEX) // Easy way to see if we are hovered over the right action
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void SpriteCB_Pokeball(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_POKEMON)
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void SpriteCB_Bag(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_BAG || sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_PYRAMID_BAG)
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void SpriteCB_Pokenav(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_POKENAV)
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void SpriteCB_Dexnav(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_DEXNAV)
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void SpriteCB_TrainerCard(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_PLAYER || sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_PLAYER_LINK)
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void SpriteCB_Save(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_SAVE)
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void SpriteCB_Options(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_OPTION)
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void SpriteCB_Cancel(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_EXIT)
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void SpriteCB_Retire(struct Sprite* sprite) 
{
    if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_RETIRE_SAFARI || sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_RETIRE_FRONTIER)
    {
        StartSpriteAnimIfDifferent(sprite, 1);
        StartSpriteAffineAnimIfDifferent(sprite, 1);
    }
    else
    {
        StartSpriteAnimIfDifferent(sprite, 0);
        StartSpriteAffineAnimIfDifferent(sprite, 0);
    }
}

static void LoadStartMenuGfx(void)
{
    LoadSpritePalette(&sSpritePal_Selector);
    LoadCompressedSpriteSheet(&sSpriteSheet_Selector);
    if (FlagGet(FLAG_SYS_POKEDEX_GET))
        LoadCompressedSpriteSheet(sSpriteSheet_PokedexIcon);
    if (DN_FLAG_DEXNAV_GET != 0 && FlagGet(DN_FLAG_DEXNAV_GET))
        LoadCompressedSpriteSheet(sSpriteSheet_DexnavIcon);
    if (FlagGet(FLAG_SYS_POKEMON_GET))
        LoadCompressedSpriteSheet(sSpriteSheet_PokeballIcon);
    LoadCompressedSpriteSheet(sSpriteSheet_BagIcon);
    if (FlagGet(FLAG_SYS_POKENAV_GET))
        LoadCompressedSpriteSheet(sSpriteSheet_PokenavIcon);
    LoadCompressedSpriteSheet(sSpriteSheet_TrainerCardIcon);
    if (GetSafariZoneFlag())
        LoadCompressedSpriteSheet(sSpriteSheet_RetireIcon);
    else
        LoadCompressedSpriteSheet(sSpriteSheet_SaveIcon);
    LoadCompressedSpriteSheet(sSpriteSheet_OptionsIcon);
    LoadCompressedSpriteSheet(sSpriteSheet_CancelIcon);
}

static void DestroyStartMenuGfx(void)
{
    u32 i;
    FreeSpritePaletteByTag(TAG_MENU_PAL);
    for (i = 0; i < sSpriteIdCount; i++)
    {
        FreeSpriteOamMatrix(&gSprites[sSpriteIds[i]]);
        FreeSpriteTiles(&gSprites[sSpriteIds[i]]);
        DestroySprite(&gSprites[sSpriteIds[i]]);
        sSpriteIds[i] = SPRITE_NONE;
    }
    for (i = 0; i < 2; i++)
    {
        FreeSpriteOamMatrix(&gSprites[sSelectorSpriteIds[i]]);
        FreeSpriteTiles(&gSprites[sSelectorSpriteIds[i]]);
        DestroySprite(&gSprites[sSelectorSpriteIds[i]]);
        sSpriteIds[i] = SPRITE_NONE;
    }
    sSpriteIdCount = 0;
}

// If you want to shorten the dates to Sat., Sun., etc., change this to 70
#define CLOCK_WINDOW_WIDTH 104

const u8 gText_Saturday[] = _("Saturday,");
const u8 gText_Sunday[] = _("Sunday,");
const u8 gText_Monday[] = _("Monday,");
const u8 gText_Tuesday[] = _("Tuesday,");
const u8 gText_Wednesday[] = _("Wednesday,");
const u8 gText_Thursday[] = _("Thursday,");
const u8 gText_Friday[] = _("Friday,");

const u8 gText_Domingo[] = _("Domingo,");
const u8 gText_Segunda[] = _("Segunda,");
const u8 gText_Terca[] = _("Terça,");
const u8 gText_Quarta[] = _("Quarta,");
const u8 gText_Quinta[] = _("Quinta,");
const u8 gText_Sexta[] = _("Sexta,");
const u8 gText_Sabado[] = _("Sábado,");

const u8 gText_Lunes[] = _("Lunes,");
const u8 gText_Martes[] = _("Martes,");
const u8 gText_Miercoles[] = _("Miércoles,");
const u8 gText_Jueves[] = _("Jueves,");
const u8 gText_Viernes[] = _("Viernes,");
const u8 gText_Hour[] = _("h");

const u8 *const gDayNameStringsTable[7] = {
    gText_Saturday,
    gText_Sunday,
    gText_Monday,
    gText_Tuesday,
    gText_Wednesday,
    gText_Thursday,
    gText_Friday,
};

const u8 *const gDayNameStringsTablePt[7] = {
    gText_Sabado,
    gText_Domingo,
    gText_Segunda,
    gText_Terca,
    gText_Quarta,
    gText_Quinta,
    gText_Sexta,
};

const u8 *const gDayNameStringsTableEs[7] = {
    gText_Sabado,
    gText_Domingo,
    gText_Lunes,
    gText_Martes,
    gText_Miercoles,
    gText_Jueves,
    gText_Viernes,
};

static void ShowTimeWindow(void)
{
    const u8 *suffix;
    u8* ptr;
    u8 convertedHours;
    bool8 is24h = (GET_LANGUAGE() == PT || GET_LANGUAGE() == ES);

    if (!sStartClockWindowActive)
    {
        sStartClockWindowId = AddWindow(&sWindowTemplate_StartClock);
        PutWindowTilemap(sStartClockWindowId);
        sStartClockWindowActive = TRUE;
    }

    FillWindowPixelBuffer(sStartClockWindowId, PIXEL_FILL(1));
    DrawStdWindowFrame(sStartClockWindowId, FALSE);

    if (is24h)
    {
        // Formato 24h
        convertedHours = gLocalTime.hours;
        suffix = gText_Hour;
    }
    else
    {
        if (gLocalTime.hours < 12)
        {
            if (gLocalTime.hours == 0)
                convertedHours = 12;
            else
                convertedHours = gLocalTime.hours;
            suffix = gText_AM;
        }
        else if (gLocalTime.hours == 12)
        {
            convertedHours = 12;
            if (suffix == gText_AM);
                suffix = gText_PM;
        }
        else
        {
            convertedHours = gLocalTime.hours - 12;
            suffix = gText_PM;
        }
    }

    if (GET_LANGUAGE() == PT)
        StringExpandPlaceholders(gStringVar4, gDayNameStringsTablePt[GetDayOfWeek()]); // +1 because the game counts Saturday as the first day of the week, while in Portuguese Sunday is the first day
    else if (GET_LANGUAGE() == ES)
        StringExpandPlaceholders(gStringVar4, gDayNameStringsTableEs[GetDayOfWeek()]); // +1 because the game counts Saturday as the first day of the week, while in Spanish Sunday is the first day
    else
        StringExpandPlaceholders(gStringVar4, gDayNameStringsTable[GetDayOfWeek()]); // +1 because the game counts Saturday as the first day of the week
    // StringExpandPlaceholders(gStringVar4, gText_ContinueMenuTime); // prints "time" word, from version before weekday was added and leaving it here in case anyone would prefer to use it
    AddTextPrinterParameterized(sStartClockWindowId, 1, gStringVar4, 0, 1, 0xFF, NULL); 

    ptr = ConvertIntToDecimalStringN(gStringVar4, convertedHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    *ptr = 0xF0;

    ConvertIntToDecimalStringN(ptr + 1, gLocalTime.minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized(sStartClockWindowId, 1, gStringVar4, GetStringRightAlignXOffset(1, suffix, CLOCK_WINDOW_WIDTH) - (CLOCK_WINDOW_WIDTH - GetStringRightAlignXOffset(1, gStringVar4, CLOCK_WINDOW_WIDTH) + 3), 1, 0xFF, NULL); // print time

    AddTextPrinterParameterized(sStartClockWindowId, 1, suffix, GetStringRightAlignXOffset(1, suffix, CLOCK_WINDOW_WIDTH), 1, 0xFF, NULL); // print am/pm

    CopyWindowToVram(sStartClockWindowId, COPYWIN_FULL);
}

static void RemoveTimeWindow(void)
{
    if (sStartClockWindowActive)
    {
        ClearStdWindowAndFrameToTransparent(sStartClockWindowId, FALSE);
        RemoveWindow(sStartClockWindowId);
        sStartClockWindowActive = FALSE;
    }
}
