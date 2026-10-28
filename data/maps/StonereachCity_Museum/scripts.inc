StonereachCity_Museum_MapScripts::
	.byte 0


StonereachCity_Museum_EntranceTrigger::
# 6 "data/maps/StonereachCity_Museum/scripts.pory"
	goto_if_set FLAG_STONEREACH_MUSEUM_ADMISSION_PAID, StonereachCity_Museum_EntranceTrigger_2
# 9 "data/maps/StonereachCity_Museum/scripts.pory"
	lockall
# 10 "data/maps/StonereachCity_Museum/scripts.pory"
	playse SE_PIN
# 11 "data/maps/StonereachCity_Museum/scripts.pory"
	movenpc LOCALID_MUSEUM_DOORMAN, StonereachCity_Museum_EntranceTrigger_Movement_0
# 12 "data/maps/StonereachCity_Museum/scripts.pory"
	waitse
# 13 "data/maps/StonereachCity_Museum/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 14 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_0x8004
# 15 "data/maps/StonereachCity_Museum/scripts.pory"
	case 18, StonereachCity_Museum_EntranceTrigger_6
# 16 "data/maps/StonereachCity_Museum/scripts.pory"
	case 19, StonereachCity_Museum_EntranceTrigger_7
# 17 "data/maps/StonereachCity_Museum/scripts.pory"
	case 20, StonereachCity_Museum_EntranceTrigger_8
# 18 "data/maps/StonereachCity_Museum/scripts.pory"
	case 21, StonereachCity_Museum_EntranceTrigger_9
# 19 "data/maps/StonereachCity_Museum/scripts.pory"
	case 22, StonereachCity_Museum_EntranceTrigger_10
StonereachCity_Museum_EntranceTrigger_4:
# 21 "data/maps/StonereachCity_Museum/scripts.pory"
	call StonereachCity_Museum_Admission
# 22 "data/maps/StonereachCity_Museum/scripts.pory"
	goto_if_unset FLAG_STONEREACH_MUSEUM_ADMISSION_PAID, StonereachCity_Museum_EntranceTrigger_12
StonereachCity_Museum_EntranceTrigger_11:
# 25 "data/maps/StonereachCity_Museum/scripts.pory"
	releaseall
	end

StonereachCity_Museum_EntranceTrigger_2:
	end

StonereachCity_Museum_EntranceTrigger_6:
# 15 "data/maps/StonereachCity_Museum/scripts.pory"
	moveplayer StonereachCity_Museum_EntranceTrigger_Movement_1
	goto StonereachCity_Museum_EntranceTrigger_4

StonereachCity_Museum_EntranceTrigger_7:
# 16 "data/maps/StonereachCity_Museum/scripts.pory"
	moveplayer StonereachCity_Museum_EntranceTrigger_Movement_2
	goto StonereachCity_Museum_EntranceTrigger_4

StonereachCity_Museum_EntranceTrigger_8:
# 17 "data/maps/StonereachCity_Museum/scripts.pory"
	moveplayer StonereachCity_Museum_EntranceTrigger_Movement_3
	goto StonereachCity_Museum_EntranceTrigger_4

StonereachCity_Museum_EntranceTrigger_9:
# 18 "data/maps/StonereachCity_Museum/scripts.pory"
	moveplayer StonereachCity_Museum_EntranceTrigger_Movement_4
	goto StonereachCity_Museum_EntranceTrigger_4

StonereachCity_Museum_EntranceTrigger_10:
# 19 "data/maps/StonereachCity_Museum/scripts.pory"
	moveplayer StonereachCity_Museum_EntranceTrigger_Movement_5
	goto StonereachCity_Museum_EntranceTrigger_4

StonereachCity_Museum_EntranceTrigger_12:
# 23 "data/maps/StonereachCity_Museum/scripts.pory"
	moveplayer StonereachCity_Museum_EntranceTrigger_Movement_6
	goto StonereachCity_Museum_EntranceTrigger_11


StonereachCity_Museum_Doorman_Talk::
# 30 "data/maps/StonereachCity_Museum/scripts.pory"
	lock
# 31 "data/maps/StonereachCity_Museum/scripts.pory"
	faceplayer
# 32 "data/maps/StonereachCity_Museum/scripts.pory"
	call StonereachCity_Museum_Admission
# 33 "data/maps/StonereachCity_Museum/scripts.pory"
	release
	end


StonereachCity_Museum_Admission::
# 38 "data/maps/StonereachCity_Museum/scripts.pory"
	goto_if_set FLAG_STONEREACH_MUSEUM_ADMISSION_PAID, StonereachCity_Museum_Admission_2
# 46 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 47 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Admission_6
# 48 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Admission_7
# 49 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Admission_8
StonereachCity_Museum_Admission_4:
# 51 "data/maps/StonereachCity_Museum/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq StonereachCity_Museum_Admission_15
# 59 "data/maps/StonereachCity_Museum/scripts.pory"
	checkmoney 2000
# 60 "data/maps/StonereachCity_Museum/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq StonereachCity_Museum_Admission_18
# 68 "data/maps/StonereachCity_Museum/scripts.pory"
	removemoney 2000
# 69 "data/maps/StonereachCity_Museum/scripts.pory"
	setflag FLAG_STONEREACH_MUSEUM_ADMISSION_PAID
# 70 "data/maps/StonereachCity_Museum/scripts.pory"
	playse SE_SHOP
# 71 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 72 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Admission_27
# 73 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Admission_28
# 74 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Admission_29
StonereachCity_Museum_Admission_25:
	return

StonereachCity_Museum_Admission_2:
# 39 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 40 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Admission_11
# 41 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Admission_12
# 42 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Admission_13
StonereachCity_Museum_Admission_9:
	return

StonereachCity_Museum_Admission_6:
# 47 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_3, MSGBOX_YESNO
	goto StonereachCity_Museum_Admission_4

