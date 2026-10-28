Route5_MapScripts::
	.byte 0


Route5_EventScript_MeetElowen::
# 5 "data/maps/Route5/scripts.pory"
	lockall
# 7 "data/maps/Route5/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 8 "data/maps/Route5/scripts.pory"
	compare VAR_0x8005, 21
	goto_if_eq Route5_EventScript_MeetElowen_2
Route5_EventScript_MeetElowen_1:
# 11 "data/maps/Route5/scripts.pory"
	moveplayer Route5_EventScript_MeetElowen_Movement_1
# 12 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_ELOWEN, Route5_EventScript_MeetElowen_Movement_1
# 13 "data/maps/Route5/scripts.pory"
	pause 24
# 14 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_SHROOMISH, Route5_EventScript_MeetElowen_Movement_2
# 15 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenCalm
# 16 "data/maps/Route5/scripts.pory"
	pause 24
# 17 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_SHROOMISH, Route5_EventScript_MeetElowen_Movement_3
# 18 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenRest
# 21 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_ELOWEN, Route5_EventScript_MeetElowen_Movement_4
# 22 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_SHROOMISH, Route5_EventScript_MeetElowen_Movement_5
# 23 "data/maps/Route5/scripts.pory"
	pause 16
# 24 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_ELOWEN, Route5_EventScript_MeetElowen_Movement_3
# 25 "data/maps/Route5/scripts.pory"
	pause 16
# 26 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenNotice
# 27 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_ELOWEN, Route5_EventScript_MeetElowen_Movement_1
# 28 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenFound
# 29 "data/maps/Route5/scripts.pory"
	pause 20
# 30 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenSanctum
# 31 "data/maps/Route5/scripts.pory"
	pause 16
# 32 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenNotFirst
# 33 "data/maps/Route5/scripts.pory"
	pause 20
# 34 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenLeaving
# 35 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_ELOWEN, Route5_EventScript_MeetElowen_Movement_3
# 36 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenQuestion
# 38 "data/maps/Route5/scripts.pory"
	moveplayer Route5_EventScript_MeetElowen_Movement_6
# 39 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenUnderstand
# 40 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_ELOWEN, Route5_EventScript_MeetElowen_Movement_1
# 41 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenPhilosophy
# 42 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_SHROOMISH, Route5_EventScript_MeetElowen_Movement_7
# 43 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenBetter
# 45 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_SHROOMISH, Route5_EventScript_MeetElowen_Movement_8
# 47 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_SHROOMISH, Route5_EventScript_MeetElowen_Movement_9
# 48 "data/maps/Route5/scripts.pory"
	setflag FLAG_HIDE_ROUTE5_SHROOMISH
# 49 "data/maps/Route5/scripts.pory"
	removeobject LOCALID_ROUTE_5_SHROOMISH
# 50 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_ELOWEN, Route5_EventScript_MeetElowen_Movement_3
# 51 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenContinue
# 52 "data/maps/Route5/scripts.pory"
	pause 20
# 53 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenTown
# 54 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenAgain
# 55 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_ELOWEN, Route5_EventScript_MeetElowen_Movement_7
# 56 "data/maps/Route5/scripts.pory"
	call Route5_EventScript_ElowenBye
# 58 "data/maps/Route5/scripts.pory"
	movenpc LOCALID_ROUTE_5_ELOWEN, Route5_EventScript_MeetElowen_Movement_10
# 59 "data/maps/Route5/scripts.pory"
	setflag FLAG_HIDE_ROUTE5_ELOWEN
# 60 "data/maps/Route5/scripts.pory"
	removeobject LOCALID_ROUTE_5_ELOWEN
# 61 "data/maps/Route5/scripts.pory"
	setflag FLAG_MET_ELOWEN_ROUTE5
# 62 "data/maps/Route5/scripts.pory"
	setvar VAR_ROUTE5_STATE, 1
# 63 "data/maps/Route5/scripts.pory"
	releaseall
	end

