Route101_MapScripts::
	.byte 0


Route1_Youngster_battle::
# 6 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 7 "data/maps/Route101/scripts.pory"
	case PT, Route1_Youngster_battle_3
# 10 "data/maps/Route101/scripts.pory"
	case EN, Route1_Youngster_battle_4
# 13 "data/maps/Route101/scripts.pory"
	case ES, Route1_Youngster_battle_5
Route1_Youngster_battle_1:
# 17 "data/maps/Route101/scripts.pory"
	release
	end

Route1_Youngster_battle_3:
# 8 "data/maps/Route101/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_ROMULO, Route1_Youngster_battle_Text_0, Route1_Youngster_battle_Text_1
# 9 "data/maps/Route101/scripts.pory"
	msgbox Route1_Youngster_battle_Text_2
	goto Route1_Youngster_battle_1

Route1_Youngster_battle_4:
# 11 "data/maps/Route101/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_ROMULO, Route1_Youngster_battle_Text_3, Route1_Youngster_battle_Text_4
# 12 "data/maps/Route101/scripts.pory"
	msgbox Route1_Youngster_battle_Text_5
	goto Route1_Youngster_battle_1

Route1_Youngster_battle_5:
# 14 "data/maps/Route101/scripts.pory"
	trainerbattle_single TRAINER_YOUNGSTER_ROMULO, Route1_Youngster_battle_Text_6, Route1_Youngster_battle_Text_7
# 15 "data/maps/Route101/scripts.pory"
	msgbox Route1_Youngster_battle_Text_8
	goto Route1_Youngster_battle_1


Route1_PokeBall_Potion_Get::
# 22 "data/maps/Route101/scripts.pory"
	finditem ITEM_POTION, 1
	end


Route1_PokeBall_Antidote_Get::
# 27 "data/maps/Route101/scripts.pory"
	finditem ITEM_ANTIDOTE, 1
	end


Route1_TrainerTips_Sign::
# 32 "data/maps/Route101/scripts.pory"
	helpwindow HELP_POKE_BALL
	end


Route1_Sign::
# 37 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 38 "data/maps/Route101/scripts.pory"
	case PT, Route1_Sign_3
# 39 "data/maps/Route101/scripts.pory"
	case EN, Route1_Sign_4
# 40 "data/maps/Route101/scripts.pory"
	case ES, Route1_Sign_5
Route1_Sign_1:
	end

Route1_Sign_3:
# 38 "data/maps/Route101/scripts.pory"
	msgbox Route1_Sign_Text_0, MSGBOX_SIGN
	goto Route1_Sign_1

Route1_Sign_4:
# 39 "data/maps/Route101/scripts.pory"
	msgbox Route1_Sign_Text_1, MSGBOX_SIGN
	goto Route1_Sign_1

Route1_Sign_5:
# 40 "data/maps/Route101/scripts.pory"
	msgbox Route1_Sign_Text_2, MSGBOX_SIGN
	goto Route1_Sign_1


Route1_EncounterHikariWildBattle_Tile::
# 49 "data/maps/Route101/scripts.pory"
	lockall
# 50 "data/maps/Route101/scripts.pory"
	playbgm MUS_ENCOUNTER_SUSPICIOUS, 0
# 51 "data/maps/Route101/scripts.pory"
	special SpawnCameraObject
# 52 "data/maps/Route101/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 53 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_1, 13
	goto_if_eq Route1_EncounterHikariWildBattle_Tile_2
# 55 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_1, 14
	goto_if_eq Route1_EncounterHikariWildBattle_Tile_3
# 58 "data/maps/Route101/scripts.pory"
	movecamera Movement_Camera_GotoHikari_3
Route1_EncounterHikariWildBattle_Tile_1:
# 60 "data/maps/Route101/scripts.pory"
	special RemoveCameraObject
# 61 "data/maps/Route101/scripts.pory"
	pause 30
# 62 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 63 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_9
# 64 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_10
# 65 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_11
Route1_EncounterHikariWildBattle_Tile_7:
# 67 "data/maps/Route101/scripts.pory"
	pause 30
# 68 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_ABSOL, Movement_Absol_MovesAngry
# 69 "data/maps/Route101/scripts.pory"
	showmonmugshot SPECIES_ABSOL, MUGSHOT_DOWN_RIGHT
# 70 "data/maps/Route101/scripts.pory"
	setspeaker Route1_EncounterHikariWildBattle_Tile_Text_4
# 71 "data/maps/Route101/scripts.pory"
	msgbox Route1_EncounterHikariWildBattle_Tile_Text_5, MSGBOX_AUTOCLOSE
# 72 "data/maps/Route101/scripts.pory"
	waitmoncry
# 73 "data/maps/Route101/scripts.pory"
	hidemonmugshot
