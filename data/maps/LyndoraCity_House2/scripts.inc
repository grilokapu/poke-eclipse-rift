LyndoraCity_House2_MapScripts::
# 2 "data/maps/LyndoraCity_House2/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LyndoraCity_House2_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LyndoraCity_House2_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/LyndoraCity_House2/scripts.pory"
	goto_if_set FLAG_LYNDORA_HOUSE2_KECLEON_FOUND, LyndoraCity_House2_MapScripts_MAP_SCRIPT_ON_LOAD_2
# 6 "data/maps/LyndoraCity_House2/scripts.pory"
	setflag FLAG_HIDE_LYNDORA_HOUSE2_KECLEON
LyndoraCity_House2_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	end

LyndoraCity_House2_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 4 "data/maps/LyndoraCity_House2/scripts.pory"
	clearflag FLAG_HIDE_LYNDORA_HOUSE2_KECLEON
	goto LyndoraCity_House2_MapScripts_MAP_SCRIPT_ON_LOAD_1


LyndoraCity_House2_EventScript_Researcher::
# 13 "data/maps/LyndoraCity_House2/scripts.pory"
	lock
# 14 "data/maps/LyndoraCity_House2/scripts.pory"
	faceplayer
# 15 "data/maps/LyndoraCity_House2/scripts.pory"
	goto_if_unset FLAG_LYNDORA_HOUSE2_KECLEON_FOUND, LyndoraCity_House2_EventScript_Researcher_2
# 30 "data/maps/LyndoraCity_House2/scripts.pory"
	goto_if_unset FLAG_LYNDORA_HOUSE2_REWARD_RECEIVED, LyndoraCity_House2_EventScript_Researcher_5
# 55 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 56 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_Researcher_14
# 57 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_Researcher_15
# 58 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_Researcher_16
LyndoraCity_House2_EventScript_Researcher_12:
# 60 "data/maps/LyndoraCity_House2/scripts.pory"
	release
	end

LyndoraCity_House2_EventScript_Researcher_2:
# 16 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 17 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_Researcher_9
# 18 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_Researcher_10
# 19 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_Researcher_11
LyndoraCity_House2_EventScript_Researcher_7:
# 21 "data/maps/LyndoraCity_House2/scripts.pory"
	pause 30
# 22 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 23 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_Researcher_24
# 24 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_Researcher_25
# 25 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_Researcher_26
LyndoraCity_House2_EventScript_Researcher_22:
# 27 "data/maps/LyndoraCity_House2/scripts.pory"
	release
	end

LyndoraCity_House2_EventScript_Researcher_5:
# 31 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 32 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_Researcher_19
# 33 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_Researcher_20
# 34 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_Researcher_21
LyndoraCity_House2_EventScript_Researcher_17:
# 36 "data/maps/LyndoraCity_House2/scripts.pory"
	checkitemspace ITEM_WIDE_LENS, 1
# 37 "data/maps/LyndoraCity_House2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LyndoraCity_House2_EventScript_Researcher_28
# 46 "data/maps/LyndoraCity_House2/scripts.pory"
	giveitem ITEM_WIDE_LENS, 1
# 47 "data/maps/LyndoraCity_House2/scripts.pory"
	compare VAR_0x8007, FALSE
	goto_if_eq LyndoraCity_House2_EventScript_Researcher_31
# 51 "data/maps/LyndoraCity_House2/scripts.pory"
	setflag FLAG_LYNDORA_HOUSE2_REWARD_RECEIVED
# 52 "data/maps/LyndoraCity_House2/scripts.pory"
	release
	end

LyndoraCity_House2_EventScript_Researcher_9:
# 17 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_7

LyndoraCity_House2_EventScript_Researcher_10:
# 18 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_7

LyndoraCity_House2_EventScript_Researcher_11:
# 19 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_7

LyndoraCity_House2_EventScript_Researcher_14:
# 56 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_12, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_12

LyndoraCity_House2_EventScript_Researcher_15:
# 57 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_13, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_12

LyndoraCity_House2_EventScript_Researcher_16:
# 58 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_14, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_12

LyndoraCity_House2_EventScript_Researcher_19:
# 32 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_6, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_17

