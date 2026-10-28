Route4_MapScripts::
	.byte 0


Route4_EventScript_Sign::
# 4 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_Sign_3
# 6 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_Sign_4
# 7 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_Sign_5
Route4_EventScript_Sign_1:
	end

Route4_EventScript_Sign_3:
# 5 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_Sign_Text_0, MSGBOX_SIGN
	goto Route4_EventScript_Sign_1

Route4_EventScript_Sign_4:
# 6 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_Sign_Text_1, MSGBOX_SIGN
	goto Route4_EventScript_Sign_1

Route4_EventScript_Sign_5:
# 7 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_Sign_Text_2, MSGBOX_SIGN
	goto Route4_EventScript_Sign_1


Route4_EventScript_AbsolSymbol::
# 14 "data/maps/Route4/scripts.pory"
	goto_if_unset FLAG_DEFEATED_STONEREACH_GYM, Route4_EventScript_AbsolSymbol_2
# 17 "data/maps/Route4/scripts.pory"
	goto_if_set FLAG_ROUTE4_ABSOL_SYMBOL_EVENT_DONE, Route4_EventScript_AbsolSymbol_5
# 21 "data/maps/Route4/scripts.pory"
	lockall
# 22 "data/maps/Route4/scripts.pory"
	moveplayer Route4_EventScript_AbsolSymbol_Movement_0
# 23 "data/maps/Route4/scripts.pory"
	special SpawnCameraObject
# 24 "data/maps/Route4/scripts.pory"
	movecamera Route4_EventScript_AbsolSymbol_Movement_1
# 25 "data/maps/Route4/scripts.pory"
	movenpc LOCALID_ROUTE4_EVENT_ABSOL, Route4_EventScript_AbsolSymbol_Movement_2
# 26 "data/maps/Route4/scripts.pory"
	pause 36
# 28 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 29 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_AbsolSymbol_9
# 30 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_AbsolSymbol_10
# 31 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_AbsolSymbol_11
Route4_EventScript_AbsolSymbol_7:
# 33 "data/maps/Route4/scripts.pory"
	pause 45
# 36 "data/maps/Route4/scripts.pory"
	movenpc LOCALID_ROUTE4_EVENT_ABSOL, Route4_EventScript_AbsolSymbol_Movement_3
# 37 "data/maps/Route4/scripts.pory"
	playse SE_M_CONFUSE_RAY
# 38 "data/maps/Route4/scripts.pory"
	setvar VAR_0x8004, 1
# 39 "data/maps/Route4/scripts.pory"
	setvar VAR_0x8005, 1
# 40 "data/maps/Route4/scripts.pory"
	setvar VAR_0x8006, 4
# 41 "data/maps/Route4/scripts.pory"
	setvar VAR_0x8007, 4
# 42 "data/maps/Route4/scripts.pory"
	special ShakeCamera
# 43 "data/maps/Route4/scripts.pory"
	setvar VAR_0x8000, LOCALID_ROUTE4_EVENT_ABSOL
# 44 "data/maps/Route4/scripts.pory"
	callnative CreateRoute4GroundSymbol
# 45 "data/maps/Route4/scripts.pory"
	waitstate
# 46 "data/maps/Route4/scripts.pory"
	pause 8
# 49 "data/maps/Route4/scripts.pory"
	playse SE_PIN
# 50 "data/maps/Route4/scripts.pory"
	movenpc LOCALID_ROUTE4_EVENT_ABSOL, Route4_EventScript_AbsolSymbol_Movement_4
# 51 "data/maps/Route4/scripts.pory"
	waitse
# 52 "data/maps/Route4/scripts.pory"
	pause 28
# 55 "data/maps/Route4/scripts.pory"
	movenpc LOCALID_ROUTE4_EVENT_ABSOL, Route4_EventScript_AbsolSymbol_Movement_5
# 56 "data/maps/Route4/scripts.pory"
	pause 18
# 57 "data/maps/Route4/scripts.pory"
	movenpc LOCALID_ROUTE4_EVENT_ABSOL, Route4_EventScript_AbsolSymbol_Movement_6
# 58 "data/maps/Route4/scripts.pory"
	removeobject LOCALID_ROUTE4_EVENT_ABSOL
# 59 "data/maps/Route4/scripts.pory"
	setflag FLAG_ROUTE4_ABSOL_SYMBOL_EVENT_DONE
# 61 "data/maps/Route4/scripts.pory"
	pause 30
# 62 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_AbsolSymbol_Text_3, MSGBOX_DEFAULT
# 63 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 64 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_AbsolSymbol_14
# 65 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_AbsolSymbol_15
# 66 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_AbsolSymbol_16
Route4_EventScript_AbsolSymbol_12:
# 69 "data/maps/Route4/scripts.pory"
	movecamera Route4_EventScript_AbsolSymbol_Movement_7
# 70 "data/maps/Route4/scripts.pory"
	special RemoveCameraObject
# 71 "data/maps/Route4/scripts.pory"
	releaseall
	end

Route4_EventScript_AbsolSymbol_2:
	end

Route4_EventScript_AbsolSymbol_5:
	end

Route4_EventScript_AbsolSymbol_9:
# 29 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_AbsolSymbol_Text_0, MSGBOX_DEFAULT
	goto Route4_EventScript_AbsolSymbol_7

Route4_EventScript_AbsolSymbol_10:
# 30 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_AbsolSymbol_Text_1, MSGBOX_DEFAULT
	goto Route4_EventScript_AbsolSymbol_7

Route4_EventScript_AbsolSymbol_11:
# 31 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_AbsolSymbol_Text_2, MSGBOX_DEFAULT
	goto Route4_EventScript_AbsolSymbol_7

Route4_EventScript_AbsolSymbol_14:
# 64 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_AbsolSymbol_Text_4, MSGBOX_DEFAULT
	goto Route4_EventScript_AbsolSymbol_12

