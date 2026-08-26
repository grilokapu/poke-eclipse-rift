StonereachCity_Gym_MapScripts::
	.byte 0


StonereachCity_Gym_EventScript_Anorith::
# 4 "data/maps/StonereachCity_Gym/scripts.pory"
	lock
# 5 "data/maps/StonereachCity_Gym/scripts.pory"
	faceplayer
# 6 "data/maps/StonereachCity_Gym/scripts.pory"
	showmonmugshot SPECIES_ANORITH, MUGSHOT_SOUTHEAST
# 7 "data/maps/StonereachCity_Gym/scripts.pory"
	setspeaker StonereachCity_Gym_EventScript_Anorith_Text_0
# 8 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Anorith_Text_1, MSGBOX_AUTOCLOSE
# 9 "data/maps/StonereachCity_Gym/scripts.pory"
	waitmoncry
# 10 "data/maps/StonereachCity_Gym/scripts.pory"
	hidemonmugshot
# 11 "data/maps/StonereachCity_Gym/scripts.pory"
	release
	end


StonereachCity_Gym_EventScript_Roxanne::
# 16 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 17 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_Roxanne_3
# 18 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_Roxanne_4
# 19 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_Roxanne_5
StonereachCity_Gym_EventScript_Roxanne_1:
# 21 "data/maps/StonereachCity_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 22 "data/maps/StonereachCity_Gym/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq StonereachCity_Gym_EventScript_Roxanne_7
StonereachCity_Gym_EventScript_Roxanne_6:
# 25 "data/maps/StonereachCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, StonereachCity_Gym_EventScript_Roxanne_10
StonereachCity_Gym_EventScript_Roxanne_9:
# 28 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 29 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_Roxanne_14
# 30 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_Roxanne_15
# 31 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_Roxanne_16
StonereachCity_Gym_EventScript_Roxanne_12:
# 33 "data/maps/StonereachCity_Gym/scripts.pory"
	release
	end

StonereachCity_Gym_EventScript_Roxanne_3:
# 17 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LEADER_ALDREN, StonereachCity_Gym_EventScript_Roxanne_Text_0, StonereachCity_Gym_EventScript_Roxanne_Text_1, StonereachCity_Gym_EventScript_RoxanneDefeated
	goto StonereachCity_Gym_EventScript_Roxanne_1

StonereachCity_Gym_EventScript_Roxanne_4:
# 18 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LEADER_ALDREN, StonereachCity_Gym_EventScript_Roxanne_Text_2, StonereachCity_Gym_EventScript_Roxanne_Text_3, StonereachCity_Gym_EventScript_RoxanneDefeated
	goto StonereachCity_Gym_EventScript_Roxanne_1

StonereachCity_Gym_EventScript_Roxanne_5:
# 19 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LEADER_ALDREN, StonereachCity_Gym_EventScript_Roxanne_Text_4, StonereachCity_Gym_EventScript_Roxanne_Text_5, StonereachCity_Gym_EventScript_RoxanneDefeated
	goto StonereachCity_Gym_EventScript_Roxanne_1

StonereachCity_Gym_EventScript_Roxanne_7:
# 23 "data/maps/StonereachCity_Gym/scripts.pory"
	goto StonereachCity_Gym_EventScript_RoxanneRematch
	goto StonereachCity_Gym_EventScript_Roxanne_6

StonereachCity_Gym_EventScript_Roxanne_10:
# 26 "data/maps/StonereachCity_Gym/scripts.pory"
	goto StonereachCity_Gym_EventScript_GiveRockTomb
	goto StonereachCity_Gym_EventScript_Roxanne_9

StonereachCity_Gym_EventScript_Roxanne_14:
# 29 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Roxanne_Text_6, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_Roxanne_12

StonereachCity_Gym_EventScript_Roxanne_15:
# 30 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Roxanne_Text_7, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_Roxanne_12

StonereachCity_Gym_EventScript_Roxanne_16:
# 31 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Roxanne_Text_8, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_Roxanne_12


StonereachCity_Gym_EventScript_RoxanneDefeated::
# 38 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 39 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_RoxanneDefeated_3
# 40 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_RoxanneDefeated_4
# 41 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_RoxanneDefeated_5
StonereachCity_Gym_EventScript_RoxanneDefeated_1:
# 43 "data/maps/StonereachCity_Gym/scripts.pory"
	waitmessage