# 74 "data/maps/Route101/scripts.pory"
	pause 20
# 75 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_ABSOL, Movement_Absol_MovesAngry_Clockwise
# 76 "data/maps/Route101/scripts.pory"
	showmonmugshot SPECIES_ABSOL, MUGSHOT_DOWN_RIGHT
# 77 "data/maps/Route101/scripts.pory"
	setspeaker Route1_EncounterHikariWildBattle_Tile_Text_4
# 78 "data/maps/Route101/scripts.pory"
	msgbox Route1_EncounterHikariWildBattle_Tile_Text_5, MSGBOX_AUTOCLOSE
# 79 "data/maps/Route101/scripts.pory"
	waitmoncry
# 80 "data/maps/Route101/scripts.pory"
	hidemonmugshot
# 81 "data/maps/Route101/scripts.pory"
	pause 30
# 82 "data/maps/Route101/scripts.pory"
	playse SE_PIN
# 83 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Common_Movement_ExclaimFacingRight
# 84 "data/maps/Route101/scripts.pory"
	waitse
# 85 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 86 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_14
# 87 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_15
# 88 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_16
Route1_EncounterHikariWildBattle_Tile_12:
# 90 "data/maps/Route101/scripts.pory"
	pause 10
# 91 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Common_Movement_ExclaimFacingLeft
# 92 "data/maps/Route101/scripts.pory"
	pause 10
# 93 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 94 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_19
# 95 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_20
# 96 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_21
Route1_EncounterHikariWildBattle_Tile_17:
# 98 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Movement_HikariStepsBackwards
# 99 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_1, 13
	goto_if_eq Route1_EncounterHikariWildBattle_Tile_23
# 101 "data/maps/Route101/scripts.pory"
	compare VAR_TEMP_1, 15
	goto_if_eq Route1_EncounterHikariWildBattle_Tile_24
Route1_EncounterHikariWildBattle_Tile_22:
# 104 "data/maps/Route101/scripts.pory"
	moveplayer Movement_PlayerStepsForwards
# 105 "data/maps/Route101/scripts.pory"
	createspobject OBJ_EVENT_GFX_SPECIES ( LYCANROC_MIDNIGHT ), 5, 22, 14, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
# 106 "data/maps/Route101/scripts.pory"
	movenpc 5, Movement_Lycanroc_ExitBall
# 107 "data/maps/Route101/scripts.pory"
	pause 20
# 108 "data/maps/Route101/scripts.pory"
	setspeaker Route1_EncounterHikariWildBattle_Tile_Text_12
# 109 "data/maps/Route101/scripts.pory"
	showmonmugshot SPECIES_LYCANROC_MIDNIGHT, MUGSHOT_DOWN_RIGHT
# 110 "data/maps/Route101/scripts.pory"
	msgbox Route1_EncounterHikariWildBattle_Tile_Text_13, MSGBOX_AUTOCLOSE
# 111 "data/maps/Route101/scripts.pory"
	waitmoncry
# 112 "data/maps/Route101/scripts.pory"
	hidemonmugshot
# 113 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 114 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_29
# 115 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_30
# 116 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_31
Route1_EncounterHikariWildBattle_Tile_27:
# 118 "data/maps/Route101/scripts.pory"
	pause 20
# 119 "data/maps/Route101/scripts.pory"
	movenpc 5, Movement_LycanrocAttack
# 120 "data/maps/Route101/scripts.pory"
	playse SE_M_BITE
# 121 "data/maps/Route101/scripts.pory"
	waitse
# 122 "data/maps/Route101/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 123 "data/maps/Route101/scripts.pory"
	movenpc 5, Movement_LycanrocBack
# 124 "data/maps/Route101/scripts.pory"
	waitse
# 125 "data/maps/Route101/scripts.pory"
	pause 20
# 126 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_ABSOL, Movement_AbsolAttack
# 127 "data/maps/Route101/scripts.pory"
	playse SE_M_CUT
# 128 "data/maps/Route101/scripts.pory"
	waitse
# 129 "data/maps/Route101/scripts.pory"
	playse SE_EFFECTIVE
# 130 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_ABSOL, Movement_AbsolBack
# 131 "data/maps/Route101/scripts.pory"
	waitse
# 132 "data/maps/Route101/scripts.pory"
	pause 20
# 133 "data/maps/Route101/scripts.pory"
	playse SE_PIN
# 134 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_ABSOL, Common_Movement_EmojiAngry
# 135 "data/maps/Route101/scripts.pory"
	waitse
# 136 "data/maps/Route101/scripts.pory"
	pause 20
# 137 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 138 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_34
# 139 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_35
# 140 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_36
Route1_EncounterHikariWildBattle_Tile_32:
# 142 "data/maps/Route101/scripts.pory"
	pause 20
