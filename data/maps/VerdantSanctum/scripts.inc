VerdantSanctum_MapScripts::
	.byte 0


VerdantSanctum_EventScript_PicnickerPaty::
# 4 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_PicnickerPaty_3
# 8 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_PicnickerPaty_4
# 11 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_PicnickerPaty_5
VerdantSanctum_EventScript_PicnickerPaty_1:
# 15 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_PicnickerPaty_3:
# 6 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_PATY, VerdantSanctum_EventScript_PicnickerPaty_Text_0, VerdantSanctum_EventScript_PicnickerPaty_Text_1
# 7 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_PicnickerPaty_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_PicnickerPaty_1

VerdantSanctum_EventScript_PicnickerPaty_4:
# 9 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_PATY, VerdantSanctum_EventScript_PicnickerPaty_Text_3, VerdantSanctum_EventScript_PicnickerPaty_Text_4
# 10 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_PicnickerPaty_Text_5, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_PicnickerPaty_1

VerdantSanctum_EventScript_PicnickerPaty_5:
# 12 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_PATY, VerdantSanctum_EventScript_PicnickerPaty_Text_6, VerdantSanctum_EventScript_PicnickerPaty_Text_7
# 13 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_PicnickerPaty_Text_8, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_PicnickerPaty_1


VerdantSanctum_EventScript_SouthPassageShroomish::
# 22 "data/maps/VerdantSanctum/scripts.pory"
	lock
# 23 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 24 "data/maps/VerdantSanctum/scripts.pory"
	movenpc VAR_LAST_TALKED, VerdantSanctum_EventScript_SouthPassageShroomish_Movement_0
# 25 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 26 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 27 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_SouthPassageShroomish_3
# 28 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_SouthPassageShroomish_4
# 29 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_SouthPassageShroomish_5
VerdantSanctum_EventScript_SouthPassageShroomish_1:
# 31 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_SouthPassageShroomish_3:
# 27 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_SouthPassageShroomish_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_SouthPassageShroomish_1

VerdantSanctum_EventScript_SouthPassageShroomish_4:
# 28 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_SouthPassageShroomish_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_SouthPassageShroomish_1

VerdantSanctum_EventScript_SouthPassageShroomish_5:
# 29 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_SouthPassageShroomish_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_SouthPassageShroomish_1


VerdantSanctum_EventScript_IslandLeafStone::
# 37 "data/maps/VerdantSanctum/scripts.pory"
	finditem ITEM_LEAF_STONE
	end


VerdantSanctum_EventScript_Shroomish::
# 42 "data/maps/VerdantSanctum/scripts.pory"
	lockall
# 43 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 44 "data/maps/VerdantSanctum/scripts.pory"
	pause 20
# 45 "data/maps/VerdantSanctum/scripts.pory"
	movenpc LOCALID_VERDANT_SANCTUM_SHROOMISH, VerdantSanctum_EventScript_SouthPassageShroomish_Movement_0
# 46 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 48 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 49 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_Shroomish_3
# 50 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_Shroomish_4
# 51 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_Shroomish_5
VerdantSanctum_EventScript_Shroomish_1:
# 56 "data/maps/VerdantSanctum/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq VerdantSanctum_EventScript_Shroomish_7
# 56 "data/maps/VerdantSanctum/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq VerdantSanctum_EventScript_Shroomish_7
# 59 "data/maps/VerdantSanctum/scripts.pory"
	movenpc LOCALID_VERDANT_SANCTUM_SHROOMISH, VerdantSanctum_EventScript_Shroomish_Movement_1
VerdantSanctum_EventScript_Shroomish_6:
# 61 "data/maps/VerdantSanctum/scripts.pory"
	releaseall
	end

VerdantSanctum_EventScript_Shroomish_3:
# 49 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_Shroomish_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_Shroomish_1

VerdantSanctum_EventScript_Shroomish_4:
# 50 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_Shroomish_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_Shroomish_1

VerdantSanctum_EventScript_Shroomish_5:
# 51 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_Shroomish_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_Shroomish_1

VerdantSanctum_EventScript_Shroomish_7:
# 57 "data/maps/VerdantSanctum/scripts.pory"
	movenpc LOCALID_VERDANT_SANCTUM_SHROOMISH, VerdantSanctum_EventScript_Shroomish_Movement_0
	goto VerdantSanctum_EventScript_Shroomish_6


VerdantSanctum_EventScript_ColumnA::
# 67 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 68 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_ColumnA_3
# 69 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_ColumnA_4
# 70 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_ColumnA_5
VerdantSanctum_EventScript_ColumnA_1:
	end

VerdantSanctum_EventScript_ColumnA_3:
# 68 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnA_Text_0, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnA_1

VerdantSanctum_EventScript_ColumnA_4:
# 69 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnA_Text_1, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnA_1

VerdantSanctum_EventScript_ColumnA_5:
# 70 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnA_Text_2, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnA_1


