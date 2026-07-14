Route103_MapScripts::
	.byte 0


Route103_EventScript_RouteSign::
# 6 "data/maps/Route103/scripts.pory"
	switch VAR_LANGUAGE
# 7 "data/maps/Route103/scripts.pory"
	case PT, Route103_EventScript_RouteSign_2
# 8 "data/maps/Route103/scripts.pory"
	case EN, Route103_EventScript_RouteSign_3
# 9 "data/maps/Route103/scripts.pory"
	case ES, Route103_EventScript_RouteSign_4
	return

Route103_EventScript_RouteSign_2:
# 7 "data/maps/Route103/scripts.pory"
	msgbox Route103_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	return

Route103_EventScript_RouteSign_3:
# 8 "data/maps/Route103/scripts.pory"
	msgbox Route103_EventScript_RouteSign_Text_1, MSGBOX_SIGN
	return

Route103_EventScript_RouteSign_4:
# 9 "data/maps/Route103/scripts.pory"
	msgbox Route103_EventScript_RouteSign_Text_2, MSGBOX_SIGN
	return


Route103_EventScript_Lass_Talk::
# 14 "data/maps/Route103/scripts.pory"
	switch VAR_LANGUAGE
# 15 "data/maps/Route103/scripts.pory"
	case PT, Route103_EventScript_Lass_Talk_3
# 16 "data/maps/Route103/scripts.pory"
	case EN, Route103_EventScript_Lass_Talk_4
# 17 "data/maps/Route103/scripts.pory"
	case ES, Route103_EventScript_Lass_Talk_5
Route103_EventScript_Lass_Talk_1:
	end

Route103_EventScript_Lass_Talk_3:
# 15 "data/maps/Route103/scripts.pory"
	msgbox Route103_EventScript_Lass_Talk_Text_0, MSGBOX_NPC
	goto Route103_EventScript_Lass_Talk_1

Route103_EventScript_Lass_Talk_4:
# 16 "data/maps/Route103/scripts.pory"
	msgbox Route103_EventScript_Lass_Talk_Text_1, MSGBOX_NPC
	goto Route103_EventScript_Lass_Talk_1

Route103_EventScript_Lass_Talk_5:
# 17 "data/maps/Route103/scripts.pory"
	msgbox Route103_EventScript_Lass_Talk_Text_2, MSGBOX_NPC
	goto Route103_EventScript_Lass_Talk_1


Route103_EventScript_Pokemon_Tips::
# 23 "data/maps/Route103/scripts.pory"
	helpwindow HELP_MATCH_STATS
	end


Route103_EventScript_Water_Gem_Get::
# 28 "data/maps/Route103/scripts.pory"
	finditem ITEM_WATER_GEM
	end


Route103_EventScript_Youngster_Battle::
# 35 "data/maps/Route103/scripts.pory"
	switch VAR_LANGUAGE
# 36 "data/maps/Route103/scripts.pory"
	case PT, Route103_EventScript_Youngster_Battle_3
# 39 "data/maps/Route103/scripts.pory"
	case EN, Route103_EventScript_Youngster_Battle_4
# 42 "data/maps/Route103/scripts.pory"
	case ES, Route103_EventScript_Youngster_Battle_5
Route103_EventScript_Youngster_Battle_1:
# 46 "data/maps/Route103/scripts.pory"
	release
	end

Route103_EventScript_Youngster_Battle_3:
# 37 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_NOAH, Route103_EventScript_Youngster_Battle_Text_0, Route103_EventScript_Youngster_Battle_Text_1
# 38 "data/maps/Route103/scripts.pory"
	msgbox Route103_EventScript_Youngster_Battle_Text_2
	goto Route103_EventScript_Youngster_Battle_1

Route103_EventScript_Youngster_Battle_4:
# 40 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_NOAH, Route103_EventScript_Youngster_Battle_Text_3, Route103_EventScript_Youngster_Battle_Text_4
# 41 "data/maps/Route103/scripts.pory"
	msgbox Route103_EventScript_Youngster_Battle_Text_5
	goto Route103_EventScript_Youngster_Battle_1