# 143 "data/maps/Route101/scripts.pory"
	playmoncry SPECIES_LYCANROC_MIDNIGHT, 0
# 144 "data/maps/Route101/scripts.pory"
	waitmoncry
# 145 "data/maps/Route101/scripts.pory"
	movenpc 5, Movement_LycanrocStoneAttack
# 146 "data/maps/Route101/scripts.pory"
	playse SE_M_ROCK_THROW
# 147 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8000, LOCALID_ROUTE1_ABSOL
# 148 "data/maps/Route101/scripts.pory"
	callnative CreateStoneEdge
# 149 "data/maps/Route101/scripts.pory"
	playse SE_EFFECTIVE
# 150 "data/maps/Route101/scripts.pory"
	pause 30
# 151 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_ABSOL, Movement_Absol_Hurt_AfterStoneEdge
# 152 "data/maps/Route101/scripts.pory"
	pause 20
# 153 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 154 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_39
# 155 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_40
# 156 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_41
Route1_EncounterHikariWildBattle_Tile_37:
# 158 "data/maps/Route101/scripts.pory"
	movenpc 5, Movement_Lycanroc_EnterBall
# 159 "data/maps/Route101/scripts.pory"
	removeobject 5
# 160 "data/maps/Route101/scripts.pory"
	pause 20
# 161 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Movement_HikariStepsForwards
# 162 "data/maps/Route101/scripts.pory"
	createspobject OBJ_EVENT_GFX_POKE_BALL, 6, 22, 14, MOVEMENT_TYPE_NONE
# 163 "data/maps/Route101/scripts.pory"
	movenpc 6, Movement_Pokeball_Bounce_Againt_Absol
# 164 "data/maps/Route101/scripts.pory"
	playse SE_BALL_THROW
# 165 "data/maps/Route101/scripts.pory"
	waitse
# 166 "data/maps/Route101/scripts.pory"
	removeobject LOCALID_ROUTE1_ABSOL
# 167 "data/maps/Route101/scripts.pory"
	playse SE_BALL_BOUNCE_1
# 168 "data/maps/Route101/scripts.pory"
	waitse
# 169 "data/maps/Route101/scripts.pory"
	playse SE_BALL_BOUNCE_2
# 170 "data/maps/Route101/scripts.pory"
	waitse
# 171 "data/maps/Route101/scripts.pory"
	playse SE_BALL_BOUNCE_3
# 172 "data/maps/Route101/scripts.pory"
	waitse
# 173 "data/maps/Route101/scripts.pory"
	playse SE_BALL_BOUNCE_4
# 174 "data/maps/Route101/scripts.pory"
	waitse
# 175 "data/maps/Route101/scripts.pory"
	playse MUS_RG_CAUGHT_INTRO
# 176 "data/maps/Route101/scripts.pory"
	waitse
# 177 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Movement_HikariStepsForwards
# 178 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 179 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_44
# 180 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_45
# 181 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_46
Route1_EncounterHikariWildBattle_Tile_42:
# 183 "data/maps/Route101/scripts.pory"
	pause 20
# 184 "data/maps/Route101/scripts.pory"
	removeobject 6
# 185 "data/maps/Route101/scripts.pory"
	pause 10
# 186 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 187 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_49
# 188 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_50
# 189 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_51
Route1_EncounterHikariWildBattle_Tile_47:
# 191 "data/maps/Route101/scripts.pory"
	pause 10
# 192 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Common_Movement_FaceRight
# 193 "data/maps/Route101/scripts.pory"
	special SpawnCameraObject
# 194 "data/maps/Route101/scripts.pory"
	movecamera Movement_Camera_BackToPlayer
# 195 "data/maps/Route101/scripts.pory"
	special RemoveCameraObject
# 196 "data/maps/Route101/scripts.pory"
	playbgm MUS_ROUTE101, 0
# 197 "data/maps/Route101/scripts.pory"
	playse SE_PIN
# 198 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Common_Movement_EmojiThinking
# 199 "data/maps/Route101/scripts.pory"
	waitse
# 200 "data/maps/Route101/scripts.pory"
	pause 10
# 201 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 202 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_54
# 203 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_55
# 204 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_56
Route1_EncounterHikariWildBattle_Tile_52:
# 206 "data/maps/Route101/scripts.pory"
	pause 20
# 207 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Movement_HikariGoNextPlayer
# 208 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 209 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_59
# 210 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_60
# 211 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_61
Route1_EncounterHikariWildBattle_Tile_57:
# 213 "data/maps/Route101/scripts.pory"
	playse SE_PIN
# 214 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Common_Movement_EmojiSlithly
# 215 "data/maps/Route101/scripts.pory"
	waitse
