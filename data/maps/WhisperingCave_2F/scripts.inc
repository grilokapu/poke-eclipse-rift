WhisperingCave_2F_MapScripts::
# 2 "data/maps/WhisperingCave_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, WhisperingCave_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

WhisperingCave_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/WhisperingCave_2F/scripts.pory"
	goto_if_set FLAG_GIOVANNI_CAVE_SYMBOL, WhisperingCave_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
WhisperingCave_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

WhisperingCave_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/WhisperingCave_2F/scripts.pory"
	setobjectxyperm LOCALID_WHISPERING_HIKER, 14, 9
# 5 "data/maps/WhisperingCave_2F/scripts.pory"
	setobjectmovementtype LOCALID_WHISPERING_HIKER, MOVEMENT_TYPE_FACE_RIGHT
	goto WhisperingCave_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1


WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger::
# 14 "data/maps/WhisperingCave_2F/scripts.pory"
	lock
# 15 "data/maps/WhisperingCave_2F/scripts.pory"
	removeowe
# 16 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_0
# 17 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 18 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 19 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_1
# 20 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 21 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 22 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 23 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_3
# 24 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_4
# 25 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_5
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_1:
# 27 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_2
# 28 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_PLAYER, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_3
# 29 "data/maps/WhisperingCave_2F/scripts.pory"
	waitmovementall
# 30 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 31 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 32 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_8
# 33 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_9
# 34 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_10
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_6:
# 36 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 50
# 37 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_4
# 38 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_PLAYER, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_5
# 39 "data/maps/WhisperingCave_2F/scripts.pory"
	waitmovementall
# 40 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 41 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 42 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_13
# 43 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_14
# 44 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_15
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_11:
# 46 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 47 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_3
# 48 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_6
# 49 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 50 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 51 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_7
# 52 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 53 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 54 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_M_CONFUSE_RAY
# 55 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 24
# 56 "data/maps/WhisperingCave_2F/scripts.pory"
	fadescreen FADE_TO_WHITE
# 57 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_SHINY
# 58 "data/maps/WhisperingCave_2F/scripts.pory"
	callnative CreateCaveSymbol
# 59 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 8
# 60 "data/maps/WhisperingCave_2F/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 61 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 90
# 62 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 63 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_8
# 64 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 65 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_18
# 66 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_19
# 67 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_20
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_16:
# 69 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 70 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 71 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_23
# 72 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_24
# 73 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_25
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_21:
# 75 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 76 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 77 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_28
# 78 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_29
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_30
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_26:
# 81 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 82 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 83 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_33
# 84 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_34
# 85 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_35
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_31:
# 87 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 88 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_6
# 89 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_9
# 91 "data/maps/WhisperingCave_2F/scripts.pory"
	setflag FLAG_GIOVANNI_CAVE_SYMBOL
# 92 "data/maps/WhisperingCave_2F/scripts.pory"
	removeobject LOCALID_WHISPERING_GIOVANNI
# 93 "data/maps/WhisperingCave_2F/scripts.pory"
	setobjectxyperm LOCALID_WHISPERING_HIKER, 14, 9
# 94 "data/maps/WhisperingCave_2F/scripts.pory"
	turnobject LOCALID_WHISPERING_HIKER, DIR_EAST
# 95 "data/maps/WhisperingCave_2F/scripts.pory"
	setvar VAR_WHISPERING_CAVE_2F_EVENT, 1
# 96 "data/maps/WhisperingCave_2F/scripts.pory"
	updateowe
# 97 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_3:
# 23 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_1, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_1

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_4:
# 24 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_2, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_1

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_5:
# 25 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_3, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_1

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_8:
# 32 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_4, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_6

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_9:
# 33 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_5, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_6

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_10:
# 34 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_6, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_6

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_13:
# 42 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_7, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_11

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_14:
# 43 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_8, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_11

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_15:
# 44 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_9, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_11

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_18:
# 65 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_10, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_16

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_19:
# 66 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_11, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_16

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_20:
# 67 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_12, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_16

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_23:
# 71 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_13, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_21

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_24:
# 72 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_14, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_21

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_25:
# 73 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_15, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_21

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_28:
# 77 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_16, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_26

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_29:
# 78 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_17, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_26

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_30:
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_18, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_26

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_33:
# 83 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_19, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_31

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_34:
# 84 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_20, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_31

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_35:
# 85 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_21, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_31


WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk::
# 102 "data/maps/WhisperingCave_2F/scripts.pory"
	lock
# 103 "data/maps/WhisperingCave_2F/scripts.pory"
	faceplayer
