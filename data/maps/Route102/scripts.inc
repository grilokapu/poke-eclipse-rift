Route102_MapScripts::
	.byte 0


Route2_EventScript_Lass_Battle::
# 6 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 7 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Lass_Battle_3
# 10 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Lass_Battle_4
# 13 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Lass_Battle_5
Route2_EventScript_Lass_Battle_1:
# 17 "data/maps/Route102/scripts.pory"
	release
	end

Route2_EventScript_Lass_Battle_3:
# 8 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_LASS_MARIANA, Route2_EventScript_Lass_Battle_Text_0, Route2_EventScript_Lass_Battle_Text_1
# 9 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Lass_Battle_Text_2
	goto Route2_EventScript_Lass_Battle_1

Route2_EventScript_Lass_Battle_4:
# 11 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_LASS_MARIANA, Route2_EventScript_Lass_Battle_Text_3, Route2_EventScript_Lass_Battle_Text_4
# 12 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Lass_Battle_Text_5
	goto Route2_EventScript_Lass_Battle_1

Route2_EventScript_Lass_Battle_5:
# 14 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_LASS_MARIANA, Route2_EventScript_Lass_Battle_Text_6, Route2_EventScript_Lass_Battle_Text_7
# 15 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Lass_Battle_Text_8
	goto Route2_EventScript_Lass_Battle_1


Route2_EventScript_Meeting_Giovanni::
# 25 "data/maps/Route102/scripts.pory"
	lockall
# 26 "data/maps/Route102/scripts.pory"
	moveplayer Common_Movement_FaceLeft
# 27 "data/maps/Route102/scripts.pory"
	special SpawnCameraObject
# 28 "data/maps/Route102/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 29 "data/maps/Route102/scripts.pory"
	compare VAR_0x8005, 13
	goto_if_eq Route2_EventScript_Meeting_Giovanni_2
# 32 "data/maps/Route102/scripts.pory"
	movecamera Route2_EventScript_Meeting_Giovanni_Movement_1
Route2_EventScript_Meeting_Giovanni_1:
# 34 "data/maps/Route102/scripts.pory"
	special RemoveCameraObject
# 35 "data/maps/Route102/scripts.pory"
	pause 30
# 36 "data/maps/Route102/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 37 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_MEOWTH, Route2_EventScript_Meeting_Giovanni_Movement_2
# 38 "data/maps/Route102/scripts.pory"
	playse SE_EFFECTIVE
# 39 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 40 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_7
# 41 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_8
# 42 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_9
Route2_EventScript_Meeting_Giovanni_5:
# 44 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_MEOWTH, Route2_EventScript_Meeting_Giovanni_Movement_3
# 45 "data/maps/Route102/scripts.pory"
	waitmessage
# 46 "data/maps/Route102/scripts.pory"
	closemessage
# 47 "data/maps/Route102/scripts.pory"
	pause 20
# 48 "data/maps/Route102/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, 0
# 49 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_NIDORAN, Route2_EventScript_Meeting_Giovanni_Movement_4
# 50 "data/maps/Route102/scripts.pory"
	playse SE_EFFECTIVE
# 51 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 52 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_12
# 53 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_13
# 54 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_14
Route2_EventScript_Meeting_Giovanni_10:
# 56 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_NIDORAN, Route2_EventScript_Meeting_Giovanni_Movement_5
# 57 "data/maps/Route102/scripts.pory"
	waitmessage
# 58 "data/maps/Route102/scripts.pory"
	closemessage
# 59 "data/maps/Route102/scripts.pory"
	pause 20
# 60 "data/maps/Route102/scripts.pory"
	applymovement LOCALID_ROUTE2_MEOWTH, Route2_EventScript_Meeting_Giovanni_Movement_6
# 61 "data/maps/Route102/scripts.pory"
	applymovement LOCALID_ROUTE2_NIDORAN, Route2_EventScript_Meeting_Giovanni_Movement_7
# 62 "data/maps/Route102/scripts.pory"
	waitmovementall
# 63 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_MEOWTH, Route2_EventScript_Meeting_Giovanni_Movement_8
# 64 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_NIDORAN, Route2_EventScript_Meeting_Giovanni_Movement_9
# 65 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_MEOWTH, Route2_EventScript_Meeting_Giovanni_Movement_10
# 66 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_NIDORAN, Route2_EventScript_Meeting_Giovanni_Movement_11
# 67 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 68 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_17
# 69 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_18
# 70 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_19
Route2_EventScript_Meeting_Giovanni_15:
# 72 "data/maps/Route102/scripts.pory"
	special SpawnCameraObject
# 73 "data/maps/Route102/scripts.pory"
	movecamera Route2_EventScript_Meeting_Giovanni_Movement_12
# 74 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Movement_13
# 75 "data/maps/Route102/scripts.pory"
	special RemoveCameraObject
# 76 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 77 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_22
# 78 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_23
# 79 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_24
Route2_EventScript_Meeting_Giovanni_20:
# 81 "data/maps/Route102/scripts.pory"
	pause 20
# 82 "data/maps/Route102/scripts.pory"
	showmonmugshot SPECIES_NIDORAN_M, MUGSHOT_SOUTHEAST
# 83 "data/maps/Route102/scripts.pory"
	setspeaker Route2_EventScript_Meeting_Giovanni_Text_13
# 84 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Meeting_Giovanni_Text_14, MSGBOX_AUTOCLOSE
# 85 "data/maps/Route102/scripts.pory"
	waitmoncry
# 86 "data/maps/Route102/scripts.pory"
	hidemonmugshot
# 87 "data/maps/Route102/scripts.pory"
	pause 20
# 88 "data/maps/Route102/scripts.pory"
	special SpawnCameraObject
# 89 "data/maps/Route102/scripts.pory"
	movecamera Route2_EventScript_Meeting_Giovanni_Movement_7
# 90 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Movement_14
# 91 "data/maps/Route102/scripts.pory"
	special RemoveCameraObject
# 92 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 93 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_27
# 94 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_28
# 95 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_29
Route2_EventScript_Meeting_Giovanni_25:
# 97 "data/maps/Route102/scripts.pory"
	pause 20
# 98 "data/maps/Route102/scripts.pory"
	showmonmugshot SPECIES_MEOWTH, MUGSHOT_SOUTHEAST
# 99 "data/maps/Route102/scripts.pory"
	setspeaker Route2_EventScript_Meeting_Giovanni_Text_18
# 100 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Meeting_Giovanni_Text_19, MSGBOX_AUTOCLOSE
# 101 "data/maps/Route102/scripts.pory"
	waitmoncry
# 102 "data/maps/Route102/scripts.pory"
	hidemonmugshot
