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
	lockall
# 55 "data/maps/SILENT_FOREST/scripts.pory"
	call Draw_Chien_Symbol
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	pause 60
# 57 "data/maps/SILENT_FOREST/scripts.pory"
	playbgm MUS_RG_SEVII_67, 0
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Chien_Pao_Event_Movement_0
# 59 "data/maps/SILENT_FOREST/scripts.pory"
	pause 50
# 60 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_NOTE_D
# 61 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 62 "data/maps/SILENT_FOREST/scripts.pory"
	pause 35
# 63 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_NOTE_A
# 64 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 65 "data/maps/SILENT_FOREST/scripts.pory"
	pause 50
# 66 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 67 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Symbol_Chien_Pao_Movement_0
# 68 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 69 "data/maps/SILENT_FOREST/scripts.pory"
	pause 40
# 70 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Chien_Pao_Event_Movement_1
# 71 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 72 "data/maps/SILENT_FOREST/scripts.pory"
	call Erase_Chien_Symbol
# 73 "data/maps/SILENT_FOREST/scripts.pory"
	pause 12
# 74 "data/maps/SILENT_FOREST/scripts.pory"
	call Draw_Chien_Symbol
# 75 "data/maps/SILENT_FOREST/scripts.pory"
	pause 12
# 76 "data/maps/SILENT_FOREST/scripts.pory"
	call Erase_Chien_Symbol
# 77 "data/maps/SILENT_FOREST/scripts.pory"
	pause 25
# 78 "data/maps/SILENT_FOREST/scripts.pory"
	call Draw_Chien_Symbol
# 79 "data/maps/SILENT_FOREST/scripts.pory"
	pause 40
# 80 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_SET_SYMBOL_ANIM
# 81 "data/maps/SILENT_FOREST/scripts.pory"
	special DrawWholeMapView
# 82 "data/maps/SILENT_FOREST/scripts.pory"
	pause 50
# 83 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_ORB
# 84 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_RESULT, 2
# 85 "data/maps/SILENT_FOREST/scripts.pory"
	special DoOrbEffect
# 86 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Chien_Pao_Event_Movement_2
# 87 "data/maps/SILENT_FOREST/scripts.pory"
	pause 180
# 88 "data/maps/SILENT_FOREST/scripts.pory"
	special FadeOutOrbEffect
# 89 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_NIGHTMARE
# 90 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 91 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_TO_WHITE
# 92 "data/maps/SILENT_FOREST/scripts.pory"
	fadedefaultbgm
# 93 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8004, 1
# 94 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8005, 1
# 95 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8006, 8
# 96 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8007, 5
# 97 "data/maps/SILENT_FOREST/scripts.pory"
	special ShakeCamera
# 98 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
# 99 "data/maps/SILENT_FOREST/scripts.pory"
	pause 100
# 100 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 101 "data/maps/SILENT_FOREST/scripts.pory"
	pause 80
# 102 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_3
# 104 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_4
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_5
SilentForest_EventScript_Chien_Pao_Event_1:
# 107 "data/maps/SILENT_FOREST/scripts.pory"
	pause 70
# 108 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_NOTE_D
# 109 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 110 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 111 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 112 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_8
# 113 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_9
# 114 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_10
SilentForest_EventScript_Chien_Pao_Event_6:
# 116 "data/maps/SILENT_FOREST/scripts.pory"
	pause 60
# 117 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_SHINY
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CreatePlayerBright
# 119 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 120 "data/maps/SILENT_FOREST/scripts.pory"
	pause 120
# 121 "data/maps/SILENT_FOREST/scripts.pory"
	clearflag FLAG_CHIEN_PAO_SILENT_FOREST
# 122 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_FOREST_CHIEN_PAO
# 123 "data/maps/SILENT_FOREST/scripts.pory"
	special SpawnCameraObject
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	movecamera SilentForest_EventScript_Chien_Pao_Event_Movement_3
# 125 "data/maps/SILENT_FOREST/scripts.pory"
	pause 50
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_CAMERA, SilentForest_EventScript_Chien_Pao_Event_Movement_4
# 127 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_5
# 128 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 129 "data/maps/SILENT_FOREST/scripts.pory"
	special RemoveCameraObject
