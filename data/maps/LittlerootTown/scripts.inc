LittlerootTown_MapScripts::
# 2 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 9 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 4 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 5 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 4 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 1
	goto_if_le LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_PLAYERFACING_ROOM, 0, PineveilTown_ProffessorHikariInterviwew
	.2byte 0


PineveilTown_ProffessorHikariInterviwew::
# 15 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 16 "data/maps/LittlerootTown/scripts.pory"
	playbgm MUS_RG_TEACHY_TV_SHOW, 0
# 17 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 18 "data/maps/LittlerootTown/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_3
# 20 "data/maps/LittlerootTown/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_4
# 22 "data/maps/LittlerootTown/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_5
PineveilTown_ProffessorHikariInterviwew_1:
# 25 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 26 "data/maps/LittlerootTown/scripts.pory"
	movenpc LOCALID_REPORTER, Movement_Interview_1
# 27 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 28 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 29 "data/maps/LittlerootTown/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_8
# 31 "data/maps/LittlerootTown/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_9
# 33 "data/maps/LittlerootTown/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_10
PineveilTown_ProffessorHikariInterviwew_6:
# 36 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 37 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 38 "data/maps/LittlerootTown/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_13
# 40 "data/maps/LittlerootTown/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_14
# 42 "data/maps/LittlerootTown/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_15
PineveilTown_ProffessorHikariInterviwew_11:
# 45 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 46 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 47 "data/maps/LittlerootTown/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_18
# 49 "data/maps/LittlerootTown/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_19
# 51 "data/maps/LittlerootTown/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_20
PineveilTown_ProffessorHikariInterviwew_16:
# 54 "data/maps/LittlerootTown/scripts.pory"
	movenpc LOCALID_REPORTER, Movement_Interview_2
# 55 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 56 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 57 "data/maps/LittlerootTown/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_23
# 59 "data/maps/LittlerootTown/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_24
# 61 "data/maps/LittlerootTown/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_ProffessorHikariInterviwew_25
PineveilTown_ProffessorHikariInterviwew_21:
# 64 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_PLAYERFACING_ROOM, 1
# 65 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_INTERVIEW_HIKARI_DONE
# 66 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_SPAWN_INVISIBLE
# 67 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 7, 5
# 68 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 69 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

PineveilTown_ProffessorHikariInterviwew_3:
# 19 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_1
	goto PineveilTown_ProffessorHikariInterviwew_1

PineveilTown_ProffessorHikariInterviwew_4:
# 21 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_2
	goto PineveilTown_ProffessorHikariInterviwew_1

PineveilTown_ProffessorHikariInterviwew_5:
# 23 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_3
	goto PineveilTown_ProffessorHikariInterviwew_1

PineveilTown_ProffessorHikariInterviwew_8:
# 30 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_4
	goto PineveilTown_ProffessorHikariInterviwew_6

PineveilTown_ProffessorHikariInterviwew_9:
# 32 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_5
	goto PineveilTown_ProffessorHikariInterviwew_6

PineveilTown_ProffessorHikariInterviwew_10:
# 34 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_6
	goto PineveilTown_ProffessorHikariInterviwew_6

PineveilTown_ProffessorHikariInterviwew_13:
# 39 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_HIKARI, PineveilTown_ProffessorHikariInterviwew_Text_7, PineveilTown_ProffessorHikariInterviwew_Text_8
	goto PineveilTown_ProffessorHikariInterviwew_11

PineveilTown_ProffessorHikariInterviwew_14:
# 41 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_HIKARI, PineveilTown_ProffessorHikariInterviwew_Text_7, PineveilTown_ProffessorHikariInterviwew_Text_9
	goto PineveilTown_ProffessorHikariInterviwew_11

PineveilTown_ProffessorHikariInterviwew_15:
# 43 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_HIKARI, PineveilTown_ProffessorHikariInterviwew_Text_7, PineveilTown_ProffessorHikariInterviwew_Text_10
	goto PineveilTown_ProffessorHikariInterviwew_11

PineveilTown_ProffessorHikariInterviwew_18:
# 48 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_11
	goto PineveilTown_ProffessorHikariInterviwew_16

PineveilTown_ProffessorHikariInterviwew_19:
# 50 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_12
	goto PineveilTown_ProffessorHikariInterviwew_16

PineveilTown_ProffessorHikariInterviwew_20:
# 52 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_13
	goto PineveilTown_ProffessorHikariInterviwew_16

PineveilTown_ProffessorHikariInterviwew_23:
# 58 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_14
	goto PineveilTown_ProffessorHikariInterviwew_21

PineveilTown_ProffessorHikariInterviwew_24:
# 60 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_15
	goto PineveilTown_ProffessorHikariInterviwew_21

PineveilTown_ProffessorHikariInterviwew_25:
# 62 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_REPORTER, PineveilTown_ProffessorHikariInterviwew_Text_0, PineveilTown_ProffessorHikariInterviwew_Text_16
	goto PineveilTown_ProffessorHikariInterviwew_21


PineveilTown_PlayerHouseSign::
# 74 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 75 "data/maps/LittlerootTown/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_PlayerHouseSign_3
# 78 "data/maps/LittlerootTown/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_PlayerHouseSign_4
# 79 "data/maps/LittlerootTown/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_PlayerHouseSign_5
PineveilTown_PlayerHouseSign_1:
	end