Route5_EventScript_MeetElowen_2:
# 9 "data/maps/Route5/scripts.pory"
	moveplayer Route5_EventScript_MeetElowen_Movement_0
	goto Route5_EventScript_MeetElowen_1


Route5_EventScript_ElowenCalm::
# 68 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 69 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenCalm_3
# 70 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenCalm_4
# 71 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenCalm_5
Route5_EventScript_ElowenCalm_1:
	return

Route5_EventScript_ElowenCalm_3:
# 69 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenCalm_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenCalm_1

Route5_EventScript_ElowenCalm_4:
# 70 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenCalm_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenCalm_1

Route5_EventScript_ElowenCalm_5:
# 71 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenCalm_Text_3, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenCalm_1


Route5_EventScript_ElowenRest::
# 77 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 78 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenRest_3
# 79 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenRest_4
# 80 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenRest_5
Route5_EventScript_ElowenRest_1:
	return

Route5_EventScript_ElowenRest_3:
# 78 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenRest_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenRest_1

Route5_EventScript_ElowenRest_4:
# 79 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenRest_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenRest_1

Route5_EventScript_ElowenRest_5:
# 80 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenRest_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenRest_1


Route5_EventScript_ElowenNotice::
# 86 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 87 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenNotice_3
# 88 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenNotice_4
# 89 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenNotice_5
Route5_EventScript_ElowenNotice_1:
	return

Route5_EventScript_ElowenNotice_3:
# 87 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenNotice_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenNotice_1

Route5_EventScript_ElowenNotice_4:
# 88 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenNotice_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenNotice_1

Route5_EventScript_ElowenNotice_5:
# 89 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenNotice_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenNotice_1


Route5_EventScript_ElowenFound::
# 95 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 96 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenFound_3
# 97 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenFound_4
# 98 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenFound_5
Route5_EventScript_ElowenFound_1:
	return

Route5_EventScript_ElowenFound_3:
# 96 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenFound_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenFound_1

Route5_EventScript_ElowenFound_4:
# 97 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenFound_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenFound_1

Route5_EventScript_ElowenFound_5:
# 98 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenFound_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenFound_1


Route5_EventScript_ElowenSanctum::
# 104 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 105 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenSanctum_3
# 106 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenSanctum_4
# 107 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenSanctum_5
Route5_EventScript_ElowenSanctum_1:
	return

Route5_EventScript_ElowenSanctum_3:
# 105 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenSanctum_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenSanctum_1

Route5_EventScript_ElowenSanctum_4:
# 106 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenSanctum_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenSanctum_1

Route5_EventScript_ElowenSanctum_5:
# 107 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenSanctum_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenSanctum_1


Route5_EventScript_ElowenNotFirst::
# 113 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 114 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenNotFirst_3
# 115 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenNotFirst_4
# 116 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenNotFirst_5
Route5_EventScript_ElowenNotFirst_1:
	return

Route5_EventScript_ElowenNotFirst_3:
# 114 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenNotFirst_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenNotFirst_1

Route5_EventScript_ElowenNotFirst_4:
# 115 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenNotFirst_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenNotFirst_1

Route5_EventScript_ElowenNotFirst_5:
# 116 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenNotFirst_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenNotFirst_1


Route5_EventScript_ElowenLeaving::
# 122 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 123 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenLeaving_3
# 124 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenLeaving_4
# 125 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenLeaving_5
Route5_EventScript_ElowenLeaving_1:
	return

Route5_EventScript_ElowenLeaving_3:
# 123 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenLeaving_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenLeaving_1

Route5_EventScript_ElowenLeaving_4:
# 124 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenLeaving_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenLeaving_1

Route5_EventScript_ElowenLeaving_5:
# 125 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenLeaving_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenLeaving_1


Route5_EventScript_ElowenQuestion::
# 131 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 132 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenQuestion_3
# 133 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenQuestion_4
# 134 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenQuestion_5
Route5_EventScript_ElowenQuestion_1:
	return

Route5_EventScript_ElowenQuestion_3:
# 132 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenQuestion_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenQuestion_1

Route5_EventScript_ElowenQuestion_4:
# 133 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenQuestion_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenQuestion_1

