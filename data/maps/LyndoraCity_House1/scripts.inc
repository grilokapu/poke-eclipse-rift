LyndoraCity_House1_MapScripts::
	.byte 0


LyndoraCity_House1_EventScript_RetiredTrainer::
# 4 "data/maps/LyndoraCity_House1/scripts.pory"
	lock
# 5 "data/maps/LyndoraCity_House1/scripts.pory"
	faceplayer
# 6 "data/maps/LyndoraCity_House1/scripts.pory"
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL_LYNDORA, LyndoraCity_House1_EventScript_RetiredTrainer_2
# 15 "data/maps/LyndoraCity_House1/scripts.pory"
	switch VAR_LANGUAGE
# 16 "data/maps/LyndoraCity_House1/scripts.pory"
	case PT, LyndoraCity_House1_EventScript_RetiredTrainer_6
# 17 "data/maps/LyndoraCity_House1/scripts.pory"
	case EN, LyndoraCity_House1_EventScript_RetiredTrainer_7
# 18 "data/maps/LyndoraCity_House1/scripts.pory"
	case ES, LyndoraCity_House1_EventScript_RetiredTrainer_8
LyndoraCity_House1_EventScript_RetiredTrainer_4:
# 20 "data/maps/LyndoraCity_House1/scripts.pory"
	pause 30
# 21 "data/maps/LyndoraCity_House1/scripts.pory"
	switch VAR_LANGUAGE
# 22 "data/maps/LyndoraCity_House1/scripts.pory"
	case PT, LyndoraCity_House1_EventScript_RetiredTrainer_16
# 23 "data/maps/LyndoraCity_House1/scripts.pory"
	case EN, LyndoraCity_House1_EventScript_RetiredTrainer_17
# 24 "data/maps/LyndoraCity_House1/scripts.pory"
	case ES, LyndoraCity_House1_EventScript_RetiredTrainer_18
LyndoraCity_House1_EventScript_RetiredTrainer_14:
# 26 "data/maps/LyndoraCity_House1/scripts.pory"
	checkitemspace ITEM_SOOTHE_BELL, 1
# 27 "data/maps/LyndoraCity_House1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LyndoraCity_House1_EventScript_RetiredTrainer_20
# 32 "data/maps/LyndoraCity_House1/scripts.pory"
	giveitem ITEM_SOOTHE_BELL, 1
# 33 "data/maps/LyndoraCity_House1/scripts.pory"
	compare VAR_0x8007, FALSE
	goto_if_eq LyndoraCity_House1_EventScript_RetiredTrainer_23
# 37 "data/maps/LyndoraCity_House1/scripts.pory"
	setflag FLAG_RECEIVED_SOOTHE_BELL_LYNDORA
# 38 "data/maps/LyndoraCity_House1/scripts.pory"
	switch VAR_LANGUAGE
# 39 "data/maps/LyndoraCity_House1/scripts.pory"
	case PT, LyndoraCity_House1_EventScript_RetiredTrainer_27
# 40 "data/maps/LyndoraCity_House1/scripts.pory"
	case EN, LyndoraCity_House1_EventScript_RetiredTrainer_28
# 41 "data/maps/LyndoraCity_House1/scripts.pory"
	case ES, LyndoraCity_House1_EventScript_RetiredTrainer_29
LyndoraCity_House1_EventScript_RetiredTrainer_25:
# 43 "data/maps/LyndoraCity_House1/scripts.pory"
	release
	end

LyndoraCity_House1_EventScript_RetiredTrainer_2:
# 7 "data/maps/LyndoraCity_House1/scripts.pory"
	switch VAR_LANGUAGE
# 8 "data/maps/LyndoraCity_House1/scripts.pory"
	case PT, LyndoraCity_House1_EventScript_RetiredTrainer_11
# 9 "data/maps/LyndoraCity_House1/scripts.pory"
	case EN, LyndoraCity_House1_EventScript_RetiredTrainer_12
# 10 "data/maps/LyndoraCity_House1/scripts.pory"
	case ES, LyndoraCity_House1_EventScript_RetiredTrainer_13