Route4_EventScript_AbsolSymbol_15:
# 65 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_AbsolSymbol_Text_5, MSGBOX_DEFAULT
	goto Route4_EventScript_AbsolSymbol_12

Route4_EventScript_AbsolSymbol_16:
# 66 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_AbsolSymbol_Text_6, MSGBOX_DEFAULT
	goto Route4_EventScript_AbsolSymbol_12


Route4_EventScript_ParasolLady_Battle::
# 76 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 77 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_ParasolLady_Battle_3
# 80 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_ParasolLady_Battle_4
# 83 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_ParasolLady_Battle_5
Route4_EventScript_ParasolLady_Battle_1:
# 87 "data/maps/Route4/scripts.pory"
	release
	end

Route4_EventScript_ParasolLady_Battle_3:
# 78 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_PARASOL_LADY_CARMEM, Route4_EventScript_ParasolLady_Battle_Text_0, Route4_EventScript_ParasolLady_Battle_Text_1
# 79 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_ParasolLady_Battle_Text_2
	goto Route4_EventScript_ParasolLady_Battle_1

Route4_EventScript_ParasolLady_Battle_4:
# 81 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_PARASOL_LADY_CARMEM, Route4_EventScript_ParasolLady_Battle_Text_3, Route4_EventScript_ParasolLady_Battle_Text_4
# 82 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_ParasolLady_Battle_Text_5
	goto Route4_EventScript_ParasolLady_Battle_1

Route4_EventScript_ParasolLady_Battle_5:
# 84 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_PARASOL_LADY_CARMEM, Route4_EventScript_ParasolLady_Battle_Text_6, Route4_EventScript_ParasolLady_Battle_Text_7
# 85 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_ParasolLady_Battle_Text_8
	goto Route4_EventScript_ParasolLady_Battle_1


Route4_EventScript_TM_IceFang_Get::
# 92 "data/maps/Route4/scripts.pory"
	finditem ITEM_TM_ICE_FANG
	end


Route4_EventScript_SuperPotion_Get::
# 97 "data/maps/Route4/scripts.pory"
	finditem ITEM_SUPER_POTION
	end


Route4_EventScript_Revive_Get::
# 102 "data/maps/Route4/scripts.pory"
	finditem ITEM_REVIVE
	end


Route4_EventScript_NetBall_Get::
# 107 "data/maps/Route4/scripts.pory"
	finditem ITEM_NET_BALL
	end


Route4_EventScript_Youngster_Battle::
# 112 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 113 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_Youngster_Battle_3
# 116 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_Youngster_Battle_4
# 119 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_Youngster_Battle_5
Route4_EventScript_Youngster_Battle_1:
	end

Route4_EventScript_Youngster_Battle_3:
# 114 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_RENAN, Route4_EventScript_Youngster_Battle_Text_0, Route4_EventScript_Youngster_Battle_Text_1
# 115 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_Youngster_Battle_Text_2, MSGBOX_NPC
	goto Route4_EventScript_Youngster_Battle_1

Route4_EventScript_Youngster_Battle_4:
# 117 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_RENAN, Route4_EventScript_Youngster_Battle_Text_3, Route4_EventScript_Youngster_Battle_Text_4
# 118 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_Youngster_Battle_Text_5, MSGBOX_NPC
	goto Route4_EventScript_Youngster_Battle_1

Route4_EventScript_Youngster_Battle_5:
# 120 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_RENAN, Route4_EventScript_Youngster_Battle_Text_6, Route4_EventScript_Youngster_Battle_Text_7
# 121 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_Youngster_Battle_Text_8, MSGBOX_NPC
	goto Route4_EventScript_Youngster_Battle_1


Route4_EventScript_PokefanM_Leonel_Battle::
# 127 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 128 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_PokefanM_Leonel_Battle_3
# 131 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_PokefanM_Leonel_Battle_4
# 134 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_PokefanM_Leonel_Battle_5
Route4_EventScript_PokefanM_Leonel_Battle_1:
# 138 "data/maps/Route4/scripts.pory"
	release
	end

Route4_EventScript_PokefanM_Leonel_Battle_3:
# 129 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_POKEFAN_M_LEONEL, Route4_EventScript_PokefanM_Leonel_Battle_Text_0, Route4_EventScript_PokefanM_Leonel_Battle_Text_1
# 130 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_PokefanM_Leonel_Battle_Text_2, MSGBOX_NPC
	goto Route4_EventScript_PokefanM_Leonel_Battle_1

Route4_EventScript_PokefanM_Leonel_Battle_4:
# 132 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_POKEFAN_M_LEONEL, Route4_EventScript_PokefanM_Leonel_Battle_Text_3, Route4_EventScript_PokefanM_Leonel_Battle_Text_4
# 133 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_PokefanM_Leonel_Battle_Text_5, MSGBOX_NPC
	goto Route4_EventScript_PokefanM_Leonel_Battle_1

Route4_EventScript_PokefanM_Leonel_Battle_5:
# 135 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_POKEFAN_M_LEONEL, Route4_EventScript_PokefanM_Leonel_Battle_Text_6, Route4_EventScript_PokefanM_Leonel_Battle_Text_7
# 136 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_PokefanM_Leonel_Battle_Text_8, MSGBOX_NPC
	goto Route4_EventScript_PokefanM_Leonel_Battle_1


Route4_EventScript_BugCatcher_Romeu_Battle::
# 143 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 144 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_BugCatcher_Romeu_Battle_3
# 147 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_BugCatcher_Romeu_Battle_4
# 150 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_BugCatcher_Romeu_Battle_5
Route4_EventScript_BugCatcher_Romeu_Battle_1:
# 154 "data/maps/Route4/scripts.pory"
	release
	end

