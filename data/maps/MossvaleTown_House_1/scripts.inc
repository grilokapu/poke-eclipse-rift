MossvaleTown_House_1_MapScripts::
	.byte 0


MossvaleTown_House_1_EventScript_Woman::
# 4 "data/maps/MossvaleTown_House_1/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/MossvaleTown_House_1/scripts.pory"
	case PT, MossvaleTown_House_1_EventScript_Woman_3
# 6 "data/maps/MossvaleTown_House_1/scripts.pory"
	case EN, MossvaleTown_House_1_EventScript_Woman_4
# 7 "data/maps/MossvaleTown_House_1/scripts.pory"
	case ES, MossvaleTown_House_1_EventScript_Woman_5
MossvaleTown_House_1_EventScript_Woman_1:
	end

MossvaleTown_House_1_EventScript_Woman_3:
# 5 "data/maps/MossvaleTown_House_1/scripts.pory"
	msgbox MossvaleTown_House_1_EventScript_Woman_Text_0, MSGBOX_NPC
	goto MossvaleTown_House_1_EventScript_Woman_1

MossvaleTown_House_1_EventScript_Woman_4:
# 6 "data/maps/MossvaleTown_House_1/scripts.pory"
	msgbox MossvaleTown_House_1_EventScript_Woman_Text_1, MSGBOX_NPC
	goto MossvaleTown_House_1_EventScript_Woman_1

MossvaleTown_House_1_EventScript_Woman_5:
# 7 "data/maps/MossvaleTown_House_1/scripts.pory"
	msgbox MossvaleTown_House_1_EventScript_Woman_Text_2, MSGBOX_NPC
	goto MossvaleTown_House_1_EventScript_Woman_1


MossvaleTown_House_1_EventScript_Man::
# 13 "data/maps/MossvaleTown_House_1/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/MossvaleTown_House_1/scripts.pory"
	case PT, MossvaleTown_House_1_EventScript_Man_3
# 15 "data/maps/MossvaleTown_House_1/scripts.pory"
	case EN, MossvaleTown_House_1_EventScript_Man_4
# 16 "data/maps/MossvaleTown_House_1/scripts.pory"
	case ES, MossvaleTown_House_1_EventScript_Man_5
MossvaleTown_House_1_EventScript_Man_1:
	end

MossvaleTown_House_1_EventScript_Man_3:
# 14 "data/maps/MossvaleTown_House_1/scripts.pory"
	msgbox MossvaleTown_House_1_EventScript_Man_Text_0, MSGBOX_NPC
	goto MossvaleTown_House_1_EventScript_Man_1

MossvaleTown_House_1_EventScript_Man_4:
# 15 "data/maps/MossvaleTown_House_1/scripts.pory"
	msgbox MossvaleTown_House_1_EventScript_Man_Text_1, MSGBOX_NPC
	goto MossvaleTown_House_1_EventScript_Man_1

MossvaleTown_House_1_EventScript_Man_5:
# 16 "data/maps/MossvaleTown_House_1/scripts.pory"
	msgbox MossvaleTown_House_1_EventScript_Man_Text_2, MSGBOX_NPC
	goto MossvaleTown_House_1_EventScript_Man_1


MossvaleTown_House_1_EventScript_Woman_Text_0:
# 5 "data/maps/MossvaleTown_House_1/scripts.pory"
	.string "Pode descansar um pouco.\nA chuva não tem pressa de parar.\pAqui em Mossvale, sempre deixo\numa toalha perto da porta\lpara os visitantes.$"

MossvaleTown_House_1_EventScript_Woman_Text_1:
# 6 "data/maps/MossvaleTown_House_1/scripts.pory"
	.string "You can rest for a while.\nThe rain is in no hurry to stop.\pHere in Mossvale, I always keep\na towel by the door\lfor visitors.$"

MossvaleTown_House_1_EventScript_Woman_Text_2:
# 7 "data/maps/MossvaleTown_House_1/scripts.pory"
	.string "Puedes descansar un rato.\nLa lluvia no tiene prisa.\pAquí en Mossvale, siempre dejo\nuna toalla junto a la puerta\lpara las visitas.$"

MossvaleTown_House_1_EventScript_Man_Text_0:
# 14 "data/maps/MossvaleTown_House_1/scripts.pory"
	.string "Comprei botas impermeáveis\npara enfrentar a chuva.\pFuncionam muito bem!\nA água que entra por cima\lnunca mais sai.$"

MossvaleTown_House_1_EventScript_Man_Text_1:
# 15 "data/maps/MossvaleTown_House_1/scripts.pory"
	.string "I bought waterproof boots\nto deal with the rain.\pThey work perfectly!\nWater that gets in at the top\lnever comes out again.$"

MossvaleTown_House_1_EventScript_Man_Text_2:
# 16 "data/maps/MossvaleTown_House_1/scripts.pory"
	.string "Compré botas impermeables\npara enfrentar la lluvia.\p¡Funcionan de maravilla!\nEl agua que entra por arriba\lya no vuelve a salir.$"
