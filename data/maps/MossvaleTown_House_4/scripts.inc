MossvaleTown_House_4_MapScripts::
	.byte 0


MossvaleTown_House_4_EventScript_Girl::
# 4 "data/maps/MossvaleTown_House_4/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/MossvaleTown_House_4/scripts.pory"
	case PT, MossvaleTown_House_4_EventScript_Girl_3
# 6 "data/maps/MossvaleTown_House_4/scripts.pory"
	case EN, MossvaleTown_House_4_EventScript_Girl_4
# 7 "data/maps/MossvaleTown_House_4/scripts.pory"
	case ES, MossvaleTown_House_4_EventScript_Girl_5
MossvaleTown_House_4_EventScript_Girl_1:
	end

MossvaleTown_House_4_EventScript_Girl_3:
# 5 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Girl_Text_0, MSGBOX_NPC
	goto MossvaleTown_House_4_EventScript_Girl_1

MossvaleTown_House_4_EventScript_Girl_4:
# 6 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Girl_Text_1, MSGBOX_NPC
	goto MossvaleTown_House_4_EventScript_Girl_1

MossvaleTown_House_4_EventScript_Girl_5:
# 7 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Girl_Text_2, MSGBOX_NPC
	goto MossvaleTown_House_4_EventScript_Girl_1


MossvaleTown_House_4_EventScript_Fisherman::
# 13 "data/maps/MossvaleTown_House_4/scripts.pory"
	lock
# 14 "data/maps/MossvaleTown_House_4/scripts.pory"
	faceplayer
# 15 "data/maps/MossvaleTown_House_4/scripts.pory"
	goto_if_set FLAG_RECEIVED_OLD_ROD, MossvaleTown_House_4_EventScript_Fisherman_2
# 20 "data/maps/MossvaleTown_House_4/scripts.pory"
	checkitem ITEM_OLD_ROD
# 21 "data/maps/MossvaleTown_House_4/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MossvaleTown_House_4_EventScript_Fisherman_5
# 27 "data/maps/MossvaleTown_House_4/scripts.pory"
	switch VAR_LANGUAGE
# 28 "data/maps/MossvaleTown_House_4/scripts.pory"
	case PT, MossvaleTown_House_4_EventScript_Fisherman_9
# 29 "data/maps/MossvaleTown_House_4/scripts.pory"
	case EN, MossvaleTown_House_4_EventScript_Fisherman_10
# 30 "data/maps/MossvaleTown_House_4/scripts.pory"
	case ES, MossvaleTown_House_4_EventScript_Fisherman_11
MossvaleTown_House_4_EventScript_Fisherman_7:
# 32 "data/maps/MossvaleTown_House_4/scripts.pory"
	call MossvaleTown_House_4_EventScript_FishingLesson
# 33 "data/maps/MossvaleTown_House_4/scripts.pory"
	switch VAR_LANGUAGE
# 34 "data/maps/MossvaleTown_House_4/scripts.pory"
	case PT, MossvaleTown_House_4_EventScript_Fisherman_14
# 35 "data/maps/MossvaleTown_House_4/scripts.pory"
	case EN, MossvaleTown_House_4_EventScript_Fisherman_15
# 36 "data/maps/MossvaleTown_House_4/scripts.pory"
	case ES, MossvaleTown_House_4_EventScript_Fisherman_16
MossvaleTown_House_4_EventScript_Fisherman_12:
# 38 "data/maps/MossvaleTown_House_4/scripts.pory"
	giveitem ITEM_OLD_ROD
# 39 "data/maps/MossvaleTown_House_4/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossvaleTown_House_4_EventScript_Fisherman_18
# 48 "data/maps/MossvaleTown_House_4/scripts.pory"
	setflag FLAG_RECEIVED_OLD_ROD
# 49 "data/maps/MossvaleTown_House_4/scripts.pory"
	switch VAR_LANGUAGE
# 50 "data/maps/MossvaleTown_House_4/scripts.pory"
	case PT, MossvaleTown_House_4_EventScript_Fisherman_22
# 51 "data/maps/MossvaleTown_House_4/scripts.pory"
	case EN, MossvaleTown_House_4_EventScript_Fisherman_23