Route4_EventScript_BugCatcher_Romeu_Battle_3:
# 145 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_ROMEU, Route4_EventScript_BugCatcher_Romeu_Battle_Text_0, Route4_EventScript_BugCatcher_Romeu_Battle_Text_1
# 146 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BugCatcher_Romeu_Battle_Text_2, MSGBOX_NPC
	goto Route4_EventScript_BugCatcher_Romeu_Battle_1

Route4_EventScript_BugCatcher_Romeu_Battle_4:
# 148 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_ROMEU, Route4_EventScript_BugCatcher_Romeu_Battle_Text_3, Route4_EventScript_BugCatcher_Romeu_Battle_Text_4
# 149 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BugCatcher_Romeu_Battle_Text_5, MSGBOX_NPC
	goto Route4_EventScript_BugCatcher_Romeu_Battle_1

Route4_EventScript_BugCatcher_Romeu_Battle_5:
# 151 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_ROMEU, Route4_EventScript_BugCatcher_Romeu_Battle_Text_6, Route4_EventScript_BugCatcher_Romeu_Battle_Text_7
# 152 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BugCatcher_Romeu_Battle_Text_8, MSGBOX_NPC
	goto Route4_EventScript_BugCatcher_Romeu_Battle_1


Route4_EventScript_Lass::
# 159 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 160 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_Lass_3
# 161 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_Lass_4
# 162 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_Lass_5
Route4_EventScript_Lass_1:
	end

Route4_EventScript_Lass_3:
# 160 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_Lass_Text_0, MSGBOX_NPC
	goto Route4_EventScript_Lass_1

Route4_EventScript_Lass_4:
# 161 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_Lass_Text_1, MSGBOX_NPC
	goto Route4_EventScript_Lass_1

Route4_EventScript_Lass_5:
# 162 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_Lass_Text_2, MSGBOX_NPC
	goto Route4_EventScript_Lass_1


Route4_EventScript_ExpertF_StrangePokemon::
# 168 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 169 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_ExpertF_StrangePokemon_3
# 170 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_ExpertF_StrangePokemon_4
# 171 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_ExpertF_StrangePokemon_5
Route4_EventScript_ExpertF_StrangePokemon_1:
	end

Route4_EventScript_ExpertF_StrangePokemon_3:
# 169 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_ExpertF_StrangePokemon_Text_0, MSGBOX_NPC
	goto Route4_EventScript_ExpertF_StrangePokemon_1

Route4_EventScript_ExpertF_StrangePokemon_4:
# 170 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_ExpertF_StrangePokemon_Text_1, MSGBOX_NPC
	goto Route4_EventScript_ExpertF_StrangePokemon_1

Route4_EventScript_ExpertF_StrangePokemon_5:
# 171 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_ExpertF_StrangePokemon_Text_2, MSGBOX_NPC
	goto Route4_EventScript_ExpertF_StrangePokemon_1


Route4_EventScript_BirdKeeper_Challenge::
# 180 "data/maps/Route4/scripts.pory"
	lockall
# 181 "data/maps/Route4/scripts.pory"
	faceplayer
# 183 "data/maps/Route4/scripts.pory"
	goto_if_set FLAG_ROUTE4_BIRD_KEEPER_CHALLENGE_DONE, Route4_EventScript_BirdKeeper_Challenge_2
# 193 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 194 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_BirdKeeper_Challenge_6
# 195 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_BirdKeeper_Challenge_7
# 196 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_BirdKeeper_Challenge_8
Route4_EventScript_BirdKeeper_Challenge_4:
# 198 "data/maps/Route4/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq Route4_EventScript_BirdKeeper_Challenge_15
# 208 "data/maps/Route4/scripts.pory"
	checkitemspace ITEM_STARAPTITE
# 209 "data/maps/Route4/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Route4_EventScript_BirdKeeper_Challenge_18
# 219 "data/maps/Route4/scripts.pory"
	hidefollower 1
# 220 "data/maps/Route4/scripts.pory"
	setobjectxy LOCALID_PLAYER, 46, 27
# 221 "data/maps/Route4/scripts.pory"
	movenpc LOCALID_ROUTE4_BIRD_KEEPER, Route4_EventScript_BirdKeeper_Challenge_Movement_0
# 222 "data/maps/Route4/scripts.pory"
	moveplayer Route4_EventScript_BirdKeeper_Challenge_Movement_1
# 223 "data/maps/Route4/scripts.pory"
	pause 20
# 225 "data/maps/Route4/scripts.pory"
	createspobject OBJ_EVENT_GFX_SPECIES ( SQUAWKABILLY ), 16, 46, 24, MOVEMENT_TYPE_FACE_DOWN
# 226 "data/maps/Route4/scripts.pory"
	callnative GetFirstPartyMonGraphicsId
# 227 "data/maps/Route4/scripts.pory"
	createspobject VAR_0x8000, 17, 46, 25, MOVEMENT_TYPE_FACE_UP
# 228 "data/maps/Route4/scripts.pory"
	movenpc 16, Route4_EventScript_BirdKeeper_Challenge_Movement_2
# 229 "data/maps/Route4/scripts.pory"
	movenpc 17, Route4_EventScript_BirdKeeper_Challenge_Movement_3
# 230 "data/maps/Route4/scripts.pory"
	pause 20
# 232 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 233 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_BirdKeeper_Challenge_27
# 234 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_BirdKeeper_Challenge_28
# 235 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_BirdKeeper_Challenge_29
Route4_EventScript_BirdKeeper_Challenge_25:
# 237 "data/maps/Route4/scripts.pory"
	releaseall
	end

Route4_EventScript_BirdKeeper_Challenge_2:
# 184 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 185 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_BirdKeeper_Challenge_11
# 186 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_BirdKeeper_Challenge_12
# 187 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_BirdKeeper_Challenge_13
Route4_EventScript_BirdKeeper_Challenge_9:
# 189 "data/maps/Route4/scripts.pory"
	releaseall
	end