PineveilTown_PlayerHouseSign_3:
# 76 "data/maps/LittlerootTown/scripts.pory"
	callnative CheckGenderString
# 77 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_PlayerHouseSign_Text_0, MSGBOX_SIGN
	goto PineveilTown_PlayerHouseSign_1

PineveilTown_PlayerHouseSign_4:
# 78 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_PlayerHouseSign_Text_1, MSGBOX_SIGN
	goto PineveilTown_PlayerHouseSign_1

PineveilTown_PlayerHouseSign_5:
# 79 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_PlayerHouseSign_Text_2, MSGBOX_SIGN
	goto PineveilTown_PlayerHouseSign_1


PineveilTown_RivalHouseSign::
# 85 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 86 "data/maps/LittlerootTown/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_RivalHouseSign_3
# 87 "data/maps/LittlerootTown/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_RivalHouseSign_4
# 88 "data/maps/LittlerootTown/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_RivalHouseSign_5
PineveilTown_RivalHouseSign_1:
	end

PineveilTown_RivalHouseSign_3:
# 86 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_RivalHouseSign_Text_0, MSGBOX_SIGN
	goto PineveilTown_RivalHouseSign_1

PineveilTown_RivalHouseSign_4:
# 87 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_RivalHouseSign_Text_1, MSGBOX_SIGN
	goto PineveilTown_RivalHouseSign_1

PineveilTown_RivalHouseSign_5:
# 88 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_RivalHouseSign_Text_2
	goto PineveilTown_RivalHouseSign_1


PineveilTown_Boy_Conversation::
# 94 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 95 "data/maps/LittlerootTown/scripts.pory"
	case PORTUGUESE_LANGUAGE, PineveilTown_Boy_Conversation_3
# 96 "data/maps/LittlerootTown/scripts.pory"
	case ENGLISH_LANGUAGE, PineveilTown_Boy_Conversation_4
# 97 "data/maps/LittlerootTown/scripts.pory"
	case SPANISH_LANGUAGE, PineveilTown_Boy_Conversation_5
PineveilTown_Boy_Conversation_1:
	end

PineveilTown_Boy_Conversation_3:
# 95 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_Boy_Conversation_Text_0, MSGBOX_NPC
	goto PineveilTown_Boy_Conversation_1

PineveilTown_Boy_Conversation_4:
# 96 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_Boy_Conversation_Text_1, MSGBOX_NPC
	goto PineveilTown_Boy_Conversation_1

PineveilTown_Boy_Conversation_5:
# 97 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_Boy_Conversation_Text_2, MSGBOX_NPC
	goto PineveilTown_Boy_Conversation_1


PineveilTown_BirdKeeper_Talk::
# 103 "data/maps/LittlerootTown/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, PineveilTown_BirdKeeper_Talk_1
# 110 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 111 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_BirdKeeper_Talk_9
# 114 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_BirdKeeper_Talk_10
# 116 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_BirdKeeper_Talk_11
	return

PineveilTown_BirdKeeper_Talk_1:
# 104 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 105 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_BirdKeeper_Talk_5
# 106 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_BirdKeeper_Talk_6
# 107 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_BirdKeeper_Talk_7
	return

PineveilTown_BirdKeeper_Talk_5:
# 105 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_BirdKeeper_Talk_Text_0, MSGBOX_NPC
	return

PineveilTown_BirdKeeper_Talk_6:
# 106 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_BirdKeeper_Talk_Text_1, MSGBOX_NPC
	return

PineveilTown_BirdKeeper_Talk_7:
# 107 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_BirdKeeper_Talk_Text_2, MSGBOX_NPC
	return

PineveilTown_BirdKeeper_Talk_9:
# 112 "data/maps/LittlerootTown/scripts.pory"
	checkgenderstr
# 113 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_BirdKeeper_Talk_Text_3, MSGBOX_NPC
	return

PineveilTown_BirdKeeper_Talk_10:
# 115 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_BirdKeeper_Talk_Text_4, MSGBOX_NPC
	return

PineveilTown_BirdKeeper_Talk_11:
# 117 "data/maps/LittlerootTown/scripts.pory"
	checkgenderstr
# 118 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_BirdKeeper_Talk_Text_5, MSGBOX_NPC
	return


PineveilTown_CantPassUntilHaveAPokemon_Tile::
# 124 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 125 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 126 "data/maps/LittlerootTown/scripts.pory"
	movenpc LOCALID_LITTLEROOT_BIDKEEPER, Common_Movement_ExclamationMark
# 127 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 128 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 129 "data/maps/LittlerootTown/scripts.pory"
	moveplayer Common_Movement_FaceUp
# 130 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 131 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_CantPassUntilHaveAPokemon_Tile_3
# 132 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_CantPassUntilHaveAPokemon_Tile_4
# 133 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_CantPassUntilHaveAPokemon_Tile_5
PineveilTown_CantPassUntilHaveAPokemon_Tile_1:
# 135 "data/maps/LittlerootTown/scripts.pory"
	moveplayer Movement_Player_Walk_Right
# 136 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

PineveilTown_CantPassUntilHaveAPokemon_Tile_3:
# 131 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_CantPassUntilHaveAPokemon_Tile_Text_0, MSGBOX_AUTOCLOSE
	goto PineveilTown_CantPassUntilHaveAPokemon_Tile_1

PineveilTown_CantPassUntilHaveAPokemon_Tile_4:
# 132 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_CantPassUntilHaveAPokemon_Tile_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_CantPassUntilHaveAPokemon_Tile_1

