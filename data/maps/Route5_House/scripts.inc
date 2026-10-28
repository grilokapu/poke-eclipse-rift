Route5_House_MapScripts::
	.byte 0


Route5_House_EventScript_Farmer::
# 4 "data/maps/Route5_House/scripts.pory"
	lock
# 5 "data/maps/Route5_House/scripts.pory"
	faceplayer
# 6 "data/maps/Route5_House/scripts.pory"
	goto_if_unset FLAG_ROUTE5_HOUSE_RECEIVED_ORAN, Route5_House_EventScript_Farmer_2
Route5_House_EventScript_Farmer_1:
# 25 "data/maps/Route5_House/scripts.pory"
	switch VAR_LANGUAGE
# 26 "data/maps/Route5_House/scripts.pory"
	case PT, Route5_House_EventScript_Farmer_6
# 27 "data/maps/Route5_House/scripts.pory"
	case EN, Route5_House_EventScript_Farmer_7
# 28 "data/maps/Route5_House/scripts.pory"
	case ES, Route5_House_EventScript_Farmer_8
Route5_House_EventScript_Farmer_4:
# 30 "data/maps/Route5_House/scripts.pory"
	release
	end

Route5_House_EventScript_Farmer_2:
# 7 "data/maps/Route5_House/scripts.pory"
	switch VAR_LANGUAGE
# 8 "data/maps/Route5_House/scripts.pory"
	case PT, Route5_House_EventScript_Farmer_11
# 9 "data/maps/Route5_House/scripts.pory"
	case EN, Route5_House_EventScript_Farmer_12
# 10 "data/maps/Route5_House/scripts.pory"
	case ES, Route5_House_EventScript_Farmer_13
Route5_House_EventScript_Farmer_9:
# 12 "data/maps/Route5_House/scripts.pory"
	checkitemspace ITEM_ORAN_BERRY, 3
# 13 "data/maps/Route5_House/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Route5_House_EventScript_Farmer_15
# 18 "data/maps/Route5_House/scripts.pory"
	giveitem ITEM_ORAN_BERRY, 3
# 19 "data/maps/Route5_House/scripts.pory"
	compare VAR_0x8007, FALSE
	goto_if_eq Route5_House_EventScript_Farmer_18
# 23 "data/maps/Route5_House/scripts.pory"
	setflag FLAG_ROUTE5_HOUSE_RECEIVED_ORAN
	goto Route5_House_EventScript_Farmer_1

Route5_House_EventScript_Farmer_6:
# 26 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Farmer_Text_3, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Farmer_4

Route5_House_EventScript_Farmer_7:
# 27 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Farmer_Text_4, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Farmer_4

Route5_House_EventScript_Farmer_8:
# 28 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Farmer_Text_5, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Farmer_4

Route5_House_EventScript_Farmer_11:
# 8 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Farmer_Text_0, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Farmer_9

Route5_House_EventScript_Farmer_12:
# 9 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Farmer_Text_1, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Farmer_9

Route5_House_EventScript_Farmer_13:
# 10 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Farmer_Text_2, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Farmer_9

Route5_House_EventScript_Farmer_15:
# 14 "data/maps/Route5_House/scripts.pory"
	call Route5_House_EventScript_BagFull
# 15 "data/maps/Route5_House/scripts.pory"
	release
	end

Route5_House_EventScript_Farmer_18:
# 20 "data/maps/Route5_House/scripts.pory"
	release
	end


Route5_House_EventScript_Wife::
# 35 "data/maps/Route5_House/scripts.pory"
	lock
# 36 "data/maps/Route5_House/scripts.pory"
	faceplayer
# 37 "data/maps/Route5_House/scripts.pory"
	goto_if_unset FLAG_ROUTE5_HOUSE_RECEIVED_PECHA, Route5_House_EventScript_Wife_2
Route5_House_EventScript_Wife_1:
# 56 "data/maps/Route5_House/scripts.pory"
	switch VAR_LANGUAGE
