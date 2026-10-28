LyndoraCity_MapScripts::
	.byte 0


LyndoraCity_EventScript_SchoolKidF::
# 4 "data/maps/LyndoraCity/scripts.pory"
	lock
# 5 "data/maps/LyndoraCity/scripts.pory"
	faceplayer
# 7 "data/maps/LyndoraCity/scripts.pory"
	goto_if_set FLAG_TEMP_1, LyndoraCity_EventScript_SchoolKidF_2
# 14 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 15 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_SchoolKidF_11
# 16 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_SchoolKidF_12
# 17 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_SchoolKidF_13
LyndoraCity_EventScript_SchoolKidF_9:
# 19 "data/maps/LyndoraCity/scripts.pory"
	setflag FLAG_TEMP_1
LyndoraCity_EventScript_SchoolKidF_1:
# 21 "data/maps/LyndoraCity/scripts.pory"
	release
	end

LyndoraCity_EventScript_SchoolKidF_2:
# 8 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 9 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_SchoolKidF_6
# 10 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_SchoolKidF_7
# 11 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_SchoolKidF_8
	goto LyndoraCity_EventScript_SchoolKidF_1

LyndoraCity_EventScript_SchoolKidF_6:
# 9 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_SchoolKidF_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_SchoolKidF_1

LyndoraCity_EventScript_SchoolKidF_7:
# 10 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_SchoolKidF_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_SchoolKidF_1

LyndoraCity_EventScript_SchoolKidF_8:
# 11 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_SchoolKidF_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_SchoolKidF_1

LyndoraCity_EventScript_SchoolKidF_11:
# 15 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_SchoolKidF_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_SchoolKidF_9

LyndoraCity_EventScript_SchoolKidF_12:
# 16 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_SchoolKidF_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_SchoolKidF_9

LyndoraCity_EventScript_SchoolKidF_13:
# 17 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_SchoolKidF_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_SchoolKidF_9


LyndoraCity_EventScript_Girl::
# 26 "data/maps/LyndoraCity/scripts.pory"
	lock
# 27 "data/maps/LyndoraCity/scripts.pory"
	faceplayer
# 29 "data/maps/LyndoraCity/scripts.pory"
	goto_if_set FLAG_TEMP_2, LyndoraCity_EventScript_Girl_2
# 36 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 37 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_Girl_11
# 38 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_Girl_12
# 39 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_Girl_13
LyndoraCity_EventScript_Girl_9:
# 41 "data/maps/LyndoraCity/scripts.pory"
	setflag FLAG_TEMP_2
LyndoraCity_EventScript_Girl_1:
# 43 "data/maps/LyndoraCity/scripts.pory"
	release
	end

LyndoraCity_EventScript_Girl_2:
# 30 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 31 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_Girl_6
# 32 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_Girl_7
# 33 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_Girl_8
	goto LyndoraCity_EventScript_Girl_1

LyndoraCity_EventScript_Girl_6:
# 31 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Girl_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Girl_1

LyndoraCity_EventScript_Girl_7:
# 32 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Girl_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Girl_1

LyndoraCity_EventScript_Girl_8:
# 33 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Girl_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Girl_1

LyndoraCity_EventScript_Girl_11:
# 37 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Girl_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Girl_9

LyndoraCity_EventScript_Girl_12:
# 38 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Girl_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Girl_9

LyndoraCity_EventScript_Girl_13:
# 39 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Girl_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Girl_9


LyndoraCity_EventScript_Fisherman::
# 48 "data/maps/LyndoraCity/scripts.pory"
	lock
# 49 "data/maps/LyndoraCity/scripts.pory"
	faceplayer
# 50 "data/maps/LyndoraCity/scripts.pory"
	checktrainerflag TRAINER_FISHERMAN_BIROLIRO
# 51 "data/maps/LyndoraCity/scripts.pory"
	goto_if_eq TRUE, LyndoraCity_EventScript_Fisherman_AfterBattle
# 52 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 53 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_Fisherman_3
# 54 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_Fisherman_4
# 55 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_Fisherman_5
LyndoraCity_EventScript_Fisherman_1:
# 57 "data/maps/LyndoraCity/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq LyndoraCity_EventScript_Fisherman_7
# 66 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 67 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_Fisherman_11
# 68 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_Fisherman_12
# 69 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_Fisherman_13
LyndoraCity_EventScript_Fisherman_9:
# 71 "data/maps/LyndoraCity/scripts.pory"
	goto LyndoraCity_EventScript_Fisherman_AfterBattle
	return