# 216 "data/maps/Route101/scripts.pory"
	pause 10
# 217 "data/maps/Route101/scripts.pory"
	switch VAR_LANGUAGE
# 218 "data/maps/Route101/scripts.pory"
	case PT, Route1_EncounterHikariWildBattle_Tile_64
# 219 "data/maps/Route101/scripts.pory"
	case EN, Route1_EncounterHikariWildBattle_Tile_65
# 220 "data/maps/Route101/scripts.pory"
	case ES, Route1_EncounterHikariWildBattle_Tile_66
Route1_EncounterHikariWildBattle_Tile_62:
# 222 "data/maps/Route101/scripts.pory"
	movenpc LOCALID_ROUTE1_HIKARI, Movement_WalkBackToLab
# 223 "data/maps/Route101/scripts.pory"
	removeobject LOCALID_ROUTE1_HIKARI
# 224 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE1_HIKARI_EVENT, 1
# 225 "data/maps/Route101/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 1
# 226 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIKARI_ROUTE_1
# 227 "data/maps/Route101/scripts.pory"
	moveplayer Movement_PlayerGoBackToLab
# 228 "data/maps/Route101/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 14
# 229 "data/maps/Route101/scripts.pory"
	release
	end

Route1_EncounterHikariWildBattle_Tile_2:
# 54 "data/maps/Route101/scripts.pory"
	movecamera Movement_Camera_GotoHikari_1
	goto Route1_EncounterHikariWildBattle_Tile_1

Route1_EncounterHikariWildBattle_Tile_3:
# 56 "data/maps/Route101/scripts.pory"
	movecamera Movement_Camera_GotoHikari_2
	goto Route1_EncounterHikariWildBattle_Tile_1

Route1_EncounterHikariWildBattle_Tile_9:
# 63 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_1, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_7

Route1_EncounterHikariWildBattle_Tile_10:
# 64 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_2, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_7

Route1_EncounterHikariWildBattle_Tile_11:
# 65 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_3, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_7

Route1_EncounterHikariWildBattle_Tile_14:
# 86 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_6, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_12

Route1_EncounterHikariWildBattle_Tile_15:
# 87 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_7, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_12

Route1_EncounterHikariWildBattle_Tile_16:
# 88 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_8, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_12

Route1_EncounterHikariWildBattle_Tile_19:
# 94 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_9, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_17

Route1_EncounterHikariWildBattle_Tile_20:
# 95 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_10, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_17

Route1_EncounterHikariWildBattle_Tile_21:
# 96 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_11, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_17

Route1_EncounterHikariWildBattle_Tile_23:
# 100 "data/maps/Route101/scripts.pory"
	moveplayer Common_Movement_WalkDown
	goto Route1_EncounterHikariWildBattle_Tile_22

Route1_EncounterHikariWildBattle_Tile_24:
# 102 "data/maps/Route101/scripts.pory"
	moveplayer Common_Movement_WalkUp
	goto Route1_EncounterHikariWildBattle_Tile_22

Route1_EncounterHikariWildBattle_Tile_29:
# 114 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_14, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_27

Route1_EncounterHikariWildBattle_Tile_30:
# 115 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_15, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_27

Route1_EncounterHikariWildBattle_Tile_31:
# 116 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_16, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_27

Route1_EncounterHikariWildBattle_Tile_34:
# 138 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_17, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_32

Route1_EncounterHikariWildBattle_Tile_35:
# 139 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_18, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_32

Route1_EncounterHikariWildBattle_Tile_36:
# 140 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_19, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_32

Route1_EncounterHikariWildBattle_Tile_39:
# 154 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_20, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_37

Route1_EncounterHikariWildBattle_Tile_40:
# 155 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_21, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_37

Route1_EncounterHikariWildBattle_Tile_41:
# 156 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_22, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_37

Route1_EncounterHikariWildBattle_Tile_44:
# 179 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_23, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_42

Route1_EncounterHikariWildBattle_Tile_45:
# 180 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_24, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_42

Route1_EncounterHikariWildBattle_Tile_46:
# 181 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_25, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_42

Route1_EncounterHikariWildBattle_Tile_49:
# 187 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_26, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_47

Route1_EncounterHikariWildBattle_Tile_50:
# 188 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_27, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_47

Route1_EncounterHikariWildBattle_Tile_51:
# 189 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_28, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_47

Route1_EncounterHikariWildBattle_Tile_54:
# 202 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_29, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_52

Route1_EncounterHikariWildBattle_Tile_55:
# 203 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_30, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_52

Route1_EncounterHikariWildBattle_Tile_56:
# 204 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_31, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_52

Route1_EncounterHikariWildBattle_Tile_59:
# 209 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_32, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_57

