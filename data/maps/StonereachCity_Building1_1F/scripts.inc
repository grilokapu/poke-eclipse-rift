StonereachCity_Building1_1F_MapScripts::
	.byte 0


StonereachCity_Building1_1F_EventScript_Fisherman::
# 4 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	lock
# 5 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	faceplayer
# 6 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	goto_if_set FLAG_STONEREACH_NPC_TRADE_COMPLETED, StonereachCity_Building1_1F_EventScript_Fisherman_2
# 16 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	switch VAR_LANGUAGE
# 17 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case PT, StonereachCity_Building1_1F_EventScript_Fisherman_6
# 18 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case EN, StonereachCity_Building1_1F_EventScript_Fisherman_7
# 19 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case ES, StonereachCity_Building1_1F_EventScript_Fisherman_8
StonereachCity_Building1_1F_EventScript_Fisherman_4:
# 21 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq StonereachCity_Building1_1F_EventScript_Fisherman_15
# 31 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	specialvar VAR_RESULT, CalculatePlayerPartyCount
# 32 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt StonereachCity_Building1_1F_EventScript_Fisherman_18
# 42 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	checkitemspace ITEM_STARAPTITE
# 43 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq StonereachCity_Building1_1F_EventScript_Fisherman_26
# 53 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	special ChoosePartyMon
# 54 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	lock
# 55 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	faceplayer
# 56 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq StonereachCity_Building1_1F_EventScript_Fisherman_34
# 60 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 61 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	compare VAR_RESULT, SPECIES_STARLY
	goto_if_ne StonereachCity_Building1_1F_EventScript_Fisherman_42
# 71 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	specialvar VAR_RESULT, ScriptTakeSelectedPartyMon
# 72 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq StonereachCity_Building1_1F_EventScript_Fisherman_45
# 76 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	switch VAR_LANGUAGE
# 77 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case PT, StonereachCity_Building1_1F_EventScript_Fisherman_54
# 78 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case EN, StonereachCity_Building1_1F_EventScript_Fisherman_55
# 79 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case ES, StonereachCity_Building1_1F_EventScript_Fisherman_56
StonereachCity_Building1_1F_EventScript_Fisherman_52:
# 81 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	giveitem ITEM_STARAPTITE
# 82 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	setflag FLAG_STONEREACH_NPC_TRADE_COMPLETED
# 83 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	release
	end

StonereachCity_Building1_1F_EventScript_Fisherman_2:
# 7 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	switch VAR_LANGUAGE
# 8 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case PT, StonereachCity_Building1_1F_EventScript_Fisherman_11
# 9 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case EN, StonereachCity_Building1_1F_EventScript_Fisherman_12
# 10 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case ES, StonereachCity_Building1_1F_EventScript_Fisherman_13
StonereachCity_Building1_1F_EventScript_Fisherman_9:
# 12 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	release
	end

StonereachCity_Building1_1F_EventScript_Fisherman_6:
# 17 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_3, MSGBOX_YESNO
	goto StonereachCity_Building1_1F_EventScript_Fisherman_4

StonereachCity_Building1_1F_EventScript_Fisherman_7:
# 18 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_4, MSGBOX_YESNO
	goto StonereachCity_Building1_1F_EventScript_Fisherman_4

StonereachCity_Building1_1F_EventScript_Fisherman_8:
# 19 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_5, MSGBOX_YESNO
	goto StonereachCity_Building1_1F_EventScript_Fisherman_4

StonereachCity_Building1_1F_EventScript_Fisherman_11:
# 8 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_0, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_9

StonereachCity_Building1_1F_EventScript_Fisherman_12:
# 9 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_1, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_9

StonereachCity_Building1_1F_EventScript_Fisherman_13:
# 10 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_2, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_9

StonereachCity_Building1_1F_EventScript_Fisherman_15:
# 22 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	switch VAR_LANGUAGE
# 23 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case PT, StonereachCity_Building1_1F_EventScript_Fisherman_22
# 24 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case EN, StonereachCity_Building1_1F_EventScript_Fisherman_23
# 25 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case ES, StonereachCity_Building1_1F_EventScript_Fisherman_24
StonereachCity_Building1_1F_EventScript_Fisherman_20:
# 27 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	release
	end