# 104 "data/maps/WhisperingCave_2F/scripts.pory"
	goto_if_set FLAG_GIOVANNI_CAVE_SYMBOL, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_2
# 114 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 115 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_1
# 116 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 117 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 118 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 119 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 120 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_6
# 121 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_7
# 122 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_8
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_4:
# 124 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 125 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_0
# 126 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 127 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 128 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 129 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 130 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_16
# 131 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_17
# 132 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_18
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_14:
# 134 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_1
# 135 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_2
# 136 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_3
# 137 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_PLAYER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_4
# 138 "data/maps/WhisperingCave_2F/scripts.pory"
	waitmovementall
# 139 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_5
# 140 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_2:
# 105 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 106 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 107 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_11
# 108 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_12
# 109 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_13
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_9:
# 111 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_6:
# 120 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_4
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_4

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_7:
# 121 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_5
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_4

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_8:
# 122 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_6
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_4

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_11:
# 107 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_1
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_9

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_12:
# 108 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_2
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_9

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_13:
# 109 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_3
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_9

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_16:
# 130 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_7
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_14

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_17:
# 131 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_8
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_14

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_18:
# 132 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_9
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_14


WhisperingCave_2F_EventScript_Hiker_Guard_Way::
# 145 "data/maps/WhisperingCave_2F/scripts.pory"
	lock
# 146 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 147 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_1
# 148 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 149 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 150 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_2
# 151 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_6
# 152 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 153 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 154 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_3
# 155 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_4
# 156 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_5
WhisperingCave_2F_EventScript_Hiker_Guard_Way_1:
# 158 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 159 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_0
# 160 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 161 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 162 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 163 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 164 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_8
# 165 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_9
# 166 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_10
WhisperingCave_2F_EventScript_Hiker_Guard_Way_6:
# 168 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_3
# 169 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_PLAYER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_4
# 170 "data/maps/WhisperingCave_2F/scripts.pory"
	waitmovementall
# 171 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_5
# 172 "data/maps/WhisperingCave_2F/scripts.pory"
	setvar VAR_WHISPERING_CAVE_HIKER_EVENT, 1
# 173 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Hiker_Guard_Way_3:
# 154 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_4
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_1

WhisperingCave_2F_EventScript_Hiker_Guard_Way_4:
# 155 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_5
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_1

WhisperingCave_2F_EventScript_Hiker_Guard_Way_5:
# 156 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_6
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_1

WhisperingCave_2F_EventScript_Hiker_Guard_Way_8:
# 164 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_7
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_6

WhisperingCave_2F_EventScript_Hiker_Guard_Way_9:
# 165 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_8
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_6

WhisperingCave_2F_EventScript_Hiker_Guard_Way_10:
# 166 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_9
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_6


WhisperingCave_2F_EventScript_Picnicker_Battle::
# 180 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 181 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Picnicker_Battle_3
# 184 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Picnicker_Battle_4
# 187 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Picnicker_Battle_5
WhisperingCave_2F_EventScript_Picnicker_Battle_1:
# 191 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Picnicker_Battle_3:
# 182 "data/maps/WhisperingCave_2F/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_SARAH, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_0, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_1
# 183 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Picnicker_Battle_Text_2
	goto WhisperingCave_2F_EventScript_Picnicker_Battle_1

WhisperingCave_2F_EventScript_Picnicker_Battle_4:
# 185 "data/maps/WhisperingCave_2F/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_SARAH, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_3, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_4
# 186 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Picnicker_Battle_Text_5
	goto WhisperingCave_2F_EventScript_Picnicker_Battle_1

WhisperingCave_2F_EventScript_Picnicker_Battle_5:
# 188 "data/maps/WhisperingCave_2F/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_SARAH, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_6, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_7
# 189 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Picnicker_Battle_Text_8
	goto WhisperingCave_2F_EventScript_Picnicker_Battle_1


WhisperingCave_2F_EventScript_Rare_Bone_Get::
# 196 "data/maps/WhisperingCave_2F/scripts.pory"
	finditem ITEM_RARE_BONE
	end


WhisperingCave_2F_EventScript_Fisherman_Talk::
# 201 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 202 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Fisherman_Talk_3
# 203 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Fisherman_Talk_4
# 204 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Fisherman_Talk_5
WhisperingCave_2F_EventScript_Fisherman_Talk_1:
	end

WhisperingCave_2F_EventScript_Fisherman_Talk_3:
# 202 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Fisherman_Talk_Text_0, MSGBOX_NPC
	goto WhisperingCave_2F_EventScript_Fisherman_Talk_1

