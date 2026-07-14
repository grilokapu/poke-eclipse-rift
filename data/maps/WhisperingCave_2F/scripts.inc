WhisperingCave_2F_MapScripts::
	.byte 0


WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger::
# 8 "data/maps/WhisperingCave_2F/scripts.pory"
	lock
# 9 "data/maps/WhisperingCave_2F/scripts.pory"
	removeowe
# 10 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_0
# 11 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 12 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 13 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_1
# 14 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 15 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 16 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 17 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_3
# 18 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_4
# 19 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_5
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_1:
# 21 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_2
# 22 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_PLAYER, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_3
# 23 "data/maps/WhisperingCave_2F/scripts.pory"
	waitmovementall
# 24 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 25 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 26 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_8
# 27 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_9
# 28 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_10
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_6:
# 30 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 50
# 31 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_4
# 32 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_PLAYER, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_5
# 33 "data/maps/WhisperingCave_2F/scripts.pory"
	waitmovementall
# 34 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 35 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 36 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_13
# 37 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_14
# 38 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_15
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_11:
# 40 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 41 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_3
# 42 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_6
# 43 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 44 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 45 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_7
# 46 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 47 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 48 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_SHINY
# 49 "data/maps/WhisperingCave_2F/scripts.pory"
	callnative CreateCaveSymbol
# 50 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 100
# 51 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 52 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_8
# 53 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 54 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_18
# 55 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_19
# 56 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_20
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_16:
# 58 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 59 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 60 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_23
# 61 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_24
# 62 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_25
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_21:
# 64 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 65 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 66 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_28
# 67 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_29
# 68 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_30
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_26:
# 70 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 71 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 72 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_33
# 73 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_34
# 74 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_35
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_31:
# 76 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 77 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_6
# 78 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 30
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_9
# 80 "data/maps/WhisperingCave_2F/scripts.pory"
	setflag FLAG_GIOVANNI_CAVE_SYMBOL
# 81 "data/maps/WhisperingCave_2F/scripts.pory"
	removeobject LOCALID_WHISPERING_GIOVANNI
# 82 "data/maps/WhisperingCave_2F/scripts.pory"
	setvar VAR_WHISPERING_CAVE_2F_EVENT, 1
# 83 "data/maps/WhisperingCave_2F/scripts.pory"
	updateowe
# 84 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_3:
# 17 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_1, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_1

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_4:
# 18 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_2, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_1

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_5:
# 19 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_3, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_1

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_8:
# 26 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_4, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_6

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_9:
# 27 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_5, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_6

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_10:
# 28 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_6, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_6

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_13:
# 36 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_7, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_11

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_14:
# 37 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_8, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_11

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_15:
# 38 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_9, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_11

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_18:
# 54 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_10, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_16

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_19:
# 55 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_11, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_16

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_20:
# 56 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_12, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_16

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_23:
# 60 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_13, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_21

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_24:
# 61 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_14, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_21

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_25:
# 62 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_15, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_21

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_28:
# 66 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_16, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_26

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_29:
# 67 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_17, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_26

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_30:
# 68 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_18, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_26

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_33:
# 72 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_19, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_31

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_34:
# 73 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_20, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_31

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_35:
# 74 "data/maps/WhisperingCave_2F/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_21, MSGBOX_AUTOCLOSE
	goto WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_31


WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk::
# 89 "data/maps/WhisperingCave_2F/scripts.pory"
	lock
# 90 "data/maps/WhisperingCave_2F/scripts.pory"
	faceplayer
# 91 "data/maps/WhisperingCave_2F/scripts.pory"
	goto_if_set FLAG_GIOVANNI_CAVE_SYMBOL, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_2
# 101 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 102 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_1
# 103 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 104 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 105 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 106 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 107 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_6
# 108 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_7
# 109 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_8
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_4:
# 111 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 112 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_0
# 113 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 114 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 115 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 116 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 117 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_16
# 118 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_17
# 119 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_18
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_14:
# 121 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_1
# 122 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_2
# 123 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_3
# 124 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_PLAYER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_4
# 125 "data/maps/WhisperingCave_2F/scripts.pory"
	waitmovementall
