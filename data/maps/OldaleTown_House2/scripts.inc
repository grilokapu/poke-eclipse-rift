OldaleTown_House2_MapScripts::
	.byte 0


SylvaraTown_EventScript_Woman_Talk::
# 6 "data/maps/OldaleTown_House2/scripts.pory"
	switch VAR_LANGUAGE
# 7 "data/maps/OldaleTown_House2/scripts.pory"
	case PT, SylvaraTown_EventScript_Woman_Talk_3
# 8 "data/maps/OldaleTown_House2/scripts.pory"
	case EN, SylvaraTown_EventScript_Woman_Talk_4
# 9 "data/maps/OldaleTown_House2/scripts.pory"
	case ES, SylvaraTown_EventScript_Woman_Talk_5
SylvaraTown_EventScript_Woman_Talk_1:
	end

SylvaraTown_EventScript_Woman_Talk_3:
# 7 "data/maps/OldaleTown_House2/scripts.pory"
	msgbox SylvaraTown_EventScript_Woman_Talk_Text_0, MSGBOX_NPC
	goto SylvaraTown_EventScript_Woman_Talk_1

SylvaraTown_EventScript_Woman_Talk_4:
# 8 "data/maps/OldaleTown_House2/scripts.pory"
	msgbox SylvaraTown_EventScript_Woman_Talk_Text_1, MSGBOX_NPC
	goto SylvaraTown_EventScript_Woman_Talk_1

SylvaraTown_EventScript_Woman_Talk_5:
# 9 "data/maps/OldaleTown_House2/scripts.pory"
	msgbox SylvaraTown_EventScript_Woman_Talk_Text_2, MSGBOX_NPC
	goto SylvaraTown_EventScript_Woman_Talk_1


SylvaraTown_EventScript_Man_Talk::
# 15 "data/maps/OldaleTown_House2/scripts.pory"
	switch VAR_LANGUAGE
# 16 "data/maps/OldaleTown_House2/scripts.pory"
	case PT, SylvaraTown_EventScript_Man_Talk_3
# 17 "data/maps/OldaleTown_House2/scripts.pory"
	case EN, SylvaraTown_EventScript_Man_Talk_4
# 18 "data/maps/OldaleTown_House2/scripts.pory"
	case ES, SylvaraTown_EventScript_Man_Talk_5
SylvaraTown_EventScript_Man_Talk_1:
	end

SylvaraTown_EventScript_Man_Talk_3:
# 16 "data/maps/OldaleTown_House2/scripts.pory"
	msgbox SylvaraTown_EventScript_Man_Talk_Text_0, MSGBOX_NPC
	goto SylvaraTown_EventScript_Man_Talk_1

SylvaraTown_EventScript_Man_Talk_4:
# 17 "data/maps/OldaleTown_House2/scripts.pory"
	msgbox SylvaraTown_EventScript_Man_Talk_Text_1, MSGBOX_NPC
	goto SylvaraTown_EventScript_Man_Talk_1

SylvaraTown_EventScript_Man_Talk_5:
# 18 "data/maps/OldaleTown_House2/scripts.pory"
	msgbox SylvaraTown_EventScript_Man_Talk_Text_2, MSGBOX_NPC
	goto SylvaraTown_EventScript_Man_Talk_1


SylvaraTown_EventScript_Woman_Talk_Text_0:
# 7 "data/maps/OldaleTown_House2/scripts.pory"
	.string "Se você quer que seus POKéMON\nfiquem mais fortes, não tenha medo\lde batalhar!\pToda batalha é uma chance de\nganhar experiência.$"

SylvaraTown_EventScript_Woman_Talk_Text_1:
# 8 "data/maps/OldaleTown_House2/scripts.pory"
	.string "If you want your POKéMON to grow\nstronger, don't be afraid to\lbattle!\pEvery battle is a chance to gain\nexperience.$"

SylvaraTown_EventScript_Woman_Talk_Text_2:
# 9 "data/maps/OldaleTown_House2/scripts.pory"
	.string "¡Si quieres que tus POKéMON se\nvuelvan más fuertes, no tengas\lmiedo de combatir!\pCada batalla es una oportunidad\npara ganar experiencia.$"

SylvaraTown_EventScript_Man_Talk_Text_0:
# 16 "data/maps/OldaleTown_House2/scripts.pory"
	.string "Alguns POKéMON evoluem apenas com\no tempo, mas outros precisam\lacumular experiência em batalha.\pQuanto mais eles aprendem, mais\nperto ficam de alcançar seu\lverdadeiro potencial!$"

SylvaraTown_EventScript_Man_Talk_Text_1:
# 17 "data/maps/OldaleTown_House2/scripts.pory"
	.string "Some POKéMON evolve with time, but\nothers need to gain experience\lthrough battles.\pThe more they learn, the closer\nthey get to reaching their true\lpotential!$"

SylvaraTown_EventScript_Man_Talk_Text_2:
# 18 "data/maps/OldaleTown_House2/scripts.pory"
	.string "Algunos POKéMON evolucionan con el\ntiempo, pero otros necesitan ganar\lexperiencia en combate.\p¡Cuanto más aprenden, más cerca\nestán de alcanzar su verdadero\lpotencial!$"
