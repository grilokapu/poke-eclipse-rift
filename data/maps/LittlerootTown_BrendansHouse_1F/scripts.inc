LittlerootTown_BrendansHouse_1F_MapScripts::
	.byte 0


PineveilTown_RivalMom_talk::
# 5 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lock
# 6 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	faceplayer
# 7 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_set FLAG_RIVAL_LEAVE_HOUSE, PineveilTown_RivalMom_talk_2
# 14 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	switch VAR_LANGUAGE
# 15 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case PT, PineveilTown_RivalMom_talk_10
# 16 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case EN, PineveilTown_RivalMom_talk_11
# 17 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case ES, PineveilTown_RivalMom_talk_12
PineveilTown_RivalMom_talk_1:
# 20 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	release
	end

PineveilTown_RivalMom_talk_2:
# 8 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	switch VAR_LANGUAGE
# 9 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case PT, PineveilTown_RivalMom_talk_6
# 10 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case EN, PineveilTown_RivalMom_talk_7
# 11 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case ES, PineveilTown_RivalMom_talk_8
	goto PineveilTown_RivalMom_talk_1

PineveilTown_RivalMom_talk_6:
# 9 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalMom_talk_Text_0, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalMom_talk_1

PineveilTown_RivalMom_talk_7:
# 10 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalMom_talk_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalMom_talk_1

PineveilTown_RivalMom_talk_8:
# 11 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalMom_talk_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalMom_talk_1

PineveilTown_RivalMom_talk_10:
# 15 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalMom_talk_Text_3, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalMom_talk_1

PineveilTown_RivalMom_talk_11:
# 16 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalMom_talk_Text_4, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalMom_talk_1

PineveilTown_RivalMom_talk_12:
# 17 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalMom_talk_Text_5, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalMom_talk_1


PineveilTown_RivalHouse_Mom_Tile::
# 25 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_unset FLAG_RIVAL_LEAVE_HOUSE, PineveilTown_RivalHouse_Mom_Tile_1
# 29 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lock
# 30 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 31 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	movenpc LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
# 32 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitse
# 33 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 34 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	moveplayer Common_Movement_FaceUp
# 35 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 36 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	copyvar VAR_RESULT, VAR_TEMP_0
# 37 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq PineveilTown_RivalHouse_Mom_Tile_5
# 40 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	movenpc LOCALID_RIVAL_MOM, Movement_RivalMom_GotoPlayer_1
PineveilTown_RivalHouse_Mom_Tile_4:
# 42 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	switch VAR_LANGUAGE
# 43 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case PT, PineveilTown_RivalHouse_Mom_Tile_10
# 44 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case EN, PineveilTown_RivalHouse_Mom_Tile_11
# 45 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case ES, PineveilTown_RivalHouse_Mom_Tile_12
PineveilTown_RivalHouse_Mom_Tile_8:
# 47 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	giveitem ITEM_TOWN_MAP
# 48 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitfanfare
# 49 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 20
# 50 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	switch VAR_LANGUAGE
# 51 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case PT, PineveilTown_RivalHouse_Mom_Tile_15
# 52 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case EN, PineveilTown_RivalHouse_Mom_Tile_16
# 53 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case ES, PineveilTown_RivalHouse_Mom_Tile_17
PineveilTown_RivalHouse_Mom_Tile_13:
# 55 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq PineveilTown_RivalHouse_Mom_Tile_19
# 58 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	movenpc LOCALID_RIVAL_MOM, Movement_RivalMom_GoAwayPlayer_1
PineveilTown_RivalHouse_Mom_Tile_18:
# 60 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_RIVAL_HOUSE_STATE, 1
# 61 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	release
	end

PineveilTown_RivalHouse_Mom_Tile_1:
# 26 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	release
	end

PineveilTown_RivalHouse_Mom_Tile_5:
# 38 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	movenpc LOCALID_RIVAL_MOM, Movement_RivalMom_GotoPlayer_0
	goto PineveilTown_RivalHouse_Mom_Tile_4

PineveilTown_RivalHouse_Mom_Tile_10:
# 43 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalHouse_Mom_Tile_Text_0, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalHouse_Mom_Tile_8

PineveilTown_RivalHouse_Mom_Tile_11:
# 44 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalHouse_Mom_Tile_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalHouse_Mom_Tile_8

PineveilTown_RivalHouse_Mom_Tile_12:
# 45 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalHouse_Mom_Tile_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalHouse_Mom_Tile_8

PineveilTown_RivalHouse_Mom_Tile_15:
# 51 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalHouse_Mom_Tile_Text_3, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalHouse_Mom_Tile_13

