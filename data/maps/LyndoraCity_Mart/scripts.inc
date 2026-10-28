LyndoraCity_Mart_MapScripts::
	.byte 0


LyndoraCity_Mart_EventScript_Clerk::
# 4 "data/maps/LyndoraCity_Mart/scripts.pory"
	lock
# 5 "data/maps/LyndoraCity_Mart/scripts.pory"
	faceplayer
# 6 "data/maps/LyndoraCity_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 7 "data/maps/LyndoraCity_Mart/scripts.pory"
	case PT, LyndoraCity_Mart_EventScript_Clerk_3
# 8 "data/maps/LyndoraCity_Mart/scripts.pory"
	case EN, LyndoraCity_Mart_EventScript_Clerk_4
# 9 "data/maps/LyndoraCity_Mart/scripts.pory"
	case ES, LyndoraCity_Mart_EventScript_Clerk_5
LyndoraCity_Mart_EventScript_Clerk_1:
# 11 "data/maps/LyndoraCity_Mart/scripts.pory"
	waitmessage
# 12 "data/maps/LyndoraCity_Mart/scripts.pory"
	pokemart LyndoraCity_Mart_Pokemart
# 13 "data/maps/LyndoraCity_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/LyndoraCity_Mart/scripts.pory"
	case PT, LyndoraCity_Mart_EventScript_Clerk_8
# 15 "data/maps/LyndoraCity_Mart/scripts.pory"
	case EN, LyndoraCity_Mart_EventScript_Clerk_9
# 16 "data/maps/LyndoraCity_Mart/scripts.pory"
	case ES, LyndoraCity_Mart_EventScript_Clerk_10
LyndoraCity_Mart_EventScript_Clerk_6:
# 18 "data/maps/LyndoraCity_Mart/scripts.pory"
	release
	end

LyndoraCity_Mart_EventScript_Clerk_3:
# 7 "data/maps/LyndoraCity_Mart/scripts.pory"
	message gText_HowMayIServeYouPt
	goto LyndoraCity_Mart_EventScript_Clerk_1

LyndoraCity_Mart_EventScript_Clerk_4:
# 8 "data/maps/LyndoraCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
	goto LyndoraCity_Mart_EventScript_Clerk_1

LyndoraCity_Mart_EventScript_Clerk_5:
# 9 "data/maps/LyndoraCity_Mart/scripts.pory"
	message gText_HowMayIServeYouEs
	goto LyndoraCity_Mart_EventScript_Clerk_1

LyndoraCity_Mart_EventScript_Clerk_8:
# 14 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgainPt
	goto LyndoraCity_Mart_EventScript_Clerk_6

LyndoraCity_Mart_EventScript_Clerk_9:
# 15 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain
	goto LyndoraCity_Mart_EventScript_Clerk_6

LyndoraCity_Mart_EventScript_Clerk_10:
# 16 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgainEs
	goto LyndoraCity_Mart_EventScript_Clerk_6


LyndoraCity_Mart_EventScript_Woman::
# 23 "data/maps/LyndoraCity_Mart/scripts.pory"
	lock
# 24 "data/maps/LyndoraCity_Mart/scripts.pory"
	faceplayer
# 25 "data/maps/LyndoraCity_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 26 "data/maps/LyndoraCity_Mart/scripts.pory"
	case PT, LyndoraCity_Mart_EventScript_Woman_3
# 27 "data/maps/LyndoraCity_Mart/scripts.pory"
	case EN, LyndoraCity_Mart_EventScript_Woman_4
# 28 "data/maps/LyndoraCity_Mart/scripts.pory"
	case ES, LyndoraCity_Mart_EventScript_Woman_5
LyndoraCity_Mart_EventScript_Woman_1:
# 30 "data/maps/LyndoraCity_Mart/scripts.pory"
	release
	end

LyndoraCity_Mart_EventScript_Woman_3:
# 26 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox LyndoraCity_Mart_EventScript_Woman_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_Mart_EventScript_Woman_1

LyndoraCity_Mart_EventScript_Woman_4:
# 27 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox LyndoraCity_Mart_EventScript_Woman_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_Mart_EventScript_Woman_1

LyndoraCity_Mart_EventScript_Woman_5:
# 28 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox LyndoraCity_Mart_EventScript_Woman_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_Mart_EventScript_Woman_1


LyndoraCity_Mart_EventScript_Boy::
# 35 "data/maps/LyndoraCity_Mart/scripts.pory"
	lock
# 36 "data/maps/LyndoraCity_Mart/scripts.pory"
	faceplayer
# 37 "data/maps/LyndoraCity_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 38 "data/maps/LyndoraCity_Mart/scripts.pory"
	case PT, LyndoraCity_Mart_EventScript_Boy_3
# 39 "data/maps/LyndoraCity_Mart/scripts.pory"
	case EN, LyndoraCity_Mart_EventScript_Boy_4
# 40 "data/maps/LyndoraCity_Mart/scripts.pory"
	case ES, LyndoraCity_Mart_EventScript_Boy_5
LyndoraCity_Mart_EventScript_Boy_1:
# 42 "data/maps/LyndoraCity_Mart/scripts.pory"
	release
	end

