StonereachCity_Building1_2F_MapScripts::
	.byte 0


StonereachCity_Building1_2F_EventScript_Gentleman::
# 4 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	lock
# 5 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	faceplayer
# 6 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_STONEREACH, StonereachCity_Building1_2F_EventScript_Gentleman_2
# 15 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	switch VAR_LANGUAGE
# 16 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case PT, StonereachCity_Building1_2F_EventScript_Gentleman_6
# 17 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case EN, StonereachCity_Building1_2F_EventScript_Gentleman_7
# 18 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case ES, StonereachCity_Building1_2F_EventScript_Gentleman_8
StonereachCity_Building1_2F_EventScript_Gentleman_4:
# 20 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	checkitemspace ITEM_PREMIER_BALL
# 21 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq StonereachCity_Building1_2F_EventScript_Gentleman_15
# 30 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	giveitem ITEM_PREMIER_BALL
# 31 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	setflag FLAG_RECEIVED_PREMIER_BALL_STONEREACH
# 32 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	release
	end

StonereachCity_Building1_2F_EventScript_Gentleman_2:
# 7 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	switch VAR_LANGUAGE
# 8 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case PT, StonereachCity_Building1_2F_EventScript_Gentleman_11
# 9 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case EN, StonereachCity_Building1_2F_EventScript_Gentleman_12
# 10 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case ES, StonereachCity_Building1_2F_EventScript_Gentleman_13
StonereachCity_Building1_2F_EventScript_Gentleman_9:
# 12 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	release
	end

StonereachCity_Building1_2F_EventScript_Gentleman_6:
# 16 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Gentleman_Text_3, MSGBOX_DEFAULT
	goto StonereachCity_Building1_2F_EventScript_Gentleman_4

StonereachCity_Building1_2F_EventScript_Gentleman_7:
# 17 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Gentleman_Text_4, MSGBOX_DEFAULT
	goto StonereachCity_Building1_2F_EventScript_Gentleman_4

StonereachCity_Building1_2F_EventScript_Gentleman_8:
# 18 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Gentleman_Text_5, MSGBOX_DEFAULT
	goto StonereachCity_Building1_2F_EventScript_Gentleman_4

StonereachCity_Building1_2F_EventScript_Gentleman_11:
# 8 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Gentleman_Text_0, MSGBOX_DEFAULT
	goto StonereachCity_Building1_2F_EventScript_Gentleman_9

StonereachCity_Building1_2F_EventScript_Gentleman_12:
# 9 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Gentleman_Text_1, MSGBOX_DEFAULT
	goto StonereachCity_Building1_2F_EventScript_Gentleman_9

StonereachCity_Building1_2F_EventScript_Gentleman_13:
# 10 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Gentleman_Text_2, MSGBOX_DEFAULT
	goto StonereachCity_Building1_2F_EventScript_Gentleman_9

StonereachCity_Building1_2F_EventScript_Gentleman_15:
# 22 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	switch VAR_LANGUAGE
# 23 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case PT, StonereachCity_Building1_2F_EventScript_Gentleman_19
# 24 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case EN, StonereachCity_Building1_2F_EventScript_Gentleman_20
# 25 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case ES, StonereachCity_Building1_2F_EventScript_Gentleman_21
StonereachCity_Building1_2F_EventScript_Gentleman_17:
# 27 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	release
	end

StonereachCity_Building1_2F_EventScript_Gentleman_19:
# 23 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Gentleman_Text_6, MSGBOX_DEFAULT
	goto StonereachCity_Building1_2F_EventScript_Gentleman_17

StonereachCity_Building1_2F_EventScript_Gentleman_20:
# 24 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Gentleman_Text_7, MSGBOX_DEFAULT
	goto StonereachCity_Building1_2F_EventScript_Gentleman_17

StonereachCity_Building1_2F_EventScript_Gentleman_21:
# 25 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Gentleman_Text_8, MSGBOX_DEFAULT
	goto StonereachCity_Building1_2F_EventScript_Gentleman_17


StonereachCity_Building1_2F_EventScript_Collector::
# 37 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	switch VAR_LANGUAGE
# 38 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case PT, StonereachCity_Building1_2F_EventScript_Collector_3
# 39 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case EN, StonereachCity_Building1_2F_EventScript_Collector_4
# 40 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case ES, StonereachCity_Building1_2F_EventScript_Collector_5
StonereachCity_Building1_2F_EventScript_Collector_1:
	end

StonereachCity_Building1_2F_EventScript_Collector_3:
# 38 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Collector_Text_0, MSGBOX_NPC
	goto StonereachCity_Building1_2F_EventScript_Collector_1

StonereachCity_Building1_2F_EventScript_Collector_4:
# 39 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Collector_Text_1, MSGBOX_NPC
	goto StonereachCity_Building1_2F_EventScript_Collector_1

StonereachCity_Building1_2F_EventScript_Collector_5:
# 40 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Collector_Text_2, MSGBOX_NPC
	goto StonereachCity_Building1_2F_EventScript_Collector_1


