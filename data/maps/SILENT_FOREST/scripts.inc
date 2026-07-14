SILENT_FOREST_MapScripts::
# 6 "data/maps/SILENT_FOREST/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SILENT_FOREST_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 2 "data/maps/SILENT_FOREST/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SILENT_FOREST_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SILENT_FOREST_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 7 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_CHIEN_PAO_SILENT_FOREST
	return

SILENT_FOREST_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/SILENT_FOREST/scripts.pory"
	map_script_2 VAR_FOREST_WHISPER_STATE, 0, SilentForest_EventScript_FadeIn_Player
# 4 "data/maps/SILENT_FOREST/scripts.pory"
	map_script_2 VAR_FOREST_WHISPER_STATE, 2, SilentForest_EventScript_Chien_Pao_Event
	.2byte 0


SilentForest_EventScript_FadeIn_Player::
# 15 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_RAIN
# 16 "data/maps/SILENT_FOREST/scripts.pory"
	pause 100
# 17 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_NOTE_D
# 18 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 19 "data/maps/SILENT_FOREST/scripts.pory"
	pause 80
# 20 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_NOTE_E
# 21 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 22 "data/maps/SILENT_FOREST/scripts.pory"
	pause 80
# 23 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_NOTE_A
# 24 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 25 "data/maps/SILENT_FOREST/scripts.pory"
	pause 80
# 26 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_NOTE_D
# 27 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 28 "data/maps/SILENT_FOREST/scripts.pory"
	pause 80
# 29 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_SWITCH
# 30 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 31 "data/maps/SILENT_FOREST/scripts.pory"
	pause 100
# 32 "data/maps/SILENT_FOREST/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 33 "data/maps/SILENT_FOREST/scripts.pory"
	clearflag FLAG_SPAWN_INVISIBLE
# 34 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_FOREST_WHISPER_STATE, 1
# 35 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 2
# 36 "data/maps/SILENT_FOREST/scripts.pory"
	warpsilent MAP_SILENT_FOREST, VAR_TEMP_0, VAR_TEMP_1
# 37 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
	return


SilentForest_EventScript_Symbol_Chien_Pao::
# 41 "data/maps/SILENT_FOREST/scripts.pory"
	lockall
# 42 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 43 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Symbol_Chien_Pao_Movement_0
# 44 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 45 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 46 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_FOREST_WHISPER_STATE, 2
# 47 "data/maps/SILENT_FOREST/scripts.pory"
	warp MAP_SILENT_FOREST, 11, 21
# 48 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
	return


SilentForest_EventScript_Chien_Pao_Event::
# 54 "data/maps/SILENT_FOREST/scripts.pory"
	call Draw_Chien_Symbol
# 55 "data/maps/SILENT_FOREST/scripts.pory"
	playbgm MUS_RG_SEVII_67, 0
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Chien_Pao_Event_Movement_0
# 57 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 59 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Symbol_Chien_Pao_Movement_0
# 60 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 61 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 62 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Chien_Pao_Event_Movement_1
# 63 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_SET_SYMBOL_ANIM
# 64 "data/maps/SILENT_FOREST/scripts.pory"
	special DrawWholeMapView
# 65 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 66 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_ORB
# 67 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_RESULT, 2
# 68 "data/maps/SILENT_FOREST/scripts.pory"
	special DoOrbEffect
# 69 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Chien_Pao_Event_Movement_2
# 70 "data/maps/SILENT_FOREST/scripts.pory"
	pause 150
# 71 "data/maps/SILENT_FOREST/scripts.pory"
	special FadeOutOrbEffect
# 72 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
# 73 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_TO_WHITE
# 74 "data/maps/SILENT_FOREST/scripts.pory"
	fadedefaultbgm
# 75 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8004, 1
# 76 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8005, 1
# 77 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8006, 8
# 78 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8007, 5
# 79 "data/maps/SILENT_FOREST/scripts.pory"
	special ShakeCamera
# 80 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
# 81 "data/maps/SILENT_FOREST/scripts.pory"
	pause 100
