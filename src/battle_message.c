#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_record.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_special.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_hill.h"
#include "trainer_slide.h"
#include "trainer_tower.h"
#include "window.h"
#include "line_break.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    union {
        struct {
            DEPRECATED("Use color.background instead") u8 bgColor;
            DEPRECATED("Use color.foreground instead") u8 fgColor;
            DEPRECATED("Use color.shadow instead") u8 shadowColor;
            DEPRECATED("Use color.accent instead") u8 accentColor;
        };
        union TextColor color;
    };
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
};

#if TESTING
EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#else
static EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#endif
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_EmptyString4[] = _("");

static const u8 *ChooseBattleText(const u8 *en, const u8 *pt, const u8 *es)
{
    switch (GET_LANGUAGE())
    {
    case PT:
        return pt;
    case ES:
        return es;
    default:
        return en;
    }
}

const u8 gText_PkmnShroudedInMist[] = _("{B_ATK_TEAM1} team became shrouded in mist!");
static const u8 sText_PkmnShroudedInMistPt[] = _("A equipe de {B_ATK_TEAM1} ficou envolta em névoa!");
static const u8 sText_PkmnShroudedInMistEs[] = _("¡El equipo de {B_ATK_TEAM1} quedó envuelto en niebla!");
const u8 gText_PkmnGettingPumped[] = _("{B_DEF_NAME_WITH_PREFIX} is getting pumped!");
static const u8 sText_PkmnGettingPumpedPt[] = _("{B_DEF_NAME_WITH_PREFIX} está se preparando!");
static const u8 sText_PkmnGettingPumpedEs[] = _("¡{B_DEF_NAME_WITH_PREFIX} se está preparando!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_BUFF1} is preventing switching out with its {B_LAST_ABILITY} Ability!\p");
static const u8 sText_PkmnsXPreventsSwitchingPt[] = _("{B_BUFF1} impede a troca com sua habilidade {B_LAST_ABILITY}!\p");
static const u8 sText_PkmnsXPreventsSwitchingEs[] = _("¡{B_BUFF1} impide el cambio con su habilidad {B_LAST_ABILITY}!\p");
const u8 gText_StatSharply[] = _(" sharply ");
static const u8 sText_StatSharplyPt[] = _(" subiu muito");
static const u8 sText_StatSharplyEs[] = _(" subió mucho");
const u8 gText_StatRose[] = _("rose!");
static const u8 sText_StatRosePt[] = _("subiu");
static const u8 sText_StatRoseEs[] = _("subió");
const u8 gText_StatFell[] = _("fell!");
static const u8 sText_StatFellPt[] = _("caiu!");
static const u8 sText_StatFellEs[] = _("bajó!");
const u8 gText_DefendersStatRose[] = _("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} rose {B_BUFF2}!");
static const u8 sText_DefendersStatRosePt[] = _("{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX} subiu muito {B_BUFF2}!");
static const u8 sText_DefendersStatRoseEs[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX} subió mucho {B_BUFF2}!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}You got away safely!\p");
static const u8 sText_GotAwaySafelyPt[] = _("{PLAY_SE SE_FLEE}Você fugiu com segurança!\p");
static const u8 sText_GotAwaySafelyEs[] = _("{PLAY_SE SE_FLEE}¡Escapaste sin problemas!\p");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("You defeated {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerDefeatedLinkTrainerPt[] = _("Você derrotou {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerDefeatedLinkTrainerEs[] = _("¡Derrotaste a {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("You defeated {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_TwoLinkTrainersDefeatedPt[] = _("Você derrotou {B_LINK_OPPONENT1_NAME} e {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_TwoLinkTrainersDefeatedEs[] = _("¡Derrotaste a {B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("You lost against {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainerPt[] = _("Você perdeu contra {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainerEs[] = _("¡Perdiste contra {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostToTwo[] = _("You lost to {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerLostToTwoPt[] = _("Você perdeu contra {B_LINK_OPPONENT1_NAME} e {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerLostToTwoEs[] = _("¡Perdiste contra {B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("You battled to a draw against {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainerPt[] = _("Você empatou a batalha contra {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainerEs[] = _("¡Empataste contra {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("You battled to a draw against {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwoPt[] = _("Você empatou a batalha contra {B_LINK_OPPONENT1_NAME} e {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwoEs[] = _("¡Empataste contra {B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} fled!"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_WildFledPt[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} fugiu!");
static const u8 sText_WildFledEs[] = _("{PLAY_SE SE_FLEE}¡{B_LINK_OPPONENT1_NAME} huyó!");
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME} fled!"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_TwoWildFledPt[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} e {B_LINK_OPPONENT2_NAME} fugiram!");
static const u8 sText_TwoWildFledEs[] = _("{PLAY_SE SE_FLEE}¡{B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME} huyeron!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("You defeated {B_TRAINER1_NAME_WITH_CLASS}!\p");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1Pt[] = _("Você derrotou {B_TRAINER1_NAME_WITH_CLASS}!\p");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1Es[] = _("¡Derrotaste a {B_TRAINER1_NAME_WITH_CLASS}!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} appeared!\p");
static const u8 sText_OpponentMon1AppearedPt[] = _("{B_OPPONENT_MON1_NAME} apareceu!\p");
static const u8 sText_OpponentMon1AppearedEs[] = _("¡Apareció {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_WildPkmnAppeared[] = _("You encountered a wild {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_WildPkmnAppearedPt[] = _("Você encontrou um {B_OPPONENT_MON1_NAME} selvagem!\p");
static const u8 sText_WildPkmnAppearedEs[] = _("¡Encontraste un {B_OPPONENT_MON1_NAME} salvaje!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("You encountered a wild {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("You encountered a wild {B_OPPONENT_MON1_NAME}!{PAUSE 127}");
static const u8 sText_WildPkmnAppearedPausePt[] = _("Você encontrou um {B_OPPONENT_MON1_NAME} selvagem!{PAUSE 127}");
static const u8 sText_WildPkmnAppearedPauseEs[] = _("¡Encontraste un {B_OPPONENT_MON1_NAME} salvaje!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("Oh! A wild {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME} appeared!\p");
static const u8 sText_TwoWildPkmnAppearedPt[] = _("Oh! Um {B_OPPONENT_MON1_NAME} e um {B_OPPONENT_MON2_NAME} selvagens apareceram!\p");
static const u8 sText_TwoWildPkmnAppearedEs[] = _("¡Oh! ¡Un {B_OPPONENT_MON1_NAME} y un {B_OPPONENT_MON2_NAME} salvajes aparecieron!\p");
static const u8 sText_GhostAppearedCantId[] = _("The GHOST appeared!\pDarn!\nThe GHOST can't be ID'd!\p");
static const u8 sText_TheGhostAppeared[] = _("The GHOST appeared!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("You are challenged by {B_TRAINER1_NAME_WITH_CLASS}!\p");
static const u8 sText_Trainer1WantsToBattlePt[] = _("Você foi desafiado por {B_TRAINER1_NAME_WITH_CLASS}!\p");
static const u8 sText_Trainer1WantsToBattleEs[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} te desafía!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("You are challenged by {B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("You are challenged by {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_Trainer1SentOutPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_OPPONENT_MON1_NAME}!");
static const u8 sText_Trainer1SentOutPkmnPt[] = _("{B_TRAINER1_NAME_WITH_CLASS} enviou {B_OPPONENT_MON1_NAME}!");
static const u8 sText_Trainer1SentOutPkmnEs[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} envió a {B_OPPONENT_MON1_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmnPt[] = _("{B_TRAINER1_NAME_WITH_CLASS} enviou {B_OPPONENT_MON1_NAME} e {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmnEs[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} envió a {B_OPPONENT_MON1_NAME} y {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_BUFF1}!");
static const u8 sText_Trainer1SentOutPkmn2Pt[] = _("{B_TRAINER1_NAME_WITH_CLASS} enviou {B_BUFF1}!");
static const u8 sText_Trainer1SentOutPkmn2Es[] = _("¡{B_TRAINER1_NAME_WITH_CLASS} envió a {B_BUFF1}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_BUFF1}!");
static const u8 sText_LinkTrainer2SentOutPkmn2[] = _("{B_LINK_OPPONENT2_NAME} sent out {B_BUFF1}!");
static const u8 sText_LinkTrainerIntroSendOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_LINK_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_OPPONENT_MON1_NAME} and {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersIntroSendOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_LINK_OPPONENT_MON1_NAME}! {B_LINK_OPPONENT2_NAME} sent out {B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{B_LINK_OPPONENT1_NAME} sent out {B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} sent out {B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("Go! {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoPkmnPt[] = _("Vai! {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoPkmnEs[] = _("¡Adelante! {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("Go! {B_PLAYER_MON1_NAME} and {B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("Go! {B_BUFF1}!");
static const u8 sText_GoPkmn2Pt[] = _("Vai! {B_BUFF1}!");
static const u8 sText_GoPkmn2Es[] = _("¡Adelante! {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("You're in charge, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("Go for it, {B_BUFF1}!");
static const u8 sText_JustALittleMorePkmn[] = _("Just a little more! Hang in there, {B_BUFF1}!"); //currently unused, will require code changes
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("Your opponent's weak! Get 'em, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmn1GoPkmn[] = _("{B_LINK_PARTNER_NAME} sent out {B_LINK_PLAYER_MON1_NAME}! Go, {B_LINK_PLAYER_MON2_NAME}!");
static const u8 sText_LinkPartnerSentOutPkmn2GoPkmn[] = _("{B_LINK_PARTNER_NAME} sent out {B_LINK_PLAYER_MON2_NAME}! Go, {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_LinkPartnerSentOutPkmn1[] = _("{B_LINK_PARTNER_NAME} sent out {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmn2[] = _("{B_LINK_PARTNER_NAME} sent out {B_BUFF1}!");
static const u8 sText_LinkPartnerWithdrewPkmn1[] = _("{B_LINK_PARTNER_NAME} withdrew {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_LinkPartnerWithdrewPkmn2[] = _("{B_LINK_PARTNER_NAME} withdrew {B_LINK_PLAYER_MON2_NAME}!");
static const u8 sText_PkmnSwitchOut[] = _("{B_BUFF1}, switch out! Come back!"); //currently unused, I believe its used for when you switch on a Pokémon in shift mode
static const u8 sText_PkmnThatsEnough[] = _("{B_BUFF1}, that's enough! Come back!");
static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}, come back!");
static const u8 sText_PkmnOkComeBack[] = _("OK, {B_BUFF1}! Come back!");
static const u8 sText_PkmnGoodComeBack[] = _("Good job, {B_BUFF1}! Come back!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} withdrew {B_BUFF1}!");
static const u8 sText_Trainer2WithdrewPkmn[] = _("{B_TRAINER2_NAME_WITH_CLASS} withdrew {B_BUFF1}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{B_LINK_OPPONENT1_NAME} withdrew {B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{B_LINK_OPPONENT2_NAME} withdrew {B_BUFF1}!");
static const u8 sText_WildPkmnPrefix[] = _("The wild ");
static const u8 sText_WildPkmnPrefixPt[] = _("O ");
static const u8 sText_WildPkmnPrefixEs[] = _("El ");
static const u8 sText_FoePkmnPrefix[] = _("The opposing ");
static const u8 sText_FoePkmnPrefixPt[] = _("O adversário ");
static const u8 sText_FoePkmnPrefixEs[] = _("El rival ");
static const u8 sText_WildPkmnPrefixLower[] = _("the wild ");
static const u8 sText_WildPkmnPrefixLowerPt[] = _("o ");
static const u8 sText_WildPkmnPrefixLowerEs[] = _("el ");
static const u8 sText_FoePkmnPrefixLower[] = _("the opposing ");
static const u8 sText_FoePkmnPrefixLowerPt[] = _("o adversário ");
static const u8 sText_FoePkmnPrefixLowerEs[] = _("el rival ");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("Opposing");
static const u8 sText_FoePkmnPrefix2Pt[] = _("Adversário");
static const u8 sText_FoePkmnPrefix2Es[] = _("Rival");
static const u8 sText_AllyPkmnPrefix[] = _("Ally");
static const u8 sText_AllyPkmnPrefixPt[] = _("Aliado");
static const u8 sText_AllyPkmnPrefixEs[] = _("Aliado");
static const u8 sText_FoePkmnPrefix3[] = _("Opposing");
static const u8 sText_FoePkmnPrefix3Pt[] = _("Adversário");
static const u8 sText_FoePkmnPrefix3Es[] = _("Rival");
static const u8 sText_AllyPkmnPrefix2[] = _("Ally");
static const u8 sText_AllyPkmnPrefix2Pt[] = _("Aliado");
static const u8 sText_AllyPkmnPrefix2Es[] = _("Aliado");
static const u8 sText_FoePkmnPrefix4[] = _("Opposing");
static const u8 sText_FoePkmnPrefix4Pt[] = _("Adversário");
static const u8 sText_FoePkmnPrefix4Es[] = _("Rival");
static const u8 sText_AllyPkmnPrefix3[] = _("Ally");
static const u8 sText_AllyPkmnPrefix3Pt[] = _("Aliado");
static const u8 sText_AllyPkmnPrefix3Es[] = _("Aliado");
static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} used {B_BUFF3}!");
static const u8 sText_AttackerUsedXPt[] = _("{B_ATK_NAME_WITH_PREFIX} usou {B_BUFF3}!");
static const u8 sText_AttackerUsedXEs[] = _("¡{B_ATK_NAME_WITH_PREFIX} usó {B_BUFF3}!");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP[] = _("HP");
static const u8 sText_Attack[] = _("Attack");
static const u8 sText_Defense[] = _("Defense");
static const u8 sText_Speed[] = _("Speed");
static const u8 sText_SpAttack[] = _("Sp. Atk");
static const u8 sText_SpDefense[] = _("Sp. Def");
static const u8 sText_Accuracy[] = _("accuracy");
static const u8 sText_Evasiveness[] = _("evasiveness");

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] =
{
    [STAT_HP]      = sText_HP,
    [STAT_ATK]     = sText_Attack,
    [STAT_DEF]     = sText_Defense,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAttack,
    [STAT_SPDEF]   = sText_SpDefense,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};
const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = COMPOUND_STRING("was too spicy!"),
    [FLAVOR_DRY]    = COMPOUND_STRING("was too dry!"),
    [FLAVOR_SWEET]  = COMPOUND_STRING("was too sweet!"),
    [FLAVOR_BITTER] = COMPOUND_STRING("was too bitter!"),
    [FLAVOR_SOUR]   = COMPOUND_STRING("was too sour!"),
};

static const u8 sText_Someones[] = _("someone's");
static const u8 sText_Lanettes[] = _("LANETTE's"); //no decapitalize until it is everywhere
static const u8 sText_Bills[] = _("BILL's");
static const u8 sText_EnigmaBerry[] = _("ENIGMA BERRY"); //no decapitalize until it is everywhere
static const u8 sText_BerrySuffix[] = _(" BERRY"); //no decapitalize until it is everywhere
const u8 gText_EmptyString3[] = _("");

static const u8 sText_TwoInGameTrainersDefeated[] = _("You defeated {B_TRAINER1_NAME_WITH_CLASS} and {B_TRAINER2_NAME_WITH_CLASS}!\p");

// New battle strings.
const u8 gText_drastically[] = _(" drastically");
const u8 gText_severely[] = _("severely ");
static const u8 sText_TerrainReturnedToNormal[] = _("The terrain returned to normal!"); // Unused

const u8 *const gBattleStringsTable[STRINGID_COUNT] =
{
    [STRINGID_TRAINER1LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER1_LOSE_TEXT}"),
    [STRINGID_PKMNGAINEDEXP]                        = COMPOUND_STRING("{B_BUFF1} gained{B_BUFF2} {B_BUFF3} Exp. Points!\p"),
    [STRINGID_PKMNGREWTOLV]                         = COMPOUND_STRING("{B_BUFF1} grew to Lv. {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_PKMNLEARNEDMOVE]                      = COMPOUND_STRING("{B_BUFF1} learned {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_TRYTOLEARNMOVE1]                      = COMPOUND_STRING("{B_BUFF1} wants to learn the move {B_BUFF2}.\p"),
    [STRINGID_TRYTOLEARNMOVE2]                      = COMPOUND_STRING("However, {B_BUFF1} already knows four moves.\p"),
    [STRINGID_TRYTOLEARNMOVE3]                      = COMPOUND_STRING("Should another move be forgotten and replaced with {B_BUFF2}?"),
    [STRINGID_PKMNFORGOTMOVE]                       = COMPOUND_STRING("{B_BUFF1} forgot {B_BUFF2}…\p"),
    [STRINGID_STOPLEARNINGMOVE]                     = COMPOUND_STRING("{PAUSE 32}Do you want to give up on having {B_BUFF1} learn {B_BUFF2}?"),
    [STRINGID_DIDNOTLEARNMOVE]                      = COMPOUND_STRING("{B_BUFF1} did not learn {B_BUFF2}.\p"),
    [STRINGID_PKMNLEARNEDMOVE2]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} learned {B_BUFF1}!"),
    [STRINGID_PKMNPROTECTEDITSELF]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} protected itself!"),
    [STRINGID_ITDOESNTAFFECT]                       = COMPOUND_STRING("It doesn't affect {B_DEF_NAME_WITH_PREFIX2}…"),
    [STRINGID_ITDOESNTAFFECTSCR]                    = COMPOUND_STRING("It doesn't affect {B_SCR_NAME_WITH_PREFIX2}…"),
    [STRINGID_BATTLERFAINTED]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} fainted!\p"),
    [STRINGID_PLAYERGOTMONEY]                       = COMPOUND_STRING("You got ¥{B_BUFF1} for winning!\p"),
    [STRINGID_PLAYERWHITEOUT]                       = COMPOUND_STRING("You have no more Pokémon that can fight!\p"),
    [STRINGID_PLAYERWHITEOUT2_WILD]                 = COMPOUND_STRING("You panicked and dropped ¥{B_BUFF1}…"),
    [STRINGID_PLAYERWHITEOUT2_TRAINER]              = COMPOUND_STRING("You gave ¥{B_BUFF1} to the winner…"),
    [STRINGID_PLAYERWHITEOUT3]                      = COMPOUND_STRING("You were overwhelmed by your defeat!"),
    [STRINGID_PREVENTSESCAPE]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} prevents escape with {B_SCR_ABILITY}!\p"),
    [STRINGID_HITXTIMES]                            = COMPOUND_STRING("The Pokémon was hit {B_BUFF1} time(s)!"), //SV has dynamic plural here
    [STRINGID_PKMNFELLASLEEP]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} fell asleep!"),
    [STRINGID_PKMNMADESLEEP]                        = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} made {B_EFF_NAME_WITH_PREFIX2} sleep!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYASLEEP]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is already asleep!"),
    [STRINGID_PKMNALREADYASLEEP2]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is already asleep!"),
    [STRINGID_PKMNWASPOISONED]                      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was poisoned!"),
    [STRINGID_PKMNPOISONEDBY]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was poisoned by {B_SCR_NAME_WITH_PREFIX2}'s {B_BUFF1}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYPOISON]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by its poisoning!"),
    [STRINGID_PKMNALREADYPOISONED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is already poisoned!"),
    [STRINGID_PKMNBADLYPOISONED]                    = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was badly poisoned!"),
    [STRINGID_PKMNENERGYDRAINED]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} had its energy drained!"),
    [STRINGID_PKMNWASBURNED]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was burned!"),
    [STRINGID_PKMNBURNEDBY]                         = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} burned {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYBURN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by its burn!"),
    [STRINGID_PKMNWASFROZEN]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was frozen solid!"),
    [STRINGID_PKMNFROZENBY]                         = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} froze {B_EFF_NAME_WITH_PREFIX2} solid!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISFROZEN]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is frozen solid!"),
    [STRINGID_PKMNWASDEFROSTED]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} thawed out!"),
    [STRINGID_PKMNWASDEFROSTEDBY]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} melted the ice!"),
    [STRINGID_PKMNWASPARALYZED]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is paralyzed, so it may be unable to move!"),
    [STRINGID_PKMNWASPARALYZEDBY]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} paralyzed {B_EFF_NAME_WITH_PREFIX2}, so it may be unable to move!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISPARALYZED]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} couldn't move because it's paralyzed!"),
    [STRINGID_PKMNISALREADYPARALYZED]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is already paralyzed!"),
    [STRINGID_PKMNHEALEDPARALYSIS]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was cured of paralysis!"),
    [STRINGID_STATSWONTINCREASE]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any higher!"),
    [STRINGID_STATSWONTDECREASE]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any lower!"),
    [STRINGID_PKMNISCONFUSED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is confused!"),
    [STRINGID_PKMNHEALEDCONFUSION]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} snapped out of its confusion!"),
    [STRINGID_PKMNWASCONFUSED]                      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became confused!"),
    [STRINGID_PKMNALREADYCONFUSED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is already confused!"),
    [STRINGID_PKMNFELLINLOVE]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fell in love!"),
    [STRINGID_PKMNINLOVE]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is in love with {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNIMMOBILIZEDBYLOVE]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is immobilized by love!"),
    [STRINGID_PKMNCHANGEDTYPE]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformed into the {B_BUFF1} type!"),
    [STRINGID_PKMNFLINCHED]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} flinched and couldn't move!"),
    [STRINGID_PKMNREGAINEDHEALTH]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s HP was restored."),
    [STRINGID_PKMNHPFULL]                           = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s HP is full!"),
    [STRINGID_PKMNRAISEDSPDEF]                      = COMPOUND_STRING("Light Screen made {B_ATK_TEAM2} team stronger against special moves!"),
    [STRINGID_PKMNRAISEDDEF]                        = COMPOUND_STRING("Reflect made {B_ATK_TEAM2} team stronger against physical moves!"),
    [STRINGID_PKMNAURORAVEIL]                       = COMPOUND_STRING("Aurora Veil made {B_ATK_TEAM2} team stronger against physical and special moves!"),
    [STRINGID_PKMNCOVEREDBYVEIL]                    = COMPOUND_STRING("{B_ATK_TEAM1} team cloaked itself in a mystical veil!"),
    [STRINGID_PKMNUSEDSAFEGUARD]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is protected by Safeguard!"),
    [STRINGID_PKMNSAFEGUARDEXPIRED]                 = COMPOUND_STRING("{B_ATK_TEAM1} team is no longer protected by Safeguard!"),
    [STRINGID_PKMNWENTTOSLEEP]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} went to sleep!"), //not in gen 5+
    [STRINGID_PKMNSLEPTHEALTHY]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} slept and restored its HP!"),
    [STRINGID_PKMNWHIPPEDWHIRLWIND]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} whipped up a whirlwind!"),
    [STRINGID_PKMNTOOKSUNLIGHT]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorbed light!"),
    [STRINGID_PKMNLOWEREDHEAD]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tucked in its head!"),
    [STRINGID_PKMNFLEWHIGH]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} flew up high!"),
    [STRINGID_PKMNDUGHOLE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} burrowed its way under the ground!"),
    [STRINGID_PKMNSQUEEZEDBYBIND]                   = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was squeezed by {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNTRAPPEDINVORTEX]                  = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became trapped in the vortex!"),
    [STRINGID_PKMNWRAPPEDBY]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was wrapped by {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCLAMPED]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} clamped down on {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBY]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by {B_BUFF1}!"),
    [STRINGID_PKMNFREEDFROM]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was freed from {B_BUFF1}!"),
    [STRINGID_PKMNCRASHED]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kept going and crashed!"),
    [STRINGID_PKMNSHROUDEDINMIST]                   = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is protected by the mist!"),
    [STRINGID_PKMNGETTINGPUMPED]                    = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was damaged by the recoil!"),
    [STRINGID_PKMNPROTECTEDITSELF2]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} protected itself!"),
    [STRINGID_PKMNBUFFETEDBYSANDSTORM]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is buffeted by the sandstorm!"),
    [STRINGID_PKMNPELTEDBYHAIL]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is buffeted by the hail!"),
    [STRINGID_PKMNSEEDED]                           = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was seeded!"),
    [STRINGID_PKMNAVOIDEDATTACK]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} avoided the attack!"),
    [STRINGID_BATTLERAVOIDEDATTACK]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} avoided the attack!"),
    [STRINGID_PKMNSAPPEDBYLEECHSEED]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s health is sapped by Leech Seed!"),
    [STRINGID_PKMNFASTASLEEP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is fast asleep."),
    [STRINGID_PKMNWOKEUP]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} woke up!"),
    [STRINGID_PKMNWOKEUPINUPROAR]                   = COMPOUND_STRING("The uproar woke {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCAUSEDUPROAR]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} caused an uproar!"),
    [STRINGID_PKMNMAKINGUPROAR]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is making an uproar!"),
    [STRINGID_PKMNCALMEDDOWN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} calmed down."),
    [STRINGID_PKMNSTOCKPILED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stockpiled {B_BUFF1}!"),
    [STRINGID_PKMNCANTSLEEPINUPROAR2]               = COMPOUND_STRING("But {B_DEF_NAME_WITH_PREFIX2} can't sleep in an uproar!"),
    [STRINGID_UPROARKEPTPKMNAWAKE]                  = COMPOUND_STRING("But the uproar kept {B_DEF_NAME_WITH_PREFIX2} awake!"),
    [STRINGID_PKMNSTAYEDAWAKEUSING]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} stayed awake!"),
    [STRINGID_PKMNSTORINGENERGY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is storing energy!"),
    [STRINGID_PKMNUNLEASHEDENERGY]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} unleashed its energy!"),
    [STRINGID_PKMNFATIGUECONFUSION]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} became confused due to fatigue!"),
    [STRINGID_PLAYERPICKEDUPMONEY]                  = COMPOUND_STRING("You picked up ¥{B_BUFF1}!\p"),
    [STRINGID_PKMNUNAFFECTED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is unaffected!"),
    [STRINGID_PKMNTRANSFORMEDINTO]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformed into {B_BUFF1}!"),
    [STRINGID_PKMNMADESUBSTITUTE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} put in a substitute!"),
    [STRINGID_PKMNHASSUBSTITUTE]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} already has a substitute!"),
    [STRINGID_SUBSTITUTEDAMAGED]                    = COMPOUND_STRING("The substitute took damage for {B_DEF_NAME_WITH_PREFIX2}!\p"),
    [STRINGID_PKMNSUBSTITUTEFADED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s substitute faded!\p"),
    [STRINGID_PKMNMUSTRECHARGE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} must recharge!"),
    [STRINGID_PKMNRAGEBUILDING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s rage is building!"),
    [STRINGID_PKMNMOVEWASDISABLED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled!"),
    [STRINGID_PKMNMOVEISDISABLED]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} is disabled!\p"),
    [STRINGID_PKMNMOVEDISABLEDNOMORE]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s move is no longer disabled!"),
    [STRINGID_PKMNGOTENCORE]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} must do an encore!"),
    [STRINGID_PKMNGOTENCOREDMOVE]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} can only use {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNENCOREENDED]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} ended its encore!"),
    [STRINGID_PKMNTOOKAIM]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} took aim at {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSKETCHEDMOVE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sketched {B_BUFF1}!"),
    [STRINGID_PKMNTRYINGTOTAKEFOE]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hoping to take its attacker down with it!"),
    [STRINGID_PKMNTOOKFOE]                          = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} took its attacker down with it!"),
    [STRINGID_PKMNREDUCEDPP]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} lost {B_BUFF2} PP from {B_BUFF1}!"),
    [STRINGID_PKMNSTOLEITEM]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stole {B_EFF_NAME_WITH_PREFIX2}'s {B_LAST_ITEM}!"),
    [STRINGID_TARGETCANTESCAPENOW]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} can no longer escape!"),
    [STRINGID_PKMNFELLINTONIGHTMARE]                = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} began having a nightmare!"),
    [STRINGID_PKMNLOCKEDINNIGHTMARE]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is locked in a nightmare!"),
    [STRINGID_PKMNLAIDCURSE]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cut its own HP and put a curse on {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNAFFLICTEDBYCURSE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is afflicted by the curse!"),
    [STRINGID_SPIKESSCATTERED]                      = COMPOUND_STRING("Spikes were scattered on the ground all around {B_DEF_TEAM2} team!"),
    [STRINGID_PKMNHURTBYSPIKES]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was hurt by the spikes!"),
    [STRINGID_PKMNIDENTIFIED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was identified!"),
    [STRINGID_PKMNPERISHCOUNTFELL]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s perish count fell to {B_BUFF1}!"),
    [STRINGID_PKMNBRACEDITSELF]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} braced itself!"),
    [STRINGID_PKMNENDUREDHIT]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} endured the hit!"),
    [STRINGID_MAGNITUDESTRENGTH]                    = COMPOUND_STRING("Magnitude {B_BUFF1}!"),
    [STRINGID_PKMNCUTHPMAXEDATTACK]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cut its own HP and maximized its Attack!"),
    [STRINGID_PKMNCOPIEDSTATCHANGES]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} copied {B_EFF_NAME_WITH_PREFIX2}'s stat changes!"),
    [STRINGID_PKMNGOTFREE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was freed from {B_BUFF1}!"),
    [STRINGID_PKMNSHEDLEECHSEED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was freed from Leech Seed!"),
    [STRINGID_PKMNBLEWAWAYSPIKES]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away Spikes!"), // Not in gen 5+
    [STRINGID_PKMNFLEDFROMBATTLE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} fled from battle!"),
    [STRINGID_PKMNFORESAWATTACK]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foresaw an attack!"),
    [STRINGID_PKMNTOOKATTACK]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} took the {B_BUFF1} attack!"),
    [STRINGID_PKMNATTACK]                           = COMPOUND_STRING("{B_BUFF1}'s attack!"), // Not in gen 5+
    [STRINGID_PKMNCENTERATTENTION]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} became the center of attention!"),
    [STRINGID_PKMNCHARGINGPOWER]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} began charging power!"),
    [STRINGID_NATUREPOWERTURNEDINTO]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Nature Power turned into {B_CURRENT_MOVE}!"),
    [STRINGID_PKMNSTATUSNORMAL]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s status returned to normal!"),
    [STRINGID_PKMNHASNOMOVESLEFT]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} has no moves left that it can use!\p"),
    [STRINGID_PKMNSUBJECTEDTOTORMENT]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was subjected to torment!"),
    [STRINGID_PKMNCANTUSEMOVETORMENT]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't use the same move twice in a row due to the torment!\p"),
    [STRINGID_PKMNTIGHTENINGFOCUS]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is tightening its focus!"),
    [STRINGID_PKMNFELLFORTAUNT]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fell for the taunt!"),
    [STRINGID_PKMNCANTUSEMOVETAUNT]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't use {B_CURRENT_MOVE} after the taunt!\p"),
    [STRINGID_PKMNREADYTOHELP]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is ready to help {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSWITCHEDITEMS]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} switched items with its target!"),
    [STRINGID_PKMNCOPIEDFOE]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} copied {B_DEF_NAME_WITH_PREFIX2}'s Ability!"),
    [STRINGID_PKMNWISHCAMETRUE]                     = COMPOUND_STRING("{B_BUFF1}'s wish came true!"),
    [STRINGID_PKMNPLANTEDROOTS]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} planted its roots!"),
    [STRINGID_PKMNABSORBEDNUTRIENTS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorbed nutrients with its roots!"),
    [STRINGID_PKMNANCHOREDITSELF]                   = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is anchored in place with its roots!"),
    [STRINGID_PKMNWASMADEDROWSY]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} grew drowsy!"),
    [STRINGID_PKMNKNOCKEDOFF]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} knocked off {B_EFF_NAME_WITH_PREFIX2}'s {B_LAST_ITEM}!"),
    [STRINGID_PKMNSWAPPEDABILITIES]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} swapped Abilities with its target!"),
    [STRINGID_PKMNSEALEDOPPONENTMOVE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sealed any moves its target shares with it!"),
    [STRINGID_PKMNCANTUSEMOVESEALED]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't use its sealed {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNWANTSGRUDGE]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wants its target to bear a grudge!"),
    [STRINGID_PKMNLOSTPPGRUDGE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} lost all of {B_BUFF1}'s PP due to the grudge!"),
    [STRINGID_PKMNSHROUDEDITSELF]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shrouded itself with Magic Coat!"),
    [STRINGID_PKMNMOVEBOUNCED]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} bounced the {B_CURRENT_MOVE} back!"),
    [STRINGID_PKMNWAITSFORTARGET]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is waiting for a target to make a move!"),
    [STRINGID_PKMNSNATCHEDMOVE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} snatched {B_SCR_NAME_WITH_PREFIX2}'s move!"),
    [STRINGID_PKMNMADEITRAIN]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} made it rain!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPROTECTEDBY]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was protected by {B_DEF_ABILITY}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSUSAGE]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents {B_ATK_NAME_WITH_PREFIX2} from using {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNRESTOREDHPUSING]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} had its HP restored."),
    [STRINGID_PKMNCHANGEDTYPEWITH]                  = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s type changed to {B_BUFF1}!"),
    [STRINGID_PKMNPREVENTSROMANCEWITH]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} prevents romance!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSCONFUSIONWITH]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} cannot be confused!"),
    [STRINGID_PKMNRAISEDFIREPOWERWITH]              = COMPOUND_STRING("The power of {B_SCR_NAME_WITH_PREFIX}'s Fire-type moves rose!"),
    [STRINGID_PKMNANCHORSITSELFWITH]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is anchored in place with its suction cups!"),
    [STRINGID_PKMNPREVENTSSTATLOSSWITH]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s stats were not lowered!"),
    [STRINGID_PKMNHURTSWITH]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by {B_DEF_NAME_WITH_PREFIX2}'s {B_BUFF1}!"),
    [STRINGID_PKMNTRACED]                           = COMPOUND_STRING("It traced {B_BUFF1}'s {B_BUFF2}!"),
    [STRINGID_STATSHARPLY]                          = gText_StatSharply,
    [STRINGID_STATHARSHLY]                          = COMPOUND_STRING("harshly "),
    [STRINGID_STATROSE]                             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} rose{B_BUFF2}!"),
    [STRINGID_STATFELL]                             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} {B_BUFF2}fell!"),
    [STRINGID_CRITICALHIT]                          = COMPOUND_STRING("A critical hit!"),
    [STRINGID_ONEHITKO]                             = COMPOUND_STRING("It's a one-hit KO!"),
    [STRINGID_123POOF]                              = COMPOUND_STRING("One…{PAUSE 10}two…{PAUSE 10}and…{PAUSE 10}{PAUSE 20}{PLAY_SE SE_BALL_BOUNCE_1}ta-da!\p"),
    [STRINGID_ANDELLIPSIS]                          = COMPOUND_STRING("And…\p"),
    [STRINGID_NOTVERYEFFECTIVE]                     = COMPOUND_STRING("It's not very effective…"),
    [STRINGID_SUPEREFFECTIVE]                       = COMPOUND_STRING("It's super effective!"),
    [STRINGID_GOTAWAYSAFELY]                        = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED]                         = COMPOUND_STRING("{PLAY_SE SE_FLEE}The wild {B_BUFF1} fled!"),
    [STRINGID_NORUNNINGFROMTRAINERS]                = COMPOUND_STRING("No! There's no running from a Trainer battle!\p"),
    [STRINGID_CANTESCAPE]                           = COMPOUND_STRING("You can't escape!\p"),
    [STRINGID_DONTLEAVEBIRCH]                       = COMPOUND_STRING("PROF. BIRCH: Don't leave me like this!\p"), //no decapitalize until it is everywhere
    [STRINGID_BUTNOTHINGHAPPENED]                   = COMPOUND_STRING("But nothing happened!"),
    [STRINGID_BUTITFAILED]                          = COMPOUND_STRING("But it failed!"),
    [STRINGID_ITHURTCONFUSION]                      = COMPOUND_STRING("It hurt itself in its confusion!"),
    [STRINGID_STARTEDTORAIN]                        = COMPOUND_STRING("It started to rain!"),
    [STRINGID_DOWNPOURSTARTED]                      = COMPOUND_STRING("A downpour started!"), // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
    [STRINGID_RAINCONTINUES]                        = COMPOUND_STRING("Rain continues to fall."), //not in gen 5+
    [STRINGID_DOWNPOURCONTINUES]                    = COMPOUND_STRING("The downpour continues."), // unused
    [STRINGID_RAINSTOPPED]                          = COMPOUND_STRING("The rain stopped."),
    [STRINGID_SANDSTORMBREWED]                      = COMPOUND_STRING("A sandstorm kicked up!"),
    [STRINGID_SANDSTORMRAGES]                       = COMPOUND_STRING("The sandstorm is raging."),
    [STRINGID_SANDSTORMSUBSIDED]                    = COMPOUND_STRING("The sandstorm subsided."),
    [STRINGID_SUNLIGHTGOTBRIGHT]                    = COMPOUND_STRING("The sunlight turned harsh!"),
    [STRINGID_SUNLIGHTSTRONG]                       = COMPOUND_STRING("The sunlight is strong."), //not in gen 5+
    [STRINGID_SUNLIGHTFADED]                        = COMPOUND_STRING("The sunlight faded."),
    [STRINGID_STARTEDHAIL]                          = COMPOUND_STRING("It started to hail!"),
    [STRINGID_HAILCONTINUES]                        = COMPOUND_STRING("The hail is crashing down."),
    [STRINGID_HAILSTOPPED]                          = COMPOUND_STRING("The hail stopped."),
    [STRINGID_STATCHANGESGONE]                      = COMPOUND_STRING("All stat changes were eliminated!"),
    [STRINGID_COINSSCATTERED]                       = COMPOUND_STRING("Coins were scattered everywhere!"),
    [STRINGID_TOOWEAKFORSUBSTITUTE]                 = COMPOUND_STRING("But it does not have enough HP left to make a substitute!"),
    [STRINGID_SHAREDPAIN]                           = COMPOUND_STRING("The battlers shared their pain!"),
    [STRINGID_BELLCHIMED]                           = COMPOUND_STRING("A bell chimed!"),
    [STRINGID_FAINTINTHREE]                         = COMPOUND_STRING("All Pokémon that heard the song will faint in three turns!"),
    [STRINGID_NOPPLEFT]                             = COMPOUND_STRING("There's no PP left for this move!\p"), //not in gen 5+
    [STRINGID_BUTNOPPLEFT]                          = COMPOUND_STRING("But there was no PP left for the move!"),
    [STRINGID_PLAYERUSEDITEM]                       = COMPOUND_STRING("You used {B_LAST_ITEM}!"),
    [STRINGID_WALLYUSEDITEM]                        = COMPOUND_STRING("WALLY used {B_LAST_ITEM}!"), //no decapitalize until it is everywhere
    [STRINGID_TRAINERBLOCKEDBALL]                   = COMPOUND_STRING("The Trainer blocked your Poké Ball!"),
    [STRINGID_DONTBEATHIEF]                         = COMPOUND_STRING("Don't be a thief!"),
    [STRINGID_ITDODGEDBALL]                         = COMPOUND_STRING("It dodged your thrown Poké Ball! This Pokémon can't be caught!"),
    [STRINGID_PKMNBROKEFREE]                        = COMPOUND_STRING("Oh no! The Pokémon broke free!"),
    [STRINGID_ITAPPEAREDCAUGHT]                     = COMPOUND_STRING("Aww! It appeared to be caught!"),
    [STRINGID_AARGHALMOSTHADIT]                     = COMPOUND_STRING("Aargh! Almost had it!"),
    [STRINGID_SHOOTSOCLOSE]                         = COMPOUND_STRING("Gah! It was so close, too!"),
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER]               = COMPOUND_STRING("Gotcha! {B_DEF_NAME} was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p"),
    [STRINGID_GOTCHAPKMNCAUGHTWALLY]                = COMPOUND_STRING("Gotcha! {B_DEF_NAME} was caught!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}"),
    [STRINGID_GIVENICKNAMECAPTURED]                 = COMPOUND_STRING("Would you like to give {B_DEF_NAME} a nickname?"),
    [STRINGID_PKMNDATAADDEDTODEX]                   = COMPOUND_STRING("{B_DEF_NAME}'s data has been added to the Pokédex!\p"),
    [STRINGID_ITISRAINING]                          = COMPOUND_STRING("It's raining!"),
    [STRINGID_SANDSTORMISRAGING]                    = COMPOUND_STRING("The sandstorm is raging!"),
    [STRINGID_CANTESCAPE2]                          = COMPOUND_STRING("You couldn't get away!\p"),
    [STRINGID_PKMNIGNORESASLEEP]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ignored orders and kept sleeping!"),
    [STRINGID_PKMNIGNOREDORDERS]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ignored orders!"),
    [STRINGID_PKMNBEGANTONAP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} began to nap!"),
    [STRINGID_PKMNLOAFING]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is loafing around!"),
    [STRINGID_PKMNWONTOBEY]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} won't obey!"),
    [STRINGID_PKMNTURNEDAWAY]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} turned away!"),
    [STRINGID_PKMNPRETENDNOTNOTICE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} pretended not to notice!"),
    [STRINGID_ENEMYABOUTTOSWITCHPKMN]               = COMPOUND_STRING("{B_TRAINER1_NAME_WITH_CLASS} is about to send out {B_BUFF2}. Will you switch your Pokémon?"),
    [STRINGID_CREPTCLOSER]                          = COMPOUND_STRING("{B_PLAYER_NAME} crept closer to {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_CANTGETCLOSER]                        = COMPOUND_STRING("{B_PLAYER_NAME} can't get any closer!"), //safari
    [STRINGID_PKMNWATCHINGCAREFULLY]                = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is watching carefully!"), //safari
    [STRINGID_PKMNCURIOUSABOUTX]                    = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is curious about the {B_BUFF1}!"), //safari
    [STRINGID_PKMNENTHRALLEDBYX]                    = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is enthralled by the {B_BUFF1}!"), //safari
    [STRINGID_PKMNIGNOREDX]                         = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} completely ignored the {B_BUFF1}!"), //safari
    [STRINGID_THREWPOKEBLOCKATPKMN]                 = COMPOUND_STRING("{B_PLAYER_NAME} threw a {POKEBLOCK} at the {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_OUTOFSAFARIBALLS]                     = COMPOUND_STRING("{PLAY_SE SE_DING_DONG}ANNOUNCER: You're out of Safari Balls! Game over!\p"), //safari
    [STRINGID_PKMNSITEMCUREDPARALYSIS]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its paralysis!"),
    [STRINGID_PKMNSITEMCUREDPOISON]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its poison!"),
    [STRINGID_PKMNSITEMHEALEDBURN]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its burn!"),
    [STRINGID_PKMNSITEMDEFROSTEDIT]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} defrosted it!"),
    [STRINGID_PKMNSITEMWOKEIT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} woke it up!"),
    [STRINGID_PKMNSITEMSNAPPEDOUT]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} snapped it out of its confusion!"),
    [STRINGID_PKMNSITEMCUREDPROBLEM]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its {B_BUFF1} problem!"), // Not in Gen 5+
    [STRINGID_PKMNSITEMRESTOREDHEALTH]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restored its health using its {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDPP]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restored PP to its move {B_BUFF1} using its {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDSTATUS]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} returned its stats to normal using its {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE]           = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restored a little HP using its {B_LAST_ITEM}!"),
    [STRINGID_ITEMALLOWSONLYYMOVE]                  = COMPOUND_STRING("{B_LAST_ITEM} only allows the use of {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNHUNGONWITHX]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hung on using its {B_LAST_ITEM}!"),
    [STRINGID_EMPTYSTRING3]                         = gText_EmptyString3,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} had its HP restored."),
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} whipped up a sandstorm!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXPREVENTSYLOSS]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} was not lowered!"),
    [STRINGID_PKMNSXINFATUATEDY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} fell in love!"),
    [STRINGID_PKMNSXMADEYINEFFECTIVE]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s item cannot be removed!"),
    [STRINGID_ITSUCKEDLIQUIDOOZE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sucked up the liquid ooze!"),
    [STRINGID_PKMNTRANSFORMED]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} transformed!"),
    [STRINGID_ELECTRICITYWEAKENED]                  = COMPOUND_STRING("Electricity's power was weakened!"),
    [STRINGID_FIREWEAKENED]                         = COMPOUND_STRING("Fire's power was weakened!"),
    [STRINGID_PKMNHIDUNDERWATER]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hid underwater!"),
    [STRINGID_PKMNSPRANGUP]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sprang up!"),
    [STRINGID_HMMOVESCANTBEFORGOTTEN]               = COMPOUND_STRING("HM moves can't be forgotten now.\p"),
    [STRINGID_XFOUNDONEY]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} found one {B_LAST_ITEM}!"),
    [STRINGID_PLAYERDEFEATEDTRAINER1]               = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA]                        = COMPOUND_STRING("A soothing aroma wafted through the area!"),
    [STRINGID_ITEMSCANTBEUSEDNOW]                   = COMPOUND_STRING("Items can't be used now.{PAUSE 64}"), // Not present in Gen 5+
    [STRINGID_USINGITEMSTATOFPKMNROSE]              = COMPOUND_STRING("The {B_LAST_ITEM}{B_BUFF2} boosted {B_SCR_NAME_WITH_PREFIX2}'s {B_BUFF1}!"),
    [STRINGID_USINGITEMSTATOFPKMNFELL]              = COMPOUND_STRING("The {B_LAST_ITEM}{B_BUFF2} lowered {B_SCR_NAME_WITH_PREFIX2}'s {B_BUFF1}!"), // This string does not exist in Gen 5+. Used to print more info that's otherwise obscured such as using Room Service
    [STRINGID_PKMNUSEDXTOGETPUMPED]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} used the {B_LAST_ITEM} to get pumped!"),
    [STRINGID_PKMNSXMADEYUSELESS]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} made {B_CURRENT_MOVE} useless!"), //not in gen 5+, ability popup
    [STRINGID_PKMNTRAPPEDBYSANDTOMB]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became trapped by the quicksand!"),
    [STRINGID_EMPTYSTRING4]                         = COMPOUND_STRING(""),
    [STRINGID_ABOOSTED]                             = COMPOUND_STRING(" a boosted"),
    [STRINGID_PKMNSXINTENSIFIEDSUN]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} intensified the sun's rays!"), //not in gen 5+, ability popup
    [STRINGID_YOUTHROWABALLNOWRIGHT]                = COMPOUND_STRING("You throw a Ball now, right? I… I'll do my best!"),
    [STRINGID_PKMNSXTOOKATTACK]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} took the attack!"),
    [STRINGID_PKMNCHOSEXASDESTINY]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} chose Doom Desire as its destiny!"),
    [STRINGID_PKMNLOSTFOCUS]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} lost its focus and couldn't move!"),
    [STRINGID_USENEXTPKMN]                          = COMPOUND_STRING("Use next Pokémon?"),
    [STRINGID_PKMNFLEDUSINGITS]                     = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fled using its {B_LAST_ITEM}!\p"),
    [STRINGID_PKMNFLEDUSING]                        = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fled using {B_ATK_ABILITY}!\p"), //not in gen 5+
    [STRINGID_PKMNWASDRAGGEDOUT]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was dragged out!\p"),
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} normalized its status!"), // Not in Gen 5+
    [STRINGID_TRAINER1USEDITEM]                     = COMPOUND_STRING("{B_ATK_TRAINER_NAME_WITH_CLASS} used {B_LAST_ITEM}!"),
    [STRINGID_BOXISFULL]                            = COMPOUND_STRING("The Box is full! You can't catch any more!\p"),
    [STRINGID_PKMNSXMADEITINEFFECTIVE]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} made it ineffective!"),
    [STRINGID_PKMNSXPREVENTSFLINCHING]              = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY} prevents flinching!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYHASBURN]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is already burned!"),
    [STRINGID_PKMNSXBLOCKSY]                        = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} blocks {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXWOREOFF]                        = COMPOUND_STRING("{B_ATK_TEAM1} team's {B_BUFF1} wore off!"),
    [STRINGID_THEWALLSHATTERED]                     = COMPOUND_STRING("The wall shattered!"), //not in gen5+, uses "your teams light screen wore off!" etc instead
    [STRINGID_PKMNSXCUREDITSYPROBLEM]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} cured its {B_BUFF1} problem!"), //not in gen 5+, ability popup
    [STRINGID_ATTACKERCANTESCAPE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't escape!"),
    [STRINGID_PKMNOBTAINEDX]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} obtained {B_BUFF1}."),
    [STRINGID_PKMNOBTAINEDX2]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} obtained {B_BUFF2}."),
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} obtained {B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} obtained {B_BUFF2}."),
    [STRINGID_BUTNOEFFECT]                          = COMPOUND_STRING("But it had no effect!"),
    [STRINGID_TWOENEMIESDEFEATED]                   = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER2_LOSE_TEXT}"),
    [STRINGID_PKMNINCAPABLEOFPOWER]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} appears incapable of using its power!"),
    [STRINGID_GLINTAPPEARSINEYE]                    = COMPOUND_STRING("A glint appears in {B_SCR_NAME_WITH_PREFIX2}'s eyes!"),
    [STRINGID_PKMNGETTINGINTOPOSITION]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is getting into position!"),
    [STRINGID_PKMNBEGANGROWLINGDEEPLY]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} began growling deeply!"),
    [STRINGID_PKMNEAGERFORMORE]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is eager for more!"),
    [STRINGID_DEFEATEDOPPONENTBYREFEREE]            = COMPOUND_STRING("{B_PLAYER_MON1_NAME} defeated the opponent {B_OPPONENT_MON1_NAME} in a REFEREE's decision!"),
    [STRINGID_LOSTTOOPPONENTBYREFEREE]              = COMPOUND_STRING("{B_PLAYER_MON1_NAME} lost to the opponent {B_OPPONENT_MON1_NAME} in a REFEREE's decision!"),
    [STRINGID_TIEDOPPONENTBYREFEREE]                = COMPOUND_STRING("{B_PLAYER_MON1_NAME} tied the opponent {B_OPPONENT_MON1_NAME} in a REFEREE's decision!"),
    [STRINGID_QUESTIONFORFEITMATCH]                 = COMPOUND_STRING("Would you like to forfeit the match and quit now?"),
    [STRINGID_FORFEITEDMATCH]                       = COMPOUND_STRING("The match was forfeited."),
    [STRINGID_PKMNTRANSFERREDSOMEONESPC]            = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC]            = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL]                = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL]                = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT]                      = COMPOUND_STRING("{B_TRAINER1_WIN_TEXT}"),
    [STRINGID_TRAINER2WINTEXT]                      = COMPOUND_STRING("{B_TRAINER2_WIN_TEXT}"),
    [STRINGID_ENDUREDSTURDY]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} endured the hit using {B_DEF_ABILITY}!"),
    [STRINGID_POWERHERB]                            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became fully charged due to its {B_LAST_ITEM}!"),
    [STRINGID_HURTBYITEM]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by the {B_LAST_ITEM}!"),
    [STRINGID_GRAVITYINTENSIFIED]                   = COMPOUND_STRING("Gravity intensified!"),
    [STRINGID_TARGETWOKEUP]                         = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} woke up!"),
    [STRINGID_TAILWINDBLEW]                         = COMPOUND_STRING("The Tailwind blew from behind {B_ATK_TEAM2} team!"),
    [STRINGID_PKMNWENTBACK]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} went back to {B_ATK_TRAINER_NAME}!"),
    [STRINGID_PKMNCANTUSEITEMSANYMORE]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} can't use items anymore!"),
    [STRINGID_PKMNFLUNG]                            = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} flung its {B_LAST_ITEM}!"),
    [STRINGID_PKMNPREVENTEDFROMHEALING]             = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was prevented from healing!"),
    [STRINGID_PKMNSWITCHEDATKANDDEF]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} switched its Attack and Defense!"),
    [STRINGID_PKMNSABILITYSUPPRESSED]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Ability was suppressed!"),
    [STRINGID_SHIELDEDFROMCRITICALHITS]             = COMPOUND_STRING("Lucky Chant shielded {B_ATK_TEAM2} team from critical hits!"),
    [STRINGID_PKMNACQUIREDABILITY]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} acquired {B_DEF_ABILITY}!"),
    [STRINGID_POISONSPIKESSCATTERED]                = COMPOUND_STRING("Poison spikes were scattered on the ground all around {B_DEF_TEAM2} team!"),
    [STRINGID_PKMNSWITCHEDSTATCHANGES]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} switched stat changes with its target!"),
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} surrounded itself with a veil of water!"),
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM]      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} levitated with electromagnetism!"),
    [STRINGID_PKMNTWISTEDDIMENSIONS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} twisted the dimensions!"),
    [STRINGID_POINTEDSTONESFLOAT]                   = COMPOUND_STRING("Pointed stones float in the air around {B_DEF_TEAM2} team!"),
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became trapped by swirling magma!"),
    [STRINGID_VANISHEDINSTANTLY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} vanished instantly!"),
    [STRINGID_PROTECTEDTEAM]                        = COMPOUND_STRING("{B_CURRENT_MOVE} protected {B_ATK_TEAM2} team!"),
    [STRINGID_SHAREDITSGUARD]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shared its guard with the target!"),
    [STRINGID_SHAREDITSPOWER]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shared its power with the target!"),
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON]         = COMPOUND_STRING("It created a bizarre area in which Defense and Sp. Def stats are swapped!"),
    [STRINGID_BECAMENIMBLE]                         = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} became nimble!"),
    [STRINGID_HURLEDINTOTHEAIR]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was hurled into the air!"),
    [STRINGID_HELDITEMSLOSEEFFECTS]                 = COMPOUND_STRING("It created a bizarre area in which Pokémon's held items lose their effects!"),
    [STRINGID_FELLSTRAIGHTDOWN]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} fell straight down!"),
    [STRINGID_TARGETCHANGEDTYPE]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} transformed into the {B_BUFF1} type!"),
    [STRINGID_KINDOFFER]                            = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} took the kind offer!"),
    [STRINGID_RESETSTARGETSSTATLEVELS]              = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s stat changes were removed!"),
    [STRINGID_ALLYSWITCHPOSITION]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} and {B_SCR_NAME_WITH_PREFIX2} switched places!"),
    [STRINGID_REFLECTTARGETSTYPE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became the same type as {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_EMBARGOENDS]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can use items again!"),
    [STRINGID_ELECTROMAGNETISM]                     = COMPOUND_STRING("electromagnetism"),
    [STRINGID_BUFFERENDS]                           = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} wore off!"),
    [STRINGID_TELEKINESISENDS]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was freed from the telekinesis!"),
    [STRINGID_TAILWINDENDS]                         = COMPOUND_STRING("{B_ATK_TEAM1} team's Tailwind petered out!"),
    [STRINGID_LUCKYCHANTENDS]                       = COMPOUND_STRING("{B_ATK_TEAM1} team's Lucky Chant wore off!"),
    [STRINGID_TRICKROOMENDS]                        = COMPOUND_STRING("The twisted dimensions returned to normal!"),
    [STRINGID_WONDERROOMENDS]                       = COMPOUND_STRING("Wonder Room wore off, and Defense and Sp. Def stats returned to normal!"),
    [STRINGID_MAGICROOMENDS]                        = COMPOUND_STRING("Magic Room wore off, and held items' effects returned to normal!"),
    [STRINGID_MUDSPORTENDS]                         = COMPOUND_STRING("The effects of Mud Sport have faded."),
    [STRINGID_WATERSPORTENDS]                       = COMPOUND_STRING("The effects of Water Sport have faded."),
    [STRINGID_GRAVITYENDS]                          = COMPOUND_STRING("Gravity returned to normal!"),
    [STRINGID_AQUARINGHEAL]                         = COMPOUND_STRING("A veil of water restored {B_ATK_NAME_WITH_PREFIX2}'s HP!"),
    [STRINGID_ELECTRICTERRAINENDS]                  = COMPOUND_STRING("The electricity disappeared from the battlefield."),
    [STRINGID_MISTYTERRAINENDS]                     = COMPOUND_STRING("The mist disappeared from the battlefield."),
    [STRINGID_PSYCHICTERRAINENDS]                   = COMPOUND_STRING("The weirdness disappeared from the battlefield!"),
    [STRINGID_GRASSYTERRAINENDS]                    = COMPOUND_STRING("The grass disappeared from the battlefield."),
    [STRINGID_TARGETABILITYSTATRAISE]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} {B_BUFF2}raised its {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_STATWASMAXEDOUT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} maxed its {B_BUFF1}!"),
    [STRINGID_ATTACKERABILITYSTATRAISE]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} {B_BUFF2}raised its {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_POISONHEALHPUP]                       = COMPOUND_STRING("The poisoning healed {B_ATK_NAME_WITH_PREFIX2} a little bit!"), // Not in Gen 5+
    [STRINGID_BADDREAMSDMG]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is tormented!"),
    [STRINGID_MOLDBREAKERENTERS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} breaks the mold!"),
    [STRINGID_TERAVOLTENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is radiating a bursting aura!"),
    [STRINGID_TURBOBLAZEENTERS]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is radiating a blazing aura!"),
    [STRINGID_SLOWSTARTENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is slow to get going!"),
    [STRINGID_SLOWSTARTEND]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} finally got its act together!"),
    [STRINGID_SOLARPOWERHPDROP]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} takes its toll!"), // Not in Gen 5+
    [STRINGID_AFTERMATHDMG]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt!"),
    [STRINGID_ANTICIPATIONACTIVATES]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} shuddered!"),
    [STRINGID_FOREWARNACTIVATES]                    = COMPOUND_STRING("{B_SCR_ABILITY} alerted {B_SCR_NAME_WITH_PREFIX2} to {B_EFF_NAME_WITH_PREFIX2}'s {B_BUFF1}!"),
    [STRINGID_ICEBODYHPGAIN]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} healed it a little bit!"), // Not in Gen 5+
    [STRINGID_SNOWWARNINGHAIL]                      = COMPOUND_STRING("It started to hail!"),
    [STRINGID_FRISKACTIVATES]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} frisked {B_SCR_NAME_WITH_PREFIX2} and found its {B_LAST_ITEM}!"),
    [STRINGID_UNNERVEENTERS]                        = COMPOUND_STRING("{B_EFF_TEAM1} team is too nervous to eat Berries!"),
    [STRINGID_HARVESTBERRY]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} harvested its {B_LAST_ITEM}!"),
    [STRINGID_PROTEANTYPECHANGE]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} transformed it into the {B_BUFF1} type!"),
    [STRINGID_SYMBIOSISITEMPASS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} shared its {B_LAST_ITEM} with {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_STEALTHROCKDMG]                       = COMPOUND_STRING("Pointed stones dug into {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_TOXICSPIKESABSORBED]                  = COMPOUND_STRING("The poison spikes disappeared from the ground around {B_EFF_TEAM2} team!"),
    [STRINGID_TOXICSPIKESPOISONED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was poisoned!"),
    [STRINGID_TOXICSPIKESBADLYPOISONED]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was badly poisoned!"),
    [STRINGID_STICKYWEBSWITCHIN]                    = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} was caught in a sticky web!"),
    [STRINGID_HEALINGWISHCAMETRUE]                  = COMPOUND_STRING("The healing wish came true for {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_HEALINGWISHHEALED]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} regained health!"),
    [STRINGID_LUNARDANCECAMETRUE]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} became cloaked in mystical moonlight!"),
    [STRINGID_CURSEDBODYDISABLED]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} was disabled!"),
    [STRINGID_ATTACKERACQUIREDABILITY]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} acquired {B_ATK_ABILITY}!"), // Not in Gen 5+
    [STRINGID_TARGETABILITYSTATLOWER]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} {B_BUFF2}lowered its {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_TARGETSTATWONTGOHIGHER]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} won't go any higher!"),
    [STRINGID_PKMNMOVEBOUNCEDABILITY]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} was bounced back!"),
    [STRINGID_IMPOSTERTRANSFORM]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformed into {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ASSAULTVESTDOESNTALLOW]               = COMPOUND_STRING("The effects of the {B_LAST_ITEM} prevent status moves from being used!\p"),
    [STRINGID_GRAVITYPREVENTSUSAGE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can't use {B_CURRENT_MOVE} because of gravity!\p"),
    [STRINGID_HEALBLOCKPREVENTSUSAGE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was prevented from healing!\p"),
    [STRINGID_NOTDONEYET]                           = COMPOUND_STRING("This move effect is not done yet!\p"),
    [STRINGID_STICKYWEBUSED]                        = COMPOUND_STRING("A sticky web has been laid out on the ground around {B_DEF_TEAM2} team!"),
    [STRINGID_QUASHSUCCESS]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s move was postponed!"),
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away Toxic Spikes!"),
    [STRINGID_PKMNBLEWAWAYSTICKYWEB]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away Sticky Web!"),
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away Stealth Rock!"),
    [STRINGID_IONDELUGEON]                          = COMPOUND_STRING("A deluge of ions showers the battlefield!"),
    [STRINGID_TOPSYTURVYSWITCHEDSTATS]              = COMPOUND_STRING("All stat changes on {B_DEF_NAME_WITH_PREFIX2} were inverted!"),
    [STRINGID_TERRAINBECOMESMISTY]                  = COMPOUND_STRING("Mist swirled around the battlefield!"),
    [STRINGID_TERRAINBECOMESGRASSY]                 = COMPOUND_STRING("Grass grew to cover the battlefield!"),
    [STRINGID_TERRAINBECOMESELECTRIC]               = COMPOUND_STRING("An electric current ran across the battlefield!"),
    [STRINGID_TERRAINBECOMESPSYCHIC]                = COMPOUND_STRING("The battlefield got weird!"),
    [STRINGID_TARGETELECTRIFIED]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s moves have been electrified!"),
    [STRINGID_MEGAEVOREACTING]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ITEM} is reacting to {B_ATK_TRAINER_NAME}'s Mega Ring!"), //actually displays the type of mega ring in inventory, but we didnt implement them :(
    [STRINGID_MEGAEVOEVOLVED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} has Mega Evolved into Mega {B_BUFF1}!"),
    [STRINGID_DRASTICALLY]                          = gText_drastically,
    [STRINGID_SEVERELY]                             = gText_severely,
    [STRINGID_INFESTATION]                          = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} has been afflicted with an infestation by {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_NOEFFECTONTARGET]                     = COMPOUND_STRING("It won't have any effect on {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_BURSTINGFLAMESHIT]                    = COMPOUND_STRING("The bursting flames hit {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_BESTOWITEMGIVING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} received {B_LAST_ITEM} from {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THIRDTYPEADDED]                       = COMPOUND_STRING("{B_BUFF1} type was added to {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_FELLFORFEINT]                         = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} fell for the feint!"),
    [STRINGID_POKEMONCANNOTUSEMOVE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cannot use {B_CURRENT_MOVE}!"),
    [STRINGID_COVEREDINPOWDER]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is covered in powder!"),
    [STRINGID_POWDEREXPLODES]                       = COMPOUND_STRING("When the flame touched the powder on the Pokémon, it exploded!"),
    [STRINGID_BELCHCANTSELECT]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hasn't eaten any held Berries, so it can't possibly belch!\p"),
    [STRINGID_SPECTRALTHIEFSTEAL]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stole the target's boosted stats!"),
    [STRINGID_GRAVITYGROUNDING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fell from the sky due to the gravity!"),
    [STRINGID_MISTYTERRAINPREVENTS]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} surrounds itself with a protective mist!"),
    [STRINGID_GRASSYTERRAINHEALS]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is healed by the grassy terrain!"),
    [STRINGID_ELECTRICTERRAINPREVENTS]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} surrounds itself with electrified terrain!"),
    [STRINGID_PSYCHICTERRAINPREVENTS]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is protected by the Psychic Terrain!"),
    [STRINGID_SAFETYGOGGLESPROTECTED]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is not affected thanks to its {B_LAST_ITEM}!"),
    [STRINGID_FLOWERVEILPROTECTED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} surrounded itself with a veil of petals!"),
    [STRINGID_FLOWERVEILPROTECTEDTARGET]            = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} surrounded itself with a veil of petals!"),
    [STRINGID_AROMAVEILPROTECTED]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is protected by an aromatic veil!"),
    [STRINGID_CELEBRATEMESSAGE]                     = COMPOUND_STRING("Congratulations, {B_PLAYER_NAME}!"),
    [STRINGID_USEDINSTRUCTEDMOVE]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} followed {B_ATK_NAME_WITH_PREFIX2}'s instructions!"),
    [STRINGID_THROATCHOPENDS]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can use sound-based moves again!"),
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP]            = COMPOUND_STRING("The effects of Throat Chop prevent {B_ATK_NAME_WITH_PREFIX2} from using certain moves!\p"),
    [STRINGID_LASERFOCUS]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} concentrated intensely!"),
    [STRINGID_GEMACTIVATES]                         = COMPOUND_STRING("The {B_LAST_ITEM} strengthened {B_ATK_NAME_WITH_PREFIX2}'s power!"),
    [STRINGID_BERRYDMGREDUCES]                      = COMPOUND_STRING("The {B_LAST_ITEM} weakened the damage to {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_AIRBALLOONFLOAT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} floats in the air with its Air Balloon!"),
    [STRINGID_AIRBALLOONPOP]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Air Balloon popped!"),
    [STRINGID_INCINERATEBURN]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s {B_LAST_ITEM} was burnt up!"),
    [STRINGID_BUGBITE]                              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stole and ate its target's {B_LAST_ITEM}!"),
    [STRINGID_ILLUSIONWOREOFF]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s illusion wore off!"),
    [STRINGID_ATTACKERCUREDTARGETSTATUS]            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cured {B_DEF_NAME_WITH_PREFIX2}'s problem!"),
    [STRINGID_ATTACKERLOSTFIRETYPE]                 = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} burned itself out!"),
    [STRINGID_HEALERCURE]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was cured of {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_SCRIPTINGABILITYSTATRAISE]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} {B_BUFF2}raised its {B_BUFF1}!"),
    [STRINGID_RECEIVERABILITYTAKEOVER]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} was taken over!"),
    [STRINGID_PKNMABSORBINGPOWER]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is absorbing power!"),
    [STRINGID_NOONEWILLBEABLETORUNAWAY]             = COMPOUND_STRING("No one will be able to run away during the next turn!"),
    [STRINGID_DESTINYKNOTACTIVATES]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fell in love because of the {B_LAST_ITEM}!"),
    [STRINGID_CLOAKEDINAFREEZINGLIGHT]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became cloaked in a freezing light!"),
    [STRINGID_CLEARAMULETWONTLOWERSTATS]            = COMPOUND_STRING("The effects of the {B_LAST_ITEM} held by {B_SCR_NAME_WITH_PREFIX2} prevents its stats from being lowered!"),
    [STRINGID_FERVENTWISHREACHED]                   = COMPOUND_STRING("{B_ATK_TRAINER_NAME}'s fervent wish has reached {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_AIRLOCKACTIVATES]                     = COMPOUND_STRING("The effects of the weather disappeared."),
    [STRINGID_PRESSUREENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is exerting its pressure!"),
    [STRINGID_DARKAURAENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is radiating a dark aura!"),
    [STRINGID_FAIRYAURAENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is radiating a fairy aura!"),
    [STRINGID_AURABREAKENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} reversed all other Pokémon's auras!"),
    [STRINGID_COMATOSEENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is drowsing!"),
    [STRINGID_SCREENCLEANERENTERS]                  = COMPOUND_STRING("All screens on the field were cleansed!"),
    [STRINGID_FETCHEDPOKEBALL]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} found a {B_LAST_ITEM}!"),
    [STRINGID_ASANDSTORMKICKEDUP]                   = COMPOUND_STRING("A sandstorm kicked up!"),
    [STRINGID_PKMNSWILLPERISHIN3TURNS]              = COMPOUND_STRING("Both Pokémon will faint in three turns!"),
    [STRINGID_AURAFLAREDTOLIFE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s aura flared to life!"),
    [STRINGID_ASONEENTERS]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} has two Abilities!"),
    [STRINGID_CURIOUSMEDICINEENTERS]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s stat changes were removed!"),
    [STRINGID_CANACTFASTERTHANKSTO]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can act faster than normal, thanks to its {B_BUFF1}!"),
    [STRINGID_MICLEBERRYACTIVATES]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} boosted the accuracy of its next move using {B_LAST_ITEM}!"),
    [STRINGID_PKMNSHOOKOFFTHETAUNT]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} shook off the taunt!"),
    [STRINGID_PKMNGOTOVERITSINFATUATION]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} got over its infatuation!"),
    [STRINGID_ITEMCANNOTBEREMOVED]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s item cannot be removed!"),
    [STRINGID_STICKYBARBTRANSFER]                   = COMPOUND_STRING("The {B_LAST_ITEM} attached itself to {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBURNHEALED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s burn was cured!"),
    [STRINGID_REDCARDACTIVATE]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} held up its Red Card against {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_EJECTBUTTONACTIVATE]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is switched out with the {B_LAST_ITEM}!"),
    [STRINGID_ATKGOTOVERINFATUATION]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} cured its infatuation status using its {B_LAST_ITEM}!"),
    [STRINGID_TORMENTEDNOMORE]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is no longer tormented!"),
    [STRINGID_HEALBLOCKEDNOMORE]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} is no longer prevented from healing!"),
    [STRINGID_ATTACKERBECAMEFULLYCHARGED]           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became fully charged due to its bond with its trainer!\p"),
    [STRINGID_ATTACKERBECAMEASHSPECIES]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became Ash-Greninja!\p"),
    [STRINGID_EXTREMELYHARSHSUNLIGHT]               = COMPOUND_STRING("The sunlight turned extremely harsh!"),
    [STRINGID_EXTREMESUNLIGHTFADED]                 = COMPOUND_STRING("The extremely harsh sunlight faded!"),
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT]     = COMPOUND_STRING("The Water-type attack evaporated in the extremely harsh sunlight!"),
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED] = COMPOUND_STRING("The extremely harsh sunlight was not lessened at all!"),
    [STRINGID_HEAVYRAIN]                            = COMPOUND_STRING("A heavy rain began to fall!"),
    [STRINGID_HEAVYRAINLIFTED]                      = COMPOUND_STRING("The heavy rain has lifted!"),
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN]         = COMPOUND_STRING("The Fire-type attack fizzled out in the heavy rain!"),
    [STRINGID_NORELIEFROMHEAVYRAIN]                 = COMPOUND_STRING("There is no relief from this heavy rain!"),
    [STRINGID_MYSTERIOUSAIRCURRENT]                 = COMPOUND_STRING("Mysterious strong winds are protecting Flying-type Pokémon!"),
    [STRINGID_STRONGWINDSDISSIPATED]                = COMPOUND_STRING("The mysterious strong winds have dissipated!"),
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON]          = COMPOUND_STRING("The mysterious strong winds blow on regardless!"),
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS]           = COMPOUND_STRING("The mysterious strong winds weakened the attack!"),
    [STRINGID_STUFFCHEEKSCANTSELECT]                = COMPOUND_STRING("It can't use the move because it doesn't have a Berry!\p"),
    [STRINGID_PKMNREVERTEDTOPRIMAL]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s Primal Reversion! It reverted to its primal state!"),
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE]             = COMPOUND_STRING("But {B_ATK_NAME_WITH_PREFIX2} can't use the move!"),
    [STRINGID_BUTHOOPACANTUSEIT]                    = COMPOUND_STRING("But {B_ATK_NAME_WITH_PREFIX2} can't use it the way it is now!"),
    [STRINGID_BROKETHROUGHPROTECTION]               = COMPOUND_STRING("It broke through {B_EFF_NAME_WITH_PREFIX2}'s protection!"),
    [STRINGID_ABILITYALLOWSONLYMOVE]                = COMPOUND_STRING("{B_ATK_ABILITY} only allows the use of {B_CURRENT_MOVE}!\p"),
    [STRINGID_SWAPPEDABILITIES]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} swapped Abilities with its target!"),
    [STRINGID_PKMNHEALEDPOISON]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} was cured of its poisoning!"),
    [STRINGID_BATTLERTYPECHANGEDTO]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s type changed to {B_BUFF1}!"),
    [STRINGID_BOTHCANNOLONGERESCAPE]                = COMPOUND_STRING("Neither Pokémon can run away!"),
    [STRINGID_CANTESCAPEDUETOUSEDMOVE]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} can no longer escape because it used No Retreat!"),
    [STRINGID_PKMNBECAMEWEAKERTOFIRE]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} became weaker to fire!"),
    [STRINGID_ABOUTTOUSEPOLTERGEIST]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is about to be attacked by its {B_LAST_ITEM}!"),
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE]       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} can no longer escape because of Octolock!"),
    [STRINGID_NEUTRALIZINGGASENTERS]                = COMPOUND_STRING("Neutralizing gas filled the area!"),
    [STRINGID_NEUTRALIZINGGASOVER]                  = COMPOUND_STRING("The effects of the neutralizing gas wore off!"),
    [STRINGID_TARGETTOOHEAVY]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} is too heavy to be lifted!"),
    [STRINGID_PKMNTOOKTARGETHIGH]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} took {B_DEF_NAME_WITH_PREFIX2} into the sky!"),
    [STRINGID_PKMNINSNAPTRAP]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} got trapped by a snap trap!"),
    [STRINGID_METEORBEAMCHARGING]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is overflowing with space power!"),
    [STRINGID_HEATUPBEAK]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} started heating up its beak!"),
    [STRINGID_COURTCHANGE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} swapped the battle effects affecting each side of the field!"),
    [STRINGID_ZPOWERSURROUNDS]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} surrounded itself with its Z-Power!"),
    [STRINGID_ZMOVEUNLEASHED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} unleashes its full-force Z-Move!"),
    [STRINGID_ZMOVERESETSSTATS]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} returned its decreased stats to normal using its Z-Power!"),
    [STRINGID_ZMOVEALLSTATSUP]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} boosted its stats using its Z-Power!"),
    [STRINGID_ZMOVEZBOOSTCRIT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} boosted its critical-hit ratio using its Z-Power!"),
    [STRINGID_ZMOVERESTOREHP]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restored its HP using its Z-Power!"),
    [STRINGID_ZMOVESTATUP]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} boosted its stats using its Z-Power!"),
    [STRINGID_ZMOVEHPTRAP]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s HP was restored by the Z-Power!"),
    [STRINGID_ATTACKEREXPELLEDTHEPOISON]            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} managed to expel the poison so you wouldn't worry!"),
    [STRINGID_ATTACKERSHOOKITSELFAWAKE]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shook itself awake so you wouldn't worry!"),
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} gathered all its energy to break through its paralysis so you wouldn't worry!"),
    [STRINGID_ATTACKERHEALEDITSBURN]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cured its burn through sheer determination so you wouldn't worry!"),
    [STRINGID_ATTACKERMELTEDTHEICE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} melted the ice with its fiery determination so you wouldn't worry!"),
    [STRINGID_TARGETTOUGHEDITOUT]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} toughed it out so you wouldn't feel sad!"),
    [STRINGID_ATTACKERLOSTELECTRICTYPE]             = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} used up all its electricity!"),
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET]       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} switched {B_BUFF1} with its target!"),
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER]         = COMPOUND_STRING("Being hit by {B_CURRENT_MOVE} charged {B_EFF_NAME_WITH_PREFIX2} with power!"),
    [STRINGID_SUNLIGHTACTIVATEDABILITY]             = COMPOUND_STRING("The harsh sunlight activated {B_SCR_NAME_WITH_PREFIX2}'s Protosynthesis!"),
    [STRINGID_STATWASHEIGHTENED]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} was heightened!"),
    [STRINGID_ELECTRICTERRAINACTIVATEDABILITY]      = COMPOUND_STRING("The Electric Terrain activated {B_SCR_NAME_WITH_PREFIX2}'s Quark Drive!"),
    [STRINGID_ABILITYWEAKENEDSURROUNDINGMONSSTAT]   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} weakened the {B_BUFF1} of all surrounding Pokémon!\p"),
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN]  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} gained strength from the fallen!"),
    [STRINGID_PKMNSABILITYPREVENTSABILITY]          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} prevents {B_DEF_NAME_WITH_PREFIX2}'s {B_DEF_ABILITY} from working!"), //not in gen 5+, ability popup
    [STRINGID_PREPARESHELLTRAP]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} set a shell trap!"),
    [STRINGID_SHELLTRAPDIDNTWORK]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s shell trap didn't work!"),
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM]            = COMPOUND_STRING("The spikes disappeared from the ground around {B_ATK_TEAM2} team!"),
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("The poison spikes disappeared from the ground around {B_ATK_TEAM2} team!"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM]         = COMPOUND_STRING("The sticky web has disappeared from the ground around {B_ATK_TEAM2} team!"),
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("The pointed stones disappeared from around {B_ATK_TEAM2} team!"),
    [STRINGID_COULDNTFULLYPROTECT]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} couldn't fully protect itself and got hurt!"),
    [STRINGID_STOCKPILEDEFFECTWOREOFF]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s stockpiled effect wore off!"),
    [STRINGID_PKMNREVIVEDREADYTOFIGHT]              = COMPOUND_STRING("{B_BUFF1} was revived and is ready to fight again!"),
    [STRINGID_ITEMRESTOREDSPECIESHEALTH]            = COMPOUND_STRING("{B_BUFF1} had its HP restored."),
    [STRINGID_ITEMCUREDSPECIESSTATUS]               = COMPOUND_STRING("{B_BUFF1} had its status healed!"), // Not in Gen 5+
    [STRINGID_ITEMRESTOREDSPECIESPP]                = COMPOUND_STRING("The PP of {B_BUFF1}'s {B_BUFF2} was restored!"),
    [STRINGID_THUNDERCAGETRAPPED]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} trapped {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBYFROSTBITE]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by its frostbite!"),
    [STRINGID_PKMNGOTFROSTBITE]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} got frostbite!"),
    [STRINGID_PKMNSITEMHEALEDFROSTBITE]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} cured its frostbite!"),
    [STRINGID_ATTACKERHEALEDITSFROSTBITE]           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cured its frostbite through sheer determination so you wouldn't worry!"),
    [STRINGID_PKMNFROSTBITEHEALED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s frostbite was cured!"),
    [STRINGID_PKMNFROSTBITEHEALEDBY]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} cured its frostbite!"),
    [STRINGID_MIRRORHERBCOPIED]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} used its Mirror Herb to mirror its opponent's stat changes!"),
    [STRINGID_STARTEDSNOW]                          = COMPOUND_STRING("It started to snow!"),
    [STRINGID_SNOWCONTINUES]                        = COMPOUND_STRING("Snow continues to fall."), //not in gen 5+ (lol)
    [STRINGID_SNOWSTOPPED]                          = COMPOUND_STRING("The snow stopped."),
    [STRINGID_SNOWWARNINGSNOW]                      = COMPOUND_STRING("It started to snow!"),
    [STRINGID_PKMNITEMMELTED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} corroded {B_DEF_NAME_WITH_PREFIX2}'s {B_LAST_ITEM}!"),
    [STRINGID_ULTRABURSTREACTING]                   = COMPOUND_STRING("Bright light is about to burst out of {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ULTRABURSTCOMPLETED]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} regained its true power through Ultra Burst!"),
    [STRINGID_TEAMGAINEDEXP]                        = COMPOUND_STRING("The rest of your team gained Exp. Points thanks to the Exp. Share!\p"),
    [STRINGID_CURRENTMOVECANTSELECT]                = COMPOUND_STRING("{B_BUFF1} cannot be used!\p"),
    [STRINGID_TARGETISBEINGSALTCURED]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} is being salt cured!"),
    [STRINGID_TARGETISHURTBYSALTCURE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by {B_BUFF1}!"),
    [STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP]      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} got covered in sticky candy syrup!"),
    [STRINGID_SHARPSTEELFLOATS]                     = COMPOUND_STRING("Sharp-pointed pieces of steel started floating around {B_DEF_TEAM2} Pokémon!"),
    [STRINGID_SHARPSTEELDMG]                        = COMPOUND_STRING("The sharp steel bit into {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBLEWAWAYSHARPSTEEL]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blew away sharp steel!"),
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM]        = COMPOUND_STRING("The pieces of steel surrounding {B_ATK_TEAM2} Pokémon disappeared!"),
    [STRINGID_TEAMTRAPPEDWITHVINES]                 = COMPOUND_STRING("{B_EFF_TEAM1} Pokémon got trapped with vines!"),
    [STRINGID_PKMNHURTBYVINES]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by G-Max Vine Lash's ferocious beating!"),
    [STRINGID_TEAMCAUGHTINVORTEX]                   = COMPOUND_STRING("{B_EFF_TEAM1} Pokémon got caught in a vortex of water!"),
    [STRINGID_PKMNHURTBYVORTEX]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by G-Max Cannonade's vortex!"),
    [STRINGID_TEAMSURROUNDEDBYFIRE]                 = COMPOUND_STRING("{B_EFF_TEAM1} Pokémon were surrounded by fire!"),
    [STRINGID_PKMNBURNINGUP]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is burning up within G-Max Wildfire's flames!"),
    [STRINGID_TEAMSURROUNDEDBYROCKS]                = COMPOUND_STRING("{B_EFF_TEAM1} Pokémon became surrounded by rocks!"),
    [STRINGID_PKMNHURTBYROCKSTHROWN]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is hurt by rocks thrown out by G-Max Volcalith!"),
    [STRINGID_MOVEBLOCKEDBYDYNAMAX]                 = COMPOUND_STRING("The move was blocked by the power of Dynamax!"),
    [STRINGID_ZEROTOHEROTRANSFORMATION]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} underwent a heroic transformation!"),
    [STRINGID_THETWOMOVESBECOMEONE]                 = COMPOUND_STRING("The two moves have become one! It's a combined move!{PAUSE 16}"),
    [STRINGID_ARAINBOWAPPEAREDONSIDE]               = COMPOUND_STRING("A rainbow appeared in the sky on {B_ATK_TEAM2} team's side!"),
    [STRINGID_THERAINBOWDISAPPEARED]                = COMPOUND_STRING("The rainbow on {B_ATK_TEAM2} team's side disappeared!"),
    [STRINGID_WAITINGFORPARTNERSMOVE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is waiting for {B_ATK_PARTNER_NAME}'s move…{PAUSE 16}"),
    [STRINGID_SEAOFFIREENVELOPEDSIDE]               = COMPOUND_STRING("A sea of fire enveloped {B_DEF_TEAM2} team!"),
    [STRINGID_HURTBYTHESEAOFFIRE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} was hurt by the sea of fire!"),
    [STRINGID_THESEAOFFIREDISAPPEARED]              = COMPOUND_STRING("The sea of fire around {B_ATK_TEAM2} team disappeared!"),
    [STRINGID_SWAMPENVELOPEDSIDE]                   = COMPOUND_STRING("A swamp enveloped {B_EFF_TEAM2} team!"),
    [STRINGID_THESWAMPDISAPPEARED]                  = COMPOUND_STRING("The swamp around {B_ATK_TEAM2} team disappeared!"),
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is preparing to tell a chillingly bad joke!"),
    [STRINGID_HOSPITALITYRESTORATION]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} drank down all the matcha that {B_SCR_NAME_WITH_PREFIX2} made!"),
    [STRINGID_ELECTROSHOTCHARGING]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorbed electricity!"),
    [STRINGID_ITEMWASUSEDUP]                        = COMPOUND_STRING("The {B_LAST_ITEM} was used up…"),
    [STRINGID_ATTACKERLOSTITSTYPE]                  = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} lost its {B_BUFF1} type!"),
    [STRINGID_SHEDITSTAIL]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} shed its tail to create a decoy!"),
    [STRINGID_CLOAKEDINAHARSHLIGHT]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} became cloaked in a harsh light!"),
    [STRINGID_SUPERSWEETAROMAWAFTS]                 = COMPOUND_STRING("A supersweet aroma is wafting from the syrup covering {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_DIMENSIONSWERETWISTED]                = COMPOUND_STRING("The dimensions were twisted!"),
    [STRINGID_BIZARREARENACREATED]                  = COMPOUND_STRING("A bizarre area was created in which Pokémon's held items lose their effects!"),
    [STRINGID_BIZARREAREACREATED]                   = COMPOUND_STRING("A bizarre area was created in which Defense and Sp. Def stats are swapped!"),
    [STRINGID_TIDYINGUPCOMPLETE]                    = COMPOUND_STRING("Tidying up complete!"),
    [STRINGID_PKMNTERASTALLIZEDINTO]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} terastallized into the {B_BUFF1} type!"), // Does not exist, meant to mimic form change strings
    [STRINGID_BOOSTERENERGYACTIVATES]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} used its {B_LAST_ITEM} to activate {B_SCR_ABILITY}!"),
    [STRINGID_FOGCREPTUP]                           = COMPOUND_STRING("Fog crept up as thick as soup!"),
    [STRINGID_FOGISDEEP]                            = COMPOUND_STRING("The fog is deep…"),
    [STRINGID_FOGLIFTED]                            = COMPOUND_STRING("The fog lifted."),
    [STRINGID_PKMNMADESHELLGLEAM]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} made its shell gleam! It's distorting type matchups!"),
    [STRINGID_FICKLEBEAMDOUBLED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is going all out for this attack!"),
    [STRINGID_COMMANDERACTIVATES]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was swallowed by {B_BUFF1} and became {B_BUFF1}'s commander!"),
    [STRINGID_POKEFLUTECATCHY]                      = COMPOUND_STRING("{B_PLAYER_NAME} played the {B_LAST_ITEM}.\pNow, that's a catchy tune!"),
    [STRINGID_POKEFLUTE]                            = COMPOUND_STRING("{B_PLAYER_NAME} played the {B_LAST_ITEM}."),
    [STRINGID_MONHEARINGFLUTEAWOKE]                 = COMPOUND_STRING("The Pokémon hearing the flute awoke!"),
    [STRINGID_SUNLIGHTISHARSH]                      = COMPOUND_STRING("The sunlight is harsh!"),
    [STRINGID_ITISHAILING]                          = COMPOUND_STRING("It's hailing!"),
    [STRINGID_ITISSNOWING]                          = COMPOUND_STRING("It's snowing!"),
    [STRINGID_ISCOVEREDWITHGRASS]                   = COMPOUND_STRING("The battlefield is covered with grass!"),
    [STRINGID_MISTSWIRLSAROUND]                     = COMPOUND_STRING("Mist swirls around the battlefield!"),
    [STRINGID_ELECTRICCURRENTISRUNNING]             = COMPOUND_STRING("An electric current is running across the battlefield!"),
    [STRINGID_SEEMSWEIRD]                           = COMPOUND_STRING("The battlefield seems weird!"),
    [STRINGID_WAGGLINGAFINGER]                      = COMPOUND_STRING("Waggling a finger let it use {B_CURRENT_MOVE}!"),
    [STRINGID_BLOCKEDBYSLEEPCLAUSE]                 = COMPOUND_STRING("Sleep Clause kept {B_DEF_NAME_WITH_PREFIX2} awake!"),
    [STRINGID_SUPEREFFECTIVETWOFOES]                = COMPOUND_STRING("It's super effective on {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}!"),
    [STRINGID_NOTVERYEFFECTIVETWOFOES]              = COMPOUND_STRING("It's not very effective on {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}!"),
    [STRINGID_SENDCAUGHTMONPARTYORBOX]              = COMPOUND_STRING("Add {B_DEF_NAME} to your party?"),
    [STRINGID_PKMNSENTTOPCAFTERCATCH]               = gText_PkmnSentToPCAfterCatch,
    [STRINGID_PKMNDYNAMAXED]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} grew huge into its Dynamax form!"),
    [STRINGID_PKMNGIGANTAMAXED]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} grew huge into its Gigantamax form!"),
    [STRINGID_TIMETODYNAMAX]                        = COMPOUND_STRING("Time to Dynamax!"),
    [STRINGID_TIMETOGIGANTAMAX]                     = COMPOUND_STRING("Time to Gigantamax!"),
    [STRINGID_QUESTIONFORFEITBATTLE]                = COMPOUND_STRING("Would you like to give up on this battle and quit now? Quitting the battle is the same as losing the battle."),
    [STRINGID_POWERCONSTRUCTPRESENCEOFMANY]         = COMPOUND_STRING("You sense the presence of many!"),
    [STRINGID_POWERCONSTRUCTTRANSFORM]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformed into its Complete Forme!"),
    [STRINGID_ABILITYSHIELDPROTECTS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Ability is protected by the effects of its {B_LAST_ITEM}!"),
    [STRINGID_MONTOOSCAREDTOMOVE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} is too scared to move!"),
    [STRINGID_GHOSTGETOUTGETOUT]                    = COMPOUND_STRING("GHOST: Get out…… Get out……"),
    [STRINGID_SILPHSCOPEUNVEILED]                   = COMPOUND_STRING("SILPH SCOPE unveiled the GHOST's\nidentity!"),
    [STRINGID_GHOSTWASMAROWAK]                      = COMPOUND_STRING("The GHOST was MAROWAK!\p"),
    [STRINGID_TRAINER1MON1COMEBACK]                 = COMPOUND_STRING("{B_TRAINER1_NAME}: {B_OPPONENT_MON1_NAME}, come back!"),
    [STRINGID_THREWROCK]                            = COMPOUND_STRING("{B_PLAYER_NAME} threw a ROCK\nat the {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_THREWBAIT]                            = COMPOUND_STRING("{B_PLAYER_NAME} threw some BAIT\nat the {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_PKMNANGRY]                            = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is angry!"),
    [STRINGID_PKMNEATING]                           = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} is eating!"),
    [STRINGID_PKMNDISGUISEWASBUSTED]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s disguise was busted!"),
    [STRINGID_ZENMODETRIGGERED]                     = COMPOUND_STRING("{B_SCR_ABILITY} triggered!"),
    [STRINGID_ZENMODEENDED]                         = COMPOUND_STRING("{B_SCR_ABILITY} ended!"),
    [STRINGID_SCRCUREDPARALYSIS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was cured of paralysis!"),
    [STRINGID_SCRCUREDPOISON]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} was cured of its poisoning!"),
    [STRINGID_SCRCUREDBURN]                         = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s burn was cured!"),
    [STRINGID_SCRCUREDSLEEP]                        = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} woke up!"),
    [STRINGID_SCRCUREDCONFUSION]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} snapped out of its confusion!"),
    [STRINGID_PARTYCUREDPARALYSIS]                  = COMPOUND_STRING("{B_BUFF1} was cured of paralysis!"),
    [STRINGID_PARTYCUREDPOISON]                     = COMPOUND_STRING("{B_BUFF1} was cured of its poisoning!"),
    [STRINGID_PARTYCUREDBURN]                       = COMPOUND_STRING("{B_BUFF1}'s burn was cured!"),
    [STRINGID_PARTYCUREDSLEEP]                      = COMPOUND_STRING("{B_BUFF1} woke up!"),
    [STRINGID_PARTYCUREDFREEZE]                     = COMPOUND_STRING("{B_BUFF1} thawed out!"),
    [STRINGID_PARTYCUREDFROSTBITE]                  = COMPOUND_STRING("{B_BUFF1}'s frostbite was cured!"),
    [STRINGID_PKMNATKNOTLOWERED]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s Attack was not lowered!"),
    [STRINGID_REFLECTWOREOFF]                       = COMPOUND_STRING("{B_DEF_TEAM1} team's Reflect wore off!"),
    [STRINGID_LIGHTSCREENWOREOFF]                   = COMPOUND_STRING("{B_DEF_TEAM1} team's Light Screen wore off!"),
    [STRINGID_AURORAVEILWOREOFF]                    = COMPOUND_STRING("{B_DEF_TEAM1} team's Aurora Veil wore off!"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMYOU]          = COMPOUND_STRING("The sticky web has disappeared from the ground around you!"),
};

const u8 *const gBattleStringsTablePt[STRINGID_COUNT] =
{
    [STRINGID_TRAINER1LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER1_LOSE_TEXT}"),
    [STRINGID_PKMNGAINEDEXP]                        = COMPOUND_STRING("{B_BUFF1} ganhou{B_BUFF2} {B_BUFF3} pontos de Exp.!\p"),
    [STRINGID_PKMNGREWTOLV]                         = COMPOUND_STRING("{B_BUFF1} subiu para o Lv. {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_PKMNLEARNEDMOVE]                      = COMPOUND_STRING("{B_BUFF1} aprendeu {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_TRYTOLEARNMOVE1]                      = COMPOUND_STRING("{B_BUFF1} quer aprender o golpe {B_BUFF2}.\p"),
    [STRINGID_TRYTOLEARNMOVE2]                      = COMPOUND_STRING("Mas {B_BUFF1} já conhece quatro golpes.\p"),
    [STRINGID_TRYTOLEARNMOVE3]                      = COMPOUND_STRING("Esquecer outro golpe para aprender {B_BUFF2}?"),
    [STRINGID_PKMNFORGOTMOVE]                       = COMPOUND_STRING("{B_BUFF1} esqueceu {B_BUFF2}…\p"),
    [STRINGID_STOPLEARNINGMOVE]                     = COMPOUND_STRING("{PAUSE 32}Desistir de fazer {B_BUFF1} aprender {B_BUFF2}?"),
    [STRINGID_DIDNOTLEARNMOVE]                      = COMPOUND_STRING("{B_BUFF1} não aprendeu {B_BUFF2}.\p"),
    [STRINGID_PKMNLEARNEDMOVE2]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} aprendeu {B_BUFF1}!"),
    [STRINGID_PKMNPROTECTEDITSELF]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} se protegeu!"),
    [STRINGID_ITDOESNTAFFECT]                       = COMPOUND_STRING("Não afeta {B_DEF_NAME_WITH_PREFIX2}…"),
    [STRINGID_ITDOESNTAFFECTSCR]                    = COMPOUND_STRING("Isso não afeta {B_SCR_NAME_WITH_PREFIX2}…"),
    [STRINGID_BATTLERFAINTED]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} desmaiou!\p"),
    [STRINGID_PLAYERGOTMONEY]                       = COMPOUND_STRING("Você recebeu ¥{B_BUFF1} pela vitória!\p"),
    [STRINGID_PLAYERWHITEOUT]                       = COMPOUND_STRING("Você não tem mais Pokémon que possam lutar!\p"),
    [STRINGID_PLAYERWHITEOUT2_WILD]                 = COMPOUND_STRING("Você entrou em pânico e deixou cair ¥{B_BUFF1}…"),
    [STRINGID_PLAYERWHITEOUT2_TRAINER]              = COMPOUND_STRING("Você entregou ¥{B_BUFF1} ao vencedor…"),
    [STRINGID_PLAYERWHITEOUT3]                      = COMPOUND_STRING("Você foi dominado pela derrota!"),
    [STRINGID_PREVENTSESCAPE]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} impede a fuga com {B_SCR_ABILITY}!\p"),
    [STRINGID_HITXTIMES]                            = COMPOUND_STRING("O Pokémon foi atingido {B_BUFF1} vez(es)!"), //SV has dynamic plural here
    [STRINGID_PKMNFELLASLEEP]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} adormeceu!"),
    [STRINGID_PKMNMADESLEEP]                        = COMPOUND_STRING("O {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} fez {B_EFF_NAME_WITH_PREFIX2} dormir!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYASLEEP]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} já está dormindo!"),
    [STRINGID_PKMNALREADYASLEEP2]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} já está dormindo!"),
    [STRINGID_PKMNWASPOISONED]                      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} foi envenenado!"),
    [STRINGID_PKMNPOISONEDBY]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} foi envenenado pelo {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYPOISON]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sofreu dano do veneno!"),
    [STRINGID_PKMNALREADYPOISONED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} já está envenenado!"),
    [STRINGID_PKMNBADLYPOISONED]                    = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} foi gravemente envenenado!"),
    [STRINGID_PKMNENERGYDRAINED]                    = COMPOUND_STRING("A energia de {B_DEF_NAME_WITH_PREFIX} foi drenada!"),
    [STRINGID_PKMNWASBURNED]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} foi queimado!"),
    [STRINGID_PKMNBURNEDBY]                         = COMPOUND_STRING("{B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} queimou {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYBURN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sofreu dano da queimadura!"),
    [STRINGID_PKMNWASFROZEN]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} congelou!"),
    [STRINGID_PKMNFROZENBY]                         = COMPOUND_STRING("O {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} congelou {B_EFF_NAME_WITH_PREFIX2} sólido!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISFROZEN]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está congelado!"),
    [STRINGID_PKMNWASDEFROSTED]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} descongelou!"),
    [STRINGID_PKMNWASDEFROSTEDBY]                   = COMPOUND_STRING("O {B_CURRENT_MOVE} de {B_SCR_NAME_WITH_PREFIX} derreteu o gelo!"),
    [STRINGID_PKMNWASPARALYZED]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} está paralisado e pode não se mover!"),
    [STRINGID_PKMNWASPARALYZEDBY]                   = COMPOUND_STRING("O {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} paralisou {B_EFF_NAME_WITH_PREFIX2}, então ele pode não conseguir se mover!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISPARALYZED]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não conseguiu se mover por estar paralisado!"),
    [STRINGID_PKMNISALREADYPARALYZED]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} já está paralisado!"),
    [STRINGID_PKMNHEALEDPARALYSIS]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} se curou da paralisia!"),
    [STRINGID_STATSWONTINCREASE]                    = COMPOUND_STRING("O {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} não irá mais alto!"),
    [STRINGID_STATSWONTDECREASE]                    = COMPOUND_STRING("O {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} não vai cair mais!"),
    [STRINGID_PKMNISCONFUSED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está confuso!"),
    [STRINGID_PKMNHEALEDCONFUSION]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} saiu da confusão!"),
    [STRINGID_PKMNWASCONFUSED]                      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} ficou confuso!"),
    [STRINGID_PKMNALREADYCONFUSED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} já está confuso!"),
    [STRINGID_PKMNFELLINLOVE]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} se apaixonou!"),
    [STRINGID_PKMNINLOVE]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está apaixonado por {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNIMMOBILIZEDBYLOVE]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está imobilizado pelo amor!"),
    [STRINGID_PKMNCHANGEDTYPE]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformado no tipo {B_BUFF1}!"),
    [STRINGID_PKMNFLINCHED]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hesitou e não conseguiu se mover!"),
    [STRINGID_PKMNREGAINEDHEALTH]                   = COMPOUND_STRING("O HP de {B_DEF_NAME_WITH_PREFIX} foi restaurado."),
    [STRINGID_PKMNHPFULL]                           = COMPOUND_STRING("O HP de {B_DEF_NAME_WITH_PREFIX} está cheio!"),
    [STRINGID_PKMNRAISEDSPDEF]                      = COMPOUND_STRING("Light Screen tornou a equipe {B_ATK_TEAM2} mais forte contra golpes especiais!"),
    [STRINGID_PKMNRAISEDDEF]                        = COMPOUND_STRING("Reflect tornou a equipe {B_ATK_TEAM2} mais forte contra movimentos físicos!"),
    [STRINGID_PKMNAURORAVEIL]                       = COMPOUND_STRING("Aurora Veil deixou o time {B_ATK_TEAM2} mais forte contra golpes físicos e especiais!"),
    [STRINGID_PKMNCOVEREDBYVEIL]                    = COMPOUND_STRING("A equipe {B_ATK_TEAM1} se escondeu em um véu místico!"),
    [STRINGID_PKMNUSEDSAFEGUARD]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} é protegido por Safeguard!"),
    [STRINGID_PKMNSAFEGUARDEXPIRED]                 = COMPOUND_STRING("A equipe {B_ATK_TEAM1} não está mais protegida pelo Safeguard!"),
    [STRINGID_PKMNWENTTOSLEEP]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi dormir!"), //not in gen 5+
    [STRINGID_PKMNSLEPTHEALTHY]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} dormiu e restaurou seu HP!"),
    [STRINGID_PKMNWHIPPEDWHIRLWIND]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} provocou um redemoinho!"),
    [STRINGID_PKMNTOOKSUNLIGHT]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorveu luz!"),
    [STRINGID_PKMNLOWEREDHEAD]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} enfiado na cabeça!"),
    [STRINGID_PKMNFLEWHIGH]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} voou alto!"),
    [STRINGID_PKMNDUGHOLE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} abriu caminho no subsolo!"),
    [STRINGID_PKMNSQUEEZEDBYBIND]                   = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} foi espremido por {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNTRAPPEDINVORTEX]                  = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} ficou preso no vórtice!"),
    [STRINGID_PKMNWRAPPEDBY]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} foi embrulhado por {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCLAMPED]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} reprimiu {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBY]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} é ferido por {B_BUFF1}!"),
    [STRINGID_PKMNFREEDFROM]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi libertado de {B_BUFF1}!"),
    [STRINGID_PKMNCRASHED]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} continuou e travou!"),
    [STRINGID_PKMNSHROUDEDINMIST]                   = sText_PkmnShroudedInMistPt,
    [STRINGID_PKMNPROTECTEDBYMIST]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} está protegido pela névoa!"),
    [STRINGID_PKMNGETTINGPUMPED]                    = sText_PkmnGettingPumpedPt,
    [STRINGID_PKMNHITWITHRECOIL]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi danificado pelo recuo!"),
    [STRINGID_PKMNPROTECTEDITSELF2]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se protegeu!"),
    [STRINGID_PKMNBUFFETEDBYSANDSTORM]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} é atingido pela tempestade de areia!"),
    [STRINGID_PKMNPELTEDBYHAIL]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} é atingido pelo granizo!"),
    [STRINGID_PKMNSEEDED]                           = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} foi propagado!"),
    [STRINGID_PKMNAVOIDEDATTACK]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} evitou o ataque!"),
    [STRINGID_BATTLERAVOIDEDATTACK]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} evitou o ataque!"),
    [STRINGID_PKMNSAPPEDBYLEECHSEED]                = COMPOUND_STRING("A saúde de {B_ATK_NAME_WITH_PREFIX} é minada por Leech Seed!"),
    [STRINGID_PKMNFASTASLEEP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está dormindo profundamente."),
    [STRINGID_PKMNWOKEUP]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} acordou!"),
    [STRINGID_PKMNWOKEUPINUPROAR]                   = COMPOUND_STRING("O alvoroço acordou {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCAUSEDUPROAR]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} causou alvoroço!"),
    [STRINGID_PKMNMAKINGUPROAR]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está fazendo barulho!"),
    [STRINGID_PKMNCALMEDDOWN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se acalmou."),
    [STRINGID_PKMNSTOCKPILED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} armazenou {B_BUFF1}!"),
    [STRINGID_PKMNCANTSLEEPINUPROAR2]               = COMPOUND_STRING("Mas {B_DEF_NAME_WITH_PREFIX2} não consegue dormir em alvoroço!"),
    [STRINGID_UPROARKEPTPKMNAWAKE]                  = COMPOUND_STRING("Mas o alvoroço manteve {B_DEF_NAME_WITH_PREFIX2} acordado!"),
    [STRINGID_PKMNSTAYEDAWAKEUSING]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ficou acordado!"),
    [STRINGID_PKMNSTORINGENERGY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está armazenando energia!"),
    [STRINGID_PKMNUNLEASHEDENERGY]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} liberou sua energia!"),
    [STRINGID_PKMNFATIGUECONFUSION]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} ficou confuso devido ao cansaço!"),
    [STRINGID_PLAYERPICKEDUPMONEY]                  = COMPOUND_STRING("Você pegou ¥{B_BUFF1}!\p"),
    [STRINGID_PKMNUNAFFECTED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} não é afetado!"),
    [STRINGID_PKMNTRANSFORMEDINTO]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformado em {B_BUFF1}!"),
    [STRINGID_PKMNMADESUBSTITUTE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} coloque um substituto!"),
    [STRINGID_PKMNHASSUBSTITUTE]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} já tem substituto!"),
    [STRINGID_SUBSTITUTEDAMAGED]                    = COMPOUND_STRING("O substituto sofreu dano por {B_DEF_NAME_WITH_PREFIX2}!\p"),
    [STRINGID_PKMNSUBSTITUTEFADED]                  = COMPOUND_STRING("O substituto de {B_SCR_NAME_WITH_PREFIX} desapareceu!\p"),
    [STRINGID_PKMNMUSTRECHARGE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} deve recarregar!"),
    [STRINGID_PKMNRAGEBUILDING]                     = COMPOUND_STRING("A raiva de {B_DEF_NAME_WITH_PREFIX} está aumentando!"),
    [STRINGID_PKMNMOVEWASDISABLED]                  = COMPOUND_STRING("O {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX} foi desativado!"),
    [STRINGID_PKMNMOVEISDISABLED]                   = COMPOUND_STRING("{B_CURRENT_MOVE} de {B_ATK_NAME_WITH_PREFIX} está desabilitado!\p"),
    [STRINGID_PKMNMOVEDISABLEDNOMORE]               = COMPOUND_STRING("O movimento de {B_SCR_NAME_WITH_PREFIX} não está mais desativado!"),
    [STRINGID_PKMNGOTENCORE]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} deve fazer um encore!"),
    [STRINGID_PKMNGOTENCOREDMOVE]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} só pode usar {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNENCOREENDED]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} encerrou seu encore!"),
    [STRINGID_PKMNTOOKAIM]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} mirou em {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSKETCHEDMOVE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} esboçou {B_BUFF1}!"),
    [STRINGID_PKMNTRYINGTOTAKEFOE]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} espera derrubar seu atacante com ele!"),
    [STRINGID_PKMNTOOKFOE]                          = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} derrubou seu atacante junto!"),
    [STRINGID_PKMNREDUCEDPP]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} perdeu {B_BUFF2} PP de {B_BUFF1}!"),
    [STRINGID_PKMNSTOLEITEM]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} roubou o {B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_TARGETCANTESCAPENOW]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} não pode mais escapar!"),
    [STRINGID_PKMNFELLINTONIGHTMARE]                = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} começou a ter um pesadelo!"),
    [STRINGID_PKMNLOCKEDINNIGHTMARE]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está preso em um pesadelo!"),
    [STRINGID_PKMNLAIDCURSE]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cortou seu próprio HP e amaldiçoou {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNAFFLICTEDBYCURSE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} é afetado pela maldição!"),
    [STRINGID_SPIKESSCATTERED]                      = COMPOUND_STRING("Espinhos estavam espalhados pelo chão ao redor da equipe {B_DEF_TEAM2}!"),
    [STRINGID_PKMNHURTBYSPIKES]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} foi ferido pelos espinhos!"),
    [STRINGID_PKMNIDENTIFIED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} foi identificado!"),
    [STRINGID_PKMNPERISHCOUNTFELL]                  = COMPOUND_STRING("A contagem de mortes de {B_ATK_NAME_WITH_PREFIX} caiu para {B_BUFF1}!"),
    [STRINGID_PKMNBRACEDITSELF]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se preparou!"),
    [STRINGID_PKMNENDUREDHIT]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} suportou o golpe!"),
    [STRINGID_MAGNITUDESTRENGTH]                    = COMPOUND_STRING("Magnitude {B_BUFF1}!"),
    [STRINGID_PKMNCUTHPMAXEDATTACK]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cortou seu próprio HP e maximizou seu ataque!"),
    [STRINGID_PKMNCOPIEDSTATCHANGES]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} copiou as alterações de estatísticas de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNGOTFREE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi libertado de {B_BUFF1}!"),
    [STRINGID_PKMNSHEDLEECHSEED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi libertado da Leech Seed!"),
    [STRINGID_PKMNBLEWAWAYSPIKES]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} explodiu Spikes!"), // Not in gen 5+
    [STRINGID_PKMNFLEDFROMBATTLE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} fugiu da batalha!"),
    [STRINGID_PKMNFORESAWATTACK]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} previu um ataque!"),
    [STRINGID_PKMNTOOKATTACK]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} recebeu o ataque {B_BUFF1}!"),
    [STRINGID_PKMNATTACK]                           = COMPOUND_STRING("Ataque de {B_BUFF1}!"), // Not in gen 5+
    [STRINGID_PKMNCENTERATTENTION]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} se tornou o centro das atenções!"),
    [STRINGID_PKMNCHARGINGPOWER]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} começou a carregar energia!"),
    [STRINGID_NATUREPOWERTURNEDINTO]                = COMPOUND_STRING("O Poder da Natureza de {B_ATK_NAME_WITH_PREFIX} se transformou em {B_CURRENT_MOVE}!"),
    [STRINGID_PKMNSTATUSNORMAL]                     = COMPOUND_STRING("O status de {B_ATK_NAME_WITH_PREFIX} voltou ao normal!"),
    [STRINGID_PKMNHASNOMOVESLEFT]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não tem mais movimentos que possa usar!\p"),
    [STRINGID_PKMNSUBJECTEDTOTORMENT]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} foi submetido ao tormento!"),
    [STRINGID_PKMNCANTUSEMOVETORMENT]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não pode usar o mesmo movimento duas vezes seguidas devido ao tormento!\p"),
    [STRINGID_PKMNTIGHTENINGFOCUS]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está aumentando seu foco!"),
    [STRINGID_PKMNFELLFORTAUNT]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} caiu na provocação!"),
    [STRINGID_PKMNCANTUSEMOVETAUNT]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não pode usar {B_CURRENT_MOVE} após a provocação!\p"),
    [STRINGID_PKMNREADYTOHELP]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está pronto para ajudar {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSWITCHEDITEMS]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} trocou itens com seu alvo!"),
    [STRINGID_PKMNCOPIEDFOE]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} copiou a habilidade de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNWISHCAMETRUE]                     = COMPOUND_STRING("O desejo de {B_BUFF1} se tornou realidade!"),
    [STRINGID_PKMNPLANTEDROOTS]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} plantou suas raízes!"),
    [STRINGID_PKMNABSORBEDNUTRIENTS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorveu nutrientes com suas raízes!"),
    [STRINGID_PKMNANCHOREDITSELF]                   = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} está ancorado com suas raízes!"),
    [STRINGID_PKMNWASMADEDROWSY]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ficou sonolento!"),
    [STRINGID_PKMNKNOCKEDOFF]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} derrubou {B_EFF_NAME_WITH_PREFIX2} de {B_LAST_ITEM}!"),
    [STRINGID_PKMNSWAPPEDABILITIES]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} trocou Habilidades com seu alvo!"),
    [STRINGID_PKMNSEALEDOPPONENTMOVE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} selou qualquer movimento que seu alvo compartilhe com ele!"),
    [STRINGID_PKMNCANTUSEMOVESEALED]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não pode usar seu {B_CURRENT_MOVE} selado!\p"),
    [STRINGID_PKMNWANTSGRUDGE]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} quer que seu alvo guarde rancor!"),
    [STRINGID_PKMNLOSTPPGRUDGE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} perdeu todos os PP de {B_BUFF1} devido ao rancor!"),
    [STRINGID_PKMNSHROUDEDITSELF]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se envolveu com Magic Coat!"),
    [STRINGID_PKMNMOVEBOUNCED]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} recuperou o {B_CURRENT_MOVE}!"),
    [STRINGID_PKMNWAITSFORTARGET]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está esperando que um alvo faça um movimento!"),
    [STRINGID_PKMNSNATCHEDMOVE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} arrebatou o movimento de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNMADEITRAIN]                       = COMPOUND_STRING("O {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} fez chover!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPROTECTEDBY]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} foi protegido por {B_DEF_ABILITY}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSUSAGE]                    = COMPOUND_STRING("O {B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX} impede que {B_ATK_NAME_WITH_PREFIX2} use {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNRESTOREDHPUSING]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} teve seu HP restaurado."),
    [STRINGID_PKMNCHANGEDTYPEWITH]                  = COMPOUND_STRING("O tipo de {B_EFF_NAME_WITH_PREFIX} foi alterado para {B_BUFF1}!"),
    [STRINGID_PKMNPREVENTSROMANCEWITH]              = COMPOUND_STRING("O {B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX} impede o romance!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSCONFUSIONWITH]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} não pode ser confundido!"),
    [STRINGID_PKMNRAISEDFIREPOWERWITH]              = COMPOUND_STRING("O poder dos movimentos Fire-type de {B_SCR_NAME_WITH_PREFIX} aumentou!"),
    [STRINGID_PKMNANCHORSITSELFWITH]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} está ancorado no lugar com suas ventosas!"),
    [STRINGID_PKMNPREVENTSSTATLOSSWITH]             = COMPOUND_STRING("As estatísticas de {B_SCR_NAME_WITH_PREFIX} não foram reduzidas!"),
    [STRINGID_PKMNHURTSWITH]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi ferido pelo {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNTRACED]                           = COMPOUND_STRING("Ele rastreou o {B_BUFF2} de {B_BUFF1}!"),
    [STRINGID_STATSHARPLY]                          = sText_StatSharplyPt,
    [STRINGID_STATHARSHLY]                          = COMPOUND_STRING("duramente"),
    [STRINGID_STATROSE]                             = COMPOUND_STRING("{B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} subiu{B_BUFF2}!"),
    [STRINGID_STATFELL]                             = COMPOUND_STRING("{B_BUFF1} {B_BUFF2} de {B_SCR_NAME_WITH_PREFIX} caiu!"),
    [STRINGID_CRITICALHIT]                          = COMPOUND_STRING("Um golpe crítico!"),
    [STRINGID_ONEHITKO]                             = COMPOUND_STRING("É um nocaute de um golpe!"),
    [STRINGID_123POOF]                              = COMPOUND_STRING("Um…{PAUSE 10}dois…{PAUSE 10}e…{PAUSE 10}{PAUSE 20}{PLAY_SE SE_BALL_BOUNCE_1}ta-da!\p"),
    [STRINGID_ANDELLIPSIS]                          = COMPOUND_STRING("E…\p"),
    [STRINGID_NOTVERYEFFECTIVE]                     = COMPOUND_STRING("Não é muito eficaz…"),
    [STRINGID_SUPEREFFECTIVE]                       = COMPOUND_STRING("É super eficaz!"),
    [STRINGID_GOTAWAYSAFELY]                        = sText_GotAwaySafelyPt,
    [STRINGID_WILDPKMNFLED]                         = COMPOUND_STRING("{PLAY_SE SE_FLEE}O selvagem {B_BUFF1} fugiu!"),
    [STRINGID_NORUNNINGFROMTRAINERS]                = COMPOUND_STRING("Não! Não há como fugir de uma batalha de Treinador!\p"),
    [STRINGID_CANTESCAPE]                           = COMPOUND_STRING("Você não pode escapar!\p"),
    [STRINGID_DONTLEAVEBIRCH]                       = COMPOUND_STRING("Prof. BIRCH: Não me deixe assim!\p"), //no decapitalize until it is everywhere
    [STRINGID_BUTNOTHINGHAPPENED]                   = COMPOUND_STRING("Mas nada aconteceu!"),
    [STRINGID_BUTITFAILED]                          = COMPOUND_STRING("Mas falhou!"),
    [STRINGID_ITHURTCONFUSION]                      = COMPOUND_STRING("Ele se machucou em sua confusão!"),
    [STRINGID_STARTEDTORAIN]                        = COMPOUND_STRING("Começou a chover!"),
    [STRINGID_DOWNPOURSTARTED]                      = COMPOUND_STRING("Começou uma chuva torrencial!"), // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
    [STRINGID_RAINCONTINUES]                        = COMPOUND_STRING("A chuva continua a cair."), //not in gen 5+
    [STRINGID_DOWNPOURCONTINUES]                    = COMPOUND_STRING("A chuva continua."), // unused
    [STRINGID_RAINSTOPPED]                          = COMPOUND_STRING("A chuva parou."),
    [STRINGID_SANDSTORMBREWED]                      = COMPOUND_STRING("Uma tempestade de areia começou!"),
    [STRINGID_SANDSTORMRAGES]                       = COMPOUND_STRING("A tempestade de areia está violenta."),
    [STRINGID_SANDSTORMSUBSIDED]                    = COMPOUND_STRING("A tempestade de areia diminuiu."),
    [STRINGID_SUNLIGHTGOTBRIGHT]                    = COMPOUND_STRING("A luz do sol ficou forte!"),
    [STRINGID_SUNLIGHTSTRONG]                       = COMPOUND_STRING("A luz solar é forte."), //not in gen 5+
    [STRINGID_SUNLIGHTFADED]                        = COMPOUND_STRING("A luz do sol desapareceu."),
    [STRINGID_STARTEDHAIL]                          = COMPOUND_STRING("Começou a chover granizo!"),
    [STRINGID_HAILCONTINUES]                        = COMPOUND_STRING("O granizo está caindo."),
    [STRINGID_HAILSTOPPED]                          = COMPOUND_STRING("O granizo parou."),
    [STRINGID_STATCHANGESGONE]                      = COMPOUND_STRING("Todas as alterações de estatísticas foram eliminadas!"),
    [STRINGID_COINSSCATTERED]                       = COMPOUND_STRING("Moedas estavam espalhadas por toda parte!"),
    [STRINGID_TOOWEAKFORSUBSTITUTE]                 = COMPOUND_STRING("Mas não tem HP suficiente para fazer um substituto!"),
    [STRINGID_SHAREDPAIN]                           = COMPOUND_STRING("Os batalhadores compartilharam sua dor!"),
    [STRINGID_BELLCHIMED]                           = COMPOUND_STRING("Um sino tocou!"),
    [STRINGID_FAINTINTHREE]                         = COMPOUND_STRING("Todos os Pokémon que ouvirem a música irão desmaiar em três turnos!"),
    [STRINGID_NOPPLEFT]                             = COMPOUND_STRING("Não há mais PP para este movimento!\p"), //not in gen 5+
    [STRINGID_BUTNOPPLEFT]                          = COMPOUND_STRING("Mas não sobrou nenhum PP para a mudança!"),
    [STRINGID_PLAYERUSEDITEM]                       = COMPOUND_STRING("Você usou {B_LAST_ITEM}!"),
    [STRINGID_WALLYUSEDITEM]                        = COMPOUND_STRING("WALLY usou {B_LAST_ITEM}!"), //no decapitalize until it is everywhere
    [STRINGID_TRAINERBLOCKEDBALL]                   = COMPOUND_STRING("O Treinador bloqueou sua Pokébola!"),
    [STRINGID_DONTBEATHIEF]                         = COMPOUND_STRING("Não seja um ladrão!"),
    [STRINGID_ITDODGEDBALL]                         = COMPOUND_STRING("Ele se esquivou da sua Pokébola lançada! Este Pokémon não pode ser capturado!"),
    [STRINGID_PKMNBROKEFREE]                        = COMPOUND_STRING("Oh não! O Pokémon se libertou!"),
    [STRINGID_ITAPPEAREDCAUGHT]                     = COMPOUND_STRING("Ah! Parecia ter sido pego!"),
    [STRINGID_AARGHALMOSTHADIT]                     = COMPOUND_STRING("Argh! Quase consegui!"),
    [STRINGID_SHOOTSOCLOSE]                         = COMPOUND_STRING("Ah! Estava tão perto também!"),
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER]               = COMPOUND_STRING("Entendi! {B_DEF_NAME} foi pego!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p"),
    [STRINGID_GOTCHAPKMNCAUGHTWALLY]                = COMPOUND_STRING("Entendi! {B_DEF_NAME} foi pego!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}"),
    [STRINGID_GIVENICKNAMECAPTURED]                 = COMPOUND_STRING("Você gostaria de dar um apelido a {B_DEF_NAME}?"),
    [STRINGID_PKMNDATAADDEDTODEX]                   = COMPOUND_STRING("Os dados de {B_DEF_NAME} foram adicionados ao Pokédex!\p"),
    [STRINGID_ITISRAINING]                          = COMPOUND_STRING("Está chovendo!"),
    [STRINGID_SANDSTORMISRAGING]                    = COMPOUND_STRING("A tempestade de areia está forte!"),
    [STRINGID_CANTESCAPE2]                          = COMPOUND_STRING("Você não poderia fugir!\p"),
    [STRINGID_PKMNIGNORESASLEEP]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ignorou ordens e continuou dormindo!"),
    [STRINGID_PKMNIGNOREDORDERS]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ignorou ordens!"),
    [STRINGID_PKMNBEGANTONAP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} começou a tirar uma soneca!"),
    [STRINGID_PKMNLOAFING]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está vagando por aí!"),
    [STRINGID_PKMNWONTOBEY]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não obedecerá!"),
    [STRINGID_PKMNTURNEDAWAY]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se virou!"),
    [STRINGID_PKMNPRETENDNOTNOTICE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} fingiu não notar!"),
    [STRINGID_ENEMYABOUTTOSWITCHPKMN]               = COMPOUND_STRING("{B_TRAINER1_NAME_WITH_CLASS} está prestes a enviar {B_BUFF2}. Você vai trocar seu Pokémon?"),
    [STRINGID_CREPTCLOSER]                          = COMPOUND_STRING("{B_PLAYER_NAME} se aproximou de {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_CANTGETCLOSER]                        = COMPOUND_STRING("{B_PLAYER_NAME} não pode chegar mais perto!"), //safari
    [STRINGID_PKMNWATCHINGCAREFULLY]                = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} está observando com atenção!"), //safari
    [STRINGID_PKMNCURIOUSABOUTX]                    = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} está curioso sobre o {B_BUFF1}!"), //safari
    [STRINGID_PKMNENTHRALLEDBYX]                    = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} está encantado com o {B_BUFF1}!"), //safari
    [STRINGID_PKMNIGNOREDX]                         = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} ignorou completamente o {B_BUFF1}!"), //safari
    [STRINGID_THREWPOKEBLOCKATPKMN]                 = COMPOUND_STRING("{B_PLAYER_NAME} lançou um {POKEBLOCK} no {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_OUTOFSAFARIBALLS]                     = COMPOUND_STRING("{PLAY_SE SE_DING_DONG}ANNOUNCER: Você está sem Safari Balls! Fim do jogo!\p"), //safari
    [STRINGID_PKMNSITEMCUREDPARALYSIS]              = COMPOUND_STRING("O {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} curou sua paralisia!"),
    [STRINGID_PKMNSITEMCUREDPOISON]                 = COMPOUND_STRING("O {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} curou seu veneno!"),
    [STRINGID_PKMNSITEMHEALEDBURN]                  = COMPOUND_STRING("O {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} curou sua queimadura!"),
    [STRINGID_PKMNSITEMDEFROSTEDIT]                 = COMPOUND_STRING("O {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} descongelou!"),
    [STRINGID_PKMNSITEMWOKEIT]                      = COMPOUND_STRING("O {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} acordou!"),
    [STRINGID_PKMNSITEMSNAPPEDOUT]                  = COMPOUND_STRING("O {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} tirou-o de sua confusão!"),
    [STRINGID_PKMNSITEMCUREDPROBLEM]                = COMPOUND_STRING("O {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} curou seu problema {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_PKMNSITEMRESTOREDHEALTH]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restaurou sua saúde usando seu {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDPP]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restaurou o PP para seu movimento {B_BUFF1} usando seu {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDSTATUS]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} retornou suas estatísticas ao normal usando seu {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE]           = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restaurou um pouco de HP usando seu {B_LAST_ITEM}!"),
    [STRINGID_ITEMALLOWSONLYYMOVE]                  = COMPOUND_STRING("{B_LAST_ITEM} permite apenas o uso de {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNHUNGONWITHX]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} continuou usando seu {B_LAST_ITEM}!"),
    [STRINGID_EMPTYSTRING3]                         = gText_EmptyString3,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} teve seu HP restaurado."),
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM]             = COMPOUND_STRING("O {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} provocou uma tempestade de areia!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXPREVENTSYLOSS]                  = COMPOUND_STRING("O {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} não foi reduzido!"),
    [STRINGID_PKMNSXINFATUATEDY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se apaixonou!"),
    [STRINGID_PKMNSXMADEYINEFFECTIVE]               = COMPOUND_STRING("O item de {B_SCR_NAME_WITH_PREFIX} não pode ser removido!"),
    [STRINGID_ITSUCKEDLIQUIDOOZE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sugou o lodo líquido!"),
    [STRINGID_PKMNTRANSFORMED]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} transformado!"),
    [STRINGID_ELECTRICITYWEAKENED]                  = COMPOUND_STRING("O poder da eletricidade foi enfraquecido!"),
    [STRINGID_FIREWEAKENED]                         = COMPOUND_STRING("O poder do fogo foi enfraquecido!"),
    [STRINGID_PKMNHIDUNDERWATER]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se escondeu debaixo d’água!"),
    [STRINGID_PKMNSPRANGUP]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} surgiu!"),
    [STRINGID_HMMOVESCANTBEFORGOTTEN]               = COMPOUND_STRING("Os movimentos HM não podem ser esquecidos agora.\p"),
    [STRINGID_XFOUNDONEY]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} encontrou um {B_LAST_ITEM}!"),
    [STRINGID_PLAYERDEFEATEDTRAINER1]               = sText_PlayerDefeatedLinkTrainerTrainer1Pt,
    [STRINGID_SOOTHINGAROMA]                        = COMPOUND_STRING("Um aroma suave flutuou pela área!"),
    [STRINGID_ITEMSCANTBEUSEDNOW]                   = COMPOUND_STRING("Os itens não podem ser usados agora.{PAUSE 64}"), // Not present in Gen 5+
    [STRINGID_USINGITEMSTATOFPKMNROSE]              = COMPOUND_STRING("O {B_LAST_ITEM}{B_BUFF2} impulsionou o {B_BUFF1} do {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_USINGITEMSTATOFPKMNFELL]              = COMPOUND_STRING("O {B_LAST_ITEM}{B_BUFF2} baixou o {B_BUFF1} do {B_SCR_NAME_WITH_PREFIX2}!"), // This string does not exist in Gen 5+. Used to print more info that's otherwise obscured such as using Room Service
    [STRINGID_PKMNUSEDXTOGETPUMPED]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} usou o {B_LAST_ITEM} para se animar!"),
    [STRINGID_PKMNSXMADEYUSELESS]                   = COMPOUND_STRING("O {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} tornou {B_CURRENT_MOVE} inútil!"), //not in gen 5+, ability popup
    [STRINGID_PKMNTRAPPEDBYSANDTOMB]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} ficou preso na areia movediça!"),
    [STRINGID_EMPTYSTRING4]                         = COMPOUND_STRING(""),
    [STRINGID_ABOOSTED]                             = COMPOUND_STRING("um impulsionado"),
    [STRINGID_PKMNSXINTENSIFIEDSUN]                 = COMPOUND_STRING("O {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} intensificou os raios solares!"), //not in gen 5+, ability popup
    [STRINGID_YOUTHROWABALLNOWRIGHT]                = COMPOUND_STRING("Você joga uma bola agora, certo? Eu… farei o meu melhor!"),
    [STRINGID_PKMNSXTOOKATTACK]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} assumiu o ataque!"),
    [STRINGID_PKMNCHOSEXASDESTINY]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} escolheu Doom Desire como seu destino!"),
    [STRINGID_PKMNLOSTFOCUS]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} perdeu o foco e não conseguia se mover!"),
    [STRINGID_USENEXTPKMN]                          = COMPOUND_STRING("Usar o próximo Pokémon?"),
    [STRINGID_PKMNFLEDUSINGITS]                     = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fugiu usando seu {B_LAST_ITEM}!\p"),
    [STRINGID_PKMNFLEDUSING]                        = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fugiu usando {B_ATK_ABILITY}!\p"), //not in gen 5+
    [STRINGID_PKMNWASDRAGGEDOUT]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} foi arrastado!\p"),
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS]            = COMPOUND_STRING("O {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} normalizou seu status!"), // Not in Gen 5+
    [STRINGID_TRAINER1USEDITEM]                     = COMPOUND_STRING("{B_ATK_TRAINER_NAME_WITH_CLASS} usou {B_LAST_ITEM}!"),
    [STRINGID_BOXISFULL]                            = COMPOUND_STRING("A caixa está cheia! Você não pode pegar mais!\p"),
    [STRINGID_PKMNSXMADEITINEFFECTIVE]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} tornou-o ineficaz!"),
    [STRINGID_PKMNSXPREVENTSFLINCHING]              = COMPOUND_STRING("O {B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX} evita vacilar!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYHASBURN]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} já está queimado!"),
    [STRINGID_PKMNSXBLOCKSY]                        = COMPOUND_STRING("{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} bloqueia {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXWOREOFF]                        = COMPOUND_STRING("O {B_BUFF1} da equipe {B_ATK_TEAM1} passou!"),
    [STRINGID_THEWALLSHATTERED]                     = COMPOUND_STRING("A parede quebrou!"), //not in gen5+, uses "your teams light screen wore off!" etc instead
    [STRINGID_PKMNSXCUREDITSYPROBLEM]               = COMPOUND_STRING("O {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} curou seu problema {B_BUFF1}!"), //not in gen 5+, ability popup
    [STRINGID_ATTACKERCANTESCAPE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não pode escapar!"),
    [STRINGID_PKMNOBTAINEDX]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} obteve {B_BUFF1}."),
    [STRINGID_PKMNOBTAINEDX2]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} obteve {B_BUFF2}."),
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} obteve {B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} obteve {B_BUFF2}."),
    [STRINGID_BUTNOEFFECT]                          = COMPOUND_STRING("Mas não surtiu efeito!"),
    [STRINGID_TWOENEMIESDEFEATED]                   = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER2_LOSE_TEXT}"),
    [STRINGID_PKMNINCAPABLEOFPOWER]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} parece incapaz de usar seu poder!"),
    [STRINGID_GLINTAPPEARSINEYE]                    = COMPOUND_STRING("Um brilho aparece nos olhos de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNGETTINGINTOPOSITION]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} está se posicionando!"),
    [STRINGID_PKMNBEGANGROWLINGDEEPLY]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} começou a rosnar profundamente!"),
    [STRINGID_PKMNEAGERFORMORE]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} está ansioso por mais!"),
    [STRINGID_DEFEATEDOPPONENTBYREFEREE]            = COMPOUND_STRING("{B_PLAYER_MON1_NAME} derrotou o adversário {B_OPPONENT_MON1_NAME} na decisão do ÁRBITRO!"),
    [STRINGID_LOSTTOOPPONENTBYREFEREE]              = COMPOUND_STRING("{B_PLAYER_MON1_NAME} perdeu para o adversário {B_OPPONENT_MON1_NAME} na decisão do ÁRBITRO!"),
    [STRINGID_TIEDOPPONENTBYREFEREE]                = COMPOUND_STRING("{B_PLAYER_MON1_NAME} empatou com o adversário {B_OPPONENT_MON1_NAME} na decisão do ÁRBITRO!"),
    [STRINGID_QUESTIONFORFEITMATCH]                 = COMPOUND_STRING("Você gostaria de desistir da partida e desistir agora?"),
    [STRINGID_FORFEITEDMATCH]                       = COMPOUND_STRING("A partida foi perdida."),
    [STRINGID_PKMNTRANSFERREDSOMEONESPC]            = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC]            = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL]                = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL]                = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT]                      = COMPOUND_STRING("{B_TRAINER1_WIN_TEXT}"),
    [STRINGID_TRAINER2WINTEXT]                      = COMPOUND_STRING("{B_TRAINER2_WIN_TEXT}"),
    [STRINGID_ENDUREDSTURDY]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} suportou o golpe usando {B_DEF_ABILITY}!"),
    [STRINGID_POWERHERB]                            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ficou totalmente carregado devido ao seu {B_LAST_ITEM}!"),
    [STRINGID_HURTBYITEM]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi ferido pelo {B_LAST_ITEM}!"),
    [STRINGID_GRAVITYINTENSIFIED]                   = COMPOUND_STRING("A gravidade se intensificou!"),
    [STRINGID_TARGETWOKEUP]                         = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} acordou!"),
    [STRINGID_TAILWINDBLEW]                         = COMPOUND_STRING("O Tailwind soprou por trás da equipe {B_ATK_TEAM2}!"),
    [STRINGID_PKMNWENTBACK]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} voltou para {B_ATK_TRAINER_NAME}!"),
    [STRINGID_PKMNCANTUSEITEMSANYMORE]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} não pode mais usar itens!"),
    [STRINGID_PKMNFLUNG]                            = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} lançou seu {B_LAST_ITEM}!"),
    [STRINGID_PKMNPREVENTEDFROMHEALING]             = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} foi impedido de curar!"),
    [STRINGID_PKMNSWITCHEDATKANDDEF]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} trocou seu Ataque e Defesa!"),
    [STRINGID_PKMNSABILITYSUPPRESSED]               = COMPOUND_STRING("A habilidade de {B_DEF_NAME_WITH_PREFIX} foi suprimida!"),
    [STRINGID_SHIELDEDFROMCRITICALHITS]             = COMPOUND_STRING("Lucky Chant protegeu a equipe {B_ATK_TEAM2} de ataques críticos!"),
    [STRINGID_PKMNACQUIREDABILITY]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} adquiriu {B_DEF_ABILITY}!"),
    [STRINGID_POISONSPIKESSCATTERED]                = COMPOUND_STRING("Espinhos de veneno foram espalhados pelo chão ao redor da equipe {B_DEF_TEAM2}!"),
    [STRINGID_PKMNSWITCHEDSTATCHANGES]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} trocou mudanças de estatísticas com seu alvo!"),
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cercou-se com um véu de água!"),
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM]      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} levitado com eletromagnetismo!"),
    [STRINGID_PKMNTWISTEDDIMENSIONS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} distorceu as dimensões!"),
    [STRINGID_POINTEDSTONESFLOAT]                   = COMPOUND_STRING("Pedras pontiagudas flutuam no ar ao redor da equipe {B_DEF_TEAM2}!"),
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} ficou preso em turbilhões de magma!"),
    [STRINGID_VANISHEDINSTANTLY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} desapareceu instantaneamente!"),
    [STRINGID_PROTECTEDTEAM]                        = COMPOUND_STRING("{B_CURRENT_MOVE} protegeu a equipe {B_ATK_TEAM2}!"),
    [STRINGID_SHAREDITSGUARD]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} compartilhou sua guarda com o alvo!"),
    [STRINGID_SHAREDITSPOWER]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} compartilhou seu poder com o alvo!"),
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON]         = COMPOUND_STRING("Criou uma área bizarra em que Defesa e Sp. As estatísticas de Def foram trocadas!"),
    [STRINGID_BECAMENIMBLE]                         = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} tornou-se ágil!"),
    [STRINGID_HURLEDINTOTHEAIR]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} foi lançado ao ar!"),
    [STRINGID_HELDITEMSLOSEEFFECTS]                 = COMPOUND_STRING("Criou-se uma área bizarra onde os itens retidos pelos Pokémon perdem os seus efeitos!"),
    [STRINGID_FELLSTRAIGHTDOWN]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} caiu direto!"),
    [STRINGID_TARGETCHANGEDTYPE]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} transformado no tipo {B_BUFF1}!"),
    [STRINGID_KINDOFFER]                            = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} aceitou a gentil oferta!"),
    [STRINGID_RESETSTARGETSSTATLEVELS]              = COMPOUND_STRING("As alterações nas estatísticas de {B_EFF_NAME_WITH_PREFIX} foram removidas!"),
    [STRINGID_ALLYSWITCHPOSITION]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} e {B_SCR_NAME_WITH_PREFIX2} trocaram de lugar!"),
    [STRINGID_REFLECTTARGETSTYPE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tornou-se do mesmo tipo que {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_EMBARGOENDS]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} pode usar itens novamente!"),
    [STRINGID_ELECTROMAGNETISM]                     = COMPOUND_STRING("eletromagnetismo"),
    [STRINGID_BUFFERENDS]                           = COMPOUND_STRING("O {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} passou!"),
    [STRINGID_TELEKINESISENDS]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi libertado da telecinesia!"),
    [STRINGID_TAILWINDENDS]                         = COMPOUND_STRING("O Tailwind da equipe {B_ATK_TEAM1} desapareceu!"),
    [STRINGID_LUCKYCHANTENDS]                       = COMPOUND_STRING("O Lucky Chant da equipe {B_ATK_TEAM1} passou!"),
    [STRINGID_TRICKROOMENDS]                        = COMPOUND_STRING("As dimensões distorcidas voltaram ao normal!"),
    [STRINGID_WONDERROOMENDS]                       = COMPOUND_STRING("Wonder Room passou e Defense e Sp. As estatísticas de defesa voltaram ao normal!"),
    [STRINGID_MAGICROOMENDS]                        = COMPOUND_STRING("O efeito da Sala Mágica desapareceu e os efeitos dos itens retidos voltaram ao normal!"),
    [STRINGID_MUDSPORTENDS]                         = COMPOUND_STRING("Os efeitos do Mud Sport desapareceram."),
    [STRINGID_WATERSPORTENDS]                       = COMPOUND_STRING("Os efeitos dos esportes aquáticos desapareceram."),
    [STRINGID_GRAVITYENDS]                          = COMPOUND_STRING("A gravidade voltou ao normal!"),
    [STRINGID_AQUARINGHEAL]                         = COMPOUND_STRING("Um véu de água restaurou o HP de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ELECTRICTERRAINENDS]                  = COMPOUND_STRING("A eletricidade desapareceu do campo de batalha."),
    [STRINGID_MISTYTERRAINENDS]                     = COMPOUND_STRING("A névoa desapareceu do campo de batalha."),
    [STRINGID_PSYCHICTERRAINENDS]                   = COMPOUND_STRING("A estranheza desapareceu do campo de batalha!"),
    [STRINGID_GRASSYTERRAINENDS]                    = COMPOUND_STRING("A grama desapareceu do campo de batalha."),
    [STRINGID_TARGETABILITYSTATRAISE]               = COMPOUND_STRING("{B_DEF_ABILITY} {B_BUFF2} de {B_DEF_NAME_WITH_PREFIX} aumentou seu {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_STATWASMAXEDOUT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} maximizou seu {B_BUFF1}!"),
    [STRINGID_ATTACKERABILITYSTATRAISE]             = COMPOUND_STRING("{B_ATK_ABILITY} {B_BUFF2} de {B_ATK_NAME_WITH_PREFIX} aumentou seu {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_POISONHEALHPUP]                       = COMPOUND_STRING("O envenenamento curou um pouco {B_ATK_NAME_WITH_PREFIX2}!"), // Not in Gen 5+
    [STRINGID_BADDREAMSDMG]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} está atormentado!"),
    [STRINGID_MOLDBREAKERENTERS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} quebra o molde!"),
    [STRINGID_TERAVOLTENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} está irradiando uma aura explosiva!"),
    [STRINGID_TURBOBLAZEENTERS]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} está irradiando uma aura ardente!"),
    [STRINGID_SLOWSTARTENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} demora para começar!"),
    [STRINGID_SLOWSTARTEND]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} finalmente conseguiu agir!"),
    [STRINGID_SOLARPOWERHPDROP]                     = COMPOUND_STRING("O {B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX} cobra seu preço!"), // Not in Gen 5+
    [STRINGID_AFTERMATHDMG]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ficou ferido!"),
    [STRINGID_ANTICIPATIONACTIVATES]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} estremeceu!"),
    [STRINGID_FOREWARNACTIVATES]                    = COMPOUND_STRING("{B_SCR_ABILITY} alertou {B_SCR_NAME_WITH_PREFIX2} sobre o {B_BUFF1} de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ICEBODYHPGAIN]                        = COMPOUND_STRING("O {B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX} curou um pouco!"), // Not in Gen 5+
    [STRINGID_SNOWWARNINGHAIL]                      = COMPOUND_STRING("Começou a chover granizo!"),
    [STRINGID_FRISKACTIVATES]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} revistou {B_SCR_NAME_WITH_PREFIX2} e encontrou seu {B_LAST_ITEM}!"),
    [STRINGID_UNNERVEENTERS]                        = COMPOUND_STRING("A equipe {B_EFF_TEAM1} está nervosa demais para comer frutas vermelhas!"),
    [STRINGID_HARVESTBERRY]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} colheu seu {B_LAST_ITEM}!"),
    [STRINGID_PROTEANTYPECHANGE]                    = COMPOUND_STRING("O {B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX} o transformou no tipo {B_BUFF1}!"),
    [STRINGID_SYMBIOSISITEMPASS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} compartilhou seu {B_LAST_ITEM} com {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_STEALTHROCKDMG]                       = COMPOUND_STRING("Pedras pontiagudas cravadas em {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_TOXICSPIKESABSORBED]                  = COMPOUND_STRING("Os espinhos de veneno desapareceram do chão ao redor da equipe {B_EFF_TEAM2}!"),
    [STRINGID_TOXICSPIKESPOISONED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} foi envenenado!"),
    [STRINGID_TOXICSPIKESBADLYPOISONED]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} foi gravemente envenenado!"),
    [STRINGID_STICKYWEBSWITCHIN]                    = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} foi pego em uma teia pegajosa!"),
    [STRINGID_HEALINGWISHCAMETRUE]                  = COMPOUND_STRING("O desejo de cura se tornou realidade para {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_HEALINGWISHHEALED]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} recuperou a saúde!"),
    [STRINGID_LUNARDANCECAMETRUE]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} ficou envolto em luar místico!"),
    [STRINGID_CURSEDBODYDISABLED]                   = COMPOUND_STRING("O {B_BUFF1} de {B_ATK_NAME_WITH_PREFIX} foi desativado!"),
    [STRINGID_ATTACKERACQUIREDABILITY]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} adquiriu {B_ATK_ABILITY}!"), // Not in Gen 5+
    [STRINGID_TARGETABILITYSTATLOWER]               = COMPOUND_STRING("{B_DEF_ABILITY} {B_BUFF2} de {B_DEF_NAME_WITH_PREFIX} baixou seu {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_TARGETSTATWONTGOHIGHER]               = COMPOUND_STRING("O {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX} não irá mais alto!"),
    [STRINGID_PKMNMOVEBOUNCEDABILITY]               = COMPOUND_STRING("O {B_CURRENT_MOVE} de {B_DEF_NAME_WITH_PREFIX} foi recuperado!"),
    [STRINGID_IMPOSTERTRANSFORM]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformado em {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ASSAULTVESTDOESNTALLOW]               = COMPOUND_STRING("Os efeitos do {B_LAST_ITEM} impedem que movimentos de status sejam usados!\p"),
    [STRINGID_GRAVITYPREVENTSUSAGE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não pode usar {B_CURRENT_MOVE} por causa da gravidade!\p"),
    [STRINGID_HEALBLOCKPREVENTSUSAGE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi impedido de curar!\p"),
    [STRINGID_NOTDONEYET]                           = COMPOUND_STRING("Este efeito de movimento ainda não foi concluído!\p"),
    [STRINGID_STICKYWEBUSED]                        = COMPOUND_STRING("Uma teia pegajosa foi colocada no chão em torno da equipe {B_DEF_TEAM2}!"),
    [STRINGID_QUASHSUCCESS]                         = COMPOUND_STRING("A mudança de {B_DEF_NAME_WITH_PREFIX} foi adiada!"),
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} explodiu Picos Tóxicos!"),
    [STRINGID_PKMNBLEWAWAYSTICKYWEB]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} explodiu a Teia Pegajosa!"),
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} explodiu Stealth Rock!"),
    [STRINGID_IONDELUGEON]                          = COMPOUND_STRING("Um dilúvio de íons inunda o campo de batalha!"),
    [STRINGID_TOPSYTURVYSWITCHEDSTATS]              = COMPOUND_STRING("Todas as alterações de estatísticas em {B_DEF_NAME_WITH_PREFIX2} foram invertidas!"),
    [STRINGID_TERRAINBECOMESMISTY]                  = COMPOUND_STRING("A névoa girou em torno do campo de batalha!"),
    [STRINGID_TERRAINBECOMESGRASSY]                 = COMPOUND_STRING("A grama cresceu para cobrir o campo de batalha!"),
    [STRINGID_TERRAINBECOMESELECTRIC]               = COMPOUND_STRING("Uma corrente elétrica percorreu o campo de batalha!"),
    [STRINGID_TERRAINBECOMESPSYCHIC]                = COMPOUND_STRING("O campo de batalha ficou estranho!"),
    [STRINGID_TARGETELECTRIFIED]                    = COMPOUND_STRING("Os movimentos de {B_DEF_NAME_WITH_PREFIX} foram eletrificados!"),
    [STRINGID_MEGAEVOREACTING]                      = COMPOUND_STRING("{B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX} está reagindo ao Mega Ring de {B_ATK_TRAINER_NAME}!"), //actually displays the type of mega ring in inventory, but we didnt implement them :(
    [STRINGID_MEGAEVOEVOLVED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} Megaevoluiu para Mega {B_BUFF1}!"),
    [STRINGID_DRASTICALLY]                          = gText_drastically,
    [STRINGID_SEVERELY]                             = gText_severely,
    [STRINGID_INFESTATION]                          = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} foi afetado por uma infestação por {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_NOEFFECTONTARGET]                     = COMPOUND_STRING("Não terá nenhum efeito em {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_BURSTINGFLAMESHIT]                    = COMPOUND_STRING("As chamas explodindo atingiram {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_BESTOWITEMGIVING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} recebeu {B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THIRDTYPEADDED]                       = COMPOUND_STRING("O tipo {B_BUFF1} foi adicionado a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_FELLFORFEINT]                         = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} caiu na finta!"),
    [STRINGID_POKEMONCANNOTUSEMOVE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não pode usar {B_CURRENT_MOVE}!"),
    [STRINGID_COVEREDINPOWDER]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} está coberto de pó!"),
    [STRINGID_POWDEREXPLODES]                       = COMPOUND_STRING("Quando a chama tocou a pólvora do Pokémon, ela explodiu!"),
    [STRINGID_BELCHCANTSELECT]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não comeu nenhuma fruta retida, então não pode arrotar!\p"),
    [STRINGID_SPECTRALTHIEFSTEAL]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} roubou as estatísticas aumentadas do alvo!"),
    [STRINGID_GRAVITYGROUNDING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} caiu do céu devido à gravidade!"),
    [STRINGID_MISTYTERRAINPREVENTS]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} envolve-se com uma névoa protetora!"),
    [STRINGID_GRASSYTERRAINHEALS]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} é curado pelo terreno gramado!"),
    [STRINGID_ELECTRICTERRAINPREVENTS]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} cerca-se de terreno eletrificado!"),
    [STRINGID_PSYCHICTERRAINPREVENTS]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} é protegido pelo Terreno Psíquico!"),
    [STRINGID_SAFETYGOGGLESPROTECTED]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} não é afetado graças ao seu {B_LAST_ITEM}!"),
    [STRINGID_FLOWERVEILPROTECTED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} cercou-se de um véu de pétalas!"),
    [STRINGID_FLOWERVEILPROTECTEDTARGET]            = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} cercou-se de um véu de pétalas!"),
    [STRINGID_AROMAVEILPROTECTED]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} está protegido por um véu aromático!"),
    [STRINGID_CELEBRATEMESSAGE]                     = COMPOUND_STRING("Parabéns, {B_PLAYER_NAME}!"),
    [STRINGID_USEDINSTRUCTEDMOVE]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} seguiu as instruções de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THROATCHOPENDS]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} pode usar movimentos baseados em som novamente!"),
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP]            = COMPOUND_STRING("Os efeitos do Throat Chop impedem que {B_ATK_NAME_WITH_PREFIX2} use certos movimentos!\p"),
    [STRINGID_LASERFOCUS]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} concentrado intensamente!"),
    [STRINGID_GEMACTIVATES]                         = COMPOUND_STRING("O {B_LAST_ITEM} fortaleceu o poder do {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_BERRYDMGREDUCES]                      = COMPOUND_STRING("O {B_LAST_ITEM} enfraqueceu o dano ao {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_AIRBALLOONFLOAT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} flutua no ar com seu balão de ar!"),
    [STRINGID_AIRBALLOONPOP]                        = COMPOUND_STRING("O balão de ar de {B_DEF_NAME_WITH_PREFIX} estourou!"),
    [STRINGID_INCINERATEBURN]                       = COMPOUND_STRING("O {B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX} foi queimado!"),
    [STRINGID_BUGBITE]                              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} roubou e comeu o {B_LAST_ITEM} do seu alvo!"),
    [STRINGID_ILLUSIONWOREOFF]                      = COMPOUND_STRING("A ilusão de {B_SCR_NAME_WITH_PREFIX} acabou!"),
    [STRINGID_ATTACKERCUREDTARGETSTATUS]            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} curou o problema de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ATTACKERLOSTFIRETYPE]                 = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} queimou sozinho!"),
    [STRINGID_HEALERCURE]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi curado de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_SCRIPTINGABILITYSTATRAISE]            = COMPOUND_STRING("{B_SCR_ABILITY} {B_BUFF2} de {B_SCR_NAME_WITH_PREFIX} aumentou seu {B_BUFF1}!"),
    [STRINGID_RECEIVERABILITYTAKEOVER]              = COMPOUND_STRING("O {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} foi assumido!"),
    [STRINGID_PKNMABSORBINGPOWER]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está absorvendo poder!"),
    [STRINGID_NOONEWILLBEABLETORUNAWAY]             = COMPOUND_STRING("Ninguém poderá fugir durante o próximo turno!"),
    [STRINGID_DESTINYKNOTACTIVATES]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} se apaixonou por causa do {B_LAST_ITEM}!"),
    [STRINGID_CLOAKEDINAFREEZINGLIGHT]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ficou envolto em uma luz congelante!"),
    [STRINGID_CLEARAMULETWONTLOWERSTATS]            = COMPOUND_STRING("Os efeitos do {B_LAST_ITEM} detido por {B_SCR_NAME_WITH_PREFIX2} evitam que suas estatísticas sejam reduzidas!"),
    [STRINGID_FERVENTWISHREACHED]                   = COMPOUND_STRING("O desejo fervoroso de {B_ATK_TRAINER_NAME} alcançou {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_AIRLOCKACTIVATES]                     = COMPOUND_STRING("Os efeitos do tempo desapareceram."),
    [STRINGID_PRESSUREENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} está exercendo pressão!"),
    [STRINGID_DARKAURAENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} está irradiando uma aura sombria!"),
    [STRINGID_FAIRYAURAENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} está irradiando uma aura de fada!"),
    [STRINGID_AURABREAKENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} reverteu as auras de todos os outros Pokémon!"),
    [STRINGID_COMATOSEENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} está cochilando!"),
    [STRINGID_SCREENCLEANERENTERS]                  = COMPOUND_STRING("Todas as telas do campo foram limpas!"),
    [STRINGID_FETCHEDPOKEBALL]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} encontrou um {B_LAST_ITEM}!"),
    [STRINGID_ASANDSTORMKICKEDUP]                   = COMPOUND_STRING("Uma tempestade de areia começou!"),
    [STRINGID_PKMNSWILLPERISHIN3TURNS]              = COMPOUND_STRING("Ambos os Pokémon desmaiarão em três turnos!"),
    [STRINGID_AURAFLAREDTOLIFE]                     = COMPOUND_STRING("A aura de {B_ATK_NAME_WITH_PREFIX} ganhou vida!"),
    [STRINGID_ASONEENTERS]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} tem duas habilidades!"),
    [STRINGID_CURIOUSMEDICINEENTERS]                = COMPOUND_STRING("As alterações nas estatísticas de {B_EFF_NAME_WITH_PREFIX} foram removidas!"),
    [STRINGID_CANACTFASTERTHANKSTO]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} pode agir mais rápido que o normal, graças ao seu {B_BUFF1}!"),
    [STRINGID_MICLEBERRYACTIVATES]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} aumentou a precisão do seu próximo movimento usando {B_LAST_ITEM}!"),
    [STRINGID_PKMNSHOOKOFFTHETAUNT]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} se livrou da provocação!"),
    [STRINGID_PKMNGOTOVERITSINFATUATION]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} superou sua paixão!"),
    [STRINGID_ITEMCANNOTBEREMOVED]                  = COMPOUND_STRING("O item de {B_ATK_NAME_WITH_PREFIX} não pode ser removido!"),
    [STRINGID_STICKYBARBTRANSFER]                   = COMPOUND_STRING("O {B_LAST_ITEM} se uniu ao {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBURNHEALED]                       = COMPOUND_STRING("A queimadura de {B_DEF_NAME_WITH_PREFIX} foi curada!"),
    [STRINGID_REDCARDACTIVATE]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} mostrou seu Cartão Vermelho contra {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_EJECTBUTTONACTIVATE]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} foi trocado pelo {B_LAST_ITEM}!"),
    [STRINGID_ATKGOTOVERINFATUATION]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} curou seu status de paixão usando seu {B_LAST_ITEM}!"),
    [STRINGID_TORMENTEDNOMORE]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} não está mais atormentado!"),
    [STRINGID_HEALBLOCKEDNOMORE]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} não está mais impedido de curar!"),
    [STRINGID_ATTACKERBECAMEFULLYCHARGED]           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ficou totalmente carregado devido ao seu vínculo com seu treinador!\p"),
    [STRINGID_ATTACKERBECAMEASHSPECIES]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se tornou Ash-Greninja!\p"),
    [STRINGID_EXTREMELYHARSHSUNLIGHT]               = COMPOUND_STRING("A luz do sol ficou extremamente forte!"),
    [STRINGID_EXTREMESUNLIGHTFADED]                 = COMPOUND_STRING("A luz solar extremamente forte desapareceu!"),
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT]     = COMPOUND_STRING("O ataque do tipo Água evaporou sob a luz solar extremamente forte!"),
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED] = COMPOUND_STRING("A luz solar extremamente forte não diminuiu em nada!"),
    [STRINGID_HEAVYRAIN]                            = COMPOUND_STRING("Uma forte chuva começou a cair!"),
    [STRINGID_HEAVYRAINLIFTED]                      = COMPOUND_STRING("A forte chuva passou!"),
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN]         = COMPOUND_STRING("O ataque do tipo Fogo fracassou na chuva forte!"),
    [STRINGID_NORELIEFROMHEAVYRAIN]                 = COMPOUND_STRING("Não há alívio para esta chuva forte!"),
    [STRINGID_MYSTERIOUSAIRCURRENT]                 = COMPOUND_STRING("Ventos fortes e misteriosos estão protegendo Pokémon do tipo Voador!"),
    [STRINGID_STRONGWINDSDISSIPATED]                = COMPOUND_STRING("Os misteriosos ventos fortes se dissiparam!"),
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON]          = COMPOUND_STRING("Os misteriosos ventos fortes sopram de qualquer maneira!"),
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS]           = COMPOUND_STRING("Os misteriosos ventos fortes enfraqueceram o ataque!"),
    [STRINGID_STUFFCHEEKSCANTSELECT]                = COMPOUND_STRING("Ele não pode usar o movimento porque não tem uma Berry!\p"),
    [STRINGID_PKMNREVERTEDTOPRIMAL]                 = COMPOUND_STRING("Reversão Primordial de {B_SCR_NAME_WITH_PREFIX}! Ele voltou ao seu estado original!"),
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE]             = COMPOUND_STRING("Mas {B_ATK_NAME_WITH_PREFIX2} não pode usar o movimento!"),
    [STRINGID_BUTHOOPACANTUSEIT]                    = COMPOUND_STRING("Mas {B_ATK_NAME_WITH_PREFIX2} não pode usá-lo do jeito que está agora!"),
    [STRINGID_BROKETHROUGHPROTECTION]               = COMPOUND_STRING("Rompeu a proteção de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ABILITYALLOWSONLYMOVE]                = COMPOUND_STRING("{B_ATK_ABILITY} permite apenas o uso de {B_CURRENT_MOVE}!\p"),
    [STRINGID_SWAPPEDABILITIES]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} trocou Habilidades com seu alvo!"),
    [STRINGID_PKMNHEALEDPOISON]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} foi curado do envenenamento!"),
    [STRINGID_BATTLERTYPECHANGEDTO]                 = COMPOUND_STRING("O tipo de {B_SCR_NAME_WITH_PREFIX} foi alterado para {B_BUFF1}!"),
    [STRINGID_BOTHCANNOLONGERESCAPE]                = COMPOUND_STRING("Nenhum dos Pokémon pode fugir!"),
    [STRINGID_CANTESCAPEDUETOUSEDMOVE]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} não pode mais escapar porque usou No Retreat!"),
    [STRINGID_PKMNBECAMEWEAKERTOFIRE]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ficou mais fraco para disparar!"),
    [STRINGID_ABOUTTOUSEPOLTERGEIST]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} está prestes a ser atacado por seu {B_LAST_ITEM}!"),
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE]       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} não pode mais escapar por causa do Octolock!"),
    [STRINGID_NEUTRALIZINGGASENTERS]                = COMPOUND_STRING("Gás neutralizante encheu a área!"),
    [STRINGID_NEUTRALIZINGGASOVER]                  = COMPOUND_STRING("Os efeitos do gás neutralizante passaram!"),
    [STRINGID_TARGETTOOHEAVY]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} é muito pesado para ser levantado!"),
    [STRINGID_PKMNTOOKTARGETHIGH]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} levou {B_DEF_NAME_WITH_PREFIX2} para o céu!"),
    [STRINGID_PKMNINSNAPTRAP]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} foi preso por uma armadilha instantânea!"),
    [STRINGID_METEORBEAMCHARGING]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está transbordando de poder espacial!"),
    [STRINGID_HEATUPBEAK]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} começou a aquecer o bico!"),
    [STRINGID_COURTCHANGE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} trocou os efeitos de batalha que afetam cada lado do campo!"),
    [STRINGID_ZPOWERSURROUNDS]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cercou-se de seu Z-Power!"),
    [STRINGID_ZMOVEUNLEASHED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} libera seu Z-Move com força total!"),
    [STRINGID_ZMOVERESETSSTATS]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} retornou suas estatísticas reduzidas ao normal usando seu Z-Power!"),
    [STRINGID_ZMOVEALLSTATSUP]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} aumentou suas estatísticas usando seu Z-Power!"),
    [STRINGID_ZMOVEZBOOSTCRIT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} aumentou sua taxa de acerto crítico usando seu Z-Power!"),
    [STRINGID_ZMOVERESTOREHP]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} restaurou seu HP usando seu Z-Power!"),
    [STRINGID_ZMOVESTATUP]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} aumentou suas estatísticas usando seu Z-Power!"),
    [STRINGID_ZMOVEHPTRAP]                          = COMPOUND_STRING("O HP de {B_SCR_NAME_WITH_PREFIX} foi restaurado pelo Z-Power!"),
    [STRINGID_ATTACKEREXPELLEDTHEPOISON]            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} conseguiu expelir o veneno para você não se preocupar!"),
    [STRINGID_ATTACKERSHOOKITSELFAWAKE]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} acordou sacudido para que você não se preocupasse!"),
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} reuniu toda a sua energia para romper a paralisia, para que você não se preocupasse!"),
    [STRINGID_ATTACKERHEALEDITSBURN]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} curou sua queimadura por pura determinação, então você não se preocuparia!"),
    [STRINGID_ATTACKERMELTEDTHEICE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} derreteu o gelo com sua determinação ardente para que você não se preocupe!"),
    [STRINGID_TARGETTOUGHEDITOUT]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} resistiu para que você não se sentisse triste!"),
    [STRINGID_ATTACKERLOSTELECTRICTYPE]             = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} consumiu toda a sua eletricidade!"),
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET]       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} trocou {B_BUFF1} com seu alvo!"),
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER]         = COMPOUND_STRING("Ser atingido por {B_CURRENT_MOVE} carregou {B_EFF_NAME_WITH_PREFIX2} de poder!"),
    [STRINGID_SUNLIGHTACTIVATEDABILITY]             = COMPOUND_STRING("A forte luz solar ativou a protossíntese de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_STATWASHEIGHTENED]                    = COMPOUND_STRING("O {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} foi aumentado!"),
    [STRINGID_ELECTRICTERRAINACTIVATEDABILITY]      = COMPOUND_STRING("O Electric Terrain ativou o Quark Drive do {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_ABILITYWEAKENEDSURROUNDINGMONSSTAT]   = COMPOUND_STRING("O {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} enfraqueceu o {B_BUFF1} de todos os Pokémon ao redor!\p"),
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN]  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} ganhou força com os caídos!"),
    [STRINGID_PKMNSABILITYPREVENTSABILITY]          = COMPOUND_STRING("O {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} impede que o {B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2} funcione!"), //not in gen 5+, ability popup
    [STRINGID_PREPARESHELLTRAP]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} armou uma armadilha!"),
    [STRINGID_SHELLTRAPDIDNTWORK]                   = COMPOUND_STRING("A armadilha de shell do {B_ATK_NAME_WITH_PREFIX} não funcionou!"),
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM]            = COMPOUND_STRING("Os espinhos desapareceram do chão ao redor da equipe {B_ATK_TEAM2}!"),
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("Os espinhos de veneno desapareceram do chão ao redor da equipe {B_ATK_TEAM2}!"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM]         = COMPOUND_STRING("A teia pegajosa desapareceu do chão ao redor da equipe {B_ATK_TEAM2}!"),
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("As pedras pontiagudas desapareceram da equipe {B_ATK_TEAM2}!"),
    [STRINGID_COULDNTFULLYPROTECT]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} não conseguiu se proteger totalmente e se machucou!"),
    [STRINGID_STOCKPILEDEFFECTWOREOFF]              = COMPOUND_STRING("O efeito acumulado de {B_ATK_NAME_WITH_PREFIX} passou!"),
    [STRINGID_PKMNREVIVEDREADYTOFIGHT]              = COMPOUND_STRING("{B_BUFF1} foi revivido e está pronto para lutar novamente!"),
    [STRINGID_ITEMRESTOREDSPECIESHEALTH]            = COMPOUND_STRING("{B_BUFF1} teve seu HP restaurado."),
    [STRINGID_ITEMCUREDSPECIESSTATUS]               = COMPOUND_STRING("{B_BUFF1} teve seu status curado!"), // Not in Gen 5+
    [STRINGID_ITEMRESTOREDSPECIESPP]                = COMPOUND_STRING("O PP do {B_BUFF1} de {B_BUFF2} foi restaurado!"),
    [STRINGID_THUNDERCAGETRAPPED]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} preso {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBYFROSTBITE]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi ferido pelo congelamento!"),
    [STRINGID_PKMNGOTFROSTBITE]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} sofreu congelamento!"),
    [STRINGID_PKMNSITEMHEALEDFROSTBITE]             = COMPOUND_STRING("O {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} curou seu congelamento!"),
    [STRINGID_ATTACKERHEALEDITSFROSTBITE]           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} curou seu congelamento através de pura determinação, então você não se preocuparia!"),
    [STRINGID_PKMNFROSTBITEHEALED]                  = COMPOUND_STRING("O congelamento de {B_SCR_NAME_WITH_PREFIX} foi curado!"),
    [STRINGID_PKMNFROSTBITEHEALEDBY]                = COMPOUND_STRING("O {B_CURRENT_MOVE} de {B_SCR_NAME_WITH_PREFIX} curou seu congelamento!"),
    [STRINGID_MIRRORHERBCOPIED]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} usou sua Mirror Herb para espelhar as mudanças de estatísticas de seu oponente!"),
    [STRINGID_STARTEDSNOW]                          = COMPOUND_STRING("Começou a nevar!"),
    [STRINGID_SNOWCONTINUES]                        = COMPOUND_STRING("A neve continua a cair."), //not in gen 5+ (lol)
    [STRINGID_SNOWSTOPPED]                          = COMPOUND_STRING("A neve parou."),
    [STRINGID_SNOWWARNINGSNOW]                      = COMPOUND_STRING("Começou a nevar!"),
    [STRINGID_PKMNITEMMELTED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} corroeu {B_DEF_NAME_WITH_PREFIX2} de {B_LAST_ITEM}!"),
    [STRINGID_ULTRABURSTREACTING]                   = COMPOUND_STRING("Uma luz brilhante está prestes a explodir de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ULTRABURSTCOMPLETED]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} recuperou seu verdadeiro poder através do Ultra Burst!"),
    [STRINGID_TEAMGAINEDEXP]                        = COMPOUND_STRING("O resto da sua equipe ganhou Exp. Pontos graças ao Exp. Compartilhe!\p"),
    [STRINGID_CURRENTMOVECANTSELECT]                = COMPOUND_STRING("{B_BUFF1} não pode ser usado!\p"),
    [STRINGID_TARGETISBEINGSALTCURED]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} está sendo curado com sal!"),
    [STRINGID_TARGETISHURTBYSALTCURE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} é ferido por {B_BUFF1}!"),
    [STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP]      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} ficou coberto de calda de doce pegajosa!"),
    [STRINGID_SHARPSTEELFLOATS]                     = COMPOUND_STRING("Pedaços de aço pontiagudos começaram a flutuar ao redor do Pokémon {B_DEF_TEAM2}!"),
    [STRINGID_SHARPSTEELDMG]                        = COMPOUND_STRING("O aço afiado atingiu {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBLEWAWAYSHARPSTEEL]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} explodiu o aço afiado!"),
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM]        = COMPOUND_STRING("Os pedaços de aço que cercavam o Pokémon {B_ATK_TEAM2} desapareceram!"),
    [STRINGID_TEAMTRAPPEDWITHVINES]                 = COMPOUND_STRING("Pokémon {B_EFF_TEAM1} ficaram presos em vinhas!"),
    [STRINGID_PKMNHURTBYVINES]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} é ferido pela surra feroz de G-Max Vine Lash!"),
    [STRINGID_TEAMCAUGHTINVORTEX]                   = COMPOUND_STRING("O Pokémon {B_EFF_TEAM1} foi pego em um vórtice de água!"),
    [STRINGID_PKMNHURTBYVORTEX]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} é ferido pelo vórtice do G-Max Cannonade!"),
    [STRINGID_TEAMSURROUNDEDBYFIRE]                 = COMPOUND_STRING("Pokémon {B_EFF_TEAM1} foram cercados por fogo!"),
    [STRINGID_PKMNBURNINGUP]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está queimando nas chamas do G-Max Wildfire!"),
    [STRINGID_TEAMSURROUNDEDBYROCKS]                = COMPOUND_STRING("O Pokémon {B_EFF_TEAM1} ficou cercado por pedras!"),
    [STRINGID_PKMNHURTBYROCKSTHROWN]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} é ferido por pedras lançadas por G-Max Volcalith!"),
    [STRINGID_MOVEBLOCKEDBYDYNAMAX]                 = COMPOUND_STRING("O movimento foi bloqueado pelo poder do Dynamax!"),
    [STRINGID_ZEROTOHEROTRANSFORMATION]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} passou por uma transformação heróica!"),
    [STRINGID_THETWOMOVESBECOMEONE]                 = COMPOUND_STRING("Os dois movimentos se tornaram um! É um movimento combinado!{PAUSE 16}"),
    [STRINGID_ARAINBOWAPPEAREDONSIDE]               = COMPOUND_STRING("Um arco-íris apareceu no céu do lado da equipe {B_ATK_TEAM2}!"),
    [STRINGID_THERAINBOWDISAPPEARED]                = COMPOUND_STRING("O arco-íris do lado da equipe {B_ATK_TEAM2} desapareceu!"),
    [STRINGID_WAITINGFORPARTNERSMOVE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está aguardando o movimento de {B_ATK_PARTNER_NAME}…{PAUSE 16}"),
    [STRINGID_SEAOFFIREENVELOPEDSIDE]               = COMPOUND_STRING("Um mar de fogo envolveu a equipe {B_DEF_TEAM2}!"),
    [STRINGID_HURTBYTHESEAOFFIRE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} foi ferido pelo mar de fogo!"),
    [STRINGID_THESEAOFFIREDISAPPEARED]              = COMPOUND_STRING("O mar de fogo ao redor da equipe {B_ATK_TEAM2} desapareceu!"),
    [STRINGID_SWAMPENVELOPEDSIDE]                   = COMPOUND_STRING("Um pântano envolveu a equipe {B_EFF_TEAM2}!"),
    [STRINGID_THESWAMPDISAPPEARED]                  = COMPOUND_STRING("O pântano ao redor da equipe {B_ATK_TEAM2} desapareceu!"),
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está se preparando para contar uma piada assustadoramente ruim!"),
    [STRINGID_HOSPITALITYRESTORATION]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} bebeu todo o matcha que {B_SCR_NAME_WITH_PREFIX2} fez!"),
    [STRINGID_ELECTROSHOTCHARGING]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorveu eletricidade!"),
    [STRINGID_ITEMWASUSEDUP]                        = COMPOUND_STRING("O {B_LAST_ITEM} foi usado…"),
    [STRINGID_ATTACKERLOSTITSTYPE]                  = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} perdeu seu tipo {B_BUFF1}!"),
    [STRINGID_SHEDITSTAIL]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} largou o rabo para criar uma isca!"),
    [STRINGID_CLOAKEDINAHARSHLIGHT]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ficou envolto em uma luz forte!"),
    [STRINGID_SUPERSWEETAROMAWAFTS]                 = COMPOUND_STRING("Um aroma superdoce emana da calda que cobre {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_DIMENSIONSWERETWISTED]                = COMPOUND_STRING("As dimensões foram distorcidas!"),
    [STRINGID_BIZARREARENACREATED]                  = COMPOUND_STRING("Foi criada uma área bizarra onde os itens retidos pelos Pokémon perdem seus efeitos!"),
    [STRINGID_BIZARREAREACREATED]                   = COMPOUND_STRING("Foi criada uma área bizarra na qual Defesa e Sp. As estatísticas de Def foram trocadas!"),
    [STRINGID_TIDYINGUPCOMPLETE]                    = COMPOUND_STRING("Arrumação completa!"),
    [STRINGID_PKMNTERASTALLIZEDINTO]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} terastalizado no tipo {B_BUFF1}!"), // Does not exist, meant to mimic form change strings
    [STRINGID_BOOSTERENERGYACTIVATES]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} usou seu {B_LAST_ITEM} para ativar {B_SCR_ABILITY}!"),
    [STRINGID_FOGCREPTUP]                           = COMPOUND_STRING("A névoa subiu tão espessa quanto uma sopa!"),
    [STRINGID_FOGISDEEP]                            = COMPOUND_STRING("A neblina é profunda…"),
    [STRINGID_FOGLIFTED]                            = COMPOUND_STRING("A névoa se dissipou."),
    [STRINGID_PKMNMADESHELLGLEAM]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fez sua concha brilhar! Está distorcendo os tipos de confrontos!"),
    [STRINGID_FICKLEBEAMDOUBLED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está dando tudo de si neste ataque!"),
    [STRINGID_COMMANDERACTIVATES]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} foi engolido por {B_BUFF1} e se tornou o comandante de {B_BUFF1}!"),
    [STRINGID_POKEFLUTECATCHY]                      = COMPOUND_STRING("{B_PLAYER_NAME} tocou {B_LAST_ITEM}.\pAgora, essa é uma música cativante!"),
    [STRINGID_POKEFLUTE]                            = COMPOUND_STRING("{B_PLAYER_NAME} jogou o {B_LAST_ITEM}."),
    [STRINGID_MONHEARINGFLUTEAWOKE]                 = COMPOUND_STRING("O Pokémon ouvindo a flauta acordou!"),
    [STRINGID_SUNLIGHTISHARSH]                      = COMPOUND_STRING("A luz do sol é forte!"),
    [STRINGID_ITISHAILING]                          = COMPOUND_STRING("Está saudando!"),
    [STRINGID_ITISSNOWING]                          = COMPOUND_STRING("Está nevando!"),
    [STRINGID_ISCOVEREDWITHGRASS]                   = COMPOUND_STRING("O campo de batalha está coberto de grama!"),
    [STRINGID_MISTSWIRLSAROUND]                     = COMPOUND_STRING("A névoa gira em torno do campo de batalha!"),
    [STRINGID_ELECTRICCURRENTISRUNNING]             = COMPOUND_STRING("Uma corrente elétrica atravessa o campo de batalha!"),
    [STRINGID_SEEMSWEIRD]                           = COMPOUND_STRING("O campo de batalha parece estranho!"),
    [STRINGID_WAGGLINGAFINGER]                      = COMPOUND_STRING("Balançando um dedo, deixe-o usar {B_CURRENT_MOVE}!"),
    [STRINGID_BLOCKEDBYSLEEPCLAUSE]                 = COMPOUND_STRING("A cláusula de sono manteve {B_DEF_NAME_WITH_PREFIX2} acordado!"),
    [STRINGID_SUPEREFFECTIVETWOFOES]                = COMPOUND_STRING("É supereficaz em {B_DEF_NAME_WITH_PREFIX2} e {B_DEF_PARTNER_NAME}!"),
    [STRINGID_NOTVERYEFFECTIVETWOFOES]              = COMPOUND_STRING("Não é muito eficaz em {B_DEF_NAME_WITH_PREFIX2} e {B_DEF_PARTNER_NAME}!"),
    [STRINGID_SENDCAUGHTMONPARTYORBOX]              = COMPOUND_STRING("Adicionar {B_DEF_NAME} à sua festa?"),
    [STRINGID_PKMNSENTTOPCAFTERCATCH]               = gText_PkmnSentToPCAfterCatch,
    [STRINGID_PKMNDYNAMAXED]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cresceu enormemente em sua forma Dynamax!"),
    [STRINGID_PKMNGIGANTAMAXED]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} cresceu enormemente em sua forma Gigantamax!"),
    [STRINGID_TIMETODYNAMAX]                        = COMPOUND_STRING("É hora de Dynamax!"),
    [STRINGID_TIMETOGIGANTAMAX]                     = COMPOUND_STRING("É hora do Gigantamax!"),
    [STRINGID_QUESTIONFORFEITBATTLE]                = COMPOUND_STRING("Você gostaria de desistir dessa batalha e desistir agora? Desistir da batalha é o mesmo que perdê-la."),
    [STRINGID_POWERCONSTRUCTPRESENCEOFMANY]         = COMPOUND_STRING("Você sente a presença de muitos!"),
    [STRINGID_POWERCONSTRUCTTRANSFORM]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformado em sua Forma Completa!"),
    [STRINGID_ABILITYSHIELDPROTECTS]                = COMPOUND_STRING("A habilidade de {B_ATK_NAME_WITH_PREFIX} é protegida pelos efeitos de seu {B_LAST_ITEM}!"),
    [STRINGID_MONTOOSCAREDTOMOVE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está com muito medo de se mover!"),
    [STRINGID_GHOSTGETOUTGETOUT]                    = COMPOUND_STRING("FANTASMA: Saia...... Saia......"),
    [STRINGID_SILPHSCOPEUNVEILED]                   = COMPOUND_STRING("SILPH SCOPE revelou a identidade \n do GHOST!"),
    [STRINGID_GHOSTWASMAROWAK]                      = COMPOUND_STRING("O FANTASMA era MAROWAK!\p"),
    [STRINGID_TRAINER1MON1COMEBACK]                 = COMPOUND_STRING("{B_TRAINER1_NAME}: {B_OPPONENT_MON1_NAME}, volte!"),
    [STRINGID_THREWROCK]                            = COMPOUND_STRING("{B_PLAYER_NAME} lançou um ROCK\n no {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_THREWBAIT]                            = COMPOUND_STRING("{B_PLAYER_NAME} jogou BAIT\n no {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_PKMNANGRY]                            = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} está com raiva!"),
    [STRINGID_PKMNEATING]                           = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} está comendo!"),
    [STRINGID_PKMNDISGUISEWASBUSTED]                = COMPOUND_STRING("O disfarce de {B_SCR_NAME_WITH_PREFIX} foi descoberto!"),
    [STRINGID_ZENMODETRIGGERED]                     = COMPOUND_STRING("{B_SCR_ABILITY} acionado!"),
    [STRINGID_ZENMODEENDED]                         = COMPOUND_STRING("{B_SCR_ABILITY} terminou!"),
    [STRINGID_SCRCUREDPARALYSIS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} foi curado da paralisia!"),
    [STRINGID_SCRCUREDPOISON]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} foi curado do envenenamento!"),
    [STRINGID_SCRCUREDBURN]                         = COMPOUND_STRING("A queimadura de {B_SCR_NAME_WITH_PREFIX} foi curada!"),
    [STRINGID_SCRCUREDSLEEP]                        = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} acordou!"),
    [STRINGID_SCRCUREDCONFUSION]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} saiu de sua confusão!"),
    [STRINGID_PARTYCUREDPARALYSIS]                  = COMPOUND_STRING("{B_BUFF1} foi curado da paralisia!"),
    [STRINGID_PARTYCUREDPOISON]                     = COMPOUND_STRING("{B_BUFF1} foi curado do envenenamento!"),
    [STRINGID_PARTYCUREDBURN]                       = COMPOUND_STRING("A queimadura de {B_BUFF1} foi curada!"),
    [STRINGID_PARTYCUREDSLEEP]                      = COMPOUND_STRING("{B_BUFF1} acordou!"),
    [STRINGID_PARTYCUREDFREEZE]                     = COMPOUND_STRING("{B_BUFF1} descongelou!"),
    [STRINGID_PARTYCUREDFROSTBITE]                  = COMPOUND_STRING("O congelamento de {B_BUFF1} foi curado!"),
    [STRINGID_PKMNATKNOTLOWERED]                    = COMPOUND_STRING("O ataque de {B_SCR_NAME_WITH_PREFIX} não foi reduzido!"),
    [STRINGID_REFLECTWOREOFF]                       = COMPOUND_STRING("O Reflect da equipe {B_DEF_TEAM1} passou!"),
    [STRINGID_LIGHTSCREENWOREOFF]                   = COMPOUND_STRING("A tela de luz da equipe {B_DEF_TEAM1} passou!"),
    [STRINGID_AURORAVEILWOREOFF]                    = COMPOUND_STRING("O Aurora Veil da equipe {B_DEF_TEAM1} passou!"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMYOU]          = COMPOUND_STRING("A teia pegajosa desapareceu do chão ao seu redor!"),
};

const u8 *const gBattleStringsTableEs[STRINGID_COUNT] =
{
    [STRINGID_TRAINER1LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER1_LOSE_TEXT}"),
    [STRINGID_PKMNGAINEDEXP]                        = COMPOUND_STRING("¡{B_BUFF1} ganó{B_BUFF2} {B_BUFF3} puntos de Exp.!\p"),
    [STRINGID_PKMNGREWTOLV]                         = COMPOUND_STRING("¡{B_BUFF1} subió al Nv. {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_PKMNLEARNEDMOVE]                      = COMPOUND_STRING("¡{B_BUFF1} aprendió {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_TRYTOLEARNMOVE1]                      = COMPOUND_STRING("{B_BUFF1} quiere aprender el movimiento {B_BUFF2}.\p"),
    [STRINGID_TRYTOLEARNMOVE2]                      = COMPOUND_STRING("Pero {B_BUFF1} ya conoce cuatro movimientos.\p"),
    [STRINGID_TRYTOLEARNMOVE3]                      = COMPOUND_STRING("¿Olvidar otro movimiento para aprender {B_BUFF2}?"),
    [STRINGID_PKMNFORGOTMOVE]                       = COMPOUND_STRING("{B_BUFF1} olvidó {B_BUFF2}…\p"),
    [STRINGID_STOPLEARNINGMOVE]                     = COMPOUND_STRING("{PAUSE 32}¿Quieres dejar de enseñar {B_BUFF2} a {B_BUFF1}?"),
    [STRINGID_DIDNOTLEARNMOVE]                      = COMPOUND_STRING("{B_BUFF1} no aprendió {B_BUFF2}.\p"),
    [STRINGID_PKMNLEARNEDMOVE2]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} aprendió {B_BUFF1}!"),
    [STRINGID_PKMNPROTECTEDITSELF]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se protegió!"),
    [STRINGID_ITDOESNTAFFECT]                       = COMPOUND_STRING("No afecta a {B_DEF_NAME_WITH_PREFIX2}…"),
    [STRINGID_ITDOESNTAFFECTSCR]                    = COMPOUND_STRING("No afecta a {B_SCR_NAME_WITH_PREFIX2}…"),
    [STRINGID_BATTLERFAINTED]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se debilitó!\p"),
    [STRINGID_PLAYERGOTMONEY]                       = COMPOUND_STRING("¡Recibiste ¥{B_BUFF1} por ganar!\p"),
    [STRINGID_PLAYERWHITEOUT]                       = COMPOUND_STRING("¡No te quedan Pokémon que puedan luchar!\p"),
    [STRINGID_PLAYERWHITEOUT2_WILD]                 = COMPOUND_STRING("Entraste en pánico y soltaste ¥{B_BUFF1}…"),
    [STRINGID_PLAYERWHITEOUT2_TRAINER]              = COMPOUND_STRING("Entregaste ¥{B_BUFF1} al ganador…"),
    [STRINGID_PLAYERWHITEOUT3]                      = COMPOUND_STRING("¡La derrota te abrumó!"),
    [STRINGID_PREVENTSESCAPE]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} impide huir con {B_SCR_ABILITY}!\p"),
    [STRINGID_HITXTIMES]                            = COMPOUND_STRING("¡El Pokémon fue golpeado {B_BUFF1} vez/veces!"), //SV has dynamic plural here
    [STRINGID_PKMNFELLASLEEP]                       = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se durmió!"),
    [STRINGID_PKMNMADESLEEP]                        = COMPOUND_STRING("¡El {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} hizo dormir a {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYASLEEP]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya está dormido!"),
    [STRINGID_PKMNALREADYASLEEP2]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ya está dormido!"),
    [STRINGID_PKMNWASPOISONED]                      = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} fue envenenado!"),
    [STRINGID_PKMNPOISONEDBY]                       = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} fue envenenado por {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYPOISON]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} sufrió daño por el veneno!"),
    [STRINGID_PKMNALREADYPOISONED]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya está envenenado!"),
    [STRINGID_PKMNBADLYPOISONED]                    = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} fue gravemente envenenado!"),
    [STRINGID_PKMNENERGYDRAINED]                    = COMPOUND_STRING("¡La energía de {B_DEF_NAME_WITH_PREFIX} fue drenada!"),
    [STRINGID_PKMNWASBURNED]                        = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} sufrió una quemadura!"),
    [STRINGID_PKMNBURNEDBY]                         = COMPOUND_STRING("¡{B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} quemó {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYBURN]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} sufrió daño por la quemadura!"),
    [STRINGID_PKMNWASFROZEN]                        = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} quedó congelado!"),
    [STRINGID_PKMNFROZENBY]                         = COMPOUND_STRING("¡El {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} congeló a {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISFROZEN]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está congelado!"),
    [STRINGID_PKMNWASDEFROSTED]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se descongeló!"),
    [STRINGID_PKMNWASDEFROSTEDBY]                   = COMPOUND_STRING("¡El {B_CURRENT_MOVE} de {B_SCR_NAME_WITH_PREFIX} derritió el hielo!"),
    [STRINGID_PKMNWASPARALYZED]                     = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} está paralizado y quizá no pueda moverse!"),
    [STRINGID_PKMNWASPARALYZEDBY]                   = COMPOUND_STRING("¡El {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} paralizó a {B_EFF_NAME_WITH_PREFIX2}, por lo que es posible que no pueda moverse!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISPARALYZED]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no pudo moverse por estar paralizado!"),
    [STRINGID_PKMNISALREADYPARALYZED]               = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya está paralizado!"),
    [STRINGID_PKMNHEALEDPARALYSIS]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se curó de la parálisis!"),
    [STRINGID_STATSWONTINCREASE]                    = COMPOUND_STRING("¡El {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} no llegará más alto!"),
    [STRINGID_STATSWONTDECREASE]                    = COMPOUND_STRING("¡El {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} no bajará más!"),
    [STRINGID_PKMNISCONFUSED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está confundido!"),
    [STRINGID_PKMNHEALEDCONFUSION]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} salió de su confusión!"),
    [STRINGID_PKMNWASCONFUSED]                      = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} quedó confundido!"),
    [STRINGID_PKMNALREADYCONFUSED]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya está confundido!"),
    [STRINGID_PKMNFELLINLOVE]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se enamoró!"),
    [STRINGID_PKMNINLOVE]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está enamorado de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNIMMOBILIZEDBYLOVE]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está inmovilizado por amor!"),
    [STRINGID_PKMNCHANGEDTYPE]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} transformado en el tipo {B_BUFF1}!"),
    [STRINGID_PKMNFLINCHED]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} retrocedió y no pudo moverse!"),
    [STRINGID_PKMNREGAINEDHEALTH]                   = COMPOUND_STRING("Los PS de {B_DEF_NAME_WITH_PREFIX} fueron restaurados."),
    [STRINGID_PKMNHPFULL]                           = COMPOUND_STRING("¡Los PS de {B_DEF_NAME_WITH_PREFIX} están al máximo!"),
    [STRINGID_PKMNRAISEDSPDEF]                      = COMPOUND_STRING("¡Light Screen fortaleció al equipo {B_ATK_TEAM2} contra movimientos especiales!"),
    [STRINGID_PKMNRAISEDDEF]                        = COMPOUND_STRING("¡Reflect hizo que el equipo {B_ATK_TEAM2} fuera más fuerte contra los movimientos físicos!"),
    [STRINGID_PKMNAURORAVEIL]                       = COMPOUND_STRING("¡Aurora Veil fortaleció al equipo {B_ATK_TEAM2} contra movimientos físicos y especiales!"),
    [STRINGID_PKMNCOVEREDBYVEIL]                    = COMPOUND_STRING("¡El equipo {B_ATK_TEAM1} se cubrió con un velo místico!"),
    [STRINGID_PKMNUSEDSAFEGUARD]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} está protegido por Safeguard!"),
    [STRINGID_PKMNSAFEGUARDEXPIRED]                 = COMPOUND_STRING("¡El equipo {B_ATK_TEAM1} ya no está protegido por Safeguard!"),
    [STRINGID_PKMNWENTTOSLEEP]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se fue a dormir!"), //not in gen 5+
    [STRINGID_PKMNSLEPTHEALTHY]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} durmió y restauró sus PS!"),
    [STRINGID_PKMNWHIPPEDWHIRLWIND]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} provocó un torbellino!"),
    [STRINGID_PKMNTOOKSUNLIGHT]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} absorbió la luz!"),
    [STRINGID_PKMNLOWEREDHEAD]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} metido en la cabeza!"),
    [STRINGID_PKMNFLEWHIGH]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} voló alto!"),
    [STRINGID_PKMNDUGHOLE]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se abrió camino bajo tierra!"),
    [STRINGID_PKMNSQUEEZEDBYBIND]                   = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} fue exprimido por {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNTRAPPEDINVORTEX]                  = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} quedó atrapado en el vórtice!"),
    [STRINGID_PKMNWRAPPEDBY]                        = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} fue envuelto por {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCLAMPED]                          = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} tomó medidas drásticas contra {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBY]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está herido por {B_BUFF1}!"),
    [STRINGID_PKMNFREEDFROM]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} fue liberado de {B_BUFF1}!"),
    [STRINGID_PKMNCRASHED]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} siguió adelante y se estrelló!"),
    [STRINGID_PKMNSHROUDEDINMIST]                   = sText_PkmnShroudedInMistEs,
    [STRINGID_PKMNPROTECTEDBYMIST]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} está protegido por la niebla!"),
    [STRINGID_PKMNGETTINGPUMPED]                    = sText_PkmnGettingPumpedEs,
    [STRINGID_PKMNHITWITHRECOIL]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} resultó dañado por el retroceso!"),
    [STRINGID_PKMNPROTECTEDITSELF2]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se protegió!"),
    [STRINGID_PKMNBUFFETEDBYSANDSTORM]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} es azotado por la tormenta de arena!"),
    [STRINGID_PKMNPELTEDBYHAIL]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} es azotado por el granizo!"),
    [STRINGID_PKMNSEEDED]                           = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} fue sembrado!"),
    [STRINGID_PKMNAVOIDEDATTACK]                    = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} evitó el ataque!"),
    [STRINGID_BATTLERAVOIDEDATTACK]                 = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} evitó el ataque!"),
    [STRINGID_PKMNSAPPEDBYLEECHSEED]                = COMPOUND_STRING("¡La salud de {B_ATK_NAME_WITH_PREFIX} se ve debilitada por Leech Seed!"),
    [STRINGID_PKMNFASTASLEEP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está profundamente dormido."),
    [STRINGID_PKMNWOKEUP]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} despertó!"),
    [STRINGID_PKMNWOKEUPINUPROAR]                   = COMPOUND_STRING("¡El alboroto despertó a {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCAUSEDUPROAR]                     = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} causó revuelo!"),
    [STRINGID_PKMNMAKINGUPROAR]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está causando un gran revuelo!"),
    [STRINGID_PKMNCALMEDDOWN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} se calmó."),
    [STRINGID_PKMNSTOCKPILED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} almacenado {B_BUFF1}!"),
    [STRINGID_PKMNCANTSLEEPINUPROAR2]               = COMPOUND_STRING("¡Pero {B_DEF_NAME_WITH_PREFIX2} no puede dormir en medio del alboroto!"),
    [STRINGID_UPROARKEPTPKMNAWAKE]                  = COMPOUND_STRING("¡Pero el alboroto mantuvo despierto a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSTAYEDAWAKEUSING]                 = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se quedó despierto!"),
    [STRINGID_PKMNSTORINGENERGY]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está almacenando energía!"),
    [STRINGID_PKMNUNLEASHEDENERGY]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} desató su energía!"),
    [STRINGID_PKMNFATIGUECONFUSION]                 = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se confundió debido a la fatiga!"),
    [STRINGID_PLAYERPICKEDUPMONEY]                  = COMPOUND_STRING("Recogiste ¥{B_BUFF1}!\p"),
    [STRINGID_PKMNUNAFFECTED]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} no se ve afectado!"),
    [STRINGID_PKMNTRANSFORMEDINTO]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} transformado en {B_BUFF1}!"),
    [STRINGID_PKMNMADESUBSTITUTE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} puso un sustituto!"),
    [STRINGID_PKMNHASSUBSTITUTE]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ya tiene sustituto!"),
    [STRINGID_SUBSTITUTEDAMAGED]                    = COMPOUND_STRING("El sustituto sufrió daños por {B_DEF_NAME_WITH_PREFIX2}!\p"),
    [STRINGID_PKMNSUBSTITUTEFADED]                  = COMPOUND_STRING("¡El sustituto de {B_SCR_NAME_WITH_PREFIX} se desvaneció!\p"),
    [STRINGID_PKMNMUSTRECHARGE]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} debe recargarse!"),
    [STRINGID_PKMNRAGEBUILDING]                     = COMPOUND_STRING("¡La ira de {B_DEF_NAME_WITH_PREFIX} está aumentando!"),
    [STRINGID_PKMNMOVEWASDISABLED]                  = COMPOUND_STRING("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX} fue deshabilitado!"),
    [STRINGID_PKMNMOVEISDISABLED]                   = COMPOUND_STRING("¡El {B_CURRENT_MOVE} de {B_ATK_NAME_WITH_PREFIX} está deshabilitado!\p"),
    [STRINGID_PKMNMOVEDISABLEDNOMORE]               = COMPOUND_STRING("¡El movimiento de {B_SCR_NAME_WITH_PREFIX} ya no está deshabilitado!"),
    [STRINGID_PKMNGOTENCORE]                        = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} debe hacer un bis!"),
    [STRINGID_PKMNGOTENCOREDMOVE]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} solo puede usar {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNENCOREENDED]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} terminó su bis!"),
    [STRINGID_PKMNTOOKAIM]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} apuntó a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSKETCHEDMOVE]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} esbozó {B_BUFF1}!"),
    [STRINGID_PKMNTRYINGTOTAKEFOE]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} espera derribar a su atacante con él!"),
    [STRINGID_PKMNTOOKFOE]                          = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} derribó a su atacante con él!"),
    [STRINGID_PKMNREDUCEDPP]                        = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} perdió {B_BUFF2} PP de {B_BUFF1}!"),
    [STRINGID_PKMNSTOLEITEM]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} robó el {B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_TARGETCANTESCAPENOW]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya no puede escapar!"),
    [STRINGID_PKMNFELLINTONIGHTMARE]                = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} comenzó a tener una pesadilla!"),
    [STRINGID_PKMNLOCKEDINNIGHTMARE]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está atrapado en una pesadilla!"),
    [STRINGID_PKMNLAIDCURSE]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} cortó su propio HP y puso una maldición sobre {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNAFFLICTEDBYCURSE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está afectado por la maldición!"),
    [STRINGID_SPIKESSCATTERED]                      = COMPOUND_STRING("¡Se esparcieron púas por el suelo alrededor del equipo {B_DEF_TEAM2}!"),
    [STRINGID_PKMNHURTBYSPIKES]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} resultó herido por los picos!"),
    [STRINGID_PKMNIDENTIFIED]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} fue identificado!"),
    [STRINGID_PKMNPERISHCOUNTFELL]                  = COMPOUND_STRING("¡El recuento de muertes de {B_ATK_NAME_WITH_PREFIX} cayó a {B_BUFF1}!"),
    [STRINGID_PKMNBRACEDITSELF]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se preparó!"),
    [STRINGID_PKMNENDUREDHIT]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} soportó el golpe!"),
    [STRINGID_MAGNITUDESTRENGTH]                    = COMPOUND_STRING("Magnitud {B_BUFF1}!"),
    [STRINGID_PKMNCUTHPMAXEDATTACK]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} cortó su propio HP y maximizó su ataque!"),
    [STRINGID_PKMNCOPIEDSTATCHANGES]                = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} copió los cambios de estadísticas de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNGOTFREE]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} fue liberado de {B_BUFF1}!"),
    [STRINGID_PKMNSHEDLEECHSEED]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} fue liberado de Leech Seed!"),
    [STRINGID_PKMNBLEWAWAYSPIKES]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} arrasó con Spikes!"), // Not in gen 5+
    [STRINGID_PKMNFLEDFROMBATTLE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} huyó de la batalla!"),
    [STRINGID_PKMNFORESAWATTACK]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} previó un ataque!"),
    [STRINGID_PKMNTOOKATTACK]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} recibió el ataque {B_BUFF1}!"),
    [STRINGID_PKMNATTACK]                           = COMPOUND_STRING("¡El ataque de {B_BUFF1}!"), // Not in gen 5+
    [STRINGID_PKMNCENTERATTENTION]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se convirtió en el centro de atención!"),
    [STRINGID_PKMNCHARGINGPOWER]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} comenzó a cargar energía!"),
    [STRINGID_NATUREPOWERTURNEDINTO]                = COMPOUND_STRING("¡El poder natural de {B_ATK_NAME_WITH_PREFIX} se convirtió en {B_CURRENT_MOVE}!"),
    [STRINGID_PKMNSTATUSNORMAL]                     = COMPOUND_STRING("¡El estado de {B_ATK_NAME_WITH_PREFIX} volvió a la normalidad!"),
    [STRINGID_PKMNHASNOMOVESLEFT]                   = COMPOUND_STRING("¡A {B_ATK_NAME_WITH_PREFIX} no le quedan movimientos que pueda usar!\p"),
    [STRINGID_PKMNSUBJECTEDTOTORMENT]               = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} fue sometido a tormento!"),
    [STRINGID_PKMNCANTUSEMOVETORMENT]               = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede usar el mismo movimiento dos veces seguidas debido al tormento!\p"),
    [STRINGID_PKMNTIGHTENINGFOCUS]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está reforzando su enfoque!"),
    [STRINGID_PKMNFELLFORTAUNT]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se enamoró de la burla!"),
    [STRINGID_PKMNCANTUSEMOVETAUNT]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede usar {B_CURRENT_MOVE} después de la burla!\p"),
    [STRINGID_PKMNREADYTOHELP]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está listo para ayudar a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSWITCHEDITEMS]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} cambió elementos con su objetivo!"),
    [STRINGID_PKMNCOPIEDFOE]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} copió la habilidad de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNWISHCAMETRUE]                     = COMPOUND_STRING("¡El deseo de {B_BUFF1} se hizo realidad!"),
    [STRINGID_PKMNPLANTEDROOTS]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} plantó sus raíces!"),
    [STRINGID_PKMNABSORBEDNUTRIENTS]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} absorbió nutrientes con sus raíces!"),
    [STRINGID_PKMNANCHOREDITSELF]                   = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} está anclado en su lugar con sus raíces!"),
    [STRINGID_PKMNWASMADEDROWSY]                    = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se adormeció!"),
    [STRINGID_PKMNKNOCKEDOFF]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} derrotó a {B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNSWAPPEDABILITIES]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} intercambió habilidades con su objetivo!"),
    [STRINGID_PKMNSEALEDOPPONENTMOVE]               = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} selló cualquier movimiento que su objetivo compartiera con él!"),
    [STRINGID_PKMNCANTUSEMOVESEALED]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede usar su {B_CURRENT_MOVE} sellado!\p"),
    [STRINGID_PKMNWANTSGRUDGE]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} quiere que su objetivo guarde rencor!"),
    [STRINGID_PKMNLOSTPPGRUDGE]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} perdió todos los PP de {B_BUFF1} debido al rencor!"),
    [STRINGID_PKMNSHROUDEDITSELF]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se cubrió con Magic Coat!"),
    [STRINGID_PKMNMOVEBOUNCED]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} rebotó el {B_CURRENT_MOVE}!"),
    [STRINGID_PKMNWAITSFORTARGET]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está esperando que un objetivo haga un movimiento!"),
    [STRINGID_PKMNSNATCHEDMOVE]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} le arrebató el movimiento a {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNMADEITRAIN]                       = COMPOUND_STRING("¡El {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} hizo llover!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPROTECTEDBY]                      = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} estaba protegido por {B_DEF_ABILITY}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSUSAGE]                    = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX} evita que {B_ATK_NAME_WITH_PREFIX2} use {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNRESTOREDHPUSING]                  = COMPOUND_STRING("A {B_SCR_NAME_WITH_PREFIX} se le restauró su HP."),
    [STRINGID_PKMNCHANGEDTYPEWITH]                  = COMPOUND_STRING("¡El tipo de {B_EFF_NAME_WITH_PREFIX} cambió a {B_BUFF1}!"),
    [STRINGID_PKMNPREVENTSROMANCEWITH]              = COMPOUND_STRING("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX} previene el romance!"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSCONFUSIONWITH]            = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} no se puede confundir!"),
    [STRINGID_PKMNRAISEDFIREPOWERWITH]              = COMPOUND_STRING("¡El poder de los movimientos tipo Fuego de {B_SCR_NAME_WITH_PREFIX} aumentó!"),
    [STRINGID_PKMNANCHORSITSELFWITH]                = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se fija con sus ventosas!"),
    [STRINGID_PKMNPREVENTSSTATLOSSWITH]             = COMPOUND_STRING("¡Las estadísticas de {B_SCR_NAME_WITH_PREFIX} no fueron reducidas!"),
    [STRINGID_PKMNHURTSWITH]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} fue herido por {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNTRACED]                           = COMPOUND_STRING("¡Rastreó el {B_BUFF2} de {B_BUFF1}!"),
    [STRINGID_STATSHARPLY]                          = sText_StatSharplyEs,
    [STRINGID_STATHARSHLY]                          = COMPOUND_STRING("duramente"),
    [STRINGID_STATROSE]                             = COMPOUND_STRING("¡La rosa {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX}{B_BUFF2}!"),
    [STRINGID_STATFELL]                             = COMPOUND_STRING("¡{B_BUFF1} {B_BUFF2} de {B_SCR_NAME_WITH_PREFIX} cayó!"),
    [STRINGID_CRITICALHIT]                          = COMPOUND_STRING("¡Un golpe crítico!"),
    [STRINGID_ONEHITKO]                             = COMPOUND_STRING("¡Es un KO de un solo golpe!"),
    [STRINGID_123POOF]                              = COMPOUND_STRING("Uno…{PAUSE 10}dos…{PAUSE 10}y…{PAUSE 10}{PAUSE 20}{PLAY_SE SE_BALL_BOUNCE_1}ta-da!\p"),
    [STRINGID_ANDELLIPSIS]                          = COMPOUND_STRING("Y…\p"),
    [STRINGID_NOTVERYEFFECTIVE]                     = COMPOUND_STRING("No es muy efectivo..."),
    [STRINGID_SUPEREFFECTIVE]                       = COMPOUND_STRING("¡Es súper efectivo!"),
    [STRINGID_GOTAWAYSAFELY]                        = sText_GotAwaySafelyEs,
    [STRINGID_WILDPKMNFLED]                         = COMPOUND_STRING("{PLAY_SE SE_FLEE}¡El salvaje {B_BUFF1} huyó!"),
    [STRINGID_NORUNNINGFROMTRAINERS]                = COMPOUND_STRING("¡No! ¡No se puede huir de una batalla de Entrenador! \p"),
    [STRINGID_CANTESCAPE]                           = COMPOUND_STRING("¡No puedes escapar!\p"),
    [STRINGID_DONTLEAVEBIRCH]                       = COMPOUND_STRING("PROFE. BIRCH: ¡No me dejes así!\p"), //no decapitalize until it is everywhere
    [STRINGID_BUTNOTHINGHAPPENED]                   = COMPOUND_STRING("¡Pero no pasó nada!"),
    [STRINGID_BUTITFAILED]                          = COMPOUND_STRING("¡Pero falló!"),
    [STRINGID_ITHURTCONFUSION]                      = COMPOUND_STRING("¡Se lastimó en su confusión!"),
    [STRINGID_STARTEDTORAIN]                        = COMPOUND_STRING("¡Empezó a llover!"),
    [STRINGID_DOWNPOURSTARTED]                      = COMPOUND_STRING("¡Comenzó un aguacero!"), // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
    [STRINGID_RAINCONTINUES]                        = COMPOUND_STRING("La lluvia sigue cayendo."), //not in gen 5+
    [STRINGID_DOWNPOURCONTINUES]                    = COMPOUND_STRING("El aguacero continúa."), // unused
    [STRINGID_RAINSTOPPED]                          = COMPOUND_STRING("La lluvia paró."),
    [STRINGID_SANDSTORMBREWED]                      = COMPOUND_STRING("¡Se levantó una tormenta de arena!"),
    [STRINGID_SANDSTORMRAGES]                       = COMPOUND_STRING("La tormenta de arena está furiosa."),
    [STRINGID_SANDSTORMSUBSIDED]                    = COMPOUND_STRING("La tormenta de arena amainó."),
    [STRINGID_SUNLIGHTGOTBRIGHT]                    = COMPOUND_STRING("¡La luz del sol se volvió dura!"),
    [STRINGID_SUNLIGHTSTRONG]                       = COMPOUND_STRING("La luz del sol es fuerte."), //not in gen 5+
    [STRINGID_SUNLIGHTFADED]                        = COMPOUND_STRING("La luz del sol se desvaneció."),
    [STRINGID_STARTEDHAIL]                          = COMPOUND_STRING("¡Empezó a granizar!"),
    [STRINGID_HAILCONTINUES]                        = COMPOUND_STRING("El granizo está cayendo."),
    [STRINGID_HAILSTOPPED]                          = COMPOUND_STRING("El granizo cesó."),
    [STRINGID_STATCHANGESGONE]                      = COMPOUND_STRING("¡Todos los cambios de estadísticas fueron eliminados!"),
    [STRINGID_COINSSCATTERED]                       = COMPOUND_STRING("¡Las monedas estaban esparcidas por todas partes!"),
    [STRINGID_TOOWEAKFORSUBSTITUTE]                 = COMPOUND_STRING("¡Pero no le quedan suficientes HP para hacer un sustituto!"),
    [STRINGID_SHAREDPAIN]                           = COMPOUND_STRING("¡Los luchadores compartieron su dolor!"),
    [STRINGID_BELLCHIMED]                           = COMPOUND_STRING("¡Sonó una campana!"),
    [STRINGID_FAINTINTHREE]                         = COMPOUND_STRING("¡Todos los Pokémon que escuchen la canción se desmayarán en tres turnos!"),
    [STRINGID_NOPPLEFT]                             = COMPOUND_STRING("¡No quedan PP para este movimiento!\p"), //not in gen 5+
    [STRINGID_BUTNOPPLEFT]                          = COMPOUND_STRING("¡Pero ya no quedaba ningún PP para la mudanza!"),
    [STRINGID_PLAYERUSEDITEM]                       = COMPOUND_STRING("¡Usaste {B_LAST_ITEM}!"),
    [STRINGID_WALLYUSEDITEM]                        = COMPOUND_STRING("¡WALLY usó {B_LAST_ITEM}!"), //no decapitalize until it is everywhere
    [STRINGID_TRAINERBLOCKEDBALL]                   = COMPOUND_STRING("¡El Entrenador bloqueó tu Poké Ball!"),
    [STRINGID_DONTBEATHIEF]                         = COMPOUND_STRING("¡No seas ladrón!"),
    [STRINGID_ITDODGEDBALL]                         = COMPOUND_STRING("¡Esquivó tu Poké Ball lanzada! ¡Este Pokémon no se puede atrapar!"),
    [STRINGID_PKMNBROKEFREE]                        = COMPOUND_STRING("¡Oh, no! ¡El Pokémon se liberó!"),
    [STRINGID_ITAPPEAREDCAUGHT]                     = COMPOUND_STRING("¡Oooh! ¡Parecía estar atrapado!"),
    [STRINGID_AARGHALMOSTHADIT]                     = COMPOUND_STRING("¡Ay! ¡Casi lo tengo!"),
    [STRINGID_SHOOTSOCLOSE]                         = COMPOUND_STRING("¡Ah! ¡Estaba tan cerca también!"),
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER]               = COMPOUND_STRING("¡Entendido! ¡{B_DEF_NAME} fue atrapado!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p"),
    [STRINGID_GOTCHAPKMNCAUGHTWALLY]                = COMPOUND_STRING("¡Entendido! ¡{B_DEF_NAME} fue atrapado!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}"),
    [STRINGID_GIVENICKNAMECAPTURED]                 = COMPOUND_STRING("¿Te gustaría ponerle un apodo a {B_DEF_NAME}?"),
    [STRINGID_PKMNDATAADDEDTODEX]                   = COMPOUND_STRING("¡Los datos de {B_DEF_NAME} han sido añadidos a la Pokédex!\p"),
    [STRINGID_ITISRAINING]                          = COMPOUND_STRING("¡Está lloviendo!"),
    [STRINGID_SANDSTORMISRAGING]                    = COMPOUND_STRING("¡La tormenta de arena está arrasando!"),
    [STRINGID_CANTESCAPE2]                          = COMPOUND_STRING("¡No podías escapar!\p"),
    [STRINGID_PKMNIGNORESASLEEP]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ignoró las órdenes y siguió durmiendo!"),
    [STRINGID_PKMNIGNOREDORDERS]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ignoró las órdenes!"),
    [STRINGID_PKMNBEGANTONAP]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} comenzó a dormir la siesta!"),
    [STRINGID_PKMNLOAFING]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está holgazaneando!"),
    [STRINGID_PKMNWONTOBEY]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no obedecerá!"),
    [STRINGID_PKMNTURNEDAWAY]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se dio la vuelta!"),
    [STRINGID_PKMNPRETENDNOTNOTICE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} fingió no darse cuenta!"),
    [STRINGID_ENEMYABOUTTOSWITCHPKMN]               = COMPOUND_STRING("{B_TRAINER1_NAME_WITH_CLASS} está a punto de enviar {B_BUFF2}. ¿Cambiarás tu Pokémon?"),
    [STRINGID_CREPTCLOSER]                          = COMPOUND_STRING("¡{B_PLAYER_NAME} se acercó más a {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_CANTGETCLOSER]                        = COMPOUND_STRING("¡{B_PLAYER_NAME} no puede acercarse más!"), //safari
    [STRINGID_PKMNWATCHINGCAREFULLY]                = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} está mirando con atención!"), //safari
    [STRINGID_PKMNCURIOUSABOUTX]                    = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} siente curiosidad por el {B_BUFF1}!"), //safari
    [STRINGID_PKMNENTHRALLEDBYX]                    = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} está cautivado por el {B_BUFF1}!"), //safari
    [STRINGID_PKMNIGNOREDX]                         = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} ignoró por completo el {B_BUFF1}!"), //safari
    [STRINGID_THREWPOKEBLOCKATPKMN]                 = COMPOUND_STRING("¡{B_PLAYER_NAME} le lanzó un {POKEBLOCK} al {B_OPPONENT_MON1_NAME}!"), //safari
    [STRINGID_OUTOFSAFARIBALLS]                     = COMPOUND_STRING("{PLAY_SE SE_DING_DONG}ANNOUNCER: ¡Se te acabaron las Safari Balls! ¡Se acabó el juego! \p"), //safari
    [STRINGID_PKMNSITEMCUREDPARALYSIS]              = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} curó su parálisis!"),
    [STRINGID_PKMNSITEMCUREDPOISON]                 = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} curó su veneno!"),
    [STRINGID_PKMNSITEMHEALEDBURN]                  = COMPOUND_STRING("¡El {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} curó su quemadura!"),
    [STRINGID_PKMNSITEMDEFROSTEDIT]                 = COMPOUND_STRING("¡El {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} lo descongeló!"),
    [STRINGID_PKMNSITEMWOKEIT]                      = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} lo despertó!"),
    [STRINGID_PKMNSITEMSNAPPEDOUT]                  = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} lo sacó de su confusión!"),
    [STRINGID_PKMNSITEMCUREDPROBLEM]                = COMPOUND_STRING("¡El {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} solucionó su problema de {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_PKMNSITEMRESTOREDHEALTH]              = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} restauró su salud usando su {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDPP]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} restauró a PP a su movimiento {B_BUFF1} usando su {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDSTATUS]              = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} volvió a sus estadísticas a la normalidad usando su {B_LAST_ITEM}!"),
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE]           = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} restauró un poco de HP usando su {B_LAST_ITEM}!"),
    [STRINGID_ITEMALLOWSONLYYMOVE]                  = COMPOUND_STRING("{B_LAST_ITEM} sólo permite el uso de {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNHUNGONWITHX]                      = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} aguantó usando su {B_LAST_ITEM}!"),
    [STRINGID_EMPTYSTRING3]                         = gText_EmptyString3,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2]             = COMPOUND_STRING("A {B_ATK_NAME_WITH_PREFIX} se le restauró su HP."),
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM]             = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} provocó una tormenta de arena!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXPREVENTSYLOSS]                  = COMPOUND_STRING("¡El {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} no fue bajado!"),
    [STRINGID_PKMNSXINFATUATEDY]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se enamoró!"),
    [STRINGID_PKMNSXMADEYINEFFECTIVE]               = COMPOUND_STRING("¡El artículo de {B_SCR_NAME_WITH_PREFIX} no se puede eliminar!"),
    [STRINGID_ITSUCKEDLIQUIDOOZE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} aspiró el líquido que rezuma!"),
    [STRINGID_PKMNTRANSFORMED]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} transformado!"),
    [STRINGID_ELECTRICITYWEAKENED]                  = COMPOUND_STRING("¡El poder de la electricidad se debilitó!"),
    [STRINGID_FIREWEAKENED]                         = COMPOUND_STRING("¡El poder del fuego se debilitó!"),
    [STRINGID_PKMNHIDUNDERWATER]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se escondió bajo el agua!"),
    [STRINGID_PKMNSPRANGUP]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} surgió!"),
    [STRINGID_HMMOVESCANTBEFORGOTTEN]               = COMPOUND_STRING("Los movimientos HM no se pueden olvidar ahora.\p"),
    [STRINGID_XFOUNDONEY]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} encontró un {B_LAST_ITEM}!"),
    [STRINGID_PLAYERDEFEATEDTRAINER1]               = sText_PlayerDefeatedLinkTrainerTrainer1Es,
    [STRINGID_SOOTHINGAROMA]                        = COMPOUND_STRING("¡Un aroma relajante flotaba por la zona!"),
    [STRINGID_ITEMSCANTBEUSEDNOW]                   = COMPOUND_STRING("Los artículos no se pueden usar ahora.{PAUSE 64}"), // Not present in Gen 5+
    [STRINGID_USINGITEMSTATOFPKMNROSE]              = COMPOUND_STRING("¡El {B_LAST_ITEM}{B_BUFF2} impulsó el {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_USINGITEMSTATOFPKMNFELL]              = COMPOUND_STRING("¡El {B_LAST_ITEM}{B_BUFF2} bajó el {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX2}!"), // This string does not exist in Gen 5+. Used to print more info that's otherwise obscured such as using Room Service
    [STRINGID_PKMNUSEDXTOGETPUMPED]                 = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} usó el {B_LAST_ITEM} para entusiasmarse!"),
    [STRINGID_PKMNSXMADEYUSELESS]                   = COMPOUND_STRING("¡El {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} inutilizó a {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNTRAPPEDBYSANDTOMB]                = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} quedó atrapado por las arenas movedizas!"),
    [STRINGID_EMPTYSTRING4]                         = COMPOUND_STRING(""),
    [STRINGID_ABOOSTED]                             = COMPOUND_STRING("un impulsado"),
    [STRINGID_PKMNSXINTENSIFIEDSUN]                 = COMPOUND_STRING("¡El {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} intensificó los rayos del sol!"), //not in gen 5+, ability popup
    [STRINGID_YOUTHROWABALLNOWRIGHT]                = COMPOUND_STRING("Lanzas una pelota ahora, ¿verdad? Yo... ¡haré lo mejor que pueda!"),
    [STRINGID_PKMNSXTOOKATTACK]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} tomó el ataque!"),
    [STRINGID_PKMNCHOSEXASDESTINY]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} eligió Doom Desire como su destino!"),
    [STRINGID_PKMNLOSTFOCUS]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} perdió la concentración y no podía moverse!"),
    [STRINGID_USENEXTPKMN]                          = COMPOUND_STRING("¿Usar el siguiente Pokémon?"),
    [STRINGID_PKMNFLEDUSINGITS]                     = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} huyó usando su {B_LAST_ITEM}!\p"),
    [STRINGID_PKMNFLEDUSING]                        = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} huyó usando {B_ATK_ABILITY}!\p"), //not in gen 5+
    [STRINGID_PKMNWASDRAGGEDOUT]                    = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} fue arrastrado!\p"),
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS]            = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} normalizó su estado!"), // Not in Gen 5+
    [STRINGID_TRAINER1USEDITEM]                     = COMPOUND_STRING("{B_ATK_TRAINER_NAME_WITH_CLASS} usado {B_LAST_ITEM}!"),
    [STRINGID_BOXISFULL]                            = COMPOUND_STRING("¡La Caja está llena! ¡No puedes atrapar más!\p"),
    [STRINGID_PKMNSXMADEITINEFFECTIVE]              = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} lo hizo ineficaz!"),
    [STRINGID_PKMNSXPREVENTSFLINCHING]              = COMPOUND_STRING("¡El {B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX} evita que se estremezca!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYHASBURN]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya está quemado!"),
    [STRINGID_PKMNSXBLOCKSY]                        = COMPOUND_STRING("¡{B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} bloquea {B_CURRENT_MOVE}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXWOREOFF]                        = COMPOUND_STRING("¡El {B_BUFF1} del equipo {B_ATK_TEAM1} desapareció!"),
    [STRINGID_THEWALLSHATTERED]                     = COMPOUND_STRING("¡El muro se hizo añicos!"), //not in gen5+, uses "your teams light screen wore off!" etc instead
    [STRINGID_PKMNSXCUREDITSYPROBLEM]               = COMPOUND_STRING("¡El {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} solucionó su problema de {B_BUFF1}!"), //not in gen 5+, ability popup
    [STRINGID_ATTACKERCANTESCAPE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede escapar!"),
    [STRINGID_PKMNOBTAINEDX]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} obtuvo {B_BUFF1}."),
    [STRINGID_PKMNOBTAINEDX2]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} obtuvo {B_BUFF2}."),
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} obtuvo {B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} obtuvo {B_BUFF2}."),
    [STRINGID_BUTNOEFFECT]                          = COMPOUND_STRING("¡Pero no tuvo ningún efecto!"),
    [STRINGID_TWOENEMIESDEFEATED]                   = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER2_LOSE_TEXT}"),
    [STRINGID_PKMNINCAPABLEOFPOWER]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} parece incapaz de usar su poder!"),
    [STRINGID_GLINTAPPEARSINEYE]                    = COMPOUND_STRING("¡Un brillo aparece en los ojos de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNGETTINGINTOPOSITION]              = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se está poniendo en posición!"),
    [STRINGID_PKMNBEGANGROWLINGDEEPLY]              = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} comenzó a gruñir profundamente!"),
    [STRINGID_PKMNEAGERFORMORE]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} está ansioso por más!"),
    [STRINGID_DEFEATEDOPPONENTBYREFEREE]            = COMPOUND_STRING("¡{B_PLAYER_MON1_NAME} derrotó al oponente {B_OPPONENT_MON1_NAME} en una decisión del ÁRBITRO!"),
    [STRINGID_LOSTTOOPPONENTBYREFEREE]              = COMPOUND_STRING("¡{B_PLAYER_MON1_NAME} perdió ante el oponente {B_OPPONENT_MON1_NAME} por decisión del ÁRBITRO!"),
    [STRINGID_TIEDOPPONENTBYREFEREE]                = COMPOUND_STRING("¡{B_PLAYER_MON1_NAME} empató al oponente {B_OPPONENT_MON1_NAME} en una decisión del ÁRBITRO!"),
    [STRINGID_QUESTIONFORFEITMATCH]                 = COMPOUND_STRING("¿Le gustaría perder el partido y abandonar ahora?"),
    [STRINGID_FORFEITEDMATCH]                       = COMPOUND_STRING("El partido fue perdido."),
    [STRINGID_PKMNTRANSFERREDSOMEONESPC]            = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC]            = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL]                = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL]                = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT]                      = COMPOUND_STRING("{B_TRAINER1_WIN_TEXT}"),
    [STRINGID_TRAINER2WINTEXT]                      = COMPOUND_STRING("{B_TRAINER2_WIN_TEXT}"),
    [STRINGID_ENDUREDSTURDY]                        = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} soportó el golpe usando {B_DEF_ABILITY}!"),
    [STRINGID_POWERHERB]                            = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} quedó completamente cargado debido a su {B_LAST_ITEM}!"),
    [STRINGID_HURTBYITEM]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} resultó herido por el {B_LAST_ITEM}!"),
    [STRINGID_GRAVITYINTENSIFIED]                   = COMPOUND_STRING("¡La gravedad se intensificó!"),
    [STRINGID_TARGETWOKEUP]                         = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} despertó!"),
    [STRINGID_TAILWINDBLEW]                         = COMPOUND_STRING("¡El viento de cola sopló detrás del equipo {B_ATK_TEAM2}!"),
    [STRINGID_PKMNWENTBACK]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} volvió a {B_ATK_TRAINER_NAME}!"),
    [STRINGID_PKMNCANTUSEITEMSANYMORE]              = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya no puede usar artículos!"),
    [STRINGID_PKMNFLUNG]                            = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} arrojó su {B_LAST_ITEM}!"),
    [STRINGID_PKMNPREVENTEDFROMHEALING]             = COMPOUND_STRING("¡A {B_DEF_NAME_WITH_PREFIX} se le impidió sanar!"),
    [STRINGID_PKMNSWITCHEDATKANDDEF]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} cambió su ataque y defensa!"),
    [STRINGID_PKMNSABILITYSUPPRESSED]               = COMPOUND_STRING("¡La habilidad de {B_DEF_NAME_WITH_PREFIX} fue suprimida!"),
    [STRINGID_SHIELDEDFROMCRITICALHITS]             = COMPOUND_STRING("¡Lucky Chant protegió al equipo {B_ATK_TEAM2} de golpes críticos!"),
    [STRINGID_PKMNACQUIREDABILITY]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} adquirió {B_DEF_ABILITY}!"),
    [STRINGID_POISONSPIKESSCATTERED]                = COMPOUND_STRING("¡Picos de veneno estaban esparcidos por el suelo alrededor del equipo {B_DEF_TEAM2}!"),
    [STRINGID_PKMNSWITCHEDSTATCHANGES]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} cambió los cambios de estadísticas con su objetivo!"),
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER]        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se rodeó de un velo de agua!"),
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM]      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} levitado con electromagnetismo!"),
    [STRINGID_PKMNTWISTEDDIMENSIONS]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} torció las dimensiones!"),
    [STRINGID_POINTEDSTONESFLOAT]                   = COMPOUND_STRING("¡Piedras puntiagudas flotan en el aire alrededor del equipo {B_DEF_TEAM2}!"),
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA]               = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} quedó atrapado por un remolino de magma!"),
    [STRINGID_VANISHEDINSTANTLY]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} desapareció al instante!"),
    [STRINGID_PROTECTEDTEAM]                        = COMPOUND_STRING("¡{B_CURRENT_MOVE} protegió al equipo {B_ATK_TEAM2}!"),
    [STRINGID_SHAREDITSGUARD]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} compartió su guardia con el objetivo!"),
    [STRINGID_SHAREDITSPOWER]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} compartió su poder con el objetivo!"),
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON]         = COMPOUND_STRING("Creó una zona extraña en la que Defensa y Sp. ¡Las estadísticas de defensa se intercambian!"),
    [STRINGID_BECAMENIMBLE]                         = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se volvió ágil!"),
    [STRINGID_HURLEDINTOTHEAIR]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} fue lanzado al aire!"),
    [STRINGID_HELDITEMSLOSEEFFECTS]                 = COMPOUND_STRING("¡Creó un área extraña en la que los objetos que posee Pokémon pierden sus efectos!"),
    [STRINGID_FELLSTRAIGHTDOWN]                     = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} cayó hacia abajo!"),
    [STRINGID_TARGETCHANGEDTYPE]                    = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} transformado en el tipo {B_BUFF1}!"),
    [STRINGID_KINDOFFER]                            = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} aceptó la amable oferta!"),
    [STRINGID_RESETSTARGETSSTATLEVELS]              = COMPOUND_STRING("¡Se eliminaron los cambios en las estadísticas de {B_EFF_NAME_WITH_PREFIX}!"),
    [STRINGID_ALLYSWITCHPOSITION]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} y {B_SCR_NAME_WITH_PREFIX2} cambiaron de lugar!"),
    [STRINGID_REFLECTTARGETSTYPE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se convirtió en el mismo tipo que {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_EMBARGOENDS]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} puede volver a usar elementos!"),
    [STRINGID_ELECTROMAGNETISM]                     = COMPOUND_STRING("electromagnetismo"),
    [STRINGID_BUFFERENDS]                           = COMPOUND_STRING("¡El efecto {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} desapareció!"),
    [STRINGID_TELEKINESISENDS]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} fue liberado de la telequinesis!"),
    [STRINGID_TAILWINDENDS]                         = COMPOUND_STRING("¡El Tailwind del equipo {B_ATK_TEAM1} se agotó!"),
    [STRINGID_LUCKYCHANTENDS]                       = COMPOUND_STRING("¡El Lucky Chant del equipo {B_ATK_TEAM1} desapareció!"),
    [STRINGID_TRICKROOMENDS]                        = COMPOUND_STRING("¡Las dimensiones retorcidas volvieron a la normalidad!"),
    [STRINGID_WONDERROOMENDS]                       = COMPOUND_STRING("Wonder Room desapareció, y Defense y Sp. ¡Las estadísticas de defensa volvieron a la normalidad!"),
    [STRINGID_MAGICROOMENDS]                        = COMPOUND_STRING("¡La Sala Mágica desapareció y los efectos de los objetos retenidos volvieron a la normalidad!"),
    [STRINGID_MUDSPORTENDS]                         = COMPOUND_STRING("Los efectos de Mud Sport se han desvanecido."),
    [STRINGID_WATERSPORTENDS]                       = COMPOUND_STRING("Los efectos de los deportes acuáticos se han desvanecido."),
    [STRINGID_GRAVITYENDS]                          = COMPOUND_STRING("¡La gravedad volvió a la normalidad!"),
    [STRINGID_AQUARINGHEAL]                         = COMPOUND_STRING("¡Un velo de agua restauró el HP de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ELECTRICTERRAINENDS]                  = COMPOUND_STRING("La electricidad desapareció del campo de batalla."),
    [STRINGID_MISTYTERRAINENDS]                     = COMPOUND_STRING("La niebla desapareció del campo de batalla."),
    [STRINGID_PSYCHICTERRAINENDS]                   = COMPOUND_STRING("¡La rareza desapareció del campo de batalla!"),
    [STRINGID_GRASSYTERRAINENDS]                    = COMPOUND_STRING("La hierba desapareció del campo de batalla."),
    [STRINGID_TARGETABILITYSTATRAISE]               = COMPOUND_STRING("¡{B_DEF_ABILITY} {B_BUFF2} de {B_DEF_NAME_WITH_PREFIX} elevó su {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_STATWASMAXEDOUT]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} maximizó su {B_BUFF1}!"),
    [STRINGID_ATTACKERABILITYSTATRAISE]             = COMPOUND_STRING("¡{B_ATK_ABILITY} {B_BUFF2} de {B_ATK_NAME_WITH_PREFIX} elevó su {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_POISONHEALHPUP]                       = COMPOUND_STRING("¡El envenenamiento curó un poco a {B_ATK_NAME_WITH_PREFIX2}!"), // Not in Gen 5+
    [STRINGID_BADDREAMSDMG]                         = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} está atormentado!"),
    [STRINGID_MOLDBREAKERENTERS]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} rompe moldes!"),
    [STRINGID_TERAVOLTENTERS]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} irradia un aura explosiva!"),
    [STRINGID_TURBOBLAZEENTERS]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} irradia un aura ardiente!"),
    [STRINGID_SLOWSTARTENTERS]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} tarda en ponerse en marcha!"),
    [STRINGID_SLOWSTARTEND]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} finalmente se puso manos a la obra!"),
    [STRINGID_SOLARPOWERHPDROP]                     = COMPOUND_STRING("¡El {B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX} pasa factura!"), // Not in Gen 5+
    [STRINGID_AFTERMATHDMG]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} resultó herido!"),
    [STRINGID_ANTICIPATIONACTIVATES]                = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se estremeció!"),
    [STRINGID_FOREWARNACTIVATES]                    = COMPOUND_STRING("¡{B_SCR_ABILITY} alertó a {B_SCR_NAME_WITH_PREFIX2} sobre el {B_BUFF1} de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ICEBODYHPGAIN]                        = COMPOUND_STRING("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX} lo curó un poco!"), // Not in Gen 5+
    [STRINGID_SNOWWARNINGHAIL]                      = COMPOUND_STRING("¡Empezó a granizar!"),
    [STRINGID_FRISKACTIVATES]                       = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} registró a {B_SCR_NAME_WITH_PREFIX2} y encontró su {B_LAST_ITEM}!"),
    [STRINGID_UNNERVEENTERS]                        = COMPOUND_STRING("¡El equipo {B_EFF_TEAM1} está demasiado nervioso para comer bayas!"),
    [STRINGID_HARVESTBERRY]                         = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} cosechó su {B_LAST_ITEM}!"),
    [STRINGID_PROTEANTYPECHANGE]                    = COMPOUND_STRING("¡El {B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX} lo transformó en el tipo {B_BUFF1}!"),
    [STRINGID_SYMBIOSISITEMPASS]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} compartió su {B_LAST_ITEM} con {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_STEALTHROCKDMG]                       = COMPOUND_STRING("¡Piedras puntiagudas excavadas en {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_TOXICSPIKESABSORBED]                  = COMPOUND_STRING("¡Los picos de veneno desaparecieron del suelo alrededor del equipo {B_EFF_TEAM2}!"),
    [STRINGID_TOXICSPIKESPOISONED]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} fue envenenado!"),
    [STRINGID_TOXICSPIKESBADLYPOISONED]             = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} fue gravemente envenenado!"),
    [STRINGID_STICKYWEBSWITCHIN]                    = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} quedó atrapado en una red pegajosa!"),
    [STRINGID_HEALINGWISHCAMETRUE]                  = COMPOUND_STRING("¡El deseo de curación se hizo realidad para {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_HEALINGWISHHEALED]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} recuperó la salud!"),
    [STRINGID_LUNARDANCECAMETRUE]                   = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} quedó envuelto en la mística luz de la luna!"),
    [STRINGID_CURSEDBODYDISABLED]                   = COMPOUND_STRING("¡{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX} fue deshabilitado!"),
    [STRINGID_ATTACKERACQUIREDABILITY]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} adquirió {B_ATK_ABILITY}!"), // Not in Gen 5+
    [STRINGID_TARGETABILITYSTATLOWER]               = COMPOUND_STRING("¡{B_DEF_ABILITY} {B_BUFF2} de {B_DEF_NAME_WITH_PREFIX} bajó su {B_BUFF1}!"), // Not in Gen 5+
    [STRINGID_TARGETSTATWONTGOHIGHER]               = COMPOUND_STRING("¡El {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX} no llegará más alto!"),
    [STRINGID_PKMNMOVEBOUNCEDABILITY]               = COMPOUND_STRING("¡{B_CURRENT_MOVE} de {B_DEF_NAME_WITH_PREFIX} se recuperó!"),
    [STRINGID_IMPOSTERTRANSFORM]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} transformado en {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ASSAULTVESTDOESNTALLOW]               = COMPOUND_STRING("¡Los efectos del {B_LAST_ITEM} impiden que se utilicen movimientos de estado!\p"),
    [STRINGID_GRAVITYPREVENTSUSAGE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede usar {B_CURRENT_MOVE} debido a la gravedad!\p"),
    [STRINGID_HEALBLOCKPREVENTSUSAGE]               = COMPOUND_STRING("¡A {B_ATK_NAME_WITH_PREFIX} se le impidió sanar!\p"),
    [STRINGID_NOTDONEYET]                           = COMPOUND_STRING("¡Este efecto de movimiento aún no está terminado!\p"),
    [STRINGID_STICKYWEBUSED]                        = COMPOUND_STRING("¡Se ha tendido una red pegajosa en el suelo alrededor del equipo {B_DEF_TEAM2}!"),
    [STRINGID_QUASHSUCCESS]                         = COMPOUND_STRING("¡La mudanza de {B_DEF_NAME_WITH_PREFIX} fue pospuesta!"),
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} arrasó con los picos tóxicos!"),
    [STRINGID_PKMNBLEWAWAYSTICKYWEB]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} arrasó con Sticky Web!"),
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} arrasó con Stealth Rock!"),
    [STRINGID_IONDELUGEON]                          = COMPOUND_STRING("¡Un diluvio de iones inunda el campo de batalla!"),
    [STRINGID_TOPSYTURVYSWITCHEDSTATS]              = COMPOUND_STRING("¡Todos los cambios de estadísticas en {B_DEF_NAME_WITH_PREFIX2} fueron invertidos!"),
    [STRINGID_TERRAINBECOMESMISTY]                  = COMPOUND_STRING("¡La niebla se arremolinaba en el campo de batalla!"),
    [STRINGID_TERRAINBECOMESGRASSY]                 = COMPOUND_STRING("¡La hierba creció para cubrir el campo de batalla!"),
    [STRINGID_TERRAINBECOMESELECTRIC]               = COMPOUND_STRING("¡Una corriente eléctrica recorrió el campo de batalla!"),
    [STRINGID_TERRAINBECOMESPSYCHIC]                = COMPOUND_STRING("¡El campo de batalla se volvió extraño!"),
    [STRINGID_TARGETELECTRIFIED]                    = COMPOUND_STRING("¡Los movimientos de {B_DEF_NAME_WITH_PREFIX} han sido electrificados!"),
    [STRINGID_MEGAEVOREACTING]                      = COMPOUND_STRING("¡{B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX} está reaccionando al Mega Ring de {B_ATK_TRAINER_NAME}!"), //actually displays the type of mega ring in inventory, but we didnt implement them :(
    [STRINGID_MEGAEVOEVOLVED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ha megaevolucionado a Mega {B_BUFF1}!"),
    [STRINGID_DRASTICALLY]                          = gText_drastically,
    [STRINGID_SEVERELY]                             = gText_severely,
    [STRINGID_INFESTATION]                          = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} ha sido afectado por una infestación de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_NOEFFECTONTARGET]                     = COMPOUND_STRING("¡No tendrá ningún efecto en {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_BURSTINGFLAMESHIT]                    = COMPOUND_STRING("¡Las llamas explosivas golpearon a {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_BESTOWITEMGIVING]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} recibió {B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THIRDTYPEADDED]                       = COMPOUND_STRING("¡Se agregó el tipo {B_BUFF1} a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_FELLFORFEINT]                         = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} cayó en la finta!"),
    [STRINGID_POKEMONCANNOTUSEMOVE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} no puede usar {B_CURRENT_MOVE}!"),
    [STRINGID_COVEREDINPOWDER]                      = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} está cubierto de polvo!"),
    [STRINGID_POWDEREXPLODES]                       = COMPOUND_STRING("Cuando la llama tocó el polvo del Pokémon, ¡explotó!"),
    [STRINGID_BELCHCANTSELECT]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} no ha comido ninguna bayas retenidas, ¡así que no puede eructar!\p"),
    [STRINGID_SPECTRALTHIEFSTEAL]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} robó las estadísticas mejoradas del objetivo!"),
    [STRINGID_GRAVITYGROUNDING]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} cayó del cielo debido a la gravedad!"),
    [STRINGID_MISTYTERRAINPREVENTS]                 = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se rodea de una niebla protectora!"),
    [STRINGID_GRASSYTERRAINHEALS]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se cura con el terreno cubierto de hierba!"),
    [STRINGID_ELECTRICTERRAINPREVENTS]              = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se rodea de terreno electrificado!"),
    [STRINGID_PSYCHICTERRAINPREVENTS]               = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} está protegido por el Terreno Psíquico!"),
    [STRINGID_SAFETYGOGGLESPROTECTED]               = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} no se ve afectado gracias a su {B_LAST_ITEM}!"),
    [STRINGID_FLOWERVEILPROTECTED]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se rodeó de un velo de pétalos!"),
    [STRINGID_FLOWERVEILPROTECTEDTARGET]            = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se rodeó de un velo de pétalos!"),
    [STRINGID_AROMAVEILPROTECTED]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} está protegido por un velo aromático!"),
    [STRINGID_CELEBRATEMESSAGE]                     = COMPOUND_STRING("¡Felicitaciones, {B_PLAYER_NAME}!"),
    [STRINGID_USEDINSTRUCTEDMOVE]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} siguió las instrucciones de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THROATCHOPENDS]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} puede volver a usar movimientos basados en sonido!"),
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP]            = COMPOUND_STRING("¡Los efectos de Throat Chop impiden que {B_ATK_NAME_WITH_PREFIX2} use ciertos movimientos!\p"),
    [STRINGID_LASERFOCUS]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} concentrado intensamente!"),
    [STRINGID_GEMACTIVATES]                         = COMPOUND_STRING("¡El {B_LAST_ITEM} fortaleció el poder del {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_BERRYDMGREDUCES]                      = COMPOUND_STRING("¡El {B_LAST_ITEM} debilitó el daño a {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_AIRBALLOONFLOAT]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} flota en el aire con su globo aerostático!"),
    [STRINGID_AIRBALLOONPOP]                        = COMPOUND_STRING("¡El globo aerostático de {B_DEF_NAME_WITH_PREFIX} explotó!"),
    [STRINGID_INCINERATEBURN]                       = COMPOUND_STRING("¡El {B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX} se quemó!"),
    [STRINGID_BUGBITE]                              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} robó y se comió el {B_LAST_ITEM} de su objetivo!"),
    [STRINGID_ILLUSIONWOREOFF]                      = COMPOUND_STRING("¡La ilusión de {B_SCR_NAME_WITH_PREFIX} desapareció!"),
    [STRINGID_ATTACKERCUREDTARGETSTATUS]            = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} solucionó el problema de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ATTACKERLOSTFIRETYPE]                 = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se quemó solo!"),
    [STRINGID_HEALERCURE]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se curó de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_SCRIPTINGABILITYSTATRAISE]            = COMPOUND_STRING("¡{B_SCR_ABILITY} {B_BUFF2} de {B_SCR_NAME_WITH_PREFIX} elevó su {B_BUFF1}!"),
    [STRINGID_RECEIVERABILITYTAKEOVER]              = COMPOUND_STRING("¡El {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} fue tomado!"),
    [STRINGID_PKNMABSORBINGPOWER]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está absorbiendo poder!"),
    [STRINGID_NOONEWILLBEABLETORUNAWAY]             = COMPOUND_STRING("¡Nadie podrá huir durante el próximo turno!"),
    [STRINGID_DESTINYKNOTACTIVATES]                 = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se enamoró del {B_LAST_ITEM}!"),
    [STRINGID_CLOAKEDINAFREEZINGLIGHT]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} quedó envuelto en una luz helada!"),
    [STRINGID_CLEARAMULETWONTLOWERSTATS]            = COMPOUND_STRING("¡Los efectos del {B_LAST_ITEM} en poder de {B_SCR_NAME_WITH_PREFIX2} evitan que sus estadísticas disminuyan!"),
    [STRINGID_FERVENTWISHREACHED]                   = COMPOUND_STRING("¡El ferviente deseo de {B_ATK_TRAINER_NAME} ha llegado a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_AIRLOCKACTIVATES]                     = COMPOUND_STRING("Los efectos del clima desaparecieron."),
    [STRINGID_PRESSUREENTERS]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} está ejerciendo presión!"),
    [STRINGID_DARKAURAENTERS]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} irradia un aura oscura!"),
    [STRINGID_FAIRYAURAENTERS]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} irradia un aura de hada!"),
    [STRINGID_AURABREAKENTERS]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} invirtió las auras de todos los demás Pokémon!"),
    [STRINGID_COMATOSEENTERS]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} está durmiendo!"),
    [STRINGID_SCREENCLEANERENTERS]                  = COMPOUND_STRING("¡Se limpiaron todas las pantallas del campo!"),
    [STRINGID_FETCHEDPOKEBALL]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} encontró un {B_LAST_ITEM}!"),
    [STRINGID_ASANDSTORMKICKEDUP]                   = COMPOUND_STRING("¡Se levantó una tormenta de arena!"),
    [STRINGID_PKMNSWILLPERISHIN3TURNS]              = COMPOUND_STRING("¡Ambos Pokémon se debilitarán en tres turnos!"),
    [STRINGID_AURAFLAREDTOLIFE]                     = COMPOUND_STRING("¡El aura de {B_ATK_NAME_WITH_PREFIX} cobró vida!"),
    [STRINGID_ASONEENTERS]                          = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} tiene dos habilidades!"),
    [STRINGID_CURIOUSMEDICINEENTERS]                = COMPOUND_STRING("¡Se eliminaron los cambios en las estadísticas de {B_EFF_NAME_WITH_PREFIX}!"),
    [STRINGID_CANACTFASTERTHANKSTO]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} puede actuar más rápido de lo normal gracias a su {B_BUFF1}!"),
    [STRINGID_MICLEBERRYACTIVATES]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} aumentó la precisión de su siguiente movimiento usando {B_LAST_ITEM}!"),
    [STRINGID_PKMNSHOOKOFFTHETAUNT]                 = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se libró de la burla!"),
    [STRINGID_PKMNGOTOVERITSINFATUATION]            = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} superó su enamoramiento!"),
    [STRINGID_ITEMCANNOTBEREMOVED]                  = COMPOUND_STRING("¡El artículo de {B_ATK_NAME_WITH_PREFIX} no se puede eliminar!"),
    [STRINGID_STICKYBARBTRANSFER]                   = COMPOUND_STRING("¡El {B_LAST_ITEM} se adjuntó a {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBURNHEALED]                       = COMPOUND_STRING("¡La quemadura de {B_DEF_NAME_WITH_PREFIX} se curó!"),
    [STRINGID_REDCARDACTIVATE]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} mostró su tarjeta roja contra {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_EJECTBUTTONACTIVATE]                  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se cambia con {B_LAST_ITEM}!"),
    [STRINGID_ATKGOTOVERINFATUATION]                = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} curó su estado de enamoramiento usando su {B_LAST_ITEM}!"),
    [STRINGID_TORMENTEDNOMORE]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ya no está atormentado!"),
    [STRINGID_HEALBLOCKEDNOMORE]                    = COMPOUND_STRING("¡Ya no se impide que {B_SCR_NAME_WITH_PREFIX} se cure!"),
    [STRINGID_ATTACKERBECAMEFULLYCHARGED]           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} quedó completamente cargado debido a su vínculo con su entrenador!\p"),
    [STRINGID_ATTACKERBECAMEASHSPECIES]             = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se convirtió en Ash-Greninja!\p"),
    [STRINGID_EXTREMELYHARSHSUNLIGHT]               = COMPOUND_STRING("¡La luz del sol se volvió extremadamente dura!"),
    [STRINGID_EXTREMESUNLIGHTFADED]                 = COMPOUND_STRING("¡La luz del sol extremadamente intensa se desvaneció!"),
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT]     = COMPOUND_STRING("¡El ataque tipo Agua se evaporó bajo la luz del sol extremadamente intensa!"),
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED] = COMPOUND_STRING("¡La luz del sol extremadamente dura no disminuyó en absoluto!"),
    [STRINGID_HEAVYRAIN]                            = COMPOUND_STRING("¡Comenzó a caer una fuerte lluvia!"),
    [STRINGID_HEAVYRAINLIFTED]                      = COMPOUND_STRING("¡La fuerte lluvia ha cesado!"),
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN]         = COMPOUND_STRING("¡El ataque tipo Fuego fracasó bajo la fuerte lluvia!"),
    [STRINGID_NORELIEFROMHEAVYRAIN]                 = COMPOUND_STRING("¡No hay alivio para esta fuerte lluvia!"),
    [STRINGID_MYSTERIOUSAIRCURRENT]                 = COMPOUND_STRING("¡Misteriosos vientos fuertes protegen a los Pokémon de tipo Volador!"),
    [STRINGID_STRONGWINDSDISSIPATED]                = COMPOUND_STRING("¡Los misteriosos y fuertes vientos se han disipado!"),
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON]          = COMPOUND_STRING("¡Los misteriosos y fuertes vientos continúan soplando de todos modos!"),
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS]           = COMPOUND_STRING("¡Los misteriosos vientos fuertes debilitaron el ataque!"),
    [STRINGID_STUFFCHEEKSCANTSELECT]                = COMPOUND_STRING("¡No puede usar el movimiento porque no tiene una baya!\p"),
    [STRINGID_PKMNREVERTEDTOPRIMAL]                 = COMPOUND_STRING("¡La reversión primordial de {B_SCR_NAME_WITH_PREFIX}! ¡Volvió a su estado original!"),
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE]             = COMPOUND_STRING("¡Pero {B_ATK_NAME_WITH_PREFIX2} no puede usar el movimiento!"),
    [STRINGID_BUTHOOPACANTUSEIT]                    = COMPOUND_STRING("¡Pero {B_ATK_NAME_WITH_PREFIX2} no puede usarlo como está ahora!"),
    [STRINGID_BROKETHROUGHPROTECTION]               = COMPOUND_STRING("¡Rompió la protección de {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ABILITYALLOWSONLYMOVE]                = COMPOUND_STRING("{B_ATK_ABILITY} sólo permite el uso de {B_CURRENT_MOVE}!\p"),
    [STRINGID_SWAPPEDABILITIES]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} intercambió habilidades con su objetivo!"),
    [STRINGID_PKMNHEALEDPOISON]                     = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se curó de su envenenamiento!"),
    [STRINGID_BATTLERTYPECHANGEDTO]                 = COMPOUND_STRING("¡El tipo de {B_SCR_NAME_WITH_PREFIX} cambió a {B_BUFF1}!"),
    [STRINGID_BOTHCANNOLONGERESCAPE]                = COMPOUND_STRING("¡Ninguno de los Pokémon puede huir!"),
    [STRINGID_CANTESCAPEDUETOUSEDMOVE]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} ya no puede escapar porque usó No Retreat!"),
    [STRINGID_PKMNBECAMEWEAKERTOFIRE]               = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se volvió más débil para disparar!"),
    [STRINGID_ABOUTTOUSEPOLTERGEIST]                = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} está a punto de ser atacado por su {B_LAST_ITEM}!"),
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE]       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} ya no puede escapar gracias a Octolock!"),
    [STRINGID_NEUTRALIZINGGASENTERS]                = COMPOUND_STRING("¡El gas neutralizante llenó el área!"),
    [STRINGID_NEUTRALIZINGGASOVER]                  = COMPOUND_STRING("¡Los efectos del gas neutralizante desaparecieron!"),
    [STRINGID_TARGETTOOHEAVY]                       = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} es demasiado pesado para levantarlo!"),
    [STRINGID_PKMNTOOKTARGETHIGH]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} llevó a {B_DEF_NAME_WITH_PREFIX2} al cielo!"),
    [STRINGID_PKMNINSNAPTRAP]                       = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} quedó atrapado por una trampa!"),
    [STRINGID_METEORBEAMCHARGING]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está repleto de poder espacial!"),
    [STRINGID_HEATUPBEAK]                           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} empezó a calentar su pico!"),
    [STRINGID_COURTCHANGE]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} intercambió los efectos de batalla que afectan a cada lado del campo!"),
    [STRINGID_ZPOWERSURROUNDS]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se rodeó de su Z-Power!"),
    [STRINGID_ZMOVEUNLEASHED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} desata su Z-Move con toda su fuerza!"),
    [STRINGID_ZMOVERESETSSTATS]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} devolvió sus estadísticas disminuidas a la normalidad usando su Z-Power!"),
    [STRINGID_ZMOVEALLSTATSUP]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} aumentó sus estadísticas usando su Z-Power!"),
    [STRINGID_ZMOVEZBOOSTCRIT]                      = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} aumentó su índice de golpes críticos usando su Z-Power!"),
    [STRINGID_ZMOVERESTOREHP]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} restauró su HP usando su Z-Power!"),
    [STRINGID_ZMOVESTATUP]                          = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} aumentó sus estadísticas usando su Z-Power!"),
    [STRINGID_ZMOVEHPTRAP]                          = COMPOUND_STRING("¡El Z-Power restauró el HP de {B_SCR_NAME_WITH_PREFIX}!"),
    [STRINGID_ATTACKEREXPELLEDTHEPOISON]            = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} logró expulsar el veneno para que no te preocuparas!"),
    [STRINGID_ATTACKERSHOOKITSELFAWAKE]             = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se despertó para que no te preocuparas!"),
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS]        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} reunió toda su energía para romper su parálisis para que no te preocupes!"),
    [STRINGID_ATTACKERHEALEDITSBURN]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} curó su quemadura con pura determinación para que no te preocupes!"),
    [STRINGID_ATTACKERMELTEDTHEICE]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} derritió el hielo con su ardiente determinación para que no te preocupes!"),
    [STRINGID_TARGETTOUGHEDITOUT]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} se esforzó para que no te sintieras triste!"),
    [STRINGID_ATTACKERLOSTELECTRICTYPE]             = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} agotó toda su electricidad!"),
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET]       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} cambió a {B_BUFF1} con su objetivo!"),
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER]         = COMPOUND_STRING("¡Ser golpeado por {B_CURRENT_MOVE} cargó a {B_EFF_NAME_WITH_PREFIX2} con poder!"),
    [STRINGID_SUNLIGHTACTIVATEDABILITY]             = COMPOUND_STRING("¡La intensa luz del sol activó la protosíntesis de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_STATWASHEIGHTENED]                    = COMPOUND_STRING("¡El {B_BUFF1} de {B_SCR_NAME_WITH_PREFIX} fue realzado!"),
    [STRINGID_ELECTRICTERRAINACTIVATEDABILITY]      = COMPOUND_STRING("¡El Electric Terrain activó el Quark Drive de {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_ABILITYWEAKENEDSURROUNDINGMONSSTAT]   = COMPOUND_STRING("¡El {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} debilitó el {B_BUFF1} de todos los Pokémon circundantes!\p"),
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN]  = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} ganó fuerza de los caídos!"),
    [STRINGID_PKMNSABILITYPREVENTSABILITY]          = COMPOUND_STRING("¡El {B_SCR_ABILITY} de {B_SCR_NAME_WITH_PREFIX} impide que funcione el {B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PREPARESHELLTRAP]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} puso una trampa de proyectiles!"),
    [STRINGID_SHELLTRAPDIDNTWORK]                   = COMPOUND_STRING("¡La trampa de proyectiles de {B_ATK_NAME_WITH_PREFIX} no funcionó!"),
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM]            = COMPOUND_STRING("¡Las púas desaparecieron del suelo alrededor del equipo {B_ATK_TEAM2}!"),
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("¡Los picos de veneno desaparecieron del suelo alrededor del equipo {B_ATK_TEAM2}!"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM]         = COMPOUND_STRING("¡La telaraña pegajosa ha desaparecido del suelo alrededor del equipo {B_ATK_TEAM2}!"),
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("¡Las piedras puntiagudas desaparecieron alrededor del equipo {B_ATK_TEAM2}!"),
    [STRINGID_COULDNTFULLYPROTECT]                  = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} no pudo protegerse completamente y resultó herido!"),
    [STRINGID_STOCKPILEDEFFECTWOREOFF]              = COMPOUND_STRING("¡El efecto acumulado de {B_ATK_NAME_WITH_PREFIX} desapareció!"),
    [STRINGID_PKMNREVIVEDREADYTOFIGHT]              = COMPOUND_STRING("¡{B_BUFF1} revivió y está listo para luchar nuevamente!"),
    [STRINGID_ITEMRESTOREDSPECIESHEALTH]            = COMPOUND_STRING("A {B_BUFF1} se le restauró su HP."),
    [STRINGID_ITEMCUREDSPECIESSTATUS]               = COMPOUND_STRING("¡{B_BUFF1} tuvo su estado curado!"), // Not in Gen 5+
    [STRINGID_ITEMRESTOREDSPECIESPP]                = COMPOUND_STRING("¡Se restauró el PP del {B_BUFF2} de {B_BUFF1}!"),
    [STRINGID_THUNDERCAGETRAPPED]                   = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} atrapado {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNHURTBYFROSTBITE]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} resultó herido por congelación!"),
    [STRINGID_PKMNGOTFROSTBITE]                     = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se congeló!"),
    [STRINGID_PKMNSITEMHEALEDFROSTBITE]             = COMPOUND_STRING("¡El {B_LAST_ITEM} de {B_SCR_NAME_WITH_PREFIX} curó su congelación!"),
    [STRINGID_ATTACKERHEALEDITSFROSTBITE]           = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} curó su congelación con pura determinación para que no te preocupes!"),
    [STRINGID_PKMNFROSTBITEHEALED]                  = COMPOUND_STRING("¡La congelación de {B_SCR_NAME_WITH_PREFIX} se curó!"),
    [STRINGID_PKMNFROSTBITEHEALEDBY]                = COMPOUND_STRING("¡El {B_CURRENT_MOVE} de {B_SCR_NAME_WITH_PREFIX} curó su congelación!"),
    [STRINGID_MIRRORHERBCOPIED]                     = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} usó su Mirror Herb para reflejar los cambios de estadísticas de su oponente!"),
    [STRINGID_STARTEDSNOW]                          = COMPOUND_STRING("¡Empezó a nevar!"),
    [STRINGID_SNOWCONTINUES]                        = COMPOUND_STRING("La nieve sigue cayendo."), //not in gen 5+ (lol)
    [STRINGID_SNOWSTOPPED]                          = COMPOUND_STRING("La nieve paró."),
    [STRINGID_SNOWWARNINGSNOW]                      = COMPOUND_STRING("¡Empezó a nevar!"),
    [STRINGID_PKMNITEMMELTED]                       = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} corroyó el {B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ULTRABURSTREACTING]                   = COMPOUND_STRING("¡Una luz brillante está a punto de salir de {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_ULTRABURSTCOMPLETED]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} recuperó su verdadero poder a través de Ultra Burst!"),
    [STRINGID_TEAMGAINEDEXP]                        = COMPOUND_STRING("El resto de tu equipo ganó Exp. Puntos gracias al Exp. Compartir!\p"),
    [STRINGID_CURRENTMOVECANTSELECT]                = COMPOUND_STRING("¡{B_BUFF1} no se puede utilizar!\p"),
    [STRINGID_TARGETISBEINGSALTCURED]               = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se está curando con sal!"),
    [STRINGID_TARGETISHURTBYSALTCURE]               = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está herido por {B_BUFF1}!"),
    [STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP]      = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se cubrió de almíbar de caramelo pegajoso!"),
    [STRINGID_SHARPSTEELFLOATS]                     = COMPOUND_STRING("¡Piezas de acero puntiagudas comenzaron a flotar alrededor de los Pokémon {B_DEF_TEAM2}!"),
    [STRINGID_SHARPSTEELDMG]                        = COMPOUND_STRING("¡El acero afilado mordió {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBLEWAWAYSHARPSTEEL]               = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} hizo volar el acero afilado!"),
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM]        = COMPOUND_STRING("¡Las piezas de acero que rodeaban al Pokémon {B_ATK_TEAM2} desaparecieron!"),
    [STRINGID_TEAMTRAPPEDWITHVINES]                 = COMPOUND_STRING("¡{B_EFF_TEAM1} Pokémon quedó atrapado con enredaderas!"),
    [STRINGID_PKMNHURTBYVINES]                      = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} resulta herido por la feroz golpiza de G-Max Vine Lash!"),
    [STRINGID_TEAMCAUGHTINVORTEX]                   = COMPOUND_STRING("¡{B_EFF_TEAM1} Pokémon quedó atrapado en un vórtice de agua!"),
    [STRINGID_PKMNHURTBYVORTEX]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} resulta herido por el vórtice de G-Max Cannonade!"),
    [STRINGID_TEAMSURROUNDEDBYFIRE]                 = COMPOUND_STRING("¡Los Pokémon {B_EFF_TEAM1} fueron rodeados de fuego!"),
    [STRINGID_PKMNBURNINGUP]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se está quemando entre las llamas de G-Max Wildfire!"),
    [STRINGID_TEAMSURROUNDEDBYROCKS]                = COMPOUND_STRING("¡{B_EFF_TEAM1} Pokémon quedó rodeado de rocas!"),
    [STRINGID_PKMNHURTBYROCKSTHROWN]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} resulta herido por las piedras arrojadas por G-Max Volcalith!"),
    [STRINGID_MOVEBLOCKEDBYDYNAMAX]                 = COMPOUND_STRING("¡El movimiento fue bloqueado por el poder de Dynamax!"),
    [STRINGID_ZEROTOHEROTRANSFORMATION]             = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} sufrió una transformación heroica!"),
    [STRINGID_THETWOMOVESBECOMEONE]                 = COMPOUND_STRING("¡Los dos movimientos se han convertido en uno! ¡Es un movimiento combinado!{PAUSE 16}"),
    [STRINGID_ARAINBOWAPPEAREDONSIDE]               = COMPOUND_STRING("¡Un arcoíris apareció en el cielo del lado del equipo {B_ATK_TEAM2}!"),
    [STRINGID_THERAINBOWDISAPPEARED]                = COMPOUND_STRING("¡El arcoíris del lado del equipo {B_ATK_TEAM2} desapareció!"),
    [STRINGID_WAITINGFORPARTNERSMOVE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} está esperando el movimiento de {B_ATK_PARTNER_NAME}…{PAUSE 16}"),
    [STRINGID_SEAOFFIREENVELOPEDSIDE]               = COMPOUND_STRING("¡Un mar de fuego envolvió al equipo {B_DEF_TEAM2}!"),
    [STRINGID_HURTBYTHESEAOFFIRE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} resultó herido por el mar de fuego!"),
    [STRINGID_THESEAOFFIREDISAPPEARED]              = COMPOUND_STRING("¡El mar de fuego alrededor del equipo {B_ATK_TEAM2} desapareció!"),
    [STRINGID_SWAMPENVELOPEDSIDE]                   = COMPOUND_STRING("¡Un pantano envolvió al equipo {B_EFF_TEAM2}!"),
    [STRINGID_THESWAMPDISAPPEARED]                  = COMPOUND_STRING("¡El pantano alrededor del equipo {B_ATK_TEAM2} desapareció!"),
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE]        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se está preparando para contar un chiste escalofriantemente malo!"),
    [STRINGID_HOSPITALITYRESTORATION]               = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} se bebió todo el matcha que hizo {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_ELECTROSHOTCHARGING]                  = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} absorbió electricidad!"),
    [STRINGID_ITEMWASUSEDUP]                        = COMPOUND_STRING("El {B_LAST_ITEM} estaba agotado…"),
    [STRINGID_ATTACKERLOSTITSTYPE]                  = COMPOUND_STRING("¡{B_EFF_NAME_WITH_PREFIX} perdió su tipo {B_BUFF1}!"),
    [STRINGID_SHEDITSTAIL]                          = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} se deshace de la cola para crear un señuelo!"),
    [STRINGID_CLOAKEDINAHARSHLIGHT]                 = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} quedó envuelto en una luz dura!"),
    [STRINGID_SUPERSWEETAROMAWAFTS]                 = COMPOUND_STRING("¡Un aroma súper dulce emana del almíbar que cubre {B_EFF_NAME_WITH_PREFIX2}!"),
    [STRINGID_DIMENSIONSWERETWISTED]                = COMPOUND_STRING("¡Las dimensiones estaban torcidas!"),
    [STRINGID_BIZARREARENACREATED]                  = COMPOUND_STRING("¡Se creó una zona extraña en la que los objetos que posee Pokémon pierden sus efectos!"),
    [STRINGID_BIZARREAREACREATED]                   = COMPOUND_STRING("Se creó una zona extraña en la que Defensa y Sp. ¡Las estadísticas de defensa se intercambian!"),
    [STRINGID_TIDYINGUPCOMPLETE]                    = COMPOUND_STRING("¡Ordenación completa!"),
    [STRINGID_PKMNTERASTALLIZEDINTO]                = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} terastalizado en el tipo {B_BUFF1}!"), // Does not exist, meant to mimic form change strings
    [STRINGID_BOOSTERENERGYACTIVATES]               = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} usó su {B_LAST_ITEM} para activar {B_SCR_ABILITY}!"),
    [STRINGID_FOGCREPTUP]                           = COMPOUND_STRING("¡La niebla se hizo tan espesa como una sopa!"),
    [STRINGID_FOGISDEEP]                            = COMPOUND_STRING("La niebla es profunda..."),
    [STRINGID_FOGLIFTED]                            = COMPOUND_STRING("La niebla se disipó."),
    [STRINGID_PKMNMADESHELLGLEAM]                   = COMPOUND_STRING("¡{B_DEF_NAME_WITH_PREFIX} hizo brillar su caparazón! ¡Está distorsionando los enfrentamientos de tipos!"),
    [STRINGID_FICKLEBEAMDOUBLED]                    = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} está haciendo todo lo posible por este ataque!"),
    [STRINGID_COMMANDERACTIVATES]                   = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} fue tragado por {B_BUFF1} y se convirtió en el comandante de {B_BUFF1}!"),
    [STRINGID_POKEFLUTECATCHY]                      = COMPOUND_STRING("{B_PLAYER_NAME} tocó {B_LAST_ITEM}.\p¡Ahora sí que es una melodía pegadiza!"),
    [STRINGID_POKEFLUTE]                            = COMPOUND_STRING("{B_PLAYER_NAME} jugó el {B_LAST_ITEM}."),
    [STRINGID_MONHEARINGFLUTEAWOKE]                 = COMPOUND_STRING("¡El Pokémon que escuchó la flauta despertó!"),
    [STRINGID_SUNLIGHTISHARSH]                      = COMPOUND_STRING("¡La luz del sol es dura!"),
    [STRINGID_ITISHAILING]                          = COMPOUND_STRING("¡Está granizando!"),
    [STRINGID_ITISSNOWING]                          = COMPOUND_STRING("¡Está nevando!"),
    [STRINGID_ISCOVEREDWITHGRASS]                   = COMPOUND_STRING("¡El campo de batalla está cubierto de hierba!"),
    [STRINGID_MISTSWIRLSAROUND]                     = COMPOUND_STRING("¡La niebla se arremolina en el campo de batalla!"),
    [STRINGID_ELECTRICCURRENTISRUNNING]             = COMPOUND_STRING("¡Una corriente eléctrica recorre el campo de batalla!"),
    [STRINGID_SEEMSWEIRD]                           = COMPOUND_STRING("¡El campo de batalla parece extraño!"),
    [STRINGID_WAGGLINGAFINGER]                      = COMPOUND_STRING("Moviendo un dedo, ¡déjalo usar {B_CURRENT_MOVE}!"),
    [STRINGID_BLOCKEDBYSLEEPCLAUSE]                 = COMPOUND_STRING("¡La cláusula de suspensión mantuvo despierto a {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_SUPEREFFECTIVETWOFOES]                = COMPOUND_STRING("¡Es súper efectivo en {B_DEF_NAME_WITH_PREFIX2} y {B_DEF_PARTNER_NAME}!"),
    [STRINGID_NOTVERYEFFECTIVETWOFOES]              = COMPOUND_STRING("¡No es muy efectivo en {B_DEF_NAME_WITH_PREFIX2} y {B_DEF_PARTNER_NAME}!"),
    [STRINGID_SENDCAUGHTMONPARTYORBOX]              = COMPOUND_STRING("¿Agregar {B_DEF_NAME} a tu grupo?"),
    [STRINGID_PKMNSENTTOPCAFTERCATCH]               = gText_PkmnSentToPCAfterCatch,
    [STRINGID_PKMNDYNAMAXED]                        = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} creció enormemente hasta alcanzar su forma Dynamax!"),
    [STRINGID_PKMNGIGANTAMAXED]                     = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} creció enormemente hasta alcanzar su forma Gigantamax!"),
    [STRINGID_TIMETODYNAMAX]                        = COMPOUND_STRING("¡Es hora de dinamaxizar!"),
    [STRINGID_TIMETOGIGANTAMAX]                     = COMPOUND_STRING("¡Es hora de Gigantamax!"),
    [STRINGID_QUESTIONFORFEITBATTLE]                = COMPOUND_STRING("¿Le gustaría renunciar a esta batalla y renunciar ahora? Dejar la batalla es lo mismo que perderla."),
    [STRINGID_POWERCONSTRUCTPRESENCEOFMANY]         = COMPOUND_STRING("¡Sientes la presencia de muchos!"),
    [STRINGID_POWERCONSTRUCTTRANSFORM]              = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} transformado en su forma completa!"),
    [STRINGID_ABILITYSHIELDPROTECTS]                = COMPOUND_STRING("¡La habilidad de {B_ATK_NAME_WITH_PREFIX} está protegida por los efectos de su {B_LAST_ITEM}!"),
    [STRINGID_MONTOOSCAREDTOMOVE]                   = COMPOUND_STRING("¡{B_ATK_NAME_WITH_PREFIX} tiene demasiado miedo para moverse!"),
    [STRINGID_GHOSTGETOUTGETOUT]                    = COMPOUND_STRING("FANTASMA: Fuera... Fuera..."),
    [STRINGID_SILPHSCOPEUNVEILED]                   = COMPOUND_STRING("¡SILPH SCOPE reveló la identidad \n del FANTASMA!"),
    [STRINGID_GHOSTWASMAROWAK]                      = COMPOUND_STRING("¡El FANTASMA era MAROWAK!\p"),
    [STRINGID_TRAINER1MON1COMEBACK]                 = COMPOUND_STRING("{B_TRAINER1_NAME}: {B_OPPONENT_MON1_NAME}, ¡vuelve!"),
    [STRINGID_THREWROCK]                            = COMPOUND_STRING("¡{B_PLAYER_NAME} lanzó un ROCK\n al {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_THREWBAIT]                            = COMPOUND_STRING("¡{B_PLAYER_NAME} arrojó algo de BAIT\n al {B_OPPONENT_MON1_NAME}!"),
    [STRINGID_PKMNANGRY]                            = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} está enojado!"),
    [STRINGID_PKMNEATING]                           = COMPOUND_STRING("¡{B_OPPONENT_MON1_NAME} está comiendo!"),
    [STRINGID_PKMNDISGUISEWASBUSTED]                = COMPOUND_STRING("¡El disfraz de {B_SCR_NAME_WITH_PREFIX} fue roto!"),
    [STRINGID_ZENMODETRIGGERED]                     = COMPOUND_STRING("¡{B_SCR_ABILITY} activado!"),
    [STRINGID_ZENMODEENDED]                         = COMPOUND_STRING("¡{B_SCR_ABILITY} terminó!"),
    [STRINGID_SCRCUREDPARALYSIS]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se curó de la parálisis!"),
    [STRINGID_SCRCUREDPOISON]                       = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} se curó de su envenenamiento!"),
    [STRINGID_SCRCUREDBURN]                         = COMPOUND_STRING("¡La quemadura de {B_SCR_NAME_WITH_PREFIX} se curó!"),
    [STRINGID_SCRCUREDSLEEP]                        = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} despertó!"),
    [STRINGID_SCRCUREDCONFUSION]                    = COMPOUND_STRING("¡{B_SCR_NAME_WITH_PREFIX} salió de su confusión!"),
    [STRINGID_PARTYCUREDPARALYSIS]                  = COMPOUND_STRING("¡{B_BUFF1} se curó de la parálisis!"),
    [STRINGID_PARTYCUREDPOISON]                     = COMPOUND_STRING("¡{B_BUFF1} se curó de su envenenamiento!"),
    [STRINGID_PARTYCUREDBURN]                       = COMPOUND_STRING("¡La quemadura de {B_BUFF1} se curó!"),
    [STRINGID_PARTYCUREDSLEEP]                      = COMPOUND_STRING("¡{B_BUFF1} despertó!"),
    [STRINGID_PARTYCUREDFREEZE]                     = COMPOUND_STRING("¡{B_BUFF1} descongelado!"),
    [STRINGID_PARTYCUREDFROSTBITE]                  = COMPOUND_STRING("¡La congelación de {B_BUFF1} se curó!"),
    [STRINGID_PKMNATKNOTLOWERED]                    = COMPOUND_STRING("¡El ataque de {B_SCR_NAME_WITH_PREFIX} no fue reducido!"),
    [STRINGID_REFLECTWOREOFF]                       = COMPOUND_STRING("¡El Reflect del equipo {B_DEF_TEAM1} desapareció!"),
    [STRINGID_LIGHTSCREENWOREOFF]                   = COMPOUND_STRING("¡La pantalla de luz del equipo {B_DEF_TEAM1} desapareció!"),
    [STRINGID_AURORAVEILWOREOFF]                    = COMPOUND_STRING("¡El Velo Aurora del equipo {B_DEF_TEAM1} desapareció!"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMYOU]          = COMPOUND_STRING("¡La red pegajosa ha desaparecido del suelo a tu alrededor!"),
};

const u8 *GetBattleString(u32 stringId)
{
    const u8 *const *table;

    if (stringId >= STRINGID_COUNT)
        return sText_EmptyString4;

    switch (GET_LANGUAGE())
    {
    case PT:
        table = gBattleStringsTablePt;
        break;
    case ES:
        table = gBattleStringsTableEs;
        break;
    default:
        table = gBattleStringsTable;
        break;
    }

    return table[stringId];
}

const u16 gTrainerUsedItemStringIds[] =
{
    STRINGID_PLAYERUSEDITEM, STRINGID_TRAINER1USEDITEM
};

const u16 gZEffectStringIds[] =
{
    [B_MSG_Z_RESET_STATS] = STRINGID_ZMOVERESETSSTATS,
    [B_MSG_Z_ALL_STATS_UP]= STRINGID_ZMOVEALLSTATSUP,
    [B_MSG_Z_BOOST_CRITS] = STRINGID_ZMOVEZBOOSTCRIT,
    [B_MSG_Z_FOLLOW_ME]   = STRINGID_PKMNCENTERATTENTION,
    [B_MSG_Z_RECOVER_HP]  = STRINGID_ZMOVERESTOREHP,
    [B_MSG_Z_STAT_UP]     = STRINGID_ZMOVESTATUP,
    [B_MSG_Z_HP_TRAP]     = STRINGID_ZMOVEHPTRAP,
};

const u16 gMentalHerbCureStringIds[] =
{
    [B_MSG_MENTALHERBCURE_INFATUATION] = STRINGID_ATKGOTOVERINFATUATION,
    [B_MSG_MENTALHERBCURE_TORMENT]     = STRINGID_TORMENTEDNOMORE,
    [B_MSG_MENTALHERBCURE_DISABLE]     = STRINGID_PKMNMOVEDISABLEDNOMORE,
    [B_MSG_MENTALHERBCURE_HEALBLOCK]   = STRINGID_HEALBLOCKEDNOMORE,
    [B_MSG_MENTALHERBCURE_ENCORE]      = STRINGID_PKMNENCOREENDED,
    [B_MSG_MENTALHERBCURE_TAUNT]       = STRINGID_PKMNSHOOKOFFTHETAUNT,
};

const u16 gStartingStatusStringIds[B_MSG_STARTING_STATUS_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_SET_TRICK_ROOM]       = STRINGID_DIMENSIONSWERETWISTED,
    [B_MSG_SET_MAGIC_ROOM]       = STRINGID_BIZARREARENACREATED,
    [B_MSG_SET_WONDER_ROOM]      = STRINGID_BIZARREAREACREATED,
    [B_MSG_SET_TAILWIND]         = STRINGID_TAILWINDBLEW,
    [B_MSG_SET_RAINBOW]          = STRINGID_ARAINBOWAPPEAREDONSIDE,
    [B_MSG_SET_SEA_OF_FIRE]      = STRINGID_SEAOFFIREENVELOPEDSIDE,
    [B_MSG_SET_SWAMP]            = STRINGID_SWAMPENVELOPEDSIDE,
    [B_MSG_SET_SPIKES]           = STRINGID_SPIKESSCATTERED,
    [B_MSG_SET_POISON_SPIKES]    = STRINGID_POISONSPIKESSCATTERED,
    [B_MSG_SET_STICKY_WEB]       = STRINGID_STICKYWEBUSED,
    [B_MSG_SET_STEALTH_ROCK]     = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SET_SHARP_STEEL]      = STRINGID_SHARPSTEELFLOATS,
};

const u16 gTerrainStringIds[B_MSG_TERRAIN_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY] = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC] = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY] = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_TERRAIN_END_MISTY] = STRINGID_MISTYTERRAINENDS,
    [B_MSG_TERRAIN_END_ELECTRIC] = STRINGID_ELECTRICTERRAINENDS,
    [B_MSG_TERRAIN_END_PSYCHIC] = STRINGID_PSYCHICTERRAINENDS,
    [B_MSG_TERRAIN_END_GRASSY] = STRINGID_GRASSYTERRAINENDS,
};

const u16 gTerrainPreventsStringIds[] =
{
    [B_MSG_TERRAINPREVENTS_MISTY]    = STRINGID_MISTYTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_ELECTRIC] = STRINGID_ELECTRICTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_PSYCHIC]  = STRINGID_PSYCHICTERRAINPREVENTS
};

const u16 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE,
    STRINGID_LUNARDANCECAMETRUE
};

const u16 gDmgHazardsStringIds[] =
{
    [B_MSG_PKMNHURTBYSPIKES]   = STRINGID_PKMNHURTBYSPIKES,
    [B_MSG_STEALTHROCKDMG]     = STRINGID_STEALTHROCKDMG,
    [B_MSG_SHARPSTEELDMG]      = STRINGID_SHARPSTEELDMG,
    [B_MSG_POINTEDSTONESFLOAT] = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SPIKESSCATTERED]    = STRINGID_SPIKESSCATTERED,
    [B_MSG_SHARPSTEELFLOATS]   = STRINGID_SHARPSTEELFLOATS,
};

const u16 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_TERAVOLT] = STRINGID_TERAVOLTENTERS,
    [B_MSG_SWITCHIN_TURBOBLAZE] = STRINGID_TURBOBLAZEENTERS,
    [B_MSG_SWITCHIN_SLOWSTART] = STRINGID_SLOWSTARTENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_ASONE] = STRINGID_ASONEENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
    [B_MSG_SWITCHIN_PASTEL_VEIL] = STRINGID_PKMNHEALEDPOISON,
    [B_MSG_SWITCHIN_NEUTRALIZING_GAS] = STRINGID_NEUTRALIZINGGASENTERS,
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
    [B_MSG_STARTED_SNOW]      = STRINGID_STARTEDSNOW,
    [B_MSG_STARTED_FOG]       = STRINGID_FOGCREPTUP, // Unused, can use for custom moves that set fog
};

const u16 gAbilityWeatherChangeStringId[] =
{
    [B_MSG_STARTED_DRIZZLE]        = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_SAND_STREAM]    = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_DROUGHT]        = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL_WARNING]   = STRINGID_STARTEDHAIL,
    [B_MSG_STARTED_SNOW_WARNING]   = STRINGID_STARTEDSNOW,
    [B_MSG_STARTED_DESOLATE_LAND]  = STRINGID_EXTREMELYHARSHSUNLIGHT,
    [B_MSG_STARTED_PRIMORDIAL_SEA] = STRINGID_HEAVYRAIN,
    [B_MSG_STARTED_STRONG_WINDS]   = STRINGID_MYSTERIOUSAIRCURRENT,
};

const u16 gWeatherEndsStringIds[B_MSG_WEATHER_END_COUNT] =
{
    [B_MSG_WEATHER_END_RAIN]                       = STRINGID_RAINSTOPPED,
    [B_MSG_WEATHER_END_SUN]                        = STRINGID_SUNLIGHTFADED,
    [B_MSG_WEATHER_END_SANDSTORM]                  = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_WEATHER_END_HAIL]                       = STRINGID_HAILSTOPPED,
    [B_MSG_WEATHER_END_SNOW]                       = STRINGID_SNOWSTOPPED,
    [B_MSG_WEATHER_END_FOG]                        = STRINGID_FOGLIFTED,
    [B_MSG_WEATHER_END_EXTREMELY_HARSH_SUNLIGHT]   = STRINGID_EXTREMESUNLIGHTFADED,
    [B_MSG_WEATHER_END_HEAVY_RAIN]                 = STRINGID_HEAVYRAINLIFTED,
    [B_MSG_WEATHER_END_STRONG_WINDS]               = STRINGID_STRONGWINDSDISSIPATED,
};

const u16 gWeatherTurnStringIds[] =
{
    [B_MSG_WEATHER_TURN_RAIN]         = STRINGID_RAINCONTINUES,
    [B_MSG_WEATHER_TURN_DOWNPOUR]     = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_WEATHER_TURN_SUN]          = STRINGID_SUNLIGHTSTRONG,
    [B_MSG_WEATHER_TURN_SANDSTORM]    = STRINGID_SANDSTORMRAGES,
    [B_MSG_WEATHER_TURN_HAIL]         = STRINGID_HAILCONTINUES,
    [B_MSG_WEATHER_TURN_SNOW]         = STRINGID_SNOWCONTINUES,
    [B_MSG_WEATHER_TURN_FOG]          = STRINGID_FOGISDEEP,
    [B_MSG_WEATHER_TURN_STRONG_WINDS] = STRINGID_MYSTERIOUSAIRCURRENTBLOWSON,
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u16 gBrokeProtectionStringIds[] =
{
    [B_MSG_FEINT]           = STRINGID_FELLFORFEINT,
    [B_MSG_HYPERSPACE_FURY] = STRINGID_BROKETHROUGHPROTECTION,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
    [B_MSG_SET_AURORA_VEIL]        = STRINGID_PKMNAURORAVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_STAT_CHANGED]            = STRINGID_STATROSE,
    [B_MSG_STAT_WONT_CHANGE]        = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_MAXED]              = STRINGID_STATWASMAXEDOUT,
    [B_MSG_STAT_CHANGE_EMPTY]       = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]       = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_STAT_CHANGED_BELLY_DRUM] = STRINGID_PKMNCUTHPMAXEDATTACK,
    [B_MSG_USED_DIRE_HIT]           = STRINGID_PKMNUSEDXTOGETPUMPED,
};

// Mostly redundant, combine with above in a future pr
const u16 gStatDownStringIds[] =
{
    [B_MSG_STAT_CHANGED]            = STRINGID_STATFELL,
    [B_MSG_STAT_WONT_CHANGE]        = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_CHANGE_EMPTY]       = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]       = STRINGID_USINGITEMSTATOFPKMNFELL,
    [B_MSG_STAT_CHANGED_BELLY_DRUM] = STRINGID_PKMNCUTHPMAXEDATTACK, // Message for contrary is still printed
};

// Index copied from move's index in sTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    [B_MSG_WRAPPED_BIND]        = STRINGID_PKMNSQUEEZEDBYBIND,     // MOVE_BIND
    [B_MSG_WRAPPED_WRAP]        = STRINGID_PKMNWRAPPEDBY,          // MOVE_WRAP
    [B_MSG_WRAPPED_FIRE_SPIN]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_FIRE_SPIN
    [B_MSG_WRAPPED_CLAMP]       = STRINGID_PKMNCLAMPED,            // MOVE_CLAMP
    [B_MSG_WRAPPED_WHIRLPOOL]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_WHIRLPOOL
    [B_MSG_WRAPPED_SAND_TOMB]   = STRINGID_PKMNTRAPPEDBYSANDTOMB,  // MOVE_SAND_TOMB
    [B_MSG_WRAPPED_MAGMA_STORM] = STRINGID_TRAPPEDBYSWIRLINGMAGMA, // MOVE_MAGMA_STORM
    [B_MSG_WRAPPED_INFESTATION] = STRINGID_INFESTATION,            // MOVE_INFESTATION
    [B_MSG_WRAPPED_SNAP_TRAP]   = STRINGID_PKMNINSNAPTRAP,         // MOVE_SNAP_TRAP
    [B_MSG_WRAPPED_THUNDER_CAGE]= STRINGID_THUNDERCAGETRAPPED,     // MOVE_THUNDER_CAGE
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrostbiteStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNGOTFROSTBITE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNGOTFROSTBITE,
};

const u16 gFrostbiteHealedStringIds[] =
{
    [B_MSG_FROSTBITE_HEALED]         = STRINGID_PKMNFROSTBITEHEALED,
    [B_MSG_FROSTBITE_HEALED_BY_MOVE] = STRINGID_PKMNFROSTBITEHEALEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = (B_OVERWORLD_SNOW >= GEN_9 ? STRINGID_ITISSNOWING : STRINGID_ITISHAILING),
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_FOGISDEEP,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_FOGISDEEP,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTISHARSH,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gTerrainStartsStringIds[] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_MISTSWIRLSAROUND,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_ELECTRICCURRENTISRUNNING,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_SEEMSWEIRD,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_ISCOVEREDWITHGRASS,
};

const u16 gPrimalWeatherBlocksStringIds[] =
{
    [B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN]      = STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN,
    [B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN]    = STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT,
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariReactionStringIds[NUM_SAFARI_REACTIONS] =
{
    [B_MSG_MON_WATCHING] = STRINGID_PKMNWATCHINGCAREFULLY,
    [B_MSG_MON_ANGRY]    = STRINGID_PKMNANGRY,
    [B_MSG_MON_EATING]   = STRINGID_PKMNEATING
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 CureStatusBerryEffectStringID[] =
{
    [B_MSG_CURED_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [B_MSG_CURED_POISON] = STRINGID_PKMNSITEMCUREDPOISON,
    [B_MSG_CURED_BURN] = STRINGID_PKMNSITEMHEALEDBURN,
    [B_MSG_CURED_FREEZE] = STRINGID_PKMNSITEMDEFROSTEDIT,
    [B_MSG_CURED_FROSTBITE] = STRINGID_PKMNSITEMHEALEDFROSTBITE,
    [B_MSG_CURED_SLEEP] = STRINGID_PKMNSITEMWOKEIT,
    [B_MSG_CURED_CONFUSION] = STRINGID_PKMNSITEMSNAPPEDOUT,
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEITINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]   = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]   = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL]  = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL]  = STRINGID_PKMNBOXLANETTESPCFULL,
    [B_MSG_SWAPPED_INTO_PARTY] = STRINGID_PKMNSENTTOPCAFTERCATCH,
};

const u16 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u16 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP, STRINGID_PKMNGOTFROSTBITE
};

const u16 gDamageNonTypesStartStringIds[] =
{
    [B_MSG_TRAPPED_WITH_VINES]  = STRINGID_TEAMTRAPPEDWITHVINES,
    [B_MSG_CAUGHT_IN_VORTEX]    = STRINGID_TEAMCAUGHTINVORTEX,
    [B_MSG_SURROUNDED_BY_FIRE]  = STRINGID_TEAMSURROUNDEDBYFIRE,
    [B_MSG_SURROUNDED_BY_ROCKS] = STRINGID_TEAMSURROUNDEDBYROCKS,
};

const u16 gDamageNonTypesDmgStringIds[] =
{
    [B_MSG_HURT_BY_VINES]        = STRINGID_PKMNHURTBYVINES,
    [B_MSG_HURT_BY_VORTEX]       = STRINGID_PKMNHURTBYVORTEX,
    [B_MSG_BURNING_UP]           = STRINGID_PKMNBURNINGUP,
    [B_MSG_HURT_BY_ROCKS_THROWN] = STRINGID_PKMNHURTBYROCKSTHROWN,
};

const u16 gRemoveHazardsStringIds[] =
{
    [HAZARDS_SPIKES] = STRINGID_SPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STICKY_WEB] = STRINGID_STICKYWEBDISAPPEAREDFROMTEAM,
    [HAZARDS_TOXIC_SPIKES] = STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STEALTH_ROCK] = STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM,
    [HAZARDS_STEELSURGE] = STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM,
};

const u16 gZenModeStringIds[] =
{
    [B_MSG_ZEN_MODE_TRIGGERED] = STRINGID_ZENMODETRIGGERED,
    [B_MSG_ZEN_MODE_ENDED] = STRINGID_ZENMODEENDED
};

const u16 gCureStatusStringIds[] =
{
    [B_MSG_CURED_PARALYSIS] = STRINGID_SCRCUREDPARALYSIS,
    [B_MSG_CURED_POISON] = STRINGID_SCRCUREDPOISON,
    [B_MSG_CURED_BURN] = STRINGID_SCRCUREDBURN,
    [B_MSG_CURED_SLEEP] = STRINGID_SCRCUREDSLEEP,
    [B_MSG_CURED_FREEZE] = STRINGID_PKMNWASDEFROSTED,
    [B_MSG_CURED_FROSTBITE] = STRINGID_PKMNFROSTBITEHEALED,
    [B_MSG_CURED_CONFUSION] = STRINGID_SCRCUREDCONFUSION,
    [B_MSG_CURED_INFATUATION] = STRINGID_PKMNGOTOVERITSINFATUATION,
    [B_MSG_CURED_TAUNT] = STRINGID_PKMNSHOOKOFFTHETAUNT,
};

const u16 gPartyCureStatusStringIds[] =
{
    [B_MSG_CURED_PARALYSIS] = STRINGID_PARTYCUREDPARALYSIS,
    [B_MSG_CURED_POISON] = STRINGID_PARTYCUREDPOISON,
    [B_MSG_CURED_BURN] = STRINGID_PARTYCUREDBURN,
    [B_MSG_CURED_SLEEP] = STRINGID_PARTYCUREDSLEEP,
    [B_MSG_CURED_FREEZE] = STRINGID_PARTYCUREDFREEZE,
    [B_MSG_CURED_FROSTBITE] = STRINGID_PARTYCUREDFROSTBITE,
    [B_MSG_CURED_CONFUSION] = STRINGID_SCRCUREDCONFUSION,
    [B_MSG_CURED_INFATUATION] = STRINGID_PKMNGOTOVERITSINFATUATION,
    [B_MSG_CURED_TAUNT] = STRINGID_PKMNSHOOKOFFTHETAUNT,
};

const u16 gHurtByStringIds[] =
{
    [B_MSG_HURT] = STRINGID_AFTERMATHDMG,
    [B_MSG_HURT_BY_ITEM] = STRINGID_PKMNHURTSWITH,
};

const u16 gBreakScreensStringIds[] =
{
    [B_MSG_BREAK_REFLECT] = STRINGID_REFLECTWOREOFF,
    [B_MSG_BREAK_LIGHT_SCREEN] = STRINGID_LIGHTSCREENWOREOFF,
    [B_MSG_BREAK_AURORA_VEIL] = STRINGID_AURORAVEILWOREOFF,
};

const u8 gText_PkmnIsEvolving[] = _("What?\n{STR_VAR_1} is evolving!");
static const u8 sText_PkmnIsEvolvingPt[] = _("O quê?\n{STR_VAR_1} está evoluindo!");
static const u8 sText_PkmnIsEvolvingEs[] = _("¿Qué?\n¡{STR_VAR_1} está evolucionando!");
const u8 gText_CongratsPkmnEvolved[] = _("Congratulations! Your {STR_VAR_1}\nevolved into {STR_VAR_2}!{WAIT_SE}\p");
static const u8 sText_CongratsPkmnEvolvedPt[] = _("Parabéns! Seu {STR_VAR_1}\nevoluiu para {STR_VAR_2}!{WAIT_SE}\p");
static const u8 sText_CongratsPkmnEvolvedEs[] = _("¡Felicidades! ¡Tu {STR_VAR_1}\nevolucionó a {STR_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("Huh? {STR_VAR_1}\nstopped evolving!\p");
static const u8 sText_PkmnStoppedEvolvingPt[] = _("Hã? {STR_VAR_1}\nparou de evoluir!\p");
static const u8 sText_PkmnStoppedEvolvingEs[] = _("¿Eh? ¡{STR_VAR_1}\ndejó de evolucionar!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("What will\n{B_BUFF1} do?");
static const u8 sText_WhatWillPkmnDoPt[] = _("O que\n{B_BUFF1} fará?");
static const u8 sText_WhatWillPkmnDoEs[] = _("¿Qué hará\n{B_BUFF1}?");
const u8 gText_WhatWillPkmnDo2[] = _("What will\n{B_PLAYER_NAME} do?");
static const u8 sText_WhatWillPkmnDo2Pt[] = _("O que\n{B_PLAYER_NAME} fará?");
static const u8 sText_WhatWillPkmnDo2Es[] = _("¿Qué hará\n{B_PLAYER_NAME}?");
const u8 gText_WhatWillWallyDo[] = _("What will\nWALLY do?");
static const u8 sText_WhatWillWallyDoPt[] = _("O que\nWALLY fará?");
static const u8 sText_WhatWillWallyDoEs[] = _("¿Qué hará\nWALLY?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Link standby…");
static const u8 sText_LinkStandbyPt[] = _("{PAUSE 16}Aguardando conexão…");
static const u8 sText_LinkStandbyEs[] = _("{PAUSE 16}Esperando conexión…");
const u8 gText_BattleMenu[] = _("Battle{CLEAR_TO 56}Bag\nPokémon{CLEAR_TO 56}Run");
static const u8 sText_BattleMenuPt[] = _("Lutar{CLEAR_TO 56}Mochila\nPokémon{CLEAR_TO 56}Fugir");
static const u8 sText_BattleMenuEs[] = _("Luchar{CLEAR_TO 56}Mochila\nPokémon{CLEAR_TO 56}Huir");
const u8 gText_SafariZoneMenu[] = _("Ball{CLEAR_TO 56}{POKEBLOCK}\nGo Near{CLEAR_TO 56}Run");
const u8 gText_SafariZoneMenuFrlg[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}BALL{CLEAR_TO 56}BAIT\nROCK{CLEAR_TO 56}RUN");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TYPE/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}PP\nTYPE/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}Which move should\nbe forgotten?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}Yes\nNo");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}Switch\nwhich?");

const u8 *GetText_PkmnIsEvolving(void)
{
    return ChooseBattleText(gText_PkmnIsEvolving, sText_PkmnIsEvolvingPt, sText_PkmnIsEvolvingEs);
}

const u8 *GetText_CongratsPkmnEvolved(void)
{
    return ChooseBattleText(gText_CongratsPkmnEvolved, sText_CongratsPkmnEvolvedPt, sText_CongratsPkmnEvolvedEs);
}

const u8 *GetText_PkmnStoppedEvolving(void)
{
    return ChooseBattleText(gText_PkmnStoppedEvolving, sText_PkmnStoppedEvolvingPt, sText_PkmnStoppedEvolvingEs);
}

const u8 *GetText_WhatWillPkmnDo(void)
{
    return ChooseBattleText(gText_WhatWillPkmnDo, sText_WhatWillPkmnDoPt, sText_WhatWillPkmnDoEs);
}

const u8 *GetText_WhatWillPkmnDo2(void)
{
    return ChooseBattleText(gText_WhatWillPkmnDo2, sText_WhatWillPkmnDo2Pt, sText_WhatWillPkmnDo2Es);
}

const u8 *GetText_WhatWillWallyDo(void)
{
    return ChooseBattleText(gText_WhatWillWallyDo, sText_WhatWillWallyDoPt, sText_WhatWillWallyDoEs);
}

const u8 *GetText_LinkStandby(void)
{
    return ChooseBattleText(gText_LinkStandby, sText_LinkStandbyPt, sText_LinkStandbyEs);
}

const u8 *GetText_BattleMenu(void)
{
    return ChooseBattleText(gText_BattleMenu, sText_BattleMenuPt, sText_BattleMenuEs);
}

const u8 *GetText_PkmnShroudedInMist(void)
{
    return ChooseBattleText(gText_PkmnShroudedInMist, sText_PkmnShroudedInMistPt, sText_PkmnShroudedInMistEs);
}

const u8 *GetText_PkmnGettingPumped(void)
{
    return ChooseBattleText(gText_PkmnGettingPumped, sText_PkmnGettingPumpedPt, sText_PkmnGettingPumpedEs);
}

const u8 *GetText_PkmnsXPreventsSwitching(void)
{
    return ChooseBattleText(gText_PkmnsXPreventsSwitching, sText_PkmnsXPreventsSwitchingPt, sText_PkmnsXPreventsSwitchingEs);
}

const u8 *GetText_StatSharply(void)
{
    return ChooseBattleText(gText_StatSharply, sText_StatSharplyPt, sText_StatSharplyEs);
}

const u8 *GetText_StatRose(void)
{
    return ChooseBattleText(gText_StatRose, sText_StatRosePt, sText_StatRoseEs);
}

const u8 *GetText_StatFell(void)
{
    return ChooseBattleText(gText_StatFell, sText_StatFellPt, sText_StatFellEs);
}

const u8 *GetText_DefendersStatRose(void)
{
    return ChooseBattleText(gText_DefendersStatRose, sText_DefendersStatRosePt, sText_DefendersStatRoseEs);
}

const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");
const u8 gText_SafariBalls[] = _("Safari Balls");
const u8 gText_SafariBallLeft[] = _("Left: $");
const u8 gText_Sleep[] = _("sleep");
const u8 gText_Poison[] = _("poison");
const u8 gText_Burn[] = _("burn");
const u8 gText_Paralysis[] = _("paralysis");
const u8 gText_Ice[] = _("ice");
const u8 gText_Confusion[] = _("confusion");
const u8 gText_Love[] = _("love");
const u8 gText_SpaceAndSpace[] = _(" and ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("are");
const u8 gText_Are2[] = _("are");
const u8 gText_BadEgg[] = _("Bad Egg");
const u8 gText_BattleWallyName[] = _("WALLY");
const u8 gText_Win[] = _("{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}Win");
const u8 gText_Loss[] = _("{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}Loss");
const u8 gText_Draw[] = _("{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}Draw");
static const u8 sText_SpaceIs[] = _(" is");
static const u8 sText_ApostropheS[] = _("'s");
const u8 gText_BattleTourney[] = _("BATTLE TOURNEY");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = COMPOUND_STRING("Round 1"),
    [DOME_ROUND2]    = COMPOUND_STRING("Round 2"),
    [DOME_SEMIFINAL] = COMPOUND_STRING("Semifinal"),
    [DOME_FINAL]     = COMPOUND_STRING("Final"),
};

const u8 gText_TheGreatNewHope[] = _("The great new hope!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("Will the championship dream come true?!\p");
const u8 gText_AFormerChampion[] = _("A former champion!\p");
const u8 gText_ThePreviousChampion[] = _("The previous champion!\p");
const u8 gText_TheUnbeatenChampion[] = _("The unbeaten champion!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mind");
const u8 gText_Skill[] = _("Skill");
const u8 gText_Body[] = _("Body");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}Judgment{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} sent out {B_OPPONENT_MON1_NAME}!\p{B_TRAINER2_NAME_WITH_CLASS} sent out {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer2SentOutPkmn[] = _("{B_TRAINER2_NAME_WITH_CLASS} sent out {B_BUFF1}!");
static const u8 sText_TwoTrainersWantToBattle[] = _("You are challenged by {B_TRAINER1_NAME_WITH_CLASS} and {B_TRAINER2_NAME_WITH_CLASS}!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{B_PARTNER_NAME_WITH_CLASS} sent out {B_PLAYER_MON2_NAME}! Go, {B_PLAYER_MON1_NAME}!");
static const u8 sText_InGamePartnerSentOutNGoZ[] = _("{B_PARTNER_NAME_WITH_CLASS} sent out {B_PLAYER_MON1_NAME}! Go, {B_PLAYER_MON2_NAME}!");
static const u8 sText_InGamePartnerSentOutPkmn1[] = _("{B_PARTNER_NAME_WITH_CLASS} sent out {B_PLAYER_MON1_NAME}!");
static const u8 sText_InGamePartnerSentOutPkmn2[] = _("{B_PARTNER_NAME_WITH_CLASS} sent out {B_PLAYER_MON2_NAME}!");
static const u8 sText_InGamePartnerWithdrewPkmn1[] = _("{B_PARTNER_NAME_WITH_CLASS} withdrew {B_PLAYER_MON1_NAME}!");
static const u8 sText_InGamePartnerWithdrewPkmn2[] = _("{B_PARTNER_NAME_WITH_CLASS} withdrew {B_PLAYER_MON2_NAME}!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

const u8 *const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = COMPOUND_STRING("REFEREE: If nothing is decided in 3 turns, we will go to judging!"),
    [B_MSG_REF_THATS_IT]           = COMPOUND_STRING("REFEREE: That's it! We will now go to judging to determine the winner!"),
    [B_MSG_REF_JUDGE_MIND]         = COMPOUND_STRING("REFEREE: Judging category 1, Mind! The POKéMON showing the most guts!\p"),
    [B_MSG_REF_JUDGE_SKILL]        = COMPOUND_STRING("REFEREE: Judging category 2, Skill! The POKéMON using moves the best!\p"),
    [B_MSG_REF_JUDGE_BODY]         = COMPOUND_STRING("REFEREE: Judging category 3, Body! The POKéMON with the most vitality!\p"),
    [B_MSG_REF_PLAYER_WON]         = COMPOUND_STRING("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}! The winner is {B_PLAYER_NAME}'s {B_PLAYER_MON1_NAME}!\p"),
    [B_MSG_REF_OPPONENT_WON]       = COMPOUND_STRING("REFEREE: Judgment: {B_BUFF1} to {B_BUFF2}! The winner is {B_TRAINER1_NAME}'s {B_OPPONENT_MON1_NAME}!\p"),
    [B_MSG_REF_DRAW]               = COMPOUND_STRING("REFEREE: Judgment: 3 to 3! We have a draw!\p"),
    [B_MSG_REF_COMMENCE_BATTLE]    = COMPOUND_STRING("REFEREE: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}! Commence battling!"),
};

static const u8 sText_Trainer1Fled[] = _( "{PLAY_SE SE_FLEE}{B_TRAINER1_NAME_WITH_CLASS} fled!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("You lost to {B_TRAINER1_NAME_WITH_CLASS}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("You battled to a draw against {B_TRAINER1_NAME_WITH_CLASS}!");
const u8 gText_RecordBattleToPass[] = _("Would you like to record your battle\non your Frontier Pass?");
const u8 gText_BattleRecordedOnPass[] = _("{B_PLAYER_NAME}'s battle result was recorded\non the Frontier Pass.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("You are challenged by {B_LINK_OPPONENT1_NAME}!\p");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("You are challenged by {B_LINK_OPPONENT1_NAME} and {B_LINK_OPPONENT2_NAME}!\p");
static const u8 sText_Your1[] = _("Your");
static const u8 sText_Opposing1[] = _("The opposing");
static const u8 sText_Your2[] = _("your");
static const u8 sText_Opposing2[] = _("the opposing");
static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_KantoTutorial[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_OAK_OLD_MAN] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena,
    [B_WIN_TYPE_KANTO_TUTORIAL] = sTextOnWindowsInfo_KantoTutorial,
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(enum StringID stringID, enum BattlerId battler)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleResources->bufferA[battler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->scriptPartyIdx = gBattleMsgDataPtr->bakScriptPartyIdx;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                    {
                        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                            stringPtr = sText_LinkTrainerWantsToBattle;
                        else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                            stringPtr = sText_TwoTrainersWantToBattle;
                        else if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
                            stringPtr = sText_LinkTrainerWantsToBattlePause;
                        else
                            stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    }
                    else
                    {
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                    }
                }
                else
                {
                    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                        stringPtr = ChooseBattleText(sText_Trainer1WantsToBattle, sText_Trainer1WantsToBattlePt, sText_Trainer1WantsToBattleEs);
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = ChooseBattleText(sText_Trainer1WantsToBattle, sText_Trainer1WantsToBattlePt, sText_Trainer1WantsToBattleEs);
                else if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = ChooseBattleText(sText_Trainer1WantsToBattle, sText_Trainer1WantsToBattlePt, sText_Trainer1WantsToBattleEs);
            }
        }
        else
        {
            if (IsGhostBattleWithoutScope())
                stringPtr = sText_GhostAppearedCantId;
            else if (gBattleTypeFlags & BATTLE_TYPE_GHOST)
                stringPtr = sText_TheGhostAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))))
                stringPtr = ChooseBattleText(sText_TwoWildPkmnAppeared, sText_TwoWildPkmnAppearedPt, sText_TwoWildPkmnAppearedEs);
            else if (gBattleTypeFlags & BATTLE_TYPE_CATCH_TUTORIAL)
                stringPtr = ChooseBattleText(sText_WildPkmnAppearedPause, sText_WildPkmnAppearedPausePt, sText_WildPkmnAppearedPauseEs);
            else
                stringPtr = ChooseBattleText(sText_WildPkmnAppeared, sText_WildPkmnAppearedPt, sText_WildPkmnAppearedEs);
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (BattlerIsPlayer(battler) || BattlerIsPlayer(BATTLE_PARTNER(battler))
         || BattlerIsWally(battler) || BattlerIsWally(BATTLE_PARTNER(battler)))
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(BATTLE_PARTNER(battler))))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI && (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK || gBattleTypeFlags & BATTLE_TYPE_LINK))
                {
                    if (BattlerIsPlayer(battler))
                        stringPtr = sText_LinkPartnerSentOutPkmn2GoPkmn; // Player is on left
                    else
                        stringPtr = sText_LinkPartnerSentOutPkmn1GoPkmn; // Link Partner on left
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                {
                    if (BattlerIsPlayer(battler) && (battler & BIT_FLANK) == B_FLANK_LEFT)
                        stringPtr = sText_InGamePartnerSentOutZGoN; // Player is on left
                    else
                        stringPtr = sText_InGamePartnerSentOutNGoZ; // Partner on left
                }
                else
                {
                    stringPtr = sText_GoTwoPkmn;
                }
            }
            else
            {
                stringPtr = ChooseBattleText(sText_GoPkmn, sText_GoPkmnPt, sText_GoPkmnEs);
            }
        }
        else
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(BATTLE_PARTNER(battler))))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
                else if ((gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) || (gBattleTypeFlags & BATTLE_TYPE_MULTI && (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK || gBattleTypeFlags & BATTLE_TYPE_LINK)))
                    stringPtr = sText_TwoLinkTrainersIntroSendOutPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS || gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (BattlerIsLink(battler) || (BattlerIsRecorded(battler) && BattlerIsOpponent(battler))) // Link Opponent doubles and test opponent
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = ChooseBattleText(sText_Trainer1SentOutTwoPkmn, sText_Trainer1SentOutTwoPkmnPt, sText_Trainer1SentOutTwoPkmnEs);
            }
            else if (BattlerIsLink(battler) || (BattlerIsRecorded(battler) && BattlerIsOpponent(battler)))
            {
                if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerIntroSendOutPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1SentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if ((GetBattlerPosition(battler) & BIT_FLANK) == B_FLANK_LEFT) // battler 0 and 1
        {
            if (BattlerIsPlayer(battler) || BattlerIsWally(battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_PkmnThatsEnough;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_PkmnComeBack;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_PkmnOkComeBack;
                else
                    stringPtr = sText_PkmnGoodComeBack;
            }
            else if (BattlerIsPartner(battler)) // Link or Ingame Partner
            {
                if (BattlerIsLink(battler) || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                    stringPtr = sText_LinkPartnerWithdrewPkmn1;
                else
                    stringPtr = sText_InGamePartnerWithdrewPkmn1;
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
             || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent A and test opponent
            {
                stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        else // battler 2 and 3
        {
            if (BattlerIsPlayer(battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_PkmnThatsEnough;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_PkmnComeBack;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_PkmnOkComeBack;
                else
                    stringPtr = sText_PkmnGoodComeBack;
            }
            else if (BattlerIsPartner(battler)) // Link or Ingame Partner
            {
                if (BattlerIsLink(battler) || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                    stringPtr = sText_LinkPartnerWithdrewPkmn2;
                else
                    stringPtr = sText_InGamePartnerWithdrewPkmn2;
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
             || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent B and test opponent
            {
                if (BattleSideHasTwoTrainers(B_SIDE_OPPONENT))
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) // Opponent B
            {
                stringPtr = sText_Trainer2WithdrewPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if ((GetBattlerPosition(gBattleScripting.battler) & BIT_FLANK) == B_FLANK_LEFT) // battler 0 and 1
        {
            if (BattlerIsPlayer(gBattleScripting.battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = ChooseBattleText(sText_GoPkmn2, sText_GoPkmn2Pt, sText_GoPkmn2Es);
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_DoItPkmn;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_GoForItPkmn;
                else
                    stringPtr = sText_YourFoesWeakGetEmPkmn;
            }
            else if (BattlerIsPartner(gBattleScripting.battler)) // Link or Ingame Partner
            {
                if (BattlerIsLink(gBattleScripting.battler) || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                    stringPtr = sText_LinkPartnerSentOutPkmn1;
                else
                    stringPtr = sText_InGamePartnerSentOutPkmn1;
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
             || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent A and test opponent
            {
                stringPtr = sText_LinkTrainerSentOutPkmn;
            }
            else // Opponent A
            {
                stringPtr = ChooseBattleText(sText_Trainer1SentOutPkmn, sText_Trainer1SentOutPkmnPt, sText_Trainer1SentOutPkmnEs);
            }
        }
        else // battler 2 and 3
        {
            if (BattlerIsPlayer(gBattleScripting.battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_GoPkmn2;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_DoItPkmn;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_GoForItPkmn;
                else
                    stringPtr = sText_YourFoesWeakGetEmPkmn;
            }
            else if (BattlerIsPartner(gBattleScripting.battler)) // Link or Ingame Partner
            {
                if (BattlerIsLink(gBattleScripting.battler) || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                    stringPtr = sText_LinkPartnerSentOutPkmn2;
                else
                    stringPtr = sText_InGamePartnerSentOutPkmn2;
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
             || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent B and test opponent
            {
                if (BattleSideHasTwoTrainers(B_SIDE_OPPONENT))
                    stringPtr = sText_LinkTrainer2SentOutPkmn2;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn2;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) // Opponent B
            {
                stringPtr = sText_Trainer2SentOutPkmn;
            }
            else // Single trainer double Opponent A
            {
                stringPtr = ChooseBattleText(sText_Trainer1SentOutPkmn2, sText_Trainer1SentOutPkmn2Pt, sText_Trainer1SentOutPkmn2Es);
            }
        }
        break;
    case STRINGID_USEDMOVE: // Pokémon used a move msg
        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
         && !IsZMove(gBattleMsgDataPtr->currentMove)
         && !IsMaxMove(gBattleMsgDataPtr->currentMove))
            StringCopy(gBattleTextBuff3, gTypesInfo[*(&gBattleStruct->stringMoveType)].generic);
        else
            StringCopy(gBattleTextBuff3, GetMoveName(gBattleMsgDataPtr->currentMove));
        stringPtr = ChooseBattleText(sText_AttackerUsedX, sText_AttackerUsedXPt, sText_AttackerUsedXEs);
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (!(BattlerIsPlayer(battler) || BattlerIsPlayer(BATTLE_PARTNER(battler))) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = ChooseBattleText(sText_GotAwaySafely, sText_GotAwaySafelyPt, sText_GotAwaySafelyEs);
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = ChooseBattleText(sText_TwoWildFled, sText_TwoWildFledPt, sText_TwoWildFledEs);
            else
                stringPtr = ChooseBattleText(sText_WildFled, sText_WildFledPt, sText_WildFledEs);
        }
        else
        {
            if (!(BattlerIsPlayer(battler) || BattlerIsPlayer(BATTLE_PARTNER(battler))) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = ChooseBattleText(sText_TwoLinkTrainersDefeated, sText_TwoLinkTrainersDefeatedPt, sText_TwoLinkTrainersDefeatedEs);
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = ChooseBattleText(sText_PlayerLostToTwo, sText_PlayerLostToTwoPt, sText_PlayerLostToTwoEs);
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = ChooseBattleText(sText_PlayerBattledToDrawVsTwo, sText_PlayerBattledToDrawVsTwoPt, sText_PlayerBattledToDrawVsTwoEs);
                    break;
                }
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = ChooseBattleText(sText_PlayerDefeatedLinkTrainerTrainer1, sText_PlayerDefeatedLinkTrainerTrainer1Pt, sText_PlayerDefeatedLinkTrainerTrainer1Es);
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = ChooseBattleText(sText_PlayerDefeatedLinkTrainer, sText_PlayerDefeatedLinkTrainerPt, sText_PlayerDefeatedLinkTrainerEs);
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = ChooseBattleText(sText_PlayerLostAgainstLinkTrainer, sText_PlayerLostAgainstLinkTrainerPt, sText_PlayerLostAgainstLinkTrainerEs);
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = ChooseBattleText(sText_PlayerBattledToDrawLinkTrainer, sText_PlayerBattledToDrawLinkTrainerPt, sText_PlayerBattledToDrawLinkTrainerEs);
                    break;
                }
            }
        }
        break;
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default: // load a string from the table
        if (stringID >= STRINGID_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = GetBattleString(stringID);
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
#ifndef NDEBUG
    u32 j, strWidth;
    u32 dstID = BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
    for (j = 1;; j++)
    {
        strWidth = GetStringLineWidth(0, gDisplayedStringBattle, 0, j, sizeof(gDisplayedStringBattle));
        if (strWidth == 0)
            break;
    }
    return dstID;
#else
    return BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
#endif
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

static void GetBattlerNick(enum BattlerId battler, u8 *dst)
{
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    struct Pokemon *mon = GetBattlerMon(battler);

    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

#define HANDLE_NICKNAME_STRING_CASE(battler)                            \
    if (!IsOnPlayerSide(battler))                                       \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = ChooseBattleText(sText_FoePkmnPrefix, sText_FoePkmnPrefixPt, sText_FoePkmnPrefixEs);                                \
        else                                                            \
            toCpy = ChooseBattleText(sText_WildPkmnPrefix, sText_WildPkmnPrefixPt, sText_WildPkmnPrefixEs);                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battler, text);                                      \
    toCpy = text;

#define HANDLE_NICKNAME_STRING_LOWERCASE(battler)                       \
    if (!IsOnPlayerSide(battler))                       \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = ChooseBattleText(sText_FoePkmnPrefixLower, sText_FoePkmnPrefixLowerPt, sText_FoePkmnPrefixLowerEs);                           \
        else                                                            \
            toCpy = ChooseBattleText(sText_WildPkmnPrefixLower, sText_WildPkmnPrefixLowerPt, sText_WildPkmnPrefixLowerEs);                          \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battler, text);                                      \
    toCpy = text;

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId, u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u32 i;
        for (i = 0; i < ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
            text[i] = gBattleResources->secretBase->trainerName[i];
        text[i] = EOS;
        ConvertInternationalString(text, gBattleResources->secretBase->language);
        toCpy = text;
    }
    else if (trainerId == TRAINER_UNION_ROOM)
    {
        toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_LINK_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler)].name;
        else
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler) & BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        GetFrontierTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
    {
        GetTrainerTowerOpponentName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        GetTrainerHillTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        GetEreaderTrainerName(text);
        toCpy = text;
    }
    else
    {
        enum TrainerClassID trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);

        if (trainerClass == TRAINER_CLASS_RIVAL)
            toCpy = GetExpandedPlaceholder(PLACEHOLDER_ID_RIVAL);
        else
            toCpy = GetTrainerNameFromId(trainerId);
    }

    assertf(DoesStringProperlyTerminate(toCpy, TRAINER_NAME_LENGTH + 1),"Opponent needs a valid name")
    {
        return sText_EmptyString4;
    }

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_OPPONENT_LEFT:
        toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    case B_POSITION_OPPONENT_RIGHT:
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT)
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, battler);
        else
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    default:
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetPlayerName(u8 *text, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_PLAYER_LEFT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            toCpy = gLinkPlayers[0].name;
        else
            toCpy = gSaveBlock2Ptr->playerName;
        break;
    case B_POSITION_PLAYER_RIGHT:
        if (((gBattleTypeFlags & BATTLE_TYPE_RECORDED) && !(gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)))
            || gTestRunnerEnabled)
        {
            toCpy = gLinkPlayers[0].name;
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_MULTI))
        {
            toCpy = gLinkPlayers[2].name;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            GetFrontierTrainerName(text, gPartnerTrainerId);
            toCpy = text;
        }
        else
        {
            toCpy = gSaveBlock2Ptr->playerName;
        }
        break;
    default:
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    if (IsOnPlayerSide(battler))
        return BattleStringGetPlayerName(text, battler);
    else
        return BattleStringGetOpponentName(text, multiplayerId, battler);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
        toCpy = gTrainerClasses[GetSecretBaseTrainerClass()].name;
    else if (trainerId == TRAINER_UNION_ROOM)
        toCpy = gTrainerClasses[GetUnionRoomTrainerClass()].name;
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        toCpy = gTrainerClasses[GetFrontierBrainTrainerClass()].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        toCpy = gTrainerClasses[GetFrontierOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
        toCpy = gTrainerClasses[GetTrainerTowerOpponentClass()].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        toCpy = gTrainerClasses[GetTrainerHillOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
        toCpy = gTrainerClasses[GetEreaderTrainerClassId()].name;
    else if (trainerId == TRAINER_LINK_OPPONENT)
        toCpy = gTrainerClasses[TRAINER_NONE].name;
    else
        toCpy = gTrainerClasses[GetTrainerClassFromId(trainerId)].name;

    return toCpy;
}

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst, u32 dstSize)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 *textStart = &text[0];
    u8 multiplayerId;
    u8 fontId = FONT_NORMAL;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    // Clear destination first
    while (dstID < dstSize)
    {
        dst[dstID] = EOS;
        dstID++;
    }

    dstID = 0;
    while (*src != EOS)
    {
        toCpy = NULL;

        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            u32 classLength = 0;
            u32 nameLength = 0;
            const u8 *classString;
            const u8 *nameString;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                {
                    toCpy = gBattleTextBuff2;
                }
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                {
                    toCpy = gBattleTextBuff3;
                }
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // Unused, to change into sth else.
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(BATTLE_PARTNER(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_DEF_PARTNER_NAME: // partner target name
                GetBattlerNick(BATTLE_PARTNER(gBattlerTarget), text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->currentMove);
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->originallyUsedMove);
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY_E_READER)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = GetAbilityName(gLastUsedAbility);
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = GetAbilityName(sBattlerAbilities[gBattlerAttacker]);
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = GetAbilityName(sBattlerAbilities[gBattlerTarget]);
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = GetAbilityName(sBattlerAbilities[gBattleScripting.battler]);
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = GetAbilityName(sBattlerAbilities[gEffectBattler]);
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                break;
            case B_TXT_TRAINER1_NAME_WITH_CLASS: // trainer1 name with trainer class
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(LEFT_FOE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(RIGHT_FOE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentLoseText(gStringVar4, 0);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentWinText(gStringVar4, 0);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerWonSpeech();
                }
                break;
            case B_TXT_26: // ?
                if (!IsOnPlayerSide(gBattleScripting.battler))
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = ChooseBattleText(sText_FoePkmnPrefix, sText_FoePkmnPrefixPt, sText_FoePkmnPrefixEs);
                    else
                        toCpy = ChooseBattleText(sText_WildPkmnPrefix, sText_WildPkmnPrefixPt, sText_WildPkmnPrefixEs);
                    while (*toCpy != EOS)
                    {
                        dst[dstID] = *toCpy;
                        dstID++;
                        toCpy++;
                    }
                }
                GetMonData(&GetBattlerParty(gBattleScripting.battler)[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = IS_FRLG ? sText_Bills : sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = ChooseBattleText(sText_AllyPkmnPrefix2, sText_AllyPkmnPrefix2Pt, sText_AllyPkmnPrefix2Es);
                else
                    toCpy = ChooseBattleText(sText_FoePkmnPrefix3, sText_FoePkmnPrefix3Pt, sText_FoePkmnPrefix3Es);
                break;
            case B_TXT_DEF_PREFIX2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = ChooseBattleText(sText_AllyPkmnPrefix2, sText_AllyPkmnPrefix2Pt, sText_AllyPkmnPrefix2Es);
                else
                    toCpy = ChooseBattleText(sText_FoePkmnPrefix3, sText_FoePkmnPrefix3Pt, sText_FoePkmnPrefix3Es);
                break;
            case B_TXT_ATK_PREFIX1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = ChooseBattleText(sText_AllyPkmnPrefix, sText_AllyPkmnPrefixPt, sText_AllyPkmnPrefixEs);
                else
                    toCpy = ChooseBattleText(sText_FoePkmnPrefix2, sText_FoePkmnPrefix2Pt, sText_FoePkmnPrefix2Es);
                break;
            case B_TXT_DEF_PREFIX1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = ChooseBattleText(sText_AllyPkmnPrefix, sText_AllyPkmnPrefixPt, sText_AllyPkmnPrefixEs);
                else
                    toCpy = ChooseBattleText(sText_FoePkmnPrefix2, sText_FoePkmnPrefix2Pt, sText_FoePkmnPrefix2Es);
                break;
            case B_TXT_ATK_PREFIX3:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = ChooseBattleText(sText_AllyPkmnPrefix3, sText_AllyPkmnPrefix3Pt, sText_AllyPkmnPrefix3Es);
                else
                    toCpy = ChooseBattleText(sText_FoePkmnPrefix4, sText_FoePkmnPrefix4Pt, sText_FoePkmnPrefix4Es);
                break;
            case B_TXT_DEF_PREFIX3:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = ChooseBattleText(sText_AllyPkmnPrefix3, sText_AllyPkmnPrefix3Pt, sText_AllyPkmnPrefix3Es);
                else
                    toCpy = ChooseBattleText(sText_FoePkmnPrefix4, sText_FoePkmnPrefix4Pt, sText_FoePkmnPrefix4Es);
                break;
            case B_TXT_TRAINER2_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                break;
            case B_TXT_TRAINER2_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                break;
            case B_TXT_TRAINER2_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentLoseText(gStringVar4, 1);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentWinText(gStringVar4, 1);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                break;
            case B_TXT_PARTNER_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetPlayerName(textStart, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(text, multiplayerId, gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (GetBattlerPosition(gBattlerAttacker))
                {
                case B_POSITION_PLAYER_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                        toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                    break;
                case B_POSITION_OPPONENT_LEFT:
                    toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                case B_POSITION_OPPONENT_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                    else
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                default:
                    break;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME_WITH_CLASS:
                toCpy = textStart;
                if (GetBattlerPosition(gBattlerAttacker) == B_POSITION_PLAYER_LEFT)
                {
                    textStart = StringCopy(textStart, BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker));
                }
                else
                {
                    classString = NULL;
                    switch (GetBattlerPosition(gBattlerAttacker))
                    {
                    case B_POSITION_PLAYER_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                            classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                        break;
                    case B_POSITION_OPPONENT_LEFT:
                        classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    case B_POSITION_OPPONENT_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                        else
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    default:
                        break;
                    }
                    classLength = 0;
                    nameLength = 0;
                    while (classString[classLength] != EOS)
                    {
                        textStart[classLength] = classString[classLength];
                        classLength++;
                    }
                    textStart[classLength] = CHAR_SPACE;
                    textStart += 1 + classLength;
                    nameString = BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker);
                    if (nameString != textStart)
                    {
                        while (nameString[nameLength] != EOS)
                        {
                            textStart[nameLength] = nameString[nameLength];
                            nameLength++;
                        }
                        textStart[nameLength] = EOS;
                    }
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_EFF_TEAM1:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_EFF_TEAM2:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerTarget)
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattleScripting.battler)
                break;
            }

            if (toCpy != NULL)
            {
                while (*toCpy != EOS)
                {
                    if (*toCpy == CHAR_SPACE)
                        dst[dstID] = CHAR_NBSP;
                    else
                        dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    BreakStringAutomatic(dst, BATTLE_MSG_MAX_WIDTH, BATTLE_MSG_MAX_LINES, fontId, SHOW_SCROLL_PROMPT);

    return dstID;
}

static void IllusionNickHack(enum BattlerId battler, u32 partyId, u8 *dst)
{
    u32 id = PARTY_SIZE;
    struct Pokemon *party = GetBattlerParty(battler);
    struct Pokemon *mon = &party[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(battler)))
            partnerMon = GetBattlerMon(BATTLE_PARTNER(battler));
        else
            partnerMon = mon;

        id = GetIllusionMonPartyId(party, mon, partnerMon, battler);
    }

    if (id != PARTY_SIZE)
        GetMonData(&party[id], MON_DATA_NICKNAME, dst);
    else
        GetMonData(mon, MON_DATA_NICKNAME, dst);
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, GetBattleString(hword));
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, GetMoveName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypesInfo[src[srcID + 1]].name);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
        case B_BUFF_MON_NICK_WITH_PREFIX_LOWER: // poke nick with lowercase prefix
            if (!IsOnPlayerSide(src[srcID + 1]))
            {
                if (src[srcID] == B_BUFF_MON_NICK_WITH_PREFIX_LOWER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, ChooseBattleText(sText_FoePkmnPrefixLower, sText_FoePkmnPrefixLowerPt, sText_FoePkmnPrefixLowerEs));
                    else
                        StringAppend(dst, ChooseBattleText(sText_WildPkmnPrefixLower, sText_WildPkmnPrefixLowerPt, sText_WildPkmnPrefixLowerEs));
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, ChooseBattleText(sText_FoePkmnPrefix, sText_FoePkmnPrefixPt, sText_FoePkmnPrefixEs));
                    else
                        StringAppend(dst, ChooseBattleText(sText_WildPkmnPrefix, sText_WildPkmnPrefixPt, sText_WildPkmnPrefixEs));
                }
            }
            GetMonData(&GetBattlerParty(src[srcID + 1])[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            StringCopy(dst, GetSpeciesName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGet_Nickname(dst);
            }
            else
            {
                GetMonData(&GetBattlerParty(src[srcID + 1])[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, GetAbilityName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY_E_READER)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.type = WINDOW_TEXT_PRINTER;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.color = textInfo[windowId].color;

    if (B_WIN_MOVE_NAME_1 <= windowId && windowId <= B_WIN_MOVE_NAME_4)
    {
        // We cannot check the actual width of the window because
        // B_WIN_MOVE_NAME_1 and B_WIN_MOVE_NAME_3 are 16 wide for
        // Z-move details.
        if (gBattleStruct->zmove.viewing && windowId == B_WIN_MOVE_NAME_1)
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 16 * TILE_WIDTH);
        else
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 8 * TILE_WIDTH);
    }

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT || windowId == B_WIN_OAK_OLD_MAN)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if ((gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)) || gTestRunnerEnabled || ((gBattleTypeFlags & BATTLE_TYPE_POKEDUDE) && windowId != B_WIN_OAK_OLD_MAN))
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT || windowId == B_WIN_OAK_OLD_MAN)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(enum BattlerId battler)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var;

    if (!gBattleStruct->zmove.viewing)
        var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[battler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[battler]]);
    else
        var = 3;

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}
