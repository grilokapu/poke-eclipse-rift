#ifndef GUARD_BW_SUMMARY_SCREEN_H
#define GUARD_BW_SUMMARY_SCREEN_H

#include "main.h"

// turn on and off the bw summary screen
#define BW_SUMMARY_SCREEN                           FALSE

// constants
#define BW_MAX_MOVE_DESCRIPTION_LENGTH              100     // this only needs to be updated if you use auto-formatting
#define BW_IV_EV_HIDDEN                             0       // don't show IVs and EVs
#define BW_IV_EV_GRADED                             1       // show graded values for IVs and EVs
#define BW_IV_EV_PRECISE                            2       // show precise values for IVs and EVs
#define BW_SUMMARY_MON_IDLE_ANIMS_FRAMES            300     // number of frames between each idle anim IF BW_SUMMARY_MON_IDLE_ANIMS is true.
                                                            // for reference, Emerald runs at 60FPS by default

// configs
#define BW_SUMMARY_AUTO_FORMAT_MOVE_DESCRIPTIONS    TRUE                // automatically formats move descriptions to fit the new box size. disable if you want to format them manually
#define BW_SUMMARY_NATURE_COLORS                    TRUE                // color stats increased or reduced by nature, red = boosted, blue = reduced
#define BW_SUMMARY_NATURE_ARROWS                    FALSE               // arrows to show stats increased or reduced by nature
#define BW_SUMMARY_CATEGORY_ICONS                   TRUE                // determines whether category (split) icons are shown or not
#define BW_SUMMARY_IV_EV_DISPLAY                    BW_IV_EV_GRADED     // determines how to show IVs and EVs
#define BW_SUMMARY_DECAP                            FALSE               // indicates if summary screen-specific strings should be decapitalized
#define BW_SUMMARY_SHOW_FRIENDSHIP                  TRUE                  // show a heart that fills up to indicate friendship value
#define BW_SUMMARY_BW_STATUS_ICONS                  TRUE                // use Gen 5 style status icons instead of the default ones.
#define BW_SUMMARY_BW_TYPE_ICONS                    TRUE                // use Gen 5 style type icons instead of the default ones.
                                                                        // out of the box the vanilla icons don't fit well, this is mostly a compatibility
                                                                        // option for people who already use custom icons everywhere else
#define BW_SUMMARY_SCROLLING_BG                     TRUE                // enables scrolling animated background
#define BW_SUMMARY_BG_BLEND                         TRUE                // enables alpha blending for the main UI (semi-transparency)
#define BW_SUMMARY_MON_IDLE_ANIMS                   TRUE                // loops the mon animations regularly as an "idle" anim
#define BW_SUMMARY_MON_SHADOWS                      TRUE                // displays a shadow for the mon sprite
#define BW_SUMMARY_SHOW_TERA_TYPE                   TRUE                // show tera type icons
#define BW_SUMMARY_SHOW_CONTEST_MOVES               TRUE                // show the contest moves page

#define BW_SUMMARY_SCREEN_SWSH_GRAPHICS             TRUE                // use the swsh summary screen graphics and layout. this is mostly a compatibility option for people who already use swsh-style graphics in other parts of their hack, as the swsh layout is very different and would require extra work to implement properly
// Looking for configs for renaming mons and relearning moves? Those use the standard expansion configs
// P_SUMMARY_SCREEN_RENAME and P_SUMMARY_SCREEN_MOVE_RELEARNER in include/config/pokemon.h
// Same with showing dynamic types:
// P_SHOW_DYNAMIC_TYPES

/* Info for users

General tilemap setup
BG3 - scrolling grid background (or not scrolling if you turned the config off) 
BG2 - main UI overlayed on scrolling BG
BG1 - pop in move effect windows
BG0 - text windows

Mosaic effect used when transitioning between screens and actvating
effect windows is controlled by tMosaicStrength in the relevant
task functions.

BG scrolling speed can be modified by altering the value parameter
of the ChangeBgX and ChangeBgY functions in VBlank()

Main UI and shadow transparency levels can be adjusted by changing the
value written to the alpha blend register in this line in bw_summary_screen.c:

static void InitBGs(void)
...
SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(14, 6));
...
}

*/

/* ravetodo in future updates
- extended move desc window
- ribbons
*/

void ShowPokemonSummaryScreen_BW(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
void ShowSelectMovePokemonSummaryScreen_BW(struct Pokemon *mons, u8 monIndex, void (*callback)(void), u16 newMove);
void ShowPokemonSummaryScreenHandleDeoxys_BW(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
u8 GetMoveSlotToReplace_BW(void);
void SummaryScreen_SetAnimDelayTaskId_BW(u8 taskId);
void SummaryScreen_SetShadowAnimDelayTaskId_BW(u8 taskId);

#if BW_SUMMARY_SCREEN
enum
{
	DARK,
	WHITE_TITLE,
	BLUE_SHADOW,
	WHITE,
	RED_SHADOW,
	BLUE,
	RED,
	ORANGE,
	RED_2,
    GREEN,
};

static const u8 sPSSTextColours[][3] =
{
    [DARK] = {0, 14, 13},		//Text Dark
    [WHITE_TITLE] = {0, 1, 2}, 	//Text White (title) 
    [BLUE_SHADOW] = {0, 15, 7}, //Red Shadow
    [WHITE] = {0, 15, 14},		//Text White
    [RED_SHADOW] = {0, 15, 1}, 	//Blue Shadow
    [BLUE] = {0, 7, 6}, 		//Male Symbol
    [RED] = {0, 1, 2}, 			//Female Symbol (red)
    [ORANGE] = {0, 3, 14}, 		//Low PP
    [RED_2] = {0, 1, 14}, 		//Whithout PP
    [GREEN] = {0, 5, 14}         //Green
};
#endif

#endif // GUARD_BW_SUMMARY_SCREEN_H