#include "global.h"
#include "event_data.h"
#include "menu.h"
#include "palette.h"
#include "pssicons.h"
#include "script_menu.h"
#include "sprite.h"
#include "task.h"

#include "constants/flags.h"
#include "constants/vars.h"

#include "gba/types.h"

struct PssIcons
{
    const u16 * const gfx;
    const u16 * const palette;
};

static const struct PssIcons gCustomPicTable[] =
{
    [PSS_NONE] = {NULL, NULL},
    [PSS_ICON_BARRY] = {gPssIcon_BarryGfx, gPssIcon_BarryPal},
    [PSS_ICON_HIKARI] = {gPssIcon_HikariGfx, gPssIcon_HikariPal},
    [PSS_ICON_REPORTER] = {gPssIcon_ReporterGfx, gPssIcon_ReporterPal},
    [PSS_ICON_MOM] = {gPssIcon_MomGfx, gPssIcon_MomPal},
    [PSS_ICON_SORCERER] = {gPssIcon_SorcererGfx, gPssIcon_SorcererPal},
    [PSS_ICON_LUCIEN] = {gPssIcon_LucienGfx, gPssIcon_LucienPal},
    [PSS_ICON_SCIENTIST] = {gPssIcon_ScientistGfx, gPssIcon_ScientistPal},
};

static const struct OamData sOamData_PssIcon =
{
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0, // 4bpp
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1,
    .paletteNum = 13,
};

static const struct SpriteTemplate sPSSIconTemplate =
{
    .tileTag = GFXTAG_PSSICON,
    .paletteTag = 0xFFFF,
    .oam = &sOamData_PssIcon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

bool8 ShowPssIconFromTable(u8 index)
{
    u8 spriteId;
    u8 taskId;
    u8 x = 20;
    u8 y = 6;

    if (FlagGet(FLAG_SHAKE_PSSICON))
    {
        x -= 10;
        y -= 3;
    }

    ClosePssIconPic();

    if (index >= ARRAY_COUNT(gCustomPicTable))
        return FALSE;

    const struct PssIcons *entry = &gCustomPicTable[index];
    
    LoadSpriteSheet(&(struct SpriteSheet){
        .data = entry->gfx,
        .size = 0x800,
        .tag = GFXTAG_PSSICON,
    });

    LoadPalette(entry->palette,
                          OBJ_PLTT_ID(13),
                          32);

    spriteId = CreateSprite(&sPSSIconTemplate, x * 8 + 40, y * 8 + 35, 0);
    gSprites[spriteId].oam.paletteNum = 13;
    taskId = CreateTask(Task_WaitPssIcon, 80);
    gTasks[taskId].tState = 0;
    gTasks[taskId].tSpriteId = spriteId;
    if (FlagGet(FLAG_SHAKE_PSSICON))
        gSprites[spriteId].callback = SpriteCB_ShakeBadgePic;
    gSprites[spriteId].oam.priority = 0;
    ScheduleBgCopyTilemapToVram(0);
    return TRUE;
}

void ClosePssIconPic(void)
{
    u8 taskId = FindTaskIdByFunc(Task_WaitPssIcon);
    if (taskId != 0xFF)
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
        FreeSpriteTilesByTag(GFXTAG_PSSICON);
        DestroyTask(taskId);
    }
}

static void Task_WaitPssIcon(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->tState)
    {
    case 0:
        task->tState++;
        break;
    case 1:
        break;
    case 2:
        DestroySprite(&gSprites[task->tSpriteId]);
        FreeSpriteTilesByTag(GFXTAG_PSSICON);
        task->tState++;
        break;
    case 3:
        ClearToTransparentAndRemoveWindow(task->tWindowId);
        DestroyTask(taskId);
        break;
    }
}

static const union AffineAnimCmd sAffineAnim_ShakeBadge[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 128, 1), //Start rotated left
	AFFINEANIMCMD_FRAME(0, 0, -8, 16), //Double sprite size + rotate right
	AFFINEANIMCMD_FRAME(0, 0, -3, 8), //End at right 24
	AFFINEANIMCMD_FRAME(0, 0, 3, 16), //End at left 24
	AFFINEANIMCMD_FRAME(0, 0, -3, 16), //End at right 24
	AFFINEANIMCMD_FRAME(0, 0, 3, 16), //End at left 24
	AFFINEANIMCMD_FRAME(0, 0, -3, 8), //End at 0
	AFFINEANIMCMD_END,
};

static const union AffineAnimCmd* const sAffineAnimTable_ShakeBadge[] =
{
    sAffineAnim_ShakeBadge,
};

void StartShakeAffineAnimForBadge(struct Sprite* sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
    sprite->oam.matrixNum = AllocOamMatrix();
    sprite->affineAnims = sAffineAnimTable_ShakeBadge;
    StartSpriteAffineAnim(sprite, 0);
}

void SpriteCB_ShakeBadgePic(struct Sprite *sprite)
{
	StartShakeAffineAnimForBadge(sprite);
	sprite->callback = SpriteCallbackDummy;
}