# 44 "data/maps/StonereachCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 45 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 46 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_RoxanneDefeated_8
# 47 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_RoxanneDefeated_9
# 48 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_RoxanneDefeated_10
StonereachCity_Gym_EventScript_RoxanneDefeated_6:
# 50 "data/maps/StonereachCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_STONEREACH_GYM
# 51 "data/maps/StonereachCity_Gym/scripts.pory"
	setflag FLAG_BADGE01_GET
# 52 "data/maps/StonereachCity_Gym/scripts.pory"
	setvar VAR_STONEREACH_CITY_STATE, 1
# 53 "data/maps/StonereachCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 54 "data/maps/StonereachCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 55 "data/maps/StonereachCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 56 "data/maps/StonereachCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 57 "data/maps/StonereachCity_Gym/scripts.pory"
	goto StonereachCity_Gym_EventScript_GiveRockTomb
	return

StonereachCity_Gym_EventScript_RoxanneDefeated_3:
# 39 "data/maps/StonereachCity_Gym/scripts.pory"
	message StonereachCity_Gym_EventScript_RoxanneDefeated_Text_0
	goto StonereachCity_Gym_EventScript_RoxanneDefeated_1

StonereachCity_Gym_EventScript_RoxanneDefeated_4:
# 40 "data/maps/StonereachCity_Gym/scripts.pory"
	message StonereachCity_Gym_EventScript_RoxanneDefeated_Text_1
	goto StonereachCity_Gym_EventScript_RoxanneDefeated_1

StonereachCity_Gym_EventScript_RoxanneDefeated_5:
# 41 "data/maps/StonereachCity_Gym/scripts.pory"
	message StonereachCity_Gym_EventScript_RoxanneDefeated_Text_2
	goto StonereachCity_Gym_EventScript_RoxanneDefeated_1

StonereachCity_Gym_EventScript_RoxanneDefeated_8:
# 46 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_RoxanneDefeated_Text_3, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_RoxanneDefeated_6

StonereachCity_Gym_EventScript_RoxanneDefeated_9:
# 47 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_RoxanneDefeated_Text_4, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_RoxanneDefeated_6

StonereachCity_Gym_EventScript_RoxanneDefeated_10:
# 48 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_RoxanneDefeated_Text_5, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_RoxanneDefeated_6


StonereachCity_Gym_EventScript_GiveRockTomb::
# 61 "data/maps/StonereachCity_Gym/scripts.pory"
	giveitem ITEM_TM_ROCK_TOMB
# 62 "data/maps/StonereachCity_Gym/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq StonereachCity_Gym_EventScript_GiveRockTomb_2
StonereachCity_Gym_EventScript_GiveRockTomb_1:
# 65 "data/maps/StonereachCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
# 66 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 67 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_GiveRockTomb_6
# 68 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_GiveRockTomb_7
# 69 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_GiveRockTomb_8
StonereachCity_Gym_EventScript_GiveRockTomb_4:
# 71 "data/maps/StonereachCity_Gym/scripts.pory"
	release
	end

StonereachCity_Gym_EventScript_GiveRockTomb_2:
# 63 "data/maps/StonereachCity_Gym/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto StonereachCity_Gym_EventScript_GiveRockTomb_1

StonereachCity_Gym_EventScript_GiveRockTomb_6:
# 67 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GiveRockTomb_Text_0, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GiveRockTomb_4

StonereachCity_Gym_EventScript_GiveRockTomb_7:
# 68 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GiveRockTomb_Text_1, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GiveRockTomb_4

StonereachCity_Gym_EventScript_GiveRockTomb_8:
# 69 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GiveRockTomb_Text_2, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GiveRockTomb_4


StonereachCity_Gym_EventScript_RoxanneRematch::
# 76 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 77 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_RoxanneRematch_3
# 78 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_RoxanneRematch_4
# 79 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_RoxanneRematch_5
StonereachCity_Gym_EventScript_RoxanneRematch_1:
# 81 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 82 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_RoxanneRematch_8
# 83 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_RoxanneRematch_9
# 84 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_RoxanneRematch_10
StonereachCity_Gym_EventScript_RoxanneRematch_6:
	end

StonereachCity_Gym_EventScript_RoxanneRematch_3:
# 77 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_ROXANNE_1, StonereachCity_Gym_EventScript_RoxanneRematch_Text_0, StonereachCity_Gym_EventScript_RoxanneRematch_Text_1, StonereachCity_Gym_EventScript_RoxanneRematch_Text_2
	goto StonereachCity_Gym_EventScript_RoxanneRematch_1

StonereachCity_Gym_EventScript_RoxanneRematch_4:
# 78 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_ROXANNE_1, StonereachCity_Gym_EventScript_RoxanneRematch_Text_3, StonereachCity_Gym_EventScript_RoxanneRematch_Text_4, StonereachCity_Gym_EventScript_RoxanneRematch_Text_5
	goto StonereachCity_Gym_EventScript_RoxanneRematch_1