StonereachCity_Museum_Admission_7:
# 48 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_4, MSGBOX_YESNO
	goto StonereachCity_Museum_Admission_4

StonereachCity_Museum_Admission_8:
# 49 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_5, MSGBOX_YESNO
	goto StonereachCity_Museum_Admission_4

StonereachCity_Museum_Admission_11:
# 40 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_0, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_9

StonereachCity_Museum_Admission_12:
# 41 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_1, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_9

StonereachCity_Museum_Admission_13:
# 42 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_2, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_9

StonereachCity_Museum_Admission_15:
# 52 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 53 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Admission_22
# 54 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Admission_23
# 55 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Admission_24
StonereachCity_Museum_Admission_20:
	return

StonereachCity_Museum_Admission_18:
# 61 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 62 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Admission_32
# 63 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Admission_33
# 64 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Admission_34
StonereachCity_Museum_Admission_30:
	return

StonereachCity_Museum_Admission_22:
# 53 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_6, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_20

StonereachCity_Museum_Admission_23:
# 54 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_7, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_20

StonereachCity_Museum_Admission_24:
# 55 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_8, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_20

StonereachCity_Museum_Admission_27:
# 72 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_12, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_25

StonereachCity_Museum_Admission_28:
# 73 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_13, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_25

StonereachCity_Museum_Admission_29:
# 74 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_14, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_25

StonereachCity_Museum_Admission_32:
# 62 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_9, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_30

StonereachCity_Museum_Admission_33:
# 63 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_10, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_30

StonereachCity_Museum_Admission_34:
# 64 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Admission_Text_11, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Admission_30


StonereachCity_Museum_Researcher_Talk::
# 80 "data/maps/StonereachCity_Museum/scripts.pory"
	lock
# 81 "data/maps/StonereachCity_Museum/scripts.pory"
	faceplayer
# 82 "data/maps/StonereachCity_Museum/scripts.pory"
	goto_if_set FLAG_STONEREACH_MUSEUM_TRADE_DONE, StonereachCity_Museum_Researcher_Talk_2
# 91 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 92 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Researcher_Talk_6
# 93 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Researcher_Talk_7
# 94 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Researcher_Talk_8
StonereachCity_Museum_Researcher_Talk_4:
# 96 "data/maps/StonereachCity_Museum/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq StonereachCity_Museum_Researcher_Talk_15
# 100 "data/maps/StonereachCity_Museum/scripts.pory"
	checkitem ITEM_RARE_BONE
# 101 "data/maps/StonereachCity_Museum/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq StonereachCity_Museum_Researcher_Talk_18
# 110 "data/maps/StonereachCity_Museum/scripts.pory"
	checkitemspace ITEM_FOSSILIZED_DRAKE
# 111 "data/maps/StonereachCity_Museum/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq StonereachCity_Museum_Researcher_Talk_21
# 120 "data/maps/StonereachCity_Museum/scripts.pory"
	removeitem ITEM_RARE_BONE
# 121 "data/maps/StonereachCity_Museum/scripts.pory"
	giveitem ITEM_FOSSILIZED_DRAKE
# 122 "data/maps/StonereachCity_Museum/scripts.pory"
	setflag FLAG_STONEREACH_MUSEUM_TRADE_DONE
# 123 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 124 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Researcher_Talk_30
# 125 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Researcher_Talk_31
# 126 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Researcher_Talk_32
StonereachCity_Museum_Researcher_Talk_28:
# 128 "data/maps/StonereachCity_Museum/scripts.pory"
	release
	end

StonereachCity_Museum_Researcher_Talk_2:
# 83 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 84 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Researcher_Talk_11
# 85 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Researcher_Talk_12
# 86 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Researcher_Talk_13
StonereachCity_Museum_Researcher_Talk_9:
# 88 "data/maps/StonereachCity_Museum/scripts.pory"
	release
	end

StonereachCity_Museum_Researcher_Talk_6:
# 92 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_3, MSGBOX_YESNO
	goto StonereachCity_Museum_Researcher_Talk_4

StonereachCity_Museum_Researcher_Talk_7:
# 93 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_4, MSGBOX_YESNO
	goto StonereachCity_Museum_Researcher_Talk_4

StonereachCity_Museum_Researcher_Talk_8:
# 94 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_5, MSGBOX_YESNO
	goto StonereachCity_Museum_Researcher_Talk_4

StonereachCity_Museum_Researcher_Talk_11:
# 84 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_0, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_9

StonereachCity_Museum_Researcher_Talk_12:
# 85 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_1, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_9

StonereachCity_Museum_Researcher_Talk_13:
# 86 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_2, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_9

StonereachCity_Museum_Researcher_Talk_15:
# 97 "data/maps/StonereachCity_Museum/scripts.pory"
	release
	end

StonereachCity_Museum_Researcher_Talk_18:
# 102 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 103 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Researcher_Talk_25
# 104 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Researcher_Talk_26
# 105 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Researcher_Talk_27
StonereachCity_Museum_Researcher_Talk_23:
# 107 "data/maps/StonereachCity_Museum/scripts.pory"
	release
	end

StonereachCity_Museum_Researcher_Talk_21:
# 112 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 113 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Researcher_Talk_35
# 114 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Researcher_Talk_36
# 115 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Researcher_Talk_37
StonereachCity_Museum_Researcher_Talk_33:
# 117 "data/maps/StonereachCity_Museum/scripts.pory"
	release
	end

StonereachCity_Museum_Researcher_Talk_25:
# 103 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_6, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_23

StonereachCity_Museum_Researcher_Talk_26:
# 104 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_7, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_23

StonereachCity_Museum_Researcher_Talk_27:
# 105 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_8, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_23

StonereachCity_Museum_Researcher_Talk_30:
# 124 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_12, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_28