LyndoraCity_EventScript_Fisherman_3:
# 53 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Fisherman_Text_0, MSGBOX_YESNO
	goto LyndoraCity_EventScript_Fisherman_1

LyndoraCity_EventScript_Fisherman_4:
# 54 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Fisherman_Text_1, MSGBOX_YESNO
	goto LyndoraCity_EventScript_Fisherman_1

LyndoraCity_EventScript_Fisherman_5:
# 55 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Fisherman_Text_2, MSGBOX_YESNO
	goto LyndoraCity_EventScript_Fisherman_1

LyndoraCity_EventScript_Fisherman_7:
# 58 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 59 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_Fisherman_16
# 60 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_Fisherman_17
# 61 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_Fisherman_18
LyndoraCity_EventScript_Fisherman_14:
# 63 "data/maps/LyndoraCity/scripts.pory"
	release
	end

LyndoraCity_EventScript_Fisherman_11:
# 67 "data/maps/LyndoraCity/scripts.pory"
	trainerbattle_single TRAINER_FISHERMAN_BIROLIRO, LyndoraCity_EventScript_Fisherman_Text_6, LyndoraCity_EventScript_Fisherman_Text_7
	goto LyndoraCity_EventScript_Fisherman_9

LyndoraCity_EventScript_Fisherman_12:
# 68 "data/maps/LyndoraCity/scripts.pory"
	trainerbattle_single TRAINER_FISHERMAN_BIROLIRO, LyndoraCity_EventScript_Fisherman_Text_8, LyndoraCity_EventScript_Fisherman_Text_9
	goto LyndoraCity_EventScript_Fisherman_9

LyndoraCity_EventScript_Fisherman_13:
# 69 "data/maps/LyndoraCity/scripts.pory"
	trainerbattle_single TRAINER_FISHERMAN_BIROLIRO, LyndoraCity_EventScript_Fisherman_Text_10, LyndoraCity_EventScript_Fisherman_Text_11
	goto LyndoraCity_EventScript_Fisherman_9

LyndoraCity_EventScript_Fisherman_16:
# 59 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Fisherman_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Fisherman_14

LyndoraCity_EventScript_Fisherman_17:
# 60 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Fisherman_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Fisherman_14

LyndoraCity_EventScript_Fisherman_18:
# 61 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Fisherman_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Fisherman_14


LyndoraCity_EventScript_Fisherman_AfterBattle::
# 75 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 76 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_Fisherman_AfterBattle_3
# 77 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_Fisherman_AfterBattle_4
# 78 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_Fisherman_AfterBattle_5
LyndoraCity_EventScript_Fisherman_AfterBattle_1:
# 80 "data/maps/LyndoraCity/scripts.pory"
	release
	end

LyndoraCity_EventScript_Fisherman_AfterBattle_3:
# 76 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Fisherman_AfterBattle_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Fisherman_AfterBattle_1

LyndoraCity_EventScript_Fisherman_AfterBattle_4:
# 77 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Fisherman_AfterBattle_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Fisherman_AfterBattle_1

LyndoraCity_EventScript_Fisherman_AfterBattle_5:
# 78 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Fisherman_AfterBattle_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Fisherman_AfterBattle_1


LyndoraCity_EventScript_Psyduck::
# 85 "data/maps/LyndoraCity/scripts.pory"
	lock
# 86 "data/maps/LyndoraCity/scripts.pory"
	faceplayer
# 87 "data/maps/LyndoraCity/scripts.pory"
	showmonmugshot SPECIES_PSYDUCK, MUGSHOT_SOUTHEAST
# 88 "data/maps/LyndoraCity/scripts.pory"
	setspeaker LyndoraCity_EventScript_Psyduck_Text_0
# 89 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Psyduck_Text_1, MSGBOX_DEFAULT
# 90 "data/maps/LyndoraCity/scripts.pory"
	waitmoncry
# 91 "data/maps/LyndoraCity/scripts.pory"
	hidemonmugshot
# 92 "data/maps/LyndoraCity/scripts.pory"
	release
	end


