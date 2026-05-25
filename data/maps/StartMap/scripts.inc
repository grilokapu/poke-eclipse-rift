StartMap_MapScripts::
# 2 "data/maps/StartMap/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, StartMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

StartMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/StartMap/scripts.pory"
	map_script_2 VAR_DW_START_STORY, 0, Story_Start_ChooseDifficulty
	.2byte 0


Story_Start_ChooseDifficulty::
# 8 "data/maps/StartMap/scripts.pory"
	compare VAR_LANGUAGE, PORTUGUESE_LANGUAGE
	goto_if_eq Story_Start_ChooseDifficulty_2
# 11 "data/maps/StartMap/scripts.pory"
	compare VAR_LANGUAGE, ENGLISH_LANGUAGE
	goto_if_eq Story_Start_ChooseDifficulty_3
# 14 "data/maps/StartMap/scripts.pory"
	compare VAR_LANGUAGE, SPANISH_LANGUAGE
	goto_if_eq Story_Start_ChooseDifficulty_4
Story_Start_ChooseDifficulty_1:
# 17 "data/maps/StartMap/scripts.pory"
	waitmessage
# 18 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 19 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_ChooseDifficulty_10
# 20 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_ChooseDifficulty_10
# 21 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_ChooseDifficulty_11
Story_Start_ChooseDifficulty_8:
# 23 "data/maps/StartMap/scripts.pory"
	switch VAR_RESULT
# 24 "data/maps/StartMap/scripts.pory"
	case 0, Story_Start_ChooseDifficulty_13
# 25 "data/maps/StartMap/scripts.pory"
	case 1, Story_Start_ChooseDifficulty_14
# 26 "data/maps/StartMap/scripts.pory"
	case 2, Story_Start_ChooseDifficulty_15
# 27 "data/maps/StartMap/scripts.pory"
	case 3, Story_Start_ChooseDifficulty_16
	return

Story_Start_ChooseDifficulty_2:
# 9 "data/maps/StartMap/scripts.pory"
	message Story_Start_ChooseDifficulty_Text_0
	goto Story_Start_ChooseDifficulty_1

Story_Start_ChooseDifficulty_3:
# 12 "data/maps/StartMap/scripts.pory"
	message Story_Start_ChooseDifficulty_Text_1
	goto Story_Start_ChooseDifficulty_1

Story_Start_ChooseDifficulty_4:
# 15 "data/maps/StartMap/scripts.pory"
	message Story_Start_ChooseDifficulty_Text_2
	goto Story_Start_ChooseDifficulty_1

Story_Start_ChooseDifficulty_10:
# 20 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_ChooseDifficulty_Text_3, Story_Start_ChooseDifficulty_Text_4, Story_Start_ChooseDifficulty_Text_5, Story_Start_ChooseDifficulty_Text_6
	goto Story_Start_ChooseDifficulty_8

Story_Start_ChooseDifficulty_11:
# 21 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_ChooseDifficulty_Text_7, Story_Start_ChooseDifficulty_Text_4, Story_Start_ChooseDifficulty_Text_8, Story_Start_ChooseDifficulty_Text_9
	goto Story_Start_ChooseDifficulty_8

Story_Start_ChooseDifficulty_13:
# 24 "data/maps/StartMap/scripts.pory"
	goto Story_Start_EasyMode_Choosed
	return

Story_Start_ChooseDifficulty_14:
# 25 "data/maps/StartMap/scripts.pory"
	goto Story_Start_NormalMode_Choosed
	return

Story_Start_ChooseDifficulty_15:
# 26 "data/maps/StartMap/scripts.pory"
	goto Story_Start_HardMode_Choosed
	return

Story_Start_ChooseDifficulty_16:
# 27 "data/maps/StartMap/scripts.pory"
	goto Story_Start_LunaticMode_Choosed
	return


Story_Start_WantToChooseDifficulty::
# 45 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 46 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_WantToChooseDifficulty_3
# 51 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_WantToChooseDifficulty_4
# 55 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_WantToChooseDifficulty_5
Story_Start_WantToChooseDifficulty_1:
	return