Route4_EventScript_BirdKeeper_Challenge_6:
# 194 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_3, MSGBOX_YESNO
	goto Route4_EventScript_BirdKeeper_Challenge_4

Route4_EventScript_BirdKeeper_Challenge_7:
# 195 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_4, MSGBOX_YESNO
	goto Route4_EventScript_BirdKeeper_Challenge_4

Route4_EventScript_BirdKeeper_Challenge_8:
# 196 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_5, MSGBOX_YESNO
	goto Route4_EventScript_BirdKeeper_Challenge_4

Route4_EventScript_BirdKeeper_Challenge_11:
# 185 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_0, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Challenge_9

Route4_EventScript_BirdKeeper_Challenge_12:
# 186 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_1, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Challenge_9

Route4_EventScript_BirdKeeper_Challenge_13:
# 187 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_2, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Challenge_9

Route4_EventScript_BirdKeeper_Challenge_15:
# 199 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 200 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_BirdKeeper_Challenge_22
# 201 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_BirdKeeper_Challenge_23
# 202 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_BirdKeeper_Challenge_24
Route4_EventScript_BirdKeeper_Challenge_20:
# 204 "data/maps/Route4/scripts.pory"
	releaseall
	end

Route4_EventScript_BirdKeeper_Challenge_18:
# 210 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 211 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_BirdKeeper_Challenge_32
# 212 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_BirdKeeper_Challenge_33
# 213 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_BirdKeeper_Challenge_34
Route4_EventScript_BirdKeeper_Challenge_30:
# 215 "data/maps/Route4/scripts.pory"
	releaseall
	end

Route4_EventScript_BirdKeeper_Challenge_22:
# 200 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_6, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Challenge_20

Route4_EventScript_BirdKeeper_Challenge_23:
# 201 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_7, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Challenge_20

Route4_EventScript_BirdKeeper_Challenge_24:
# 202 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_8, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Challenge_20

Route4_EventScript_BirdKeeper_Challenge_27:
# 233 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_BIRD_KEEPER_LOHAN, Route4_EventScript_BirdKeeper_Challenge_Text_12, Route4_EventScript_BirdKeeper_Challenge_Text_13, Route4_EventScript_BirdKeeper_Victory
	goto Route4_EventScript_BirdKeeper_Challenge_25

Route4_EventScript_BirdKeeper_Challenge_28:
# 234 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_BIRD_KEEPER_LOHAN, Route4_EventScript_BirdKeeper_Challenge_Text_14, Route4_EventScript_BirdKeeper_Challenge_Text_15, Route4_EventScript_BirdKeeper_Victory
	goto Route4_EventScript_BirdKeeper_Challenge_25

Route4_EventScript_BirdKeeper_Challenge_29:
# 235 "data/maps/Route4/scripts.pory"
	trainerbattle_single TRAINER_BIRD_KEEPER_LOHAN, Route4_EventScript_BirdKeeper_Challenge_Text_16, Route4_EventScript_BirdKeeper_Challenge_Text_17, Route4_EventScript_BirdKeeper_Victory
	goto Route4_EventScript_BirdKeeper_Challenge_25

Route4_EventScript_BirdKeeper_Challenge_32:
# 211 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_9, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Challenge_30

Route4_EventScript_BirdKeeper_Challenge_33:
# 212 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_10, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Challenge_30

Route4_EventScript_BirdKeeper_Challenge_34:
# 213 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Challenge_Text_11, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Challenge_30


Route4_EventScript_BirdKeeper_Victory::
# 242 "data/maps/Route4/scripts.pory"
	applymovement 16, Route4_EventScript_BirdKeeper_Victory_Movement_0
# 243 "data/maps/Route4/scripts.pory"
	applymovement 17, Route4_EventScript_BirdKeeper_Victory_Movement_0
# 244 "data/maps/Route4/scripts.pory"
	waitmovementall
# 245 "data/maps/Route4/scripts.pory"
	removeobject 16
# 246 "data/maps/Route4/scripts.pory"
	removeobject 17
# 247 "data/maps/Route4/scripts.pory"
	callnative UpdateFollowingPokemon
# 249 "data/maps/Route4/scripts.pory"
	movenpc LOCALID_ROUTE4_BIRD_KEEPER, Route4_EventScript_AbsolSymbol_Movement_0
# 250 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 251 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_BirdKeeper_Victory_3
# 252 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_BirdKeeper_Victory_4
# 253 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_BirdKeeper_Victory_5
Route4_EventScript_BirdKeeper_Victory_1:
# 255 "data/maps/Route4/scripts.pory"
	giveitem ITEM_STARAPTITE
# 256 "data/maps/Route4/scripts.pory"
	setflag FLAG_ROUTE4_BIRD_KEEPER_CHALLENGE_DONE
# 257 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 258 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_BirdKeeper_Victory_8
# 259 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_BirdKeeper_Victory_9
# 260 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_BirdKeeper_Victory_10
Route4_EventScript_BirdKeeper_Victory_6:
# 262 "data/maps/Route4/scripts.pory"
	releaseall
	end

Route4_EventScript_BirdKeeper_Victory_3:
# 251 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Victory_Text_0, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Victory_1

Route4_EventScript_BirdKeeper_Victory_4:
# 252 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Victory_Text_1, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Victory_1

Route4_EventScript_BirdKeeper_Victory_5:
# 253 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Victory_Text_2, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Victory_1

Route4_EventScript_BirdKeeper_Victory_8:
# 258 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Victory_Text_3, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Victory_6

Route4_EventScript_BirdKeeper_Victory_9:
# 259 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Victory_Text_4, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Victory_6

Route4_EventScript_BirdKeeper_Victory_10:
# 260 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_BirdKeeper_Victory_Text_5, MSGBOX_DEFAULT
	goto Route4_EventScript_BirdKeeper_Victory_6


