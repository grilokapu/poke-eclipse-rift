BattleFrontier_BattlePikeCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeCorridor_OnWarp
	.byte 0

BattleFrontier_BattlePikeCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeCorridor_EventScript_EnterCorridor
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_EnterCorridor::
	delay 16
	frontier_set FRONTIER_DATA_BATTLE_NUM, 1
	pike_cleartrainerids
	pike_nohealing TRUE
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_PlayerEnterCorridor
	applymovement LOCALID_PIKE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePikeCorridor_Movement_AttendantEnterCorridor
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeCorridor_Text_YourChallengeHasBegun, MSGBOX_DEFAULT
	closemessage
	releaseall
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeCorridor_Movement_PlayerExitCorridor
	waitmovement 0
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM, 6, 10
	waitstate
	end

BattleFrontier_BattlePikeCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeCorridor_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeCorridor_Movement_PlayerEnterCorridor:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeCorridor_Movement_PlayerExitCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeCorridor_Movement_AttendantEnterCorridor:
	walk_up
	walk_up
	walk_left
	face_down
	step_end

BattleFrontier_BattlePikeCorridor_Text_YourChallengeHasBegun:
	.string "Your Battle Choice challenge\n"
	.string "has now begun…$"

BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string "Where the luck of TRAINERS\n"
	.string "is put to the test…\p"
	.string "Welcome to the BATTLE PIKE…\p"
	.string "I am your guide to the BATTLE PIKE…$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "Would you like to take the Battle\n"
	.string "Choice challenge?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "Here we conduct an event we call\n"
	.string "the Battle Choice.\p"
	.string "The Battle Choice rules are very\n"
	.string "simple…\p"
	.string "Choose one of three paths and make\n"
	.string "your way to the goal room at the end\l"
	.string "of the BATTLE PIKE. It's that simple.\p"
	.string "However, what happens on the chosen\n"
	.string "path depends entirely on the luck\l"
	.string "of the challenger…\p"
	.string "If you reach the goal, you will be\n"
	.string "rewarded with Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please have a word with\l"
	.string "our staff in the big rooms on the way.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "We look forward to seeing you\n"
	.string "on another occasion…$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "You have the choice of two courses,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which will you challenge?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "I beg your pardon, but…\p"
	.string "You do not have three eligible\n"
	.string "POKéMON for the Battle Choice event.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsEnd:
	.string "Please come see me when\n"
	.string "you are ready…$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "I beg your pardon, but…\p"
	.string "You do not have three eligible\n"
	.string "POKéMON for the Battle Choice event.\p"
	.string "You must have three different\n"
	.string "POKéMON to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "Please choose the three POKéMON\n"
	.string "you wish to enter in the challenge…$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "Before starting your Battle Choice\n"
	.string "challenge, I must save the game.\l"
	.string "Is that acceptable?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "Please step this way…$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "Your challenge has ended…\p"
	.string "I shall record your results.\n"
	.string "Please wait…$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "You have completed the challenge…\p"
	.string "I must say… You seem to possess luck\n"
	.string "in abundance…$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "I shall record your results.\n"
	.string "Please wait…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "To commemorate your completion of\n"
	.string "the Battle Choice challenge, we award\l"
	.string "you these Battle Point(s)…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "You appear to have reached the limit\n"
	.string "for Battle Points…\p"
	.string "Please exchange some Battle Points\n"
	.string "for prizes, then return…$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "I beg your pardon, but…\p"
	.string "You failed to save before you quit\n"
	.string "your challenge the last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. I am sorry…$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "Congratulations…\p"
	.string "You have snatched victory from the\n"
	.string "PIKE QUEEN and cleared the event…$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "In recognition of your amazing luck,\n"
	.string "we award you these Battle Point(s)…$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "Arrgh! I blew my chance!\n"
	.string "I was one room away from the goal!\p"
	.string "In this place, you'd better watch out\n"
	.string "for poison, freezing, and so on.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "I've completed the challenge 10 times\n"
	.string "now, but I've never had to battle\l"
	.string "a TRAINER once.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "Listen! Listen!\p"
	.string "Don't you think that the special\n"
	.string "abilities of POKéMON will be useful\l"
	.string "here?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "What is this weird place?\n"
	.string "I can't figure it out at all!\p"
	.string "I've taken the challenge a bunch\n"
	.string "of times, but all I ever do is run into\l"
	.string "TRAINERS whichever path I choose.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "The Battle Choice's rules are listed.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "Which heading do you want to read?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "The BAG and POKéNAV may not be used\n"
	.string "during a Battle Choice challenge.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "During a Battle Choice challenge,\n"
	.string "any BERRY or HERB held by POKéMON\l"
	.string "will be effective only once.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "During a Battle Choice challenge,\n"
	.string "the sequence of POKéMON cannot be\l"
	.string "changed.\p"
	.string "The sequence must be set before\n"
	.string "starting your challenge.$"

BattleFrontier_BattlePikeThreePathRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeThreePathRoom_OnWarp
	.byte 0

BattleFrontier_BattlePikeThreePathRoom_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_5, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom
	map_script_2 VAR_TEMP_5, 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_OnWarp:
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeThreePathRoom_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_4, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpToLobby::
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume
	waitmessage
	pike_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge, MSGBOX_DEFAULT
	closemessage
	releaseall
	frontier_settrainers
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 99
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_Attendant::
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Room number
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3
	case 5, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5
	case 7, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7
	case 9, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9
	case 11, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11
	case 13, BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom1::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom3::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom5::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom7::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom9::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom11::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AttendantRoom13::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskContinueChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge::
	frontier_saveparty
	message BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData
	waitmessage
	special LoadPlayerParty
	pike_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskSaveChallenge::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_PauseChallenge
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePike_EventScript_Retire
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetHintRoom::
	pike_sethintroom
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_SetPikeQueenHint::
	setvar VAR_TEMP_5, 1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GivePikeQueenHint::
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer
	waitmovement 0
	lockall
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent, MSGBOX_DEFAULT
	releaseall
	applymovement LOCALID_PIKE_HINT_GIVER, BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos
	waitmovement 0
	setvar VAR_TEMP_5, 255
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintGiver::
	pike_gethint
	goto_if_eq VAR_RESULT, PIKE_HINT_BRAIN, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint
	case NO, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_DeclineHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_AcceptHint::
	pike_gethintroomid
	switch VAR_RESULT
	case PIKE_ROOM_LEFT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint
	case PIKE_ROOM_CENTER, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint
	case PIKE_ROOM_RIGHT, BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveLeftRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveCenterRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveRightRoomHint::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveHint::
	pike_gethint
	switch VAR_RESULT
	case PIKE_HINT_NOSTALGIA, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia
	case PIKE_HINT_WHISPERING, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering
	case PIKE_HINT_POKEMON, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon
	case PIKE_HINT_PEOPLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintNostalgia::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintWhispering::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPokemon::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_HintPeople::
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_GiveBrainHint::
	lock
	faceplayer
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverApproachPlayer:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Movement_HintGiverReturnToPos:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom1:
	.string "You are currently in\n"
	.string "the 1st room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom3:
	.string "You are currently in\n"
	.string "the 3rd room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom5:
	.string "You are currently in\n"
	.string "the 5th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom7:
	.string "You are currently in\n"
	.string "the 7th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom9:
	.string "You are currently in\n"
	.string "the 9th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom11:
	.string "You are currently in\n"
	.string "the 11th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_CurrentlyInRoom13:
	.string "You are currently in\n"
	.string "the 13th room…$"

BattleFrontier_BattlePikeThreePathRoom_Text_ContinueWithChallenge:
	.string "Will you continue with\n"
	.string "your challenge?$"

BattleFrontier_BattlePikeThreePathRoom_Text_SaveChallengeAndQuit:
	.string "Would you like to save your challenge\n"
	.string "and quit the game for now?$"

BattleFrontier_BattlePikeThreePathRoom_Text_RetireFromChallenge:
	.string "Do you wish to retire from your\n"
	.string "Battle Choice challenge?$"

BattleFrontier_BattlePikeThreePathRoom_Text_AwaitingReturnSaveBeforeResume:
	.string "We've been awaiting your return…\p"
	.string "Before resuming your Battle Choice\n"
	.string "challenge, let me save the game…$"

BattleFrontier_BattlePikeThreePathRoom_Text_PleaseEnjoyChallenge:
	.string "Please do enjoy your Battle Choice\n"
	.string "challenge…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SavingYourData:
	.string "I am saving your data…\n"
	.string "A little time, please…$"

BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack:
	.string "The path is blocked!\n"
	.string "And there is no turning back…$"

BattleFrontier_BattlePikeThreePathRoom_Text_FindingItDifficultToChoose:
	.string "I beg your pardon, but…\p"
	.string "Are you perhaps finding it difficult\n"
	.string "to choose your path?$"

BattleFrontier_BattlePikeThreePathRoom_Text_ApologizeForImpertinence:
	.string "I see…\n"
	.string "I apologize for my impertinence…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutRightPath:
	.string "Ah, let me see… There is something\n"
	.string "about the path on the right…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutCenterPath:
	.string "Ah, let me see… There is something\n"
	.string "about the path in the center…$"

BattleFrontier_BattlePikeThreePathRoom_Text_SomethingAboutLeftPath:
	.string "Ah, let me see… There is something\n"
	.string "about the path on the left…$"

BattleFrontier_BattlePikeThreePathRoom_Text_AromaOfPokemon:
	.string "It seems to have the distinct aroma\n"
	.string "of POKéMON wafting around it…$"

BattleFrontier_BattlePikeThreePathRoom_Text_PresenceOfPeople:
	.string "Is it… A TRAINER?\n"
	.string "I sense the presence of people…$"

BattleFrontier_BattlePikeThreePathRoom_Text_HeardWhispering:
	.string "I seem to have heard something…\n"
	.string "It may have been whispering…$"

BattleFrontier_BattlePikeThreePathRoom_Text_WaveOfNostaliga:
	.string "For some odd reason, I felt a wave\n"
	.string "of nostalgia coming from it…$"

BattleFrontier_BattlePikeThreePathRoom_Text_TerrifyingEvent:
	.string "I am sorry to say…\p"
	.string "A terrifying event, yes, a horrible one,\n"
	.string "is about to befall you…\p"
	.string "I urge you to pay the utmost care\n"
	.string "and prepare for the worst…$"

BattleFrontier_BattlePikeThreePathRoom_Text_DreadfulPresence:
	.string "From every path I sense a dreadful\n"
	.string "presence…$"
BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	facilitytrainerbattle FACILITY_BATTLE_PYRAMID
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "This is a sample message.$"

gText_BattlePyramidConfirmRest::
	.string "Your BATTLE PYRAMID quest will be\n"
	.string "saved so that you may quit for now.\l"
	.string "Is that okay?$"

gText_BattlePyramidConfirmRetire::
	.string "Are you sure you want to quit your\n"
	.string "PYRAMID quest?$"

BattlePyramid_Text_ExitHintUp1::
	.string "This floor's exit is in\n"
	.string "that direction: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "This floor's exit is in\n"
	.string "that direction: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "This floor's exit is in\n"
	.string "that direction: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "This floor's exit is in\n"
	.string "that direction: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "The exit on this floor is in\n"
	.string "the {UP_ARROW} direction.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "The exit on this floor is in\n"
	.string "the {LEFT_ARROW} direction.$"

BattlePyramid_Text_ExitHintRight2::
	.string "The exit on this floor is in\n"
	.string "the {RIGHT_ARROW} direction.$"

BattlePyramid_Text_ExitHintDown2::
	.string "The exit on this floor is in\n"
	.string "the {DOWN_ARROW} direction.$"

BattlePyramid_Text_ExitHintUp3::
	.string "The exit is over\n"
	.string "that {UP_ARROW} way.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "The exit is over\n"
	.string "that {LEFT_ARROW} way.$"

BattlePyramid_Text_ExitHintRight3::
	.string "The exit is over\n"
	.string "that {RIGHT_ARROW} way.$"

BattlePyramid_Text_ExitHintDown3::
	.string "The exit is over\n"
	.string "that {DOWN_ARROW} way.$"

BattlePyramid_Text_ExitHintUp4::
	.string "On this floor, the exit is somewhere\n"
	.string "in the {UP_ARROW} direction.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "On this floor, the exit is somewhere\n"
	.string "in the {LEFT_ARROW} direction.$"

BattlePyramid_Text_ExitHintRight4::
	.string "On this floor, the exit is somewhere\n"
	.string "in the {RIGHT_ARROW} direction.$"

BattlePyramid_Text_ExitHintDown4::
	.string "On this floor, the exit is somewhere\n"
	.string "in the {DOWN_ARROW} direction.$"

BattlePyramid_Text_ExitHintUp5::
	.string "The exit?\n"
	.string "It's that {UP_ARROW} way.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "The exit?\n"
	.string "It's that {LEFT_ARROW} way.$"

BattlePyramid_Text_ExitHintRight5::
	.string "The exit?\n"
	.string "It's that {RIGHT_ARROW} way.$"

BattlePyramid_Text_ExitHintDown5::
	.string "The exit?\n"
	.string "It's that {DOWN_ARROW} way.$"

BattlePyramid_Text_ExitHintUp6::
	.string "The exit happens to be in\n"
	.string "the {UP_ARROW} direction.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "The exit happens to be in\n"
	.string "the {LEFT_ARROW} direction.$"

BattlePyramid_Text_ExitHintRight6::
	.string "The exit happens to be in\n"
	.string "the {RIGHT_ARROW} direction.$"

BattlePyramid_Text_ExitHintDown6::
	.string "The exit happens to be in\n"
	.string "the {DOWN_ARROW} direction.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Are you looking for items?\p"
	.string "There are eight items left to\n"
	.string "be found.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Are you looking for items?\p"
	.string "There are seven items left to\n"
	.string "be found.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Are you looking for items?\p"
	.string "There are six items left to\n"
	.string "be found.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Are you looking for items?\p"
	.string "There are five items left to\n"
	.string "be found.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Are you looking for items?\p"
	.string "There are four items left to\n"
	.string "be found.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Are you looking for items?\p"
	.string "There are three items left to\n"
	.string "be found.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Are you looking for items?\p"
	.string "There are two items left to\n"
	.string "be found.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Are you looking for items?\p"
	.string "There is one item left to\n"
	.string "be found.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Are you looking for items?\p"
	.string "There isn't anything left to\n"
	.string "be found!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are eight items\n"
	.string "lying around here.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are seven items left\n"
	.string "lying around here.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are six items left\n"
	.string "lying around here.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are five items left\n"
	.string "lying around here.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are four items left\n"
	.string "lying around here.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are three items left\n"
	.string "lying around here.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There are two items left\n"
	.string "lying around here.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There is just one item\n"
	.string "lying around here.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Because you won, I'll tell you\n"
	.string "a little secret!\p"
	.string "There isn't anything left\n"
	.string "lying around here.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are eight items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are seven items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are six items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are five items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are four items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are three items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are two items left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there's but one item left\n"
	.string "waiting to be found on this floor.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "How's your stock of items holding up?\p"
	.string "I reckon there are no more items\n"
	.string "waiting to be found on this floor.\l"
	.string "You take care now!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be eight more\n"
	.string "items on the ground.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be seven more\n"
	.string "items on the ground.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be six more\n"
	.string "items on the ground.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be five more\n"
	.string "items on the ground.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be four more\n"
	.string "items on the ground.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be three more\n"
	.string "items on the ground.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be two more\n"
	.string "items on the ground.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appears to be only one more\n"
	.string "item on the ground.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "You're strong, so you've earned\n"
	.string "a hint!\p"
	.string "There appear to be no more\n"
	.string "items on the ground.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are eight items…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are seven items…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are six items…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are five items…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are four items…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are three items…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are two items…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there is one item…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "On this floor of the PYRAMID,\n"
	.string "I hear there are no items…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there are eight more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there are seven more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there are six more\n"
	.string "items on this floor.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there are five more\n"
	.string "items on this floor.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there are four more\n"
	.string "items on this floor.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there are three more\n"
	.string "items on this floor.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there are two more\n"
	.string "items on this floor.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there is one more\n"
	.string "item on this floor.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Have you collected any items?\p"
	.string "I believe there are no more\n"
	.string "items on this floor.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "You were really awesome!\p"
	.string "But there are still seven tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "You were really awesome!\p"
	.string "But there are still six tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "You were really awesome!\p"
	.string "But there are still five tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "You were really awesome!\p"
	.string "But there are still four tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "You were really awesome!\p"
	.string "But there are still three tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "You were really awesome!\p"
	.string "But there are still two tough\n"
	.string "TRAINERS other than me!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "You were really awesome!\p"
	.string "But there's still one tough\n"
	.string "TRAINER other than me!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "You were really awesome!\p"
	.string "There's no one left that\n"
	.string "can beat you!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are seven TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are six TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are five TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are four TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are three TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are two TRAINERS left!\n"
	.string "Someone will humble you!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there's one TRAINER left!\n"
	.string "I'm sure you will be humbled!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "This is so upsetting!\p"
	.string "But there are no more TRAINERS\n"
	.string "who can engage you!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there are seven more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there are six more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there are five more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there are four more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there are three more TRAINERS\n"
	.string "on this floor. Can you beat them all?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there are two more TRAINERS\n"
	.string "on this floor. Can you beat them both?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "But there's still one more TRAINER\n"
	.string "on this floor. Can you prevail?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "That's pretty impressive!\p"
	.string "You've gone through all the TRAINERS\n"
	.string "on this floor.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Maybe you could sweep through\n"
	.string "the seven TRAINERS left on this floor.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Maybe you could sweep through\n"
	.string "the six TRAINERS left on this floor.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Maybe you could sweep through\n"
	.string "the five TRAINERS left on this floor.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Maybe you could sweep through\n"
	.string "the four TRAINERS left on this floor.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Maybe you could sweep through\n"
	.string "the three TRAINERS left on this floor.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Maybe you could sweep through\n"
	.string "the two TRAINERS left on this floor.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Maybe you could complete your sweep\n"
	.string "with the one TRAINER left on this floor.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "There isn't a single person left who\n"
	.string "can defeat you now…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "You may have what it takes to beat\n"
	.string "the seven expert TRAINERS who remain.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "You may have what it takes to beat\n"
	.string "the six expert TRAINERS who remain.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "You may have what it takes to beat\n"
	.string "the five expert TRAINERS who remain.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "You may have what it takes to beat\n"
	.string "the four expert TRAINERS who remain.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "You may have what it takes to beat\n"
	.string "the three expert TRAINERS who remain.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "You may have what it takes to beat\n"
	.string "the two expert TRAINERS who remain.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "You may have what it takes to beat\n"
	.string "the one expert TRAINER who remains.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Your skills are beyond reproach.\p"
	.string "There are no more TRAINERS here\n"
	.string "who have any chance of beating you.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Can you keep winning against\n"
	.string "the seven remaining TRAINERS?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Can you keep winning against\n"
	.string "the six remaining TRAINERS?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Can you keep winning against\n"
	.string "the five remaining TRAINERS?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Can you keep winning against\n"
	.string "the four remaining TRAINERS?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Can you keep winning against\n"
	.string "the three remaining TRAINERS?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Can you keep winning against\n"
	.string "the two remaining TRAINERS?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Can you keep winning against\n"
	.string "the last remaining TRAINER?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "There aren't any TRAINERS left that\n"
	.string "can take you on now…$"
BattleFrontier_BattlePyramidTop_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidTop_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidTop_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidTop_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidTop_OnWarp
	.byte 0

BattleFrontier_BattlePyramidTop_OnTransition:
	pyramid_updatelight 200, PYRAMID_LIGHT_SET_RADIUS
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto_if_ne VAR_TEMP_C, 0, BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects
	setobjectxyperm LOCALID_BRANDON, 0, 0
BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects::
	end

BattleFrontier_BattlePyramidTop_OnResume:
	frontier_getbrainstatus
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus
	call BattleFrontier_EventScript_SetBrainObjectGfx
BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus::
	copyvar VAR_TEMP_C, VAR_RESULT
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePyramidTop_OnFrame:
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidTop_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID_TOP, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_Attendant::
	lock
	faceplayer
	goto_if_ne VAR_TEMP_D, 0, BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady
	goto_if_ne VAR_TEMP_C, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside
	msgbox BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop
	waitmovement 0
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath
	waitmovement 0
	message BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	closemessage
BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady::
	msgbox BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside::
	msgbox BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere, MSGBOX_DEFAULT
	applymovement LOCALID_PYRAMID_TOP_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
	setvar VAR_TEMP_D, 1
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon::
	lockall
	switch VAR_TEMP_C
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver::
	msgbox BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon

BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold::
	msgbox BattleFrontier_BattlePyramidTop_Text_EverythingYouHave, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_FarewellForNow, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon

BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle::
	closemessage
	dofacilitytrainerbattle FACILITY_BATTLE_PYRAMID
	waitstate
	return

BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside:
	walk_right
	walk_in_place_faster_left
	step_end

BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath:
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer:
	walk_fast_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	delay_16
	step_end

BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo:
	.string "It is a delight to see you here!\n"
	.string "You have reached the summit of\l"
	.string "the BATTLE PYRAMID!\p"
	.string "Above here is the PYRAMID's\n"
	.string "lookout point.\p"
	.string "It is a place open only to those\n"
	.string "who have conquered the PYRAMID.\p"
	.string "Now, please!\n"
	.string "Up you go!$"

BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid:
	.string "The PYRAMID's new conqueror!\n"
	.string "Let the name {PLAYER} be known!$"

BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere:
	.string "It is a delight to see you here!\p"
	.string "Unfortunately, you were second by\n"
	.string "a mere fraction of time!\p"
	.string "Our chief has already conquered\n"
	.string "the PYRAMID ahead of you.\p"
	.string "However, my young explorer…\n"
	.string "You are a TRAINER!\p"
	.string "Assert your power and take the glory\n"
	.string "of the pinnacle from our chief!\p"
	.string "Now, please! When you are ready,\n"
	.string "take one more step of courage!$"

BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure:
	.string "Young adventurer…\p"
	.string "Wouldn't you agree that explorations\n"
	.string "are the grandest of adventures?\p"
	.string "Your own wits!\p"
	.string "Your own strength!\p"
	.string "Your own POKéMON!\p"
	.string "And, above all, only your own courage\n"
	.string "to lead you through unknown worlds…$"

BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon:
	.string "Aah, yes, indeed this life is grand!\n"
	.string "Grand, it is! Eh?\p"
	.string "I'm BRANDON!\p"
	.string "I'm the PYRAMID KING, which means\n"
	.string "I'm in charge here.\p"
	.string "Most people call me the chief!\p"
	.string "You coming here means you have\n"
	.string "that much confidence in yourself,\l"
	.string "am I right?\p"
	.string "Hahahah!\n"
	.string "This should be exciting!$"

BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle:
	.string "Now, then!\n"
	.string "Bring your courage to our battle!$"

BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease:
	.string "BRANDON: Hahahah! Grand it was!\n"
	.string "Grand, yes, indeed!\p"
	.string "Well done! You've earned recognition!\n"
	.string "Your FRONTIER PASS, please!$"

BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol:
	.string "The Brave Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting:
	.string "Young explorer!\n"
	.string "I look forward to our next meeting!$"

BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned:
	.string "BRANDON: …You've finally returned,\n"
	.string "young explorer…\p"
	.string "Your love of adventure seems to come\n"
	.string "deep from within your heart…\p"
	.string "Yes… You are exactly as I was in\n"
	.string "my own youth…\p"
	.string "… … …Ah…\p"
	.string "The passionate!\p"
	.string "The dangerous!\p"
	.string "The desperate!\p"
	.string "Those days of death-defying,\n"
	.string "life-affirming adventures are back…$"

BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter:
	.string "Now, then!\p"
	.string "I sense my own courage is off\n"
	.string "the meter!$"

BattleFrontier_BattlePyramidTop_Text_EverythingYouHave:
	.string "Everything you have!\n"
	.string "I'm braced for it all!$"

BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis:
	.string "BRANDON: Hahahah!\n"
	.string "Remarkable!\l"
	.string "Yes, it's grand, indeed!\p"
	.string "Young explorer!\p"
	.string "You've bested me through and through!\n"
	.string "Here! I want you to have this!$"

BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine:
	.string "The Brave Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattlePyramidTop_Text_FarewellForNow:
	.string "Ah, yes! It just goes to show that\n"
	.string "I have much to learn still!\p"
	.string "May our paths cross again!\n"
	.string "Farewell for now, young explorer!$"

BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady:
	.string "Now, when you are ready, take courage\n"
	.string "and step forward.$"

BattleFrontier_BattleTowerBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_OnWarp
	.byte 0

BattleFrontier_BattleTowerBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible
	end

BattleFrontier_BattleTowerBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom::
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter
	waitmovement 0
	frontier_get FRONTIER_DATA_BATTLE_NUM
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
	waitmovement 0
	setvar VAR_TEMP_2, 1
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter::
	tower_setopponent
	addobject LOCALID_TOWER_BATTLE_OPPONENT
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter
	waitmovement 0
	tower_getopponentintro 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	switch VAR_RESULT
	case B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent
BattleFrontier_BattleTower_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent::
	call BattleFrontier_EventScript_IncrementWinStreak
	tower_setbattlewon
	switch VAR_RESULT
	case 7, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit
	waitmovement 0
	removeobject LOCALID_TOWER_BATTLE_OPPONENT
	frontier_getbrainstatus
	call_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
	waitmovement 0
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent::
	frontier_getbrainstatus
	copyvar VAR_TEMP_F, VAR_RESULT
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	case YES, BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge::
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
	waitmovement 0
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
	waitmessage
	tower_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent::
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent
	case 4, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent
	case 5, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent
	case 6, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent
	waitmessage
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent
	waitmessage
	return

BattleFrontier_EventScript_IncrementWinStreak::
	frontier_incrementstreak
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter::
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit
	waitmovement 0
	return

BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext::
	goto_if_eq VAR_TEMP_2, 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden::
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden
	waitmessage
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden

BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden

BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel::
	call BattleFrontier_EventScript_SetBrainObjectGfx
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
	waitmovement 0
	applymovement LOCALID_TOWER_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
	waitmovement 0
	addobject LOCALID_TOWER_BATTLE_OPPONENT
	applymovement LOCALID_TOWER_BATTLE_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter
	waitmovement 0
	switch VAR_TEMP_F
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe, MSGBOX_DEFAULT
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost

BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon

BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle::
	closemessage
	setvar VAR_TEMP_2, 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	special HealPlayerParty
	dofacilitytrainerbattle FACILITY_BATTLE_TOWER
	waitstate
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_0x8004, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle
	frontier_restorehelditems
	special HealPlayerParty
	frontier_resetsketch
BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle::
	tower_setinterviewdata
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	return

BattleFrontier_EventScript_SetBrainObjectGfx::
	frontier_setbrainobj
	return

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant:
	face_down
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle:
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos:
	walk_down
	walk_left
	walk_left
	walk_left
	face_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible:
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter:
	set_visible
	delay_16
	walk_up
	walk_left
	walk_left
	delay_8
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit:
	walk_right
	walk_right
	walk_down
	set_invisible
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay:
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant:
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby::
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles
	goto_if_eq VAR_RESULT, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis
	goto_if_eq VAR_RESULT, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 6, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles::
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 10, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis::
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 14, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis::
	tower_closelink
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 18, 6
	waitstate
	end

BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge::
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth:
	.string "We will restore your POKéMON to\n"
	.string "full health.$"

@ Unused
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForOpponent:
	.string "You will be facing opponent no. {STR_VAR_1}.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent:
	.string "You will be facing opponent no. 2.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent:
	.string "You will be facing opponent no. 3.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent:
	.string "You will be facing opponent no. 4.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent:
	.string "You will be facing opponent no. 5.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent:
	.string "You will be facing opponent no. 6.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent:
	.string "You will be facing opponent no. 7.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle:
	.string "Record your battle on your\n"
	.string "FRONTIER PASS?$"

BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass:
	.string "{PLAYER}'s battle was recorded\n"
	.string "on the FRONTIER PASS.$"

BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame:
	.string "Would you like to save and\n"
	.string "quit the game?$"

BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait:
	.string "Saving your battle data.\n"
	.string "Please wait.$"

BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge:
	.string "Would you like to cancel your BATTLE\n"
	.string "ROOM challenge?$"

BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved::
	.string "There was an error of some sort.\n"
	.string "Your record could not be saved.$"

BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay:
	.string "Excuse me, but…\p"
	.string "Our leader, the SALON MAIDEN, is on\n"
	.string "her way here in hopes of battling you.\p"
	.string "She should be arriving very shortly.$"

BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden:
	.string "You will be facing the SALON MAIDEN.\n"
	.string "Are you prepared?$"

BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel:
	.string "Greetings…\n"
	.string "My name is ANABEL.\p"
	.string "I am the SALON MAIDEN, and I am in\n"
	.string "charge of running the BATTLE TOWER…\p"
	.string "I have heard several rumors\n"
	.string "about you…\p"
	.string "In all honesty, what I have heard does\n"
	.string "not seem attractive in any way…\p"
	.string "The reason I've come to see you…\n"
	.string "Well, there is but one reason…$"

BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent:
	.string "Let me see your talent in\n"
	.string "its entirety…$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized:
	.string "ANABEL: Fufufu, nicely done…\p"
	.string "Your FRONTIER PASS, please…\n"
	.string "Your talent shall be recognized.$"

BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol:
	.string "The Ability Symbol was embossed on\n"
	.string "the FRONTIER PASS!$"

BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime:
	.string "… … … … … …\p"
	.string "You have confidence in your POKéMON\n"
	.string "battling talent, don't you?\p"
	.string "I urge you to keep battling and\n"
	.string "keep on winning.\p"
	.string "I will be waiting for you.\n"
	.string "Until the next time we meet…$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack:
	.string "ANABEL: You really did come back to\n"
	.string "see me…\p"
	.string "… … … … … …\p"
	.string "You've won straight matches to see me…\n"
	.string "I won't have to hold back against you…\p"
	.string "It's been too long now…\p"
	.string "Too long since I've been able to battle\n"
	.string "without thinking about anything…$"

BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe:
	.string "Let's begin, shall we?$"

BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease:
	.string "ANABEL: Fufu, congratulations…\n"
	.string "Your FRONTIER PASS, please…$"

BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine:
	.string "The Ability Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain:
	.string "That was fun…\p"
	.string "I have never had a POKéMON battle\n"
	.string "so enjoyable before…\p"
	.string "I wish I could battle with you again…$"

BattleFrontier_BattleTowerLobby_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerLobby_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerLobby_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerLobby_OnWarp
	.byte 0

BattleFrontier_BattleTowerLobby_OnResume:
	special TryHideBattleTowerReporter
	end

BattleFrontier_BattleTowerLobby_OnTransition:
	call BattleFrontier_BattleTowerLobby_EventScript_ShowOrHideReporter
	apprentice_shouldcheckgone
	goto_if_eq VAR_0x8004, FALSE, BattleFrontier_BattleTowerLobby_EventScript_ShowApprentice  @ VAR_0x8004 always TRUE here
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, BattleFrontier_BattleTowerLobby_EventScript_HideApprentice
BattleFrontier_BattleTowerLobby_EventScript_ShowApprentice::
	clearflag FLAG_HIDE_APPRENTICE
	apprentice_setgfx
BattleFrontier_BattleTowerLobby_EventScript_EndShowOrHideApprentice::
	end

BattleFrontier_BattleTowerLobby_EventScript_HideApprentice::
	setflag FLAG_HIDE_APPRENTICE
	goto BattleFrontier_BattleTowerLobby_EventScript_EndShowOrHideApprentice

BattleFrontier_BattleTowerLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleTowerLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleTowerLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	msgbox BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	tower_set TOWER_DATA_WIN_STREAK, 0
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_WonChallenge::
	lock
	faceplayer
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden
	message BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven
	waitmessage
	goto BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons

BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden::
	msgbox BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons::
	tower_giveribbons
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints
	message BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 49, BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge::
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	callnative UpdateFollowingPokemon
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_LostChallenge::
	goto_if_ne VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying
BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak::
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying::
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying
	waitmessage
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	callnative UpdateFollowingPokemon
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle::
	message BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	tower_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
	message BattleFrontier_BattleTowerLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
	case 0, BattleFrontier_EventScript_SaveBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle

BattleFrontier_EventScript_SaveBattle::
	frontier_savebattle
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_EventScript_BattleSaveFailed
	playse SE_SAVE
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle

BattleFrontier_EventScript_BattleSaveFailed::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle::
	return

BattleFrontier_EventScript_GetCantRecordBattle::
	frontier_get FRONTIER_DATA_RECORD_DISABLED
	return

BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge::
	lock
	faceplayer
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_SetBravoTrainerOn
	message BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_SetBravoTrainerOn::
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
	return

BattleFrontier_BattleTowerLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	special SavePlayerParty
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_AskEnterSinglesChallenge::
	message BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainSinglesChallenge
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleTowerLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterSinglesChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	special SavePlayerParty
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_AskEnterDoublesChallenge::
	message BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainDoublesChallenge
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterDoublesChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_MultisAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	clearflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	special SavePlayerParty
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_AskEnterMultisChallenge::
	message BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainMultisChallenge
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_ExplainMultisChallenge::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterMultisChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_LinkMultisAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	special SavePlayerParty
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_AskEnterLinkMultisChallenge::
	message BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterLinkMultisChallenge
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainLinkMultisChallenge
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_TryEnterLinkMultisChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeLinkMultisChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeLinkMultisChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
@ The command tower_save ultimately calls TrySavingData(SAVE_LINK), which writes data in SaveBlock1 and SaveBlock2
@ to the flash, but not data in PokemonStorage. The SaveGame script that follows asks the player to do a full save,
@ which they can opt out of. As a result the player can save their party and quit without having saved the PC.
@ This allows players to clone pokemon and their held items by withdrawing them (or erase them by despositing).
#ifndef BUGFIX
	tower_save 0
#endif
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
@ GAME_STAT_ENTERED_BATTLE_TOWER should not be incremented here, for two reasons:
@ 1. It is incremented again in BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful or BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
@ 2. If the player tries to connect, but fails, the counter will still be incremented even if the player never enters the tower.
#ifndef BUGFIX
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
#endif
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan::
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_TOWER_FEELINGS, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_FeelingsBattleNow
	case 1, BattleFrontier_BattleTowerLobby_EventScript_FeelingsIWon
	case 2, BattleFrontier_BattleTowerLobby_EventScript_FeelingsILost
	case 3, BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsBattleNow::
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_START
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsIWon::
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_WON
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsILost::
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_LOST
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
	end

BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell::
	msgbox BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings::
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CanceledEasyChat
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleTowerLobby_EventScript_SubmittedFeelings
	end

BattleFrontier_BattleTowerLobby_EventScript_CanceledEasyChat::
	msgbox BattleFrontier_BattleTowerLobby_Text_ChangedYourMind, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_SubmittedFeelings::
	msgbox BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded, MSGBOX_NPC
	end

BattleFrontier_BattleTowerLobby_EventScript_Boy::
	msgbox BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins, MSGBOX_NPC
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowMultisResults::
	lockall
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_MULTIS
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowLinkMultisResults::
	lockall
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_LINK_MULTIS
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles::
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles::
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles::
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles::
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS  @ No status provided, so it relies on VAR_0x8006 being 0 already
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge::
	special CloseLink
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_EnterElevator::
	special SavePlayerParty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	call BattleFrontier_BattleTowerLobby_EventScript_GetPartySize
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0
BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad::
	tower_loadlinkopponents
	delay 1
	goto_if_ne VAR_RESULT, 6, BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad
	call BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom::
	call BattleFrontier_BattleTowerLobby_EventScript_BufferModeText
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom
	msgbox BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator

BattleFrontier_BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom::
	messageautoscroll BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom
	waitmessage
	delay 48
BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator::
	closemessage
	call BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo
	call BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
	waitmovement 0
	opendoor VAR_0x8004, 1
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator
	waitmovement 0
	closedoor VAR_0x8004, 1
	waitdooranim
	return

BattleFrontier_BattleTowerLobby_Movement_WalkToElevator:
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Unused
BattleFrontier_BattleTowerLobby_Movement_UnusedEnterElevator:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end

BattleFrontier_BattleTowerLobby_EventScript_BufferModeText::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_BufferTextLinkMulti
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextLinkMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_TalkedToDoublesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_TalkedToMultisAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_TalkedToLinkMultisAttendant
	return

BattleFrontier_BattleTowerLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_TOWER_ATTENDANT_SINGLES
	return

BattleFrontier_BattleTowerLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_TOWER_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleTowerLobby_EventScript_TalkedToMultisAttendant::
	setvar VAR_LAST_TALKED, LOCALID_TOWER_ATTENDANT_MULTIS
	return

BattleFrontier_BattleTowerLobby_EventScript_TalkedToLinkMultisAttendant::
	setvar VAR_LAST_TALKED, LOCALID_TOWER_ATTENDANT_LINK_MULTIS
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordSingles
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordDoubles
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordMultis
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordLinkMultis
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordSingles::
	setvar VAR_0x8004, 6
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordDoubles::
	setvar VAR_0x8004, 10
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordMultis::
	setvar VAR_0x8004, 14
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordLinkMultis::
	setvar VAR_0x8004, 18
	return

BattleFrontier_BattleTowerLobby_EventScript_GetPartySize::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetLinkMultisPartySize
	return

BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize::
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize::
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	return

BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize::
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	return

BattleFrontier_BattleTowerLobby_EventScript_GetLinkMultisPartySize::
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	return

BattleFrontier_EventScript_GetLvlMode::
	frontier_get FRONTIER_DATA_LVL_MODE
	return

BattleFrontier_BattleTowerLobby_EventScript_TryCableLink::
	setvar VAR_0x8004, USING_BATTLE_TOWER
	message gText_PleaseWaitForLink
	waitmessage
	setvar VAR_0x8005, 0
	special TryBattleLinkup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto_if_eq VAR_RESULT, LINKUP_FAILED_BATTLE_TOWER, BattleFrontier_BattleTowerLobby_EventScript_AbortLink
	end

BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections::
	special CloseLink
	goto_if_eq VAR_0x8005, 3, BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection
	msgbox Text_PlayersMadeDifferentSelections, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection::
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
	msgbox BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers::
	msgbox BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers, MSGBOX_DEFAULT
	special CloseLink
	msgbox CableClub_Text_IncorrectNumberOfParticipants, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_AbortLink::
	special CloseLink
	call_if_eq VAR_0x8005, 0, BattleFrontier_BattleTowerLobby_EventScript_FriendChoseDifferentLvlMode
	call_if_eq VAR_0x8005, 1, BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMon
	call_if_eq VAR_0x8005, 2, BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMons
	msgbox BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_FriendChoseDifferentLvlMode::
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
	return

BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMon::
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon, MSGBOX_DEFAULT
	return

BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMons::
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons, MSGBOX_DEFAULT
	return

BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful::
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	special SaveForBattleTowerLink
	playse SE_SAVE
	waitse
	special TrySetBattleTowerLinkType
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_ExplainLinkMultisChallenge::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterLinkMultisChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink::
	setvar VAR_0x8004, LINK_GROUP_BATTLE_TOWER
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
	end

BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader::
	message CableClub_Text_ChooseGroupLeaderOfTwo
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
	case 1, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
	goto_if_eq VAR_RESULT, LINKUP_FAILED, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
	goto_if_eq VAR_RESULT, LINKUP_FAILED_BATTLE_TOWER, BattleFrontier_BattleTowerLobby_EventScript_AbortLink
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
	goto_if_eq VAR_RESULT, LINKUP_FAILED, BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
	goto_if_eq VAR_RESULT, LINKUP_FAILED_BATTLE_TOWER, BattleFrontier_BattleTowerLobby_EventScript_AbortLink
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful::
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	special SaveForBattleTowerLink
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleTowerLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_TOWER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_RulesTower
	case 1, BattleFrontier_BattleTowerLobby_EventScript_RulesMons
	case 2, BattleFrontier_BattleTowerLobby_EventScript_RulesSalon
	case 3, BattleFrontier_BattleTowerLobby_EventScript_RulesMultiLink
	case 4, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesTower::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesMons::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesSalon::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesMultiLink::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_ExitRules::
	releaseall
	end

@ Unused
BattleFrontier_BattleTowerLobby_Text_DirectYouToBattleRoom:
	.string "I'll direct you to your BATTLE ROOM now.$"

BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting:
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven:
	.string "Congratulations!\n"
	.string "You've beaten all seven TRAINERS!\p"
	.string "$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_EarnedFabulousPrize:
	.string "For beating seven TRAINERS in a row,\n"
	.string "you have earned this fabulous prize!\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_ReceivedPrize:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_BagFullMakeRoom:
	.string "Oh, your BAG appears to be full.\p"
	.string "Please make room in your BAG, then come\n"
	.string "see me.$"

BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying:
	.string "Thank you for playing!\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved:
	.string "Your record will be saved.\n"
	.string "Please wait.$"

BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou:
	.string "We've been waiting for you!\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved:
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress will be saved. Please wait.$"

BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer:
	.string "You're finally about to face the\n"
	.string "50th TRAINER.\p"
	.string "From here on, every time you beat seven\n"
	.string "TRAINERS in a row, your POKéMON will\l"
	.string "receive a commemorative RIBBON.\p"
	.string "Good luck!$"

BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons:
	.string "Here are some RIBBONS for beating\n"
	.string "seven tough TRAINERS in a row.\p"
	.string "{PLAYER} received some RIBBONS!$"

BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons:
	.string "{PLAYER} put the RIBBONS on\n"
	.string "the challenger POKéMON.$"

BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower:
	.string "Excuse me, do you have a moment?\p"
	.string "Can you describe your feelings when\n"
	.string "you're about to begin a BATTLE TOWER\l"
	.string "match, or when you've either won or\l"
	.string "lost a match?$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin:
	.string "Okay, what are your feelings when\n"
	.string "you're about to begin a match?$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon:
	.string "What do you feel when you've won\n"
	.string "a match?$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost:
	.string "Can I hear about your feelings when\n"
	.string "you have lost a match?$"

BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt:
	.string "Oh, so you don't think much about it?\n"
	.string "You're one cool customer.$"

BattleFrontier_BattleTowerLobby_Text_ChangedYourMind:
	.string "Hunh? You changed your mind?\n"
	.string "I guess you're fickle.$"

BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel:
	.string "Okay, so that's how you feel?\n"
	.string "That's quite original.\p"
	.string "Thanks!$"

BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded:
	.string "The number of matches you win in a row\n"
	.string "is recorded.\p"
	.string "I'd better not get beaten in\n"
	.string "an embarrassing way!$"

BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins:
	.string "Once you've entered the BATTLE TOWER,\n"
	.string "you can't leave until you either lose\l"
	.string "or you beat seven TRAINERS in a row.\p"
	.string "You'd best be certain that you're up\n"
	.string "to the challenge.$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_DoubleBattleRoomConstruction:
	.string "Welcome to the BATTLE TOWER\n"
	.string "DOUBLE BATTLE CORNER!\p"
	.string "Unfortunately, the BATTLE ROOMS\n"
	.string "are still under construction.\p"
	.string "Please come back when the work\n"
	.string "is completed.$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_MultiBattleRoomConstruction:
	.string "Welcome to the BATTLE TOWER\n"
	.string "MULTI BATTLE CORNER!\p"
	.string "Unfortunately, the BATTLE ROOMS\n"
	.string "are still under construction.\p"
	.string "Please come back when the work\n"
	.string "is completed.$"

BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge:
	.string "We look forward to seeing you on\n"
	.string "another challenge!$"

BattleFrontier_BattleTowerLobby_Text_WhichLevelMode:
	.string "The BATTLE ROOM offers two levels\n"
	.string "of challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_PleaseSelectMons:
	.string "Please select the POKéMON you wish\n"
	.string "to enter.$"

BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering:
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress must be saved. Is that okay?$"

BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom:
	.string "I will now show you to the\n"
	.string "{STR_VAR_1} BATTLE ROOM.$"

BattleFrontier_BattleTowerLobby_Text_RecordLastMatch:
	.string "Shall I record your last BATTLE TOWER\n"
	.string "match on your FRONTIER PASS?$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50:
	.string "Excuse me!\p"
	.string "You don't have {STR_VAR_2} eligible POKéMON.\p"
	.string "You must have {STR_VAR_2} different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsEnd:
	.string "Please come see me when you are ready.$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Excuse me!\p"
	.string "You don't have {STR_VAR_2} eligible POKéMON.\p"
	.string "You must have {STR_VAR_2} different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles:
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles:
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles:
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles:
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis:
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis:
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle:
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the SINGLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge:
	.string "Would you like to take the SINGLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge:
	.string "The BATTLE TOWER's SINGLE BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "SINGLE BATTLES with three POKéMON.\p"
	.string "There are many SINGLE BATTLE ROOMS\n"
	.string "in the BATTLE TOWER for team battles.\p"
	.string "In each of the SINGLE BATTLE ROOMS,\n"
	.string "seven TRAINERS await your challenge.\p"
	.string "If you manage to defeat all seven,\n"
	.string "you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleTowerLobby_Text_SelectThreeMons:
	.string "Now please select the three POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle:
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the DOUBLE\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge:
	.string "Would you like to take the DOUBLE\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge:
	.string "The BATTLE TOWER's DOUBLE BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "DOUBLE BATTLES with four POKéMON.\p"
	.string "There are many DOUBLE BATTLE ROOMS\n"
	.string "in the BATTLE TOWER for team battles.\p"
	.string "In each of the DOUBLE BATTLE ROOMS,\n"
	.string "seven TRAINERS await your challenge.\p"
	.string "If you manage to defeat all seven,\n"
	.string "you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons:
	.string "Now please select the four POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle:
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge:
	.string "Would you like to take the MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge:
	.string "The BATTLE TOWER's MULTI BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "MULTI BATTLES.\p"
	.string "For MULTI BATTLES, you must partner\n"
	.string "with a TRAINER in the TOWER and enter\l"
	.string "with two POKéMON each.\p"
	.string "Inside the TOWER is a room named\n"
	.string "the BATTLE SALON where you may meet\l"
	.string "other TRAINERS.\p"
	.string "There, you must find a TRAINER to act\n"
	.string "as your partner in MULTI BATTLES.\p"
	.string "Once you have partnered up, you will\n"
	.string "be shown to a MULTI BATTLE ROOM.\p"
	.string "In the MULTI BATTLE ROOM, seven\n"
	.string "tag teams await your challenge.\p"
	.string "If you manage to defeat all seven\n"
	.string "teams, you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons:
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle:
	.string "Where the talents of TRAINERS\n"
	.string "are put to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the LINK MULTI\n"
	.string "BATTLE ROOMS.$"

BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge:
	.string "Would you like to take the LINK MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge:
	.string "The BATTLE TOWER's MULTI BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "MULTI BATTLES with a friend.\p"
	.string "You must link with your friend using\n"
	.string "Wireless Adapters or a Game Boy\l"
	.string "Advance Game Link cable.\p"
	.string "You must partner with your friend and\n"
	.string "enter two different kinds of POKéMON.\p"
	.string "There are many MULTI BATTLE ROOMS\n"
	.string "in the BATTLE TOWER for team battles.\p"
	.string "In a MULTI BATTLE ROOM, seven\n"
	.string "tag teams await you and your friend\l"
	.string "to make a tag-team challenge.\p"
	.string "If you manage to defeat all seven\n"
	.string "teams, you will earn Battle Points.\p"
	.string "Please beware that unlike other ROOMS,\n"
	.string "you may not interrupt your challenge.\p"
	.string "Once you start, you must battle seven\n"
	.string "MULTI BATTLES in a row nonstop.$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2:
	.string "Now please select the two POKéMON\n"
	.string "that are to be entered.$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_ChoseSameMonAsFriend:
	.string "You have chosen the same kind of\n"
	.string "POKéMON as your friend.\p"
	.string "Please choose two POKéMON different\n"
	.string "from your friend's, match the level\l"
	.string "you wish to enter, and register again.$"

BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers:
	.string "The LINK MULTI BATTLE ROOM challenge\n"
	.string "is only for two linked players.$"

BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon:
	.string "Your friend has also selected\n"
	.string "the POKéMON {STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons:
	.string "Your friend has also selected the\n"
	.string "POKéMON {STR_VAR_1} and {STR_VAR_2}.$"

BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode:
	.string "Your friend has chosen a different\n"
	.string "battle level.$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMon:
	.string "Your friend has chosen a different\n"
	.string "battle level.\p"
	.string "Your friend has also selected\n"
	.string "the POKéMON {STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMons:
	.string "Your friend has chosen a different\n"
	.string "battle level.\p"
	.string "Your friend has also selected the\n"
	.string "POKéMON {STR_VAR_1} and {STR_VAR_2}.$"

BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode:
	.string "Please choose two POKéMON different\n"
	.string "from your friend's, match the level\l"
	.string "you wish to enter, and register again.$"

BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn:
	.string "I will save the game before\n"
	.string "showing you in. Please wait.$"

BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden:
	.string "Congratulations!\n"
	.string "You have defeated the SALON MAIDEN\l"
	.string "and swept seven TRAINERS!$"

BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints:
	.string "In recognition of your infinite talent,\n"
	.string "we award you these Battle Point(s).$"

BattleFrontier_Text_ObtainedXBattlePoints:
	.string "{PLAYER} obtained {STR_VAR_1} Battle Point(s).$"

BattleFrontier_BattleTowerLobby_Text_RulesAreListed:
	.string "The BATTLE TOWER rules are listed.$"

BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading:
	.string "Which heading do you want to read?$"

BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules:
	.string "The BATTLE TOWER is a facility where\n"
	.string "four types of battles are waged--\l"
	.string "SINGLE BATTLE, DOUBLE BATTLE, MULTI\l"
	.string "BATTLE, and LINK MULTI BATTLE.\p"
	.string "For each of these types, there are\n"
	.string "separate BATTLE ROOMS.\p"
	.string "Please speak with a guide offering\n"
	.string "the type of battle you wish to enter.$"

BattleFrontier_BattleTowerLobby_Text_ExplainMonRules:
	.string "Depending on the BATTLE ROOM you are\n"
	.string "entering, you will be required to take\l"
	.string "a certain number of POKéMON.\p"
	.string "The SINGLE BATTLE mode requires\n"
	.string "three POKéMON.\p"
	.string "The DOUBLE BATTLE mode requires four,\n"
	.string "and the MULTI modes both require two.$"

BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules:
	.string "The BATTLE SALON is where you must\n"
	.string "find a partner to form a tag team for\l"
	.string "the MULTI BATTLE ROOM challenge.\p"
	.string "Choose the best partner for you by\n"
	.string "examining other TRAINERS'\l"
	.string "POKéMON and their moves.\p"
	.string "You may choose a new tag partner\n"
	.string "after winning seven straight matches.$"

BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules:
	.string "The LINK MULTI BATTLE Mode is for two\n"
	.string "friends to mount a challenge together.\p"
	.string "You and your friend must be linked with\n"
	.string "Wireless Adapters or a GBA Game Link\l"
	.string "cable.\p"
	.string "You must choose two POKéMON at\n"
	.string "the registration counter.\p"
	.string "These POKéMON must be different\n"
	.string "from those of your friend.\p"
	.string "You may not interrupt this challenge\n"
	.string "in the middle, unlike other modes.$"
@ On this map the player will automatically walk into the room, but the camera is supposed to remain still.
@ To do this GF sets the player (LOCALID_PLAYER) invisible and creates a fake player object (LOCALID_TOWER_MULTI_BATTLE_PLAYER).
@ The graphics of this fake player object are represented with VAR_OBJ_GFX_ID_F.
@ The graphics of the partner are represented with VAR_OBJ_GFX_ID_E, which will ultimately be set by tower_setpartnergfx.
@ The graphics of the opponents are represented with VAR_OBJ_GFX_ID_0 and OBJ_EVENT_GFX_VAR_1, which will ultimately be set by tower_setopponent.

BattleFrontier_BattleTowerMultiBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiBattleRoom_OnTransition:
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx::
	tower_setpartnergfx
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BRENDAN_NORMAL
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale::
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_MAY_NORMAL
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx::
	special SetBattleTowerLinkPlayerGfx
	return