StonereachCity_Gym_EventScript_RoxanneRematch_5:
# 79 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_ROXANNE_1, StonereachCity_Gym_EventScript_RoxanneRematch_Text_6, StonereachCity_Gym_EventScript_RoxanneRematch_Text_7, StonereachCity_Gym_EventScript_RoxanneRematch_Text_8
	goto StonereachCity_Gym_EventScript_RoxanneRematch_1

StonereachCity_Gym_EventScript_RoxanneRematch_8:
# 82 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_RoxanneRematch_Text_9, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_RoxanneRematch_6

StonereachCity_Gym_EventScript_RoxanneRematch_9:
# 83 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_RoxanneRematch_Text_10, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_RoxanneRematch_6

StonereachCity_Gym_EventScript_RoxanneRematch_10:
# 84 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_RoxanneRematch_Text_11, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_RoxanneRematch_6


StonereachCity_Gym_EventScript_Rick::
# 90 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 91 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_Rick_3
# 92 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_Rick_4
# 93 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_Rick_5
StonereachCity_Gym_EventScript_Rick_1:
# 95 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 96 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_Rick_8
# 97 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_Rick_9
# 98 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_Rick_10
StonereachCity_Gym_EventScript_Rick_6:
	end

StonereachCity_Gym_EventScript_Rick_3:
# 91 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RUIN_MANIAC_RICK, StonereachCity_Gym_EventScript_Rick_Text_0, StonereachCity_Gym_EventScript_Rick_Text_1
	goto StonereachCity_Gym_EventScript_Rick_1

StonereachCity_Gym_EventScript_Rick_4:
# 92 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RUIN_MANIAC_RICK, StonereachCity_Gym_EventScript_Rick_Text_2, StonereachCity_Gym_EventScript_Rick_Text_3
	goto StonereachCity_Gym_EventScript_Rick_1

StonereachCity_Gym_EventScript_Rick_5:
# 93 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RUIN_MANIAC_RICK, StonereachCity_Gym_EventScript_Rick_Text_4, StonereachCity_Gym_EventScript_Rick_Text_5
	goto StonereachCity_Gym_EventScript_Rick_1

StonereachCity_Gym_EventScript_Rick_8:
# 96 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Rick_Text_6, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_Rick_6

StonereachCity_Gym_EventScript_Rick_9:
# 97 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Rick_Text_7, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_Rick_6

StonereachCity_Gym_EventScript_Rick_10:
# 98 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Rick_Text_8, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_Rick_6


StonereachCity_Gym_EventScript_Tommy::
# 104 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 105 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_Tommy_3
# 106 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_Tommy_4
# 107 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_Tommy_5
StonereachCity_Gym_EventScript_Tommy_1:
# 109 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 110 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_Tommy_8
# 111 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_Tommy_9
# 112 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_Tommy_10
StonereachCity_Gym_EventScript_Tommy_6:
	end

StonereachCity_Gym_EventScript_Tommy_3:
# 105 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RUIN_MANIAC_TOMMY, StonereachCity_Gym_EventScript_Tommy_Text_0, StonereachCity_Gym_EventScript_Tommy_Text_1
	goto StonereachCity_Gym_EventScript_Tommy_1

StonereachCity_Gym_EventScript_Tommy_4:
# 106 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RUIN_MANIAC_TOMMY, StonereachCity_Gym_EventScript_Tommy_Text_2, StonereachCity_Gym_EventScript_Tommy_Text_3
	goto StonereachCity_Gym_EventScript_Tommy_1

StonereachCity_Gym_EventScript_Tommy_5:
# 107 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RUIN_MANIAC_TOMMY, StonereachCity_Gym_EventScript_Tommy_Text_4, StonereachCity_Gym_EventScript_Tommy_Text_5
	goto StonereachCity_Gym_EventScript_Tommy_1

StonereachCity_Gym_EventScript_Tommy_8:
# 110 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Tommy_Text_6, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_Tommy_6

StonereachCity_Gym_EventScript_Tommy_9:
# 111 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Tommy_Text_7, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_Tommy_6

StonereachCity_Gym_EventScript_Tommy_10:
# 112 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Tommy_Text_8, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_Tommy_6


StonereachCity_Gym_EventScript_Marc::
# 118 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 119 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_Marc_3
# 120 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_Marc_4
# 121 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_Marc_5
StonereachCity_Gym_EventScript_Marc_1:
# 123 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 124 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_Marc_8
# 125 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_Marc_9
# 126 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_Marc_10
StonereachCity_Gym_EventScript_Marc_6:
	end

