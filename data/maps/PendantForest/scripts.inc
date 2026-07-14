PendantForest_MapScripts::
	.byte 0


PendantForest_TrainerBattle_BugCatcher_Leonel::
# 5 "data/maps/PendantForest/scripts.pory"
	switch VAR_LANGUAGE
# 6 "data/maps/PendantForest/scripts.pory"
	case PT, PendantForest_TrainerBattle_BugCatcher_Leonel_3
# 9 "data/maps/PendantForest/scripts.pory"
	case EN, PendantForest_TrainerBattle_BugCatcher_Leonel_4
# 12 "data/maps/PendantForest/scripts.pory"
	case ES, PendantForest_TrainerBattle_BugCatcher_Leonel_5
PendantForest_TrainerBattle_BugCatcher_Leonel_1:
# 16 "data/maps/PendantForest/scripts.pory"
	release
	end

PendantForest_TrainerBattle_BugCatcher_Leonel_3:
# 7 "data/maps/PendantForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_LEONEL, PendantForest_TrainerBattle_BugCatcher_Leonel_Text_0, PendantForest_TrainerBattle_BugCatcher_Leonel_Text_1
# 8 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_TrainerBattle_BugCatcher_Leonel_Text_2
	goto PendantForest_TrainerBattle_BugCatcher_Leonel_1

PendantForest_TrainerBattle_BugCatcher_Leonel_4:
# 10 "data/maps/PendantForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_LEONEL, PendantForest_TrainerBattle_BugCatcher_Leonel_Text_3, PendantForest_TrainerBattle_BugCatcher_Leonel_Text_4
# 11 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_TrainerBattle_BugCatcher_Leonel_Text_5
	goto PendantForest_TrainerBattle_BugCatcher_Leonel_1

PendantForest_TrainerBattle_BugCatcher_Leonel_5:
# 13 "data/maps/PendantForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_LEONEL, PendantForest_TrainerBattle_BugCatcher_Leonel_Text_6, PendantForest_TrainerBattle_BugCatcher_Leonel_Text_7
# 14 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_TrainerBattle_BugCatcher_Leonel_Text_8
	goto PendantForest_TrainerBattle_BugCatcher_Leonel_1


PendantForest_FatMan_Talk::
# 21 "data/maps/PendantForest/scripts.pory"
	switch VAR_LANGUAGE
# 22 "data/maps/PendantForest/scripts.pory"
	case PT, PendantForest_FatMan_Talk_3
# 23 "data/maps/PendantForest/scripts.pory"
	case EN, PendantForest_FatMan_Talk_4
# 24 "data/maps/PendantForest/scripts.pory"
	case ES, PendantForest_FatMan_Talk_5
PendantForest_FatMan_Talk_1:
	end

PendantForest_FatMan_Talk_3:
# 22 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_FatMan_Talk_Text_0, MSGBOX_NPC
	goto PendantForest_FatMan_Talk_1

PendantForest_FatMan_Talk_4:
# 23 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_FatMan_Talk_Text_1, MSGBOX_NPC
	goto PendantForest_FatMan_Talk_1

PendantForest_FatMan_Talk_5:
# 24 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_FatMan_Talk_Text_2, MSGBOX_NPC
	goto PendantForest_FatMan_Talk_1


PendantForest_FindItem_Repel::
# 30 "data/maps/PendantForest/scripts.pory"
	finditem ITEM_REPEL
	end


PendantForest_FindItem_TM11::
# 35 "data/maps/PendantForest/scripts.pory"
	finditem ITEM_TM_ACID_SPRAY
	end


PendantForest_FindItem_Antidote::
# 40 "data/maps/PendantForest/scripts.pory"
	finditem ITEM_ANTIDOTE
	end


PendantForest_TrainerBattle_Camper_Dilan::
# 45 "data/maps/PendantForest/scripts.pory"
	switch VAR_LANGUAGE
# 46 "data/maps/PendantForest/scripts.pory"
	case PT, PendantForest_TrainerBattle_Camper_Dilan_3
# 49 "data/maps/PendantForest/scripts.pory"
	case EN, PendantForest_TrainerBattle_Camper_Dilan_4
# 52 "data/maps/PendantForest/scripts.pory"
	case ES, PendantForest_TrainerBattle_Camper_Dilan_5
PendantForest_TrainerBattle_Camper_Dilan_1:
	end

PendantForest_TrainerBattle_Camper_Dilan_3:
# 47 "data/maps/PendantForest/scripts.pory"
	trainerbattle_single TRAINER_CAMPER_DILAN, PendantForest_TrainerBattle_Camper_Dilan_Text_0, PendantForest_TrainerBattle_Camper_Dilan_Text_1
# 48 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_TrainerBattle_Camper_Dilan_Text_2
	goto PendantForest_TrainerBattle_Camper_Dilan_1

