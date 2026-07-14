OldaleTown_Mart_MapScripts::
	.byte 0


SylvaraTown_EventScript_Mart::
# 6 "data/maps/OldaleTown_Mart/scripts.pory"
	lock
# 7 "data/maps/OldaleTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/OldaleTown_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 9 "data/maps/OldaleTown_Mart/scripts.pory"
	case PT, SylvaraTown_EventScript_Mart_3
# 10 "data/maps/OldaleTown_Mart/scripts.pory"
	case EN, SylvaraTown_EventScript_Mart_4
# 11 "data/maps/OldaleTown_Mart/scripts.pory"
	case ES, SylvaraTown_EventScript_Mart_5
SylvaraTown_EventScript_Mart_1:
# 13 "data/maps/OldaleTown_Mart/scripts.pory"
	waitmessage
# 14 "data/maps/OldaleTown_Mart/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, SylvaraTown_EventScript_Mart_7
SylvaraTown_EventScript_Mart_6:
# 17 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemart SylvaraTown_Mart_Pokemart_Basic
# 18 "data/maps/OldaleTown_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 19 "data/maps/OldaleTown_Mart/scripts.pory"
	case PT, SylvaraTown_EventScript_Mart_11
# 20 "data/maps/OldaleTown_Mart/scripts.pory"
	case EN, SylvaraTown_EventScript_Mart_12
# 21 "data/maps/OldaleTown_Mart/scripts.pory"
	case ES, SylvaraTown_EventScript_Mart_13
SylvaraTown_EventScript_Mart_9:
# 23 "data/maps/OldaleTown_Mart/scripts.pory"
	release
	end

SylvaraTown_EventScript_Mart_3:
# 9 "data/maps/OldaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYouPt
	goto SylvaraTown_EventScript_Mart_1

SylvaraTown_EventScript_Mart_4:
# 10 "data/maps/OldaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
	goto SylvaraTown_EventScript_Mart_1

SylvaraTown_EventScript_Mart_5:
# 11 "data/maps/OldaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYouEs
	goto SylvaraTown_EventScript_Mart_1

SylvaraTown_EventScript_Mart_7:
# 15 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemart SylvaraTown_Mart_Pokemart_Expanded
	goto SylvaraTown_EventScript_Mart_6

SylvaraTown_EventScript_Mart_11:
# 19 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgainPt
	goto SylvaraTown_EventScript_Mart_9

SylvaraTown_EventScript_Mart_12:
# 20 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain
	goto SylvaraTown_EventScript_Mart_9

SylvaraTown_EventScript_Mart_13:
# 21 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgainEs
	goto SylvaraTown_EventScript_Mart_9


SylvaraTown_EventScript_Mart_Woman::
# 28 "data/maps/OldaleTown_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 29 "data/maps/OldaleTown_Mart/scripts.pory"
	case PT, SylvaraTown_EventScript_Mart_Woman_3
# 30 "data/maps/OldaleTown_Mart/scripts.pory"
	case EN, SylvaraTown_EventScript_Mart_Woman_4
# 31 "data/maps/OldaleTown_Mart/scripts.pory"
	case ES, SylvaraTown_EventScript_Mart_Woman_5
SylvaraTown_EventScript_Mart_Woman_1:
	end

SylvaraTown_EventScript_Mart_Woman_3:
# 29 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox SylvaraTown_EventScript_Mart_Woman_Text_0, MSGBOX_NPC
	goto SylvaraTown_EventScript_Mart_Woman_1

SylvaraTown_EventScript_Mart_Woman_4:
# 30 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox SylvaraTown_EventScript_Mart_Woman_Text_1, MSGBOX_NPC
	goto SylvaraTown_EventScript_Mart_Woman_1

SylvaraTown_EventScript_Mart_Woman_5:
# 31 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox SylvaraTown_EventScript_Mart_Woman_Text_2, MSGBOX_NPC
	goto SylvaraTown_EventScript_Mart_Woman_1


SylvaraTown_EventScript_Mart_Boy::
# 37 "data/maps/OldaleTown_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 38 "data/maps/OldaleTown_Mart/scripts.pory"
	case PT, SylvaraTown_EventScript_Mart_Boy_3
# 39 "data/maps/OldaleTown_Mart/scripts.pory"
	case EN, SylvaraTown_EventScript_Mart_Boy_4
# 40 "data/maps/OldaleTown_Mart/scripts.pory"
	case ES, SylvaraTown_EventScript_Mart_Boy_5
SylvaraTown_EventScript_Mart_Boy_1:
	end

SylvaraTown_EventScript_Mart_Boy_3:
# 38 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox SylvaraTown_EventScript_Mart_Boy_Text_0, MSGBOX_NPC
	goto SylvaraTown_EventScript_Mart_Boy_1

SylvaraTown_EventScript_Mart_Boy_4:
# 39 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox SylvaraTown_EventScript_Mart_Boy_Text_1, MSGBOX_NPC
	goto SylvaraTown_EventScript_Mart_Boy_1

SylvaraTown_EventScript_Mart_Boy_5:
# 40 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox SylvaraTown_EventScript_Mart_Boy_Text_2, MSGBOX_NPC
	goto SylvaraTown_EventScript_Mart_Boy_1


	.align 2
# 45 "data/maps/OldaleTown_Mart/scripts.pory"
SylvaraTown_Mart_Pokemart_Basic:
# 46 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_POTION
# 47 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 48 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 49 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE

	.align 2
# 52 "data/maps/OldaleTown_Mart/scripts.pory"
SylvaraTown_Mart_Pokemart_Expanded:
# 53 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 54 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_POTION
# 55 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 56 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 57 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE

SylvaraTown_EventScript_Mart_Woman_Text_0:
# 29 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "Uma boa TREINADORA nunca sai do\nMART sem algumas POTIONS.\pVocê nunca sabe quando seu POKéMON\nvai precisar de ajuda no meio da\lestrada!$"

SylvaraTown_EventScript_Mart_Woman_Text_1:
# 30 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "A good TRAINER never leaves the\nMART without a few POTIONS.\pYou never know when your POKéMON\nmight need help out on the road!$"

SylvaraTown_EventScript_Mart_Woman_Text_2:
# 31 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "Una buena ENTRENADORA nunca sale\ndel MART sin algunas POTIONS.\p¡Nunca sabes cuándo tu POKéMON\nnecesitará ayuda en medio del\lcamino!$"

SylvaraTown_EventScript_Mart_Boy_Text_0:
# 38 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "Seu POKéMON já foi envenenado no\nmeio de uma caverna?\pAcredite, voltar correndo até um\nCENTRO POKéMON não é nada\ldivertido.\pPor isso eu sempre carrego alguns\nANTIDOTES comigo!$"

SylvaraTown_EventScript_Mart_Boy_Text_1:
# 39 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "Has your POKéMON ever been\npoisoned in the middle of a cave?\pTrust me, rushing back to a\nPOKéMON CENTER isn't fun at all.\pThat's why I always carry a few\nANTIDOTES with me!$"

SylvaraTown_EventScript_Mart_Boy_Text_2:
# 40 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "¿Alguna vez tu POKéMON ha sido\nenvenenado en medio de una cueva?\pCréeme, correr de vuelta a un\nCENTRO POKéMON no es nada\ldivertido.\p¡Por eso siempre llevo algunos\nANTIDOTES conmigo!$"
