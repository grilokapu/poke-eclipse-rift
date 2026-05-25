OldaleTown_MapScripts::
# 2 "data/maps/OldaleTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_VISITED_OLDALE_TOWN
	return


SylvaraTown_Sign::
# 8 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 9 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_Sign_3
# 10 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_Sign_4
# 11 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_Sign_5
SylvaraTown_Sign_1:
	end

SylvaraTown_Sign_3:
# 9 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Sign_Text_0, MSGBOX_SIGN
	goto SylvaraTown_Sign_1

SylvaraTown_Sign_4:
# 10 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Sign_Text_1, MSGBOX_SIGN
	goto SylvaraTown_Sign_1

SylvaraTown_Sign_5:
# 11 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Sign_Text_2, MSGBOX_SIGN
	goto SylvaraTown_Sign_1


SylvaraTown_PokemonCenter_Sign::
# 17 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 18 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_PokemonCenter_Sign_3
# 19 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_PokemonCenter_Sign_4
# 20 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_PokemonCenter_Sign_5
SylvaraTown_PokemonCenter_Sign_1:
	end

SylvaraTown_PokemonCenter_Sign_3:
# 18 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_Sign_Text_0, MSGBOX_SIGN
	goto SylvaraTown_PokemonCenter_Sign_1

SylvaraTown_PokemonCenter_Sign_4:
# 19 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_Sign_Text_1, MSGBOX_SIGN
	goto SylvaraTown_PokemonCenter_Sign_1

SylvaraTown_PokemonCenter_Sign_5:
# 20 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_Sign_Text_2, MSGBOX_SIGN
	goto SylvaraTown_PokemonCenter_Sign_1


SylvaraTown_Pokemart_Sign::
# 26 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 27 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_Pokemart_Sign_3
# 28 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_Pokemart_Sign_4
# 29 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_Pokemart_Sign_5
SylvaraTown_Pokemart_Sign_1:
	end

SylvaraTown_Pokemart_Sign_3:
# 27 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Pokemart_Sign_Text_0, MSGBOX_SIGN
	goto SylvaraTown_Pokemart_Sign_1

SylvaraTown_Pokemart_Sign_4:
# 28 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Pokemart_Sign_Text_1, MSGBOX_SIGN
	goto SylvaraTown_Pokemart_Sign_1

SylvaraTown_Pokemart_Sign_5:
# 29 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Pokemart_Sign_Text_2, MSGBOX_SIGN
	goto SylvaraTown_Pokemart_Sign_1


SylvaraTown_BoyWithRalts_Talk::
# 35 "data/maps/OldaleTown/scripts.pory"
	lock
# 36 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 37 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 38 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_BoyWithRalts_Talk_3
# 39 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_BoyWithRalts_Talk_4
# 40 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_BoyWithRalts_Talk_5
SylvaraTown_BoyWithRalts_Talk_1:
# 42 "data/maps/OldaleTown/scripts.pory"
	movenpc VAR_LAST_TALKED, Common_Movement_FaceRight
# 43 "data/maps/OldaleTown/scripts.pory"
	release
	end

SylvaraTown_BoyWithRalts_Talk_3:
# 38 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_BoyWithRalts_Talk_Text_0
	goto SylvaraTown_BoyWithRalts_Talk_1

SylvaraTown_BoyWithRalts_Talk_4:
# 39 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_BoyWithRalts_Talk_Text_1
	goto SylvaraTown_BoyWithRalts_Talk_1

SylvaraTown_BoyWithRalts_Talk_5:
# 40 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_BoyWithRalts_Talk_Text_2
	goto SylvaraTown_BoyWithRalts_Talk_1


SylvaraTown_Ralts_Cry::
# 48 "data/maps/OldaleTown/scripts.pory"
	lock
# 49 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 50 "data/maps/OldaleTown/scripts.pory"
	showmonmugshot SPECIES_RALTS, MUGSHOT_DOWN_RIGHT
# 51 "data/maps/OldaleTown/scripts.pory"
	setspeaker SylvaraTown_Ralts_Cry_Text_0
# 52 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Ralts_Cry_Text_1
# 53 "data/maps/OldaleTown/scripts.pory"
	waitmoncry
# 54 "data/maps/OldaleTown/scripts.pory"
	hidemonmugshot
# 55 "data/maps/OldaleTown/scripts.pory"
	movenpc VAR_LAST_TALKED, Common_Movement_FaceLeft
# 56 "data/maps/OldaleTown/scripts.pory"
	release
	end


SylvaraTown_Girl_Talk::
# 61 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 62 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_Girl_Talk_3
# 63 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_Girl_Talk_4
# 64 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_Girl_Talk_5
SylvaraTown_Girl_Talk_1:
	end

SylvaraTown_Girl_Talk_3:
# 62 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Girl_Talk_Text_0, MSGBOX_NPC
	goto SylvaraTown_Girl_Talk_1

SylvaraTown_Girl_Talk_4:
# 63 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Girl_Talk_Text_1, MSGBOX_NPC
	goto SylvaraTown_Girl_Talk_1

SylvaraTown_Girl_Talk_5:
# 64 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Girl_Talk_Text_2, MSGBOX_NPC
	goto SylvaraTown_Girl_Talk_1


SylvaraTown_Backpacker_Talk::
# 70 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 71 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_Backpacker_Talk_3
# 72 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_Backpacker_Talk_4
# 73 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_Backpacker_Talk_5
SylvaraTown_Backpacker_Talk_1:
	end