VerdantSanctum_EventScript_ColumnB::
# 76 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 77 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_ColumnB_3
# 78 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_ColumnB_4
# 79 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_ColumnB_5
VerdantSanctum_EventScript_ColumnB_1:
	end

VerdantSanctum_EventScript_ColumnB_3:
# 77 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnB_Text_0, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnB_1

VerdantSanctum_EventScript_ColumnB_4:
# 78 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnB_Text_1, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnB_1

VerdantSanctum_EventScript_ColumnB_5:
# 79 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnB_Text_2, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnB_1


VerdantSanctum_EventScript_ColumnC::
# 85 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 86 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_ColumnC_3
# 87 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_ColumnC_4
# 88 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_ColumnC_5
VerdantSanctum_EventScript_ColumnC_1:
	end

VerdantSanctum_EventScript_ColumnC_3:
# 86 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnC_Text_0, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnC_1

VerdantSanctum_EventScript_ColumnC_4:
# 87 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnC_Text_1, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnC_1

VerdantSanctum_EventScript_ColumnC_5:
# 88 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnC_Text_2, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnC_1


VerdantSanctum_EventScript_ColumnSimple::
# 94 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 95 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_ColumnSimple_3
# 96 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_ColumnSimple_4
# 97 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_ColumnSimple_5
VerdantSanctum_EventScript_ColumnSimple_1:
	end

VerdantSanctum_EventScript_ColumnSimple_3:
# 95 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnSimple_Text_0, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnSimple_1

VerdantSanctum_EventScript_ColumnSimple_4:
# 96 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnSimple_Text_1, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnSimple_1

VerdantSanctum_EventScript_ColumnSimple_5:
# 97 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ColumnSimple_Text_2, MSGBOX_SIGN
	goto VerdantSanctum_EventScript_ColumnSimple_1


VerdantSanctum_EventScript_Entrance::
# 104 "data/maps/VerdantSanctum/scripts.pory"
	goto_if_set FLAG_VERDANT_SANCTUM_ENTRANCE_DONE, VerdantSanctum_EventScript_Entrance_2
# 108 "data/maps/VerdantSanctum/scripts.pory"
	lockall
# 109 "data/maps/VerdantSanctum/scripts.pory"
	moveplayer VerdantSanctum_EventScript_Entrance_Movement_0
# 110 "data/maps/VerdantSanctum/scripts.pory"
	special SpawnCameraObject
# 111 "data/maps/VerdantSanctum/scripts.pory"
	movecamera VerdantSanctum_EventScript_Entrance_Movement_1
# 112 "data/maps/VerdantSanctum/scripts.pory"
	pause 45
# 114 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 115 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_Entrance_6
# 116 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_Entrance_7
# 117 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_Entrance_8
VerdantSanctum_EventScript_Entrance_4:
# 119 "data/maps/VerdantSanctum/scripts.pory"
	pause 30
# 121 "data/maps/VerdantSanctum/scripts.pory"
	movecamera VerdantSanctum_EventScript_Entrance_Movement_2
# 122 "data/maps/VerdantSanctum/scripts.pory"
	special RemoveCameraObject
# 123 "data/maps/VerdantSanctum/scripts.pory"
	releaseall
# 124 "data/maps/VerdantSanctum/scripts.pory"
	setflag FLAG_VERDANT_SANCTUM_ENTRANCE_DONE
	end

VerdantSanctum_EventScript_Entrance_2:
	end

VerdantSanctum_EventScript_Entrance_6:
# 115 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_Entrance_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_Entrance_4

VerdantSanctum_EventScript_Entrance_7:
# 116 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_Entrance_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_Entrance_4

VerdantSanctum_EventScript_Entrance_8:
# 117 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_Entrance_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_Entrance_4


VerdantSanctum_EventScript_PsychicFredrick_Battle::
# 129 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 130 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_PsychicFredrick_Battle_3
# 133 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_PsychicFredrick_Battle_4
# 136 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_PsychicFredrick_Battle_5
VerdantSanctum_EventScript_PsychicFredrick_Battle_1:
# 140 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_PsychicFredrick_Battle_3:
# 131 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_PSYCHIC_FREDRICK, VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_0, VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_1
# 132 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_PsychicFredrick_Battle_1

VerdantSanctum_EventScript_PsychicFredrick_Battle_4:
# 134 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_PSYCHIC_FREDRICK, VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_3, VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_4
# 135 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_5, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_PsychicFredrick_Battle_1

VerdantSanctum_EventScript_PsychicFredrick_Battle_5:
# 137 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_PSYCHIC_FREDRICK, VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_6, VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_7
# 138 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_8, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_PsychicFredrick_Battle_1


VerdantSanctum_EventScript_PokemonRangerM_Battle::
# 145 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 146 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_PokemonRangerM_Battle_3
# 149 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_PokemonRangerM_Battle_4
# 152 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_PokemonRangerM_Battle_5
VerdantSanctum_EventScript_PokemonRangerM_Battle_1:
# 156 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_PokemonRangerM_Battle_3:
# 147 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_POKEMON_RANGER_EDU, VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_0, VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_1
# 148 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_PokemonRangerM_Battle_1

