VerdantSanctum_Shrine_MapScripts::
# 2 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdantSanctum_Shrine_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 6 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VerdantSanctum_Shrine_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

VerdantSanctum_Shrine_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setflag FLAG_HIDE_VERDANT_SANCTUM_RESEARCHER
	end

VerdantSanctum_Shrine_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	callnative ResetVerdantSanctumRuins
	end


VerdantSanctum_Shrine_EventScript_Inscription::
# 13 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	lockall
# 14 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	call VerdantSanctum_Shrine_EventScript_ReadInscription
# 15 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	releaseall
	end


VerdantSanctum_Shrine_EventScript_ReadInscription::
# 20 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 21 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_ReadInscription_3
# 22 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_ReadInscription_4
# 23 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_ReadInscription_5
VerdantSanctum_Shrine_EventScript_ReadInscription_1:
# 25 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	pause 30
# 26 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 27 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_ReadInscription_8
# 28 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_ReadInscription_9
# 29 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_ReadInscription_10
VerdantSanctum_Shrine_EventScript_ReadInscription_6:
# 31 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 32 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_ReadInscription_13
# 33 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_ReadInscription_14
# 34 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_ReadInscription_15
VerdantSanctum_Shrine_EventScript_ReadInscription_11:
# 36 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setflag FLAG_VERDANT_SANCTUM_INSCRIPTION_READ
	return

VerdantSanctum_Shrine_EventScript_ReadInscription_3:
# 21 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_ReadInscription_Text_0, MSGBOX_SIGN
	goto VerdantSanctum_Shrine_EventScript_ReadInscription_1

VerdantSanctum_Shrine_EventScript_ReadInscription_4:
# 22 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_ReadInscription_Text_1, MSGBOX_SIGN
	goto VerdantSanctum_Shrine_EventScript_ReadInscription_1

VerdantSanctum_Shrine_EventScript_ReadInscription_5:
# 23 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_ReadInscription_Text_2, MSGBOX_SIGN
	goto VerdantSanctum_Shrine_EventScript_ReadInscription_1

VerdantSanctum_Shrine_EventScript_ReadInscription_8:
# 27 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_ReadInscription_Text_3, MSGBOX_SIGN
	goto VerdantSanctum_Shrine_EventScript_ReadInscription_6

VerdantSanctum_Shrine_EventScript_ReadInscription_9:
# 28 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_ReadInscription_Text_4, MSGBOX_SIGN
	goto VerdantSanctum_Shrine_EventScript_ReadInscription_6

VerdantSanctum_Shrine_EventScript_ReadInscription_10:
# 29 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_ReadInscription_Text_5, MSGBOX_SIGN
	goto VerdantSanctum_Shrine_EventScript_ReadInscription_6

VerdantSanctum_Shrine_EventScript_ReadInscription_13:
# 32 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_ReadInscription_Text_6, MSGBOX_SIGN
	goto VerdantSanctum_Shrine_EventScript_ReadInscription_11

VerdantSanctum_Shrine_EventScript_ReadInscription_14:
# 33 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_ReadInscription_Text_7, MSGBOX_SIGN
	goto VerdantSanctum_Shrine_EventScript_ReadInscription_11

VerdantSanctum_Shrine_EventScript_ReadInscription_15:
# 34 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_ReadInscription_Text_8, MSGBOX_SIGN
	goto VerdantSanctum_Shrine_EventScript_ReadInscription_11


VerdantSanctum_Shrine_EventScript_Exit::
# 42 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	goto_if_set FLAG_VERDANT_SANCTUM_ANOMALY, VerdantSanctum_Shrine_EventScript_Exit_2
# 46 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 47 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq VerdantSanctum_Shrine_EventScript_Exit_5
# 50 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	lockall
# 51 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	goto_if_unset FLAG_VERDANT_SANCTUM_INSCRIPTION_READ, VerdantSanctum_Shrine_EventScript_Exit_8
# 57 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	fadeoutbgm 1
# 58 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setvar VAR_0x8004, 1
# 59 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setvar VAR_0x8005, 1
# 60 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setvar VAR_0x8006, 4
# 61 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setvar VAR_0x8007, 4
# 62 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	special ShakeCamera
# 64 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	playse SE_M_CONFUSE_RAY
# 65 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	waitstate
# 66 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, -8
# 67 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	callnative BeginVerdantSanctumAnomaly
# 68 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	special DrawWholeMapView
# 69 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, -8
# 70 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	pause 60
# 71 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	fadescreenspeed FADE_TO_WHITE, -8
# 72 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	callnative EndVerdantSanctumAnomaly
# 73 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	special DrawWholeMapView
# 74 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	fadescreenspeed FADE_FROM_WHITE, -8
# 75 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	waitse
# 76 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	pause 30
# 77 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Exit_Text_0, MSGBOX_DEFAULT
# 78 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	call VerdantSanctum_Shrine_EventScript_Researcher
# 79 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setflag FLAG_VERDANT_SANCTUM_ANOMALY
# 80 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	fadeinbgm 1
# 81 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	releaseall
	end