Route1_EncounterHikariWildBattle_Tile_60:
# 210 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_33, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_57

Route1_EncounterHikariWildBattle_Tile_61:
# 211 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_34, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_57

Route1_EncounterHikariWildBattle_Tile_64:
# 218 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_35, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_62

Route1_EncounterHikariWildBattle_Tile_65:
# 219 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_36, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_62

Route1_EncounterHikariWildBattle_Tile_66:
# 220 "data/maps/Route101/scripts.pory"
	msgminibox PSS_ICON_HIKARI, Route1_EncounterHikariWildBattle_Tile_Text_0, Route1_EncounterHikariWildBattle_Tile_Text_37, MSGBOX_AUTOCLOSE
	goto Route1_EncounterHikariWildBattle_Tile_62


# 233 "data/maps/Route101/scripts.pory"
Movement_PlayerGoBackToLab:
# 234 "data/maps/Route101/scripts.pory"
	walk_right
# 234 "data/maps/Route101/scripts.pory"
	walk_right
# 234 "data/maps/Route101/scripts.pory"
	walk_right
# 234 "data/maps/Route101/scripts.pory"
	walk_right
# 235 "data/maps/Route101/scripts.pory"
	walk_down
# 235 "data/maps/Route101/scripts.pory"
	walk_down
	step_end

# 238 "data/maps/Route101/scripts.pory"
Movement_Absol_Hurt_AfterStoneEdge:
# 239 "data/maps/Route101/scripts.pory"
	walk_faster_left_backwards
# 240 "data/maps/Route101/scripts.pory"
	delay_16
# 241 "data/maps/Route101/scripts.pory"
	walk_right
# 242 "data/maps/Route101/scripts.pory"
	face_right
	step_end

# 245 "data/maps/Route101/scripts.pory"
Movement_WalkBackToLab:
# 246 "data/maps/Route101/scripts.pory"
	walk_down
# 247 "data/maps/Route101/scripts.pory"
	walk_right
# 247 "data/maps/Route101/scripts.pory"
	walk_right
# 247 "data/maps/Route101/scripts.pory"
	walk_right
# 247 "data/maps/Route101/scripts.pory"
	walk_right
# 247 "data/maps/Route101/scripts.pory"
	walk_right
# 248 "data/maps/Route101/scripts.pory"
	walk_down
# 248 "data/maps/Route101/scripts.pory"
	walk_down
# 249 "data/maps/Route101/scripts.pory"
	walk_right
# 249 "data/maps/Route101/scripts.pory"
	walk_right
# 249 "data/maps/Route101/scripts.pory"
	walk_right
# 249 "data/maps/Route101/scripts.pory"
	walk_right
# 249 "data/maps/Route101/scripts.pory"
	walk_right
	step_end

# 252 "data/maps/Route101/scripts.pory"
Movement_HikariGoNextPlayer:
# 253 "data/maps/Route101/scripts.pory"
	walk_right
# 253 "data/maps/Route101/scripts.pory"
	walk_right
# 254 "data/maps/Route101/scripts.pory"
	face_right
	step_end

# 257 "data/maps/Route101/scripts.pory"
Movement_Pokeball_Bounce_Againt_Absol:
# 258 "data/maps/Route101/scripts.pory"
	jump_2_left
	step_end

# 261 "data/maps/Route101/scripts.pory"
Movement_HikariStepsForwards:
# 262 "data/maps/Route101/scripts.pory"
	walk_left
# 263 "data/maps/Route101/scripts.pory"
	face_left
	step_end

# 266 "data/maps/Route101/scripts.pory"
Movement_LycanrocStoneAttack:
# 267 "data/maps/Route101/scripts.pory"
	jump_in_place_left
# 267 "data/maps/Route101/scripts.pory"
	jump_in_place_left
	step_end

# 270 "data/maps/Route101/scripts.pory"
Movement_AbsolAttack:
# 271 "data/maps/Route101/scripts.pory"
	walk_faster_right
# 271 "data/maps/Route101/scripts.pory"
	walk_faster_right
	step_end

# 274 "data/maps/Route101/scripts.pory"
Movement_LycanrocAttack:
# 275 "data/maps/Route101/scripts.pory"
	walk_faster_left
# 275 "data/maps/Route101/scripts.pory"
	walk_faster_left
	step_end

# 278 "data/maps/Route101/scripts.pory"
Movement_LycanrocBack:
# 279 "data/maps/Route101/scripts.pory"
	jump_right_backwards
# 280 "data/maps/Route101/scripts.pory"
	walk_right
# 281 "data/maps/Route101/scripts.pory"
	face_left
	step_end