VerdantSanctum_EventScript_PokemonRangerM_Battle_4:
# 150 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_POKEMON_RANGER_EDU, VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_3, VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_4
# 151 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_5, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_PokemonRangerM_Battle_1

VerdantSanctum_EventScript_PokemonRangerM_Battle_5:
# 153 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_POKEMON_RANGER_EDU, VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_6, VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_7
# 154 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_8, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_PokemonRangerM_Battle_1


VerdantSanctum_EventScript_AceTrainerAlma::
# 161 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 162 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_AceTrainerAlma_3
# 165 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_AceTrainerAlma_4
# 168 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_AceTrainerAlma_5
VerdantSanctum_EventScript_AceTrainerAlma_1:
# 172 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_AceTrainerAlma_3:
# 163 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_ACE_TRAINER_ALMA, VerdantSanctum_EventScript_AceTrainerAlma_Text_0, VerdantSanctum_EventScript_AceTrainerAlma_Text_1
# 164 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_AceTrainerAlma_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_AceTrainerAlma_1

VerdantSanctum_EventScript_AceTrainerAlma_4:
# 166 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_ACE_TRAINER_ALMA, VerdantSanctum_EventScript_AceTrainerAlma_Text_3, VerdantSanctum_EventScript_AceTrainerAlma_Text_4
# 167 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_AceTrainerAlma_Text_5, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_AceTrainerAlma_1

VerdantSanctum_EventScript_AceTrainerAlma_5:
# 169 "data/maps/VerdantSanctum/scripts.pory"
	trainerbattle_single TRAINER_ACE_TRAINER_ALMA, VerdantSanctum_EventScript_AceTrainerAlma_Text_6, VerdantSanctum_EventScript_AceTrainerAlma_Text_7
# 170 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_AceTrainerAlma_Text_8, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_AceTrainerAlma_1


VerdantSanctum_EventScript_ForestListener::
# 177 "data/maps/VerdantSanctum/scripts.pory"
	lock
# 178 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 179 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 180 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_ForestListener_3
# 181 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_ForestListener_4
# 182 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_ForestListener_5
VerdantSanctum_EventScript_ForestListener_1:
# 184 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_ForestListener_3:
# 180 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ForestListener_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_ForestListener_1

VerdantSanctum_EventScript_ForestListener_4:
# 181 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ForestListener_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_ForestListener_1

VerdantSanctum_EventScript_ForestListener_5:
# 182 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_ForestListener_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_ForestListener_1


VerdantSanctum_EventScript_MushroomObserver::
# 189 "data/maps/VerdantSanctum/scripts.pory"
	lock
# 190 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 191 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 192 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_MushroomObserver_3
# 193 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_MushroomObserver_4
# 194 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_MushroomObserver_5
VerdantSanctum_EventScript_MushroomObserver_1:
# 196 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_MushroomObserver_3:
# 192 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_MushroomObserver_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_MushroomObserver_1

VerdantSanctum_EventScript_MushroomObserver_4:
# 193 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_MushroomObserver_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_MushroomObserver_1

VerdantSanctum_EventScript_MushroomObserver_5:
# 194 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_MushroomObserver_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_MushroomObserver_1


VerdantSanctum_EventScript_RuinResearcher::
# 201 "data/maps/VerdantSanctum/scripts.pory"
	lock
# 202 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 203 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 204 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_RuinResearcher_3
# 205 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_RuinResearcher_4
# 206 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_RuinResearcher_5
VerdantSanctum_EventScript_RuinResearcher_1:
# 208 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_RuinResearcher_3:
# 204 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_RuinResearcher_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_RuinResearcher_1

VerdantSanctum_EventScript_RuinResearcher_4:
# 205 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_RuinResearcher_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_RuinResearcher_1

VerdantSanctum_EventScript_RuinResearcher_5:
# 206 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_RuinResearcher_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_RuinResearcher_1


VerdantSanctum_EventScript_TrailExplorer::
# 213 "data/maps/VerdantSanctum/scripts.pory"
	lock
# 214 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 215 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 216 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_TrailExplorer_3
# 217 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_TrailExplorer_4
# 218 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_TrailExplorer_5
VerdantSanctum_EventScript_TrailExplorer_1:
# 220 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_TrailExplorer_3:
# 216 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_TrailExplorer_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_TrailExplorer_1

VerdantSanctum_EventScript_TrailExplorer_4:
# 217 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_TrailExplorer_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_TrailExplorer_1

VerdantSanctum_EventScript_TrailExplorer_5:
# 218 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_TrailExplorer_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_TrailExplorer_1


VerdantSanctum_EventScript_LightWatcher::
# 225 "data/maps/VerdantSanctum/scripts.pory"
	lock