# 103 "data/maps/Route102/scripts.pory"
	pause 20
# 104 "data/maps/Route102/scripts.pory"
	special SpawnCameraObject
# 105 "data/maps/Route102/scripts.pory"
	compare VAR_0x8005, 13
	goto_if_eq Route2_EventScript_Meeting_Giovanni_31
# 108 "data/maps/Route102/scripts.pory"
	movecamera Route2_EventScript_Meeting_Giovanni_Movement_16
Route2_EventScript_Meeting_Giovanni_30:
# 110 "data/maps/Route102/scripts.pory"
	special RemoveCameraObject
# 111 "data/maps/Route102/scripts.pory"
	goto Route2_EventScript_Meeting_Giovanni_Continue
	return

Route2_EventScript_Meeting_Giovanni_2:
# 30 "data/maps/Route102/scripts.pory"
	movecamera Route2_EventScript_Meeting_Giovanni_Movement_0
	goto Route2_EventScript_Meeting_Giovanni_1

Route2_EventScript_Meeting_Giovanni_7:
# 40 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Meeting_Giovanni_Text_0
	goto Route2_EventScript_Meeting_Giovanni_5

Route2_EventScript_Meeting_Giovanni_8:
# 41 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Meeting_Giovanni_Text_1
	goto Route2_EventScript_Meeting_Giovanni_5

Route2_EventScript_Meeting_Giovanni_9:
# 42 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Meeting_Giovanni_Text_2
	goto Route2_EventScript_Meeting_Giovanni_5

Route2_EventScript_Meeting_Giovanni_12:
# 52 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Meeting_Giovanni_Text_3
	goto Route2_EventScript_Meeting_Giovanni_10

Route2_EventScript_Meeting_Giovanni_13:
# 53 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Meeting_Giovanni_Text_4
	goto Route2_EventScript_Meeting_Giovanni_10

Route2_EventScript_Meeting_Giovanni_14:
# 54 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Meeting_Giovanni_Text_5
	goto Route2_EventScript_Meeting_Giovanni_10

Route2_EventScript_Meeting_Giovanni_17:
# 68 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Text_7, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_15

Route2_EventScript_Meeting_Giovanni_18:
# 69 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Text_8, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_15

Route2_EventScript_Meeting_Giovanni_19:
# 70 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Text_9, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_15

Route2_EventScript_Meeting_Giovanni_22:
# 77 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Text_10, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_20

Route2_EventScript_Meeting_Giovanni_23:
# 78 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Text_11, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_20

Route2_EventScript_Meeting_Giovanni_24:
# 79 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Text_12, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_20

Route2_EventScript_Meeting_Giovanni_27:
# 93 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Text_15, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_25

Route2_EventScript_Meeting_Giovanni_28:
# 94 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Text_16, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_25

Route2_EventScript_Meeting_Giovanni_29:
# 95 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Text_17, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_25

Route2_EventScript_Meeting_Giovanni_31:
# 106 "data/maps/Route102/scripts.pory"
	movecamera Route2_EventScript_Meeting_Giovanni_Movement_15
	goto Route2_EventScript_Meeting_Giovanni_30


Route2_EventScript_Meeting_Giovanni_Continue::
# 117 "data/maps/Route102/scripts.pory"
	compare VAR_0x8005, 13
	goto_if_eq Route2_EventScript_Meeting_Giovanni_Continue_2
# 120 "data/maps/Route102/scripts.pory"
	moveplayer Route2_EventScript_Meeting_Giovanni_Continue_Movement_1
Route2_EventScript_Meeting_Giovanni_Continue_1:
# 122 "data/maps/Route102/scripts.pory"
	pause 20
# 123 "data/maps/Route102/scripts.pory"
	playse SE_PIN
# 124 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Continue_Movement_2
# 125 "data/maps/Route102/scripts.pory"
	waitse
# 126 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 127 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_Continue_7
# 128 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_Continue_8
# 129 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_Continue_9
Route2_EventScript_Meeting_Giovanni_Continue_5:
# 131 "data/maps/Route102/scripts.pory"
	pause 30
# 132 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Continue_Movement_3
# 133 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 134 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_Continue_12
# 135 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_Continue_13
# 136 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_Continue_14
Route2_EventScript_Meeting_Giovanni_Continue_10:
# 138 "data/maps/Route102/scripts.pory"
	pause 20
# 139 "data/maps/Route102/scripts.pory"
	playse SE_PIN
# 140 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Continue_Movement_4
# 141 "data/maps/Route102/scripts.pory"
	waitse
# 142 "data/maps/Route102/scripts.pory"
	pause 20
# 143 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 144 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_Continue_17
# 145 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_Continue_18
# 146 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_Continue_19
Route2_EventScript_Meeting_Giovanni_Continue_15:
# 148 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_NIDORAN, Route2_EventScript_Meeting_Giovanni_Continue_Movement_5
# 149 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_MEOWTH, Route2_EventScript_Meeting_Giovanni_Continue_Movement_5
# 150 "data/maps/Route102/scripts.pory"
	removeobject LOCALID_ROUTE2_NIDORAN
# 151 "data/maps/Route102/scripts.pory"
	removeobject LOCALID_ROUTE2_MEOWTH
# 152 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Continue_Movement_6
# 153 "data/maps/Route102/scripts.pory"
	moveplayer Route2_EventScript_Meeting_Giovanni_Continue_Movement_7
# 154 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 155 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_Continue_22
# 156 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_Continue_23
# 157 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_Continue_24
Route2_EventScript_Meeting_Giovanni_Continue_20:
# 159 "data/maps/Route102/scripts.pory"
	pause 10
# 160 "data/maps/Route102/scripts.pory"
	addobject LOCALID_ROUTE2_MEOWTH
# 161 "data/maps/Route102/scripts.pory"
	setobjectxy LOCALID_ROUTE2_MEOWTH, 25, 12
# 162 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_MEOWTH, Route2_EventScript_Meeting_Giovanni_Continue_Movement_8
# 163 "data/maps/Route102/scripts.pory"
	callnative GetFirstPartyMonGraphicsId
# 164 "data/maps/Route102/scripts.pory"
	createspobject VAR_0x8000, 11, 25, 13, MOVEMENT_TYPE_FACE_UP
# 165 "data/maps/Route102/scripts.pory"
	goto Route2_EventScript_Meeting_Giovanni_Battle
	return

Route2_EventScript_Meeting_Giovanni_Continue_2:
# 118 "data/maps/Route102/scripts.pory"
	moveplayer Route2_EventScript_Meeting_Giovanni_Continue_Movement_0
	goto Route2_EventScript_Meeting_Giovanni_Continue_1

Route2_EventScript_Meeting_Giovanni_Continue_7:
# 127 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_0, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_5