StonereachCity_Gym_EventScript_Marc_3:
# 119 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HIKER_MARC, StonereachCity_Gym_EventScript_Marc_Text_0, StonereachCity_Gym_EventScript_Marc_Text_1
	goto StonereachCity_Gym_EventScript_Marc_1

StonereachCity_Gym_EventScript_Marc_4:
# 120 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HIKER_MARC, StonereachCity_Gym_EventScript_Marc_Text_2, StonereachCity_Gym_EventScript_Marc_Text_3
	goto StonereachCity_Gym_EventScript_Marc_1

StonereachCity_Gym_EventScript_Marc_5:
# 121 "data/maps/StonereachCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HIKER_MARC, StonereachCity_Gym_EventScript_Marc_Text_4, StonereachCity_Gym_EventScript_Marc_Text_5
	goto StonereachCity_Gym_EventScript_Marc_1

StonereachCity_Gym_EventScript_Marc_8:
# 124 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Marc_Text_6, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_Marc_6

StonereachCity_Gym_EventScript_Marc_9:
# 125 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Marc_Text_7, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_Marc_6

StonereachCity_Gym_EventScript_Marc_10:
# 126 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_Marc_Text_8, MSGBOX_AUTOCLOSE
	goto StonereachCity_Gym_EventScript_Marc_6


StonereachCity_Gym_EventScript_GymGuide::
# 132 "data/maps/StonereachCity_Gym/scripts.pory"
	lock
# 133 "data/maps/StonereachCity_Gym/scripts.pory"
	faceplayer
# 134 "data/maps/StonereachCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_STONEREACH_GYM, StonereachCity_Gym_EventScript_GymGuide_2
# 141 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 142 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_GymGuide_10
# 143 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_GymGuide_11
# 144 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_GymGuide_12
StonereachCity_Gym_EventScript_GymGuide_1:
# 147 "data/maps/StonereachCity_Gym/scripts.pory"
	release
	end

StonereachCity_Gym_EventScript_GymGuide_2:
# 135 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 136 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_GymGuide_6
# 137 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_GymGuide_7
# 138 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_GymGuide_8
	goto StonereachCity_Gym_EventScript_GymGuide_1

StonereachCity_Gym_EventScript_GymGuide_6:
# 136 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymGuide_Text_0, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymGuide_1

StonereachCity_Gym_EventScript_GymGuide_7:
# 137 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymGuide_Text_1, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymGuide_1

StonereachCity_Gym_EventScript_GymGuide_8:
# 138 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymGuide_Text_2, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymGuide_1

StonereachCity_Gym_EventScript_GymGuide_10:
# 142 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymGuide_Text_3, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymGuide_1

StonereachCity_Gym_EventScript_GymGuide_11:
# 143 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymGuide_Text_4, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymGuide_1

StonereachCity_Gym_EventScript_GymGuide_12:
# 144 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymGuide_Text_5, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymGuide_1


StonereachCity_Gym_EventScript_RegisterRoxanne::
# 152 "data/maps/StonereachCity_Gym/scripts.pory"
	lockall
# 153 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 154 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_RegisterRoxanne_3
# 155 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_RegisterRoxanne_4
# 156 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_RegisterRoxanne_5
StonereachCity_Gym_EventScript_RegisterRoxanne_1:
# 158 "data/maps/StonereachCity_Gym/scripts.pory"
	waitmessage
# 159 "data/maps/StonereachCity_Gym/scripts.pory"
	pause 30
# 160 "data/maps/StonereachCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 161 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 162 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_RegisterRoxanne_8
# 163 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_RegisterRoxanne_9
# 164 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_RegisterRoxanne_10
StonereachCity_Gym_EventScript_RegisterRoxanne_6:
# 166 "data/maps/StonereachCity_Gym/scripts.pory"
	waitfanfare
# 167 "data/maps/StonereachCity_Gym/scripts.pory"
	closemessage
# 168 "data/maps/StonereachCity_Gym/scripts.pory"
	pause 30
# 169 "data/maps/StonereachCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
# 170 "data/maps/StonereachCity_Gym/scripts.pory"
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 171 "data/maps/StonereachCity_Gym/scripts.pory"
	releaseall
	end

StonereachCity_Gym_EventScript_RegisterRoxanne_3:
# 154 "data/maps/StonereachCity_Gym/scripts.pory"
	pokenavcall StonereachCity_Gym_Text_AldrenRegisterCall_PT
	goto StonereachCity_Gym_EventScript_RegisterRoxanne_1