# 57 "data/maps/Route5_House/scripts.pory"
	case PT, Route5_House_EventScript_Wife_6
# 58 "data/maps/Route5_House/scripts.pory"
	case EN, Route5_House_EventScript_Wife_7
# 59 "data/maps/Route5_House/scripts.pory"
	case ES, Route5_House_EventScript_Wife_8
Route5_House_EventScript_Wife_4:
# 61 "data/maps/Route5_House/scripts.pory"
	release
	end

Route5_House_EventScript_Wife_2:
# 38 "data/maps/Route5_House/scripts.pory"
	switch VAR_LANGUAGE
# 39 "data/maps/Route5_House/scripts.pory"
	case PT, Route5_House_EventScript_Wife_11
# 40 "data/maps/Route5_House/scripts.pory"
	case EN, Route5_House_EventScript_Wife_12
# 41 "data/maps/Route5_House/scripts.pory"
	case ES, Route5_House_EventScript_Wife_13
Route5_House_EventScript_Wife_9:
# 43 "data/maps/Route5_House/scripts.pory"
	checkitemspace ITEM_PECHA_BERRY, 2
# 44 "data/maps/Route5_House/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Route5_House_EventScript_Wife_15
# 49 "data/maps/Route5_House/scripts.pory"
	giveitem ITEM_PECHA_BERRY, 2
# 50 "data/maps/Route5_House/scripts.pory"
	compare VAR_0x8007, FALSE
	goto_if_eq Route5_House_EventScript_Wife_18
# 54 "data/maps/Route5_House/scripts.pory"
	setflag FLAG_ROUTE5_HOUSE_RECEIVED_PECHA
	goto Route5_House_EventScript_Wife_1

Route5_House_EventScript_Wife_6:
# 57 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Wife_Text_3, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Wife_4

Route5_House_EventScript_Wife_7:
# 58 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Wife_Text_4, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Wife_4

Route5_House_EventScript_Wife_8:
# 59 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Wife_Text_5, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Wife_4

Route5_House_EventScript_Wife_11:
# 39 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Wife_Text_0, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Wife_9

Route5_House_EventScript_Wife_12:
# 40 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Wife_Text_1, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Wife_9

Route5_House_EventScript_Wife_13:
# 41 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Wife_Text_2, MSGBOX_DEFAULT
	goto Route5_House_EventScript_Wife_9

Route5_House_EventScript_Wife_15:
# 45 "data/maps/Route5_House/scripts.pory"
	call Route5_House_EventScript_BagFull
# 46 "data/maps/Route5_House/scripts.pory"
	release
	end

Route5_House_EventScript_Wife_18:
# 51 "data/maps/Route5_House/scripts.pory"
	release
	end


Route5_House_EventScript_Child::
# 66 "data/maps/Route5_House/scripts.pory"
	switch VAR_LANGUAGE
# 67 "data/maps/Route5_House/scripts.pory"
	case PT, Route5_House_EventScript_Child_3
# 68 "data/maps/Route5_House/scripts.pory"
	case EN, Route5_House_EventScript_Child_4
# 69 "data/maps/Route5_House/scripts.pory"
	case ES, Route5_House_EventScript_Child_5
Route5_House_EventScript_Child_1:
	end

Route5_House_EventScript_Child_3:
# 67 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Child_Text_0, MSGBOX_NPC
	goto Route5_House_EventScript_Child_1

Route5_House_EventScript_Child_4:
# 68 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Child_Text_1, MSGBOX_NPC
	goto Route5_House_EventScript_Child_1

Route5_House_EventScript_Child_5:
# 69 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_Child_Text_2, MSGBOX_NPC
	goto Route5_House_EventScript_Child_1


Route5_House_EventScript_BagFull::
# 75 "data/maps/Route5_House/scripts.pory"
	switch VAR_LANGUAGE
# 76 "data/maps/Route5_House/scripts.pory"
	case PT, Route5_House_EventScript_BagFull_3