Route4_EventScript_FatMan::
# 267 "data/maps/Route4/scripts.pory"
	switch VAR_LANGUAGE
# 268 "data/maps/Route4/scripts.pory"
	case PT, Route4_EventScript_FatMan_3
# 269 "data/maps/Route4/scripts.pory"
	case EN, Route4_EventScript_FatMan_4
# 270 "data/maps/Route4/scripts.pory"
	case ES, Route4_EventScript_FatMan_5
Route4_EventScript_FatMan_1:
	end

Route4_EventScript_FatMan_3:
# 268 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_FatMan_Text_0, MSGBOX_NPC
	goto Route4_EventScript_FatMan_1

Route4_EventScript_FatMan_4:
# 269 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_FatMan_Text_1, MSGBOX_NPC
	goto Route4_EventScript_FatMan_1

Route4_EventScript_FatMan_5:
# 270 "data/maps/Route4/scripts.pory"
	msgbox Route4_EventScript_FatMan_Text_2, MSGBOX_NPC
	goto Route4_EventScript_FatMan_1


# 22 "data/maps/Route4/scripts.pory"
Route4_EventScript_AbsolSymbol_Movement_0:
# 22 "data/maps/Route4/scripts.pory"
	walk_down
# 22 "data/maps/Route4/scripts.pory"
	walk_down
# 22 "data/maps/Route4/scripts.pory"
	face_down
	step_end

# 24 "data/maps/Route4/scripts.pory"
Route4_EventScript_AbsolSymbol_Movement_1:
# 24 "data/maps/Route4/scripts.pory"
	walk_down
	step_end

# 25 "data/maps/Route4/scripts.pory"
Route4_EventScript_AbsolSymbol_Movement_2:
# 25 "data/maps/Route4/scripts.pory"
	face_right
	step_end

# 36 "data/maps/Route4/scripts.pory"
Route4_EventScript_AbsolSymbol_Movement_3:
# 36 "data/maps/Route4/scripts.pory"
	face_up
# 36 "data/maps/Route4/scripts.pory"
	delay_8
# 36 "data/maps/Route4/scripts.pory"
	face_down
# 36 "data/maps/Route4/scripts.pory"
	delay_8
# 36 "data/maps/Route4/scripts.pory"
	face_right
	step_end

# 50 "data/maps/Route4/scripts.pory"
Route4_EventScript_AbsolSymbol_Movement_4:
# 50 "data/maps/Route4/scripts.pory"
	emote_exclamation_mark
# 50 "data/maps/Route4/scripts.pory"
	walk_fast_left
	step_end

# 55 "data/maps/Route4/scripts.pory"
Route4_EventScript_AbsolSymbol_Movement_5:
# 55 "data/maps/Route4/scripts.pory"
	face_up
# 55 "data/maps/Route4/scripts.pory"
	delay_16
	step_end

# 57 "data/maps/Route4/scripts.pory"
Route4_EventScript_AbsolSymbol_Movement_6:
# 57 "data/maps/Route4/scripts.pory"
	walk_fast_left
# 57 "data/maps/Route4/scripts.pory"
	walk_fast_left
# 57 "data/maps/Route4/scripts.pory"
	walk_fast_left
# 57 "data/maps/Route4/scripts.pory"
	walk_fast_left
# 57 "data/maps/Route4/scripts.pory"
	walk_fast_left
# 57 "data/maps/Route4/scripts.pory"
	walk_fast_left
# 57 "data/maps/Route4/scripts.pory"
	walk_fast_left
# 57 "data/maps/Route4/scripts.pory"
	walk_fast_left
	step_end

# 69 "data/maps/Route4/scripts.pory"
Route4_EventScript_AbsolSymbol_Movement_7:
# 69 "data/maps/Route4/scripts.pory"
	walk_up
	step_end

# 221 "data/maps/Route4/scripts.pory"
Route4_EventScript_BirdKeeper_Challenge_Movement_0:
# 221 "data/maps/Route4/scripts.pory"
	walk_left
# 221 "data/maps/Route4/scripts.pory"
	walk_left
# 221 "data/maps/Route4/scripts.pory"
	walk_up
# 221 "data/maps/Route4/scripts.pory"
	face_down
	step_end

# 222 "data/maps/Route4/scripts.pory"
Route4_EventScript_BirdKeeper_Challenge_Movement_1:
# 222 "data/maps/Route4/scripts.pory"
	walk_up
# 222 "data/maps/Route4/scripts.pory"
	face_up
	step_end

# 228 "data/maps/Route4/scripts.pory"
Route4_EventScript_BirdKeeper_Challenge_Movement_2:
# 228 "data/maps/Route4/scripts.pory"
	exit_pokeball
# 228 "data/maps/Route4/scripts.pory"
	face_down
	step_end

# 229 "data/maps/Route4/scripts.pory"
Route4_EventScript_BirdKeeper_Challenge_Movement_3:
# 229 "data/maps/Route4/scripts.pory"
	exit_pokeball
# 229 "data/maps/Route4/scripts.pory"
	face_up
	step_end

# 242 "data/maps/Route4/scripts.pory"
Route4_EventScript_BirdKeeper_Victory_Movement_0:
# 242 "data/maps/Route4/scripts.pory"
	enter_pokeball
	step_end

Route4_EventScript_Sign_Text_0:
# 5 "data/maps/Route4/scripts.pory"
	.string "Rota 4\nCidade Stonereach {UP_ARROW_2}\lSantuário Verdante {DOWN_ARROW}$"

Route4_EventScript_Sign_Text_1:
# 6 "data/maps/Route4/scripts.pory"
	.string "Route 4\nStonereach City {UP_ARROW_2}\lVerdant Sanctum {DOWN_ARROW}$"

Route4_EventScript_Sign_Text_2:
# 7 "data/maps/Route4/scripts.pory"
	.string "Ruta 4\nCiudad Stonereach {UP_ARROW_2}\lSantuário Verdante {DOWN_ARROW}$"