Story_Start_WantToChooseDifficulty_3:
# 47 "data/maps/StartMap/scripts.pory"
	message Text_WantToChooseDifficultyPt
# 48 "data/maps/StartMap/scripts.pory"
	waitmessage
# 49 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_WantToChooseDifficulty_Text_0, Story_Start_WantToChooseDifficulty_Text_1, Story_Start_WantToChooseDifficulty_Text_2
	goto Story_Start_WantToChooseDifficulty_1

Story_Start_WantToChooseDifficulty_4:
# 52 "data/maps/StartMap/scripts.pory"
	message Text_WantToChooseDifficultyEn
# 53 "data/maps/StartMap/scripts.pory"
	waitmessage
# 54 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_WantToChooseDifficulty_Text_3, Story_Start_WantToChooseDifficulty_Text_4, Story_Start_WantToChooseDifficulty_Text_2
	goto Story_Start_WantToChooseDifficulty_1

Story_Start_WantToChooseDifficulty_5:
# 56 "data/maps/StartMap/scripts.pory"
	message Text_WantToChooseDifficultyEs
# 57 "data/maps/StartMap/scripts.pory"
	waitmessage
# 58 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_WantToChooseDifficulty_Text_5, Story_Start_WantToChooseDifficulty_Text_4, Story_Start_WantToChooseDifficulty_Text_2
	goto Story_Start_WantToChooseDifficulty_1


Story_Start_EasyMode_Choosed::
# 64 "data/maps/StartMap/scripts.pory"
	call Story_Start_WantToChooseDifficulty
# 65 "data/maps/StartMap/scripts.pory"
	closemessage
# 66 "data/maps/StartMap/scripts.pory"
	switch VAR_RESULT
# 67 "data/maps/StartMap/scripts.pory"
	case 0, Story_Start_EasyMode_Choosed_3
# 73 "data/maps/StartMap/scripts.pory"
	case 1, Story_Start_EasyMode_Choosed_4
# 74 "data/maps/StartMap/scripts.pory"
	case 2, Story_Start_EasyMode_Choosed_5
Story_Start_EasyMode_Choosed_1:
# 78 "data/maps/StartMap/scripts.pory"
	setvar VAR_DIFFICULTY, 0
# 79 "data/maps/StartMap/scripts.pory"
	setvar VAR_DIFFICULTY, DIFFICULTY_EASY
# 80 "data/maps/StartMap/scripts.pory"
	goto Story_Start_ChooseLevelCap
	return

Story_Start_EasyMode_Choosed_3:
# 68 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 69 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_EasyMode_Choosed_7
# 70 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_EasyMode_Choosed_8
# 71 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_EasyMode_Choosed_9
	goto Story_Start_EasyMode_Choosed_1

Story_Start_EasyMode_Choosed_4:
# 73 "data/maps/StartMap/scripts.pory"
	goto Story_Start_ChooseDifficulty
	goto Story_Start_EasyMode_Choosed_1

Story_Start_EasyMode_Choosed_5:
# 75 "data/maps/StartMap/scripts.pory"
	helpwindow HELP_EASY_MODE
# 76 "data/maps/StartMap/scripts.pory"
	goto Story_Start_EasyMode_Choosed
	goto Story_Start_EasyMode_Choosed_1

Story_Start_EasyMode_Choosed_7:
# 69 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_EasyMode_Choosed_Text_0
	goto Story_Start_EasyMode_Choosed_1

Story_Start_EasyMode_Choosed_8:
# 70 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_EasyMode_Choosed_Text_1
	goto Story_Start_EasyMode_Choosed_1

Story_Start_EasyMode_Choosed_9:
# 71 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_EasyMode_Choosed_Text_2
	goto Story_Start_EasyMode_Choosed_1


Story_Start_NormalMode_Choosed::
# 84 "data/maps/StartMap/scripts.pory"
	call Story_Start_WantToChooseDifficulty
# 85 "data/maps/StartMap/scripts.pory"
	closemessage