StonereachCity_Museum_Researcher_Talk_31:
# 125 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_13, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_28

StonereachCity_Museum_Researcher_Talk_32:
# 126 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_14, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_28

StonereachCity_Museum_Researcher_Talk_35:
# 113 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_9, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_33

StonereachCity_Museum_Researcher_Talk_36:
# 114 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_10, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_33

StonereachCity_Museum_Researcher_Talk_37:
# 115 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Researcher_Talk_Text_11, MSGBOX_DEFAULT
	goto StonereachCity_Museum_Researcher_Talk_33


StonereachCity_Museum_Sign_Armaldo::
# 133 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 134 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_Armaldo_3
# 135 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_Armaldo_4
# 136 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_Armaldo_5
StonereachCity_Museum_Sign_Armaldo_1:
	end

StonereachCity_Museum_Sign_Armaldo_3:
# 134 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Armaldo_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Armaldo_1

StonereachCity_Museum_Sign_Armaldo_4:
# 135 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Armaldo_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Armaldo_1

StonereachCity_Museum_Sign_Armaldo_5:
# 136 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Armaldo_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Armaldo_1


StonereachCity_Museum_Sign_Cradily::
# 142 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 143 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_Cradily_3
# 144 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_Cradily_4
# 145 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_Cradily_5
StonereachCity_Museum_Sign_Cradily_1:
	end

StonereachCity_Museum_Sign_Cradily_3:
# 143 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Cradily_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Cradily_1

StonereachCity_Museum_Sign_Cradily_4:
# 144 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Cradily_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Cradily_1

StonereachCity_Museum_Sign_Cradily_5:
# 145 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Cradily_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Cradily_1


StonereachCity_Museum_Sign_Cranidos::
# 151 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 152 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_Cranidos_3
# 153 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_Cranidos_4
# 154 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_Cranidos_5
StonereachCity_Museum_Sign_Cranidos_1:
	end

StonereachCity_Museum_Sign_Cranidos_3:
# 152 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Cranidos_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Cranidos_1

StonereachCity_Museum_Sign_Cranidos_4:
# 153 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Cranidos_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Cranidos_1

StonereachCity_Museum_Sign_Cranidos_5:
# 154 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Cranidos_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Cranidos_1


StonereachCity_Museum_Sign_HelixFossils::
# 160 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 161 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_HelixFossils_3
# 162 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_HelixFossils_4
# 163 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_HelixFossils_5
StonereachCity_Museum_Sign_HelixFossils_1:
	end

StonereachCity_Museum_Sign_HelixFossils_3:
# 161 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_HelixFossils_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_HelixFossils_1

StonereachCity_Museum_Sign_HelixFossils_4:
# 162 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_HelixFossils_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_HelixFossils_1

StonereachCity_Museum_Sign_HelixFossils_5:
# 163 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_HelixFossils_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_HelixFossils_1


StonereachCity_Museum_Sign_DomeFossils::
# 169 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 170 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_DomeFossils_3
# 171 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_DomeFossils_4
# 172 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_DomeFossils_5
StonereachCity_Museum_Sign_DomeFossils_1:
	end

StonereachCity_Museum_Sign_DomeFossils_3:
# 170 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_DomeFossils_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_DomeFossils_1

StonereachCity_Museum_Sign_DomeFossils_4:
# 171 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_DomeFossils_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_DomeFossils_1

StonereachCity_Museum_Sign_DomeFossils_5:
# 172 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_DomeFossils_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_DomeFossils_1


StonereachCity_Museum_Sign_AncientBirdWriting::
# 178 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 179 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_AncientBirdWriting_3
# 180 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_AncientBirdWriting_4
# 181 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_AncientBirdWriting_5
StonereachCity_Museum_Sign_AncientBirdWriting_1:
	end

StonereachCity_Museum_Sign_AncientBirdWriting_3:
# 179 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_AncientBirdWriting_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_AncientBirdWriting_1

StonereachCity_Museum_Sign_AncientBirdWriting_4:
# 180 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_AncientBirdWriting_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_AncientBirdWriting_1

StonereachCity_Museum_Sign_AncientBirdWriting_5:
# 181 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_AncientBirdWriting_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_AncientBirdWriting_1


StonereachCity_Museum_Sign_AncientDragonWriting::
# 187 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 188 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_AncientDragonWriting_3
# 189 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_AncientDragonWriting_4
# 190 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_AncientDragonWriting_5
StonereachCity_Museum_Sign_AncientDragonWriting_1:
	end

StonereachCity_Museum_Sign_AncientDragonWriting_3:
# 188 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_AncientDragonWriting_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_AncientDragonWriting_1

StonereachCity_Museum_Sign_AncientDragonWriting_4:
# 189 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_AncientDragonWriting_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_AncientDragonWriting_1

StonereachCity_Museum_Sign_AncientDragonWriting_5:
# 190 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_AncientDragonWriting_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_AncientDragonWriting_1


StonereachCity_Museum_Sign_HandledJar::
# 196 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 197 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_HandledJar_3
# 198 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_HandledJar_4
# 199 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_HandledJar_5
StonereachCity_Museum_Sign_HandledJar_1:
	end

StonereachCity_Museum_Sign_HandledJar_3:
# 197 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_HandledJar_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_HandledJar_1

StonereachCity_Museum_Sign_HandledJar_4:
# 198 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_HandledJar_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_HandledJar_1

StonereachCity_Museum_Sign_HandledJar_5:
# 199 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_HandledJar_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_HandledJar_1


StonereachCity_Museum_Sign_PlainJar::
# 205 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 206 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_PlainJar_3
# 207 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_PlainJar_4
# 208 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_PlainJar_5
StonereachCity_Museum_Sign_PlainJar_1:
	end