# 77 "data/maps/Route5_House/scripts.pory"
	case EN, Route5_House_EventScript_BagFull_4
# 78 "data/maps/Route5_House/scripts.pory"
	case ES, Route5_House_EventScript_BagFull_5
Route5_House_EventScript_BagFull_1:
	return

Route5_House_EventScript_BagFull_3:
# 76 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_BagFull_Text_0, MSGBOX_DEFAULT
	goto Route5_House_EventScript_BagFull_1

Route5_House_EventScript_BagFull_4:
# 77 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_BagFull_Text_1, MSGBOX_DEFAULT
	goto Route5_House_EventScript_BagFull_1

Route5_House_EventScript_BagFull_5:
# 78 "data/maps/Route5_House/scripts.pory"
	msgbox Route5_House_EventScript_BagFull_Text_2, MSGBOX_DEFAULT
	goto Route5_House_EventScript_BagFull_1


Route5_House_EventScript_Farmer_Text_0:
# 8 "data/maps/Route5_House/scripts.pory"
	.string "Entre, entre! Aqui a gente só\ndeixa a chuva do lado de fora.\pSou quem cuida do pomar.\nMeu segredo? Nunca trabalhar\lsem cuidar dos parceiros.\pLeve três Oran Berries.\nColhi antes da chuva apertar!$"

Route5_House_EventScript_Farmer_Text_1:
# 9 "data/maps/Route5_House/scripts.pory"
	.string "Come in! Rain is the only guest\nwe leave outside.\pI tend the orchard. My secret?\nAlways look after the partners\lwho work beside you.\pTake three Oran Berries.\nI picked them before the storm!$"

Route5_House_EventScript_Farmer_Text_2:
# 10 "data/maps/Route5_House/scripts.pory"
	.string "¡Pasa! Aquí solo dejamos\nla lluvia fuera de casa.\pYo cuido el huerto. ¿Mi secreto?\nCuidar siempre a los compañeros\lque trabajan a mi lado.\pLleva tres Bayas Oran.\n¡Las recogí antes de la tormenta!$"

Route5_House_EventScript_Farmer_Text_3:
# 26 "data/maps/Route5_House/scripts.pory"
	.string "Uma Oran Berry recupera 10 PS.\pSe um Pokémon a segurar,\nele a come sozinho na batalha\lquando os PS ficam pela metade.\pDepois de usada, ela acaba.\nConfira o item antes de sair!\pSaco vazio não para em pé.\nVale para fazendeiro e Pokémon!$"

Route5_House_EventScript_Farmer_Text_4:
# 27 "data/maps/Route5_House/scripts.pory"
	.string "An Oran Berry restores 10 HP.\pIf a Pokémon holds one, it eats\nit during battle when its HP\ldrops to half or less.\pThe Berry is consumed.\nCheck held items before leaving!\pNobody works well on an empty\nstomach. Farmers or Pokémon!$"

Route5_House_EventScript_Farmer_Text_5:
# 28 "data/maps/Route5_House/scripts.pory"
	.string "Una Baya Oran restaura 10 PS.\pSi un Pokémon lleva una, la come\nen combate cuando sus PS bajan\la la mitad o menos.\pLa baya se consume.\n¡Revisa los objetos antes de salir!\p¡Nadie trabaja bien con hambre,\nni granjeros ni Pokémon!$"

Route5_House_EventScript_Wife_Text_0:
# 39 "data/maps/Route5_House/scripts.pory"
	.string "Meu marido conta as colheitas.\nEu conto quantas vezes ele volta\lcom os bolsos cheios de terra.\pTambém separo Pecha Berries\npara nossos Pokémon.\pLeve duas. No mato, nem todo\nencontro deixa só arranhões!$"