# 52 "data/maps/MossvaleTown_House_4/scripts.pory"
	case ES, MossvaleTown_House_4_EventScript_Fisherman_24
MossvaleTown_House_4_EventScript_Fisherman_20:
# 54 "data/maps/MossvaleTown_House_4/scripts.pory"
	release
	end

MossvaleTown_House_4_EventScript_Fisherman_2:
# 16 "data/maps/MossvaleTown_House_4/scripts.pory"
	call MossvaleTown_House_4_EventScript_FishingLesson
# 17 "data/maps/MossvaleTown_House_4/scripts.pory"
	release
	end

MossvaleTown_House_4_EventScript_Fisherman_5:
# 22 "data/maps/MossvaleTown_House_4/scripts.pory"
	setflag FLAG_RECEIVED_OLD_ROD
# 23 "data/maps/MossvaleTown_House_4/scripts.pory"
	call MossvaleTown_House_4_EventScript_FishingLesson
# 24 "data/maps/MossvaleTown_House_4/scripts.pory"
	release
	end

MossvaleTown_House_4_EventScript_Fisherman_9:
# 28 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_0, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_7

MossvaleTown_House_4_EventScript_Fisherman_10:
# 29 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_1, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_7

MossvaleTown_House_4_EventScript_Fisherman_11:
# 30 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_2, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_7

MossvaleTown_House_4_EventScript_Fisherman_14:
# 34 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_3, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_12

MossvaleTown_House_4_EventScript_Fisherman_15:
# 35 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_4, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_12

MossvaleTown_House_4_EventScript_Fisherman_16:
# 36 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_5, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_12

MossvaleTown_House_4_EventScript_Fisherman_18:
# 40 "data/maps/MossvaleTown_House_4/scripts.pory"
	switch VAR_LANGUAGE
# 41 "data/maps/MossvaleTown_House_4/scripts.pory"
	case PT, MossvaleTown_House_4_EventScript_Fisherman_27
# 42 "data/maps/MossvaleTown_House_4/scripts.pory"
	case EN, MossvaleTown_House_4_EventScript_Fisherman_28
# 43 "data/maps/MossvaleTown_House_4/scripts.pory"
	case ES, MossvaleTown_House_4_EventScript_Fisherman_29
MossvaleTown_House_4_EventScript_Fisherman_25:
# 45 "data/maps/MossvaleTown_House_4/scripts.pory"
	release
	end

MossvaleTown_House_4_EventScript_Fisherman_22:
# 50 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_9, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_20

MossvaleTown_House_4_EventScript_Fisherman_23:
# 51 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_10, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_20

MossvaleTown_House_4_EventScript_Fisherman_24:
# 52 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_11, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_20

MossvaleTown_House_4_EventScript_Fisherman_27:
# 41 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_6, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_25

MossvaleTown_House_4_EventScript_Fisherman_28:
# 42 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_7, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_25

MossvaleTown_House_4_EventScript_Fisherman_29:
# 43 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_Fisherman_Text_8, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_Fisherman_25


MossvaleTown_House_4_EventScript_FishingLesson::
# 59 "data/maps/MossvaleTown_House_4/scripts.pory"
	switch VAR_LANGUAGE
# 60 "data/maps/MossvaleTown_House_4/scripts.pory"
	case PT, MossvaleTown_House_4_EventScript_FishingLesson_3
# 61 "data/maps/MossvaleTown_House_4/scripts.pory"
	case EN, MossvaleTown_House_4_EventScript_FishingLesson_4
# 62 "data/maps/MossvaleTown_House_4/scripts.pory"
	case ES, MossvaleTown_House_4_EventScript_FishingLesson_5
MossvaleTown_House_4_EventScript_FishingLesson_1:
	return

MossvaleTown_House_4_EventScript_FishingLesson_3:
# 60 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_FishingLesson_Text_0, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_FishingLesson_1

MossvaleTown_House_4_EventScript_FishingLesson_4:
# 61 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_FishingLesson_Text_1, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_FishingLesson_1

MossvaleTown_House_4_EventScript_FishingLesson_5:
# 62 "data/maps/MossvaleTown_House_4/scripts.pory"
	msgbox MossvaleTown_House_4_EventScript_FishingLesson_Text_2, MSGBOX_DEFAULT
	goto MossvaleTown_House_4_EventScript_FishingLesson_1