Route2_EventScript_Meeting_Giovanni_Continue_8:
# 128 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_1, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_5

Route2_EventScript_Meeting_Giovanni_Continue_9:
# 129 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_2, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_5

Route2_EventScript_Meeting_Giovanni_Continue_12:
# 134 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_3, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_10

Route2_EventScript_Meeting_Giovanni_Continue_13:
# 135 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_4, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_10

Route2_EventScript_Meeting_Giovanni_Continue_14:
# 136 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_5, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_10

Route2_EventScript_Meeting_Giovanni_Continue_17:
# 144 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_6, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_15

Route2_EventScript_Meeting_Giovanni_Continue_18:
# 145 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_7, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_15

Route2_EventScript_Meeting_Giovanni_Continue_19:
# 146 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_8, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_15

Route2_EventScript_Meeting_Giovanni_Continue_22:
# 155 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_9, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_20

Route2_EventScript_Meeting_Giovanni_Continue_23:
# 156 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_10, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_20

Route2_EventScript_Meeting_Giovanni_Continue_24:
# 157 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_Continue_Text_11, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_Continue_20


Route2_EventScript_Meeting_Giovanni_Battle::
# 170 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 171 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_Battle_3
# 172 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_Battle_4
# 173 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_Battle_5
Route2_EventScript_Meeting_Giovanni_Battle_1:
# 175 "data/maps/Route102/scripts.pory"
	release
	end

Route2_EventScript_Meeting_Giovanni_Battle_3:
# 171 "data/maps/Route102/scripts.pory"
	trainerbattle_continue_lost TRAINER_ROUTE2_YOUNG_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Battle_Text_0, Route2_EventScript_Meeting_Giovanni_Battle_Text_1, Route2_EventScript_Meeting_Giovanni_End
	goto Route2_EventScript_Meeting_Giovanni_Battle_1

Route2_EventScript_Meeting_Giovanni_Battle_4:
# 172 "data/maps/Route102/scripts.pory"
	trainerbattle_continue_lost TRAINER_ROUTE2_YOUNG_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Battle_Text_2, Route2_EventScript_Meeting_Giovanni_Battle_Text_3, Route2_EventScript_Meeting_Giovanni_End
	goto Route2_EventScript_Meeting_Giovanni_Battle_1

Route2_EventScript_Meeting_Giovanni_Battle_5:
# 173 "data/maps/Route102/scripts.pory"
	trainerbattle_continue_lost TRAINER_ROUTE2_YOUNG_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Battle_Text_4, Route2_EventScript_Meeting_Giovanni_Battle_Text_5, Route2_EventScript_Meeting_Giovanni_End
	goto Route2_EventScript_Meeting_Giovanni_Battle_1


Route2_EventScript_Meeting_Giovanni_End::
# 180 "data/maps/Route102/scripts.pory"
	applymovement LOCALID_ROUTE2_MEOWTH, Route2_EventScript_Meeting_Giovanni_Continue_Movement_5
# 181 "data/maps/Route102/scripts.pory"
	applymovement 11, Route2_EventScript_Meeting_Giovanni_Continue_Movement_5
# 182 "data/maps/Route102/scripts.pory"
	waitmovementall
# 183 "data/maps/Route102/scripts.pory"
	removeobject LOCALID_ROUTE2_MEOWTH
# 184 "data/maps/Route102/scripts.pory"
	removeobject 11
# 185 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 186 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_End_3
# 187 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_End_4
# 188 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_End_5
Route2_EventScript_Meeting_Giovanni_End_1:
# 190 "data/maps/Route102/scripts.pory"
	applymovement LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Movement_14
# 191 "data/maps/Route102/scripts.pory"
	applymovement LOCALID_PLAYER, Route2_EventScript_Meeting_Giovanni_End_Movement_0
# 192 "data/maps/Route102/scripts.pory"
	waitmovementall
# 193 "data/maps/Route102/scripts.pory"
	pause 20
# 194 "data/maps/Route102/scripts.pory"
	playse SE_PIN
# 195 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_End_Movement_1
# 196 "data/maps/Route102/scripts.pory"
	waitse
# 197 "data/maps/Route102/scripts.pory"
	pause 20
# 198 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 199 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_End_8
# 200 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_End_9
# 201 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_End_10
Route2_EventScript_Meeting_Giovanni_End_6:
# 203 "data/maps/Route102/scripts.pory"
	pause 20
# 204 "data/maps/Route102/scripts.pory"
	playse SE_PIN
# 205 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_PLAYER, Route2_EventScript_Meeting_Giovanni_End_Movement_2
# 206 "data/maps/Route102/scripts.pory"
	waitse
# 207 "data/maps/Route102/scripts.pory"
	pause 20
# 208 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 209 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_End_13
# 210 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_End_14
# 211 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_End_15
Route2_EventScript_Meeting_Giovanni_End_11:
# 213 "data/maps/Route102/scripts.pory"
	setemoji LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_End_Movement_3
# 214 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 215 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_End_18
# 216 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_End_19
# 217 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_End_20
Route2_EventScript_Meeting_Giovanni_End_16:
# 219 "data/maps/Route102/scripts.pory"
	pause 30
# 220 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 221 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Meeting_Giovanni_End_23
# 222 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Meeting_Giovanni_End_24
# 223 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Meeting_Giovanni_End_25
Route2_EventScript_Meeting_Giovanni_End_21:
# 225 "data/maps/Route102/scripts.pory"
	movenpc LOCALID_ROUTE2_GIOVANNI, Route2_EventScript_Meeting_Giovanni_End_Movement_4
# 226 "data/maps/Route102/scripts.pory"
	setflag FLAG_ROUTE2_GIOVANNI
# 227 "data/maps/Route102/scripts.pory"
	setvar VAR_ROUTE2_MEETING_GIOVANNI_STATE, 1
# 228 "data/maps/Route102/scripts.pory"
	release
	end

Route2_EventScript_Meeting_Giovanni_End_3:
# 186 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_0, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_1

Route2_EventScript_Meeting_Giovanni_End_4:
# 187 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_1, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_1

Route2_EventScript_Meeting_Giovanni_End_5:
# 188 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_2, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_1

Route2_EventScript_Meeting_Giovanni_End_8:
# 199 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_3, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_6

Route2_EventScript_Meeting_Giovanni_End_9:
# 200 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_4, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_6

Route2_EventScript_Meeting_Giovanni_End_10:
# 201 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_5, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_6

Route2_EventScript_Meeting_Giovanni_End_13:
# 209 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_6, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_11

Route2_EventScript_Meeting_Giovanni_End_14:
# 210 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_7, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_11