StonereachCity_Gym_EventScript_RegisterRoxanne_4:
# 155 "data/maps/StonereachCity_Gym/scripts.pory"
	pokenavcall StonereachCity_Gym_Text_AldrenRegisterCall_EN
	goto StonereachCity_Gym_EventScript_RegisterRoxanne_1

StonereachCity_Gym_EventScript_RegisterRoxanne_5:
# 156 "data/maps/StonereachCity_Gym/scripts.pory"
	pokenavcall StonereachCity_Gym_Text_AldrenRegisterCall_ES
	goto StonereachCity_Gym_EventScript_RegisterRoxanne_1

StonereachCity_Gym_EventScript_RegisterRoxanne_8:
# 162 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_RegisterRoxanne_Text_0, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_RegisterRoxanne_6

StonereachCity_Gym_EventScript_RegisterRoxanne_9:
# 163 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_RegisterRoxanne_Text_1, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_RegisterRoxanne_6

StonereachCity_Gym_EventScript_RegisterRoxanne_10:
# 164 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_RegisterRoxanne_Text_2, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_RegisterRoxanne_6


StonereachCity_Gym_EventScript_LeftGymStatue::
# 188 "data/maps/StonereachCity_Gym/scripts.pory"
	lockall
# 189 "data/maps/StonereachCity_Gym/scripts.pory"
	goto StonereachCity_Gym_EventScript_GymStatue
	return


StonereachCity_Gym_EventScript_RightGymStatue::
# 193 "data/maps/StonereachCity_Gym/scripts.pory"
	lockall
# 194 "data/maps/StonereachCity_Gym/scripts.pory"
	goto StonereachCity_Gym_EventScript_GymStatue
	return


StonereachCity_Gym_EventScript_GymStatue::
# 198 "data/maps/StonereachCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, StonereachCity_Gym_EventScript_GymStatue_2
# 205 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 206 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_GymStatue_10
# 207 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_GymStatue_11
# 208 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_GymStatue_12
StonereachCity_Gym_EventScript_GymStatue_1:
# 211 "data/maps/StonereachCity_Gym/scripts.pory"
	releaseall
	end

StonereachCity_Gym_EventScript_GymStatue_2:
# 199 "data/maps/StonereachCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 200 "data/maps/StonereachCity_Gym/scripts.pory"
	case PT, StonereachCity_Gym_EventScript_GymStatue_6
# 201 "data/maps/StonereachCity_Gym/scripts.pory"
	case EN, StonereachCity_Gym_EventScript_GymStatue_7
# 202 "data/maps/StonereachCity_Gym/scripts.pory"
	case ES, StonereachCity_Gym_EventScript_GymStatue_8
	goto StonereachCity_Gym_EventScript_GymStatue_1

StonereachCity_Gym_EventScript_GymStatue_6:
# 200 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymStatue_Text_0, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymStatue_1

StonereachCity_Gym_EventScript_GymStatue_7:
# 201 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymStatue_Text_1, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymStatue_1

StonereachCity_Gym_EventScript_GymStatue_8:
# 202 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymStatue_Text_2, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymStatue_1

StonereachCity_Gym_EventScript_GymStatue_10:
# 206 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymStatue_Text_3, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymStatue_1

StonereachCity_Gym_EventScript_GymStatue_11:
# 207 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymStatue_Text_4, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymStatue_1

StonereachCity_Gym_EventScript_GymStatue_12:
# 208 "data/maps/StonereachCity_Gym/scripts.pory"
	msgbox StonereachCity_Gym_EventScript_GymStatue_Text_5, MSGBOX_DEFAULT
	goto StonereachCity_Gym_EventScript_GymStatue_1


StonereachCity_Gym_EventScript_Anorith_Text_0:
# 7 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Anorith$"

StonereachCity_Gym_EventScript_Anorith_Text_1:
# 8 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Krii-krii!$"

StonereachCity_Gym_EventScript_Roxanne_Text_0:
# 17 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Que bom revê-lo, {PLAYER}.\pNo museu, estudamos as marcas que\no tempo deixa na pedra.\pAqui, estudamos as marcas que uma\ldecisão deixa numa batalha.\pEu sou Aldren, Líder de Stonereach.\nMostre-me o que sua jornada gravou\lem você!$"

StonereachCity_Gym_EventScript_Roxanne_Text_1:
# 17 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Excelente...\pVocê encontrou a fissura na minha\ndefesa.$"