# 226 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 227 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 228 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_LightWatcher_3
# 229 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_LightWatcher_4
# 230 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_LightWatcher_5
VerdantSanctum_EventScript_LightWatcher_1:
# 232 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_LightWatcher_3:
# 228 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_LightWatcher_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_LightWatcher_1

VerdantSanctum_EventScript_LightWatcher_4:
# 229 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_LightWatcher_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_LightWatcher_1

VerdantSanctum_EventScript_LightWatcher_5:
# 230 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_LightWatcher_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_LightWatcher_1


VerdantSanctum_EventScript_YoungExplorer::
# 237 "data/maps/VerdantSanctum/scripts.pory"
	lock
# 238 "data/maps/VerdantSanctum/scripts.pory"
	faceplayer
# 239 "data/maps/VerdantSanctum/scripts.pory"
	switch VAR_LANGUAGE
# 240 "data/maps/VerdantSanctum/scripts.pory"
	case PT, VerdantSanctum_EventScript_YoungExplorer_3
# 241 "data/maps/VerdantSanctum/scripts.pory"
	case EN, VerdantSanctum_EventScript_YoungExplorer_4
# 242 "data/maps/VerdantSanctum/scripts.pory"
	case ES, VerdantSanctum_EventScript_YoungExplorer_5
VerdantSanctum_EventScript_YoungExplorer_1:
# 244 "data/maps/VerdantSanctum/scripts.pory"
	release
	end

VerdantSanctum_EventScript_YoungExplorer_3:
# 240 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_YoungExplorer_Text_0, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_YoungExplorer_1

VerdantSanctum_EventScript_YoungExplorer_4:
# 241 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_YoungExplorer_Text_1, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_YoungExplorer_1

VerdantSanctum_EventScript_YoungExplorer_5:
# 242 "data/maps/VerdantSanctum/scripts.pory"
	msgbox VerdantSanctum_EventScript_YoungExplorer_Text_2, MSGBOX_DEFAULT
	goto VerdantSanctum_EventScript_YoungExplorer_1


# 24 "data/maps/VerdantSanctum/scripts.pory"
VerdantSanctum_EventScript_SouthPassageShroomish_Movement_0:
# 24 "data/maps/VerdantSanctum/scripts.pory"
	emoji_doubt
# 24 "data/maps/VerdantSanctum/scripts.pory"
	face_left
# 24 "data/maps/VerdantSanctum/scripts.pory"
	delay_16
# 24 "data/maps/VerdantSanctum/scripts.pory"
	face_right
# 24 "data/maps/VerdantSanctum/scripts.pory"
	delay_16
	step_end

# 57 "data/maps/VerdantSanctum/scripts.pory"
VerdantSanctum_EventScript_Shroomish_Movement_0:
# 57 "data/maps/VerdantSanctum/scripts.pory"
	walk_right
# 57 "data/maps/VerdantSanctum/scripts.pory"
	walk_right
# 57 "data/maps/VerdantSanctum/scripts.pory"
	delay_16
# 57 "data/maps/VerdantSanctum/scripts.pory"
	walk_left
# 57 "data/maps/VerdantSanctum/scripts.pory"
	walk_left
# 57 "data/maps/VerdantSanctum/scripts.pory"
	face_down
	step_end

# 59 "data/maps/VerdantSanctum/scripts.pory"
VerdantSanctum_EventScript_Shroomish_Movement_1:
# 59 "data/maps/VerdantSanctum/scripts.pory"
	walk_up
# 59 "data/maps/VerdantSanctum/scripts.pory"
	walk_up
# 59 "data/maps/VerdantSanctum/scripts.pory"
	delay_16
# 59 "data/maps/VerdantSanctum/scripts.pory"
	walk_down
# 59 "data/maps/VerdantSanctum/scripts.pory"
	walk_down
# 59 "data/maps/VerdantSanctum/scripts.pory"
	face_down
	step_end

# 109 "data/maps/VerdantSanctum/scripts.pory"
VerdantSanctum_EventScript_Entrance_Movement_0:
# 109 "data/maps/VerdantSanctum/scripts.pory"
	walk_down
# 109 "data/maps/VerdantSanctum/scripts.pory"
	walk_down
# 109 "data/maps/VerdantSanctum/scripts.pory"
	walk_down
# 109 "data/maps/VerdantSanctum/scripts.pory"
	face_down
	step_end

# 111 "data/maps/VerdantSanctum/scripts.pory"
VerdantSanctum_EventScript_Entrance_Movement_1:
# 111 "data/maps/VerdantSanctum/scripts.pory"
	walk_slow_down
# 111 "data/maps/VerdantSanctum/scripts.pory"
	walk_slow_down
# 111 "data/maps/VerdantSanctum/scripts.pory"
	walk_slow_down
# 111 "data/maps/VerdantSanctum/scripts.pory"
	walk_slow_down
	step_end

# 121 "data/maps/VerdantSanctum/scripts.pory"
VerdantSanctum_EventScript_Entrance_Movement_2:
# 121 "data/maps/VerdantSanctum/scripts.pory"
	walk_slow_up