LyndoraCity_House2_EventScript_Researcher_20:
# 33 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_7, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_17

LyndoraCity_House2_EventScript_Researcher_21:
# 34 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_8, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_17

LyndoraCity_House2_EventScript_Researcher_24:
# 23 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_22

LyndoraCity_House2_EventScript_Researcher_25:
# 24 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_22

LyndoraCity_House2_EventScript_Researcher_26:
# 25 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_22

LyndoraCity_House2_EventScript_Researcher_28:
# 38 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 39 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_Researcher_35
# 40 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_Researcher_36
# 41 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_Researcher_37
LyndoraCity_House2_EventScript_Researcher_33:
# 43 "data/maps/LyndoraCity_House2/scripts.pory"
	release
	end

LyndoraCity_House2_EventScript_Researcher_31:
# 48 "data/maps/LyndoraCity_House2/scripts.pory"
	release
	end

LyndoraCity_House2_EventScript_Researcher_35:
# 39 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_9, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_33

LyndoraCity_House2_EventScript_Researcher_36:
# 40 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_10, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_33

LyndoraCity_House2_EventScript_Researcher_37:
# 41 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_Researcher_Text_11, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_Researcher_33


LyndoraCity_House2_EventScript_SchoolKid::
# 65 "data/maps/LyndoraCity_House2/scripts.pory"
	lock
# 66 "data/maps/LyndoraCity_House2/scripts.pory"
	faceplayer
# 67 "data/maps/LyndoraCity_House2/scripts.pory"
	goto_if_unset FLAG_LYNDORA_HOUSE2_KECLEON_FOUND, LyndoraCity_House2_EventScript_SchoolKid_2
# 81 "data/maps/LyndoraCity_House2/scripts.pory"
	goto_if_unset FLAG_TEMP_1, LyndoraCity_House2_EventScript_SchoolKid_10
# 89 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 90 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_SchoolKid_23
# 91 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_SchoolKid_24
# 92 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_SchoolKid_25
LyndoraCity_House2_EventScript_SchoolKid_1:
# 96 "data/maps/LyndoraCity_House2/scripts.pory"
	release
	end

LyndoraCity_House2_EventScript_SchoolKid_2:
# 68 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 69 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_SchoolKid_7
# 70 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_SchoolKid_8
# 71 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_SchoolKid_9
LyndoraCity_House2_EventScript_SchoolKid_5:
# 73 "data/maps/LyndoraCity_House2/scripts.pory"
	pause 30
# 74 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 75 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_SchoolKid_14
# 76 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_SchoolKid_15
# 77 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_SchoolKid_16
	goto LyndoraCity_House2_EventScript_SchoolKid_1

LyndoraCity_House2_EventScript_SchoolKid_7:
# 69 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_5

LyndoraCity_House2_EventScript_SchoolKid_8:
# 70 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_5

LyndoraCity_House2_EventScript_SchoolKid_9:
# 71 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_5

LyndoraCity_House2_EventScript_SchoolKid_10:
# 82 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 83 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_SchoolKid_19
# 84 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_SchoolKid_20
# 85 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_SchoolKid_21
LyndoraCity_House2_EventScript_SchoolKid_17:
# 87 "data/maps/LyndoraCity_House2/scripts.pory"
	setflag FLAG_TEMP_1
	goto LyndoraCity_House2_EventScript_SchoolKid_1

LyndoraCity_House2_EventScript_SchoolKid_14:
# 75 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_1

LyndoraCity_House2_EventScript_SchoolKid_15:
# 76 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_1

LyndoraCity_House2_EventScript_SchoolKid_16:
# 77 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_1

LyndoraCity_House2_EventScript_SchoolKid_19:
# 83 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_6, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_17

LyndoraCity_House2_EventScript_SchoolKid_20:
# 84 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_7, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_17

LyndoraCity_House2_EventScript_SchoolKid_21:
# 85 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_8, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_17

LyndoraCity_House2_EventScript_SchoolKid_23:
# 90 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_9, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_1

LyndoraCity_House2_EventScript_SchoolKid_24:
# 91 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_10, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_1

