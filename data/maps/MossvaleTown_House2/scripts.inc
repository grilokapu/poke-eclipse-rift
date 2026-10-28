MossvaleTown_House2_MapScripts::
	.byte 0


MossvaleTown_House2_EventScript_Gardener::
# 4 "data/maps/MossvaleTown_House2/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/MossvaleTown_House2/scripts.pory"
	case PT, MossvaleTown_House2_EventScript_Gardener_3
# 6 "data/maps/MossvaleTown_House2/scripts.pory"
	case EN, MossvaleTown_House2_EventScript_Gardener_4
# 7 "data/maps/MossvaleTown_House2/scripts.pory"
	case ES, MossvaleTown_House2_EventScript_Gardener_5
MossvaleTown_House2_EventScript_Gardener_1:
	end

MossvaleTown_House2_EventScript_Gardener_3:
# 5 "data/maps/MossvaleTown_House2/scripts.pory"
	msgbox MossvaleTown_House2_EventScript_Gardener_Text_0, MSGBOX_NPC
	goto MossvaleTown_House2_EventScript_Gardener_1

MossvaleTown_House2_EventScript_Gardener_4:
# 6 "data/maps/MossvaleTown_House2/scripts.pory"
	msgbox MossvaleTown_House2_EventScript_Gardener_Text_1, MSGBOX_NPC
	goto MossvaleTown_House2_EventScript_Gardener_1

MossvaleTown_House2_EventScript_Gardener_5:
# 7 "data/maps/MossvaleTown_House2/scripts.pory"
	msgbox MossvaleTown_House2_EventScript_Gardener_Text_2, MSGBOX_NPC
	goto MossvaleTown_House2_EventScript_Gardener_1


MossvaleTown_House2_EventScript_Girl::
# 13 "data/maps/MossvaleTown_House2/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/MossvaleTown_House2/scripts.pory"
	case PT, MossvaleTown_House2_EventScript_Girl_3
# 15 "data/maps/MossvaleTown_House2/scripts.pory"
	case EN, MossvaleTown_House2_EventScript_Girl_4
# 16 "data/maps/MossvaleTown_House2/scripts.pory"
	case ES, MossvaleTown_House2_EventScript_Girl_5
MossvaleTown_House2_EventScript_Girl_1:
	end

MossvaleTown_House2_EventScript_Girl_3:
# 14 "data/maps/MossvaleTown_House2/scripts.pory"
	msgbox MossvaleTown_House2_EventScript_Girl_Text_0, MSGBOX_NPC
	goto MossvaleTown_House2_EventScript_Girl_1

MossvaleTown_House2_EventScript_Girl_4:
# 15 "data/maps/MossvaleTown_House2/scripts.pory"
	msgbox MossvaleTown_House2_EventScript_Girl_Text_1, MSGBOX_NPC
	goto MossvaleTown_House2_EventScript_Girl_1

MossvaleTown_House2_EventScript_Girl_5:
# 16 "data/maps/MossvaleTown_House2/scripts.pory"
	msgbox MossvaleTown_House2_EventScript_Girl_Text_2, MSGBOX_NPC
	goto MossvaleTown_House2_EventScript_Girl_1


MossvaleTown_House2_EventScript_Gardener_Text_0:
# 5 "data/maps/MossvaleTown_House2/scripts.pory"
	.string "As plantas gostam de água,\nmas também precisam de cuidado.\pTodo dia olho as folhas.\nÉ assim que percebo quando\lalguma não está bem.$"

MossvaleTown_House2_EventScript_Gardener_Text_1:
# 6 "data/maps/MossvaleTown_House2/scripts.pory"
	.string "Plants like water, but they\nneed care as well.\pI check their leaves each day.\nThat is how I notice when\none is not doing well.$"

MossvaleTown_House2_EventScript_Gardener_Text_2:
# 7 "data/maps/MossvaleTown_House2/scripts.pory"
	.string "A las plantas les gusta el agua,\npero también necesitan cuidados.\pReviso sus hojas cada día.\nAsí me doy cuenta cuando\lalguna no está bien.$"

MossvaleTown_House2_EventScript_Girl_Text_0:
# 14 "data/maps/MossvaleTown_House2/scripts.pory"
	.string "Disseram que conversar com\nas plantas ajuda a crescer.\pContei minhas notas da escola.\nAcho que a samambaia\ldesmaiou.$"

MossvaleTown_House2_EventScript_Girl_Text_1:
# 15 "data/maps/MossvaleTown_House2/scripts.pory"
	.string "They said talking to plants\nhelps them grow.\pI told them my school grades.\nI think the fern\ljust fainted.$"

MossvaleTown_House2_EventScript_Girl_Text_2:
# 16 "data/maps/MossvaleTown_House2/scripts.pory"
	.string "Dicen que hablar con las\nplantas las ayuda a crecer.\pLes conté mis notas de clase.\nCreo que el helecho\lse desmayó.$"