PineveilTown_CantPassUntilHaveAPokemon_Tile_5:
# 133 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_CantPassUntilHaveAPokemon_Tile_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_CantPassUntilHaveAPokemon_Tile_1


PineveilTown_Signpost::
# 141 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 142 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_Signpost_3
# 143 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_Signpost_4
# 144 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_Signpost_5
PineveilTown_Signpost_1:
	end

PineveilTown_Signpost_3:
# 142 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_Signpost_Text_0, MSGBOX_SIGN
	goto PineveilTown_Signpost_1

PineveilTown_Signpost_4:
# 143 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_Signpost_Text_1, MSGBOX_SIGN
	goto PineveilTown_Signpost_1

PineveilTown_Signpost_5:
# 144 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_Signpost_Text_2, MSGBOX_SIGN
	goto PineveilTown_Signpost_1


PineveilTown_Lab_Signpost::
# 150 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 151 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_Lab_Signpost_3
# 152 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_Lab_Signpost_4
# 153 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_Lab_Signpost_5
PineveilTown_Lab_Signpost_1:
	end

PineveilTown_Lab_Signpost_3:
# 151 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_Lab_Signpost_Text_0, MSGBOX_SIGN
	goto PineveilTown_Lab_Signpost_1

PineveilTown_Lab_Signpost_4:
# 152 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_Lab_Signpost_Text_1, MSGBOX_SIGN
	goto PineveilTown_Lab_Signpost_1

PineveilTown_Lab_Signpost_5:
# 153 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_Lab_Signpost_Text_2, MSGBOX_SIGN
	goto PineveilTown_Lab_Signpost_1


PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone::
# 161 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 162 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 163 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_3
# 164 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_4
# 165 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_5
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_1:
# 167 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 168 "data/maps/LittlerootTown/scripts.pory"
	createspobject OBJ_EVENT_GFX_MOM, 6, 13, 19, MOVEMENT_TYPE_FACE_UP
# 169 "data/maps/LittlerootTown/scripts.pory"
	special SpawnCameraObject
# 170 "data/maps/LittlerootTown/scripts.pory"
	movecamera Movement_PineveilCameraToMom
# 171 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 172 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp6
# 173 "data/maps/LittlerootTown/scripts.pory"
	applymovement 6, Common_Movement_WalkUp5
# 174 "data/maps/LittlerootTown/scripts.pory"
	waitmovementall
# 175 "data/maps/LittlerootTown/scripts.pory"
	special RemoveCameraObject
# 176 "data/maps/LittlerootTown/scripts.pory"
	moveplayer Common_Movement_FaceDown
# 177 "data/maps/LittlerootTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 178 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 179 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_8
# 180 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_9
# 181 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_10
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_6:
# 183 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 184 "data/maps/LittlerootTown/scripts.pory"
	movenpc 6, Common_Movement_EmojiKissing
# 185 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 186 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 187 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 188 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_13
# 189 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_14
# 190 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_15
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_11:
# 192 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 193 "data/maps/LittlerootTown/scripts.pory"
	movenpc 6, Common_Movement_EmojiRelaxed
# 194 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 195 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 196 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 197 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_18
# 198 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_19
# 199 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_20
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_16:
# 201 "data/maps/LittlerootTown/scripts.pory"
	pause 10
# 202 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 203 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 204 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 205 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_23
# 206 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_24
# 207 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_25
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_21:
# 209 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 210 "data/maps/LittlerootTown/scripts.pory"
	waitbuttonpress
# 211 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 212 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 213 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_28
# 214 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_29
# 215 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_30
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_26:
# 217 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 218 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_DEXNAV_GET
# 219 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 220 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_33
# 221 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_34
# 222 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_35
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_31:
# 224 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 225 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 226 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 227 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_38
# 228 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_39
# 229 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_40
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_36:
# 231 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 232 "data/maps/LittlerootTown/scripts.pory"
	waitbuttonpress
# 233 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 234 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 235 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_43
# 236 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_44
# 237 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_45
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_41:
# 239 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 240 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 241 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_48
# 242 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_49
# 243 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_50
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_46:
# 245 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 246 "data/maps/LittlerootTown/scripts.pory"
	createspobject OBJ_EVENT_GFX_SCIENTIST_1, 7, 12, 19, MOVEMENT_TYPE_FACE_UP
# 247 "data/maps/LittlerootTown/scripts.pory"
	movenpc 7, Movement_Scientist_ComeNextPlayer
# 248 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 249 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_53
# 250 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_54
# 251 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_55
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_51:
# 253 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 254 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_PLAYER, Movement_PineveilHaveDoubtLookingLeft
# 255 "data/maps/LittlerootTown/scripts.pory"
	applymovement 6, Movement_PineveilHaveDoubtLookingLeft
# 256 "data/maps/LittlerootTown/scripts.pory"
	waitmovementall
# 257 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 258 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 259 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 260 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_58
# 261 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_59
# 262 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_60
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_56:
# 264 "data/maps/LittlerootTown/scripts.pory"
	movenpc 6, Movement_PineveilWalkDownLookingUp
# 265 "data/maps/LittlerootTown/scripts.pory"
	moveplayer Movement_PineveilWalkDownLookingUp
# 266 "data/maps/LittlerootTown/scripts.pory"
	movenpc 7, Movement_Pineveil_ScientisRushToLab