# 130 "data/maps/SILENT_FOREST/scripts.pory"
	pause 40
# 131 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 132 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 133 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_13
# 134 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_14
# 135 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_15
SilentForest_EventScript_Chien_Pao_Event_11:
# 137 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 138 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 139 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_6
# 141 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 142 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 143 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 144 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_18
# 145 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_19
# 146 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_20
SilentForest_EventScript_Chien_Pao_Event_16:
# 148 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 149 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 150 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 151 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 152 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_23
# 153 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_24
# 154 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_25
SilentForest_EventScript_Chien_Pao_Event_21:
# 156 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 157 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 158 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_7
# 159 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 160 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 161 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 162 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_28
# 163 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_29
# 164 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_30
SilentForest_EventScript_Chien_Pao_Event_26:
# 167 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 168 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_ICE_BREAK
# 169 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 170 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 171 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 172 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Symbol_Chien_Pao_Movement_0
# 173 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 174 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 175 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8004, 1
# 176 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8005, 1
# 177 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8006, 8
# 178 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8007, 5
# 179 "data/maps/SILENT_FOREST/scripts.pory"
	special ShakeCamera
# 180 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
# 181 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_MAGNET_PORTAL_BEHIND
# 182 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_WARP_IN
# 183 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CreateMagnectPortal
# 184 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_8
# 185 "data/maps/SILENT_FOREST/scripts.pory"
	pause 120
# 186 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 187 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 188 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_33
# 189 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_34
# 190 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_35
SilentForest_EventScript_Chien_Pao_Event_31:
# 192 "data/maps/SILENT_FOREST/scripts.pory"
	clearflag FLAG_MAGNET_PORTAL_BEHIND
# 193 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 194 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 195 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_FOREST_CHIEN_PAO, SilentForest_EventScript_Chien_Pao_Event_Movement_9
# 196 "data/maps/SILENT_FOREST/scripts.pory"
	call Set_Chien_Pao_Name
# 197 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 198 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_EventScript_Chien_Pao_Event_38
# 199 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_EventScript_Chien_Pao_Event_39
# 200 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_EventScript_Chien_Pao_Event_40
SilentForest_EventScript_Chien_Pao_Event_36:
# 202 "data/maps/SILENT_FOREST/scripts.pory"
	call HideChien_Pao_Mugshot
# 203 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 204 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_WARP_IN
# 205 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CreateMagnectPortal
# 206 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_FOREST_CHIEN_PAO
# 207 "data/maps/SILENT_FOREST/scripts.pory"
	pause 120
# 208 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 209 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer SilentForest_EventScript_Chien_Pao_Event_Movement_10
# 210 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 211 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 212 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_DING_DONG
# 213 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 214 "data/maps/SILENT_FOREST/scripts.pory"
	call Erase_Chien_Symbol
# 215 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 216 "data/maps/SILENT_FOREST/scripts.pory"
	call Draw_Chien_Symbol
# 217 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 218 "data/maps/SILENT_FOREST/scripts.pory"
	call Erase_Chien_Symbol
# 219 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 220 "data/maps/SILENT_FOREST/scripts.pory"
	call Draw_Chien_Symbol
# 221 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 222 "data/maps/SILENT_FOREST/scripts.pory"
	call Erase_Chien_Symbol
# 223 "data/maps/SILENT_FOREST/scripts.pory"
	pause 150
# 224 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_TO_BLACK
# 225 "data/maps/SILENT_FOREST/scripts.pory"
	pause 100
# 226 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_SILENT_FOREST_STATE, 1
# 227 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 0
# 228 "data/maps/SILENT_FOREST/scripts.pory"
	warpsilent MAP_PINEVEIL_TOWN_MAYS_HOUSE_2F, 7, 6
# 229 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
	return

SilentForest_EventScript_Chien_Pao_Event_3:
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_0
	goto SilentForest_EventScript_Chien_Pao_Event_1

SilentForest_EventScript_Chien_Pao_Event_4:
# 104 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_1
	goto SilentForest_EventScript_Chien_Pao_Event_1