# 121 "data/maps/VerdantSanctum/scripts.pory"
	walk_slow_up
# 121 "data/maps/VerdantSanctum/scripts.pory"
	walk_slow_up
# 121 "data/maps/VerdantSanctum/scripts.pory"
	walk_slow_up
	step_end

VerdantSanctum_EventScript_PicnickerPaty_Text_0:
# 6 "data/maps/VerdantSanctum/scripts.pory"
	.string "Vim explorar o santuário só\npor diversão!\pUma batalha vai deixar o passeio\nainda melhor!$"

VerdantSanctum_EventScript_PicnickerPaty_Text_1:
# 6 "data/maps/VerdantSanctum/scripts.pory"
	.string "Perdi, mas me diverti muito!$"

VerdantSanctum_EventScript_PicnickerPaty_Text_2:
# 7 "data/maps/VerdantSanctum/scripts.pory"
	.string "Meu Smoliv adora o sol, e Shroomish\nprefere a sombra das árvores.\pAgora só falta achar um cantinho\npara o nosso piquenique!$"

VerdantSanctum_EventScript_PicnickerPaty_Text_3:
# 9 "data/maps/VerdantSanctum/scripts.pory"
	.string "I came to explore the sanctuary\njust for fun!\pA battle will make this outing\neven better!$"

VerdantSanctum_EventScript_PicnickerPaty_Text_4:
# 9 "data/maps/VerdantSanctum/scripts.pory"
	.string "I lost, but I had so much fun!$"

VerdantSanctum_EventScript_PicnickerPaty_Text_5:
# 10 "data/maps/VerdantSanctum/scripts.pory"
	.string "My Smoliv loves the sun, while\nShroomish prefers the trees' shade.\pNow we just need to find a spot\nfor our picnic!$"

VerdantSanctum_EventScript_PicnickerPaty_Text_6:
# 12 "data/maps/VerdantSanctum/scripts.pory"
	.string "¡Vine a explorar el santuario\nsolo por diversión!\p¡Un combate hará que el paseo\nsea aún mejor!$"

VerdantSanctum_EventScript_PicnickerPaty_Text_7:
# 12 "data/maps/VerdantSanctum/scripts.pory"
	.string "¡Perdí, pero me divertí mucho!$"

VerdantSanctum_EventScript_PicnickerPaty_Text_8:
# 13 "data/maps/VerdantSanctum/scripts.pory"
	.string "A mi Smoliv le encanta el sol,\ny Shroomish prefiere la sombra.\p¡Ahora solo falta encontrar\nun rincón para nuestro pícnic!$"

VerdantSanctum_EventScript_SouthPassageShroomish_Text_0:
# 27 "data/maps/VerdantSanctum/scripts.pory"
	.string "Os SHROOMISH estão inquietos.\pEles se amontoam na passagem,\nsem sair do lugar.$"

VerdantSanctum_EventScript_SouthPassageShroomish_Text_1:
# 28 "data/maps/VerdantSanctum/scripts.pory"
	.string "The SHROOMISH are restless.\pThey huddle in the passage\nand refuse to move.$"

VerdantSanctum_EventScript_SouthPassageShroomish_Text_2:
# 29 "data/maps/VerdantSanctum/scripts.pory"
	.string "Los SHROOMISH están inquietos.\pSe amontonan en el paso\nsin moverse del sitio.$"

VerdantSanctum_EventScript_Shroomish_Text_0:
# 49 "data/maps/VerdantSanctum/scripts.pory"
	.string "O SHROOMISH parece\ndesorientado...\pEle parece não reconhecer\no lugar ao seu redor.$"

VerdantSanctum_EventScript_Shroomish_Text_1:
# 50 "data/maps/VerdantSanctum/scripts.pory"
	.string "SHROOMISH seems disoriented...\pIt seems not to recognize\nits surroundings.$"

VerdantSanctum_EventScript_Shroomish_Text_2:
# 51 "data/maps/VerdantSanctum/scripts.pory"
	.string "SHROOMISH parece desorientado...\pParece no reconocer\nel lugar que lo rodea.$"

VerdantSanctum_EventScript_ColumnA_Text_0:
# 68 "data/maps/VerdantSanctum/scripts.pory"
	.string "A superfície está coberta de\npequenas marcas.\pSão antigas demais para serem\nreconhecidas.$"

VerdantSanctum_EventScript_ColumnA_Text_1:
# 69 "data/maps/VerdantSanctum/scripts.pory"
	.string "The surface is covered in\nsmall marks.\pThey are too old to be\nrecognized.$"

VerdantSanctum_EventScript_ColumnA_Text_2:
# 70 "data/maps/VerdantSanctum/scripts.pory"
	.string "La superficie está cubierta de\npequeñas marcas.\pSon demasiado antiguas para\nreconocerlas.$"

