Common_EventScript_PkmnCenterNurse::
# 2 "data/scripts/pkmn_center_nurse.pory"
	lock
# 3 "data/scripts/pkmn_center_nurse.pory"
	faceplayer
# 4 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 0
# 5 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, CountPlayerTrainerStars
# 6 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 4
	goto_if_eq Common_EventScript_PkmnCenterNurse_2
Common_EventScript_PkmnCenterNurse_1:
# 9 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 10 "data/scripts/pkmn_center_nurse.pory"
	case PT, Common_EventScript_PkmnCenterNurse_6
# 11 "data/scripts/pkmn_center_nurse.pory"
	case EN, Common_EventScript_PkmnCenterNurse_7
# 12 "data/scripts/pkmn_center_nurse.pory"
	case ES, Common_EventScript_PkmnCenterNurse_8
Common_EventScript_PkmnCenterNurse_4:
# 14 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 15 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 16 "data/scripts/pkmn_center_nurse.pory"
	case PT, Common_EventScript_PkmnCenterNurse_11
# 17 "data/scripts/pkmn_center_nurse.pory"
	case EN, Common_EventScript_PkmnCenterNurse_12
# 18 "data/scripts/pkmn_center_nurse.pory"
	case ES, Common_EventScript_PkmnCenterNurse_13
Common_EventScript_PkmnCenterNurse_9:
# 20 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterNurse_15
# 22 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_PkmnCenterNurse_16
Common_EventScript_PkmnCenterNurse_14:
	end

Common_EventScript_PkmnCenterNurse_2:
# 7 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_GoldCard
	goto Common_EventScript_PkmnCenterNurse_1

Common_EventScript_PkmnCenterNurse_6:
# 10 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, Common_EventScript_PkmnCenterNurse_Text_1, MSGBOX_AUTOCLOSE
	goto Common_EventScript_PkmnCenterNurse_4

Common_EventScript_PkmnCenterNurse_7:
# 11 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, gText_WouldYouLikeToRestYourPkmn, MSGBOX_AUTOCLOSE
	goto Common_EventScript_PkmnCenterNurse_4

Common_EventScript_PkmnCenterNurse_8:
# 12 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, Common_EventScript_PkmnCenterNurse_Text_2, MSGBOX_AUTOCLOSE
	goto Common_EventScript_PkmnCenterNurse_4

Common_EventScript_PkmnCenterNurse_11:
# 16 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_3, MSGBOX_YESNO
	goto Common_EventScript_PkmnCenterNurse_9

Common_EventScript_PkmnCenterNurse_12:
# 17 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_4, MSGBOX_YESNO
	goto Common_EventScript_PkmnCenterNurse_9

Common_EventScript_PkmnCenterNurse_13:
# 18 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_5, MSGBOX_YESNO
	goto Common_EventScript_PkmnCenterNurse_9

Common_EventScript_PkmnCenterNurse_15:
# 21 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_HealPkmn
	goto Common_EventScript_PkmnCenterNurse_14

Common_EventScript_PkmnCenterNurse_16:
# 23 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_Goodbye
	goto Common_EventScript_PkmnCenterNurse_14


EventScript_PkmnCenterNurse_Goodbye::
# 29 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 30 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 31 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 32 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_Goodbye_3
# 33 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_Goodbye_4
# 34 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_Goodbye_5
EventScript_PkmnCenterNurse_Goodbye_1:
# 36 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
	return

EventScript_PkmnCenterNurse_Goodbye_3:
# 32 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_Goodbye_Text_0
	goto EventScript_PkmnCenterNurse_Goodbye_1

EventScript_PkmnCenterNurse_Goodbye_4:
# 33 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain
	goto EventScript_PkmnCenterNurse_Goodbye_1

EventScript_PkmnCenterNurse_Goodbye_5:
# 34 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_Goodbye_Text_1
	goto EventScript_PkmnCenterNurse_Goodbye_1


EventScript_PkmnCenterNurse_HealPkmn::
# 42 "data/scripts/pkmn_center_nurse.pory"
	incrementgamestat GAME_STAT_USED_POKECENTER
# 43 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8004, 0
	goto_if_eq EventScript_PkmnCenterNurse_HealPkmn_2