# 267 "data/maps/LittlerootTown/scripts.pory"
	removeobject 7
# 268 "data/maps/LittlerootTown/scripts.pory"
	playse SE_DOOR
# 269 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 270 "data/maps/LittlerootTown/scripts.pory"
	pause 20
# 271 "data/maps/LittlerootTown/scripts.pory"
	moveplayer Common_Movement_FaceDown
# 272 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_LANGUAGE
# 273 "data/maps/LittlerootTown/scripts.pory"
	case PT, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_63
# 274 "data/maps/LittlerootTown/scripts.pory"
	case EN, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_64
# 275 "data/maps/LittlerootTown/scripts.pory"
	case ES, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_65
PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_61:
# 277 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 278 "data/maps/LittlerootTown/scripts.pory"
	movenpc 6, Common_Movement_EmojiKissing
# 279 "data/maps/LittlerootTown/scripts.pory"
	waitse
# 280 "data/maps/LittlerootTown/scripts.pory"
	pause 10
# 281 "data/maps/LittlerootTown/scripts.pory"
	movenpc 6, Movement_Pineveil_MomGoBackHome
# 282 "data/maps/LittlerootTown/scripts.pory"
	removeobject 6
# 283 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
# 284 "data/maps/LittlerootTown/scripts.pory"
	pause 30
# 285 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 286 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 6
# 287 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 288 "data/maps/LittlerootTown/scripts.pory"
	release
	end

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_3:
# 163 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_1

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_4:
# 164 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_1

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_5:
# 165 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_4, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_1

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_8:
# 179 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_5, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_6

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_9:
# 180 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_6, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_6

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_10:
# 181 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_7, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_6

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_13:
# 188 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_8, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_11

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_14:
# 189 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_9, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_11

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_15:
# 190 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_10, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_11

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_18:
# 197 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_11, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_16

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_19:
# 198 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_12, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_16

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_20:
# 199 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_13, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_16

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_23:
# 205 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_14
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_21

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_24:
# 206 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_15
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_21

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_25:
# 207 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_16
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_21

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_28:
# 213 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_17, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_26

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_29:
# 214 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_18, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_26

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_30:
# 215 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_19, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_26

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_33:
# 220 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_20, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_31

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_34:
# 221 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_21, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_31

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_35:
# 222 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_22, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_31

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_38:
# 227 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_23
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_36

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_39:
# 228 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_24
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_36

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_40:
# 229 "data/maps/LittlerootTown/scripts.pory"
	msgbox PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_25
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_36

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_43:
# 235 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_26, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_41

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_44:
# 236 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_27, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_41

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_45:
# 237 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_28, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_41

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_48:
# 241 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_29, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_46

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_49:
# 242 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_30, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_46

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_50:
# 243 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_31, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_46

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_53:
# 249 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_SCIENTIST, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_32, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_33, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_51

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_54:
# 250 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_SCIENTIST, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_32, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_34, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_51

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_55:
# 251 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_SCIENTIST, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_32, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_35, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_51

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_58:
# 260 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_SCIENTIST, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_32, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_36, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_56

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_59:
# 261 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_SCIENTIST, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_32, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_37, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_56

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_60:
# 262 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_SCIENTIST, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_32, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_38, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_56

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_63:
# 273 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_39, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_61

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_64:
# 274 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_40, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_61

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_65:
# 275 "data/maps/LittlerootTown/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3, PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_41, MSGBOX_AUTOCLOSE
	goto PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_61


# 292 "data/maps/LittlerootTown/scripts.pory"
Movement_Pineveil_MomGoBackHome:
# 293 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 293 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 293 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 294 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 294 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 295 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 295 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 296 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 296 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 296 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 296 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 299 "data/maps/LittlerootTown/scripts.pory"
Movement_Pineveil_ScientisRushToLab:
# 300 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 301 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 301 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 301 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 301 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 301 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 301 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 302 "data/maps/LittlerootTown/scripts.pory"
	delay_16
	step_end

# 305 "data/maps/LittlerootTown/scripts.pory"
Movement_PineveilWalkDownLookingUp:
# 306 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 307 "data/maps/LittlerootTown/scripts.pory"
	face_up
	step_end

# 310 "data/maps/LittlerootTown/scripts.pory"
Movement_PineveilHaveDoubtLookingLeft:
# 311 "data/maps/LittlerootTown/scripts.pory"
	emoji_doubt
# 312 "data/maps/LittlerootTown/scripts.pory"
	face_left
	step_end

# 315 "data/maps/LittlerootTown/scripts.pory"
Movement_Scientist_ComeNextPlayer:
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 316 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 317 "data/maps/LittlerootTown/scripts.pory"
	face_right
	step_end

# 320 "data/maps/LittlerootTown/scripts.pory"
Movement_PineveilCameraToMom:
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 324 "data/maps/LittlerootTown/scripts.pory"
Movement_Interview_1:
# 325 "data/maps/LittlerootTown/scripts.pory"
	face_up
	step_end

# 328 "data/maps/LittlerootTown/scripts.pory"
Movement_Interview_2:
# 329 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 332 "data/maps/LittlerootTown/scripts.pory"
Movement_BirdKeeper_GoToPlayer1:
# 333 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 333 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 334 "data/maps/LittlerootTown/scripts.pory"
	face_right
	step_end

# 337 "data/maps/LittlerootTown/scripts.pory"
Movement_BirdKeeper_GoToPlayer2:
# 338 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 338 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 338 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 339 "data/maps/LittlerootTown/scripts.pory"
	face_right
	step_end

