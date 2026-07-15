#include "global.h"
#include "naming_screen.h"
#include "malloc.h"
#include "palette.h"
#include "task.h"
#include "sprite.h"
#include "string_util.h"
#include "window.h"
#include "bg.h"
#include "gpu_regs.h"
#include "pokemon.h"
#include "field_specials.h"
#include "field_player_avatar.h"
#include "event_object_movement.h"
#include "event_data.h"
#include "constants/songs.h"
#include "pokemon_storage_system.h"
#include "graphics.h"
#include "sound.h"
#include "trig.h"
#include "field_effect.h"
#include "pokemon_icon.h"
#include "data.h"
#include "strings.h"
#include "menu.h"
#include "text_window.h"
#include "overworld.h"
#include "walda_phrase.h"
#include "main.h"
#include "decompress.h"
#include "constants/characters.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"
#include "gba/syscall.h"

enum {
    INPUT_NONE,
    INPUT_DPAD_UP,
    INPUT_DPAD_DOWN,
    INPUT_DPAD_LEFT,
    INPUT_DPAD_RIGHT,
    INPUT_A_BUTTON,
    INPUT_B_BUTTON,
    INPUT_LR_BUTTON,
    INPUT_SELECT,
    INPUT_START,
};

#define KBROW_COUNT 3
#define KBCOL_COUNT 12
#define FILE_COUNT 4

enum {
    GFXTAG_BACK_BUTTON,
    GFXTAG_OK_BUTTON,
    GFXTAG_PAGE_SWAP_FRAME,
    GFXTAG_PAGE_SWAP_BUTTON,
    GFXTAG_PAGE_SWAP_UPPER,
    GFXTAG_PAGE_SWAP_LOWER,
    GFXTAG_PAGE_SWAP_OTHERS,
    GFXTAG_CURSOR,
    GFXTAG_CURSOR_SQUISHED,
    GFXTAG_CURSOR_FILLED,
    GFXTAG_INPUT_ARROW,
    GFXTAG_UNDERSCORE,
    GFXTAG_RIVAL = 255,
};

enum {
    PALTAG_MENU, // Also the PC icon
    PALTAG_PAGE_SWAP_UPPER,
    PALTAG_PAGE_SWAP_LOWER,
    PALTAG_PAGE_SWAP_OTHERS, // Also the input arrow/underscore
    PALTAG_PAGE_SWAP,
    PALTAG_CURSOR,
    PALTAG_BACK_BUTTON,
    PALTAG_OK_BUTTON,
    PALTAG_RIVAL = 255,
};

enum {
    WIN_KB_PAGE_1, // Which of these two windows is in front is cycled as the player swaps
    WIN_KB_PAGE_2, // Initially WIN_KB_PAGE_1 is in front, with WIN_KB_PAGE_2 on deck
    WIN_TEXT_ENTRY,
    WIN_TEXT_ENTRY_BOX,
    WIN_BANNER,
    WIN_COUNT,
};

// The constants for the pages are needlessly complicated because GF didn't keep the indexing order consistent
// This set is used for sNamingScreen->currentPage. It uses the order that the pages are cycled in
enum {
    KBPAGE_LETTERS_UPPER,
    KBPAGE_LETTERS_LOWER,
    KBPAGE_SYMBOLS,
    KBPAGE_COUNT,
};

// This set is used for initializing a page's keyboard text and getting its number of columns
enum {
    KEYBOARD_LETTERS_LOWER,
    KEYBOARD_LETTERS_UPPER,
    KEYBOARD_SYMBOLS,
};

// This set is used for getting the gfx/pal tags of the page's swap button
enum {
    PAGE_SWAP_UPPER,
    PAGE_SWAP_OTHERS,
    PAGE_SWAP_LOWER,
};

enum {
    KEY_ROLE_CHAR,
    KEY_ROLE_PAGE_UPPER,
    KEY_ROLE_PAGE_LOWER,
    KEY_ROLE_PAGE_OTHER,
    KEY_ROLE_BACKSPACE,
    KEY_ROLE_OK,
};

enum {
    BUTTON_PAGE,
    BUTTON_BACK,
    BUTTON_OK,
    BUTTON_COUNT,
};

enum
{
    FNKEY_CASE_UPPER,
    FNKEY_CASE_LOWER,
    FNKEY_CASE_OTHER,
    FNKEY_BACK,
    FNKEY_OK,
};

// states for Task_NamingScreen
enum {
    STATE_FADE_IN,
    STATE_WAIT_FADE_IN,
    STATE_HANDLE_INPUT,
    STATE_MOVE_TO_OK_BUTTON,
    STATE_START_PAGE_SWAP,
    STATE_WAIT_PAGE_SWAP,
    STATE_PRESSED_OK,
    STATE_WAIT_SENT_TO_PC_MESSAGE,
    STATE_FADE_OUT,
    STATE_EXIT,
};

// sates for Task_HandleInput
enum
{
    INPUT_STATE_DISABLED,
    INPUT_STATE_ENABLED,
    INPUT_STATE_OVERRIDE,
};

struct NamingScreenTemplate
{
    u8 copyExistingString;
    u8 maxChars;
    u8 iconFunction;
    u8 addGenderIcon;
    u8 initialPage;
    const u8 *title;
    const u8 *titleSpa;
    const u8 *titlePt;
};

struct NamingScreenData
{
    u8 textBuffer[0x10];
    u8 state;
    u8 windows[5];
    u16 inputCharBaseXPos;
    u16 bg2vOffset;
    u8 bldAlphaTg;
    u8 currentPage;
    u8 cursorSpriteId;
    u8 selectBtnFrameSpriteId;
    u8 keyRepeatStartDelayCopy;
    const struct NamingScreenTemplate *template;
    u8 templateNum;
    u8 *destBuffer;
    enum Species monSpecies;
    u16 monGender;
    u32 monPersonality;
    MainCallback returnCallback;
};

EWRAM_DATA static struct NamingScreenData *sNamingScreen = NULL;

static const u8 sNamingScreenTextColor[] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY };
static const struct NamingScreenTemplate *const sNamingScreenTemplates[];
static const struct SpriteSheet sSpriteSheets[];
static const struct SpritePalette sSpritePalettes[];
static const struct SpriteTemplate sSpriteTemplate_Cursor;
static const struct SpriteTemplate sSpriteTemplate_UndescoreMain;
static const struct SpriteTemplate sSpriteTemplate_Underscore;
static const struct SpriteTemplate sSpriteTemplate_PCIcon;
static const struct SubspriteTable sSubspriteTable_PCIcon[];

static bool8 KeyboardKeyHandler_Character(u8);
static bool8 KeyboardKeyHandler_PageUpper(u8);
static bool8 KeyboardKeyHandler_PageLower(u8);
static bool8 KeyboardKeyHandler_PageOther(u8);
static bool8 KeyboardKeyHandler_Backspace(u8);
static bool8 KeyboardKeyHandler_OK(u8);