# 86 "data/maps/StartMap/scripts.pory"
	switch VAR_RESULT
# 87 "data/maps/StartMap/scripts.pory"
	case 0, Story_Start_NormalMode_Choosed_3
# 93 "data/maps/StartMap/scripts.pory"
	case 1, Story_Start_NormalMode_Choosed_4
# 94 "data/maps/StartMap/scripts.pory"
	case 2, Story_Start_NormalMode_Choosed_5
Story_Start_NormalMode_Choosed_1:
# 99 "data/maps/StartMap/scripts.pory"
	setvar VAR_DIFFICULTY, 0
# 100 "data/maps/StartMap/scripts.pory"
	setvar VAR_DIFFICULTY, DIFFICULTY_NORMAL
# 101 "data/maps/StartMap/scripts.pory"
	goto Story_Start_NormalMode_Choosed
	return

Story_Start_NormalMode_Choosed_3:
# 88 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 89 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_NormalMode_Choosed_7
# 90 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_NormalMode_Choosed_8
# 91 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_NormalMode_Choosed_9
	goto Story_Start_NormalMode_Choosed_1

Story_Start_NormalMode_Choosed_4:
# 93 "data/maps/StartMap/scripts.pory"
	goto Story_Start_ChooseDifficulty
	goto Story_Start_NormalMode_Choosed_1

Story_Start_NormalMode_Choosed_5:
# 95 "data/maps/StartMap/scripts.pory"
	closemessage
# 96 "data/maps/StartMap/scripts.pory"
	helpwindow HELP_NORMAL_MODE
# 97 "data/maps/StartMap/scripts.pory"
	goto Story_Start_EasyMode_Choosed
	goto Story_Start_NormalMode_Choosed_1

Story_Start_NormalMode_Choosed_7:
# 89 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_NormalMode_Choosed_Text_0
	goto Story_Start_NormalMode_Choosed_1

Story_Start_NormalMode_Choosed_8:
# 90 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_NormalMode_Choosed_Text_1
	goto Story_Start_NormalMode_Choosed_1

Story_Start_NormalMode_Choosed_9:
# 91 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_NormalMode_Choosed_Text_2
	goto Story_Start_NormalMode_Choosed_1


Story_Start_HardMode_Choosed::
# 105 "data/maps/StartMap/scripts.pory"
	call Story_Start_WantToChooseDifficulty
# 106 "data/maps/StartMap/scripts.pory"
	closemessage
# 107 "data/maps/StartMap/scripts.pory"
	switch VAR_RESULT
# 108 "data/maps/StartMap/scripts.pory"
	case 0, Story_Start_HardMode_Choosed_3
# 114 "data/maps/StartMap/scripts.pory"
	case 1, Story_Start_HardMode_Choosed_4
# 115 "data/maps/StartMap/scripts.pory"
	case 2, Story_Start_HardMode_Choosed_5
Story_Start_HardMode_Choosed_1:
# 120 "data/maps/StartMap/scripts.pory"
	setvar VAR_DIFFICULTY, 0
# 121 "data/maps/StartMap/scripts.pory"
	setvar VAR_DIFFICULTY, DIFFICULTY_HARD
# 122 "data/maps/StartMap/scripts.pory"
	setflag FLAG_LEVEL_CAP_ENABLED
# 123 "data/maps/StartMap/scripts.pory"
	goto Story_Start_MinimalGrinding
	return

Story_Start_HardMode_Choosed_3:
# 109 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 110 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_HardMode_Choosed_7
# 111 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_HardMode_Choosed_8
# 112 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_HardMode_Choosed_9
	goto Story_Start_HardMode_Choosed_1

Story_Start_HardMode_Choosed_4:
# 114 "data/maps/StartMap/scripts.pory"
	goto Story_Start_ChooseDifficulty
	goto Story_Start_HardMode_Choosed_1

Story_Start_HardMode_Choosed_5:
# 116 "data/maps/StartMap/scripts.pory"
	closemessage
# 117 "data/maps/StartMap/scripts.pory"
	helpwindow HELP_HARD_MODE