# 342 "data/maps/LittlerootTown/scripts.pory"
Movement_BirdKeeper_GoAwayPlayer1:
# 343 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 343 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 344 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 347 "data/maps/LittlerootTown/scripts.pory"
Movement_BirdKeeper_GoAwayPlayer2:
# 348 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 348 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 348 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 349 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 352 "data/maps/LittlerootTown/scripts.pory"
Movement_Player_Walk_Right:
# 353 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 354 "data/maps/LittlerootTown/scripts.pory"
	face_right
	step_end

# 357 "data/maps/LittlerootTown/scripts.pory"
Movement_Player_Walk_down:
# 358 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 359 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

PineveilTown_ProffessorHikariInterviwew_Text_0:
# 19 "data/maps/LittlerootTown/scripts.pory"
	.string "Rezende$"

PineveilTown_ProffessorHikariInterviwew_Text_1:
# 19 "data/maps/LittlerootTown/scripts.pory"
	.string "Interrompemos nossa programação\npara uma entrevista especial com a\lProfessora Hikari, que acaba de\lretornar de uma expedição de\lpesquisa à região de Paldea.$"

PineveilTown_ProffessorHikariInterviwew_Text_2:
# 21 "data/maps/LittlerootTown/scripts.pory"
	.string "We interrupt our programming for a\nspecial interview with Professor\lHikari, who has just returned from\la research expedition to the\lPaldea region.$"

PineveilTown_ProffessorHikariInterviwew_Text_3:
# 23 "data/maps/LittlerootTown/scripts.pory"
	.string "Interrumpimos nuestra programación\npara una entrevista especial con\lla profesora Hikari, quien acaba\lde regresar de una expedición de\linvestigación a la región de\lPaldea.$"

PineveilTown_ProffessorHikariInterviwew_Text_4:
# 30 "data/maps/LittlerootTown/scripts.pory"
	.string "Professora Hikari, poderia\ncompartilhar com nossos\ltelespectadores como foi sua\lexpedição à região de Paldea?$"

PineveilTown_ProffessorHikariInterviwew_Text_5:
# 32 "data/maps/LittlerootTown/scripts.pory"
	.string "Professor Hikari, could you share\nwith our viewers what your\lexpedition to the Paldea region\lwas like?$"

PineveilTown_ProffessorHikariInterviwew_Text_6:
# 34 "data/maps/LittlerootTown/scripts.pory"
	.string "Profesora Hikari, ¿podría\ncompartir con nuestros\ltelevidentes cómo fue su\lexpedición a la región de Paldea?$"

PineveilTown_ProffessorHikariInterviwew_Text_7:
# 39 "data/maps/LittlerootTown/scripts.pory"
	.string "Hikari$"

PineveilTown_ProffessorHikariInterviwew_Text_8:
# 39 "data/maps/LittlerootTown/scripts.pory"
	.string "Agradeço, Rezende.\pPaldea é uma região fascinante,\ncheia de inovação, tradição e\lnovas formas de Pokémon.\pEstudei a Teracristalização a\nfundo e seus efeitos nas\lestratégias de batalha.\pMas agora meu foco retorna à\nregião de Aetheris.\pTreinadores que almejam a Liga\ndevem treinar duro, estudar\lbastante e nunca desistir.\pAinda há muito a descobrir sobre\nos Pokémon de Aetheris.\pEspero que a nova geração de\ntreinadores nos ajude a desvendar\lesses mistérios.$"

PineveilTown_ProffessorHikariInterviwew_Text_9:
# 41 "data/maps/LittlerootTown/scripts.pory"
	.string "Thank you, Rezende.\pPaldea is a fascinating region,\nfull of innovation, tradition, and\lnew forms of Pokémon.\pI studied Terastalization in depth\nand its effects on battle\lstrategies.\pBut now my focus returns to the\nAetheris region.\pTrainers who aspire to challenge\nthe League must train hard, study\lwell, and never give up.\pThere is still much to discover\nabout the Pokémon of Aetheris.\pI hope the next generation of\nTrainers will help us uncover\lthese mysteries.$"

PineveilTown_ProffessorHikariInterviwew_Text_10:
# 43 "data/maps/LittlerootTown/scripts.pory"
	.string "Gracias, Rezende.\pPaldea es una región fascinante,\nllena de innovación, tradición y\lnuevas formas de Pokémon.\pEstudié la Teracristalización a\nfondo y sus efectos en las\lestrategias de combate.\pPero ahora mi enfoque vuelve a la\nregión de Aetheris.\pLos entrenadores que aspiran a la\nLiga deben entrenar duro, estudiar\lbien y nunca rendirse.\pAún queda mucho por descubrir\nsobre los Pokémon de Aetheris.\pEspero que la nueva generación de\nEntrenadores nos ayude a descubrir\lestos misterios.$"

PineveilTown_ProffessorHikariInterviwew_Text_11:
# 48 "data/maps/LittlerootTown/scripts.pory"
	.string "Muito obrigado, Professora Hikari.\pDesejamos sucesso em suas\npesquisas.$"

PineveilTown_ProffessorHikariInterviwew_Text_12:
# 50 "data/maps/LittlerootTown/scripts.pory"
	.string "Thank you very much, Professor\nHikari.\pWe wish you great success in your\nresearch.$"

