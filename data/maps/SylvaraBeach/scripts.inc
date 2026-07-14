SylvaraBeach_MapScripts::
	.byte 0


SylvaraBeach_EventScript_Psychic_Battle::
# 6 "data/maps/SylvaraBeach/scripts.pory"
	switch VAR_LANGUAGE
# 7 "data/maps/SylvaraBeach/scripts.pory"
	case PT, SylvaraBeach_EventScript_Psychic_Battle_3
# 10 "data/maps/SylvaraBeach/scripts.pory"
	case EN, SylvaraBeach_EventScript_Psychic_Battle_4
# 13 "data/maps/SylvaraBeach/scripts.pory"
	case ES, SylvaraBeach_EventScript_Psychic_Battle_5
SylvaraBeach_EventScript_Psychic_Battle_1:
# 17 "data/maps/SylvaraBeach/scripts.pory"
	release
	end

SylvaraBeach_EventScript_Psychic_Battle_3:
# 8 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_single TRAINER_PSYCHIC_M_LAWRENCE, SylvaraBeach_EventScript_Psychic_Battle_Text_0, SylvaraBeach_EventScript_Psychic_Battle_Text_1
# 9 "data/maps/SylvaraBeach/scripts.pory"
	msgbox SylvaraBeach_EventScript_Psychic_Battle_Text_2
	goto SylvaraBeach_EventScript_Psychic_Battle_1

SylvaraBeach_EventScript_Psychic_Battle_4:
# 11 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_single TRAINER_PSYCHIC_M_LAWRENCE, SylvaraBeach_EventScript_Psychic_Battle_Text_3, SylvaraBeach_EventScript_Psychic_Battle_Text_4
# 12 "data/maps/SylvaraBeach/scripts.pory"
	msgbox SylvaraBeach_EventScript_Psychic_Battle_Text_5
	goto SylvaraBeach_EventScript_Psychic_Battle_1

SylvaraBeach_EventScript_Psychic_Battle_5:
# 14 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_single TRAINER_PSYCHIC_M_LAWRENCE, SylvaraBeach_EventScript_Psychic_Battle_Text_6, SylvaraBeach_EventScript_Psychic_Battle_Text_7
# 15 "data/maps/SylvaraBeach/scripts.pory"
	msgbox SylvaraBeach_EventScript_Psychic_Battle_Text_8
	goto SylvaraBeach_EventScript_Psychic_Battle_1


SylvaraBeach_EventScript_Rival_Battle::
# 22 "data/maps/SylvaraBeach/scripts.pory"
	lockall
# 23 "data/maps/SylvaraBeach/scripts.pory"
	faceplayer
# 24 "data/maps/SylvaraBeach/scripts.pory"
	removeowe
# 25 "data/maps/SylvaraBeach/scripts.pory"
	playbgm MUS_RG_ENCOUNTER_RIVAL, 1
# 26 "data/maps/SylvaraBeach/scripts.pory"
	playse SE_PIN
# 27 "data/maps/SylvaraBeach/scripts.pory"
	movenpc VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 28 "data/maps/SylvaraBeach/scripts.pory"
	waitse
# 29 "data/maps/SylvaraBeach/scripts.pory"
	pause 10
# 30 "data/maps/SylvaraBeach/scripts.pory"
	switch VAR_LANGUAGE
# 31 "data/maps/SylvaraBeach/scripts.pory"
	case PT, SylvaraBeach_EventScript_Rival_Battle_3
# 34 "data/maps/SylvaraBeach/scripts.pory"
	case EN, SylvaraBeach_EventScript_Rival_Battle_4
# 37 "data/maps/SylvaraBeach/scripts.pory"
	case ES, SylvaraBeach_EventScript_Rival_Battle_5
SylvaraBeach_EventScript_Rival_Battle_1:
# 41 "data/maps/SylvaraBeach/scripts.pory"
	release
	end

