PineveilTown_MaysHouse_2F_MapScripts::
# 2 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 13 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_PLAYER_ROOM_STATE, 1
	goto_if_ne PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 9 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_PLAYER_ROOM_STATE, 1
	goto_if_ge PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 5 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
	return

PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 10 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_KAEL_SLEEPING, MOVEMENT_TYPE_INVISIBLE
	return

PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 7 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_KAEL_SLEEPING, 7, 6
	return

PineveilTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_PLAYER_ROOM_STATE, 0, PineveilTown_PlayerRoom_Start_Story
# 15 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SILENT_FOREST_STATE, 1, PineveilTown_PlayerRoom_After_Story
	.2byte 0


PineveilTown_PlayerRoom_After_Story::
# 20 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	lockall
# 21 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 22 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerRoom_After_Story_3
# 23 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerRoom_After_Story_4
# 24 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerRoom_After_Story_5
PineveilTown_PlayerRoom_After_Story_1:
# 26 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SILENT_FOREST_STATE, 2
# 27 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerRoom_After_Story_3:
# 22 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_After_Story_Text_0, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerRoom_After_Story_1

PineveilTown_PlayerRoom_After_Story_4:
# 23 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_After_Story_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerRoom_After_Story_1

PineveilTown_PlayerRoom_After_Story_5:
# 24 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_After_Story_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerRoom_After_Story_1


PineveilTown_PlayerRoom_Start_Story::
# 32 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playbgm MUS_RG_SEVII_45, 0
# 33 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	delay 400
# 34 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	special SpawnCameraObject
# 35 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_CAMERA, Movement_Camera_Goes_Up
# 36 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 37 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	special RemoveCameraObject
# 38 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 39 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	delay 30
# 40 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MSGBOXONMIDDLE
# 41 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 43 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerRoom_Start_Story_3
# 44 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerRoom_Start_Story_4
# 45 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerRoom_Start_Story_5
PineveilTown_PlayerRoom_Start_Story_1:
# 47 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitbuttonpress
# 48 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	closemessage
# 49 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_MSGBOXONMIDDLE
# 50 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_SPAWN_INVISIBLE
# 51 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_M_NIGHTMARE
# 52 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitse
# 53 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setvar VAR_PLAYER_ROOM_STATE, 1
# 54 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 55 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	warpsilent MAP_SILENT_FOREST, 42, 23
# 56 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitstate
# 57 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	release
	end

PineveilTown_PlayerRoom_Start_Story_3:
# 43 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	transbox PineveilTown_PlayerRoom_Start_Story_Text_0
	goto PineveilTown_PlayerRoom_Start_Story_1

PineveilTown_PlayerRoom_Start_Story_4:
# 44 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	transbox PineveilTown_PlayerRoom_Start_Story_Text_1
	goto PineveilTown_PlayerRoom_Start_Story_1

PineveilTown_PlayerRoom_Start_Story_5:
# 45 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	transbox PineveilTown_PlayerRoom_Start_Story_Text_2
	goto PineveilTown_PlayerRoom_Start_Story_1


PineveilTown_Player_PC::
# 62 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	lockall
# 63 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 64 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 65 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 66 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 67 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_Player_PC_3
# 70 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_Player_PC_4
# 73 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_Player_PC_5
PineveilTown_Player_PC_1:
# 76 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 77 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_Player_PC_3:
# 68 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_Player_PC_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_Player_PC_1

PineveilTown_Player_PC_4:
# 71 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_Player_PC_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_Player_PC_1

PineveilTown_Player_PC_5:
# 74 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_Player_PC_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_Player_PC_1


PineveilTown_TurnOffPlayer_PC::
# 82 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 83 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 84 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 85 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


PineveilTown_PlayerVideoGamePassword::
# 90 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	lockall
# 91 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 92 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_3
# 95 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_4
# 98 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_5
PineveilTown_PlayerVideoGamePassword_1:
# 101 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	special EnterCode
# 102 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitstate
# 103 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	special GetCodeFeedback
# 104 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_RESULT
# 105 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case 0, PineveilTown_PlayerVideoGamePassword_8
# 107 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case 1, PineveilTown_PlayerVideoGamePassword_9
# 109 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case 2, PineveilTown_PlayerVideoGamePassword_10
# 111 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case 3, PineveilTown_PlayerVideoGamePassword_11
PineveilTown_PlayerVideoGamePassword_6:
# 114 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword
	return