StonereachCity_Museum_Sign_PlainJar_3:
# 206 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_PlainJar_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_PlainJar_1

StonereachCity_Museum_Sign_PlainJar_4:
# 207 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_PlainJar_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_PlainJar_1

StonereachCity_Museum_Sign_PlainJar_5:
# 208 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_PlainJar_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_PlainJar_1


StonereachCity_Museum_Sign_PatternedJar::
# 214 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 215 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_PatternedJar_3
# 216 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_PatternedJar_4
# 217 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_PatternedJar_5
StonereachCity_Museum_Sign_PatternedJar_1:
	end

StonereachCity_Museum_Sign_PatternedJar_3:
# 215 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_PatternedJar_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_PatternedJar_1

StonereachCity_Museum_Sign_PatternedJar_4:
# 216 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_PatternedJar_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_PatternedJar_1

StonereachCity_Museum_Sign_PatternedJar_5:
# 217 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_PatternedJar_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_PatternedJar_1


StonereachCity_Museum_Sign_Aerodactyl::
# 223 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 224 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_Aerodactyl_3
# 225 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_Aerodactyl_4
# 226 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_Aerodactyl_5
StonereachCity_Museum_Sign_Aerodactyl_1:
	end

StonereachCity_Museum_Sign_Aerodactyl_3:
# 224 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Aerodactyl_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Aerodactyl_1

StonereachCity_Museum_Sign_Aerodactyl_4:
# 225 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Aerodactyl_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Aerodactyl_1

StonereachCity_Museum_Sign_Aerodactyl_5:
# 226 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Aerodactyl_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Aerodactyl_1


StonereachCity_Museum_Sign_ClawFossil::
# 232 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 233 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_ClawFossil_3
# 234 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_ClawFossil_4
# 235 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_ClawFossil_5
StonereachCity_Museum_Sign_ClawFossil_1:
	end

StonereachCity_Museum_Sign_ClawFossil_3:
# 233 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_ClawFossil_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_ClawFossil_1

StonereachCity_Museum_Sign_ClawFossil_4:
# 234 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_ClawFossil_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_ClawFossil_1

StonereachCity_Museum_Sign_ClawFossil_5:
# 235 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_ClawFossil_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_ClawFossil_1


StonereachCity_Museum_Sign_OldAmber::
# 241 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 242 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_OldAmber_3
# 243 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_OldAmber_4
# 244 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_OldAmber_5
StonereachCity_Museum_Sign_OldAmber_1:
	end

StonereachCity_Museum_Sign_OldAmber_3:
# 242 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_OldAmber_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_OldAmber_1

StonereachCity_Museum_Sign_OldAmber_4:
# 243 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_OldAmber_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_OldAmber_1

StonereachCity_Museum_Sign_OldAmber_5:
# 244 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_OldAmber_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_OldAmber_1


StonereachCity_Museum_Sign_Tyrantrum::
# 250 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 251 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_Tyrantrum_3
# 252 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_Tyrantrum_4
# 253 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_Tyrantrum_5
StonereachCity_Museum_Sign_Tyrantrum_1:
	end

StonereachCity_Museum_Sign_Tyrantrum_3:
# 251 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Tyrantrum_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Tyrantrum_1

StonereachCity_Museum_Sign_Tyrantrum_4:
# 252 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Tyrantrum_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Tyrantrum_1

StonereachCity_Museum_Sign_Tyrantrum_5:
# 253 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_Tyrantrum_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_Tyrantrum_1


StonereachCity_Museum_Visitor_Gentleman_Talk::
# 259 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 260 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Visitor_Gentleman_Talk_3
# 261 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Visitor_Gentleman_Talk_4
# 262 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Visitor_Gentleman_Talk_5
StonereachCity_Museum_Visitor_Gentleman_Talk_1:
	end

StonereachCity_Museum_Visitor_Gentleman_Talk_3:
# 260 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Gentleman_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Gentleman_Talk_1

StonereachCity_Museum_Visitor_Gentleman_Talk_4:
# 261 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Gentleman_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Gentleman_Talk_1

StonereachCity_Museum_Visitor_Gentleman_Talk_5:
# 262 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Gentleman_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Gentleman_Talk_1


StonereachCity_Museum_Visitor_Pokefan_Talk::
# 268 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 269 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Visitor_Pokefan_Talk_3
# 270 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Visitor_Pokefan_Talk_4
# 271 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Visitor_Pokefan_Talk_5
StonereachCity_Museum_Visitor_Pokefan_Talk_1:
	end

StonereachCity_Museum_Visitor_Pokefan_Talk_3:
# 269 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Pokefan_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Pokefan_Talk_1

StonereachCity_Museum_Visitor_Pokefan_Talk_4:
# 270 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Pokefan_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Pokefan_Talk_1

StonereachCity_Museum_Visitor_Pokefan_Talk_5:
# 271 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Pokefan_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Pokefan_Talk_1


StonereachCity_Museum_Visitor_Boy_Talk::
# 277 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 278 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Visitor_Boy_Talk_3
# 279 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Visitor_Boy_Talk_4
# 280 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Visitor_Boy_Talk_5
StonereachCity_Museum_Visitor_Boy_Talk_1:
	end

StonereachCity_Museum_Visitor_Boy_Talk_3:
# 278 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Boy_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Boy_Talk_1

StonereachCity_Museum_Visitor_Boy_Talk_4:
# 279 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Boy_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Boy_Talk_1

StonereachCity_Museum_Visitor_Boy_Talk_5:
# 280 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Boy_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Boy_Talk_1


StonereachCity_Museum_Visitor_OldMan_Talk::
# 286 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 287 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Visitor_OldMan_Talk_3
# 288 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Visitor_OldMan_Talk_4
# 289 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Visitor_OldMan_Talk_5
StonereachCity_Museum_Visitor_OldMan_Talk_1:
	end

