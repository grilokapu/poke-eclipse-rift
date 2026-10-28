StonereachCity_Building2_1F_MapScripts::
	.byte 0


StonereachCity_Building2_1F_EventScript_Scientist::
# 4 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	case PT, StonereachCity_Building2_1F_EventScript_Scientist_3
# 6 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	case EN, StonereachCity_Building2_1F_EventScript_Scientist_4
# 7 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	case ES, StonereachCity_Building2_1F_EventScript_Scientist_5
StonereachCity_Building2_1F_EventScript_Scientist_1:
	end

StonereachCity_Building2_1F_EventScript_Scientist_3:
# 5 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	msgbox StonereachCity_Building2_1F_EventScript_Scientist_Text_0, MSGBOX_NPC
	goto StonereachCity_Building2_1F_EventScript_Scientist_1

StonereachCity_Building2_1F_EventScript_Scientist_4:
# 6 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	msgbox StonereachCity_Building2_1F_EventScript_Scientist_Text_1, MSGBOX_NPC
	goto StonereachCity_Building2_1F_EventScript_Scientist_1

StonereachCity_Building2_1F_EventScript_Scientist_5:
# 7 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	msgbox StonereachCity_Building2_1F_EventScript_Scientist_Text_2, MSGBOX_NPC
	goto StonereachCity_Building2_1F_EventScript_Scientist_1


StonereachCity_Building2_1F_EventScript_Boy::
# 13 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	case PT, StonereachCity_Building2_1F_EventScript_Boy_3
# 15 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	case EN, StonereachCity_Building2_1F_EventScript_Boy_4
# 16 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	case ES, StonereachCity_Building2_1F_EventScript_Boy_5
StonereachCity_Building2_1F_EventScript_Boy_1:
	end

StonereachCity_Building2_1F_EventScript_Boy_3:
# 14 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	msgbox StonereachCity_Building2_1F_EventScript_Boy_Text_0, MSGBOX_NPC
	goto StonereachCity_Building2_1F_EventScript_Boy_1

StonereachCity_Building2_1F_EventScript_Boy_4:
# 15 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	msgbox StonereachCity_Building2_1F_EventScript_Boy_Text_1, MSGBOX_NPC
	goto StonereachCity_Building2_1F_EventScript_Boy_1

StonereachCity_Building2_1F_EventScript_Boy_5:
# 16 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	msgbox StonereachCity_Building2_1F_EventScript_Boy_Text_2, MSGBOX_NPC
	goto StonereachCity_Building2_1F_EventScript_Boy_1


StonereachCity_Building2_1F_EventScript_Scientist_Text_0:
# 5 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	.string "Estou comparando amostras das pedras\nda cidade com as da WHISPERING\lCAVE.\pA composição é quase idêntica…\nmas as da caverna vibram em uma\lfrequência incomum.\pTalvez seja apenas pressão\nsubterrânea.\pÉ isso que continuo dizendo a mim\nmesmo, pelo menos.$"

StonereachCity_Building2_1F_EventScript_Scientist_Text_1:
# 6 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	.string "I'm comparing samples from the city\nwith stones from WHISPERING CAVE.\pTheir composition is nearly\nidentical…\pBut the cave samples vibrate at an\nunusual frequency.\pPerhaps it's only underground\npressure.\pThat's what I keep telling myself,\nat least.$"

StonereachCity_Building2_1F_EventScript_Scientist_Text_2:
# 7 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	.string "Comparo muestras de la ciudad con\npiedras de WHISPERING CAVE.\pSu composición es casi idéntica…\pPero las muestras de la cueva vibran\na una frecuencia inusual.\pQuizá solo sea presión subterránea.\pAl menos, eso sigo diciéndome.$"

StonereachCity_Building2_1F_EventScript_Boy_Text_0:
# 14 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	.string "O cientista disse para eu não tocar\nnas amostras.\pEntão eu só cheguei bem perto e\nfiquei olhando.\pUma delas rolou sozinha.\pNão fui eu! Acho…$"

StonereachCity_Building2_1F_EventScript_Boy_Text_1:
# 15 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	.string "The scientist told me not to touch\nthe samples.\pSo I only got really close and\nstared at them.\pOne of them rolled on its own.\pIt wasn't me! I think…$"

StonereachCity_Building2_1F_EventScript_Boy_Text_2:
# 16 "data/maps/StonereachCity_Building2_1F/scripts.pory"
	.string "El científico dijo que no tocara\nlas muestras.\pSolo me acerqué mucho y las miré.\pUna rodó por sí sola.\p¡No fui yo! Creo…$"
