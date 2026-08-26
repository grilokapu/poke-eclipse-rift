StonereachCity_PokemonCenter_1F_MapScripts::
# 2 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0


StonereachCity_PokemonCenter_1F_EventScript_Nurse::
# 6 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_STONEREACH_NURSE
# 7 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 8 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 9 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 10 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	release
	end


StonereachCity_PokemonCenter_1F_EventScript_Boy::
# 15 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	switch VAR_LANGUAGE
# 16 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	case PT, StonereachCity_PokemonCenter_1F_EventScript_Boy_3
# 17 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	case EN, StonereachCity_PokemonCenter_1F_EventScript_Boy_4
# 18 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	case ES, StonereachCity_PokemonCenter_1F_EventScript_Boy_5
StonereachCity_PokemonCenter_1F_EventScript_Boy_1:
	end

StonereachCity_PokemonCenter_1F_EventScript_Boy_3:
# 16 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	msgbox StonereachCity_PokemonCenter_1F_EventScript_Boy_Text_0, MSGBOX_NPC
	goto StonereachCity_PokemonCenter_1F_EventScript_Boy_1

StonereachCity_PokemonCenter_1F_EventScript_Boy_4:
# 17 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	msgbox StonereachCity_PokemonCenter_1F_EventScript_Boy_Text_1, MSGBOX_NPC
	goto StonereachCity_PokemonCenter_1F_EventScript_Boy_1

StonereachCity_PokemonCenter_1F_EventScript_Boy_5:
# 18 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	msgbox StonereachCity_PokemonCenter_1F_EventScript_Boy_Text_2, MSGBOX_NPC
	goto StonereachCity_PokemonCenter_1F_EventScript_Boy_1


StonereachCity_PokemonCenter_1F_EventScript_Girl::
# 24 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	switch VAR_LANGUAGE
# 25 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	case PT, StonereachCity_PokemonCenter_1F_EventScript_Girl_3
# 26 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	case EN, StonereachCity_PokemonCenter_1F_EventScript_Girl_4
# 27 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	case ES, StonereachCity_PokemonCenter_1F_EventScript_Girl_5
StonereachCity_PokemonCenter_1F_EventScript_Girl_1:
	end

StonereachCity_PokemonCenter_1F_EventScript_Girl_3:
# 25 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	msgbox StonereachCity_PokemonCenter_1F_EventScript_Girl_Text_0, MSGBOX_NPC
	goto StonereachCity_PokemonCenter_1F_EventScript_Girl_1

StonereachCity_PokemonCenter_1F_EventScript_Girl_4:
# 26 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	msgbox StonereachCity_PokemonCenter_1F_EventScript_Girl_Text_1, MSGBOX_NPC
	goto StonereachCity_PokemonCenter_1F_EventScript_Girl_1

StonereachCity_PokemonCenter_1F_EventScript_Girl_5:
# 27 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	msgbox StonereachCity_PokemonCenter_1F_EventScript_Girl_Text_2, MSGBOX_NPC
	goto StonereachCity_PokemonCenter_1F_EventScript_Girl_1


StonereachCity_PokemonCenter_1F_EventScript_Traveler::
# 33 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	switch VAR_LANGUAGE
# 34 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	case PT, StonereachCity_PokemonCenter_1F_EventScript_Traveler_3
# 35 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	case EN, StonereachCity_PokemonCenter_1F_EventScript_Traveler_4
# 36 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	case ES, StonereachCity_PokemonCenter_1F_EventScript_Traveler_5
StonereachCity_PokemonCenter_1F_EventScript_Traveler_1:
	end

StonereachCity_PokemonCenter_1F_EventScript_Traveler_3:
# 34 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	msgbox StonereachCity_PokemonCenter_1F_EventScript_Traveler_Text_0, MSGBOX_NPC
	goto StonereachCity_PokemonCenter_1F_EventScript_Traveler_1

StonereachCity_PokemonCenter_1F_EventScript_Traveler_4:
# 35 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	msgbox StonereachCity_PokemonCenter_1F_EventScript_Traveler_Text_1, MSGBOX_NPC
	goto StonereachCity_PokemonCenter_1F_EventScript_Traveler_1

StonereachCity_PokemonCenter_1F_EventScript_Traveler_5:
# 36 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	msgbox StonereachCity_PokemonCenter_1F_EventScript_Traveler_Text_2, MSGBOX_NPC
	goto StonereachCity_PokemonCenter_1F_EventScript_Traveler_1


StonereachCity_PokemonCenter_1F_EventScript_Boy_Text_0:
# 16 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	.string "Meu Aron tem uma Nature Adamant.\pIsso favorece o Ataque, mas reduz o\nAtaque Especial.\pNão significa que ele seja bravo…\nSó que prefere resolver tudo com\luma boa cabeçada!$"

StonereachCity_PokemonCenter_1F_EventScript_Boy_Text_1:
# 17 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	.string "My Aron has an Adamant Nature.\pIt favors Attack, but lowers\nSpecial Attack.\pThat doesn't mean he's angry…\nHe just prefers solving everything\lwith a good headbutt!$"

StonereachCity_PokemonCenter_1F_EventScript_Boy_Text_2:
# 18 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	.string "Mi Aron tiene una Naturaleza Firme.\pFavorece el Ataque, pero reduce el\nAtaque Especial.\pEso no significa que esté enojado…\n¡Solo prefiere resolverlo todo con\lun buen cabezazo!$"

StonereachCity_PokemonCenter_1F_EventScript_Girl_Text_0:
# 25 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	.string "Quando meu Pokémon se machuca, eu\nsempre digo que vai ficar tudo bem.\pTalvez ele não entenda as palavras…\nMas entende quando eu fico ao lado\ldele.$"

StonereachCity_PokemonCenter_1F_EventScript_Girl_Text_1:
# 26 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	.string "Whenever my Pokémon gets hurt, I\nalways say everything will be okay.\pMaybe it doesn't understand the\nwords…\pBut it understands when I stay by\nits side.$"

StonereachCity_PokemonCenter_1F_EventScript_Girl_Text_2:
# 27 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	.string "Cuando mi Pokémon se lastima,\nsiempre digo que todo estará bien.\pQuizá no entienda mis palabras…\pPero entiende cuando permanezco a\nsu lado.$"

StonereachCity_PokemonCenter_1F_EventScript_Traveler_Text_0:
# 34 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	.string "As pedras de STONEREACH parecem\nimóveis, mas guardam marcas de\ltudo que passou por elas.\pAcho que os treinadores são assim\ntambém.\pCada batalha deixa alguma coisa\npara trás.$"

StonereachCity_PokemonCenter_1F_EventScript_Traveler_Text_1:
# 35 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	.string "STONEREACH's stones look\nunchanging, yet they carry marks\lfrom everything that passed them.\pI think Trainers are the same.\pEvery battle leaves something\nbehind.$"

StonereachCity_PokemonCenter_1F_EventScript_Traveler_Text_2:
# 36 "data/maps/StonereachCity_PokemonCenter_1F/scripts.pory"
	.string "Las piedras de STONEREACH parecen\ninmutables, pero conservan las\lmarcas de todo lo que pasó.\pCreo que los Entrenadores somos\niguales.\pCada combate deja algo atrás.$"