LyndoraCity_EventScript_OldMan::
# 97 "data/maps/LyndoraCity/scripts.pory"
	lock
# 98 "data/maps/LyndoraCity/scripts.pory"
	faceplayer
# 99 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 100 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_OldMan_3
# 101 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_OldMan_4
# 102 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_OldMan_5
LyndoraCity_EventScript_OldMan_1:
# 104 "data/maps/LyndoraCity/scripts.pory"
	release
	end

LyndoraCity_EventScript_OldMan_3:
# 100 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_OldMan_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_OldMan_1

LyndoraCity_EventScript_OldMan_4:
# 101 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_OldMan_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_OldMan_1

LyndoraCity_EventScript_OldMan_5:
# 102 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_OldMan_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_OldMan_1


LyndoraCity_EventScript_GymSign::
# 109 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 110 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_GymSign_3
# 111 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_GymSign_4
# 112 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_GymSign_5
LyndoraCity_EventScript_GymSign_1:
	end

LyndoraCity_EventScript_GymSign_3:
# 110 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_GymSign_Text_0, MSGBOX_SIGN
	goto LyndoraCity_EventScript_GymSign_1

LyndoraCity_EventScript_GymSign_4:
# 111 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_GymSign_Text_1, MSGBOX_SIGN
	goto LyndoraCity_EventScript_GymSign_1

LyndoraCity_EventScript_GymSign_5:
# 112 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_GymSign_Text_2, MSGBOX_SIGN
	goto LyndoraCity_EventScript_GymSign_1


LyndoraCity_EventScript_CitySign::
# 118 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 119 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_CitySign_3
# 120 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_CitySign_4
# 121 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_CitySign_5
LyndoraCity_EventScript_CitySign_1:
	end

LyndoraCity_EventScript_CitySign_3:
# 119 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_CitySign_Text_0, MSGBOX_SIGN
	goto LyndoraCity_EventScript_CitySign_1

LyndoraCity_EventScript_CitySign_4:
# 120 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_CitySign_Text_1, MSGBOX_SIGN
	goto LyndoraCity_EventScript_CitySign_1

LyndoraCity_EventScript_CitySign_5:
# 121 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_CitySign_Text_2, MSGBOX_SIGN
	goto LyndoraCity_EventScript_CitySign_1


LyndoraCity_EventScript_FlowerShopSign::
# 127 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 128 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_FlowerShopSign_3
# 129 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_FlowerShopSign_4
# 130 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_FlowerShopSign_5
LyndoraCity_EventScript_FlowerShopSign_1:
	end

LyndoraCity_EventScript_FlowerShopSign_3:
# 128 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_FlowerShopSign_Text_0, MSGBOX_SIGN
	goto LyndoraCity_EventScript_FlowerShopSign_1

LyndoraCity_EventScript_FlowerShopSign_4:
# 129 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_FlowerShopSign_Text_1, MSGBOX_SIGN
	goto LyndoraCity_EventScript_FlowerShopSign_1

LyndoraCity_EventScript_FlowerShopSign_5:
# 130 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_FlowerShopSign_Text_2, MSGBOX_SIGN
	goto LyndoraCity_EventScript_FlowerShopSign_1


LyndoraCity_EventScript_PokemonCenterSign::
# 136 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 137 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_PokemonCenterSign_3
# 138 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_PokemonCenterSign_4
# 139 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_PokemonCenterSign_5
LyndoraCity_EventScript_PokemonCenterSign_1:
	end

LyndoraCity_EventScript_PokemonCenterSign_3:
# 137 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_PokemonCenterSign_Text_0, MSGBOX_SIGN
	goto LyndoraCity_EventScript_PokemonCenterSign_1

LyndoraCity_EventScript_PokemonCenterSign_4:
# 138 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_PokemonCenterSign_Text_1, MSGBOX_SIGN
	goto LyndoraCity_EventScript_PokemonCenterSign_1

LyndoraCity_EventScript_PokemonCenterSign_5:
# 139 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_PokemonCenterSign_Text_2, MSGBOX_SIGN
	goto LyndoraCity_EventScript_PokemonCenterSign_1


LyndoraCity_EventScript_MartSign::
# 145 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 146 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_MartSign_3
# 147 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_MartSign_4
# 148 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_MartSign_5
LyndoraCity_EventScript_MartSign_1:
	end