Route2_EventScript_Meeting_Giovanni_End_15:
# 211 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_8, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_11

Route2_EventScript_Meeting_Giovanni_End_18:
# 215 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_9, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_16

Route2_EventScript_Meeting_Giovanni_End_19:
# 216 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_10, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_16

Route2_EventScript_Meeting_Giovanni_End_20:
# 217 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_11, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_16

Route2_EventScript_Meeting_Giovanni_End_23:
# 221 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_12, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_21

Route2_EventScript_Meeting_Giovanni_End_24:
# 222 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_13, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_21

Route2_EventScript_Meeting_Giovanni_End_25:
# 223 "data/maps/Route102/scripts.pory"
	msgminibox PSS_ICON_GIOVANNI, Route2_EventScript_Meeting_Giovanni_Text_6, Route2_EventScript_Meeting_Giovanni_End_Text_14, MSGBOX_AUTOCLOSE
	goto Route2_EventScript_Meeting_Giovanni_End_21


Route2_EventScript_Potion_Get::
# 233 "data/maps/Route102/scripts.pory"
	finditem ITEM_POTION, 1
	end


Route2_EventScript_ScapeRope_Get::
# 238 "data/maps/Route102/scripts.pory"
	finditem ITEM_ESCAPE_ROPE
	end


Route2_EventScript_Youngster_Battle::
# 243 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 244 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Youngster_Battle_3
# 247 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Youngster_Battle_4
# 250 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Youngster_Battle_5
Route2_EventScript_Youngster_Battle_1:
# 254 "data/maps/Route102/scripts.pory"
	release
	end

Route2_EventScript_Youngster_Battle_3:
# 245 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_ROBERTO, Route2_EventScript_Youngster_Battle_Text_0, Route2_EventScript_Youngster_Battle_Text_1
# 246 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Youngster_Battle_Text_2
	goto Route2_EventScript_Youngster_Battle_1

Route2_EventScript_Youngster_Battle_4:
# 248 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_ROBERTO, Route2_EventScript_Youngster_Battle_Text_3, Route2_EventScript_Youngster_Battle_Text_4
# 249 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Youngster_Battle_Text_5
	goto Route2_EventScript_Youngster_Battle_1

Route2_EventScript_Youngster_Battle_5:
# 251 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_ROBERTO, Route2_EventScript_Youngster_Battle_Text_6, Route2_EventScript_Youngster_Battle_Text_7
# 252 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Youngster_Battle_Text_8
	goto Route2_EventScript_Youngster_Battle_1


Route2_EventScript_FatGuy_Talk::
# 259 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 260 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_FatGuy_Talk_3
# 261 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_FatGuy_Talk_4
# 262 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_FatGuy_Talk_5
Route2_EventScript_FatGuy_Talk_1:
	end

Route2_EventScript_FatGuy_Talk_3:
# 260 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_FatGuy_Talk_Text_0, MSGBOX_NPC
	goto Route2_EventScript_FatGuy_Talk_1

Route2_EventScript_FatGuy_Talk_4:
# 261 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_FatGuy_Talk_Text_1, MSGBOX_NPC
	goto Route2_EventScript_FatGuy_Talk_1

Route2_EventScript_FatGuy_Talk_5:
# 262 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_FatGuy_Talk_Text_2, MSGBOX_NPC
	goto Route2_EventScript_FatGuy_Talk_1


Route2_EventScript_BugCatcher_Battle::
# 268 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 269 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_BugCatcher_Battle_3
# 272 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_BugCatcher_Battle_4
# 275 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_BugCatcher_Battle_5
Route2_EventScript_BugCatcher_Battle_1:
# 279 "data/maps/Route102/scripts.pory"
	release
	end

Route2_EventScript_BugCatcher_Battle_3:
# 270 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_DECLAN, Route2_EventScript_BugCatcher_Battle_Text_0, Route2_EventScript_BugCatcher_Battle_Text_1
# 271 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_BugCatcher_Battle_Text_2
	goto Route2_EventScript_BugCatcher_Battle_1

Route2_EventScript_BugCatcher_Battle_4:
# 273 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_DECLAN, Route2_EventScript_BugCatcher_Battle_Text_3, Route2_EventScript_BugCatcher_Battle_Text_4
# 274 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_BugCatcher_Battle_Text_5
	goto Route2_EventScript_BugCatcher_Battle_1

Route2_EventScript_BugCatcher_Battle_5:
# 276 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_DECLAN, Route2_EventScript_BugCatcher_Battle_Text_6, Route2_EventScript_BugCatcher_Battle_Text_7
# 277 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_BugCatcher_Battle_Text_8
	goto Route2_EventScript_BugCatcher_Battle_1


Route2_EventScript_NestBall_Get::
# 284 "data/maps/Route102/scripts.pory"
	finditem ITEM_NEST_BALL
	end


Route2_EventScript_Sign::
# 289 "data/maps/Route102/scripts.pory"
	switch VAR_LANGUAGE
# 290 "data/maps/Route102/scripts.pory"
	case PT, Route2_EventScript_Sign_3
# 291 "data/maps/Route102/scripts.pory"
	case EN, Route2_EventScript_Sign_4
# 292 "data/maps/Route102/scripts.pory"
	case ES, Route2_EventScript_Sign_5
Route2_EventScript_Sign_1:
	end

Route2_EventScript_Sign_3:
# 290 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Sign_Text_0, MSGBOX_SIGN
	goto Route2_EventScript_Sign_1

Route2_EventScript_Sign_4:
# 291 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Sign_Text_1, MSGBOX_SIGN
	goto Route2_EventScript_Sign_1

Route2_EventScript_Sign_5:
# 292 "data/maps/Route102/scripts.pory"
	msgbox Route2_EventScript_Sign_Text_2, MSGBOX_SIGN
	goto Route2_EventScript_Sign_1


# 30 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_0:
# 30 "data/maps/Route102/scripts.pory"
	walk_left
# 30 "data/maps/Route102/scripts.pory"
	walk_left
# 30 "data/maps/Route102/scripts.pory"
	walk_left
# 30 "data/maps/Route102/scripts.pory"
	walk_left
# 30 "data/maps/Route102/scripts.pory"
	walk_left
# 30 "data/maps/Route102/scripts.pory"
	walk_left
# 30 "data/maps/Route102/scripts.pory"
	walk_left
# 30 "data/maps/Route102/scripts.pory"
	walk_up
	step_end

# 32 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_1:
# 32 "data/maps/Route102/scripts.pory"
	walk_left
# 32 "data/maps/Route102/scripts.pory"
	walk_left
# 32 "data/maps/Route102/scripts.pory"
	walk_left
# 32 "data/maps/Route102/scripts.pory"
	walk_left