static void CB2_LoadNamingScreen(void);
static void ResetVHBlank(void);
static void NamingScreen_Init(void);
static void NamingScreen_InitBGs(void);
static void NamingScreen_ResetObjectsAndTasks(void);
static void NamingScreen_LoadBGsTilesAndMap(void);
static void NamingScreen_LoadBGsPal(void);
static void NamingScreen_LoadObjectsGfx(void);
static void NamingScreen_CreateObjects(void);
static void CreateCursorSprite(void);
static void CreateTextEntrySprites(void);
static void CreateInputTargetIcon(void);
static void CreateInputHandlerTask(void);
static void Task_HandleInput(u8);
static void CreateNamingScreenTask(void);
static void Task_NamingScreen(u8 taskId);
static bool8 MainState_FadeIn(void);
static void SetSpritesVisible(void);
static void SetCursorInvisibility(u8);
static void SetVBlank(void);
static void VBlankCB_NamingScreen(void);
static bool8 MainState_WaitFadeIn(void);
static void SetInputState(u8);
static void SetCursorFlashing(bool8);
static bool8 MainState_HandleInput(void);
static u8 HandleKeyboardEvent(void);
static void SetCursorPos(s16, s16);
static void GetCursorPos(s16 *x, s16 *y);
static u8 SwapKeyboardPage(void);
static void DeleteTextCharacter(void);
static u8 GetPreviousTextCaretPosition(void);
static void DrawTextEntryBox(void);
static void DrawTextEntry(void);
static void DrawNormalTextEntryBox(void);
static void DrawMonTextEntryBox(void);
static u8 GetKeyRoleAtCursorPos(void);
static void MoveCursorToOKButton(void);
static bool8 AddTextCharacter(void);
static void BufferCharacter(u8);
static u8 GetTextEntryPosition(void);
static void SquishCursor(void);
static void NamingScreen_RedrawOptions(void);
static bool8 MainState_MoveToOKButton(void);
static u8 IsCursorAnimFinished(void);
static bool8 MainState_StartPageSwap(void);
static void StartPageSwapAnim(void);
static void Task_HandlePageSwapAnim(u8);
static bool8 PageSwapAnimState_Init(struct Task *);
static bool8 PageSwapAnimState_1(struct Task *);
static bool8 PageSwapAnimState_2(struct Task *);
static bool8 PageSwapAnimState_3(struct Task *);
static bool8 PageSwapAnimState_Done(struct Task *);
static bool8 MainState_WaitPageSwap(void);
static bool8 MainState_PokemonStore(void);
static void SaveInputText(void);
static void DisplaySentToPCMessage(void);
static void NamingScreen_DrawDialogueFrame(void);
static bool8 MainState_WaitSentToPCMessage(void);
static bool8 MainState_FadeOut(void);
static bool8 MainState_Exit(void);
static void CB2_NamingScreen(void);
static void NamingScreen_ShowBgs(void);
static void NamingScreen_NoIcon(void);
static void NamingScreen_CreatePlayerIcon(void);
static void NamingScreen_CreatePCIcon(void);
static void NamingScreen_CreateMonIcon(void);
static void NamingScreen_CreateWaldaDadIcon(void);
static void NamingScreen_CreateCodeIcon(void);
static void NamingScreen_CreateRivalIcon(void);
static void Input_Disabled(struct Task *);
static void Input_Enabled(struct Task *);
static void Input_Override(struct Task *);
static void MoveCursorToBackButton(void);
static void HandleDpadMovement(struct Task *);
static bool8 IsWideLetter(u8);
static void CallAddGenderIconFunc(void);
static u8 GetInputEvent(void);
static u8 CurrentPageToKeyboardId(s16 x);
static bool8 IsPageSwapAnimNotInProgress(void);
static void AddGenderIconFunc_No(void);
static void AddGenderIconFunc_Yes(void);

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .priority = 1
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 27,
        .priority = 2
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .priority = 3
    }
};

static const struct WindowTemplate sWindowTemplates[WIN_COUNT + 1] =
{
    [WIN_KB_PAGE_1] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 10,
        .width = 19,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0
    },
    [WIN_KB_PAGE_2] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 10,
        .width = 19,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 152
    },
    [WIN_TEXT_ENTRY] = {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 4,
        .width = 15,
        .height = 2,
        .paletteNum = 10,
        .baseBlock = 304
    },
    [WIN_TEXT_ENTRY_BOX] = {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 2,
        .width = 16,
        .height = 2,
        .paletteNum = 10,
        .baseBlock = 334
    },
    [WIN_BANNER] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 11,
        .baseBlock = 366
    },
    DUMMY_WIN_TEMPLATE
};
static const u8 sPCIconOff_Gfx[] = INCGFX_U8("graphics/naming_screen/pc_icon_off.png", ".4bpp");
static const u8 sPCIconOn_Gfx[] = INCGFX_U8("graphics/naming_screen/pc_icon_on.png", ".4bpp");
static const u16 sKeyboard_Pal[] = INCGFX_U16("graphics/naming_screen/keyboard.pal", ".gbapal");
static const u16 sRival_Gfx[] = INCGFX_U16("graphics/naming_screen/rival.png", ".4bpp");
static const u16 sRival_Pal[] = INCGFX_U16("graphics/naming_screen/rival.pal", ".gbapal");

static const u8 *const sTransferredToPCMessages[] =
{
    gText_PkmnTransferredSomeonesPC,
    gText_PkmnTransferredLanettesPC,
    gText_PkmnTransferredSomeonesPCBoxFull,
    gText_PkmnTransferredLanettesPCBoxFull
};

static const u8 sText_AlphabetUpperLower[] = _("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!");

static const u8 sKeyboardChars[][3][12] = {
    [KBPAGE_LETTERS_LOWER] = {
        __("abcdefghijk."),
        __("lmnñopqrstu,"),
        __("vwxyzáéíóúü "),
    },
    [KBPAGE_LETTERS_UPPER] = {
        __("ABCDEFGHIJK."),
        __("LMNÑOPQRSTU,"),
        __("VWXYZÁÉÍÓÚÜ "),
    },
    [KBPAGE_SYMBOLS] = {
        __("0123456789+-"),
        __("…·%():;=¡!¿?"),
        __("“”‘'/♂♀     "),
    }
};

static bool8 TriggerKeyboardChange(void)
{
    sNamingScreen->state = STATE_START_PAGE_SWAP;
    return TRUE;
}

static void CreateNamingScreenTask(void)
{
    CreateTask(Task_NamingScreen, 2);
    SetMainCallback2(CB2_NamingScreen);
}

void DoNamingScreen(u8 templateNum, u8 *destBuffer, u16 monSpeciesOrPlayerGender, u16 monGender, u32 monPersonality, MainCallback returnCallback)
{
    sNamingScreen = Alloc(sizeof(struct NamingScreenData));
    if (!sNamingScreen)
    {
        SetMainCallback2(returnCallback);
    }
    else
    {
        sNamingScreen->templateNum = templateNum;
        sNamingScreen->monSpecies = monSpeciesOrPlayerGender;
        sNamingScreen->monGender = monGender;
        sNamingScreen->monPersonality = monPersonality;
        sNamingScreen->destBuffer = destBuffer;
        sNamingScreen->returnCallback = returnCallback;

        if (templateNum == NAMING_SCREEN_PLAYER)
            StartTimer1();

        SetMainCallback2(CB2_LoadNamingScreen);
    }
}

static void CB2_LoadNamingScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetVHBlank();
        NamingScreen_Init();
        gMain.state++;
        break;
    case 1:
        NamingScreen_InitBGs();
        gMain.state++;
        break;
    case 2:
        NamingScreen_ResetObjectsAndTasks();
        gMain.state++;
        break;
    case 3:
        NamingScreen_LoadBGsTilesAndMap();
        gMain.state++;
        break;
    case 4:
        NamingScreen_LoadBGsPal();
        gMain.state++;
        break;
    case 5:
        NamingScreen_LoadObjectsGfx();
        gMain.state++;
        break;
    case 6:
        NamingScreen_CreateObjects();
        UpdatePaletteFade();
        NamingScreen_ShowBgs();
        gMain.state++;
        break;
    default:
        CreateInputHandlerTask();
        CreateNamingScreenTask();
        break;
    }
}

static void NamingScreen_Init(void)
{
    sNamingScreen->state = STATE_FADE_IN;
    sNamingScreen->bg2vOffset = 0;
    sNamingScreen->bldAlphaTg = 16;
    sNamingScreen->template = sNamingScreenTemplates[sNamingScreen->templateNum];
    sNamingScreen->currentPage = sNamingScreen->template->initialPage;
    sNamingScreen->inputCharBaseXPos = (DISPLAY_WIDTH - sNamingScreen->template->maxChars * 8) / 2 + 6;
    if (sNamingScreen->templateNum == NAMING_SCREEN_WALDA)
        sNamingScreen->inputCharBaseXPos += 11;
    sNamingScreen->keyRepeatStartDelayCopy = gKeyRepeatStartDelay;
    memset(sNamingScreen->textBuffer, EOS, sizeof(sNamingScreen->textBuffer));
    if (sNamingScreen->template->copyExistingString != 0)
        StringCopy(sNamingScreen->textBuffer, sNamingScreen->destBuffer);
    gKeyRepeatStartDelay = 16;
}

static void SetSpritesVisible(void)
{
    u8 i;
    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].inUse)
            gSprites[i].invisible = FALSE;
    }
    SetCursorInvisibility(FALSE);
}

