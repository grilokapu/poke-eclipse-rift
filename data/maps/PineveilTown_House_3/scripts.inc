PineveilTown_House_3_MapScripts::
	.byte 0


PineveilTown_House_3_Girl::
# 5 "data/maps/PineveilTown_House_3/scripts.pory"
	lock
# 6 "data/maps/PineveilTown_House_3/scripts.pory"
	faceplayer
# 7 "data/maps/PineveilTown_House_3/scripts.pory"
	switch VAR_LANGUAGE
# 8 "data/maps/PineveilTown_House_3/scripts.pory"
	case PT, PineveilTown_House_3_Girl_3
# 9 "data/maps/PineveilTown_House_3/scripts.pory"
	case EN, PineveilTown_House_3_Girl_4
# 10 "data/maps/PineveilTown_House_3/scripts.pory"
	case ES, PineveilTown_House_3_Girl_5
PineveilTown_House_3_Girl_1:
# 12 "data/maps/PineveilTown_House_3/scripts.pory"
	release
	end

PineveilTown_House_3_Girl_3:
# 8 "data/maps/PineveilTown_House_3/scripts.pory"
	msgbox PineveilTown_House_3_Girl_Text_0
	goto PineveilTown_House_3_Girl_1

PineveilTown_House_3_Girl_4:
# 9 "data/maps/PineveilTown_House_3/scripts.pory"
	msgbox PineveilTown_House_3_Girl_Text_1
	goto PineveilTown_House_3_Girl_1

PineveilTown_House_3_Girl_5:
# 10 "data/maps/PineveilTown_House_3/scripts.pory"
	msgbox PineveilTown_House_3_Girl_Text_2
	goto PineveilTown_House_3_Girl_1


PineveilTown_House_3_Girl_Text_0:
# 8 "data/maps/PineveilTown_House_3/scripts.pory"
	.string "Estou esperando minha mãe… ela\nsempre se atrasa um pouquinho.\pAcho que puxei isso dela!$"

PineveilTown_House_3_Girl_Text_1:
# 9 "data/maps/PineveilTown_House_3/scripts.pory"
	.string "I'm waiting for my mom… she's\nalways a little late.\pI guess I got that from her!$"

PineveilTown_House_3_Girl_Text_2:
# 10 "data/maps/PineveilTown_House_3/scripts.pory"
	.string "Estoy esperando a mi mamá… siempre\nllega un poco tarde.\p¡Creo que saqué eso de ella!$"