PineveilTown_ProffessorHikariInterviwew_Text_13:
# 52 "data/maps/LittlerootTown/scripts.pory"
	.string "Muchas gracias, profesora Hikari.\pLe deseamos mucho éxito en sus\ninvestigaciones.$"

PineveilTown_ProffessorHikariInterviwew_Text_14:
# 58 "data/maps/LittlerootTown/scripts.pory"
	.string "A todos os treinadores aspirantes:\pO caminho para a grandeza começa\nagora.\pEsta foi uma reportagem exclusiva\nda TV Voltaris.\pContinuem ligados!$"

PineveilTown_ProffessorHikariInterviwew_Text_15:
# 60 "data/maps/LittlerootTown/scripts.pory"
	.string "To all aspiring Trainers:\pThe path to greatness begins now.\pThis was an exclusive report from\nVoltaris TV.\pStay tuned!$"

PineveilTown_ProffessorHikariInterviwew_Text_16:
# 62 "data/maps/LittlerootTown/scripts.pory"
	.string "A todos los Entrenadores\naspirantes:\pEl camino hacia la grandeza\ncomienza ahora.\pEste fue un reportaje exclusivo de\nTV Voltaris.\p¡Sigan en sintonía!$"

PineveilTown_PlayerHouseSign_Text_0:
# 77 "data/maps/LittlerootTown/scripts.pory"
	.string "Casa d{STR_VAR_1} {PLAYER}.$"

PineveilTown_PlayerHouseSign_Text_1:
# 78 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s house.$"

PineveilTown_PlayerHouseSign_Text_2:
# 79 "data/maps/LittlerootTown/scripts.pory"
	.string "La casa de {PLAYER}.$"

PineveilTown_RivalHouseSign_Text_0:
# 86 "data/maps/LittlerootTown/scripts.pory"
	.string "Casa do {RIVAL}.$"

PineveilTown_RivalHouseSign_Text_1:
# 87 "data/maps/LittlerootTown/scripts.pory"
	.string "{RIVAL}'s house.$"

PineveilTown_RivalHouseSign_Text_2:
# 88 "data/maps/LittlerootTown/scripts.pory"
	.string "La casa de {RIVAL}.$"

PineveilTown_Boy_Conversation_Text_0:
# 95 "data/maps/LittlerootTown/scripts.pory"
	.string "Eu adoro viver aqui em Pineveil!\pÉ tudo tão calmo… e o vento nas\nárvores faz um som tão relaxante.\pÀs vezes fico imaginando como deve\nser viajar pelo mundo…\pMas, pra falar a verdade, acho que\nnão existe lugar melhor que aqui!$"

PineveilTown_Boy_Conversation_Text_1:
# 96 "data/maps/LittlerootTown/scripts.pory"
	.string "I love living here in Pineveil!\pEverything is so calm… and the\nsound of the wind through the\ltrees is so relaxing.\pSometimes I wonder what it would\nbe like to travel the world…\pBut honestly, I think there's no\nbetter place than here!$"

PineveilTown_Boy_Conversation_Text_2:
# 97 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Me encanta vivir aquí en\nPineveil!\pTodo es tan tranquilo… y el sonido\ndel viento entre los árboles es\lmuy relajante.\pA veces me pregunto cómo será\nviajar por el mundo…\pPero, sinceramente, ¡creo que no\nhay un lugar mejor que este!$"

PineveilTown_BirdKeeper_Talk_Text_0:
# 105 "data/maps/LittlerootTown/scripts.pory"
	.string "Ei, você não pode passar por aqui\nainda!\pA Rota 1 pode ser perigosa…\nPokémon selvagens aparecem por lá.\pSem um Pokémon ao seu lado, é\nmelhor não arriscar.\pVolte quando tiver um Pokémon para\nte proteger!$"

PineveilTown_BirdKeeper_Talk_Text_1:
# 106 "data/maps/LittlerootTown/scripts.pory"
	.string "Hey, you can't go through here\njust yet!\pRoute 1 can be dangerous… wild\nPokémon appear there.\pWithout a Pokémon by your side,\nit's best not to take the risk.\pCome back when you have a Pokémon\nto protect you!$"

PineveilTown_BirdKeeper_Talk_Text_2:
# 107 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Oye, aún no puedes pasar por\naquí!\pLa Ruta 1 puede ser peligrosa…\naparecen Pokémon salvajes.\pSin un Pokémon a tu lado, es mejor\nno arriesgarse.\p¡Vuelve cuando tengas un Pokémon\nque te proteja!$"

PineveilTown_BirdKeeper_Talk_Text_3:
# 113 "data/maps/LittlerootTown/scripts.pory"
	.string "Ah, vejo que você já tem um\nPokémon!\pAgora sim, você está pront{STR_VAR_1} para\nseguir pela Rota 1.\pMas não baixe a guarda, ok?\nPokémon selvagens podem aparecer a\lqualquer momento.\pBoa sorte na sua jornada!$"

PineveilTown_BirdKeeper_Talk_Text_4:
# 115 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, I see you have a Pokémon now!\pNow you're ready to head onto\nRoute 1.\pBut don't let your guard down,\nokay? Wild Pokémon can appear at\lany time.\pGood luck on your journey!$"