SylvaraBeach_EventScript_Rival_Battle_3:
# 32 "data/maps/SylvaraBeach/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, SylvaraBeach_EventScript_Rival_Battle_Text_0, SylvaraBeach_EventScript_Rival_Battle_Text_1, MSGBOX_AUTOCLOSE
# 33 "data/maps/SylvaraBeach/scripts.pory"
	goto SylvaraBeach_EventScript_Rival_Battle_PT
	goto SylvaraBeach_EventScript_Rival_Battle_1

SylvaraBeach_EventScript_Rival_Battle_4:
# 35 "data/maps/SylvaraBeach/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, SylvaraBeach_EventScript_Rival_Battle_Text_0, SylvaraBeach_EventScript_Rival_Battle_Text_2, MSGBOX_AUTOCLOSE
# 36 "data/maps/SylvaraBeach/scripts.pory"
	goto SylvaraBeach_EventScript_Rival_Battle_EN
	goto SylvaraBeach_EventScript_Rival_Battle_1

SylvaraBeach_EventScript_Rival_Battle_5:
# 38 "data/maps/SylvaraBeach/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, SylvaraBeach_EventScript_Rival_Battle_Text_0, SylvaraBeach_EventScript_Rival_Battle_Text_3, MSGBOX_AUTOCLOSE
# 39 "data/maps/SylvaraBeach/scripts.pory"
	goto SylvaraBeach_EventScript_Rival_Battle_ES
	goto SylvaraBeach_EventScript_Rival_Battle_1


SylvaraBeach_EventScript_Rival_Battle_PT::
# 46 "data/maps/SylvaraBeach/scripts.pory"
	goto_if_set FLAG_ADVENTURE_IS_MONOTYPE, SylvaraBeach_EventScript_Rival_Battle_PT_2
SylvaraBeach_EventScript_Rival_Battle_PT_1:
# 49 "data/maps/SylvaraBeach/scripts.pory"
	switch VAR_STORE_FIST_MON_TYPE
# 50 "data/maps/SylvaraBeach/scripts.pory"
	case TYPE_WATER, SylvaraBeach_EventScript_Rival_Battle_PT_6
# 52 "data/maps/SylvaraBeach/scripts.pory"
	case TYPE_FIRE, SylvaraBeach_EventScript_Rival_Battle_PT_7
# 54 "data/maps/SylvaraBeach/scripts.pory"
	case TYPE_GRASS, SylvaraBeach_EventScript_Rival_Battle_PT_8
SylvaraBeach_EventScript_Rival_Battle_PT_4:
# 57 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH, SylvaraBeach_EventScript_Rival_Battle_PT_Text_0, SylvaraBeach_EventScript_Rival_Battle_PT_Text_1, SylvaraBeach_EventScript_Rival_Continue
# 58 "data/maps/SylvaraBeach/scripts.pory"
	release
	end

SylvaraBeach_EventScript_Rival_Battle_PT_2:
# 47 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH, SylvaraBeach_EventScript_Rival_Battle_PT_Text_0, SylvaraBeach_EventScript_Rival_Battle_PT_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_PT_1

SylvaraBeach_EventScript_Rival_Battle_PT_6:
# 51 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH_GRASS, SylvaraBeach_EventScript_Rival_Battle_PT_Text_0, SylvaraBeach_EventScript_Rival_Battle_PT_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_PT_4

SylvaraBeach_EventScript_Rival_Battle_PT_7:
# 53 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH_WATER, SylvaraBeach_EventScript_Rival_Battle_PT_Text_0, SylvaraBeach_EventScript_Rival_Battle_PT_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_PT_4

SylvaraBeach_EventScript_Rival_Battle_PT_8:
# 55 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH_FIRE, SylvaraBeach_EventScript_Rival_Battle_PT_Text_0, SylvaraBeach_EventScript_Rival_Battle_PT_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_PT_4


SylvaraBeach_EventScript_Rival_Battle_EN::
# 63 "data/maps/SylvaraBeach/scripts.pory"
	goto_if_set FLAG_ADVENTURE_IS_MONOTYPE, SylvaraBeach_EventScript_Rival_Battle_EN_2