# 82 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 83 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 84 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 85 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_3
# 86 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_4
# 87 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_5
SilentForest_EventScript_Chien_Pao_Event_1:
# 89 "data/maps/SILENT_FOREST/scripts.pory"
	pause 50
# 90 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 91 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_8
# 92 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_9
# 93 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_10
SilentForest_EventScript_Chien_Pao_Event_6:
# 95 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 96 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_SHINY
# 97 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CreatePlayerBright
# 98 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 99 "data/maps/SILENT_FOREST/scripts.pory"
	pause 100
# 100 "data/maps/SILENT_FOREST/scripts.pory"
	clearflag FLAG_CHIEN_PAO_SILENT_FOREST
# 101 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_FOREST_CHIEN_PAO
# 102 "data/maps/SILENT_FOREST/scripts.pory"
	special SpawnCameraObject
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	movecamera SilentForest_EventScript_Chien_Pao_Event_Movement_3
# 104 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_CAMERA, SilentForest_EventScript_Chien_Pao_Event_Movement_4
# 106 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_5
# 107 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 108 "data/maps/SILENT_FOREST/scripts.pory"
	special RemoveCameraObject
# 109 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 110 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 111 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_13
# 112 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_14
# 113 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_15
SilentForest_EventScript_Chien_Pao_Event_11:
# 115 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 116 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 117 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_6
# 119 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 120 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 121 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 122 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_18
# 123 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_19
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_20
SilentForest_EventScript_Chien_Pao_Event_16:
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 127 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 128 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 129 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 130 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_23
# 131 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_24
# 132 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_25
SilentForest_EventScript_Chien_Pao_Event_21:
# 134 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 135 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 136 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_7
# 137 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 138 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 139 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_28
# 141 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_29
# 142 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_30
SilentForest_EventScript_Chien_Pao_Event_26:
# 145 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 146 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 147 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 148 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 149 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 150 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Symbol_Chien_Pao_Movement_0
# 151 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 152 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 153 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8004, 1
# 154 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8005, 1
# 155 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8006, 8
# 156 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8007, 5
# 157 "data/maps/SILENT_FOREST/scripts.pory"
	special ShakeCamera
# 158 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
# 159 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_MAGNET_PORTAL_BEHIND
# 160 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CreateMagnectPortal
# 161 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_8
# 162 "data/maps/SILENT_FOREST/scripts.pory"
	pause 100
# 163 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 164 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 165 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_33
# 166 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_34
# 167 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_35
SilentForest_EventScript_Chien_Pao_Event_31:
# 169 "data/maps/SILENT_FOREST/scripts.pory"
	clearflag FLAG_MAGNET_PORTAL_BEHIND
# 170 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 171 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 172 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_9
# 173 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 174 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 175 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_38
# 176 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_39
# 177 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_40
SilentForest_EventScript_Chien_Pao_Event_36:
# 179 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 180 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 181 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CreateMagnectPortal
# 182 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_FOREST_CHIEN_PAO
# 183 "data/maps/SILENT_FOREST/scripts.pory"
	pause 100
# 184 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 185 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Chien_Pao_Event_Movement_10
# 186 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 187 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 188 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_DING_DONG
# 189 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 190 "data/maps/SILENT_FOREST/scripts.pory"
	call Erase_Chien_Symbol
# 191 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 192 "data/maps/SILENT_FOREST/scripts.pory"
	call Draw_Chien_Symbol
# 193 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 194 "data/maps/SILENT_FOREST/scripts.pory"
	call Erase_Chien_Symbol
# 195 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 196 "data/maps/SILENT_FOREST/scripts.pory"
	call Draw_Chien_Symbol
# 197 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 198 "data/maps/SILENT_FOREST/scripts.pory"
	call Erase_Chien_Symbol
# 199 "data/maps/SILENT_FOREST/scripts.pory"
	pause 150
# 200 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_TO_BLACK
# 201 "data/maps/SILENT_FOREST/scripts.pory"
	pause 100