static void NamingScreen_InitBGs(void)
{
    u8 i;

    DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));

    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);

    InitStandardTextBoxWindows();
    InitTextBoxGfxAndPrinters();

    for (i = 0; i < WIN_COUNT; i++)
        sNamingScreen->windows[i] = AddWindow(&sWindowTemplates[i]);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG2 | BLDCNT_TGT2_BG3);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
}

static void NamingScreen_ResetObjectsAndTasks(void)
{
	ResetPaletteFade();
	ResetSpriteData();
	FreeAllSpritePalettes();
	ResetTasks();
}

static void NamingScreen_LoadBGsTilesAndMap(void)
{
    DecompressDataWithHeaderVram(gNamingScreenBGTiles,      	((void *)BG_VRAM + 0x4000));
    DecompressDataWithHeaderVram(gNamingScreenBGMap,			((void *)BG_VRAM + 0xE000));
    DecompressDataWithHeaderVram(gNamingScreenCharUpperMap,     ((void *)BG_VRAM + 0xD800 + 0x200));
	DecompressDataWithHeaderVram(gNamingScreenButtonsEng,   	((void *)BG_VRAM + 0xE000 + 0x440));
}

static void Task_NamingScreen(u8 taskId)
{
    switch (sNamingScreen->state)
    {
    case STATE_FADE_IN:
        MainState_FadeIn();
        SetSpritesVisible();
        SetVBlank();
        break;
    case STATE_WAIT_FADE_IN:
        MainState_WaitFadeIn();
        break;
    case STATE_HANDLE_INPUT:
        MainState_HandleInput();
        break;
    case STATE_MOVE_TO_OK_BUTTON:
        MainState_MoveToOKButton();
        break;
    case STATE_START_PAGE_SWAP:
        MainState_StartPageSwap();
        break;
    case STATE_WAIT_PAGE_SWAP:
        MainState_WaitPageSwap();
        break;
    case STATE_PRESSED_OK:
        MainState_PokemonStore();
        break;
    case STATE_WAIT_SENT_TO_PC_MESSAGE:
        MainState_WaitSentToPCMessage();
        break;
    case STATE_FADE_OUT:
        MainState_FadeOut();
        break;
    case STATE_EXIT:
        MainState_Exit();
        break;
    }
}

static bool8 MainState_FadeIn(void)
{
    sNamingScreen->currentPage = KBPAGE_LETTERS_UPPER;
    NamingScreen_RedrawOptions();
    DrawTextEntry();
    DrawTextEntryBox();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    sNamingScreen->state++;
    return FALSE;
}

static bool8 MainState_WaitFadeIn(void)
{
    if (!gPaletteFade.active)
    {
        SetInputState(INPUT_STATE_ENABLED);
        SetCursorFlashing(TRUE);
        sNamingScreen->state++;
    }
    return FALSE;
}

static bool8 MainState_HandleInput(void)
{
    return HandleKeyboardEvent();
}

static bool8 MainState_MoveToOKButton(void)
{
    if (IsCursorAnimFinished())
    {
        SetInputState(INPUT_STATE_ENABLED);
        MoveCursorToOKButton();
        sNamingScreen->state = STATE_HANDLE_INPUT;
    }
    return FALSE;
}

static bool8 MainState_PokemonStore(void)
{
    SaveInputText();
    SetInputState(INPUT_STATE_DISABLED);
    SetCursorFlashing(FALSE);
    if (sNamingScreen->templateNum == NAMING_SCREEN_CAUGHT_MON &&
        CalculatePlayerPartyCount() >= PARTY_SIZE)
    {
        DisplaySentToPCMessage();
        sNamingScreen->state = STATE_WAIT_SENT_TO_PC_MESSAGE;
        return FALSE;
    }
    else
    {
        sNamingScreen->state = STATE_FADE_OUT;
        return TRUE;  //Exit the naming screen
    }
}

static bool8 MainState_FadeOut(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    sNamingScreen->state++;
    return FALSE;
}

static bool8 MainState_Exit(void)
{
    if (!gPaletteFade.active)
    {
        if (sNamingScreen->templateNum == NAMING_SCREEN_PLAYER)
            SeedRngAndSetTrainerId();
        SetMainCallback2(sNamingScreen->returnCallback);
        DestroyTask(FindTaskIdByFunc(Task_NamingScreen));
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sNamingScreen);
    }
    return FALSE;
}