SylvaraTown_Backpacker_Talk_3:
# 71 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Backpacker_Talk_Text_0, MSGBOX_NPC
	goto SylvaraTown_Backpacker_Talk_1

SylvaraTown_Backpacker_Talk_4:
# 72 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Backpacker_Talk_Text_1, MSGBOX_NPC
	goto SylvaraTown_Backpacker_Talk_1

SylvaraTown_Backpacker_Talk_5:
# 73 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Backpacker_Talk_Text_2, MSGBOX_NPC
	goto SylvaraTown_Backpacker_Talk_1


SylvaraTown_Sign_Text_0:
# 9 "data/maps/OldaleTown/scripts.pory"
	.string "Vila Sylvara\pUma Vila Guiada pelo Vento e pelas\nFolhas.$"

SylvaraTown_Sign_Text_1:
# 10 "data/maps/OldaleTown/scripts.pory"
	.string "Sylvara Town\pA Town Guided by the Wind and\nLeaves.$"

SylvaraTown_Sign_Text_2:
# 11 "data/maps/OldaleTown/scripts.pory"
	.string "Aldea Sylvara\pUna Aldea Guiada por el Viento y\nlas Hojas.$"

SylvaraTown_PokemonCenter_Sign_Text_0:
# 18 "data/maps/OldaleTown/scripts.pory"
	.string "Centro Pokémon\pDescanse Sob a Calmaria da\nNatureza.$"

SylvaraTown_PokemonCenter_Sign_Text_1:
# 19 "data/maps/OldaleTown/scripts.pory"
	.string "Pokémon Center\pRest Beneath Nature’s Calm.$"

SylvaraTown_PokemonCenter_Sign_Text_2:
# 20 "data/maps/OldaleTown/scripts.pory"
	.string "Centro Pokémon\pDescansa Bajo la Calma de la\nNaturaleza.$"

SylvaraTown_Pokemart_Sign_Text_0:
# 27 "data/maps/OldaleTown/scripts.pory"
	.string "Loja Pokémon\pTudo que um Treinador precisa para\na jornada.$"

SylvaraTown_Pokemart_Sign_Text_1:
# 28 "data/maps/OldaleTown/scripts.pory"
	.string "Pokémart\pEverything a Trainer needs for the\nroad ahead.$"

SylvaraTown_Pokemart_Sign_Text_2:
# 29 "data/maps/OldaleTown/scripts.pory"
	.string "Tienda Pokémon\pTodo lo que un Entrenador necesita\npara el camino.$"

SylvaraTown_BoyWithRalts_Talk_Text_0:
# 38 "data/maps/OldaleTown/scripts.pory"
	.string "Meu Ralts sempre sabe quando eu\nestou triste…\pO problema é que ele também sabe\nquando eu estou aprontando!$"

SylvaraTown_BoyWithRalts_Talk_Text_1:
# 39 "data/maps/OldaleTown/scripts.pory"
	.string "My Ralts always knows when I'm\nfeeling sad…\pThe problem is, it also knows when\nI'm about to do something dumb!$"

SylvaraTown_BoyWithRalts_Talk_Text_2:
# 40 "data/maps/OldaleTown/scripts.pory"
	.string "Mi Ralts siempre sabe cuándo estoy\ntriste…\p¡El problema es que también sabe\ncuándo estoy por hacer alguna\ltontería!$"

SylvaraTown_Ralts_Cry_Text_0:
# 51 "data/maps/OldaleTown/scripts.pory"
	.string "Ralts$"

SylvaraTown_Ralts_Cry_Text_1:
# 52 "data/maps/OldaleTown/scripts.pory"
	.string "Ral Ral!$"

SylvaraTown_Girl_Talk_Text_0:
# 62 "data/maps/OldaleTown/scripts.pory"
	.string "Às vezes eu caminho pela Floresta\nPendant só para ouvir o som\ldas árvores…\pMas quando o sol começa a\ndesaparecer, eu volto correndo pra\lcasa!$"

SylvaraTown_Girl_Talk_Text_1:
# 63 "data/maps/OldaleTown/scripts.pory"
	.string "Sometimes I walk through Pendant\nForest just to hear the sound\lof the trees…\pBut when the sun starts to fade, I\nrun straight back home!$"

SylvaraTown_Girl_Talk_Text_2:
# 64 "data/maps/OldaleTown/scripts.pory"
	.string "A veces camino por el Bosque\nPendant solo para escuchar el\lsonido de los árboles…\p¡Pero cuando el sol empieza a\nocultarse, regreso corriendo a\lcasa!$"

SylvaraTown_Backpacker_Talk_Text_0:
# 71 "data/maps/OldaleTown/scripts.pory"
	.string "Você sabia que é mais saudável\npara seu Pokémon dar uma Sitrus\lBerry, do quê ele ser acertado por\lum tijolo?$"

SylvaraTown_Backpacker_Talk_Text_1:
# 72 "data/maps/OldaleTown/scripts.pory"
	.string "Did you know it's much healthier\nfor your Pokémon to eat a Sitrus\lBerry than to get hit by a brick?$"

SylvaraTown_Backpacker_Talk_Text_2:
# 73 "data/maps/OldaleTown/scripts.pory"
	.string "¿Sabías que es mucho más saludable\npara tu Pokémon comer una Baya\lZidra que recibir un ladrillazo?$"