Route5_EventScript_ElowenQuestion_5:
# 134 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenQuestion_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenQuestion_1


Route5_EventScript_ElowenUnderstand::
# 140 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 141 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenUnderstand_3
# 142 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenUnderstand_4
# 143 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenUnderstand_5
Route5_EventScript_ElowenUnderstand_1:
	return

Route5_EventScript_ElowenUnderstand_3:
# 141 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenUnderstand_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenUnderstand_1

Route5_EventScript_ElowenUnderstand_4:
# 142 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenUnderstand_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenUnderstand_1

Route5_EventScript_ElowenUnderstand_5:
# 143 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenUnderstand_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenUnderstand_1


Route5_EventScript_ElowenPhilosophy::
# 149 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 150 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenPhilosophy_3
# 151 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenPhilosophy_4
# 152 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenPhilosophy_5
Route5_EventScript_ElowenPhilosophy_1:
	return

Route5_EventScript_ElowenPhilosophy_3:
# 150 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenPhilosophy_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenPhilosophy_1

Route5_EventScript_ElowenPhilosophy_4:
# 151 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenPhilosophy_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenPhilosophy_1

Route5_EventScript_ElowenPhilosophy_5:
# 152 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenPhilosophy_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenPhilosophy_1


Route5_EventScript_ElowenBetter::
# 158 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 159 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenBetter_3
# 160 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenBetter_4
# 161 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenBetter_5
Route5_EventScript_ElowenBetter_1:
	return

Route5_EventScript_ElowenBetter_3:
# 159 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenBetter_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenBetter_1

Route5_EventScript_ElowenBetter_4:
# 160 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenBetter_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenBetter_1

Route5_EventScript_ElowenBetter_5:
# 161 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenBetter_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenBetter_1


Route5_EventScript_ElowenContinue::
# 167 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 168 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenContinue_3
# 169 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenContinue_4
# 170 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenContinue_5
Route5_EventScript_ElowenContinue_1:
	return

Route5_EventScript_ElowenContinue_3:
# 168 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenContinue_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenContinue_1

Route5_EventScript_ElowenContinue_4:
# 169 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenContinue_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenContinue_1

Route5_EventScript_ElowenContinue_5:
# 170 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenContinue_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenContinue_1


Route5_EventScript_ElowenTown::
# 176 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 177 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenTown_3
# 178 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenTown_4
# 179 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenTown_5
Route5_EventScript_ElowenTown_1:
	return

Route5_EventScript_ElowenTown_3:
# 177 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenTown_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenTown_1

Route5_EventScript_ElowenTown_4:
# 178 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenTown_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenTown_1

Route5_EventScript_ElowenTown_5:
# 179 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenTown_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenTown_1


Route5_EventScript_ElowenAgain::
# 185 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 186 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenAgain_3
# 187 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenAgain_4
# 188 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenAgain_5
Route5_EventScript_ElowenAgain_1:
	return

Route5_EventScript_ElowenAgain_3:
# 186 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenAgain_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenAgain_1

Route5_EventScript_ElowenAgain_4:
# 187 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenAgain_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenAgain_1

Route5_EventScript_ElowenAgain_5:
# 188 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenAgain_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenAgain_1


Route5_EventScript_ElowenBye::
# 194 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 195 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_ElowenBye_3
# 196 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_ElowenBye_4
# 197 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_ElowenBye_5
Route5_EventScript_ElowenBye_1:
	return

Route5_EventScript_ElowenBye_3:
# 195 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenBye_Text_0, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenBye_1

Route5_EventScript_ElowenBye_4:
# 196 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenBye_Text_1, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenBye_1

Route5_EventScript_ElowenBye_5:
# 197 "data/maps/Route5/scripts.pory"
	msgminibox PSS_ICON_ELOWEN, Route5_EventScript_ElowenCalm_Text_0, Route5_EventScript_ElowenBye_Text_2, MSGBOX_DEFAULT
	goto Route5_EventScript_ElowenBye_1