PineveilTown_BirdKeeper_Talk_Text_5:
# 118 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Ah, veo que ya tienes un Pokémon!\pAhora sí, estás list{STR_VAR_1} para avanzar\npor la Ruta 1.\pPero no bajes la guardia, ¿de\nacuerdo? Los Pokémon salvajes\lpueden aparecer en cualquier\lmomento.\p¡Buena suerte en tu aventura!$"

PineveilTown_CantPassUntilHaveAPokemon_Tile_Text_0:
# 131 "data/maps/LittlerootTown/scripts.pory"
	.string "Ei, você não pode passar por aqui\nainda!\pA Rota 1 pode ser perigosa…\nPokémon selvagens aparecem por lá.$"

PineveilTown_CantPassUntilHaveAPokemon_Tile_Text_1:
# 132 "data/maps/LittlerootTown/scripts.pory"
	.string "Hey, you can't go through here\njust yet!\pRoute 1 can be dangerous… wild\nPokémon appear there.$"

PineveilTown_CantPassUntilHaveAPokemon_Tile_Text_2:
# 133 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Oye, aún no puedes pasar por\naquí!\pLa Ruta 1 puede ser peligrosa…\naparecen Pokémon salvajes.$"

PineveilTown_Signpost_Text_0:
# 142 "data/maps/LittlerootTown/scripts.pory"
	.string "PINEVEIL TOWN\pUma vila serena onde o vento\nsussurra entre os pinheiros.$"

PineveilTown_Signpost_Text_1:
# 143 "data/maps/LittlerootTown/scripts.pory"
	.string "PINEVEIL TOWN\pA quiet village where the wind\nwhispers through the pines.$"

PineveilTown_Signpost_Text_2:
# 144 "data/maps/LittlerootTown/scripts.pory"
	.string "PINEVEIL TOWN\pUn pueblo tranquilo donde el\nviento susurra entre los pinos.$"

PineveilTown_Lab_Signpost_Text_0:
# 151 "data/maps/LittlerootTown/scripts.pory"
	.string "Laboratório de Pesquisas de\nPineveil$"

PineveilTown_Lab_Signpost_Text_1:
# 152 "data/maps/LittlerootTown/scripts.pory"
	.string "Pineveil Research Lab$"

PineveilTown_Lab_Signpost_Text_2:
# 153 "data/maps/LittlerootTown/scripts.pory"
	.string "Laboratorio de Investigación de\nPineveil$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_0:
# 163 "data/maps/LittlerootTown/scripts.pory"
	.string "Mãe$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_1:
# 163 "data/maps/LittlerootTown/scripts.pory"
	.string "Hey, {PLAYER}!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_2:
# 164 "data/maps/LittlerootTown/scripts.pory"
	.string "Mom$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_3:
# 165 "data/maps/LittlerootTown/scripts.pory"
	.string "Mamá$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_4:
# 165 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Hola, {PLAYER}!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_5:
# 179 "data/maps/LittlerootTown/scripts.pory"
	.string "Eu estava ansiosa para conhecer\nseu primeiro Pokémon companheiro.\pEle é lindo e saudável. Que belo\n{STR_VAR_1}.$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_6:
# 180 "data/maps/LittlerootTown/scripts.pory"
	.string "I was excited to meet your first\npartner Pokémon.\pIt looks healthy and beautiful.\nWhat a wonderful {STR_VAR_1}.$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_7:
# 181 "data/maps/LittlerootTown/scripts.pory"
	.string "Estaba ansiosa por conocer a tu\nprimer Pokémon compañero.\pSe ve saludable y hermoso. Qué\nhermoso {STR_VAR_1}.$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_8:
# 188 "data/maps/LittlerootTown/scripts.pory"
	.string "Cuide bem do seu {STR_VAR_1} e\nse divirtam muito juntos!\pAh, e não se esqueça de me visitar\nde vez em quando, ok?$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_9:
# 189 "data/maps/LittlerootTown/scripts.pory"
	.string "Take good care of your {STR_VAR_1}\nand have lots of fun together!\pAh, and don't forget to visit me\nfrom time to time, okay?$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_10:
# 190 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Cuida bien de tu {STR_VAR_1} y\ndiviértanse mucho juntos!\pAh, y no olvides visitarme de vez en\ncuando, ¿de acuerdo?$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_11:
# 197 "data/maps/LittlerootTown/scripts.pory"
	.string "Ah, e mais uma coisa. Quero que\nleve isto com você na sua\laventura. Tome!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_12:
# 198 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, and one more thing. I want you\nto take these with you on your\ladventure. Here!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_13:
# 199 "data/maps/LittlerootTown/scripts.pory"
	.string "Ah, y una cosa más. Quiero que\nlleves esto contigo en tu\laventura. ¡Toma!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_14:
# 205 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} recebeu os {COLOR}{BLUE}Tênis de Corrida{COLOR}{DARK_GRAY}\nde presente!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_15:
# 206 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received {COLOR}{BLUE}Running Shoes{COLOR}{DARK_GRAY}\nas a gift!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_16:
# 207 "data/maps/LittlerootTown/scripts.pory"
	.string "¡{PLAYER} recibió los {COLOR}{BLUE}Zapatos de Correr{COLOR}{DARK_GRAY}\ncomo regalo!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_17:
# 213 "data/maps/LittlerootTown/scripts.pory"
	.string "Estes são os Tênis de Corrida.\pCom eles, você poderá correr\nsempre que quiser.\pBasta segurar o botão {B_BUTTON} enquanto\nanda.\pEles vão deixar sua aventura muito\nmais rápida e divertida!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_18:
# 214 "data/maps/LittlerootTown/scripts.pory"
	.string "These are the Running Shoes.\pWith them, you'll be able to run\nwhenever you want.\pJust hold the {B_BUTTON} Button while\nwalking.\pThey'll make your adventure much\nfaster and more fun!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_19:
# 215 "data/maps/LittlerootTown/scripts.pory"
	.string "Estos son los Zapatos de Correr.\pCon ellos, podrás correr cuando\nquieras.\pSolo mantén presionado el Botón {B_BUTTON}\nmientras caminas.\p¡Harán que tu aventura sea mucho\nmás rápida y divertida!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_20:
# 220 "data/maps/LittlerootTown/scripts.pory"
	.string "Ah, quase me esqueci!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_21:
# 221 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, I almost forgot!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_22:
# 222 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Ah, casi lo olvido!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_23:
# 227 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} recebeu a {COLOR}{BLUE}DexNav{COLOR}{DARK_GRAY} de presente!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_24:
# 228 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received {COLOR}{BLUE}DexNav{COLOR}{DARK_GRAY} as a gift!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_25:
# 229 "data/maps/LittlerootTown/scripts.pory"
	.string "¡{PLAYER} recibió la {COLOR}{BLUE}DexNav{COLOR}{DARK_GRAY} como regalo!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_26:
# 235 "data/maps/LittlerootTown/scripts.pory"
	.string "Ah, e isto aqui é a DexNav.\pEla permite localizar Pokémon\nselvagens nas redondezas e até\ldescobrir informações sobre eles\lantes da batalha.\pQuanto mais você usar, melhor\nficará em encontrar Pokémon raros!\pPara acessá-la, basta abrir o menu\n{START_BUTTON}.$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_27:
# 236 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, and this here is the DexNav.\pIt allows you to locate wild\nPokémon nearby and even learn\linformation about them before\lbattle.\pThe more you use it, the better\nyou'll become at finding rare\lPokémon!\pTo access it, just open the {START_BUTTON}\nmenu.$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_28:
# 237 "data/maps/LittlerootTown/scripts.pory"
	.string "Ah, y esto es la DexNav.\pTe permite localizar Pokémon\nsalvajes cercanos e incluso\ldescubrir información sobre ellos\lantes del combate.\p¡Mientras más la uses, mejor serás\nencontrando Pokémon raros!\pPara acceder a ella, solo abre el\nmenú {START_BUTTON}.$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_29:
# 241 "data/maps/LittlerootTown/scripts.pory"
	.string "Cuide-se, está bem? O mundo lá\nfora é enorme, e muitas coisas\lincríveis esperam por você.\pTenho certeza de que viverá\ngrandes aventuras ao lado do seu\lPokémon.\pE lembre-se: esta sempre será sua\ncasa.$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_30:
# 242 "data/maps/LittlerootTown/scripts.pory"
	.string "Take care of yourself, okay? The\nworld out there is huge, and many\lamazing things are waiting for\lyou.\pI'm sure you'll experience great\nadventures alongside your Pokémon.\pAnd remember: this will always be\nyour home.$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_31:
# 243 "data/maps/LittlerootTown/scripts.pory"
	.string "Cuídate, ¿de acuerdo? El mundo\nallá afuera es enorme, y muchas\lcosas increíbles te esperan.\pEstoy segura de que vivirás\ngrandes aventuras junto a tu\lPokémon.\pY recuerda: esta siempre será tu\nhogar.$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_32:
# 249 "data/maps/LittlerootTown/scripts.pory"
	.string "Edwin$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_33:
# 249 "data/maps/LittlerootTown/scripts.pory"
	.string "Com licença!\nPreciso passar!\pTenho algo urgente para falar com\na Professora!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_34:
# 250 "data/maps/LittlerootTown/scripts.pory"
	.string "Excuse me!\nI need to get through!\pI have something urgent to tell\nthe Professor!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_35:
# 251 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Disculpen!\n¡Necesito pasar!\p¡Tengo algo urgente que hablar con\nla Profesora!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_36:
# 260 "data/maps/LittlerootTown/scripts.pory"
	.string "Vamos, rápido!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_37:
# 261 "data/maps/LittlerootTown/scripts.pory"
	.string "Come on, hurry!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_38:
# 262 "data/maps/LittlerootTown/scripts.pory"
	.string "¡Vamos, rápido!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_39:
# 273 "data/maps/LittlerootTown/scripts.pory"
	.string "Que estranho… Nunca vi alguém tão\ndesesperado assim.\pEspero que não seja nada sério…\nBem, não vou mais atrasar você.\pVá em frente e aproveite sua\naventura!\pEu vou voltar para casa.\nAgora diga tchau!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_40:
# 274 "data/maps/LittlerootTown/scripts.pory"
	.string "That was strange… I've never seen\nsomeone that desperate before.\pI hope it's nothing serious… Well,\nI won't keep you any longer.\pGo on and enjoy your adventure!\pI'll head back home now.\nSee ya!$"

PineveilTown_MomComeToGiveSomeItemsBeforePlayerGone_Text_41:
# 275 "data/maps/LittlerootTown/scripts.pory"
	.string "Qué extraño… Nunca había visto a\nalguien tan desesperado así.\pEspero que no sea nada grave…\nBueno, no voy a retrasarte más.\p¡Sigue adelante y disfruta tu\naventura!\pYo volveré a casa.\nHasta luego!$"