static void DisplaySentToPCMessage(void)
{
    u8 stringToDisplay = 0;

    if (!IsDestinationBoxFull())
    {
        StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON)));
        StringCopy(gStringVar2, sNamingScreen->destBuffer);
    }
    else
    {
        StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON)));
        StringCopy(gStringVar2, sNamingScreen->destBuffer);
        StringCopy(gStringVar3, GetBoxNamePtr(GetPCBoxToSendMon()));
        stringToDisplay = 2;
    }

    if (FlagGet(FLAG_SYS_PC_LANETTE))
        stringToDisplay++;

    StringExpandPlaceholders(gStringVar4, sTransferredToPCMessages[stringToDisplay]);
    NamingScreen_DrawDialogueFrame();
    //gTextFlags.canABSpeedUpPrint = TRUE;
    AddTextPrinterParameterized2(0, FONT_NORMAL, gStringVar4, GetPlayerTextSpeedDelay(), 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static bool8 MainState_WaitSentToPCMessage(void)
{
    RunTextPrinters();
    if (!IsTextPrinterActiveOnWindow(0) && JOY_NEW(A_BUTTON))
        sNamingScreen->state = STATE_FADE_OUT;

    return FALSE;
}

static bool8 MainState_StartPageSwap(void)
{
    SetInputState(INPUT_STATE_DISABLED);
    StartPageSwapAnim();
    SetCursorInvisibility(TRUE);
    PlaySE(SE_WIN_OPEN);
    sNamingScreen->state = STATE_WAIT_PAGE_SWAP;
    return FALSE;
}

static bool8 MainState_WaitPageSwap(void)
{
    s16 cursorX;
    s16 cursorY;

    if (IsPageSwapAnimNotInProgress())
    {
        sNamingScreen->state = STATE_HANDLE_INPUT;
        sNamingScreen->currentPage++;
        sNamingScreen->currentPage %= KBPAGE_COUNT;
        SetInputState(INPUT_STATE_ENABLED);
        GetCursorPos(&cursorX, &cursorY);
        SetCursorPos(cursorX, cursorY);
        SetCursorInvisibility(FALSE);
    }
    return FALSE;
}

//--------------------------------------------------
// Page Swap
//--------------------------------------------------
#define tState data[0]
#define tFrameCount data[1]

static bool8 (*const sPageSwapAnimStateFuncs[])(struct Task *) =
{
    PageSwapAnimState_Init,
    PageSwapAnimState_1,
    PageSwapAnimState_2,
    PageSwapAnimState_3,
    PageSwapAnimState_Done,
};

static void StartPageSwapAnim(void)
{
    u8 taskId;

    taskId = CreateTask(Task_HandlePageSwapAnim, 0);
    Task_HandlePageSwapAnim(taskId);
}

static void Task_HandlePageSwapAnim(u8 taskId)
{
    while (sPageSwapAnimStateFuncs[gTasks[taskId].tState](&gTasks[taskId]) != 0);
}

static bool8 IsPageSwapAnimNotInProgress(void)
{
    if (FindTaskIdByFunc(Task_HandlePageSwapAnim) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

static bool8 PageSwapAnimState_Init(struct Task *task)
{
    sNamingScreen->bldAlphaTg = 16;
    sNamingScreen->bg2vOffset = 0;
    task->tState++;
    return FALSE;
}

static bool8 PageSwapAnimState_1(struct Task *task)
{
    u8 a = sNamingScreen->bldAlphaTg;
    u8 b = 16;
    u8 c = sNamingScreen->bg2vOffset;
    task->tFrameCount += 1;
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(a, b)); 
	sNamingScreen->bldAlphaTg = a - 1;
	sNamingScreen->bg2vOffset = c - 2;
	if ((a - 1) == 0)
    {
		task->tState++;
    }
    return FALSE;
}

static bool8 PageSwapAnimState_2(struct Task *task)
{
	u8 prevPage = sNamingScreen->currentPage;
	
	LoadPalette(gNamingScreenPal, 0, 0xE0);
	
	if (prevPage == KBPAGE_LETTERS_UPPER)
	{
		LoadPalette(gNamingScreenSelPal, 0x20, 0x20);
		DecompressDataWithHeaderVram(gNamingScreenCharLowerMap,   ((void *)BG_VRAM + 0xD800 + 0x200));
	}
	if (prevPage == KBPAGE_LETTERS_LOWER)
	{
		LoadPalette(gNamingScreenSelPal, 0x30, 0x20);
		DecompressDataWithHeaderVram(gNamingScreenCharOtherMap,   ((void *)BG_VRAM + 0xD800 + 0x200));
	}
	if (prevPage == KBPAGE_SYMBOLS)
	{
		LoadPalette(gNamingScreenSelPal, 0x10, 0x20);
		DecompressDataWithHeaderVram(gNamingScreenCharUpperMap,   ((void *)BG_VRAM + 0xD800 + 0x200));
	}	
	task->tState++;
    return FALSE;
}

static bool8 PageSwapAnimState_3(struct Task *task)
{
	u8 a = sNamingScreen->bldAlphaTg;
	u8 b = 16;
	task->tFrameCount += 1;
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(a, b));
	++sNamingScreen->bldAlphaTg;
	sNamingScreen->bg2vOffset += 2;
	if ((a + 1) == 16)
    {
		SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
		task->tState++;
    }
    return FALSE;
}

static bool8 PageSwapAnimState_Done(struct Task *task)
{
    DestroyTask(FindTaskIdByFunc(Task_HandlePageSwapAnim));
    return 0;
}

#undef tState
#undef tFrameCount

//--------------------------------------------------
// Cursor blink
//--------------------------------------------------

#define tIdent data[0]


//--------------------------------------------------
// Cursor
//--------------------------------------------------
#define sX          data[0]
#define sY          data[1]
#define sPrevX      data[2]
#define sPrevY      data[3]
#define sInvisible  data[4] & 0x00FF
#define sColor      data[5]
#define sColorIncr  data[6]
#define sColorDelay data[7]

static void SpriteCB_Cursor(struct Sprite *sprite)
{
    if (sprite->animEnded)
        StartSpriteAnim(sprite, 0);

    // Hide cursor when on button column
    sprite->invisible = sprite->sInvisible;
    if (sprite->sY == FILE_COUNT - 1)
        sprite->invisible = TRUE;

    if (sprite->invisible || (sprite->sInvisible) == FALSE
       || sprite->sX != sprite->sPrevX || sprite->sY != sprite->sPrevY)
    {
        sprite->sColor = 0;
        sprite->sColorIncr = 2;
        sprite->sColorDelay = 2;
    }

    sprite->sColorDelay--;
    if (sprite->sColorDelay == 0)
    {
        sprite->sColor += sprite->sColorIncr;
        if (sprite->sColor == 16 || sprite->sColor == 0)
            sprite->sColorIncr = -sprite->sColorIncr;
        sprite->sColorDelay = 2;
    }

    if ((sprite->sInvisible) != FALSE)
    {
        s8 gb = sprite->sColor;
        s8 r = sprite->sColor >> 1;
        u16 index = IndexOfSpritePaletteTag(PALTAG_CURSOR) * 16 + 0x0101;

        MultiplyInvertedPaletteRGBComponents(index, r, gb, gb);
    }
}

#define sDelay  data[0]
#define sXPosId data[1]
static void SpriteCB_InputArrow(struct Sprite *sprite)
{
    const s16 x[] = {0, -4, -2, -1};

    if (sprite->sDelay == 0 || --sprite->sDelay == 0)
    {
        sprite->sDelay = 8;
        sprite->sXPosId = (sprite->sXPosId + 1) & 3;
    }
    sprite->x2 = x[sprite->sXPosId];
}
#undef sDelay

#define sId     data[0]
#define sYPosId data[1]
#define sDelay  data[2]
static void SpriteCB_Underscore(struct Sprite *sprite)
{
    const s16 y[] = {2, 3, 2, 1};
    u8 pos;

    pos = GetTextEntryPosition();
    if (pos != (u8)sprite->sId)
    {
        sprite->y2 = 0;
        sprite->sYPosId = 0;
        sprite->sDelay = 0;
    }
    else
    {
        sprite->y2 = y[sprite->sYPosId];
        sprite->sDelay++;
        if (sprite->sDelay > 8)
        {
            sprite->sYPosId = (sprite->sYPosId + 1) & 3;
            sprite->sDelay = 0;
        }
    }
}

#undef sId
#undef sYPosId
#undef sDelay

static void NamingScreen_CreateObjects(void)
{
    CreateCursorSprite();
    CreateTextEntrySprites();
    CreateInputTargetIcon();
}

static void CreateCursorSprite(void)
{
    sNamingScreen->cursorSpriteId = CreateSprite(&sSpriteTemplate_Cursor, 38, 88, 1);
    SetCursorInvisibility(TRUE);
    gSprites[sNamingScreen->cursorSpriteId].oam.priority = 1;
    gSprites[sNamingScreen->cursorSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
    gSprites[sNamingScreen->cursorSpriteId].sColorIncr = 1; // ? immediately overwritten
    gSprites[sNamingScreen->cursorSpriteId].sColorIncr = 2;
    SetCursorPos(0, 0);
}

static const u8 sPageToKeyboardId[][KBCOL_COUNT] = { // Character Coords
    {0,  2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 22},  //Upper page
    {0,  2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 22},  //Lower page
    {0,  2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 22},  //Others page
};

static u8 CurrentPageToKeyboardId(s16 x)
{
    return sPageToKeyboardId[sNamingScreen->currentPage][x];
}

static void SetCursorPos(s16 x, s16 y)
{
    struct Sprite *cursorSprite = &gSprites[sNamingScreen->cursorSpriteId];

    cursorSprite->x = CurrentPageToKeyboardId(x) * 8 + 28;
    cursorSprite->y = y * 24 + 80;
    cursorSprite->sPrevX = cursorSprite->sX;
    cursorSprite->sPrevY = cursorSprite->sY;
    cursorSprite->sX = x;
    cursorSprite->sY = y;
}

static void GetCursorPos(s16 *x, s16 *y)
{
    struct Sprite *cursorSprite = &gSprites[sNamingScreen->cursorSpriteId];

    *x = cursorSprite->sX;
    *y = cursorSprite->sY;
}

static void MoveCursorToOKButton(void)
{
    LoadPalette(gNamingScreenPal, 0, 0xE0);
	LoadPalette(gNamingScreenSelPal, 0x50, 0x20);
	SetCursorPos(4, FILE_COUNT - 1);
}

static void MoveCursorToBackButton(void)
{
	LoadPalette(gNamingScreenPal, 0, 0xE0);
	LoadPalette(gNamingScreenSelPal, 0x40, 0x20);
	SetCursorPos(3, FILE_COUNT - 1);
}

static void SetCursorInvisibility(bool8 invisible)
{
    gSprites[sNamingScreen->cursorSpriteId].data[4] &= ~0xFF;
    gSprites[sNamingScreen->cursorSpriteId].data[4] |= invisible; // sInvisible
    StartSpriteAnim(&gSprites[sNamingScreen->cursorSpriteId], 0);
}

static void SetCursorFlashing(bool8 flashing)
{
    gSprites[sNamingScreen->cursorSpriteId].data[4] &= 0xFF;
    gSprites[sNamingScreen->cursorSpriteId].data[4] |= flashing << 8; // sFlashing
}

static void SquishCursor(void)
{
    StartSpriteAnim(&gSprites[sNamingScreen->cursorSpriteId], 1);
}

static bool8 IsCursorAnimFinished(void)
{
    return gSprites[sNamingScreen->cursorSpriteId].animEnded;
}

static const u8 sButtonKeyRoles[] = {KEY_ROLE_PAGE_UPPER, KEY_ROLE_PAGE_LOWER, KEY_ROLE_PAGE_OTHER, KEY_ROLE_BACKSPACE, KEY_ROLE_OK};

static u8 GetKeyRoleAtCursorPos(void)
{
    s16 cursorX;
    s16 cursorY;

    GetCursorPos(&cursorX, &cursorY);
    if (cursorY < FILE_COUNT - 1)
        return KEY_ROLE_CHAR;
    else
        return sButtonKeyRoles[cursorX];
}

static void CreateTextEntrySprites(void)
{
    u8 spriteId;
    s16 xPos;
    u8 i;

    xPos = sNamingScreen->inputCharBaseXPos - 5;
    spriteId = CreateSprite(&sSpriteTemplate_UndescoreMain, xPos, 40, 0);
    gSprites[spriteId].oam.priority = 3;
    gSprites[spriteId].invisible = TRUE;
    xPos = sNamingScreen->inputCharBaseXPos;
    for (i = 0; i < sNamingScreen->template->maxChars; i++, xPos += 8)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Underscore, xPos + 3, 44, 0);
        gSprites[spriteId].oam.priority = 3;
        gSprites[spriteId].data[0] = i;
        gSprites[spriteId].invisible = TRUE;
    }
}