# 45 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8004, 1
	goto_if_eq EventScript_PkmnCenterNurse_HealPkmn_3
EventScript_PkmnCenterNurse_HealPkmn_1:
# 48 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 49 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
# 50 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
# 51 "data/scripts/pkmn_center_nurse.pory"
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_HealPkmn_7
EventScript_PkmnCenterNurse_HealPkmn_6:
# 54 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_HealPkmn_2:
# 44 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_PkmnCenterNurse_IllTakeYourPkmn
	goto EventScript_PkmnCenterNurse_HealPkmn_1

EventScript_PkmnCenterNurse_HealPkmn_3:
# 46 "data/scripts/pkmn_center_nurse.pory"
	call EventScript_PkmnCenterNurse_IllTakeYourPkmn2
	goto EventScript_PkmnCenterNurse_HealPkmn_1

EventScript_PkmnCenterNurse_HealPkmn_7:
# 52 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_HealPkmn_6


EventScript_PkmnCenterNurse_IllTakeYourPkmn::
# 59 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 60 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 61 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 62 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_IllTakeYourPkmn_3
# 63 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_IllTakeYourPkmn_4
# 64 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_IllTakeYourPkmn_5
EventScript_PkmnCenterNurse_IllTakeYourPkmn_1:
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmn_3:
# 62 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_IllTakeYourPkmn_Text_0
	goto EventScript_PkmnCenterNurse_IllTakeYourPkmn_1

EventScript_PkmnCenterNurse_IllTakeYourPkmn_4:
# 63 "data/scripts/pkmn_center_nurse.pory"
	message gText_IllTakeYourPkmn
	goto EventScript_PkmnCenterNurse_IllTakeYourPkmn_1

EventScript_PkmnCenterNurse_IllTakeYourPkmn_5:
# 64 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_IllTakeYourPkmn_Text_1
	goto EventScript_PkmnCenterNurse_IllTakeYourPkmn_1


EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
# 70 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 71 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 72 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 73 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_IllTakeYourPkmn2_3
# 74 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_IllTakeYourPkmn2_4
# 75 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_IllTakeYourPkmn2_5
EventScript_PkmnCenterNurse_IllTakeYourPkmn2_1:
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2_3:
# 73 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_IllTakeYourPkmn_Text_0
	goto EventScript_PkmnCenterNurse_IllTakeYourPkmn2_1

EventScript_PkmnCenterNurse_IllTakeYourPkmn2_4:
# 74 "data/scripts/pkmn_center_nurse.pory"
	message gText_IllTakeYourPkmn2
	goto EventScript_PkmnCenterNurse_IllTakeYourPkmn2_1

EventScript_PkmnCenterNurse_IllTakeYourPkmn2_5:
# 75 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_IllTakeYourPkmn_Text_1
	goto EventScript_PkmnCenterNurse_IllTakeYourPkmn2_1


EventScript_PkmnCenterNurse_TakeAndHealPkmn::
# 81 "data/scripts/pkmn_center_nurse.pory"
	hidefollower 0
# 82 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Turn
# 83 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 84 "data/scripts/pkmn_center_nurse.pory"
	dofieldeffect FLDEFF_POKECENTER_HEAL
# 85 "data/scripts/pkmn_center_nurse.pory"
	waitfieldeffect FLDEFF_POKECENTER_HEAL
# 86 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
# 87 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 88 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
# 89 "data/scripts/pkmn_center_nurse.pory"
	callnative UpdateFollowingPokemon
	return


EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
# 94 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
# 95 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_2
EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_1:
# 98 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
# 99 "data/scripts/pkmn_center_nurse.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 100 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8008, 0
	goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_5
# 102 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8008, 1
	goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_6
EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_4:
	end

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_2:
# 96 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_1

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_5:
# 101 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_4

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_6:
# 103 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_4


EventScript_PkmnCenterNurse_ReturnPkmn::
# 110 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8004, 1
	goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn_2
