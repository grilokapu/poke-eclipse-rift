MossvaleTown_Mart_MapScripts::
	.byte 0


MossvaleTown_Mart_EventScript_Clerk::
# 6 "data/maps/MossvaleTown_Mart/scripts.pory"
	lock
# 7 "data/maps/MossvaleTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/MossvaleTown_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 9 "data/maps/MossvaleTown_Mart/scripts.pory"
	case PT, MossvaleTown_Mart_EventScript_Clerk_3
# 10 "data/maps/MossvaleTown_Mart/scripts.pory"
	case EN, MossvaleTown_Mart_EventScript_Clerk_4
# 11 "data/maps/MossvaleTown_Mart/scripts.pory"
	case ES, MossvaleTown_Mart_EventScript_Clerk_5
MossvaleTown_Mart_EventScript_Clerk_1:
# 13 "data/maps/MossvaleTown_Mart/scripts.pory"
	waitmessage
# 14 "data/maps/MossvaleTown_Mart/scripts.pory"
	pokemart MossvaleTown_Mart_Pokemart
# 15 "data/maps/MossvaleTown_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 16 "data/maps/MossvaleTown_Mart/scripts.pory"
	case PT, MossvaleTown_Mart_EventScript_Clerk_8
# 17 "data/maps/MossvaleTown_Mart/scripts.pory"
	case EN, MossvaleTown_Mart_EventScript_Clerk_9
# 18 "data/maps/MossvaleTown_Mart/scripts.pory"
	case ES, MossvaleTown_Mart_EventScript_Clerk_10
MossvaleTown_Mart_EventScript_Clerk_6:
# 20 "data/maps/MossvaleTown_Mart/scripts.pory"
	release
	end

MossvaleTown_Mart_EventScript_Clerk_3:
# 9 "data/maps/MossvaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYouPt
	goto MossvaleTown_Mart_EventScript_Clerk_1

MossvaleTown_Mart_EventScript_Clerk_4:
# 10 "data/maps/MossvaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
	goto MossvaleTown_Mart_EventScript_Clerk_1

MossvaleTown_Mart_EventScript_Clerk_5:
# 11 "data/maps/MossvaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYouEs
	goto MossvaleTown_Mart_EventScript_Clerk_1

MossvaleTown_Mart_EventScript_Clerk_8:
# 16 "data/maps/MossvaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgainPt
	goto MossvaleTown_Mart_EventScript_Clerk_6

MossvaleTown_Mart_EventScript_Clerk_9:
# 17 "data/maps/MossvaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain
	goto MossvaleTown_Mart_EventScript_Clerk_6

MossvaleTown_Mart_EventScript_Clerk_10:
# 18 "data/maps/MossvaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgainEs
	goto MossvaleTown_Mart_EventScript_Clerk_6


MossvaleTown_Mart_EventScript_Boy::
# 25 "data/maps/MossvaleTown_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 26 "data/maps/MossvaleTown_Mart/scripts.pory"
	case PT, MossvaleTown_Mart_EventScript_Boy_3
# 27 "data/maps/MossvaleTown_Mart/scripts.pory"
	case EN, MossvaleTown_Mart_EventScript_Boy_4
# 28 "data/maps/MossvaleTown_Mart/scripts.pory"
	case ES, MossvaleTown_Mart_EventScript_Boy_5
MossvaleTown_Mart_EventScript_Boy_1:
	end

MossvaleTown_Mart_EventScript_Boy_3:
# 26 "data/maps/MossvaleTown_Mart/scripts.pory"
	msgbox MossvaleTown_Mart_EventScript_Boy_Text_0, MSGBOX_NPC
	goto MossvaleTown_Mart_EventScript_Boy_1

MossvaleTown_Mart_EventScript_Boy_4:
# 27 "data/maps/MossvaleTown_Mart/scripts.pory"
	msgbox MossvaleTown_Mart_EventScript_Boy_Text_1, MSGBOX_NPC
	goto MossvaleTown_Mart_EventScript_Boy_1