Route5_EventScript_BlackBelt_Battle::
# 203 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 204 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_BlackBelt_Battle_3
# 207 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_BlackBelt_Battle_4
# 210 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_BlackBelt_Battle_5
Route5_EventScript_BlackBelt_Battle_1:
# 214 "data/maps/Route5/scripts.pory"
	release
	end

Route5_EventScript_BlackBelt_Battle_3:
# 205 "data/maps/Route5/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_SALATIEL, Route5_EventScript_BlackBelt_Battle_Text_0, Route5_EventScript_BlackBelt_Battle_Text_1
# 206 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_BlackBelt_Battle_Text_2, MSGBOX_NPC
	goto Route5_EventScript_BlackBelt_Battle_1

Route5_EventScript_BlackBelt_Battle_4:
# 208 "data/maps/Route5/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_SALATIEL, Route5_EventScript_BlackBelt_Battle_Text_3, Route5_EventScript_BlackBelt_Battle_Text_4
# 209 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_BlackBelt_Battle_Text_5, MSGBOX_NPC
	goto Route5_EventScript_BlackBelt_Battle_1

Route5_EventScript_BlackBelt_Battle_5:
# 211 "data/maps/Route5/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_SALATIEL, Route5_EventScript_BlackBelt_Battle_Text_6, Route5_EventScript_BlackBelt_Battle_Text_7
# 212 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_BlackBelt_Battle_Text_8, MSGBOX_NPC
	goto Route5_EventScript_BlackBelt_Battle_1


Route5_EventScript_Picnicker_Battle::
# 219 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 220 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_Picnicker_Battle_3
# 223 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_Picnicker_Battle_4
# 226 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_Picnicker_Battle_5
Route5_EventScript_Picnicker_Battle_1:
# 230 "data/maps/Route5/scripts.pory"
	release
	end

Route5_EventScript_Picnicker_Battle_3:
# 221 "data/maps/Route5/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_RENATA, Route5_EventScript_Picnicker_Battle_Text_0, Route5_EventScript_Picnicker_Battle_Text_1
# 222 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_Picnicker_Battle_Text_2, MSGBOX_NPC
	goto Route5_EventScript_Picnicker_Battle_1

Route5_EventScript_Picnicker_Battle_4:
# 224 "data/maps/Route5/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_RENATA, Route5_EventScript_Picnicker_Battle_Text_3, Route5_EventScript_Picnicker_Battle_Text_4
# 225 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_Picnicker_Battle_Text_5, MSGBOX_NPC
	goto Route5_EventScript_Picnicker_Battle_1

Route5_EventScript_Picnicker_Battle_5:
# 227 "data/maps/Route5/scripts.pory"
	trainerbattle_single TRAINER_PICNICKER_RENATA, Route5_EventScript_Picnicker_Battle_Text_6, Route5_EventScript_Picnicker_Battle_Text_7
# 228 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_Picnicker_Battle_Text_8, MSGBOX_NPC
	goto Route5_EventScript_Picnicker_Battle_1


Route5_EventScript_Man::
# 235 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 236 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_Man_3
# 237 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_Man_4
# 238 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_Man_5
Route5_EventScript_Man_1:
	end

Route5_EventScript_Man_3:
# 236 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_Man_Text_0, MSGBOX_NPC
	goto Route5_EventScript_Man_1

Route5_EventScript_Man_4:
# 237 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_Man_Text_1, MSGBOX_NPC
	goto Route5_EventScript_Man_1

Route5_EventScript_Man_5:
# 238 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_Man_Text_2, MSGBOX_NPC
	goto Route5_EventScript_Man_1


Route5_EventScript_Backpacker::
# 244 "data/maps/Route5/scripts.pory"
	switch VAR_LANGUAGE
# 245 "data/maps/Route5/scripts.pory"
	case PT, Route5_EventScript_Backpacker_3
# 246 "data/maps/Route5/scripts.pory"
	case EN, Route5_EventScript_Backpacker_4
# 247 "data/maps/Route5/scripts.pory"
	case ES, Route5_EventScript_Backpacker_5