SylvaraBeach_EventScript_Rival_Battle_EN_1:
# 66 "data/maps/SylvaraBeach/scripts.pory"
	switch VAR_STORE_FIST_MON_TYPE
# 67 "data/maps/SylvaraBeach/scripts.pory"
	case TYPE_WATER, SylvaraBeach_EventScript_Rival_Battle_EN_6
# 69 "data/maps/SylvaraBeach/scripts.pory"
	case TYPE_FIRE, SylvaraBeach_EventScript_Rival_Battle_EN_7
# 71 "data/maps/SylvaraBeach/scripts.pory"
	case TYPE_GRASS, SylvaraBeach_EventScript_Rival_Battle_EN_8
SylvaraBeach_EventScript_Rival_Battle_EN_4:
# 74 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH, SylvaraBeach_EventScript_Rival_Battle_EN_Text_0, SylvaraBeach_EventScript_Rival_Battle_EN_Text_1, SylvaraBeach_EventScript_Rival_Continue
# 75 "data/maps/SylvaraBeach/scripts.pory"
	release
	end

SylvaraBeach_EventScript_Rival_Battle_EN_2:
# 64 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH, SylvaraBeach_EventScript_Rival_Battle_EN_Text_0, SylvaraBeach_EventScript_Rival_Battle_EN_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_EN_1

SylvaraBeach_EventScript_Rival_Battle_EN_6:
# 68 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH_GRASS, SylvaraBeach_EventScript_Rival_Battle_EN_Text_0, SylvaraBeach_EventScript_Rival_Battle_EN_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_EN_4

SylvaraBeach_EventScript_Rival_Battle_EN_7:
# 70 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH_WATER, SylvaraBeach_EventScript_Rival_Battle_EN_Text_0, SylvaraBeach_EventScript_Rival_Battle_EN_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_EN_4

SylvaraBeach_EventScript_Rival_Battle_EN_8:
# 72 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH_FIRE, SylvaraBeach_EventScript_Rival_Battle_EN_Text_0, SylvaraBeach_EventScript_Rival_Battle_EN_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_EN_4


SylvaraBeach_EventScript_Rival_Battle_ES::
# 80 "data/maps/SylvaraBeach/scripts.pory"
	goto_if_set FLAG_ADVENTURE_IS_MONOTYPE, SylvaraBeach_EventScript_Rival_Battle_ES_2
SylvaraBeach_EventScript_Rival_Battle_ES_1:
# 83 "data/maps/SylvaraBeach/scripts.pory"
	switch VAR_STORE_FIST_MON_TYPE
# 84 "data/maps/SylvaraBeach/scripts.pory"
	case TYPE_WATER, SylvaraBeach_EventScript_Rival_Battle_ES_6
# 86 "data/maps/SylvaraBeach/scripts.pory"
	case TYPE_FIRE, SylvaraBeach_EventScript_Rival_Battle_ES_7
# 88 "data/maps/SylvaraBeach/scripts.pory"
	case TYPE_GRASS, SylvaraBeach_EventScript_Rival_Battle_ES_8
SylvaraBeach_EventScript_Rival_Battle_ES_4:
# 91 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH, SylvaraBeach_EventScript_Rival_Battle_ES_Text_0, SylvaraBeach_EventScript_Rival_Battle_ES_Text_1, SylvaraBeach_EventScript_Rival_Continue
# 92 "data/maps/SylvaraBeach/scripts.pory"
	release
	end

SylvaraBeach_EventScript_Rival_Battle_ES_2:
# 81 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH, SylvaraBeach_EventScript_Rival_Battle_ES_Text_0, SylvaraBeach_EventScript_Rival_Battle_ES_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_ES_1

SylvaraBeach_EventScript_Rival_Battle_ES_6:
# 85 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH_GRASS, SylvaraBeach_EventScript_Rival_Battle_ES_Text_0, SylvaraBeach_EventScript_Rival_Battle_ES_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_ES_4

