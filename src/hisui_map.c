#include "global.h"
#include "gpu_regs.h"
#include "hisui_map.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static void CB2_InitHisuiMap(void);
static void CB2_HisuiMap(void);
static void VBlankCB_HisuiMap(void);
static void ExitHisuiMap(void);
static void DrawHisuiMap(void);

static const u8 sHisuiMapTiles[] = INCGFX_U8("graphics/hisui_map/tiles.png", ".8bpp");
static const u16 sHisuiMapTilemap[] = INCBIN_U16("graphics/hisui_map/map.bin");
static const u16 sHisuiMapPalette[] = INCGFX_U16("graphics/hisui_map/palette.pal", ".gbapal");

void ShowHisuiMap(void)
{
    SetMainCallback2(CB2_InitHisuiMap);
}

static void CB2_InitHisuiMap(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    DmaClear16(3, (void *)VRAM, BG_VRAM_SIZE);
    DrawHisuiMap();
    LoadPalette(sHisuiMapPalette, 0, PLTT_SIZE_8BPP);

    ResetPaletteFade();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ScanlineEffect_Stop();
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);

    // Mode 4 uses the affine BG2 registers. The overworld may leave a
    // transformed matrix behind, so restore a 1:1 scale at origin.
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2PA, 1 << 8);
    SetGpuReg(REG_OFFSET_BG2PB, 0);
    SetGpuReg(REG_OFFSET_BG2PC, 0);
    SetGpuReg(REG_OFFSET_BG2PD, 1 << 8);
    SetGpuReg(REG_OFFSET_BG2X_L, 0);
    SetGpuReg(REG_OFFSET_BG2X_H, 0);
    SetGpuReg(REG_OFFSET_BG2Y_L, 0);
    SetGpuReg(REG_OFFSET_BG2Y_H, 0);

    SetVBlankCallback(VBlankCB_HisuiMap);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_4 | DISPCNT_BG2_ON);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetMainCallback2(CB2_HisuiMap);
}

static void CB2_HisuiMap(void)
{
    UpdatePaletteFade();

    if (!gPaletteFade.active && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(ExitHisuiMap);
    }
}

static void ExitHisuiMap(void)
{
    UpdatePaletteFade();
    if (!gPaletteFade.active)
    {
        SetVBlankCallback(NULL);
        SetMainCallback2(CB2_ReturnToFieldContinueScript);
    }
}

static void DrawHisuiMap(void)
{
    u16 mapIndex;

    for (mapIndex = 0; mapIndex < ARRAY_COUNT(sHisuiMapTilemap); mapIndex++)
    {
        u16 mapEntry = sHisuiMapTilemap[mapIndex];
        u16 tileId = mapEntry & 0x3FF;
        bool8 hFlip = (mapEntry & 0x400) != 0;
        bool8 vFlip = (mapEntry & 0x800) != 0;
        u16 tileX = (mapIndex % 30) * 8;
        u16 tileY = (mapIndex / 30) * 8;
        u8 y;

        for (y = 0; y < 8; y++)
        {
            u8 x;
            u8 sourceY = vFlip ? 7 - y : y;

            for (x = 0; x < 8; x++)
            {
                u8 sourceX = hFlip ? 7 - x : x;
                ((u8 *)VRAM)[(tileY + y) * DISPLAY_WIDTH + tileX + x] =
                    sHisuiMapTiles[tileId * 64 + sourceY * 8 + sourceX];
            }
        }
    }
}

static void VBlankCB_HisuiMap(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}
