StonereachCity_MapScripts::
# 2 "data/maps/StonereachCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, StonereachCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

StonereachCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/StonereachCity/scripts.pory"
	compare VAR_STONEREACH_CITY_STATE, 1
	goto_if_eq StonereachCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
StonereachCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

StonereachCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/StonereachCity/scripts.pory"
	setobjectxyperm LOCALID_STONEREACH_GYM_GUARDIAN, 40, 36
# 5 "data/maps/StonereachCity/scripts.pory"
	setobjectmovementtype LOCALID_STONEREACH_GYM_GUARDIAN, MOVEMENT_TYPE_FACE_DOWN
	goto StonereachCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1


StonereachCity_Gentleman_Talk::
# 12 "data/maps/StonereachCity/scripts.pory"
	switch VAR_LANGUAGE
# 13 "data/maps/StonereachCity/scripts.pory"
	case PT, StonereachCity_Gentleman_Talk_3
# 14 "data/maps/StonereachCity/scripts.pory"
	case EN, StonereachCity_Gentleman_Talk_4
# 15 "data/maps/StonereachCity/scripts.pory"
	case ES, StonereachCity_Gentleman_Talk_5
StonereachCity_Gentleman_Talk_1:
	end

StonereachCity_Gentleman_Talk_3:
# 13 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_Gentleman_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_Gentleman_Talk_1

StonereachCity_Gentleman_Talk_4:
# 14 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_Gentleman_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_Gentleman_Talk_1

StonereachCity_Gentleman_Talk_5:
# 15 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_Gentleman_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_Gentleman_Talk_1


StonereachCity_FatMan_Talk::
# 21 "data/maps/StonereachCity/scripts.pory"
	switch VAR_LANGUAGE
# 22 "data/maps/StonereachCity/scripts.pory"
	case PT, StonereachCity_FatMan_Talk_3
# 23 "data/maps/StonereachCity/scripts.pory"
	case EN, StonereachCity_FatMan_Talk_4
# 24 "data/maps/StonereachCity/scripts.pory"
	case ES, StonereachCity_FatMan_Talk_5
StonereachCity_FatMan_Talk_1:
	end

StonereachCity_FatMan_Talk_3:
# 22 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_FatMan_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_FatMan_Talk_1

StonereachCity_FatMan_Talk_4:
# 23 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_FatMan_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_FatMan_Talk_1

StonereachCity_FatMan_Talk_5:
# 24 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_FatMan_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_FatMan_Talk_1


StonereachCity_Girl_Talk::
# 30 "data/maps/StonereachCity/scripts.pory"
	switch VAR_LANGUAGE
# 31 "data/maps/StonereachCity/scripts.pory"
	case PT, StonereachCity_Girl_Talk_3
# 32 "data/maps/StonereachCity/scripts.pory"
	case EN, StonereachCity_Girl_Talk_4
# 33 "data/maps/StonereachCity/scripts.pory"
	case ES, StonereachCity_Girl_Talk_5
StonereachCity_Girl_Talk_1:
	end

StonereachCity_Girl_Talk_3:
# 31 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_Girl_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_Girl_Talk_1

StonereachCity_Girl_Talk_4:
# 32 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_Girl_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_Girl_Talk_1

StonereachCity_Girl_Talk_5:
# 33 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_Girl_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_Girl_Talk_1


StonereachCity_Youngster_Talk::
# 39 "data/maps/StonereachCity/scripts.pory"
	switch VAR_LANGUAGE
# 40 "data/maps/StonereachCity/scripts.pory"
	case PT, StonereachCity_Youngster_Talk_3
# 41 "data/maps/StonereachCity/scripts.pory"
	case EN, StonereachCity_Youngster_Talk_4
# 42 "data/maps/StonereachCity/scripts.pory"
	case ES, StonereachCity_Youngster_Talk_5
StonereachCity_Youngster_Talk_1:
	end

StonereachCity_Youngster_Talk_3:
# 40 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_Youngster_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_Youngster_Talk_1

StonereachCity_Youngster_Talk_4:
# 41 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_Youngster_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_Youngster_Talk_1

StonereachCity_Youngster_Talk_5:
# 42 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_Youngster_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_Youngster_Talk_1


StonereachCity_GymGuardian_EntranceTrigger::
# 50 "data/maps/StonereachCity/scripts.pory"
	lockall
# 51 "data/maps/StonereachCity/scripts.pory"
	playse SE_PIN
# 52 "data/maps/StonereachCity/scripts.pory"
	movenpc LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_0
# 53 "data/maps/StonereachCity/scripts.pory"
	pause 50