SylvaraBeach_EventScript_Rival_Battle_ES_7:
# 87 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH_WATER, SylvaraBeach_EventScript_Rival_Battle_ES_Text_0, SylvaraBeach_EventScript_Rival_Battle_ES_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_ES_4

SylvaraBeach_EventScript_Rival_Battle_ES_8:
# 89 "data/maps/SylvaraBeach/scripts.pory"
	trainerbattle_continue_lost TRAINER_RIVAL_SYLVARA_BEACH_FIRE, SylvaraBeach_EventScript_Rival_Battle_ES_Text_0, SylvaraBeach_EventScript_Rival_Battle_ES_Text_1, SylvaraBeach_EventScript_Rival_Continue
	goto SylvaraBeach_EventScript_Rival_Battle_ES_4


SylvaraBeach_EventScript_Rival_Continue::
# 97 "data/maps/SylvaraBeach/scripts.pory"
	lockall
# 98 "data/maps/SylvaraBeach/scripts.pory"
	switch VAR_LANGUAGE
# 99 "data/maps/SylvaraBeach/scripts.pory"
	case PT, SylvaraBeach_EventScript_Rival_Continue_3
# 100 "data/maps/SylvaraBeach/scripts.pory"
	case EN, SylvaraBeach_EventScript_Rival_Continue_4
# 101 "data/maps/SylvaraBeach/scripts.pory"
	case ES, SylvaraBeach_EventScript_Rival_Continue_5
SylvaraBeach_EventScript_Rival_Continue_1:
# 103 "data/maps/SylvaraBeach/scripts.pory"
	playse SE_PIN
# 104 "data/maps/SylvaraBeach/scripts.pory"
	movenpc VAR_LAST_TALKED, Common_Movement_EmojiConfident
# 105 "data/maps/SylvaraBeach/scripts.pory"
	waitse
# 106 "data/maps/SylvaraBeach/scripts.pory"
	pause 10
# 107 "data/maps/SylvaraBeach/scripts.pory"
	switch VAR_LANGUAGE
# 108 "data/maps/SylvaraBeach/scripts.pory"
	case PT, SylvaraBeach_EventScript_Rival_Continue_8
# 109 "data/maps/SylvaraBeach/scripts.pory"
	case EN, SylvaraBeach_EventScript_Rival_Continue_9
# 110 "data/maps/SylvaraBeach/scripts.pory"
	case ES, SylvaraBeach_EventScript_Rival_Continue_10
SylvaraBeach_EventScript_Rival_Continue_6:
# 112 "data/maps/SylvaraBeach/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq SylvaraBeach_EventScript_Rival_Continue_12
# 115 "data/maps/SylvaraBeach/scripts.pory"
	movenpc VAR_LAST_TALKED, Movement_SylvaraBeach_Rival_GoAway_1
SylvaraBeach_EventScript_Rival_Continue_11:
# 117 "data/maps/SylvaraBeach/scripts.pory"
	setflag FLAG_SYLVARA_TOWN_RIVAL_DONE
# 118 "data/maps/SylvaraBeach/scripts.pory"
	removeobject LOCALID_BEACH_RIVAL
# 119 "data/maps/SylvaraBeach/scripts.pory"
	fadedefaultbgm
# 120 "data/maps/SylvaraBeach/scripts.pory"
	special HealPlayerParty
# 121 "data/maps/SylvaraBeach/scripts.pory"
	updateowe
# 122 "data/maps/SylvaraBeach/scripts.pory"
	releaseall
	end

SylvaraBeach_EventScript_Rival_Continue_3:
# 99 "data/maps/SylvaraBeach/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, SylvaraBeach_EventScript_Rival_Battle_Text_0, SylvaraBeach_EventScript_Rival_Continue_Text_0, MSGBOX_AUTOCLOSE
	goto SylvaraBeach_EventScript_Rival_Continue_1

SylvaraBeach_EventScript_Rival_Continue_4:
# 100 "data/maps/SylvaraBeach/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, SylvaraBeach_EventScript_Rival_Battle_Text_0, SylvaraBeach_EventScript_Rival_Continue_Text_1, MSGBOX_AUTOCLOSE
	goto SylvaraBeach_EventScript_Rival_Continue_1

