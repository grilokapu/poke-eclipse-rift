#include "global.h"
#include "decompress.h"
#include "expansion_intro.h"
#include "gpu_regs.h"
#include "intro.h"
#include "intro_frlg.h"
#include "main.h"
#include "palette.h"
#include "pokeroms_logo.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "task.h"
#include "constants/rgb.h"

#define POKEROMS_LOGO_SCREEN_BASE 31
#define POKEROMS_LOGO_WIDTH_TILES 30
#define POKEROMS_LOGO_HEIGHT_TILES 20
#define POKEROMS_LOGO_DISPLAY_FRAMES (3 * 60)

static const u32 sPokeromsLogoTiles[] = INCGFX_U32("graphics/pokeroms_logo/tiles.png", ".4bpp");
static const u16 sPokeromsLogoPalette[] = INCGFX_U16("graphics/pokeroms_logo/palette.pal", ".gbapal");
static const u16 sPokeromsLogoTilemap[] = INCBIN_U16("graphics/pokeroms_logo/map.bin");

enum
{
    POKEROMS_LOGO_FADE_IN,
    POKEROMS_LOGO_DISPLAY,
    POKEROMS_LOGO_FADE_OUT,
};

static u16 sPokeromsLogoTimer;
static u8 sPokeromsLogoState;

static void VBlankCB_PokeromsLogo(void);
static void CB2_PokeromsLogoScreen(void);
static void LoadPokeromsLogoTilemap(void);
static void ContinueAfterPokeromsLogo(void);

void CB2_InitPokeromsLogoScreen(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    CpuFill32(0, (void *)VRAM, VRAM_SIZE);
    CpuFill32(0, (void *)OAM, OAM_SIZE);
    CpuFill16(0, (void *)PLTT, PLTT_SIZE);
    ResetPaletteFade();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();

    CpuCopy16(sPokeromsLogoTiles, (void *)BG_CHAR_ADDR(0), sizeof(sPokeromsLogoTiles));
    LoadPokeromsLogoTilemap();
    LoadPalette(sPokeromsLogoPalette, BG_PLTT_ID(0), sizeof(sPokeromsLogoPalette));

    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(POKEROMS_LOGO_SCREEN_BASE)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;

    sPokeromsLogoTimer = 0;
    sPokeromsLogoState = POKEROMS_LOGO_FADE_IN;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB_PokeromsLogo);
    SetMainCallback2(CB2_PokeromsLogoScreen);
}

static void LoadPokeromsLogoTilemap(void)
{
    u32 y;
    u16 *dst = (u16 *)BG_SCREEN_ADDR(POKEROMS_LOGO_SCREEN_BASE);

    for (y = 0; y < POKEROMS_LOGO_HEIGHT_TILES; y++)
    {
        CpuCopy16(&sPokeromsLogoTilemap[y * POKEROMS_LOGO_WIDTH_TILES],
                  &dst[y * 32],
                  POKEROMS_LOGO_WIDTH_TILES * sizeof(u16));
    }
}

static void VBlankCB_PokeromsLogo(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_PokeromsLogoScreen(void)
{
    UpdatePaletteFade();

    switch (sPokeromsLogoState)
    {
    case POKEROMS_LOGO_FADE_IN:
        if (!gPaletteFade.active)
            sPokeromsLogoState = POKEROMS_LOGO_DISPLAY;
        break;
    case POKEROMS_LOGO_DISPLAY:
        if (++sPokeromsLogoTimer >= POKEROMS_LOGO_DISPLAY_FRAMES || gMain.newKeys != 0)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sPokeromsLogoState = POKEROMS_LOGO_FADE_OUT;
        }
        break;
    case POKEROMS_LOGO_FADE_OUT:
        if (!gPaletteFade.active)
            ContinueAfterPokeromsLogo();
        break;
    }
}

static void ContinueAfterPokeromsLogo(void)
{
#if EXPANSION_INTRO == TRUE
    SetMainCallback2(CB2_ExpansionIntro);
    CreateTask(Task_HandleExpansionIntro, 0);
#else
    if (IS_FRLG)
    {
        SetMainCallback2(CB2_SetUpIntroFrlg);
    }
    else
    {
        CreateTask(Task_Scene1_Load, 0);
        SetMainCallback2(MainCB2_Intro);
    }
#endif
}