# 202 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_SILENT_FOREST_STATE, 1
# 203 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 0
# 204 "data/maps/SILENT_FOREST/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 7, 6
# 205 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
	return

SilentForest_EventScript_Chien_Pao_Event_3:
# 85 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_0
	goto SilentForest_EventScript_Chien_Pao_Event_1

SilentForest_EventScript_Chien_Pao_Event_4:
# 86 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_1
	goto SilentForest_EventScript_Chien_Pao_Event_1

SilentForest_EventScript_Chien_Pao_Event_5:
# 87 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_2
	goto SilentForest_EventScript_Chien_Pao_Event_1

SilentForest_EventScript_Chien_Pao_Event_8:
# 91 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_3
	goto SilentForest_EventScript_Chien_Pao_Event_6

SilentForest_EventScript_Chien_Pao_Event_9:
# 92 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_4
	goto SilentForest_EventScript_Chien_Pao_Event_6

SilentForest_EventScript_Chien_Pao_Event_10:
# 93 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_5
	goto SilentForest_EventScript_Chien_Pao_Event_6

SilentForest_EventScript_Chien_Pao_Event_13:
# 111 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_6, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_11

SilentForest_EventScript_Chien_Pao_Event_14:
# 112 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_7, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_11

SilentForest_EventScript_Chien_Pao_Event_15:
# 113 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_8, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_11

SilentForest_EventScript_Chien_Pao_Event_18:
# 122 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_9, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_16

SilentForest_EventScript_Chien_Pao_Event_19:
# 123 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_10, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_16

SilentForest_EventScript_Chien_Pao_Event_20:
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_11, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_16

SilentForest_EventScript_Chien_Pao_Event_23:
# 130 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_12, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_21

SilentForest_EventScript_Chien_Pao_Event_24:
# 131 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_13, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_21

SilentForest_EventScript_Chien_Pao_Event_25:
# 132 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_14, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_21

SilentForest_EventScript_Chien_Pao_Event_28:
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_15, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_26

SilentForest_EventScript_Chien_Pao_Event_29:
# 141 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_16, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_26

SilentForest_EventScript_Chien_Pao_Event_30:
# 142 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_17, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_26

SilentForest_EventScript_Chien_Pao_Event_33:
# 165 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_18, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_31

SilentForest_EventScript_Chien_Pao_Event_34:
# 166 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_19, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_31

SilentForest_EventScript_Chien_Pao_Event_35:
# 167 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_20, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_31

SilentForest_EventScript_Chien_Pao_Event_38:
# 175 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_21, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_36

SilentForest_EventScript_Chien_Pao_Event_39:
# 176 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_22, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_36

SilentForest_EventScript_Chien_Pao_Event_40:
# 177 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_23, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_36


Set_Chien_Pao_Name::
# 209 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker Set_Chien_Pao_Name_Text_0
# 210 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_SOUTHEAST
	return


HideChien_Pao_Mugshot::
# 215 "data/maps/SILENT_FOREST/scripts.pory"
	waitmoncry
# 216 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
	return


Erase_Chien_Symbol::
# 221 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 9, 0x206, FALSE
# 222 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 9, 0x206, FALSE
# 223 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 9, 0x206, FALSE
# 224 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 9, 0x206, FALSE
# 225 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 9, 0x206, FALSE
# 226 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 10, 0x206, FALSE
# 227 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 10, 0x206, FALSE
# 228 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 10, 0x206, FALSE
# 229 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 10, 0x206, FALSE
# 230 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 10, 0x206, FALSE
# 231 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 11, 0x206, FALSE
# 232 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 11, 0x206, FALSE
# 233 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 11, 0x206, FALSE
# 234 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 11, 0x206, FALSE
# 235 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 11, 0x206, FALSE
# 236 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 12, 0x206, FALSE
# 237 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 12, 0x206, FALSE
# 238 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 12, 0x206, FALSE
# 239 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 12, 0x206, FALSE
# 240 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 12, 0x206, FALSE
# 241 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 13, 0x206, FALSE
# 242 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 13, 0x206, FALSE
# 243 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 13, 0x206, FALSE
# 244 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 13, 0x206, FALSE
# 245 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 13, 0x206, FALSE
# 246 "data/maps/SILENT_FOREST/scripts.pory"
	special DrawWholeMapView
	return


