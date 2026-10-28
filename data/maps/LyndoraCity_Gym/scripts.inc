LyndoraCity_Gym_MapScripts::
	.byte 0


LyndoraCity_Gym_EventScript_Doorman::
# 4 "data/maps/LyndoraCity_Gym/scripts.pory"
	lock
# 5 "data/maps/LyndoraCity_Gym/scripts.pory"
	faceplayer
# 6 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, LyndoraCity_Gym_EventScript_Doorman_2
# 13 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto_if_unset FLAG_BADGE01_GET, LyndoraCity_Gym_EventScript_Doorman_9
# 20 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 21 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Doorman_17
# 22 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Doorman_18
# 23 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Doorman_19
LyndoraCity_Gym_EventScript_Doorman_1:
# 27 "data/maps/LyndoraCity_Gym/scripts.pory"
	release
	end

LyndoraCity_Gym_EventScript_Doorman_2:
# 7 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 8 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Doorman_6
# 9 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Doorman_7
# 10 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Doorman_8
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_6:
# 8 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Doorman_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_7:
# 9 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Doorman_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_8:
# 10 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Doorman_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_9:
# 14 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 15 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Doorman_13
# 16 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Doorman_14
# 17 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Doorman_15
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_13:
# 15 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Doorman_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_14:
# 16 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Doorman_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_15:
# 17 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Doorman_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_17:
# 21 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Doorman_Text_6, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_18:
# 22 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Doorman_Text_7, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Doorman_1

LyndoraCity_Gym_EventScript_Doorman_19:
# 23 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Doorman_Text_8, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Doorman_1


LyndoraCity_Gym_EventScript_Leah::
# 32 "data/maps/LyndoraCity_Gym/scripts.pory"
	lock
# 33 "data/maps/LyndoraCity_Gym/scripts.pory"
	faceplayer
# 34 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 35 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Leah_3
# 36 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Leah_4
# 37 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Leah_5
LyndoraCity_Gym_EventScript_Leah_1:
# 39 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 40 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Leah_8
# 41 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Leah_9
# 42 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Leah_10
LyndoraCity_Gym_EventScript_Leah_6:
# 44 "data/maps/LyndoraCity_Gym/scripts.pory"
	release
	end

LyndoraCity_Gym_EventScript_Leah_3:
# 35 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LASS_LEAH, LyndoraCity_Gym_EventScript_Leah_Text_0, LyndoraCity_Gym_EventScript_Leah_Text_1
	goto LyndoraCity_Gym_EventScript_Leah_1

LyndoraCity_Gym_EventScript_Leah_4:
# 36 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LASS_LEAH, LyndoraCity_Gym_EventScript_Leah_Text_2, LyndoraCity_Gym_EventScript_Leah_Text_3
	goto LyndoraCity_Gym_EventScript_Leah_1

LyndoraCity_Gym_EventScript_Leah_5:
# 37 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LASS_LEAH, LyndoraCity_Gym_EventScript_Leah_Text_4, LyndoraCity_Gym_EventScript_Leah_Text_5
	goto LyndoraCity_Gym_EventScript_Leah_1

LyndoraCity_Gym_EventScript_Leah_8:
# 40 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Leah_Text_6, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Leah_6

LyndoraCity_Gym_EventScript_Leah_9:
# 41 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Leah_Text_7, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Leah_6

LyndoraCity_Gym_EventScript_Leah_10:
# 42 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Leah_Text_8, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Leah_6


LyndoraCity_Gym_EventScript_Beauty::
# 49 "data/maps/LyndoraCity_Gym/scripts.pory"
	lock
# 50 "data/maps/LyndoraCity_Gym/scripts.pory"
	faceplayer
# 51 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 52 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Beauty_3
# 53 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Beauty_4
# 54 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Beauty_5
LyndoraCity_Gym_EventScript_Beauty_1:
# 56 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 57 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Beauty_8
# 58 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Beauty_9
# 59 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Beauty_10
LyndoraCity_Gym_EventScript_Beauty_6:
# 61 "data/maps/LyndoraCity_Gym/scripts.pory"
	release
	end

LyndoraCity_Gym_EventScript_Beauty_3:
# 52 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BEAUTY_ESTER, LyndoraCity_Gym_EventScript_Beauty_Text_0, LyndoraCity_Gym_EventScript_Beauty_Text_1
	goto LyndoraCity_Gym_EventScript_Beauty_1

