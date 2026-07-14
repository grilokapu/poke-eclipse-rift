OldaleTown_MapScripts::
# 2 "data/maps/OldaleTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_VISITED_OLDALE_TOWN
# 4 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_SYLVARA_TOWN_RIVAL_DONE, OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 5 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/OldaleTown/scripts.pory"
	compare VAR_OLDALE_TOWN_STATE, 0
	goto_if_eq OldaleTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return


SylvaraTown_Sign::
# 11 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 12 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_Sign_3
# 13 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_Sign_4
# 14 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_Sign_5
SylvaraTown_Sign_1:
	end

SylvaraTown_Sign_3:
# 12 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Sign_Text_0, MSGBOX_SIGN
	goto SylvaraTown_Sign_1

SylvaraTown_Sign_4:
# 13 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Sign_Text_1, MSGBOX_SIGN
	goto SylvaraTown_Sign_1

SylvaraTown_Sign_5:
# 14 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Sign_Text_2, MSGBOX_SIGN
	goto SylvaraTown_Sign_1


SylvaraTown_PokemonCenter_Sign::
# 20 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 21 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_PokemonCenter_Sign_3
# 22 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_PokemonCenter_Sign_4
# 23 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_PokemonCenter_Sign_5
SylvaraTown_PokemonCenter_Sign_1:
	end

SylvaraTown_PokemonCenter_Sign_3:
# 21 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_Sign_Text_0, MSGBOX_SIGN
	goto SylvaraTown_PokemonCenter_Sign_1

SylvaraTown_PokemonCenter_Sign_4:
# 22 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_Sign_Text_1, MSGBOX_SIGN
	goto SylvaraTown_PokemonCenter_Sign_1

SylvaraTown_PokemonCenter_Sign_5:
# 23 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_PokemonCenter_Sign_Text_2, MSGBOX_SIGN
	goto SylvaraTown_PokemonCenter_Sign_1


SylvaraTown_Pokemart_Sign::
# 29 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 30 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_Pokemart_Sign_3
# 31 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_Pokemart_Sign_4
# 32 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_Pokemart_Sign_5
SylvaraTown_Pokemart_Sign_1:
	end

SylvaraTown_Pokemart_Sign_3:
# 30 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Pokemart_Sign_Text_0, MSGBOX_SIGN
	goto SylvaraTown_Pokemart_Sign_1

SylvaraTown_Pokemart_Sign_4:
# 31 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Pokemart_Sign_Text_1, MSGBOX_SIGN
	goto SylvaraTown_Pokemart_Sign_1

SylvaraTown_Pokemart_Sign_5:
# 32 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Pokemart_Sign_Text_2, MSGBOX_SIGN
	goto SylvaraTown_Pokemart_Sign_1


SylvaraTown_BoyWithRalts_Talk::
# 38 "data/maps/OldaleTown/scripts.pory"
	lock
# 39 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 40 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 41 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_BoyWithRalts_Talk_3
# 42 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_BoyWithRalts_Talk_4
# 43 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_BoyWithRalts_Talk_5
SylvaraTown_BoyWithRalts_Talk_1:
# 45 "data/maps/OldaleTown/scripts.pory"
	movenpc VAR_LAST_TALKED, Common_Movement_FaceRight
# 46 "data/maps/OldaleTown/scripts.pory"
	release
	end

SylvaraTown_BoyWithRalts_Talk_3:
# 41 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_BoyWithRalts_Talk_Text_0
	goto SylvaraTown_BoyWithRalts_Talk_1

SylvaraTown_BoyWithRalts_Talk_4:
# 42 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_BoyWithRalts_Talk_Text_1
	goto SylvaraTown_BoyWithRalts_Talk_1

SylvaraTown_BoyWithRalts_Talk_5:
# 43 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_BoyWithRalts_Talk_Text_2
	goto SylvaraTown_BoyWithRalts_Talk_1


SylvaraTown_Ralts_Cry::
# 51 "data/maps/OldaleTown/scripts.pory"
	lock
# 52 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 53 "data/maps/OldaleTown/scripts.pory"
	showmonmugshot SPECIES_RALTS, MUGSHOT_SOUTHEAST
# 54 "data/maps/OldaleTown/scripts.pory"
	setspeaker SylvaraTown_Ralts_Cry_Text_0
# 55 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Ralts_Cry_Text_1
# 56 "data/maps/OldaleTown/scripts.pory"
	waitmoncry
# 57 "data/maps/OldaleTown/scripts.pory"
	hidemonmugshot
# 58 "data/maps/OldaleTown/scripts.pory"
	movenpc VAR_LAST_TALKED, Common_Movement_FaceLeft
# 59 "data/maps/OldaleTown/scripts.pory"
	release
	end