EventScript_PkmnCenterNurse_ReturnPkmn_1:
# 113 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 114 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 115 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 116 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_ReturnPkmn_6
# 117 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_ReturnPkmn_7
# 118 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_ReturnPkmn_8
EventScript_PkmnCenterNurse_ReturnPkmn_4:
# 120 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 121 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 122 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 123 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 124 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_ReturnPkmn_11
# 125 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_ReturnPkmn_12
# 126 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_ReturnPkmn_13
EventScript_PkmnCenterNurse_ReturnPkmn_9:
# 128 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
	return

EventScript_PkmnCenterNurse_ReturnPkmn_2:
# 111 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn2
	goto EventScript_PkmnCenterNurse_ReturnPkmn_1

EventScript_PkmnCenterNurse_ReturnPkmn_6:
# 116 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_ReturnPkmn_Text_0
	goto EventScript_PkmnCenterNurse_ReturnPkmn_4

EventScript_PkmnCenterNurse_ReturnPkmn_7:
# 117 "data/scripts/pkmn_center_nurse.pory"
	message gText_RestoredPkmnToFullHealth
	goto EventScript_PkmnCenterNurse_ReturnPkmn_4

EventScript_PkmnCenterNurse_ReturnPkmn_8:
# 118 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_ReturnPkmn_Text_1
	goto EventScript_PkmnCenterNurse_ReturnPkmn_4

EventScript_PkmnCenterNurse_ReturnPkmn_11:
# 124 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_Goodbye_Text_0
	goto EventScript_PkmnCenterNurse_ReturnPkmn_9

EventScript_PkmnCenterNurse_ReturnPkmn_12:
# 125 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain
	goto EventScript_PkmnCenterNurse_ReturnPkmn_9

EventScript_PkmnCenterNurse_ReturnPkmn_13:
# 126 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_Goodbye_Text_1
	goto EventScript_PkmnCenterNurse_ReturnPkmn_9


EventScript_PkmnCenterNurse_ReturnPkmn2::
# 133 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 134 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 135 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 136 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_ReturnPkmn2_3
# 137 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_ReturnPkmn2_4
# 138 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_ReturnPkmn2_5
EventScript_PkmnCenterNurse_ReturnPkmn2_1:
# 140 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 141 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
# 142 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 143 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 144 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 145 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 146 "data/scripts/pkmn_center_nurse.pory"
	checkgenderstr
# 147 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 148 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_ReturnPkmn2_8
# 149 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_ReturnPkmn2_9
# 150 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_ReturnPkmn2_10
EventScript_PkmnCenterNurse_ReturnPkmn2_6:
# 152 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
	return

EventScript_PkmnCenterNurse_ReturnPkmn2_3:
# 136 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_ReturnPkmn2_Text_0
	goto EventScript_PkmnCenterNurse_ReturnPkmn2_1

EventScript_PkmnCenterNurse_ReturnPkmn2_4:
# 137 "data/scripts/pkmn_center_nurse.pory"
	message gText_ThankYouForWaiting
	goto EventScript_PkmnCenterNurse_ReturnPkmn2_1

EventScript_PkmnCenterNurse_ReturnPkmn2_5:
# 138 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_ReturnPkmn2_Text_1
	goto EventScript_PkmnCenterNurse_ReturnPkmn2_1

EventScript_PkmnCenterNurse_ReturnPkmn2_8:
# 148 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_ReturnPkmn2_Text_2
	goto EventScript_PkmnCenterNurse_ReturnPkmn2_6

EventScript_PkmnCenterNurse_ReturnPkmn2_9:
# 149 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain2
	goto EventScript_PkmnCenterNurse_ReturnPkmn2_6

EventScript_PkmnCenterNurse_ReturnPkmn2_10:
# 150 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_Goodbye_Text_1
	goto EventScript_PkmnCenterNurse_ReturnPkmn2_6


EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
# 157 "data/scripts/pkmn_center_nurse.pory"
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_2
EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_1:
# 160 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 161 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_6
# 162 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_7
# 163 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_8
EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_4:
# 165 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
# 166 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 167 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 168 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 169 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_11
# 170 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_12
# 171 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_13
EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_9:
# 173 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 174 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
# 175 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 176 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 177 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 178 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 179 "data/scripts/pkmn_center_nurse.pory"
	checkgenderstr
