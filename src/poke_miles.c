#include "global.h"
#include "overworld.h"
#include "poke_miles.h"
#include "constants/game_stat.h"

#define MAX_POKE_MILES 0xFFFFFF

u32 GetPokeMiles(void)
{
    return GetGameStat(GAME_STAT_POKE_MILES);
}

void AddPokeMiles(u32 amount)
{
    u32 balance = GetPokeMiles();

    if (amount > MAX_POKE_MILES - balance)
        balance = MAX_POKE_MILES;
    else
        balance += amount;

    SetGameStat(GAME_STAT_POKE_MILES, balance);
}

bool32 RemovePokeMiles(u32 amount)
{
    u32 balance = GetPokeMiles();

    if (amount > balance)
        return FALSE;

    SetGameStat(GAME_STAT_POKE_MILES, balance - amount);
    return TRUE;
}

void UpdatePokeMilesOnPlayerStep(void)
{
    u32 steps = GetGameStat(GAME_STAT_STEPS);

    if (steps != 0 && steps % STEPS_PER_POKE_MILE == 0)
        AddPokeMiles(1);
}