SylvaraTown_Girl_Talk::
# 64 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 65 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_Girl_Talk_3
# 66 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_Girl_Talk_4
# 67 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_Girl_Talk_5
SylvaraTown_Girl_Talk_1:
	end

SylvaraTown_Girl_Talk_3:
# 65 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Girl_Talk_Text_0, MSGBOX_NPC
	goto SylvaraTown_Girl_Talk_1

SylvaraTown_Girl_Talk_4:
# 66 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Girl_Talk_Text_1, MSGBOX_NPC
	goto SylvaraTown_Girl_Talk_1

SylvaraTown_Girl_Talk_5:
# 67 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Girl_Talk_Text_2, MSGBOX_NPC
	goto SylvaraTown_Girl_Talk_1


SylvaraTown_Backpacker_Talk::
# 73 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 74 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_Backpacker_Talk_3
# 75 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_Backpacker_Talk_4
# 76 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_Backpacker_Talk_5
SylvaraTown_Backpacker_Talk_1:
	end

SylvaraTown_Backpacker_Talk_3:
# 74 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Backpacker_Talk_Text_0, MSGBOX_NPC
	goto SylvaraTown_Backpacker_Talk_1

SylvaraTown_Backpacker_Talk_4:
# 75 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Backpacker_Talk_Text_1, MSGBOX_NPC
	goto SylvaraTown_Backpacker_Talk_1

SylvaraTown_Backpacker_Talk_5:
# 76 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_Backpacker_Talk_Text_2, MSGBOX_NPC
	goto SylvaraTown_Backpacker_Talk_1


SylvaraTown_EventScript_Girl_Trigger::
# 82 "data/maps/OldaleTown/scripts.pory"
	lockall
# 83 "data/maps/OldaleTown/scripts.pory"
	playse SE_PIN
# 84 "data/maps/OldaleTown/scripts.pory"
	movenpc LOCALID_SYLVARA_GIRL_2, Common_Movement_ExclamationMark
# 85 "data/maps/OldaleTown/scripts.pory"
	waitse
# 86 "data/maps/OldaleTown/scripts.pory"
	pause 20
# 87 "data/maps/OldaleTown/scripts.pory"
	moveplayer Common_Movement_FaceRight
# 88 "data/maps/OldaleTown/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 89 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_0, 9
	goto_if_eq SylvaraTown_EventScript_Girl_Trigger_2
# 92 "data/maps/OldaleTown/scripts.pory"
	movenpc LOCALID_SYLVARA_GIRL_2, Movement_Girl_GoNextPlayer_2
SylvaraTown_EventScript_Girl_Trigger_1:
# 94 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 95 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_EventScript_Girl_Trigger_7
# 96 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_EventScript_Girl_Trigger_8
# 97 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_EventScript_Girl_Trigger_9
SylvaraTown_EventScript_Girl_Trigger_5:
# 99 "data/maps/OldaleTown/scripts.pory"
	compare VAR_TEMP_0, 9
	goto_if_eq SylvaraTown_EventScript_Girl_Trigger_11
# 102 "data/maps/OldaleTown/scripts.pory"
	movenpc LOCALID_SYLVARA_GIRL_2, Movement_Girl_GoAway_AfterTalk_2
SylvaraTown_EventScript_Girl_Trigger_10:
# 104 "data/maps/OldaleTown/scripts.pory"
	moveplayer Movement_PlayerWalk_RightFacingRight
# 105 "data/maps/OldaleTown/scripts.pory"
	releaseall
	end

SylvaraTown_EventScript_Girl_Trigger_2:
# 90 "data/maps/OldaleTown/scripts.pory"
	movenpc LOCALID_SYLVARA_GIRL_2, Movement_Girl_GoNextPlayer_1
	goto SylvaraTown_EventScript_Girl_Trigger_1

SylvaraTown_EventScript_Girl_Trigger_7:
# 95 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_EventScript_Girl_Trigger_Text_0, MSGBOX_AUTOCLOSE
	goto SylvaraTown_EventScript_Girl_Trigger_5

SylvaraTown_EventScript_Girl_Trigger_8:
# 96 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_EventScript_Girl_Trigger_Text_1, MSGBOX_AUTOCLOSE
	goto SylvaraTown_EventScript_Girl_Trigger_5

SylvaraTown_EventScript_Girl_Trigger_9:
# 97 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_EventScript_Girl_Trigger_Text_2, MSGBOX_AUTOCLOSE
	goto SylvaraTown_EventScript_Girl_Trigger_5