LyndoraCity_EventScript_MartSign_3:
# 146 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_MartSign_Text_0, MSGBOX_SIGN
	goto LyndoraCity_EventScript_MartSign_1

LyndoraCity_EventScript_MartSign_4:
# 147 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_MartSign_Text_1, MSGBOX_SIGN
	goto LyndoraCity_EventScript_MartSign_1

LyndoraCity_EventScript_MartSign_5:
# 148 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_MartSign_Text_2, MSGBOX_SIGN
	goto LyndoraCity_EventScript_MartSign_1


LyndoraCity_EventScript_FountainResident::
# 154 "data/maps/LyndoraCity/scripts.pory"
	lock
# 155 "data/maps/LyndoraCity/scripts.pory"
	faceplayer
# 156 "data/maps/LyndoraCity/scripts.pory"
	goto_if_set FLAG_LYNDORA_MET_FOUNTAIN_RESIDENT, LyndoraCity_EventScript_FountainResident_2
# 163 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 164 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_FountainResident_11
# 165 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_FountainResident_12
# 166 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_FountainResident_13
LyndoraCity_EventScript_FountainResident_9:
# 168 "data/maps/LyndoraCity/scripts.pory"
	setflag FLAG_LYNDORA_MET_FOUNTAIN_RESIDENT
LyndoraCity_EventScript_FountainResident_1:
# 170 "data/maps/LyndoraCity/scripts.pory"
	release
	end

LyndoraCity_EventScript_FountainResident_2:
# 157 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 158 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_FountainResident_6
# 159 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_FountainResident_7
# 160 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_FountainResident_8
	goto LyndoraCity_EventScript_FountainResident_1

LyndoraCity_EventScript_FountainResident_6:
# 158 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_FountainResident_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_FountainResident_1

LyndoraCity_EventScript_FountainResident_7:
# 159 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_FountainResident_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_FountainResident_1

LyndoraCity_EventScript_FountainResident_8:
# 160 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_FountainResident_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_FountainResident_1

LyndoraCity_EventScript_FountainResident_11:
# 164 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_FountainResident_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_FountainResident_9

LyndoraCity_EventScript_FountainResident_12:
# 165 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_FountainResident_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_FountainResident_9

LyndoraCity_EventScript_FountainResident_13:
# 166 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_FountainResident_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_FountainResident_9


LyndoraCity_EventScript_Gardener::
# 175 "data/maps/LyndoraCity/scripts.pory"
	lock
# 176 "data/maps/LyndoraCity/scripts.pory"
	faceplayer
# 178 "data/maps/LyndoraCity/scripts.pory"
	goto_if_set FLAG_LYNDORA_PLANTS_EVENT_COMPLETE, LyndoraCity_EventScript_Gardener_2
# 185 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 186 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_Gardener_10
# 187 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_Gardener_11
# 188 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_Gardener_12
LyndoraCity_EventScript_Gardener_1:
# 191 "data/maps/LyndoraCity/scripts.pory"
	release
	end

LyndoraCity_EventScript_Gardener_2:
# 179 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 180 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_Gardener_6
# 181 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_Gardener_7
# 182 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_Gardener_8
	goto LyndoraCity_EventScript_Gardener_1

LyndoraCity_EventScript_Gardener_6:
# 180 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Gardener_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Gardener_1

LyndoraCity_EventScript_Gardener_7:
# 181 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Gardener_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Gardener_1

LyndoraCity_EventScript_Gardener_8:
# 182 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Gardener_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Gardener_1

LyndoraCity_EventScript_Gardener_10:
# 186 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Gardener_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Gardener_1

LyndoraCity_EventScript_Gardener_11:
# 187 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Gardener_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Gardener_1

LyndoraCity_EventScript_Gardener_12:
# 188 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Gardener_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Gardener_1


LyndoraCity_EventScript_Gardener2::
# 196 "data/maps/LyndoraCity/scripts.pory"
	lock
# 197 "data/maps/LyndoraCity/scripts.pory"
	faceplayer
# 198 "data/maps/LyndoraCity/scripts.pory"
	switch VAR_LANGUAGE
# 199 "data/maps/LyndoraCity/scripts.pory"
	case PT, LyndoraCity_EventScript_Gardener2_3