PineveilTown_PlayerVideoGamePassword_3:
# 93 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_1

PineveilTown_PlayerVideoGamePassword_4:
# 96 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_1

PineveilTown_PlayerVideoGamePassword_5:
# 99 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_1

PineveilTown_PlayerVideoGamePassword_8:
# 106 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls
	goto PineveilTown_PlayerVideoGamePassword_6

PineveilTown_PlayerVideoGamePassword_9:
# 108 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel
	goto PineveilTown_PlayerVideoGamePassword_6

PineveilTown_PlayerVideoGamePassword_10:
# 110 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_RareCandy
	goto PineveilTown_PlayerVideoGamePassword_6

PineveilTown_PlayerVideoGamePassword_11:
# 112 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_StartPack
	goto PineveilTown_PlayerVideoGamePassword_6


PineveilTown_PlayerVideoGamePassword_QuickBalls::
# 118 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_QUICK_BALLS, PineveilTown_PlayerVideoGamePassword_AlreadyReceived
# 119 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_QUICK_BALL, 10
# 120 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_QuickBalls_2
PineveilTown_PlayerVideoGamePassword_QuickBalls_1:
# 123 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 124 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 125 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_QuickBalls_6
# 128 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_QuickBalls_7
# 131 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_QuickBalls_8
PineveilTown_PlayerVideoGamePassword_QuickBalls_4:
# 134 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitse
# 135 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_QUICK_BALL, 10
# 136 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_QUICK_BALLS
# 137 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	closemessage
# 138 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_QuickBalls_2:
# 121 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_NoBagSpace
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_1

PineveilTown_PlayerVideoGamePassword_QuickBalls_6:
# 126 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_4

PineveilTown_PlayerVideoGamePassword_QuickBalls_7:
# 129 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_4

PineveilTown_PlayerVideoGamePassword_QuickBalls_8:
# 132 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_4


SystemScript_Infinite_Repel_Off::
# 143 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	lockall
# 144 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 145 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_Off_3
# 148 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_Off_4
# 151 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_Off_5
SystemScript_Infinite_Repel_Off_1:
# 154 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SystemScript_Infinite_Repel_Off_7
SystemScript_Infinite_Repel_Off_6:
# 158 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_NO_RANDOM_WILD_ENCOUNTERS
# 159 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 160 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_Off_11
# 162 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_Off_12
# 164 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_Off_13
SystemScript_Infinite_Repel_Off_9:
# 167 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	return

SystemScript_Infinite_Repel_Off_3:
# 146 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_0, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_Off_1

SystemScript_Infinite_Repel_Off_4:
# 149 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_1, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_Off_1

SystemScript_Infinite_Repel_Off_5:
# 152 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_2, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_Off_1

SystemScript_Infinite_Repel_Off_7:
# 156 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	goto SystemScript_Infinite_Repel_Off_6

SystemScript_Infinite_Repel_Off_11:
# 161 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_3, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_Off_9

SystemScript_Infinite_Repel_Off_12:
# 163 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_4, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_Off_9

SystemScript_Infinite_Repel_Off_13:
# 165 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_5, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_Off_9


SystemScript_Infinite_Repel_On::
# 171 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	lockall
# 172 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 173 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_On_3
# 176 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_On_4
# 179 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_On_5
SystemScript_Infinite_Repel_On_1:
# 182 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SystemScript_Infinite_Repel_On_7
SystemScript_Infinite_Repel_On_6:
# 186 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_NO_RANDOM_WILD_ENCOUNTERS
# 187 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 188 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_On_11
# 190 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_On_12
# 192 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_On_13
SystemScript_Infinite_Repel_On_9:
# 195 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	return

SystemScript_Infinite_Repel_On_3:
# 174 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_0, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_On_1

SystemScript_Infinite_Repel_On_4:
# 177 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_1, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_On_1

SystemScript_Infinite_Repel_On_5:
# 180 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_2, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_On_1

SystemScript_Infinite_Repel_On_7:
# 184 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	goto SystemScript_Infinite_Repel_On_6

SystemScript_Infinite_Repel_On_11:
# 189 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_3, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_On_9

SystemScript_Infinite_Repel_On_12:
# 191 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_4, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_On_9

SystemScript_Infinite_Repel_On_13:
# 193 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_5, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_On_9


EndScript::
# 199 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


