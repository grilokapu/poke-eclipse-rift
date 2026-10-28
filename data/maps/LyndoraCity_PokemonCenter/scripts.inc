LyndoraCity_PokemonCenter_MapScripts::
# 2 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 3 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LyndoraCity_PokemonCenter_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LyndoraCity_PokemonCenter_MapScripts_MAP_SCRIPT_ON_LOAD:
# 4 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	sethealingplacePC MAP_LYNDORA_CITY_POKEMON_CENTER
	end


LyndoraCity_PokemonCenter_EventScript_Nurse::
# 10 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	setvar VAR_0x800B, LOCALID_LYNDORA_NURSE
# 11 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 12 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	waitmessage
# 13 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	waitbuttonpress
# 14 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	release
	end


LyndoraCity_PokemonCenter_EventScript_OldWoman::
# 19 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	switch VAR_LANGUAGE
# 20 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case PT, LyndoraCity_PokemonCenter_EventScript_OldWoman_3
# 21 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case EN, LyndoraCity_PokemonCenter_EventScript_OldWoman_4
# 22 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case ES, LyndoraCity_PokemonCenter_EventScript_OldWoman_5
LyndoraCity_PokemonCenter_EventScript_OldWoman_1:
	end

LyndoraCity_PokemonCenter_EventScript_OldWoman_3:
# 20 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_OldWoman_Text_0, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_OldWoman_1

LyndoraCity_PokemonCenter_EventScript_OldWoman_4:
# 21 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_OldWoman_Text_1, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_OldWoman_1

LyndoraCity_PokemonCenter_EventScript_OldWoman_5:
# 22 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_OldWoman_Text_2, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_OldWoman_1


LyndoraCity_PokemonCenter_EventScript_Trainer::
# 28 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	switch VAR_LANGUAGE
# 29 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case PT, LyndoraCity_PokemonCenter_EventScript_Trainer_3
# 30 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case EN, LyndoraCity_PokemonCenter_EventScript_Trainer_4
# 31 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case ES, LyndoraCity_PokemonCenter_EventScript_Trainer_5
LyndoraCity_PokemonCenter_EventScript_Trainer_1:
	end

LyndoraCity_PokemonCenter_EventScript_Trainer_3:
# 29 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_Trainer_Text_0, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_Trainer_1

LyndoraCity_PokemonCenter_EventScript_Trainer_4:
# 30 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_Trainer_Text_1, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_Trainer_1

LyndoraCity_PokemonCenter_EventScript_Trainer_5:
# 31 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_Trainer_Text_2, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_Trainer_1


LyndoraCity_PokemonCenter_EventScript_LittleGirl::
# 37 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	switch VAR_LANGUAGE
# 38 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case PT, LyndoraCity_PokemonCenter_EventScript_LittleGirl_3
# 39 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case EN, LyndoraCity_PokemonCenter_EventScript_LittleGirl_4
# 40 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case ES, LyndoraCity_PokemonCenter_EventScript_LittleGirl_5
LyndoraCity_PokemonCenter_EventScript_LittleGirl_1:
	end

LyndoraCity_PokemonCenter_EventScript_LittleGirl_3:
# 38 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_LittleGirl_Text_0, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_LittleGirl_1

LyndoraCity_PokemonCenter_EventScript_LittleGirl_4:
# 39 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_LittleGirl_Text_1, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_LittleGirl_1

LyndoraCity_PokemonCenter_EventScript_LittleGirl_5:
# 40 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_LittleGirl_Text_2, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_LittleGirl_1


LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs::
# 46 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	switch VAR_LANGUAGE
# 47 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case PT, LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_3
# 48 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case EN, LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_4
# 49 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	case ES, LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_5
LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_1:
	end

LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_3:
# 47 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_Text_0, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_1

LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_4:
# 48 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_Text_1, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_1

LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_5:
# 49 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	msgbox LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_Text_2, MSGBOX_NPC
	goto LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_1


LyndoraCity_PokemonCenter_EventScript_OldWoman_Text_0:
# 20 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "Meu POKéMON conhece o caminho\npara este Centro de cor.\pÀs vezes acho que ele vem só\npara receber carinho da Joy!$"

LyndoraCity_PokemonCenter_EventScript_OldWoman_Text_1:
# 21 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "My POKéMON knows the way\nto this Center by heart.\pSometimes I think it comes\njust to get a hug from Joy!$"

LyndoraCity_PokemonCenter_EventScript_OldWoman_Text_2:
# 22 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "Mi POKéMON se sabe de memoria\nel camino a este Centro.\p¡A veces creo que viene solo\npara que Joy lo mime!$"

LyndoraCity_PokemonCenter_EventScript_Trainer_Text_0:
# 29 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "Cheguei pela Rota 5 e vim\ndireto cuidar da minha equipe.\pAntes de seguir viagem, vou\nrepor meus itens aqui mesmo.$"

LyndoraCity_PokemonCenter_EventScript_Trainer_Text_1:
# 30 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "I arrived from Route 5 and\ncame to heal my team first.\pBefore moving on, I will\nrestock my items right here.$"

LyndoraCity_PokemonCenter_EventScript_Trainer_Text_2:
# 31 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "Llegué por la Ruta 5 y vine\nprimero a curar a mi equipo.\pAntes de seguir, compraré\nmás objetos aquí mismo.$"

LyndoraCity_PokemonCenter_EventScript_LittleGirl_Text_0:
# 38 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "Meu POKéMON dormiu no meu colo\nenquanto esperávamos a Joy.\pAgora minhas pernas dormiram\ntambém... Como vou levantar?$"

LyndoraCity_PokemonCenter_EventScript_LittleGirl_Text_1:
# 39 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "My POKéMON fell asleep on\nmy lap while we waited for Joy.\pNow my legs are asleep too...\nHow am I supposed to get up?$"

LyndoraCity_PokemonCenter_EventScript_LittleGirl_Text_2:
# 40 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "Mi POKéMON se durmió en mi\nregazo mientras esperábamos.\pAhora mis piernas también...\n¿Cómo voy a levantarme?$"

LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_Text_0:
# 47 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "Sinto muito.\pEstamos trabalhando no subsolo\nagora.\pO acesso ao público está proibido.\pPor favor, tente novamente mais\ntarde.$"

LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_Text_1:
# 48 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "Sorry.\pWe are working in the basement\nnow.\pPublic access is prohibited.\pPlease try again later.$"

LyndoraCity_PokemonCenter_EventScript_Teala_BlockStairs_Text_2:
# 49 "data/maps/LyndoraCity_PokemonCenter/scripts.pory"
	.string "Lo siento.\pEstamos trabajando en el sótano\nahora.\pEl acceso al público está\nprohibido.\pPor favor, inténtelo de nuevo más\ntarde.$"