LyndoraCity_Gym_EventScript_Beauty_4:
# 53 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BEAUTY_ESTER, LyndoraCity_Gym_EventScript_Beauty_Text_2, LyndoraCity_Gym_EventScript_Beauty_Text_3
	goto LyndoraCity_Gym_EventScript_Beauty_1

LyndoraCity_Gym_EventScript_Beauty_5:
# 54 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BEAUTY_ESTER, LyndoraCity_Gym_EventScript_Beauty_Text_4, LyndoraCity_Gym_EventScript_Beauty_Text_5
	goto LyndoraCity_Gym_EventScript_Beauty_1

LyndoraCity_Gym_EventScript_Beauty_8:
# 57 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Beauty_Text_6, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Beauty_6

LyndoraCity_Gym_EventScript_Beauty_9:
# 58 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Beauty_Text_7, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Beauty_6

LyndoraCity_Gym_EventScript_Beauty_10:
# 59 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Beauty_Text_8, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Beauty_6


LyndoraCity_Gym_EventScript_AromaLady::
# 66 "data/maps/LyndoraCity_Gym/scripts.pory"
	lock
# 67 "data/maps/LyndoraCity_Gym/scripts.pory"
	faceplayer
# 68 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 69 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_AromaLady_3
# 70 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_AromaLady_4
# 71 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_AromaLady_5
LyndoraCity_Gym_EventScript_AromaLady_1:
# 73 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 74 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_AromaLady_8
# 75 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_AromaLady_9
# 76 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_AromaLady_10
LyndoraCity_Gym_EventScript_AromaLady_6:
# 78 "data/maps/LyndoraCity_Gym/scripts.pory"
	release
	end

LyndoraCity_Gym_EventScript_AromaLady_3:
# 69 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_AROMA_LADY_DAISY, LyndoraCity_Gym_EventScript_AromaLady_Text_0, LyndoraCity_Gym_EventScript_AromaLady_Text_1
	goto LyndoraCity_Gym_EventScript_AromaLady_1

LyndoraCity_Gym_EventScript_AromaLady_4:
# 70 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_AROMA_LADY_DAISY, LyndoraCity_Gym_EventScript_AromaLady_Text_2, LyndoraCity_Gym_EventScript_AromaLady_Text_3
	goto LyndoraCity_Gym_EventScript_AromaLady_1

LyndoraCity_Gym_EventScript_AromaLady_5:
# 71 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_AROMA_LADY_DAISY, LyndoraCity_Gym_EventScript_AromaLady_Text_4, LyndoraCity_Gym_EventScript_AromaLady_Text_5
	goto LyndoraCity_Gym_EventScript_AromaLady_1

LyndoraCity_Gym_EventScript_AromaLady_8:
# 74 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_AromaLady_Text_6, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_AromaLady_6

LyndoraCity_Gym_EventScript_AromaLady_9:
# 75 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_AromaLady_Text_7, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_AromaLady_6

LyndoraCity_Gym_EventScript_AromaLady_10:
# 76 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_AromaLady_Text_8, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_AromaLady_6


LyndoraCity_Gym_EventScript_Elowen::
# 83 "data/maps/LyndoraCity_Gym/scripts.pory"
	lock
# 84 "data/maps/LyndoraCity_Gym/scripts.pory"
	faceplayer
# 85 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_LYNDORA_GYM, LyndoraCity_Gym_EventScript_Elowen_2
LyndoraCity_Gym_EventScript_Elowen_1:
# 91 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto_if_unset FLAG_BADGE01_GET, LyndoraCity_Gym_EventScript_Elowen_5
# 100 "data/maps/LyndoraCity_Gym/scripts.pory"
	setspeaker LyndoraCity_Gym_EventScript_Elowen_Text_3
# 101 "data/maps/LyndoraCity_Gym/scripts.pory"
	showpssicon PSS_ICON_ELOWEN
# 102 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 103 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Elowen_12
# 104 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Elowen_13
# 105 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Elowen_14
LyndoraCity_Gym_EventScript_Elowen_10:
# 107 "data/maps/LyndoraCity_Gym/scripts.pory"
	callnative ClosePssIconPic
# 108 "data/maps/LyndoraCity_Gym/scripts.pory"
	release
	end

