LyndoraCity_House3_MapScripts::
	.byte 0


LyndoraCity_House3_EventScript_OldWoman::
# 4 "data/maps/LyndoraCity_House3/scripts.pory"
	lock
# 5 "data/maps/LyndoraCity_House3/scripts.pory"
	faceplayer
# 7 "data/maps/LyndoraCity_House3/scripts.pory"
	goto_if_set FLAG_TEMP_1, LyndoraCity_House3_EventScript_OldWoman_2
# 14 "data/maps/LyndoraCity_House3/scripts.pory"
	switch VAR_LANGUAGE
# 15 "data/maps/LyndoraCity_House3/scripts.pory"
	case PT, LyndoraCity_House3_EventScript_OldWoman_11
# 16 "data/maps/LyndoraCity_House3/scripts.pory"
	case EN, LyndoraCity_House3_EventScript_OldWoman_12
# 17 "data/maps/LyndoraCity_House3/scripts.pory"
	case ES, LyndoraCity_House3_EventScript_OldWoman_13
LyndoraCity_House3_EventScript_OldWoman_9:
# 19 "data/maps/LyndoraCity_House3/scripts.pory"
	pause 30
# 20 "data/maps/LyndoraCity_House3/scripts.pory"
	switch VAR_LANGUAGE
# 21 "data/maps/LyndoraCity_House3/scripts.pory"
	case PT, LyndoraCity_House3_EventScript_OldWoman_16
# 22 "data/maps/LyndoraCity_House3/scripts.pory"
	case EN, LyndoraCity_House3_EventScript_OldWoman_17
# 23 "data/maps/LyndoraCity_House3/scripts.pory"
	case ES, LyndoraCity_House3_EventScript_OldWoman_18
LyndoraCity_House3_EventScript_OldWoman_14:
# 25 "data/maps/LyndoraCity_House3/scripts.pory"
	setflag FLAG_TEMP_1
LyndoraCity_House3_EventScript_OldWoman_1:
# 27 "data/maps/LyndoraCity_House3/scripts.pory"
	release
	end

LyndoraCity_House3_EventScript_OldWoman_2:
# 8 "data/maps/LyndoraCity_House3/scripts.pory"
	switch VAR_LANGUAGE
# 9 "data/maps/LyndoraCity_House3/scripts.pory"
	case PT, LyndoraCity_House3_EventScript_OldWoman_6
# 10 "data/maps/LyndoraCity_House3/scripts.pory"
	case EN, LyndoraCity_House3_EventScript_OldWoman_7
# 11 "data/maps/LyndoraCity_House3/scripts.pory"
	case ES, LyndoraCity_House3_EventScript_OldWoman_8
	goto LyndoraCity_House3_EventScript_OldWoman_1

LyndoraCity_House3_EventScript_OldWoman_6:
# 9 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_OldWoman_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_OldWoman_1

LyndoraCity_House3_EventScript_OldWoman_7:
# 10 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_OldWoman_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_OldWoman_1

LyndoraCity_House3_EventScript_OldWoman_8:
# 11 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_OldWoman_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_OldWoman_1

LyndoraCity_House3_EventScript_OldWoman_11:
# 15 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_OldWoman_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_OldWoman_9

LyndoraCity_House3_EventScript_OldWoman_12:
# 16 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_OldWoman_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_OldWoman_9

LyndoraCity_House3_EventScript_OldWoman_13:
# 17 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_OldWoman_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_OldWoman_9

LyndoraCity_House3_EventScript_OldWoman_16:
# 21 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_OldWoman_Text_6, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_OldWoman_14

LyndoraCity_House3_EventScript_OldWoman_17:
# 22 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_OldWoman_Text_7, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_OldWoman_14

LyndoraCity_House3_EventScript_OldWoman_18:
# 23 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_OldWoman_Text_8, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_OldWoman_14


LyndoraCity_House3_EventScript_LittleGirl::
# 32 "data/maps/LyndoraCity_House3/scripts.pory"
	lock
# 33 "data/maps/LyndoraCity_House3/scripts.pory"
	faceplayer
# 35 "data/maps/LyndoraCity_House3/scripts.pory"
	goto_if_set FLAG_TEMP_2, LyndoraCity_House3_EventScript_LittleGirl_2
# 42 "data/maps/LyndoraCity_House3/scripts.pory"
	switch VAR_LANGUAGE
