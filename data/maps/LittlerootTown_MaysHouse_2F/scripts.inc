LittlerootTown_MaysHouse_2F_MapScripts::
# 2 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 13 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_PLAYER_ROOM_STATE, 1
	goto_if_ne LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 9 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_PLAYER_ROOM_STATE, 1
	goto_if_ge LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 5 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 10 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_KAEL_SLEEPING, MOVEMENT_TYPE_INVISIBLE
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 7 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_KAEL_SLEEPING, 7, 6
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_PLAYER_ROOM_STATE, 0, PineveilTown_PlayerRoom_Start_Story
# 15 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SILENT_FOREST_STATE, 1, PineveilTown_PlayerRoom_After_Story
	.2byte 0


PineveilTown_PlayerRoom_After_Story::
# 20 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerRoom_After_Story_3
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerRoom_After_Story_4
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerRoom_After_Story_5
PineveilTown_PlayerRoom_After_Story_1:
# 26 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SILENT_FOREST_STATE, 2
# 27 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerRoom_After_Story_3:
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_After_Story_Text_0, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerRoom_After_Story_1

PineveilTown_PlayerRoom_After_Story_4:
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_After_Story_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerRoom_After_Story_1

PineveilTown_PlayerRoom_After_Story_5:
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_After_Story_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerRoom_After_Story_1


PineveilTown_PlayerRoom_Start_Story::
# 32 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playbgm MUS_RG_SEVII_45, 0
# 33 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 400
# 34 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special SpawnCameraObject
# 35 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_CAMERA, Movement_Camera_Goes_Up
# 36 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement LOCALID_CAMERA
# 37 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special RemoveCameraObject
# 38 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 39 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 30
# 40 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MSGBOXONMIDDLE
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerRoom_Start_Story_3
# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerRoom_Start_Story_4
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerRoom_Start_Story_5
PineveilTown_PlayerRoom_Start_Story_1:
# 47 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitbuttonpress
# 48 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 49 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_MSGBOXONMIDDLE
# 50 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_SPAWN_INVISIBLE
# 51 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_M_NIGHTMARE
# 52 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 53 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_PLAYER_ROOM_STATE, 1
# 54 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 55 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	warpsilent MAP_SILENT_FOREST, 42, 23
# 56 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 57 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	release
	end

PineveilTown_PlayerRoom_Start_Story_3:
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	transbox PineveilTown_PlayerRoom_Start_Story_Text_0
	goto PineveilTown_PlayerRoom_Start_Story_1

PineveilTown_PlayerRoom_Start_Story_4:
# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	transbox PineveilTown_PlayerRoom_Start_Story_Text_1
	goto PineveilTown_PlayerRoom_Start_Story_1

PineveilTown_PlayerRoom_Start_Story_5:
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	transbox PineveilTown_PlayerRoom_Start_Story_Text_2
	goto PineveilTown_PlayerRoom_Start_Story_1


PineveilTown_Player_PC::
# 62 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 63 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 64 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 66 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 67 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_Player_PC_3
# 70 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_Player_PC_4
# 73 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_Player_PC_5
PineveilTown_Player_PC_1:
# 76 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 77 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 78 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_Player_PC_3:
# 68 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_Player_PC_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_Player_PC_1

PineveilTown_Player_PC_4:
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_Player_PC_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_Player_PC_1

PineveilTown_Player_PC_5:
# 74 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_Player_PC_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_Player_PC_1


PineveilTown_TurnOffPlayer_PC::
# 83 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 84 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 85 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 86 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


PineveilTown_PlayerVideoGamePassword::
# 91 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 92 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 93 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_3
# 96 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_4
# 99 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_5
PineveilTown_PlayerVideoGamePassword_1:
# 102 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special EnterCode
# 103 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 104 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special GetCodeFeedback
# 105 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_RESULT
# 106 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 0, PineveilTown_PlayerVideoGamePassword_8
# 108 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 1, PineveilTown_PlayerVideoGamePassword_9
# 110 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 2, PineveilTown_PlayerVideoGamePassword_10
# 112 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 3, PineveilTown_PlayerVideoGamePassword_11
PineveilTown_PlayerVideoGamePassword_6:
# 115 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword
	return