# 118 "data/maps/StartMap/scripts.pory"
	goto Story_Start_HardMode_Choosed
	goto Story_Start_HardMode_Choosed_1

Story_Start_HardMode_Choosed_7:
# 110 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_HardMode_Choosed_Text_0
	goto Story_Start_HardMode_Choosed_1

Story_Start_HardMode_Choosed_8:
# 111 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_HardMode_Choosed_Text_1
	goto Story_Start_HardMode_Choosed_1

Story_Start_HardMode_Choosed_9:
# 112 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_HardMode_Choosed_Text_2
	goto Story_Start_HardMode_Choosed_1


Story_Start_ChooseLevelCap::
# 127 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 128 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_ChooseLevelCap_3
# 132 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_ChooseLevelCap_4
# 136 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_ChooseLevelCap_5
Story_Start_ChooseLevelCap_1:
# 141 "data/maps/StartMap/scripts.pory"
	switch VAR_RESULT
# 142 "data/maps/StartMap/scripts.pory"
	case 0, Story_Start_ChooseLevelCap_8
# 149 "data/maps/StartMap/scripts.pory"
	case 1, Story_Start_ChooseLevelCap_9
# 155 "data/maps/StartMap/scripts.pory"
	case 2, Story_Start_ChooseLevelCap_10
Story_Start_ChooseLevelCap_6:
# 160 "data/maps/StartMap/scripts.pory"
	goto Story_Start_MinimalGrinding
	return

Story_Start_ChooseLevelCap_3:
# 129 "data/maps/StartMap/scripts.pory"
	message Story_Start_ChooseLevelCap_Text_0
# 130 "data/maps/StartMap/scripts.pory"
	waitmessage
# 131 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_WantToChooseDifficulty_Text_0, Story_Start_WantToChooseDifficulty_Text_1, Story_Start_WantToChooseDifficulty_Text_2
	goto Story_Start_ChooseLevelCap_1

Story_Start_ChooseLevelCap_4:
# 133 "data/maps/StartMap/scripts.pory"
	message Story_Start_ChooseLevelCap_Text_1
# 134 "data/maps/StartMap/scripts.pory"
	waitmessage
# 135 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_WantToChooseDifficulty_Text_3, Story_Start_WantToChooseDifficulty_Text_4, Story_Start_WantToChooseDifficulty_Text_2
	goto Story_Start_ChooseLevelCap_1

Story_Start_ChooseLevelCap_5:
# 137 "data/maps/StartMap/scripts.pory"
	message Story_Start_ChooseLevelCap_Text_2
# 138 "data/maps/StartMap/scripts.pory"
	waitmessage
# 139 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_WantToChooseDifficulty_Text_5, Story_Start_WantToChooseDifficulty_Text_4, Story_Start_WantToChooseDifficulty_Text_2
	goto Story_Start_ChooseLevelCap_1

Story_Start_ChooseLevelCap_8:
# 143 "data/maps/StartMap/scripts.pory"
	setflag FLAG_LEVEL_CAP_ENABLED
# 144 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 145 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_ChooseLevelCap_12
# 146 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_ChooseLevelCap_13
# 147 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_ChooseLevelCap_14
	goto Story_Start_ChooseLevelCap_6

Story_Start_ChooseLevelCap_9:
# 150 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 151 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_ChooseLevelCap_16
# 152 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_ChooseLevelCap_17
# 153 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_ChooseLevelCap_18
	goto Story_Start_ChooseLevelCap_6

Story_Start_ChooseLevelCap_10:
# 156 "data/maps/StartMap/scripts.pory"
	closemessage
# 157 "data/maps/StartMap/scripts.pory"
	helpwindow HELP_LEVEL_CAP
# 158 "data/maps/StartMap/scripts.pory"
	goto Story_Start_ChooseLevelCap
	goto Story_Start_ChooseLevelCap_6

Story_Start_ChooseLevelCap_12:
# 145 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_ChooseLevelCap_Text_3
	goto Story_Start_ChooseLevelCap_6

