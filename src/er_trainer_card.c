#include "global.h"
#include "bg.h"
#include "datetime.h"
#include "decompress.h"
#include "er_trainer_card.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "poke_miles.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trainer.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "constants/flags.h"
#include "constants/game_stat.h"
#include "constants/rgb.h"
#include "constants/songs.h"

enum
{
    WIN_ER_CARD_TEXT,
    WIN_ER_CARD_PIC,
};

struct ERTrainerCardData
{
    MainCallback callback;
    u8 textWindow;
    u8 picWindow;
    u8 badgeSpriteIds[3];
    u16 bg0Tilemap[BG_SCREEN_SIZE / sizeof(u16)];
    u16 bg1Tilemap[BG_SCREEN_SIZE / sizeof(u16)];
};

static EWRAM_DATA struct ERTrainerCardData *sERCard = NULL;

static const u32 sERCardTiles[] = INCGFX_U32("graphics/er_trainercard/tiles.png", ".4bpp");
static const u16 sERCardMap[] = INCBIN_U16("graphics/er_trainercard/map.bin");
static const u16 sERCardPalette[] = INCGFX_U16("graphics/er_trainercard/palette.pal", ".gbapal");

enum
{
    ER_BADGE_ROCHAREACH,
    ER_BADGE_LEAFBOND,
    ER_BADGE_MINDSEAL,
    ER_BADGE_COUNT,
};

#define TAG_ER_BADGE_GFX_BASE 0xE100
#define TAG_ER_BADGE_PAL_BASE 0xE110

static const u32 sLeafbondBadgeGfx[] = INCGFX_U32("graphics/er_trainercard/leafbond_badge.png", ".4bpp.smol");
static const u32 sRochareachBadgeGfx[] = INCGFX_U32("graphics/er_trainercard/rochareach_badge.png", ".4bpp.smol");
static const u32 sMindsealBadgeGfx[] = INCGFX_U32("graphics/er_trainercard/mindseal_badge.png", ".4bpp.smol");
static const u16 sLeafbondBadgePal[] = INCGFX_U16("graphics/er_trainercard/leafbond_badge.png", ".gbapal");
static const u16 sRochareachBadgePal[] = INCGFX_U16("graphics/er_trainercard/rochareach_badge.png", ".gbapal");
static const u16 sMindsealBadgePal[] = INCGFX_U16("graphics/er_trainercard/mindseal_badge.png", ".gbapal");

static const struct CompressedSpriteSheet sERBadgeSheets[ER_BADGE_COUNT] =
{
    {sRochareachBadgeGfx, 32 * 32 / 2, TAG_ER_BADGE_GFX_BASE + ER_BADGE_ROCHAREACH},
    {sLeafbondBadgeGfx, 32 * 32 / 2, TAG_ER_BADGE_GFX_BASE + ER_BADGE_LEAFBOND},
    {sMindsealBadgeGfx, 32 * 32 / 2, TAG_ER_BADGE_GFX_BASE + ER_BADGE_MINDSEAL},
};

static const struct SpritePalette sERBadgePalettes[ER_BADGE_COUNT] =
{
    {sRochareachBadgePal, TAG_ER_BADGE_PAL_BASE + ER_BADGE_ROCHAREACH},
    {sLeafbondBadgePal, TAG_ER_BADGE_PAL_BASE + ER_BADGE_LEAFBOND},
    {sMindsealBadgePal, TAG_ER_BADGE_PAL_BASE + ER_BADGE_MINDSEAL},
};

static const struct OamData sERBadgeOam =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0,
};

