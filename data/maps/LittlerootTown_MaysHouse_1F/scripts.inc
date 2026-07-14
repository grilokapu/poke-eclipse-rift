LittlerootTown_MaysHouse_1F_MapScripts::
# 6 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD
# 10 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 2 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 19 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	sethealingplacehack MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 7, 7, HEAL_LOCATION_MOM
	end

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 11 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_PLAYERFACING_ROOM, 2
	goto_if_eq LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 14 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_PLAYERFACING_ROOM, 1
	goto_if_eq LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	end

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 15 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 6, 5
	goto LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_PLAYER_MOM_HOUSE_STATE, 0, PineveilTown_Mom_Talk_After_Player_Leaves_Room
# 4 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_PLAYER_MOM_HOUSE_STATE, 1, PineveilTown_Mom_Continue_Talking_Player_OnTV
	.2byte 0

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 20 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_PLAYERFACING_ROOM, 1, PineveilTown_PlayerHouse_Player_LookUp_OnWarp
	.2byte 0


PineveilTown_Mom_Talk_After_Player_Leaves_Room::
# 25 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 26 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 27 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	movenpc LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
# 28 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitse
# 29 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	pause 20
# 30 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkgenderstr
# 31 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	movenpc LOCALID_PLAYERS_HOUSE_1F_MOM, Movement_Mom_GoNext_Player
# 32 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	moveplayer Common_Movement_FaceDown
# 33 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	pause 20
# 34 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_LANGUAGE
# 35 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case PT, PineveilTown_Mom_Talk_After_Player_Leaves_Room_3
# 36 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case EN, PineveilTown_Mom_Talk_After_Player_Leaves_Room_4
# 37 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case ES, PineveilTown_Mom_Talk_After_Player_Leaves_Room_5
PineveilTown_Mom_Talk_After_Player_Leaves_Room_1:
# 39 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Movement_Mom_GoTo_TV
# 40 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Movement_FollowMom_To_TV
# 41 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovementall
# 42 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	pause 20
# 43 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 44 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_PLAYER_MOM_HOUSE_STATE, 1
# 45 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 46 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN, 13, 9
# 47 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitstate
# 48 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
	end

PineveilTown_Mom_Talk_After_Player_Leaves_Room_3:
# 35 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_0, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_Mom_Talk_After_Player_Leaves_Room_1

PineveilTown_Mom_Talk_After_Player_Leaves_Room_4:
# 36 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_2, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_3, MSGBOX_AUTOCLOSE
	goto PineveilTown_Mom_Talk_After_Player_Leaves_Room_1

PineveilTown_Mom_Talk_After_Player_Leaves_Room_5:
# 37 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_4, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_5, MSGBOX_AUTOCLOSE
	goto PineveilTown_Mom_Talk_After_Player_Leaves_Room_1


PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile::
# 53 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 54 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 55 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	movenpc LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_ExclaimFacingDown
# 56 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitse
# 57 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	pause 20
# 58 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	moveplayer Common_Movement_FaceUp
# 59 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkgenderstr
# 60 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	callnative CheckGenderString4
# 61 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_LANGUAGE
# 62 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case PT, PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_3
# 63 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case EN, PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_4
# 64 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case ES, PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_5
PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_1:
# 66 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	movenpc LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceUp
# 67 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_PLAYER_MOM_HOUSE_STATE, 3
# 68 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
	end

PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_3:
# 62 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_0, PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_Text_0, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_1

PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_4:
# 63 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_2, PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_1

PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_5:
# 64 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_4, PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_1


PineveilTown_PlayerHouse_Player_LookUp_OnWarp::
# 73 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_PLAYERFACING_ROOM, 2
# 74 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