LyndoraCity_Gym_EventScript_Elowen_2:
# 86 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_BULLET_SEED, LyndoraCity_Gym_EventScript_Elowen_8
LyndoraCity_Gym_EventScript_Elowen_7:
# 89 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto LyndoraCity_Gym_EventScript_AfterVictory
	goto LyndoraCity_Gym_EventScript_Elowen_1

LyndoraCity_Gym_EventScript_Elowen_5:
# 92 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 93 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Elowen_17
# 94 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Elowen_18
# 95 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Elowen_19
LyndoraCity_Gym_EventScript_Elowen_15:
# 97 "data/maps/LyndoraCity_Gym/scripts.pory"
	release
	end

LyndoraCity_Gym_EventScript_Elowen_8:
# 87 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto LyndoraCity_Gym_EventScript_GiveBulletSeed
	goto LyndoraCity_Gym_EventScript_Elowen_7

LyndoraCity_Gym_EventScript_Elowen_12:
# 103 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LEADER_ELOWEN, LyndoraCity_Gym_EventScript_Elowen_Text_4, LyndoraCity_Gym_EventScript_Elowen_Text_5, LyndoraCity_Gym_EventScript_ElowenDefeated
	goto LyndoraCity_Gym_EventScript_Elowen_10

LyndoraCity_Gym_EventScript_Elowen_13:
# 104 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LEADER_ELOWEN, LyndoraCity_Gym_EventScript_Elowen_Text_6, LyndoraCity_Gym_EventScript_Elowen_Text_7, LyndoraCity_Gym_EventScript_ElowenDefeated
	goto LyndoraCity_Gym_EventScript_Elowen_10

LyndoraCity_Gym_EventScript_Elowen_14:
# 105 "data/maps/LyndoraCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_LEADER_ELOWEN, LyndoraCity_Gym_EventScript_Elowen_Text_8, LyndoraCity_Gym_EventScript_Elowen_Text_9, LyndoraCity_Gym_EventScript_ElowenDefeated
	goto LyndoraCity_Gym_EventScript_Elowen_10

LyndoraCity_Gym_EventScript_Elowen_17:
# 93 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Elowen_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Elowen_15

LyndoraCity_Gym_EventScript_Elowen_18:
# 94 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Elowen_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Elowen_15

LyndoraCity_Gym_EventScript_Elowen_19:
# 95 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Elowen_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_Elowen_15


LyndoraCity_Gym_EventScript_ElowenDefeated::
# 113 "data/maps/LyndoraCity_Gym/scripts.pory"
	setspeaker LyndoraCity_Gym_EventScript_Elowen_Text_3
# 114 "data/maps/LyndoraCity_Gym/scripts.pory"
	showpssicon PSS_ICON_ELOWEN
# 115 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 116 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_ElowenDefeated_3
# 117 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_ElowenDefeated_4
# 118 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_ElowenDefeated_5
LyndoraCity_Gym_EventScript_ElowenDefeated_1:
# 120 "data/maps/LyndoraCity_Gym/scripts.pory"
	waitmessage
# 121 "data/maps/LyndoraCity_Gym/scripts.pory"
	callnative ClosePssIconPic
# 122 "data/maps/LyndoraCity_Gym/scripts.pory"
	call Common_EventScript_PlayLeafbondBadgeFanfare
# 123 "data/maps/LyndoraCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_LYNDORA_GYM
# 124 "data/maps/LyndoraCity_Gym/scripts.pory"
	setflag FLAG_BADGE02_GET
# 125 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto LyndoraCity_Gym_EventScript_GiveBulletSeed
	return

LyndoraCity_Gym_EventScript_ElowenDefeated_3:
# 116 "data/maps/LyndoraCity_Gym/scripts.pory"
	message LyndoraCity_Gym_EventScript_ElowenDefeated_Text_0
	goto LyndoraCity_Gym_EventScript_ElowenDefeated_1

LyndoraCity_Gym_EventScript_ElowenDefeated_4:
# 117 "data/maps/LyndoraCity_Gym/scripts.pory"
	message LyndoraCity_Gym_EventScript_ElowenDefeated_Text_1
	goto LyndoraCity_Gym_EventScript_ElowenDefeated_1