VerdantSanctum_EventScript_ColumnB_Text_0:
# 77 "data/maps/VerdantSanctum/scripts.pory"
	.string "Parte da coluna parece ter sido\ncuidadosamente polida.\pApesar da idade, quase não\nexistem rachaduras.$"

VerdantSanctum_EventScript_ColumnB_Text_1:
# 78 "data/maps/VerdantSanctum/scripts.pory"
	.string "Part of the column seems to have\nbeen carefully polished.\pDespite its age, there are\nalmost no cracks.$"

VerdantSanctum_EventScript_ColumnB_Text_2:
# 79 "data/maps/VerdantSanctum/scripts.pory"
	.string "Parte de la columna parece haber\nsido pulida con cuidado.\pA pesar de su edad, casi no\nhay grietas.$"

VerdantSanctum_EventScript_ColumnC_Text_0:
# 86 "data/maps/VerdantSanctum/scripts.pory"
	.string "Há um pequeno desenho gravado\nna pedra.\pNão se parece com o símbolo\nque você viu antes.$"

VerdantSanctum_EventScript_ColumnC_Text_1:
# 87 "data/maps/VerdantSanctum/scripts.pory"
	.string "There is a small drawing carved\ninto the stone.\pIt does not look like the symbol\nyou saw before.$"

VerdantSanctum_EventScript_ColumnC_Text_2:
# 88 "data/maps/VerdantSanctum/scripts.pory"
	.string "Hay un pequeño dibujo grabado\nen la piedra.\pNo se parece al símbolo\nque viste antes.$"

VerdantSanctum_EventScript_ColumnSimple_Text_0:
# 95 "data/maps/VerdantSanctum/scripts.pory"
	.string "Uma antiga coluna de pedra.$"

VerdantSanctum_EventScript_ColumnSimple_Text_1:
# 96 "data/maps/VerdantSanctum/scripts.pory"
	.string "An ancient stone column.$"

VerdantSanctum_EventScript_ColumnSimple_Text_2:
# 97 "data/maps/VerdantSanctum/scripts.pory"
	.string "Una antigua columna de piedra.$"

VerdantSanctum_EventScript_Entrance_Text_0:
# 115 "data/maps/VerdantSanctum/scripts.pory"
	.string "O ar aqui parece...\ndiferente.$"

VerdantSanctum_EventScript_Entrance_Text_1:
# 116 "data/maps/VerdantSanctum/scripts.pory"
	.string "The air here feels...\ndifferent.$"

VerdantSanctum_EventScript_Entrance_Text_2:
# 117 "data/maps/VerdantSanctum/scripts.pory"
	.string "El aire aquí se siente...\ndiferente.$"

VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_0:
# 131 "data/maps/VerdantSanctum/scripts.pory"
	.string "Sinto algo incomum vindo\ndas ruínas...\pÉ como um pensamento distante\nque não consigo compreender.\pTalvez uma batalha me ajude\na clarear a mente. Vamos?$"

VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_1:
# 131 "data/maps/VerdantSanctum/scripts.pory"
	.string "Sua força me trouxe de volta!$"

VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_2:
# 132 "data/maps/VerdantSanctum/scripts.pory"
	.string "Mesmo com a mente mais clara,\na sensação continua...\pEla vem e vai, como um eco\nentre aquelas pedras.\pSerá que os Pokémon daqui\ntambém conseguem senti-la?$"

VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_3:
# 134 "data/maps/VerdantSanctum/scripts.pory"
	.string "I sense something unusual\ncoming from the ruins...\pLike a distant thought\nI can't quite understand.\pPerhaps a battle will help\nclear my mind. Shall we?$"

VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_4:
# 134 "data/maps/VerdantSanctum/scripts.pory"
	.string "Your strength brought me back!$"

VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_5:
# 135 "data/maps/VerdantSanctum/scripts.pory"
	.string "Even with my mind clearer,\nthe feeling remains...\pIt comes and goes, like an echo\namong those stones.\pI wonder if the Pokémon here\ncan sense it too?$"

VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_6:
# 137 "data/maps/VerdantSanctum/scripts.pory"
	.string "Siento algo inusual que viene\nde las ruinas...\pEs como un pensamiento lejano\nque no logro comprender.\pQuizá un combate me ayude\na despejar la mente. ¿Vamos?$"

VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_7:
# 137 "data/maps/VerdantSanctum/scripts.pory"
	.string "¡Tu fuerza me hizo reaccionar!$"

VerdantSanctum_EventScript_PsychicFredrick_Battle_Text_8:
# 138 "data/maps/VerdantSanctum/scripts.pory"
	.string "Incluso con la mente más clara,\nla sensación continúa...\pVa y viene, como un eco\nentre aquellas piedras.\p¿Los Pokémon de este lugar\ntambién podrán sentirla?$"

VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_0:
# 147 "data/maps/VerdantSanctum/scripts.pory"
	.string "Sou Ranger. Estou observando\nos Pokémon deste santuário.\pOs Shroomish parecem perdidos,\nmesmo no próprio habitat...\pPreciso estar pronto para ajudar.\nQue tal uma batalha de treino?$"

VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_1:
# 147 "data/maps/VerdantSanctum/scripts.pory"
	.string "Você sabe agir sob pressão!$"

VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_2:
# 148 "data/maps/VerdantSanctum/scripts.pory"
	.string "Os Pokémon percebem mudanças\nque nós nem conseguimos sentir.\pTalvez algo neste lugar esteja\ndeixando todos tão inquietos.\pVou continuar observando.\nEles precisam de cuidado.$"

VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_3:
# 150 "data/maps/VerdantSanctum/scripts.pory"
	.string "I'm a Ranger. I'm observing\nthe Pokémon in this sanctuary.\pThe Shroomish seem lost,\neven in their own habitat...\pI need to be ready to help.\nHow about a practice battle?$"

VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_4:
# 150 "data/maps/VerdantSanctum/scripts.pory"
	.string "You stay calm under pressure!$"

VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_5:
# 151 "data/maps/VerdantSanctum/scripts.pory"
	.string "Pokémon can sense changes\nthat we don't even notice.\pPerhaps something here\nis making them all so restless.\pI'll keep watching over them.\nThey need someone looking out.$"

VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_6:
# 153 "data/maps/VerdantSanctum/scripts.pory"
	.string "Soy Ranger. Estoy observando\na los Pokémon del santuario.\pLos Shroomish parecen perdidos,\nincluso en su propio hábitat...\pDebo estar listo para ayudar.\n¿Qué tal un combate de práctica?$"

VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_7:
# 153 "data/maps/VerdantSanctum/scripts.pory"
	.string "¡Sabes actuar bajo presión!$"

VerdantSanctum_EventScript_PokemonRangerM_Battle_Text_8:
# 154 "data/maps/VerdantSanctum/scripts.pory"
	.string "Los Pokémon perciben cambios\nque nosotros ni notamos.\pQuizá algo en este lugar\nlos tenga tan inquietos.\pSeguiré observándolos.\nNecesitan que alguien los cuide.$"

VerdantSanctum_EventScript_AceTrainerAlma_Text_0:
# 163 "data/maps/VerdantSanctum/scripts.pory"
	.string "Sou Alma! Vim pelas trilhas,\nmas fiquei pelos desafios!\pVocê chegou até aqui. Quero ver\ncomo se sai numa batalha!$"

VerdantSanctum_EventScript_AceTrainerAlma_Text_1:
# 163 "data/maps/VerdantSanctum/scripts.pory"
	.string "Isso sim foi um desafio!$"

VerdantSanctum_EventScript_AceTrainerAlma_Text_2:
# 164 "data/maps/VerdantSanctum/scripts.pory"
	.string "Ganhar é bom, mas uma batalha\ndifícil me ensina muito mais!\pVou treinar com meu time.\nAinda temos muito a aprender!$"

VerdantSanctum_EventScript_AceTrainerAlma_Text_3:
# 166 "data/maps/VerdantSanctum/scripts.pory"
	.string "I'm Alma! I came for the trails,\nbut stayed for the challenges!\pYou made it this far. Let's see\nhow you do in a battle!$"

VerdantSanctum_EventScript_AceTrainerAlma_Text_4:
# 166 "data/maps/VerdantSanctum/scripts.pory"
	.string "Now that was a challenge!$"

VerdantSanctum_EventScript_AceTrainerAlma_Text_5:
# 167 "data/maps/VerdantSanctum/scripts.pory"
	.string "Winning feels good, but a tough\nbattle teaches me so much more!\pI'll keep training with my team.\nWe still have plenty to learn!$"

VerdantSanctum_EventScript_AceTrainerAlma_Text_6:
# 169 "data/maps/VerdantSanctum/scripts.pory"
	.string "¡Soy Alma! Vine por los senderos,\n¡pero me quedé por los retos!\pLlegaste hasta aquí. ¡Veamos\ncómo te va en un combate!$"

VerdantSanctum_EventScript_AceTrainerAlma_Text_7:
# 169 "data/maps/VerdantSanctum/scripts.pory"
	.string "¡Eso sí que fue un reto!$"

VerdantSanctum_EventScript_AceTrainerAlma_Text_8:
# 170 "data/maps/VerdantSanctum/scripts.pory"
	.string "¡Ganar está bien, pero un combate\ndifícil me enseña mucho más!\pSeguiré entrenando con mi equipo.\n¡Aún tenemos mucho que aprender!$"

VerdantSanctum_EventScript_ForestListener_Text_0:
# 180 "data/maps/VerdantSanctum/scripts.pory"
	.string "O vento muda de voz entre\nas árvores e as colunas.\pFeche os olhos por um instante.\nQue som você ouviu primeiro?$"

VerdantSanctum_EventScript_ForestListener_Text_1:
# 181 "data/maps/VerdantSanctum/scripts.pory"
	.string "The wind sounds different among\nthe trees and the columns.\pClose your eyes for a moment.\nWhich sound did you hear first?$"