# 284 "data/maps/Route101/scripts.pory"
Movement_AbsolBack:
# 285 "data/maps/Route101/scripts.pory"
	jump_left_backwards
# 285 "data/maps/Route101/scripts.pory"
	jump_left_backwards
# 286 "data/maps/Route101/scripts.pory"
	face_right
	step_end

# 289 "data/maps/Route101/scripts.pory"
Movement_Lycanroc_ExitBall:
# 290 "data/maps/Route101/scripts.pory"
	exit_pokeball
	step_end

# 293 "data/maps/Route101/scripts.pory"
Movement_Lycanroc_EnterBall:
# 294 "data/maps/Route101/scripts.pory"
	enter_pokeball
	step_end

# 297 "data/maps/Route101/scripts.pory"
Movement_PlayerStepsForwards:
# 298 "data/maps/Route101/scripts.pory"
	walk_left
# 298 "data/maps/Route101/scripts.pory"
	walk_left
# 299 "data/maps/Route101/scripts.pory"
	face_left
	step_end

# 302 "data/maps/Route101/scripts.pory"
Movement_HikariStepsBackwards:
# 303 "data/maps/Route101/scripts.pory"
	walk_slow_right_backwards
# 304 "data/maps/Route101/scripts.pory"
	face_left
	step_end

# 307 "data/maps/Route101/scripts.pory"
Movement_Absol_MovesAngry_Clockwise:
# 308 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 309 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 310 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 311 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 312 "data/maps/Route101/scripts.pory"
	jump_in_place_right
# 313 "data/maps/Route101/scripts.pory"
	jump_in_place_right
	step_end

# 316 "data/maps/Route101/scripts.pory"
Movement_Absol_MovesAngry:
# 317 "data/maps/Route101/scripts.pory"
	jump_in_place_right
# 318 "data/maps/Route101/scripts.pory"
	jump_in_place_right
	step_end

# 321 "data/maps/Route101/scripts.pory"
Movement_Camera_GotoHikari_1:
# 322 "data/maps/Route101/scripts.pory"
	walk_down
# 323 "data/maps/Route101/scripts.pory"
	walk_left
# 323 "data/maps/Route101/scripts.pory"
	walk_left
# 323 "data/maps/Route101/scripts.pory"
	walk_left
# 323 "data/maps/Route101/scripts.pory"
	walk_left
	step_end

# 326 "data/maps/Route101/scripts.pory"
Movement_Camera_GotoHikari_2:
# 327 "data/maps/Route101/scripts.pory"
	walk_left
# 327 "data/maps/Route101/scripts.pory"
	walk_left
# 327 "data/maps/Route101/scripts.pory"
	walk_left
# 327 "data/maps/Route101/scripts.pory"
	walk_left
	step_end

# 330 "data/maps/Route101/scripts.pory"
Movement_Camera_GotoHikari_3:
# 331 "data/maps/Route101/scripts.pory"
	walk_up
# 332 "data/maps/Route101/scripts.pory"
	walk_left
# 332 "data/maps/Route101/scripts.pory"
	walk_left
# 332 "data/maps/Route101/scripts.pory"
	walk_left
# 332 "data/maps/Route101/scripts.pory"
	walk_left
	step_end

# 335 "data/maps/Route101/scripts.pory"
Movement_Camera_BackToPlayer:
# 336 "data/maps/Route101/scripts.pory"
	walk_right
# 336 "data/maps/Route101/scripts.pory"
	walk_right
# 336 "data/maps/Route101/scripts.pory"
	walk_right
# 336 "data/maps/Route101/scripts.pory"
	walk_right
	step_end

Route1_Youngster_battle_Text_0:
# 8 "data/maps/Route101/scripts.pory"
	.string "Essa é minha primeira batalha de\nverdade com um Pokémon!$"

Route1_Youngster_battle_Text_1:
# 8 "data/maps/Route101/scripts.pory"
	.string "Poxa vida!\nEu achei que tava pronto!$"

Route1_Youngster_battle_Text_2:
# 9 "data/maps/Route101/scripts.pory"
	.string "Tenho treinado muito!\nDa próxima vez, eu vou vencer!$"

Route1_Youngster_battle_Text_3:
# 11 "data/maps/Route101/scripts.pory"
	.string "This is my first real\nPokemon battle!$"

Route1_Youngster_battle_Text_4:
# 11 "data/maps/Route101/scripts.pory"
	.string "Aw man!\nI thought I was ready!$"

Route1_Youngster_battle_Text_5:
# 12 "data/maps/Route101/scripts.pory"
	.string "I've been training hard!\nNext time, I'll win!$"

Route1_Youngster_battle_Text_6:
# 14 "data/maps/Route101/scripts.pory"
	.string "¡Esta es mi primera batalla\nde verdad con un Pokémon!$"