# 200 "data/maps/LyndoraCity/scripts.pory"
	case EN, LyndoraCity_EventScript_Gardener2_4
# 201 "data/maps/LyndoraCity/scripts.pory"
	case ES, LyndoraCity_EventScript_Gardener2_5
LyndoraCity_EventScript_Gardener2_1:
# 203 "data/maps/LyndoraCity/scripts.pory"
	release
	end

LyndoraCity_EventScript_Gardener2_3:
# 199 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Gardener2_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Gardener2_1

LyndoraCity_EventScript_Gardener2_4:
# 200 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Gardener2_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Gardener2_1

LyndoraCity_EventScript_Gardener2_5:
# 201 "data/maps/LyndoraCity/scripts.pory"
	msgbox LyndoraCity_EventScript_Gardener2_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_EventScript_Gardener2_1


LyndoraCity_EventScript_SchoolKidF_Text_0:
# 9 "data/maps/LyndoraCity/scripts.pory"
	.string "Será que um BULBASAUR\nprecisa de fertilizante?\pMelhor perguntar à Elowen!$"

LyndoraCity_EventScript_SchoolKidF_Text_1:
# 10 "data/maps/LyndoraCity/scripts.pory"
	.string "Does a BULBASAUR\nneed fertilizer?\pI'd better ask Elowen!$"

LyndoraCity_EventScript_SchoolKidF_Text_2:
# 11 "data/maps/LyndoraCity/scripts.pory"
	.string "¿Necesitará abono\nun BULBASAUR?\p¡Mejor le pregunto a Elowen!$"

LyndoraCity_EventScript_SchoolKidF_Text_3:
# 15 "data/maps/LyndoraCity/scripts.pory"
	.string "Hoje aprendemos que as plantas\nprecisam de água e luz\lpara crescer!\pEntão eu perguntei\nà professora...\pSe eu regar meu BULBASAUR,\nele vai crescer mais rápido?\pHehe! Ela não soube\no que responder!$"

LyndoraCity_EventScript_SchoolKidF_Text_4:
# 16 "data/maps/LyndoraCity/scripts.pory"
	.string "Today we learned that plants\nneed water and light to grow!\pSo I asked my teacher...\pIf I water my BULBASAUR,\nwill it grow faster?\pHehe! She didn't know\nwhat to say!$"

LyndoraCity_EventScript_SchoolKidF_Text_5:
# 17 "data/maps/LyndoraCity/scripts.pory"
	.string "¡Hoy aprendimos que las plantas\nnecesitan agua y luz\lpara crecer!\pEntonces le pregunté\na la profesora...\pSi riego a mi BULBASAUR,\n¿crecerá más rápido?\p¡Je, je! ¡No supo\nqué responder!$"

LyndoraCity_EventScript_Girl_Text_0:
# 31 "data/maps/LyndoraCity/scripts.pory"
	.string "Elowen diz que cuidar de um\nPokémon é como cultivar\luma planta.\pÉ preciso paciência,\ncarinho e atenção.$"

LyndoraCity_EventScript_Girl_Text_1:
# 32 "data/maps/LyndoraCity/scripts.pory"
	.string "Elowen says caring for a Pokémon\nis like growing a plant.\pIt takes patience,\nlove, and attention.$"

LyndoraCity_EventScript_Girl_Text_2:
# 33 "data/maps/LyndoraCity/scripts.pory"
	.string "Elowen dice que cuidar de un\nPokémon es como cultivar\luna planta.\pHace falta paciencia,\ncariño y atención.$"

LyndoraCity_EventScript_Girl_Text_3:
# 37 "data/maps/LyndoraCity/scripts.pory"
	.string "Minha irmãzinha acha que pode\nfazer um BULBASAUR crescer\lusando um regador!\pEu disse que Pokémon\nnão funcionam assim...\p...mas agora ela quer testar\ncom meu ODDISH!$"

LyndoraCity_EventScript_Girl_Text_4:
# 38 "data/maps/LyndoraCity/scripts.pory"
	.string "My little sister thinks she can\nmake a BULBASAUR grow\lwith a watering can!\pI told her Pokémon\ndon't work that way...\p...but now she wants to try\nit on my ODDISH!$"