#undef sX
#undef sY
#undef sPrevX
#undef sPrevY
#undef sInvisible
#undef sFlashing
#undef sColor
#undef sColorIncr
#undef sColorDelay

//--------------------------------------------------
// Icon creation (the thing you're naming or giving input to)
//--------------------------------------------------

static void (*const sIconFunctions[])(void) =
{
    NamingScreen_NoIcon,
    NamingScreen_CreatePlayerIcon,
    NamingScreen_CreatePCIcon,
    NamingScreen_CreateMonIcon,
    NamingScreen_CreateWaldaDadIcon,
    NamingScreen_CreateCodeIcon,
    NamingScreen_CreateRivalIcon,
};

static void CreateInputTargetIcon(void)
{
    sIconFunctions[sNamingScreen->template->iconFunction]();
}

static void NamingScreen_NoIcon(void)
{

}

static void NamingScreen_CreatePlayerIcon(void)
{
    u16 rivalGfxId;
    u8 spriteId;

    rivalGfxId = GetRivalAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, (enum Gender)sNamingScreen->monSpecies);
    spriteId = CreateObjectGraphicsSprite(rivalGfxId, SpriteCallbackDummy, 40, 26, 0);
    gSprites[spriteId].oam.priority = 3;
    StartSpriteAnim(&gSprites[spriteId], ANIM_STD_GO_SOUTH);
}

static void NamingScreen_CreatePCIcon(void)
{
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_PCIcon, 40, 26, 0);
    SetSubspriteTables(&gSprites[spriteId], sSubspriteTable_PCIcon);
    gSprites[spriteId].oam.priority = 3;
}

static void NamingScreen_CreateMonIcon(void)
{
    u8 spriteId;

    LoadMonIconPalettes();
    spriteId = CreateMonIcon(sNamingScreen->monSpeciesOrPlayerGender, SpriteCallbackDummy, 40, 26, 0, sNamingScreen->monPersonality);
    gSprites[spriteId].oam.priority = 3;
}

static void NamingScreen_CreateWaldaDadIcon(void)
{
    u8 spriteId;

    spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_MAN_1, SpriteCallbackDummy, 40, 26, 0);
    gSprites[spriteId].oam.priority = 3;
    StartSpriteAnim(&gSprites[spriteId], ANIM_STD_GO_SOUTH);
}

static void NamingScreen_CreateCodeIcon(void)
{
    u8 spriteId;
    spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_MYSTERY_GIFT_MAN, SpriteCallbackDummy, 40, 26, 0);
    gSprites[spriteId].oam.priority = 3;
}

