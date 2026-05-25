LittlerootTown_MaysHouse_2F_MapScripts::
# 2 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_PLAYER_ROOM_STATE, 1
	goto_if_ne LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 5 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 7 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_KAEL_SLEEPING, 7, 6
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_PLAYER_ROOM_STATE, 0, PineveilTown_PlayerRoom_Start_Story
# 13 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SILENT_FOREST_STATE, 1, PineveilTown_PlayerRoom_After_Story
	.2byte 0


PineveilTown_PlayerRoom_After_Story::
# 18 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 19 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 20 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerRoom_After_Story_3
# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerRoom_After_Story_4
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerRoom_After_Story_5
PineveilTown_PlayerRoom_After_Story_1:
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SILENT_FOREST_STATE, 2
# 25 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerRoom_After_Story_3:
# 20 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_After_Story_Text_0, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerRoom_After_Story_1

PineveilTown_PlayerRoom_After_Story_4:
# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_After_Story_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerRoom_After_Story_1

PineveilTown_PlayerRoom_After_Story_5:
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_After_Story_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerRoom_After_Story_1


PineveilTown_PlayerRoom_Start_Story::
# 30 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playbgm MUS_RG_SEVII_45, 0
# 31 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 400
# 32 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special SpawnCameraObject
# 33 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_CAMERA, Movement_Camera_Goes_Up
# 34 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 35 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special RemoveCameraObject
# 36 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 37 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 30
# 38 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MSGBOXONMIDDLE
# 39 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerRoom_Start_Story_3
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerRoom_Start_Story_4
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerRoom_Start_Story_5
PineveilTown_PlayerRoom_Start_Story_1:
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitbuttonpress
# 46 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 47 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_MSGBOXONMIDDLE
# 48 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_SPAWN_INVISIBLE
# 49 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_M_NIGHTMARE
# 50 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 51 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_PLAYER_ROOM_STATE, 1
# 52 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 1
# 53 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	warpsilent MAP_SILENT_FOREST, 68, 27
# 54 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	release
	end

PineveilTown_PlayerRoom_Start_Story_3:
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	transbox PineveilTown_PlayerRoom_Start_Story_Text_0
	goto PineveilTown_PlayerRoom_Start_Story_1

PineveilTown_PlayerRoom_Start_Story_4:
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	transbox PineveilTown_PlayerRoom_Start_Story_Text_1
	goto PineveilTown_PlayerRoom_Start_Story_1

PineveilTown_PlayerRoom_Start_Story_5:
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	transbox PineveilTown_PlayerRoom_Start_Story_Text_2
	goto PineveilTown_PlayerRoom_Start_Story_1


PineveilTown_Player_PC::
# 59 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 60 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 61 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 62 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 63 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 64 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_Player_PC_3
# 67 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_Player_PC_4
# 70 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_Player_PC_5
PineveilTown_Player_PC_1:
# 73 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 74 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 75 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_Player_PC_3:
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_Player_PC_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_Player_PC_1

PineveilTown_Player_PC_4:
# 68 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_Player_PC_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_Player_PC_1

PineveilTown_Player_PC_5:
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_Player_PC_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_Player_PC_1


PineveilTown_TurnOffPlayer_PC::
# 80 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 81 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 82 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 83 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


PineveilTown_PlayerVideoGamePassword::
# 88 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 89 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 90 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_3
# 93 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_4
# 96 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_5
PineveilTown_PlayerVideoGamePassword_1:
# 99 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special EnterCode
# 100 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 101 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special GetCodeFeedback
# 102 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_RESULT
# 103 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 0, PineveilTown_PlayerVideoGamePassword_8
# 105 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 1, PineveilTown_PlayerVideoGamePassword_9
# 107 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 2, PineveilTown_PlayerVideoGamePassword_10
# 109 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 3, PineveilTown_PlayerVideoGamePassword_11
PineveilTown_PlayerVideoGamePassword_6:
# 112 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword
	return

PineveilTown_PlayerVideoGamePassword_3:
# 91 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_1

PineveilTown_PlayerVideoGamePassword_4:
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_1

PineveilTown_PlayerVideoGamePassword_5:
# 97 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_1

PineveilTown_PlayerVideoGamePassword_8:
# 104 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls
	goto PineveilTown_PlayerVideoGamePassword_6

PineveilTown_PlayerVideoGamePassword_9:
# 106 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel
	goto PineveilTown_PlayerVideoGamePassword_6

PineveilTown_PlayerVideoGamePassword_10:
# 108 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_RareCandy
	goto PineveilTown_PlayerVideoGamePassword_6

PineveilTown_PlayerVideoGamePassword_11:
# 110 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_StartPack
	goto PineveilTown_PlayerVideoGamePassword_6