StonereachCity_Museum_Visitor_OldMan_Talk_3:
# 287 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_OldMan_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_OldMan_Talk_1

StonereachCity_Museum_Visitor_OldMan_Talk_4:
# 288 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_OldMan_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_OldMan_Talk_1

StonereachCity_Museum_Visitor_OldMan_Talk_5:
# 289 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_OldMan_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_OldMan_Talk_1


StonereachCity_Museum_Visitor_Girl_Talk::
# 295 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 296 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Visitor_Girl_Talk_3
# 297 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Visitor_Girl_Talk_4
# 298 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Visitor_Girl_Talk_5
StonereachCity_Museum_Visitor_Girl_Talk_1:
	end

StonereachCity_Museum_Visitor_Girl_Talk_3:
# 296 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Girl_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Girl_Talk_1

StonereachCity_Museum_Visitor_Girl_Talk_4:
# 297 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Girl_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Girl_Talk_1

StonereachCity_Museum_Visitor_Girl_Talk_5:
# 298 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Girl_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Girl_Talk_1


StonereachCity_Museum_Visitor_Hiker_Talk::
# 304 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 305 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Visitor_Hiker_Talk_3
# 306 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Visitor_Hiker_Talk_4
# 307 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Visitor_Hiker_Talk_5
StonereachCity_Museum_Visitor_Hiker_Talk_1:
	end

StonereachCity_Museum_Visitor_Hiker_Talk_3:
# 305 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Hiker_Talk_Text_0, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Hiker_Talk_1

StonereachCity_Museum_Visitor_Hiker_Talk_4:
# 306 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Hiker_Talk_Text_1, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Hiker_Talk_1

StonereachCity_Museum_Visitor_Hiker_Talk_5:
# 307 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Visitor_Hiker_Talk_Text_2, MSGBOX_NPC
	goto StonereachCity_Museum_Visitor_Hiker_Talk_1


StonereachCity_Museum_Sign_HisuiMap::
# 313 "data/maps/StonereachCity_Museum/scripts.pory"
	lockall
# 314 "data/maps/StonereachCity_Museum/scripts.pory"
	switch VAR_LANGUAGE
# 315 "data/maps/StonereachCity_Museum/scripts.pory"
	case PT, StonereachCity_Museum_Sign_HisuiMap_3
# 316 "data/maps/StonereachCity_Museum/scripts.pory"
	case EN, StonereachCity_Museum_Sign_HisuiMap_4
# 317 "data/maps/StonereachCity_Museum/scripts.pory"
	case ES, StonereachCity_Museum_Sign_HisuiMap_5
StonereachCity_Museum_Sign_HisuiMap_1:
# 319 "data/maps/StonereachCity_Museum/scripts.pory"
	closemessage
# 320 "data/maps/StonereachCity_Museum/scripts.pory"
	special ShowHisuiMap
# 321 "data/maps/StonereachCity_Museum/scripts.pory"
	releaseall
	end

StonereachCity_Museum_Sign_HisuiMap_3:
# 315 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_HisuiMap_Text_0, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_HisuiMap_1

StonereachCity_Museum_Sign_HisuiMap_4:
# 316 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_HisuiMap_Text_1, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_HisuiMap_1

StonereachCity_Museum_Sign_HisuiMap_5:
# 317 "data/maps/StonereachCity_Museum/scripts.pory"
	msgbox StonereachCity_Museum_Sign_HisuiMap_Text_2, MSGBOX_SIGN
	goto StonereachCity_Museum_Sign_HisuiMap_1


# 11 "data/maps/StonereachCity_Museum/scripts.pory"
StonereachCity_Museum_EntranceTrigger_Movement_0:
# 11 "data/maps/StonereachCity_Museum/scripts.pory"
	emote_exclamation_mark
	step_end

# 15 "data/maps/StonereachCity_Museum/scripts.pory"
StonereachCity_Museum_EntranceTrigger_Movement_1:
# 15 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 15 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 15 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 15 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 15 "data/maps/StonereachCity_Museum/scripts.pory"
	face_right
	step_end

# 16 "data/maps/StonereachCity_Museum/scripts.pory"
StonereachCity_Museum_EntranceTrigger_Movement_2:
# 16 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 16 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 16 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 16 "data/maps/StonereachCity_Museum/scripts.pory"
	face_right
	step_end

# 17 "data/maps/StonereachCity_Museum/scripts.pory"
StonereachCity_Museum_EntranceTrigger_Movement_3:
# 17 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 17 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 17 "data/maps/StonereachCity_Museum/scripts.pory"
	face_right
	step_end

# 18 "data/maps/StonereachCity_Museum/scripts.pory"
StonereachCity_Museum_EntranceTrigger_Movement_4:
# 18 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_right
# 18 "data/maps/StonereachCity_Museum/scripts.pory"
	face_right
	step_end

# 19 "data/maps/StonereachCity_Museum/scripts.pory"
StonereachCity_Museum_EntranceTrigger_Movement_5:
# 19 "data/maps/StonereachCity_Museum/scripts.pory"
	face_right
	step_end

# 23 "data/maps/StonereachCity_Museum/scripts.pory"
StonereachCity_Museum_EntranceTrigger_Movement_6:
# 23 "data/maps/StonereachCity_Museum/scripts.pory"
	walk_down
# 23 "data/maps/StonereachCity_Museum/scripts.pory"
	face_up
	step_end

StonereachCity_Museum_Admission_Text_0:
# 40 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Seu ingresso já está liberado.\pAproveite a visita ao museu!$"

StonereachCity_Museum_Admission_Text_1:
# 41 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Your admission is already cleared.\pEnjoy your visit to the museum!$"

StonereachCity_Museum_Admission_Text_2:
# 42 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Tu entrada ya está autorizada.\p¡Disfruta de tu visita al museo!$"