BattleFrontier_BattleTowerMultiBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj::
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM
	end

BattleFrontier_BattleTowerMultiBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom::
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom
	waitmovement 0
	frontier_get FRONTIER_DATA_BATTLE_NUM
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
	waitmovement 0
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter::
	tower_setopponent
	addobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1
	addobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter
	waitmovement 0
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink
	tower_getopponentintro 0
	delay 15
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	tower_getopponentintro 1
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink::
	tower_getopponentintro 0
	delay 15
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
	waitmovement 0
	messageautoscroll gStringVar4
	waitmessage
	delay 48
	tower_getopponentintro 1
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
	waitmovement 0
	messageautoscroll gStringVar4
	waitmessage
	delay 48
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle::
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
	switch VAR_RESULT
	case B_OUTCOME_WON, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents::
	call BattleFrontier_EventScript_IncrementWinStreak
	tower_setbattlewon
	switch VAR_RESULT
	case 7, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit
	applymovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit
	waitmovement 0
	removeobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_1
	removeobject LOCALID_TOWER_MULTI_BATTLE_OPPONENT_2
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
	waitmovement 0
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
	waitmovement 0
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink::
	messageautoscroll BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth
	waitmessage
	delay 48
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty::
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_MULTI_PARTY_SIZE
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord::
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle::
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
	case YES, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge::
	closemessage
	clearflag FLAG_TEMP_2
	applymovement LOCALID_TOWER_MULTI_BATTLE_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
	applymovement LOCALID_TOWER_MULTI_BATTLE_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
	waitmovement 0
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
	applymovement LOCALID_TOWER_MULTI_BATTLE_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
	waitmovement 0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	tower_set TOWER_DATA_LVL_MODE
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
	special Script_TryGainNewFanFromCounter
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge::
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
	waitmessage
	tower_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen 1
	frontier_reset
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink::
	copyvar VAR_TEMP_F, VAR_RESULT
	switch VAR_TEMP_F
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink::
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg::
	waitmessage
	delay 48
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink::
	goto_if_set FLAG_TEMP_2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord
	multichoice 19, 6, MULTI_GO_ON_RECORD_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord::
	multichoice 20, 8, MULTI_GO_ON_RETIRE, TRUE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink::
	setvar VAR_0x8004, BATTLE_TOWER_LINK_CONTINUE
	setvar VAR_0x8005, 0
	message gText_LinkStandby3
	waitmessage
	special LinkRetireStatusWithBattleTowerPartner
	goto_if_ne VAR_RESULT, BATTLE_TOWER_LINKSTAT_CONTINUE, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink::
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
	call BattleFrontier_EventScript_SaveBattle
	setflag FLAG_TEMP_2
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink::
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink::
	setvar VAR_0x8004, BATTLE_TOWER_LINK_RETIRE
	setvar VAR_0x8005, 0
	message gText_LinkStandby3
	waitmessage
	special LinkRetireStatusWithBattleTowerPartner
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink::
	special BattleTowerReconnectLink
	return

BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom:
	walk_left
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant:
	face_left
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle:
	walk_in_place_faster_right
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter:
	walk_right
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer:
	walk_right
	walk_right
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos:
	walk_left
	walk_left
	walk_in_place_faster_right
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft:
	walk_in_place_left
	step_end

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet:
	.string "The 2nd set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet:
	.string "The 3rd set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet:
	.string "The 4th set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet:
	.string "The 5th set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet:
	.string "The 6th set of opponents is next.\n"
	.string "Are you ready?$"

BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet:
	.string "The 7th set of opponents is next.\n"
	.string "Are you ready?$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_2ndOpponentSetNext:
	.string "The 2nd set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_3rdOpponentSetNext:
	.string "The 3rd set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_4thOpponentSetNext:
	.string "The 4th set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_5thOpponentSetNext:
	.string "The 5th set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_6thOpponentSetNext:
	.string "The 6th set of opponents is next.\n"
	.string "Do your best!$"

@ Unused
BattleFrontier_BattleTowerMultiBattleRoom_Text_7thOpponentSetNext:
	.string "The 7th set of opponents is next.\n"
	.string "Do your best!$"

gText_LinkStandby3::
	.string "Link standby…$"

gText_YourPartnerHasRetired::
	.string "Your partner has retired.\p"
	.string "Your BATTLE ROOM challenge\n"
	.string "will be canceled.$"
BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Please find a partner from out of\n"
	.string "the TRAINERS gathered here.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, you have not found a partner\n"
	.string "for your tag team.\p"
	.string "Would you like to quit looking and\n"
	.string "return to the reception counter?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Then, please find a partner from\n"
	.string "the TRAINERS gathered here.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Thank you for choosing a partner.\p"
	.string "I will now show you to your\n"
	.string "MULTI BATTLE ROOM.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "You can call me {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "On {STR_VAR_1}'s advice, I brought\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let me join you as a tag team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Thank you!\n"
	.string "I'll go register right now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "I really wanted to form a tag team\n"
	.string "with you, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "My name is {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "I got advice from {STR_VAR_1} and chose\n"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please, let's form a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Thank you very much!\n"
	.string "I'll be done with registration quickly!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, I was hoping that I could\n"
	.string "partner up with you…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Um, my name's {STR_VAR_3}, and I'm\n"
	.string "{STR_VAR_1}'s no. {STR_VAR_2} apprentice.\p"
	.string "Snivel…\p"
	.string "I'm sorry!\n"
	.string "This tension is making me cry…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} advised me, so I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Snivel…\n"
	.string "Please, please team up with me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh, really? You will?\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Oh… I'm sorry…\n"
	.string "I'm so happy, I'm crying…\p"
	.string "I'll go register right away.\n"
	.string "Please don't go away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, b-but…\n"
	.string "Sob… Waaaaah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Hi, there! I'm {STR_VAR_3}!\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} recommended my crew.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's what I have! Cool, huh?\p"
	.string "So come on!\n"
	.string "Let's form a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Yay! Great!\n"
	.string "Okay, I'll go register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Aww, why?\n"
	.string "I wanted to team up, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "I'm {STR_VAR_3}, the no. {STR_VAR_2} apprentice\n"
	.string "of the famous {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "I looked to {STR_VAR_3} for advice.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's my pair.\p"
	.string "Please, will you join me in\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Thank you!\n"
	.string "I'll register right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, I had been hoping to join\n"
	.string "you in a tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Um… I'm sincerely happy that you\n"
	.string "would take the time to talk to me.\p"
	.string "I'm {STR_VAR_3}.\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} gave me advice.\n"
	.string "I'm very grateful for it.\p"
	.string "I have a team of one {STR_VAR_2}\n"
	.string "with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I know I'm asking a lot…\p"
	.string "I don't think you'll be willing to,\n"
	.string "but may I join you as a partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Really? I can't believe it!\n"
	.string "I can't believe you'll let me join you!\l"
	.string "I… I won't let you down!\p"
	.string "Um… If it's really okay, I'll go register\n"
	.string "right this instant!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\n"
	.string "I didn't think I was good enough…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Hi, I'm {STR_VAR_3}.\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} told me that it would be\n"
	.string "good to make this team:\l"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "and one {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}.\p"
	.string "Not bad, huh?\n"
	.string "Want me to team up with you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Okay, glad to join you!\n"
	.string "I hope you won't mess things up for me!\l"
	.string "I'll do my registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Huh? Why did you turn me down?\n"
	.string "You're no judge of character!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "I'm {STR_VAR_3} and I'm a TRIATHLETE.\n"
	.string "I'm busy every day what with jogging,\l"
	.string "training, and rapping.\p"
	.string "I also happen to be {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "This is what {STR_VAR_3} recommended.\n"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "I put a lot of effort into raising\n"
	.string "them, even though I'm busy.\p"
	.string "Let's form a tag team\n"
	.string "and give it a go!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Thanks, that's the spirit!\n"
	.string "Hang tight while I go register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "I took time from my busy schedule\n"
	.string "to be here! Give me a break!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Hi!\n"
	.string "How's it going?\p"
	.string "I'm {STR_VAR_3}, {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice. Glad to meet you!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Listen, listen! You have to hear about\n"
	.string "the POKéMON {STR_VAR_3} recommended.\l"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Of course I raised them superbly!\p"
	.string "So, want to team up?\n"
	.string "I'm sure it'll be a great combo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Yay, I think this will be fun!\n"
	.string "I'll go register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, you're mean!\n"
	.string "I come recommended, you know.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Please let me introduce myself.\n"
	.string "I am {STR_VAR_3}.\p"
	.string "I serve as {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "I sought the sage advice of\n"
	.string "{STR_VAR_3} and raised my team\l"
	.string "of one {STR_VAR_2} with {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Please agree to a tag team with me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… I'm delighted!\n"
	.string "I promise to give you my best!\p"
	.string "Of course I will register us!\n"
	.string "Please wait!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "I had been hoping to join you,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Eek! You spoke to me!\n"
	.string "I… I'm overjoyed!\p"
	.string "I'm {STR_VAR_3}! I'm {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "On {STR_VAR_3}'s advice, I trained\n"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}.\p"
	.string "Please, can you grant me my wish?\n"
	.string "I want to be your tag-team partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Eek! I… I feel giddy!\n"
	.string "Thank you so much!\l"
	.string "I'll go register us right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah! Don't you feel any pity?\n"
	.string "But that makes you cooler…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Yeehaw! I'm {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice!\p"
	.string "{STR_VAR_3}'s my name, hello, hello!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "My mentor {STR_VAR_3} recommended\n"
	.string "one {STR_VAR_1}-master {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "and one {STR_VAR_1}-master\n"
	.string "{STR_VAR_2}.\p"
	.string "Good stuff, huh?\n"
	.string "You'll partner with me, won't you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Okay, excellent!\n"
	.string "I'll get the registration done quickly!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah!\n"
	.string "You're a calculating one, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hey! There's big trouble! This is\n"
	.string "the BATTLE TOWER's last day!\p"
	.string "… … … … … …\n"
	.string "I'm only joking!\p"
	.string "People call me {STR_VAR_3} and I do, too!\n"
	.string "I'm {STR_VAR_1}'s 1,000th apprentice!\l"
	.string "Actually, I'm no. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} gave me some advice.\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} with {STR_VAR_1}.\n"
	.string "I've got ten of each kind!\l"
	.string "Actually, just one of each!\p"
	.string "How about it?\n"
	.string "Want to try tag battles with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Yippee!\n"
	.string "I'll give you a POKéMON as my thanks!\p"
	.string "Just joking! But I will really go do\n"
	.string "the registration, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, that's so cold! I'll have to wreck\n"
	.string "the BATTLE TOWER for that!\p"
	.string "Of course I won't!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Hey, there, I'm rockin' and a-rollin'!\n"
	.string "POKéMON, I be controllin'!\p"
	.string "I'm {STR_VAR_3} the rappin' SAILOR.\n"
	.string "Don't be mistakin' me for no wailer!\p"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
	.string "Me, you shouldn't be quick to dismiss!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "With the advice of {STR_VAR_3} I did\n"
	.string "abide, put together my team of pride!\l"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}!\p"
	.string "Our meeting we should commemorate,\n"
	.string "with a tag-team victory to celebrate!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hey, hey, I like your style!\n"
	.string "Our registration, I will go file!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, hey, {PLAYER}, now that's cold!\n"
	.string "If I may be so bold!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Yippee-yahoo!\n"
	.string "Oh, don't run! I was just having fun!\p"
	.string "Howdy! I'm {STR_VAR_3}!\n"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} told me what to do.\n"
	.string "So one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2}, I did choose.\p"
	.string "So, what do you say?\n"
	.string "Come on, make my day!\p"
	.string "Please, I'm begging you!\n"
	.string "Let me join you, don't leave me blue!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Yeahah! Luck is with me!\n"
	.string "It sure makes me happy!\p"
	.string "Before we go join the fray,\n"
	.string "I'll go register right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "You're turning me down?\n"
	.string "{PLAYER}, you're making me frown!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Cough!\p"
	.string "Oh, sorry, I have a cold.\n"
	.string "My POKéMON are fine, though.\p"
	.string "My name's {STR_VAR_3}, {STR_VAR_1}'s\n"
	.string "no. {STR_VAR_2} apprentice. Cough!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "I took {STR_VAR_3}'s advice to heart\n"
	.string "and put together my team of\l"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I trained them every day,\n"
	.string "even in wind and rain.\p"
	.string "That's why I have this cold,\n"
	.string "I think.\p"
	.string "That's what I'm about.\n"
	.string "Want to be my tag partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Thanks, I appreciate this!\n"
	.string "Cough, cough!\l"
	.string "Hang on while I go register.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, you won't?\n"
	.string "{PLAYER}, I think we'd make a good pair.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, hello!\n"
	.string "This is nerve-racking.\p"
	.string "I'm {STR_VAR_3}.\n"
	.string "I'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} said this team'll be good--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I'm feeling self-conscious about this,\n"
	.string "but will you let me join you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, gee, thank you!\n"
	.string "I feel bashful, but I'll do my best!\p"
	.string "I'll go get the registration done.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, please don't say no!\n"
	.string "I feel self-conscious enough already…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "I am {STR_VAR_3}, and that's no lie.\n"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} recommended my team.\p"
	.string "Since the advice sounded sincere,\n"
	.string "I decided to bring with me\l"
	.string "my {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "my {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "If possible, I would like you to accept\n"
	.string "me as your tag-team partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "You really will accept me?\n"
	.string "It would be too terrible otherwise.\p"
	.string "But since you've agreed, this is fine.\n"
	.string "I shall go register the both of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Now why would you refuse?\n"
	.string "Is this your idea of a joke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "I'm {STR_VAR_1}, and I'm a LASS!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "What I have are one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} that uses {STR_VAR_1}.\n"
	.string "Those are what I have with me.\p"
	.string "Will you be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Thank you!\n"
	.string "I'll go do the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "You don't want to be my partner?\n"
	.string "You'll regret it later!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Hello!\p"
	.string "I'm YOUNGSTER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Want to know what I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "You'll be my tag-team partner,\n"
	.string "won't you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Yay!\n"
	.string "I'll go and register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Aww! If you'd form a tag team with\n"
	.string "my POKéMON, we'd be unstoppable!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Yahoo!\n"
	.string "I'm HIKER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Know what I have with me?\n"
	.string "My {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "my {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Sounds good, eh?\n"
	.string "Want to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Yahoo!\n"
	.string "I'll go do the registering, then.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "I would've liked to battle with you\n"
	.string "at my side.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a BEAUTY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Do you know what I've been raising?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What do you think?\n"
	.string "Want to make a tag team together?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Wonderful!\n"
	.string "I'll get the registration done now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "How disappointing!\p"
	.string "We two together--we would've been\n"
	.string "the best!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Yo!\p"
	.string "You know who I am?\n"
	.string "I'm {STR_VAR_1} the FISHERMAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "I've got with me a team of one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "So, how about it?\n"
	.string "Will you battle at my side?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Good, good!\n"
	.string "Leave it up to me!\p"
	.string "I'll go and register us now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "We matched up perfectly, too…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Glad to make your acquaintance.\n"
	.string "I am {STR_VAR_1}, a LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "I am accompanied by a team of\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "I hope I meet your approval.\n"
	.string "For I wish to have you as my partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "I thank you sincerely.\n"
	.string "I shall handle the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "I'm sure that you will regret not\n"
	.string "having me as your partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "I'm TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "What I have…\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "That's my pair!\p"
	.string "Please?\n"
	.string "Will you form a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Gee, thanks!\n"
	.string "I'll go register at the counter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "We two together, we would've been\n"
	.string "tough for certain!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Hiya!\n"
	.string "I'm BUG CATCHER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Check out what I have!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "So, listen!\n"
	.string "Do you want to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Gotcha!\p"
	.string "I'll go do the registration stuff\n"
	.string "at the counter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Aww, my POKéMON are awesome.\n"
	.string "I hope you won't regret this!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Good day!\n"
	.string "I'm SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "What I've been raising are one\n"
	.string "{STR_VAR_2} that uses {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "and one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Not too bad, don't you think?\n"
	.string "Would you care to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Thank you very much!\n"
	.string "I'll get done with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "That's too bad…\p"
	.string "I was hoping that I could learn\n"
	.string "from you as your partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Yo! Let me tell you who I am!\n"
	.string "I'm RICH BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Guess what I got!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "I'm willing to offer you the chance\n"
	.string "to be in a tag team with me.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Smart move!\p"
	.string "I'll finish up the registration\n"
	.string "process quick!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "You'd turn me of all people down?\n"
	.string "You'll regret that decision for sure!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah!\n"
	.string "I am BLACK BELT {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "As my companions, I have\n"
	.string "one {STR_VAR_2} using {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "and one {STR_VAR_2} using\n"
	.string "{STR_VAR_1}.\p"
	.string "Please, grant me my wish!\n"
	.string "Allow me to be your tag partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah!\n"
	.string "I will go register forthwith!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "I see… I hope for an opportunity\n"
	.string "the next time we meet…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Hi, there!\n"
	.string "I'm {STR_VAR_1}, and I'm a TUBER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "I'll tell you what I have.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
	.string "May I please be on your tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Thank you!\n"
	.string "I'll go register us now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "If we'd become partners, we could\n"
	.string "have been so strong!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Greetings…\n"
	.string "I am HEX MANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "I bear with me one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} together with one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1}-using {STR_VAR_2}…\p"
	.string "I beseech you…\n"
	.string "Join me in a tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "I thank you…\n"
	.string "I shall register us…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "I so longed to join you…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "How do you do? I'm {STR_VAR_1},\n"
	.string "and I'm a POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "I'm raising a couple good ones!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Feel like making a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Thank you kindly!\p"
	.string "I'll go take care of the registration\n"
	.string "stuff, so you wait right here!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "I was looking forward to being\n"
	.string "your partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Well, hello!\n"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Want to know what I run with?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well?\n"
	.string "Want to be in a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Good going!\p"
	.string "I'll be quick and get the registration\n"
	.string "all done!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "You and me, we would've been tops.\n"
	.string "It's too bad…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Hey, there! My name's {STR_VAR_1}!\n"
	.string "I'm a TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "I go on runs with my durable team--\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Not too shabby, huh?\n"
	.string "We should be in a tag team together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "All right!\n"
	.string "I'll go register in a flash!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "I really wanted to battle as your\n"
	.string "tag-team partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "I'm BATTLE GIRL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "I've been toughening up one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}!\p"
	.string "Do you like that combo?\n"
	.string "How about you and me join up?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Why, thanks!\p"
	.string "I'll get the registration done\n"
	.string "right now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "With you, I thought we could form\n"
	.string "the ultimate tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "I'm TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "I've been running with one {STR_VAR_2}\n"
	.string "that knows how to use {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "We could be in a tag team.\n"
	.string "Wouldn't that be great?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Thank you!\p"
	.string "I'll go register us, and that's\n"
	.string "right now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Aww, that's too bad. We would've been\n"
	.string "the toughest tag team around!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Me?\n"
	.string "I'm TUBER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "What do I have with me?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Hey?\n"
	.string "You'll team up with me, right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Okay!\p"
	.string "I'll go register!\n"
	.string "Let's be excellent together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "My POKéMON are tough for sure…\n"
	.string "It's too bad you don't want to team up.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yay-hey!\n"
	.string "Call me GUITARIST {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Check out my entourage!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Yay-hey! Pretty wild, huh?\n"
	.string "We'll have to do a duet in a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Yay-hey! Right on!\n"
	.string "I'll do that registration stuff now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "My POKéMON rock hard!\n"
	.string "You'll be sorry, I tell you!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Pleased to meet you.\n"
	.string "I am {STR_VAR_1}, a GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "I am accompanied by my trusted\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "May I ask you to join me in a tag-team\n"
	.string "partnership arrangement?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, I thank you for your trust.\n"
	.string "I shall be done with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "That is most unfortunate…\p"
	.string "I shall look forward to the next\n"
	.string "opportunity…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Hello, I'm {STR_VAR_1},\n"
	.string "and I'm a POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "I have with me now one {STR_VAR_2}\n"
	.string "that knows the move {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Do you like what you see?\n"
	.string "Why don't you be my tag partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Thank you!\n"
	.string "I'll look after the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "My POKéMON are top grade…\n"
	.string "It's too bad you can't appreciate that.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm!\n"
	.string "I am {STR_VAR_1}, and an EXPERT am I!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "The POKéMON that I've toughened up are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "What say you to a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm!\n"
	.string "I shall register us right away!\l"
	.string "Let us both do our best!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "I will hope that your choice is\n"
	.string "indeed correct…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hello, hello.\n"
	.string "I'm {STR_VAR_1}, and I'm an EXPERT.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "I've raised my POKéMON thoroughly.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they're what I have.\p"
	.string "Wouldn't you like to team up with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Good, good.\n"
	.string "I'll see to the registration right away.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Perhaps we can form a team the next\n"
	.string "time we meet.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "I'm DRAGON TAMER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "The team I've been toughening up is\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How about it?\n"
	.string "Want to be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Okay, I'll give it my best!\n"
	.string "I'll go register now, all right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "You're not going to find many tougher\n"
	.string "partners than me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "I'm BIRD KEEPER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "What POKéMON do I have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Don't you think we'd make a decent\n"
	.string "tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Great, thanks!\n"
	.string "I'll look after the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "My POKéMON and I are strong.\n"
	.string "What a letdown.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "I'm NINJA BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "My POKéMON team consists of one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Let's be in a tag team together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Yay!\n"
	.string "Let me go register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "You'll regret not having my tough\n"
	.string "POKéMON on your side!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Hello!\n"
	.string "I'm PARASOL LADY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Escorting me now are my {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "Aren't they nice?\n"
	.string "Care to join us in a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Thanks a bunch!\p"
	.string "I'll go register at the counter.\n"
	.string "Let's not disappoint each other!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "My POKéMON are tremendously strong.\n"
	.string "How disappointing…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Hello.\n"
	.string "I'm {STR_VAR_1}, and I'm a BUG MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "I have found my POKéMON, yes.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they are what I found.\p"
	.string "Could I interest you in forming\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Okay!\n"
	.string "Understood!\p"
	.string "I won't be long with the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "With the POKéMON I found, we wouldn't\n"
	.string "have lost…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ahoy, there!\n"
	.string "I'm SAILOR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Let me show you my pride and joy!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Of course you're not going to turn\n"
	.string "me down. We will team up, right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "I didn't expect any less!\n"
	.string "I'll go register now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "We would've stormed through\n"
	.string "the opposition! Too bad!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hi, I'm {STR_VAR_1}.\n"
	.string "I'm a COLLECTOR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "The jewels in my collection are\n"
	.string "my {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Swell, huh?\n"
	.string "We should be in a team together.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, yeah!\p"
	.string "Well, let's not waste any time.\n"
	.string "I'll go register the two of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Well, that's upsetting.\n"
	.string "You don't appreciate my POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Howdy, I'm {STR_VAR_1}.\n"
	.string "I'm a POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Keeping me company are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Don't you think we'd make an impressive\n"
	.string "tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "That's super!\n"
	.string "I'll deal with the registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "Next time, choose my POKéMON,\n"
	.string "will you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "My name's {STR_VAR_1}.\n"
	.string "I'm a POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Let me tell you about my team. I have\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "How would you like to form a tag team\n"
	.string "with my little posse?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "We'll be at our best!\n"
	.string "I'll get the registration done quick!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "I hope you'll choose my POKéMON\n"
	.string "next time.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Pleased to meet you. I'm {STR_VAR_1}.\n"
	.string "I consider myself an AROMA LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "I travel with one {STR_VAR_2}\n"
	.string "that uses {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "one {STR_VAR_2} that uses\n"
	.string "{STR_VAR_1}.\p"
	.string "I hope they strike your fancy.\n"
	.string "Would you care to be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "I'm honored by your acceptance.\n"
	.string "I will go register right this instant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "It would be wonderful if we could form\n"
	.string "a tag team the next time we meet.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Want to know who I am?\n"
	.string "I'm {STR_VAR_1}, the RUIN MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "The POKéMON that I have with me are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Intriguing, eh?\n"
	.string "How about you and I partner up?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "That's a sound decision!\n"
	.string "I'll go do the registration paperwork.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm…\n"
	.string "I think my POKéMON are tough…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "I'm COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "The POKéMON I have right now are one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
	.string "Cool, huh?\p"
	.string "Don't you think it'd be pretty cool\n"
	.string "if we made a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Cool!\n"
	.string "I'll go do the registration in a flash!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "I thought that we'd make just\n"
	.string "the greatest team ever.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "I'm COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "The team I've been raising has one\n"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Does that sound okay?\n"
	.string "How about we become tag partners?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Sounds A-OK!\n"
	.string "I'd better do the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "I was thinking how we would be\n"
	.string "one tough team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Heyo!\n"
	.string "I'm {STR_VAR_1}, the POKéMANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "What does a guy like me have?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
	.string "that's what!\p"
	.string "Let's do it!\n"
	.string "We'll stomp around as a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Good call!\n"
	.string "I'll register the both of us!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "My POKéMON are brutal!\n"
	.string "It's not my fault if you regret this!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Yo, there!\n"
	.string "I'm KINDLER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "You know what my training cooked up?\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Well, what do you say?\n"
	.string "Want to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "All right!\n"
	.string "I'll get on with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Promise you'll partner up with me\n"
	.string "the next time we run into each other.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "I'm {STR_VAR_1}, and I'm a CAMPER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "I've been raising one {STR_VAR_1}-\n"
	.string "using {STR_VAR_2} and one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Do you think it'd be fun to team up?\n"
	.string "I bet it would be!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Yeah!\n"
	.string "Off I go to register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Next time, okay?\n"
	.string "I want to be on your team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a PICNICKER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "The POKéMON I've been taking are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Are you interested in joining me\n"
	.string "on a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Why, thank you!\n"
	.string "I will do the registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "It would be nice if I could join you\n"
	.string "some other time.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "I'm PSYCHIC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "The twosome I've been raising are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Would you like to form a tag team\n"
	.string "with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Sure thing!\n"
	.string "I'll take care of the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "If we meet again, that's when I'd like\n"
	.string "to team up with you.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "I'm {STR_VAR_1}.\n"
	.string "I'm a PSYCHIC.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
	.string "they're my disciples.\p"
	.string "Doesn't the idea of forming a tag-team\n"
	.string "partnership intrigue you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Thank you.\n"
	.string "I'll go deal with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "I hope there will be another chance\n"
	.string "to forge an alliance.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "I'm SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are my POKéMON pair.\p"
	.string "May I please be your partner on\n"
	.string "a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, thank you!\n"
	.string "I'll register at the counter right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Please?\n"
	.string "May I join you the next time?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Hiya! The name's {STR_VAR_1}!\n"
	.string "I'm a POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "The POKéMON I've raised are one\n"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
	.string "Sound interesting?\n"
	.string "How about we form a tag team, then?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "All righty!\n"
	.string "You leave the registration to me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "You have to team up with me next time,\n"
	.string "all right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "I'm {STR_VAR_1}, and I'm proud to say\n"
	.string "that I am a POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "The darling POKéMON I've raised are\n"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
	.string "Aren't they just the cutest?\n"
	.string "We ought to make a team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Thank you, dear!\n"
	.string "I'll be on my way to register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "My darling POKéMON are the best,\n"
	.string "I'll have you know. How annoying!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hi, I'm SWIMMER {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "and one {STR_VAR_1}-using\n"
	.string "{STR_VAR_2} are what I've trained.\p"
	.string "You and me, let's make a tag team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "That's cool!\n"
	.string "I'll register the two of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "If we meet again, you owe me\n"
	.string "a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "What's happening?\n"
	.string "I'm {STR_VAR_1}, and I'm a TRIATHLETE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "I got a couple decent POKéMON.\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "It'd be neat if we made a tag team\n"
	.string "together, so how about it?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Right on!\n"
	.string "You wait while I register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "I expect you'll let me join you\n"
	.string "next time, how's that?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "I'm the TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "another {STR_VAR_2} that knows how\n"
	.string "to use {STR_VAR_1}. That's my pair.\p"
	.string "What do you think?\n"
	.string "We'd make a good team, I'd say.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "I like that answer!\n"
	.string "I'll get done with registration fast!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "You'll give me another chance to form\n"
	.string "a partnership, won't you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Hi, there! Hello!\n"
	.string "I'm {STR_VAR_1}, and I'm a SWIMMER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Check out what I've been raising!\n"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
	.string "Sweet, huh?\n"
	.string "It'd be sweet to form a team, too!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Much obliged!\n"
	.string "I'll get this registration thing done!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "If we meet again, you have to team up\n"
	.string "with me. You'll do that, right?$"

BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

.macro setitemandprice item:req, price:req
	setvar VAR_0x8009, \item
	setvar VAR_0x8008, \price
.endm

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1::
	bufferdecorationname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	setitemandprice DECOR_KISS_POSTER, 16
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	setitemandprice DECOR_KISS_CUSHION, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
	setitemandprice DECOR_SMOOCHUM_DOLL, 32
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	setitemandprice DECOR_TOGEPI_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	setitemandprice DECOR_MEOWTH_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	setitemandprice DECOR_CLEFAIRY_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	setitemandprice DECOR_DITTO_DOLL, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	setitemandprice DECOR_CYNDAQUIL_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	setitemandprice DECOR_CHIKORITA_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	setitemandprice DECOR_TOTODILE_DOLL, 80
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor1

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2::
	bufferdecorationname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	setitemandprice DECOR_LAPRAS_DOLL, 128
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	setitemandprice DECOR_SNORLAX_DOLL, 128
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	setitemandprice DECOR_VENUSAUR_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	setitemandprice DECOR_CHARIZARD_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	setitemandprice DECOR_BLASTOISE_DOLL, 256
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseDecor2

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	setitemandprice ITEM_PROTEIN, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	setitemandprice ITEM_CALCIUM, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	setitemandprice ITEM_IRON, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	setitemandprice ITEM_ZINC, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	setitemandprice ITEM_CARBOS, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	setitemandprice ITEM_HP_UP, 1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseVitamin


BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem::
	bufferitemname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	setitemandprice ITEM_LEFTOVERS, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	setitemandprice ITEM_WHITE_HERB, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	setitemandprice ITEM_QUICK_CLAW, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	setitemandprice ITEM_MENTAL_HERB, 48
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	setitemandprice ITEM_BRIGHT_POWDER, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	setitemandprice ITEM_CHOICE_BAND, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	setitemandprice ITEM_KINGS_ROCK, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	setitemandprice ITEM_FOCUS_BAND, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	setitemandprice ITEM_SCOPE_LENS, 64
	goto BattleFrontier_ExchangeServiceCorner_EventScript_PurchaseHoldItem

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Please choose a prize from this list.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPurchase:
	.string "You've chosen the {STR_VAR_1}.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Here is your prize!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "A large poster with a SMOOCHUM print.$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "A SMOOCHUM cushion.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "A SMOOCHUM DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "A TOGEPI DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "A MEOWTH DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "A CLEFAIRY DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "A DITTO DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "A CYNDAQUIL DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "A CHIKORITA DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "A TOTODILE DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "A large DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "Raises the stat ATTACK of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "Raises the stat SP. ATK of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "Raises the stat DEFENSE of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "Raises the stat SP. DEF of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "Raises the stat SPEED of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "Raises the HP of one POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "A hold item that restores any\n"
	.string "lowered stat.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "A hold item that snaps POKéMON out\n"
	.string "of infatuation.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"
BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Howdy! When it comes to news about\n"
	.string "the BATTLE FRONTIER, I'm no. 1.\p"
	.string "You can think of me as\n"
	.string "the FRONTIER MANIAC.\p"
	.string "Just checking, but you are a TRAINER,\n"
	.string "isn't that right?\p"
	.string "I'll happily share the hottest news\n"
	.string "I gathered about the BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Howdy! Did you swing by to grill me\n"
	.string "about the latest word? Oh, all right!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Well? Well? Well?\p"
	.string "I'm sure my information's been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Let's see now…\p"
	.string "It sounds like the {STR_VAR_1}\n"
	.string "is the hottest place going.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Let's see now…\p"
	.string "It sounds like BATTLE TOWER\n"
	.string "{STR_VAR_1} is the hottest.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this mysterious TRAINER called\n"
	.string "the SALON MAIDEN that runs the place.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Have you battled the SALON MAIDEN?\p"
	.string "When she's measuring up her opponent,\n"
	.string "she apparently uses these POKéMON:\p"
	.string "A PSYCHIC-type PSI POKéMON,\n"
	.string "a FIRE-type VOLCANO POKéMON,\l"
	.string "and a NORMAL-type SLEEPING POKéMON.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Have you battled the SALON MAIDEN\n"
	.string "when she's serious?\p"
	.string "When she's battling flat out,\n"
	.string "she apparently uses these POKéMON:\p"
	.string "A DRAGON & PSYCHIC EON POKéMON,\n"
	.string "an ELECTRIC-type THUNDER POKéMON,\l"
	.string "and a NORMAL-type SLEEPING POKéMON.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this flamboyant TRAINER called\n"
	.string "the DOME ACE that runs the place.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Have you battled the DOME ACE?\p"
	.string "When he's treating the opponent\n"
	.string "lightly, he uses these three POKéMON:\p"
	.string "A DRAGON & FLYING DRAGON POKéMON,\n"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
	.string "and a FIRE & FLYING FLAME POKéMON.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Have you battled the DOME ACE\n"
	.string "when he's serious?\p"
	.string "When he's demonstrating his strategy,\n"
	.string "he uses these three POKéMON:\p"
	.string "A DRAGON & FLYING EON POKéMON,\n"
	.string "a WATER & GROUND MUD FISH POKéMON,\l"
	.string "and a STEEL- & PSYCHIC-type IRON LEG\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this freaky TRAINER called\n"
	.string "the FACTORY HEAD that runs the place.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Have you battled the FACTORY HEAD\n"
	.string "already?\p"
	.string "Let me think… When he goes to battle,\n"
	.string "he just gets three rental POKéMON.\p"
	.string "He battles under pretty much the same\n"
	.string "conditions as you.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Have you battled the FACTORY HEAD\n"
	.string "when he's serious?\p"
	.string "When he goes seriously to battle,\n"
	.string "he still gets three rental POKéMON.\p"
	.string "He battles under virtually the same\n"
	.string "conditions as you.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this scary TRAINER called\n"
	.string "the PIKE QUEEN that runs the place.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Have you battled the PIKE QUEEN\n"
	.string "before?\p"
	.string "When she's in a good mood, they say\n"
	.string "she uses these three POKéMON:\p"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
	.string "a BUG & ROCK MOLD POKéMON,\l"
	.string "and a WATER-type TENDER POKéMON.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Have you battled the PIKE QUEEN\n"
	.string "when she's serious?\p"
	.string "When she's seriously annoyed, they say\n"
	.string "she uses these three POKéMON:\p"
	.string "A POISON-type FANG SNAKE POKéMON,\n"
	.string "a STEEL & GROUND IRON SNAKE POKéMON,\l"
	.string "and a WATER- & FLYING-type ATROCIOUS\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this cute TRAINER called\n"
	.string "the ARENA TYCOON that runs the place.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Have you battled the ARENA TYCOON\n"
	.string "before?\p"
	.string "When she's assessing the foe's ability,\n"
	.string "she supposedly uses these POKéMON:\p"
	.string "A BUG & FIGHTING SINGLE HORN POKéMON,\n"
	.string "a DARK-type MOONLIGHT POKéMON,\l"
	.string "and a BUG & GHOST SHED POKéMON.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Have you battled the ARENA TYCOON\n"
	.string "when she's serious?\p"
	.string "When she battles for keeps,\n"
	.string "she supposedly uses these POKéMON:\p"
	.string "A DARK-type MOONLIGHT POKéMON,\n"
	.string "a GHOST & POISON SHADOW POKéMON\l"
	.string "and a GRASS- & FIGHTING-type\l"
	.string "MUSHROOM POKéMON.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this sinister TRAINER called\n"
	.string "the PALACE MAVEN that runs the place.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Have you battled the PALACE MAVEN\n"
	.string "before?\p"
	.string "When he's testing the opponent's\n"
	.string "spirit, he's said to use these POKéMON:\p"
	.string "A POISON & FLYING-type BAT POKéMON,\n"
	.string "a NORMAL-type LAZY POKéMON, and a\l"
	.string "WATER- & ICE-type TRANSPORT POKéMON.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Have you battled the PALACE MAVEN\n"
	.string "when he's serious?\p"
	.string "When he throws his entire might into\n"
	.string "battle, he's said to use these POKéMON:\p"
	.string "A FIRE-type LEGENDARY POKéMON,\n"
	.string "a NORMAL-type LAZY POKéMON,\l"
	.string "and a WATER-type AURORA POKéMON.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top TRAINERS that SCOTT\n"
	.string "calls the FRONTIER BRAINS is there.\p"
	.string "It's this fiery-hot TRAINER called\n"
	.string "the PYRAMID KING that runs the place.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Have you battled the PYRAMID KING\n"
	.string "before?\p"
	.string "When he's checking the foe's power,\n"
	.string "he apparently uses these POKéMON:\p"
	.string "A ROCK-type ROCK PEAK POKéMON,\n"
	.string "an ICE-type ICEBERG POKéMON,\l"
	.string "and a STEEL-type IRON POKéMON.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Have you battled the PYRAMID KING\n"
	.string "when he's serious?\p"
	.string "When he's pumped with hot power,\n"
	.string "he apparently uses these POKéMON:\p"
	.string "An ICE & FLYING FREEZE POKéMON, an\n"
	.string "ELECTRIC & FLYING ELECTRIC POKéMON,\l"
	.string "and a FIRE- & FLYING-type FLAME\l"
	.string "POKéMON.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Sure, there are several places where\n"
	.string "you can enter DOUBLE BATTLES.\p"
	.string "But the DOUBLE BATTLE ROOMS of\n"
	.string "the BATTLE TOWER are, like, basic!\p"
	.string "They're where you should learn about\n"
	.string "how DOUBLE BATTLES are played here\l"
	.string "in the BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Watch yourself in the battles here.\p"
	.string "I hear there are TRAINERS that have\n"
	.string "strategies they developed just for\l"
	.string "DOUBLE BATTLES.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Once you're confident and comfortable\n"
	.string "with DOUBLE BATTLES here, you should\l"
	.string "think about challenging other places\l"
	.string "offering DOUBLE BATTLES.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "All sorts of TRAINERS gather in\n"
	.string "the BATTLE SALON.\p"
	.string "Just think--you may run into your\n"
	.string "friends or followers!\l"
	.string "You should look carefully!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "If you're with a friend, head for the\n"
	.string "LINK MULTI BATTLE ROOM.\p"
	.string "If you play with a strong friend,\n"
	.string "you can expect to see tough foes!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "What amazing news-gathering power!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "What amazing powers of observation!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "What amazing power of persuasion!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…What is this place?\n"
	.string "It's scaring me…$"

BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…What's that you want?\p"
	.string "Can't you see we're kind of busy here?\n"
	.string "Can't your business wait till later?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…Huh?\n"
	.string "You look to me like a tough TRAINER.\p"
	.string "Heheh…\n"
	.string "Listen, I have this proposition.\p"
	.string "We have a little group going here,\n"
	.string "and we play a little game with what\l"
	.string "goes on in the BATTLE FRONTIER.\p"
	.string "The rules are really simple.\p"
	.string "First, we pick one of the facilities\n"
	.string "in the BATTLE FRONTIER.\p"
	.string "Then, we each pick a different TRAINER\n"
	.string "who's taking that facility's challenge,\l"
	.string "and bet with our Battle Points.\p"
	.string "The guy who bet on the TRAINER with\n"
	.string "the best record takes all the Battle\l"
	.string "Points in the pool.\p"
	.string "Sounds simple, huh?\n"
	.string "So, anyway…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "TOWER's SINGLE BATTLE ROOMS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "TOWER's DOUBLE BATTLE ROOMS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "TOWER's MULTI BATTLE ROOMS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "DOME's SINGLE BATTLE Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "DOME's DOUBLE BATTLE Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "FACTORY's Battle Swap Single Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "FACTORY's Battle Swap Double Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "PALACE's SINGLE BATTLE HALLS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be challenging the BATTLE\l"
	.string "PALACE's DOUBLE BATTLE HALLS.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "ARENA's Set KO Tourney.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE PIKE's\l"
	.string "Battle Choice.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "What I'm looking for is a TRAINER who's\n"
	.string "going to be entering the BATTLE\l"
	.string "PYRAMID's Battle Quest.\p"
	.string "But so far, I haven't seen a TRAINER\n"
	.string "that has that winning quality.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "I'll see to it that you benefit, too.\n"
	.string "So how about it?\l"
	.string "How about entering that event for me?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "All right, that's perfect.\n"
	.string "So, uh… How about spotting me some\l"
	.string "of your Battle Points?\p"
	.string "Trust me, I'll show you my gratitude\n"
	.string "afterward.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Great, great!\n"
	.string "So, how much can you spot me?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh, no, no, no!\n"
	.string "You don't have enough Battle Points!\p"
	.string "I wish you wouldn't monkey around and\n"
	.string "waste everyone's time!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Heheh! Thanks much!\n"
	.string "So, off you go!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Get to the BATTLE TOWER's\n"
	.string "SINGLE BATTLE ROOMS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Get to the BATTLE TOWER's\n"
	.string "DOUBLE BATTLE ROOMS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Get to the BATTLE TOWER's\n"
	.string "MULTI BATTLE ROOMS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Get to the BATTLE DOME's\n"
	.string "SINGLE BATTLE Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Get to the BATTLE DOME's\n"
	.string "DOUBLE BATTLE Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Get to the BATTLE FACTORY's\n"
	.string "Battle Swap Single Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Get to the BATTLE FACTORY's\n"
	.string "Battle Swap Double Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Get to the BATTLE PALACE's\n"
	.string "SINGLE BATTLE HALLS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Get to the BATTLE PALACE's\n"
	.string "DOUBLE BATTLE HALLS pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Get to the BATTLE ARENA's\n"
	.string "Set KO Tourney pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Get to the BATTLE PIKE's\n"
	.string "Battle Choice pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Get to the BATTLE PYRAMID's\n"
	.string "Battle Quest pronto!\p"
	.string "It's a must-win situation!\n"
	.string "Don't blow your chance!\l"
	.string "Both of our futures depend on you!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, it's you…\n"
	.string "Nice try…\p"
	.string "I hate to break it to you, but I can't\n"
	.string "return your Battle Points…\p"
	.string "I guess we'll have to let it motivate\n"
	.string "us to try harder next time!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh, yes!\n"
	.string "Hello there, champ!\p"
	.string "I knew you could!\n"
	.string "I knew you would!\l"
	.string "We're both big winners!\p"
	.string "I'll return your Battle Points and,\n"
	.string "of course, a little extra from me!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} obtained\n"
	.string "{STR_VAR_1} Battle Points.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "If you're up for another challenge,\n"
	.string "please do think of me!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Not interested?! You shouldn't be\n"
	.string "so afraid to take a chance!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "I backed the wrong TRAINER again!\p"
	.string "Maybe I should be battling normally\n"
	.string "like everyone else…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "That TRAINER…\p"
	.string "He's good, but he gets rattled too\n"
	.string "easily to survive the BATTLE DOME…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Giggle!\n"
	.string "I know a winner when I see one!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Those TRAINERS…\n"
	.string "What are they doing?\l"
	.string "They should be taking challenges.$"
BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Ehehe!\n"
	.string "I can tell what POKéMON are thinking!\p"
	.string "Please!\n"
	.string "Can I see your POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Boo!\n"
	.string "Cheapie!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself whether\l"
	.string "or not it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "That's silly! An EGG is asleep!\n"
	.string "I can't talk to it!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "How charming!\n"
	.string "That little lady claims she can\l"
	.string "understand POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "I have this feeling that the little girl\n"
	.string "is saying something profound.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "I know something!\p"
	.string "That little girl plays at the red house\n"
	.string "a lot!$"

BattleFrontier_Lounge7_MapScripts::
	.byte 0

@special ChooseMonForMoveTutor
BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_SOFT_BOILED
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_DREAM_EATER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_MEGA_KICK
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_BODY_SLAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_COUNTER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SNORE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MUD_SLAP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SWIFT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ENDURE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_PSYCH_UP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end


BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "You couldn't tell it from looking now,\n"
	.string "but I used to be one tough TRAINER.\p"
	.string "I had a reputation as the toughest\n"
	.string "BEAUTY around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What is it now?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that blowhard woman over\n"
	.string "there. I'm actually talented!\p"
	.string "Let me prove it to you.\n"
	.string "I can teach your POKéMON special and\l"
	.string "yet cute moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Are you back to learn special and\n"
	.string "yet cute POKéMON moves?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Fine, fine, look here!\n"
	.string "Which move should I teach?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "The move {STR_VAR_1}, is it?\n"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Fine, fine, now pick the POKéMON\n"
	.string "I should teach the move to.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "What the…\n"
	.string "You haven't got enough Battle Points!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Do you see how skilled I am now?\n"
	.string "I'll take your Battle Points, thanks!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "I know it's hard to see now, but I used\n"
	.string "to be one fantastic TRAINER.\p"
	.string "I had a reputation as the most\n"
	.string "invincible SWIMMER around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that buffoonish woman over\n"
	.string "there. I'm actually experienced!\p"
	.string "I can prove it to you.\n"
	.string "I can teach your POKéMON hard and\l"
	.string "yet pretty moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Have you come to learn hard and\n"
	.string "yet pretty POKéMON moves?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Those ladies, the way they bad-mouth\n"
	.string "each other, you probably think that\l"
	.string "they don't get along.\p"
	.string "But if that were true, they wouldn't\n"
	.string "stay out here together, would they?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "When I was just a wee YOUNGSTER,\n"
	.string "those ladies were strong and beautiful.\p"
	.string "They were idols among us TRAINERS.\p"
	.string "Even now, age hasn't dulled their\n"
	.string "abilities.\p"
	.string "In fact, their POKéMON moves have\n"
	.string "grown even more polished.\p"
	.string "But… For some reason, I can't help\n"
	.string "but feel this…\p"
	.string "Time is so cruel…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Recovers up to\n"
	.string "half the user's\n"
	.string "maximum HP.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Inflicts damage\n"
	.string "identical to the\n"
	.string "user's level.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Recovers half the\n"
	.string "damage inflicted\n"
	.string "on a sleeping foe.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "A strong punch\n"
	.string "thrown with\n"
	.string "incredible power.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "An extremely\n"
	.string "powerful kick with\n"
	.string "intense force.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "A full-body slam\n"
	.string "that may cause\n"
	.string "paralysis.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Large boulders\n"
	.string "are hurled. May\n"
	.string "cause flinching.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Retaliates any\n"
	.string "physical hit with\n"
	.string "double the power.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "A weak jolt of\n"
	.string "electricity that\n"
	.string "paralyzes the foe.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "A fighting dance\n"
	.string "that sharply\n"
	.string "raises ATTACK.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Curls up to con-\n"
	.string "ceal weak spots\n"
	.string "and raise DEFENSE.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "A loud attack\n"
	.string "that can be used\n"
	.string "only while asleep.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Hurls mud in the\n"
	.string "foe's face to re-\n"
	.string "duce its accuracy.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Sprays star-\n"
	.string "shaped rays\n"
	.string "that never miss.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "A chilling attack\n"
	.string "that lowers the\n"
	.string "foe's SPEED.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Endures any at-\n"
	.string "tack for 1 turn,\n"
	.string "leaving 1HP.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copies the foe's\n"
	.string "effect(s) and\n"
	.string "gives to the user.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "An icy punch\n"
	.string "that may\n"
	.string "freeze the foe.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "An electrified\n"
	.string "punch that may\n"
	.string "paralyze the foe.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "A fiery punch\n"
	.string "that may burn\n"
	.string "the foe.$"
BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "This is the BATTLE TOWER!\n"
	.string "Keep the win streak as the toughest\l"
	.string "TRAINER!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "This is the BATTLE PALACE!\n"
	.string "Keep your eyes on POKéMON battles!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "This is the BATTLE ARENA!\n"
	.string "Let the toughest teams gather!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "This is the BATTLE PYRAMID!\n"
	.string "Advance through the Battle Quest!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "BATTLE FRONTIER RANKING HALL\n"
	.string "Set your sights on new records!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
	.string "Exchange your Battle Points!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Wow!\n"
	.string "It's huge!\p"
	.string "The BATTLE TOWER feels special.\n"
	.string "It's different from the others.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "My grand ambition is to conquer both\n"
	.string "the BATTLE FRONTIER and the POKéMON\l"
	.string "LEAGUE.\p"
	.string "And if my dream comes true…\p"
	.string "I… I'm going to ask MIMI next door\n"
	.string "if she will be friends with me!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "The BATTLE PYRAMID's too harsh!\n"
	.string "I just can't make it to the top!\p"
	.string "Since I'm out of options, maybe I can\n"
	.string "climb the outside…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "I thrive in darkness…\n"
	.string "Yes… What is worthy of me?\l"
	.string "None other than the BATTLE PYRAMID…\p"
	.string "What say you to wandering in darkness\n"
	.string "and in utter and total desperation?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "I didn't sleep for a week, but then\n"
	.string "I put together the ultimate team!\p"
	.string "I can't see myself losing, no joke.\n"
	.string "We're storming the BATTLE ARENA!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Did SCOTT bring you here, too?\n"
	.string "What is it with that guy?\p"
	.string "It sounds like he really does know\n"
	.string "how to spot talented TRAINERS, but…\p"
	.string "I've never seen him battling in person\n"
	.string "ever.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "I believe in you, little buddy!\p"
	.string "I'll make my little ZIGG any favorite\n"
	.string "tasty treats you like if you win!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON looks vacant…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "People call me a busybody,\n"
	.string "but I can't help it.\p"
	.string "Your hat's on crooked!\n"
	.string "Oh, no, trash on the ground!\l"
	.string "Oops, it's almost dinnertime!\p"
	.string "I don't know if I can stand to just\n"
	.string "watch at the BATTLE PALACE…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "I may not look that impressive now,\n"
	.string "but I once beat a GYM LEADER.\p"
	.string "Who knows, maybe I should give it\n"
	.string "another shot at glory.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "I'm fast on my BIKE, and that goes for\n"
	.string "the way I battle, too.\p"
	.string "I win matches in the blink of\n"
	.string "an eye!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "I'm better than my daddy\n"
	.string "at POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Go on, my baby sweetie!\n"
	.string "Go rack up some wins for Daddy!\p"
	.string "You're just like your mother,\n"
	.string "so you'll be dominating!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "It wasn't easy getting here,\n"
	.string "but I'd heard about this knockout\l"
	.string "pretty girl at the BATTLE ARENA.\p"
	.string "Instead of her, do you know what\n"
	.string "I found?\p"
	.string "A whole teeming mob of sweaty,\n"
	.string "stinky, and primitive martial artists!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "I sometimes see this really important-\n"
	.string "looking old man going in there.\p"
	.string "He has these really awesome POKéMON.\n"
	.string "He seems really nice, though.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Do you know it?\n"
	.string "The legend of the BATTLE PYRAMID?\p"
	.string "When there comes a confident TRAINER\n"
	.string "reaching for the golden pinnacle,\l"
	.string "there shall appear a man among men.\p"
	.string "Don't know that legend?\n"
	.string "Well, of course not!\l"
	.string "I just made it up!\p"
	.string "What's it supposed to mean?\n"
	.string "That, my friend, I can't say!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Man! Oh man!\n"
	.string "I've never lost once before!\p"
	.string "But I got wiped out with no saving\n"
	.string "grace at all!\p"
	.string "And then I'm told I don't have any\n"
	.string "talent?! Man!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "This guy ran into a horribly tough\n"
	.string "TRAINER while he was on the BATTLE\l"
	.string "TOWER challenge.\p"
	.string "Now look at him…\p"
	.string "You need to be cautious if you ever\n"
	.string "decide to go to the BATTLE TOWER.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Yes!\n"
	.string "I've finally got enough Battle Points!\p"
	.string "I guess I'll trade for another giant\n"
	.string "plush DOLL!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh, yeah, okay!\n"
	.string "So this is the RANKING HALL!\p"
	.string "I'd like to go down in history as\n"
	.string "a super champ and have my name\l"
	.string "recorded here for posterity.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "With you by my side, I can do anything.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, darling, you are so wonderful!\p"
	.string "Ooh, I just can't wait anymore!\p"
	.string "Let's go to a MULTI BATTLE ROOM\n"
	.string "right this instant!\p"
	.string "If we get together in the BATTLE SALON,\n"
	.string "the power of our love will overcome\l"
	.string "everyone we meet.\p"
	.string "Why, before us, darling, everything\n"
	.string "will topple like dominoes!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "The BATTLE FRONTIER isn't exclusively\n"
	.string "for tough TRAINERS.\p"
	.string "Many people with special abilities\n"
	.string "have been invited, it seems.\p"
	.string "That man SCOTT…\p"
	.string "He may have built this place to serve\n"
	.string "a bigger objective…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Excuse me, young one.\n"
	.string "Have you good eyesight?\p"
	.string "There is an odd tree past here, and to\n"
	.string "my tired eyes it seems to wiggle.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Excuse me, young one.\n"
	.string "Have you a good memory?\p"
	.string "I have this feeling there once was\n"
	.string "an odd tree past here.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "I…\n"
	.string "I saw it!\p"
	.string "There was a sticky sort of a POKéMON\n"
	.string "with a long tail up ahead!\p"
	.string "It was hiding under a boulder, and\n"
	.string "it kept staring at me!$"
FarawayIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FarawayIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Interior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FarawayIsland_Interior_OnFrame
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, FarawayIsland_Interior_OnReturnToField
	.byte 0

FarawayIsland_Interior_OnReturnToField:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TrySetMewAboveGrass
	end

FarawayIsland_Interior_EventScript_TrySetMewAboveGrass::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_SetMewAboveGrass
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_SetMewAboveGrass
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_SetMewAboveGrass
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, FarawayIsland_Interior_EventScript_SetMewAboveGrass
	return

FarawayIsland_Interior_EventScript_SetMewAboveGrass::
	setvar VAR_0x8004, 1
	special SetMewAboveGrass
	return

FarawayIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TryRemoveMew
	end

FarawayIsland_Interior_EventScript_TryRemoveMew::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

FarawayIsland_Interior_OnTransition:
	setvar VAR_FARAWAY_ISLAND_STEP_COUNTER, 0
	setvar VAR_TEMP_1, 1
	call_if_unset FLAG_CAUGHT_MEW, FarawayIsland_Interior_EventScript_TryShowMew
	end

FarawayIsland_Interior_EventScript_TryShowMew::
	goto_if_set FLAG_DEFEATED_MEW, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEW
	setvar VAR_TEMP_1, 0
	return

FarawayIsland_Interior_OnFrame:
	map_script_2 VAR_TEMP_1, 0, FarawayIsland_Interior_EventScript_FindMew
	.2byte 0

FarawayIsland_Interior_EventScript_FindMew::
	lockall
	playse SE_PIN
	applymovement LOCALID_FARAWAY_ISLAND_MEW, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FARAWAY_ISLAND_MEW, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewMoveAndHide
	waitmovement 0
	copyobjectxytoperm LOCALID_FARAWAY_ISLAND_MEW
	setvar VAR_TEMP_1, 1
	releaseall
	end

FarawayIsland_Interior_Movement_MewMoveAndHide:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	set_invisible
	step_end

FarawayIsland_Interior_Movement_MewAppear:
	set_visible
	step_end

FarawayIsland_Interior_Movement_MewFloatUpNorth:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_down
	walk_in_place_down
	step_end

FarawayIsland_Interior_Movement_MewFloatUpSouth:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_up
	walk_in_place_up
	step_end

FarawayIsland_Interior_Movement_MewFloatUpWest:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_right
	walk_in_place_right
	step_end

FarawayIsland_Interior_Movement_MewFloatUpEast:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_left
	walk_in_place_left
	step_end

FarawayIsland_Interior_EventScript_Mew::
	lock
	faceplayer
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewAppear
	waitmovement 0
	setvar VAR_0x8004, 0
	special SetMewAboveGrass
	message FarawayIsland_Interior_Text_Mew
	waitse
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	call_if_eq VAR_FACING, DIR_NORTH, FarawayIsland_Interior_EventScript_FoundMewNorth
	call_if_eq VAR_FACING, DIR_SOUTH, FarawayIsland_Interior_EventScript_FoundMewSouth
	call_if_eq VAR_FACING, DIR_WEST, FarawayIsland_Interior_EventScript_FoundMewWest
	call_if_eq VAR_FACING, DIR_EAST, FarawayIsland_Interior_EventScript_FoundMewEast
	special DestroyMewEmergingGrassSprite
	delay 40
	waitmoncry
	seteventmon SPECIES_MEW, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_MewDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_PlayerOrMewRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_PlayerOrMewRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, FarawayIsland_Interior_EventScript_PlayerOrMewRan
	setflag FLAG_CAUGHT_MEW
	release
	end

FarawayIsland_Interior_EventScript_MewDefeated::
	setflag FLAG_DEFEATED_MEW
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

FarawayIsland_Interior_EventScript_PlayerOrMewRan::
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

FarawayIsland_Interior_EventScript_FoundMewNorth::
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpNorth
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_FoundMewSouth::
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpSouth
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_FoundMewWest::
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpWest
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_FoundMewEast::
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpEast
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_HideMewWhenGrassCut::
	lockall
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_MEW
	removeobject LOCALID_FARAWAY_ISLAND_MEW
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded:
	.string "The feeling of being watched faded…$"
IslandCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IslandCave_OnResume
	map_script MAP_SCRIPT_ON_LOAD, IslandCave_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, IslandCave_OnTransition
	.byte 0

IslandCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IslandCave_EventScript_TryRemoveRegice
	end

IslandCave_EventScript_TryRemoveRegice::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

IslandCave_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_HideRegiEntrance
	end

IslandCave_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

IslandCave_OnTransition:
	setflag FLAG_LANDMARK_ISLAND_CAVE
	call IslandCave_EventScript_ClearSteps
	call_if_unset FLAG_DEFEATED_REGICE, IslandCave_EventScript_ShowRegice
	end

IslandCave_EventScript_ShowRegice::
	clearflag FLAG_HIDE_REGICE
	return

IslandCave_EventScript_OpenRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_SYS_BRAILLE_REGICE_COMPLETED
	end

IslandCave_EventScript_CaveEntranceMiddle::
	lockall
	call_if_set FLAG_TEMP_REGICE_PUZZLE_FAILED, IslandCave_EventScript_ClearSteps
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_BigHoleInWall
	braillemessage IslandCave_Braille_RunLapAroundWall
	setflag FLAG_TEMP_REGICE_PUZZLE_STARTED
	special ShouldDoBrailleRegicePuzzle
	goto IslandCave_EventScript_CloseBrailleMsg
	end

IslandCave_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

IslandCave_EventScript_CaveEntranceSide::
	lockall
	call_if_set FLAG_TEMP_REGICE_PUZZLE_FAILED, IslandCave_EventScript_ClearSteps
	braillemessage IslandCave_Braille_RunLapAroundWall
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_CloseBrailleMsg
	setflag FLAG_TEMP_REGICE_PUZZLE_STARTED
	special ShouldDoBrailleRegicePuzzle
	goto IslandCave_EventScript_CloseBrailleMsg
	end

IslandCave_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end

IslandCave_EventScript_ClearSteps::
	setvar VAR_REGICE_STEPS_1, 0
	setvar VAR_REGICE_STEPS_2, 0
	setvar VAR_REGICE_STEPS_3, 0
	clearflag FLAG_TEMP_REGICE_PUZZLE_FAILED
	return

IslandCave_EventScript_Regice::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGICE, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IslandCave_EventScript_DefeatedRegice
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IslandCave_EventScript_RanFromRegice
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IslandCave_EventScript_RanFromRegice
	setflag FLAG_DEFEATED_REGICE
	release
	end

IslandCave_EventScript_DefeatedRegice::
	setflag FLAG_DEFEATED_REGICE
	goto Common_EventScript_RemoveStaticPokemon
	end

IslandCave_EventScript_RanFromRegice::
	setvar VAR_0x8004, SPECIES_REGICE
	goto Common_EventScript_LegendaryFlewAway
	end
MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "UNCLE: It's because of POKéMON that\n"
	.string "this boy's got more pep, I suppose…\l"
	.string "But he's become a bit too peppy…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "WALLY: Aww, UNCLE, please?\p"
	.string "I want to challenge this GYM and see\n"
	.string "how much better I've become.\p"
	.string "Please? May I, please?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "UNCLE: Now hold on, WALLY.\p"
	.string "Since you started living with POKéMON,\n"
	.string "you have grown quite a lot stronger.\p"
	.string "But don't you think you're pushing it\n"
	.string "to suddenly challenge a GYM?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY: I'm not pushing it.\p"
	.string "If I combine forces with RALTS,\n"
	.string "we can beat anyone!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "WALLY: Oh! Hi, {PLAYER}!\p"
	.string "I've gotten a lot stronger since\n"
	.string "we met.\p"
	.string "{PLAYER}, I want you and my UNCLE to\n"
	.string "understand that.\p"
	.string "{PLAYER}, please, will you have\n"
	.string "a battle with me?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY: Oh… If you won't battle me,\n"
	.string "{PLAYER}, my UNCLE won't know that I've\l"
	.string "become really strong.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "UNCLE: {PLAYER}{KUN}, was it?\n"
	.string "On WALLY's behalf, can I ask you to\l"
	.string "battle with him just this once?\p"
	.string "I don't think he's going to listen to\n"
	.string "any reason the way he is now.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "WALLY: {PLAYER}, please!\n"
	.string "Battle with me, please.$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY: {PLAYER}, thank you.\p"
	.string "Okay… Here I come!$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "I lost…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "WALLY: UNCLE…\n"
	.string "I'll go back to VERDANTURF…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, thank you.\n"
	.string "Being a TRAINER is tough, isn't it?\p"
	.string "It's not enough just to have POKéMON\n"
	.string "and make them battle. That isn't what\l"
	.string "being a real TRAINER is about.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "UNCLE: WALLY, there's no need to be so\n"
	.string "down on yourself.\p"
	.string "Why, what's keeping you from becoming\n"
	.string "stronger and stronger?\p"
	.string "Come on, let's go home.\n"
	.string "Everyone's waiting for you.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "UNCLE: {PLAYER}{KUN}, it just dawned on me\n"
	.string "that you must be the TRAINER who kept\l"
	.string "an eye out for WALLY when he caught\l"
	.string "his POKéMON.\p"
	.string "Why don't you visit us in VERDANTURF\n"
	.string "sometime?\l"
	.string "I'm sure WALLY would enjoy it.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "WALLY: Oh, hello, {PLAYER}!\p"
	.string "I just wanted to tell you that\n"
	.string "my uncle bought me a POKéNAV!\p"
	.string "Now I can get in touch with you\n"
	.string "anytime, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MauvilleCity_Text_RegisteredWally:
	.string "Registered WALLY\n"
	.string "in the POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Hehe…\n"
	.string "I was watching that match!\p"
	.string "You're friends with that boy WALLY,\n"
	.string "aren't you?\p"
	.string "But you didn't hold anything back\n"
	.string "and beat him impressively.\p"
	.string "Yeah! That's what a real POKéMON\n"
	.string "battle is all about!\p"
	.string "I idolize TRAINERS like that!\p"
	.string "… … … … … …\n"
	.string "I'll be cheering for you!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON: Oh, {PLAYER}{KUN}!\n"
	.string "You look like you have a lot of zip!\l"
	.string "That's a good thing, wahahahaha!\p"
	.string "Fine! I've decided!\n"
	.string "I need a favor, {PLAYER}{KUN}!\p"
	.string "MAUVILLE CITY has an underground\n"
	.string "sector called NEW MAUVILLE.\p"
	.string "{PLAYER}{KUN}, I'd like you to go there and\n"
	.string "switch off the GENERATOR.\p"
	.string "The GENERATOR has been running a bit\n"
	.string "haywire. It's getting unsafe.\p"
	.string "Here, this is the KEY to get into\n"
	.string "NEW MAUVILLE.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON: Don't you worry about it.\n"
	.string "It won't be a challenge to you.\p"
	.string "The entrance to NEW MAUVILLE is just\n"
	.string "a short SURF away from ROUTE 110.\p"
	.string "That's it, then, you have my trust!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON: Wahahahaha!\p"
	.string "I knew it, {PLAYER}{KUN}! I knew I'd made\n"
	.string "the right choice asking you!\p"
	.string "This is my thanks--a TM containing\n"
	.string "THUNDERBOLT!\p"
	.string "Go on, you've earned it!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON: Wahahahaha!\p"
	.string "It pleases me to no end to see\n"
	.string "the young step up and take charge!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "You know, it's cool to have POKéMON\n"
	.string "battles and stuff…\p"
	.string "But if your POKéMON gets hurt,\n"
	.string "you have to nurse it back to health.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "The roads of this town stretch north\n"
	.string "and south, and east and west.\p"
	.string "Because of that, we get all sorts of\n"
	.string "people coming through.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Have you been to RYDEL'S CYCLES yet?\p"
	.string "RYDEL, the owner, is a very generous\n"
	.string "man.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Even if you're riding a BIKE,\n"
	.string "wild POKéMON could jump you.$"

MauvilleCity_Text_CitySign:
	.string "MAUVILLE CITY\n"
	.string "“The bright and shiny city of fun!”$"

MauvilleCity_Text_GymSign:
	.string "MAUVILLE CITY POKéMON GYM\n"
	.string "LEADER: WATTSON\l"
	.string "“The cheerfully electrifying man!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Ride in gravel and shake up your\n"
	.string "soul!”\l"
	.string "RYDEL'S CYCLES$"

MauvilleCity_Text_GameCornerSign:
	.string "“The play spot for all!”\n"
	.string "MAUVILLE GAME CORNER$"

MauvilleCity_Text_ExplainTV:
	.string "Hi, do you check out TV at all?\p"
	.string "They've added a bunch of cool new\n"
	.string "shows recently.\p"
	.string "TV is so cool. I've seen my friends on\n"
	.string "TV just out of the blue.\p"
	.string "And, sometimes, they even put you on TV\n"
	.string "without telling you.\p"
	.string "I wish I would be on TV sometime.\p"
	.string "That's why I think you should check\n"
	.string "out TVs whenever you can.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Hi, have you been checking out TVs?$"
MauvilleCity_GameCorner_MapScripts::
	.byte 0

	@ Game Corner prices
	.set TM_DOUBLE_TEAM_COINS, 1500
	.set TM_PSYCHIC_COINS, 3500
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_ICE_BEAM_COINS, 4000
	.set DOLL_COINS, 1000

	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

MauvilleCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase::
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize

MauvilleCity_GameCorner_EventScript_ChooseDollPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
	end

MauvilleCity_GameCorner_EventScript_TreeckoDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_TorchicDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_MudkipDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize

MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TREECKO_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTorchicDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TORCHIC_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_BuyMudkipDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_MUDKIP_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
	call Common_EventScript_NoRoomForDecor
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

MauvilleCity_GameCorner_EventScript_CancelDollSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize

MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_TMDoubleTeam
	case 1, MauvilleCity_GameCorner_EventScript_TMPsychic
	case 2, MauvilleCity_GameCorner_EventScript_TMFlamethrower
	case 3, MauvilleCity_GameCorner_EventScript_TMThunderbolt
	case 4, MauvilleCity_GameCorner_EventScript_TMIceBeam
	case 5, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
	end

MauvilleCity_GameCorner_EventScript_TMDoubleTeam::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM32
	setvar VAR_0x8004, ITEM_TM32
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMPsychic::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMFlamethrower::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_TMIceBeam::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize

MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelTMSelect
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam
	case 2, MauvilleCity_GameCorner_EventScript_BuyTMPsychic
	case 3, MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower
	case 4, MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt
	case 5, MauvilleCity_GameCorner_EventScript_BuyTMIceBeam
	end

MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM32
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM32
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMPsychic::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_PSYCHIC
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_PSYCHIC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_FLAMETHROWER
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_BuyTMIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_ICE_BEAM
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

MauvilleCity_GameCorner_EventScript_CancelTMSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_Woman2::
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman::
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal::
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase::
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "This is MAUVILLE GAME CORNER.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "Okay, you wanted some COINS for\n"
	.string "the games?\p"
	.string "But you don't have a COIN CASE for\n"
	.string "stowing the COINS.$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
	.string "Were you looking for COINS?\p"
	.string "It's ¥1000 for 50 COINS.\n"
	.string "Would you like some?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Thank you very much!\n"
	.string "Here are your COINS!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

MauvilleCity_GameCorner_Text_CoinCaseIsFull:
	.string "Oh?\n"
	.string "Your COIN CASE is full.$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
	.string "Oh… You don't need COINS, then?\n"
	.string "Good luck on your adventure!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Welcome.\p"
	.string "You can exchange your COINS for\n"
	.string "prizes here.$"

MauvilleCity_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

MauvilleCity_GameCorner_Text_NotEnoughCoins:
	.string "You don't have enough COINS.$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_OhIsThatSo:
	.string "Oh, is that so? \n"
	.string "You need to save some COINS before\l"
	.string "coming back here.$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
	.string "So your choice is {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_HereYouGo:
	.string "Here you go!$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
	.string "Oh, you can't carry any more than that.$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
	.string "I made a mistake and got two of\n"
	.string "the same DOLLS.\p"
	.string "Would you like one of them?$"

MauvilleCity_GameCorner_Text_HereYouGo2:
	.string "Here you go!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow:
	.string "Huh?\n"
	.string "You want it, but not right now?$"

MauvilleCity_GameCorner_Text_DontBeNegative:
	.string "Oh, don't be so negative!\n"
	.string "You can have this!$"

MauvilleCity_GameCorner_Text_CantWinJackpot:
	.string "There's a prize I want, but I can't win\n"
	.string "the jackpot.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "Hey, kid, if you want to play here,\n"
	.string "you need a COIN CASE.\p"
	.string "I think the young lady next door\n"
	.string "had one. Go see her!$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "My luck can only last so long.\n"
	.string "This is too much for me.\l"
	.string "Here, take some COINS!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "MAUVILLE has something for\n"
	.string "everyone.\p"
	.string "For me, it's the GAME CORNER.$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
	.string "The ROULETTE tables have different\n"
	.string "rates.\p"
	.string "Check your COINS if you're going to\n"
	.string "pick a table.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "It's easy to lose track of time in here. \n"
	.string "I should get back to work.$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "COINS are needed to play here\n"
	.string "in the GAME CORNER.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
	.string "This ROULETTE thing…\n"
	.string "It's rather demanding.\p"
	.string "Win or lose, it's only by luck.$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "Up to three COINS can be used to play\n"
	.string "the SLOTS.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7:
	.string "It's very difficult to make it stop\n"
	.string "right on “7.”\p"
	.string "If it stops on “7” during the REEL TIME\n"
	.string "bonus game, you'll receive extra COINS.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "Here's some information for you\n"
	.string "about the SLOTS.\p"
	.string "The more lightning bolts you stock,\n"
	.string "the more REEL TIME chances you get.\p"
	.string "In a game with the maximum five\n"
	.string "REEL TIME chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 COINS, but it's\n"
	.string "very difficult to get.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "You can't play if you don't have\n"
	.string "a COIN CASE.$"

MossdeepCity_SpaceCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_OnFrame
	.byte 0

MossdeepCity_SpaceCenter_2F_OnTransition:
	call_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians
	call_if_eq VAR_MOSSDEEP_SPACE_CENTER_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts
	end

MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians::
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setobjectxyperm LOCALID_SPACE_CENTER_2F_SCIENTIST, 5, 3
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_2F_RICH_BOY, 3, 2
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_RICH_BOY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_2F_GENTLEMAN, 1, 3
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_GENTLEMAN, MOVEMENT_TYPE_FACE_RIGHT
	return

MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts::
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_6, 11, 2
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_7, 15, 2
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_5, 13, 4
	return

MossdeepCity_SpaceCenter_2F_OnFrame:
	map_script_2 VAR_MOSSDEEP_SPACE_CENTER_STATE, 1, MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts::
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
	msgbox MossdeepCity_SpaceCenter_2F_Text_GoodAnswer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerExit
	waitmovement 0
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 13, 1
	waitstate
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_PlayerExit:
	walk_up
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_5, MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat
	applymovement LOCALID_SPACE_CENTER_GRUNT_5, MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_6, MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat
	applymovement LOCALID_SPACE_CENTER_GRUNT_6, MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_7, MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat
	applymovement LOCALID_SPACE_CENTER_GRUNT_7, MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_6
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_7
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_5
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoy::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace, MSGBOX_DEFAULT
	release
	end

@ Battle for the below 3 grunts is handled in MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
MossdeepCity_SpaceCenter_2F_EventScript_Grunt6::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt7::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt5::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Tabitha::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Maxie::
	lockall
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_Steven::
	lockall
	goto_if_set FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER, MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel, MSGBOX_DEFAULT
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_NOT_EFFECTIVE
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth
	applymovement LOCALID_SPACE_CENTER_2F_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFight
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth::
	applymovement LOCALID_SPACE_CENTER_2F_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_StevenFight:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth:
	face_left
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	face_down
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle
	special LoadPlayerParty
	goto MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt

MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle::
	multi_2_vs_2 TRAINER_MAXIE_MOSSDEEP, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, TRAINER_TABITHA_MOSSDEEP, MossdeepCity_SpaceCenter_Text_TabithaDefeat, PARTNER_STEVEN
	switch VAR_RESULT
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_SPACE_CENTER_MAXIE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SPACE_CENTER_TABITHA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 60
	applymovement LOCALID_SPACE_CENTER_MAXIE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_SPACE_CENTER_TABITHA, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MOSSDEEP_CITY_STATE, 3
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 3
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	removeobject LOCALID_SPACE_CENTER_GRUNT_6
	removeobject LOCALID_SPACE_CENTER_GRUNT_7
	removeobject LOCALID_SPACE_CENTER_GRUNT_5
	removeobject LOCALID_SPACE_CENTER_TABITHA
	removeobject LOCALID_SPACE_CENTER_MAXIE
	setobjectxy LOCALID_SPACE_CENTER_2F_SCIENTIST, 5, 6
	turnobject LOCALID_SPACE_CENTER_2F_SCIENTIST, DIR_SOUTH
	setobjectxy LOCALID_SPACE_CENTER_2F_GENTLEMAN, 11, 8
	turnobject LOCALID_SPACE_CENTER_2F_GENTLEMAN, DIR_NORTH
	setobjectxy LOCALID_SPACE_CENTER_2F_RICH_BOY, 6, 2
	turnobject LOCALID_SPACE_CENTER_2F_RICH_BOY, DIR_NORTH
	call MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer
	fadescreen FADE_FROM_BLACK
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	removeobject LOCALID_SPACE_CENTER_2F_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	removeobject LOCALID_SPACE_CENTER_2F_SCIENTIST
	setobjectxyperm LOCALID_SPACE_CENTER_2F_SCIENTIST, 5, 6
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_SCIENTIST, MOVEMENT_TYPE_WANDER_AROUND
	addobject LOCALID_SPACE_CENTER_2F_SCIENTIST
	fadescreen FADE_FROM_BLACK
#ifdef BUGFIX
	releaseall
#endif
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer::
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth
	case DIR_WEST, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth::
	turnobject LOCALID_SPACE_CENTER_2F_STEVEN, DIR_NORTH
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest::
	turnobject LOCALID_SPACE_CENTER_2F_STEVEN, DIR_EAST
	return

MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall
	call_if_eq VAR_RESULT, FEMALE, MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall
	closemessage
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall::
	pokenavcall MatchCall_Text_MayRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall::
	pokenavcall MatchCall_Text_BrendanRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets:
	.string "MOSSDEEP has mainly sunny weather,\n"
	.string "and its winds are stable.\p"
	.string "It's an ideal location for launching\n"
	.string "rockets.$"

MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel:
	.string "Why would TEAM MAGMA want to steal\n"
	.string "our rocket fuel in the first place?$"

MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut:
	.string "If only I was a little younger, I would\n"
	.string "have liked being an astronaut…\p"
	.string "No… It's not too late!\n"
	.string "I can and will try!$"

MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis:
	.string "If TEAM MAGMA takes the rocket fuel,\n"
	.string "I won't be able to go to space!\p"
	.string "They can't be allowed to get away\n"
	.string "with such an outrage!$"

MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace:
	.string "I wish ordinary people could go into\n"
	.string "space one day…$"

MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace:
	.string "TEAM MAGMA…\n"
	.string "Do they want to go to space, too?$"

MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn:
	.string "What's wrong with you?\p"
	.string "You're outnumbered three to one,\n"
	.string "but you still want to take us on?$"

MossdeepCity_SpaceCenter_2F_Text_GoodAnswer:
	.string "Good answer!\n"
	.string "That's what a smart person'll do!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro:
	.string "A reckless go-getter, are you?\n"
	.string "Okay, I'll go first!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat:
	.string "I lost!\n"
	.string "But!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro:
	.string "It's too soon to be relieved!\n"
	.string "I'm up next!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat:
	.string "I lost, too!\n"
	.string "But!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro:
	.string "I bet you want to take a break.\n"
	.string "But I'm not about to let you do that!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat:
	.string "We should've taken a break…\n"
	.string "That's what we should've done…$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle:
	.string "Three of us here, and look at the sorry\n"
	.string "mess we got ourselves into.$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle:
	.string "We three losing like this…\n"
	.string "We look worse than usual by triple!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle:
	.string "Are we being useful to our leader\n"
	.string "at all?$"

MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou:
	.string "Hehehe!\p"
	.string "We come all the way here to get some\n"
	.string "fuel, and we're interfered with again!\p"
	.string "If you're going to mess with us too,\n"
	.string "we'll take care of you at the same time!$"

MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere:
	.string "MAXIE: Clear out of the way!\n"
	.string "Don't you dare interfere!$"

MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel:
	.string "STEVEN: TEAM MAGMA…\p"
	.string "What's the point of stealing rocket\n"
	.string "fuel?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano:
	.string "MAXIE: Fufufu… Since you're so\n"
	.string "curious, you deserve an explanation.\p"
	.string "We're going to jettison the entire\n"
	.string "load into MT. CHIMNEY!\p"
	.string "With GROUDON gone, we have no need\n"
	.string "for that slag heap of a mountain!\p"
	.string "So we'll use the fuel's power to make\n"
	.string "the volcano erupt!\p"
	.string "It will be savage!$"

MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle:
	.string "STEVEN: {PLAYER}{KUN}!\n"
	.string "You're going to help me?\p"
	.string "Let's go into battle together!\n"
	.string "Are you ready?$"

MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly:
	.string "STEVEN: Then, hurry!\n"
	.string "Get ready quickly!$"

MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand:
	.string "All I want…\n"
	.string "I just want to expand the land mass…$"

MossdeepCity_SpaceCenter_Text_TabithaDefeat:
	.string "I'm with our leader…$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided:
	.string "MAXIE: We failed to make the volcano\n"
	.string "erupt…\p"
	.string "We failed to control GROUDON after\n"
	.string "we had awoken it…\p"
	.string "Is our goal to expand the land\n"
	.string "misguided?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "If…\n"
	.string "If we, TEAM MAGMA, are wrong…\l"
	.string "… … … … … …\p"
	.string "Then might TEAM AQUA's goal to expand\n"
	.string "the sea also be equally misguided?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp:
	.string "MAXIE: All right…\n"
	.string "We will give up on the fuel…\p"
	.string "There appear to be more important\n"
	.string "matters that I must examine…$"

MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome:
	.string "STEVEN: Whew, that was too tense.\n"
	.string "{PLAYER}{KUN}, thank you.\p"
	.string "I have something to give you as\n"
	.string "thanks for your support.\p"
	.string "Please come see me at home\n"
	.string "after this.\p"
	.string "Oh, yes, I don't live in RUSTBORO CITY.\n"
	.string "I live right here on this island.$"
Route110_TrickHouseEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEntrance_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEntrance_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEntrance_OnWarp
	.byte 0

	@ State descriptions for VAR_TRICK_HOUSE_ENTRANCE_STATE
	@ 0: Trick Master is hiding
	@ 1: Trick Master has left at start of challenge
	@ 2: Trick Master ready to give normal reward from previous challenge (if bag was full)
	@ 3: Trick Master still making next puzzle
	@ 4: Finished final puzzle
	@ 5: Completed previous challenge
	@ 6: 'Trick Master' mechadoll ready to give Tent reward from final challenge (if bag was full)

Route110_TrickHouseEntrance_OnTransition:
	setflag FLAG_LANDMARK_TRICK_HOUSE
	goto_if_eq VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 1, Route110_TrickHouseEntrance_EventScript_EnterFromCorridor
	goto_if_eq VAR_TRICK_HOUSE_PRIZE_PICKUP, 1, Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward
	goto_if_eq VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	call_if_eq VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger
	case 1, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1
	case 3, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2
	case 4, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3
	end

Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 2
	end

Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 6
	end

Route110_TrickHouseEntrance_EventScript_EnterFromCorridor::
	setvar VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 0
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_FinishedPuzzles
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2::
	call_if_unset FLAG_BADGE03_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3::
	call_if_unset FLAG_BADGE04_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4::
	call_if_unset FLAG_BADGE05_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5::
	call_if_unset FLAG_BADGE06_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6::
	call_if_unset FLAG_BADGE07_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7::
	call_if_unset FLAG_BADGE08_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8::
	call_if_unset FLAG_SYS_GAME_CLEAR, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
	return

Route110_TrickHouseEntrance_EventScript_FinishedPuzzles::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 4
	return

Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle::
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
	return

Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor::
	setobjectxyperm LOCALID_TRICK_MASTER, 5, 2
	end

Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 0
	end

Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3::
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_OnWarp:
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_TrickMasterFound
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 1, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 2, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 4, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 6, Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor
	.2byte 0

Route110_TrickHouseEntrance_EventScript_TrickMasterFound::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	turnobject LOCALID_PLAYER, DIR_WEST
	end

Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot::
	addobject LOCALID_TRICK_MASTER
	hideobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1
	case 1, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2
	case 2, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3
	case 3, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4
	case 4, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5
	case 5, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6
	case 6, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7
	case 7, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1::
	setobjectxy LOCALID_TRICK_MASTER, 6, 3
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2::
	setobjectxy LOCALID_TRICK_MASTER, 11, 5
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3::
	setobjectxy LOCALID_TRICK_MASTER, 9, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4::
	setobjectxy LOCALID_TRICK_MASTER, 3, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5::
	setobjectxy LOCALID_TRICK_MASTER, 0, 5
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6::
	setobjectxy LOCALID_TRICK_MASTER, 11, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7::
	setobjectxy LOCALID_TRICK_MASTER, 8, 1
	end

Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8::
	setobjectxy LOCALID_TRICK_MASTER, 4, 4
	end

Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster::
	removeobject LOCALID_TRICK_MASTER
	end

Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor::
	addobject LOCALID_TRICK_MASTER
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
	turnobject LOCALID_TRICK_MASTER, DIR_NORTH
	end

Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor::
	addobject LOCALID_TRICK_MASTER
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
	turnobject LOCALID_TRICK_MASTER, DIR_SOUTH
	end

Route110_TrickHouseEntrance_OnFrame:
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_BeginChallenge
	.2byte 0

Route110_TrickHouseEntrance_EventScript_BeginChallenge::
	lockall
	delay 20
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_MeetTrickMaster
	msgbox Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 1
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_UnusedRelease::
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_TrickMaster::
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, Route110_TrickHouseEntrance_EventScript_FoundTrickMaster
	case 2, Route110_TrickHouseEntrance_EventScript_GiveReward
	case 3, Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle
	case 6, Route110_TrickHouseEntrance_EventScript_MechadollReward
	end

Route110_TrickHouseEntrance_EventScript_FoundTrickMaster::
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_FoundBehindTree
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_FoundInDresser
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_FoundInPlanter
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_FoundInCupboard
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_FoundBehindWindow
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion
	closemessage
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1
	warpsilent MAP_ROUTE110_TRICK_HOUSE_ENTRANCE, 6, 2
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBehindTree::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindTree, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundInDresser::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInDresser, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow::
	msgbox Route110_TrickHouseEntrance_Text_ConealedBeyondWindow, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundInPlanter::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInPlanter, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundInCupboard::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInCupboard, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBehindWindow::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindWindow, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion::
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion, MSGBOX_DEFAULT
	return

Route110_TrickHouse_Movement_TrickMasterSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

Route110_TrickHouse_Movement_TrickMasterJumpAway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

Route110_TrickHouseEntrance_EventScript_MeetTrickMaster::
	msgbox Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster, MSGBOX_DEFAULT
	return

Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle::
	msgbox Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TRICK_MASTER, Common_Movement_Delay48
	waitmovement 0
	msgbox Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges, MSGBOX_DEFAULT
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GiveReward::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward, MSGBOX_DEFAULT
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 3, Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 4, Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 5, Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 6, Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward::
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward::
	giveitem ITEM_TIMER_BALL
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward::
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward::
	giveitem ITEM_SMOKE_BALL
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward::
	giveitem ITEM_TM_TAUNT
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward::
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward::
	giveitem ITEM_PP_MAX
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_GotReward
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GotReward::
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_MechadollReward::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route110_TrickHouseEntrance_Text_MechadollWhichTent, MSGBOX_DEFAULT
	call Route110_TrickHouseEntrance_EventScript_ChooseTent
	goto_if_eq VAR_RESULT, TRUE, Route110_TrickHouseEntrance_EventScript_ReceivedTent
	call_if_eq VAR_RESULT, FALSE, Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEntrance_Text_PCFullAgain, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEntrance_EventScript_GiveRedTent
	goto Route110_TrickHouseEntrance_EventScript_GiveBlueTent

Route110_TrickHouseEntrance_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEntrance_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEntrance_EventScript_ReceivedTent::
	msgbox Route110_TrickHouseEntrance_Text_ThenFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHousePuzzle5_Movement_MechadollShake
	waitmovement 0
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_Door::
	lockall
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
	case 0, Route110_TrickHouseEntrance_EventScript_ItsAScroll
	case 1, Route110_TrickHouseEntrance_EventScript_GoInHolePrompt
	case 4, Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote
	case 5, Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage
	end

Route110_TrickHouseEntrance_EventScript_ItsAScroll::
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_GoInHolePrompt::
	msgbox Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom::
	setmetatile 5, 1, METATILE_GenericBuilding_TrickHouse_Stairs_Down, FALSE
	special DrawWholeMapView
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Route110_TrickHouseEntrance_Movement_EnterRoom
	waitmovement 0
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1
	case 1, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2
	case 2, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3
	case 3, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4
	case 4, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5
	case 5, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6
	case 6, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7
	case 7, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8
	end

Route110_TrickHouseEntrance_Movement_EnterRoom:
	set_invisible
	step_end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE1, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE2, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE3, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE4, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE6, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8::
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE8, 0, 21
	waitstate
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote::
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage::
	goto_if_eq VAR_TRICK_HOUSE_LEVEL, 8, Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2::
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_Door::
	lockall
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHousePuzzle1_EventScript_Door
	case 1, Route110_TrickHousePuzzle2_EventScript_Door
	case 2, Route110_TrickHousePuzzle3_EventScript_Door
	case 3, Route110_TrickHousePuzzle4_EventScript_Door
	case 4, Route110_TrickHousePuzzle5_EventScript_Door
	case 5, Route110_TrickHousePuzzle6_EventScript_Door
	case 6, Route110_TrickHousePuzzle7_EventScript_Door
	case 7, Route110_TrickHousePuzzle8_EventScript_Door
	end

Route110_TrickHousePuzzle1_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle4_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle6_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle7_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle8_EventScript_Door::
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle_EventScript_DoorLocked
	msgbox Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 2
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_DoorLocked::
	msgbox Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_ReadScrollAgain::
	msgbox Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHousePuzzle_EventScript_FoundScroll::
	playfanfare MUS_OBTAIN_ITEM
	message Route110_TrickHousePuzzle_Text_FoundAScroll
	waitfanfare
	msgbox Route110_TrickHousePuzzle_Text_MemorizedSecretCode, MSGBOX_DEFAULT
	releaseall
	end

Route110_TrickHouseEntrance_EventScript_TrickMasterHiding::
	lockall
	msgbox Route110_TrickHouseEntrance_Text_YoureBeingWatched, MSGBOX_DEFAULT
	releaseall
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 0, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 1, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2
	call_if_eq VAR_TRICK_HOUSE_LEVEL, 2, Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
	end

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1::
	setvar VAR_0x8004, 6  @ x
	setvar VAR_0x8005, 3  @ y
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2::
	setvar VAR_0x8004, 11  @ x
	setvar VAR_0x8005, 5   @ y
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3::
	setvar VAR_0x8004, 9  @ x
	setvar VAR_0x8005, 2  @ y
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	return

Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle::
	setvar VAR_0x8006, 0
	dofieldeffectsparkle VAR_0x8004, VAR_0x8005, VAR_0x8006
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	return

Route110_TrickHouseEntrance_Text_YoureBeingWatched:
	.string "You're being watched…$"

Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "beneath this desk? You're sharp!$"

Route110_TrickHouseEntrance_Text_ConcealedBehindTree:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "behind this tree? You're sharp!$"

Route110_TrickHouseEntrance_Text_ConcealedInDresser:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this dresser? You're sharp!$"

Route110_TrickHouseEntrance_Text_ConealedBeyondWindow:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "beyond this window? You're sharp!$"

Route110_TrickHouseEntrance_Text_ConcealedInPlanter:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this planter? You're sharp!$"

Route110_TrickHouseEntrance_Text_ConcealedInCupboard:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this cupboard? You're sharp!$"

Route110_TrickHouseEntrance_Text_ConcealedBehindWindow:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "behind this window? You're sharp!$"

Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "beneath this cushion? You're sharp!$"

Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster:
	.string "Behold!\p"
	.string "For I am the greatest living mystery\n"
	.string "of a man in all of HOENN!\l"
	.string "They call me…\p"
	.string "The TRICK MASTER!\n"
	.string "Wahahaha! Glad to meet you!$"

Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse:
	.string "You, you've come to challenge\n"
	.string "my TRICK HOUSE, haven't you?\p"
	.string "That's why you're here, isn't it?\n"
	.string "Yes, it is!\p"
	.string "Consider your challenge accepted!\p"
	.string "Enter through the scroll there,\n"
	.string "and let your challenge commence!\p"
	.string "I shall be waiting in the back!$"

Route110_TrickHouseEntrance_Text_ItsAScroll:
	.string "It's a scroll.$"

Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll:
	.string "There is a big hole behind the scroll!\p"
	.string "Want to go in?$"

Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote:
	.string "There is a note affixed to the scroll…\p"
	.string "“I am leaving on a journey.\n"
	.string "Don't look for me. TRICK MASTER”$"

Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick:
	.string "For the next time, I'll use this trick,\n"
	.string "and that scheme, and those ruses…\p"
	.string "Mufufufu… If I may say so, it's\n"
	.string "brilliantly difficult, even for me!$"

Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges:
	.string "Hah? What?!\n"
	.string "Oh, it's you!\p"
	.string "I'm in the midst of devising new tricky\n"
	.string "challenges!\p"
	.string "It's not too much to ask for a bit more\n"
	.string "time for me to think, is it now?\l"
	.string "You wouldn't begrudge me that?\l"
	.string "Come back in a little while!$"

Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward:
	.string "Ah, it's you! You're here to accept the\n"
	.string "reward from before, isn't that right?\l"
	.string "Yes, right I am!\p"
	.string "Here!\n"
	.string "I'll give it to you now!$"

Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward:
	.string "Hah?\n"
	.string "Did you not come to claim your reward?$"

Route110_TrickHouseEntrance_Text_MechadollWhichTent:
	.string "MECHADOLL 5 I AM!\n"
	.string "IF REWARD IS NOT TAKEN BY YOU,\l"
	.string "THEN TRICK MASTER YOU CANNOT FOLLOW.\p"
	.string "RED TENT OR BLUE TENT,\n"
	.string "WHICH DO YOU PREFER?$"

Route110_TrickHouseEntrance_Text_ThenFarewell:
	.string "THEN FAREWELL.$"

Route110_TrickHouseEntrance_Text_PCFullAgain:
	.string "YOUR PC STATUS: FULL AGAIN.\n"
	.string "MEAN, YOU ARE.$"

Route110_TrickHousePuzzle_Text_FoundAScroll:
	.string "{PLAYER} found a scroll.$"

Route110_TrickHousePuzzle_Text_MemorizedSecretCode:
	.string "{PLAYER} memorized the secret code\n"
	.string "written on the scroll.$"

Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt:
	.string "A secret code is written on it.$"

Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere:
	.string "The door is locked.\p"
	.string "…On closer inspection, this is written\n"
	.string "on it: “Write the secret code here.”$"
Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalEncounter::
	lockall
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
	delay 65
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	addobject LOCALID_ROUTE119_RIVAL
	delay 30
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
	releaseall
	end

Route119_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route119_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route119_EventScript_BattleMay::
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleMayTreecko
	case 1, Route119_EventScript_BattleMayTorchic
	case 2, Route119_EventScript_BattleMayMudkip
	end

Route119_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedMay::
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_BattleBrendan::
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleBrendanTreecko
	case 1, Route119_EventScript_BattleBrendanTorchic
	case 2, Route119_EventScript_BattleBrendanMudkip
	end

Route119_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_DefeatedBrendan::
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_GiveFlyHM::
	giveitem ITEM_HM_FLY
	setflag FLAG_RECEIVED_HM_FLY
	return

Route119_EventScript_RivalExitScottArrive::
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_ROUTE119_RIVAL
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
	addobject LOCALID_ROUTE119_SCOTT
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottEnter
	waitmovement 0
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
	removeobject LOCALID_ROUTE119_SCOTT
	releaseall
	end

Route119_EventScript_SetScottPos1::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 27, 25
	return

Route119_EventScript_SetScottPos2::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 28, 25
	return

Route119_EventScript_ScottExit1::
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit1
	waitmovement 0
	return

Route119_EventScript_ScottExit2::
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit2
	waitmovement 0
	return

Route119_EventScript_RivalEnter1::
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
	waitmovement 0
	return

Route119_EventScript_RivalEnter2::
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
	waitmovement 0
	return

Route119_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
	waitmovement 0
	return

Route119_EventScript_RivalExit2::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
	waitmovement 0
	return

Route119_EventScript_SetRivalPos1::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 25, 32
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 25, 32
	return

Route119_EventScript_SetRivalPos2::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 26, 32
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 26, 32
	return

Route119_Movement_PlayerWatchRivalExit1:
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_PlayerWatchRivalExit2:
	delay_16
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_RivalEnter1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalEnter2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalExit1:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_RivalExit2:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_ScottExit1:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottExit2:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall::
	lockall
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
	waitmessage
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_MayIntro:
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "Where were you? I was looking for you!\p"
	.string "How much stronger have you gotten?\n"
	.string "Let me check for you!\p"
	.string "Ready with your POKéMON?\n"
	.string "Of course you are! Go!$"

Route119_Text_MayDefeat:
	.string "Achah!\n"
	.string "{PLAYER}{KUN}, you're strong!\p"
	.string "I was worried that you might be\n"
	.string "struggling with your training.$"

Route119_Text_MayPresentForYou:
	.string "MAY: But I had absolutely nothing to\n"
	.string "worry about! Keep it up!\p"
	.string "And, here! I have a present for you.$"

Route119_Text_MayExplainFly:
	.string "MAY: Use FLY, and your POKéMON will\n"
	.string "instantly carry you to any town you've\l"
	.string "already visited.\p"
	.string "But, to use FLY, you have to get\n"
	.string "the GYM BADGE from FORTREE CITY.\l"
	.string "That's important, so don't forget.\p"
	.string "You should FLY home and visit\n"
	.string "LITTLEROOT for a change.\p"
	.string "I bet your mom's worried about you,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "Well, let's meet again somewhere!$"

Route119_Text_BrendanIntro:
	.string "BRENDAN: {PLAYER}! So this is where\n"
	.string "you've been looking for POKéMON?\p"
	.string "Let me see how good you got.\n"
	.string "I'll test you!\p"
	.string "Now!\n"
	.string "It's a battle, so battle!$"

Route119_Text_BrendanDefeat:
	.string "Hmm…\n"
	.string "You've gotten pretty darn decent.$"

Route119_Text_BrendanIllGiveYouThis:
	.string "BRENDAN: I'd say you're good enough\n"
	.string "to search for POKéMON anywhere.\p"
	.string "Here, I'll give you this.\n"
	.string "Try it out.$"

Route119_Text_BrendanExplainFly:
	.string "BRENDAN: Use FLY, and your POKéMON\n"
	.string "instantly carries you to any town\l"
	.string "you've already visited.\p"
	.string "But you need the FORTREE GYM BADGE \n"
	.string "to do that.\p"
	.string "Anyway, I have to move along.$"

Route119_Text_ScottWayToGoBeSeeingYou:
	.string "SCOTT: Hahahah!\n"
	.string "Way to go, {PLAYER}{KUN}!\p"
	.string "I just passed by a TRAINER riding\n"
	.string "a BIKE.\p"
	.string "You just beat that TRAINER, didn't you?\n"
	.string "It was pretty obvious that you did.\p"
	.string "The kid looked really upset with\n"
	.string "a face all red from anger.\p"
	.string "I sure seem to run into you often.\n"
	.string "Are you off to FORTREE GYM next?\p"
	.string "I expect that you'll do well at the GYM.\n"
	.string "Well, I'll be seeing you!$"


Route119_Text_ScottYouWonAtFortreeGym:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hiya, {PLAYER}{KUN}, it's me!\p"
	.string "Just as I thought, you won at\n"
	.string "the FORTREE GYM.\p"
	.string "Your strength…\n"
	.string "Perhaps you really are the TRAINER\l"
	.string "that I've been searching for.\p"
	.string "Remember, you have a fan in me.\n"
	.string "I'll be cheering from the sidelines.\l"
	.string "Keep up the great work!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route119_Text_StayAwayFromWeatherInstitute:
	.string "We're standing lookout here.\p"
	.string "Hey, you! Stay away from the WEATHER\n"
	.string "INSTITUTE. It's not safe.$"

Route119_Text_DontGoNearWeatherInstitute:
	.string "Lookout duty is surprisingly boring.\p"
	.string "Hey, you! Please don't go near the\n"
	.string "WEATHER INSTITUTE.$"

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "I thought you FLY by catching a whole\n"
	.string "flock of BIRD POKéMON, and then\l"
	.string "hanging on to them somehow.\p"
	.string "But it turns out there's an HM move\n"
	.string "called FLY!\p"
	.string "I wish I'd known about that a long\n"
	.string "time ago…$"

Route119_Text_TallGrassSnaresBikeTires:
	.string "Tch…\n"
	.string "It's a no-go…\p"
	.string "The tall grass snares BIKE tires.\n"
	.string "There's no way you can cycle here.$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "Can your POKéMON use its SECRET POWER\n"
	.string "on a big pile of grass and make a\l"
	.string "SECRET BASE?$"

Route119_Text_RouteSignFortree:
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} FORTREE CITY$"

Route119_Text_WeatherInstitute:
	.string "WEATHER INSTITUTE$"

Route119_Text_TrainerTipsDecoration:
	.string "TRAINER TIPS\p"
	.string "Up to sixteen decorations and\n"
	.string "furniture items can be placed in\l"
	.string "a SECRET BASE.\p"
	.string "Pick your favorite items and create\n"
	.string "your very own SECRET BASE exactly the\l"
	.string "way you want.$"
@ LOCALID_BRIDGE_KECLEON_SHADOW is a second object which is identical to LOCALID_BRIDGE_KECLEON but has a reflection palette tag for the bridge shadow
Route120_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
	.byte 0

Route120_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route120_EventScript_RemoveKecleonObject
	end

Route120_EventScript_RemoveKecleonObject::
	call_if_eq VAR_0x8009, 0, Route120_EventScript_RemoveBridgeKecleon
	call_if_eq VAR_0x8009, 1, Route120_EventScript_RemoveKecleon
	call_if_eq VAR_0x8009, 2, Route120_EventScript_RemoveKecleon
	call_if_eq VAR_0x8009, 3, Route120_EventScript_RemoveKecleon
	call_if_eq VAR_0x8009, 4, Route120_EventScript_RemoveKecleon
	call_if_eq VAR_0x8009, 5, Route120_EventScript_RemoveKecleon
	return

Route120_EventScript_RemoveBridgeKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_BRIDGE_KECLEON
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
	return

Route120_EventScript_RemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route120_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, Route120_EventScript_CloseAncientTomb
	call_if_set FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeClearMetatiles
	call_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeKecleonMovement
	end

Route120_EventScript_CloseAncientTomb::
	setmetatile 7, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 7, 55, METATILE_General_RockWall_SandBase, TRUE
	return

Route120_EventScript_SetBridgeClearMetatiles::
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
	return

Route120_EventScript_SetBridgeKecleonMovement::
	setobjectmovementtype LOCALID_BRIDGE_KECLEON_SHADOW, MOVEMENT_TYPE_FACE_RIGHT
	return

Route120_OnTransition:
	call GabbyAndTy_EventScript_UpdateLocation
	call Route120_EventScript_SetWeather
	end

Route120_EventScript_SetWeather::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_le VAR_TEMP_1, 14, Route120_EventScript_SetSunnyWeather
	goto_if_le VAR_TEMP_1, 60, Route120_EventScript_TrySetRainyWeather
	goto_if_ge VAR_TEMP_1, 61, Route120_EventScript_SetCloudyWeather
	return

Route120_EventScript_SetCloudyWeather::
	setweather WEATHER_SUNNY_CLOUDS
	return

Route120_EventScript_SetSunnyWeather::
	setweather WEATHER_SUNNY
	return

Route120_EventScript_TrySetRainyWeather::
	goto_if_le VAR_TEMP_0, 7, Route120_EventScript_SetRainyWeather
	goto_if_le VAR_TEMP_0, 19, Route120_EventScript_SetSunnyWeather
	goto Route120_EventScript_SetRainyWeather
	end

Route120_EventScript_SetRainyWeather::
	setweather WEATHER_RAIN
	return

Route120_EventScript_BerryBeauty::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_ReceivedBerry
	msgbox Route120_Text_BerriesExpressionOfLoveIsntIt, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route120_EventScript_BerryLove
	call_if_eq VAR_RESULT, NO, Route120_EventScript_BerryNotLove
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
	switch VAR_RESULT
	case 0, Route120_EventScript_GiveFigyBerry
	case 5, Route120_EventScript_GiveFigyBerry
	case 1, Route120_EventScript_GiveWikiBerry
	case 6, Route120_EventScript_GiveWikiBerry
	case 2, Route120_EventScript_GiveMagoBerry
	case 7, Route120_EventScript_GiveMagoBerry
	case 3, Route120_EventScript_GiveAguavBerry
	case 8, Route120_EventScript_GiveAguavBerry
	case 4, Route120_EventScript_GiveIapapaBerry
	case 9, Route120_EventScript_GiveIapapaBerry
	end

Route120_EventScript_GiveFigyBerry::
	setvar VAR_0x8004, ITEM_FIGY_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveWikiBerry::
	setvar VAR_0x8004, ITEM_WIKI_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveMagoBerry::
	setvar VAR_0x8004, ITEM_MAGO_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveAguavBerry::
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveIapapaBerry::
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveBerry::
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
	msgbox Route120_Text_BerryIsRareRaiseItWithCare, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_ReceivedBerry::
	msgbox Route120_Text_IllGetMoreBerriesFromBerryMaster, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_BerryLove::
	msgbox Route120_Text_YesYouUnderstand, MSGBOX_DEFAULT
	return

Route120_EventScript_BerryNotLove::
	msgbox Route120_Text_MakeYourOwnImpressions, MSGBOX_DEFAULT
	return

Route120_EventScript_Steven::
	lock
	faceplayer
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, Route120_EventScript_StevenAskReadyForBattle
	msgbox Route120_Text_StevenGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
	goto Route120_EventScript_StevenBattleKecleon
	end

Route120_EventScript_StevenNotReady::
	msgbox Route120_Text_StevenIllWaitHere, MSGBOX_DEFAULT
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
	release
	end

Route120_EventScript_StevenAskReadyForBattle::
	msgbox Route120_Text_StevenReadyForBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
	goto Route120_EventScript_StevenBattleKecleon
	end