# 32 "data/maps/Route102/scripts.pory"
	walk_left
# 32 "data/maps/Route102/scripts.pory"
	walk_left
# 32 "data/maps/Route102/scripts.pory"
	walk_left
# 32 "data/maps/Route102/scripts.pory"
	walk_up
# 32 "data/maps/Route102/scripts.pory"
	walk_up
	step_end

# 37 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_2:
# 37 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 37 "data/maps/Route102/scripts.pory"
	walk_fast_up
# 37 "data/maps/Route102/scripts.pory"
	jump_up
	step_end

# 44 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_3:
# 44 "data/maps/Route102/scripts.pory"
	walk_faster_down_backwards
# 44 "data/maps/Route102/scripts.pory"
	walk_faster_down_backwards
# 44 "data/maps/Route102/scripts.pory"
	walk_faster_down_backwards
	step_end

# 49 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_4:
# 49 "data/maps/Route102/scripts.pory"
	walk_fast_down
# 49 "data/maps/Route102/scripts.pory"
	walk_fast_down
# 49 "data/maps/Route102/scripts.pory"
	jump_down
	step_end

# 56 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_5:
# 56 "data/maps/Route102/scripts.pory"
	walk_faster_up_backwards
# 56 "data/maps/Route102/scripts.pory"
	walk_faster_up_backwards
# 56 "data/maps/Route102/scripts.pory"
	walk_faster_up_backwards
	step_end

# 60 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_6:
# 60 "data/maps/Route102/scripts.pory"
	walk_up
	step_end

# 61 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_7:
# 61 "data/maps/Route102/scripts.pory"
	walk_down
	step_end

# 63 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_8:
# 63 "data/maps/Route102/scripts.pory"
	jump_up
# 63 "data/maps/Route102/scripts.pory"
	jump_down_backwards
	step_end

# 64 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_9:
# 64 "data/maps/Route102/scripts.pory"
	jump_down
# 64 "data/maps/Route102/scripts.pory"
	jump_up_backwards
	step_end

# 65 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_10:
# 65 "data/maps/Route102/scripts.pory"
	jump_up
# 65 "data/maps/Route102/scripts.pory"
	jump_down_backwards
# 65 "data/maps/Route102/scripts.pory"
	walk_faster_down_backwards
	step_end

# 66 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_11:
# 66 "data/maps/Route102/scripts.pory"
	jump_down
# 66 "data/maps/Route102/scripts.pory"
	jump_up_backwards
# 66 "data/maps/Route102/scripts.pory"
	walk_faster_up_backwards
	step_end

# 73 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_12:
# 73 "data/maps/Route102/scripts.pory"
	walk_left
# 73 "data/maps/Route102/scripts.pory"
	walk_left
	step_end

# 74 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_13:
# 74 "data/maps/Route102/scripts.pory"
	walk_left
# 74 "data/maps/Route102/scripts.pory"
	walk_left
# 74 "data/maps/Route102/scripts.pory"
	face_up
	step_end

# 90 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_14:
# 90 "data/maps/Route102/scripts.pory"
	walk_down
# 90 "data/maps/Route102/scripts.pory"
	face_down
	step_end

# 106 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_15:
# 106 "data/maps/Route102/scripts.pory"
	walk_right
# 106 "data/maps/Route102/scripts.pory"
	walk_right
# 106 "data/maps/Route102/scripts.pory"
	walk_right
# 106 "data/maps/Route102/scripts.pory"
	walk_right
# 106 "data/maps/Route102/scripts.pory"
	walk_right
# 106 "data/maps/Route102/scripts.pory"
	walk_right
# 106 "data/maps/Route102/scripts.pory"
	walk_right
# 106 "data/maps/Route102/scripts.pory"
	walk_right
# 106 "data/maps/Route102/scripts.pory"
	walk_right
	step_end

# 108 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Movement_16:
# 108 "data/maps/Route102/scripts.pory"
	walk_right
# 108 "data/maps/Route102/scripts.pory"
	walk_right
# 108 "data/maps/Route102/scripts.pory"
	walk_right
# 108 "data/maps/Route102/scripts.pory"
	walk_right
# 108 "data/maps/Route102/scripts.pory"
	walk_right
# 108 "data/maps/Route102/scripts.pory"
	walk_right
# 108 "data/maps/Route102/scripts.pory"
	walk_right
# 108 "data/maps/Route102/scripts.pory"
	walk_right
# 108 "data/maps/Route102/scripts.pory"
	walk_right
# 108 "data/maps/Route102/scripts.pory"
	walk_down
	step_end

# 118 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Continue_Movement_0:
# 118 "data/maps/Route102/scripts.pory"
	walk_left
# 118 "data/maps/Route102/scripts.pory"
	walk_left
# 118 "data/maps/Route102/scripts.pory"
	walk_down
# 118 "data/maps/Route102/scripts.pory"
	walk_left
# 118 "data/maps/Route102/scripts.pory"
	walk_left
# 118 "data/maps/Route102/scripts.pory"
	walk_left
# 118 "data/maps/Route102/scripts.pory"
	walk_left
# 118 "data/maps/Route102/scripts.pory"
	walk_left
# 118 "data/maps/Route102/scripts.pory"
	walk_up
# 118 "data/maps/Route102/scripts.pory"
	face_left
	step_end

# 120 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Continue_Movement_1:
# 120 "data/maps/Route102/scripts.pory"
	walk_left
# 120 "data/maps/Route102/scripts.pory"
	walk_left
# 120 "data/maps/Route102/scripts.pory"
	walk_left
# 120 "data/maps/Route102/scripts.pory"
	walk_left
# 120 "data/maps/Route102/scripts.pory"
	walk_left
# 120 "data/maps/Route102/scripts.pory"
	walk_left
# 120 "data/maps/Route102/scripts.pory"
	walk_left
# 120 "data/maps/Route102/scripts.pory"
	walk_up
# 120 "data/maps/Route102/scripts.pory"
	face_left
	step_end

# 124 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Continue_Movement_2:
# 124 "data/maps/Route102/scripts.pory"
	emote_exclamation_mark
# 124 "data/maps/Route102/scripts.pory"
	face_right
	step_end

# 132 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Continue_Movement_3:
# 132 "data/maps/Route102/scripts.pory"
	walk_right
# 132 "data/maps/Route102/scripts.pory"
	face_right
	step_end

# 140 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Continue_Movement_4:
# 140 "data/maps/Route102/scripts.pory"
	emoji_confident_smiling
	step_end

# 148 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Continue_Movement_5:
# 148 "data/maps/Route102/scripts.pory"
	enter_pokeball
	step_end

# 152 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Continue_Movement_6:
# 152 "data/maps/Route102/scripts.pory"
	walk_left