StonereachCity_Museum_Admission_Text_3:
# 47 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Bem-vindo ao Museu de Stonereach!\pA taxa de visitação é de ¥2.000.\nDeseja pagar para entrar?$"

StonereachCity_Museum_Admission_Text_4:
# 48 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Welcome to the Stonereach Museum!\pAdmission costs ¥2,000.\nWould you like to pay and enter?$"

StonereachCity_Museum_Admission_Text_5:
# 49 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "¡Bienvenido al Museo de Stonereach!\pLa entrada cuesta ¥2.000.\n¿Quieres pagar para entrar?$"

StonereachCity_Museum_Admission_Text_6:
# 53 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Sem o ingresso, não posso permitir\nsua entrada.$"

StonereachCity_Museum_Admission_Text_7:
# 54 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Without a ticket, I can't allow\nyou to enter.$"

StonereachCity_Museum_Admission_Text_8:
# 55 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Sin entrada, no puedo permitirte\nel acceso.$"

StonereachCity_Museum_Admission_Text_9:
# 62 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Você não tem ¥2.000.\pVolte quando tiver o valor da taxa.$"

StonereachCity_Museum_Admission_Text_10:
# 63 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "You don't have ¥2,000.\pCome back when you have the fee.$"

StonereachCity_Museum_Admission_Text_11:
# 64 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "No tienes ¥2.000.\pVuelve cuando tengas el importe.$"

StonereachCity_Museum_Admission_Text_12:
# 72 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Pagamento recebido. Obrigado!\pAgora você tem livre acesso ao\nmuseu. Aproveite a visita!$"

StonereachCity_Museum_Admission_Text_13:
# 73 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Payment received. Thank you!\pYou now have free access to the\nmuseum. Enjoy your visit!$"

StonereachCity_Museum_Admission_Text_14:
# 74 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Pago recibido. ¡Gracias!\pYa tienes libre acceso al museo.\n¡Disfruta de la visita!$"

StonereachCity_Museum_Researcher_Talk_Text_0:
# 84 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Esse Osso Raro será muito\nimportante para minha pesquisa.\pEspero que cuide bem do seu\lFóssil de Drake!$"

StonereachCity_Museum_Researcher_Talk_Text_1:
# 85 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "That Rare Bone will be very\nimportant to my research.\pI hope you take good care of your\lFossilized Drake!$"

StonereachCity_Museum_Researcher_Talk_Text_2:
# 86 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Ese Hueso Raro será muy importante\npara mi investigación.\p¡Espero que cuides bien de tu\lDrake Fosilizado!$"

StonereachCity_Museum_Researcher_Talk_Text_3:
# 92 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Estou procurando um Osso Raro\npara minha pesquisa.\pPosso oferecer um Fóssil de Drake\nem troca. Você aceita?$"

StonereachCity_Museum_Researcher_Talk_Text_4:
# 93 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "I'm looking for a Rare Bone for my\nresearch.\pI can offer a Fossilized Drake in\nexchange. Do you accept?$"

StonereachCity_Museum_Researcher_Talk_Text_5:
# 94 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Busco un Hueso Raro para mi\ninvestigación.\pPuedo ofrecer un Drake Fosilizado a\ncambio. ¿Aceptas?$"

StonereachCity_Museum_Researcher_Talk_Text_6:
# 103 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Parece que você não tem um\nOsso Raro.$"

StonereachCity_Museum_Researcher_Talk_Text_7:
# 104 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "It looks like you don't have a\nRare Bone.$"

StonereachCity_Museum_Researcher_Talk_Text_8:
# 105 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Parece que no tienes un\nHueso Raro.$"

StonereachCity_Museum_Researcher_Talk_Text_9:
# 113 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Sua Bolsa está cheia.\pAbra espaço e fale comigo novamente.$"

StonereachCity_Museum_Researcher_Talk_Text_10:
# 114 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Your Bag is full.\pMake room and talk to me again.$"

StonereachCity_Museum_Researcher_Talk_Text_11:
# 115 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Tu Bolsa está llena.\pHaz espacio y vuelve a hablar conmigo.$"

StonereachCity_Museum_Researcher_Talk_Text_12:
# 124 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Excelente! Aqui está o Fóssil de\nDrake que prometi.\pObrigado pela troca!$"

StonereachCity_Museum_Researcher_Talk_Text_13:
# 125 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Excellent! Here's the Fossilized\nDrake I promised.\pThank you for the trade!$"

StonereachCity_Museum_Researcher_Talk_Text_14:
# 126 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "¡Excelente! Aquí tienes el Drake\nFosilizado que prometí.\p¡Gracias por el intercambio!$"

StonereachCity_Museum_Sign_Armaldo_Text_0:
# 134 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fóssil de ARMALDO\pAs placas de sua carapaça e suas\ngrandes garras estão preservadas.$"

StonereachCity_Museum_Sign_Armaldo_Text_1:
# 135 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "ARMALDO Fossil\pIts shell plates and massive claws\nremain remarkably preserved.$"

StonereachCity_Museum_Sign_Armaldo_Text_2:
# 136 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fósil de ARMALDO\pLas placas de su caparazón y sus\ngrandes garras están conservadas.$"

StonereachCity_Museum_Sign_Cradily_Text_0:
# 143 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fóssil de CRADILY\pUm Pokémon marinho pré-histórico\nque se fixava ao fundo do oceano.$"

StonereachCity_Museum_Sign_Cradily_Text_1:
# 144 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "CRADILY Fossil\pA prehistoric marine Pokémon that\nanchored itself to the ocean floor.$"

StonereachCity_Museum_Sign_Cradily_Text_2:
# 145 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fósil de CRADILY\pUn Pokémon marino prehistórico que\nse aferraba al fondo oceánico.$"