# 54 "data/maps/StonereachCity/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 55 "data/maps/StonereachCity/scripts.pory"
	switch VAR_0x8004
# 56 "data/maps/StonereachCity/scripts.pory"
	case 38, StonereachCity_GymGuardian_EntranceTrigger_3
# 58 "data/maps/StonereachCity/scripts.pory"
	case 39, StonereachCity_GymGuardian_EntranceTrigger_4
# 60 "data/maps/StonereachCity/scripts.pory"
	case 40, StonereachCity_GymGuardian_EntranceTrigger_5
# 62 "data/maps/StonereachCity/scripts.pory"
	case 41, StonereachCity_GymGuardian_EntranceTrigger_6
StonereachCity_GymGuardian_EntranceTrigger_1:
# 65 "data/maps/StonereachCity/scripts.pory"
	pause 20
# 66 "data/maps/StonereachCity/scripts.pory"
	switch VAR_LANGUAGE
# 67 "data/maps/StonereachCity/scripts.pory"
	case PT, StonereachCity_GymGuardian_EntranceTrigger_9
# 68 "data/maps/StonereachCity/scripts.pory"
	case EN, StonereachCity_GymGuardian_EntranceTrigger_10
# 69 "data/maps/StonereachCity/scripts.pory"
	case ES, StonereachCity_GymGuardian_EntranceTrigger_11
StonereachCity_GymGuardian_EntranceTrigger_7:
# 71 "data/maps/StonereachCity/scripts.pory"
	switch VAR_LANGUAGE
# 72 "data/maps/StonereachCity/scripts.pory"
	case PT, StonereachCity_GymGuardian_EntranceTrigger_14
# 73 "data/maps/StonereachCity/scripts.pory"
	case EN, StonereachCity_GymGuardian_EntranceTrigger_15
# 74 "data/maps/StonereachCity/scripts.pory"
	case ES, StonereachCity_GymGuardian_EntranceTrigger_16
StonereachCity_GymGuardian_EntranceTrigger_12:
# 76 "data/maps/StonereachCity/scripts.pory"
	closemessage
# 77 "data/maps/StonereachCity/scripts.pory"
	playse SE_PIN
# 78 "data/maps/StonereachCity/scripts.pory"
	movenpc LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_5
# 79 "data/maps/StonereachCity/scripts.pory"
	pause 20
# 80 "data/maps/StonereachCity/scripts.pory"
	movenpc LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_6
# 81 "data/maps/StonereachCity/scripts.pory"
	special SpawnCameraObject
# 82 "data/maps/StonereachCity/scripts.pory"
	switch VAR_0x8004
# 83 "data/maps/StonereachCity/scripts.pory"
	case 38, StonereachCity_GymGuardian_EntranceTrigger_19
# 86 "data/maps/StonereachCity/scripts.pory"
	case 39, StonereachCity_GymGuardian_EntranceTrigger_20
# 89 "data/maps/StonereachCity/scripts.pory"
	case 40, StonereachCity_GymGuardian_EntranceTrigger_21
# 92 "data/maps/StonereachCity/scripts.pory"
	case 41, StonereachCity_GymGuardian_EntranceTrigger_22
StonereachCity_GymGuardian_EntranceTrigger_17:
# 96 "data/maps/StonereachCity/scripts.pory"
	waitmovementall
# 97 "data/maps/StonereachCity/scripts.pory"
	setobjectxyperm LOCALID_STONEREACH_GYM_GUARDIAN, 40, 36
# 98 "data/maps/StonereachCity/scripts.pory"
	setobjectmovementtype LOCALID_STONEREACH_GYM_GUARDIAN, MOVEMENT_TYPE_FACE_DOWN
# 99 "data/maps/StonereachCity/scripts.pory"
	setvar VAR_STONEREACH_CITY_STATE, 1
# 100 "data/maps/StonereachCity/scripts.pory"
	special RemoveCameraObject
# 101 "data/maps/StonereachCity/scripts.pory"
	warpsilent MAP_STONEREACH_CITY, VAR_0x8004, VAR_0x8005
# 102 "data/maps/StonereachCity/scripts.pory"
	waitstate
	end

StonereachCity_GymGuardian_EntranceTrigger_3:
# 57 "data/maps/StonereachCity/scripts.pory"
	movenpc LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_1
	goto StonereachCity_GymGuardian_EntranceTrigger_1

StonereachCity_GymGuardian_EntranceTrigger_4:
# 59 "data/maps/StonereachCity/scripts.pory"
	movenpc LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_2
	goto StonereachCity_GymGuardian_EntranceTrigger_1