WhisperingCave_2F_EventScript_Fisherman_Talk_4:
# 203 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Fisherman_Talk_Text_1, MSGBOX_NPC
	goto WhisperingCave_2F_EventScript_Fisherman_Talk_1

WhisperingCave_2F_EventScript_Fisherman_Talk_5:
# 204 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Fisherman_Talk_Text_2, MSGBOX_NPC
	goto WhisperingCave_2F_EventScript_Fisherman_Talk_1


WhisperingCave_2F_EventScript_Cave_Symbol::
# 210 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 211 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Cave_Symbol_3
# 212 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Cave_Symbol_4
# 213 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Cave_Symbol_5
WhisperingCave_2F_EventScript_Cave_Symbol_1:
	end

WhisperingCave_2F_EventScript_Cave_Symbol_3:
# 211 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Cave_Symbol_Text_0, MSGBOX_SIGN
	goto WhisperingCave_2F_EventScript_Cave_Symbol_1

WhisperingCave_2F_EventScript_Cave_Symbol_4:
# 212 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Cave_Symbol_Text_1, MSGBOX_SIGN
	goto WhisperingCave_2F_EventScript_Cave_Symbol_1

WhisperingCave_2F_EventScript_Cave_Symbol_5:
# 213 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Cave_Symbol_Text_2, MSGBOX_SIGN
	goto WhisperingCave_2F_EventScript_Cave_Symbol_1


# 16 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_0:
# 16 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_right
# 16 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_up
# 16 "data/maps/WhisperingCave_2F/scripts.pory"
	face_up
	step_end

# 19 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_1:
# 19 "data/maps/WhisperingCave_2F/scripts.pory"
	emote_exclamation_mark
	step_end

# 27 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_2:
# 27 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_right
# 27 "data/maps/WhisperingCave_2F/scripts.pory"
	face_up
	step_end

# 28 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_3:
# 28 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_up
# 28 "data/maps/WhisperingCave_2F/scripts.pory"
	face_up
	step_end

# 37 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_4:
# 37 "data/maps/WhisperingCave_2F/scripts.pory"
	face_left
	step_end

# 38 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_5:
# 38 "data/maps/WhisperingCave_2F/scripts.pory"
	face_right
	step_end

# 48 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_6:
# 48 "data/maps/WhisperingCave_2F/scripts.pory"
	face_up
	step_end

# 51 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_7:
# 51 "data/maps/WhisperingCave_2F/scripts.pory"
	emote_question_mark
	step_end

# 63 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_8:
# 63 "data/maps/WhisperingCave_2F/scripts.pory"
	emote_exclamation_mark
# 63 "data/maps/WhisperingCave_2F/scripts.pory"
	delay_16
# 63 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_up
# 63 "data/maps/WhisperingCave_2F/scripts.pory"
	face_left
	step_end

# 90 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_9:
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	delay_16
	step_end

# 125 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_0:
# 125 "data/maps/WhisperingCave_2F/scripts.pory"
	emote_question_mark
# 125 "data/maps/WhisperingCave_2F/scripts.pory"
	face_down
	step_end

# 134 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_1:
# 134 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 134 "data/maps/WhisperingCave_2F/scripts.pory"
	face_down
# 134 "data/maps/WhisperingCave_2F/scripts.pory"
	delay_16
	step_end

# 135 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_2:
# 135 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_right
# 135 "data/maps/WhisperingCave_2F/scripts.pory"
	face_down
	step_end

# 136 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_3:
# 136 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_fast_down
	step_end

# 137 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_4:
# 137 "data/maps/WhisperingCave_2F/scripts.pory"
	jump_2_down
	step_end

