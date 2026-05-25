#ifndef GUARD_HEAL_LOCATION_H
#define GUARD_HEAL_LOCATION_H

struct HealLocation
{
    s8 mapGroup;
    s8 mapNum;
    u16 x;
    u16 y;
};

#define HEAL_LOCATION_NONE_TYPE       0
#define HEAL_LOCATION_MOM             1
#define HEAL_LOCATION_POKEMON_CENTER  2
#define HEAL_LOCATION_PC              HEAL_LOCATION_POKEMON_CENTER

u32 GetHealLocationIndexByMap(u16 mapGroup, u16 mapNum);
u32 GetHealLocationIndexByWarpData(struct WarpData *warp);
const struct HealLocation *GetHealLocationByMap(u16 mapGroup, u16 mapNum);
const struct HealLocation *GetHealLocation(u32 index);
bool32 IsLastHealLocationPlayerHouse();
bool32 HasWhiteoutRespawnHealer(void);
void SetHealingPlaceLocationHack(u8 mapGroup, u8 mapNum, u16 x, u16 y, u8 type);
void ClearHealingPlaceRespawnType(void);
void SetWhiteoutRespawnWarpAndHealerNPC(struct WarpData * warp);
u32 GetHealNpcLocalId(u32 healLocationId);

#endif // GUARD_HEAL_LOCATION_H