Route4_EventScript_AbsolSymbol_Text_0:
# 29 "data/maps/Route4/scripts.pory"
	.string "Absol parece estar observando\nalguma coisa...$"

Route4_EventScript_AbsolSymbol_Text_1:
# 30 "data/maps/Route4/scripts.pory"
	.string "Absol seems to be watching\nsomething...$"

Route4_EventScript_AbsolSymbol_Text_2:
# 31 "data/maps/Route4/scripts.pory"
	.string "Absol parece estar observando\nalgo...$"

Route4_EventScript_AbsolSymbol_Text_3:
# 62 "data/maps/Route4/scripts.pory"
	.string "...$"

Route4_EventScript_AbsolSymbol_Text_4:
# 64 "data/maps/Route4/scripts.pory"
	.string "Não há nada ali.$"

Route4_EventScript_AbsolSymbol_Text_5:
# 65 "data/maps/Route4/scripts.pory"
	.string "There's nothing there.$"

Route4_EventScript_AbsolSymbol_Text_6:
# 66 "data/maps/Route4/scripts.pory"
	.string "No hay nada ahí.$"

Route4_EventScript_ParasolLady_Battle_Text_0:
# 78 "data/maps/Route4/scripts.pory"
	.string "Não há uma nuvem no céu…\pMas meu Wingull pode resolver isso!$"

Route4_EventScript_ParasolLady_Battle_Text_1:
# 78 "data/maps/Route4/scripts.pory"
	.string "A tempestade passou tão rápido…$"

Route4_EventScript_ParasolLady_Battle_Text_2:
# 79 "data/maps/Route4/scripts.pory"
	.string "Chuva ou sol, meu Wingull sempre\nestará pronto para voar!$"

Route4_EventScript_ParasolLady_Battle_Text_3:
# 81 "data/maps/Route4/scripts.pory"
	.string "There isn't a cloud in the sky…\pBut my Wingull can fix that!$"

Route4_EventScript_ParasolLady_Battle_Text_4:
# 81 "data/maps/Route4/scripts.pory"
	.string "That storm passed so quickly…$"

Route4_EventScript_ParasolLady_Battle_Text_5:
# 82 "data/maps/Route4/scripts.pory"
	.string "Rain or shine, my Wingull will\nalways be ready to fly!$"

Route4_EventScript_ParasolLady_Battle_Text_6:
# 84 "data/maps/Route4/scripts.pory"
	.string "No hay ni una nube en el cielo…\p¡Pero mi Wingull puede arreglarlo!$"

Route4_EventScript_ParasolLady_Battle_Text_7:
# 84 "data/maps/Route4/scripts.pory"
	.string "La tormenta pasó muy rápido…$"

Route4_EventScript_ParasolLady_Battle_Text_8:
# 85 "data/maps/Route4/scripts.pory"
	.string "¡Llueva o haga sol, mi Wingull\nsiempre estará listo para volar!$"

Route4_EventScript_Youngster_Battle_Text_0:
# 114 "data/maps/Route4/scripts.pory"
	.string "Meu Lillipup farejou um adversário!\pO problema é que ele também fareja\nqualquer lanche…$"

Route4_EventScript_Youngster_Battle_Text_1:
# 114 "data/maps/Route4/scripts.pory"
	.string "Acho que ele estava pensando no\nlanche…$"

Route4_EventScript_Youngster_Battle_Text_2:
# 115 "data/maps/Route4/scripts.pory"
	.string "Vou treinar o faro dele.\pPrimeiro para batalhas, depois para\nachar minha merenda!$"

Route4_EventScript_Youngster_Battle_Text_3:
# 117 "data/maps/Route4/scripts.pory"
	.string "My Lillipup sniffed out an opponent!\pThe problem is, he also sniffs out\nevery snack…$"

Route4_EventScript_Youngster_Battle_Text_4:
# 117 "data/maps/Route4/scripts.pory"
	.string "I think he was thinking about the\nsnack…$"

Route4_EventScript_Youngster_Battle_Text_5:
# 118 "data/maps/Route4/scripts.pory"
	.string "I'll train his sense of smell.\pBattles first, then finding my\nlunch!$"

Route4_EventScript_Youngster_Battle_Text_6:
# 120 "data/maps/Route4/scripts.pory"
	.string "¡Mi Lillipup olfateó a un rival!\pEl problema es que también olfatea\ncualquier bocadillo…$"

Route4_EventScript_Youngster_Battle_Text_7:
# 120 "data/maps/Route4/scripts.pory"
	.string "Creo que estaba pensando en el\nbocadillo…$"

Route4_EventScript_Youngster_Battle_Text_8:
# 121 "data/maps/Route4/scripts.pory"
	.string "Entrenaré su olfato.\pPrimero para combatir, ¡y luego para\nencontrar mi merienda!$"

Route4_EventScript_PokefanM_Leonel_Battle_Text_0:
# 129 "data/maps/Route4/scripts.pory"
	.string "Meus pequenos parceiros estão\ncheios de energia!\pVamos mostrar do que somos capazes!$"

Route4_EventScript_PokefanM_Leonel_Battle_Text_1:
# 129 "data/maps/Route4/scripts.pory"
	.string "Vocês foram incríveis, meus\nqueridos!$"

Route4_EventScript_PokefanM_Leonel_Battle_Text_2:
# 130 "data/maps/Route4/scripts.pory"
	.string "Marill e Pachirisu podem parecer\nfofinhos, mas levam as batalhas\lmuito a sério!$"

Route4_EventScript_PokefanM_Leonel_Battle_Text_3:
# 132 "data/maps/Route4/scripts.pory"
	.string "My little partners are bursting\nwith energy!\pLet's show you what we can do!$"

