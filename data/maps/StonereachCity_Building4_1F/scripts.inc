StonereachCity_Building4_1F_MapScripts::
# 2 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, StonereachCity_Building4_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

StonereachCity_Building4_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	goto_if_set FLAG_DEXNAV_ICONS_UNLOCKED, StonereachCity_Building4_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

StonereachCity_Building4_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	setobjectmovementtype LOCALID_QUIZ_MASTER, MOVEMENT_TYPE_FACE_LEFT
	return


StonereachCity_Building4_1F_EventScript_QuizMaster::
# 10 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	goto_if_set FLAG_DEXNAV_ICONS_UNLOCKED, StonereachCity_Building4_1F_EventScript_QuizMaster_2
# 19 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	switch VAR_LANGUAGE
# 20 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case PT, StonereachCity_Building4_1F_EventScript_QuizMaster_6
# 21 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case EN, StonereachCity_Building4_1F_EventScript_QuizMaster_7
# 22 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case ES, StonereachCity_Building4_1F_EventScript_QuizMaster_8
StonereachCity_Building4_1F_EventScript_QuizMaster_4:
# 24 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq StonereachCity_Building4_1F_EventScript_QuizMaster_15
# 33 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	switch VAR_LANGUAGE
# 34 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case PT, StonereachCity_Building4_1F_EventScript_QuizMaster_19
# 35 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case EN, StonereachCity_Building4_1F_EventScript_QuizMaster_20
# 36 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case ES, StonereachCity_Building4_1F_EventScript_QuizMaster_21
StonereachCity_Building4_1F_EventScript_QuizMaster_17:
# 39 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	special StonereachQuiz_PrepareParty
# 40 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	cleartrainerflag TRAINER_STONEREACH_BATTLE_QUIZ
# 41 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	switch VAR_LANGUAGE
# 42 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case PT, StonereachCity_Building4_1F_EventScript_QuizMaster_29
# 43 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case EN, StonereachCity_Building4_1F_EventScript_QuizMaster_30
# 44 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case ES, StonereachCity_Building4_1F_EventScript_QuizMaster_31
StonereachCity_Building4_1F_EventScript_QuizMaster_27:
# 46 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded
	return

StonereachCity_Building4_1F_EventScript_QuizMaster_2:
# 11 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	switch VAR_LANGUAGE
# 12 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case PT, StonereachCity_Building4_1F_EventScript_QuizMaster_11
# 13 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case EN, StonereachCity_Building4_1F_EventScript_QuizMaster_12
# 14 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case ES, StonereachCity_Building4_1F_EventScript_QuizMaster_13
StonereachCity_Building4_1F_EventScript_QuizMaster_9:
	end

StonereachCity_Building4_1F_EventScript_QuizMaster_6:
# 20 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_3, MSGBOX_YESNO
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_4

StonereachCity_Building4_1F_EventScript_QuizMaster_7:
# 21 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_4, MSGBOX_YESNO
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_4

StonereachCity_Building4_1F_EventScript_QuizMaster_8:
# 22 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_5, MSGBOX_YESNO
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_4

StonereachCity_Building4_1F_EventScript_QuizMaster_11:
# 12 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_0, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_9

StonereachCity_Building4_1F_EventScript_QuizMaster_12:
# 13 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_1, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_9

StonereachCity_Building4_1F_EventScript_QuizMaster_13:
# 14 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_2, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_9

StonereachCity_Building4_1F_EventScript_QuizMaster_15:
# 25 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	switch VAR_LANGUAGE
# 26 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case PT, StonereachCity_Building4_1F_EventScript_QuizMaster_24
# 27 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case EN, StonereachCity_Building4_1F_EventScript_QuizMaster_25
# 28 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case ES, StonereachCity_Building4_1F_EventScript_QuizMaster_26
StonereachCity_Building4_1F_EventScript_QuizMaster_22:
	end

StonereachCity_Building4_1F_EventScript_QuizMaster_19:
# 34 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_9, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_17

StonereachCity_Building4_1F_EventScript_QuizMaster_20:
# 35 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_10, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_17

StonereachCity_Building4_1F_EventScript_QuizMaster_21:
# 36 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_11, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_17

StonereachCity_Building4_1F_EventScript_QuizMaster_24:
# 26 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_6, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_22

StonereachCity_Building4_1F_EventScript_QuizMaster_25:
# 27 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_7, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_22