# 180 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 181 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_16
# 182 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_17
# 183 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_18
EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_14:
# 185 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_2:
# 158 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_1

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_6:
# 161 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, EventScript_PkmnCenterNurse_ReturnPkmn_Text_0
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_4

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_7:
# 162 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, gText_RestoredPkmnToFullHealth
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_4

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_8:
# 163 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, EventScript_PkmnCenterNurse_ReturnPkmn_Text_1
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_4

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_11:
# 169 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_Text_0
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_9

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_12:
# 170 "data/scripts/pkmn_center_nurse.pory"
	message CableClub_Text_PlayerIsWaiting
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_9

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_13:
# 171 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_Text_1
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_9

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_16:
# 181 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_ReturnPkmn2_Text_2
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_14

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_17:
# 182 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_14

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_18:
# 183 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_Goodbye_Text_1
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_14


EventScript_PkmnCenterNurse_CheckPokerus::
# 190 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, IsPokerusInParty
# 191 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PkmnCenterNurse_CheckPokerus_2
# 193 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_PkmnCenterNurse_CheckPokerus_3
EventScript_PkmnCenterNurse_CheckPokerus_1:
	end

EventScript_PkmnCenterNurse_CheckPokerus_2:
# 192 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ExplainPokerus
	goto EventScript_PkmnCenterNurse_CheckPokerus_1

EventScript_PkmnCenterNurse_CheckPokerus_3:
# 194 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	goto EventScript_PkmnCenterNurse_CheckPokerus_1


EventScript_PkmnCenterNurse_ExplainPokerus::
# 200 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 201 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 202 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 203 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_ExplainPokerus_3
# 204 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_ExplainPokerus_4
# 205 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_ExplainPokerus_5
EventScript_PkmnCenterNurse_ExplainPokerus_1:
# 207 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
# 208 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_POKERUS_EXPLAINED
	return

EventScript_PkmnCenterNurse_ExplainPokerus_3:
# 203 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_ExplainPokerus_Text_0
	goto EventScript_PkmnCenterNurse_ExplainPokerus_1

EventScript_PkmnCenterNurse_ExplainPokerus_4:
# 204 "data/scripts/pkmn_center_nurse.pory"
	message gText_PokerusExplanation
	goto EventScript_PkmnCenterNurse_ExplainPokerus_1

EventScript_PkmnCenterNurse_ExplainPokerus_5:
# 205 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_ExplainPokerus_Text_1
	goto EventScript_PkmnCenterNurse_ExplainPokerus_1


EventScript_PkmnCenterNurse_GoldCard::
# 213 "data/scripts/pkmn_center_nurse.pory"
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_GoldCard_2
EventScript_PkmnCenterNurse_GoldCard_1:
# 216 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
# 217 "data/scripts/pkmn_center_nurse.pory"
	checkgenderstr
# 218 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 219 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_GoldCard_6
# 220 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_GoldCard_7
# 221 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_GoldCard_8
EventScript_PkmnCenterNurse_GoldCard_4:
# 223 "data/scripts/pkmn_center_nurse.pory"
	playse SE_PIN
# 224 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
# 225 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 226 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_Delay48
# 227 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 228 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 229 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_GoldCard_11
# 230 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_GoldCard_12
# 231 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_GoldCard_13
EventScript_PkmnCenterNurse_GoldCard_9:
# 233 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PkmnCenterNurse_GoldCard_15
EventScript_PkmnCenterNurse_GoldCard_14:
# 236 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 237 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 238 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 239 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_GoldCard_19
# 240 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_GoldCard_20
# 241 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_GoldCard_21
EventScript_PkmnCenterNurse_GoldCard_17:
# 243 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
	return

EventScript_PkmnCenterNurse_GoldCard_2:
# 214 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_AskForUsual
	goto EventScript_PkmnCenterNurse_GoldCard_1

EventScript_PkmnCenterNurse_GoldCard_6:
# 219 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, EventScript_PkmnCenterNurse_GoldCard_Text_0, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterNurse_GoldCard_4

EventScript_PkmnCenterNurse_GoldCard_7:
# 220 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, gText_WelcomeCutShort, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterNurse_GoldCard_4