Route120_EventScript_StevenBattleKecleon::
	msgbox Route120_Text_StevenShowMeYourPower, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, Route120_EventScript_PlayerApproachKecleonNorth
	call_if_eq VAR_FACING, DIR_WEST, Route120_EventScript_PlayerApproachKecleonWest
	applymovement LOCALID_ROUTE120_STEVEN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	msgbox Route120_Text_StevenUsedDevonScope, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRIDGE_KECLEON, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_BRIDGE_KECLEON, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KECLEON, 30
	setvar VAR_0x8009, 0
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route120_EventScript_RemoveBridgeKecleonPostBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route120_EventScript_RemoveBridgeKecleonPostBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route120_EventScript_RemoveBridgeKecleonPostBattle
	goto Route120_EventScript_StevenGiveDeconScope
	end

Route120_EventScript_RemoveBridgeKecleonPostBattle::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_BRIDGE_KECLEON
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Route120_EventScript_StevenGiveDeconScope
	end

Route120_EventScript_StevenGiveDeconScope::
	applymovement LOCALID_ROUTE120_STEVEN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Route120_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_SCOPE
	setflag FLAG_RECEIVED_DEVON_SCOPE
	msgbox Route120_Text_StevenGoodbye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE120_STEVEN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_ROUTE120_STEVEN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
	special DrawWholeMapView
	release
	end

Route120_EventScript_PlayerApproachKecleonNorth::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route120_EventScript_PlayerApproachKecleonWest::
	applymovement LOCALID_PLAYER, Route120_Movement_ApproachKecleonWest
	waitmovement 0
	return

Route120_Movement_ApproachKecleonWest:
	walk_down
	walk_left
	step_end

Route120_EventScript_BridgeKecleon::
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_NPC
	end

Route120_EventScript_RouteSignFortree::
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route120_EventScript_RouteSign121::
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
	end

Route120_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN, Route120_Text_ColinIntro, Route120_Text_ColinDefeat
	msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Robert::
	trainerbattle_single TRAINER_ROBERT_1, Route120_Text_RobertIntro, Route120_Text_RobertDefeat, Route120_EventScript_RegisterRobert
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchRobert
	msgbox Route120_Text_RobertPostBattle, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_RegisterRobert::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route120_Text_RobertRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROBERT_1
	release
	end

Route120_EventScript_RematchRobert::
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_RobertRematchIntro, Route120_Text_RobertRematchDefeat
	msgbox Route120_Text_RobertPostRematch, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Lorenzo::
	trainerbattle_single TRAINER_LORENZO, Route120_Text_LorenzoIntro, Route120_Text_LorenzoDefeat
	msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Jenna::
	trainerbattle_single TRAINER_JENNA, Route120_Text_JennaIntro, Route120_Text_JennaDefeat
	msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, Route120_EventScript_RegisterJeffrey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchJeffrey
	msgbox Route120_Text_JeffreyPostBattle, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_RegisterJeffrey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route120_Text_JeffreyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JEFFREY_1
	release
	end

Route120_EventScript_RematchJeffrey::
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_JeffreyRematchIntro, Route120_Text_JeffreyRematchDefeat
	msgbox Route120_Text_JeffreyPostRematch, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Jennifer::
	trainerbattle_single TRAINER_JENNIFER, Route120_Text_JenniferIntro, Route120_Text_JenniferDefeat
	msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Chip::
	trainerbattle_single TRAINER_CHIP, Route120_Text_ChipIntro, Route120_Text_ChipDefeat
	msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA, Route120_Text_ClarissaIntro, Route120_Text_ClarissaDefeat
	msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Angelica::
	trainerbattle_single TRAINER_ANGELICA, Route120_Text_AngelicaIntro, Route120_Text_AngelicaDefeat
	msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Keigo::
	trainerbattle_single TRAINER_KEIGO, Route120_Text_KeigoIntro, Route120_Text_KeigoDefeat
	msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY, Route120_Text_RileyIntro, Route120_Text_RileyDefeat
	msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Leonel::
	trainerbattle_single TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat
	msgbox Route120_Text_LeonelPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Callie::
	trainerbattle_single TRAINER_CALLIE, Route120_Text_CallieIntro, Route120_Text_CallieDefeat
	msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
	end

Route120_Text_StevenGreeting:
	.string "STEVEN: Hm? {PLAYER}{KUN}, hi.\n"
	.string "It's been a while.\p"
	.string "There's something here that you can't\n"
	.string "see, right?\p"
	.string "Now, if I were to use this device on\n"
	.string "the invisible obstacle…\p"
	.string "No, no. Rather than describing it,\n"
	.string "I should just show you.\l"
	.string "That would be more fun.\p"
	.string "{PLAYER}{KUN}, are your POKéMON ready for\n"
	.string "battle?$"

Route120_Text_StevenIllWaitHere:
	.string "STEVEN: No?\p"
	.string "I'll wait here, so you can get ready.$"

Route120_Text_StevenReadyForBattle:
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
	.string "ready for battle?$"

Route120_Text_StevenShowMeYourPower:
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
	.string "power as a TRAINER!$"

Route120_Text_StevenUsedDevonScope:
	.string "STEVEN used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"

Route120_Text_StevenGiveDevonScope:
	.string "STEVEN: I see…\n"
	.string "Your battle style is intriguing.\p"
	.string "Your POKéMON have obviously grown\n"
	.string "since I first met you in DEWFORD.\p"
	.string "I'd like you to have this\n"
	.string "DEVON SCOPE.\p"
	.string "Who knows, there may be other\n"
	.string "concealed POKéMON.$"

Route120_Text_StevenGoodbye:
	.string "STEVEN: {PLAYER}{KUN}.\p"
	.string "I enjoy seeing POKéMON and TRAINERS\n"
	.string "who strive together.\p"
	.string "I think you're doing great.\p"
	.string "Well, let's meet again somewhere.$"

Kecleon_Text_SomethingUnseeable:
	.string "Something unseeable is in the way.$"

Kecleon_Text_WantToUseDevonScope:
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"

Kecleon_Text_UseDevonScopeMonAttacked:
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"

Route120_Text_RouteSignFortree:
	.string "ROUTE 120\n"
	.string "{LEFT_ARROW} FORTREE CITY$"

Route120_Text_RouteSign121:
	.string "{RIGHT_ARROW} ROUTE 121\n"
	.string "{LEFT_ARROW} ROUTE 120$"
RusturfTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
	.byte 0

RusturfTunnel_OnFrame:
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
	.2byte 0

RusturfTunnel_OnTransition:
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
	end

RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_PEEKO, 13, 4
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_GRUNT, 13, 5
	return

RusturfTunnel_EventScript_Wanda::
	lock
	faceplayer
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
	setflag FLAG_TEMP_1
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_AlreadySpokenTo::
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_ClearTunnelScene::
	lockall
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
	releaseall
	end

RusturfTunnel_EventScript_BoyfriendApproachWanda1::
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda2::
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda3::
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend1::
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend2::
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend3::
	return

RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
	closemessage
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit1
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit::
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
	waitmovement 0
	return

RusturfTunnel_EventScript_WandasBoyfriendNotice::
	playse SE_PIN
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_Delay48
	waitmovement 0
	return

RusturfTunnel_Movement_WandaExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandaExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_PlayerWatchWandaExit:
	delay_8
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused2:
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused3:
	walk_up
	walk_in_place_faster_down
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend:
	walk_right
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BoyfriendFaceRight:
	walk_up
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
	walk_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda1:
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_faster_up
	step_end

RusturfTunnel_EventScript_TunnelBlockagePos1::
	setvar VAR_TEMP_1, 1
	end

RusturfTunnel_EventScript_TunnelBlockagePos2::
	setvar VAR_TEMP_1, 2
	end

RusturfTunnel_EventScript_TunnelBlockagePos3::
	setvar VAR_TEMP_1, 3
	end

RusturfTunnel_EventScript_AquaGruntBackUp::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
	waitmovement 0
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_GRUNT
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_PEEKO
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	releaseall
	end

RusturfTunnel_Movement_GruntAndPeekoBackUp:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RusturfTunnel_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RusturfTunnel_EventScript_Grunt::
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_PARTS
	closemessage
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_RUSTURF_TUNNEL_GRUNT
	delay 50
	addobject LOCALID_RUSTURF_TUNNEL_BRINEY
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
	waitmovement 0
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
	waitmovement 0
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, Common_Movement_FacePlayer
	waitmovement 0
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
	waitmessage
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	closemessage
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyExit
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_PeekoExit
	waitmovement 0
	removeobject LOCALID_RUSTURF_TUNNEL_BRINEY
	removeobject LOCALID_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_CITY_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	release
	end

RusturfTunnel_Movement_PushPlayerAsideForGrunt:
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_PlayerMoveAsideForBriney:
	walk_down
	walk_in_place_faster_up
	step_end

RusturfTunnel_Movement_GruntEscape:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_Movement_BrineyExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_Movement_PlayerWatchBrineyExit:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko2:
	delay_16
	walk_right
	step_end

RusturfTunnel_Movement_PeekoExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

RusturfTunnel_Text_ComeAndGetSome:
	.string "What, are you coming?\n"
	.string "Come and get some, then!$"

RusturfTunnel_Text_Peeko:
	.string "PEEKO: Pii pihyoh!$"

RusturfTunnel_Text_GruntIntro:
	.string "Grah, keelhaul it all!\p"
	.string "That hostage POKéMON turned out to\n"
	.string "be worthless!\p"
	.string "And to think I made a getaway…\n"
	.string "In this tunnel to nowhere!\p"
	.string "Hey! You!\n"
	.string "So you want to battle me?$"

RusturfTunnel_Text_GruntDefeat:
	.string "Urrrggh! My career in crime comes to\n"
	.string "a dead end!$"

RusturfTunnel_Text_GruntTakePackage:
	.string "This is plain not right…\p"
	.string "The BOSS told me this would be a\n"
	.string "slick-and-easy job to pull.\p"
	.string "All I had to do was steal some package\n"
	.string "from DEVON.\p"
	.string "Tch!\n"
	.string "You want it back that badly, take it!$"

RusturfTunnel_Text_PeekoGladToSeeYouSafe:
	.string "PEEKO!\n"
	.string "Am I glad to see you're safe!$"

RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
	.string "PEEKO owes her life to you!\p"
	.string "They call me MR. BRINEY.\n"
	.string "And, you are?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
	.string "I sincerely thank you!\p"
	.string "Now, if there's anything that troubles\n"
	.string "you, don't hesitate to tell me!\p"
	.string "You can usually find me in my cottage\n"
	.string "by the sea near PETALBURG WOODS.\p"
	.string "Come, PEEKO, we should make our way\n"
	.string "home.\p"
	.string "PEEKO: Pihyoh!$"

RusturfTunnel_Text_WhyCantTheyKeepDigging:
	.string "… …\p"
	.string "Why can't they keep digging?\n"
	.string "Is the bedrock too hard?\p"
	.string "My beloved awaits me in VERDANTURF\n"
	.string "TOWN just beyond here…\p"
	.string "If RUSTBORO and VERDANTURF were\n"
	.string "joined by this tunnel, I could visit\l"
	.string "her every day…\p"
	.string "But this…\n"
	.string "What am I to do?$"

RusturfTunnel_Text_ToGetToVerdanturf:
	.string "To get from RUSTBORO to VERDANTURF,\n"
	.string "you need to go to DEWFORD, then pass\l"
	.string "through SLATEPORT and MAUVILLE…$"

RusturfTunnel_Text_YouShatteredBoulderTakeHM:
	.string "Wow! You shattered that boulder\n"
	.string "blocking the way.\p"
	.string "To show you how much I appreciate it,\n"
	.string "I'd like you to have this HM.$"

RusturfTunnel_Text_ExplainStrength:
	.string "That HM contains STRENGTH.\p"
	.string "If a muscular POKéMON were to learn\n"
	.string "that, it would be able to move even\l"
	.string "large boulders.$"

RusturfTunnel_Text_WandaReunion:
	.string "WANDA!\n"
	.string "Now I can see you anytime!\p"
	.string "WANDA: That's…wonderful.\p"
	.string "Please, take some rest at my home.$"

RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
	.string "On the other side of this rock…\n"
	.string "My boyfriend is there.\p"
	.string "He… He's not just digging the tunnel\n"
	.string "to come see me.\p"
	.string "He works his hands raw and rough\n"
	.string "for the benefit of everyone.$"

RusturfTunnel_Text_MikeIntro:
	.string "What do you call a wild man up in the\n"
	.string "mountains? A mountain man, right?\p"
	.string "So why don't they call a POKéMON in\n"
	.string "the mountains a mountain POKéMON?$"

RusturfTunnel_Text_MikeDefeat:
	.string "My POKéMON…\n"
	.string "Ran out of power…$"

RusturfTunnel_Text_MikePostBattle:
	.string "They halted development here to\n"
	.string "protect POKéMON, right?\l"
	.string "There's a feel-good story!$"

SSTidalCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalCorridor_OnFrame
	.byte 0

SSTidalCorridor_OnFrame:
	map_script_2 VAR_SS_TIDAL_SCOTT_STATE, 0, SSTidalCorridor_EventScript_ScottScene
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT, SSTidalCorridor_EventScript_DepartSlateportForLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE, SSTidalCorridor_EventScript_DepartLilycoveForSlateport
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_RIGHT, SSTidalCorridor_EventScript_HalfwayToLilycove
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_LEFT, SSTidalCorridor_EventScript_ArrivedInSlateport
	.2byte 0

SSTidalCorridor_EventScript_DepartSlateportForLilycove::
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_DepartLilycoveForSlateport::
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_HalfwayToSlateport::
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ArrivedInLilycove::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInLilycove, MSGBOX_DEFAULT
	return

SSTidalCorridor_EventScript_ReachedStepCount::
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT, SSTidalCorridor_EventScript_HalfwayToLilycove
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT, SSTidalCorridor_EventScript_ArrivedInSlateport
	end

SSTidalCorridor_EventScript_HalfwayToLilycove::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_LILYCOVE
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_ArrivedInSlateport::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	lockall
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	releaseall
	end

SSTidalRooms_EventScript_ArrivedInSlateport::
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
	playse SE_DING_DONG
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
	return

SSTidalRooms_EventScript_ProgessCruiseAfterBed::
	switch VAR_SS_TIDAL_STATE
	case SS_TIDAL_DEPART_SLATEPORT, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_HALFWAY_LILYCOVE, SSTidalRooms_EventScript_ArrivedInLilycove
	case SS_TIDAL_DEPART_LILYCOVE, SSTidalRooms_EventScript_HalfwayToSlateport
	case SS_TIDAL_HALFWAY_SLATEPORT, SSTidalRooms_EventScript_ArrivedInSlateport
	return

SSTidalCorridor_EventScript_Briney::
	msgbox SSTidalCorridor_Text_BrineyWelcomeAboard, MSGBOX_NPC
	end

SSTidalCorridor_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox SSTidalCorridor_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SSTidalCorridor_EventScript_Cabin1Sign::
	msgbox SSTidalCorridor_Text_Cabin1, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin2Sign::
	msgbox SSTidalCorridor_Text_Cabin2, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin3Sign::
	msgbox SSTidalCorridor_Text_Cabin3, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_Cabin4Sign::
	msgbox SSTidalCorridor_Text_Cabin4, MSGBOX_SIGN
	end

SSTidalCorridor_EventScript_ExitSailor::
	lock
	faceplayer
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE, SSTidalCorridor_EventScript_ExitLilycove
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT, SSTidalCorridor_EventScript_ExitSlateport
	msgbox SSTidalCorridor_Text_CanRestInCabin2, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_ExitLilycove::
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_ExitSlateport::
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
	call_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalCorridor_EventScript_HideSnatchGiver
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SSTidalCorridor_EventScript_HideSnatchGiver::
	setflag FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER
	return

SSTidalCorridor_EventScript_Porthole::
	lockall
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT, SSTidalCorridor_EventScript_LookThroughPorthole
	goto_if_eq VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT, SSTidalCorridor_EventScript_LookThroughPorthole
	msgbox SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole, MSGBOX_DEFAULT
	releaseall
	end

SSTidalCorridor_EventScript_LookThroughPorthole::
	special LookThroughPorthole
	end

SSTidalCorridor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SS_TIDAL_TRAINERS, SSTidalCorridor_EventScript_EnjoyYourCruise
	call SSTidalCorridor_EventScript_CheckIfTrainersDefeated
	msgbox SSTidalCorridor_Text_VisitOtherCabins, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_EnjoyYourCruise::
	msgbox SSTidalCorridor_Text_EnjoyYourCruise, MSGBOX_DEFAULT
	release
	end

SSTidalCorridor_EventScript_CheckIfTrainersDefeated::
	goto_if_not_defeated TRAINER_PHILLIP, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEONARD, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_COLTON, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_MICAH, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_THOMAS, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_LEA_AND_JED, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_GARRET, SSTidalCorridor_EventScript_TrainerNotDefeated
	goto_if_not_defeated TRAINER_NAOMI, SSTidalCorridor_EventScript_TrainerNotDefeated
	setflag FLAG_DEFEATED_SS_TIDAL_TRAINERS
	goto SSTidalCorridor_EventScript_EnjoyYourCruise
	return

SSTidalCorridor_EventScript_TrainerNotDefeated::
	return

SSTidalCorridor_EventScript_ScottScene::
	lockall
	applymovement LOCALID_SS_TIDAL_SCOTT, SSTidalCorridor_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SSTidalCorridor_Text_ScottBattleFrontierInvite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SSTidalCorridor_Movement_PlayerWatchScottExit
	applymovement LOCALID_SS_TIDAL_EXIT_SAILOR, SSTidalCorridor_Movement_SailorMoveForScott
	applymovement LOCALID_SS_TIDAL_SCOTT, SSTidalCorridor_Movement_ScottExit
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_SS_TIDAL_SCOTT
	applymovement LOCALID_SS_TIDAL_EXIT_SAILOR, SSTidalCorridor_Movement_SailorReturn
	waitmovement 0
	delay 30
	setflag FLAG_MET_SCOTT_ON_SS_TIDAL
	setvar VAR_SS_TIDAL_SCOTT_STATE, 1
	releaseall
	end

SSTidalCorridor_Movement_ScottApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SSTidalCorridor_Movement_ScottExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SSTidalCorridor_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_down
	step_end

SSTidalCorridor_Movement_SailorMoveForScott:
	delay_16
	walk_right
	walk_right
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_left
	step_end

SSTidalCorridor_Movement_SailorReturn:
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

SSTidalCorridor_Text_ScottBattleFrontierInvite:
	.string "SCOTT: Well, hi, hi!\n"
	.string "{PLAYER}{KUN}, {PLAYER}{KUN}!\p"
	.string "Something's come up, so I have to\n"
	.string "disembark, but am I glad to see you!\p"
	.string "Congratulations, LEAGUE CHAMPION!\p"
	.string "There's a place I'd like to invite\n"
	.string "someone like you.\p"
	.string "It's the…\n"
	.string "BATTLE FRONTIER!\p"
	.string "What's the place like?\n"
	.string "You'll understand when you see it!\p"
	.string "I've spoken with the ship's CAPTAIN\n"
	.string "about this.\p"
	.string "The next time you take a ferry,\n"
	.string "you should be able to sail to\l"
	.string "the BATTLE FRONTIER.\p"
	.string "Okay, {PLAYER}{KUN}, I'll be waiting for you\n"
	.string "at the BATTLE FRONTIER!$"

SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage:
	.string "This ferry is built to plow through\n"
	.string "fast-running currents.\p"
	.string "We hope you enjoy your voyage with us.\n"
	.string "Feel free to explore the ship.$"

SSTidal_Text_HopeYouEnjoyVoyage:
	.string "We hope you enjoy your voyage on\n"
	.string "our ferry.$"

SSTidal_Text_MadeLandInSlateport:
	.string "We have made land in SLATEPORT CITY.\n"
	.string "Thank you for sailing with us.$"

SSTidal_Text_MadeLandInLilycove:
	.string "We have made land in LILYCOVE CITY.\n"
	.string "Thank you for sailing with us.$"

SSTidalCorridor_Text_CanRestInCabin2:
	.string "It'll be some time before we make land,\n"
	.string "I reckon.\p"
	.string "You can rest up in your cabin if you'd\n"
	.string "like. Your cabin's No. 2.\p"
	.string "The bed in there is soft and plushy.\n"
	.string "I can attest to how comfy it is!$"

SSTidalCorridor_Text_WeveArrived:
	.string "We've arrived!$"

SSTidalCorridor_Text_VisitOtherCabins:
	.string "Go visit other cabins.\n"
	.string "TRAINERS bored of the boat trip will\l"
	.string "be itching to battle.$"

SSTidalCorridor_Text_EnjoyYourCruise:
	.string "Enjoy your cruise!$"

SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole:
	.string "The horizon spreads beyond\n"
	.string "the porthole.$"

SSTidalCorridor_Text_BrineyWelcomeAboard:
	.string "MR. BRINEY: Welcome aboard, {PLAYER}{KUN}!\p"
	.string "They made me honorary captain of\n"
	.string "the S.S. TIDAL!\p"
	.string "You can call me CAPTAIN BRINEY now!\p"
	.string "You know, I retired once before,\n"
	.string "but when I saw this majestic ship…\p"
	.string "Let me just say, it stirred my sleeping\n"
	.string "soul as a sailor!$"

SSTidalCorridor_Text_Peeko:
	.string "PEEKO: Pihyo pihyohyo…$"

SSTidalCorridor_Text_Cabin1:
	.string "Cabin 1$"

SSTidalCorridor_Text_Cabin2:
	.string "Cabin 2$"

SSTidalCorridor_Text_Cabin3:
	.string "Cabin 3$"

SSTidalCorridor_Text_Cabin4:
	.string "Cabin 4$"
SkyPillar_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_Outside_OnFrame
	.byte 0

SkyPillar_Outside_OnTransition:
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SkyPillar_Outside_EventScript_HideMapNamePopup
	call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, SkyPillar_Outside_EventScript_CheckSetAbnormalWeather
	end

SkyPillar_Outside_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SkyPillar_Outside_EventScript_CheckSetAbnormalWeather::
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

SkyPillar_Outside_OnLoad:
	call_if_set FLAG_WALLACE_GOES_TO_SKY_PILLAR, SkyPillar_Outside_EventScript_OpenDoor
	end

SkyPillar_Outside_EventScript_OpenDoor::
	setmetatile 14, 4, METATILE_Pacifidlog_SkyPillar_DoorOpen_Top, FALSE
	setmetatile 14, 5, METATILE_Pacifidlog_SkyPillar_DoorOpen_Bottom, FALSE
	return

SkyPillar_Outside_OnFrame:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, SkyPillar_Outside_EventScript_WallaceScene
	.2byte 0

SkyPillar_Outside_EventScript_WallaceScene::
	lockall
	applymovement LOCALID_SKY_PILLAR_WALLACE, SkyPillar_Outside_Movement_WallaceApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SkyPillar_Outside_Text_OpenedDoorToSkyPillar, MSGBOX_DEFAULT
	closemessage
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	delay 40
	msgbox SkyPillar_Outside_Text_EarthquakeNotMomentToWaste, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SkyPillar_Outside_Movement_PlayerClimbSkyPillar
	applymovement LOCALID_SKY_PILLAR_WALLACE, SkyPillar_Outside_Movement_WallaceClimbSkyPillar
	waitmovement 0
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 3   @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 5   @ shake delay
	special ShakeCamera
	waitstate
	delay 20
	applymovement LOCALID_SKY_PILLAR_WALLACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_SKY_PILLAR_WALLACE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement LOCALID_SKY_PILLAR_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox SkyPillar_Outside_Text_SituationGettingWorse, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_ABNORMAL
	doweather
	special WaitWeather
	delay 30
	msgbox SkyPillar_Outside_Text_GotToGoBackForSootopolis, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenswapbuffers FADE_TO_BLACK
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SOOTOPOLIS_CITY_STATE, 4
	removeobject LOCALID_SKY_PILLAR_WALLACE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillar_Outside_Movement_WallaceApproachPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SkyPillar_Outside_Movement_WallaceClimbSkyPillar:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SkyPillar_Outside_Movement_PlayerClimbSkyPillar:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

SkyPillar_Outside_EventScript_Wallace::
	end

SkyPillar_Outside_EventScript_ClosedDoor::
	msgbox SkyPillar_Outside_Text_DoorIsClosed, MSGBOX_SIGN
	end

SkyPillar_Outside_Text_DoorIsClosed:
	.string "The door is closed.$"

SkyPillar_Outside_Text_OpenedDoorToSkyPillar:
	.string "WALLACE: Oh, my, I'm terribly sorry!\p"
	.string "In my haste, I didn't notice that\n"
	.string "I'd left you behind!\p"
	.string "I've opened the locked door of\n"
	.string "the SKY PILLAR.\p"
	.string "{PLAYER}{KUN}, let's be on our way!$"

SkyPillar_Outside_Text_EarthquakeNotMomentToWaste:
	.string "WALLACE: It's an earthquake!\p"
	.string "There's not a moment to waste!\n"
	.string "We've got to hurry!$"

SkyPillar_Outside_Text_SituationGettingWorse:
	.string "WALLACE: Hmm…\n"
	.string "The situation is getting worse…$"

SkyPillar_Outside_Text_GotToGoBackForSootopolis:
	.string "WALLACE: This isn't good…\p"
	.string "The weather distortion is spreading\n"
	.string "even here…\p"
	.string "{PLAYER}{KUN}.\p"
	.string "RAYQUAZA should be farther up\n"
	.string "from here.\p"
	.string "I'm worried about SOOTOPOLIS.\n"
	.string "I've got to go back.\p"
	.string "Everything is in your hands now.\n"
	.string "Don't fail us!$"
SootopolisCity_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
	.byte 0

SootopolisCity_OnLoad:
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
	end

SootopolisCity_EventScript_LegendariesNotArrived::
	end

SootopolisCity_EventScript_LockHouseDoors::
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, TRUE
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, TRUE
	return

SootopolisCity_EventScript_LockGymDoor::
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, TRUE
	return

SootopolisCity_OnTransition:
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
	call SootopolisCity_EventScript_SetWeather
	call SootopolisCity_EventScript_SetLayout
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetBattleSpectators
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetExitCaveOfOriginObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetOutsideGymObjPos
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetExpertBlockCaveEntrance
	end

SootopolisCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SootopolisCity_EventScript_SetBattleSpectators::
	setobjectxyperm LOCALID_KIRI, 13, 48
	setobjectxyperm LOCALID_SOOTOPOLIS_BOY_1, 46, 32
	setobjectxyperm LOCALID_SOOTOPOLIS_NINJA_BOY, 48, 41
	setobjectxyperm LOCALID_SOOTOPOLIS_WOMAN_1, 45, 43
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SOOTOPOLIS_BOY_1, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_SOOTOPOLIS_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_SOOTOPOLIS_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SootopolisCity_EventScript_SetLayout::
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalLayout
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetLegendariesLayout
	goto_if_le VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
	return