Draw_Chien_Symbol::
# 251 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 9, METATILE_InsideOfTruck_Chien_Symbol_0, FALSE
# 252 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 9, METATILE_InsideOfTruck_Chien_Symbol_1, FALSE
# 253 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 9, METATILE_InsideOfTruck_Chien_Symbol_2, FALSE
# 254 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 9, METATILE_InsideOfTruck_Chien_Symbol_3, FALSE
# 255 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 9, METATILE_InsideOfTruck_Chien_Symbol_4, FALSE
# 256 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 10, METATILE_InsideOfTruck_Chien_Symbol_5, FALSE
# 257 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 10, METATILE_InsideOfTruck_Chien_Symbol_6, FALSE
# 258 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 10, METATILE_InsideOfTruck_Chien_Symbol_7, FALSE
# 259 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 10, METATILE_InsideOfTruck_Chien_Symbol_8, FALSE
# 260 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 10, METATILE_InsideOfTruck_Chien_Symbol_9, FALSE
# 261 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 11, METATILE_InsideOfTruck_Chien_Symbol_10, FALSE
# 262 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 11, METATILE_InsideOfTruck_Chien_Symbol_11, FALSE
# 263 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 11, METATILE_InsideOfTruck_Chien_Symbol_12, FALSE
# 264 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 11, METATILE_InsideOfTruck_Chien_Symbol_13, FALSE
# 265 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 11, METATILE_InsideOfTruck_Chien_Symbol_14, FALSE
# 266 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 12, METATILE_InsideOfTruck_Chien_Symbol_15, FALSE
# 267 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 12, METATILE_InsideOfTruck_Chien_Symbol_16, FALSE
# 268 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 12, METATILE_InsideOfTruck_Chien_Symbol_17, FALSE
# 269 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 12, METATILE_InsideOfTruck_Chien_Symbol_18, FALSE
# 270 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 12, METATILE_InsideOfTruck_Chien_Symbol_19, FALSE
# 271 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 13, METATILE_InsideOfTruck_Chien_Symbol_20, FALSE
# 272 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 13, METATILE_InsideOfTruck_Chien_Symbol_21, FALSE
# 273 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 13, METATILE_InsideOfTruck_Chien_Symbol_22, FALSE
# 274 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 13, METATILE_InsideOfTruck_Chien_Symbol_23, FALSE
# 275 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 13, METATILE_InsideOfTruck_Chien_Symbol_24, FALSE
# 276 "data/maps/SILENT_FOREST/scripts.pory"
	special DrawWholeMapView
	return


# 43 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Symbol_Chien_Pao_Movement_0:
# 43 "data/maps/SILENT_FOREST/scripts.pory"
	emote_exclamation_mark
	step_end

# 56 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_0:
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 62 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_1:
# 62 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 62 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 62 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 62 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 69 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_2:
# 69 "data/maps/SILENT_FOREST/scripts.pory"
	walk_in_place_faster_down
	step_end

# 103 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_3:
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
	step_end

# 105 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_4:
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
	step_end

# 106 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_5:
# 106 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 106 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 106 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 106 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 106 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
	step_end

# 118 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_6:
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	emote_question_mark
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	face_left
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	face_right
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
	step_end

# 136 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_7:
# 136 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 136 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 136 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 161 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_8:
# 161 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 172 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_9:
# 172 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 172 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 172 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 185 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_10:
# 185 "data/maps/SILENT_FOREST/scripts.pory"
	emote_question_mark
	step_end

SilentForest_EventScript_Chien_Pao_Event_Text_0:
# 85 "data/maps/SILENT_FOREST/scripts.pory"
	.string "???\pVocê consegue me ouvir…\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_1:
