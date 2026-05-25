#include "global.h"
#include "event_data.h"
#include "heal_location.h"
#include "constants/event_objects.h"
#include "constants/heal_locations.h"
#include "constants/maps.h"

#include "data/heal_locations.h"

u32 GetHealLocationIndexByMap(u16 mapGroup, u16 mapNum)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sHealLocations); i++)
    {
        if (sHealLocations[i].mapGroup == mapGroup && sHealLocations[i].mapNum == mapNum)
            return i + 1;
    }
    return HEAL_LOCATION_NONE;
}

const struct HealLocation *GetHealLocationByMap(u16 mapGroup, u16 mapNum)
{
    u32 index = GetHealLocationIndexByMap(mapGroup, mapNum);

    if (index == HEAL_LOCATION_NONE)
        return NULL;
    else
        return &sHealLocations[index - 1];
}

u32 GetHealLocationIndexByWarpData(struct WarpData *warp)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sHealLocations); i++)
    {
        if (sHealLocations[i].mapGroup == warp->mapGroup
        && sHealLocations[i].mapNum == warp->mapNum
        && sHealLocations[i].x == warp->x
        && sHealLocations[i].y == warp->y)
            return i + 1;
    }
    return HEAL_LOCATION_NONE;
}

const struct HealLocation *GetHealLocation(u32 index)
{
    if (index == HEAL_LOCATION_NONE)
        return NULL;
    else if (index > ARRAY_COUNT(sHealLocations))
        return NULL;
    else
        return &sHealLocations[index - 1];
}

static bool32 IsLastHealLocation(u32 healLocation)
{
    const struct HealLocation *loc = GetHealLocation(healLocation);
    const struct WarpData *warpData = &gSaveBlock1Ptr->lastHealLocation;

    if (loc == NULL)
        return FALSE;

    return warpData->mapGroup == loc->mapGroup
        && warpData->mapNum == loc->mapNum
        && warpData->warpId == WARP_ID_NONE
        && warpData->x == loc->x
        && warpData->y == loc->y;
}

bool32 IsLastHealLocationPlayerHouse()
{
    if (gSaveBlock1Ptr->healingPlaceRespawnType == HEAL_LOCATION_MOM)
        return TRUE;

    return IsLastHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE)
        || IsLastHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F)
        || IsLastHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE)
        || IsLastHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F)
        || IsLastHealLocation(HEAL_LOCATION_PALLET_TOWN);
}

u32 GetHealNpcLocalId(u32 healLocationId)
{
    if (healLocationId == HEAL_LOCATION_NONE || healLocationId >= NUM_HEAL_LOCATIONS)
        return LOCALID_NONE;

    return sWhiteoutRespawnHealerNpcIds[healLocationId - 1];
}

bool32 HasWhiteoutRespawnHealer(void)
{
    if (gSaveBlock1Ptr->healingPlaceRespawnType == HEAL_LOCATION_MOM
        || gSaveBlock1Ptr->healingPlaceRespawnType == HEAL_LOCATION_POKEMON_CENTER)
        return TRUE;

    return GetHealNpcLocalId(GetHealLocationIndexByWarpData(&gSaveBlock1Ptr->lastHealLocation)) != LOCALID_NONE;
}

void SetHealingPlaceLocationHack(u8 mapGroup, u8 mapNum, u16 x, u16 y, u8 type)
{
    struct WarpData *warpData = &gSaveBlock1Ptr->lastHealLocation;

    warpData->mapGroup = mapGroup;
    warpData->mapNum = mapNum;
    warpData->warpId = WARP_ID_NONE;
    warpData->x = x;
    warpData->y = y;
    gSaveBlock1Ptr->healingPlaceRespawnType = type;

    return;
}

void ClearHealingPlaceRespawnType(void)
{
    gSaveBlock1Ptr->healingPlaceRespawnType = HEAL_LOCATION_NONE_TYPE;
}

void SetWhiteoutRespawnWarpAndHealerNPC(struct WarpData *warp)
{
    u32 healLocationId = GetHealLocationIndexByWarpData(&gSaveBlock1Ptr->lastHealLocation);
    u32 healNpcLocalId = GetHealNpcLocalId(healLocationId);

    if (gSaveBlock1Ptr->healingPlaceRespawnType == HEAL_LOCATION_MOM)
    {
        *warp = gSaveBlock1Ptr->lastHealLocation;
        gSpecialVar_LastTalked = LOCALID_PLAYERS_HOUSE_1F_MOM;
        return;
    }

    if (gSaveBlock1Ptr->healingPlaceRespawnType == HEAL_LOCATION_POKEMON_CENTER)
    {
        *warp = gSaveBlock1Ptr->lastHealLocation;
        gSpecialVar_LastTalked = 1;
        return;
    }

    if (gSaveBlock1Ptr->lastHealLocation.mapGroup != 0)
    {
        *warp = gSaveBlock1Ptr->lastHealLocation;
        return;
    }
    
    if (!healNpcLocalId)
    {
        *(warp) = gSaveBlock1Ptr->lastHealLocation;
        return;
    }

    warp->mapGroup = sWhiteoutRespawnHealCenterMapIdxs[healLocationId - 1][0];
    warp->mapNum = sWhiteoutRespawnHealCenterMapIdxs[healLocationId - 1][1];
    warp->warpId = WARP_ID_NONE;
    warp->x = sWhiteoutRespawnHealCenterMapIdxs[healLocationId - 1][2];
    warp->y = sWhiteoutRespawnHealCenterMapIdxs[healLocationId - 1][3];
    gSpecialVar_LastTalked = healNpcLocalId;
}
