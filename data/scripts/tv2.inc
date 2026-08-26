EventScript_TV2::
# 2 "data/scripts/tv2.pory"
	lock
# 3 "data/scripts/tv2.pory"
	callnative GetMapTVScript
# 4 "data/scripts/tv2.pory"
	switch VAR_RESULT
# 5 "data/scripts/tv2.pory"
	case 0, EventScript_TV2_2
# 12 "data/scripts/tv2.pory"
	case 1, EventScript_TV2_3
# 19 "data/scripts/tv2.pory"
	case 2, EventScript_TV2_4
	return

EventScript_TV2_2:
# 6 "data/scripts/tv2.pory"
	switch VAR_LANGUAGE
# 7 "data/scripts/tv2.pory"
	case PT, EventScript_TV2_7
# 8 "data/scripts/tv2.pory"
	case EN, EventScript_TV2_8
# 9 "data/scripts/tv2.pory"
	case ES, EventScript_TV2_9
EventScript_TV2_5:
# 11 "data/scripts/tv2.pory"
	goto End_Script
	return

EventScript_TV2_3:
# 13 "data/scripts/tv2.pory"
	switch VAR_LANGUAGE
# 14 "data/scripts/tv2.pory"
	case PT, EventScript_TV2_12
# 15 "data/scripts/tv2.pory"
	case EN, EventScript_TV2_13
# 16 "data/scripts/tv2.pory"
	case ES, EventScript_TV2_14
EventScript_TV2_10:
# 18 "data/scripts/tv2.pory"
	goto End_Script
	return

EventScript_TV2_4:
# 20 "data/scripts/tv2.pory"
	switch VAR_LANGUAGE
# 21 "data/scripts/tv2.pory"
	case PT, EventScript_TV2_17
# 22 "data/scripts/tv2.pory"
	case EN, EventScript_TV2_18
# 23 "data/scripts/tv2.pory"
	case ES, EventScript_TV2_19
EventScript_TV2_15:
# 25 "data/scripts/tv2.pory"
	goto End_Script
	return

EventScript_TV2_7:
# 7 "data/scripts/tv2.pory"
	msgbox EventScript_TV2_Text_0
	goto EventScript_TV2_5

EventScript_TV2_8:
# 8 "data/scripts/tv2.pory"
	msgbox EventScript_TV2_Text_1
	goto EventScript_TV2_5

EventScript_TV2_9:
# 9 "data/scripts/tv2.pory"
	msgbox EventScript_TV2_Text_2
	goto EventScript_TV2_5

EventScript_TV2_12:
# 14 "data/scripts/tv2.pory"
	msgbox EventScript_TV2_Text_3
	goto EventScript_TV2_10

EventScript_TV2_13:
# 15 "data/scripts/tv2.pory"
	msgbox EventScript_TV2_Text_4
	goto EventScript_TV2_10

EventScript_TV2_14:
# 16 "data/scripts/tv2.pory"
	msgbox EventScript_TV2_Text_5
	goto EventScript_TV2_10

EventScript_TV2_17:
# 21 "data/scripts/tv2.pory"
	msgbox EventScript_TV2_Text_6
	goto EventScript_TV2_15

EventScript_TV2_18:
# 22 "data/scripts/tv2.pory"
	msgbox EventScript_TV2_Text_7
	goto EventScript_TV2_15

EventScript_TV2_19:
# 23 "data/scripts/tv2.pory"
	msgbox EventScript_TV2_Text_8
	goto EventScript_TV2_15


End_Script::
# 30 "data/scripts/tv2.pory"
	release
	end


EventScript_TV2_Text_0:
# 7 "data/scripts/tv2.pory"
	.string "A TV está desligada.$"

EventScript_TV2_Text_1:
# 8 "data/scripts/tv2.pory"
	.string "The TV is turned off.$"

EventScript_TV2_Text_2:
# 9 "data/scripts/tv2.pory"
	.string "La TV está apagada.$"

EventScript_TV2_Text_3:
# 14 "data/scripts/tv2.pory"
	.string "A TV está ligada.\pEstá passando uma novela na TV…\n“Eu não sou a Paulina… sou a irmã\lgêmea dela, Paola!”\pA mulher dá um tapa estonteante no\nhomem!\pA mãe parece hipnotizada pela TV…\nMelhor não atrapalhar agora.$"

EventScript_TV2_Text_4:
# 15 "data/scripts/tv2.pory"
	.string "The TV is on.\pThere's a soap opera playing on\nTV…\l'I am not Paulina… I'm her twin\lsister, Paola!'\pThe woman slaps the man across the\nface!\pMom seems completely hypnotized by\nthe TV…\lBetter not interrupt her now.$"

EventScript_TV2_Text_5:
# 16 "data/scripts/tv2.pory"
	.string "La TV está encendida.\pEstán pasando una telenovela en la\nTV…\l'¡Yo no soy Paulina… soy su\lhermana gemela, Paola!'\p¡La mujer le da una fuerte\nbofetada al hombre!\pMamá parece completamente\nhipnotizada por la TV…\lSerá mejor no interrumpirla ahora.$"

EventScript_TV2_Text_6:
# 21 "data/scripts/tv2.pory"
	.string "A TV está ligada.\p“Não deixe que o que ele quer faça\num eclipse no que você precisa.\lEle é dos seus sonhos, mas não é o\lsol. Você é!”\pParece que a mãe do {RIVAL} está\nassistindo “Grey's Anathomy”.\pEstá completamente vidrada.$"

EventScript_TV2_Text_7:
# 22 "data/scripts/tv2.pory"
	.string "The TV is on.\p“Don't let what he wants eclipse\nwhat you need.\lHe may be the man of your dreams,\lbut he's not the sun. You are!”\pIt looks like {RIVAL}'s mom is\nwatching Grey's Anatomy.\pShe's completely absorbed in it.$"

EventScript_TV2_Text_8:
# 23 "data/scripts/tv2.pory"
	.string "La TV está encendida.\p“No dejes que lo que él quiere\neclipse lo que tú necesitas.\lPuede ser el hombre de tus sueños,\lpero no es el sol. ¡Tú lo eres!”\pParece que la mamá de {RIVAL} está\nviendo Grey's Anatomy.\pEstá completamente absorta.$"