LyndoraCity_EventScript_Girl_Text_5:
# 39 "data/maps/LyndoraCity/scripts.pory"
	.string "¡Mi hermanita cree que puede\nhacer crecer a un BULBASAUR\lcon una regadera!\pLe dije que los Pokémon\nno funcionan así...\p...¡pero ahora quiere probar\ncon mi ODDISH!$"

LyndoraCity_EventScript_Fisherman_Text_0:
# 53 "data/maps/LyndoraCity/scripts.pory"
	.string "Os Pokémon aquáticos parecem\ntranquilos nestes rios...\pMas são rápidos numa batalha!\nQuer enfrentar minha equipe?$"

LyndoraCity_EventScript_Fisherman_Text_1:
# 54 "data/maps/LyndoraCity/scripts.pory"
	.string "Water Pokémon look so peaceful\nin these rivers...\pBut they're quick in battle!\nWant to take on my team?$"

LyndoraCity_EventScript_Fisherman_Text_2:
# 55 "data/maps/LyndoraCity/scripts.pory"
	.string "Los Pokémon acuáticos parecen\ntranquilos en estos ríos...\p¡Pero son rápidos en combate!\n¿Quieres enfrentarte a mi equipo?$"

LyndoraCity_EventScript_Fisherman_Text_3:
# 59 "data/maps/LyndoraCity/scripts.pory"
	.string "Sem pressa! Até para pescar\né preciso ter paciência.\pMeus Pokémon e eu\nficaremos por aqui!$"

LyndoraCity_EventScript_Fisherman_Text_4:
# 60 "data/maps/LyndoraCity/scripts.pory"
	.string "No rush! Fishing takes\npatience, too.\pMy Pokémon and I\nwill be right here!$"

LyndoraCity_EventScript_Fisherman_Text_5:
# 61 "data/maps/LyndoraCity/scripts.pory"
	.string "¡Sin prisa! Para pescar\ntambién hace falta paciencia.\p¡Mis Pokémon y yo\nseguiremos por aquí!$"

LyndoraCity_EventScript_Fisherman_Text_6:
# 67 "data/maps/LyndoraCity/scripts.pory"
	.string "Vamos fazer ondas!$"

LyndoraCity_EventScript_Fisherman_Text_7:
# 67 "data/maps/LyndoraCity/scripts.pory"
	.string "Essa eu não consegui fisgar!$"

LyndoraCity_EventScript_Fisherman_Text_8:
# 68 "data/maps/LyndoraCity/scripts.pory"
	.string "Let's make some waves!$"

LyndoraCity_EventScript_Fisherman_Text_9:
# 68 "data/maps/LyndoraCity/scripts.pory"
	.string "That one got away!$"

LyndoraCity_EventScript_Fisherman_Text_10:
# 69 "data/maps/LyndoraCity/scripts.pory"
	.string "¡Vamos a levantar olas!$"

LyndoraCity_EventScript_Fisherman_Text_11:
# 69 "data/maps/LyndoraCity/scripts.pory"
	.string "¡Esta se me escapó!$"

LyndoraCity_EventScript_Fisherman_AfterBattle_Text_0:
# 76 "data/maps/LyndoraCity/scripts.pory"
	.string "Você tem jeito para batalhas!\pOs Pokémon aquáticos precisam\nde rios limpos para viver.\pCuidar destas águas é cuidar\ndos nossos companheiros!$"

LyndoraCity_EventScript_Fisherman_AfterBattle_Text_1:
# 77 "data/maps/LyndoraCity/scripts.pory"
	.string "You've got a knack for battling!\pWater Pokémon need clean rivers\nto live in.\pCaring for these waters means\ncaring for our companions!$"

LyndoraCity_EventScript_Fisherman_AfterBattle_Text_2:
# 78 "data/maps/LyndoraCity/scripts.pory"
	.string "¡Se te dan bien los combates!\pLos Pokémon acuáticos necesitan\nríos limpios para vivir.\p¡Cuidar estas aguas es cuidar\na nuestros compañeros!$"

LyndoraCity_EventScript_Psyduck_Text_0:
# 88 "data/maps/LyndoraCity/scripts.pory"
	.string "Psyduck$"

LyndoraCity_EventScript_Psyduck_Text_1:
# 89 "data/maps/LyndoraCity/scripts.pory"
	.string "Psy... duck?$"