# 126 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_5
# 127 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_2:
# 92 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 93 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 94 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_11
# 95 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_12
# 96 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_13
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_9:
# 98 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_6:
# 107 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_4
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_4

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_7:
# 108 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_5
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_4

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_8:
# 109 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_6
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_4

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_11:
# 94 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_1
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_9

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_12:
# 95 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_2
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_9

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_13:
# 96 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_3
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_9

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_16:
# 117 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_7
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_14

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_17:
# 118 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_8
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_14

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_18:
# 119 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_9
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_14


WhisperingCave_2F_EventScript_Hiker_Guard_Way::
# 132 "data/maps/WhisperingCave_2F/scripts.pory"
	lock
# 133 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 134 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_1
# 135 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 136 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 137 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_2
# 138 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_6
# 139 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 140 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 141 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_3
# 142 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_4
# 143 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_5
WhisperingCave_2F_EventScript_Hiker_Guard_Way_1:
# 145 "data/maps/WhisperingCave_2F/scripts.pory"
	playse SE_PIN
# 146 "data/maps/WhisperingCave_2F/scripts.pory"
	moveplayer WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_0
# 147 "data/maps/WhisperingCave_2F/scripts.pory"
	waitse
# 148 "data/maps/WhisperingCave_2F/scripts.pory"
	pause 20
# 149 "data/maps/WhisperingCave_2F/scripts.pory"
	setspeaker WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0
# 150 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 151 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Hiker_Guard_Way_8
# 152 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Hiker_Guard_Way_9
# 153 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Hiker_Guard_Way_10
WhisperingCave_2F_EventScript_Hiker_Guard_Way_6:
# 155 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_3
# 156 "data/maps/WhisperingCave_2F/scripts.pory"
	applymovement LOCALID_PLAYER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_4
# 157 "data/maps/WhisperingCave_2F/scripts.pory"
	waitmovementall
# 158 "data/maps/WhisperingCave_2F/scripts.pory"
	movenpc LOCALID_WHISPERING_HIKER, WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_5
# 159 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Hiker_Guard_Way_3:
# 141 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_4
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_1

WhisperingCave_2F_EventScript_Hiker_Guard_Way_4:
# 142 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_5
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_1

WhisperingCave_2F_EventScript_Hiker_Guard_Way_5:
# 143 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_6
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_1

WhisperingCave_2F_EventScript_Hiker_Guard_Way_8:
# 151 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_7
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_6

WhisperingCave_2F_EventScript_Hiker_Guard_Way_9:
# 152 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_8
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_6

WhisperingCave_2F_EventScript_Hiker_Guard_Way_10:
# 153 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_9
	goto WhisperingCave_2F_EventScript_Hiker_Guard_Way_6


WhisperingCave_2F_EventScript_Picnicker_Battle::
# 166 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 167 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Picnicker_Battle_3
# 170 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Picnicker_Battle_4
# 173 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Picnicker_Battle_5
WhisperingCave_2F_EventScript_Picnicker_Battle_1:
# 177 "data/maps/WhisperingCave_2F/scripts.pory"
	release
	end

WhisperingCave_2F_EventScript_Picnicker_Battle_3:
# 168 "data/maps/WhisperingCave_2F/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_SARAH, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_0, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_1
# 169 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Picnicker_Battle_Text_2
	goto WhisperingCave_2F_EventScript_Picnicker_Battle_1

WhisperingCave_2F_EventScript_Picnicker_Battle_4:
# 171 "data/maps/WhisperingCave_2F/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_SARAH, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_3, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_4
# 172 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Picnicker_Battle_Text_5
	goto WhisperingCave_2F_EventScript_Picnicker_Battle_1

WhisperingCave_2F_EventScript_Picnicker_Battle_5:
# 174 "data/maps/WhisperingCave_2F/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_SARAH, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_6, WhisperingCave_2F_EventScript_Picnicker_Battle_Text_7
# 175 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Picnicker_Battle_Text_8
	goto WhisperingCave_2F_EventScript_Picnicker_Battle_1


WhisperingCave_2F_EventScript_Rare_Bone_Get::
# 182 "data/maps/WhisperingCave_2F/scripts.pory"
	finditem ITEM_RARE_BONE
	end


WhisperingCave_2F_EventScript_Fisherman_Talk::
# 187 "data/maps/WhisperingCave_2F/scripts.pory"
	switch VAR_LANGUAGE