LyndoraCity_House2_EventScript_SchoolKid_25:
# 92 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_SchoolKid_Text_11, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_SchoolKid_1


LyndoraCity_House2_EventScript_HiddenKecleon::
# 101 "data/maps/LyndoraCity_House2/scripts.pory"
	lockall
# 102 "data/maps/LyndoraCity_House2/scripts.pory"
	goto_if_set FLAG_LYNDORA_HOUSE2_KECLEON_FOUND, LyndoraCity_House2_EventScript_HiddenKecleon_2
# 111 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 112 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_HiddenKecleon_6
# 113 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_HiddenKecleon_7
# 114 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_HiddenKecleon_8
LyndoraCity_House2_EventScript_HiddenKecleon_4:
# 116 "data/maps/LyndoraCity_House2/scripts.pory"
	pause 30
# 117 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 118 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_HiddenKecleon_16
# 119 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_HiddenKecleon_17
# 120 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_HiddenKecleon_18
LyndoraCity_House2_EventScript_HiddenKecleon_14:
# 122 "data/maps/LyndoraCity_House2/scripts.pory"
	setflag FLAG_LYNDORA_HOUSE2_KECLEON_FOUND
# 123 "data/maps/LyndoraCity_House2/scripts.pory"
	clearflag FLAG_HIDE_LYNDORA_HOUSE2_KECLEON
# 124 "data/maps/LyndoraCity_House2/scripts.pory"
	addobject LOCALID_LYNDORA_HOUSE2_KECLEON
# 125 "data/maps/LyndoraCity_House2/scripts.pory"
	playse SE_PIN
# 126 "data/maps/LyndoraCity_House2/scripts.pory"
	movenpc LOCALID_LYNDORA_HOUSE2_KECLEON, LyndoraCity_House2_EventScript_HiddenKecleon_Movement_0
# 127 "data/maps/LyndoraCity_House2/scripts.pory"
	waitse
# 128 "data/maps/LyndoraCity_House2/scripts.pory"
	showmonmugshot SPECIES_KECLEON, MUGSHOT_SOUTHEAST
# 129 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_9, MSGBOX_DEFAULT
# 130 "data/maps/LyndoraCity_House2/scripts.pory"
	waitmoncry
# 131 "data/maps/LyndoraCity_House2/scripts.pory"
	hidemonmugshot
# 132 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 133 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_HiddenKecleon_21
# 134 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_HiddenKecleon_22
# 135 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_HiddenKecleon_23
LyndoraCity_House2_EventScript_HiddenKecleon_19:
# 137 "data/maps/LyndoraCity_House2/scripts.pory"
	releaseall
	end

LyndoraCity_House2_EventScript_HiddenKecleon_2:
# 103 "data/maps/LyndoraCity_House2/scripts.pory"
	switch VAR_LANGUAGE
# 104 "data/maps/LyndoraCity_House2/scripts.pory"
	case PT, LyndoraCity_House2_EventScript_HiddenKecleon_11
# 105 "data/maps/LyndoraCity_House2/scripts.pory"
	case EN, LyndoraCity_House2_EventScript_HiddenKecleon_12
# 106 "data/maps/LyndoraCity_House2/scripts.pory"
	case ES, LyndoraCity_House2_EventScript_HiddenKecleon_13
LyndoraCity_House2_EventScript_HiddenKecleon_9:
# 108 "data/maps/LyndoraCity_House2/scripts.pory"
	releaseall
	end

LyndoraCity_House2_EventScript_HiddenKecleon_6:
# 112 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_4

LyndoraCity_House2_EventScript_HiddenKecleon_7:
# 113 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_4

LyndoraCity_House2_EventScript_HiddenKecleon_8:
# 114 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_4

LyndoraCity_House2_EventScript_HiddenKecleon_11:
# 104 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_9

LyndoraCity_House2_EventScript_HiddenKecleon_12:
# 105 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_9

LyndoraCity_House2_EventScript_HiddenKecleon_13:
# 106 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_9

LyndoraCity_House2_EventScript_HiddenKecleon_16:
# 118 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_6, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_14

LyndoraCity_House2_EventScript_HiddenKecleon_17:
# 119 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_7, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_14