PineveilTown_PlayerVideoGamePassword_InfiniteRepel::
# 204 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_ULTRA_REPEL, PineveilTown_PlayerVideoGamePassword_AlreadyReceived
# 205 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_ULTRA_REPEL
# 206 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_InfiniteRepel_2
PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1:
# 209 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 210 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 211 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_InfiniteRepel_6
# 214 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_InfiniteRepel_7
# 217 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_InfiniteRepel_8
PineveilTown_PlayerVideoGamePassword_InfiniteRepel_4:
# 220 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitse
# 221 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_ULTRA_REPEL, 1
# 222 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	closemessage
# 223 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_ULTRA_REPEL
# 224 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_2:
# 207 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_NoBagSpace
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_6:
# 212 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_4

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_7:
# 215 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_4

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_8:
# 218 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_4


PineveilTown_PlayerVideoGamePassword_AlreadyReceived::
# 229 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_FAILURE
# 230 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 231 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_AlreadyReceived_3
# 234 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_AlreadyReceived_4
# 237 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_AlreadyReceived_5
PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1:
# 240 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitse
# 241 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	closemessage
# 242 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_3:
# 232 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_4:
# 235 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_5:
# 238 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1


PineveilTown_PlayerVideoGamePassword_RareCandy::
# 247 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_RARE_CANDIES, PineveilTown_PlayerVideoGamePassword_AlreadyReceived
# 248 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_RARE_CANDY, 50
# 249 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_RareCandy_2
PineveilTown_PlayerVideoGamePassword_RareCandy_1:
# 252 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 253 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 254 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_RareCandy_6
# 257 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_RareCandy_7
# 260 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_RareCandy_8
PineveilTown_PlayerVideoGamePassword_RareCandy_4:
# 263 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitse
# 264 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_RARE_CANDY, 50
# 265 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_RARE_CANDIES
# 266 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	closemessage
# 267 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_RareCandy_2:
# 250 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_NoBagSpace
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_1

PineveilTown_PlayerVideoGamePassword_RareCandy_6:
# 255 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_RareCandy_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_4

PineveilTown_PlayerVideoGamePassword_RareCandy_7:
# 258 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_RareCandy_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_4

PineveilTown_PlayerVideoGamePassword_RareCandy_8:
# 261 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_RareCandy_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_4


PineveilTown_PlayerVideoGamePassword_StartPack::
# 272 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_STARTER_PACK, PineveilTown_PlayerVideoGamePassword_AlreadyReceived
# 273 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	call PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace
# 274 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_StartPack_2
PineveilTown_PlayerVideoGamePassword_StartPack_1:
# 277 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 278 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 279 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_StartPack_6
# 282 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_StartPack_7
# 285 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_StartPack_8
PineveilTown_PlayerVideoGamePassword_StartPack_4:
# 288 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitse
# 289 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_METAL_COAT, 1
# 290 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SOFT_SAND, 1
# 291 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_HARD_STONE, 1
# 292 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MIRACLE_SEED, 1
# 293 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_BLACK_GLASSES, 1
# 294 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_BLACK_BELT, 1
# 295 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MAGNET, 1
# 296 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MYSTIC_WATER, 1
# 297 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SHARP_BEAK, 1
# 298 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_POISON_BARB, 1
# 299 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_NEVER_MELT_ICE, 1
# 300 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SPELL_TAG, 1
# 301 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_TWISTED_SPOON, 1
# 302 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHARCOAL, 1
# 303 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_DRAGON_FANG, 1
# 304 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SILK_SCARF, 1
# 305 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_OCCA_BERRY, 50
# 306 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_PASSHO_BERRY, 50
# 307 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_WACAN_BERRY, 50
# 308 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_RINDO_BERRY, 50
# 309 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_YACHE_BERRY, 50
# 310 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHOPLE_BERRY, 50
# 311 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_KEBIA_BERRY, 50
# 312 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SHUCA_BERRY, 50
# 313 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_COBA_BERRY, 50
# 314 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_PAYAPA_BERRY, 50
# 315 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_TANGA_BERRY, 50
# 316 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHARTI_BERRY, 50
# 317 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_KASIB_BERRY, 50
# 318 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_HABAN_BERRY, 50
# 319 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_COLBUR_BERRY, 50
# 320 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_BABIRI_BERRY, 50
# 321 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHILAN_BERRY, 50
# 322 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MICLE_BERRY, 50
# 323 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CUSTAP_BERRY, 50
# 324 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_JABOCA_BERRY, 50
# 325 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_ROWAP_BERRY, 50
# 326 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_ROSELI_BERRY, 50
# 327 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_KEE_BERRY, 50
# 328 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MARANGA_BERRY, 50
# 329 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_STARTER_PACK
# 330 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	closemessage
# 331 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_StartPack_2:
# 275 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_NoBagSpace
	goto PineveilTown_PlayerVideoGamePassword_StartPack_1