# 152 "data/maps/Route102/scripts.pory"
	walk_up
# 152 "data/maps/Route102/scripts.pory"
	walk_up
# 152 "data/maps/Route102/scripts.pory"
	face_down
	step_end

# 153 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Continue_Movement_7:
# 153 "data/maps/Route102/scripts.pory"
	walk_left
# 153 "data/maps/Route102/scripts.pory"
	walk_left
# 153 "data/maps/Route102/scripts.pory"
	walk_down
# 153 "data/maps/Route102/scripts.pory"
	face_up
	step_end

# 162 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_Continue_Movement_8:
# 162 "data/maps/Route102/scripts.pory"
	exit_pokeball
# 162 "data/maps/Route102/scripts.pory"
	face_down
	step_end

# 191 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_End_Movement_0:
# 191 "data/maps/Route102/scripts.pory"
	walk_up
# 191 "data/maps/Route102/scripts.pory"
	face_up
	step_end

# 195 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_End_Movement_1:
# 195 "data/maps/Route102/scripts.pory"
	emoji_confiant
	step_end

# 205 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_End_Movement_2:
# 205 "data/maps/Route102/scripts.pory"
	emoji_wink
	step_end

# 213 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_End_Movement_3:
# 213 "data/maps/Route102/scripts.pory"
	emoji_confident
	step_end

# 225 "data/maps/Route102/scripts.pory"
Route2_EventScript_Meeting_Giovanni_End_Movement_4:
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
# 225 "data/maps/Route102/scripts.pory"
	walk_left
	step_end

Route2_EventScript_Lass_Battle_Text_0:
# 8 "data/maps/Route102/scripts.pory"
	.string "Caçar Pokémon é uma ótima desculpa\npara adiar outras coisas, não\lacha?$"

Route2_EventScript_Lass_Battle_Text_1:
# 8 "data/maps/Route102/scripts.pory"
	.string "Eu tentei procrastinar hoje…\pMas parece que algumas coisas\nsimplesmente não podem esperar.$"

Route2_EventScript_Lass_Battle_Text_2:
# 9 "data/maps/Route102/scripts.pory"
	.string "Sabe o que é realmente\nsurpreendente?\pEu sempre planejo procrastinar\nmais tarde.$"

Route2_EventScript_Lass_Battle_Text_3:
# 11 "data/maps/Route102/scripts.pory"
	.string "Hunting Pokémon is a great excuse\nto put other things off, don't you\lthink?$"

Route2_EventScript_Lass_Battle_Text_4:
# 11 "data/maps/Route102/scripts.pory"
	.string "I tried procrastinating today…\pBut it seems some things just\ncan't wait.$"

Route2_EventScript_Lass_Battle_Text_5:
# 12 "data/maps/Route102/scripts.pory"
	.string "You know what's really surprising?\pI always plan to procrastinate\nlater.$"

Route2_EventScript_Lass_Battle_Text_6:
# 14 "data/maps/Route102/scripts.pory"
	.string "Cazar Pokémon es una gran excusa\npara dejar otras cosas para\ldespués, ¿no crees?$"

Route2_EventScript_Lass_Battle_Text_7:
# 14 "data/maps/Route102/scripts.pory"
	.string "Intenté procrastinar hoy…\pPero parece que hay cosas que\nsimplemente no pueden esperar.$"

Route2_EventScript_Lass_Battle_Text_8:
# 15 "data/maps/Route102/scripts.pory"
	.string "¿Sabes qué es realmente\nsorprendente?\pSiempre planeo procrastinar más\ntarde.$"

Route2_EventScript_Meeting_Giovanni_Text_0:
# 40 "data/maps/Route102/scripts.pory"
	.string "Meowth usou {COLOR}{BLUE}Scratch{COLOR}{DARK_GRAY}.$"

Route2_EventScript_Meeting_Giovanni_Text_1:
# 41 "data/maps/Route102/scripts.pory"
	.string "Meowth used {COLOR}{BLUE}Scratch{COLOR}{DARK_GRAY}.$"

Route2_EventScript_Meeting_Giovanni_Text_2:
# 42 "data/maps/Route102/scripts.pory"
	.string "Meowth usó {COLOR}{BLUE}Arañazo{COLOR}{DARK_GRAY}.$"

Route2_EventScript_Meeting_Giovanni_Text_3:
# 52 "data/maps/Route102/scripts.pory"
	.string "Nidoran usou {COLOR}{BLUE}Peck{COLOR}{DARK_GRAY}.$"

Route2_EventScript_Meeting_Giovanni_Text_4:
# 53 "data/maps/Route102/scripts.pory"
	.string "Nidoran used {COLOR}{BLUE}Peck{COLOR}{DARK_GRAY}.$"

Route2_EventScript_Meeting_Giovanni_Text_5:
# 54 "data/maps/Route102/scripts.pory"
	.string "Nidoran usó {COLOR}{BLUE}Picotazo{COLOR}{DARK_GRAY}.$"

Route2_EventScript_Meeting_Giovanni_Text_6:
# 68 "data/maps/Route102/scripts.pory"
	.string "Giovanni$"

Route2_EventScript_Meeting_Giovanni_Text_7:
# 68 "data/maps/Route102/scripts.pory"
	.string "Não.\pDe novo.\pAtaques rápidos não servem para\nnada se forem previsíveis.$"

Route2_EventScript_Meeting_Giovanni_Text_8:
# 69 "data/maps/Route102/scripts.pory"
	.string "No.\pNot again.\pFast attacks don't help if they're\npredictable.$"

Route2_EventScript_Meeting_Giovanni_Text_9:
# 70 "data/maps/Route102/scripts.pory"
	.string "No.\pOtra vez.\pLos ataques rápidos no sirven para\nnada si son previsibles.$"

Route2_EventScript_Meeting_Giovanni_Text_10:
# 77 "data/maps/Route102/scripts.pory"
	.string "Você precisa pensar antes de agir.$"

Route2_EventScript_Meeting_Giovanni_Text_11:
# 78 "data/maps/Route102/scripts.pory"
	.string "You need to think before you act.$"

Route2_EventScript_Meeting_Giovanni_Text_12:
# 79 "data/maps/Route102/scripts.pory"
	.string "Necesitas pensar antes de actuar.$"

Route2_EventScript_Meeting_Giovanni_Text_13:
# 83 "data/maps/Route102/scripts.pory"
	.string "Nidoran$"

Route2_EventScript_Meeting_Giovanni_Text_14:
# 84 "data/maps/Route102/scripts.pory"
	.string "Nee-doh!\p$"