PineveilTown_PlayerVideoGamePassword_QuickBalls::
# 116 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 117 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 118 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_QuickBalls_3
# 121 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_QuickBalls_4
# 124 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_QuickBalls_5
PineveilTown_PlayerVideoGamePassword_QuickBalls_1:
# 127 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 128 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_QUICK_BALL, 10
# 129 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 130 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_QuickBalls_3:
# 119 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_1

PineveilTown_PlayerVideoGamePassword_QuickBalls_4:
# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_1

PineveilTown_PlayerVideoGamePassword_QuickBalls_5:
# 125 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_1


SystemScript_Infinite_Repel_Off::
# 135 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 136 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 137 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_Off_3
# 140 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_Off_4
# 143 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_Off_5
SystemScript_Infinite_Repel_Off_1:
# 146 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SystemScript_Infinite_Repel_Off_7
SystemScript_Infinite_Repel_Off_6:
# 150 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_NO_RANDOM_WILD_ENCOUNTERS
# 151 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 152 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_Off_11
# 154 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_Off_12
# 156 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_Off_13
SystemScript_Infinite_Repel_Off_9:
# 159 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	return

SystemScript_Infinite_Repel_Off_3:
# 138 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_0, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_Off_1

SystemScript_Infinite_Repel_Off_4:
# 141 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_1, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_Off_1

SystemScript_Infinite_Repel_Off_5:
# 144 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_2, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_Off_1

SystemScript_Infinite_Repel_Off_7:
# 148 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	goto SystemScript_Infinite_Repel_Off_6

SystemScript_Infinite_Repel_Off_11:
# 153 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_3, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_Off_9

SystemScript_Infinite_Repel_Off_12:
# 155 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_4, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_Off_9

SystemScript_Infinite_Repel_Off_13:
# 157 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_5, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_Off_9


SystemScript_Infinite_Repel_On::
# 163 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 164 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 165 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_On_3
# 168 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_On_4
# 171 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_On_5
SystemScript_Infinite_Repel_On_1:
# 174 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SystemScript_Infinite_Repel_On_7
SystemScript_Infinite_Repel_On_6:
# 178 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_NO_RANDOM_WILD_ENCOUNTERS
# 179 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 180 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_On_11
# 182 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_On_12
# 184 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_On_13
SystemScript_Infinite_Repel_On_9:
# 187 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	return

SystemScript_Infinite_Repel_On_3:
# 166 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_0, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_On_1

SystemScript_Infinite_Repel_On_4:
# 169 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_1, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_On_1

SystemScript_Infinite_Repel_On_5:
# 172 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_2, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_On_1

SystemScript_Infinite_Repel_On_7:
# 176 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	goto SystemScript_Infinite_Repel_On_6

SystemScript_Infinite_Repel_On_11:
# 181 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_3, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_On_9

SystemScript_Infinite_Repel_On_12:
# 183 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_4, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_On_9

SystemScript_Infinite_Repel_On_13:
# 185 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_5, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_On_9


EndScript::
# 191 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


PineveilTown_PlayerVideoGamePassword_InfiniteRepel::
# 196 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_ULTRA_REPEL, PineveilTown_PlayerVideoGamePassword_AlreadyReceived
# 197 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 198 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 199 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_InfiniteRepel_3
# 202 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_InfiniteRepel_4
# 205 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_InfiniteRepel_5
PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1:
# 208 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 209 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_ULTRA_REPEL, 1
# 210 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 211 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_ULTRA_REPEL
# 212 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_3:
# 200 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_4:
# 203 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_5:
# 206 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1


PineveilTown_PlayerVideoGamePassword_AlreadyReceived::
# 217 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_FAILURE
# 218 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 219 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_AlreadyReceived_3
# 222 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_AlreadyReceived_4
# 225 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_AlreadyReceived_5
PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1:
# 228 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 229 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 230 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_3:
# 220 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_4:
# 223 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_5:
# 226 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1


PineveilTown_PlayerVideoGamePassword_RareCandy::
# 235 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 236 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 237 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_RareCandy_3
# 240 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_RareCandy_4
# 243 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_RareCandy_5
PineveilTown_PlayerVideoGamePassword_RareCandy_1:
# 246 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 247 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_RARE_CANDY, 50
# 248 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 249 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_RareCandy_3:
# 238 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_RareCandy_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_1

PineveilTown_PlayerVideoGamePassword_RareCandy_4:
# 241 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_RareCandy_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_1

PineveilTown_PlayerVideoGamePassword_RareCandy_5:
# 244 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_RareCandy_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_1