SilentForest_EventScript_Chien_Pao_Event_5:
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_2
	goto SilentForest_EventScript_Chien_Pao_Event_1

SilentForest_EventScript_Chien_Pao_Event_8:
# 112 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_3
	goto SilentForest_EventScript_Chien_Pao_Event_6

SilentForest_EventScript_Chien_Pao_Event_9:
# 113 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_4
	goto SilentForest_EventScript_Chien_Pao_Event_6

SilentForest_EventScript_Chien_Pao_Event_10:
# 114 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_EventScript_Chien_Pao_Event_Text_5
	goto SilentForest_EventScript_Chien_Pao_Event_6

SilentForest_EventScript_Chien_Pao_Event_13:
# 133 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_6, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_11

SilentForest_EventScript_Chien_Pao_Event_14:
# 134 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_7, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_11

SilentForest_EventScript_Chien_Pao_Event_15:
# 135 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_8, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_11

SilentForest_EventScript_Chien_Pao_Event_18:
# 144 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_9, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_16

SilentForest_EventScript_Chien_Pao_Event_19:
# 145 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_10, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_16

SilentForest_EventScript_Chien_Pao_Event_20:
# 146 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_11, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_16

SilentForest_EventScript_Chien_Pao_Event_23:
# 152 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_12, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_21

SilentForest_EventScript_Chien_Pao_Event_24:
# 153 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_13, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_21

SilentForest_EventScript_Chien_Pao_Event_25:
# 154 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_14, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_21

SilentForest_EventScript_Chien_Pao_Event_28:
# 162 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_15, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_26

SilentForest_EventScript_Chien_Pao_Event_29:
# 163 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_16, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_26

SilentForest_EventScript_Chien_Pao_Event_30:
# 164 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_17, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_26

SilentForest_EventScript_Chien_Pao_Event_33:
# 188 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_18, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_31

SilentForest_EventScript_Chien_Pao_Event_34:
# 189 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_19, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_31

SilentForest_EventScript_Chien_Pao_Event_35:
# 190 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_20, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_31

SilentForest_EventScript_Chien_Pao_Event_38:
# 198 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_21, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_36

SilentForest_EventScript_Chien_Pao_Event_39:
# 199 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_22, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_36

SilentForest_EventScript_Chien_Pao_Event_40:
# 200 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_EventScript_Chien_Pao_Event_Text_23, MSGBOX_AUTOCLOSE
	goto SilentForest_EventScript_Chien_Pao_Event_36


Set_Chien_Pao_Name::
# 233 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker Set_Chien_Pao_Name_Text_0
# 234 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_SOUTHEAST
	return


HideChien_Pao_Mugshot::
# 239 "data/maps/SILENT_FOREST/scripts.pory"
	waitmoncry
# 240 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
	return


Erase_Chien_Symbol::
# 245 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 9, 0x206, FALSE
# 246 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 9, 0x206, FALSE
# 247 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 9, 0x206, FALSE
# 248 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 9, 0x206, FALSE
# 249 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 9, 0x206, FALSE
# 250 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 10, 0x206, FALSE
# 251 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 10, 0x206, FALSE
# 252 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 10, 0x206, FALSE
# 253 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 10, 0x206, FALSE
# 254 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 10, 0x206, FALSE
# 255 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 11, 0x206, FALSE
# 256 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 11, 0x206, FALSE
# 257 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 11, 0x206, FALSE
# 258 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 11, 0x206, FALSE
# 259 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 11, 0x206, FALSE
# 260 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 12, 0x206, FALSE
# 261 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 12, 0x206, FALSE
# 262 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 12, 0x206, FALSE
# 263 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 12, 0x206, FALSE
# 264 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 12, 0x206, FALSE
# 265 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 13, 0x206, FALSE
# 266 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 13, 0x206, FALSE
# 267 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 13, 0x206, FALSE
# 268 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 13, 0x206, FALSE
# 269 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 13, 0x206, FALSE
# 270 "data/maps/SILENT_FOREST/scripts.pory"
	special DrawWholeMapView
	return