EventScript_PkmnCenterNurse_GoldCard_8:
# 221 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, EventScript_PkmnCenterNurse_GoldCard_Text_1, MSGBOX_DEFAULT
	goto EventScript_PkmnCenterNurse_GoldCard_4

EventScript_PkmnCenterNurse_GoldCard_11:
# 229 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, EventScript_PkmnCenterNurse_GoldCard_Text_2, MSGBOX_YESNO
	goto EventScript_PkmnCenterNurse_GoldCard_9

EventScript_PkmnCenterNurse_GoldCard_12:
# 230 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, gText_NoticesGoldCard, MSGBOX_YESNO
	goto EventScript_PkmnCenterNurse_GoldCard_9

EventScript_PkmnCenterNurse_GoldCard_13:
# 231 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, EventScript_PkmnCenterNurse_GoldCard_Text_3, MSGBOX_YESNO
	goto EventScript_PkmnCenterNurse_GoldCard_9

EventScript_PkmnCenterNurse_GoldCard_15:
# 234 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_GoldCardHealPkmn
	goto EventScript_PkmnCenterNurse_GoldCard_14

EventScript_PkmnCenterNurse_GoldCard_19:
# 239 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_Goodbye_Text_0
	goto EventScript_PkmnCenterNurse_GoldCard_17

EventScript_PkmnCenterNurse_GoldCard_20:
# 240 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain2
	goto EventScript_PkmnCenterNurse_GoldCard_17

EventScript_PkmnCenterNurse_GoldCard_21:
# 241 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_Goodbye_Text_1
	goto EventScript_PkmnCenterNurse_GoldCard_17


EventScript_PkmnCenterNurse_AskForUsual::
# 248 "data/scripts/pkmn_center_nurse.pory"
	checkgenderstr
# 249 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 250 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_AskForUsual_3
# 251 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_AskForUsual_4
# 252 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_AskForUsual_5
EventScript_PkmnCenterNurse_AskForUsual_1:
# 254 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PkmnCenterNurse_AskForUsual_7
EventScript_PkmnCenterNurse_AskForUsual_6:
# 257 "data/scripts/pkmn_center_nurse.pory"
	showpssicon PSS_ICON_JOY
# 258 "data/scripts/pkmn_center_nurse.pory"
	setspeaker Common_EventScript_PkmnCenterNurse_Text_0
# 259 "data/scripts/pkmn_center_nurse.pory"
	switch VAR_LANGUAGE
# 260 "data/scripts/pkmn_center_nurse.pory"
	case PT, EventScript_PkmnCenterNurse_AskForUsual_11
# 261 "data/scripts/pkmn_center_nurse.pory"
	case EN, EventScript_PkmnCenterNurse_AskForUsual_12
# 262 "data/scripts/pkmn_center_nurse.pory"
	case ES, EventScript_PkmnCenterNurse_AskForUsual_13
EventScript_PkmnCenterNurse_AskForUsual_9:
# 264 "data/scripts/pkmn_center_nurse.pory"
	callnative ClosePssIconPic
	return

EventScript_PkmnCenterNurse_AskForUsual_3:
# 250 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, EventScript_PkmnCenterNurse_AskForUsual_Text_0, MSGBOX_YESNO
	goto EventScript_PkmnCenterNurse_AskForUsual_1

EventScript_PkmnCenterNurse_AskForUsual_4:
# 251 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, gText_YouWantTheUsual, MSGBOX_YESNO
	goto EventScript_PkmnCenterNurse_AskForUsual_1

EventScript_PkmnCenterNurse_AskForUsual_5:
# 252 "data/scripts/pkmn_center_nurse.pory"
	msgminibox PSS_ICON_JOY, Common_EventScript_PkmnCenterNurse_Text_0, EventScript_PkmnCenterNurse_AskForUsual_Text_1, MSGBOX_YESNO
	goto EventScript_PkmnCenterNurse_AskForUsual_1

EventScript_PkmnCenterNurse_AskForUsual_7:
# 255 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_GoldCardHealPkmn
	goto EventScript_PkmnCenterNurse_AskForUsual_6