LyndoraCity_Gym_EventScript_ElowenDefeated_5:
# 118 "data/maps/LyndoraCity_Gym/scripts.pory"
	message LyndoraCity_Gym_EventScript_ElowenDefeated_Text_2
	goto LyndoraCity_Gym_EventScript_ElowenDefeated_1


LyndoraCity_Gym_EventScript_GiveBulletSeed::
# 129 "data/maps/LyndoraCity_Gym/scripts.pory"
	giveitem ITEM_TM_BULLET_SEED
# 130 "data/maps/LyndoraCity_Gym/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LyndoraCity_Gym_EventScript_GiveBulletSeed_2
LyndoraCity_Gym_EventScript_GiveBulletSeed_1:
# 133 "data/maps/LyndoraCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULLET_SEED
# 134 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 135 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_GiveBulletSeed_6
# 136 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_GiveBulletSeed_7
# 137 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_GiveBulletSeed_8
LyndoraCity_Gym_EventScript_GiveBulletSeed_4:
# 139 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto LyndoraCity_Gym_EventScript_AfterVictory
	return

LyndoraCity_Gym_EventScript_GiveBulletSeed_2:
# 131 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto Common_EventScript_ShowBagIsFull
	goto LyndoraCity_Gym_EventScript_GiveBulletSeed_1

LyndoraCity_Gym_EventScript_GiveBulletSeed_6:
# 135 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_GiveBulletSeed_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_GiveBulletSeed_4

LyndoraCity_Gym_EventScript_GiveBulletSeed_7:
# 136 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_GiveBulletSeed_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_GiveBulletSeed_4

LyndoraCity_Gym_EventScript_GiveBulletSeed_8:
# 137 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_GiveBulletSeed_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_GiveBulletSeed_4


LyndoraCity_Gym_EventScript_AfterVictory::
# 143 "data/maps/LyndoraCity_Gym/scripts.pory"
	setspeaker LyndoraCity_Gym_EventScript_Elowen_Text_3
# 144 "data/maps/LyndoraCity_Gym/scripts.pory"
	showpssicon PSS_ICON_ELOWEN
# 145 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 146 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_AfterVictory_3
# 147 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_AfterVictory_4
# 148 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_AfterVictory_5
LyndoraCity_Gym_EventScript_AfterVictory_1:
# 150 "data/maps/LyndoraCity_Gym/scripts.pory"
	callnative ClosePssIconPic
# 151 "data/maps/LyndoraCity_Gym/scripts.pory"
	release
	end

LyndoraCity_Gym_EventScript_AfterVictory_3:
# 146 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_AfterVictory_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_AfterVictory_1

LyndoraCity_Gym_EventScript_AfterVictory_4:
# 147 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_AfterVictory_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_AfterVictory_1

LyndoraCity_Gym_EventScript_AfterVictory_5:
# 148 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_AfterVictory_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_Gym_EventScript_AfterVictory_1


LyndoraCity_Gym_EventScript_Dipplin::
# 156 "data/maps/LyndoraCity_Gym/scripts.pory"
	lock
# 157 "data/maps/LyndoraCity_Gym/scripts.pory"
	faceplayer
# 158 "data/maps/LyndoraCity_Gym/scripts.pory"
	showmonmugshot SPECIES_DIPPLIN, MUGSHOT_SOUTHEAST
# 159 "data/maps/LyndoraCity_Gym/scripts.pory"
	setspeaker LyndoraCity_Gym_EventScript_Dipplin_Text_0
# 160 "data/maps/LyndoraCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, LyndoraCity_Gym_EventScript_Dipplin_2
# 167 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 168 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Dipplin_10
# 169 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Dipplin_11
# 170 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Dipplin_12
LyndoraCity_Gym_EventScript_Dipplin_1:
# 173 "data/maps/LyndoraCity_Gym/scripts.pory"
	waitmoncry
# 174 "data/maps/LyndoraCity_Gym/scripts.pory"
	hidemonmugshot
# 175 "data/maps/LyndoraCity_Gym/scripts.pory"
	release
	end

LyndoraCity_Gym_EventScript_Dipplin_2:
# 161 "data/maps/LyndoraCity_Gym/scripts.pory"
	switch VAR_LANGUAGE
# 162 "data/maps/LyndoraCity_Gym/scripts.pory"
	case PT, LyndoraCity_Gym_EventScript_Dipplin_6