Route103_EventScript_Youngster_Battle_5:
# 43 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_NOAH, Route103_EventScript_Youngster_Battle_Text_6, Route103_EventScript_Youngster_Battle_Text_7
# 44 "data/maps/Route103/scripts.pory"
	msgbox Route103_EventScript_Youngster_Battle_Text_8
	goto Route103_EventScript_Youngster_Battle_1


Route103_EventScript_TM_PoisonTail_Get::
# 51 "data/maps/Route103/scripts.pory"
	finditem ITEM_TM23
	end


Route103_EventScript_RouteSign_Text_0:
# 7 "data/maps/Route103/scripts.pory"
	.string "Rota 3\nCaverna Sussuro {RIGHT_ARROW_2}\lCaverna Sussuro {LEFT_ARROW_2}$"

Route103_EventScript_RouteSign_Text_1:
# 8 "data/maps/Route103/scripts.pory"
	.string "Route 3\nWhispering Cave {RIGHT_ARROW_2}\lWhispering Cave {LEFT_ARROW_2}$"

Route103_EventScript_RouteSign_Text_2:
# 9 "data/maps/Route103/scripts.pory"
	.string "Ruta 3\nCueva Susurro {RIGHT_ARROW_2}\lCueva Susurro {LEFT_ARROW_2}$"

Route103_EventScript_Lass_Talk_Text_0:
# 15 "data/maps/Route103/scripts.pory"
	.string "Meu sonho é encontrar o Pokémon\nSupremo de Aetheris…\pSerá que esse dia vai chegar?$"

Route103_EventScript_Lass_Talk_Text_1:
# 16 "data/maps/Route103/scripts.pory"
	.string "My dream is to find Aetheris's\nSupreme Pokémon…\pI wonder if that day will ever\ncome.$"

Route103_EventScript_Lass_Talk_Text_2:
# 17 "data/maps/Route103/scripts.pory"
	.string "Mi sueño es encontrar al Pokémon\nSupremo de Aetheris…\p¿Llegará ese día alguna vez?$"

Route103_EventScript_Youngster_Battle_Text_0:
# 37 "data/maps/Route103/scripts.pory"
	.string "Vamos batalhar um pouco!$"

Route103_EventScript_Youngster_Battle_Text_1:
# 37 "data/maps/Route103/scripts.pory"
	.string "Essa derrota não estava nos meus\nplanos…$"

Route103_EventScript_Youngster_Battle_Text_2:
# 38 "data/maps/Route103/scripts.pory"
	.string "A vida é como fazer um bolo.\pÀs vezes a receita não sai como\nvocê queria… mas um pouco de\lchantilly faz milagres!$"

Route103_EventScript_Youngster_Battle_Text_3:
# 40 "data/maps/Route103/scripts.pory"
	.string "Let's have a battle!$"

Route103_EventScript_Youngster_Battle_Text_4:
# 40 "data/maps/Route103/scripts.pory"
	.string "I wasn't planning on losing…$"

Route103_EventScript_Youngster_Battle_Text_5:
# 41 "data/maps/Route103/scripts.pory"
	.string "Life is just like baking a cake.\pSometimes the recipe doesn't turn\nout the way you wanted… but a\llittle whipped cream works\lwonders!$"

Route103_EventScript_Youngster_Battle_Text_6:
# 43 "data/maps/Route103/scripts.pory"
	.string "¡Vamos a combatir!$"

Route103_EventScript_Youngster_Battle_Text_7:
# 43 "data/maps/Route103/scripts.pory"
	.string "No pensaba perder…$"

Route103_EventScript_Youngster_Battle_Text_8:
# 44 "data/maps/Route103/scripts.pory"
	.string "La vida es como preparar un\npastel.\pA veces la receta no sale como\nesperabas… ¡pero un poco de crema\lbatida hace maravillas!$"