VerdantSanctum_Shrine_EventScript_Exit_2:
	end

VerdantSanctum_Shrine_EventScript_Exit_5:
	end

VerdantSanctum_Shrine_EventScript_Exit_8:
# 52 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	moveplayer VerdantSanctum_Shrine_EventScript_Exit_Movement_0
# 53 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	releaseall
	end


VerdantSanctum_Shrine_EventScript_Researcher::
# 87 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	pause 40
# 88 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	playse SE_BRIDGE_WALK
# 89 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	pause 10
# 90 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	playse SE_BRIDGE_WALK
# 91 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	pause 8
# 92 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	playse SE_BRIDGE_WALK
# 93 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	waitse
# 96 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 97 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	moveplayer VerdantSanctum_Shrine_EventScript_Researcher_Movement_0
# 98 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	compare VAR_0x8008, 4
	goto_if_eq VerdantSanctum_Shrine_EventScript_Researcher_2
# 101 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setobjectxyperm LOCALID_VERDANT_SANCTUM_RESEARCHER, 5, 10
VerdantSanctum_Shrine_EventScript_Researcher_1:
# 103 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	clearflag FLAG_HIDE_VERDANT_SANCTUM_RESEARCHER
# 104 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	addobject LOCALID_VERDANT_SANCTUM_RESEARCHER
# 105 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	movenpc LOCALID_VERDANT_SANCTUM_RESEARCHER, VerdantSanctum_Shrine_EventScript_Researcher_Movement_1
# 106 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 107 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_Researcher_7
# 108 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_Researcher_8
# 109 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_Researcher_9
VerdantSanctum_Shrine_EventScript_Researcher_5:
# 111 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	movenpc LOCALID_VERDANT_SANCTUM_RESEARCHER, VerdantSanctum_Shrine_EventScript_Researcher_Movement_1
# 112 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 113 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_Researcher_12
# 114 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_Researcher_13
# 115 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_Researcher_14
VerdantSanctum_Shrine_EventScript_Researcher_10:
# 117 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	pause 25
# 118 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 119 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_Researcher_17
# 120 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_Researcher_18
# 121 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_Researcher_19
VerdantSanctum_Shrine_EventScript_Researcher_15:
# 123 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	movenpc LOCALID_VERDANT_SANCTUM_RESEARCHER, VerdantSanctum_Shrine_EventScript_Researcher_Movement_2
# 124 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 125 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_Researcher_22
# 126 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_Researcher_23
# 127 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_Researcher_24
VerdantSanctum_Shrine_EventScript_Researcher_20:
# 130 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	movenpc LOCALID_VERDANT_SANCTUM_RESEARCHER, VerdantSanctum_Shrine_EventScript_Researcher_Movement_3
# 131 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 132 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_Researcher_27
# 133 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_Researcher_28
# 134 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_Researcher_29
VerdantSanctum_Shrine_EventScript_Researcher_25:
# 136 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	pause 30
# 137 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 138 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_Researcher_32
# 139 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_Researcher_33
# 140 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_Researcher_34
VerdantSanctum_Shrine_EventScript_Researcher_30:
# 142 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	movenpc LOCALID_VERDANT_SANCTUM_RESEARCHER, VerdantSanctum_Shrine_EventScript_Researcher_Movement_4
# 143 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 144 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_Researcher_37
# 145 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_Researcher_38
# 146 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_Researcher_39
VerdantSanctum_Shrine_EventScript_Researcher_35:
# 148 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	pause 40
# 149 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Exit_Text_0, MSGBOX_DEFAULT
# 150 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	switch VAR_LANGUAGE
# 151 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case PT, VerdantSanctum_Shrine_EventScript_Researcher_42
# 152 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case EN, VerdantSanctum_Shrine_EventScript_Researcher_43
# 153 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	case ES, VerdantSanctum_Shrine_EventScript_Researcher_44
VerdantSanctum_Shrine_EventScript_Researcher_40:
# 155 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	movenpc LOCALID_VERDANT_SANCTUM_RESEARCHER, VerdantSanctum_Shrine_EventScript_Researcher_Movement_5
# 156 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	removeobject LOCALID_VERDANT_SANCTUM_RESEARCHER
# 157 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setflag FLAG_HIDE_VERDANT_SANCTUM_RESEARCHER
	return