PineveilTown_PlayerVideoGamePassword_3:
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_1

PineveilTown_PlayerVideoGamePassword_4:
# 97 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_1

PineveilTown_PlayerVideoGamePassword_5:
# 100 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_1

PineveilTown_PlayerVideoGamePassword_8:
# 107 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls
	goto PineveilTown_PlayerVideoGamePassword_6

PineveilTown_PlayerVideoGamePassword_9:
# 109 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel
	goto PineveilTown_PlayerVideoGamePassword_6

PineveilTown_PlayerVideoGamePassword_10:
# 111 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_RareCandy
	goto PineveilTown_PlayerVideoGamePassword_6

PineveilTown_PlayerVideoGamePassword_11:
# 113 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto PineveilTown_PlayerVideoGamePassword_StartPack
	goto PineveilTown_PlayerVideoGamePassword_6


PineveilTown_PlayerVideoGamePassword_QuickBalls::
# 119 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 120 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 121 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_QuickBalls_3
# 124 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_QuickBalls_4
# 127 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_QuickBalls_5
PineveilTown_PlayerVideoGamePassword_QuickBalls_1:
# 130 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 131 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_QUICK_BALL, 10
# 132 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 133 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_QuickBalls_3:
# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_1

PineveilTown_PlayerVideoGamePassword_QuickBalls_4:
# 125 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_1

PineveilTown_PlayerVideoGamePassword_QuickBalls_5:
# 128 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_QuickBalls_1


SystemScript_Infinite_Repel_Off::
# 138 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 139 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 140 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_Off_3
# 143 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_Off_4
# 146 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_Off_5
SystemScript_Infinite_Repel_Off_1:
# 149 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SystemScript_Infinite_Repel_Off_7
SystemScript_Infinite_Repel_Off_6:
# 153 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_NO_RANDOM_WILD_ENCOUNTERS
# 154 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 155 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_Off_11
# 157 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_Off_12
# 159 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_Off_13
SystemScript_Infinite_Repel_Off_9:
# 162 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	return

SystemScript_Infinite_Repel_Off_3:
# 141 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_0, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_Off_1

SystemScript_Infinite_Repel_Off_4:
# 144 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_1, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_Off_1

SystemScript_Infinite_Repel_Off_5:
# 147 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_2, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_Off_1

SystemScript_Infinite_Repel_Off_7:
# 151 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	goto SystemScript_Infinite_Repel_Off_6

SystemScript_Infinite_Repel_Off_11:
# 156 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_3, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_Off_9

SystemScript_Infinite_Repel_Off_12:
# 158 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_4, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_Off_9

SystemScript_Infinite_Repel_Off_13:
# 160 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_Off_Text_5, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_Off_9


SystemScript_Infinite_Repel_On::
# 166 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 167 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 168 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_On_3
# 171 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_On_4
# 174 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_On_5
SystemScript_Infinite_Repel_On_1:
# 177 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SystemScript_Infinite_Repel_On_7
SystemScript_Infinite_Repel_On_6:
# 181 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_NO_RANDOM_WILD_ENCOUNTERS
# 182 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 183 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, SystemScript_Infinite_Repel_On_11
# 185 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, SystemScript_Infinite_Repel_On_12
# 187 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, SystemScript_Infinite_Repel_On_13
SystemScript_Infinite_Repel_On_9:
# 190 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	return

SystemScript_Infinite_Repel_On_3:
# 169 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_0, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_On_1

SystemScript_Infinite_Repel_On_4:
# 172 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_1, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_On_1

SystemScript_Infinite_Repel_On_5:
# 175 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_2, MSGBOX_YESNO
	goto SystemScript_Infinite_Repel_On_1

SystemScript_Infinite_Repel_On_7:
# 179 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto EndScript
	goto SystemScript_Infinite_Repel_On_6

SystemScript_Infinite_Repel_On_11:
# 184 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_3, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_On_9

SystemScript_Infinite_Repel_On_12:
# 186 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_4, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_On_9

SystemScript_Infinite_Repel_On_13:
# 188 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox SystemScript_Infinite_Repel_On_Text_5, MSGBOX_DEFAULT
	goto SystemScript_Infinite_Repel_On_9