# 43 "data/maps/LyndoraCity_House3/scripts.pory"
	case PT, LyndoraCity_House3_EventScript_LittleGirl_11
# 44 "data/maps/LyndoraCity_House3/scripts.pory"
	case EN, LyndoraCity_House3_EventScript_LittleGirl_12
# 45 "data/maps/LyndoraCity_House3/scripts.pory"
	case ES, LyndoraCity_House3_EventScript_LittleGirl_13
LyndoraCity_House3_EventScript_LittleGirl_9:
# 47 "data/maps/LyndoraCity_House3/scripts.pory"
	setflag FLAG_TEMP_2
LyndoraCity_House3_EventScript_LittleGirl_1:
# 49 "data/maps/LyndoraCity_House3/scripts.pory"
	release
	end

LyndoraCity_House3_EventScript_LittleGirl_2:
# 36 "data/maps/LyndoraCity_House3/scripts.pory"
	switch VAR_LANGUAGE
# 37 "data/maps/LyndoraCity_House3/scripts.pory"
	case PT, LyndoraCity_House3_EventScript_LittleGirl_6
# 38 "data/maps/LyndoraCity_House3/scripts.pory"
	case EN, LyndoraCity_House3_EventScript_LittleGirl_7
# 39 "data/maps/LyndoraCity_House3/scripts.pory"
	case ES, LyndoraCity_House3_EventScript_LittleGirl_8
	goto LyndoraCity_House3_EventScript_LittleGirl_1

LyndoraCity_House3_EventScript_LittleGirl_6:
# 37 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_LittleGirl_Text_0, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_LittleGirl_1

LyndoraCity_House3_EventScript_LittleGirl_7:
# 38 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_LittleGirl_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_LittleGirl_1

LyndoraCity_House3_EventScript_LittleGirl_8:
# 39 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_LittleGirl_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_LittleGirl_1

LyndoraCity_House3_EventScript_LittleGirl_11:
# 43 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_LittleGirl_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_LittleGirl_9

LyndoraCity_House3_EventScript_LittleGirl_12:
# 44 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_LittleGirl_Text_4, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_LittleGirl_9

LyndoraCity_House3_EventScript_LittleGirl_13:
# 45 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_LittleGirl_Text_5, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_LittleGirl_9


LyndoraCity_House3_EventScript_Hoothoot::
# 54 "data/maps/LyndoraCity_House3/scripts.pory"
	lock
# 55 "data/maps/LyndoraCity_House3/scripts.pory"
	faceplayer
# 56 "data/maps/LyndoraCity_House3/scripts.pory"
	showmonmugshot SPECIES_HOOTHOOT, MUGSHOT_SOUTHEAST
# 57 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_Hoothoot_Text_0, MSGBOX_DEFAULT
# 58 "data/maps/LyndoraCity_House3/scripts.pory"
	waitmoncry
# 59 "data/maps/LyndoraCity_House3/scripts.pory"
	hidemonmugshot
# 60 "data/maps/LyndoraCity_House3/scripts.pory"
	pause 30
# 61 "data/maps/LyndoraCity_House3/scripts.pory"
	switch VAR_LANGUAGE
# 62 "data/maps/LyndoraCity_House3/scripts.pory"
	case PT, LyndoraCity_House3_EventScript_Hoothoot_3
# 63 "data/maps/LyndoraCity_House3/scripts.pory"
	case EN, LyndoraCity_House3_EventScript_Hoothoot_4
# 64 "data/maps/LyndoraCity_House3/scripts.pory"
	case ES, LyndoraCity_House3_EventScript_Hoothoot_5
LyndoraCity_House3_EventScript_Hoothoot_1:
# 66 "data/maps/LyndoraCity_House3/scripts.pory"
	release
	end

LyndoraCity_House3_EventScript_Hoothoot_3:
# 62 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_Hoothoot_Text_1, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_Hoothoot_1

LyndoraCity_House3_EventScript_Hoothoot_4:
# 63 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_Hoothoot_Text_2, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_Hoothoot_1

LyndoraCity_House3_EventScript_Hoothoot_5:
# 64 "data/maps/LyndoraCity_House3/scripts.pory"
	msgbox LyndoraCity_House3_EventScript_Hoothoot_Text_3, MSGBOX_DEFAULT
	goto LyndoraCity_House3_EventScript_Hoothoot_1