StonereachCity_Gym_EventScript_Roxanne_Text_2:
# 18 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Welcome, {PLAYER}.\pAt the museum, we study the marks\ntime leaves upon stone.\pHere, we study the marks a decision\lleaves upon a battle.\pI am Aldren, Leader of Stonereach.\nShow me what your journey has\lcarved into you!$"

StonereachCity_Gym_EventScript_Roxanne_Text_3:
# 18 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Excellent...\pYou found the fault line in my\ndefense.$"

StonereachCity_Gym_EventScript_Roxanne_Text_4:
# 19 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Te doy la bienvenida, {PLAYER}.\pEn el museo estudiamos las marcas\nque el tiempo deja en la piedra.\pAquí estudiamos las marcas que una\ldecisión deja en un combate.\pSoy Aldren, Líder de Stonereach.\n¡Muéstrame lo que tu viaje ha\lgrabado en ti!$"

StonereachCity_Gym_EventScript_Roxanne_Text_5:
# 19 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Excelente...\pHallaste la falla en mi defensa.$"

StonereachCity_Gym_EventScript_Roxanne_Text_6:
# 29 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "A pedra resiste porque aprende com\ncada impacto.\pFaça o mesmo. Outros Líderes\ntestarão forças diferentes das\lque encontrou aqui.$"

StonereachCity_Gym_EventScript_Roxanne_Text_7:
# 30 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Stone endures because it learns from\nevery impact.\pDo the same. Other Leaders will test\nstrengths unlike those you found\lhere.$"

StonereachCity_Gym_EventScript_Roxanne_Text_8:
# 31 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "La piedra resiste porque aprende de\ncada impacto.\pHaz lo mismo. Otros Líderes pondrán\na prueba fuerzas distintas a las\lde aquí.$"

StonereachCity_Gym_EventScript_RoxanneDefeated_Text_0:
# 39 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren reconheceu sua vitória.\p{PLAYER} recebeu a\nINSÍGNIA ROCHAREACH!$"

StonereachCity_Gym_EventScript_RoxanneDefeated_Text_1:
# 40 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren acknowledged your victory.\p{PLAYER} received the\nROCHAREACH BADGE!$"

StonereachCity_Gym_EventScript_RoxanneDefeated_Text_2:
# 41 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren reconoció tu victoria.\p¡{PLAYER} recibió la\nMEDALLA ROCHAREACH!$"

StonereachCity_Gym_EventScript_RoxanneDefeated_Text_3:
# 46 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "A INSÍGNIA ROCHAREACH prova que\nvocê superou o Ginásio de\lStonereach.\pEla permite usar CUT fora das\nbatalhas.\pE leve isto. Até uma muralha pode\nse tornar uma arma.$"

StonereachCity_Gym_EventScript_RoxanneDefeated_Text_4:
# 47 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "The ROCHAREACH BADGE proves you\novercame Stonereach Gym.\pIt allows you to use CUT outside\nbattle.\pAnd take this. Even a wall can be\nturned into a weapon.$"

StonereachCity_Gym_EventScript_RoxanneDefeated_Text_5:
# 48 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "La MEDALLA ROCHAREACH demuestra\nque superaste el Gimnasio de\lStonereach.\pTe permite usar CORTE fuera de\ncombate.\pY toma esto. Hasta un muro puede\nconvertirse en arma.$"

StonereachCity_Gym_EventScript_GiveRockTomb_Text_0:
# 67 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Essa TM contém ROCK TOMB.\pAlém de causar dano, as rochas\nreduzem a Velocidade do alvo.\pControle o ritmo, e até o oponente\nmais rápido perde o equilíbrio.$"

StonereachCity_Gym_EventScript_GiveRockTomb_Text_1:
# 68 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "That TM contains ROCK TOMB.\pBesides dealing damage, its rocks\nlower the target's Speed.\pControl the pace, and even the\nfastest foe loses its footing.$"