LyndoraCity_House2_EventScript_HiddenKecleon_18:
# 120 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_8, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_14

LyndoraCity_House2_EventScript_HiddenKecleon_21:
# 133 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_10, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_19

LyndoraCity_House2_EventScript_HiddenKecleon_22:
# 134 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_11, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_19

LyndoraCity_House2_EventScript_HiddenKecleon_23:
# 135 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_12, MSGBOX_DEFAULT
	goto LyndoraCity_House2_EventScript_HiddenKecleon_19


LyndoraCity_House2_EventScript_Kecleon::
# 142 "data/maps/LyndoraCity_House2/scripts.pory"
	lock
# 143 "data/maps/LyndoraCity_House2/scripts.pory"
	faceplayer
# 144 "data/maps/LyndoraCity_House2/scripts.pory"
	showmonmugshot SPECIES_KECLEON, MUGSHOT_SOUTHEAST
# 145 "data/maps/LyndoraCity_House2/scripts.pory"
	msgbox LyndoraCity_House2_EventScript_HiddenKecleon_Text_9, MSGBOX_DEFAULT
# 146 "data/maps/LyndoraCity_House2/scripts.pory"
	waitmoncry
# 147 "data/maps/LyndoraCity_House2/scripts.pory"
	hidemonmugshot
# 148 "data/maps/LyndoraCity_House2/scripts.pory"
	release
	end


# 126 "data/maps/LyndoraCity_House2/scripts.pory"
LyndoraCity_House2_EventScript_HiddenKecleon_Movement_0:
# 126 "data/maps/LyndoraCity_House2/scripts.pory"
	emote_exclamation_mark
	step_end

LyndoraCity_House2_EventScript_Researcher_Text_0:
# 17 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Estou estudando como alguns\nPokémon conseguem se camuflar.\pMeu KECLEON é especialmente\ntalentoso nisso!$"

LyndoraCity_House2_EventScript_Researcher_Text_1:
# 18 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "I study how some Pokémon\ncamouflage themselves.\pMy KECLEON is especially\ngood at it!$"

LyndoraCity_House2_EventScript_Researcher_Text_2:
# 19 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Estudio cómo algunos Pokémon\nconsiguen camuflarse.\p¡Mi KECLEON tiene\nun talento especial!$"

LyndoraCity_House2_EventScript_Researcher_Text_3:
# 23 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Na verdade...\pEle estava aqui\nhá alguns minutos.\pMas agora não consigo\nencontrá-lo!$"

LyndoraCity_House2_EventScript_Researcher_Text_4:
# 24 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Actually...\pIt was here\na few minutes ago.\pBut now I can't\nfind it!$"

LyndoraCity_House2_EventScript_Researcher_Text_5:
# 25 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "En realidad...\pEstaba aquí\nhace unos minutos.\p¡Pero ahora no consigo\nencontrarlo!$"

LyndoraCity_House2_EventScript_Researcher_Text_6:
# 32 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Ah! Então era ali que ele estava!\pHehe! Ele sempre encontra novos\nlugares para se esconder.\pVocê encontrou meu KECLEON!\nObrigada! Você tem bons olhos\lpara observar Pokémon.\pQuero lhe dar isto.$"

LyndoraCity_House2_EventScript_Researcher_Text_7:
# 33 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Oh! So that's where it was!\pHehe! It always finds new\nplaces to hide.\pYou found my KECLEON!\nThank you! You've got a good eye\lfor observing Pokémon.\pI'd like you to have this.$"

LyndoraCity_House2_EventScript_Researcher_Text_8:
# 34 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "¡Ah! ¡Así que estaba allí!\p¡Je, je! Siempre encuentra\nnuevos lugares para esconderse.\p¡Encontraste a mi KECLEON!\n¡Gracias! Tienes buen ojo\lpara observar Pokémon.\pQuiero darte esto.$"

LyndoraCity_House2_EventScript_Researcher_Text_9:
# 39 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Sua Bolsa está cheia?\pVou guardar o presente.\nAbra espaço e volte depois!$"

LyndoraCity_House2_EventScript_Researcher_Text_10:
# 40 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Is your Bag full?\pI'll keep your gift safe.\nMake some room and come back!$"

