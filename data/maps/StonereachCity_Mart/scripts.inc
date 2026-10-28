StonereachCity_Mart_MapScripts::
	.byte 0


StonereachCity_Mart_EventScript_Clerk::
# 6 "data/maps/StonereachCity_Mart/scripts.pory"
	lock
# 7 "data/maps/StonereachCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/StonereachCity_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 9 "data/maps/StonereachCity_Mart/scripts.pory"
	case PT, StonereachCity_Mart_EventScript_Clerk_3
# 10 "data/maps/StonereachCity_Mart/scripts.pory"
	case EN, StonereachCity_Mart_EventScript_Clerk_4
# 11 "data/maps/StonereachCity_Mart/scripts.pory"
	case ES, StonereachCity_Mart_EventScript_Clerk_5
StonereachCity_Mart_EventScript_Clerk_1:
# 13 "data/maps/StonereachCity_Mart/scripts.pory"
	waitmessage
# 14 "data/maps/StonereachCity_Mart/scripts.pory"
	pokemart StonereachCity_Mart_Pokemart
# 15 "data/maps/StonereachCity_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 16 "data/maps/StonereachCity_Mart/scripts.pory"
	case PT, StonereachCity_Mart_EventScript_Clerk_8
# 17 "data/maps/StonereachCity_Mart/scripts.pory"
	case EN, StonereachCity_Mart_EventScript_Clerk_9
# 18 "data/maps/StonereachCity_Mart/scripts.pory"
	case ES, StonereachCity_Mart_EventScript_Clerk_10
StonereachCity_Mart_EventScript_Clerk_6:
# 20 "data/maps/StonereachCity_Mart/scripts.pory"
	release
	end

StonereachCity_Mart_EventScript_Clerk_3:
# 9 "data/maps/StonereachCity_Mart/scripts.pory"
	message gText_HowMayIServeYouPt
	goto StonereachCity_Mart_EventScript_Clerk_1

StonereachCity_Mart_EventScript_Clerk_4:
# 10 "data/maps/StonereachCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
	goto StonereachCity_Mart_EventScript_Clerk_1

StonereachCity_Mart_EventScript_Clerk_5:
# 11 "data/maps/StonereachCity_Mart/scripts.pory"
	message gText_HowMayIServeYouEs
	goto StonereachCity_Mart_EventScript_Clerk_1

StonereachCity_Mart_EventScript_Clerk_8:
# 16 "data/maps/StonereachCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgainPt
	goto StonereachCity_Mart_EventScript_Clerk_6

StonereachCity_Mart_EventScript_Clerk_9:
# 17 "data/maps/StonereachCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain
	goto StonereachCity_Mart_EventScript_Clerk_6

StonereachCity_Mart_EventScript_Clerk_10:
# 18 "data/maps/StonereachCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgainEs
	goto StonereachCity_Mart_EventScript_Clerk_6


StonereachCity_Mart_EventScript_Boy::
# 25 "data/maps/StonereachCity_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 26 "data/maps/StonereachCity_Mart/scripts.pory"
	case PT, StonereachCity_Mart_EventScript_Boy_3
# 27 "data/maps/StonereachCity_Mart/scripts.pory"
	case EN, StonereachCity_Mart_EventScript_Boy_4
# 28 "data/maps/StonereachCity_Mart/scripts.pory"
	case ES, StonereachCity_Mart_EventScript_Boy_5
StonereachCity_Mart_EventScript_Boy_1:
	end

StonereachCity_Mart_EventScript_Boy_3:
# 26 "data/maps/StonereachCity_Mart/scripts.pory"
	msgbox StonereachCity_Mart_EventScript_Boy_Text_0, MSGBOX_NPC
	goto StonereachCity_Mart_EventScript_Boy_1

StonereachCity_Mart_EventScript_Boy_4:
# 27 "data/maps/StonereachCity_Mart/scripts.pory"
	msgbox StonereachCity_Mart_EventScript_Boy_Text_1, MSGBOX_NPC
	goto StonereachCity_Mart_EventScript_Boy_1