# 86 "data/maps/SILENT_FOREST/scripts.pory"
	.string "???\pCan you hear me…\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_2:
# 87 "data/maps/SILENT_FOREST/scripts.pory"
	.string "???\p¿Puedes oírme…\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_3:
# 91 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Finalmente…\p...\p...\pMas…\pAinda é cedo demais.\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_4:
# 92 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Finally…\p...\p...\pBut…\pIt's still too early.\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_5:
# 93 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Por fin…\p...\p...\pPero…\pAún es demasiado pronto.\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_6:
# 111 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Você não sabe quem eu sou.\pE eu também não sei quem você é.\nMas este lugar…\pNos permitiu nos encontrar.$"

SilentForest_EventScript_Chien_Pao_Event_Text_7:
# 112 "data/maps/SILENT_FOREST/scripts.pory"
	.string "You don't know who I am.\pAnd I don't know who you are.\nBut this place…\pHas allowed us to meet.$"

SilentForest_EventScript_Chien_Pao_Event_Text_8:
# 113 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No sabes quién soy.\pY yo tampoco sé quién eres.\nPero este lugar…\pNos ha permitido encontrarnos.$"

SilentForest_EventScript_Chien_Pao_Event_Text_9:
# 122 "data/maps/SILENT_FOREST/scripts.pory"
	.string "O tempo…\nEstá se rompendo.\p{PAUSE_UNTIL_PRESS}\pAlgo despertou…\nAntes da hora.$"

SilentForest_EventScript_Chien_Pao_Event_Text_10:
# 123 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Time…\nIs breaking apart.\p{PAUSE_UNTIL_PRESS}\pSomething has awakened…\nBefore its time.$"

SilentForest_EventScript_Chien_Pao_Event_Text_11:
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	.string "El tiempo…\nSe está rompiendo.\p{PAUSE_UNTIL_PRESS}\pAlgo ha despertado…\nAntes de tiempo.$"

SilentForest_EventScript_Chien_Pao_Event_Text_12:
# 130 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Escute com atenção.\nNão tente entender agora.\pQuanto menos você souber…\nMais seguro estará.$"

SilentForest_EventScript_Chien_Pao_Event_Text_13:
# 131 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Listen carefully.\nDon't try to understand now.\pThe less you know…\nThe safer you'll be.$"

SilentForest_EventScript_Chien_Pao_Event_Text_14:
# 132 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Escucha con atención.\nNo intentes comprenderlo ahora.\pCuanto menos sepas…\nMás seguro estarás.$"

SilentForest_EventScript_Chien_Pao_Event_Text_15:
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Quando o momento chegar…\pVocê saberá onde me encontrar.$"

SilentForest_EventScript_Chien_Pao_Event_Text_16:
# 141 "data/maps/SILENT_FOREST/scripts.pory"
	.string "When the time comes…\pYou'll know where to find me.$"

SilentForest_EventScript_Chien_Pao_Event_Text_17:
# 142 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Cuando llegue el momento…\pSabrás dónde encontrarme.$"

SilentForest_EventScript_Chien_Pao_Event_Text_18:
# 165 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Não…\pJá encontraram este lugar…$"

SilentForest_EventScript_Chien_Pao_Event_Text_19:
# 166 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No…\pThey've already found this place…$"

SilentForest_EventScript_Chien_Pao_Event_Text_20:
# 167 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No…\pYa han encontrado este lugar…$"

SilentForest_EventScript_Chien_Pao_Event_Text_21:
# 175 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Não deixe…\pQue eles…$"

SilentForest_EventScript_Chien_Pao_Event_Text_22:
# 176 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Don't let…\pThem…$"

SilentForest_EventScript_Chien_Pao_Event_Text_23:
# 177 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No dejes…\pQue ellos…$"

Set_Chien_Pao_Name_Text_0:
# 209 "data/maps/SILENT_FOREST/scripts.pory"
	.string "???$"