MossvaleTown_House_4_EventScript_Girl_Text_0:
# 5 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Ele diz que pegou um peixe\nmaior que esta casa.\pToda vez que conta a história,\na casa fica menor.$"

MossvaleTown_House_4_EventScript_Girl_Text_1:
# 6 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "He says he caught a fish\nbigger than this house.\pEvery time he tells the story,\nthe house gets smaller.$"

MossvaleTown_House_4_EventScript_Girl_Text_2:
# 7 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Dice que pescó un pez\nmás grande que esta casa.\pCada vez que lo cuenta,\nla casa se hace más pequeña.$"

MossvaleTown_House_4_EventScript_Fisherman_Text_0:
# 28 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Pescar é minha especialidade!\nEsperar também.\pÀs vezes espero tanto que\nesqueço qual das duas\lestou praticando.$"

MossvaleTown_House_4_EventScript_Fisherman_Text_1:
# 29 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Fishing is my specialty!\nSo is waiting.\pSometimes I wait so long\nthat I forget which one\lI am practicing.$"

MossvaleTown_House_4_EventScript_Fisherman_Text_2:
# 30 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "¡Pescar es mi especialidad!\nEsperar también.\pA veces espero tanto que\nolvido cuál de las dos\lestoy practicando.$"

MossvaleTown_House_4_EventScript_Fisherman_Text_3:
# 34 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Agora só falta uma vara!\pPode ficar com esta Old Rod.\nEla já me rendeu boas histórias.\lAgora é a sua vez!$"

MossvaleTown_House_4_EventScript_Fisherman_Text_4:
# 35 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Now you just need a rod!\pYou can have this Old Rod.\nIt gave me plenty of stories.\lNow it is your turn!$"

MossvaleTown_House_4_EventScript_Fisherman_Text_5:
# 36 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "¡Ahora solo te falta una caña!\pPuedes quedarte esta Old Rod.\nMe dio muchas buenas historias.\l¡Ahora te toca a ti!$"

MossvaleTown_House_4_EventScript_Fisherman_Text_6:
# 41 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Sua Bolsa está cheia.\nAbra espaço e volte aqui.\lVou guardar a vara para você.$"

MossvaleTown_House_4_EventScript_Fisherman_Text_7:
# 42 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Your Bag is full.\nMake room and come back.\lI will keep the rod for you.$"

MossvaleTown_House_4_EventScript_Fisherman_Text_8:
# 43 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Tu Bolsa está llena.\nHaz espacio y vuelve.\lTe guardaré la caña.$"

MossvaleTown_House_4_EventScript_Fisherman_Text_9:
# 50 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "A vara ajuda, mas não pesca\nsozinha. Lembre-se da lição!$"

MossvaleTown_House_4_EventScript_Fisherman_Text_10:
# 51 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "The rod helps, but it cannot\nfish on its own. Remember\lthe lesson!$"

MossvaleTown_House_4_EventScript_Fisherman_Text_11:
# 52 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "La caña ayuda, pero no pesca\nsola. ¡Recuerda la lección!$"

MossvaleTown_House_4_EventScript_FishingLesson_Text_0:
# 60 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Fique na margem, olhando\npara a água, e use uma vara\lpela Bolsa.\pEspere um POKéMON fisgar\na isca. Quando isso acontecer,\laperte o botão A!\pSe ele escapar, tente de novo.\nPaciência também faz parte\lda pescaria.$"

MossvaleTown_House_4_EventScript_FishingLesson_Text_1:
# 61 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Stand at the shore, face\nthe water, and use a rod\lfrom your Bag.\pWait for a POKéMON to bite.\nWhen it does, press\lthe A Button!\pIf it gets away, try again.\nPatience is part of\lfishing too.$"

MossvaleTown_House_4_EventScript_FishingLesson_Text_2:
# 62 "data/maps/MossvaleTown_House_4/scripts.pory"
	.string "Ponte en la orilla, mirando\nal agua, y usa una caña\ldesde la Bolsa.\pEspera a que pique un POKéMON.\nCuando lo haga, ¡pulsa\lel botón A!\pSi se escapa, vuelve a intentar.\nLa paciencia también forma\lparte de la pesca.$"