Story_Start_ChooseLevelCap_13:
# 146 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_ChooseLevelCap_Text_4
	goto Story_Start_ChooseLevelCap_6

Story_Start_ChooseLevelCap_14:
# 147 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_ChooseLevelCap_Text_5
	goto Story_Start_ChooseLevelCap_6

Story_Start_ChooseLevelCap_16:
# 151 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_ChooseLevelCap_Text_6
	goto Story_Start_ChooseLevelCap_6

Story_Start_ChooseLevelCap_17:
# 152 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_ChooseLevelCap_Text_7
	goto Story_Start_ChooseLevelCap_6

Story_Start_ChooseLevelCap_18:
# 153 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_ChooseLevelCap_Text_8
	goto Story_Start_ChooseLevelCap_6


Story_Start_MinimalGrinding::
# 164 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 165 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_MinimalGrinding_3
# 169 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_MinimalGrinding_4
# 173 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_MinimalGrinding_5
Story_Start_MinimalGrinding_1:
# 178 "data/maps/StartMap/scripts.pory"
	switch VAR_RESULT
# 179 "data/maps/StartMap/scripts.pory"
	case 0, Story_Start_MinimalGrinding_8
# 186 "data/maps/StartMap/scripts.pory"
	case 1, Story_Start_MinimalGrinding_9
# 192 "data/maps/StartMap/scripts.pory"
	case 2, Story_Start_MinimalGrinding_10
Story_Start_MinimalGrinding_6:
# 197 "data/maps/StartMap/scripts.pory"
	goto Story_Start_WarpToHouse
	return

Story_Start_MinimalGrinding_3:
# 166 "data/maps/StartMap/scripts.pory"
	message Story_Start_MinimalGrinding_Text_0
# 167 "data/maps/StartMap/scripts.pory"
	waitmessage
# 168 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_WantToChooseDifficulty_Text_0, Story_Start_WantToChooseDifficulty_Text_1, Story_Start_WantToChooseDifficulty_Text_2
	goto Story_Start_MinimalGrinding_1

Story_Start_MinimalGrinding_4:
# 170 "data/maps/StartMap/scripts.pory"
	message Story_Start_MinimalGrinding_Text_1
# 171 "data/maps/StartMap/scripts.pory"
	waitmessage
# 172 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_WantToChooseDifficulty_Text_3, Story_Start_WantToChooseDifficulty_Text_4, Story_Start_WantToChooseDifficulty_Text_2
	goto Story_Start_MinimalGrinding_1

Story_Start_MinimalGrinding_5:
# 174 "data/maps/StartMap/scripts.pory"
	message Story_Start_MinimalGrinding_Text_2
# 175 "data/maps/StartMap/scripts.pory"
	waitmessage
# 176 "data/maps/StartMap/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Story_Start_WantToChooseDifficulty_Text_5, Story_Start_WantToChooseDifficulty_Text_4, Story_Start_WantToChooseDifficulty_Text_2
	goto Story_Start_MinimalGrinding_1

Story_Start_MinimalGrinding_8:
# 180 "data/maps/StartMap/scripts.pory"
	setflag FLAG_MINIMALGRIND_ENABLED
# 181 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 182 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_MinimalGrinding_12
# 183 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_MinimalGrinding_13
# 184 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_MinimalGrinding_14
	goto Story_Start_MinimalGrinding_6

Story_Start_MinimalGrinding_9:
# 187 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 188 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_MinimalGrinding_16
# 189 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_MinimalGrinding_17
# 190 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_MinimalGrinding_18
	goto Story_Start_MinimalGrinding_6

Story_Start_MinimalGrinding_10:
# 193 "data/maps/StartMap/scripts.pory"
	closemessage
# 194 "data/maps/StartMap/scripts.pory"
	helpwindow HELP_MINIMAL_GRIND_MODE
# 195 "data/maps/StartMap/scripts.pory"
	goto Story_Start_MinimalGrinding
	goto Story_Start_MinimalGrinding_6