static const union AnimCmd sERBadgeAnim[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd *const sERBadgeAnimTable[] =
{
    sERBadgeAnim,
};

static const struct SpriteTemplate sERBadgeTemplates[ER_BADGE_COUNT] =
{
    {
        .tileTag = TAG_ER_BADGE_GFX_BASE + ER_BADGE_ROCHAREACH,
        .paletteTag = TAG_ER_BADGE_PAL_BASE + ER_BADGE_ROCHAREACH,
        .oam = &sERBadgeOam,
        .anims = sERBadgeAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_ER_BADGE_GFX_BASE + ER_BADGE_LEAFBOND,
        .paletteTag = TAG_ER_BADGE_PAL_BASE + ER_BADGE_LEAFBOND,
        .oam = &sERBadgeOam,
        .anims = sERBadgeAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_ER_BADGE_GFX_BASE + ER_BADGE_MINDSEAL,
        .paletteTag = TAG_ER_BADGE_PAL_BASE + ER_BADGE_MINDSEAL,
        .oam = &sERBadgeOam,
        .anims = sERBadgeAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
};

static const struct BgTemplate sERCardBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sERCardWindows[] =
{
    [WIN_ER_CARD_TEXT] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_ER_CARD_PIC] = {
        .bg = 1,
        .tilemapLeft = 20,
        .tilemapTop = 4,
        .width = 8,
        .height = 8,
        .paletteNum = 8,
        .baseBlock = 0x1F9,
    },
    DUMMY_WIN_TEMPLATE,
};

static const u8 sTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
static const u8 sText_Name[] = _("Name:");
static const u8 sText_Id[] = _("ID No.:");
static const u8 sText_Pokedex[] = _("Pokédex:");
static const u8 sText_Money[] = _("Money:");
static const u8 sText_PokeMiles[] = _("Poké Miles:");
static const u8 sText_Whiteouts[] = _("Whiteouts:");
static const u8 sText_Adventure[] = _("Adv started on:");
static const u8 sText_HallOfFame[] = _("First Hall of Fame:");
static const u8 sText_NoDate[] = _("--/--/--");
static const u8 sText_PlayTime[] = _("Play Time:");
extern const u8 gText_Colon2[];

static void CB2_InitERTrainerCard(void);
static void CB2_ERTrainerCard(void);
static void VBlankCB_ERTrainerCard(void);
static void Task_ERTrainerCard(u8 taskId);

static void CreateERBadgeSprites(void)
{
    static const u16 sBadgeFlags[ER_BADGE_COUNT] =
    {
        FLAG_BADGE01_GET,
        FLAG_BADGE02_GET,
        FLAG_BADGE03_GET,
    };
    static const s16 sBadgeX[ER_BADGE_COUNT] = {44, 120, 196};
    u32 i;

    for (i = 0; i < ER_BADGE_COUNT; i++)
    {
        sERCard->badgeSpriteIds[i] = MAX_SPRITES;
        if (FlagGet(sBadgeFlags[i]))
        {
            LoadCompressedSpriteSheet(&sERBadgeSheets[i]);
            LoadSpritePalette(&sERBadgePalettes[i]);
            sERCard->badgeSpriteIds[i] = CreateSprite(&sERBadgeTemplates[i], sBadgeX[i], 133, 0);
        }
    }
}

static void FreeERBadgeSprites(void)
{
    u32 i;

    for (i = 0; i < ER_BADGE_COUNT; i++)
    {
        if (sERCard->badgeSpriteIds[i] != MAX_SPRITES)
            DestroySprite(&gSprites[sERCard->badgeSpriteIds[i]]);
        FreeSpriteTilesByTag(TAG_ER_BADGE_GFX_BASE + i);
        FreeSpritePaletteByTag(TAG_ER_BADGE_PAL_BASE + i);
    }
}

static void PrintText(const u8 *text, u8 x, u8 y)
{
    AddTextPrinterParameterized3(sERCard->textWindow, FONT_SMALL, x, y, sTextColors, TEXT_SKIP_DRAW, text);
}

static void FormatDate(u8 *dest, const struct DateTime *date)
{
    u8 *ptr = ConvertIntToDecimalStringN(dest, date->month, STR_CONV_MODE_LEADING_ZEROS, 2);
    *ptr++ = CHAR_SLASH;
    ptr = ConvertIntToDecimalStringN(ptr, date->day, STR_CONV_MODE_LEADING_ZEROS, 2);
    *ptr++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(ptr, date->year % 100, STR_CONV_MODE_LEADING_ZEROS, 2);
}

static void GetCardDates(struct DateTime *start, struct DateTime *hof)
{
    struct Time elapsed;
    u32 hofTime = GetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME);
    u32 playSeconds = gSaveBlock2Ptr->playTimeHours * 3600
                    + gSaveBlock2Ptr->playTimeMinutes * 60;
    s64 localSeconds;

    RtcCalcLocalTime();
    localSeconds = (s64)gLocalTime.days * 86400
                 + gLocalTime.hours * 3600
                 + gLocalTime.minutes * 60
                 + gLocalTime.seconds;
    localSeconds = max(0, localSeconds - playSeconds);
    elapsed.days = localSeconds / 86400;
    elapsed.hours = (localSeconds / 3600) % 24;
    elapsed.minutes = (localSeconds / 60) % 60;
    elapsed.seconds = localSeconds % 60;
    ConvertTimeToDateTime(start, &elapsed);
    *hof = *start;
    if (GetGameStat(GAME_STAT_ENTERED_HOF))
    {
        DateTime_AddHours(hof, hofTime >> 16);
        DateTime_AddMinutes(hof, (hofTime >> 8) & 0xFF);
        DateTime_AddSeconds(hof, hofTime & 0xFF);
    }
}

