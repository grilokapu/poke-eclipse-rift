StonereachCity_Building3_2F_MapScripts::
	.byte 0


StonereachCity_Building3_2F_EventScript_Artist::
# 4 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	case PT, StonereachCity_Building3_2F_EventScript_Artist_3
# 6 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	case EN, StonereachCity_Building3_2F_EventScript_Artist_4
# 7 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	case ES, StonereachCity_Building3_2F_EventScript_Artist_5
StonereachCity_Building3_2F_EventScript_Artist_1:
	end

StonereachCity_Building3_2F_EventScript_Artist_3:
# 5 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	msgbox StonereachCity_Building3_2F_EventScript_Artist_Text_0, MSGBOX_NPC
	goto StonereachCity_Building3_2F_EventScript_Artist_1

StonereachCity_Building3_2F_EventScript_Artist_4:
# 6 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	msgbox StonereachCity_Building3_2F_EventScript_Artist_Text_1, MSGBOX_NPC
	goto StonereachCity_Building3_2F_EventScript_Artist_1

StonereachCity_Building3_2F_EventScript_Artist_5:
# 7 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	msgbox StonereachCity_Building3_2F_EventScript_Artist_Text_2, MSGBOX_NPC
	goto StonereachCity_Building3_2F_EventScript_Artist_1


StonereachCity_Building3_2F_EventScript_Artist_Text_0:
# 5 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	.string "Pinto a cidade ao entardecer.\pDurante poucos minutos, a pedra\ncinzenta ganha tons de ouro e\lvioleta.\pAs pessoas dizem que STONEREACH é\nsevera.\pTalvez nunca tenham esperado a luz\ncerta.$"

StonereachCity_Building3_2F_EventScript_Artist_Text_1:
# 6 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	.string "I paint the city at sunset.\pFor a few minutes, the gray stone\nturns gold and violet.\pPeople say STONEREACH is stern.\pPerhaps they never waited for the\nright light.$"

StonereachCity_Building3_2F_EventScript_Artist_Text_2:
# 7 "data/maps/StonereachCity_Building3_2F/scripts.pory"
	.string "Pinto la ciudad al atardecer.\pPor unos minutos, la piedra gris se\nvuelve dorada y violeta.\pDicen que STONEREACH es severa.\pQuizá nunca esperaron la luz\nadecuada.$"