static const union AnimCmd sAnim_Rival[] =
{
    ANIMCMD_FRAME( 0, 10),
    ANIMCMD_FRAME(24, 10),
    ANIMCMD_FRAME( 0, 10),
    ANIMCMD_FRAME(32, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_Rival[] =
{
    sAnim_Rival
};

static void NamingScreen_CreateRivalIcon(void)
{
    const struct SpriteSheet sheet = {
        sRival_Gfx, 0x900, GFXTAG_RIVAL
    };
    const struct SpritePalette palette = {
        sRival_Pal, PALTAG_RIVAL
    };
    struct SpriteTemplate template;
    const struct SubspriteTable * tables_p;
    u8 spriteId;

    CopyObjectGraphicsInfoToSpriteTemplate(OBJ_EVENT_GFX_RED_NORMAL, SpriteCallbackDummy, &template, &tables_p);

    template.tileTag = sheet.tag;
    template.paletteTag = palette.tag;
    template.anims = sAnims_Rival;
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&palette);
    spriteId = CreateSprite(&template, 40, 26, 0);
    gSprites[spriteId].oam.priority = 3;
}

static void NamingScreen_RedrawOptions(void)
{
	LoadPalette(gNamingScreenPal, 0x00, 0xD0);
	
	if (sNamingScreen->currentPage == KBPAGE_LETTERS_LOWER)
		LoadPalette(gNamingScreenSelPal, 0x20, 0x20);
	if (sNamingScreen->currentPage == KBPAGE_LETTERS_UPPER)
		LoadPalette(gNamingScreenSelPal, 0x10, 0x20);
	if (sNamingScreen->currentPage == KBPAGE_SYMBOLS)
		LoadPalette(gNamingScreenSelPal, 0x30, 0x20);
}

static bool8 (*const sKeyboardKeyHandlers[])(u8) =
{
    [KEY_ROLE_CHAR]            = KeyboardKeyHandler_Character,
    [KEY_ROLE_PAGE_UPPER]      = KeyboardKeyHandler_PageUpper,
    [KEY_ROLE_PAGE_LOWER]      = KeyboardKeyHandler_PageLower,
    [KEY_ROLE_PAGE_OTHER]      = KeyboardKeyHandler_PageOther,
    [KEY_ROLE_BACKSPACE]       = KeyboardKeyHandler_Backspace,
    [KEY_ROLE_OK]              = KeyboardKeyHandler_OK,
};

static bool8 HandleKeyboardEvent(void)
{
    s16 cursorX;
    s16 cursor_X = 0;
    s16 cursorY;
    u8 input = GetInputEvent();
    u8 keyRole = GetKeyRoleAtCursorPos();

    if (input == INPUT_SELECT)
    {
        GetCursorPos(&cursorX, &cursorY);
	
		if (cursorY == FILE_COUNT - 1)
		{
			if (cursorX == 0)
				cursor_X = 1;
			else if (cursorX == 1)
				cursor_X = 2;
			else if (cursorX == 2)
				cursor_X = 0;
			else if (cursorX > 2)
				cursor_X = cursorX;
			SetCursorPos(cursor_X, cursorY);
		}
        return SwapKeyboardPage();
    }
    else if (input == INPUT_B_BUTTON)
    {
        LoadPalette(gNamingScreenPal, 0, 0xE0);
		LoadPalette(gNamingScreenSelPal, 0x40, 0x20);
        DeleteTextCharacter();
        return FALSE;
    }
    else if (input == INPUT_START)
    {
        MoveCursorToOKButton();
        return FALSE;
    }
    else
    {
        return sKeyboardKeyHandlers[keyRole](input);
    }
}

static bool8 KeyboardKeyHandler_Character(u8 input)
{
    if (input == INPUT_A_BUTTON)
    {
        bool8 textFull = AddTextCharacter();

        SquishCursor();
        if (textFull)
        {
            SetInputState(INPUT_STATE_DISABLED);
            sNamingScreen->state = STATE_MOVE_TO_OK_BUTTON;
        }
        if (sNamingScreen->currentPage == KBPAGE_LETTERS_UPPER && GetTextEntryPosition() == 1)
			sNamingScreen->state = STATE_START_PAGE_SWAP;
    }
    return FALSE;
}

static bool8 KeyboardKeyHandler_PageUpper(u8 event)
{
    NamingScreen_RedrawOptions();
	if (sNamingScreen->currentPage == KBPAGE_LETTERS_UPPER)
		return FALSE;
	else
	{
		sNamingScreen->currentPage = KBPAGE_SYMBOLS;
		TriggerKeyboardChange();
	}
    return FALSE;
}

static bool8 KeyboardKeyHandler_PageLower(u8 event)
{
    NamingScreen_RedrawOptions();
	if (sNamingScreen->currentPage == KBPAGE_LETTERS_LOWER)
		return FALSE;
	else
	{
		sNamingScreen->currentPage = KBPAGE_LETTERS_UPPER;
		TriggerKeyboardChange();
	}
    return FALSE;
}

static bool8 KeyboardKeyHandler_PageOther(u8 event)
{
    NamingScreen_RedrawOptions();
	if (sNamingScreen->currentPage == KBPAGE_SYMBOLS)
		return FALSE;
	else
	{
		sNamingScreen->currentPage = KBPAGE_LETTERS_LOWER;
		TriggerKeyboardChange();
	}
    return FALSE;
}

static bool8 KeyboardKeyHandler_Backspace(u8 event)
{
	LoadPalette(gNamingScreenPal, 0, 0xE0);
	LoadPalette(gNamingScreenSelPal, 0x40, 0x20);
    if (event == INPUT_A_BUTTON)
        DeleteTextCharacter();
    return FALSE;
}

static bool8 KeyboardKeyHandler_OK(u8 event)
{
    MoveCursorToOKButton();
	if (event == INPUT_A_BUTTON)
    {
        PlaySE(SE_SELECT);
        sNamingScreen->state = STATE_PRESSED_OK;
        return TRUE;
    }
    else
        return FALSE;
}

static bool8 SwapKeyboardPage(void)
{
    sNamingScreen->state = STATE_START_PAGE_SWAP;
    return TRUE;
}

//--------------------------------------------------
// Input handling
//--------------------------------------------------

#define tState         data[0]
#define tKeyboardEvent data[1]
#define tButtonId      data[2]

static void (*const sInputFuncs[])(struct Task *) =
{
    [INPUT_STATE_DISABLED] = Input_Disabled,
    [INPUT_STATE_ENABLED]  = Input_Enabled,
    [INPUT_STATE_OVERRIDE] = Input_Override,
};

static void CreateInputHandlerTask(void)
{
    CreateTask(Task_HandleInput, 1);
}

static u8 GetInputEvent(void)
{
    u8 taskId = FindTaskIdByFunc(Task_HandleInput);

    return gTasks[taskId].tKeyboardEvent;
}

static void SetInputState(u8 state)
{
    u8 taskId = FindTaskIdByFunc(Task_HandleInput);

    gTasks[taskId].tState = state;
}

static void Task_HandleInput(u8 taskId)
{
    sInputFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

static void Input_Disabled(struct Task *task)
{
    task->tKeyboardEvent = INPUT_NONE;
}

static void Input_Enabled(struct Task *task)
{
    task->tKeyboardEvent = INPUT_NONE;

    if (JOY_NEW(A_BUTTON))
        task->tKeyboardEvent = INPUT_A_BUTTON;
    else if (JOY_NEW(B_BUTTON))
    {
        task->tKeyboardEvent = INPUT_B_BUTTON;
        MoveCursorToBackButton();
    }
    else if (JOY_NEW(SELECT_BUTTON))
        task->tKeyboardEvent = INPUT_SELECT;
    else if (JOY_NEW(START_BUTTON))
    {
        task->tKeyboardEvent = INPUT_START;
        MoveCursorToOKButton();
    }
    else
        HandleDpadMovement(task);
}

static void Input_Override(struct Task *task)
{
    task->tKeyboardEvent = INPUT_NONE;
}

static void HandleDpadMovement(struct Task *task)
{
    const s16 sDpadDeltaX[] =
    {
        [INPUT_NONE]       = 0,
        [INPUT_DPAD_UP]    = 0,
        [INPUT_DPAD_DOWN]  = 0,
        [INPUT_DPAD_LEFT]  = -1,
        [INPUT_DPAD_RIGHT] = 1
    };

    const s16 sDpadDeltaY[] =
    {
        [INPUT_NONE]       = 0,
        [INPUT_DPAD_UP]    = -1,
        [INPUT_DPAD_DOWN]  = 1,
        [INPUT_DPAD_LEFT]  = 0,
        [INPUT_DPAD_RIGHT] = 0
    };

    const s16 sKeyRowToButtonRow[] = {0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    const s16 sButtonRowToKeyRow[] = {0, 1, 3, 6, 10};

    s16 cursorX;
    s16 cursorY;
    u16 input;
    s16 prevCursorX;
    s16 prevCursorY;

    GetCursorPos(&cursorX, &cursorY);
    input = INPUT_NONE;
    if (JOY_REPEAT(DPAD_UP))
        input = INPUT_DPAD_UP;
    if (JOY_REPEAT(DPAD_DOWN))
        input = INPUT_DPAD_DOWN;
    if (JOY_REPEAT(DPAD_LEFT))
        input = INPUT_DPAD_LEFT;
    if (JOY_REPEAT(DPAD_RIGHT))
        input = INPUT_DPAD_RIGHT;

    // Get new cursor position
    prevCursorX = cursorX;
    prevCursorY = cursorY;
    cursorX += sDpadDeltaX[input];
    cursorY += sDpadDeltaY[input];

    // Wrap cursor position in the Y direction
    if (cursorY < 0)
        cursorY = FILE_COUNT - 1;
    if (cursorY > FILE_COUNT - 1)
        cursorY = 0;


    // Handle moving on/off the bottom button row
    if (sDpadDeltaY[input] != 0)
    {
        if (prevCursorY < FILE_COUNT - 1 && cursorY == FILE_COUNT - 1)
        {
            // Moved from the keyboard onto the buttons.
            cursorX = sKeyRowToButtonRow[prevCursorX];
        }
        else if (prevCursorY == FILE_COUNT - 1 && cursorY < FILE_COUNT - 1)
        {
            NamingScreen_RedrawOptions();
            cursorX = sButtonRowToKeyRow[prevCursorX];
        }
    }

    // Wrap cursor position in the X direction
    if (cursorY == FILE_COUNT - 1)
    {
        // There are only 3 keys in the button column
        // so wrap Y accordingly
        if (cursorX < 0)
            cursorX = 4;
        if (cursorX > 4)
            cursorX = 0;

        if (cursorX == 0)
            task->tButtonId = FNKEY_CASE_UPPER;
        else if (cursorX == 1)
            task->tButtonId = FNKEY_CASE_LOWER;
        else if (cursorX == 2)
            task->tButtonId = FNKEY_CASE_OTHER;
        else if (cursorX == 3)
            task->tButtonId = FNKEY_BACK;
        else if (cursorX == 4)
            task->tButtonId = FNKEY_OK;
    }
    else
    {
        if (cursorX < 0)
            cursorX = KBCOL_COUNT - 1;
        if (cursorX > KBCOL_COUNT - 1)
            cursorX = 0;
    }
    SetCursorPos(cursorX, cursorY);
}

#undef tState
#undef tKeyboardEvent
#undef tButtonId

static void DrawNormalTextEntryBox(void)
{   
    FillWindowPixelBuffer(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], PIXEL_FILL(0));
    if (GET_LANGUAGE() == PT)
        AddTextPrinterParameterized3(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], FONT_NORMAL, 1, 1, sNamingScreenTextColor, 0xFF, sNamingScreen->template->titlePt);
    else if (GET_LANGUAGE() == ES)
        AddTextPrinterParameterized3(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], FONT_NORMAL, 1, 1, sNamingScreenTextColor, 0xFF, sNamingScreen->template->titleSpa);
    else
        AddTextPrinterParameterized3(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], FONT_NORMAL, 1, 1, sNamingScreenTextColor, 0xFF, sNamingScreen->template->title);
    CopyWindowToVram(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], COPYWIN_FULL);
    PutWindowTilemap(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX]);
}

static void DrawMonTextEntryBox(void)
{
    u8 buffer[0x20];
    // Put the species name in gStringVar1 and expand the title template
    // so placeholders like {STR_VAR_1} are replaced correctly.
    StringCopy(gStringVar1, GetSpeciesName(sNamingScreen->monSpeciesOrPlayerGender));
    if (GET_LANGUAGE() == PT)
        StringExpandPlaceholders(buffer, sNamingScreen->template->titlePt);
    else if (GET_LANGUAGE() == ES)
        StringExpandPlaceholders(buffer, sNamingScreen->template->titleSpa);
    else
        StringExpandPlaceholders(buffer, sNamingScreen->template->title);
    FillWindowPixelBuffer(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], PIXEL_FILL(0));
    AddTextPrinterParameterized3(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], FONT_NORMAL, 1, 1, sNamingScreenTextColor, 0xFF, buffer);
    CopyWindowToVram(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX], COPYWIN_FULL);
    PutWindowTilemap(sNamingScreen->windows[WIN_TEXT_ENTRY_BOX]);
}