Route5_EventScript_Backpacker_1:
	end

Route5_EventScript_Backpacker_3:
# 245 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_Backpacker_Text_0, MSGBOX_NPC
	goto Route5_EventScript_Backpacker_1

Route5_EventScript_Backpacker_4:
# 246 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_Backpacker_Text_1, MSGBOX_NPC
	goto Route5_EventScript_Backpacker_1

Route5_EventScript_Backpacker_5:
# 247 "data/maps/Route5/scripts.pory"
	msgbox Route5_EventScript_Backpacker_Text_2, MSGBOX_NPC
	goto Route5_EventScript_Backpacker_1


# 9 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_0:
# 9 "data/maps/Route5/scripts.pory"
	walk_down
	step_end

# 11 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_1:
# 11 "data/maps/Route5/scripts.pory"
	face_right
	step_end

# 14 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_2:
# 14 "data/maps/Route5/scripts.pory"
	emoji_doubt
	step_end

# 17 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_3:
# 17 "data/maps/Route5/scripts.pory"
	face_left
	step_end

# 21 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_4:
# 21 "data/maps/Route5/scripts.pory"
	walk_in_place_slow_right
# 21 "data/maps/Route5/scripts.pory"
	delay_8
# 21 "data/maps/Route5/scripts.pory"
	face_right
	step_end

# 22 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_5:
# 22 "data/maps/Route5/scripts.pory"
	emoji_relaxed
	step_end

# 38 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_6:
# 38 "data/maps/Route5/scripts.pory"
	walk_in_place_faster_right
# 38 "data/maps/Route5/scripts.pory"
	face_right
	step_end

# 42 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_7:
# 42 "data/maps/Route5/scripts.pory"
	emoji_smiley
	step_end

# 45 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_8:
# 45 "data/maps/Route5/scripts.pory"
	face_left
# 45 "data/maps/Route5/scripts.pory"
	delay_16
# 45 "data/maps/Route5/scripts.pory"
	walk_down
# 45 "data/maps/Route5/scripts.pory"
	face_left
# 45 "data/maps/Route5/scripts.pory"
	delay_16
	step_end

# 47 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_9:
# 47 "data/maps/Route5/scripts.pory"
	walk_up
# 47 "data/maps/Route5/scripts.pory"
	walk_up
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_up
# 47 "data/maps/Route5/scripts.pory"
	walk_up
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
# 47 "data/maps/Route5/scripts.pory"
	walk_left
	step_end

# 58 "data/maps/Route5/scripts.pory"
Route5_EventScript_MeetElowen_Movement_10:
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
# 58 "data/maps/Route5/scripts.pory"
	walk_right
	step_end

Route5_EventScript_ElowenCalm_Text_0:
# 69 "data/maps/Route5/scripts.pory"
	.string "Elowen$"

Route5_EventScript_ElowenCalm_Text_1:
# 69 "data/maps/Route5/scripts.pory"
	.string "Calma...\pVocê já está longe daquele lugar.$"

Route5_EventScript_ElowenCalm_Text_2:
# 70 "data/maps/Route5/scripts.pory"
	.string "Easy now...\pYou are far from that place now.$"

Route5_EventScript_ElowenCalm_Text_3:
# 71 "data/maps/Route5/scripts.pory"
	.string "Tranquilo...\pYa estás lejos de aquel lugar.$"

Route5_EventScript_ElowenRest_Text_0:
# 78 "data/maps/Route5/scripts.pory"
	.string "Isso mesmo.\pDescanse um pouco.$"

Route5_EventScript_ElowenRest_Text_1:
# 79 "data/maps/Route5/scripts.pory"
	.string "That is it.\pRest a little.$"

Route5_EventScript_ElowenRest_Text_2:
# 80 "data/maps/Route5/scripts.pory"
	.string "Eso es.\pDescansa un poco.$"

Route5_EventScript_ElowenNotice_Text_0:
# 87 "data/maps/Route5/scripts.pory"
	.string "Oh!\pDesculpe. Nem percebi\nvocê chegando.$"

