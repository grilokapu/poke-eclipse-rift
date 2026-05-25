#ifndef GUARD_PSS_ICONS_H
#define GUARD_PSS_ICONS_H

#include "constants/pssicons.h"

static void Task_WaitPssIcon(u8 taskId);
void ClosePssIconPic(void);
void SpriteCB_ShakeBadgePic(struct Sprite *sprite);

#define tState        data[0]
#define tSpecies      data[1]
#define tSpriteId     data[2]
#define tWindowId     data[5]

static const u16 gPssIcon_BarryGfx[] = INCBIN_U16("graphics/pss_icons/barry.4bpp");
static const u16 gPssIcon_BarryPal[] = INCBIN_U16("graphics/pss_icons/barry.gbapal");
static const u16 gPssIcon_HikariGfx[] = INCBIN_U16("graphics/pss_icons/hikari.4bpp");
static const u16 gPssIcon_HikariPal[] = INCBIN_U16("graphics/pss_icons/hikari.gbapal");
static const u16 gPssIcon_ReporterGfx[] = INCBIN_U16("graphics/pss_icons/reporter.4bpp");
static const u16 gPssIcon_ReporterPal[] = INCBIN_U16("graphics/pss_icons/reporter.gbapal");
static const u16 gPssIcon_MomGfx[] = INCBIN_U16("graphics/pss_icons/mom.4bpp");
static const u16 gPssIcon_MomPal[] = INCBIN_U16("graphics/pss_icons/mom.gbapal");
static const u16 gPssIcon_SorcererGfx[] = INCBIN_U16("graphics/pss_icons/sorcerer.4bpp");
static const u16 gPssIcon_SorcererPal[] = INCBIN_U16("graphics/pss_icons/sorcerer.gbapal");
static const u16 gPssIcon_LucienGfx[] = INCBIN_U16("graphics/pss_icons/lucien.4bpp");
static const u16 gPssIcon_LucienPal[] = INCBIN_U16("graphics/pss_icons/lucien.gbapal");
static const u16 gPssIcon_ScientistGfx[] = INCBIN_U16("graphics/pss_icons/scientist.4bpp");
static const u16 gPssIcon_ScientistPal[] = INCBIN_U16("graphics/pss_icons/scientist.gbapal");

#define GFXTAG_PSSICON 0x7000

#endif // GUARD_PSS_ICONS_H