static void (*const sDrawTextEntryBoxFuncs[])(void) =
{
    [NAMING_SCREEN_PLAYER]     = DrawNormalTextEntryBox,
    [NAMING_SCREEN_BOX]        = DrawNormalTextEntryBox,
    [NAMING_SCREEN_CAUGHT_MON] = DrawMonTextEntryBox,
    [NAMING_SCREEN_NICKNAME]   = DrawMonTextEntryBox,
    [NAMING_SCREEN_WALDA]      = DrawNormalTextEntryBox,
    [NAMING_SCREEN_CODE]       = DrawNormalTextEntryBox,
    [NAMING_SCREEN_RIVAL]      = DrawNormalTextEntryBox
};

static void DrawTextEntryBox(void)
{
    sDrawTextEntryBoxFuncs[sNamingScreen->templateNum]();
}

static void (*const sAddGenderIconFuncs[])(void) = {
    AddGenderIconFunc_No,
    AddGenderIconFunc_Yes
};

static void CallAddGenderIconFunc(void)
{
    sAddGenderIconFuncs[sNamingScreen->template->addGenderIcon]();
}

static void AddGenderIconFunc_No(void)
{

}

static const u8 sGenderColors[2][3] =
{
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_BLUE, TEXT_COLOR_BLUE},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED}
};

static void AddGenderIconFunc_Yes(void)
{
    u8 genderSymbol[2];
    bool8 gender = MALE;

    StringCopy(genderSymbol, gText_MaleSymbol);

    if (sNamingScreen->monGender != MON_GENDERLESS)
    {
        if (sNamingScreen->monGender == MON_FEMALE)
        {
            StringCopy(genderSymbol, gText_FemaleSymbol);
            gender = FEMALE;
        }
        AddTextPrinterParameterized3(sNamingScreen->windows[2], 2, 110, 1, sGenderColors[gender], 0xFF, genderSymbol);
    }
}

static u8 GetCharAtKeyboardPos(s16 x, s16 y)
{
    return sKeyboardChars[sNamingScreen->currentPage][y][x];
}


static u8 GetTextEntryPosition(void)
{
    u8 i;

    for (i = 0; i < sNamingScreen->template->maxChars; i++)
    {
        if (sNamingScreen->textBuffer[i] == EOS)
            return i;
    }
    return sNamingScreen->template->maxChars - 1;
}

static u8 GetPreviousTextCaretPosition(void)
{
    s8 i;

    for (i = sNamingScreen->template->maxChars - 1; i > 0; i--)
    {
        if (sNamingScreen->textBuffer[i] != EOS)
            return i;
    }
    return 0;
}

static void DeleteTextCharacter(void)
{
    u8 index;
    u8 keyRole;

    index = GetPreviousTextCaretPosition();
    sNamingScreen->textBuffer[index] = CHAR_SPACE;
    DrawTextEntry();
    CopyBgTilemapBufferToVram(3);
    sNamingScreen->textBuffer[index] = EOS;
    keyRole = GetKeyRoleAtCursorPos();

    // The below flashes the Back key once on delete
    // It incorrectly leaves the Back key 1 shade lighter than its default
    if (keyRole == KEY_ROLE_CHAR || keyRole == KEY_ROLE_BACKSPACE)
    PlaySE(SE_BALL);
}

static bool8 AddTextCharacter(void)
{
    s16 x;
    s16 y;

    GetCursorPos(&x, &y);
    BufferCharacter(GetCharAtKeyboardPos(x, y));
    DrawTextEntry();
    CopyBgTilemapBufferToVram(3);
    PlaySE(SE_SELECT);

    if (GetPreviousTextCaretPosition() != sNamingScreen->template->maxChars - 1)
        return FALSE;
    else
        return TRUE;
}

static void BufferCharacter(u8 ch)
{
    u8 index = GetTextEntryPosition();
    sNamingScreen->textBuffer[index] = ch;
}

static void SaveInputText(void)
{
    u8 i;

    for (i = 0; i < sNamingScreen->template->maxChars; i++)
    {
        if (sNamingScreen->textBuffer[i] != CHAR_SPACE && sNamingScreen->textBuffer[i] != EOS)
        {
            StringCopyN(sNamingScreen->destBuffer, sNamingScreen->textBuffer, sNamingScreen->template->maxChars + 1);
            break;
        }
    }
}

static void NamingScreen_LoadObjectsGfx(void)
{
    LoadSpriteSheets(sSpriteSheets);
    LoadSpritePalettes(sSpritePalettes);
}

static void NamingScreen_LoadBGsPal(void)
{
    LoadPalette(gNamingScreenPal, 0, 0xE0);
    LoadPalette(gNamingScreenSelPal, 0x10, 0x20);
    LoadPalette(gNamingScreenTextPal, 0xA0, 0x20);
}

static void DrawTextEntry(void)
{
    u8 i;
    u8 temp[2];
    u16 extraWidth;
    u8 maxChars = sNamingScreen->template->maxChars;
    u16 x = sNamingScreen->inputCharBaseXPos - 0x40;

    FillWindowPixelBuffer(sNamingScreen->windows[WIN_TEXT_ENTRY], PIXEL_FILL(0));

    for (i = 0; i < maxChars; i++)
    {
        temp[0] = sNamingScreen->textBuffer[i];
        temp[1] = gText_ExpandedPlaceholder_Empty[0];
        extraWidth = (IsWideLetter(temp[0]) == TRUE) ? 2 : 0;

        AddTextPrinterParameterized3(
            sNamingScreen->windows[WIN_TEXT_ENTRY],
            FONT_NORMAL,
            i * 8 + x + extraWidth,   // left (X)
            1,                        // top (Y)
            sNamingScreenTextColor,
            TEXT_SKIP_DRAW,
            temp                      // string
        );
    }

    CallAddGenderIconFunc();
    CopyWindowToVram(sNamingScreen->windows[WIN_TEXT_ENTRY], COPYWIN_GFX);
    PutWindowTilemap(sNamingScreen->windows[WIN_TEXT_ENTRY]);
}

static void CB2_NamingScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void ResetVHBlank(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void SetVBlank(void)
{
    SetVBlankCallback(VBlankCB_NamingScreen);
}


static void VBlankCB_NamingScreen(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG2VOFS, sNamingScreen->bg2vOffset);
}