LyndoraCity_EventScript_OldMan_Text_0:
# 100 "data/maps/LyndoraCity/scripts.pory"
	.string "Quando eu era menino, ajudava\na cuidar dos jardins daqui.\pHoje, meu POKéMON rega as flores\nenquanto eu descanso.\pHe, he! Ele nunca esquece\nde molhar meus sapatos!$"

LyndoraCity_EventScript_OldMan_Text_1:
# 101 "data/maps/LyndoraCity/scripts.pory"
	.string "As a boy, I used to help\ncare for the gardens here.\pNow my POKéMON waters the flowers\nwhile I take a rest.\pHeh, heh! It never forgets\nto soak my shoes!$"

LyndoraCity_EventScript_OldMan_Text_2:
# 102 "data/maps/LyndoraCity/scripts.pory"
	.string "De niño, ayudaba a cuidar\nlos jardines de aquí.\pAhora mi POKéMON riega las flores\nmientras yo descanso.\p¡Je, je! ¡Nunca se olvida\nde mojarme los zapatos!$"

LyndoraCity_EventScript_GymSign_Text_0:
# 110 "data/maps/LyndoraCity/scripts.pory"
	.string "Ginásio Pokémon de Lyndora City\pLíder: Elowen\nEspecialista em Pokémon\ldo tipo Planta.\pA gentileza que faz\na força florescer!$"

LyndoraCity_EventScript_GymSign_Text_1:
# 111 "data/maps/LyndoraCity/scripts.pory"
	.string "Lyndora City Pokémon Gym\pLeader: Elowen\nGrass-type Pokémon specialist.\pThe kindness that makes\nstrength bloom!$"

LyndoraCity_EventScript_GymSign_Text_2:
# 112 "data/maps/LyndoraCity/scripts.pory"
	.string "Gimnasio Pokémon de Lyndora City\pLíder: Elowen\nEspecialista en Pokémon\lde tipo Planta.\p¡La dulzura que hace\nflorecer la fuerza!$"

LyndoraCity_EventScript_CitySign_Text_0:
# 119 "data/maps/LyndoraCity/scripts.pory"
	.string "Lyndora City\pOnde a amizade floresce\nàs margens dos rios.$"

LyndoraCity_EventScript_CitySign_Text_1:
# 120 "data/maps/LyndoraCity/scripts.pory"
	.string "Lyndora City\pWhere friendship blooms\nalong the rivers.$"

LyndoraCity_EventScript_CitySign_Text_2:
# 121 "data/maps/LyndoraCity/scripts.pory"
	.string "Lyndora City\pDonde la amistad florece\na orillas de los ríos.$"

LyndoraCity_EventScript_FlowerShopSign_Text_0:
# 128 "data/maps/LyndoraCity/scripts.pory"
	.string "Floricultura de Lyndora City\pFlores para alegrar seu dia!$"

LyndoraCity_EventScript_FlowerShopSign_Text_1:
# 129 "data/maps/LyndoraCity/scripts.pory"
	.string "Lyndora City Flower Shop\pFlowers to brighten your day!$"

LyndoraCity_EventScript_FlowerShopSign_Text_2:
# 130 "data/maps/LyndoraCity/scripts.pory"
	.string "Floristería de Lyndora City\p¡Flores para alegrar tu día!$"

LyndoraCity_EventScript_PokemonCenterSign_Text_0:
# 137 "data/maps/LyndoraCity/scripts.pory"
	.string "Centro Pokémon\pUma pausa na jornada.\nCuidado e descanso para\lseus POKéMON.$"

LyndoraCity_EventScript_PokemonCenterSign_Text_1:
# 138 "data/maps/LyndoraCity/scripts.pory"
	.string "Pokémon Center\pA break from your journey.\nCare and rest for\lyour POKéMON.$"

LyndoraCity_EventScript_PokemonCenterSign_Text_2:
# 139 "data/maps/LyndoraCity/scripts.pory"
	.string "Centro Pokémon\pUna pausa en tu viaje.\nCuidado y descanso para\ltus POKéMON.$"

LyndoraCity_EventScript_MartSign_Text_0:
# 146 "data/maps/LyndoraCity/scripts.pory"
	.string "Loja Pokémon\pSuprimentos para explorar\nLyndora e seguir viagem.$"