StonereachCity_GymGuardian_EntranceTrigger_5:
# 61 "data/maps/StonereachCity/scripts.pory"
	movenpc LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_3
	goto StonereachCity_GymGuardian_EntranceTrigger_1

StonereachCity_GymGuardian_EntranceTrigger_6:
# 63 "data/maps/StonereachCity/scripts.pory"
	movenpc LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_4
	goto StonereachCity_GymGuardian_EntranceTrigger_1

StonereachCity_GymGuardian_EntranceTrigger_9:
# 67 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_GymGuardian_EntranceTrigger_Text_0
	goto StonereachCity_GymGuardian_EntranceTrigger_7

StonereachCity_GymGuardian_EntranceTrigger_10:
# 68 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_GymGuardian_EntranceTrigger_Text_1
	goto StonereachCity_GymGuardian_EntranceTrigger_7

StonereachCity_GymGuardian_EntranceTrigger_11:
# 69 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_GymGuardian_EntranceTrigger_Text_2
	goto StonereachCity_GymGuardian_EntranceTrigger_7

StonereachCity_GymGuardian_EntranceTrigger_14:
# 72 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_GymGuardian_EntranceTrigger_Text_3
	goto StonereachCity_GymGuardian_EntranceTrigger_12

StonereachCity_GymGuardian_EntranceTrigger_15:
# 73 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_GymGuardian_EntranceTrigger_Text_4
	goto StonereachCity_GymGuardian_EntranceTrigger_12

StonereachCity_GymGuardian_EntranceTrigger_16:
# 74 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_GymGuardian_EntranceTrigger_Text_5
	goto StonereachCity_GymGuardian_EntranceTrigger_12

StonereachCity_GymGuardian_EntranceTrigger_19:
# 84 "data/maps/StonereachCity/scripts.pory"
	applymovement LOCALID_CAMERA, StonereachCity_GymGuardian_EntranceTrigger_Movement_7
# 85 "data/maps/StonereachCity/scripts.pory"
	applymovement LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_8
	goto StonereachCity_GymGuardian_EntranceTrigger_17

StonereachCity_GymGuardian_EntranceTrigger_20:
# 87 "data/maps/StonereachCity/scripts.pory"
	applymovement LOCALID_CAMERA, StonereachCity_GymGuardian_EntranceTrigger_Movement_9
# 88 "data/maps/StonereachCity/scripts.pory"
	applymovement LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_10
	goto StonereachCity_GymGuardian_EntranceTrigger_17

StonereachCity_GymGuardian_EntranceTrigger_21:
# 90 "data/maps/StonereachCity/scripts.pory"
	applymovement LOCALID_CAMERA, StonereachCity_GymGuardian_EntranceTrigger_Movement_11
# 91 "data/maps/StonereachCity/scripts.pory"
	applymovement LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_12
	goto StonereachCity_GymGuardian_EntranceTrigger_17

StonereachCity_GymGuardian_EntranceTrigger_22:
# 93 "data/maps/StonereachCity/scripts.pory"
	applymovement LOCALID_CAMERA, StonereachCity_GymGuardian_EntranceTrigger_Movement_13
# 94 "data/maps/StonereachCity/scripts.pory"
	applymovement LOCALID_STONEREACH_GYM_GUARDIAN, StonereachCity_GymGuardian_EntranceTrigger_Movement_14
	goto StonereachCity_GymGuardian_EntranceTrigger_17


StonereachCity_GymGuardian_Talk::
# 107 "data/maps/StonereachCity/scripts.pory"
	switch VAR_LANGUAGE
# 108 "data/maps/StonereachCity/scripts.pory"
	case PT, StonereachCity_GymGuardian_Talk_3
# 109 "data/maps/StonereachCity/scripts.pory"
	case EN, StonereachCity_GymGuardian_Talk_4
# 110 "data/maps/StonereachCity/scripts.pory"
	case ES, StonereachCity_GymGuardian_Talk_5
StonereachCity_GymGuardian_Talk_1:
	end

StonereachCity_GymGuardian_Talk_3:
# 108 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_GymGuardian_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_GymGuardian_Talk_1

StonereachCity_GymGuardian_Talk_4:
# 109 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_GymGuardian_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_GymGuardian_Talk_1

StonereachCity_GymGuardian_Talk_5:
# 110 "data/maps/StonereachCity/scripts.pory"
	msgbox StonereachCity_GymGuardian_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_GymGuardian_Talk_1


# 52 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_0:
# 52 "data/maps/StonereachCity/scripts.pory"
	emote_exclamation_mark
	step_end

# 57 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_1:
# 57 "data/maps/StonereachCity/scripts.pory"
	walk_up