PendantForest_TrainerBattle_Camper_Dilan_4:
# 50 "data/maps/PendantForest/scripts.pory"
	trainerbattle_single TRAINER_CAMPER_DILAN, PendantForest_TrainerBattle_Camper_Dilan_Text_3, PendantForest_TrainerBattle_Camper_Dilan_Text_4
# 51 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_TrainerBattle_Camper_Dilan_Text_5
	goto PendantForest_TrainerBattle_Camper_Dilan_1

PendantForest_TrainerBattle_Camper_Dilan_5:
# 53 "data/maps/PendantForest/scripts.pory"
	trainerbattle_single TRAINER_CAMPER_DILAN, PendantForest_TrainerBattle_Camper_Dilan_Text_6, PendantForest_TrainerBattle_Camper_Dilan_Text_7
# 54 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_TrainerBattle_Camper_Dilan_Text_8
	goto PendantForest_TrainerBattle_Camper_Dilan_1


PendantForest_TrainerBattle_BugCatcher_Francis::
# 60 "data/maps/PendantForest/scripts.pory"
	switch VAR_LANGUAGE
# 61 "data/maps/PendantForest/scripts.pory"
	case PT, PendantForest_TrainerBattle_BugCatcher_Francis_3
# 64 "data/maps/PendantForest/scripts.pory"
	case EN, PendantForest_TrainerBattle_BugCatcher_Francis_4
# 67 "data/maps/PendantForest/scripts.pory"
	case ES, PendantForest_TrainerBattle_BugCatcher_Francis_5
PendantForest_TrainerBattle_BugCatcher_Francis_1:
	end

PendantForest_TrainerBattle_BugCatcher_Francis_3:
# 62 "data/maps/PendantForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_FRANCIS, PendantForest_TrainerBattle_BugCatcher_Francis_Text_0, PendantForest_TrainerBattle_BugCatcher_Francis_Text_1
# 63 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_TrainerBattle_BugCatcher_Francis_Text_2
	goto PendantForest_TrainerBattle_BugCatcher_Francis_1

PendantForest_TrainerBattle_BugCatcher_Francis_4:
# 65 "data/maps/PendantForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_FRANCIS, PendantForest_TrainerBattle_BugCatcher_Francis_Text_3, PendantForest_TrainerBattle_BugCatcher_Francis_Text_4
# 66 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_TrainerBattle_BugCatcher_Francis_Text_5
	goto PendantForest_TrainerBattle_BugCatcher_Francis_1

PendantForest_TrainerBattle_BugCatcher_Francis_5:
# 68 "data/maps/PendantForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_FRANCIS, PendantForest_TrainerBattle_BugCatcher_Francis_Text_6, PendantForest_TrainerBattle_BugCatcher_Francis_Text_7
# 69 "data/maps/PendantForest/scripts.pory"
	msgbox PendantForest_TrainerBattle_BugCatcher_Francis_Text_8
	goto PendantForest_TrainerBattle_BugCatcher_Francis_1


PendantForest_TrainerBattle_BugCatcher_Leonel_Text_0:
# 7 "data/maps/PendantForest/scripts.pory"
	.string "Você vai se ver comigo!$"

PendantForest_TrainerBattle_BugCatcher_Leonel_Text_1:
# 7 "data/maps/PendantForest/scripts.pory"
	.string "Não estou com sorte hoje…$"

PendantForest_TrainerBattle_BugCatcher_Leonel_Text_2:
# 8 "data/maps/PendantForest/scripts.pory"
	.string "Meus insetos são muito especiais!$"

PendantForest_TrainerBattle_BugCatcher_Leonel_Text_3:
# 10 "data/maps/PendantForest/scripts.pory"
	.string "You're going to face me!$"

PendantForest_TrainerBattle_BugCatcher_Leonel_Text_4:
# 10 "data/maps/PendantForest/scripts.pory"
	.string "I'm not having any luck today…$"

PendantForest_TrainerBattle_BugCatcher_Leonel_Text_5:
# 11 "data/maps/PendantForest/scripts.pory"
	.string "My bugs are very special!$"

PendantForest_TrainerBattle_BugCatcher_Leonel_Text_6:
# 13 "data/maps/PendantForest/scripts.pory"
	.string "¡Te vas a enfrentar a mí!$"

PendantForest_TrainerBattle_BugCatcher_Leonel_Text_7:
# 13 "data/maps/PendantForest/scripts.pory"
	.string "Hoy no tengo suerte…$"

PendantForest_TrainerBattle_BugCatcher_Leonel_Text_8:
# 14 "data/maps/PendantForest/scripts.pory"
	.string "¡Mis insectos son muy especiales!$"

PendantForest_FatMan_Talk_Text_0:
# 22 "data/maps/PendantForest/scripts.pory"
	.string "Dizem que caminhar na floresta faz\nbem pra saúde…\pEntão por que eu estou ficando\nMAIS cansado?$"