SylvaraBeach_EventScript_Rival_Continue_5:
# 101 "data/maps/SylvaraBeach/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, SylvaraBeach_EventScript_Rival_Battle_Text_0, SylvaraBeach_EventScript_Rival_Continue_Text_2, MSGBOX_AUTOCLOSE
	goto SylvaraBeach_EventScript_Rival_Continue_1

SylvaraBeach_EventScript_Rival_Continue_8:
# 108 "data/maps/SylvaraBeach/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, SylvaraBeach_EventScript_Rival_Battle_Text_0, SylvaraBeach_EventScript_Rival_Continue_Text_3, MSGBOX_AUTOCLOSE
	goto SylvaraBeach_EventScript_Rival_Continue_6

SylvaraBeach_EventScript_Rival_Continue_9:
# 109 "data/maps/SylvaraBeach/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, SylvaraBeach_EventScript_Rival_Battle_Text_0, SylvaraBeach_EventScript_Rival_Continue_Text_4, MSGBOX_AUTOCLOSE
	goto SylvaraBeach_EventScript_Rival_Continue_6

SylvaraBeach_EventScript_Rival_Continue_10:
# 110 "data/maps/SylvaraBeach/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, SylvaraBeach_EventScript_Rival_Battle_Text_0, SylvaraBeach_EventScript_Rival_Continue_Text_5, MSGBOX_AUTOCLOSE
	goto SylvaraBeach_EventScript_Rival_Continue_6

SylvaraBeach_EventScript_Rival_Continue_12:
# 113 "data/maps/SylvaraBeach/scripts.pory"
	movenpc VAR_LAST_TALKED, Movement_SylvaraBeach_Rival_GoAway_2
	goto SylvaraBeach_EventScript_Rival_Continue_11


# 126 "data/maps/SylvaraBeach/scripts.pory"
Movement_SylvaraBeach_Rival_GoAway_1:
# 127 "data/maps/SylvaraBeach/scripts.pory"
	walk_right
# 127 "data/maps/SylvaraBeach/scripts.pory"
	walk_right
# 127 "data/maps/SylvaraBeach/scripts.pory"
	walk_right
# 127 "data/maps/SylvaraBeach/scripts.pory"
	walk_right
# 128 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 128 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 128 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 128 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 128 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 128 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 128 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 128 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 129 "data/maps/SylvaraBeach/scripts.pory"
	delay_16
	step_end

# 132 "data/maps/SylvaraBeach/scripts.pory"
Movement_SylvaraBeach_Rival_GoAway_2:
# 133 "data/maps/SylvaraBeach/scripts.pory"
	walk_left
# 134 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 134 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 135 "data/maps/SylvaraBeach/scripts.pory"
	walk_right
# 135 "data/maps/SylvaraBeach/scripts.pory"
	walk_right
# 135 "data/maps/SylvaraBeach/scripts.pory"
	walk_right
# 135 "data/maps/SylvaraBeach/scripts.pory"
	walk_right
# 135 "data/maps/SylvaraBeach/scripts.pory"
	walk_right
# 136 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 136 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 136 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 136 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 136 "data/maps/SylvaraBeach/scripts.pory"
	walk_up
# 137 "data/maps/SylvaraBeach/scripts.pory"
	delay_16
	step_end

SylvaraBeach_EventScript_Tuber_M_Talk::
# 141 "data/maps/SylvaraBeach/scripts.pory"
	callnative MissorMisterString
# 142 "data/maps/SylvaraBeach/scripts.pory"
	switch VAR_LANGUAGE
# 143 "data/maps/SylvaraBeach/scripts.pory"
	case PT, SylvaraBeach_EventScript_Tuber_M_Talk_3
# 144 "data/maps/SylvaraBeach/scripts.pory"
	case EN, SylvaraBeach_EventScript_Tuber_M_Talk_4
