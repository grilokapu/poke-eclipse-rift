#ifndef GUARD_POKE_MILES_H
#define GUARD_POKE_MILES_H

#define STEPS_PER_POKE_MILE 1000

u32 GetPokeMiles(void);
void AddPokeMiles(u32 amount);
bool32 RemovePokeMiles(u32 amount);
void UpdatePokeMilesOnPlayerStep(void);

#endif // GUARD_POKE_MILES_H