LyndoraCity_House1_EventScript_RetiredTrainer_9:
# 12 "data/maps/LyndoraCity_House1/scripts.pory"
	release
	end

LyndoraCity_House1_EventScript_RetiredTrainer_6:
# 16 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_4

LyndoraCity_House1_EventScript_RetiredTrainer_7:
# 17 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_4

LyndoraCity_House1_EventScript_RetiredTrainer_8:
# 18 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_4

LyndoraCity_House1_EventScript_RetiredTrainer_11:
# 8 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_9

LyndoraCity_House1_EventScript_RetiredTrainer_12:
# 9 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_9

LyndoraCity_House1_EventScript_RetiredTrainer_13:
# 10 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_9

LyndoraCity_House1_EventScript_RetiredTrainer_16:
# 22 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_6, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_14

LyndoraCity_House1_EventScript_RetiredTrainer_17:
# 23 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_7, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_14

LyndoraCity_House1_EventScript_RetiredTrainer_18:
# 24 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_8, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_14

LyndoraCity_House1_EventScript_RetiredTrainer_20:
# 28 "data/maps/LyndoraCity_House1/scripts.pory"
	call LyndoraCity_House1_EventScript_BagFull
# 29 "data/maps/LyndoraCity_House1/scripts.pory"
	release
	end

LyndoraCity_House1_EventScript_RetiredTrainer_23:
# 34 "data/maps/LyndoraCity_House1/scripts.pory"
	release
	end

LyndoraCity_House1_EventScript_RetiredTrainer_27:
# 39 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_9, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_25

LyndoraCity_House1_EventScript_RetiredTrainer_28:
# 40 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_10, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_25

LyndoraCity_House1_EventScript_RetiredTrainer_29:
# 41 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_RetiredTrainer_Text_11, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_RetiredTrainer_25


LyndoraCity_House1_EventScript_BagFull::
# 48 "data/maps/LyndoraCity_House1/scripts.pory"
	switch VAR_LANGUAGE
# 49 "data/maps/LyndoraCity_House1/scripts.pory"
	case PT, LyndoraCity_House1_EventScript_BagFull_3
# 50 "data/maps/LyndoraCity_House1/scripts.pory"
	case EN, LyndoraCity_House1_EventScript_BagFull_4
# 51 "data/maps/LyndoraCity_House1/scripts.pory"
	case ES, LyndoraCity_House1_EventScript_BagFull_5
LyndoraCity_House1_EventScript_BagFull_1:
	return

LyndoraCity_House1_EventScript_BagFull_3:
# 49 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_BagFull_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_BagFull_1

LyndoraCity_House1_EventScript_BagFull_4:
# 50 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_BagFull_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_BagFull_1

LyndoraCity_House1_EventScript_BagFull_5:
# 51 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_BagFull_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_BagFull_1


LyndoraCity_House1_EventScript_Woman::
# 57 "data/maps/LyndoraCity_House1/scripts.pory"
	lock
# 58 "data/maps/LyndoraCity_House1/scripts.pory"
	faceplayer
# 59 "data/maps/LyndoraCity_House1/scripts.pory"
	switch VAR_LANGUAGE
# 60 "data/maps/LyndoraCity_House1/scripts.pory"
	case PT, LyndoraCity_House1_EventScript_Woman_3
# 61 "data/maps/LyndoraCity_House1/scripts.pory"
	case EN, LyndoraCity_House1_EventScript_Woman_4
# 62 "data/maps/LyndoraCity_House1/scripts.pory"
	case ES, LyndoraCity_House1_EventScript_Woman_5
LyndoraCity_House1_EventScript_Woman_1:
# 64 "data/maps/LyndoraCity_House1/scripts.pory"
	release
	end

LyndoraCity_House1_EventScript_Woman_3:
# 60 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Woman_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_Woman_1

LyndoraCity_House1_EventScript_Woman_4:
# 61 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Woman_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_Woman_1

LyndoraCity_House1_EventScript_Woman_5:
# 62 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Woman_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_Woman_1