VerdantSanctum_Shrine_EventScript_Researcher_2:
# 99 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	setobjectxyperm LOCALID_VERDANT_SANCTUM_RESEARCHER, 4, 10
	goto VerdantSanctum_Shrine_EventScript_Researcher_1

VerdantSanctum_Shrine_EventScript_Researcher_7:
# 107 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_5

VerdantSanctum_Shrine_EventScript_Researcher_8:
# 108 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_5

VerdantSanctum_Shrine_EventScript_Researcher_9:
# 109 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_5

VerdantSanctum_Shrine_EventScript_Researcher_12:
# 113 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_3, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_10

VerdantSanctum_Shrine_EventScript_Researcher_13:
# 114 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_4, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_10

VerdantSanctum_Shrine_EventScript_Researcher_14:
# 115 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_5, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_10

VerdantSanctum_Shrine_EventScript_Researcher_17:
# 119 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_6, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_15

VerdantSanctum_Shrine_EventScript_Researcher_18:
# 120 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_7, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_15

VerdantSanctum_Shrine_EventScript_Researcher_19:
# 121 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_8, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_15

VerdantSanctum_Shrine_EventScript_Researcher_22:
# 125 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_9, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_20

VerdantSanctum_Shrine_EventScript_Researcher_23:
# 126 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_10, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_20

VerdantSanctum_Shrine_EventScript_Researcher_24:
# 127 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_11, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_20

VerdantSanctum_Shrine_EventScript_Researcher_27:
# 132 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_12, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_25

VerdantSanctum_Shrine_EventScript_Researcher_28:
# 133 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_13, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_25

VerdantSanctum_Shrine_EventScript_Researcher_29:
# 134 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_14, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_25

VerdantSanctum_Shrine_EventScript_Researcher_32:
# 138 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_15, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_30

VerdantSanctum_Shrine_EventScript_Researcher_33:
# 139 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_16, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_30

VerdantSanctum_Shrine_EventScript_Researcher_34:
# 140 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_17, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_30

VerdantSanctum_Shrine_EventScript_Researcher_37:
# 144 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_18, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_35

VerdantSanctum_Shrine_EventScript_Researcher_38:
# 145 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_19, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_35

VerdantSanctum_Shrine_EventScript_Researcher_39:
# 146 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_20, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_35

VerdantSanctum_Shrine_EventScript_Researcher_42:
# 151 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_21, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_40

VerdantSanctum_Shrine_EventScript_Researcher_43:
# 152 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_22, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_40

VerdantSanctum_Shrine_EventScript_Researcher_44:
# 153 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	msgbox VerdantSanctum_Shrine_EventScript_Researcher_Text_23, MSGBOX_DEFAULT
	goto VerdantSanctum_Shrine_EventScript_Researcher_40


# 52 "data/maps/VerdantSanctum_Shrine/scripts.pory"
VerdantSanctum_Shrine_EventScript_Exit_Movement_0:
# 52 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	walk_up
# 52 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	face_up
	step_end

# 97 "data/maps/VerdantSanctum_Shrine/scripts.pory"
VerdantSanctum_Shrine_EventScript_Researcher_Movement_0:
# 97 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	walk_up
# 97 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	walk_up
# 97 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	face_down
	step_end

# 105 "data/maps/VerdantSanctum_Shrine/scripts.pory"
VerdantSanctum_Shrine_EventScript_Researcher_Movement_1:
# 105 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	walk_fast_up
	step_end

# 123 "data/maps/VerdantSanctum_Shrine/scripts.pory"
VerdantSanctum_Shrine_EventScript_Researcher_Movement_2:
# 123 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	face_left
# 123 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	delay_16
# 123 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	face_right
# 123 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	delay_16
# 123 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	face_up
	step_end