# 57 "data/maps/StonereachCity/scripts.pory"
	walk_up
# 57 "data/maps/StonereachCity/scripts.pory"
	walk_left
# 57 "data/maps/StonereachCity/scripts.pory"
	face_up
	step_end

# 59 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_2:
# 59 "data/maps/StonereachCity/scripts.pory"
	walk_up
# 59 "data/maps/StonereachCity/scripts.pory"
	walk_up
# 59 "data/maps/StonereachCity/scripts.pory"
	face_up
	step_end

# 61 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_3:
# 61 "data/maps/StonereachCity/scripts.pory"
	walk_up
# 61 "data/maps/StonereachCity/scripts.pory"
	walk_up
# 61 "data/maps/StonereachCity/scripts.pory"
	walk_right
# 61 "data/maps/StonereachCity/scripts.pory"
	face_up
	step_end

# 63 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_4:
# 63 "data/maps/StonereachCity/scripts.pory"
	walk_up
# 63 "data/maps/StonereachCity/scripts.pory"
	walk_up
# 63 "data/maps/StonereachCity/scripts.pory"
	walk_right
# 63 "data/maps/StonereachCity/scripts.pory"
	walk_right
# 63 "data/maps/StonereachCity/scripts.pory"
	face_up
	step_end

# 78 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_5:
# 78 "data/maps/StonereachCity/scripts.pory"
	emoji_smiley
	step_end

# 80 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_6:
# 80 "data/maps/StonereachCity/scripts.pory"
	face_down
	step_end

# 84 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_7:
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 84 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
	step_end

# 85 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_8:
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 85 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 85 "data/maps/StonereachCity/scripts.pory"
	face_down
	step_end

# 87 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_9:
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 87 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
	step_end

# 88 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_10:
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 88 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 88 "data/maps/StonereachCity/scripts.pory"
	face_down
	step_end

# 90 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_11:
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 90 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
	step_end

# 91 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_12:
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 91 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 91 "data/maps/StonereachCity/scripts.pory"
	face_down
	step_end

# 93 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_13:
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 93 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
	step_end

# 94 "data/maps/StonereachCity/scripts.pory"
StonereachCity_GymGuardian_EntranceTrigger_Movement_14:
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_right
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_down
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 94 "data/maps/StonereachCity/scripts.pory"
	walk_fast_left
# 94 "data/maps/StonereachCity/scripts.pory"
	face_down
	step_end

StonereachCity_Gentleman_Talk_Text_0:
# 13 "data/maps/StonereachCity/scripts.pory"
	.string "STONEREACH cresceu entre pedras e\nmentes brilhantes.\pAlguns veem apenas uma cidade de\nrocha…\pEu vejo pessoas capazes de\ntransformar pedra em progresso.$"

StonereachCity_Gentleman_Talk_Text_1:
# 14 "data/maps/StonereachCity/scripts.pory"
	.string "STONEREACH grew between stone and\nbrilliant minds.\pSome see only a city of rock…\pI see people capable of turning\nstone into progress.$"

StonereachCity_Gentleman_Talk_Text_2:
# 15 "data/maps/StonereachCity/scripts.pory"
	.string "STONEREACH creció entre piedras y\nmentes brillantes.\pAlgunos solo ven una ciudad de\nroca…\pYo veo personas capaces de\nconvertir la piedra en progreso.$"

StonereachCity_FatMan_Talk_Text_0:
# 22 "data/maps/StonereachCity/scripts.pory"
	.string "Estas ladeiras são um ótimo treino!\pSubo uma, descanso… subo outra,\ndescanso de novo…\pPensando bem, acho que estou\ntreinando mais o descanso.$"

StonereachCity_FatMan_Talk_Text_1:
# 23 "data/maps/StonereachCity/scripts.pory"
	.string "These slopes make great exercise!\pI climb one, take a rest… climb\nanother, then rest again…\pCome to think of it, I may be\ntraining my resting skills.$"

StonereachCity_FatMan_Talk_Text_2:
# 24 "data/maps/StonereachCity/scripts.pory"
	.string "¡Estas cuestas son un gran ejercicio!\pSubo una, descanso… subo otra y\nvuelvo a descansar…\pAhora que lo pienso, quizá estoy\nentrenando más el descanso.$"

StonereachCity_Girl_Talk_Text_0:
# 31 "data/maps/StonereachCity/scripts.pory"
	.string "À noite, as luzes de STONEREACH\nbrilham sobre as paredes de pedra.\pDe longe, parece que a própria\nmontanha abriu os olhos.$"