LyndoraCity_EventScript_MartSign_Text_1:
# 147 "data/maps/LyndoraCity/scripts.pory"
	.string "Poké Mart\pSupplies to explore Lyndora\nand continue your journey.$"

LyndoraCity_EventScript_MartSign_Text_2:
# 148 "data/maps/LyndoraCity/scripts.pory"
	.string "Tienda Pokémon\pProvisiones para explorar\nLyndora y seguir tu viaje.$"

LyndoraCity_EventScript_FountainResident_Text_0:
# 158 "data/maps/LyndoraCity/scripts.pory"
	.string "Esta fonte é o orgulho\nda nossa cidade!\pDizem que sua água vem das\nnascentes nas montanhas.$"

LyndoraCity_EventScript_FountainResident_Text_1:
# 159 "data/maps/LyndoraCity/scripts.pory"
	.string "This fountain is the pride\nof our city!\pThey say its water comes from\nsprings in the mountains.$"

LyndoraCity_EventScript_FountainResident_Text_2:
# 160 "data/maps/LyndoraCity/scripts.pory"
	.string "¡Esta fuente es el orgullo\nde nuestra ciudad!\pDicen que su agua viene de\nmanantiales en las montañas.$"

LyndoraCity_EventScript_FountainResident_Text_3:
# 164 "data/maps/LyndoraCity/scripts.pory"
	.string "Bem-vindo a Lyndora City!\pAqui, até as ruas parecem fazer\nparte de um grande jardim!\pBonito, não acha?$"

LyndoraCity_EventScript_FountainResident_Text_4:
# 165 "data/maps/LyndoraCity/scripts.pory"
	.string "Welcome to Lyndora City!\pEven the streets here feel\nlike part of one big garden!\pLovely, isn't it?$"

LyndoraCity_EventScript_FountainResident_Text_5:
# 166 "data/maps/LyndoraCity/scripts.pory"
	.string "¡Bienvenido a Lyndora City!\p¡Aquí, hasta las calles parecen\nparte de un gran jardín!\pBonito, ¿verdad?$"

LyndoraCity_EventScript_Gardener_Text_0:
# 180 "data/maps/LyndoraCity/scripts.pory"
	.string "Elowen está investigando o que\naconteceu com as flores.\pEspero que elas voltem\nao normal logo...$"

LyndoraCity_EventScript_Gardener_Text_1:
# 181 "data/maps/LyndoraCity/scripts.pory"
	.string "Elowen is looking into what\nhappened to the flowers.\pI hope they return\nto normal soon...$"

LyndoraCity_EventScript_Gardener_Text_2:
# 182 "data/maps/LyndoraCity/scripts.pory"
	.string "Elowen está investigando qué\nles pasó a las flores.\pEspero que pronto vuelvan\na la normalidad...$"

LyndoraCity_EventScript_Gardener_Text_3:
# 186 "data/maps/LyndoraCity/scripts.pory"
	.string "Cuido destas flores\nhá muitos anos.\pMas ultimamente algumas têm\nflorescido antes da época...\pQue estranho, não acha?$"

LyndoraCity_EventScript_Gardener_Text_4:
# 187 "data/maps/LyndoraCity/scripts.pory"
	.string "I've cared for these flowers\nfor many years.\pBut lately, some have been\nblooming before their season...\pStrange, isn't it?$"

LyndoraCity_EventScript_Gardener_Text_5:
# 188 "data/maps/LyndoraCity/scripts.pory"
	.string "Cuido estas flores\ndesde hace muchos años.\pPero últimamente algunas\nflorecen antes de tiempo...\pQué extraño, ¿verdad?$"

LyndoraCity_EventScript_Gardener2_Text_0:
# 199 "data/maps/LyndoraCity/scripts.pory"
	.string "Cuido com muito carinho\ndestas flores à minha frente.\pQuando olho para elas,\nsinto que estão sorrindo para mim!$"

LyndoraCity_EventScript_Gardener2_Text_1:
# 200 "data/maps/LyndoraCity/scripts.pory"
	.string "I take such good care\nof the flowers in front of me.\pWhen I look at them,\nI can feel them smiling!$"

LyndoraCity_EventScript_Gardener2_Text_2:
# 201 "data/maps/LyndoraCity/scripts.pory"
	.string "Cuido con mucho cariño\nde estas flores que tengo delante.\pCuando las miro,\n¡siento que me sonríen!$"
