#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "load_save.h"
#include "pokemon.h"
#include "stonereach_quiz.h"
#include "constants/battle.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"

static EWRAM_DATA struct Pokemon sStonereachQuizOriginalParty[PARTY_SIZE] = {0};
static EWRAM_DATA u8 sStonereachQuizOriginalPartyCount = 0;
static EWRAM_DATA bool8 sStonereachQuizActive = FALSE;

static void SetQuizMonMoves(struct Pokemon *mon, enum Move move1, enum Move move2, enum Move move3, enum Move move4)
{
    SetMonMoveSlot(mon, move1, 0);
    SetMonMoveSlot(mon, move2, 1);
    SetMonMoveSlot(mon, move3, 2);
    SetMonMoveSlot(mon, move4, 3);
    CalculateMonStats(mon);
}

static void SetQuizMonItem(struct Pokemon *mon, enum Item item)
{
    u16 heldItem = item;

    SetMonData(mon, MON_DATA_HELD_ITEM, &heldItem);
}

bool32 StonereachQuiz_IsActive(void)
{
    return sStonereachQuizActive;
}

void StonereachQuiz_PrepareParty(void)
{
    SavePlayerParty();
    memcpy(sStonereachQuizOriginalParty, gParties[B_TRAINER_PLAYER], sizeof(sStonereachQuizOriginalParty));
    sStonereachQuizOriginalPartyCount = gPartiesCount[B_TRAINER_PLAYER];

    ZeroPlayerPartyMons();
    gPartiesCount[B_TRAINER_PLAYER] = 3;

    CreateMon(&gParties[B_TRAINER_PLAYER][0], SPECIES_LANTURN, 32, 0, OTID_STRUCT_PLAYER_ID);
    SetQuizMonMoves(
        &gParties[B_TRAINER_PLAYER][0],
        MOVE_THUNDERBOLT,
        MOVE_SURF,
        MOVE_ICE_BEAM,
        MOVE_VOLT_SWITCH);
    SetQuizMonItem(&gParties[B_TRAINER_PLAYER][0], ITEM_LEFTOVERS);

    CreateMon(&gParties[B_TRAINER_PLAYER][1], SPECIES_BRELOOM, 32, 0, OTID_STRUCT_PLAYER_ID);
    SetQuizMonMoves(
        &gParties[B_TRAINER_PLAYER][1],
        MOVE_BULLET_SEED,
        MOVE_MACH_PUNCH,
        MOVE_ROCK_TOMB,
        MOVE_SPORE);
    SetQuizMonItem(&gParties[B_TRAINER_PLAYER][1], ITEM_LOADED_DICE);

    CreateMon(&gParties[B_TRAINER_PLAYER][2], SPECIES_GARDEVOIR, 32, 0, OTID_STRUCT_PLAYER_ID);
    SetQuizMonMoves(
        &gParties[B_TRAINER_PLAYER][2],
        MOVE_PSYCHIC,
        MOVE_MOONBLAST,
        MOVE_SHADOW_BALL,
        MOVE_CALM_MIND);
    SetQuizMonItem(&gParties[B_TRAINER_PLAYER][2], ITEM_FOCUS_SASH);

    sStonereachQuizActive = TRUE;
}

bool32 StonereachQuiz_Finish(void)
{
    bool32 solved = sStonereachQuizActive && gBattleOutcome == B_OUTCOME_WON;

    memcpy(gParties[B_TRAINER_PLAYER], sStonereachQuizOriginalParty, sizeof(sStonereachQuizOriginalParty));
    gPartiesCount[B_TRAINER_PLAYER] = sStonereachQuizOriginalPartyCount;
    SavePlayerParty();

    if (solved)
        FlagSet(FLAG_DEXNAV_ICONS_UNLOCKED);

    sStonereachQuizActive = FALSE;
    return solved;
}