SylvaraTown_EventScript_Girl_Trigger_11:
# 100 "data/maps/OldaleTown/scripts.pory"
	movenpc LOCALID_SYLVARA_GIRL_2, Movement_Girl_GoAway_AfterTalk_1
	goto SylvaraTown_EventScript_Girl_Trigger_10


# 109 "data/maps/OldaleTown/scripts.pory"
Movement_PlayerWalk_RightFacingRight:
# 110 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 111 "data/maps/OldaleTown/scripts.pory"
	face_right
	step_end

# 114 "data/maps/OldaleTown/scripts.pory"
Movement_Girl_GoNextPlayer_1:
# 115 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 115 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 115 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 116 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 117 "data/maps/OldaleTown/scripts.pory"
	face_left
	step_end

# 120 "data/maps/OldaleTown/scripts.pory"
Movement_Girl_GoNextPlayer_2:
# 121 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 121 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 122 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 123 "data/maps/OldaleTown/scripts.pory"
	face_left
	step_end

# 126 "data/maps/OldaleTown/scripts.pory"
Movement_Girl_GoAway_AfterTalk_1:
# 127 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 128 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 128 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 128 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 129 "data/maps/OldaleTown/scripts.pory"
	face_up
	step_end

# 132 "data/maps/OldaleTown/scripts.pory"
Movement_Girl_GoAway_AfterTalk_2:
# 133 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 134 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 134 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 135 "data/maps/OldaleTown/scripts.pory"
	face_up
	step_end

SylvaraTown_EventScript_Girl2_Talk::
# 139 "data/maps/OldaleTown/scripts.pory"
	switch VAR_LANGUAGE
# 140 "data/maps/OldaleTown/scripts.pory"
	case PT, SylvaraTown_EventScript_Girl2_Talk_3
# 141 "data/maps/OldaleTown/scripts.pory"
	case EN, SylvaraTown_EventScript_Girl2_Talk_4
# 142 "data/maps/OldaleTown/scripts.pory"
	case ES, SylvaraTown_EventScript_Girl2_Talk_5
SylvaraTown_EventScript_Girl2_Talk_1:
	end

SylvaraTown_EventScript_Girl2_Talk_3:
# 140 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_EventScript_Girl2_Talk_Text_0, MSGBOX_NPC
	goto SylvaraTown_EventScript_Girl2_Talk_1

SylvaraTown_EventScript_Girl2_Talk_4:
# 141 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_EventScript_Girl2_Talk_Text_1, MSGBOX_NPC
	goto SylvaraTown_EventScript_Girl2_Talk_1

SylvaraTown_EventScript_Girl2_Talk_5:
# 142 "data/maps/OldaleTown/scripts.pory"
	msgbox SylvaraTown_EventScript_Girl2_Talk_Text_2, MSGBOX_NPC
	goto SylvaraTown_EventScript_Girl2_Talk_1


SylvaraTown_Sign_Text_0:
# 12 "data/maps/OldaleTown/scripts.pory"
	.string "Vila Sylvara\pUma Vila Guiada pelo Vento e pelas\nFolhas.$"

SylvaraTown_Sign_Text_1:
# 13 "data/maps/OldaleTown/scripts.pory"
	.string "Sylvara Town\pA Town Guided by the Wind and\nLeaves.$"

SylvaraTown_Sign_Text_2:
# 14 "data/maps/OldaleTown/scripts.pory"
	.string "Aldea Sylvara\pUna Aldea Guiada por el Viento y\nlas Hojas.$"

SylvaraTown_PokemonCenter_Sign_Text_0:
# 21 "data/maps/OldaleTown/scripts.pory"
	.string "Centro Pokémon\pDescanse Sob a Calmaria da\nNatureza.$"

SylvaraTown_PokemonCenter_Sign_Text_1:
# 22 "data/maps/OldaleTown/scripts.pory"
	.string "Pokémon Center\pRest Beneath Nature’s Calm.$"

SylvaraTown_PokemonCenter_Sign_Text_2:
# 23 "data/maps/OldaleTown/scripts.pory"
	.string "Centro Pokémon\pDescansa Bajo la Calma de la\nNaturaleza.$"

SylvaraTown_Pokemart_Sign_Text_0:
# 30 "data/maps/OldaleTown/scripts.pory"
	.string "Loja Pokémon\pTudo que um Treinador precisa para\na jornada.$"

SylvaraTown_Pokemart_Sign_Text_1:
# 31 "data/maps/OldaleTown/scripts.pory"
	.string "Pokémart\pEverything a Trainer needs for the\nroad ahead.$"

SylvaraTown_Pokemart_Sign_Text_2:
# 32 "data/maps/OldaleTown/scripts.pory"
	.string "Tienda Pokémon\pTodo lo que un Entrenador necesita\npara el camino.$"