EventScript_PkmnCenterNurse_AskForUsual_11:
# 260 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_ReturnPkmn2_Text_2
	goto EventScript_PkmnCenterNurse_AskForUsual_9

EventScript_PkmnCenterNurse_AskForUsual_12:
# 261 "data/scripts/pkmn_center_nurse.pory"
	message gText_WeHopeToSeeYouAgain2
	goto EventScript_PkmnCenterNurse_AskForUsual_9

EventScript_PkmnCenterNurse_AskForUsual_13:
# 262 "data/scripts/pkmn_center_nurse.pory"
	message EventScript_PkmnCenterNurse_Goodbye_Text_1
	goto EventScript_PkmnCenterNurse_AskForUsual_9


EventScript_PkmnCenterNurse_GoldCardHealPkmn::
# 269 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 1
# 270 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_HealPkmn
	end


# 274 "data/scripts/pkmn_center_nurse.pory"
Movement_PkmnCenterNurse_Bow:
# 275 "data/scripts/pkmn_center_nurse.pory"
	nurse_joy_bow
# 276 "data/scripts/pkmn_center_nurse.pory"
	delay_4
	step_end

# 279 "data/scripts/pkmn_center_nurse.pory"
Movement_PkmnCenterNurse_Turn:
# 280 "data/scripts/pkmn_center_nurse.pory"
	walk_in_place_faster_left
	step_end

Common_EventScript_PkmnCenterNurse_Text_0:
# 10 "data/scripts/pkmn_center_nurse.pory"
	.string "Joy$"

Common_EventScript_PkmnCenterNurse_Text_1:
# 10 "data/scripts/pkmn_center_nurse.pory"
	.string "Olá, e bem-vindo ao CENTRO\nPOKéMON.\pNós restauramos seus POKéMON\ncansados à saúde total.$"

Common_EventScript_PkmnCenterNurse_Text_2:
# 12 "data/scripts/pkmn_center_nurse.pory"
	.string "Hola, y bienvenido al CENTRO\nPOKéMON.\pRestauramos a tus POKéMON cansados\na su salud completa.$"

Common_EventScript_PkmnCenterNurse_Text_3:
# 16 "data/scripts/pkmn_center_nurse.pory"
	.string "Gostaria de descansar seus\nPOKéMON?$"

Common_EventScript_PkmnCenterNurse_Text_4:
# 17 "data/scripts/pkmn_center_nurse.pory"
	.string "Would you like to rest your POKéMON?$"

Common_EventScript_PkmnCenterNurse_Text_5:
# 18 "data/scripts/pkmn_center_nurse.pory"
	.string "¿Te gustaría descansar a tus\nPOKéMON?$"

EventScript_PkmnCenterNurse_Goodbye_Text_0:
# 32 "data/scripts/pkmn_center_nurse.pory"
	.string "Esperamos vê-lo novamente!$"

EventScript_PkmnCenterNurse_Goodbye_Text_1:
# 34 "data/scripts/pkmn_center_nurse.pory"
	.string "¡Esperamos volver a verte!$"

EventScript_PkmnCenterNurse_IllTakeYourPkmn_Text_0:
# 62 "data/scripts/pkmn_center_nurse.pory"
	.string "Certo, vou cuidar dos seus POKéMON\npor alguns segundos.$"

EventScript_PkmnCenterNurse_IllTakeYourPkmn_Text_1:
# 64 "data/scripts/pkmn_center_nurse.pory"
	.string "De acuerdo, cuidaré de tus POKéMON\npor unos segundos.$"

EventScript_PkmnCenterNurse_ReturnPkmn_Text_0:
# 116 "data/scripts/pkmn_center_nurse.pory"
	.string "Obrigada por esperar.\pSeus POKéMON foram restaurados à\nsaúde total.$"

EventScript_PkmnCenterNurse_ReturnPkmn_Text_1:
# 118 "data/scripts/pkmn_center_nurse.pory"
	.string "Gracias por esperar.\pTus POKéMON han sido restaurados a\nsu salud completa.$"

EventScript_PkmnCenterNurse_ReturnPkmn2_Text_0:
# 136 "data/scripts/pkmn_center_nurse.pory"
	.string "Obrigada por esperar.$"