Draw_Chien_Symbol::
# 275 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 9, METATILE_InsideOfTruck_Chien_Symbol_0, FALSE
# 276 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 9, METATILE_InsideOfTruck_Chien_Symbol_1, FALSE
# 277 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 9, METATILE_InsideOfTruck_Chien_Symbol_2, FALSE
# 278 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 9, METATILE_InsideOfTruck_Chien_Symbol_3, FALSE
# 279 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 9, METATILE_InsideOfTruck_Chien_Symbol_4, FALSE
# 280 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 10, METATILE_InsideOfTruck_Chien_Symbol_5, FALSE
# 281 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 10, METATILE_InsideOfTruck_Chien_Symbol_6, FALSE
# 282 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 10, METATILE_InsideOfTruck_Chien_Symbol_7, FALSE
# 283 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 10, METATILE_InsideOfTruck_Chien_Symbol_8, FALSE
# 284 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 10, METATILE_InsideOfTruck_Chien_Symbol_9, FALSE
# 285 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 11, METATILE_InsideOfTruck_Chien_Symbol_10, FALSE
# 286 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 11, METATILE_InsideOfTruck_Chien_Symbol_11, FALSE
# 287 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 11, METATILE_InsideOfTruck_Chien_Symbol_12, FALSE
# 288 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 11, METATILE_InsideOfTruck_Chien_Symbol_13, FALSE
# 289 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 11, METATILE_InsideOfTruck_Chien_Symbol_14, FALSE
# 290 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 12, METATILE_InsideOfTruck_Chien_Symbol_15, FALSE
# 291 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 12, METATILE_InsideOfTruck_Chien_Symbol_16, FALSE
# 292 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 12, METATILE_InsideOfTruck_Chien_Symbol_17, FALSE
# 293 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 12, METATILE_InsideOfTruck_Chien_Symbol_18, FALSE
# 294 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 12, METATILE_InsideOfTruck_Chien_Symbol_19, FALSE
# 295 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 9, 13, METATILE_InsideOfTruck_Chien_Symbol_20, FALSE
# 296 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 10, 13, METATILE_InsideOfTruck_Chien_Symbol_21, FALSE
# 297 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 11, 13, METATILE_InsideOfTruck_Chien_Symbol_22, FALSE
# 298 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 12, 13, METATILE_InsideOfTruck_Chien_Symbol_23, FALSE
# 299 "data/maps/SILENT_FOREST/scripts.pory"
	setmetatile 13, 13, METATILE_InsideOfTruck_Chien_Symbol_24, FALSE
# 300 "data/maps/SILENT_FOREST/scripts.pory"
	special DrawWholeMapView
	return


# 43 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Symbol_Chien_Pao_Movement_0:
# 43 "data/maps/SILENT_FOREST/scripts.pory"
	emote_exclamation_mark
	step_end

# 58 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_0:
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 70 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_1:
# 70 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 70 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 70 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 70 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 86 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_2:
# 86 "data/maps/SILENT_FOREST/scripts.pory"
	walk_in_place_faster_down
	step_end

# 124 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_3:
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
	step_end

# 126 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_4:
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
	step_end

# 127 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_5:
# 127 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 127 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 127 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 127 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 127 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
	step_end

# 140 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_6:
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	emote_question_mark
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	face_left
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	face_right
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	delay_16
	step_end

# 158 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_7:
# 158 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 158 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 158 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 184 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_8:
# 184 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 195 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_9:
# 195 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 195 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 195 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 209 "data/maps/SILENT_FOREST/scripts.pory"
SilentForest_EventScript_Chien_Pao_Event_Movement_10:
# 209 "data/maps/SILENT_FOREST/scripts.pory"
	emote_question_mark
	step_end

SilentForest_EventScript_Chien_Pao_Event_Text_0:
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\p...\pVocê… consegue me ouvir?\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_1:
# 104 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\p...\pCan you… hear me?\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_2:
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\p...\p¿Puedes… oírme?\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_3:
# 112 "data/maps/SILENT_FOREST/scripts.pory"
	.string "A voz atravessou…\pEntão a fenda já alcançou você.\p...\pNão.\pAinda não deveria estar aqui.\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_4:
# 113 "data/maps/SILENT_FOREST/scripts.pory"
	.string "The voice crossed through…\pThen the rift has already reached\lyou.\p...\pNo.\pYou shouldn't be here yet.\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_5:
# 114 "data/maps/SILENT_FOREST/scripts.pory"
	.string "La voz ha logrado atravesar…\pEntonces la grieta ya te ha\lalcanzado.\p...\pNo.\pAún no deberías estar aquí.\p$"

SilentForest_EventScript_Chien_Pao_Event_Text_6:
# 133 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Não diga seu nome.\pNomes deixam rastros…\nE algo está seguindo o seu.$"

SilentForest_EventScript_Chien_Pao_Event_Text_7:
# 134 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Don't tell me your name.\pNames leave trails…\nAnd something is following yours.$"

SilentForest_EventScript_Chien_Pao_Event_Text_8:
# 135 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No digas tu nombre.\pLos nombres dejan rastros…\nY algo está siguiendo el tuyo.$"

SilentForest_EventScript_Chien_Pao_Event_Text_9:
# 144 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Esta escuridão não está vazia.\pÉ uma lembrança… presa entre dois\ninstantes.\p{PAUSE_UNTIL_PRESS}\pE alguma coisa acabou de se mexer\ndo outro lado.$"

SilentForest_EventScript_Chien_Pao_Event_Text_10:
# 145 "data/maps/SILENT_FOREST/scripts.pory"
	.string "This darkness isn't empty.\pIt's a memory… trapped between two\nmoments.\p{PAUSE_UNTIL_PRESS}\pAnd something just moved on the\nother side.$"

SilentForest_EventScript_Chien_Pao_Event_Text_11:
# 146 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Esta oscuridad no está vacía.\pEs un recuerdo… atrapado entre dos\ninstantes.\p{PAUSE_UNTIL_PRESS}\pY algo acaba de moverse al otro\nlado.$"

SilentForest_EventScript_Chien_Pao_Event_Text_12:
# 152 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Quando ouvir o vento chamar pelo\nseu nome…\pNão responda.\pMesmo que a voz pareça familiar.$"

SilentForest_EventScript_Chien_Pao_Event_Text_13:
# 153 "data/maps/SILENT_FOREST/scripts.pory"
	.string "When you hear the wind call your\nname…\pDon't answer.\pEven if the voice sounds familiar.$"

SilentForest_EventScript_Chien_Pao_Event_Text_14:
# 154 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Cuando oigas al viento pronunciar\ntu nombre…\pNo respondas.\pAunque la voz te resulte familiar.$"

SilentForest_EventScript_Chien_Pao_Event_Text_15:
# 162 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Se nos encontrarmos novamente…\pTalvez eu possa contar o que você\nesqueceu.$"

SilentForest_EventScript_Chien_Pao_Event_Text_16:
# 163 "data/maps/SILENT_FOREST/scripts.pory"
	.string "If we meet again…\pPerhaps I can tell you what you\nforgot.$"

SilentForest_EventScript_Chien_Pao_Event_Text_17:
# 164 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Si volvemos a encontrarnos…\pQuizá pueda contarte lo que has\nolvidado.$"

SilentForest_EventScript_Chien_Pao_Event_Text_18:
# 188 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Não…\pJá encontraram este lugar…$"

SilentForest_EventScript_Chien_Pao_Event_Text_19:
# 189 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No…\pThey've already found this place…$"

SilentForest_EventScript_Chien_Pao_Event_Text_20:
# 190 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No…\pYa han encontrado este lugar…$"

SilentForest_EventScript_Chien_Pao_Event_Text_21:
# 198 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Não deixe que eles encontrem a…$"

SilentForest_EventScript_Chien_Pao_Event_Text_22:
# 199 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Don't let them find the…$"

SilentForest_EventScript_Chien_Pao_Event_Text_23:
# 200 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No dejes que encuentren la…$"

Set_Chien_Pao_Name_Text_0:
# 233 "data/maps/SILENT_FOREST/scripts.pory"
	.string "???$"
