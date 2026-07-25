StonereachCity_Building2_2F_MapScripts::
	.byte 0


StonereachCity_Building2_2F_EventScript_Expert::
# 4 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	case PT, StonereachCity_Building2_2F_EventScript_Expert_3
# 6 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	case EN, StonereachCity_Building2_2F_EventScript_Expert_4
# 7 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	case ES, StonereachCity_Building2_2F_EventScript_Expert_5
StonereachCity_Building2_2F_EventScript_Expert_1:
	end

StonereachCity_Building2_2F_EventScript_Expert_3:
# 5 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	msgbox StonereachCity_Building2_2F_EventScript_Expert_Text_0, MSGBOX_NPC
	goto StonereachCity_Building2_2F_EventScript_Expert_1

StonereachCity_Building2_2F_EventScript_Expert_4:
# 6 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	msgbox StonereachCity_Building2_2F_EventScript_Expert_Text_1, MSGBOX_NPC
	goto StonereachCity_Building2_2F_EventScript_Expert_1

StonereachCity_Building2_2F_EventScript_Expert_5:
# 7 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	msgbox StonereachCity_Building2_2F_EventScript_Expert_Text_2, MSGBOX_NPC
	goto StonereachCity_Building2_2F_EventScript_Expert_1


StonereachCity_Building2_2F_EventScript_Hiker::
# 13 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	case PT, StonereachCity_Building2_2F_EventScript_Hiker_3
# 15 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	case EN, StonereachCity_Building2_2F_EventScript_Hiker_4
# 16 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	case ES, StonereachCity_Building2_2F_EventScript_Hiker_5
StonereachCity_Building2_2F_EventScript_Hiker_1:
	end

StonereachCity_Building2_2F_EventScript_Hiker_3:
# 14 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	msgbox StonereachCity_Building2_2F_EventScript_Hiker_Text_0, MSGBOX_NPC
	goto StonereachCity_Building2_2F_EventScript_Hiker_1

StonereachCity_Building2_2F_EventScript_Hiker_4:
# 15 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	msgbox StonereachCity_Building2_2F_EventScript_Hiker_Text_1, MSGBOX_NPC
	goto StonereachCity_Building2_2F_EventScript_Hiker_1

StonereachCity_Building2_2F_EventScript_Hiker_5:
# 16 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	msgbox StonereachCity_Building2_2F_EventScript_Hiker_Text_2, MSGBOX_NPC
	goto StonereachCity_Building2_2F_EventScript_Hiker_1


StonereachCity_Building2_2F_EventScript_Woman::
# 22 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	switch VAR_LANGUAGE
# 23 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	case PT, StonereachCity_Building2_2F_EventScript_Woman_3
# 24 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	case EN, StonereachCity_Building2_2F_EventScript_Woman_4
# 25 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	case ES, StonereachCity_Building2_2F_EventScript_Woman_5
StonereachCity_Building2_2F_EventScript_Woman_1:
	end

StonereachCity_Building2_2F_EventScript_Woman_3:
# 23 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	msgbox StonereachCity_Building2_2F_EventScript_Woman_Text_0, MSGBOX_NPC
	goto StonereachCity_Building2_2F_EventScript_Woman_1

StonereachCity_Building2_2F_EventScript_Woman_4:
# 24 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	msgbox StonereachCity_Building2_2F_EventScript_Woman_Text_1, MSGBOX_NPC
	goto StonereachCity_Building2_2F_EventScript_Woman_1

StonereachCity_Building2_2F_EventScript_Woman_5:
# 25 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	msgbox StonereachCity_Building2_2F_EventScript_Woman_Text_2, MSGBOX_NPC
	goto StonereachCity_Building2_2F_EventScript_Woman_1


StonereachCity_Building2_2F_EventScript_Expert_Text_0:
# 5 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	.string "Uma boa treinadora não observa apenas\no adversário.\pEla sente o chão, o vento e até o\nsilêncio antes de dar uma ordem.\pAs batalhas são vencidas um instante\nantes do primeiro movimento.$"

StonereachCity_Building2_2F_EventScript_Expert_Text_1:
# 6 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	.string "A good Trainer doesn't watch only\nthe opponent.\pShe feels the ground, the wind, and\neven the silence before giving an\lorder.\pBattles are won an instant before\nthe first move.$"

StonereachCity_Building2_2F_EventScript_Expert_Text_2:
# 7 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	.string "Una buena Entrenadora no observa\nsolo al rival.\pSiente el suelo, el viento y hasta\nel silencio antes de dar una orden.\pLos combates se ganan un instante\nantes del primer movimiento.$"

StonereachCity_Building2_2F_EventScript_Hiker_Text_0:
# 14 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	.string "Subi muitas montanhas, mas as que\ncercam STONEREACH são diferentes.\pQuando o vento atravessa certas\nfendas, parece formar palavras.\pNunca entendo o que dizem.\nTalvez seja melhor assim.$"

StonereachCity_Building2_2F_EventScript_Hiker_Text_1:
# 15 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	.string "I've climbed many mountains, but\nthe ones around STONEREACH differ.\pWhen wind crosses certain cracks,\nit almost seems to form words.\pI never understand what they say.\nPerhaps that's for the best.$"

StonereachCity_Building2_2F_EventScript_Hiker_Text_2:
# 16 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	.string "Escalé muchas montañas, pero las de\nSTONEREACH son diferentes.\pCuando el viento cruza ciertas\ngrietas, parece formar palabras.\pNunca entiendo lo que dicen.\nQuizá sea mejor así.$"

StonereachCity_Building2_2F_EventScript_Woman_Text_0:
# 23 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	.string "Vim visitar o museu, mas disseram\nque a Professora Hikari está\locupada.\pAlgo importante deve ter sido\ndescoberto.\pQuando cientistas ficam em silêncio,\nos boatos começam a falar por eles.$"

StonereachCity_Building2_2F_EventScript_Woman_Text_1:
# 24 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	.string "I came to visit the museum, but\nthey said Professor Hikari is busy.\pSomething important must have been\ndiscovered.\pWhen scientists fall silent, rumors\nbegin speaking for them.$"

StonereachCity_Building2_2F_EventScript_Woman_Text_2:
# 25 "data/maps/StonereachCity_Building2_2F/scripts.pory"
	.string "Vine a visitar el museo, pero dicen\nque la Profesora Hikari está\locupada.\pAlgo importante debe haberse\ndescubierto.\pCuando los científicos callan, los\nrumores hablan por ellos.$"