StonereachCity_Building4_1F_EventScript_QuizMaster_26:
# 28 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizMaster_Text_8, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_22

StonereachCity_Building4_1F_EventScript_QuizMaster_29:
# 42 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	trainerbattle_continue_lost TRAINER_STONEREACH_BATTLE_QUIZ, StonereachCity_Building4_1F_EventScript_QuizMaster_Text_12, StonereachCity_Building4_1F_EventScript_QuizMaster_Text_13, StonereachCity_Building4_1F_EventScript_QuizBattleEnded
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_27

StonereachCity_Building4_1F_EventScript_QuizMaster_30:
# 43 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	trainerbattle_continue_lost TRAINER_STONEREACH_BATTLE_QUIZ, StonereachCity_Building4_1F_EventScript_QuizMaster_Text_14, StonereachCity_Building4_1F_EventScript_QuizMaster_Text_15, StonereachCity_Building4_1F_EventScript_QuizBattleEnded
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_27

StonereachCity_Building4_1F_EventScript_QuizMaster_31:
# 44 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	trainerbattle_continue_lost TRAINER_STONEREACH_BATTLE_QUIZ, StonereachCity_Building4_1F_EventScript_QuizMaster_Text_16, StonereachCity_Building4_1F_EventScript_QuizMaster_Text_17, StonereachCity_Building4_1F_EventScript_QuizBattleEnded
	goto StonereachCity_Building4_1F_EventScript_QuizMaster_27


StonereachCity_Building4_1F_EventScript_QuizBattleEnded::
# 50 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	specialvar VAR_RESULT, StonereachQuiz_Finish
# 51 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	cleartrainerflag TRAINER_STONEREACH_BATTLE_QUIZ
# 53 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq StonereachCity_Building4_1F_EventScript_QuizBattleEnded_2
# 61 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	switch VAR_LANGUAGE
# 62 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case PT, StonereachCity_Building4_1F_EventScript_QuizBattleEnded_17
# 63 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case EN, StonereachCity_Building4_1F_EventScript_QuizBattleEnded_18
# 64 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case ES, StonereachCity_Building4_1F_EventScript_QuizBattleEnded_19
StonereachCity_Building4_1F_EventScript_QuizBattleEnded_1:
# 67 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq StonereachCity_Building4_1F_EventScript_QuizBattleEnded_6
# 69 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq StonereachCity_Building4_1F_EventScript_QuizBattleEnded_7
# 71 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq StonereachCity_Building4_1F_EventScript_QuizBattleEnded_8
StonereachCity_Building4_1F_EventScript_QuizBattleEnded_5:
# 74 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	release
	end

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_2:
# 54 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	setflag FLAG_DEXNAV_ICONS_UNLOCKED
# 55 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	switch VAR_LANGUAGE
# 56 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case PT, StonereachCity_Building4_1F_EventScript_QuizBattleEnded_13
# 57 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case EN, StonereachCity_Building4_1F_EventScript_QuizBattleEnded_14
# 58 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	case ES, StonereachCity_Building4_1F_EventScript_QuizBattleEnded_15
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_1

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_6:
# 68 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	setobjectmovementtype LOCALID_QUIZ_MASTER, MOVEMENT_TYPE_FACE_UP
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_5

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_7:
# 70 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	setobjectmovementtype LOCALID_QUIZ_MASTER, MOVEMENT_TYPE_FACE_RIGHT
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_5

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_8:
# 72 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	setobjectmovementtype LOCALID_QUIZ_MASTER, MOVEMENT_TYPE_FACE_DOWN
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_5

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_13:
# 56 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_0, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_1

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_14:
# 57 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_1, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_1

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_15:
# 58 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_2, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_1

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_17:
# 62 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_3, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_1

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_18:
# 63 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_4, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_1

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_19:
# 64 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	msgbox StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_5, MSGBOX_NPC
	goto StonereachCity_Building4_1F_EventScript_QuizBattleEnded_1