PineveilTown_PlayerVideoGamePassword_StartPack_6:
# 280 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_StartPack_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_StartPack_4

PineveilTown_PlayerVideoGamePassword_StartPack_7:
# 283 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_StartPack_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_StartPack_4

PineveilTown_PlayerVideoGamePassword_StartPack_8:
# 286 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_StartPack_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_StartPack_4


PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace::
# 336 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_METAL_COAT
# 337 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_2
# 338 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_SOFT_SAND
# 339 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_5
# 340 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_HARD_STONE
# 341 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_8
# 342 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_MIRACLE_SEED
# 343 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_11
# 344 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_BLACK_GLASSES
# 345 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_14
# 346 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_BLACK_BELT
# 347 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_17
# 348 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_MAGNET
# 349 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_20
# 350 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_MYSTIC_WATER
# 351 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_23
# 352 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_SHARP_BEAK
# 353 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_26
# 354 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_POISON_BARB
# 355 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_29
# 356 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_NEVER_MELT_ICE
# 357 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_32
# 358 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_SPELL_TAG
# 359 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_35
# 360 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_TWISTED_SPOON
# 361 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_38
# 362 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_CHARCOAL
# 363 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_41
# 364 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_DRAGON_FANG
# 365 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_44
# 366 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_SILK_SCARF
# 367 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_47
# 368 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_OCCA_BERRY, 50
# 369 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_50
# 370 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_PASSHO_BERRY, 50
# 371 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_53
# 372 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_WACAN_BERRY, 50
# 373 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_56
# 374 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_RINDO_BERRY, 50
# 375 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_59
# 376 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_YACHE_BERRY, 50
# 377 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_62
# 378 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_CHOPLE_BERRY, 50
# 379 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_65
# 380 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_KEBIA_BERRY, 50
# 381 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_68
# 382 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_SHUCA_BERRY, 50
# 383 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_71
# 384 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_COBA_BERRY, 50
# 385 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_74
# 386 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_PAYAPA_BERRY, 50
# 387 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_77
# 388 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_TANGA_BERRY, 50
# 389 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_80
# 390 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_CHARTI_BERRY, 50
# 391 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_83
# 392 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_KASIB_BERRY, 50
# 393 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_86
# 394 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_HABAN_BERRY, 50
# 395 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_89
# 396 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_COLBUR_BERRY, 50
# 397 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_92
# 398 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_BABIRI_BERRY, 50
# 399 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_95
# 400 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_CHILAN_BERRY, 50
# 401 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_98
# 402 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_MICLE_BERRY, 50
# 403 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_101
# 404 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_CUSTAP_BERRY, 50
# 405 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_104
# 406 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_JABOCA_BERRY, 50
# 407 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_107
# 408 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_ROWAP_BERRY, 50
# 409 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_110
# 410 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_ROSELI_BERRY, 50
# 411 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_113
# 412 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_KEE_BERRY, 50
# 413 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_116
# 414 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	checkitemspace ITEM_MARANGA_BERRY, 50
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_2:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_5:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_8:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_11:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_14:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_17:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_20:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_23:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_26:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_29:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_32:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_35:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_38:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_41:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_44:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_47:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_50:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_53:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_56:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_59:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_62:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_65:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_68:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_71:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_74:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_77:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_80:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_83:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_86:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_89:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_92:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_95:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_98:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_101:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_104:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_107:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_110:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_113:
	return

PineveilTown_PlayerVideoGamePassword_CheckStartPackSpace_116:
	return


PineveilTown_PlayerVideoGamePassword_NoBagSpace::
# 419 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_FAILURE
# 420 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 421 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerVideoGamePassword_NoBagSpace_3
# 422 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerVideoGamePassword_NoBagSpace_4
# 423 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerVideoGamePassword_NoBagSpace_5
PineveilTown_PlayerVideoGamePassword_NoBagSpace_1:
# 425 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitse
# 426 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	closemessage
# 427 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_NoBagSpace_3:
# 421 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_NoBagSpace_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_NoBagSpace_1