LyndoraCity_House1_EventScript_Budew::
# 69 "data/maps/LyndoraCity_House1/scripts.pory"
	lock
# 70 "data/maps/LyndoraCity_House1/scripts.pory"
	faceplayer
# 71 "data/maps/LyndoraCity_House1/scripts.pory"
	showmonmugshot SPECIES_BUDEW, MUGSHOT_SOUTHEAST
# 72 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Budew_Text_0, MSGBOX_DEFAULT
# 73 "data/maps/LyndoraCity_House1/scripts.pory"
	waitmoncry
# 74 "data/maps/LyndoraCity_House1/scripts.pory"
	hidemonmugshot
# 75 "data/maps/LyndoraCity_House1/scripts.pory"
	movenpc LOCALID_LYNDORA_HOUSE1_BUDEW, LyndoraCity_House1_EventScript_Budew_Movement_0
# 76 "data/maps/LyndoraCity_House1/scripts.pory"
	switch VAR_LANGUAGE
# 77 "data/maps/LyndoraCity_House1/scripts.pory"
	case PT, LyndoraCity_House1_EventScript_Budew_3
# 78 "data/maps/LyndoraCity_House1/scripts.pory"
	case EN, LyndoraCity_House1_EventScript_Budew_4
# 79 "data/maps/LyndoraCity_House1/scripts.pory"
	case ES, LyndoraCity_House1_EventScript_Budew_5
LyndoraCity_House1_EventScript_Budew_1:
# 81 "data/maps/LyndoraCity_House1/scripts.pory"
	release
	end

LyndoraCity_House1_EventScript_Budew_3:
# 77 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Budew_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_Budew_1

LyndoraCity_House1_EventScript_Budew_4:
# 78 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Budew_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_Budew_1

LyndoraCity_House1_EventScript_Budew_5:
# 79 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Budew_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_House1_EventScript_Budew_1


LyndoraCity_House1_EventScript_Plant::
# 86 "data/maps/LyndoraCity_House1/scripts.pory"
	switch VAR_LANGUAGE
# 87 "data/maps/LyndoraCity_House1/scripts.pory"
	case PT, LyndoraCity_House1_EventScript_Plant_3
# 88 "data/maps/LyndoraCity_House1/scripts.pory"
	case EN, LyndoraCity_House1_EventScript_Plant_4
# 89 "data/maps/LyndoraCity_House1/scripts.pory"
	case ES, LyndoraCity_House1_EventScript_Plant_5
LyndoraCity_House1_EventScript_Plant_1:
	end

LyndoraCity_House1_EventScript_Plant_3:
# 87 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Plant_Text_0, MSGBOX_SIGN
	goto LyndoraCity_House1_EventScript_Plant_1

LyndoraCity_House1_EventScript_Plant_4:
# 88 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Plant_Text_1, MSGBOX_SIGN
	goto LyndoraCity_House1_EventScript_Plant_1

LyndoraCity_House1_EventScript_Plant_5:
# 89 "data/maps/LyndoraCity_House1/scripts.pory"
	msgbox LyndoraCity_House1_EventScript_Plant_Text_2, MSGBOX_SIGN
	goto LyndoraCity_House1_EventScript_Plant_1


# 75 "data/maps/LyndoraCity_House1/scripts.pory"
LyndoraCity_House1_EventScript_Budew_Movement_0:
# 75 "data/maps/LyndoraCity_House1/scripts.pory"
	emoji_smiley
	step_end

