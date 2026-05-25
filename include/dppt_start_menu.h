#ifndef GUARD_DPPT_START_MENU_H
#define GUARD_DPPT_START_MENU_H

#include "main.h"

#define DPPT_START_MENU                  TRUE
#define VOL_START_MENU                   FALSE

#if VOL_START_MENU == TRUE
void HeatStartMenu_Init(void);
void GoToHandleInput(void);
#endif

#endif // GUARD_DPPT_START_MENU_H