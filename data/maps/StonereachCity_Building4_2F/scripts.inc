StonereachCity_Building4_2F_MapScripts::
	.byte 0


StonereachCity_Building4_2F_EventScript_Student::
# 4 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	switch VAR_LANGUAGE
# 5 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	case PT, StonereachCity_Building4_2F_EventScript_Student_3
# 6 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	case EN, StonereachCity_Building4_2F_EventScript_Student_4
# 7 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	case ES, StonereachCity_Building4_2F_EventScript_Student_5
StonereachCity_Building4_2F_EventScript_Student_1:
	end

StonereachCity_Building4_2F_EventScript_Student_3:
# 5 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	msgbox StonereachCity_Building4_2F_EventScript_Student_Text_0, MSGBOX_NPC
	goto StonereachCity_Building4_2F_EventScript_Student_1

StonereachCity_Building4_2F_EventScript_Student_4:
# 6 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	msgbox StonereachCity_Building4_2F_EventScript_Student_Text_1, MSGBOX_NPC
	goto StonereachCity_Building4_2F_EventScript_Student_1

StonereachCity_Building4_2F_EventScript_Student_5:
# 7 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	msgbox StonereachCity_Building4_2F_EventScript_Student_Text_2, MSGBOX_NPC
	goto StonereachCity_Building4_2F_EventScript_Student_1


StonereachCity_Building4_2F_EventScript_OldWoman::
# 13 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	switch VAR_LANGUAGE
# 14 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	case PT, StonereachCity_Building4_2F_EventScript_OldWoman_3
# 15 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	case EN, StonereachCity_Building4_2F_EventScript_OldWoman_4
# 16 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	case ES, StonereachCity_Building4_2F_EventScript_OldWoman_5
StonereachCity_Building4_2F_EventScript_OldWoman_1:
	end

StonereachCity_Building4_2F_EventScript_OldWoman_3:
# 14 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	msgbox StonereachCity_Building4_2F_EventScript_OldWoman_Text_0, MSGBOX_NPC
	goto StonereachCity_Building4_2F_EventScript_OldWoman_1

StonereachCity_Building4_2F_EventScript_OldWoman_4:
# 15 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	msgbox StonereachCity_Building4_2F_EventScript_OldWoman_Text_1, MSGBOX_NPC
	goto StonereachCity_Building4_2F_EventScript_OldWoman_1

StonereachCity_Building4_2F_EventScript_OldWoman_5:
# 16 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	msgbox StonereachCity_Building4_2F_EventScript_OldWoman_Text_2, MSGBOX_NPC
	goto StonereachCity_Building4_2F_EventScript_OldWoman_1


StonereachCity_Building4_2F_EventScript_Student_Text_0:
# 5 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	.string "O mestre diz que uma batalha é como\numa frase.\pSe trocar a ordem das palavras, ela\npode perder todo o sentido.\pEu ainda acabo… falando com os\ngolpes na ordem errada.$"

StonereachCity_Building4_2F_EventScript_Student_Text_1:
# 6 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	.string "The master says a battle is like a\nsentence.\pChange the word order and it may lose\nall meaning.\pI still end up… speaking my moves in\nthe wrong order.$"

StonereachCity_Building4_2F_EventScript_Student_Text_2:
# 7 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	.string "El maestro dice que un combate es\ncomo una frase.\pSi cambias el orden de las palabras,\npuede perder todo sentido.\pYo aún… digo mis movimientos en el\norden equivocado.$"

StonereachCity_Building4_2F_EventScript_OldWoman_Text_0:
# 14 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	.string "Treinadores jovens procuram o golpe\nmais poderoso.\pCom o tempo, aprendem que o momento\ncerto pode tornar um golpe simples\ninesquecível.$"

StonereachCity_Building4_2F_EventScript_OldWoman_Text_1:
# 15 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	.string "Young Trainers seek the strongest\nmove.\pIn time, they learn the right moment\ncan make a simple move unforgettable.$"

StonereachCity_Building4_2F_EventScript_OldWoman_Text_2:
# 16 "data/maps/StonereachCity_Building4_2F/scripts.pory"
	.string "Los Entrenadores jóvenes buscan el\nmovimiento más fuerte.\pCon el tiempo aprenden que el momento\njusto vuelve inolvidable hasta un\nmovimiento sencillo.$"