PineveilTown_Mom_Continue_Talking_Player_OnTV::
# 79 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 80 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	pause 30
# 81 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceRight
# 82 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
# 83 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovementall
# 84 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	pause 20
# 85 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_LANGUAGE
# 86 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case PT, PineveilTown_Mom_Continue_Talking_Player_OnTV_3
# 87 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case EN, PineveilTown_Mom_Continue_Talking_Player_OnTV_4
# 88 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case ES, PineveilTown_Mom_Continue_Talking_Player_OnTV_5
PineveilTown_Mom_Continue_Talking_Player_OnTV_1:
# 90 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	movenpc LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceUp
# 91 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_PLAYER_MOM_HOUSE_STATE, 2
# 92 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
	end

PineveilTown_Mom_Continue_Talking_Player_OnTV_3:
# 86 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_0, PineveilTown_Mom_Continue_Talking_Player_OnTV_Text_0, MSGBOX_AUTOCLOSE
	goto PineveilTown_Mom_Continue_Talking_Player_OnTV_1

PineveilTown_Mom_Continue_Talking_Player_OnTV_4:
# 87 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_2, PineveilTown_Mom_Continue_Talking_Player_OnTV_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_Mom_Continue_Talking_Player_OnTV_1

PineveilTown_Mom_Continue_Talking_Player_OnTV_5:
# 88 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_4, PineveilTown_Mom_Continue_Talking_Player_OnTV_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_Mom_Continue_Talking_Player_OnTV_1


PineveilTown_PlayerHouse_1F_Mom_Talk::
# 97 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 98 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 99 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkgenderstr
# 100 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, PineveilTown_PlayerHouse_1F_Mom_Talk_2
# 109 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_LANGUAGE
# 110 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case PT, PineveilTown_PlayerHouse_1F_Mom_Talk_6
# 111 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case EN, PineveilTown_PlayerHouse_1F_Mom_Talk_7
# 112 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case ES, PineveilTown_PlayerHouse_1F_Mom_Talk_8
PineveilTown_PlayerHouse_1F_Mom_Talk_4:
# 114 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 115 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end

PineveilTown_PlayerHouse_1F_Mom_Talk_2:
# 101 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_LANGUAGE
# 102 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case PT, PineveilTown_PlayerHouse_1F_Mom_Talk_11
# 103 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case EN, PineveilTown_PlayerHouse_1F_Mom_Talk_12
# 104 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case ES, PineveilTown_PlayerHouse_1F_Mom_Talk_13
PineveilTown_PlayerHouse_1F_Mom_Talk_9:
# 106 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end

PineveilTown_PlayerHouse_1F_Mom_Talk_6:
# 110 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_0, PineveilTown_PlayerHouse_1F_Mom_Talk_Text_3, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerHouse_1F_Mom_Talk_4

PineveilTown_PlayerHouse_1F_Mom_Talk_7:
# 111 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_2, PineveilTown_PlayerHouse_1F_Mom_Talk_Text_4, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerHouse_1F_Mom_Talk_4

PineveilTown_PlayerHouse_1F_Mom_Talk_8:
# 112 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_4, PineveilTown_PlayerHouse_1F_Mom_Talk_Text_5, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerHouse_1F_Mom_Talk_4

PineveilTown_PlayerHouse_1F_Mom_Talk_11:
# 102 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_0, PineveilTown_PlayerHouse_1F_Mom_Talk_Text_0, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerHouse_1F_Mom_Talk_9

PineveilTown_PlayerHouse_1F_Mom_Talk_12:
# 103 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_2, PineveilTown_PlayerHouse_1F_Mom_Talk_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerHouse_1F_Mom_Talk_9

PineveilTown_PlayerHouse_1F_Mom_Talk_13:
# 104 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgminibox PSS_ICON_MOM, PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_4, PineveilTown_PlayerHouse_1F_Mom_Talk_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_PlayerHouse_1F_Mom_Talk_9


# 119 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
Movement_Mom_GoNext_Player:
# 120 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 120 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 120 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 121 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 121 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 121 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 122 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	face_up
	step_end

# 125 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
Movement_Mom_GoTo_TV:
# 126 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 126 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 127 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 127 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 127 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 127 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 128 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	face_up
	step_end

# 131 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
Movement_FollowMom_To_TV:
# 132 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 132 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 132 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 133 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 133 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 133 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 134 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	face_up
	step_end

PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_0:
# 35 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Mãe$"

PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_1:
# 35 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {PLAYER}! Ainda bem que você\nacordou… Eu já estava começando a\lficar preocupada.\pVocê dormiu muito além do normal\nhoje.\pHm? O que foi?\nVocê parece um pouco estranh{STR_VAR_1}…\lEstá se sentindo bem?\pEspero que sim, porque hoje é um\ndia muito importante.\pA temporada oficial para novos\ntreinadores na região de Aetheris\lfinalmente começou!\pE olha só, a Professora Hikari vai\naparecer ao vivo na TV daqui a\linstantes.\pVenha rápido assistir!$"

PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_2:
# 36 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Mom$"

PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_3:
# 36 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {PLAYER}! Thank goodness\nyou're awake… I was starting to\lget worried.\pYou slept way longer than usual\ntoday.\pHm? What's wrong?\nYou seem a little off… Are you\lfeeling alright?\pI hope so, because today is a very\nimportant day.\pThe official season for new\nTrainers in the Aetheris region\lhas finally begun!\pAnd look, Professor Hikari is\nabout to appear live on TV any\lmoment now.\pCome quickly and watch!$"

PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_4:
# 37 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Mami$"

PineveilTown_Mom_Talk_After_Player_Leaves_Room_Text_5:
# 37 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "¡Oh, {PLAYER}! Menos mal que\ndespertaste… Ya empezaba a\lpreocuparme.\pHoy dormiste mucho más de lo\nnormal.\p¿Hm? ¿Qué ocurre?\nTe ves un poco extrañ{STR_VAR_1}… ¿Te\lsientes bien?\pEso espero, porque hoy es un día\nmuy importante.\p¡La temporada oficial para nuevos\nentrenadores en la región de\lAetheris por fin ha comenzado!\pY mira, la Profesora Hikari\naparecerá en vivo por televisión\len cualquier momento.\p¡Ven rápido a verla!$"

PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_Text_0:
# 62 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{STR_VAR_2} querid{STR_VAR_1}, tome cuidado durante\nsua jornada.\pNem todas as pessoas que se\naproximarem de você terão boas\lintenções. O mundo pode ser muito\lmais cruel do que parece.\pNunca perca de vista o seu\nobjetivo... e mostre a todos que\lvocê pode se tornar o maior\ltreinador de Aetheris.$"

PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_Text_1:
# 63 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "My dear, be careful on your\njourney.\pNot everyone who approaches you\nwill have good intentions. The\lworld can be far harsher than it\lseems.\pNever lose sight of your goal...\nand show everyone that you can\lbecome the greatest Trainer in\lAetheris.$"

PineveilTown_PlayerHouse_Mom_Talk_On1stExit_Tile_Text_2:
# 64 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Mi querid{STR_VAR_1}, ten cuidado durante tu\nviaje.\pNo todas las personas que se\nacerquen a ti tendrán buenas\lintenciones. El mundo puede ser\lmucho más cruel de lo que parece.\pNunca pierdas de vista tu\nobjetivo... y demuestra a todos\lque puedes convertirte en el mejor\lentrenador de Aetheris.$"

PineveilTown_Mom_Continue_Talking_Player_OnTV_Text_0:
# 86 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Hehe… a Professora Hikari sempre\nfala dessas coisas com tanto\lentusiasmo.\pMas é estranho pensar que… hoje\nfinalmente chegou o seu momento.\pParece que foi ontem que você mal\nconseguia segurar uma Poké Ball.\pE agora… vai começar sua própria\njornada.\pAh, antes que eu esqueça!\pA Professora Hikari pediu para\ntodos os novos treinadores irem ao\llaboratório dela hoje.\pEla disse que preparou algo\nespecial para os iniciantes deste\lano.\pEntão não faça a professora\nesperar, certo?\pE… cuide-se lá fora, {PLAYER}.\pAetheris pode ser uma região\nlinda… mas existem lugares que é\lmelhor evitar sozinho.\p...\pBom! Já falei demais.\nVá logo antes que chegue tarde!$"