# 130 "data/maps/VerdantSanctum_Shrine/scripts.pory"
VerdantSanctum_Shrine_EventScript_Researcher_Movement_3:
# 130 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	face_down
# 130 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	delay_16
# 130 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	emoji_doubt
# 130 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	delay_16
# 130 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	face_up
	step_end

# 142 "data/maps/VerdantSanctum_Shrine/scripts.pory"
VerdantSanctum_Shrine_EventScript_Researcher_Movement_4:
# 142 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	walk_down
# 142 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	delay_16
# 142 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	face_up
	step_end

# 155 "data/maps/VerdantSanctum_Shrine/scripts.pory"
VerdantSanctum_Shrine_EventScript_Researcher_Movement_5:
# 155 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	walk_fast_down
	step_end

VerdantSanctum_Shrine_EventScript_ReadInscription_Text_0:
# 21 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Uma antiga inscrição está\ngravada na pedra.\pGrande parte do texto foi\napagada pelo tempo.\pMas uma pequena frase ainda\npode ser lida...$"

VerdantSanctum_Shrine_EventScript_ReadInscription_Text_1:
# 22 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "An ancient inscription is\ncarved into the stone.\pMuch of the text has been\nerased by time.\pBut a short phrase can\nstill be read...$"

VerdantSanctum_Shrine_EventScript_ReadInscription_Text_2:
# 23 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Una antigua inscripción está\ngrabada en la piedra.\pEl tiempo ha borrado gran\nparte del texto.\pPero aún se puede leer\nuna pequeña frase...$"

VerdantSanctum_Shrine_EventScript_ReadInscription_Text_3:
# 27 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "...quando o céu se partir...$"

VerdantSanctum_Shrine_EventScript_ReadInscription_Text_4:
# 28 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "...when the sky breaks...$"

VerdantSanctum_Shrine_EventScript_ReadInscription_Text_5:
# 29 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "...cuando el cielo se rompa...$"

VerdantSanctum_Shrine_EventScript_ReadInscription_Text_6:
# 32 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "O restante da inscrição\ndesapareceu.$"

VerdantSanctum_Shrine_EventScript_ReadInscription_Text_7:
# 33 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "The rest of the inscription\nhas vanished.$"

VerdantSanctum_Shrine_EventScript_ReadInscription_Text_8:
# 34 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "El resto de la inscripción\nha desaparecido.$"

VerdantSanctum_Shrine_EventScript_Exit_Text_0:
# 77 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "...$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_0:
# 107 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Ei!$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_1:
# 108 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Hey!$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_2:
# 109 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "¡Eh!$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_3:
# 113 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Você estava aqui quando aconteceu?$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_4:
# 114 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Were you here when it happened?$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_5:
# 115 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "¿Estabas aquí cuando ocurrió?$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_6:
# 119 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Por um instante, meus equipamentos\nregistraram uma leitura absurda.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_7:
# 120 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "For an instant, my equipment\nrecorded an absurd reading.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_8:
# 121 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Por un instante, mis equipos\nregistraron una lectura absurda.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_9:
# 125 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Mas agora...\p...não há nada.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_10:
# 126 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "But now...\p...there is nothing.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_11:
# 127 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Pero ahora...\p...no hay nada.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_12:
# 132 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Isso não faz sentido.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_13:
# 133 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "This makes no sense.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_14:
# 134 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Esto no tiene sentido.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_15:
# 138 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Preciso avisar a Professora Hikari.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_16:
# 139 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "I need to tell Professor Hikari.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_17:
# 140 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Debo avisar a la Profesora Hikari.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_18:
# 144 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Você também viu alguma coisa,\nnão viu?$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_19:
# 145 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "You saw something too,\ndidn't you?$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_20:
# 146 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Tú también viste algo,\n¿verdad?$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_21:
# 151 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Imaginei.\pSe estiver seguindo para o sul,\ntenha cuidado.\pOs Pokémon daqui estão agindo\nde maneira estranha desde\lesta manhã.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_22:
# 152 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "I thought so.\pIf you're heading south,\nbe careful.\pThe Pokémon here have been acting\nstrangely since this morning.$"

VerdantSanctum_Shrine_EventScript_Researcher_Text_23:
# 153 "data/maps/VerdantSanctum_Shrine/scripts.pory"
	.string "Me lo imaginaba.\pSi vas hacia el sur,\nten cuidado.\pLos Pokémon de aquí se comportan\nde forma extraña desde\lesta mañana.$"