Route4_EventScript_PokefanM_Leonel_Battle_Text_4:
# 132 "data/maps/Route4/scripts.pory"
	.string "You were wonderful, my\ndarlings!$"

Route4_EventScript_PokefanM_Leonel_Battle_Text_5:
# 133 "data/maps/Route4/scripts.pory"
	.string "Marill and Pachirisu may look cute,\nbut they take battling very\lseriously!$"

Route4_EventScript_PokefanM_Leonel_Battle_Text_6:
# 135 "data/maps/Route4/scripts.pory"
	.string "¡Mis pequeños compañeros están\nllenos de energía!\p¡Mostremos lo que sabemos hacer!$"

Route4_EventScript_PokefanM_Leonel_Battle_Text_7:
# 135 "data/maps/Route4/scripts.pory"
	.string "¡Estuvieron increíbles, mis\npequeños!$"

Route4_EventScript_PokefanM_Leonel_Battle_Text_8:
# 136 "data/maps/Route4/scripts.pory"
	.string "Marill y Pachirisu pueden parecer\nadorables, ¡pero se toman los\lcombates muy en serio!$"

Route4_EventScript_BugCatcher_Romeu_Battle_Text_0:
# 145 "data/maps/Route4/scripts.pory"
	.string "Encontrei insetos de todos os tipos\npor esta rota!\pQuer ver os melhores?$"

Route4_EventScript_BugCatcher_Romeu_Battle_Text_1:
# 145 "data/maps/Route4/scripts.pory"
	.string "Minha coleção ainda precisa de\ntreinamento...$"

Route4_EventScript_BugCatcher_Romeu_Battle_Text_2:
# 146 "data/maps/Route4/scripts.pory"
	.string "Cada inseto tem um jeito diferente\nde lutar.\pÉ isso que torna treiná-los tão\ldivertido!$"

Route4_EventScript_BugCatcher_Romeu_Battle_Text_3:
# 148 "data/maps/Route4/scripts.pory"
	.string "I found all kinds of bugs along\nthis route!\pWant to see the best ones?$"

Route4_EventScript_BugCatcher_Romeu_Battle_Text_4:
# 148 "data/maps/Route4/scripts.pory"
	.string "My collection still needs more\ntraining...$"

Route4_EventScript_BugCatcher_Romeu_Battle_Text_5:
# 149 "data/maps/Route4/scripts.pory"
	.string "Every bug has a different way of\nbattling.\pThat's what makes training them so\lmuch fun!$"

Route4_EventScript_BugCatcher_Romeu_Battle_Text_6:
# 151 "data/maps/Route4/scripts.pory"
	.string "¡Encontré insectos de todo tipo\npor esta ruta!\p¿Quieres ver los mejores?$"

Route4_EventScript_BugCatcher_Romeu_Battle_Text_7:
# 151 "data/maps/Route4/scripts.pory"
	.string "Mi colección aún necesita más\nentrenamiento...$"

Route4_EventScript_BugCatcher_Romeu_Battle_Text_8:
# 152 "data/maps/Route4/scripts.pory"
	.string "Cada insecto tiene una forma\ndiferente de combatir.\p¡Por eso entrenarlos es tan\ldivertido!$"

Route4_EventScript_Lass_Text_0:
# 160 "data/maps/Route4/scripts.pory"
	.string "Dizem que mulheres treinadoras fazem\nmil coisas ao mesmo tempo.\pEu planejo a rota, cuido da equipe\ne esqueço onde guardei a Poké Bola…\ltudo em dez segundos!$"

Route4_EventScript_Lass_Text_1:
# 161 "data/maps/Route4/scripts.pory"
	.string "They say women Trainers can do a\nthousand things at once.\pI plan the route, care for my team,\nand forget where I put my Poké Ball…\lall in ten seconds!$"

Route4_EventScript_Lass_Text_2:
# 162 "data/maps/Route4/scripts.pory"
	.string "Dicen que las Entrenadoras hacemos\nmil cosas a la vez.\pPlaneo la ruta, cuido del equipo y\nolvido dónde guardé la Poké Ball…\l¡todo en diez segundos!$"

Route4_EventScript_ExpertF_StrangePokemon_Text_0:
# 169 "data/maps/Route4/scripts.pory"
	.string "Há dias os Pokémon desta rota\nestão muito estranhos...\pAté minha Roselia parou de brincar.\nEla só encara o caminho ao sul,\lcomo se algo a chamasse de longe.\pSe for seguir até o Santuário\nVerdante, mantenha seus Pokémon\lpor perto.$"

Route4_EventScript_ExpertF_StrangePokemon_Text_1:
# 170 "data/maps/Route4/scripts.pory"
	.string "The Pokémon along this route have\nbeen acting strangely for days...\pEven my Roselia stopped playing.\nShe only stares at the path south,\las if something were calling her.\pIf you're heading to Verdant\nSanctum, keep your Pokémon close.$"

Route4_EventScript_ExpertF_StrangePokemon_Text_2:
# 171 "data/maps/Route4/scripts.pory"
	.string "Hace días que los Pokémon de esta\nruta se comportan de forma extraña...\pHasta mi Roselia dejó de jugar.\nSolo mira el camino hacia el sur,\lcomo si algo la estuviera llamando.\pSi vas al Santuario Verdante,\nmantén cerca a tus Pokémon.$"

Route4_EventScript_BirdKeeper_Challenge_Text_0:
# 185 "data/maps/Route4/scripts.pory"
	.string "A arena ainda se lembra da sua\nvitória!\pContinue voando alto, campeão!$"

Route4_EventScript_BirdKeeper_Challenge_Text_1:
# 186 "data/maps/Route4/scripts.pory"
	.string "The arena still remembers your\nvictory!\pKeep flying high, Champion!$"

Route4_EventScript_BirdKeeper_Challenge_Text_2:
# 187 "data/maps/Route4/scripts.pory"
	.string "¡La arena aún recuerda tu victoria!\p¡Sigue volando alto, Campeón!$"