Route5_EventScript_ElowenNotice_Text_1:
# 88 "data/maps/Route5/scripts.pory"
	.string "Oh!\pSorry. I did not notice\nyou arriving.$"

Route5_EventScript_ElowenNotice_Text_2:
# 89 "data/maps/Route5/scripts.pory"
	.string "¡Oh!\pPerdona. No me di cuenta\nde que llegabas.$"

Route5_EventScript_ElowenFound_Text_0:
# 96 "data/maps/Route5/scripts.pory"
	.string "Encontrei este pequeno\nvagando sozinho.$"

Route5_EventScript_ElowenFound_Text_1:
# 97 "data/maps/Route5/scripts.pory"
	.string "I found this little one\nwandering alone.$"

Route5_EventScript_ElowenFound_Text_2:
# 98 "data/maps/Route5/scripts.pory"
	.string "Encontré a este pequeño\nvagando solo.$"

Route5_EventScript_ElowenSanctum_Text_0:
# 105 "data/maps/Route5/scripts.pory"
	.string "Ele veio correndo da direção\ndo Santuário Verde.$"

Route5_EventScript_ElowenSanctum_Text_1:
# 106 "data/maps/Route5/scripts.pory"
	.string "It came running from the\ndirection of Verdant Sanctum.$"

Route5_EventScript_ElowenSanctum_Text_2:
# 107 "data/maps/Route5/scripts.pory"
	.string "Vino corriendo desde la\ndirección del Santuario Verde.$"

Route5_EventScript_ElowenNotFirst_Text_0:
# 114 "data/maps/Route5/scripts.pory"
	.string "Não é o primeiro.$"

Route5_EventScript_ElowenNotFirst_Text_1:
# 115 "data/maps/Route5/scripts.pory"
	.string "It is not the first.$"

Route5_EventScript_ElowenNotFirst_Text_2:
# 116 "data/maps/Route5/scripts.pory"
	.string "No es el primero.$"

Route5_EventScript_ElowenLeaving_Text_0:
# 123 "data/maps/Route5/scripts.pory"
	.string "Ultimamente, alguns Pokémon\nestão deixando aquela região\lsem motivo aparente.$"

Route5_EventScript_ElowenLeaving_Text_1:
# 124 "data/maps/Route5/scripts.pory"
	.string "Lately, some Pokémon have been\nleaving that area for\lno apparent reason.$"

Route5_EventScript_ElowenLeaving_Text_2:
# 125 "data/maps/Route5/scripts.pory"
	.string "Últimamente, algunos Pokémon\nestán dejando esa región\lsin motivo aparente.$"

Route5_EventScript_ElowenQuestion_Text_0:
# 132 "data/maps/Route5/scripts.pory"
	.string "Você também veio de lá,\nnão veio?$"

Route5_EventScript_ElowenQuestion_Text_1:
# 133 "data/maps/Route5/scripts.pory"
	.string "You came from there too,\ndid you not?$"

Route5_EventScript_ElowenQuestion_Text_2:
# 134 "data/maps/Route5/scripts.pory"
	.string "Tú también vienes de allí,\n¿verdad?$"

Route5_EventScript_ElowenUnderstand_Text_0:
# 141 "data/maps/Route5/scripts.pory"
	.string "Entendo...$"

Route5_EventScript_ElowenUnderstand_Text_1:
# 142 "data/maps/Route5/scripts.pory"
	.string "I see...$"

Route5_EventScript_ElowenUnderstand_Text_2:
# 143 "data/maps/Route5/scripts.pory"
	.string "Entiendo...$"

Route5_EventScript_ElowenPhilosophy_Text_0:
# 150 "data/maps/Route5/scripts.pory"
	.string "Pokémon percebem mudanças\nmuito antes de nós.\pÀs vezes, basta observar.$"

Route5_EventScript_ElowenPhilosophy_Text_1:
# 151 "data/maps/Route5/scripts.pory"
	.string "Pokémon sense changes\nlong before we do.\pSometimes, all we need\nto do is watch.$"

