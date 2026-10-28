Mossvale_PokemonCenter_MapScripts::
# 2 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 3 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Mossvale_PokemonCenter_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Mossvale_PokemonCenter_MapScripts_MAP_SCRIPT_ON_LOAD:
# 4 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	sethealingplacePC MAP_MOSSVALE_POKEMON_CENTER
	end


Mossvale_PokemonCenter_EventScript_Nurse::
# 10 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	setvar VAR_0x800B, LOCALID_MOSSVALE_NURSE
# 11 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 12 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	waitmessage
# 13 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	waitbuttonpress
# 14 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	release
	end


Mossvale_PokemonCenter_EventScript_Gentleman::
# 19 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	switch VAR_LANGUAGE
# 20 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case PT, Mossvale_PokemonCenter_EventScript_Gentleman_3
# 21 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case EN, Mossvale_PokemonCenter_EventScript_Gentleman_4
# 22 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case ES, Mossvale_PokemonCenter_EventScript_Gentleman_5
Mossvale_PokemonCenter_EventScript_Gentleman_1:
	end

Mossvale_PokemonCenter_EventScript_Gentleman_3:
# 20 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Gentleman_Text_0, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Gentleman_1

Mossvale_PokemonCenter_EventScript_Gentleman_4:
# 21 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Gentleman_Text_1, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Gentleman_1

Mossvale_PokemonCenter_EventScript_Gentleman_5:
# 22 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Gentleman_Text_2, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Gentleman_1


Mossvale_PokemonCenter_EventScript_Girl::
# 28 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	switch VAR_LANGUAGE
# 29 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case PT, Mossvale_PokemonCenter_EventScript_Girl_3
# 30 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case EN, Mossvale_PokemonCenter_EventScript_Girl_4
# 31 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case ES, Mossvale_PokemonCenter_EventScript_Girl_5
Mossvale_PokemonCenter_EventScript_Girl_1:
	end

Mossvale_PokemonCenter_EventScript_Girl_3:
# 29 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Girl_Text_0, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Girl_1

Mossvale_PokemonCenter_EventScript_Girl_4:
# 30 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Girl_Text_1, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Girl_1

Mossvale_PokemonCenter_EventScript_Girl_5:
# 31 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Girl_Text_2, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Girl_1


Mossvale_PokemonCenter_EventScript_Boy::
# 37 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	switch VAR_LANGUAGE
# 38 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case PT, Mossvale_PokemonCenter_EventScript_Boy_3
# 39 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case EN, Mossvale_PokemonCenter_EventScript_Boy_4
# 40 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case ES, Mossvale_PokemonCenter_EventScript_Boy_5
Mossvale_PokemonCenter_EventScript_Boy_1:
	end

Mossvale_PokemonCenter_EventScript_Boy_3:
# 38 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Boy_Text_0, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Boy_1

Mossvale_PokemonCenter_EventScript_Boy_4:
# 39 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Boy_Text_1, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Boy_1

Mossvale_PokemonCenter_EventScript_Boy_5:
# 40 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Boy_Text_2, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Boy_1


Mossvale_PokemonCenter_EventScript_Teala_BlockStairs::
# 46 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	switch VAR_LANGUAGE
# 47 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case PT, Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_3
# 48 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case EN, Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_4
# 49 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	case ES, Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_5
Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_1:
	end

Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_3:
# 47 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_Text_0, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_1

Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_4:
# 48 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_Text_1, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_1

Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_5:
# 49 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	msgbox Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_Text_2, MSGBOX_NPC
	goto Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_1


Mossvale_PokemonCenter_EventScript_Gentleman_Text_0:
# 20 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "Em Mossvale, saio de casa com\num guarda-chuva e volto com\lbarro nas botas.\pMas meus POKéMON adoram\npassear depois da chuva!$"

Mossvale_PokemonCenter_EventScript_Gentleman_Text_1:
# 21 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "In Mossvale, I leave home with\nan umbrella and come back with\lmud on my boots.\pBut my POKéMON love a walk\nafter the rain!$"

Mossvale_PokemonCenter_EventScript_Gentleman_Text_2:
# 22 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "En Mossvale, salgo de casa con\nun paraguas y vuelvo con\lbarro en las botas.\p¡A mis POKéMON les encanta\npasear después de la lluvia!$"

Mossvale_PokemonCenter_EventScript_Girl_Text_0:
# 29 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "Vim observar os POKéMON que\nse escondem entre as folhas.\pFiquei tão quietinha que um\ndeles dormiu ao meu lado!$"

Mossvale_PokemonCenter_EventScript_Girl_Text_1:
# 30 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "I came to watch the POKéMON\nhiding among the leaves.\pI stayed so still that one\nof them fell asleep beside me!$"

Mossvale_PokemonCenter_EventScript_Girl_Text_2:
# 31 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "Vine a observar a los POKéMON\nque se ocultan entre las hojas.\p¡Me quedé tan quieta que uno\nse durmió a mi lado!$"

Mossvale_PokemonCenter_EventScript_Boy_Text_0:
# 38 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "Meu POKéMON pula em todas\nas poças pelo caminho.\pEu tento desviar...\nMas ele sempre me molha!$"

Mossvale_PokemonCenter_EventScript_Boy_Text_1:
# 39 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "My POKéMON jumps into every\npuddle along the way.\pI try to dodge the splashes...\nBut it always gets me!$"

Mossvale_PokemonCenter_EventScript_Boy_Text_2:
# 40 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "Mi POKéMON salta en todos\nlos charcos del camino.\pIntento esquivar el agua...\n¡Pero siempre me moja!$"

Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_Text_0:
# 47 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "Sinto muito.\pEstamos trabalhando no subsolo\nagora.\pO acesso ao público está proibido.\pPor favor, tente novamente mais\ntarde.$"

Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_Text_1:
# 48 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "Sorry.\pWe are working in the basement\nnow.\pPublic access is prohibited.\pPlease try again later.$"

Mossvale_PokemonCenter_EventScript_Teala_BlockStairs_Text_2:
# 49 "data/maps/Mossvale_PokemonCenter/scripts.pory"
	.string "Lo siento.\pEstamos trabajando en el sótano\nahora.\pEl acceso al público está\nprohibido.\pPor favor, inténtelo de nuevo más\ntarde.$"