SylvaraTown_BoyWithRalts_Talk_Text_0:
# 41 "data/maps/OldaleTown/scripts.pory"
	.string "Meu Ralts sempre sabe quando eu\nestou triste…\pO problema é que ele também sabe\nquando eu estou aprontando!$"

SylvaraTown_BoyWithRalts_Talk_Text_1:
# 42 "data/maps/OldaleTown/scripts.pory"
	.string "My Ralts always knows when I'm\nfeeling sad…\pThe problem is, it also knows when\nI'm about to do something dumb!$"

SylvaraTown_BoyWithRalts_Talk_Text_2:
# 43 "data/maps/OldaleTown/scripts.pory"
	.string "Mi Ralts siempre sabe cuándo estoy\ntriste…\p¡El problema es que también sabe\ncuándo estoy por hacer alguna\ltontería!$"

SylvaraTown_Ralts_Cry_Text_0:
# 54 "data/maps/OldaleTown/scripts.pory"
	.string "Ralts$"

SylvaraTown_Ralts_Cry_Text_1:
# 55 "data/maps/OldaleTown/scripts.pory"
	.string "Tiii-rii!$"

SylvaraTown_Girl_Talk_Text_0:
# 65 "data/maps/OldaleTown/scripts.pory"
	.string "Às vezes eu caminho pela Floresta\nPendant só para ouvir o som\ldas árvores…\pMas quando o sol começa a\ndesaparecer, eu volto correndo pra\lcasa!$"

SylvaraTown_Girl_Talk_Text_1:
# 66 "data/maps/OldaleTown/scripts.pory"
	.string "Sometimes I walk through Pendant\nForest just to hear the sound\lof the trees…\pBut when the sun starts to fade, I\nrun straight back home!$"

SylvaraTown_Girl_Talk_Text_2:
# 67 "data/maps/OldaleTown/scripts.pory"
	.string "A veces camino por el Bosque\nPendant solo para escuchar el\lsonido de los árboles…\p¡Pero cuando el sol empieza a\nocultarse, regreso corriendo a\lcasa!$"

SylvaraTown_Backpacker_Talk_Text_0:
# 74 "data/maps/OldaleTown/scripts.pory"
	.string "Você sabia que é mais saudável\npara seu Pokémon dar uma Sitrus\lBerry, do quê ele ser acertado por\lum tijolo?$"

SylvaraTown_Backpacker_Talk_Text_1:
# 75 "data/maps/OldaleTown/scripts.pory"
	.string "Did you know it's much healthier\nfor your Pokémon to eat a Sitrus\lBerry than to get hit by a brick?$"

SylvaraTown_Backpacker_Talk_Text_2:
# 76 "data/maps/OldaleTown/scripts.pory"
	.string "¿Sabías que es mucho más saludable\npara tu Pokémon comer una Baya\lZidra que recibir un ladrillazo?$"

SylvaraTown_EventScript_Girl_Trigger_Text_0:
# 95 "data/maps/OldaleTown/scripts.pory"
	.string "Espere um instante!\pTem certeza de que não está\nesquecendo algo antes de\lcontinuar?\pUma jornada é feita de muitos\npassos… e deixar algo inacabado\lpara trás pode trazer\larrependimentos depois.$"

SylvaraTown_EventScript_Girl_Trigger_Text_1:
# 96 "data/maps/OldaleTown/scripts.pory"
	.string "Wait a moment!\pAre you sure you're not forgetting\nsomething before moving on?\pA journey is made of many steps…\nand leaving something unfinished\lbehind may lead to regrets later.$"

SylvaraTown_EventScript_Girl_Trigger_Text_2:
# 97 "data/maps/OldaleTown/scripts.pory"
	.string "¡Espera un momento!\p¿Estás seguro de que no estás\nolvidando algo antes de continuar?\pUn viaje está formado por muchos\npasos… y dejar algo sin terminar\lpuede traer arrepentimientos más\ladelante.$"

SylvaraTown_EventScript_Girl2_Talk_Text_0:
# 140 "data/maps/OldaleTown/scripts.pory"
	.string "Dê sempre o seu melhor.\pE se o seu melhor de hoje for\napenas tirar uma soneca…\pTudo bem também.$"

SylvaraTown_EventScript_Girl2_Talk_Text_1:
# 141 "data/maps/OldaleTown/scripts.pory"
	.string "Always do your best.\pAnd if your best today is simply\ntaking a nap…\pThat's okay too.$"

SylvaraTown_EventScript_Girl2_Talk_Text_2:
# 142 "data/maps/OldaleTown/scripts.pory"
	.string "Da siempre lo mejor de ti.\pY si hoy lo mejor que puedes hacer\nes tomar una siesta…\pTambién está bien.$"