StonereachCity_Gym_EventScript_GiveRockTomb_Text_2:
# 69 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Esa MT contiene TUMBA ROCAS.\pAdemás de causar daño, reduce la\nVelocidad del objetivo.\pControla el ritmo y hasta el rival\nmás veloz perderá el equilibrio.$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_0:
# 77 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "{PLAYER}, cada batalha acrescentou\numa nova camada à nossa história.\pVamos descobrir qual de nós mudou\nmais desde o último encontro!$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_1:
# 77 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Outra vitória sua...\nUma descoberta valiosa.$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_2:
# 77 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Uma batalha em dupla exige ao menos\ndois Pokémon.\pVolte quando sua equipe estiver\npreparada.$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_3:
# 78 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "{PLAYER}, every battle has added a\nnew layer to our history.\pLet us discover which of us has\nchanged more since we last met!$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_4:
# 78 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Another victory for you...\nA valuable discovery.$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_5:
# 78 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "A Double Battle requires at least\ntwo Pokémon.\pReturn when your team is ready.$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_6:
# 79 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "{PLAYER}, cada combate ha añadido\nuna capa nueva a nuestra historia.\p¡Veamos quién cambió más desde\nnuestro último encuentro!$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_7:
# 79 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Otra victoria tuya...\nUn hallazgo valioso.$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_8:
# 79 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Un Combate Doble requiere al menos\ndos Pokémon.\pRegresa cuando tu equipo esté listo.$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_9:
# 82 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Ainda tenho muito a aprender.\pÉ isso que torna cada reencontro\ntão valioso.$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_10:
# 83 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "I still have much to learn.\pThat is what makes every reunion\nso valuable.$"

StonereachCity_Gym_EventScript_RoxanneRematch_Text_11:
# 84 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aún tengo mucho que aprender.\pEso hace que cada reencuentro sea\ntan valioso.$"

StonereachCity_Gym_EventScript_Rick_Text_0:
# 91 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Uma defesa só é forte até você\nencontrar a primeira rachadura!$"

StonereachCity_Gym_EventScript_Rick_Text_1:
# 91 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Você encontrou a minha...$"

StonereachCity_Gym_EventScript_Rick_Text_2:
# 92 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "A defense is only strong until you\nfind its first crack!$"

StonereachCity_Gym_EventScript_Rick_Text_3:
# 92 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "You found mine...$"

StonereachCity_Gym_EventScript_Rick_Text_4:
# 93 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "¡Una defensa solo es fuerte hasta\nque hallas su primera grieta!$"

StonereachCity_Gym_EventScript_Rick_Text_5:
# 93 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Encontraste la mía...$"

StonereachCity_Gym_EventScript_Rick_Text_6:
# 96 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren diz que perder revela coisas\nque a vitória consegue esconder.$"

StonereachCity_Gym_EventScript_Rick_Text_7:
# 97 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren says defeat reveals things\nthat victory can hide.$"

StonereachCity_Gym_EventScript_Rick_Text_8:
# 98 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren dice que perder revela cosas\nque la victoria puede ocultar.$"

StonereachCity_Gym_EventScript_Tommy_Text_0:
# 105 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Pedra, peso e paciência!\nEssa é a fórmula de Stonereach!$"

StonereachCity_Gym_EventScript_Tommy_Text_1:
# 105 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Minha fórmula falhou!$"

StonereachCity_Gym_EventScript_Tommy_Text_2:
# 106 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Stone, weight, and patience!\nThat is Stonereach's formula!$"

StonereachCity_Gym_EventScript_Tommy_Text_3:
# 106 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "My formula failed!$"

StonereachCity_Gym_EventScript_Tommy_Text_4:
# 107 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "¡Piedra, peso y paciencia!\n¡Esa es la fórmula de Stonereach!$"

StonereachCity_Gym_EventScript_Tommy_Text_5:
# 107 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "¡Mi fórmula falló!$"

StonereachCity_Gym_EventScript_Tommy_Text_6:
# 110 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Talvez eu tenha esquecido a parte\nmais importante: adaptação.$"

StonereachCity_Gym_EventScript_Tommy_Text_7:
# 111 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Perhaps I forgot the most important\npart: adaptation.$"

StonereachCity_Gym_EventScript_Tommy_Text_8:
# 112 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Quizá olvidé la parte más\nimportante: adaptarse.$"

StonereachCity_Gym_EventScript_Marc_Text_0:
# 119 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "A montanha não sai do caminho.\nVocê é quem precisa superá-la!$"

StonereachCity_Gym_EventScript_Marc_Text_1:
# 119 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Escalou direto até o topo!$"

StonereachCity_Gym_EventScript_Marc_Text_2:
# 120 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "The mountain will not move aside.\nYou are the one who must overcome it!$"

StonereachCity_Gym_EventScript_Marc_Text_3:
# 120 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "You climbed straight to the top!$"

StonereachCity_Gym_EventScript_Marc_Text_4:
# 121 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "La montaña no se apartará.\n¡Tú debes superarla!$"

StonereachCity_Gym_EventScript_Marc_Text_5:
# 121 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "¡Subiste directo a la cima!$"

StonereachCity_Gym_EventScript_Marc_Text_6:
# 124 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Força sem leitura do terreno é só\npeso. Aldren nunca esquece disso.$"