Story_Start_MinimalGrinding_12:
# 182 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_MinimalGrinding_Text_3
	goto Story_Start_MinimalGrinding_6

Story_Start_MinimalGrinding_13:
# 183 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_MinimalGrinding_Text_4
	goto Story_Start_MinimalGrinding_6

Story_Start_MinimalGrinding_14:
# 184 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_MinimalGrinding_Text_5
	goto Story_Start_MinimalGrinding_6

Story_Start_MinimalGrinding_16:
# 188 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_MinimalGrinding_Text_6
	goto Story_Start_MinimalGrinding_6

Story_Start_MinimalGrinding_17:
# 189 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_MinimalGrinding_Text_7
	goto Story_Start_MinimalGrinding_6

Story_Start_MinimalGrinding_18:
# 190 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_MinimalGrinding_Text_8
	goto Story_Start_MinimalGrinding_6


Story_Start_WarpToHouse::
# 201 "data/maps/StartMap/scripts.pory"
	setvar VAR_DW_START_STORY, 1
# 202 "data/maps/StartMap/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 7, 6
# 203 "data/maps/StartMap/scripts.pory"
	waitstate
	return


Story_Start_LunaticMode_Choosed::
# 207 "data/maps/StartMap/scripts.pory"
	call Story_Start_WantToChooseDifficulty
# 208 "data/maps/StartMap/scripts.pory"
	closemessage
# 209 "data/maps/StartMap/scripts.pory"
	switch VAR_RESULT
# 210 "data/maps/StartMap/scripts.pory"
	case 0, Story_Start_LunaticMode_Choosed_3
# 216 "data/maps/StartMap/scripts.pory"
	case 1, Story_Start_LunaticMode_Choosed_4
# 217 "data/maps/StartMap/scripts.pory"
	case 2, Story_Start_LunaticMode_Choosed_5
Story_Start_LunaticMode_Choosed_1:
# 222 "data/maps/StartMap/scripts.pory"
	setvar VAR_DIFFICULTY, 0
# 223 "data/maps/StartMap/scripts.pory"
	setvar VAR_DIFFICULTY, DIFFICULTY_LUNATIC
# 224 "data/maps/StartMap/scripts.pory"
	setflag FLAG_LEVEL_CAP_ENABLED
# 225 "data/maps/StartMap/scripts.pory"
	setflag FLAG_MINIMALGRIND_ENABLED
# 226 "data/maps/StartMap/scripts.pory"
	goto Story_Start_WarpToHouse
	return

Story_Start_LunaticMode_Choosed_3:
# 211 "data/maps/StartMap/scripts.pory"
	switch VAR_LANGUAGE
# 212 "data/maps/StartMap/scripts.pory"
	case PORTUGUESE_LANGUAGE, Story_Start_LunaticMode_Choosed_7
# 213 "data/maps/StartMap/scripts.pory"
	case ENGLISH_LANGUAGE, Story_Start_LunaticMode_Choosed_8
# 214 "data/maps/StartMap/scripts.pory"
	case SPANISH_LANGUAGE, Story_Start_LunaticMode_Choosed_9
	goto Story_Start_LunaticMode_Choosed_1

Story_Start_LunaticMode_Choosed_4:
# 216 "data/maps/StartMap/scripts.pory"
	goto Story_Start_ChooseDifficulty
	goto Story_Start_LunaticMode_Choosed_1

Story_Start_LunaticMode_Choosed_5:
# 218 "data/maps/StartMap/scripts.pory"
	closemessage
# 219 "data/maps/StartMap/scripts.pory"
	helpwindow HELP_LUNATIC_MODE
# 220 "data/maps/StartMap/scripts.pory"
	goto Story_Start_LunaticMode_Choosed
	goto Story_Start_LunaticMode_Choosed_1

Story_Start_LunaticMode_Choosed_7:
# 212 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_LunaticMode_Choosed_Text_0
	goto Story_Start_LunaticMode_Choosed_1

Story_Start_LunaticMode_Choosed_8:
# 213 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_LunaticMode_Choosed_Text_1
	goto Story_Start_LunaticMode_Choosed_1