EventScript_PkmnCenterNurse_ReturnPkmn2_Text_1:
# 138 "data/scripts/pkmn_center_nurse.pory"
	.string "Gracias por esperar.$"

EventScript_PkmnCenterNurse_ReturnPkmn2_Text_2:
# 148 "data/scripts/pkmn_center_nurse.pory"
	.string "Esperamos vê-l{STR_VAR_1} novamente!$"

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_Text_0:
# 169 "data/scripts/pkmn_center_nurse.pory"
	.string "Parece que {STR_VAR_1} está\npassando agora mesmo.\lVá em frente!$"

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_Text_1:
# 171 "data/scripts/pkmn_center_nurse.pory"
	.string "Parece que {STR_VAR_1} se está\ntransmitiendo ahora mismo.\l¡Adelante!$"

EventScript_PkmnCenterNurse_ExplainPokerus_Text_0:
# 203 "data/scripts/pkmn_center_nurse.pory"
	.string "Seus POKéMON podem estar\ninfectados com POKéRUS.\pPouco se sabe sobre o POKéRUS,\nexceto que são formas de vida\lmicroscópicas que se prendem aos\lPOKéMON.\pEnquanto infectados, dizem que os\nPOKéMON crescem excepcionalmente\lbem.$"

EventScript_PkmnCenterNurse_ExplainPokerus_Text_1:
# 205 "data/scripts/pkmn_center_nurse.pory"
	.string "Puede que tus POKéMON estén\ninfectados con POKéRUS.\pSe sabe poco sobre el POKéRUS,\nsalvo que son formas de vida\lmicroscópicas que se adhieren a\llos POKéMON.\pSe dice que, mientras están\ninfectados, los POKéMON crecen\lexcepcionalmente bien.$"

EventScript_PkmnCenterNurse_GoldCard_Text_0:
# 219 "data/scripts/pkmn_center_nurse.pory"
	.string "Olá, e bem-vind{STR_VAR_1} ao CENTRO\nPOKéMON.\pNós restauramos seus POKéMON\ncansados à saúde total.\pGostaria de…$"

EventScript_PkmnCenterNurse_GoldCard_Text_1:
# 221 "data/scripts/pkmn_center_nurse.pory"
	.string "Hola, y bienvenid{STR_VAR_1} al CENTRO\nPOKéMON.\pRestauramos a tus POKéMON cansados\na su salud completa.\p¿Te gustaría…$"

EventScript_PkmnCenterNurse_GoldCard_Text_2:
# 229 "data/scripts/pkmn_center_nurse.pory"
	.string "E-esse cartão…\nSerá que é… o CARTÃO DOURADO?!\pAh, a cor dourada é brilhante!\nAs quatro estrelas parecem brilhar!\pJá vi vários TREINADORES com um\nCARTÃO PRATEADO antes, mas,\l{PLAYER}, você é o primeiro\lTREINADOR que já vi com um\lCARTÃO DOURADO!\pCerto, {PLAYER}, permita-me a honra\nde descansar seus POKéMON!$"

EventScript_PkmnCenterNurse_GoldCard_Text_3:
# 231 "data/scripts/pkmn_center_nurse.pory"
	.string "E-esa tarjeta…\n¿Podría ser… la TARJETA DORADA?!\p¡Ah, el color dorado es brillante!\n¡Las cuatro estrellas parecen brillar!\pYa he visto a varios ENTRENADORES\ncon una TARJETA PLATEADA antes,\lpero, {PLAYER}, ¡eres el primer\lENTRENADOR que he visto con una\lTARJETA DORADA!\pDe acuerdo, {PLAYER}, ¡permíteme el\nhonor de descansar a tus POKéMON!$"

EventScript_PkmnCenterNurse_AskForUsual_Text_0:
# 250 "data/scripts/pkmn_center_nurse.pory"
	.string "É um prazer vê-l{STR_VAR_1}, {PLAYER}!\nVocê quer o de sempre, não é?$"

EventScript_PkmnCenterNurse_AskForUsual_Text_1:
# 252 "data/scripts/pkmn_center_nurse.pory"
	.string "¡Me alegra verte, {PLAYER}!\nQuieres lo de siempre, ¿verdad?$"