StonereachCity_Museum_Sign_Cranidos_Text_0:
# 152 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Dois CRANIDOS fossilizados no\ninstante em que golpeavam suas\lcabeças em uma disputa territorial.$"

StonereachCity_Museum_Sign_Cranidos_Text_1:
# 153 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Two CRANIDOS fossilized as they\nbutted heads in a territorial\lcontest.$"

StonereachCity_Museum_Sign_Cranidos_Text_2:
# 154 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Dos CRANIDOS fosilizados mientras\nchocaban sus cabezas en una disputa\lterritorial.$"

StonereachCity_Museum_Sign_HelixFossils_Text_0:
# 161 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fósseis Helix\pConchas espirais de antigos\nOMANYTE encontrados no leito\lmarinho.$"

StonereachCity_Museum_Sign_HelixFossils_Text_1:
# 162 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Helix Fossils\pSpiral shells of ancient OMANYTE\nfound on the seabed.$"

StonereachCity_Museum_Sign_HelixFossils_Text_2:
# 163 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fósiles Helix\pConchas espirales de antiguos\nOMANYTE halladas en el fondo marino.$"

StonereachCity_Museum_Sign_DomeFossils_Text_0:
# 170 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fósseis Dome\pCarapaças de KABUTO que viveram\nhá centenas de milhões de anos.$"

StonereachCity_Museum_Sign_DomeFossils_Text_1:
# 171 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Dome Fossils\pShells of KABUTO that lived\nhundreds of millions of years ago.$"

StonereachCity_Museum_Sign_DomeFossils_Text_2:
# 172 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fósiles Dome\pCaparazones de KABUTO que vivieron\nhace cientos de millones de años.$"

StonereachCity_Museum_Sign_AncientBirdWriting_Text_0:
# 179 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Uma escritura antiga retrata uma\ngrande ave abrindo as asas diante\ldo sol.$"

StonereachCity_Museum_Sign_AncientBirdWriting_Text_1:
# 180 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "An ancient inscription depicts a\ngreat bird spreading its wings\lbefore the sun.$"

StonereachCity_Museum_Sign_AncientBirdWriting_Text_2:
# 181 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Una escritura antigua representa\nun gran ave extendiendo sus alas\lante el sol.$"

StonereachCity_Museum_Sign_AncientDragonWriting_Text_0:
# 188 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Uma escritura antiga retrata um\ndragão enrolado ao redor de uma\lmontanha.$"

StonereachCity_Museum_Sign_AncientDragonWriting_Text_1:
# 189 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "An ancient inscription depicts a\ndragon coiled around a mountain.$"

StonereachCity_Museum_Sign_AncientDragonWriting_Text_2:
# 190 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Una escritura antigua representa\nun dragón enroscado alrededor de\luna montaña.$"

StonereachCity_Museum_Sign_HandledJar_Text_0:
# 197 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Jarro antigo com alças.\pMarcas internas indicam que era\nusado para armazenar grãos.$"

StonereachCity_Museum_Sign_HandledJar_Text_1:
# 198 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Ancient handled jar.\pTraces inside suggest it was used\nto store grain.$"

StonereachCity_Museum_Sign_HandledJar_Text_2:
# 199 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Jarra antigua con asas.\pLos restos internos indican que se\nusaba para almacenar grano.$"

StonereachCity_Museum_Sign_PlainJar_Text_0:
# 206 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Jarro antigo liso.\pSeu formato simples era comum em\nassentamentos da região.$"

StonereachCity_Museum_Sign_PlainJar_Text_1:
# 207 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Plain ancient jar.\pIts simple shape was common in the\nregion's early settlements.$"

StonereachCity_Museum_Sign_PlainJar_Text_2:
# 208 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Jarra antigua lisa.\pSu forma sencilla era común en los\nprimeros asentamientos de la región.$"

StonereachCity_Museum_Sign_PatternedJar_Text_0:
# 215 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Jarro antigo estampado.\pOs padrões geométricos parecem\nrepresentar rios e montanhas.$"

StonereachCity_Museum_Sign_PatternedJar_Text_1:
# 216 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Patterned ancient jar.\pIts geometric designs appear to\ndepict rivers and mountains.$"

StonereachCity_Museum_Sign_PatternedJar_Text_2:
# 217 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Jarra antigua decorada.\pSus motivos geométricos parecen\nrepresentar ríos y montañas.$"

StonereachCity_Museum_Sign_Aerodactyl_Text_0:
# 224 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fóssil de AERODACTYL\pAs asas abertas revelam a enorme\nenvergadura deste predador antigo.$"

StonereachCity_Museum_Sign_Aerodactyl_Text_1:
# 225 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "AERODACTYL Fossil\pIts spread wings reveal this ancient\npredator's enormous wingspan.$"

StonereachCity_Museum_Sign_Aerodactyl_Text_2:
# 226 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fósil de AERODACTYL\pSus alas abiertas revelan la gran\nenvergadura de este depredador.$"

StonereachCity_Museum_Sign_ClawFossil_Text_0:
# 233 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Claw Fossil\pParte de uma garra preservada de\nANORITH, um antigo Pokémon marinho.$"

StonereachCity_Museum_Sign_ClawFossil_Text_1:
# 234 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Claw Fossil\pPart of a preserved ANORITH claw,\nan ancient marine Pokémon.$"

StonereachCity_Museum_Sign_ClawFossil_Text_2:
# 235 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fósil Garra\pParte de una garra conservada de\nANORITH, un antiguo Pokémon marino.$"

StonereachCity_Museum_Sign_OldAmber_Text_0:
# 242 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Old Amber\pUm fragmento de âmbar que conserva\nmaterial genético de AERODACTYL.$"

StonereachCity_Museum_Sign_OldAmber_Text_1:
# 243 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Old Amber\pA piece of amber preserving genetic\nmaterial from AERODACTYL.$"