StonereachCity_Building4_1F_EventScript_QuizMaster_Text_0:
# 12 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Você já provou que sabe ler uma\nbatalha antes de vencê-la.\pA DEXNAV continuará revelando os\nPokémon de cada área para você.$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_1:
# 13 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "You proved you can read a battle\nbefore winning it.\pThe DEXNAV will keep revealing each\narea's Pokémon to you.$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_2:
# 14 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Demostraste que puedes leer un\ncombate antes de ganarlo.\pLa DEXNAV seguirá revelando los\nPokémon de cada zona.$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_3:
# 20 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Eu estudo decisões em batalha.\pVocê receberá apenas três Pokémon\npara enfrentar os meus seis.\pSua equipe verdadeira ficará segura.\nAqui, vencer depende de reconhecer\lvantagens e saber quando trocar.\pQuer tentar o Enigma Tático?$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_4:
# 21 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "I study decisions made in battle.\pYou will receive only three Pokémon\nto face my six.\pYour real party will remain safe.\nVictory depends on recognizing an\ladvantage and knowing when to switch.\pTry the Tactical Riddle?$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_5:
# 22 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Estudio las decisiones en combate.\pRecibirás solo tres Pokémon para\nenfrentar a mis seis.\pTu equipo real estará seguro.\nVencer exige reconocer ventajas y\lsaber cuándo cambiar.\p¿Intentas el Enigma Táctico?$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_6:
# 26 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Uma boa resposta também pode ser\nesperar até estar preparado.$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_7:
# 27 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Waiting until you are ready can be\na good answer, too.$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_8:
# 28 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Esperar hasta estar listo también\npuede ser una buena respuesta.$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_9:
# 34 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Meus Pokémon rápidos atacarão antes.\pAlguns sobrevivem com 1 HP e usam\nENDEAVOR seguido de prioridade.\pSTURDY e BERRY JUICE também podem\nrenovar essa armadilha.\pGolpes múltiplos quebram essas\ndefesas. Prioridade encerra o plano\nantes do segundo movimento.$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_10:
# 35 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "My fast Pokémon will move first.\pSome endure at 1 HP, then use\nENDEAVOR followed by priority.\pSTURDY and BERRY JUICE can renew the\nsame trap.\pMulti-hit moves break those defenses.\nPriority ends the plan before its\nsecond move.$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_11:
# 36 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Mis Pokémon rápidos atacarán antes.\pAlgunos resisten con 1 PS y usan\nENDEAVOR seguido de prioridad.\pSTURDY y BERRY JUICE pueden renovar\nla misma trampa.\pLos golpes múltiples rompen esas\ndefensas. La prioridad detiene el\nsegundo movimiento.$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_12:
# 42 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Seis desafios. Três respostas.\nEscolha cada uma com cuidado!$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_13:
# 42 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Você encontrou resposta para todos…$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_14:
# 43 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Six challenges. Three answers.\nChoose each one carefully!$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_15:
# 43 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "You found an answer for them all…$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_16:
# 44 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Seis desafíos. Tres respuestas.\n¡Elige cada una con cuidado!$"

StonereachCity_Building4_1F_EventScript_QuizMaster_Text_17:
# 44 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Hallaste respuesta para todos…$"

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_0:
# 56 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Perfeito. Você não venceu por acaso;\nvenceu porque compreendeu o fluxo.\pComo prêmio, liberei a leitura\navançada da sua DEXNAV!\pA partir de agora, os ícones dos\nPokémon de cada área serão visíveis,\nmesmo antes de encontrá-los.$"

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_1:
# 57 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Perfect. You did not win by chance;\nyou understood the flow.\pAs your prize, I unlocked advanced\nscanning on your DEXNAV!\pFrom now on, each area's Pokémon\nicons are visible before you meet\nthem.$"

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_2:
# 58 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Perfecto. No ganaste por azar;\ncomprendiste el flujo.\p¡Como premio, desbloqueé el análisis\navanzado de tu DEXNAV!\pAhora verás los iconos de cada zona\nantes de encontrar a sus Pokémon.$"

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_3:
# 62 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Força sozinha não sustenta seis\nconfrontos.\pObserve os tipos antes de atacar e\ntroque antes que a vantagem desapareça.\pSua equipe original já foi\nrestaurada. Tente novamente.$"

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_4:
# 63 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "Strength alone cannot carry six\nmatchups.\pRead the types before attacking and\nswitch before your advantage is lost.\pYour original party is restored.\nTry again whenever you wish.$"

StonereachCity_Building4_1F_EventScript_QuizBattleEnded_Text_5:
# 64 "data/maps/StonereachCity_Building4_1F/scripts.pory"
	.string "La fuerza sola no supera seis\nenfrentamientos.\pObserva los tipos antes de atacar y\ncambia antes de perder la ventaja.\pTu equipo original fue restaurado.\nInténtalo de nuevo.$"
