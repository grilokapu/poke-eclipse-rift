WhisperingCave_MapScripts::
	.byte 0


EventScript_WhisperingCave_TM28_Get::
# 6 "data/maps/WhisperingCave/scripts.pory"
	finditem ITEM_TM_METAL_CLAW
	end


EventScript_WhisperingCave_Hiker_Battle::
# 11 "data/maps/WhisperingCave/scripts.pory"
	switch VAR_LANGUAGE
# 12 "data/maps/WhisperingCave/scripts.pory"
	case PT, EventScript_WhisperingCave_Hiker_Battle_3
# 15 "data/maps/WhisperingCave/scripts.pory"
	case EN, EventScript_WhisperingCave_Hiker_Battle_4
# 18 "data/maps/WhisperingCave/scripts.pory"
	case ES, EventScript_WhisperingCave_Hiker_Battle_5
EventScript_WhisperingCave_Hiker_Battle_1:
# 22 "data/maps/WhisperingCave/scripts.pory"
	release
	end

EventScript_WhisperingCave_Hiker_Battle_3:
# 13 "data/maps/WhisperingCave/scripts.pory"
	trainerbattle_single TRAINER_HIKER_LAMARTINE, EventScript_WhisperingCave_Hiker_Battle_Text_0, EventScript_WhisperingCave_Hiker_Battle_Text_1
# 14 "data/maps/WhisperingCave/scripts.pory"
	msgbox EventScript_WhisperingCave_Hiker_Battle_Text_2
	goto EventScript_WhisperingCave_Hiker_Battle_1

EventScript_WhisperingCave_Hiker_Battle_4:
# 16 "data/maps/WhisperingCave/scripts.pory"
	trainerbattle_single TRAINER_HIKER_LAMARTINE, EventScript_WhisperingCave_Hiker_Battle_Text_3, EventScript_WhisperingCave_Hiker_Battle_Text_4
# 17 "data/maps/WhisperingCave/scripts.pory"
	msgbox EventScript_WhisperingCave_Hiker_Battle_Text_5
	goto EventScript_WhisperingCave_Hiker_Battle_1

EventScript_WhisperingCave_Hiker_Battle_5:
# 19 "data/maps/WhisperingCave/scripts.pory"
	trainerbattle_single TRAINER_HIKER_LAMARTINE, EventScript_WhisperingCave_Hiker_Battle_Text_6, EventScript_WhisperingCave_Hiker_Battle_Text_7
# 20 "data/maps/WhisperingCave/scripts.pory"
	msgbox EventScript_WhisperingCave_Hiker_Battle_Text_8
	goto EventScript_WhisperingCave_Hiker_Battle_1


EventScript_WhisperingCave_Camper_Battle::
# 27 "data/maps/WhisperingCave/scripts.pory"
	switch VAR_LANGUAGE
# 28 "data/maps/WhisperingCave/scripts.pory"
	case PT, EventScript_WhisperingCave_Camper_Battle_3
# 31 "data/maps/WhisperingCave/scripts.pory"
	case EN, EventScript_WhisperingCave_Camper_Battle_4
# 34 "data/maps/WhisperingCave/scripts.pory"
	case ES, EventScript_WhisperingCave_Camper_Battle_5
EventScript_WhisperingCave_Camper_Battle_1:
# 38 "data/maps/WhisperingCave/scripts.pory"
	release
	end

EventScript_WhisperingCave_Camper_Battle_3:
# 29 "data/maps/WhisperingCave/scripts.pory"
	trainerbattle_single TRAINER_CAMPER_FRED, EventScript_WhisperingCave_Camper_Battle_Text_0, EventScript_WhisperingCave_Camper_Battle_Text_1
# 30 "data/maps/WhisperingCave/scripts.pory"
	msgbox EventScript_WhisperingCave_Camper_Battle_Text_2
	goto EventScript_WhisperingCave_Camper_Battle_1

EventScript_WhisperingCave_Camper_Battle_4:
# 32 "data/maps/WhisperingCave/scripts.pory"
	trainerbattle_single TRAINER_CAMPER_FRED, EventScript_WhisperingCave_Camper_Battle_Text_3, EventScript_WhisperingCave_Camper_Battle_Text_4
# 33 "data/maps/WhisperingCave/scripts.pory"
	msgbox EventScript_WhisperingCave_Camper_Battle_Text_5
	goto EventScript_WhisperingCave_Camper_Battle_1

EventScript_WhisperingCave_Camper_Battle_5:
# 35 "data/maps/WhisperingCave/scripts.pory"
	trainerbattle_single TRAINER_CAMPER_FRED, EventScript_WhisperingCave_Camper_Battle_Text_6, EventScript_WhisperingCave_Camper_Battle_Text_7
# 36 "data/maps/WhisperingCave/scripts.pory"
	msgbox EventScript_WhisperingCave_Camper_Battle_Text_8
	goto EventScript_WhisperingCave_Camper_Battle_1