# 145 "data/maps/SylvaraBeach/scripts.pory"
	case ES, SylvaraBeach_EventScript_Tuber_M_Talk_5
SylvaraBeach_EventScript_Tuber_M_Talk_1:
	end

SylvaraBeach_EventScript_Tuber_M_Talk_3:
# 143 "data/maps/SylvaraBeach/scripts.pory"
	msgbox SylvaraBeach_EventScript_Tuber_M_Talk_Text_0, MSGBOX_NPC
	goto SylvaraBeach_EventScript_Tuber_M_Talk_1

SylvaraBeach_EventScript_Tuber_M_Talk_4:
# 144 "data/maps/SylvaraBeach/scripts.pory"
	msgbox SylvaraBeach_EventScript_Tuber_M_Talk_Text_1, MSGBOX_NPC
	goto SylvaraBeach_EventScript_Tuber_M_Talk_1

SylvaraBeach_EventScript_Tuber_M_Talk_5:
# 145 "data/maps/SylvaraBeach/scripts.pory"
	msgbox SylvaraBeach_EventScript_Tuber_M_Talk_Text_2, MSGBOX_NPC
	goto SylvaraBeach_EventScript_Tuber_M_Talk_1


SylvaraBeach_EventScript_Item_Potion::
# 151 "data/maps/SylvaraBeach/scripts.pory"
	finditem ITEM_POTION
	end


SylvaraBeach_EventScript_Psychic_Battle_Text_0:
# 8 "data/maps/SylvaraBeach/scripts.pory"
	.string "Você é um pouco psicodélico\nigual a mim?\pVem fazer o teste!$"

SylvaraBeach_EventScript_Psychic_Battle_Text_1:
# 8 "data/maps/SylvaraBeach/scripts.pory"
	.string "Parece que você me venceu na\npsicodelia!$"

SylvaraBeach_EventScript_Psychic_Battle_Text_2:
# 9 "data/maps/SylvaraBeach/scripts.pory"
	.string "Será que um psicodélico pode\nevoluir para um psicopata?$"

SylvaraBeach_EventScript_Psychic_Battle_Text_3:
# 11 "data/maps/SylvaraBeach/scripts.pory"
	.string "Are you a little psychedelic\nlike me?\pCome take the test!$"

SylvaraBeach_EventScript_Psychic_Battle_Text_4:
# 11 "data/maps/SylvaraBeach/scripts.pory"
	.string "It looks like you beat me at\npsychedelia!$"

SylvaraBeach_EventScript_Psychic_Battle_Text_5:
# 12 "data/maps/SylvaraBeach/scripts.pory"
	.string "Can a psychedelic\nbecome a psychopath?$"

SylvaraBeach_EventScript_Psychic_Battle_Text_6:
# 14 "data/maps/SylvaraBeach/scripts.pory"
	.string "¿Eres un poco psicodélico\ncomo yo?\p¡Ven a hacer la prueba!$"

SylvaraBeach_EventScript_Psychic_Battle_Text_7:
# 14 "data/maps/SylvaraBeach/scripts.pory"
	.string "¡Parece que me venciste en\npsicodelia!$"

SylvaraBeach_EventScript_Psychic_Battle_Text_8:
# 15 "data/maps/SylvaraBeach/scripts.pory"
	.string "¿Puede un psicodélico\nconvertirse en psicópata?$"

SylvaraBeach_EventScript_Rival_Battle_Text_0:
# 32 "data/maps/SylvaraBeach/scripts.pory"
	.string "{RIVAL}$"