# 139 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_5:
# 139 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_up
# 139 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 139 "data/maps/WhisperingCave_2F/scripts.pory"
	face_down
	step_end

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0:
# 23 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Giovanni$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_1:
# 23 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "…\pVocê também veio até aqui.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_2:
# 24 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "…\pYou came here too.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_3:
# 25 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "…\pTú también has venido hasta aquí.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_4:
# 32 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Olhe para a parede.\pEssa marca…\nVocê já viu algo parecido?$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_5:
# 33 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Look at the wall.\pThat mark…\nHave you ever seen anything like it?$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_6:
# 34 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Mira la pared.\pEsa marca…\n¿Has visto algo parecido?$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_7:
# 42 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Eu conheço cada curva desta\ncaverna.\pEssa marca não estava aqui antes.\pOu talvez estivesse…\ne não quisesse ser encontrada.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_8:
# 43 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "I know every turn in this cave.\pThat mark wasn't here before.\pOr perhaps it was…\nand didn't want to be found.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_9:
# 44 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Conozco cada rincón de esta cueva.\pEsa marca no estaba aquí antes.\pO quizá sí…\ny no quería ser encontrada.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_10:
# 65 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Aquilo não foi um reflexo.\pPor um instante…\npareceu que a caverna olhava de\lvolta para nós.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_11:
# 66 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "That wasn't a reflection.\pFor an instant…\nit felt as though the cave was\llooking back at us.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_12:
# 67 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Eso no fue un reflejo.\pPor un instante…\npareció que la cueva nos devolvía\lla mirada.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_13:
# 71 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Ela não reagiu quando você chegou.\pEsperou até você ficar diante dela.\pComo se tivesse reconhecido você.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_14:
# 72 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "It didn't react when you arrived.\pIt waited until you stood before it.\pAs if it recognized you.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_15:
# 73 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "No reaccionó cuando llegaste.\pEsperó hasta que te pusiste ante ella.\pComo si te hubiera reconocido.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_16:
# 77 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Não…\p“Interessante” não é suficiente.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_17:
# 78 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "No…\p“Interesting” isn't enough.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_18:
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "No…\p“Interesante” no es suficiente.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_19:
# 83 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Há algo ligado a você que nem esta\npedra consegue esconder.\pAinda não sei o que é.\pMas segredos sempre deixam rastros.\pE eu sou muito bom em segui-los.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_20:
# 84 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Something tied to you cannot be\nhidden even by this stone.\pI don't know what it is yet.\pBut secrets always leave traces.\pAnd I'm very good at following them.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_21:
# 85 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Hay algo ligado a ti que ni esta\npiedra puede ocultar.\pAún no sé qué es.\pPero los secretos siempre dejan\nrastros.\pY soy muy bueno siguiéndolos.$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0:
# 105 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Gerônimo$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_1:
# 107 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Desculpa por ter te empurrado\ndaquela saliência!\pEu só queria testar se a gravidade\nainda estava funcionando.\pParece que está!$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_2:
# 108 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Sorry for pushing you off that\nledge!\pI just wanted to make sure gravity\nwas still working.\pLooks like it is!$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_3:
# 109 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¡Perdón por empujarte desde esa\ncornisa!\pSolo quería comprobar si la\ngravedad seguía funcionando.\p¡Parece que sí!$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_4:
# 120 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Espere!\pEstá vendo aquela coisa ali em\nbaixo?$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_5:
# 121 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Wait!\pDo you see that thing down there?$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_6:
# 122 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¡Espera!\p¿Ves esa cosa ahí abajo?$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_7:
# 130 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Veja mais de perto…$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_8:
# 131 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Take a closer look…$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_9:
# 132 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Míralo más de cerca…$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_0:
# 182 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Que bom encontrar você!\nVamos batalhar!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_1:
# 182 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Essa derrota não foi nada legal…$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_2:
# 183 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Quanto mais você batalha, mais\nvontade dá de continuar\lbatalhando!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_3:
# 185 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "It's great to see you!\nLet's have a battle!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_4:
# 185 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "That loss wasn't fun at all…$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_5:
# 186 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "The more you battle, the more you\nwant to keep battling!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_6:
# 188 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¡Qué bueno encontrarte!\n¡Vamos a combatir!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_7:
# 188 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Esa derrota no fue nada divertida…$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_8:
# 189 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¡Cuanto más combates, más ganas\ntienes de seguir combatiendo!$"

WhisperingCave_2F_EventScript_Fisherman_Talk_Text_0:
# 202 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Muita gente acha que a Old Rod só\nserve para pescar Magikarp.\pMas um bom Pescador sempre\nencontra surpresas!$"

WhisperingCave_2F_EventScript_Fisherman_Talk_Text_1:
# 203 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Lots of people think the Old Rod\nonly catches Magikarp.\pBut a skilled Fisher can always\nreel in a surprise!$"

WhisperingCave_2F_EventScript_Fisherman_Talk_Text_2:
# 204 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Mucha gente cree que la Old Rod\nsolo sirve para pescar Magikarp.\p¡Pero un buen Pescador siempre\nencuentra alguna sorpresa!$"

WhisperingCave_2F_EventScript_Cave_Symbol_Text_0:
# 211 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Um símbolo misterioso está gravado\nna parede.$"

WhisperingCave_2F_EventScript_Cave_Symbol_Text_1:
# 212 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "A mysterious symbol is carved into\nthe wall.$"

WhisperingCave_2F_EventScript_Cave_Symbol_Text_2:
# 213 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Un símbolo misterioso está grabado\nen la pared.$"
