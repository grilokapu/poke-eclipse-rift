OldaleTown_PokemonCenter_1F_MapScripts::
# 2 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 3 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, OldaleTown_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

OldaleTown_PokemonCenter_1F_MapScripts_MAP_SCRIPT_ON_LOAD:
# 4 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	sethealingplacePC MAP_OLDALE_TOWN_POKEMON_CENTER_1F
	end


SylvaraTown_PokemonCenter_1F_EventScript_Nurse::
# 10 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_SYLVARA_NURSE
# 11 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 12 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 13 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 14 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	release
	end


SylvaraTown_PokemonCenter_1F_EventScript_Gentleman::
# 19 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	switch VAR_LANGUAGE
# 20 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case PT, SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_3
# 21 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case EN, SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_4
# 22 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case ES, SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_5
SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_1:
	end

SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_3:
# 20 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_Text_0, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_1

SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_4:
# 21 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_Text_1, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_1

SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_5:
# 22 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_Text_2, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_1


SylvaraTown_PokemonCenter_1F_EventScript_Girl::
# 28 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	switch VAR_LANGUAGE
# 29 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case PT, SylvaraTown_PokemonCenter_1F_EventScript_Girl_3
# 30 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case EN, SylvaraTown_PokemonCenter_1F_EventScript_Girl_4
# 31 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case ES, SylvaraTown_PokemonCenter_1F_EventScript_Girl_5
SylvaraTown_PokemonCenter_1F_EventScript_Girl_1:
	end

SylvaraTown_PokemonCenter_1F_EventScript_Girl_3:
# 29 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Girl_Text_0, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Girl_1

SylvaraTown_PokemonCenter_1F_EventScript_Girl_4:
# 30 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Girl_Text_1, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Girl_1

SylvaraTown_PokemonCenter_1F_EventScript_Girl_5:
# 31 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Girl_Text_2, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Girl_1


SylvaraTown_PokemonCenter_1F_EventScript_Boy::
# 37 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	switch VAR_LANGUAGE
# 38 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case PT, SylvaraTown_PokemonCenter_1F_EventScript_Boy_3
# 39 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case EN, SylvaraTown_PokemonCenter_1F_EventScript_Boy_4
# 40 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case ES, SylvaraTown_PokemonCenter_1F_EventScript_Boy_5
SylvaraTown_PokemonCenter_1F_EventScript_Boy_1:
	end

SylvaraTown_PokemonCenter_1F_EventScript_Boy_3:
# 38 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Boy_Text_0, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Boy_1

SylvaraTown_PokemonCenter_1F_EventScript_Boy_4:
# 39 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Boy_Text_1, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Boy_1

SylvaraTown_PokemonCenter_1F_EventScript_Boy_5:
# 40 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Boy_Text_2, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Boy_1


SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs::
# 46 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	switch VAR_LANGUAGE
# 47 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case PT, SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_3
# 48 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case EN, SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_4
# 49 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	case ES, SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_5
SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_1:
	end

SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_3:
# 47 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_Text_0, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_1

SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_4:
# 48 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_Text_1, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_1

SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_5:
# 49 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_Text_2, MSGBOX_NPC
	goto SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_1


SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_Text_0:
# 20 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Ouvi dizer que metade dos\nTREINADORES que passam por Sylvara\lTown vêm só pelo famoso chá de\lervas daqui.\pA outra metade vem porque ouviu\nfalar do chá… e acabou se perdendo\lna floresta!$"

SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_Text_1:
# 21 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "I heard that half the TRAINERS\npassing through Sylvara Town come\lhere just for the famous herbal\ltea.\pThe other half come because they\nheard about the tea… and end up\lgetting lost in the forest!$"

SylvaraTown_PokemonCenter_1F_EventScript_Gentleman_Text_2:
# 22 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Escuché que la mitad de los\nENTRENADORES que pasan por Sylvara\lTown vienen solo por el famoso té\lde hierbas.\p¡La otra mitad viene por el té… y\ntermina perdiéndose en el bosque!$"

SylvaraTown_PokemonCenter_1F_EventScript_Girl_Text_0:
# 29 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Acabei de terminar meu treino!\pMeus POKéMON ficaram exaustos,\nentão vim correndo direto para o\lCENTRO POKéMON!$"

SylvaraTown_PokemonCenter_1F_EventScript_Girl_Text_1:
# 30 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "I just finished my training!\pMy POKéMON were exhausted, so I\nrushed straight to the POKéMON\lCENTER!$"

SylvaraTown_PokemonCenter_1F_EventScript_Girl_Text_2:
# 31 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "¡Acabo de terminar mi\nentrenamiento!\pMis POKéMON quedaron agotados, así\nque vine corriendo directo al\lCENTRO POKéMON!$"

SylvaraTown_PokemonCenter_1F_EventScript_Boy_Text_0:
# 38 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sabe aquela vontade de acordar\ncedo e ir correr na estrada?\pEntão…\nNunca tive!$"

SylvaraTown_PokemonCenter_1F_EventScript_Boy_Text_1:
# 39 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "You know that urge to wake up\nearly and go for a run on the\lroad?\pYeah…\nI've never had it!$"

SylvaraTown_PokemonCenter_1F_EventScript_Boy_Text_2:
# 40 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "¿Sabes esas ganas de despertarse\ntemprano e ir a correr por el\lcamino?\pPues…\n¡Nunca las tuve!$"

SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_Text_0:
# 47 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sinto muito.\pEstamos trabalhando no subsolo\nagora.\pO acesso ao público está proibido.\pPor favor, tente novamente mais\ntarde.$"

SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_Text_1:
# 48 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Sorry.\pWe are working in the basement\nnow.\pPublic access is prohibited.\pPlease try again later.$"

SylvaraTown_PokemonCenter_1F_EventScript_Teala_BlockStairs_Text_2:
# 49 "data/maps/OldaleTown_PokemonCenter_1F/scripts.pory"
	.string "Lo siento.\pEstamos trabajando en el sótano\nahora.\pEl acceso al público está\nprohibido.\pPor favor, inténtelo de nuevo más\ntarde.$"