PineveilTown_PlayerVideoGamePassword_NoBagSpace_4:
# 422 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_NoBagSpace_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_NoBagSpace_1

PineveilTown_PlayerVideoGamePassword_NoBagSpace_5:
# 423 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_NoBagSpace_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_NoBagSpace_1


PineveilTown_PlayerVideoGamePassword_WrongPassword::
# 432 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	playse SE_FAILURE
# 433 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 434 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_WrongPassword_3
# 437 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_WrongPassword_4
# 440 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_WrongPassword_5
PineveilTown_PlayerVideoGamePassword_WrongPassword_1:
# 443 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitse
# 444 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	closemessage
# 445 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_WrongPassword_3:
# 435 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword_1

PineveilTown_PlayerVideoGamePassword_WrongPassword_4:
# 438 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword_1

PineveilTown_PlayerVideoGamePassword_WrongPassword_5:
# 441 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword_1


PineveilTown_PlayerRoom_Slowpoke_Doll::
# 450 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	lockall
# 451 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 452 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerRoom_Slowpoke_Doll_3
# 455 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerRoom_Slowpoke_Doll_4
# 458 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerRoom_Slowpoke_Doll_5
PineveilTown_PlayerRoom_Slowpoke_Doll_1:
# 461 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	waitstate
# 462 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	closemessage
# 463 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerRoom_Slowpoke_Doll_3:
# 453 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_Slowpoke_Doll_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerRoom_Slowpoke_Doll_1

PineveilTown_PlayerRoom_Slowpoke_Doll_4:
# 456 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_Slowpoke_Doll_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerRoom_Slowpoke_Doll_1

PineveilTown_PlayerRoom_Slowpoke_Doll_5:
# 459 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_Slowpoke_Doll_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerRoom_Slowpoke_Doll_1


# 467 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
Movement_Camera_Goes_Up:
# 468 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	walk_up
# 468 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	walk_up
# 468 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	walk_up
# 468 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	walk_up
# 468 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	walk_up
# 468 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	walk_up
# 468 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	walk_up
# 469 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	delay_16
	step_end

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile::
# 473 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	lockall
# 474 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 475 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_eq PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_2
# 478 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	moveplayer Movement_Player_GoTo_Window
PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_1:
# 480 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 481 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_7
# 482 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_8
# 483 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_9
PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5:
# 485 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	pause 30
# 486 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	moveplayer Common_Movement_FaceRight
# 487 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	setvar VAR_PLAYER_ROOM_2F_TILE, 1
# 488 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_2:
# 476 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	moveplayer Common_Movement_FaceUp
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_1

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_7:
# 481 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_0
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_8:
# 482 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_1
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_9:
# 483 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_2
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5


# 492 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
Movement_Player_GoTo_Window:
# 493 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	walk_left
# 494 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	walk_up
# 495 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	face_up
	step_end

PineveilTown_PlayerRoom_After_Story_Text_0:
# 22 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Aquilo foi só um sonho… ou não?$"

PineveilTown_PlayerRoom_After_Story_Text_1:
# 23 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "That was just a dream… or not?$"

PineveilTown_PlayerRoom_After_Story_Text_2:
# 24 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Eso fue solo un sueño… o no?$"

PineveilTown_PlayerRoom_Start_Story_Text_0:
# 43 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "…algo está chamando.$"

PineveilTown_PlayerRoom_Start_Story_Text_1:
# 44 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "…something is calling.$"

PineveilTown_PlayerRoom_Start_Story_Text_2:
# 45 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "…algo está llamando.$"

PineveilTown_Player_PC_Text_0:
# 68 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER} ligou o PC.$"

PineveilTown_Player_PC_Text_1:
# 71 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER} booted up the PC.$"

PineveilTown_Player_PC_Text_2:
# 74 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER} encendió la PC.$"

PineveilTown_PlayerVideoGamePassword_Text_0:
# 93 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "É um Wii!\nEle é controlado por um Wii Remote!$"

PineveilTown_PlayerVideoGamePassword_Text_1:
# 96 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "It's a Wii!\nIt's controlled by a Wii Remote!$"

PineveilTown_PlayerVideoGamePassword_Text_2:
# 99 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Es un Wii!\nEstá controlado por un mando Wii!$"

PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_0:
# 126 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu 10 Quick Balls!$"

PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_1:
# 129 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received 10 Quick Balls!$"

PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_2:
# 132 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido 10 Quick Balls!$"

SystemScript_Infinite_Repel_Off_Text_0:
# 146 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Você gostaria de desativar o\nUltra Repel?$"

SystemScript_Infinite_Repel_Off_Text_1:
# 149 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Would you like to disable the\nUltra Repel?$"

SystemScript_Infinite_Repel_Off_Text_2:
# 152 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "¿Quieres desactivar el\nUltra Repel?$"

SystemScript_Infinite_Repel_Off_Text_3:
# 161 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel desativado!$"

SystemScript_Infinite_Repel_Off_Text_4:
# 163 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel disabled!$"

SystemScript_Infinite_Repel_Off_Text_5:
# 165 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "¡Ultra Repel desactivado!$"

SystemScript_Infinite_Repel_On_Text_0:
# 174 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Você gostaria de ativar o\nUltra Repel?$"

SystemScript_Infinite_Repel_On_Text_1:
# 177 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Would you like to enable the\nUltra Repel?$"

SystemScript_Infinite_Repel_On_Text_2:
# 180 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "¿Quieres activar el\nUltra Repel?$"

SystemScript_Infinite_Repel_On_Text_3:
# 189 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel ativado!$"

SystemScript_Infinite_Repel_On_Text_4:
# 191 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel enabled!$"

SystemScript_Infinite_Repel_On_Text_5:
# 193 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "¡Ultra Repel activado!$"

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_0:
# 212 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu um Ultra Repel!$"

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_1:
# 215 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received an Ultra Repel!$"

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_2:
# 218 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido un Ultra Repel!$"

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_0:
# 232 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Você já recebeu este prêmio antes.\nNão pode receber novamente!$"

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_1:
# 235 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "You have already received this\nprize. You can't receive it again!$"

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_2:
# 238 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Ya has recibido este premio.\n¡No puedes recibirlo otra vez!$"

PineveilTown_PlayerVideoGamePassword_RareCandy_Text_0:
# 255 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu 50 Rare Candies!$"

PineveilTown_PlayerVideoGamePassword_RareCandy_Text_1:
# 258 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received 50 Rare Candies!$"

PineveilTown_PlayerVideoGamePassword_RareCandy_Text_2:
# 261 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido 50 Rare Candies!$"

PineveilTown_PlayerVideoGamePassword_StartPack_Text_0:
# 280 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu um Pacote de Itens!$"

PineveilTown_PlayerVideoGamePassword_StartPack_Text_1:
# 283 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received a Pack of Items!$"

PineveilTown_PlayerVideoGamePassword_StartPack_Text_2:
# 286 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido un Pacote de Itens!$"

PineveilTown_PlayerVideoGamePassword_NoBagSpace_Text_0:
# 421 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Não há espaço suficiente na Bolsa.\pLibere espaço e tente novamente.$"

PineveilTown_PlayerVideoGamePassword_NoBagSpace_Text_1:
# 422 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "There isn't enough room in your Bag.\pMake some room and try again.$"

PineveilTown_PlayerVideoGamePassword_NoBagSpace_Text_2:
# 423 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "No hay suficiente espacio en la\nBolsa.\pHaz espacio e inténtalo de nuevo.$"

PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_0:
# 435 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Senha incorreta!\nTente novamente.$"

PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_1:
# 438 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Wrong password!\nPlease try again.$"

PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_2:
# 441 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña incorrecta!\nInténtalo de nuevo.$"

PineveilTown_PlayerRoom_Slowpoke_Doll_Text_0:
# 453 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "É um Slowpoke de pelúcia.\nEle é tão fofinho!$"

PineveilTown_PlayerRoom_Slowpoke_Doll_Text_1:
# 456 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "It's a Slowpoke plush doll.\nIt's so cute!$"

PineveilTown_PlayerRoom_Slowpoke_Doll_Text_2:
# 459 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "Es un peluche de Slowpoke.\n¡Es tan lindo!$"

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_0:
# 481 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "A chuva parou há pouco tempo.$"

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_1:
# 482 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "The rain stopped not long ago.$"

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_2:
# 483 "data/maps/PineveilTown_MaysHouse_2F/scripts.pory"
	.string "La lluvia paró hace poco.$"