Route2_EventScript_Meeting_Giovanni_Text_15:
# 93 "data/maps/Route102/scripts.pory"
	.string "E você…\pPare de brincar e leve isso a\nsério.$"

Route2_EventScript_Meeting_Giovanni_Text_16:
# 94 "data/maps/Route102/scripts.pory"
	.string "And you…\pStop messing around and take this\nseriously.$"

Route2_EventScript_Meeting_Giovanni_Text_17:
# 95 "data/maps/Route102/scripts.pory"
	.string "Y tú…\pDeja de jugar y tómate esto en\nserio.$"

Route2_EventScript_Meeting_Giovanni_Text_18:
# 99 "data/maps/Route102/scripts.pory"
	.string "Meowth$"

Route2_EventScript_Meeting_Giovanni_Text_19:
# 100 "data/maps/Route102/scripts.pory"
	.string "Meeow!\p$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_0:
# 127 "data/maps/Route102/scripts.pory"
	.string "Hm?\pVocê está aí faz tempo?$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_1:
# 128 "data/maps/Route102/scripts.pory"
	.string "Hm?\pHave you been there for a while?$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_2:
# 129 "data/maps/Route102/scripts.pory"
	.string "¿Hm?\p¿Llevas mucho tiempo ahí?$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_3:
# 134 "data/maps/Route102/scripts.pory"
	.string "Então estava assistindo.\nO que achou?\pEles ainda cometem erros demais.\pMas eu vou transformá-los nos\nPokémon mais fortes de Aetheris.$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_4:
# 135 "data/maps/Route102/scripts.pory"
	.string "So I was watching.\nWhat did you think?\pThey still make too many mistakes.\pBut I will turn them into the\nstrongest Pokémon in Aetheris.$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_5:
# 136 "data/maps/Route102/scripts.pory"
	.string "Entonces estaba mirando.\n¿Qué te pareció?\pTodavía cometen demasiados\nerrores.\pPero yo los convertiré en los\nPokémon más fuertes de Aetheris.$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_6:
# 144 "data/maps/Route102/scripts.pory"
	.string "Aliás…\pVocê também é um treinador, não é?\pÓtimo.\pEu preciso testar algumas\nestratégias.\pQue tal uma batalha?$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_7:
# 145 "data/maps/Route102/scripts.pory"
	.string "By the way…\pYou're a trainer too, aren't you?\pGreat.\pI need to test some strategies.\pHow about a battle?$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_8:
# 146 "data/maps/Route102/scripts.pory"
	.string "Por cierto…\pTú también eres un entrenador,\n¿no?\pGenial.\pNecesito probar algunas\nestrategias.\p¿Qué tal un combate?$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_9:
# 155 "data/maps/Route102/scripts.pory"
	.string "Me mostre o que você e seus\nPokémon conseguem fazer!$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_10:
# 156 "data/maps/Route102/scripts.pory"
	.string "Show me what you and your Pokémon\ncan do!$"

Route2_EventScript_Meeting_Giovanni_Continue_Text_11:
# 157 "data/maps/Route102/scripts.pory"
	.string "¡Muéstrame lo que tú y tus Pokémon\npueden hacer!$"

Route2_EventScript_Meeting_Giovanni_Battle_Text_0:
# 171 "data/maps/Route102/scripts.pory"
	.string "Heh…\pEntão foi você quem me\nsurpreendeu.\pGostei disso.$"

Route2_EventScript_Meeting_Giovanni_Battle_Text_1:
# 171 "data/maps/Route102/scripts.pory"
	.string "Interessante.\pVocê tem potencial.\pMas potencial sozinho não vence\nbatalhas.\pContinue treinando.$"

Route2_EventScript_Meeting_Giovanni_Battle_Text_2:
# 172 "data/maps/Route102/scripts.pory"
	.string "Heh…\pSo it was you who surprised me.\pI liked that.$"

Route2_EventScript_Meeting_Giovanni_Battle_Text_3:
# 172 "data/maps/Route102/scripts.pory"
	.string "Interesting.\pYou have potential.\pBut potential alone doesn't win\nbattles.\pKeep training.$"

Route2_EventScript_Meeting_Giovanni_Battle_Text_4:
# 173 "data/maps/Route102/scripts.pory"
	.string "Je…\pAsí que fuiste tú quien me\nsorprendió.\pMe gustó eso.$"

Route2_EventScript_Meeting_Giovanni_Battle_Text_5:
# 173 "data/maps/Route102/scripts.pory"
	.string "Interesante.\pTienes potencial.\pPero el potencial solo no gana\ncombates.\pSigue entrenando.$"

Route2_EventScript_Meeting_Giovanni_End_Text_0:
# 186 "data/maps/Route102/scripts.pory"
	.string "Foi divertido.\pA maioria dos treinadores só pensa\nem força.\pVocê parece pensar também.$"

Route2_EventScript_Meeting_Giovanni_End_Text_1:
# 187 "data/maps/Route102/scripts.pory"
	.string "That was fun.\pMost trainers only think about\nstrength.\pYou seem to think as well.$"

Route2_EventScript_Meeting_Giovanni_End_Text_2:
# 188 "data/maps/Route102/scripts.pory"
	.string "Fue divertido.\pLa mayoría de los entrenadores\nsolo piensan en la fuerza.\pTú pareces pensar también.$"

Route2_EventScript_Meeting_Giovanni_End_Text_3:
# 199 "data/maps/Route102/scripts.pory"
	.string "Meu nome é Giovanni.\nPrazer em conhecê-lo.$"

Route2_EventScript_Meeting_Giovanni_End_Text_4:
# 200 "data/maps/Route102/scripts.pory"
	.string "My name is Giovanni.\nNice to meet you.$"

Route2_EventScript_Meeting_Giovanni_End_Text_5:
# 201 "data/maps/Route102/scripts.pory"
	.string "Mi nombre es Giovanni.\nUn placer conocerte.$"

Route2_EventScript_Meeting_Giovanni_End_Text_6:
# 209 "data/maps/Route102/scripts.pory"
	.string "Vou me tornar alguém importante um\ndia.\pPode soar arrogante…\pMas eu sei exatamente onde quero\nchegar.\pE não pretendo parar até\nconseguir.$"

Route2_EventScript_Meeting_Giovanni_End_Text_7:
# 210 "data/maps/Route102/scripts.pory"
	.string "I'm going to become someone\nimportant someday.\pIt might sound arrogant…\pBut I know exactly where I want to\ngo.\pAnd I don't plan on stopping until\nI get there.$"

Route2_EventScript_Meeting_Giovanni_End_Text_8:
# 211 "data/maps/Route102/scripts.pory"
	.string "Voy a convertirme en alguien\nimportante algún día.\pPuede sonar arrogante…\pPero sé exactamente a dónde quiero\nllegar.\pY no pienso detenerme hasta\nlograrlo.$"