LyndoraCity_Mart_EventScript_Boy_3:
# 38 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox LyndoraCity_Mart_EventScript_Boy_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_Mart_EventScript_Boy_1

LyndoraCity_Mart_EventScript_Boy_4:
# 39 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox LyndoraCity_Mart_EventScript_Boy_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_Mart_EventScript_Boy_1

LyndoraCity_Mart_EventScript_Boy_5:
# 40 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox LyndoraCity_Mart_EventScript_Boy_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_Mart_EventScript_Boy_1


LyndoraCity_Mart_EventScript_Fisherman::
# 47 "data/maps/LyndoraCity_Mart/scripts.pory"
	lock
# 48 "data/maps/LyndoraCity_Mart/scripts.pory"
	faceplayer
# 49 "data/maps/LyndoraCity_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 50 "data/maps/LyndoraCity_Mart/scripts.pory"
	case PT, LyndoraCity_Mart_EventScript_Fisherman_3
# 51 "data/maps/LyndoraCity_Mart/scripts.pory"
	case EN, LyndoraCity_Mart_EventScript_Fisherman_4
# 52 "data/maps/LyndoraCity_Mart/scripts.pory"
	case ES, LyndoraCity_Mart_EventScript_Fisherman_5
LyndoraCity_Mart_EventScript_Fisherman_1:
# 54 "data/maps/LyndoraCity_Mart/scripts.pory"
	release
	end

LyndoraCity_Mart_EventScript_Fisherman_3:
# 50 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox LyndoraCity_Mart_EventScript_Fisherman_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_Mart_EventScript_Fisherman_1

LyndoraCity_Mart_EventScript_Fisherman_4:
# 51 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox LyndoraCity_Mart_EventScript_Fisherman_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_Mart_EventScript_Fisherman_1

LyndoraCity_Mart_EventScript_Fisherman_5:
# 52 "data/maps/LyndoraCity_Mart/scripts.pory"
	msgbox LyndoraCity_Mart_EventScript_Fisherman_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_Mart_EventScript_Fisherman_1


	.align 2
# 58 "data/maps/LyndoraCity_Mart/scripts.pory"
LyndoraCity_Mart_Pokemart:
# 59 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 60 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 61 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_NET_BALL
# 62 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_NEST_BALL
# 63 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 64 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 65 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 66 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 67 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 68 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 69 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 70 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 71 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 72 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 73 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 74 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 75 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 76 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 77 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 78 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_X_SP_DEF
# 79 "data/maps/LyndoraCity_Mart/scripts.pory"
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE

LyndoraCity_Mart_EventScript_Woman_Text_0:
# 26 "data/maps/LyndoraCity_Mart/scripts.pory"
	.string "Vim comprar remédios antes\nde desafiar o Ginásio.\pMeu Pokémon dorme até em pé...\nMelhor levar um Awakening!$"

LyndoraCity_Mart_EventScript_Woman_Text_1:
# 27 "data/maps/LyndoraCity_Mart/scripts.pory"
	.string "I came for medicine before\nchallenging the Gym.\pMy Pokémon sleeps standing up...\nI'd better get an Awakening!$"

LyndoraCity_Mart_EventScript_Woman_Text_2:
# 28 "data/maps/LyndoraCity_Mart/scripts.pory"
	.string "Vine por medicinas antes\nde desafiar el Gimnasio.\pMi Pokémon duerme hasta de pie...\n¡Mejor llevar un Awakening!$"

LyndoraCity_Mart_EventScript_Boy_Text_0:
# 38 "data/maps/LyndoraCity_Mart/scripts.pory"
	.string "Minha mãe pediu uma Potion.\pEu já estava escolhendo\na terceira Poké Ball...\pAinda bem que trouxe uma lista!$"

LyndoraCity_Mart_EventScript_Boy_Text_1:
# 39 "data/maps/LyndoraCity_Mart/scripts.pory"
	.string "Mom asked me to get a Potion.\pI was already picking out\nmy third Poké Ball...\pGood thing I brought a list!$"

LyndoraCity_Mart_EventScript_Boy_Text_2:
# 40 "data/maps/LyndoraCity_Mart/scripts.pory"
	.string "Mamá me pidió una Potion.\pYa estaba eligiendo\nmi tercera Poké Ball...\p¡Menos mal que traje una lista!$"

LyndoraCity_Mart_EventScript_Fisherman_Text_0:
# 50 "data/maps/LyndoraCity_Mart/scripts.pory"
	.string "Net Balls ajudam a capturar\nPokémon de Água e Inseto.\pVim preparado para pescar...\nMas saí com um inseto no chapéu!$"

LyndoraCity_Mart_EventScript_Fisherman_Text_1:
# 51 "data/maps/LyndoraCity_Mart/scripts.pory"
	.string "Net Balls help catch\nWater and Bug Pokémon.\pI came ready to go fishing...\nBut left with a bug on my hat!$"

LyndoraCity_Mart_EventScript_Fisherman_Text_2:
# 52 "data/maps/LyndoraCity_Mart/scripts.pory"
	.string "Las Net Balls ayudan a atrapar\nPokémon de Agua y Bicho.\pVine listo para pescar...\n¡Y salí con un bicho en el sombrero!$"