EndScript::
# 194 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


PineveilTown_PlayerVideoGamePassword_InfiniteRepel::
# 199 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_ULTRA_REPEL, PineveilTown_PlayerVideoGamePassword_AlreadyReceived
# 200 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 201 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 202 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_InfiniteRepel_3
# 205 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_InfiniteRepel_4
# 208 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_InfiniteRepel_5
PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1:
# 211 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 212 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_ULTRA_REPEL, 1
# 213 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 214 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_RECEIVED_ULTRA_REPEL
# 215 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_3:
# 203 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_4:
# 206 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_5:
# 209 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_InfiniteRepel_1


PineveilTown_PlayerVideoGamePassword_AlreadyReceived::
# 220 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_FAILURE
# 221 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 222 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_AlreadyReceived_3
# 225 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_AlreadyReceived_4
# 228 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_AlreadyReceived_5
PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1:
# 231 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 232 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 233 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_3:
# 223 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_4:
# 226 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_5:
# 229 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_AlreadyReceived_1


PineveilTown_PlayerVideoGamePassword_RareCandy::
# 238 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 239 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 240 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_RareCandy_3
# 243 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_RareCandy_4
# 246 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_RareCandy_5
PineveilTown_PlayerVideoGamePassword_RareCandy_1:
# 249 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 250 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_RARE_CANDY, 50
# 251 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 252 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_RareCandy_3:
# 241 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_RareCandy_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_1

PineveilTown_PlayerVideoGamePassword_RareCandy_4:
# 244 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_RareCandy_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_1

PineveilTown_PlayerVideoGamePassword_RareCandy_5:
# 247 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_RareCandy_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_RareCandy_1


PineveilTown_PlayerVideoGamePassword_StartPack::
# 257 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_STARTER_PACK, PineveilTown_PlayerVideoGamePassword_AlreadyReceived
# 258 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_SUCCESS
# 259 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 260 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_StartPack_3
# 263 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_StartPack_4
# 266 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_StartPack_5
PineveilTown_PlayerVideoGamePassword_StartPack_1:
# 269 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 270 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_METAL_COAT, 1
# 271 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SOFT_SAND, 1
# 272 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_HARD_STONE, 1
# 273 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MIRACLE_SEED, 1
# 274 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_BLACK_GLASSES, 1
# 275 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_BLACK_BELT, 1
# 276 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MAGNET, 1
# 277 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MYSTIC_WATER, 1
# 278 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SHARP_BEAK, 1
# 279 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_POISON_BARB, 1
# 280 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_NEVER_MELT_ICE, 1
# 281 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SPELL_TAG, 1
# 282 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_TWISTED_SPOON, 1
# 283 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHARCOAL, 1
# 284 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_DRAGON_FANG, 1
# 285 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SILK_SCARF, 1
# 286 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_OCCA_BERRY, 50
# 287 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_PASSHO_BERRY, 50
# 288 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_WACAN_BERRY, 50
# 289 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_RINDO_BERRY, 50
# 290 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_YACHE_BERRY, 50
# 291 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHOPLE_BERRY, 50
# 292 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_KEBIA_BERRY, 50
# 293 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_SHUCA_BERRY, 50
# 294 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_COBA_BERRY, 50
# 295 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_PAYAPA_BERRY, 50
# 296 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_TANGA_BERRY, 50
# 297 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHARTI_BERRY, 50
# 298 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_KASIB_BERRY, 50
# 299 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_HABAN_BERRY, 50
# 300 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_COLBUR_BERRY, 50
# 301 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_BABIRI_BERRY, 50
# 302 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CHILAN_BERRY, 50
# 303 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MICLE_BERRY, 50
# 304 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_CUSTAP_BERRY, 50
# 305 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_JABOCA_BERRY, 50
# 306 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_ROWAP_BERRY, 50
# 307 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_ROSELI_BERRY, 50
# 308 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_KEE_BERRY, 50
# 309 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	additem ITEM_MARANGA_BERRY, 50
# 310 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_STARTER_PACK
# 311 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 312 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_StartPack_3:
# 261 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_StartPack_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_StartPack_1