PendantForest_FatMan_Talk_Text_1:
# 23 "data/maps/PendantForest/scripts.pory"
	.string "People say walking through forests\nis good for your health…\pSo why am I getting EVEN more\ntired?$"

PendantForest_FatMan_Talk_Text_2:
# 24 "data/maps/PendantForest/scripts.pory"
	.string "Dicen que caminar por el bosque es\nbueno para la salud…\pEntonces, ¿por qué me estoy\ncansando AÚN más?$"

PendantForest_TrainerBattle_Camper_Dilan_Text_0:
# 47 "data/maps/PendantForest/scripts.pory"
	.string "Ei! Você também veio explorar a\nPendant Forest?\pDizem que coisas estranhas\nacontecem aqui durante a noite…\pMas eu não tenho medo!\nVamos batalhar!$"

PendantForest_TrainerBattle_Camper_Dilan_Text_1:
# 47 "data/maps/PendantForest/scripts.pory"
	.string "A-Ah…\pTalvez eu esteja um pouco\nassustado…$"

PendantForest_TrainerBattle_Camper_Dilan_Text_2:
# 48 "data/maps/PendantForest/scripts.pory"
	.string "Depois da nossa batalha, a\nfloresta parece menos assustadora.\pMas ainda sinto que alguém está\nobservando entre as árvores…$"

PendantForest_TrainerBattle_Camper_Dilan_Text_3:
# 50 "data/maps/PendantForest/scripts.pory"
	.string "Hey! Did you come to explore\nPendant Forest too?\pPeople say strange things happen\nhere during the night…\pBut I'm not scared!\nLet's battle!$"

PendantForest_TrainerBattle_Camper_Dilan_Text_4:
# 50 "data/maps/PendantForest/scripts.pory"
	.string "W-Whoa…\nMaybe I am a little scared…$"

PendantForest_TrainerBattle_Camper_Dilan_Text_5:
# 51 "data/maps/PendantForest/scripts.pory"
	.string "After our battle, the forest feels\nless scary somehow.\pBut I still feel like something is\nwatching us from the trees…$"

PendantForest_TrainerBattle_Camper_Dilan_Text_6:
# 53 "data/maps/PendantForest/scripts.pory"
	.string "¡Oye! ¿Tú también viniste a\nexplorar el Bosque Pendant?\pDicen que cosas extrañas ocurren\naquí durante la noche…\p¡Pero yo no tengo miedo!\n¡Vamos a luchar!$"

PendantForest_TrainerBattle_Camper_Dilan_Text_7:
# 53 "data/maps/PendantForest/scripts.pory"
	.string "A-Ah…\nTal vez sí estoy un poco asustado…$"

PendantForest_TrainerBattle_Camper_Dilan_Text_8:
# 54 "data/maps/PendantForest/scripts.pory"
	.string "Después de nuestra batalla, el\nbosque se siente menos aterrador.\pPero todavía siento que algo nos\nobserva entre los árboles…$"

PendantForest_TrainerBattle_BugCatcher_Francis_Text_0:
# 62 "data/maps/PendantForest/scripts.pory"
	.string "Estou treinando para me tornar um\nespecialista em Pokémon Inseto!\pVocê vai me ajudar a praticar!$"

PendantForest_TrainerBattle_BugCatcher_Francis_Text_1:
# 62 "data/maps/PendantForest/scripts.pory"
	.string "Meus insetos ainda precisam\ntreinar mais…$"

PendantForest_TrainerBattle_BugCatcher_Francis_Text_2:
# 63 "data/maps/PendantForest/scripts.pory"
	.string "Um bom treinador Inseto nunca\ndesiste de estudar!$"

PendantForest_TrainerBattle_BugCatcher_Francis_Text_3:
# 65 "data/maps/PendantForest/scripts.pory"
	.string "I'm training to become a Bug\nPokémon specialist!\pYou'll help me practice!$"

PendantForest_TrainerBattle_BugCatcher_Francis_Text_4:
# 65 "data/maps/PendantForest/scripts.pory"
	.string "My bugs still need more training…$"

PendantForest_TrainerBattle_BugCatcher_Francis_Text_5:
# 66 "data/maps/PendantForest/scripts.pory"
	.string "A good Bug Trainer never stops\nstudying!$"

PendantForest_TrainerBattle_BugCatcher_Francis_Text_6:
# 68 "data/maps/PendantForest/scripts.pory"
	.string "¡Estoy entrenando para convertirme\nen un especialista en Pokémon\lBicho!\p¡Tú me ayudarás a practicar!$"

PendantForest_TrainerBattle_BugCatcher_Francis_Text_7:
# 68 "data/maps/PendantForest/scripts.pory"
	.string "Mis bichos todavía necesitan más\nentrenamiento…$"

PendantForest_TrainerBattle_BugCatcher_Francis_Text_8:
# 69 "data/maps/PendantForest/scripts.pory"
	.string "¡Un buen Entrenador Bicho nunca\ndeja de estudiar!$"