SootopolisCity_EventScript_SetNormalLayout::
	return

SootopolisCity_EventScript_SetLegendariesLayout::
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
	return

SootopolisCity_EventScript_SetWeather::
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalWeather
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalWeather
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetDownpour
	goto_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetDownpour
	goto_if_le VAR_SKY_PILLAR_STATE, 1, Common_EventScript_SetAbnormalWeather
	return

SootopolisCity_EventScript_SetNormalWeather::
	return

SootopolisCity_EventScript_SetDownpour::
	setweather WEATHER_DOWNPOUR
	return

SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos::
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos
	return

SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
	return

SootopolisCity_EventScript_SetExitCaveOfOriginObjPos::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
	end

SootopolisCity_EventScript_SetOutsideGymObjPos::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 29, 33
	setobjectxyperm LOCALID_SOOTOPOLIS_MAXIE, 33, 35
	setobjectxyperm LOCALID_SOOTOPOLIS_ARCHIE, 34, 35
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0, SootopolisCity_EventScript_SetWallaceMiddle
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 1, SootopolisCity_EventScript_SetWallaceRight
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 2, SootopolisCity_EventScript_SetWallaceLeft
	return

SootopolisCity_EventScript_SetWallaceMiddle::
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 33
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetWallaceRight::
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 32, 33
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetWallaceLeft::
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 30, 33
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_SetExpertBlockCaveEntrance::
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
	return

SootopolisCity_OnWarp:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
	.2byte 0

SootopolisCity_EventScript_PlayerFaceLegendaries::
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_PlayerFaceLegendaries1
	call_if_eq VAR_SKY_PILLAR_STATE, 2, SootopolisCity_EventScript_PlayerFaceLegendaries2
	end

SootopolisCity_EventScript_PlayerFaceLegendaries1::
	turnobject LOCALID_PLAYER, DIR_NORTH
	return

SootopolisCity_EventScript_PlayerFaceLegendaries2::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_SKY_PILLAR_STATE, 3
	return

SootopolisCity_OnResume:
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6
	end

SootopolisCity_OnFrame:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
	.2byte 0

@ If not at PokeCenter, assumed to have arrived via Dive
SootopolisCity_EventScript_StartLegendariesScene::
	lockall
	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_LegendariesSceneFromDive
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_LegendariesSceneFromDive
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
	end

SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	doweather
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
	special Script_DoRayquazaScene
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromPokeCenter:
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_PanBackToPokeCenter:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	step_end

SootopolisCity_EventScript_LegendariesSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	setweather WEATHER_ABNORMAL
	doweather
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
	special Script_DoRayquazaScene
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
	waitmovement 0
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToDive
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_PanToActionFromDive:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PanBackToDive:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_KyogreAttack:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_KyogreMoveBack:
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_KyogreIdle:
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	step_end

SootopolisCity_Movement_GroudonAttack:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonDefend:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_GroudonMoveBack:
	lock_facing_direction
	walk_left
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_GroudonIdle:
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end

@ If not at PokeCenter, assumed to have arrived via Dive
SootopolisCity_EventScript_StartRayquazaScene::
	lockall
	special StorePlayerCoordsInVars
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
	end

SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_SOOTOPOLIS_GROUDON
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
	hideobjectat LOCALID_SOOTOPOLIS_RAYQUAZA, MAP_SOOTOPOLIS_CITY
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	playse SE_THUNDER
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
	special WaitWeather
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 3
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SOOTOPOLIS
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
	waitstate
	end

SootopolisCity_EventScript_RayquazaSceneFromDive::
	delay 60
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed FADE_TO_BLACK, 8
	call SootopolisCity_EventScript_SetRoughWater
	removeobject LOCALID_SOOTOPOLIS_GROUDON
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
	setvar VAR_0x8004, TRUE
	special Script_DoRayquazaScene
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
	special WaitWeather
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 2
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_SURF
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
	waitstate
	end

SootopolisCity_EventScript_SetRoughWater::
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
	return

SootopolisCity_Movement_RayquazaFlyOff:
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

SootopolisCity_Movement_PanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerApproachLegendaries:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Unused
SootopolisCity_Movement_PlayerApproachLegendariesDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanUp:
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

@ Unused
SootopolisCity_Movement_UnusedPanBack:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_EventScript_CaveOfOriginExpert::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ExpertPostLegendaries
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ExpertLegendaries
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_ExpertLeadToCave
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLeadToCave::
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertPostLegendaries::
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ExpertLegendaries::
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Kiri::
	lock
	faceplayer
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_KiriGiveBerry
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_KiriGiveBerry
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_KiriRayquaza
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_KiriRayquaza::
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
	closemessage
	release
	end

@ Gives 2 berries daily. First ranges from BERRY_ID_POMEG to BERRY_ID_NOMEL, second is always Figy or Iapapa
SootopolisCity_EventScript_KiriGiveBerry::
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
	giverandomberry BERRY_ID_POMEG, BERRY_ID_NOMEL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
	end

SootopolisCity_EventScript_GiveFigyBerry::
	giveitem ITEM_FIGY_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveIapapaBerry::
	giveitem ITEM_IAPAPA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriReceivedBerry::
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_KiriLikeSeasonBornIn::
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman2::
	lockall
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman2Rayquaza
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Woman2Rayquaza::
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Man::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ManPostLegendaries
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_ManPostLegendaries::
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Woman1PostLegendaries
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman1Rayquaza
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_Woman1Legendaries
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Legendaries::
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_WOMAN_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Woman1PostLegendaries::
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Woman1Rayquaza::
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoy::
	lockall
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_NinjaBoyRayquaza
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_NinjaBoyNormal
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_NinjaBoyNormal
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_NinjaBoyNormal::
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_NinjaBoyRayquaza::
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1::
	lockall
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy1Rayquaza
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Boy1Normal
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_Boy1Normal
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_Boy1Rayquaza::
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1GameClear::
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_Boy1Normal::
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GymSign::
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
	end

SootopolisCity_EventScript_CitySign::
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
	end

EventScript_ClosedSootopolisDoor::
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
	end

SootopolisCity_EventScript_Steven::
	lockall
	applymovement LOCALID_SOOTOPOLIS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_StevenHelpWallace
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_StevenHelpedWallace
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_StevenHelpedWallace
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenHelpWallace::
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenMaxieArchieLeft::
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenHelpedWallace::
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
	waitmovement 0
	delay 120
	applymovement LOCALID_SOOTOPOLIS_EXPERT, SootopolisCity_Movement_ExpertMoveAside
	waitmovement 0
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
	waitmovement 0
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
	waitstate
	end

SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
	waitmovement 0
	return

SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
	waitmovement 0
	return

SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	delay_4
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_ExpertMoveAside:
	walk_slow_left
	walk_in_place_faster_right
	step_end

SootopolisCity_Movement_StevenArriveCaveEntrance:
	walk_down
	walk_down
	walk_left
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_left
	step_end

SootopolisCity_Movement_PlayerArriveCaveEntrance:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
	walk_up
	walk_up
	step_end

SootopolisCity_EventScript_Boy2::
	lockall
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy2Rayquaza
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_Boy2Rayquaza::
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_BlackBelt::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_BlackBeltRayquaza
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_BlackBeltRayquaza::
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Girl::
	lockall
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_GirlRayquaza
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_GirlRayquaza::
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_Maniac::
	lockall
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ManiacRayquaza
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_ManiacRayquaza::
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_Wallace::
	lock
	faceplayer
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_GoToSkyPillar
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GiveWaterfall::
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_WATERFALL
	setflag FLAG_RECEIVED_HM_WATERFALL
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_WallaceMoveFromGym
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_EventScript_WallaceMoveFromGym
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_WallaceMoveFromGymWest
	release
	end

SootopolisCity_EventScript_WallaceMoveFromGym::
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
	waitmovement 0
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
	return

SootopolisCity_EventScript_WallaceMoveFromGymWest::
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
	waitmovement 0
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
	return

SootopolisCity_EventScript_GoToSkyPillar::
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_GoToGym::
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Movement_WallaceMoveFromGym:
	walk_right
	walk_in_place_faster_down
	step_end

SootopolisCity_Movement_WallaceMoveFromGymWest:
	walk_left
	walk_in_place_faster_down
	step_end

SootopolisCity_EventScript_Maxie::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_MaxieRayquaza
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_MaxieRayquaza::
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_Archie::
	lockall
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ArchieRayquaza
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_ArchieRayquaza::
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
	releaseall
	end

SootopolisCity_EventScript_MaxieArchieLeave::
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setvar VAR_MT_PYRE_STATE, 2
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
	waitstate
	releaseall
	end

@ Unused
SootopolisCity_Movement_Levitate::
	levitate
	step_end

@ Unused
SootopolisCity_Movement_DestroyTask::
	destroy_extra_task
	step_end

SootopolisCity_Text_GymSign:
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
	.string "LEADER: JUAN\p"
	.string "“The GYM LEADER with the beauty\n"
	.string "of pure water!”$"

SootopolisCity_Text_CitySign:
	.string "SOOTOPOLIS CITY\p"
	.string "“The mystical city where history\n"
	.string "slumbers.”$"

SootopolisCity_Text_DoorIsClosed:
	.string "The door is closed.$"

SootopolisCity_Text_PhysicallyFitLivingHere:
	.string "Diving in the sea. Climbing up and\n"
	.string "down stairs all the time…\p"
	.string "If you live in this town, you end up\n"
	.string "getting physically fit.$"

SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
	.string "These giant POKéMON suddenly appeared\n"
	.string "in the middle of the city!\p"
	.string "And, I've never seen them before!\p"
	.string "Why are they smashing into each\n"
	.string "other like that?\p"
	.string "Why can't they be friends, those\n"
	.string "POKéMON?$"

SootopolisCity_Text_WhatIsThatGreenPokemon:
	.string "What? What? What?\n"
	.string "What is that green POKéMON?!$"

SootopolisCity_Text_WhereDidLegendariesGo:
	.string "GROUDON and KYOGRE…\n"
	.string "Where did they go?\p"
	.string "Will they cause droughts or downpours\n"
	.string "somewhere else?$"

SootopolisCity_Text_TwoPokemonArentAngry:
	.string "I just get this sense somehow that\n"
	.string "the two POKéMON aren't angry.\p"
	.string "I think… They probably can't control\n"
	.string "their own power…$"

SootopolisCity_Text_FlyingMonStoppedRampage:
	.string "That flying POKéMON came down from\n"
	.string "the sky and stopped the rampaging\l"
	.string "POKéMON…$"

SootopolisCity_Text_WonderWhatWorldIsLike:
	.string "I… I've never been out of this city.\p"
	.string "I wonder what the world is like on\n"
	.string "the other side of this round sky?$"

SootopolisCity_Text_ThisIsWicked:
	.string "Wow!\n"
	.string "This is wicked!$"

SootopolisCity_Text_ThatWasWicked:
	.string "Wow!\n"
	.string "That was wicked!$"

SootopolisCity_Text_GoRedAndBlueMon:
	.string "Go for it, red POKéMON!\n"
	.string "Don't back off, blue POKéMON!$"

SootopolisCity_Text_DoYouKnowMonNames:
	.string "… … … … … …\p"
	.string "Hi, do you know the names of those\n"
	.string "POKéMON fighting over there?$"

SootopolisCity_Text_GreenOneSettlesThings:
	.string "I was wondering which one would win,\n"
	.string "the red one or the blue one, but, oh no,\l"
	.string "it's the green one that settles things!\p"
	.string "Talk about a huge turn of events!$"

SootopolisCity_Text_SeeingLegendWithOwnEyes:
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between POKéMON.\p"
	.string "Well, I'm seeing that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"

SootopolisCity_Text_SawLegendWithOwnEyes:
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between POKéMON.\p"
	.string "Well, I saw that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"

SootopolisCity_Text_BigPokemonFighting:
	.string "A big POKéMON is fighting with\n"
	.string "another big POKéMON!\p"
	.string "Please, someone make them stop!$"

SootopolisCity_Text_PrettyMonCameFromSky:
	.string "A pretty POKéMON came down from\n"
	.string "the sky…$"

SootopolisCity_Text_SootopolisWillBeWrecked:
	.string "Oh, no!\n"
	.string "SOOTOPOLIS CITY will get wrecked!$"

SootopolisCity_Text_SootopolisDidntGetWrecked:
	.string "SOOTOPOLIS CITY didn't get wrecked!$"

SootopolisCity_Text_NoOrdinaryTourist:
	.string "Hm!\n"
	.string "You've come all the way to SOOTOPOLIS?\l"
	.string "You're no ordinary tourist.\p"
	.string "But I suppose that doesn't make you\n"
	.string "an extraordinary tourist, either.$"

SootopolisCity_Text_CityRegainedCalm:
	.string "The city has regained its calm…$"

SootopolisCity_Text_CaveOfOriginPleaseLeave:
	.string "Who might you be?\p"
	.string "This is the CAVE OF ORIGIN.\p"
	.string "The spirits of POKéMON, becalmed at\n"
	.string "MT. PYRE, are said to be revived here.\p"
	.string "Please leave.$"

SootopolisCity_Text_LeadSuperiorTrainerToCave:
	.string "A person with a strong will and\n"
	.string "superior talent…\p"
	.string "A TRAINER who has knowledge and\n"
	.string "experience of many kinds of POKéMON…\p"
	.string "If such a person were to appear, I was\n"
	.string "instructed by WALLACE to lead that\l"
	.string "TRAINER to this CAVE.$"

SootopolisCity_Text_AwakenedPokemonClash:
	.string "Oh, my…\p"
	.string "The clash between the two awakened\n"
	.string "POKéMON was quelled by the awakening\l"
	.string "of a third POKéMON…$"

SootopolisCity_Text_CaveOfOriginSleepsToo:
	.string "This is the CAVE OF ORIGIN…\p"
	.string "With the passing of the crisis,\n"
	.string "the cave, too, shall sleep…$"

SootopolisCity_Text_SootopolisSkyBeautiful:
	.string "SOOTOPOLIS sprang up as a town in\n"
	.string "the crater of a volcano.\p"
	.string "If you look up at the sky, the lip of\n"
	.string "the crater is also visible.\l"
	.string "So, all you see is the sky in a circle.\p"
	.string "But that's what makes the sky above\n"
	.string "SOOTOPOLIS the most beautiful.$"

SootopolisCity_Text_GiganticPokemonFight:
	.string "When two POKéMON that gigantic\n"
	.string "are fighting that savagely, there's\l"
	.string "not much that we can do.$"

SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
	.string "When that third POKéMON flew down,\n"
	.string "I feared the worst.$"

SootopolisCity_Text_NightSkyFavoriteScenery:
	.string "A circle of a night sky framed by\n"
	.string "the crater of a volcano…\p"
	.string "And in that ring, stars flicker and\n"
	.string "blink as if they were alive…\l"
	.string "It's my favorite scenery.$"

SootopolisCity_Text_WeatherWentWild:
	.string "The weather was clear this morning,\n"
	.string "but…\p"
	.string "All of a sudden, dark clouds brewed up,\n"
	.string "rain started falling in sheets, and\l"
	.string "there was thunder and lightning, too.\p"
	.string "The weather just went completely\n"
	.string "wild!\p"
	.string "Is all of this because of those\n"
	.string "POKéMON?$"

SootopolisCity_Text_YouBroughtFlyingMon:
	.string "Oh?\p"
	.string "It was you who brought that flying\n"
	.string "POKéMON here?\p"
	.string "Well, aren't you amazing!$"

SootopolisCity_Text_GroudonPleaseStop:
	.string "MAXIE: G… GROUDON…\n"
	.string "Please! Stop what you're doing!\p"
	.string "I know the extent of your power now!\p"
	.string "If you keep going, all HOENN, not just\n"
	.string "SOOTOPOLIS, will be utterly ruined!$"

SootopolisCity_Text_AfterAllOurScheming:
	.string "MAXIE: So the super-ancient POKéMON\n"
	.string "weren't only GROUDON and KYOGRE…\p"
	.string "After all our fruitless scheming and\n"
	.string "frantic efforts, that one POKéMON's\l"
	.string "simple action puts everything right\l"
	.string "again as if nothing had happened…\p"
	.string "Fu…\n"
	.string "Fuhahaha…$"

SootopolisCity_Text_KyogreCalmDown:
	.string "ARCHIE: KYOGRE! What's wrong?!\n"
	.string "Look over here! It's the RED ORB!\l"
	.string "Calm down! KYOGRE!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "It's no good!\n"
	.string "It's not responding at all!$"

SootopolisCity_Text_TryingMeaninglessToPokemon:
	.string "ARCHIE: KYOGRE and GROUDON both\n"
	.string "flew off to who knows where.\p"
	.string "The weather in HOENN has returned\n"
	.string "to its normal state…\p"
	.string "Haha…\n"
	.string "Hahaha…\p"
	.string "Maybe what we were trying to do was\n"
	.string "something small, even meaningless,\l"
	.string "to POKéMON…$"

SootopolisCity_Text_InvolvedWithCrisisComeWithMe:
	.string "STEVEN: Those POKéMON fighting…\n"
	.string "GROUDON… And KYOGRE…\p"
	.string "The two super-ancient POKéMON\n"
	.string "were awakened from a long sleep…\p"
	.string "And now they are smashing each other\n"
	.string "with their uncontrollable energy…\p"
	.string "…{PLAYER}{KUN}.\p"
	.string "You being here now I'll take to mean\n"
	.string "that you're prepared to become\l"
	.string "involved in this crisis.\p"
	.string "Well, then, there's someone that\n"
	.string "I'd like you to meet.\p"
	.string "Come with me, please.$"

SootopolisCity_Text_DoesThisMakeYourFearPokemon:
	.string "STEVEN: Listen, {PLAYER}{KUN}.\p"
	.string "Does seeing GROUDON and KYOGRE make\n"
	.string "you think POKéMON are to be feared?\p"
	.string "But that's not true.\n"
	.string "POKéMON are really more…\p"
	.string "…Why am I asking you this?\n"
	.string "You already know.$"

SootopolisCity_Text_HereWereAreHelpWallace:
	.string "STEVEN: Okay, here we are!\p"
	.string "Inside here you'll find someone named\n"
	.string "WALLACE.\p"
	.string "I think you have what's needed to\n"
	.string "help him…$"

SootopolisCity_Text_KnowWhatsNeededToHelpHim:
	.string "STEVEN: I think you have what's\n"
	.string "needed to help him…$"

SootopolisCity_Text_NeverBeenToSkyPillar:
	.string "STEVEN: The SKY PILLAR…\p"
	.string "I've never been there.\n"
	.string "I wonder where it could be?$"

SootopolisCity_Text_SoThatsRayquaza:
	.string "STEVEN: So that's RAYQUAZA…\p"
	.string "It's incredible how the two rampaging\n"
	.string "POKéMON would flee from it in fear…$"

SootopolisCity_Text_MaxieArchieLeft:
	.string "STEVEN: It looks like both MAXIE and\n"
	.string "ARCHIE have gone away somewhere.\p"
	.string "Perhaps they've gone to MT. PYRE to\n"
	.string "return those ORBS…$"

SootopolisCity_Text_HaventYouScaledSkyPillar:
	.string "WALLACE: Oh?\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Haven't you scaled the SKY PILLAR\n"
	.string "yet?\p"
	.string "I'm sure that you can make it to\n"
	.string "the top of the SKY PILLAR…$"

SootopolisCity_Text_AquaMagmaDidntMeanHarm:
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "The leaders of TEAM MAGMA and AQUA,\n"
	.string "I don't think they meant harm.\p"
	.string "It wouldn't hurt to hear what they\n"
	.string "have to say for themselves.$"

SootopolisCity_Text_ThankYouForHelpAcceptThis:
	.string "WALLACE: {PLAYER}{KUN}…\n"
	.string "My eyes didn't deceive me.\p"
	.string "Thanks to your help, SOOTOPOLIS…\n"
	.string "No, all of HOENN was saved.\p"
	.string "On behalf of the people, I thank you.\p"
	.string "This is a gift from me.\n"
	.string "Please accept it.$"

SootopolisCity_Text_ExplainWaterfallGoToGym:
	.string "That HIDDEN MACHINE contains\n"
	.string "WATERFALL.\p"
	.string "If you have the RAIN BADGE, a POKéMON\n"
	.string "that has learned that HM move can\l"
	.string "force its way up waterfalls.\p"
	.string "And where does one get the RAIN BADGE?\n"
	.string "You know, don't you?\p"
	.string "That's right! You have to beat\n"
	.string "the SOOTOPOLIS GYM LEADER.\p"
	.string "When you're all set to go, step through\n"
	.string "that door.$"

SootopolisCity_Text_DazzledByMentor:
	.string "WALLACE: I'm sure that you will be\n"
	.string "dazzled by my mentor's breathtakingly\l"
	.string "elegant battle style.$"
SouthernIsland_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Exterior_OnTransition
	.byte 0

SouthernIsland_Exterior_OnTransition:
	setflag FLAG_LANDMARK_SOUTHERN_ISLAND
	end

SouthernIsland_Exterior_EventScript_Sailor::
	lock
	faceplayer
	msgbox EventTicket_Text_SouthernIslandSailBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SouthernIsland_Exterior_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SOUTHERN_ISLAND_SAILOR, MAP_SOUTHERN_ISLAND_EXTERIOR
	setvar VAR_0x8004, LOCALID_SOUTHERN_ISLAND_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SouthernIsland_Exterior_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

Ferry_EventScript_DepartIslandSouth::
	applymovement LOCALID_PLAYER, Ferry_Movement_DepartIslandBoardSouth
	waitmovement 0
	return

Ferry_EventScript_DepartIslandWest::
	applymovement LOCALID_PLAYER, Ferry_Movement_DepartIslandBoardWest
	waitmovement 0
	return

Ferry_Movement_DepartIslandBoardSouth:
	walk_down
	step_end

Ferry_Movement_DepartIslandBoardWest:
	walk_left
	walk_in_place_faster_down
	step_end

SouthernIsland_Exterior_EventScript_Sign::
	msgbox SouthernIsland_Exterior_Text_Sign, MSGBOX_SIGN
	end

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "This is the TRAINER HILL where\n"
	.string "you may enjoy tag battles with many\l"
	.string "TRAINERS.\p"
	.string "Unfortunately, we're still getting\n"
	.string "things ready. Please come back later!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Welcome!\p"
	.string "This is the TRAINER HILL where\n"
	.string "you may enjoy tag battles with many\l"
	.string "TRAINERS!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "Is this your first visit here?\p"
	.string "Before you enter, please save\n"
	.string "your game.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Let's see…\n"
	.string "The TRAINERS here now are…\p"
	.string "Up to floor no. {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Let's see…\n"
	.string "The TRAINERS here now are…\p"
	.string "There appear to be TRAINERS gathered\n"
	.string "in every room.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Would you like to challenge the\n"
	.string "waiting TRAINERS?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "I will time your progress.\n"
	.string "Best of luck!\p"
	.string "On your marks…\p"
	.string "Get set…\p"
	.string "Go!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Please do visit us again!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "That was too bad.\p"
	.string "I think you put in a tremendous\n"
	.string "effort in your battling.\p"
	.string "Please come back and try again!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "I hope you give it your best.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "When the TRAINERS switch places,\n"
	.string "the movement can be hectic.\p"
	.string "To avoid the stampede, we moved\n"
	.string "the reception counter here.\p"
	.string "I'm sorry for the inconvenience.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Thank you for playing!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Here at the TRAINER HILL, we conduct\n"
	.string "an event called the Time Attack.\p"
	.string "It is a race that measures how long\n"
	.string "you take to reach our owner on\l"
	.string "the rooftop from this counter.\p"
	.string "The fastest times are posted on\n"
	.string "the Time Board--try competing with\l"
	.string "your friends.\p"
	.string "In TRAINER battles along the way,\n"
	.string "neither Exp. Points nor money will\l"
	.string "be awarded.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, I'm sorry, but you appear to have\n"
	.string "only one POKéMON with you.\p"
	.string "You will need at least two POKéMON\n"
	.string "to enter this event.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "You finally came!\n"
	.string "Yes, you have arrived!\p"
	.string "Wait! Don't say it!\n"
	.string "I know why you came all the way\l"
	.string "here by yourself!\p"
	.string "You wanted to see me, the owner\n"
	.string "of the TRAINER HILL, because…\p"
	.string "You want to form a tag team with me!\n"
	.string "Wa-hoo!\p"
	.string "…Uh?\n"
	.string "That's not it?\p"
	.string "Anyway, I watched you on your way up.\n"
	.string "Marvelous battling! Bravo, indeed!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "For a marvelous someone like you,\n"
	.string "I have the most marvelous gift!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh, no, full up with things!\n"
	.string "You'll be back later for this!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, hold on here! Did you possibly get\n"
	.string "here marvelously quickly?\p"
	.string "How splendid! You needn't have\n"
	.string "hurried so to see me!\p"
	.string "That is so delightful. I'll have the Time\n"
	.string "Board at the reception updated!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "But, oh…\n"
	.string "You weren't very quick getting here.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Perhaps it would please me more if you\n"
	.string "arrived zippier next time.\p"
	.string "Then, I should be pleased to form\n"
	.string "a tag team with you!\p"
	.string "Until we meet again, amigo!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "I had the TRAINER HILL built for but\n"
	.string "one reason and one only!\p"
	.string "To find the most suitable partner\n"
	.string "with whom I may form a tag team!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Who knows what sort of TRAINERS\n"
	.string "and POKéMON combos are ahead?\p"
	.string "All I know is that I'll knock aside\n"
	.string "anyone that stands in my way!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "I heard tough TRAINERS come to this\n"
	.string "TRAINER HILL from all over.\p"
	.string "I can't wait to test the waters!\p"
	.string "I'll knock aside anyone that stands\n"
	.string "in my way!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Do you see the Time Board over there?\p"
	.string "My friends and I are trying to see who\n"
	.string "can reach the top in the least time.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Do you know when they're opening\n"
	.string "this place up?\p"
	.string "I'm waiting here to be the first\n"
	.string "challenger ever!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Would you like to return to\n"
	.string "the reception counter?$"