SylvaraBeach_EventScript_Rival_Battle_Text_1:
# 32 "data/maps/SylvaraBeach/scripts.pory"
	.string "Ei, {PLAYER}, ainda bem que você\nchegou!\pEu estava aproveitando a vista da\nPraia Sylvara antes de seguir em\lfrente.\pÉ um lugar tranquilo… perfeito\npara colocar os pensamentos em\lordem.\pPara ser sincero, tive alguns\npressentimentos estranhos ontem.\pNão sei explicar muito bem, mas\nparecia que algo importante estava\lprestes a acontecer.\pAinda assim, não quero deixar isso\nme distrair.\pNossa jornada está apenas\ncomeçando, e quero aproveitar cada\lmomento dela.\pQuero me tornar mais forte,\nconhecer novos Pokémon e descobrir\ltudo o que Aetheris tem a\loferecer.\pE acho que existe uma ótima\nmaneira de dar o primeiro passo.\pQue tal uma batalha entre nós\ndois?\pVamos ver o quanto aprendemos até\nagora!$"

SylvaraBeach_EventScript_Rival_Battle_Text_2:
# 35 "data/maps/SylvaraBeach/scripts.pory"
	.string "Hey, {PLAYER}, I'm glad you made\nit!\pI was taking a moment to enjoy the\nview of Sylvara Beach before\lmoving on.\pIt's a peaceful place… perfect for\nclearing your thoughts.\pTo be honest, I had some strange\nfeelings yesterday.\pI can't really explain them, but\nit felt like something important\lwas about to happen.\pEven so, I don't want to let that\ndistract me.\pOur journey is only beginning, and\nI want to make the most of every\lmoment.\pI want to grow stronger, meet new\nPokémon, and discover everything\lAetheris has to offer.\pAnd I think there's a great way to\ntake the first step.\pHow about a battle between the two\nof us?\pLet's see how much we've learned\nso far!$"

SylvaraBeach_EventScript_Rival_Battle_Text_3:
# 38 "data/maps/SylvaraBeach/scripts.pory"
	.string "¡Hola, {PLAYER}! ¡Qué bueno que\nllegaste!\pEstaba disfrutando la vista de la\nPlaya Sylvara antes de continuar\lmi camino.\pEs un lugar tranquilo… perfecto\npara ordenar los pensamientos.\pPara ser sincero, ayer tuve\nalgunos presentimientos extraños.\pNo sabría explicarlo, pero sentía\nque algo importante estaba por\lsuceder.\pAun así, no quiero dejar que eso\nme distraiga.\pNuestra aventura apenas está\ncomenzando, y quiero aprovechar\lcada instante.\pQuiero volverme más fuerte,\nconocer nuevos Pokémon y descubrir\ltodo lo que Aetheris tiene para\lofrecer.\pY creo que hay una excelente forma\nde dar el primer paso.\p¿Qué te parece una batalla entre\nnosotros?\p¡Veamos cuánto hemos aprendido\nhasta ahora!$"

SylvaraBeach_EventScript_Rival_Battle_PT_Text_0:
# 47 "data/maps/SylvaraBeach/scripts.pory"
	.string "Impressionante… você está ficando\ncada vez mais forte!$"

SylvaraBeach_EventScript_Rival_Battle_PT_Text_1:
# 47 "data/maps/SylvaraBeach/scripts.pory"
	.string "Heh, desta vez eu levei a melhor!$"

SylvaraBeach_EventScript_Rival_Battle_EN_Text_0:
# 64 "data/maps/SylvaraBeach/scripts.pory"
	.string "Impressive… you're getting stronger\nevery time!$"

SylvaraBeach_EventScript_Rival_Battle_EN_Text_1:
# 64 "data/maps/SylvaraBeach/scripts.pory"
	.string "Heh, looks like I got the better\nof you this time!$"

SylvaraBeach_EventScript_Rival_Battle_ES_Text_0:
# 81 "data/maps/SylvaraBeach/scripts.pory"
	.string "Impresionante… ¡cada vez te haces\nmás fuerte!$"

SylvaraBeach_EventScript_Rival_Battle_ES_Text_1:
# 81 "data/maps/SylvaraBeach/scripts.pory"
	.string "Je, esta vez yo salí victorioso.$"