PineveilTown_Mom_Continue_Talking_Player_OnTV_Text_1:
# 87 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Hehe… Professor Hikari always\ntalks about these things with so\lmuch enthusiasm.\pBut it's strange to think that…\ntoday is finally your moment.\pIt feels like just yesterday you\ncould barely hold a Poké Ball.\pAnd now… you're about to begin\nyour very own journey.\pAh, before I forget!\nProfessor Hikari asked all the new\lTrainers to go to her laboratory\ltoday.\pShe said she prepared something\nspecial for this year's beginners.\pSo don't keep the professor\nwaiting, alright?\pAnd… be careful out there,\n{PLAYER}.\pAetheris may be a beautiful\nregion… but there are places\lbetter not explored alone.\p...\pWell! I've talked long enough.\nYou should get going before you're\llate!$"

PineveilTown_Mom_Continue_Talking_Player_OnTV_Text_2:
# 88 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Jeje… La Profesora Hikari siempre\nhabla de estas cosas con tanto\lentusiasmo.\pPero es extraño pensar que… hoy\nfinalmente llegó tu momento.\pParece que fue ayer cuando apenas\npodías sostener una Poké Ball.\pY ahora… estás a punto de comenzar\ntu propia aventura.\p¡Ah, antes de que lo olvide!\nLa Profesora Hikari pidió que\ltodos los nuevos entrenadores\lfueran hoy a su laboratorio.\pDijo que preparó algo especial\npara los principiantes de este\laño.\pAsí que no hagas esperar a la\nprofesora, ¿de acuerdo?\pY… cuídate ahí fuera, {PLAYER}.\pAetheris puede ser una región\nhermosa… pero hay lugares que es\lmejor no explorar solo.\p...\p¡Bueno! Ya hablé demasiado.\nSerá mejor que te vayas antes de\lque llegues tarde!$"

PineveilTown_PlayerHouse_1F_Mom_Talk_Text_0:
# 102 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{PLAYER}, você ainda não foi?\pO laboratório da Professora Hikari\nfica logo ali.\lNão faça ela esperar!$"

PineveilTown_PlayerHouse_1F_Mom_Talk_Text_1:
# 103 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{PLAYER}, you haven't gone yet?\pProfessor Hikari's laboratory is\nright over there.\lDon't make her wait!$"

PineveilTown_PlayerHouse_1F_Mom_Talk_Text_2:
# 104 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "{PLAYER}, ¿todavía no has ido?\pEl laboratorio de la Profesora Hikari\nestá justo allí.\lNo la hagas esperar!$"

PineveilTown_PlayerHouse_1F_Mom_Talk_Text_3:
# 110 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {PLAYER}! Você voltou?\pVocê parece cansado…\nSua jornada deve estar sendo mais\ldifícil do que imaginava.\pMas eu consigo ver nos seus olhos…\nVocê já está mudando.\pHehe… acho que isso faz parte de\ncrescer como treinador.\pVenha cá por um instante.\nVocê precisa descansar um pouco.\pUma bom cochilo sempre ajuda\na clarear a mente.$"

PineveilTown_PlayerHouse_1F_Mom_Talk_Text_4:
# 111 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {PLAYER}! You're back?\pYou look exhausted...\nYour journey must be harder than\lyou expected.\pBut I can see it in your eyes...\nYou're already changing.\pHehe... I guess that's part of\ngrowing as a Trainer.\pCome here for a moment.\nYou need to get some rest.\pA good nap always helps clear the\nmind.$"

PineveilTown_PlayerHouse_1F_Mom_Talk_Text_5:
# 112 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "¡Oh, {PLAYER}! ¿Has vuelto?\pPareces cansado…\nTu aventura debe estar siendo más\ldifícil de lo que imaginabas.\pPero puedo verlo en tus ojos…\nYa estás cambiando.\pJeje… supongo que eso forma parte\nde crecer como entrenador.\pVen aquí un momento.\nNecesitas descansar un poco.\pUna buena siesta siempre ayuda a\ndespejar la mente.$"