Story_Start_LunaticMode_Choosed_9:
# 214 "data/maps/StartMap/scripts.pory"
	msgbox Story_Start_LunaticMode_Choosed_Text_2
	goto Story_Start_LunaticMode_Choosed_1


Story_Start_ChooseDifficulty_Text_0:
# 9 "data/maps/StartMap/scripts.pory"
	.string "Escolha o nível de dificuldade\npara a sua aventura.$"

Story_Start_ChooseDifficulty_Text_1:
# 12 "data/maps/StartMap/scripts.pory"
	.string "Choose the difficulty level for\nyour adventure.$"

Story_Start_ChooseDifficulty_Text_2:
# 15 "data/maps/StartMap/scripts.pory"
	.string "Elige el nivel de dificultad para\ntu aventura.$"

Story_Start_ChooseDifficulty_Text_3:
# 20 "data/maps/StartMap/scripts.pory"
	.string "FÁCIL$"

Story_Start_ChooseDifficulty_Text_4:
# 20 "data/maps/StartMap/scripts.pory"
	.string "NORMAL$"

Story_Start_ChooseDifficulty_Text_5:
# 20 "data/maps/StartMap/scripts.pory"
	.string "DIFÍCIL$"

Story_Start_ChooseDifficulty_Text_6:
# 20 "data/maps/StartMap/scripts.pory"
	.string "LUNÁTICO$"

Story_Start_ChooseDifficulty_Text_7:
# 21 "data/maps/StartMap/scripts.pory"
	.string "EASY$"

Story_Start_ChooseDifficulty_Text_8:
# 21 "data/maps/StartMap/scripts.pory"
	.string "HARD$"

Story_Start_ChooseDifficulty_Text_9:
# 21 "data/maps/StartMap/scripts.pory"
	.string "LUNATIC$"

Story_Start_WantToChooseDifficulty_Text_0:
# 49 "data/maps/StartMap/scripts.pory"
	.string "SIM$"

Story_Start_WantToChooseDifficulty_Text_1:
# 49 "data/maps/StartMap/scripts.pory"
	.string "NÃO$"

Story_Start_WantToChooseDifficulty_Text_2:
# 49 "data/maps/StartMap/scripts.pory"
	.string "INFO$"

Story_Start_WantToChooseDifficulty_Text_3:
# 54 "data/maps/StartMap/scripts.pory"
	.string "YES$"

Story_Start_WantToChooseDifficulty_Text_4:
# 54 "data/maps/StartMap/scripts.pory"
	.string "NO$"

Story_Start_WantToChooseDifficulty_Text_5:
# 58 "data/maps/StartMap/scripts.pory"
	.string "SI$"

Story_Start_EasyMode_Choosed_Text_0:
# 69 "data/maps/StartMap/scripts.pory"
	.string "Modo fácil escolhido!$"

Story_Start_EasyMode_Choosed_Text_1:
# 70 "data/maps/StartMap/scripts.pory"
	.string "Easy mode chosen!$"

Story_Start_EasyMode_Choosed_Text_2:
# 71 "data/maps/StartMap/scripts.pory"
	.string "Modo fácil elegido!$"

Story_Start_NormalMode_Choosed_Text_0:
# 89 "data/maps/StartMap/scripts.pory"
	.string "Modo Normal escolhido!$"

Story_Start_NormalMode_Choosed_Text_1:
# 90 "data/maps/StartMap/scripts.pory"
	.string "Normal Mode chosen!$"

Story_Start_NormalMode_Choosed_Text_2:
# 91 "data/maps/StartMap/scripts.pory"
	.string "Modo Normal elegido!$"

Story_Start_HardMode_Choosed_Text_0:
# 110 "data/maps/StartMap/scripts.pory"
	.string "Modo Difícil escolhido!$"

Story_Start_HardMode_Choosed_Text_1:
# 111 "data/maps/StartMap/scripts.pory"
	.string "Hard Mode chosen!$"