Route1_Youngster_battle_Text_7:
# 14 "data/maps/Route101/scripts.pory"
	.string "¡Rayos!\n¡Creí que estaba listo!$"

Route1_Youngster_battle_Text_8:
# 15 "data/maps/Route101/scripts.pory"
	.string "¡He estado entrenando duro!\n¡La próxima vez, ganaré!$"

Route1_Sign_Text_0:
# 38 "data/maps/Route101/scripts.pory"
	.string "Rota 1\nVila Pineveil {RIGHT_ARROW_2}\lFloresta Pendant {UP_ARROW_2}$"

Route1_Sign_Text_1:
# 39 "data/maps/Route101/scripts.pory"
	.string "Route 1\nPineveil Town {RIGHT_ARROW_2}\lPendant Forest {UP_ARROW_2}$"

Route1_Sign_Text_2:
# 40 "data/maps/Route101/scripts.pory"
	.string "Ruta 1\nPueblo Pineveil {RIGHT_ARROW_2}\lBosque Pendant {UP_ARROW_2}$"

Route1_EncounterHikariWildBattle_Tile_Text_0:
# 63 "data/maps/Route101/scripts.pory"
	.string "Hikari$"

Route1_EncounterHikariWildBattle_Tile_Text_1:
# 63 "data/maps/Route101/scripts.pory"
	.string "...calma.\nEu não quero machucar você.$"

Route1_EncounterHikariWildBattle_Tile_Text_2:
# 64 "data/maps/Route101/scripts.pory"
	.string "...calm down.\nI don't want to hurt you.$"

Route1_EncounterHikariWildBattle_Tile_Text_3:
# 65 "data/maps/Route101/scripts.pory"
	.string "...tranquilo.\nNo quiero hacerte daño.$"

Route1_EncounterHikariWildBattle_Tile_Text_4:
# 70 "data/maps/Route101/scripts.pory"
	.string "Absol$"

Route1_EncounterHikariWildBattle_Tile_Text_5:
# 71 "data/maps/Route101/scripts.pory"
	.string "Grrrrrrr!$"

Route1_EncounterHikariWildBattle_Tile_Text_6:
# 86 "data/maps/Route101/scripts.pory"
	.string "Hm?\pVocê não deveria estar aqui\nsozinho.$"

Route1_EncounterHikariWildBattle_Tile_Text_7:
# 87 "data/maps/Route101/scripts.pory"
	.string "Hm?\pYou shouldn't be here alone.$"

Route1_EncounterHikariWildBattle_Tile_Text_8:
# 88 "data/maps/Route101/scripts.pory"
	.string "¿Hm?\pNo deberías estar aquí solo.$"

Route1_EncounterHikariWildBattle_Tile_Text_9:
# 94 "data/maps/Route101/scripts.pory"
	.string "Fique atrás de mim.$"

Route1_EncounterHikariWildBattle_Tile_Text_10:
# 95 "data/maps/Route101/scripts.pory"
	.string "Stay behind me.$"

Route1_EncounterHikariWildBattle_Tile_Text_11:
# 96 "data/maps/Route101/scripts.pory"
	.string "Quedate detrás de mí.$"

Route1_EncounterHikariWildBattle_Tile_Text_12:
# 108 "data/maps/Route101/scripts.pory"
	.string "Lycanroc$"

Route1_EncounterHikariWildBattle_Tile_Text_13:
# 110 "data/maps/Route101/scripts.pory"
	.string "awooooo!$"

Route1_EncounterHikariWildBattle_Tile_Text_14:
# 114 "data/maps/Route101/scripts.pory"
	.string "Vai, Lycanroc!\pUse {COLOR}{RED}Mastigada{COLOR}{DARK_GRAY}.$"

Route1_EncounterHikariWildBattle_Tile_Text_15:
# 115 "data/maps/Route101/scripts.pory"
	.string "Go, Lycanroc!\pUse {COLOR}{RED}Crunch{COLOR}{DARK_GRAY}.$"

Route1_EncounterHikariWildBattle_Tile_Text_16:
# 116 "data/maps/Route101/scripts.pory"
	.string "Vamos, Lycanroc!\pUsa {COLOR}{RED}Triturar{COLOR}{DARK_GRAY}.$"

Route1_EncounterHikariWildBattle_Tile_Text_17:
# 138 "data/maps/Route101/scripts.pory"
	.string "Agora use {COLOR}{RED}Gume de Pedra{COLOR}{DARK_GRAY}, Lycanroc!$"

Route1_EncounterHikariWildBattle_Tile_Text_18:
# 139 "data/maps/Route101/scripts.pory"
	.string "Now use {COLOR}{RED}Stone Edge{COLOR}{DARK_GRAY}, Lycanroc!$"