StonereachCity_Building1_2F_EventScript_Woman::
# 46 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	switch VAR_LANGUAGE
# 47 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case PT, StonereachCity_Building1_2F_EventScript_Woman_3
# 48 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case EN, StonereachCity_Building1_2F_EventScript_Woman_4
# 49 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	case ES, StonereachCity_Building1_2F_EventScript_Woman_5
StonereachCity_Building1_2F_EventScript_Woman_1:
	end

StonereachCity_Building1_2F_EventScript_Woman_3:
# 47 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Woman_Text_0, MSGBOX_NPC
	goto StonereachCity_Building1_2F_EventScript_Woman_1

StonereachCity_Building1_2F_EventScript_Woman_4:
# 48 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Woman_Text_1, MSGBOX_NPC
	goto StonereachCity_Building1_2F_EventScript_Woman_1

StonereachCity_Building1_2F_EventScript_Woman_5:
# 49 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	msgbox StonereachCity_Building1_2F_EventScript_Woman_Text_2, MSGBOX_NPC
	goto StonereachCity_Building1_2F_EventScript_Woman_1


StonereachCity_Building1_2F_EventScript_Gentleman_Text_0:
# 8 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "Uma PREMIER BALL não torna a captura\nmais fácil.\pMas um momento importante merece\nser lembrado com elegância, não\lacha?$"

StonereachCity_Building1_2F_EventScript_Gentleman_Text_1:
# 9 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "A PREMIER BALL doesn't make a catch\nany easier.\pBut an important moment deserves to\nbe remembered with elegance,\ldoesn't it?$"

StonereachCity_Building1_2F_EventScript_Gentleman_Text_2:
# 10 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "Una HONOR BALL no facilita una\ncaptura.\pPero un momento importante merece\nser recordado con elegancia,\l¿no crees?$"

StonereachCity_Building1_2F_EventScript_Gentleman_Text_3:
# 16 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "As pessoas daqui valorizam pedras\nraras, mas eu coleciono momentos.\pEsta PREMIER BALL estava guardada\npara uma ocasião especial.\pSeu olhar diz que você encontrará\numa antes de mim. Pode ficar com\lela.$"

StonereachCity_Building1_2F_EventScript_Gentleman_Text_4:
# 17 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "People here value rare stones, but\nI collect moments.\pThis PREMIER BALL was saved for a\nspecial occasion.\pYour eyes say you'll find one before\nI do. You may have it.$"

StonereachCity_Building1_2F_EventScript_Gentleman_Text_5:
# 18 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "Aquí valoran las piedras raras, pero\nyo colecciono momentos.\pGuardaba esta HONOR BALL para una\nocasión especial.\pTu mirada dice que hallarás una antes\nque yo. Puedes quedártela.$"

StonereachCity_Building1_2F_EventScript_Gentleman_Text_6:
# 23 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "Parece que sua Bolsa está cheia.\nVolte quando tiver espaço.$"

StonereachCity_Building1_2F_EventScript_Gentleman_Text_7:
# 24 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "It seems your Bag is full.\nCome back when you have room.$"

StonereachCity_Building1_2F_EventScript_Gentleman_Text_8:
# 25 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "Parece que tu Bolsa está llena.\nRegresa cuando tengas espacio.$"

StonereachCity_Building1_2F_EventScript_Collector_Text_0:
# 38 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "Dizem que toda pedra guarda uma\nhistória.\pEntão deixei uma na janela por dez\nanos.\pAté agora, a única história que ela\nguarda é a de nunca ter saído do\llugar.$"

StonereachCity_Building1_2F_EventScript_Collector_Text_1:
# 39 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "They say every stone holds a story.\pSo I left one by the window for ten\nyears.\pSo far, its only story is that it\nhas never moved.$"

StonereachCity_Building1_2F_EventScript_Collector_Text_2:
# 40 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "Dicen que cada piedra guarda una\nhistoria.\pDejé una junto a la ventana por\ndiez años.\pHasta ahora, su única historia es\nque nunca se movió.$"

StonereachCity_Building1_2F_EventScript_Woman_Text_0:
# 47 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "Lá de cima, consigo ver treinadores\nentrando na cidade.\pAlguns olham para os prédios.\nOutros, para o Ginásio.\pOs mais curiosos olham para as\nmontanhas, como se algo os chamasse.$"

StonereachCity_Building1_2F_EventScript_Woman_Text_1:
# 48 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "From up here, I can see Trainers\nentering the city.\pSome look at the buildings. Others\nlook at the Gym.\pThe curious ones look toward the\nmountains, as if something were\lcalling them.$"

StonereachCity_Building1_2F_EventScript_Woman_Text_2:
# 49 "data/maps/StonereachCity_Building1_2F/scripts.pory"
	.string "Desde aquí veo a los Entrenadores\nentrar en la ciudad.\pUnos miran los edificios. Otros, el\nGimnasio.\pLos más curiosos miran las montañas,\ncomo si algo los llamara.$"