# 163 "data/maps/LyndoraCity_Gym/scripts.pory"
	case EN, LyndoraCity_Gym_EventScript_Dipplin_7
# 164 "data/maps/LyndoraCity_Gym/scripts.pory"
	case ES, LyndoraCity_Gym_EventScript_Dipplin_8
	goto LyndoraCity_Gym_EventScript_Dipplin_1

LyndoraCity_Gym_EventScript_Dipplin_6:
# 162 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Dipplin_Text_1, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Dipplin_1

LyndoraCity_Gym_EventScript_Dipplin_7:
# 163 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Dipplin_Text_2, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Dipplin_1

LyndoraCity_Gym_EventScript_Dipplin_8:
# 164 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Dipplin_Text_3, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Dipplin_1

LyndoraCity_Gym_EventScript_Dipplin_10:
# 168 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Dipplin_Text_4, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Dipplin_1

LyndoraCity_Gym_EventScript_Dipplin_11:
# 169 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Dipplin_Text_5, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Dipplin_1

LyndoraCity_Gym_EventScript_Dipplin_12:
# 170 "data/maps/LyndoraCity_Gym/scripts.pory"
	msgbox LyndoraCity_Gym_EventScript_Dipplin_Text_6, MSGBOX_AUTOCLOSE
	goto LyndoraCity_Gym_EventScript_Dipplin_1


LyndoraCity_Gym_EventScript_Doorman_Text_0:
# 8 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Parabéns pela vitória!\pElowen ficou muito impressionada\ncom sua batalha.$"

LyndoraCity_Gym_EventScript_Doorman_Text_1:
# 9 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Congratulations on your victory!\pElowen was very impressed by\nyour battle.$"

LyndoraCity_Gym_EventScript_Doorman_Text_2:
# 10 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Felicidades por tu victoria!\pElowen quedó muy impresionada\ncon tu combate.$"

LyndoraCity_Gym_EventScript_Doorman_Text_3:
# 15 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Bem-vindo ao Ginásio de Lyndora!\pElowen aceita desafios de quem já\nconquistou a primeira insígnia.\pVolte depois de vencer o Ginásio\nde Stonereach!$"

LyndoraCity_Gym_EventScript_Doorman_Text_4:
# 16 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Welcome to Lyndora Gym!\pElowen accepts challenges from\ntrainers with the first Badge.\pReturn after winning at\nStonereach Gym!$"

LyndoraCity_Gym_EventScript_Doorman_Text_5:
# 17 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Te damos la bienvenida al\nGimnasio de Lyndora!\pElowen acepta desafíos de quienes\nya tienen la primera medalla.\p¡Vuelve tras vencer el Gimnasio\nde Stonereach!$"

LyndoraCity_Gym_EventScript_Doorman_Text_6:
# 21 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Elowen é paciente, mas não\nsubestime sua estratégia.\pOs treinadores daqui vão testar\nsua capacidade de adaptação!$"

LyndoraCity_Gym_EventScript_Doorman_Text_7:
# 22 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Elowen is patient, but do not\nunderestimate her strategy.\pThe trainers here will test your\nability to adapt!$"

LyndoraCity_Gym_EventScript_Doorman_Text_8:
# 23 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Elowen es paciente, pero no\nsubestimes su estrategia.\p¡Los entrenadores pondrán a prueba\ntu capacidad de adaptarte!$"

LyndoraCity_Gym_EventScript_Leah_Text_0:
# 35 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Elowen me ensinou que a natureza\nsempre encontra um caminho.\pVamos ver se você encontra o seu!$"

LyndoraCity_Gym_EventScript_Leah_Text_1:
# 35 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Você encontrou uma boa\nestratégia!$"

LyndoraCity_Gym_EventScript_Leah_Text_2:
# 36 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Elowen taught me that nature\nalways finds a way.\pLet us see if you can find yours!$"

LyndoraCity_Gym_EventScript_Leah_Text_3:
# 36 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "You found a good strategy!$"

LyndoraCity_Gym_EventScript_Leah_Text_4:
# 37 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Elowen me enseñó que la naturaleza\nsiempre encuentra un camino.\p¡Veamos si encuentras el tuyo!$"

LyndoraCity_Gym_EventScript_Leah_Text_5:
# 37 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Encontraste una buena estrategia!$"