EventScript_WhisperingCave_Item_MysticWater_Get::
# 43 "data/maps/WhisperingCave/scripts.pory"
	finditem ITEM_MYSTIC_WATER
	end


EventScript_WhisperingCave_FossilizedDrake_Get::
# 48 "data/maps/WhisperingCave/scripts.pory"
	finditem ITEM_FOSSILIZED_DRAKE
	end


EventScript_WhisperingCave_Hiker_Battle_Text_0:
# 13 "data/maps/WhisperingCave/scripts.pory"
	.string "La-la-la…\pAh! Um treinador!\pQue tal acompanhar o ritmo da\nminha batalha?$"

EventScript_WhisperingCave_Hiker_Battle_Text_1:
# 13 "data/maps/WhisperingCave/scripts.pory"
	.string "La… la…\pOps. Acho que desafinei.$"

EventScript_WhisperingCave_Hiker_Battle_Text_2:
# 14 "data/maps/WhisperingCave/scripts.pory"
	.string "As cavernas têm uma acústica\nincrível.\pAté meus Pokémon parecem gostar\ndas minhas músicas.$"

EventScript_WhisperingCave_Hiker_Battle_Text_3:
# 16 "data/maps/WhisperingCave/scripts.pory"
	.string "La-la-la…\pOh! A Trainer!\pHow about keeping up with the\nrhythm of my battle?$"

EventScript_WhisperingCave_Hiker_Battle_Text_4:
# 16 "data/maps/WhisperingCave/scripts.pory"
	.string "La… la…\pOops. Looks like I hit a wrong\nnote.$"

EventScript_WhisperingCave_Hiker_Battle_Text_5:
# 17 "data/maps/WhisperingCave/scripts.pory"
	.string "Caves have amazing acoustics.\pEven my Pokémon seem to enjoy my\nsongs.$"

EventScript_WhisperingCave_Hiker_Battle_Text_6:
# 19 "data/maps/WhisperingCave/scripts.pory"
	.string "La-la-la…\p¡Oh! ¡Un Entrenador!\p¿Qué tal si sigues el ritmo de mi\nbatalla?$"

EventScript_WhisperingCave_Hiker_Battle_Text_7:
# 19 "data/maps/WhisperingCave/scripts.pory"
	.string "La… la…\pUps. Creo que desafiné.$"

EventScript_WhisperingCave_Hiker_Battle_Text_8:
# 20 "data/maps/WhisperingCave/scripts.pory"
	.string "Las cuevas tienen una acústica\nincreíble.\pHasta mis Pokémon parecen\ndisfrutar de mis canciones.$"

EventScript_WhisperingCave_Camper_Battle_Text_0:
# 29 "data/maps/WhisperingCave/scripts.pory"
	.string "Eu sempre confundo “mais” e “mas”.\pMas… ou era mais?\pAh, tanto faz! Vamos batalhar!$"

EventScript_WhisperingCave_Camper_Battle_Text_1:
# 29 "data/maps/WhisperingCave/scripts.pory"
	.string "Eu perdi…\pOu ganhei experiência?\pAcho que as duas coisas!$"

EventScript_WhisperingCave_Camper_Battle_Text_2:
# 30 "data/maps/WhisperingCave/scripts.pory"
	.string "Outro dia escrevi “concerto”\nquando queria dizer “conserto”.\pMeu Pokémon ficou tão confuso\nquanto eu.$"

EventScript_WhisperingCave_Camper_Battle_Text_3:
# 32 "data/maps/WhisperingCave/scripts.pory"
	.string "I always mix up “peace” and\n“piece”.\pOr was it the other way around?\pAh, whatever! Let's battle!$"

EventScript_WhisperingCave_Camper_Battle_Text_4:
# 32 "data/maps/WhisperingCave/scripts.pory"
	.string "I lost…\pOr did I gain experience?\pI guess both!$"

EventScript_WhisperingCave_Camper_Battle_Text_5:
# 33 "data/maps/WhisperingCave/scripts.pory"
	.string "The other day I wrote “Leek” when\nI meant “Leak”.\pMy Pokémon was just as confused as\nI was.$"

EventScript_WhisperingCave_Camper_Battle_Text_6:
# 35 "data/maps/WhisperingCave/scripts.pory"
	.string "Siempre confundo algunas palabras.\p¿Era una cosa o la otra?\p¡Bah, da igual! ¡Vamos a combatir!$"

EventScript_WhisperingCave_Camper_Battle_Text_7:
# 35 "data/maps/WhisperingCave/scripts.pory"
	.string "Perdí…\p¿O gané experiencia?\p¡Creo que ambas cosas!$"

EventScript_WhisperingCave_Camper_Battle_Text_8:
# 36 "data/maps/WhisperingCave/scripts.pory"
	.string "El otro día escribí una palabra\ncuando quería decir otra.\pMi Pokémon estaba tan confundido\ncomo yo.$"
