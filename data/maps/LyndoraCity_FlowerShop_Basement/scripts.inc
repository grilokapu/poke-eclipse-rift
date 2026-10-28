LyndoraCity_FlowerShop_Basement_MapScripts::
	.byte 0


LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper::
# 4 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	lock
# 5 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	faceplayer
# 6 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	goto_if_set FLAG_TEMP_3, LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_2
# 13 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	case PT, LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_11
# 15 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	case EN, LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_12
# 16 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	case ES, LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_13
LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_9:
# 18 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	setflag FLAG_TEMP_3
LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_1:
# 20 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	release
	end

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_2:
# 7 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	switch VAR_LANGUAGE
# 8 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	case PT, LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_6
# 9 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	case EN, LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_7
# 10 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	case ES, LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_8
	goto LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_1

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_6:
# 8 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	msgbox LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_1

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_7:
# 9 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	msgbox LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_1

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_8:
# 10 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	msgbox LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_1

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_11:
# 14 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	msgbox LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_9

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_12:
# 15 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	msgbox LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_9

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_13:
# 16 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	msgbox LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_9


LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_0:
# 8 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	.string "Cada planta precisa das condições\ncertas para crescer.\pAté mesmo as que parecem\nmais resistentes!$"

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_1:
# 9 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	.string "Every plant needs the right\nconditions to grow.\pEven the ones that seem\nthe hardiest!$"

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_2:
# 10 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	.string "Cada planta necesita las\ncondiciones adecuadas para crecer.\p¡Incluso las que parecen\nmás resistentes!$"

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_3:
# 14 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	.string "Este é o nosso depósito.\pGuardamos aqui vasos, sementes\ne plantas que ainda não foram\npara a loja.\pÉ preciso manter tudo organizado!$"

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_4:
# 15 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	.string "This is our stockroom.\pWe keep pots, seeds and plants\nhere until they go to the shop.\pEverything must stay organized!$"

LyndoraCity_FlowerShop_Basement_EventScript_Stockkeeper_Text_5:
# 16 "data/maps/LyndoraCity_FlowerShop_Basement/scripts.pory"
	.string "Este es nuestro depósito.\pAquí guardamos macetas, semillas\ny plantas que aún no han ido\na la tienda.\p¡Hay que mantener todo ordenado!$"