StonereachCity_Mart_EventScript_Boy_5:
# 28 "data/maps/StonereachCity_Mart/scripts.pory"
	msgbox StonereachCity_Mart_EventScript_Boy_Text_2, MSGBOX_NPC
	goto StonereachCity_Mart_EventScript_Boy_1


StonereachCity_Mart_EventScript_Pokefan::
# 34 "data/maps/StonereachCity_Mart/scripts.pory"
	switch VAR_LANGUAGE
# 35 "data/maps/StonereachCity_Mart/scripts.pory"
	case PT, StonereachCity_Mart_EventScript_Pokefan_3
# 36 "data/maps/StonereachCity_Mart/scripts.pory"
	case EN, StonereachCity_Mart_EventScript_Pokefan_4
# 37 "data/maps/StonereachCity_Mart/scripts.pory"
	case ES, StonereachCity_Mart_EventScript_Pokefan_5
StonereachCity_Mart_EventScript_Pokefan_1:
	end

StonereachCity_Mart_EventScript_Pokefan_3:
# 35 "data/maps/StonereachCity_Mart/scripts.pory"
	msgbox StonereachCity_Mart_EventScript_Pokefan_Text_0, MSGBOX_NPC
	goto StonereachCity_Mart_EventScript_Pokefan_1

StonereachCity_Mart_EventScript_Pokefan_4:
# 36 "data/maps/StonereachCity_Mart/scripts.pory"
	msgbox StonereachCity_Mart_EventScript_Pokefan_Text_1, MSGBOX_NPC
	goto StonereachCity_Mart_EventScript_Pokefan_1

StonereachCity_Mart_EventScript_Pokefan_5:
# 37 "data/maps/StonereachCity_Mart/scripts.pory"
	msgbox StonereachCity_Mart_EventScript_Pokefan_Text_2, MSGBOX_NPC
	goto StonereachCity_Mart_EventScript_Pokefan_1


	.align 2
# 42 "data/maps/StonereachCity_Mart/scripts.pory"
StonereachCity_Mart_Pokemart:
# 43 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 44 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 45 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 46 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 47 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 48 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 49 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 50 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 51 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 52 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 53 "data/maps/StonereachCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_NONE

StonereachCity_Mart_EventScript_Boy_Text_0:
# 26 "data/maps/StonereachCity_Mart/scripts.pory"
	.string "Vou levar uma Escape Rope para a\npróxima caverna.\pEla não impede que eu me perca…\nMas transforma um desastre em uma\lsaída rápida!$"

StonereachCity_Mart_EventScript_Boy_Text_1:
# 27 "data/maps/StonereachCity_Mart/scripts.pory"
	.string "I'm taking an Escape Rope into the\nnext cave.\pIt won't stop me from getting lost…\nBut it can turn a disaster into a\lquick escape!$"

StonereachCity_Mart_EventScript_Boy_Text_2:
# 28 "data/maps/StonereachCity_Mart/scripts.pory"
	.string "Llevaré una Escape Rope a la\npróxima cueva.\pNo evitará que me pierda…\n¡Pero puede convertir un desastre\len una salida rápida!$"

StonereachCity_Mart_EventScript_Pokefan_Text_0:
# 35 "data/maps/StonereachCity_Mart/scripts.pory"
	.string "Meu Nosepass aguenta golpes como\numa muralha.\pMas até uma muralha acumula\nrachaduras.\pPor isso nunca viajo sem algumas\nSuper Potions.$"

StonereachCity_Mart_EventScript_Pokefan_Text_1:
# 36 "data/maps/StonereachCity_Mart/scripts.pory"
	.string "My Nosepass takes hits like a wall.\pBut even a wall gathers cracks.\pThat's why I never travel without\na few Super Potions.$"

StonereachCity_Mart_EventScript_Pokefan_Text_2:
# 37 "data/maps/StonereachCity_Mart/scripts.pory"
	.string "Mi Nosepass resiste golpes como un\nmuro.\pPero hasta un muro acumula\ngrietas.\pPor eso nunca viajo sin algunas\nSuper Potions.$"