Route5_EventScript_ElowenPhilosophy_Text_2:
# 152 "data/maps/Route5/scripts.pory"
	.string "Los Pokémon perciben cambios\nmucho antes que nosotros.\pA veces, basta con observar.$"

Route5_EventScript_ElowenBetter_Text_0:
# 159 "data/maps/Route5/scripts.pory"
	.string "Parece que você já está melhor.$"

Route5_EventScript_ElowenBetter_Text_1:
# 160 "data/maps/Route5/scripts.pory"
	.string "You seem to be feeling better.$"

Route5_EventScript_ElowenBetter_Text_2:
# 161 "data/maps/Route5/scripts.pory"
	.string "Parece que ya te sientes mejor.$"

Route5_EventScript_ElowenContinue_Text_0:
# 168 "data/maps/Route5/scripts.pory"
	.string "Eu também deveria continuar.$"

Route5_EventScript_ElowenContinue_Text_1:
# 169 "data/maps/Route5/scripts.pory"
	.string "I should be on my way too.$"

Route5_EventScript_ElowenContinue_Text_2:
# 170 "data/maps/Route5/scripts.pory"
	.string "Yo también debería seguir.$"

Route5_EventScript_ElowenTown_Text_0:
# 177 "data/maps/Route5/scripts.pory"
	.string "Estou voltando para\nLyndora City.$"

Route5_EventScript_ElowenTown_Text_1:
# 178 "data/maps/Route5/scripts.pory"
	.string "I am heading back\nto Lyndora City.$"

Route5_EventScript_ElowenTown_Text_2:
# 179 "data/maps/Route5/scripts.pory"
	.string "Estoy volviendo\na Lyndora City.$"

Route5_EventScript_ElowenAgain_Text_0:
# 186 "data/maps/Route5/scripts.pory"
	.string "Se estiver seguindo\nnaquela direção...\p...provavelmente nos\nveremos novamente.$"

Route5_EventScript_ElowenAgain_Text_1:
# 187 "data/maps/Route5/scripts.pory"
	.string "If you are heading\nthat way...\p...we will probably\nmeet again.$"

Route5_EventScript_ElowenAgain_Text_2:
# 188 "data/maps/Route5/scripts.pory"
	.string "Si vas en\nesa dirección...\p...probablemente volvamos\na encontrarnos.$"

Route5_EventScript_ElowenBye_Text_0:
# 195 "data/maps/Route5/scripts.pory"
	.string "Até lá.$"

Route5_EventScript_ElowenBye_Text_1:
# 196 "data/maps/Route5/scripts.pory"
	.string "Until then.$"

Route5_EventScript_ElowenBye_Text_2:
# 197 "data/maps/Route5/scripts.pory"
	.string "Hasta entonces.$"

Route5_EventScript_BlackBelt_Battle_Text_0:
# 205 "data/maps/Route5/scripts.pory"
	.string "Nem a chuva interrompe nosso\ntreino!\pMostre a força da sua equipe!$"

Route5_EventScript_BlackBelt_Battle_Text_1:
# 205 "data/maps/Route5/scripts.pory"
	.string "Que golpe! Você nos superou!$"

Route5_EventScript_BlackBelt_Battle_Text_2:
# 206 "data/maps/Route5/scripts.pory"
	.string "Força não é tudo numa batalha.\pMeu próximo treino será aprender\ncom esta derrota!$"

Route5_EventScript_BlackBelt_Battle_Text_3:
# 208 "data/maps/Route5/scripts.pory"
	.string "Even rain can't stop our\ntraining!\pShow me your team's strength!$"

Route5_EventScript_BlackBelt_Battle_Text_4:
# 208 "data/maps/Route5/scripts.pory"
	.string "What a hit! You outmatched us!$"

Route5_EventScript_BlackBelt_Battle_Text_5:
# 209 "data/maps/Route5/scripts.pory"
	.string "Strength isn't everything in\na battle.\pMy next exercise is learning\nfrom this defeat!$"