# 188 "data/maps/WhisperingCave_2F/scripts.pory"
	case PT, WhisperingCave_2F_EventScript_Fisherman_Talk_3
# 189 "data/maps/WhisperingCave_2F/scripts.pory"
	case EN, WhisperingCave_2F_EventScript_Fisherman_Talk_4
# 190 "data/maps/WhisperingCave_2F/scripts.pory"
	case ES, WhisperingCave_2F_EventScript_Fisherman_Talk_5
WhisperingCave_2F_EventScript_Fisherman_Talk_1:
	end

WhisperingCave_2F_EventScript_Fisherman_Talk_3:
# 188 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Fisherman_Talk_Text_0, MSGBOX_NPC
	goto WhisperingCave_2F_EventScript_Fisherman_Talk_1

WhisperingCave_2F_EventScript_Fisherman_Talk_4:
# 189 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Fisherman_Talk_Text_1, MSGBOX_NPC
	goto WhisperingCave_2F_EventScript_Fisherman_Talk_1

WhisperingCave_2F_EventScript_Fisherman_Talk_5:
# 190 "data/maps/WhisperingCave_2F/scripts.pory"
	msgbox WhisperingCave_2F_EventScript_Fisherman_Talk_Text_2, MSGBOX_NPC
	goto WhisperingCave_2F_EventScript_Fisherman_Talk_1


WhisperingCave_2F_EventScript_Hiker_Talk::
	return


# 10 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_0:
# 10 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_right
# 10 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_up
# 10 "data/maps/WhisperingCave_2F/scripts.pory"
	face_up
	step_end

# 13 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_1:
# 13 "data/maps/WhisperingCave_2F/scripts.pory"
	emote_exclamation_mark
	step_end

# 21 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_2:
# 21 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_right
# 21 "data/maps/WhisperingCave_2F/scripts.pory"
	face_up
	step_end

# 22 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_3:
# 22 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_up
# 22 "data/maps/WhisperingCave_2F/scripts.pory"
	face_up
	step_end

# 31 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_4:
# 31 "data/maps/WhisperingCave_2F/scripts.pory"
	face_left
	step_end

# 32 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_5:
# 32 "data/maps/WhisperingCave_2F/scripts.pory"
	face_right
	step_end

# 42 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_6:
# 42 "data/maps/WhisperingCave_2F/scripts.pory"
	face_up
	step_end

# 45 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_7:
# 45 "data/maps/WhisperingCave_2F/scripts.pory"
	emote_question_mark
	step_end

# 52 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_8:
# 52 "data/maps/WhisperingCave_2F/scripts.pory"
	emote_exclamation_mark
# 52 "data/maps/WhisperingCave_2F/scripts.pory"
	delay_16
# 52 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_up
# 52 "data/maps/WhisperingCave_2F/scripts.pory"
	face_left
	step_end

# 79 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Movement_9:
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 79 "data/maps/WhisperingCave_2F/scripts.pory"
	delay_16
	step_end

# 112 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_0:
# 112 "data/maps/WhisperingCave_2F/scripts.pory"
	emote_question_mark
# 112 "data/maps/WhisperingCave_2F/scripts.pory"
	face_down
	step_end

# 121 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_1:
# 121 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_down
# 121 "data/maps/WhisperingCave_2F/scripts.pory"
	face_down
# 121 "data/maps/WhisperingCave_2F/scripts.pory"
	delay_16
	step_end

# 122 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_2:
# 122 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_right
# 122 "data/maps/WhisperingCave_2F/scripts.pory"
	face_down
	step_end

# 123 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_3:
# 123 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_fast_down
	step_end

# 124 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_4:
# 124 "data/maps/WhisperingCave_2F/scripts.pory"
	jump_2_down
	step_end

# 126 "data/maps/WhisperingCave_2F/scripts.pory"
WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Movement_5:
# 126 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_up
# 126 "data/maps/WhisperingCave_2F/scripts.pory"
	walk_left