PineveilTown_PlayerVideoGamePassword_StartPack_4:
# 264 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_StartPack_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_StartPack_1

PineveilTown_PlayerVideoGamePassword_StartPack_5:
# 267 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_StartPack_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_StartPack_1


PineveilTown_PlayerVideoGamePassword_WrongPassword::
# 317 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_FAILURE
# 318 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 319 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerVideoGamePassword_WrongPassword_3
# 322 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_WrongPassword_4
# 325 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerVideoGamePassword_WrongPassword_5
PineveilTown_PlayerVideoGamePassword_WrongPassword_1:
# 328 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitse
# 329 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 330 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerVideoGamePassword_WrongPassword_3:
# 320 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword_1

PineveilTown_PlayerVideoGamePassword_WrongPassword_4:
# 323 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword_1

PineveilTown_PlayerVideoGamePassword_WrongPassword_5:
# 326 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerVideoGamePassword_WrongPassword_1


PineveilTown_PlayerRoom_Slowpoke_Doll::
# 335 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 336 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 337 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerRoom_Slowpoke_Doll_3
# 340 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerRoom_Slowpoke_Doll_4
# 343 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerRoom_Slowpoke_Doll_5
PineveilTown_PlayerRoom_Slowpoke_Doll_1:
# 346 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 347 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 348 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerRoom_Slowpoke_Doll_3:
# 338 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_Slowpoke_Doll_Text_0, MSGBOX_DEFAULT
	goto PineveilTown_PlayerRoom_Slowpoke_Doll_1

PineveilTown_PlayerRoom_Slowpoke_Doll_4:
# 341 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_Slowpoke_Doll_Text_1, MSGBOX_DEFAULT
	goto PineveilTown_PlayerRoom_Slowpoke_Doll_1

PineveilTown_PlayerRoom_Slowpoke_Doll_5:
# 344 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerRoom_Slowpoke_Doll_Text_2, MSGBOX_DEFAULT
	goto PineveilTown_PlayerRoom_Slowpoke_Doll_1


# 352 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
Movement_Camera_Goes_Up:
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 354 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
	step_end

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile::
# 358 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 359 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 360 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_eq PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_2
# 363 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	moveplayer Movement_Player_GoTo_Window
PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_1:
# 365 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 366 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case PT, PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_7
# 367 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case EN, PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_8
# 368 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case ES, PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_9
PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5:
# 370 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	pause 30
# 371 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	moveplayer Common_Movement_FaceRight
# 372 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_PLAYER_ROOM_2F_TILE, 1
# 373 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_2:
# 361 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	moveplayer Common_Movement_FaceUp
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_1

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_7:
# 366 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_0
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_8:
# 367 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_1
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_9:
# 368 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_2
	goto PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_5


# 377 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
Movement_Player_GoTo_Window:
# 378 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_left
# 379 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 380 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	face_up
	step_end

PineveilTown_PlayerRoom_After_Story_Text_0:
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Aquilo foi só um sonho… ou não?$"

PineveilTown_PlayerRoom_After_Story_Text_1:
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "That was just a dream… or not?$"

PineveilTown_PlayerRoom_After_Story_Text_2:
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Eso fue solo un sueño… o no?$"

PineveilTown_PlayerRoom_Start_Story_Text_0:
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "…algo está chamando.$"

PineveilTown_PlayerRoom_Start_Story_Text_1:
# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "…something is calling.$"

PineveilTown_PlayerRoom_Start_Story_Text_2:
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "…algo está llamando.$"

PineveilTown_Player_PC_Text_0:
# 68 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER} ligou o PC.$"

PineveilTown_Player_PC_Text_1:
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER} booted up the PC.$"

PineveilTown_Player_PC_Text_2:
# 74 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER} encendió la PC.$"

PineveilTown_PlayerVideoGamePassword_Text_0:
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "É um Wii!\nEle é controlado por um Wii Remote!$"

PineveilTown_PlayerVideoGamePassword_Text_1:
# 97 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "It's a Wii!\nIt's controlled by a Wii Remote!$"

PineveilTown_PlayerVideoGamePassword_Text_2:
# 100 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Es un Wii!\nEstá controlado por un mando Wii!$"

PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_0:
# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu 10 Quick Balls!$"

PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_1:
# 125 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received 10 Quick Balls!$"

PineveilTown_PlayerVideoGamePassword_QuickBalls_Text_2:
# 128 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido 10 Quick Balls!$"

SystemScript_Infinite_Repel_Off_Text_0:
# 141 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Você gostaria de desativar o\nUltra Repel?$"

SystemScript_Infinite_Repel_Off_Text_1:
# 144 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Would you like to disable the\nUltra Repel?$"

SystemScript_Infinite_Repel_Off_Text_2:
# 147 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¿Quieres desactivar el\nUltra Repel?$"

SystemScript_Infinite_Repel_Off_Text_3:
# 156 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel desativado!$"

SystemScript_Infinite_Repel_Off_Text_4:
# 158 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel disabled!$"

SystemScript_Infinite_Repel_Off_Text_5:
# 160 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Ultra Repel desactivado!$"

SystemScript_Infinite_Repel_On_Text_0:
# 169 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Você gostaria de ativar o\nUltra Repel?$"

SystemScript_Infinite_Repel_On_Text_1:
# 172 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Would you like to enable the\nUltra Repel?$"

SystemScript_Infinite_Repel_On_Text_2:
# 175 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¿Quieres activar el\nUltra Repel?$"

SystemScript_Infinite_Repel_On_Text_3:
# 184 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel ativado!$"

SystemScript_Infinite_Repel_On_Text_4:
# 186 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ultra Repel enabled!$"

SystemScript_Infinite_Repel_On_Text_5:
# 188 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Ultra Repel activado!$"

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_0:
# 203 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu um Ultra Repel!$"

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_1:
# 206 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received an Ultra Repel!$"

PineveilTown_PlayerVideoGamePassword_InfiniteRepel_Text_2:
# 209 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido un Ultra Repel!$"

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_0:
# 223 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Você já recebeu este prêmio antes.\nNão pode receber novamente!$"

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_1:
# 226 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "You have already received this\nprize. You can't receive it again!$"

PineveilTown_PlayerVideoGamePassword_AlreadyReceived_Text_2:
# 229 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Ya has recibido este premio.\n¡No puedes recibirlo otra vez!$"

PineveilTown_PlayerVideoGamePassword_RareCandy_Text_0:
# 241 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu 50 Rare Candies!$"

PineveilTown_PlayerVideoGamePassword_RareCandy_Text_1:
# 244 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received 50 Rare Candies!$"

PineveilTown_PlayerVideoGamePassword_RareCandy_Text_2:
# 247 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido 50 Rare Candies!$"

PineveilTown_PlayerVideoGamePassword_StartPack_Text_0:
# 261 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha correta!\nVocê recebeu um Pacote de Itens!$"

PineveilTown_PlayerVideoGamePassword_StartPack_Text_1:
# 264 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Correct password!\nYou received a Pack of Items!$"

PineveilTown_PlayerVideoGamePassword_StartPack_Text_2:
# 267 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña correcta!\n¡Has recibido un Pacote de Itens!$"

PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_0:
# 320 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Senha incorreta!\nTente novamente.$"

PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_1:
# 323 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Wrong password!\nPlease try again.$"

PineveilTown_PlayerVideoGamePassword_WrongPassword_Text_2:
# 326 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "¡Contraseña incorrecta!\nInténtalo de nuevo.$"

PineveilTown_PlayerRoom_Slowpoke_Doll_Text_0:
# 338 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "É um Slowpoke de pelúcia.\nEle é tão fofinho!$"

PineveilTown_PlayerRoom_Slowpoke_Doll_Text_1:
# 341 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "It's a Slowpoke plush doll.\nIt's so cute!$"

PineveilTown_PlayerRoom_Slowpoke_Doll_Text_2:
# 344 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Es un peluche de Slowpoke.\n¡Es tan lindo!$"

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_0:
# 366 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "A chuva parou há pouco tempo.$"

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_1:
# 367 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "The rain stopped not long ago.$"

PineveilTown_PlayerHouse_2F_Player_Check_Rain_Tile_Text_2:
# 368 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "La lluvia paró hace poco.$"