Route5_EventScript_BlackBelt_Battle_Text_6:
# 211 "data/maps/Route5/scripts.pory"
	.string "¡Ni la lluvia detiene nuestro\nentrenamiento!\p¡Muéstrame la fuerza de tu equipo!$"

Route5_EventScript_BlackBelt_Battle_Text_7:
# 211 "data/maps/Route5/scripts.pory"
	.string "¡Qué golpe! ¡Nos superaste!$"

Route5_EventScript_BlackBelt_Battle_Text_8:
# 212 "data/maps/Route5/scripts.pory"
	.string "La fuerza no lo es todo en\nun combate.\p¡Mi próximo ejercicio será\naprender de esta derrota!$"

Route5_EventScript_Picnicker_Battle_Text_0:
# 221 "data/maps/Route5/scripts.pory"
	.string "A chuva estragou meu piquenique...\pMas uma batalha pode salvar o dia!$"

Route5_EventScript_Picnicker_Battle_Text_1:
# 221 "data/maps/Route5/scripts.pory"
	.string "Até perdi a vontade de comer!$"

Route5_EventScript_Picnicker_Battle_Text_2:
# 222 "data/maps/Route5/scripts.pory"
	.string "Dolliv gosta desta chuvinha,\ne Castform já entrou no clima!\pAcho que só eu queria sol...$"

Route5_EventScript_Picnicker_Battle_Text_3:
# 224 "data/maps/Route5/scripts.pory"
	.string "The rain ruined my picnic...\pBut a battle could save the day!$"

Route5_EventScript_Picnicker_Battle_Text_4:
# 224 "data/maps/Route5/scripts.pory"
	.string "I even lost my appetite!$"

Route5_EventScript_Picnicker_Battle_Text_5:
# 225 "data/maps/Route5/scripts.pory"
	.string "Dolliv likes this drizzle,\nand Castform feels right at home!\pI guess only I wanted sunshine...$"

Route5_EventScript_Picnicker_Battle_Text_6:
# 227 "data/maps/Route5/scripts.pory"
	.string "La lluvia arruinó mi picnic...\p¡Pero un combate alegrará el día!$"

Route5_EventScript_Picnicker_Battle_Text_7:
# 227 "data/maps/Route5/scripts.pory"
	.string "¡Hasta se me quitó el hambre!$"

Route5_EventScript_Picnicker_Battle_Text_8:
# 228 "data/maps/Route5/scripts.pory"
	.string "A Dolliv le gusta esta lluvia,\n¡y Castform ya se ha adaptado!\pCreo que solo yo quería sol...$"

Route5_EventScript_Man_Text_0:
# 236 "data/maps/Route5/scripts.pory"
	.string "Eu gostaria de batalhar naquela\narena...\pMas não posso participar.\nAinda não tenho Pokémon\lsuficientes na minha equipe!$"

Route5_EventScript_Man_Text_1:
# 237 "data/maps/Route5/scripts.pory"
	.string "I'd love to battle in that\narena...\pBut I can't take part.\nI don't have enough Pokémon\lon my team yet!$"

Route5_EventScript_Man_Text_2:
# 238 "data/maps/Route5/scripts.pory"
	.string "Me gustaría combatir en aquella\narena...\pPero no puedo participar.\n¡Aún no tengo suficientes\lPokémon en mi equipo!$"

Route5_EventScript_Backpacker_Text_0:
# 245 "data/maps/Route5/scripts.pory"
	.string "Estou indo para Lyndora City\npara curar meus Pokémon.\pA viagem foi puxada...\nMeus parceiros merecem\lum bom descanso!$"

Route5_EventScript_Backpacker_Text_1:
# 246 "data/maps/Route5/scripts.pory"
	.string "I'm heading to Lyndora City\nto heal my Pokémon.\pIt's been a tough journey...\nMy partners deserve\la good rest!$"

Route5_EventScript_Backpacker_Text_2:
# 247 "data/maps/Route5/scripts.pory"
	.string "Voy hacia Lyndora City\npara curar a mis Pokémon.\pEl viaje ha sido duro...\n¡Mis compañeros merecen\lun buen descanso!$"
