MossvaleTown_House_3_MapScripts::
	.byte 0


MossvaleTown_House_3_EventScript_Reader::
# 4 "data/maps/MossvaleTown_House_3/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/MossvaleTown_House_3/scripts.pory"
	case PT, MossvaleTown_House_3_EventScript_Reader_3
# 6 "data/maps/MossvaleTown_House_3/scripts.pory"
	case EN, MossvaleTown_House_3_EventScript_Reader_4
# 7 "data/maps/MossvaleTown_House_3/scripts.pory"
	case ES, MossvaleTown_House_3_EventScript_Reader_5
MossvaleTown_House_3_EventScript_Reader_1:
	end

MossvaleTown_House_3_EventScript_Reader_3:
# 5 "data/maps/MossvaleTown_House_3/scripts.pory"
	msgbox MossvaleTown_House_3_EventScript_Reader_Text_0, MSGBOX_NPC
	goto MossvaleTown_House_3_EventScript_Reader_1

MossvaleTown_House_3_EventScript_Reader_4:
# 6 "data/maps/MossvaleTown_House_3/scripts.pory"
	msgbox MossvaleTown_House_3_EventScript_Reader_Text_1, MSGBOX_NPC
	goto MossvaleTown_House_3_EventScript_Reader_1

MossvaleTown_House_3_EventScript_Reader_5:
# 7 "data/maps/MossvaleTown_House_3/scripts.pory"
	msgbox MossvaleTown_House_3_EventScript_Reader_Text_2, MSGBOX_NPC
	goto MossvaleTown_House_3_EventScript_Reader_1


MossvaleTown_House_3_EventScript_Boy::
# 13 "data/maps/MossvaleTown_House_3/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/MossvaleTown_House_3/scripts.pory"
	case PT, MossvaleTown_House_3_EventScript_Boy_3
# 15 "data/maps/MossvaleTown_House_3/scripts.pory"
	case EN, MossvaleTown_House_3_EventScript_Boy_4
# 16 "data/maps/MossvaleTown_House_3/scripts.pory"
	case ES, MossvaleTown_House_3_EventScript_Boy_5
MossvaleTown_House_3_EventScript_Boy_1:
	end

MossvaleTown_House_3_EventScript_Boy_3:
# 14 "data/maps/MossvaleTown_House_3/scripts.pory"
	msgbox MossvaleTown_House_3_EventScript_Boy_Text_0, MSGBOX_NPC
	goto MossvaleTown_House_3_EventScript_Boy_1

MossvaleTown_House_3_EventScript_Boy_4:
# 15 "data/maps/MossvaleTown_House_3/scripts.pory"
	msgbox MossvaleTown_House_3_EventScript_Boy_Text_1, MSGBOX_NPC
	goto MossvaleTown_House_3_EventScript_Boy_1

MossvaleTown_House_3_EventScript_Boy_5:
# 16 "data/maps/MossvaleTown_House_3/scripts.pory"
	msgbox MossvaleTown_House_3_EventScript_Boy_Text_2, MSGBOX_NPC
	goto MossvaleTown_House_3_EventScript_Boy_1


MossvaleTown_House_3_EventScript_Reader_Text_0:
# 5 "data/maps/MossvaleTown_House_3/scripts.pory"
	.string "Gosto de ler ouvindo a chuva.\pSó preciso tomar cuidado\npara não cochilar e perder\la página.\pMeu recorde é ler a mesma\npágina cinco vezes.$"

MossvaleTown_House_3_EventScript_Reader_Text_1:
# 6 "data/maps/MossvaleTown_House_3/scripts.pory"
	.string "I like reading to the sound\nof rain.\pI just have to avoid dozing\noff and losing my place.\pMy record is reading the\nsame page five times.$"

MossvaleTown_House_3_EventScript_Reader_Text_2:
# 7 "data/maps/MossvaleTown_House_3/scripts.pory"
	.string "Me gusta leer mientras\nescucho la lluvia.\pDebo evitar quedarme dormido\ny perder la página.\pMi récord es leer la misma\npágina cinco veces.$"

MossvaleTown_House_3_EventScript_Boy_Text_0:
# 14 "data/maps/MossvaleTown_House_3/scripts.pory"
	.string "Quero desenhar todos os\nPOKéMON que vivem por aqui.\pAté agora desenhei três.\nMinha mãe acha que são\ltrês batatas.$"

MossvaleTown_House_3_EventScript_Boy_Text_1:
# 15 "data/maps/MossvaleTown_House_3/scripts.pory"
	.string "I want to draw every POKéMON\nthat lives around here.\pSo far, I have drawn three.\nMom thinks they are\lthree potatoes.$"

MossvaleTown_House_3_EventScript_Boy_Text_2:
# 16 "data/maps/MossvaleTown_House_3/scripts.pory"
	.string "Quiero dibujar a todos los\nPOKéMON que viven por aquí.\pHasta ahora dibujé tres.\nMi madre cree que son\ltres patatas.$"