LyndoraCity_House2_EventScript_Researcher_Text_11:
# 41 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "¿Tu Bolsa está llena?\pTe guardaré el regalo.\n¡Haz espacio y vuelve luego!$"

LyndoraCity_House2_EventScript_Researcher_Text_12:
# 56 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "KECLEON consegue mudar a cor\ndo corpo para se camuflar.\pMas aquela faixa em sua\nbarriga continua visível!$"

LyndoraCity_House2_EventScript_Researcher_Text_13:
# 57 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "KECLEON can change its body\ncolor to blend in.\pBut that stripe on its belly\nstays visible!$"

LyndoraCity_House2_EventScript_Researcher_Text_14:
# 58 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "KECLEON puede cambiar de color\npara camuflarse.\p¡Pero la franja de su barriga\nsigue siendo visible!$"

LyndoraCity_House2_EventScript_SchoolKid_Text_0:
# 69 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Minha irmã vive dizendo que\nKECLEON é um mestre\lda camuflagem!\pMas aposto que consigo\nencontrá-lo antes dela!$"

LyndoraCity_House2_EventScript_SchoolKid_Text_1:
# 70 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "My sister keeps saying KECLEON\nis a master of camouflage!\pBut I bet I can\nfind it before she does!$"

LyndoraCity_House2_EventScript_SchoolKid_Text_2:
# 71 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "¡Mi hermana siempre dice que\nKECLEON es un maestro\ldel camuflaje!\p¡Pero apuesto a que puedo\nencontrarlo antes que ella!$"

LyndoraCity_House2_EventScript_SchoolKid_Text_3:
# 75 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Hmm...\pVocê viu alguma coisa\nse mexendo por aqui?$"

LyndoraCity_House2_EventScript_SchoolKid_Text_4:
# 76 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Hmm...\pHave you seen anything\nmoving around here?$"

LyndoraCity_House2_EventScript_SchoolKid_Text_5:
# 77 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Mmm...\p¿Has visto algo\nmoviéndose por aquí?$"

LyndoraCity_House2_EventScript_SchoolKid_Text_6:
# 83 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Ahhh! Você encontrou primeiro!\pNa próxima vez, eu ganho!$"

LyndoraCity_House2_EventScript_SchoolKid_Text_7:
# 84 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Awww! You found it first!\pNext time, I win!$"

LyndoraCity_House2_EventScript_SchoolKid_Text_8:
# 85 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "¡Ahhh! ¡Lo encontraste primero!\p¡La próxima vez gano yo!$"

LyndoraCity_House2_EventScript_SchoolKid_Text_9:
# 90 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Se eu tivesse um KECLEON,\nbrincaria de esconde-esconde\ltodos os dias!$"

LyndoraCity_House2_EventScript_SchoolKid_Text_10:
# 91 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "If I had a KECLEON,\nI'd play hide-and-seek\levery day!$"

LyndoraCity_House2_EventScript_SchoolKid_Text_11:
# 92 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "¡Si tuviera un KECLEON,\njugaría al escondite\ltodos los días!$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_0:
# 104 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Não há mais nada\nescondido atrás do vaso.$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_1:
# 105 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "There's nothing else\nhiding behind the pot.$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_2:
# 106 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Ya no hay nada\nescondido detrás de la maceta.$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_3:
# 112 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Há algo estranho\natrás deste vaso...$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_4:
# 113 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Something looks odd\nbehind this pot...$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_5:
# 114 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Hay algo extraño\ndetrás de esta maceta...$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_6:
# 118 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Parece que alguma coisa\nestá se mexendo!$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_7:
# 119 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "It looks like something\nis moving!$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_8:
# 120 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "¡Parece que algo\nse está moviendo!$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_9:
# 129 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "KECLEON: Kecleon!$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_10:
# 133 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "Um KECLEON estava\nescondido atrás do vaso!$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_11:
# 134 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "A KECLEON was\nhiding behind the pot!$"

LyndoraCity_House2_EventScript_HiddenKecleon_Text_12:
# 135 "data/maps/LyndoraCity_House2/scripts.pory"
	.string "¡Un KECLEON estaba\nescondido detrás de la maceta!$"