PineveilTown_RivalHouse_Mom_Tile_16:
# 52 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalHouse_Mom_Tile_Text_4, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalHouse_Mom_Tile_13

PineveilTown_RivalHouse_Mom_Tile_17:
# 53 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PineveilTown_RivalHouse_Mom_Tile_Text_5, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalHouse_Mom_Tile_13

PineveilTown_RivalHouse_Mom_Tile_19:
# 56 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	movenpc LOCALID_RIVAL_MOM, Movement_RivalMom_GoAwayPlayer_0
	goto PineveilTown_RivalHouse_Mom_Tile_18


# 66 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
Movement_RivalMom_GotoPlayer_0:
# 67 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 68 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_down
# 69 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	face_down
	step_end

# 72 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
Movement_RivalMom_GotoPlayer_1:
# 73 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 73 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 74 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_down
# 75 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	face_down
	step_end

# 78 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
Movement_RivalMom_GoAwayPlayer_0:
# 79 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 80 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 81 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	face_up
	step_end

# 84 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
Movement_RivalMom_GoAwayPlayer_1:
# 85 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 86 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 86 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 87 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	face_up
	step_end

PineveilTown_RivalMom_talk_Text_0:
# 9 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Nossa chegada em Aetheris tem sido\nincrível até agora.\pEspero que a gente se acostume\nrápido com a nova vida por aqui.$"

PineveilTown_RivalMom_talk_Text_1:
# 10 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Our arrival in Aetheris has been\nwonderful so far.\pI hope we can settle into our new\nlife here soon.$"

PineveilTown_RivalMom_talk_Text_2:
# 11 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Nuestra llegada a Aetheris ha sido\nmaravillosa hasta ahora.\pEspero que podamos adaptarnos\nrápido a nuestra nueva vida aquí.$"

PineveilTown_RivalMom_talk_Text_3:
# 15 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh! Você também veio para a\nseleção dos treinadores?\pDesculpe… Achei que meu filho já\ntivesse saído do quarto, mas ele\lainda está lá dentro.\pEsse garoto vive trancado\norganizando livros e anotações...\pEspero que ele não acabe perdendo\no primeiro dia da jornada em\lAetheris.$"

PineveilTown_RivalMom_talk_Text_4:
# 16 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh! Did you come for the Trainer\nselection too?\pSorry... I thought my son had\nalready left his room, but he's\lstill in there.\pThat boy is always locked away\norganizing books and notes...\pI just hope he doesn't end up\nmissing the first day of the\ljourney in Aetheris.$"

PineveilTown_RivalMom_talk_Text_5:
# 17 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "¡Oh! ¿Tú también viniste para la\nselección de entrenadores?\pLo siento... Pensé que mi hijo ya\nhabía salido de su habitación,\lpero todavía sigue allí dentro.\pEse chico vive encerrado\norganizando libros y apuntes...\pSolo espero que no termine\nperdiéndose el primer día de la\laventura en Aetheris.$"

PineveilTown_RivalHouse_Mom_Tile_Text_0:
# 43 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Ah, {PLAYER}!\nO meu filho saiu às pressas!\pEle acabou esquecendo o Mapa da\nRegião…\pSabe de uma coisa? Pode ficar com\nele!$"

PineveilTown_RivalHouse_Mom_Tile_Text_1:
# 44 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, {PLAYER}!\nMy son rushed out in a hurry!\pHe ended up forgetting the Region\nMap…\pYou know what? You can keep it!$"

PineveilTown_RivalHouse_Mom_Tile_Text_2:
# 45 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "¡Ah, {PLAYER}!\n¡Mi hijo salió con mucha prisa!\pTerminó olvidando el Mapa de la\nRegión…\p¿Sabes qué? ¡Puedes quedártelo!$"

PineveilTown_RivalHouse_Mom_Tile_Text_3:
# 51 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Cuide-se na sua jornada, {PLAYER}!\nE, por favor, fique de olho no\lmeu filho de vez em quando.\pEspero ver vocês dois novamente em\nbreve!$"

PineveilTown_RivalHouse_Mom_Tile_Text_4:
# 52 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Take care on your journey,\n{PLAYER}!\lAnd please, keep an eye on\lmy son every now and then.\pI hope to see you both again soon!$"

PineveilTown_RivalHouse_Mom_Tile_Text_5:
# 53 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "¡Cuídate en tu aventura, {PLAYER}!\nY, por favor, cuida de mi hijo\lde vez en cuando.\p¡Espero verlos a los dos otra vez\nmuy pronto!$"