LyndoraCity_House3_EventScript_OldWoman_Text_0:
# 9 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "Os Pokémon são criaturas\nextraordinárias...\pÀs vezes, acho que entendem\neste mundo melhor do que nós.$"

LyndoraCity_House3_EventScript_OldWoman_Text_1:
# 10 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "Pokémon are extraordinary\ncreatures...\pSometimes, I think they know\nthis world better than we do.$"

LyndoraCity_House3_EventScript_OldWoman_Text_2:
# 11 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "Los Pokémon son criaturas\nextraordinarias...\pA veces, creo que entienden\neste mundo mejor que nosotros.$"

LyndoraCity_House3_EventScript_OldWoman_Text_3:
# 15 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "Ah, um jovem treinador!\pFaz muito tempo que não vejo\nalguém tão animado para viajar.\pQuando eu era criança, minha avó\ncontava histórias sobre\las florestas de Aetheris.\pEla dizia que, às vezes,\nos Pokémon percebiam coisas\lque nós não podíamos enxergar...$"

LyndoraCity_House3_EventScript_OldWoman_Text_4:
# 16 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "Ah, a young Trainer!\pIt's been a long time since\nI saw someone so eager to travel.\pWhen I was a child, my grandma\ntold stories about\lthe forests of Aetheris.\pShe said Pokémon sometimes\nnoticed things\lwe couldn't see...$"

LyndoraCity_House3_EventScript_OldWoman_Text_5:
# 17 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "¡Ah, un joven Entrenador!\pHacía mucho que no veía a alguien\ncon tantas ganas de viajar.\pDe niña, mi abuela contaba\nhistorias sobre los bosques\lde Aetheris.\pDecía que, a veces, los Pokémon\npercibían cosas que nosotros\lno podíamos ver...$"

LyndoraCity_House3_EventScript_OldWoman_Text_6:
# 21 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "Hehe! Talvez fossem apenas\nhistórias para nos fazer dormir.$"

LyndoraCity_House3_EventScript_OldWoman_Text_7:
# 22 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "Hehe! Perhaps they were just\nstories to help us fall asleep.$"

LyndoraCity_House3_EventScript_OldWoman_Text_8:
# 23 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "¡Je, je! Quizás solo eran cuentos\npara ayudarnos a dormir.$"

LyndoraCity_House3_EventScript_LittleGirl_Text_0:
# 37 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "Quando eu crescer,\nvou viajar por Aetheris!\pQuero descobrir se as histórias\nda vovó são verdadeiras!$"

LyndoraCity_House3_EventScript_LittleGirl_Text_1:
# 38 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "When I grow up,\nI'll travel across Aetheris!\pI want to find out if Grandma's\nstories are true!$"

LyndoraCity_House3_EventScript_LittleGirl_Text_2:
# 39 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "¡Cuando sea mayor,\nviajaré por Aetheris!\p¡Quiero descubrir si las historias\nde la abuela son ciertas!$"

LyndoraCity_House3_EventScript_LittleGirl_Text_3:
# 43 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "Minha avó adora contar\nhistórias antigas!\pOntem ela disse que algumas\nárvores conseguem ouvir\los Pokémon!\pMas árvores nem têm orelhas!\pHehe!$"

LyndoraCity_House3_EventScript_LittleGirl_Text_4:
# 44 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "My grandma loves telling\nold stories!\pYesterday she said some trees\ncan hear Pokémon!\pBut trees don't even have ears!\pHehe!$"

LyndoraCity_House3_EventScript_LittleGirl_Text_5:
# 45 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "¡A mi abuela le encanta\ncontar historias antiguas!\p¡Ayer dijo que algunos árboles\npueden oír a los Pokémon!\p¡Pero los árboles no tienen orejas!\p¡Je, je!$"

LyndoraCity_House3_EventScript_Hoothoot_Text_0:
# 57 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "HOOTHOOT: Hoo! Hoo!$"

LyndoraCity_House3_EventScript_Hoothoot_Text_1:
# 62 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "O HOOTHOOT observa\nvocê atentamente.$"

LyndoraCity_House3_EventScript_Hoothoot_Text_2:
# 63 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "HOOTHOOT watches\nyou closely.$"

LyndoraCity_House3_EventScript_Hoothoot_Text_3:
# 64 "data/maps/LyndoraCity_House3/scripts.pory"
	.string "HOOTHOOT te observa\ncon atención.$"