LyndoraCity_Gym_EventScript_Leah_Text_6:
# 40 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Elowen vai querer ver isso de\nperto!$"

LyndoraCity_Gym_EventScript_Leah_Text_7:
# 41 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Elowen will want to see that\nfor herself!$"

LyndoraCity_Gym_EventScript_Leah_Text_8:
# 42 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Elowen querrá verlo de cerca!$"

LyndoraCity_Gym_EventScript_Beauty_Text_0:
# 52 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Flores bonitas precisam de\ncuidados constantes.\pMeus Pokémon também!\pMostre como cuida dos seus\ncompanheiros!$"

LyndoraCity_Gym_EventScript_Beauty_Text_1:
# 52 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Que batalha encantadora!$"

LyndoraCity_Gym_EventScript_Beauty_Text_2:
# 53 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Beautiful flowers need constant\ncare.\pSo do my Pokémon!\pShow me how you care for your\ncompanions!$"

LyndoraCity_Gym_EventScript_Beauty_Text_3:
# 53 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "What a lovely battle!$"

LyndoraCity_Gym_EventScript_Beauty_Text_4:
# 54 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Las flores bonitas necesitan\ncuidados constantes.\p¡Mis Pokémon también!\p¡Muéstrame cómo cuidas a tus\ncompañeros!$"

LyndoraCity_Gym_EventScript_Beauty_Text_5:
# 54 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Qué combate tan encantador!$"

LyndoraCity_Gym_EventScript_Beauty_Text_6:
# 57 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Você e seus Pokémon formam uma\nótima equipe.$"

LyndoraCity_Gym_EventScript_Beauty_Text_7:
# 58 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "You and your Pokémon make a\ngreat team.$"

LyndoraCity_Gym_EventScript_Beauty_Text_8:
# 59 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Tú y tus Pokémon forman un\nequipo excelente.$"

LyndoraCity_Gym_EventScript_AromaLady_Text_0:
# 69 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Consegue sentir o perfume destas\nflores?\pNão se distraia com tanta beleza!\pMeus Pokémon estão prontos para\nbatalhar!$"

LyndoraCity_Gym_EventScript_AromaLady_Text_1:
# 69 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Ah, que resultado inesperado!$"

LyndoraCity_Gym_EventScript_AromaLady_Text_2:
# 70 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Can you smell these flowers?\pDo not get distracted by all\nthis beauty!\pMy Pokémon are ready to battle!$"

LyndoraCity_Gym_EventScript_AromaLady_Text_3:
# 70 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Oh, what an unexpected result!$"

LyndoraCity_Gym_EventScript_AromaLady_Text_4:
# 71 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¿Sientes el aroma de estas flores?\p¡No te distraigas con tanta\nbelleza!\p¡Mis Pokémon están listos para\ncombatir!$"

LyndoraCity_Gym_EventScript_AromaLady_Text_5:
# 71 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Qué resultado tan inesperado!$"

LyndoraCity_Gym_EventScript_AromaLady_Text_6:
# 74 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Continue cuidando tão bem dos\nseus Pokémon!$"

LyndoraCity_Gym_EventScript_AromaLady_Text_7:
# 75 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Keep taking such good care of\nyour Pokémon!$"

LyndoraCity_Gym_EventScript_AromaLady_Text_8:
# 76 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Sigue cuidando tan bien a tus\nPokémon!$"

LyndoraCity_Gym_EventScript_Elowen_Text_0:
# 93 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Desculpe, mas o desafio do meu\nGinásio exige a insígnia de\nStonereach.$"

LyndoraCity_Gym_EventScript_Elowen_Text_1:
# 94 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "I am sorry, but my Gym challenge\nrequires the Stonereach Badge.$"

LyndoraCity_Gym_EventScript_Elowen_Text_2:
# 95 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Lo siento, pero mi desafío exige\nla medalla de Stonereach.$"

LyndoraCity_Gym_EventScript_Elowen_Text_3:
# 100 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Elowen$"

LyndoraCity_Gym_EventScript_Elowen_Text_4:
# 103 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Oh! Você é aquele treinador da\nRota 5!\pQue bom ver você novamente.\nAquele Shroomish já está muito\nmelhor.\pAh, acho que ainda não me\napresentei.\nMeu nome é Elowen, Líder deste\nGinásio.\pEntão... veio me desafiar?\pÓtimo! Vamos ver como você e seus\nPokémon se saem!$"