StonereachCity_Building1_1F_EventScript_Fisherman_18:
# 33 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	switch VAR_LANGUAGE
# 34 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case PT, StonereachCity_Building1_1F_EventScript_Fisherman_30
# 35 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case EN, StonereachCity_Building1_1F_EventScript_Fisherman_31
# 36 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case ES, StonereachCity_Building1_1F_EventScript_Fisherman_32
StonereachCity_Building1_1F_EventScript_Fisherman_28:
# 38 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	release
	end

StonereachCity_Building1_1F_EventScript_Fisherman_22:
# 23 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_6, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_20

StonereachCity_Building1_1F_EventScript_Fisherman_23:
# 24 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_7, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_20

StonereachCity_Building1_1F_EventScript_Fisherman_24:
# 25 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_8, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_20

StonereachCity_Building1_1F_EventScript_Fisherman_26:
# 44 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	switch VAR_LANGUAGE
# 45 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case PT, StonereachCity_Building1_1F_EventScript_Fisherman_38
# 46 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case EN, StonereachCity_Building1_1F_EventScript_Fisherman_39
# 47 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case ES, StonereachCity_Building1_1F_EventScript_Fisherman_40
StonereachCity_Building1_1F_EventScript_Fisherman_36:
# 49 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	release
	end

StonereachCity_Building1_1F_EventScript_Fisherman_30:
# 34 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_9, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_28

StonereachCity_Building1_1F_EventScript_Fisherman_31:
# 35 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_10, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_28

StonereachCity_Building1_1F_EventScript_Fisherman_32:
# 36 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_11, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_28

StonereachCity_Building1_1F_EventScript_Fisherman_34:
# 57 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	release
	end

StonereachCity_Building1_1F_EventScript_Fisherman_38:
# 45 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_12, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_36

StonereachCity_Building1_1F_EventScript_Fisherman_39:
# 46 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_13, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_36

StonereachCity_Building1_1F_EventScript_Fisherman_40:
# 47 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_14, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_36

StonereachCity_Building1_1F_EventScript_Fisherman_42:
# 62 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	switch VAR_LANGUAGE
# 63 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case PT, StonereachCity_Building1_1F_EventScript_Fisherman_49
# 64 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case EN, StonereachCity_Building1_1F_EventScript_Fisherman_50
# 65 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case ES, StonereachCity_Building1_1F_EventScript_Fisherman_51
StonereachCity_Building1_1F_EventScript_Fisherman_47:
# 67 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	release
	end

StonereachCity_Building1_1F_EventScript_Fisherman_45:
# 73 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	release
	end

StonereachCity_Building1_1F_EventScript_Fisherman_49:
# 63 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_15, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_47

StonereachCity_Building1_1F_EventScript_Fisherman_50:
# 64 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_16, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_47

StonereachCity_Building1_1F_EventScript_Fisherman_51:
# 65 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_17, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_47

StonereachCity_Building1_1F_EventScript_Fisherman_54:
# 77 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_18, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_52

StonereachCity_Building1_1F_EventScript_Fisherman_55:
# 78 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_19, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_52

StonereachCity_Building1_1F_EventScript_Fisherman_56:
# 79 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Fisherman_Text_20, MSGBOX_DEFAULT
	goto StonereachCity_Building1_1F_EventScript_Fisherman_52


StonereachCity_Building1_1F_EventScript_Girl::
# 88 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	switch VAR_LANGUAGE
# 89 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case PT, StonereachCity_Building1_1F_EventScript_Girl_3
# 90 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case EN, StonereachCity_Building1_1F_EventScript_Girl_4
# 91 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	case ES, StonereachCity_Building1_1F_EventScript_Girl_5
StonereachCity_Building1_1F_EventScript_Girl_1:
	end

StonereachCity_Building1_1F_EventScript_Girl_3:
# 89 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Girl_Text_0, MSGBOX_NPC
	goto StonereachCity_Building1_1F_EventScript_Girl_1

StonereachCity_Building1_1F_EventScript_Girl_4:
# 90 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Girl_Text_1, MSGBOX_NPC
	goto StonereachCity_Building1_1F_EventScript_Girl_1

StonereachCity_Building1_1F_EventScript_Girl_5:
# 91 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	msgbox StonereachCity_Building1_1F_EventScript_Girl_Text_2, MSGBOX_NPC
	goto StonereachCity_Building1_1F_EventScript_Girl_1


