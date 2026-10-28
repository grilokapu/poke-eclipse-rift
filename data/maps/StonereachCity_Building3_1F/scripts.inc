StonereachCity_Building3_1F_MapScripts::
	.byte 0


StonereachCity_Building3_1F_EventScript_Pokefan::
# 4 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	case PT, StonereachCity_Building3_1F_EventScript_Pokefan_3
# 6 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	case EN, StonereachCity_Building3_1F_EventScript_Pokefan_4
# 7 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	case ES, StonereachCity_Building3_1F_EventScript_Pokefan_5
StonereachCity_Building3_1F_EventScript_Pokefan_1:
	end

StonereachCity_Building3_1F_EventScript_Pokefan_3:
# 5 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	msgbox StonereachCity_Building3_1F_EventScript_Pokefan_Text_0, MSGBOX_NPC
	goto StonereachCity_Building3_1F_EventScript_Pokefan_1

StonereachCity_Building3_1F_EventScript_Pokefan_4:
# 6 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	msgbox StonereachCity_Building3_1F_EventScript_Pokefan_Text_1, MSGBOX_NPC
	goto StonereachCity_Building3_1F_EventScript_Pokefan_1

StonereachCity_Building3_1F_EventScript_Pokefan_5:
# 7 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	msgbox StonereachCity_Building3_1F_EventScript_Pokefan_Text_2, MSGBOX_NPC
	goto StonereachCity_Building3_1F_EventScript_Pokefan_1


StonereachCity_Building3_1F_EventScript_LittleGirl::
# 13 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	case PT, StonereachCity_Building3_1F_EventScript_LittleGirl_3
# 15 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	case EN, StonereachCity_Building3_1F_EventScript_LittleGirl_4
# 16 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	case ES, StonereachCity_Building3_1F_EventScript_LittleGirl_5
StonereachCity_Building3_1F_EventScript_LittleGirl_1:
	end

StonereachCity_Building3_1F_EventScript_LittleGirl_3:
# 14 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	msgbox StonereachCity_Building3_1F_EventScript_LittleGirl_Text_0, MSGBOX_NPC
	goto StonereachCity_Building3_1F_EventScript_LittleGirl_1

StonereachCity_Building3_1F_EventScript_LittleGirl_4:
# 15 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	msgbox StonereachCity_Building3_1F_EventScript_LittleGirl_Text_1, MSGBOX_NPC
	goto StonereachCity_Building3_1F_EventScript_LittleGirl_1

StonereachCity_Building3_1F_EventScript_LittleGirl_5:
# 16 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	msgbox StonereachCity_Building3_1F_EventScript_LittleGirl_Text_2, MSGBOX_NPC
	goto StonereachCity_Building3_1F_EventScript_LittleGirl_1


StonereachCity_Building3_1F_EventScript_OldMan::
# 22 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	switch VAR_LANGUAGE
# 23 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	case PT, StonereachCity_Building3_1F_EventScript_OldMan_3
# 24 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	case EN, StonereachCity_Building3_1F_EventScript_OldMan_4
# 25 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	case ES, StonereachCity_Building3_1F_EventScript_OldMan_5
StonereachCity_Building3_1F_EventScript_OldMan_1:
	end

StonereachCity_Building3_1F_EventScript_OldMan_3:
# 23 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	msgbox StonereachCity_Building3_1F_EventScript_OldMan_Text_0, MSGBOX_NPC
	goto StonereachCity_Building3_1F_EventScript_OldMan_1

StonereachCity_Building3_1F_EventScript_OldMan_4:
# 24 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	msgbox StonereachCity_Building3_1F_EventScript_OldMan_Text_1, MSGBOX_NPC
	goto StonereachCity_Building3_1F_EventScript_OldMan_1

StonereachCity_Building3_1F_EventScript_OldMan_5:
# 25 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	msgbox StonereachCity_Building3_1F_EventScript_OldMan_Text_2, MSGBOX_NPC
	goto StonereachCity_Building3_1F_EventScript_OldMan_1


StonereachCity_Building3_1F_EventScript_Pokefan_Text_0:
# 5 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	.string "Meu SKITTY costumava se esconder\nquando ouvia o sino da cidade.\pAgora ele corre até a janela para\nescutar.\pPokémon também criam lembranças dos\nlugares onde vivem.$"

StonereachCity_Building3_1F_EventScript_Pokefan_Text_1:
# 6 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	.string "My SKITTY used to hide whenever it\nheard the city's bell.\pNow it runs to the window to listen.\pPokémon make memories of the places\nthey live in, too.$"

StonereachCity_Building3_1F_EventScript_Pokefan_Text_2:
# 7 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	.string "Mi SKITTY se escondía al escuchar la\ncampana de la ciudad.\pAhora corre a la ventana para oírla.\pLos Pokémon también crean recuerdos\nde los lugares donde viven.$"

StonereachCity_Building3_1F_EventScript_LittleGirl_Text_0:
# 14 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	.string "Estou treinando para ser Líder de\nGinásio!\pMinha especialidade será… todos os\ntipos!\pAssim ninguém vai conseguir\nadivinhar minha estratégia!$"

StonereachCity_Building3_1F_EventScript_LittleGirl_Text_1:
# 15 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	.string "I'm training to become a Gym\nLeader!\pMy specialty will be… every type!\pThat way, nobody will ever guess my\nstrategy!$"

StonereachCity_Building3_1F_EventScript_LittleGirl_Text_2:
# 16 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	.string "¡Entreno para ser Líder de\nGimnasio!\pMi especialidad será… ¡todos los\ntipos!\p¡Así nadie adivinará mi estrategia!$"

StonereachCity_Building3_1F_EventScript_OldMan_Text_0:
# 23 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	.string "Ajudei a erguer alguns dos primeiros\nprédios de STONEREACH.\pTodos pensam que o segredo está na\npedra.\pMas uma parede só permanece de pé\nquando cada peça aprende a sustentar\la outra.$"

StonereachCity_Building3_1F_EventScript_OldMan_Text_1:
# 24 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	.string "I helped raise some of STONEREACH's\nfirst buildings.\pEveryone thinks the secret lies in\nthe stone.\pBut a wall stands only when every\npiece learns to support the next.$"

StonereachCity_Building3_1F_EventScript_OldMan_Text_2:
# 25 "data/maps/StonereachCity_Building3_1F/scripts.pory"
	.string "Ayudé a levantar algunos de los\nprimeros edificios de STONEREACH.\pTodos creen que el secreto está en\nla piedra.\pPero un muro sigue en pie cuando\ncada pieza sostiene a la siguiente.$"