LyndoraCity_Gym_EventScript_Elowen_Text_5:
# 103 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Impressionante! Você soube se\nadaptar quando a batalha apertou.$"

LyndoraCity_Gym_EventScript_Elowen_Text_6:
# 104 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Oh! You are that Trainer from\nRoute 5!\pIt is good to see you again.\nThat Shroomish is doing much\nbetter now.\pOh, I have not introduced myself.\nMy name is Elowen, Leader of this\nGym.\pSo... have you come to challenge\nme?\pWonderful! Let us see how you and\nyour Pokémon do!$"

LyndoraCity_Gym_EventScript_Elowen_Text_7:
# 104 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Impressive! You adapted even when\nthe battle got difficult.$"

LyndoraCity_Gym_EventScript_Elowen_Text_8:
# 105 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Oh! ¡Eres aquel entrenador de\nla Ruta 5!\pMe alegra volver a verte.\nAquel Shroomish está mucho mejor.\pAh, aún no me he presentado.\nSoy Elowen, Líder de este\nGimnasio.\pEntonces... ¿viniste a desafiarme?\p¡Muy bien! Veamos cómo les va a ti\ny a tus Pokémon.$"

LyndoraCity_Gym_EventScript_Elowen_Text_9:
# 105 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Impresionante! Supiste adaptarte\ncuando el combate se complicó.$"

LyndoraCity_Gym_EventScript_ElowenDefeated_Text_0:
# 116 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Impressionante!\pVocê merece a INSÍGNIA\nLEAFBOND!$"

LyndoraCity_Gym_EventScript_ElowenDefeated_Text_1:
# 117 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Impressive!\pYou deserve the LEAFBOND\nBADGE!$"

LyndoraCity_Gym_EventScript_ElowenDefeated_Text_2:
# 118 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Impresionante!\p¡Mereces la MEDALLA\nLEAFBOND!$"

LyndoraCity_Gym_EventScript_GiveBulletSeed_Text_0:
# 135 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Você recebeu uma TM50!\pEla contém BULLET SEED.$"

LyndoraCity_Gym_EventScript_GiveBulletSeed_Text_1:
# 136 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "You received a TM50!\pIt contains BULLET SEED.$"

LyndoraCity_Gym_EventScript_GiveBulletSeed_Text_2:
# 137 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "¡Recibiste una MT50!\pContiene BULLET SEED.$"

LyndoraCity_Gym_EventScript_AfterVictory_Text_0:
# 146 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Continue confiando nos seus\nPokémon.\pCada batalha é uma chance de\ncrescerem juntos.$"

LyndoraCity_Gym_EventScript_AfterVictory_Text_1:
# 147 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Keep trusting your Pokémon.\pEvery battle is a chance for you\nto grow together.$"

LyndoraCity_Gym_EventScript_AfterVictory_Text_2:
# 148 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Sigue confiando en tus Pokémon.\pCada combate es una oportunidad\npara crecer juntos.$"

LyndoraCity_Gym_EventScript_Dipplin_Text_0:
# 159 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Dipplin$"

LyndoraCity_Gym_EventScript_Dipplin_Text_1:
# 162 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Dipplin: Dipplin!\pDipplin parece feliz por você ter\nvencido Elowen.$"

LyndoraCity_Gym_EventScript_Dipplin_Text_2:
# 163 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Dipplin: Dipplin!\pDipplin seems happy that you\ndefeated Elowen.$"

LyndoraCity_Gym_EventScript_Dipplin_Text_3:
# 164 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Dipplin: ¡Dipplin!\pDipplin parece feliz de que hayas\nvencido a Elowen.$"

LyndoraCity_Gym_EventScript_Dipplin_Text_4:
# 168 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Dipplin: Dipplin!\pO Pokémon parece aproveitar o\naroma das flores.$"

LyndoraCity_Gym_EventScript_Dipplin_Text_5:
# 169 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Dipplin: Dipplin!\pThe Pokémon seems to be enjoying\nthe scent of the flowers.$"

LyndoraCity_Gym_EventScript_Dipplin_Text_6:
# 170 "data/maps/LyndoraCity_Gym/scripts.pory"
	.string "Dipplin: ¡Dipplin!\pEl Pokémon parece disfrutar del\naroma de las flores.$"