MossvaleTown_Mart_EventScript_Boy_5:
# 28 "data/maps/MossvaleTown_Mart/scripts.pory"
	msgbox MossvaleTown_Mart_EventScript_Boy_Text_2, MSGBOX_NPC
	goto MossvaleTown_Mart_EventScript_Boy_1


MossvaleTown_Mart_EventScript_Woman::
# 34 "data/maps/MossvaleTown_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 35 "data/maps/MossvaleTown_Mart/scripts.pory"
	case PT, MossvaleTown_Mart_EventScript_Woman_3
# 36 "data/maps/MossvaleTown_Mart/scripts.pory"
	case EN, MossvaleTown_Mart_EventScript_Woman_4
# 37 "data/maps/MossvaleTown_Mart/scripts.pory"
	case ES, MossvaleTown_Mart_EventScript_Woman_5
MossvaleTown_Mart_EventScript_Woman_1:
	end

MossvaleTown_Mart_EventScript_Woman_3:
# 35 "data/maps/MossvaleTown_Mart/scripts.pory"
	msgbox MossvaleTown_Mart_EventScript_Woman_Text_0, MSGBOX_NPC
	goto MossvaleTown_Mart_EventScript_Woman_1

MossvaleTown_Mart_EventScript_Woman_4:
# 36 "data/maps/MossvaleTown_Mart/scripts.pory"
	msgbox MossvaleTown_Mart_EventScript_Woman_Text_1, MSGBOX_NPC
	goto MossvaleTown_Mart_EventScript_Woman_1

MossvaleTown_Mart_EventScript_Woman_5:
# 37 "data/maps/MossvaleTown_Mart/scripts.pory"
	msgbox MossvaleTown_Mart_EventScript_Woman_Text_2, MSGBOX_NPC
	goto MossvaleTown_Mart_EventScript_Woman_1


	.align 2
# 42 "data/maps/MossvaleTown_Mart/scripts.pory"
MossvaleTown_Mart_Pokemart:
# 43 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 44 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 45 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_POTION
# 46 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 47 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 48 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 49 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 50 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 51 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 52 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 53 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 54 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 55 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 56 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 57 "data/maps/MossvaleTown_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_NONE

MossvaleTown_Mart_EventScript_Boy_Text_0:
# 26 "data/maps/MossvaleTown_Mart/scripts.pory"
	.string "Vim buscar Great Balls antes\nde explorar Mossvale.\pSe eu encontrar um POKéMON\nnovo entre as folhas, quero\lestar preparado!$"

MossvaleTown_Mart_EventScript_Boy_Text_1:
# 27 "data/maps/MossvaleTown_Mart/scripts.pory"
	.string "I came for Great Balls before\nexploring Mossvale.\pIf I find a new POKéMON\namong the leaves, I want\lto be ready!$"

MossvaleTown_Mart_EventScript_Boy_Text_2:
# 28 "data/maps/MossvaleTown_Mart/scripts.pory"
	.string "Vine por Great Balls antes\nde explorar Mossvale.\pSi encuentro un POKéMON nuevo\nentre las hojas, ¡quiero\lestar preparado!$"

MossvaleTown_Mart_EventScript_Woman_Text_0:
# 35 "data/maps/MossvaleTown_Mart/scripts.pory"
	.string "Eu levo Antidotes e Awakenings\nquando vou caminhar por aqui.\pMeu POKéMON adora enfiar o\nfocinho em cada moita...\lMelhor levar alguns extras!$"

MossvaleTown_Mart_EventScript_Woman_Text_1:
# 36 "data/maps/MossvaleTown_Mart/scripts.pory"
	.string "I pack Antidotes and Awakenings\nwhen I go walking around here.\pMy POKéMON loves poking its\nnose into every bush...\lBetter bring a few extras!$"

MossvaleTown_Mart_EventScript_Woman_Text_2:
# 37 "data/maps/MossvaleTown_Mart/scripts.pory"
	.string "Llevo Antidotes y Awakenings\ncuando salgo a caminar por aquí.\pA mi POKéMON le encanta meter\nel hocico en cada arbusto...\l¡Mejor llevar unos de más!$"