Route1_EncounterHikariWildBattle_Tile_Text_19:
# 140 "data/maps/Route101/scripts.pory"
	.string "¡Ahora usa {COLOR}{RED}Roca Afilada{COLOR}{DARK_GRAY}, Lycanroc!$"

Route1_EncounterHikariWildBattle_Tile_Text_20:
# 154 "data/maps/Route101/scripts.pory"
	.string "Volte, Lycanroc!$"

Route1_EncounterHikariWildBattle_Tile_Text_21:
# 155 "data/maps/Route101/scripts.pory"
	.string "Go back, Lycanroc!$"

Route1_EncounterHikariWildBattle_Tile_Text_22:
# 156 "data/maps/Route101/scripts.pory"
	.string "¡Vuelve, Lycanroc!$"

Route1_EncounterHikariWildBattle_Tile_Text_23:
# 179 "data/maps/Route101/scripts.pory"
	.string "Você quase matou a gente de susto,\nsabia?$"

Route1_EncounterHikariWildBattle_Tile_Text_24:
# 180 "data/maps/Route101/scripts.pory"
	.string "You almost scared us to death, you\nknow?$"

Route1_EncounterHikariWildBattle_Tile_Text_25:
# 181 "data/maps/Route101/scripts.pory"
	.string "Casi nos matas del susto, ¿sabías?$"

Route1_EncounterHikariWildBattle_Tile_Text_26:
# 187 "data/maps/Route101/scripts.pory"
	.string "Um Absol aparecendo tão perto da\nvila…\pIsso não é normal.$"

Route1_EncounterHikariWildBattle_Tile_Text_27:
# 188 "data/maps/Route101/scripts.pory"
	.string "An Absol showing up so close to\nthe village…\pThat's not normal.$"

Route1_EncounterHikariWildBattle_Tile_Text_28:
# 189 "data/maps/Route101/scripts.pory"
	.string "Un Absol apareciendo tan cerca de\nla aldea…\pEso no es normal.$"

Route1_EncounterHikariWildBattle_Tile_Text_29:
# 202 "data/maps/Route101/scripts.pory"
	.string "E então ele começou a agir\nestranho quando viu você.\pCurioso...$"

Route1_EncounterHikariWildBattle_Tile_Text_30:
# 203 "data/maps/Route101/scripts.pory"
	.string "And then it started acting\nstrangely when it saw you.\pCurious...$"

Route1_EncounterHikariWildBattle_Tile_Text_31:
# 204 "data/maps/Route101/scripts.pory"
	.string "Y entonces comenzó a actuar de\nforma extraña cuando te vio.\pCurioso...$"

Route1_EncounterHikariWildBattle_Tile_Text_32:
# 209 "data/maps/Route101/scripts.pory"
	.string "Ah, certo.\pVocê deve ser um dos novos\ntreinadores.\pEu sou a Professora Hikari.\pDesculpe por fazê-los esperar no\nlaboratório.\pEu estava investigando relatos\nsobre Pokémon agindo de forma\lincomum nesta rota.$"

Route1_EncounterHikariWildBattle_Tile_Text_33:
# 210 "data/maps/Route101/scripts.pory"
	.string "Ah, right.\pYou must be one of the new\nTrainers.\pI'm Professor Hikari.\pSorry for making you wait at the\nlaboratory.\pI was investigating reports of\nPokémon behaving strangely on this\lroute.$"

Route1_EncounterHikariWildBattle_Tile_Text_34:
# 211 "data/maps/Route101/scripts.pory"
	.string "Ah, cierto.\pDebes ser uno de los nuevos\nentrenadores.\pSoy la Profesora Hikari.\pPerdón por hacerlos esperar en el\nlaboratorio.\pEstaba investigando reportes sobre\nPokémon comportándose de forma\lextraña en esta ruta.$"

Route1_EncounterHikariWildBattle_Tile_Text_35:
# 218 "data/maps/Route101/scripts.pory"
	.string "Ultimamente… coisas estranhas têm\nacontecido em Aetheris.\p...\pMas esse não é o melhor lugar para\nconversar.\pVamos voltar para o laboratório.$"

Route1_EncounterHikariWildBattle_Tile_Text_36:
# 219 "data/maps/Route101/scripts.pory"
	.string "Lately… strange things have been\nhappening in Aetheris.\p...\pBut this isn't the best place to\ntalk.\pLet's head back to the laboratory.$"

Route1_EncounterHikariWildBattle_Tile_Text_37:
# 220 "data/maps/Route101/scripts.pory"
	.string "Últimamente… cosas extrañas han\nestado ocurriendo en Aetheris.\p...\pPero este no es el mejor lugar\npara hablar.\pVolvamos al laboratorio.$"