StonereachCity_Girl_Talk_Text_1:
# 32 "data/maps/StonereachCity/scripts.pory"
	.string "At night, STONEREACH's lights glow\nagainst the stone walls.\pFrom far away, it looks as though\nthe mountain itself opened its eyes.$"

StonereachCity_Girl_Talk_Text_2:
# 33 "data/maps/StonereachCity/scripts.pory"
	.string "Por la noche, las luces de\nSTONEREACH brillan sobre la piedra.\pDesde lejos, parece que la propia\nmontaña abrió los ojos.$"

StonereachCity_Youngster_Talk_Text_0:
# 40 "data/maps/StonereachCity/scripts.pory"
	.string "Ouvi dizer que Pokémon do tipo\nPedra são lentos.\pEntão desafiei um para uma corrida…\pEle não correu, mas eu tropecei\nnele. Acho que ele venceu.$"

StonereachCity_Youngster_Talk_Text_1:
# 41 "data/maps/StonereachCity/scripts.pory"
	.string "I heard Rock-type Pokémon are slow.\pSo I challenged one to a race…\pIt never ran, but I tripped over\nit. I guess it won.$"

StonereachCity_Youngster_Talk_Text_2:
# 42 "data/maps/StonereachCity/scripts.pory"
	.string "Oí que los Pokémon de tipo Roca\nson lentos.\pAsí que desafié a uno a una carrera…\pNo corrió, pero tropecé con él.\nSupongo que ganó.$"

StonereachCity_GymGuardian_EntranceTrigger_Text_0:
# 67 "data/maps/StonereachCity/scripts.pory"
	.string "Bem-vindo a Stonereach City!\pSe veio desafiar o Ginásio, terá\nque esperar um pouco.\pO Líder está ajudando a Professora\nHikari no museu.$"

StonereachCity_GymGuardian_EntranceTrigger_Text_1:
# 68 "data/maps/StonereachCity/scripts.pory"
	.string "Welcome to Stonereach City!\pIf you came to challenge the Gym,\nyou'll have to wait a little while.\pThe Leader is helping Professor\nHikari at the museum.$"

StonereachCity_GymGuardian_EntranceTrigger_Text_2:
# 69 "data/maps/StonereachCity/scripts.pory"
	.string "¡Bienvenido a Ciudad Stonereach!\pSi vienes a desafiar el Gimnasio,\ntendrás que esperar un poco.\pEl Líder está ayudando a la\nProfesora Hikari en el museo.$"

StonereachCity_GymGuardian_EntranceTrigger_Text_3:
# 72 "data/maps/StonereachCity/scripts.pory"
	.string "Vou esperar em frente ao Ginásio.\pEnquanto isso, fique à vontade para\nexplorar a cidade.\pSTONEREACH tem muito mais a oferecer\ndo que batalhas de Ginásio!\pQuando o Líder voltar, serei o\nprimeiro a saber.$"

StonereachCity_GymGuardian_EntranceTrigger_Text_4:
# 73 "data/maps/StonereachCity/scripts.pory"
	.string "I'll wait in front of the Gym.\pIn the meantime, feel free to\nexplore the city.\pSTONEREACH has much more to offer\nthan Gym battles!\pWhen the Leader returns, I'll be\nthe first to know.$"

StonereachCity_GymGuardian_EntranceTrigger_Text_5:
# 74 "data/maps/StonereachCity/scripts.pory"
	.string "Esperaré frente al Gimnasio.\pMientras tanto, siéntete libre de\nexplorar la ciudad.\p¡STONEREACH ofrece mucho más que\ncombates de Gimnasio!\pCuando vuelva el Líder, seré el\nprimero en saberlo.$"

StonereachCity_GymGuardian_Talk_Text_0:
# 108 "data/maps/StonereachCity/scripts.pory"
	.string "O Líder ainda não voltou do museu.\pA Professora Hikari deve ter\nencontrado algo que exige toda a\latenção dele.\pAssim que ele retornar, o Ginásio\nvoltará a receber desafiantes.$"

StonereachCity_GymGuardian_Talk_Text_1:
# 109 "data/maps/StonereachCity/scripts.pory"
	.string "The Leader still hasn't returned\nfrom the museum.\pProfessor Hikari must have found\nsomething requiring his full\lattention.\pThe Gym will welcome challengers\nagain as soon as he returns.$"

StonereachCity_GymGuardian_Talk_Text_2:
# 110 "data/maps/StonereachCity/scripts.pory"
	.string "El Líder aún no ha regresado del\nmuseo.\pLa Profesora Hikari debe haber\nencontrado algo que requiere toda\lsu atención.\pEl Gimnasio recibirá retadores de\nnuevo en cuanto vuelva.$"