static void NamingScreen_ShowBgs(void)
{
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static bool8 IsWideLetter(u8 character)
{
    u8 i;

    for (i = 0; sText_AlphabetUpperLower[i] != EOS; i++)
    {
        if (character == sText_AlphabetUpperLower[i])
            return TRUE;
    }
    return FALSE;
}

static void NamingScreen_WindowFunc_DrawDialogueFrame(void)
{
	FillBgTilemapBufferRect(0, 0x30,    0,   14,   1,       1,  14);
	FillBgTilemapBufferRect(0, 0x31,    1,   14,   1,       1,  14);
	FillBgTilemapBufferRect(0, 0x32,    2,   14,  26,       1,  14);
    FillBgTilemapBufferRect(0, 0x33, 0x1C, 	 14, 	1, 		1, 	14);
    FillBgTilemapBufferRect(0, 0x34, 0x1D, 	 14, 	1, 		1, 	14);
	FillBgTilemapBufferRect(0, 0x35, 	0, 	 15, 	1, 		3, 	14);
    FillBgTilemapBufferRect(0, 0x36, 	1, 	 15, 	1, 		3, 	14);
    FillBgTilemapBufferRect(0, 0x37, 	2, 	 15,   26, 		4, 	14);
    FillBgTilemapBufferRect(0, 0x38, 0x1C, 	 15, 	1, 		3, 	14);
    FillBgTilemapBufferRect(0, 0x39, 0x1D, 	 15, 	1, 		3, 	14);
    FillBgTilemapBufferRect(0, 0x3A, 	0,   18, 	1, 		1, 	14);
    FillBgTilemapBufferRect(0, 0x3B, 	1,   18, 	1, 		1, 	14);
    FillBgTilemapBufferRect(0, 0x3D, 0x1C,   18, 	1, 		1, 	14);
    FillBgTilemapBufferRect(0, 0x3E, 0x1D,   18, 	1, 		1, 	14);
	FillBgTilemapBufferRect(0, 0x3F,    0,   19, 	1, 		1, 	14);
	FillBgTilemapBufferRect(0, 0x40,    1,   19, 	1, 		1, 	14);
	FillBgTilemapBufferRect(0, 0x41,    2,   19,   26, 		1, 	14);
	FillBgTilemapBufferRect(0, BG_TILE_H_FLIP(0x40), 0x1C, 19, 	1, 		1, 	14);
	FillBgTilemapBufferRect(0, BG_TILE_H_FLIP(0x3F), 0x1D, 19, 	1, 		1, 	14); 
}

static void NamingScreen_DrawDialogueFrame(void)
{
	LoadMessageBoxGfx(0, 0x30, 0xE0);
	NamingScreen_WindowFunc_DrawDialogueFrame();
	FillWindowPixelBuffer(0, PIXEL_FILL(1));
	PutWindowTilemap(0);
	CopyWindowToVram(0, COPYWIN_FULL);
}

//--------------------------------------------------
// Forward-declared variables
//--------------------------------------------------

// Initial pages below are pointless, they're overwritten with KBPAGE_LETTERS_UPPER in MainState_FadeIn()
static const struct NamingScreenTemplate sPlayerNamingScreenTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = PLAYER_NAME_LENGTH,
    .iconFunction = 1,
    .addGenderIcon = FALSE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    //.unused = 35,
    .title = COMPOUND_STRING("YOUR NAME?"),
    .titlePt = COMPOUND_STRING("SEU NOME?"),
    .titleSpa = COMPOUND_STRING("¿TU NOMBRE?"),
};

static const struct NamingScreenTemplate sPCBoxNamingTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = BOX_NAME_LENGTH,
    .iconFunction = 2,
    .addGenderIcon = FALSE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    //.unused = 19,
    .title = COMPOUND_STRING("BOX NAME?"),
    .titlePt = COMPOUND_STRING("NOME DA CAIXA?"),
    .titleSpa = COMPOUND_STRING("NOMBRE DE LA CAJA?"),
};

static const struct NamingScreenTemplate sMonNamingScreenTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = POKEMON_NAME_LENGTH,
    .iconFunction = 3,
    .addGenderIcon = TRUE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    //.unused = 35,
    .title = COMPOUND_STRING("{STR_VAR_1}'s nickname?"),
    .titlePt = COMPOUND_STRING("Apelido de {STR_VAR_1}?"),
    .titleSpa = COMPOUND_STRING("¿Nombre de {STR_VAR_1}?"),
};

static const struct NamingScreenTemplate sWaldaWordsScreenTemplate =
{
    .copyExistingString = TRUE,
    .maxChars = WALDA_PHRASE_LENGTH,
    .iconFunction = 4,
    .addGenderIcon = FALSE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    //.unused = 11,
    .title = COMPOUND_STRING("Tell him the words."),
    .titlePt = COMPOUND_STRING("Diga a ele as palavras."),
    .titleSpa = COMPOUND_STRING("Dile las palabras."),
};

static const struct NamingScreenTemplate sCodeScreenTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = CODE_NAME_LENGTH,
    .iconFunction = 5,
    .addGenderIcon = FALSE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    //.unused = 35,
    .title = COMPOUND_STRING("Enter code:"),
    .titlePt = COMPOUND_STRING("Digite o código:"),
    .titleSpa = COMPOUND_STRING("Introduce el código:"),
};

static const struct NamingScreenTemplate sRivalNamingScreenTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = PLAYER_NAME_LENGTH,
    .iconFunction = 6,
    .addGenderIcon = FALSE,
    .initialPage = KBPAGE_LETTERS_UPPER,
    .title = COMPOUND_STRING("RIVAL's NAME?"),
    .titlePt = COMPOUND_STRING("NOME DO RIVAL?"),
    .titleSpa = COMPOUND_STRING("¿NOMBRE DEL RIVAL?"),
};

static const struct OamData sOam_8x8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct OamData sOam_16x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

/*
[0_]    16x24
[1+] <--Origin
[2_]
*/
static const struct Subsprite sSubsprites_PCIcon[] =
{
    {
        .x = -8,
        .y = -12,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 0,
        .priority = 3
    },
    {
        .x = -8,
        .y = -4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 2,
        .priority = 3
    },
    {
        .x = -8,
        .y =  4,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .tileOffset = 4,
        .priority = 3
    }
};

static const struct SubspriteTable sSubspriteTable_PCIcon[] =
{
    {ARRAY_COUNT(sSubsprites_PCIcon), sSubsprites_PCIcon}
};

static const struct SpriteFrameImage sImageTable_PCIcon[] =
{
    {sPCIconOff_Gfx, sizeof(sPCIconOff_Gfx)},
    {sPCIconOn_Gfx, sizeof(sPCIconOn_Gfx)},
};

static const union AnimCmd sAnim_Loop[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_CursorSquish[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PCIcon[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_Loop[] =
{
    sAnim_Loop
};

static const union AnimCmd *const gSpriteAnimTable_Underscore[] = {
    sAnim_Loop
};

static const union AnimCmd *const sAnims_Cursor[] =
{
    sAnim_Loop,
    sAnim_CursorSquish
};

static const union AnimCmd *const sAnims_PCIcon[] =
{
    sAnim_PCIcon
};

static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_CURSOR,
    .oam = &sOam_16x32,
    .anims = sAnims_Cursor,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Cursor
};

static const struct SpriteTemplate sSpriteTemplate_UndescoreMain =
{
    .tileTag = GFXTAG_INPUT_ARROW,
    .paletteTag = PALTAG_PAGE_SWAP_OTHERS,
    .oam = &sOam_8x8,
    .anims = sAnims_Loop,
    .callback = SpriteCB_InputArrow
};

static const struct SpriteTemplate sSpriteTemplate_Underscore =
{
    .tileTag = GFXTAG_UNDERSCORE,
    .paletteTag = PALTAG_PAGE_SWAP_OTHERS,
    .oam = &sOam_8x8,
    .anims = sAnims_Loop,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Underscore
};

static const struct SpriteTemplate sSpriteTemplate_PCIcon =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_MENU,
    .oam = &sOam_8x8,
    .anims = sAnims_PCIcon,
    .images = sImageTable_PCIcon,
};

static const struct NamingScreenTemplate *const sNamingScreenTemplates[] =
{
    [NAMING_SCREEN_PLAYER]     = &sPlayerNamingScreenTemplate,
    [NAMING_SCREEN_BOX]        = &sPCBoxNamingTemplate,
    [NAMING_SCREEN_CAUGHT_MON] = &sMonNamingScreenTemplate,
    [NAMING_SCREEN_NICKNAME]   = &sMonNamingScreenTemplate,
    [NAMING_SCREEN_WALDA]      = &sWaldaWordsScreenTemplate,
    [NAMING_SCREEN_CODE]       = &sCodeScreenTemplate,
    [NAMING_SCREEN_RIVAL]      = &sRivalNamingScreenTemplate,
};

static const struct SpriteSheet sSpriteSheets[] =
{
    {gNamingScreenCursor_Gfx,         0x100,  GFXTAG_CURSOR},
    {gNamingScreenCursorSquished_Gfx, 0x100,  GFXTAG_CURSOR_SQUISHED},
    {gNamingScreenCursorFilled_Gfx,   0x100,  GFXTAG_CURSOR_FILLED},
    {gNamingScreenUnderscore_Gfx,     0x020,  GFXTAG_UNDERSCORE},
    {NULL}
};

static const struct SpritePalette sSpritePalettes[] =
{
    {gNamingScreenMenu_Pal[0], PALTAG_MENU},
    {gNamingScreenMenu_Pal[4], PALTAG_PAGE_SWAP_OTHERS},
    {gNamingScreenMenu_Pal[2], PALTAG_CURSOR},
    {NULL}
};