Route4_EventScript_BirdKeeper_Challenge_Text_3:
# 194 "data/maps/Route4/scripts.pory"
	.string "Bem-vindo à minha pequena arena!\pMeu Squawkabilly e eu desafiamos\ntreinadores que não têm medo de\lvoar alto.\pQuer aceitar o desafio?\nHá um prêmio para quem vencer!$"

Route4_EventScript_BirdKeeper_Challenge_Text_4:
# 195 "data/maps/Route4/scripts.pory"
	.string "Welcome to my little arena!\pMy Squawkabilly and I challenge\nTrainers who aren't afraid to\lfly high.\pWill you accept the challenge?\nThere's a prize if you win!$"

Route4_EventScript_BirdKeeper_Challenge_Text_5:
# 196 "data/maps/Route4/scripts.pory"
	.string "¡Bienvenido a mi pequeña arena!\pMi Squawkabilly y yo desafiamos a\nEntrenadores que no temen volar\lalto.\p¿Aceptas el desafío?\n¡Hay un premio si ganas!$"

Route4_EventScript_BirdKeeper_Challenge_Text_6:
# 200 "data/maps/Route4/scripts.pory"
	.string "Sem problema! Até os melhores\npássaros esperam o vento certo.$"

Route4_EventScript_BirdKeeper_Challenge_Text_7:
# 201 "data/maps/Route4/scripts.pory"
	.string "No problem! Even the best birds\nwait for the right wind.$"

Route4_EventScript_BirdKeeper_Challenge_Text_8:
# 202 "data/maps/Route4/scripts.pory"
	.string "¡No hay problema! Hasta las mejores\naves voladoras esperan el viento\ladecuado.$"

Route4_EventScript_BirdKeeper_Challenge_Text_9:
# 211 "data/maps/Route4/scripts.pory"
	.string "Sua Bolsa está cheia.\pAbra espaço para o prêmio e volte\npara aceitar o desafio!$"

Route4_EventScript_BirdKeeper_Challenge_Text_10:
# 212 "data/maps/Route4/scripts.pory"
	.string "Your Bag is full.\pMake room for the prize, then come\nback to accept the challenge!$"

Route4_EventScript_BirdKeeper_Challenge_Text_11:
# 213 "data/maps/Route4/scripts.pory"
	.string "Tu Bolsa está llena.\p¡Haz espacio para el premio y vuelve\npara aceptar el desafío!$"

Route4_EventScript_BirdKeeper_Challenge_Text_12:
# 233 "data/maps/Route4/scripts.pory"
	.string "As asas estão abertas.\nQue comece o desafio!$"

Route4_EventScript_BirdKeeper_Challenge_Text_13:
# 233 "data/maps/Route4/scripts.pory"
	.string "Você dominou os céus!$"

Route4_EventScript_BirdKeeper_Challenge_Text_14:
# 234 "data/maps/Route4/scripts.pory"
	.string "Our wings are spread.\nLet the challenge begin!$"

Route4_EventScript_BirdKeeper_Challenge_Text_15:
# 234 "data/maps/Route4/scripts.pory"
	.string "You ruled the skies!$"

Route4_EventScript_BirdKeeper_Challenge_Text_16:
# 235 "data/maps/Route4/scripts.pory"
	.string "Las alas están abiertas.\n¡Que comience el desafío!$"

Route4_EventScript_BirdKeeper_Challenge_Text_17:
# 235 "data/maps/Route4/scripts.pory"
	.string "¡Dominaste los cielos!$"

Route4_EventScript_BirdKeeper_Victory_Text_0:
# 251 "data/maps/Route4/scripts.pory"
	.string "Parabéns! Você e seu Pokémon\nformam uma dupla de primeira.\pComo prometido, este é o seu prêmio!$"

Route4_EventScript_BirdKeeper_Victory_Text_1:
# 252 "data/maps/Route4/scripts.pory"
	.string "Congratulations! You and your\nPokémon make a first-class team.\pAs promised, here's your prize!$"

Route4_EventScript_BirdKeeper_Victory_Text_2:
# 253 "data/maps/Route4/scripts.pory"
	.string "¡Felicidades! Tú y tu Pokémon\nforman un equipo de primera.\pComo prometí, ¡aquí está tu premio!$"

Route4_EventScript_BirdKeeper_Victory_Text_3:
# 258 "data/maps/Route4/scripts.pory"
	.string "A Staraptite pertence a alguém que\nsabe alcançar novas alturas.\pNos vemos por aí, campeão!$"

Route4_EventScript_BirdKeeper_Victory_Text_4:
# 259 "data/maps/Route4/scripts.pory"
	.string "The Staraptite belongs with someone\nwho can reach new heights.\pSee you around, Champion!$"

Route4_EventScript_BirdKeeper_Victory_Text_5:
# 260 "data/maps/Route4/scripts.pory"
	.string "La Staraptita pertenece a quien sabe\nalcanzar nuevas alturas.\p¡Nos vemos, Campeón!$"

Route4_EventScript_FatMan_Text_0:
# 268 "data/maps/Route4/scripts.pory"
	.string "Você sabia que Snorlax pode pesar\nmais de 450 quilos?\pEu também fico imóvel depois do\nalmoço, mas ninguém me chama de\lPokémon raro!$"

Route4_EventScript_FatMan_Text_1:
# 269 "data/maps/Route4/scripts.pory"
	.string "Did you know Snorlax can weigh over\n450 kilograms?\pI also stop moving after lunch, but\nnobody calls me a rare Pokémon!$"

Route4_EventScript_FatMan_Text_2:
# 270 "data/maps/Route4/scripts.pory"
	.string "¿Sabías que Snorlax puede pesar más\nde 450 kilos?\pYo tampoco me muevo después de\ncomer, ¡pero nadie me llama Pokémon\lraro!$"
