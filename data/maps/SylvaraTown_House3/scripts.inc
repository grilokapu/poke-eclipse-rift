SylvaraTown_House3_MapScripts::
	.byte 0


SylvaraTown_House3_Gentleman_EventScript::
# 6 "data/maps/SylvaraTown_House3/scripts.pory"
	lock
# 7 "data/maps/SylvaraTown_House3/scripts.pory"
	faceplayer
# 8 "data/maps/SylvaraTown_House3/scripts.pory"
	goto_if_set FLAG_SYLVARA_TOWN_RARE_CANDY, SylvaraTown_House3_Gentleman_EventScript_2
# 17 "data/maps/SylvaraTown_House3/scripts.pory"
	switch VAR_LANGUAGE
# 18 "data/maps/SylvaraTown_House3/scripts.pory"
	case PT, SylvaraTown_House3_Gentleman_EventScript_6
# 19 "data/maps/SylvaraTown_House3/scripts.pory"
	case EN, SylvaraTown_House3_Gentleman_EventScript_7
# 20 "data/maps/SylvaraTown_House3/scripts.pory"
	case ES, SylvaraTown_House3_Gentleman_EventScript_8
SylvaraTown_House3_Gentleman_EventScript_4:
# 22 "data/maps/SylvaraTown_House3/scripts.pory"
	giveitem ITEM_RARE_CANDY, 1
# 23 "data/maps/SylvaraTown_House3/scripts.pory"
	setflag FLAG_SYLVARA_TOWN_RARE_CANDY
# 24 "data/maps/SylvaraTown_House3/scripts.pory"
	release
	end

SylvaraTown_House3_Gentleman_EventScript_2:
# 9 "data/maps/SylvaraTown_House3/scripts.pory"
	switch VAR_LANGUAGE
# 10 "data/maps/SylvaraTown_House3/scripts.pory"
	case PT, SylvaraTown_House3_Gentleman_EventScript_11
# 11 "data/maps/SylvaraTown_House3/scripts.pory"
	case EN, SylvaraTown_House3_Gentleman_EventScript_12
# 12 "data/maps/SylvaraTown_House3/scripts.pory"
	case ES, SylvaraTown_House3_Gentleman_EventScript_13
SylvaraTown_House3_Gentleman_EventScript_9:
# 14 "data/maps/SylvaraTown_House3/scripts.pory"
	release
	end

SylvaraTown_House3_Gentleman_EventScript_6:
# 18 "data/maps/SylvaraTown_House3/scripts.pory"
	msgbox SylvaraTown_House3_Gentleman_EventScript_Text_3, MSGBOX_AUTOCLOSE
	goto SylvaraTown_House3_Gentleman_EventScript_4

SylvaraTown_House3_Gentleman_EventScript_7:
# 19 "data/maps/SylvaraTown_House3/scripts.pory"
	msgbox SylvaraTown_House3_Gentleman_EventScript_Text_4, MSGBOX_AUTOCLOSE
	goto SylvaraTown_House3_Gentleman_EventScript_4

SylvaraTown_House3_Gentleman_EventScript_8:
# 20 "data/maps/SylvaraTown_House3/scripts.pory"
	msgbox SylvaraTown_House3_Gentleman_EventScript_Text_5, MSGBOX_AUTOCLOSE
	goto SylvaraTown_House3_Gentleman_EventScript_4

SylvaraTown_House3_Gentleman_EventScript_11:
# 10 "data/maps/SylvaraTown_House3/scripts.pory"
	msgbox SylvaraTown_House3_Gentleman_EventScript_Text_0, MSGBOX_AUTOCLOSE
	goto SylvaraTown_House3_Gentleman_EventScript_9

SylvaraTown_House3_Gentleman_EventScript_12:
# 11 "data/maps/SylvaraTown_House3/scripts.pory"
	msgbox SylvaraTown_House3_Gentleman_EventScript_Text_1, MSGBOX_AUTOCLOSE
	goto SylvaraTown_House3_Gentleman_EventScript_9

SylvaraTown_House3_Gentleman_EventScript_13:
# 12 "data/maps/SylvaraTown_House3/scripts.pory"
	msgbox SylvaraTown_House3_Gentleman_EventScript_Text_2, MSGBOX_AUTOCLOSE
	goto SylvaraTown_House3_Gentleman_EventScript_9


SylvaraTown_House3_Gentleman_EventScript_Text_0:
# 10 "data/maps/SylvaraTown_House3/scripts.pory"
	.string "Como está aquele DOCE RARO que te\ndei?\pEspero que tenha ajudado algum\nPOKéMON a dar o próximo grande\lpasso!\pEu ainda guardo alguns comigo… só\npor precaução.$"

SylvaraTown_House3_Gentleman_EventScript_Text_1:
# 11 "data/maps/SylvaraTown_House3/scripts.pory"
	.string "How's that RARE CANDY I gave you?\pI hope it helped one of your\nPOKéMON take the next big step!\pI still keep a few with me… just\nin case.$"

SylvaraTown_House3_Gentleman_EventScript_Text_2:
# 12 "data/maps/SylvaraTown_House3/scripts.pory"
	.string "¿Qué tal ese CARAMELO RARO que te\ndi?\p¡Espero que haya ayudado a uno de\ntus POKéMON a dar el siguiente\lgran paso!\pYo todavía llevo algunos conmigo…\npor si acaso.$"

SylvaraTown_House3_Gentleman_EventScript_Text_3:
# 18 "data/maps/SylvaraTown_House3/scripts.pory"
	.string "Às vezes ficamos ansiosos quando\nnosso POKéMON está prestes a\levoluir.\pPor isso, eu sempre carrego alguns\nDOCES RAROS comigo.\pAqui, pegue um para você!$"

SylvaraTown_House3_Gentleman_EventScript_Text_4:
# 19 "data/maps/SylvaraTown_House3/scripts.pory"
	.string "Sometimes we get excited when our\nPOKéMON is just about to evolve.\pThat's why I always carry a few\nRARE CANDIES with me.\pHere, take one for yourself!$"

SylvaraTown_House3_Gentleman_EventScript_Text_5:
# 20 "data/maps/SylvaraTown_House3/scripts.pory"
	.string "A veces nos emocionamos cuando\nnuestro POKéMON está a punto de\levolucionar.\pPor eso siempre llevo algunos\nCARAMELOS RAROS conmigo.\p¡Toma uno para ti!$"