VerdantSanctum_EventScript_ForestListener_Text_2:
# 182 "data/maps/VerdantSanctum/scripts.pory"
	.string "El viento suena distinto entre\nlos árboles y las columnas.\pCierra los ojos un momento.\n¿Qué sonido oíste primero?$"

VerdantSanctum_EventScript_MushroomObserver_Text_0:
# 192 "data/maps/VerdantSanctum/scripts.pory"
	.string "Estou desenhando os Shroomish.\nSó falta eles ficarem parados!\pToda vez que olho para o papel,\num deles muda de lugar.$"

VerdantSanctum_EventScript_MushroomObserver_Text_1:
# 193 "data/maps/VerdantSanctum/scripts.pory"
	.string "I'm sketching the Shroomish.\nIf only they would stand still!\pWhenever I look at my paper,\none of them moves away.$"

VerdantSanctum_EventScript_MushroomObserver_Text_2:
# 194 "data/maps/VerdantSanctum/scripts.pory"
	.string "Estoy dibujando a los Shroomish.\n¡Ojalá se quedaran quietos!\pCada vez que miro el papel,\nuno de ellos cambia de sitio.$"

VerdantSanctum_EventScript_RuinResearcher_Text_0:
# 204 "data/maps/VerdantSanctum/scripts.pory"
	.string "Estas colunas têm marcas\nembaixo do musgo.\pPrefiro copiar só o que vejo.\nNão vou arrancar o musgo\lpara completar meu desenho.$"

VerdantSanctum_EventScript_RuinResearcher_Text_1:
# 205 "data/maps/VerdantSanctum/scripts.pory"
	.string "These columns have markings\nbeneath the moss.\pI only copy what I can see.\nI will not tear off the moss\ljust to finish my drawing.$"

VerdantSanctum_EventScript_RuinResearcher_Text_2:
# 206 "data/maps/VerdantSanctum/scripts.pory"
	.string "Estas columnas tienen marcas\ndebajo del musgo.\pSolo copio lo que puedo ver.\nNo voy a arrancar el musgo\lpara terminar mi dibujo.$"

VerdantSanctum_EventScript_TrailExplorer_Text_0:
# 216 "data/maps/VerdantSanctum/scripts.pory"
	.string "Uma vez perdi uma bota na lama.\nMeu Pokémon voltou para buscar!\pDesde então, levo uma escova.\nA bota voltou... a lama também.$"

VerdantSanctum_EventScript_TrailExplorer_Text_1:
# 217 "data/maps/VerdantSanctum/scripts.pory"
	.string "I once lost a boot in the mud.\nMy Pokémon went back for it!\pNow I always carry a brush.\nThe boot came back...\land so did all the mud.$"

VerdantSanctum_EventScript_TrailExplorer_Text_2:
# 218 "data/maps/VerdantSanctum/scripts.pory"
	.string "Una vez perdí una bota en el lodo.\n¡Mi Pokémon fue a buscarla!\pAhora siempre llevo un cepillo.\nLa bota volvió...\ly también todo el lodo.$"

VerdantSanctum_EventScript_LightWatcher_Text_0:
# 228 "data/maps/VerdantSanctum/scripts.pory"
	.string "Eu ia embora, mas vi uma luz\npiscando entre as folhas.\pEsperei por outra. Depois outra.\nJá faz um bom tempo que\lestou quase indo embora!$"

VerdantSanctum_EventScript_LightWatcher_Text_1:
# 229 "data/maps/VerdantSanctum/scripts.pory"
	.string "I was leaving when I saw a light\nblinking among the leaves.\pI waited for another. Then more.\nI have been almost ready\lto leave for quite a while!$"

VerdantSanctum_EventScript_LightWatcher_Text_2:
# 230 "data/maps/VerdantSanctum/scripts.pory"
	.string "Iba a irme cuando vi una luz\nparpadear entre las hojas.\pEsperé otra. Y luego otra más.\n¡Llevo un buen rato\la punto de marcharme!$"

VerdantSanctum_EventScript_YoungExplorer_Text_0:
# 240 "data/maps/VerdantSanctum/scripts.pory"
	.string "A Alma adora desafios! Eu disse\nque ia achar a maior folha daqui.\pAgora preciso de uma régua...\nEla quer conferir o resultado!$"

VerdantSanctum_EventScript_YoungExplorer_Text_1:
# 241 "data/maps/VerdantSanctum/scripts.pory"
	.string "Alma loves challenges! I told her\nI would find the biggest leaf here.\pNow I need a ruler...\nShe wants to check the result!$"

VerdantSanctum_EventScript_YoungExplorer_Text_2:
# 242 "data/maps/VerdantSanctum/scripts.pory"
	.string "¡A Alma le encantan los retos!\nLe dije que hallaría la hoja mayor.\pAhora necesito una regla...\n¡Quiere comprobar el resultado!$"
