LittlerootTown_BrendansHouse_2F_MapScripts::
	.byte 0


PineveilTown_RivalRoom_RivalConversation::
# 5 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lock
# 6 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	faceplayer
# 7 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case PT, PineveilTown_RivalRoom_RivalConversation_3
# 9 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case EN, PineveilTown_RivalRoom_RivalConversation_4
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case ES, PineveilTown_RivalRoom_RivalConversation_5
PineveilTown_RivalRoom_RivalConversation_1:
# 12 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	pause 20
# 13 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case PT, PineveilTown_RivalRoom_RivalConversation_8
# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case EN, PineveilTown_RivalRoom_RivalConversation_9
# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case ES, PineveilTown_RivalRoom_RivalConversation_10
PineveilTown_RivalRoom_RivalConversation_6:
# 18 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_EAST
	goto_if_eq PineveilTown_RivalRoom_RivalConversation_12
# 21 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	movenpc LOCALID_LUCIEN_ROOM, Movement_Rival_Leaves_Room_1
PineveilTown_RivalRoom_RivalConversation_11:
# 23 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_EXIT
# 24 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	removeobject LOCALID_LUCIEN_ROOM
# 25 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_RIVAL_LEAVE_HOUSE
# 26 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	release
	end

PineveilTown_RivalRoom_RivalConversation_3:
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, PineveilTown_RivalRoom_RivalConversation_Text_0, PineveilTown_RivalRoom_RivalConversation_Text_1, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalRoom_RivalConversation_1

PineveilTown_RivalRoom_RivalConversation_4:
# 9 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, PineveilTown_RivalRoom_RivalConversation_Text_0, PineveilTown_RivalRoom_RivalConversation_Text_2, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalRoom_RivalConversation_1

PineveilTown_RivalRoom_RivalConversation_5:
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, PineveilTown_RivalRoom_RivalConversation_Text_0, PineveilTown_RivalRoom_RivalConversation_Text_3, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalRoom_RivalConversation_1

PineveilTown_RivalRoom_RivalConversation_8:
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, PineveilTown_RivalRoom_RivalConversation_Text_0, PineveilTown_RivalRoom_RivalConversation_Text_4, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalRoom_RivalConversation_6

PineveilTown_RivalRoom_RivalConversation_9:
# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, PineveilTown_RivalRoom_RivalConversation_Text_0, PineveilTown_RivalRoom_RivalConversation_Text_5, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalRoom_RivalConversation_6

PineveilTown_RivalRoom_RivalConversation_10:
# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgminibox PSS_ICON_LUCIEN, PineveilTown_RivalRoom_RivalConversation_Text_0, PineveilTown_RivalRoom_RivalConversation_Text_6, MSGBOX_AUTOCLOSE
	goto PineveilTown_RivalRoom_RivalConversation_6

PineveilTown_RivalRoom_RivalConversation_12:
# 19 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	movenpc LOCALID_LUCIEN_ROOM, Movement_Rival_Leaves_Room_2
	goto PineveilTown_RivalRoom_RivalConversation_11


# 30 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
Movement_Rival_Leaves_Room_1:
# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 32 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 33 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 34 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	set_invisible
# 35 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
	step_end

# 38 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
Movement_Rival_Leaves_Room_2:
# 39 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 40 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 40 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 40 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 41 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 42 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 43 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 44 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 45 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	set_invisible
# 46 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
	step_end

PineveilTown_RivalRoom_RivalConversation_Text_0:
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "????$"

PineveilTown_RivalRoom_RivalConversation_Text_1:
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "...\pVocê também vai ao laboratório?\pHm.\pEntão anda logo.\nA Professora Hikari odeia atrasos.$"

PineveilTown_RivalRoom_RivalConversation_Text_2:
# 9 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "...\pYou're going to the laboratory\ntoo?\pHmm.\pThen hurry up.\nProfessor Hikari hates delays.$"

PineveilTown_RivalRoom_RivalConversation_Text_3:
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "...\p¿Tú también vas al laboratorio?\pHmm.\pEntonces date prisa.\nLa Profesora Hikari odia los\lretrasos.$"

PineveilTown_RivalRoom_RivalConversation_Text_4:
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "...\pNos vemos lá.$"

PineveilTown_RivalRoom_RivalConversation_Text_5:
# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "...\pSee you there.$"

PineveilTown_RivalRoom_RivalConversation_Text_6:
# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "...\pNos vemos allí.$"