StonereachCity_Gym_EventScript_Marc_Text_7:
# 125 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Strength without reading the terrain\nis only weight. Aldren never forgets.$"

StonereachCity_Gym_EventScript_Marc_Text_8:
# 126 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "La fuerza sin leer el terreno es solo\npeso. Aldren nunca lo olvida.$"

StonereachCity_Gym_EventScript_GymGuide_Text_0:
# 136 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Que vitória!\pA INSÍGNIA ROCHAREACH no seu\nCartão de Treinador é a primeira\lmarca de uma história enorme!$"

StonereachCity_Gym_EventScript_GymGuide_Text_1:
# 137 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "What a victory!\pThe ROCHAREACH BADGE on your\nTrainer Card is the first mark\lof an enormous story!$"

StonereachCity_Gym_EventScript_GymGuide_Text_2:
# 138 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "¡Qué victoria!\p¡La MEDALLA ROCHAREACH en tu\nFicha de Entrenador es la primera\lmarca de una historia enorme!$"

StonereachCity_Gym_EventScript_GymGuide_Text_3:
# 142 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren usa Pokémon do tipo PEDRA!\pÁGUA e PLANTA abrem caminho, mas\nnão confie só na vantagem.\pEle batalha como geólogo: observa\na pressão e espera a falha certa!$"

StonereachCity_Gym_EventScript_GymGuide_Text_4:
# 143 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren uses ROCK-type Pokémon!\pWATER and GRASS clear a path, but\ndo not rely on advantage alone.\pHe battles like a geologist: reading\npressure and awaiting the right fault!$"

StonereachCity_Gym_EventScript_GymGuide_Text_5:
# 144 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "¡Aldren usa Pokémon de tipo ROCA!\pAGUA y PLANTA abren camino, pero\nno dependas solo de la ventaja.\pCombate como geólogo: estudia la\npresión y espera la falla precisa.$"

StonereachCity_Gym_EventScript_RegisterRoxanne_Text_0:
# 162 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren foi registrado no POKÉNAV!$"

StonereachCity_Gym_EventScript_RegisterRoxanne_Text_1:
# 163 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren was registered in the POKÉNAV!$"

StonereachCity_Gym_EventScript_RegisterRoxanne_Text_2:
# 164 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "¡Aldren fue registrado en el POKÉNAV!$"

StonereachCity_Gym_EventScript_GymStatue_Text_0:
# 200 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "GINÁSIO POKÉMON DE STONEREACH\pLÍDER: ALDREN\nTREINADOR CERTIFICADO: {PLAYER}$"

StonereachCity_Gym_EventScript_GymStatue_Text_1:
# 201 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "STONEREACH POKÉMON GYM\pLEADER: ALDREN\nCERTIFIED TRAINER: {PLAYER}$"

StonereachCity_Gym_EventScript_GymStatue_Text_2:
# 202 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "GIMNASIO POKÉMON STONEREACH\pLÍDER: ALDREN\nENTRENADOR CERTIFICADO: {PLAYER}$"

StonereachCity_Gym_EventScript_GymStatue_Text_3:
# 206 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "GINÁSIO POKÉMON DE STONEREACH\pLÍDER: ALDREN\n'O tempo revela o que a pedra guarda.'$"

StonereachCity_Gym_EventScript_GymStatue_Text_4:
# 207 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "STONEREACH POKÉMON GYM\pLEADER: ALDREN\n'Time reveals what stone keeps.'$"

StonereachCity_Gym_EventScript_GymStatue_Text_5:
# 208 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "GIMNASIO POKÉMON STONEREACH\pLÍDER: ALDREN\n'El tiempo revela lo que guarda la piedra.'$"

StonereachCity_Gym_Text_AldrenRegisterCall_PT::
# 175 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren: Olá, {PLAYER}.\pEstive comparando nossas batalhas\ncomo quem compara camadas de rocha.\pQuando quiser acrescentar uma nova\ncamada, estarei no Ginásio.$"

StonereachCity_Gym_Text_AldrenRegisterCall_EN::
# 179 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren: Hello, {PLAYER}.\pI've been comparing our battles as\none compares layers of stone.\pWhen you wish to add a new layer,\nI will be at the Gym.$"

StonereachCity_Gym_Text_AldrenRegisterCall_ES::
# 183 "data/maps/StonereachCity_Gym/scripts.pory"
	.string "Aldren: Hola, {PLAYER}.\pHe comparado nuestros combates como\nquien compara capas de piedra.\pCuando quieras añadir una nueva,\nestaré en el Gimnasio.$"