Route2_EventScript_Meeting_Giovanni_End_Text_9:
# 215 "data/maps/Route102/scripts.pory"
	.string "Pokémon fortes.\pTreinadores fortes.\pUm mundo forte.\pÉ isso que eu quero construir.$"

Route2_EventScript_Meeting_Giovanni_End_Text_10:
# 216 "data/maps/Route102/scripts.pory"
	.string "Strong Pokémon.\pStrong trainers.\pA strong world.\pThat's what I want to build.$"

Route2_EventScript_Meeting_Giovanni_End_Text_11:
# 217 "data/maps/Route102/scripts.pory"
	.string "Pokémon fuertes.\pEntrenadores fuertes.\pUn mundo fuerte.\pEso es lo que quiero construir.$"

Route2_EventScript_Meeting_Giovanni_End_Text_12:
# 221 "data/maps/Route102/scripts.pory"
	.string "Espero que a gente se encontre de\nnovo, {PLAYER}.\pDa próxima vez, eu vou vencer.$"

Route2_EventScript_Meeting_Giovanni_End_Text_13:
# 222 "data/maps/Route102/scripts.pory"
	.string "I hope we meet again, {PLAYER}.\pNext time, I'll win.$"

Route2_EventScript_Meeting_Giovanni_End_Text_14:
# 223 "data/maps/Route102/scripts.pory"
	.string "Espero que nos volvamos a\nencontrar, {PLAYER}.\pLa próxima vez, ganaré yo.$"

Route2_EventScript_Youngster_Battle_Text_0:
# 245 "data/maps/Route102/scripts.pory"
	.string "Capturar Pokémon pode dar trabalho\nàs vezes, não acha?$"

Route2_EventScript_Youngster_Battle_Text_1:
# 245 "data/maps/Route102/scripts.pory"
	.string "Essa derrota não vai me impedir!$"

Route2_EventScript_Youngster_Battle_Text_2:
# 246 "data/maps/Route102/scripts.pory"
	.string "Capturar Pokémon só é difícil se\nvocê estiver atrás dos stats\lperfeitos!$"

Route2_EventScript_Youngster_Battle_Text_3:
# 248 "data/maps/Route102/scripts.pory"
	.string "Catching Pokémon can be tough\nsometimes, don't you think?$"

Route2_EventScript_Youngster_Battle_Text_4:
# 248 "data/maps/Route102/scripts.pory"
	.string "This loss won't stop me!$"

Route2_EventScript_Youngster_Battle_Text_5:
# 249 "data/maps/Route102/scripts.pory"
	.string "Catching Pokémon is only hard if\nyou're after perfect stats!$"

Route2_EventScript_Youngster_Battle_Text_6:
# 251 "data/maps/Route102/scripts.pory"
	.string "Atrapar Pokémon puede ser difícil\na veces, ¿no crees?$"

Route2_EventScript_Youngster_Battle_Text_7:
# 251 "data/maps/Route102/scripts.pory"
	.string "¡Esta derrota no me detendrá!$"

Route2_EventScript_Youngster_Battle_Text_8:
# 252 "data/maps/Route102/scripts.pory"
	.string "¡Atrapar Pokémon solo es difícil\nsi buscas stats perfectos!$"

Route2_EventScript_FatGuy_Talk_Text_0:
# 260 "data/maps/Route102/scripts.pory"
	.string "Dizem que a Caverna Sussurro fica\nlogo adiante.\pVou descansar mais um pouco antes\nde entrar.$"

Route2_EventScript_FatGuy_Talk_Text_1:
# 261 "data/maps/Route102/scripts.pory"
	.string "They say Whispering Cave is just\nahead.\pI'll rest a little longer before\ngoing in.$"

Route2_EventScript_FatGuy_Talk_Text_2:
# 262 "data/maps/Route102/scripts.pory"
	.string "Dicen que la Cueva Susurro está\njusto adelante.\pDescansaré un poco más antes de\nentrar.$"

Route2_EventScript_BugCatcher_Battle_Text_0:
# 270 "data/maps/Route102/scripts.pory"
	.string "Você sabe qual é a melhor forma de\ncapturar Pokémon do tipo Inseto?$"

Route2_EventScript_BugCatcher_Battle_Text_1:
# 270 "data/maps/Route102/scripts.pory"
	.string "Parece que ainda preciso treinar\nmais meus Pokémon…$"

Route2_EventScript_BugCatcher_Battle_Text_2:
# 271 "data/maps/Route102/scripts.pory"
	.string "Se estiver procurando Pokémon do\ntipo Inseto, uma Nest Ball pode\lajudar bastante!$"

Route2_EventScript_BugCatcher_Battle_Text_3:
# 273 "data/maps/Route102/scripts.pory"
	.string "Do you know the best way to catch\nBug-type Pokémon?$"

Route2_EventScript_BugCatcher_Battle_Text_4:
# 273 "data/maps/Route102/scripts.pory"
	.string "Looks like I still need to train\nmy Pokémon a bit more…$"

Route2_EventScript_BugCatcher_Battle_Text_5:
# 274 "data/maps/Route102/scripts.pory"
	.string "If you're is searching for\nBug-type Pokémon, a Nest Ball can\lreally help!$"

Route2_EventScript_BugCatcher_Battle_Text_6:
# 276 "data/maps/Route102/scripts.pory"
	.string "¿Sabes cuál es la mejor forma de\natrapar a los Pokémon de tipo\lBicho?$"

Route2_EventScript_BugCatcher_Battle_Text_7:
# 276 "data/maps/Route102/scripts.pory"
	.string "Parece que aún necesito entrenar\nmás a mis Pokémon…$"

Route2_EventScript_BugCatcher_Battle_Text_8:
# 277 "data/maps/Route102/scripts.pory"
	.string "Si buscas Pokémon de tipo Bicho,\n¡una Nest Ball puede ser de gran\layuda!$"

Route2_EventScript_Sign_Text_0:
# 290 "data/maps/Route102/scripts.pory"
	.string "Rota 2\nVila Sylvara {RIGHT_ARROW_2}\lCaverna Sussuro {LEFT_ARROW_2}$"

Route2_EventScript_Sign_Text_1:
# 291 "data/maps/Route102/scripts.pory"
	.string "Route 2\nSylvara Town {RIGHT_ARROW_2}\lWhispering Cave {LEFT_ARROW_2}$"

Route2_EventScript_Sign_Text_2:
# 292 "data/maps/Route102/scripts.pory"
	.string "Ruta 2\nAldea Sylvara {RIGHT_ARROW_2}\lCueva Susurro {LEFT_ARROW_2}$"
