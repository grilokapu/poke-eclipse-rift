#include "global.h"
#include "menu.h"
#include "string_util.h"
#include "sound.h"
#include "text.h"
#include "window.h"
#include "help_window.h"
#include "constants/songs.h"
#include "data/help_window.h"

static u8 helpWindowId;
static bool8 sHelpWindowOpen;
static const struct WindowTemplate sHelpWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 3,
    .width = 26,
    .height = 14,
    .paletteNum = 15,
    .baseBlock = 8
};

void ShowHelpInfoWindow(struct ScriptContext *ctx)
{
    u16 helpTutorialId = ScriptReadHalfword(ctx);
    const u8 *header;
    const u8 *desc;
    PlaySE(SE_RG_HELP_OPEN);
    u32 xOffset;
    u32 yOffset;
    yOffset = 1;
    xOffset = 0;
    u8 headerColor[3] = {0, 8, 3};
    u8 headerFont = FONT_NORMAL;
    u8 descFont = FONT_SMALL;

    HideHelpInfoWindow();
    helpWindowId = AddWindow(&sHelpWindowTemplate);
    sHelpWindowOpen = TRUE;
    DrawStdWindowFrame(helpWindowId, FALSE);

    // Set non-default values if any
    if (gHelpWindowInfo[helpTutorialId].headerFont)
        headerFont = gHelpWindowInfo[helpTutorialId].headerFont;
    if (gHelpWindowInfo[helpTutorialId].descFont)
        descFont = gHelpWindowInfo[helpTutorialId].descFont;

    // Header Text
    header = gHelpWindowInfo[helpTutorialId].header;
    if (GET_LANGUAGE() == PT && gHelpWindowInfo[helpTutorialId].headerPt)
        header = gHelpWindowInfo[helpTutorialId].headerPt;
    else if (GET_LANGUAGE() == ES && gHelpWindowInfo[helpTutorialId].headerEs)
        header = gHelpWindowInfo[helpTutorialId].headerEs;
    StringCopy(gStringVar4, header);
    AddTextPrinterParameterized4(helpWindowId, headerFont, xOffset, yOffset, 0, 0, headerColor, 0, gStringVar4);
    yOffset += 16;
    // Description (can fiddle with text fonts and what not)
    desc = gHelpWindowInfo[helpTutorialId].desc;
    if (GET_LANGUAGE() == PT && gHelpWindowInfo[helpTutorialId].descPt)
        desc = gHelpWindowInfo[helpTutorialId].descPt;
    else if (GET_LANGUAGE() == ES && gHelpWindowInfo[helpTutorialId].descEs)
        desc = gHelpWindowInfo[helpTutorialId].descEs;
    StringCopy(gStringVar4, desc);
    AddTextPrinterParameterized(helpWindowId, descFont, gStringVar4, 0, yOffset, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(helpWindowId, COPYWIN_FULL);
}

void HideHelpInfoWindow(void)
{
    if (!sHelpWindowOpen)
        return;

    PlaySE(SE_RG_HELP_CLOSE);
    ClearStdWindowAndFrame(helpWindowId, FALSE);
    RemoveWindow(helpWindowId);
    sHelpWindowOpen = FALSE;
}