StonereachCity_Building1_1F_EventScript_Fisherman_Text_0:
# 8 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Seu antigo STARLY está muito bem!\pQuando ele abre as asas, este lugar\nparece pequeno demais para ele.\pCuide bem da STARAPTITE. Um dia,\nela poderá revelar a verdadeira\lforça de um STARAPTOR.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_1:
# 9 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Your old STARLY is doing great!\pWhen it spreads its wings, this\nplace seems far too small for it.\pTake good care of the STARAPTITE.\nOne day, it may reveal a STARAPTOR's\ltrue strength.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_2:
# 10 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "¡Tu antiguo STARLY está muy bien!\pCuando abre las alas, este lugar\nparece demasiado pequeño para él.\pCuida bien la STARAPTITA. Algún día\npodrá revelar la verdadera fuerza\lde un STARAPTOR.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_3:
# 17 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Há anos observo os Pokémon voadores\nque cruzam os penhascos de\lSTONEREACH.\pEncontrei esta pedra brilhando onde\num STARAPTOR pousava todas as\lmanhãs: uma STARAPTITE.\pEu gostaria de criar um STARLY e\nestudar como ele cresce.\pVocê aceitaria trocar um STARLY por\nesta STARAPTITE?$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_4:
# 18 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "For years, I've watched the Flying\nPokémon crossing STONEREACH's\lcliffs.\pI found this stone shining where a\nSTARAPTOR landed every morning:\la STARAPTITE.\pI'd like to raise a STARLY and study\nhow it grows.\pWould you trade a STARLY for this\nSTARAPTITE?$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_5:
# 19 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Durante años observé a los Pokémon\nvoladores cruzar los riscos de\lSTONEREACH.\pEncontré esta piedra brillando donde\nun STARAPTOR aterrizaba cada mañana:\luna STARAPTITA.\pQuisiera criar un STARLY y estudiar\ncómo crece.\p¿Cambiarías un STARLY por esta\nSTARAPTITA?$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_6:
# 23 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Entendo. Uma parceria não deve ser\ndecidida com pressa.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_7:
# 24 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "I understand. A partnership should\nnever be decided in haste.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_8:
# 25 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Lo entiendo. Una amistad no debe\ndecidirse con prisa.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_9:
# 34 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Esse é o seu único Pokémon!\pNão posso deixá-lo seguir viagem\nsozinho. Volte com outra companhia.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_10:
# 35 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "That's your only Pokémon!\pI can't let you continue your\njourney alone. Return with another.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_11:
# 36 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "¡Ese es tu único Pokémon!\pNo puedo dejarte continuar solo.\nRegresa con otro compañero.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_12:
# 45 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Sua Bolsa está cheia.\pAbra espaço antes de fazermos a\ntroca.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_13:
# 46 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Your Bag is full.\pMake some room before we make the\ntrade.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_14:
# 47 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Tu Bolsa está llena.\pHaz espacio antes de realizar el\ncambio.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_15:
# 63 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Este Pokémon não é um STARLY.\pMostre-me o STARLY que deseja\ntrocar.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_16:
# 64 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "This Pokémon isn't a STARLY.\pShow me the STARLY you wish to\ntrade.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_17:
# 65 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Este Pokémon no es un STARLY.\pMuéstrame el STARLY que deseas\ncambiar.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_18:
# 77 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Prometo cuidar muito bem dele.\pE esta pedra agora pertence a você.\nTalvez estivesse esperando pelo\ltreinador certo.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_19:
# 78 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "I promise I'll take very good care\nof it.\pAnd this stone now belongs to you.\nPerhaps it was waiting for the\lright Trainer.$"

StonereachCity_Building1_1F_EventScript_Fisherman_Text_20:
# 79 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Prometo que lo cuidaré muy bien.\pY esta piedra ahora te pertenece.\nQuizá esperaba al Entrenador\lindicado.$"

StonereachCity_Building1_1F_EventScript_Girl_Text_0:
# 89 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Do térreo, o barulho da fonte parece\numa chuva distante.\pÀs vezes fico aqui só para ouvir.\nSTONEREACH também sabe sussurrar.$"

StonereachCity_Building1_1F_EventScript_Girl_Text_1:
# 90 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "From down here, the fountain sounds\nlike distant rain.\pSometimes I stay just to listen.\nSTONEREACH knows how to whisper,\ltoo.$"

StonereachCity_Building1_1F_EventScript_Girl_Text_2:
# 91 "data/maps/StonereachCity_Building1_1F/scripts.pory"
	.string "Desde aquí, la fuente suena como\nlluvia distante.\pA veces me quedo solo para oírla.\nSTONEREACH también sabe susurrar.$"