Route5_House_EventScript_Wife_Text_1:
# 40 "data/maps/Route5_House/scripts.pory"
	.string "My husband counts the harvests.\nI count how often he comes home\lwith pockets full of dirt.\pI also set aside Pecha Berries\nfor our Pokémon.\pTake two. Out in the grass,\nscratches aren't the only risk!$"

Route5_House_EventScript_Wife_Text_2:
# 41 "data/maps/Route5_House/scripts.pory"
	.string "Mi marido cuenta las cosechas.\nYo cuento cuántas veces vuelve\lcon tierra en los bolsillos.\pTambién guardo Bayas Pecha\npara nuestros Pokémon.\pLleva dos. ¡En la hierba hay\nmás peligros que los arañazos!$"

Route5_House_EventScript_Wife_Text_3:
# 57 "data/maps/Route5_House/scripts.pory"
	.string "Pecha Berry cura envenenamento.\nEla não recupera os PS perdidos!\pÀs vezes é preciso cuidar\ndo veneno e dos ferimentos.\pA descrição de cada item ajuda\na escolher o tratamento certo.\pÉ como aqui em casa: uma coisa\né tirar a lama das botas...\loutra é consertar os furos!$"

Route5_House_EventScript_Wife_Text_4:
# 58 "data/maps/Route5_House/scripts.pory"
	.string "A Pecha Berry cures poisoning.\nIt won't restore lost HP!\pSometimes you need to treat\nboth poison and injuries.\pRead each item's description\nto choose the right treatment.\pIt's like our boots: washing\noff the mud is one thing...\lfixing the holes is another!$"

Route5_House_EventScript_Wife_Text_5:
# 59 "data/maps/Route5_House/scripts.pory"
	.string "Una Baya Pecha cura el veneno.\n¡No recupera los PS perdidos!\pA veces hay que tratar\nel veneno y las heridas.\pLee la descripción de cada\nobjeto para elegir bien.\pEs como con las botas: quitar\nel barro es una cosa...\l¡reparar los agujeros es otra!$"

Route5_House_EventScript_Child_Text_0:
# 67 "data/maps/Route5_House/scripts.pory"
	.string "Eu escolhia meus golpes\nsó pelo nome mais assustador!\pAí perdi pro Pokémon do vovô.\nEle nem largou a caneca...\pAgora leio o resumo dos golpes.\nOlho o tipo, a precisão\le se causam dano ou dão apoio.\pNa próxima, ele vai ter\nque largar essa caneca!$"

Route5_House_EventScript_Child_Text_1:
# 68 "data/maps/Route5_House/scripts.pory"
	.string "I used to pick moves with\nthe scariest names!\pThen Grandpa's Pokémon beat me.\nHe didn't even put his mug down...\pNow I read the move summaries.\nI check type, accuracy, and\lwhether they deal damage or help.\pNext time, he'll have\nto put that mug down!$"

Route5_House_EventScript_Child_Text_2:
# 69 "data/maps/Route5_House/scripts.pory"
	.string "¡Yo elegía los movimientos\ncon los nombres más temibles!\pLuego me ganó el Pokémon\ndel abuelo. ¡Ni soltó su taza!\pAhora leo los movimientos.\nMiro el tipo, la precisión\ly si hacen daño o dan apoyo.\p¡La próxima vez tendrá\nque soltar esa taza!$"

Route5_House_EventScript_BagFull_Text_0:
# 76 "data/maps/Route5_House/scripts.pory"
	.string "Não cabe na sua Bolsa?\nPode deixar que eu guardo.\pAbra espaço e volte\npara buscar suas Berries!$"

Route5_House_EventScript_BagFull_Text_1:
# 77 "data/maps/Route5_House/scripts.pory"
	.string "No room in your Bag?\nI'll keep these for you.\pMake some space and come back\nfor your Berries!$"

Route5_House_EventScript_BagFull_Text_2:
# 78 "data/maps/Route5_House/scripts.pory"
	.string "¿No caben en tu Bolsa?\nTe las guardaré.\p¡Haz espacio y vuelve\na buscar tus bayas!$"