PineveilTown_PlayerVideoGamePassword_StartPack::
# 254 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_STARTER_PACK, PineveilTown_PlayerVideoGamePassword_AlreadyReceived
# 255 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 256 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 257 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_StartPack_3
# 260 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_StartPack_4
# 263 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_StartPack_5
PineveilTown_PlayerVideoGamePassword_StartPack_1:
# 266 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 267 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_METAL_COAT, 1
# 268 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SOFT_SAND, 1
# 269 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_HARD_STONE, 1
# 270 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MIRACLE_SEED, 1
# 271 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_BLACK_GLASSES, 1
# 272 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_BLACK_BELT, 1
# 273 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MAGNET, 1
# 274 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MYSTIC_WATER, 1
# 275 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SHARP_BEAK, 1
# 276 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_POISON_BARB, 1
# 277 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_NEVER_MELT_ICE, 1
# 278 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SPELL_TAG, 1
# 279 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_TWISTED_SPOON, 1
# 280 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHARCOAL, 1
# 281 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_DRAGON_FANG, 1
# 282 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SILK_SCARF, 1
# 283 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_OCCA_BERRY, 50
# 284 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_PASSHO_BERRY, 50
# 285 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_WACAN_BERRY, 50
# 286 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_RINDO_BERRY, 50
# 287 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_YACHE_BERRY, 50
# 288 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHOPLE_BERRY, 50
# 289 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_KEBIA_BERRY, 50
# 290 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SHUCA_BERRY, 50
# 291 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_COBA_BERRY, 50
# 292 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_PAYAPA_BERRY, 50
# 293 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_TANGA_BERRY, 50
# 294 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHARTI_BERRY, 50
# 295 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_KASIB_BERRY, 50
# 296 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_HABAN_BERRY, 50
# 297 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_COLBUR_BERRY, 50
# 298 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_BABIRI_BERRY, 50
# 299 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHILAN_BERRY, 50
# 300 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MICLE_BERRY, 50
# 301 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CUSTAP_BERRY, 50
# 302 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_JABOCA_BERRY, 50
# 303 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_ROWAP_BERRY, 50
# 304 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_ROSELI_BERRY, 50
# 305 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_KEE_BERRY, 50
# 306 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MARANGA_BERRY, 50
# 307 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_STARTER_PACK
# 308 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 309 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_StartPack_3:
# 258 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_StartPack_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_StartPack_1

PineveilTown_PlayerVideoGamePassword_StartPack_4:
# 261 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_StartPack_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_StartPack_1

PineveilTown_PlayerVideoGamePassword_StartPack_5:
# 264 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_StartPack_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_StartPack_1


PineveilTown_PlayerVideoGamePassword_WrongPassword::
# 314 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_FAILURE
# 315 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 316 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_WrongPassword_3
# 319 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_WrongPassword_4
# 322 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_WrongPassword_5
PineveilTown_PlayerVideoGamePassword_WrongPassword_1:
# 325 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 326 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 327 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_WrongPassword_3:
# 317 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword_1

PineveilTown_PlayerVideoGamePassword_WrongPassword_4:
# 320 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword_1

PineveilTown_PlayerVideoGamePassword_WrongPassword_5:
# 323 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword_1


PineveilTown_PlayerRoom_Slowpoke_Doll::
# 332 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 333 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 334 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerRoom_Slowpoke_Doll_3
# 337 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerRoom_Slowpoke_Doll_4
# 340 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerRoom_Slowpoke_Doll_5
PineveilTown_PlayerRoom_Slowpoke_Doll_1:
# 343 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 344 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 345 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerRoom_Slowpoke_Doll_3:
# 335 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_Slowpoke_Doll_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerRoom_Slowpoke_Doll_1

PineveilTown_PlayerRoom_Slowpoke_Doll_4:
# 338 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_Slowpoke_Doll_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerRoom_Slowpoke_Doll_1

PineveilTown_PlayerRoom_Slowpoke_Doll_5:
# 341 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_Slowpoke_Doll_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerRoom_Slowpoke_Doll_1


# 349 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
Movement_Camera_Goes_Up:
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 351 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
	step_end

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile::
# 355 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 356 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 357 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_eq PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_2
# 360 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	moveplayer Movement_Player_GoTo_Window
PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_1:
# 362 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 363 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_7
# 364 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_8
# 365 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_9
PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5:
# 367 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	pause 30
# 368 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	moveplayer Common_Movement_FaceRight
# 369 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_PLAYER_ROOM_2F_TILE, 1
# 370 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_2:
# 358 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	moveplayer Common_Movement_FaceUp
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_1

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_7:
# 363 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_0
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_8:
# 364 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_1
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_9:
# 365 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_2
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5


# 374 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
Movement_Player_GoTo_Window:
# 375 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_left
# 376 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 377 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	face_up
	step_end

PineveilTown_PlayerRoom_After_Story_Text_0:
# 20 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Aquilo foi só um sonho… ou não?$"

PineveilTown_PlayerRoom_After_Story_Text_1:
# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "That was just a dream… or not?$"