LyndoraCity_House1_EventScript_RetiredTrainer_Text_0:
# 8 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Não importa quantas\nbatalhas você vença.\pUm Pokémon que confia em você\né seu maior companheiro.$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_1:
# 9 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "It doesn't matter how many\nbattles you win.\pA Pokémon that trusts you\nis your greatest companion.$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_2:
# 10 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "No importa cuántos\ncombates ganes.\pUn Pokémon que confía en ti\nes tu mejor compañero.$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_3:
# 16 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Quando era mais jovem, viajei\npor muitas regiões.\pParticipei de incontáveis\nbatalhas...\pMas sabe o que descobri?\pOs melhores momentos nem sempre\nacontecem em uma arena.\pÀs vezes, basta estar ao lado\ndos nossos Pokémon.$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_4:
# 17 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "When I was younger, I traveled\nthrough many regions.\pI took part in countless\nbattles...\pBut do you know what I learned?\pThe best moments don't always\nhappen in an arena.\pSometimes, just being with\nour Pokémon is enough.$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_5:
# 18 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "De joven, viajé\npor muchas regiones.\pParticipé en innumerables\ncombates...\p¿Pero sabes qué descubrí?\pLos mejores momentos no siempre\nocurren en una arena.\pA veces, basta con estar\njunto a nuestros Pokémon.$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_6:
# 22 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Ah! Tenho algo que talvez\nseja útil na sua jornada.$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_7:
# 23 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Oh! I have something that\nmight help on your journey.$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_8:
# 24 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "¡Ah! Tengo algo que quizás\nte sirva en tu viaje.$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_9:
# 39 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Se um Pokémon segurar esse sino,\nsua amizade crescerá mais rápido.\pCuide bem deles, está bem?$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_10:
# 40 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "A Pokémon holding this bell\nwill grow friendly more quickly.\pTake good care of them, all right?$"

LyndoraCity_House1_EventScript_RetiredTrainer_Text_11:
# 41 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Un Pokémon que lleve esta campana\nganará amistad más rápido.\pCuida bien de ellos, ¿de acuerdo?$"

LyndoraCity_House1_EventScript_BagFull_Text_0:
# 49 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Sua Bolsa está cheia?\pVou guardar o sino para você.\nAbra espaço e volte depois!$"

LyndoraCity_House1_EventScript_BagFull_Text_1:
# 50 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Is your Bag full?\pI'll keep the bell for you.\nMake some room and come back!$"

LyndoraCity_House1_EventScript_BagFull_Text_2:
# 51 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "¿Tu Bolsa está llena?\pTe guardaré la campana.\n¡Haz espacio y vuelve luego!$"

LyndoraCity_House1_EventScript_Woman_Text_0:
# 60 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Meu marido diz que se aposentou\ndas batalhas...\pMas ainda acorda cedo\npara treinar nosso BUDEW!\pHehe! Algumas coisas\nnunca mudam.$"

LyndoraCity_House1_EventScript_Woman_Text_1:
# 61 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "My husband says he's retired\nfrom battling...\pBut he still gets up early\nto train our BUDEW!\pHehe! Some things\nnever change.$"

LyndoraCity_House1_EventScript_Woman_Text_2:
# 62 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Mi marido dice que se retiró\nde los combates...\p¡Pero aún madruga\npara entrenar a nuestro BUDEW!\p¡Je, je! Algunas cosas\nnunca cambian.$"

LyndoraCity_House1_EventScript_Budew_Text_0:
# 72 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "BUDEW: Budew!$"

LyndoraCity_House1_EventScript_Budew_Text_1:
# 77 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "O BUDEW parece estar\naproveitando a luz do sol.$"

LyndoraCity_House1_EventScript_Budew_Text_2:
# 78 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "BUDEW seems to be\nenjoying the sunlight.$"

LyndoraCity_House1_EventScript_Budew_Text_3:
# 79 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "BUDEW parece estar\ndisfrutando de la luz del sol.$"

LyndoraCity_House1_EventScript_Plant_Text_0:
# 87 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Uma pequena planta cresce\nperto da janela.\pSuas folhas estão\nverdes e saudáveis.$"

LyndoraCity_House1_EventScript_Plant_Text_1:
# 88 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "A small plant grows\nnear the window.\pIts leaves look\ngreen and healthy.$"

LyndoraCity_House1_EventScript_Plant_Text_2:
# 89 "data/maps/LyndoraCity_House1/scripts.pory"
	.string "Una pequeña planta crece\ncerca de la ventana.\pSus hojas están\nverdes y sanas.$"