StonereachCity_Museum_Sign_OldAmber_Text_2:
# 244 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Ámbar Viejo\pUn fragmento de ámbar que conserva\nmaterial genético de AERODACTYL.$"

StonereachCity_Museum_Sign_Tyrantrum_Text_0:
# 251 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fóssil de TYRANTRUM\pSeu crânio imponente pertenceu a\num dos maiores predadores de sua era.$"

StonereachCity_Museum_Sign_Tyrantrum_Text_1:
# 252 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "TYRANTRUM Fossil\pIts imposing skull belonged to one\nof the greatest predators of its age.$"

StonereachCity_Museum_Sign_Tyrantrum_Text_2:
# 253 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Fósil de TYRANTRUM\pSu imponente cráneo perteneció a\nuno de los mayores depredadores.$"

StonereachCity_Museum_Visitor_Gentleman_Talk_Text_0:
# 260 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Esses fósseis são verdadeiras\njanelas para o passado.\pUma coleção assim não tem preço!$"

StonereachCity_Museum_Visitor_Gentleman_Talk_Text_1:
# 261 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "These fossils are true windows\ninto the past.\pA collection like this is priceless!$"

StonereachCity_Museum_Visitor_Gentleman_Talk_Text_2:
# 262 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Estos fósiles son auténticas\nventanas al pasado.\p¡Una colección así no tiene precio!$"

StonereachCity_Museum_Visitor_Pokefan_Talk_Text_0:
# 269 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Imaginar esses Pokémon caminhando\npelo mundo é fascinante!\pQueria ter visto um CRADILY vivo.$"

StonereachCity_Museum_Visitor_Pokefan_Talk_Text_1:
# 270 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Imagining these Pokémon roaming the\nworld is fascinating!\pI wish I could have seen a living\lCRADILY.$"

StonereachCity_Museum_Visitor_Pokefan_Talk_Text_2:
# 271 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "¡Imaginar a estos Pokémon recorriendo\nel mundo es fascinante!\pOjalá hubiera visto un CRADILY vivo.$"

StonereachCity_Museum_Visitor_Boy_Talk_Text_0:
# 278 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Dois CRANIDOS batiam a cabeça um\nno outro por território?\pEu faço quase a mesma coisa quando\lmeu irmão pega meus brinquedos!$"

StonereachCity_Museum_Visitor_Boy_Talk_Text_1:
# 279 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Two CRANIDOS butted heads over\nterritory?\pI do almost the same thing when my\lbrother takes my toys!$"

StonereachCity_Museum_Visitor_Boy_Talk_Text_2:
# 280 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "¿Dos CRANIDOS chocaban sus cabezas\npor el territorio?\p¡Yo hago casi lo mismo cuando mi\lhermano toma mis juguetes!$"

StonereachCity_Museum_Visitor_OldMan_Talk_Text_0:
# 287 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Esses jarros parecem simples, mas\ncarregam histórias de muitas vidas.\pObjetos comuns também merecem ser\llembrados.$"

StonereachCity_Museum_Visitor_OldMan_Talk_Text_1:
# 288 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "These jars look simple, but they\ncarry the stories of many lives.\pEveryday objects deserve to be\lremembered too.$"

StonereachCity_Museum_Visitor_OldMan_Talk_Text_2:
# 289 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Estas jarras parecen sencillas, pero\nguardan historias de muchas vidas.\pLos objetos cotidianos también\lmerecen ser recordados.$"

StonereachCity_Museum_Visitor_Girl_Talk_Text_0:
# 296 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "A ave daquela escritura antiga\nparece estar protegendo o sol.\pSerá que ela representa um Pokémon\lque ainda existe?$"

StonereachCity_Museum_Visitor_Girl_Talk_Text_1:
# 297 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "The bird in that ancient inscription\nlooks like it's guarding the sun.\pCould it depict a Pokémon that\lstill exists?$"

StonereachCity_Museum_Visitor_Girl_Talk_Text_2:
# 298 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "El ave de esa escritura antigua\nparece proteger el sol.\p¿Representará a un Pokémon que\ltodavía existe?$"

StonereachCity_Museum_Visitor_Hiker_Talk_Text_0:
# 305 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Já encontrei fósseis durante minhas\ntrilhas, mas nenhum tão completo.\pA rocha guarda seus segredos com\lmuito cuidado.$"

StonereachCity_Museum_Visitor_Hiker_Talk_Text_1:
# 306 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "I've found fossils on my hikes, but\nnever one this complete.\pStone guards its secrets very\lcarefully.$"

StonereachCity_Museum_Visitor_Hiker_Talk_Text_2:
# 307 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "He encontrado fósiles en mis rutas,\npero ninguno tan completo.\pLa piedra guarda sus secretos con\lmucho cuidado.$"

StonereachCity_Museum_Sign_HisuiMap_Text_0:
# 315 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Mapa da antiga região de HISUI.\pTraçado em uma época em que vastas\nterras selvagens ainda separavam os\lprimeiros assentamentos humanos.\pMuitos dos lugares retratados aqui\nreceberiam novos nomes com o passar\ldos séculos.$"

StonereachCity_Museum_Sign_HisuiMap_Text_1:
# 316 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Map of the ancient HISUI region.\pDrawn in an age when vast wildlands\nstill separated the first human\lsettlements.\pMany places depicted here would be\ngiven new names over the centuries.$"

StonereachCity_Museum_Sign_HisuiMap_Text_2:
# 317 "data/maps/StonereachCity_Museum/scripts.pory"
	.string "Mapa de la antigua región de HISUI.\pTrazado cuando vastas tierras\nsalvajes aún separaban los primeros\lasentamientos humanos.\pMuchos lugares aquí representados\nrecibirían nuevos nombres con el\lpaso de los siglos.$"
