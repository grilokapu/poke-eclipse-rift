LyndoraCity_FlowerShop_MapScripts::
	.byte 0


LyndoraCity_FlowerShop_EventScript_Clerk::
# 4 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	lock
# 5 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	faceplayer
# 6 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	switch VAR_LANGUAGE
# 7 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case PT, LyndoraCity_FlowerShop_EventScript_Clerk_3
# 8 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case EN, LyndoraCity_FlowerShop_EventScript_Clerk_4
# 9 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case ES, LyndoraCity_FlowerShop_EventScript_Clerk_5
LyndoraCity_FlowerShop_EventScript_Clerk_1:
# 11 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	release
	end

LyndoraCity_FlowerShop_EventScript_Clerk_3:
# 7 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_Clerk_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_Clerk_1

LyndoraCity_FlowerShop_EventScript_Clerk_4:
# 8 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_Clerk_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_Clerk_1

LyndoraCity_FlowerShop_EventScript_Clerk_5:
# 9 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_Clerk_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_Clerk_1


LyndoraCity_FlowerShop_EventScript_Customer::
# 16 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	lock
# 17 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	faceplayer
# 18 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	switch VAR_LANGUAGE
# 19 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case PT, LyndoraCity_FlowerShop_EventScript_Customer_3
# 20 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case EN, LyndoraCity_FlowerShop_EventScript_Customer_4
# 21 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case ES, LyndoraCity_FlowerShop_EventScript_Customer_5
LyndoraCity_FlowerShop_EventScript_Customer_1:
# 23 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	release
	end

LyndoraCity_FlowerShop_EventScript_Customer_3:
# 19 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_Customer_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_Customer_1

LyndoraCity_FlowerShop_EventScript_Customer_4:
# 20 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_Customer_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_Customer_1

LyndoraCity_FlowerShop_EventScript_Customer_5:
# 21 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_Customer_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_Customer_1


LyndoraCity_FlowerShop_EventScript_PlantCustomer::
# 28 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	lock
# 29 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	faceplayer
# 30 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	switch VAR_LANGUAGE
# 31 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case PT, LyndoraCity_FlowerShop_EventScript_PlantCustomer_3
# 32 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case EN, LyndoraCity_FlowerShop_EventScript_PlantCustomer_4
# 33 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case ES, LyndoraCity_FlowerShop_EventScript_PlantCustomer_5
LyndoraCity_FlowerShop_EventScript_PlantCustomer_1:
# 35 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	pause 30
# 36 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	switch VAR_LANGUAGE
# 37 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case PT, LyndoraCity_FlowerShop_EventScript_PlantCustomer_8
# 38 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case EN, LyndoraCity_FlowerShop_EventScript_PlantCustomer_9
# 39 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	case ES, LyndoraCity_FlowerShop_EventScript_PlantCustomer_10
LyndoraCity_FlowerShop_EventScript_PlantCustomer_6:
# 41 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	release
	end

LyndoraCity_FlowerShop_EventScript_PlantCustomer_3:
# 31 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_PlantCustomer_1

LyndoraCity_FlowerShop_EventScript_PlantCustomer_4:
# 32 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_PlantCustomer_1

LyndoraCity_FlowerShop_EventScript_PlantCustomer_5:
# 33 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_PlantCustomer_1

LyndoraCity_FlowerShop_EventScript_PlantCustomer_8:
# 37 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_PlantCustomer_6

LyndoraCity_FlowerShop_EventScript_PlantCustomer_9:
# 38 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_PlantCustomer_6

LyndoraCity_FlowerShop_EventScript_PlantCustomer_10:
# 39 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	msgbox LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_EventScript_PlantCustomer_6


LyndoraCity_FlowerShop_EventScript_Clerk_Text_0:
# 7 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "Bem-vindo à nossa floricultura!\pTemos flores de várias cores e\nplantas para todos os gostos.\pElowen é uma das nossas clientes\nmais dedicadas.\pEla sempre diz que cuidar de uma\nplanta exige paciência!$"

LyndoraCity_FlowerShop_EventScript_Clerk_Text_1:
# 8 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "Welcome to our flower shop!\pWe have flowers in many colors\nand plants for every taste.\pElowen is one of our most\ndedicated customers.\pShe always says caring for a plant\ntakes patience!$"

LyndoraCity_FlowerShop_EventScript_Clerk_Text_2:
# 9 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "¡Bienvenido a nuestra floristería!\pTenemos flores de muchos colores\ny plantas para todos los gustos.\pElowen es una de nuestras clientas\nmás dedicadas.\p¡Siempre dice que cuidar una planta\nrequiere paciencia!$"

LyndoraCity_FlowerShop_EventScript_Customer_Text_0:
# 19 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "Estou procurando flores para\ndecorar minha casa.\pÉ difícil escolher! Todas são\ntão bonitas!\pTalvez eu leve algumas rosas...\pAh, preciso decidir logo!$"

LyndoraCity_FlowerShop_EventScript_Customer_Text_1:
# 20 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "I'm looking for flowers to\ndecorate my home.\pIt's hard to choose! They're all\nso beautiful!\pMaybe I'll get some roses...\pOh, I should decide soon!$"

LyndoraCity_FlowerShop_EventScript_Customer_Text_2:
# 21 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "Busco flores para decorar\nmi casa.\p¡Es difícil elegir! Todas son\ntan bonitas.\pQuizás lleve unas rosas...\p¡Ay, debo decidirme pronto!$"

LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_0:
# 31 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "Quero colocar algumas plantas\nna minha sala.\pMas sempre esqueço de regá-las...\pTalvez eu devesse começar\ncom um CACTURNE!$"

LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_1:
# 32 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "I want some plants for my\nliving room.\pBut I always forget to water them...\pMaybe I should start with\na CACTURNE!$"

LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_2:
# 33 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "Quiero poner algunas plantas\nen mi sala.\pPero siempre olvido regarlas...\p¡Quizás debería empezar\ncon un CACTURNE!$"

LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_3:
# 37 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "...Espera, acho que esse não é\no tipo de planta vendido aqui!$"

LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_4:
# 38 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "...Wait, I don't think that's the\nkind of plant they sell here!$"

LyndoraCity_FlowerShop_EventScript_PlantCustomer_Text_5:
# 39 "data/maps/LyndoraCity_FlowerShop/scripts.pory"
	.string "...Espera, ¡creo que ese no es\nel tipo de planta que venden aquí!$"
