OldaleTown_House1_MapScripts::
	.byte 0


SylvaraTown_House2_EventScript_Woman_Talk::
# 6 "data/maps/OldaleTown_House1/scripts.pory"
	switch VAR_LANGUAGE
# 7 "data/maps/OldaleTown_House1/scripts.pory"
	case PT, SylvaraTown_House2_EventScript_Woman_Talk_3
# 8 "data/maps/OldaleTown_House1/scripts.pory"
	case EN, SylvaraTown_House2_EventScript_Woman_Talk_4
# 9 "data/maps/OldaleTown_House1/scripts.pory"
	case ES, SylvaraTown_House2_EventScript_Woman_Talk_5
SylvaraTown_House2_EventScript_Woman_Talk_1:
	end

SylvaraTown_House2_EventScript_Woman_Talk_3:
# 7 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox SylvaraTown_House2_EventScript_Woman_Talk_Text_0, MSGBOX_NPC
	goto SylvaraTown_House2_EventScript_Woman_Talk_1

SylvaraTown_House2_EventScript_Woman_Talk_4:
# 8 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox SylvaraTown_House2_EventScript_Woman_Talk_Text_1, MSGBOX_NPC
	goto SylvaraTown_House2_EventScript_Woman_Talk_1

SylvaraTown_House2_EventScript_Woman_Talk_5:
# 9 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox SylvaraTown_House2_EventScript_Woman_Talk_Text_2, MSGBOX_NPC
	goto SylvaraTown_House2_EventScript_Woman_Talk_1


SylvaraTown_EventScript_Arcanine::
# 15 "data/maps/OldaleTown_House1/scripts.pory"
	lock
# 16 "data/maps/OldaleTown_House1/scripts.pory"
	faceplayer
# 17 "data/maps/OldaleTown_House1/scripts.pory"
	showmonmugshot SPECIES_ARCANINE, MUGSHOT_SOUTHEAST
# 18 "data/maps/OldaleTown_House1/scripts.pory"
	setspeaker SylvaraTown_EventScript_Arcanine_Text_0
# 19 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox SylvaraTown_EventScript_Arcanine_Text_1
# 20 "data/maps/OldaleTown_House1/scripts.pory"
	waitmoncry
# 21 "data/maps/OldaleTown_House1/scripts.pory"
	hidemonmugshot
# 22 "data/maps/OldaleTown_House1/scripts.pory"
	release
	end


SylvaraTown_House2_EventScript_Woman_Talk_Text_0:
# 7 "data/maps/OldaleTown_House1/scripts.pory"
	.string "Meu Arcanine adorava lutar, mas\nficava furioso quando reduziam\lseus atributos.\pEntão dei a ele um {COLOR}{BLUE}CLEAR AMULET{COLOR}{DARK_GRAY}.\pAgora ele ignora essas truques e\ncontinua atacando com tudo!$"

SylvaraTown_House2_EventScript_Woman_Talk_Text_1:
# 8 "data/maps/OldaleTown_House1/scripts.pory"
	.string "My Arcanine loved battling, but it\nhated having its stats lowered.\pSo I gave it a {COLOR}{BLUE}CLEAR AMULET{COLOR}{DARK_GRAY}.\pNow it ignores those tricks and\nkeeps fighting at full strength!$"

SylvaraTown_House2_EventScript_Woman_Talk_Text_2:
# 9 "data/maps/OldaleTown_House1/scripts.pory"
	.string "A mi Arcanine le encantaba\ncombatir, pero odiaba que\lredujeran sus estadísticas.\pAsí que le di un {COLOR}{BLUE}AMULETO CLARO{COLOR}{DARK_GRAY}.\p¡Ahora ignora esos trucos y sigue\nluchando con toda su fuerza!$"

SylvaraTown_EventScript_Arcanine_Text_0:
# 18 "data/maps/OldaleTown_House1/scripts.pory"
	.string "Arcanine$"

SylvaraTown_EventScript_Arcanine_Text_1:
# 19 "data/maps/OldaleTown_House1/scripts.pory"
	.string "Grrrraaaooouu!$"