PineveilTown_PlayerRoom_After_Story_Text_2:
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Eso fue solo un sueño… o no?$"

PineveilTown_PlayerRoom_Start_Story_Text_0:
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "…algo está chamando.$"

PineveilTown_PlayerRoom_Start_Story_Text_1:
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "…something is calling.$"

PineveilTown_PlayerRoom_Start_Story_Text_2:
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "…algo está llamando.$"

PineveilTown_Player_PC_Text_0:
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER} ligou o PC.$"

PineveilTown_Player_PC_Text_1:
# 68 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER} booted up the PC.$"

PineveilTown_Player_PC_Text_2:
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER} encendió la PC.$"

PineveilTown_PlayerVideoGamePassword_Text_0:
# 91 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "É um Wii!\nEle é controlado por um Wii Remote!$"

PineveilTown_PlayerVideoGamePassword_Text_1:
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "It's a Wii!\nIt's controlled by a Wii Remote!$"

PineveilTown_PlayerVideoGamePassword_Text_2:
# 97 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Es un Wii!\nEstá controlado por un mando Wii!$"

PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_0:
# 119 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu 10 Quick Balls!$"

PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_1:
# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received 10 Quick Balls!$"

PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_2:
# 125 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido 10 Quick Balls!$"

SystemScript_Infinite_Repel_Off_Text_0:
# 138 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Você gostaria de desativar o\nUltra Repel?$"

SystemScript_Infinite_Repel_Off_Text_1:
# 141 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Would you like to disable the\nUltra Repel?$"

SystemScript_Infinite_Repel_Off_Text_2:
# 144 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¿Quieres desactivar el\nUltra Repel?$"

SystemScript_Infinite_Repel_Off_Text_3:
# 153 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel desativado!$"

SystemScript_Infinite_Repel_Off_Text_4:
# 155 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel disabled!$"

SystemScript_Infinite_Repel_Off_Text_5:
# 157 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Ultra Repel desactivado!$"

SystemScript_Infinite_Repel_On_Text_0:
# 166 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Você gostaria de ativar o\nUltra Repel?$"

SystemScript_Infinite_Repel_On_Text_1:
# 169 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Would you like to enable the\nUltra Repel?$"

SystemScript_Infinite_Repel_On_Text_2:
# 172 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¿Quieres activar el\nUltra Repel?$"

SystemScript_Infinite_Repel_On_Text_3:
# 181 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel ativado!$"

SystemScript_Infinite_Repel_On_Text_4:
# 183 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel enabled!$"

SystemScript_Infinite_Repel_On_Text_5:
# 185 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Ultra Repel activado!$"

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_0:
# 200 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu um Ultra Repel!$"

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_1:
# 203 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received an Ultra Repel!$"

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_2:
# 206 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido un Ultra Repel!$"

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_0:
# 220 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Você já recebeu este prêmio antes.\nNão pode receber novamente!$"

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_1:
# 223 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "You have already received this\nprize. You can't receive it again!$"

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_2:
# 226 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ya has recibido este premio.\n¡No puedes recibirlo otra vez!$"

PineveilTown_PlayerVideoGamePassword_RareCandy_Text_0:
# 238 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu 50 Rare Candies!$"

PineveilTown_PlayerVideoGamePassword_RareCandy_Text_1:
# 241 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received 50 Rare Candies!$"

PineveilTown_PlayerVideoGamePassword_RareCandy_Text_2:
# 244 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido 50 Rare Candies!$"

PineveilTown_PlayerVideoGamePassword_StartPack_Text_0:
# 258 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu um Pacote de Itens!$"

PineveilTown_PlayerVideoGamePassword_StartPack_Text_1:
# 261 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received a Pack of Items!$"

PineveilTown_PlayerVideoGamePassword_StartPack_Text_2:
# 264 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido un Pacote de Itens!$"

PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_0:
# 317 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha incorreta!\nTente novamente.$"

PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_1:
# 320 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Wrong password!\nPlease try again.$"

PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_2:
# 323 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña incorrecta!\nInténtalo de nuevo.$"

PineveilTown_PlayerRoom_Slowpoke_Doll_Text_0:
# 335 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "É um Slowpoke de pelúcia.\nEle é tão fofinho!$"

PineveilTown_PlayerRoom_Slowpoke_Doll_Text_1:
# 338 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "It's a Slowpoke plush doll.\nIt's so cute!$"

PineveilTown_PlayerRoom_Slowpoke_Doll_Text_2:
# 341 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Es un peluche de Slowpoke.\n¡Es tan lindo!$"

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_0:
# 363 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "A chuva parou há pouco tempo.$"

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_1:
# 364 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "The rain stopped not long ago.$"

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_2:
# 365 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "La lluvia paró hace poco.$"