# 126 "data/maps/WhisperingCave_2F/scripts.pory"
	face_down
	step_end

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_0:
# 17 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Giovanni$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_1:
# 17 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "…\pVocê também veio até aqui.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_2:
# 18 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "…\pYou came here too.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_3:
# 19 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "…\pTú también has venido hasta aquí.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_4:
# 26 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "O que acha desse desenho?$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_5:
# 27 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "What do you think of this drawing?$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_6:
# 28 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¿Qué te parece este dibujo?$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_7:
# 36 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Estranho…\pEu já passei por esta caverna\noutras vezes.\pMas nunca tinha reparado nele.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_8:
# 37 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Strange…\pI've passed through this cave\nbefore.\pBut I've never noticed it.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_9:
# 38 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Qué extraño…\pYa había pasado por esta cueva\nantes.\pPero nunca me había fijado en él.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_10:
# 54 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Você viu isso?$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_11:
# 55 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Did you see that?$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_12:
# 56 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¿Viste eso?$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_13:
# 60 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Isso só aconteceu quando você\nchegou.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_14:
# 61 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "That only happened when you\narrived.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_15:
# 62 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Eso solo ocurrió cuando llegaste.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_16:
# 66 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Interessante…$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_17:
# 67 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Interesting…$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_18:
# 68 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Interesante…$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_19:
# 72 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Agora você me deixou curioso…\pQuem… ou o que é você?\pAcho que terei tempo de sobra para\ndescobrir.\pTenho a sensação de que nossos\ncaminhos ainda vão se cruzar\lmuitas vezes.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_20:
# 73 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Now you've made me curious…\pWho… or what are you?\pI suppose I'll have plenty of time\nto find out.\pI have a feeling our paths will\ncross many more times.$"

WhisperingCave_2F_EventScript_Giovanni_LookingToSymbol_Trigger_Text_21:
# 74 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Ahora has despertado mi\ncuriosidad…\p¿Quién… o qué eres?\pSupongo que tendré tiempo de sobra\npara descubrirlo.\pTengo el presentimiento de que\nnuestros caminos volverán a\lcruzarse muchas veces.$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_0:
# 92 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Gerônimo$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_1:
# 94 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Desculpa por ter te empurrado\ndaquela saliência!\pEu só queria testar se a gravidade\nainda estava funcionando.\pParece que está!$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_2:
# 95 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Sorry for pushing you off that\nledge!\pI just wanted to make sure gravity\nwas still working.\pLooks like it is!$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_3:
# 96 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¡Perdón por empujarte desde esa\ncornisa!\pSolo quería comprobar si la\ngravedad seguía funcionando.\p¡Parece que sí!$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_4:
# 107 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Espere!\pEstá vendo aquela coisa ali em\nbaixo?$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_5:
# 108 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Wait!\pDo you see that thing down there?$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_6:
# 109 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¡Espera!\p¿Ves esa cosa ahí abajo?$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_7:
# 117 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Veja mais de perto…$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_8:
# 118 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Take a closer look…$"

WhisperingCave_2F_EventScript_Hiker_Guard_Way_Talk_Text_9:
# 119 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Míralo más de cerca…$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_0:
# 168 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Que bom encontrar você!\nVamos batalhar!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_1:
# 168 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Essa derrota não foi nada legal…$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_2:
# 169 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Quanto mais você batalha, mais\nvontade dá de continuar\lbatalhando!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_3:
# 171 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "It's great to see you!\nLet's have a battle!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_4:
# 171 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "That loss wasn't fun at all…$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_5:
# 172 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "The more you battle, the more you\nwant to keep battling!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_6:
# 174 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¡Qué bueno encontrarte!\n¡Vamos a combatir!$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_7:
# 174 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Esa derrota no fue nada divertida…$"

WhisperingCave_2F_EventScript_Picnicker_Battle_Text_8:
# 175 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "¡Cuanto más combates, más ganas\ntienes de seguir combatiendo!$"

WhisperingCave_2F_EventScript_Fisherman_Talk_Text_0:
# 188 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Muita gente acha que a Old Rod só\nserve para pescar Magikarp.\pMas um bom Pescador sempre\nencontra surpresas!c$"

WhisperingCave_2F_EventScript_Fisherman_Talk_Text_1:
# 189 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Lots of people think the Old Rod\nonly catches Magikarp.\pBut a skilled Fisher can always\nreel in a surprise!$"

WhisperingCave_2F_EventScript_Fisherman_Talk_Text_2:
# 190 "data/maps/WhisperingCave_2F/scripts.pory"
	.string "Mucha gente cree que la Old Rod\nsolo sirve para pescar Magikarp.\p¡Pero un buen Pescador siempre\nencuentra alguna sorpresa!$"