SylvaraBeach_EventScript_Rival_Continue_Text_0:
# 99 "data/maps/SylvaraBeach/scripts.pory"
	.string "Uau… essa batalha foi ainda melhor\ndo que eu imaginava.\pVocê é realmente incrível,\n{PLAYER}.\pSe esta foi a nossa primeira\nbatalha, mal posso esperar pelas\lpróximas.\pAcho que nós dois temos um longo\ncaminho pela frente.\pHá muitos lugares para conhecer,\nmuitos Pokémon para encontrar…\pE muitos desafios esperando por\nnós.\pVou seguir em frente e continuar\ntreinando.\pEntão trate de não ficar para\ntrás, certo?\pAté a próxima batalha!$"

SylvaraBeach_EventScript_Rival_Continue_Text_1:
# 100 "data/maps/SylvaraBeach/scripts.pory"
	.string "Wow… that battle was even better\nthan I imagined.\pYou're really amazing, {PLAYER}.\pIf this was our first battle, I\ncan't wait for the next ones.\pI think both of us have a long\nroad ahead.\pThere are so many places to\nexplore, so many Pokémon to meet…\pAnd so many challenges waiting for\nus.\pI'll keep moving forward and\ntraining.\pSo don't fall behind, alright?\pUntil our next battle!$"

SylvaraBeach_EventScript_Rival_Continue_Text_2:
# 101 "data/maps/SylvaraBeach/scripts.pory"
	.string "Vaya… esta batalla fue incluso\nmejor de lo que imaginaba.\pDe verdad eres increíble,\n{PLAYER}.\pSi esta fue nuestra primera\nbatalla, no puedo esperar a las\lpróximas.\pCreo que ambos tenemos un largo\ncamino por delante.\pHay muchos lugares por conocer,\nmuchos Pokémon por encontrar…\pY muchos desafíos esperándonos.\pSeguiré adelante y continuaré\nentrenando.\pAsí que no te quedes atrás, ¿de\nacuerdo?\p¡Hasta nuestra próxima batalla!$"

SylvaraBeach_EventScript_Rival_Continue_Text_3:
# 108 "data/maps/SylvaraBeach/scripts.pory"
	.string "Outra coisa…\pTome cuidado com as pessoas que\nencontrar pelo caminho.\pNem todo sorriso é sincero.\pE nem toda mão estendida está\ntentando ajudar.\pEscolha bem quem vai caminhar ao\nseu lado.\pAs decisões que tomamos podem\nmudar mais do que imaginamos.\pAté a próxima, {PLAYER}.$"

SylvaraBeach_EventScript_Rival_Continue_Text_4:
# 109 "data/maps/SylvaraBeach/scripts.pory"
	.string "One more thing…\pBe careful with the people you\nmeet along the way.\pNot every smile is genuine.\pAnd not every outstretched hand is\ntrying to help.\pChoose carefully who you walk\nbeside.\pThe choices we make can change\nmore than we realize.\pUntil next time, {PLAYER}.$"

SylvaraBeach_EventScript_Rival_Continue_Text_5:
# 110 "data/maps/SylvaraBeach/scripts.pory"
	.string "Una cosa más…\pTen cuidado con las personas que\nencuentres en tu camino.\pNo todas las sonrisas son\nsinceras.\pY no todas las manos extendidas\nintentan ayudar.\pElige bien quién caminará a tu\nlado.\pLas decisiones que tomamos pueden\ncambiar más de lo que imaginamos.\pHasta la próxima, {PLAYER}.$"

SylvaraBeach_EventScript_Tuber_M_Talk_Text_0:
# 143 "data/maps/SylvaraBeach/scripts.pory"
	.string "Brincar aqui na Praia Sylvara é\nmuito divertido, {STR_VAR_1}!$"

SylvaraBeach_EventScript_Tuber_M_Talk_Text_1:
# 144 "data/maps/SylvaraBeach/scripts.pory"
	.string "Playing here on Sylvara Beach is\nreally fun, {STR_VAR_1}!$"

SylvaraBeach_EventScript_Tuber_M_Talk_Text_2:
# 145 "data/maps/SylvaraBeach/scripts.pory"
	.string "¡Jugar aquí en la Playa Sylvara es\nmuy divertido, {STR_VAR_1}!$"