static void DrawERTrainerCard(void)
{
    u8 buffer[64];
    u8 *ptr;
    struct DateTime startDate, hofDate;
    u16 caught = FlagGet(FLAG_SYS_POKEDEX_GET)
               ? (IsNationalPokedexEnabled() ? GetNationalPokedexCount(FLAG_GET_CAUGHT)
                                             : GetRegionalPokedexCount(FLAG_GET_CAUGHT))
               : 0;

    FillWindowPixelBuffer(sERCard->textWindow, PIXEL_FILL(0));
    PrintText(sText_Name, 8, 2);
    PrintText(gSaveBlock2Ptr->playerName, 48, 2);

    PrintText(sText_Id, 126, 2);
    ConvertIntToDecimalStringN(buffer, (gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0], STR_CONV_MODE_LEADING_ZEROS, 5);
    PrintText(buffer, 174, 2);

    PrintText(sText_Pokedex, 8, 16);
    ConvertIntToDecimalStringN(buffer, caught, STR_CONV_MODE_LEFT_ALIGN, 4);
    PrintText(buffer, 82, 16);

    PrintText(sText_Money, 8, 28);
    ptr = ConvertIntToDecimalStringN(buffer, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_LEFT_ALIGN, 7);
    *ptr = EOS;
    PrintText(buffer, 68, 28);

    PrintText(sText_PokeMiles, 8, 40);
    ConvertIntToDecimalStringN(buffer, GetPokeMiles(), STR_CONV_MODE_LEFT_ALIGN, 8);
    PrintText(buffer, 90, 40);

    PrintText(sText_Whiteouts, 8, 52);
    ConvertIntToDecimalStringN(buffer, GetGameStat(GAME_STAT_PLAYER_WHITEOUTS), STR_CONV_MODE_LEFT_ALIGN, 7);
    PrintText(buffer, 90, 52);

    PrintText(sText_PlayTime, 8, 64);
    ptr = ConvertIntToDecimalStringN(buffer, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    *ptr++ = CHAR_COLON;
    ConvertIntToDecimalStringN(ptr, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    PrintText(buffer, 76, 64);

    GetCardDates(&startDate, &hofDate);
    PrintText(sText_Adventure, 8, 76);
    FormatDate(buffer, &startDate);
    PrintText(buffer, 105, 76);

    PrintText(sText_HallOfFame, 8, 88);
    if (GetGameStat(GAME_STAT_ENTERED_HOF))
        FormatDate(buffer, &hofDate);
    else
        StringCopy(buffer, sText_NoDate);
    PrintText(buffer, 108, 88);

    PutWindowTilemap(sERCard->textWindow);
    CopyWindowToVram(sERCard->textWindow, COPYWIN_FULL);
    FillWindowPixelBuffer(sERCard->picWindow, PIXEL_FILL(0));
    CreateTrainerCardTrainerPicSprite(PlayerGenderToFrontTrainerPicId_Debug(gSaveBlock2Ptr->playerGender, TRUE), TRUE, 5, 0, 8, sERCard->picWindow);
    PutWindowTilemap(sERCard->picWindow);
    CopyWindowToVram(sERCard->picWindow, COPYWIN_FULL);
}

void ShowERTrainerCard(void (*callback)(void))
{
    sERCard = AllocZeroed(sizeof(*sERCard));
    if (sERCard == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    sERCard->callback = callback;
    SetMainCallback2(CB2_InitERTrainerCard);
}

static void CB2_InitERTrainerCard(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    DmaClear16(3, (void *)VRAM, VRAM_SIZE);
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ScanlineEffect_Stop();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sERCardBgTemplates, ARRAY_COUNT(sERCardBgTemplates));
    SetBgTilemapBuffer(0, sERCard->bg0Tilemap);
    SetBgTilemapBuffer(1, sERCard->bg1Tilemap);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    InitWindows(sERCardWindows);
    DeactivateAllTextPrinters();
    sERCard->textWindow = WIN_ER_CARD_TEXT;
    sERCard->picWindow = WIN_ER_CARD_PIC;
    LoadBgTiles(0, sERCardTiles, sizeof(sERCardTiles), 0);
    CopyToBgTilemapBufferRect(0, sERCardMap, 0, 0, 30, 20);
    LoadPalette(sERCardPalette, BG_PLTT_ID(0), sizeof(sERCardPalette));
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    DrawERTrainerCard();
    CreateERBadgeSprites();
    CopyBgTilemapBufferToVram(0);
    ShowBg(0);
    ShowBg(1);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    CreateTask(Task_ERTrainerCard, 0);
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetVBlankCallback(VBlankCB_ERTrainerCard);
    SetMainCallback2(CB2_ERTrainerCard);
}

static void CB2_ERTrainerCard(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_ERTrainerCard(u8 taskId)
{
    if (!gPaletteFade.active && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].data[0] = 1;
    }
    if (gTasks[taskId].data[0] && !gPaletteFade.active)
    {
        MainCallback callback = sERCard->callback;
        FreeERBadgeSprites();
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sERCard);
        DestroyTask(taskId);
        SetVBlankCallback(NULL);
        SetMainCallback2(callback);
    }
}

static void VBlankCB_ERTrainerCard(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}