Story_Start_HardMode_Choosed_Text_2:
# 112 "data/maps/StartMap/scripts.pory"
	.string "Modo Difícil elegido!$"

Story_Start_ChooseLevelCap_Text_0:
# 129 "data/maps/StartMap/scripts.pory"
	.string "Deseja ativar o Level Cap?$"

Story_Start_ChooseLevelCap_Text_1:
# 133 "data/maps/StartMap/scripts.pory"
	.string "Do you want to activate the\nLevel Cap?$"

Story_Start_ChooseLevelCap_Text_2:
# 137 "data/maps/StartMap/scripts.pory"
	.string "¿Quieres activar el Level Cap?$"

Story_Start_ChooseLevelCap_Text_3:
# 145 "data/maps/StartMap/scripts.pory"
	.string "Level Cap ativado!$"

Story_Start_ChooseLevelCap_Text_4:
# 146 "data/maps/StartMap/scripts.pory"
	.string "Level Cap enabled!$"

Story_Start_ChooseLevelCap_Text_5:
# 147 "data/maps/StartMap/scripts.pory"
	.string "Level Cap activado!$"

Story_Start_ChooseLevelCap_Text_6:
# 151 "data/maps/StartMap/scripts.pory"
	.string "Level Cap desativado!$"

Story_Start_ChooseLevelCap_Text_7:
# 152 "data/maps/StartMap/scripts.pory"
	.string "Level Cap disabled!$"

Story_Start_ChooseLevelCap_Text_8:
# 153 "data/maps/StartMap/scripts.pory"
	.string "Level Cap desactivado!$"

Story_Start_MinimalGrinding_Text_0:
# 166 "data/maps/StartMap/scripts.pory"
	.string "Deseja ativar o Modo Minimal\nGrind?$"

Story_Start_MinimalGrinding_Text_1:
# 170 "data/maps/StartMap/scripts.pory"
	.string "Do you want to activate Minimal\nGrind Mode?$"

Story_Start_MinimalGrinding_Text_2:
# 174 "data/maps/StartMap/scripts.pory"
	.string "¿Quieres activar el Modo Minimal\nGrind?$"

Story_Start_MinimalGrinding_Text_3:
# 182 "data/maps/StartMap/scripts.pory"
	.string "Modo Minimal Grind ativado!$"

Story_Start_MinimalGrinding_Text_4:
# 183 "data/maps/StartMap/scripts.pory"
	.string "Minimal Grind Mode enabled!$"

Story_Start_MinimalGrinding_Text_5:
# 184 "data/maps/StartMap/scripts.pory"
	.string "Modo Minimal Grind activado!$"

Story_Start_MinimalGrinding_Text_6:
# 188 "data/maps/StartMap/scripts.pory"
	.string "Modo Minimal Grind desativado!$"

Story_Start_MinimalGrinding_Text_7:
# 189 "data/maps/StartMap/scripts.pory"
	.string "Minimal Grind Mode disabled!$"

Story_Start_MinimalGrinding_Text_8:
# 190 "data/maps/StartMap/scripts.pory"
	.string "Modo Minimal Grind desactivado!$"

Story_Start_LunaticMode_Choosed_Text_0:
# 212 "data/maps/StartMap/scripts.pory"
	.string "Modo Lunático escolhido!$"

Story_Start_LunaticMode_Choosed_Text_1:
# 213 "data/maps/StartMap/scripts.pory"
	.string "Lunatic Mode chosen!$"

Story_Start_LunaticMode_Choosed_Text_2:
# 214 "data/maps/StartMap/scripts.pory"
	.string "Modo Lunático elegido!$"

Text_WantToChooseDifficultyPt::
# 31 "data/maps/StartMap/scripts.pory"
	.string "Deseja escolher essa dificuldade?$"

Text_WantToChooseDifficultyEn::
# 35 "data/maps/StartMap/scripts.pory"
	.string "Would you like to choose this\n"
	.string "difficulty?$"

Text_WantToChooseDifficultyEs::
# 40 "data/maps/StartMap/scripts.pory"
	.string "¿Quieres elegir esta dificultad?$"
