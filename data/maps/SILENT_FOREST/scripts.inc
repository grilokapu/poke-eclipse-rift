SILENT_FOREST_MapScripts::
# 2 "data/maps/SILENT_FOREST/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SILENT_FOREST_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 6 "data/maps/SILENT_FOREST/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SILENT_FOREST_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

SILENT_FOREST_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_DARK_SORCERERS
	end

SILENT_FOREST_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/SILENT_FOREST/scripts.pory"
	map_script_2 VAR_FOREST_WHISPER_STATE, 0, SetPlayerFacingWarp
	.2byte 0


SetPlayerFacingWarp::
# 12 "data/maps/SILENT_FOREST/scripts.pory"
	callnative SetPlayerDirection
# 13 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_FOREST_WHISPER_STATE, 1
	end


SilentForest_Pentagram_Event_Tile::
# 20 "data/maps/SILENT_FOREST/scripts.pory"
	lockall
# 21 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 22 "data/maps/SILENT_FOREST/scripts.pory"
	moveplayer Common_Movement_ExclaimFacingDown
# 23 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 24 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_SET_SYMBOL_ANIM
# 25 "data/maps/SILENT_FOREST/scripts.pory"
	special DrawWholeMapView
# 26 "data/maps/SILENT_FOREST/scripts.pory"
	delay 20
# 27 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_EXIT
# 28 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 29 "data/maps/SILENT_FOREST/scripts.pory"
	clearflag FLAG_DARK_SORCERERS
# 30 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_SORCERER_1
# 31 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_SORCERER_2
# 32 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_SORCERER_3
# 33 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_SORCERER_4
# 34 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_SORCERER_5
# 35 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_SORCERER_6
# 36 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_SORCERER_7
# 37 "data/maps/SILENT_FOREST/scripts.pory"
	addobject LOCALID_SORCERER_8
# 38 "data/maps/SILENT_FOREST/scripts.pory"
	delay 20
# 39 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, Movement_Sorcerer_WalkDown3
# 40 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, Movement_Sorcerer_WalkLeft6
# 41 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_3, Movement_Sorcerer_WalkLeftUp5
# 42 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_4, Movement_Sorcerer_WalkLeft6LUp
# 43 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_5, Movement_Sorcerer_WalkUp3
# 44 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_6, Movement_Sorcerer_WalkRight6LUp
# 45 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_7, Movement_Sorcerer_WalkRightUp5
# 46 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, Movement_Sorcerer_WalkRight6
# 47 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 48 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 49 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_SORCERER_5, Movement_Sorcerer_WalkNextToPlayer
# 50 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 51 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_3
# 52 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_4
# 53 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_5
SilentForest_Pentagram_Event_Tile_1:
# 55 "data/maps/SILENT_FOREST/scripts.pory"
	delay 20
# 56 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_SORCERER_7, Common_Movement_WalkInPlaceRight
# 57 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CheckGenderString2
# 58 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 59 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_8
# 60 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_9
# 61 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_10
SilentForest_Pentagram_Event_Tile_6:
# 63 "data/maps/SILENT_FOREST/scripts.pory"
	delay 20
# 64 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_SORCERER_3, Common_Movement_WalkInPlaceLeft
# 65 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 66 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_13
# 67 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_14
# 68 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_15
SilentForest_Pentagram_Event_Tile_11:
# 70 "data/maps/SILENT_FOREST/scripts.pory"
	delay 20
# 71 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_SORCERER_6, Common_Movement_WalkInPlaceUp
# 72 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 73 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_18
# 74 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_19
# 75 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_20
SilentForest_Pentagram_Event_Tile_16:
# 77 "data/maps/SILENT_FOREST/scripts.pory"
	delay 20
# 78 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_SORCERER_2, Common_Movement_WalkInPlaceDown
# 79 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 80 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_23
# 81 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_24
# 82 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_25
SilentForest_Pentagram_Event_Tile_21:
# 84 "data/maps/SILENT_FOREST/scripts.pory"
	delay 20
# 85 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_SORCERER_5, Common_Movement_WalkInPlaceUp
# 86 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 87 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_28
# 88 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_29
# 89 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_30
SilentForest_Pentagram_Event_Tile_26:
# 91 "data/maps/SILENT_FOREST/scripts.pory"
	delay 10
# 92 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 93 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_33
# 94 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_34
# 95 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_35
SilentForest_Pentagram_Event_Tile_31:
# 97 "data/maps/SILENT_FOREST/scripts.pory"
	delay 20
# 98 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 99 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_38
# 100 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_39
# 101 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_40
SilentForest_Pentagram_Event_Tile_36:
# 103 "data/maps/SILENT_FOREST/scripts.pory"
	delay 20
# 104 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_43
# 106 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_44
# 107 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_45
SilentForest_Pentagram_Event_Tile_41:
# 109 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_SORCERER_5, Movement_Sorcerer_StepBackFromPlayer
# 110 "data/maps/SILENT_FOREST/scripts.pory"
	delay 30
# 111 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, MovementSorcererStepLeft2Down
# 112 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, MovementSorcererStepUpLeft2
# 113 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_3, MovementSorcererStepUp2Left
# 114 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_4, MovementSorcererStepRightUp2
# 115 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_5, MovementSorcererStepRight2Up
# 116 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_6, MovementSorcererStepDownRight2
# 117 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_7, MovementSorcererStepDown2Right
# 118 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, MovementSorcererStepLeftDown2
# 119 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 120 "data/maps/SILENT_FOREST/scripts.pory"
	delay 30
# 121 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, MovementSorcererStepLeft2Down
# 122 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_3, MovementSorcererStepUpLeft2
# 123 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_4, MovementSorcererStepUp2Left
# 124 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_5, MovementSorcererStepRightUp2
# 125 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_6, MovementSorcererStepRight2Up
# 126 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_7, MovementSorcererStepDownRight2
# 127 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, MovementSorcererStepDown2Right
# 128 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, MovementSorcererStepLeftDown2
# 129 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 130 "data/maps/SILENT_FOREST/scripts.pory"
	delay 30
# 131 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, MovementClock_S1
# 132 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_3, MovementClock_S2
# 133 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_4, MovementClock_S3
# 134 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_5, MovementClock_S4
# 135 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_6, MovementClock_S5
# 136 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_7, MovementClock_S6
# 137 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, MovementClock_S7
# 138 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, MovementClock_S8
# 139 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 140 "data/maps/SILENT_FOREST/scripts.pory"
	delay 30
# 141 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, MovementClock_S1
# 142 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, MovementClock_S2
# 143 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_3, MovementClock_S3
# 144 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_4, MovementClock_S4
# 145 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_5, MovementClock_S5
# 146 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_6, MovementClock_S6
# 147 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_7, MovementClock_S7
# 148 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, MovementClock_S8
# 149 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 150 "data/maps/SILENT_FOREST/scripts.pory"
	delay 30
# 151 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, MovementSorcererStepLeft2Down
# 152 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, MovementSorcererStepUpLeft2
# 153 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_3, MovementSorcererStepUp2Left
# 154 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_4, MovementSorcererStepRightUp2
# 155 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_5, MovementSorcererStepRight2Up
# 156 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_6, MovementSorcererStepDownRight2
# 157 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_7, MovementSorcererStepDown2Right
# 158 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, MovementSorcererStepLeftDown2
# 159 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 160 "data/maps/SILENT_FOREST/scripts.pory"
	delay 30
# 161 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, MovementClock_S1
# 162 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, MovementClock_S2
# 163 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_3, MovementClock_S3
# 164 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_4, MovementClock_S4
# 165 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_5, MovementClock_S5
# 166 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_6, MovementClock_S6
# 167 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_7, MovementClock_S7
# 168 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, MovementClock_S8
# 169 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 170 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8004, 1
# 171 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8005, 1
# 172 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8006, 8
# 173 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8007, 5
# 174 "data/maps/SILENT_FOREST/scripts.pory"
	special ShakeCamera
# 175 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
# 176 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_RESULT, 2
# 177 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_ORB
# 178 "data/maps/SILENT_FOREST/scripts.pory"
	special DoOrbEffect
# 179 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
# 180 "data/maps/SILENT_FOREST/scripts.pory"
	special FadeOutOrbEffect
# 181 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
# 182 "data/maps/SILENT_FOREST/scripts.pory"
	delay 30
# 183 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 184 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_48
# 185 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_49
# 186 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_50
SilentForest_Pentagram_Event_Tile_46:
# 188 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 189 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 190 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 191 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 192 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_53
# 193 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_54
# 194 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_55
SilentForest_Pentagram_Event_Tile_51:
# 196 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8004, 1
# 197 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8005, 1
# 198 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8006, 8
# 199 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_0x8007, 5
# 200 "data/maps/SILENT_FOREST/scripts.pory"
	special ShakeCamera
# 201 "data/maps/SILENT_FOREST/scripts.pory"
	waitstate
# 202 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 203 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 204 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_58
# 205 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_59
# 206 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_60
SilentForest_Pentagram_Event_Tile_56:
# 208 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 209 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_PETAL_DANCE
# 210 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CreateMagnectPortal
# 211 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 212 "data/maps/SILENT_FOREST/scripts.pory"
	pause 120
# 213 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_SHINY
# 214 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CreatePlayerBright
# 215 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 216 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 217 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 218 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_63
# 219 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_64
# 220 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_65
SilentForest_Pentagram_Event_Tile_61:
# 222 "data/maps/SILENT_FOREST/scripts.pory"
	pause 120
# 223 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 224 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, Common_Movement_ExclamationMark
# 225 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, Common_Movement_ExclamationMark
# 226 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_3, Common_Movement_ExclamationMark
# 227 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_4, Common_Movement_ExclamationMark
# 228 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_5, Common_Movement_ExclamationMark
# 229 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_6, Common_Movement_ExclamationMark
# 230 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_7, Common_Movement_ExclamationMark
# 231 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, Common_Movement_ExclamationMark
# 232 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 233 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 234 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 235 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_68
# 236 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_69
# 237 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_70
SilentForest_Pentagram_Event_Tile_66:
# 239 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 240 "data/maps/SILENT_FOREST/scripts.pory"
	playmoncry SPECIES_CHIEN_PAO, 0
# 241 "data/maps/SILENT_FOREST/scripts.pory"
	waitmoncry
# 242 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 243 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_PIN
# 244 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, Common_Movement_QuestionMarkFacingUp
# 245 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, Common_Movement_QuestionMarkFacingUp
# 246 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_3, Common_Movement_QuestionMarkFacingUp
# 247 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_4, Common_Movement_QuestionMarkFacingUp
# 248 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_5, Common_Movement_QuestionMarkFacingUp
# 249 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_6, Common_Movement_QuestionMarkFacingUp
# 250 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_7, Common_Movement_QuestionMarkFacingUp
# 251 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, Common_Movement_QuestionMarkFacingUp
# 252 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMarkFacingUp
# 253 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 254 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 255 "data/maps/SILENT_FOREST/scripts.pory"
	createspobject OBJ_EVENT_GFX_SPECIES ( CHIEN_PAO ), 9, 11, 5
# 256 "data/maps/SILENT_FOREST/scripts.pory"
	special SpawnCameraObject
# 257 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_CAMERA, Movement_CameraShowChienPao
# 258 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovement LOCALID_CAMERA
# 259 "data/maps/SILENT_FOREST/scripts.pory"
	special RemoveCameraObject
# 260 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 261 "data/maps/SILENT_FOREST/scripts.pory"
	special SpawnCameraObject
# 262 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_CAMERA, Movement_CameraGoBackPlayer
# 263 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement 9, Movement_Chien_Pao_GoDown
# 264 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_1, Movement_Sorcerer_GoToRight3
# 265 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_2, Movement_Sorcerer_GoToRight
# 266 "data/maps/SILENT_FOREST/scripts.pory"
	applymovement LOCALID_SORCERER_8, Movement_Sorcerer_GoToLeft
# 267 "data/maps/SILENT_FOREST/scripts.pory"
	waitmovementall
# 268 "data/maps/SILENT_FOREST/scripts.pory"
	special RemoveCameraObject
# 269 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_DOWN_RIGHT
# 270 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker SilentForest_Pentagram_Event_Tile_Text_47
# 271 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 272 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_73
# 273 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_74
# 274 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_75
SilentForest_Pentagram_Event_Tile_71:
# 276 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
# 277 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 278 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_DOWN_RIGHT
# 279 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker SilentForest_Pentagram_Event_Tile_Text_47
# 280 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 281 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_78
# 282 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_79
# 283 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_80
SilentForest_Pentagram_Event_Tile_76:
# 285 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
# 286 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 287 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_DOWN_RIGHT
# 288 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker SilentForest_Pentagram_Event_Tile_Text_47
# 289 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 290 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_83
# 291 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_84
# 292 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_85
SilentForest_Pentagram_Event_Tile_81:
# 294 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
# 295 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 296 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc LOCALID_SORCERER_1, Movement_Sorcerer_GoNextChienPao
# 297 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 298 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_88
# 299 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_89
# 300 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_90
SilentForest_Pentagram_Event_Tile_86:
# 302 "data/maps/SILENT_FOREST/scripts.pory"
	playmoncry SPECIES_CHIEN_PAO, 0
# 303 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc 9, Movement_Chien_Pao_JumpInPlace
# 304 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 305 "data/maps/SILENT_FOREST/scripts.pory"
	playmoncry SPECIES_CHIEN_PAO, 0
# 306 "data/maps/SILENT_FOREST/scripts.pory"
	waitmoncry
# 307 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BUBBLE_BEAM2
# 308 "data/maps/SILENT_FOREST/scripts.pory"
	seticescrystalcurse LOCALID_SORCERER_1
# 309 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 310 "data/maps/SILENT_FOREST/scripts.pory"
	seticescrystalcurse LOCALID_SORCERER_2
# 311 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 312 "data/maps/SILENT_FOREST/scripts.pory"
	seticescrystalcurse LOCALID_SORCERER_3
# 313 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 314 "data/maps/SILENT_FOREST/scripts.pory"
	seticescrystalcurse LOCALID_SORCERER_4
# 315 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 316 "data/maps/SILENT_FOREST/scripts.pory"
	seticescrystalcurse LOCALID_SORCERER_5
# 317 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 318 "data/maps/SILENT_FOREST/scripts.pory"
	seticescrystalcurse LOCALID_SORCERER_6
# 319 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 320 "data/maps/SILENT_FOREST/scripts.pory"
	seticescrystalcurse LOCALID_SORCERER_7
# 321 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 322 "data/maps/SILENT_FOREST/scripts.pory"
	seticescrystalcurse LOCALID_SORCERER_8
# 323 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_M_BRICK_BREAK
# 324 "data/maps/SILENT_FOREST/scripts.pory"
	pause 95
# 325 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_DARK_SORCERERS
# 326 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_SORCERER_1
# 327 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_SORCERER_2
# 328 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_SORCERER_3
# 329 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_SORCERER_4
# 330 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_SORCERER_5
# 331 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_SORCERER_6
# 332 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_SORCERER_7
# 333 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject LOCALID_SORCERER_8
# 334 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 335 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 336 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_DOWN_RIGHT
# 337 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker SilentForest_Pentagram_Event_Tile_Text_47
# 338 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 339 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_93
# 340 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_94
# 341 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_95
SilentForest_Pentagram_Event_Tile_91:
# 343 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
# 344 "data/maps/SILENT_FOREST/scripts.pory"
	waitmoncry
# 345 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc 9, Movement_Chien_Pao_GoToPlayer
# 346 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 347 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_DOWN_RIGHT
# 348 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker SilentForest_Pentagram_Event_Tile_Text_47
# 349 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 350 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_98
# 351 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_99
# 352 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_100
SilentForest_Pentagram_Event_Tile_96:
# 354 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
# 355 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 356 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_DOWN_RIGHT
# 357 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker SilentForest_Pentagram_Event_Tile_Text_47
# 358 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 359 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_103
# 360 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_104
# 361 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_105
SilentForest_Pentagram_Event_Tile_101:
# 363 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
# 364 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 365 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_DOWN_RIGHT
# 366 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker SilentForest_Pentagram_Event_Tile_Text_47
# 367 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_70, MSGBOX_AUTOCLOSE
# 368 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
# 369 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 370 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_DOWN_RIGHT
# 371 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker SilentForest_Pentagram_Event_Tile_Text_47
# 372 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 373 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_108
# 374 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_109
# 375 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_110
SilentForest_Pentagram_Event_Tile_106:
# 377 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
# 378 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 379 "data/maps/SILENT_FOREST/scripts.pory"
	showmonmugshot SPECIES_CHIEN_PAO, MUGSHOT_DOWN_RIGHT
# 380 "data/maps/SILENT_FOREST/scripts.pory"
	setspeaker SilentForest_Pentagram_Event_Tile_Text_47
# 381 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 382 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_113
# 383 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_114
# 384 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_115
SilentForest_Pentagram_Event_Tile_111:
# 386 "data/maps/SILENT_FOREST/scripts.pory"
	hidemonmugshot
# 387 "data/maps/SILENT_FOREST/scripts.pory"
	pause 10
# 388 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc 9, Common_Movement_FaceUp
# 389 "data/maps/SILENT_FOREST/scripts.pory"
	pause 20
# 390 "data/maps/SILENT_FOREST/scripts.pory"
	movenpc 9, Movement_CameraShowChienPao
# 391 "data/maps/SILENT_FOREST/scripts.pory"
	removeobject 9
# 392 "data/maps/SILENT_FOREST/scripts.pory"
	playse SE_EXIT
# 393 "data/maps/SILENT_FOREST/scripts.pory"
	waitse
# 394 "data/maps/SILENT_FOREST/scripts.pory"
	pause 30
# 395 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 396 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_Pentagram_Event_Tile_118
# 397 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_Pentagram_Event_Tile_119
# 398 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_Pentagram_Event_Tile_120
SilentForest_Pentagram_Event_Tile_116:
# 400 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_SILENT_FOREST_STATE, 1
# 401 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 0
# 402 "data/maps/SILENT_FOREST/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 7, 6
# 403 "data/maps/SILENT_FOREST/scripts.pory"
	release
	end

SilentForest_Pentagram_Event_Tile_3:
# 51 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_1, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_1

SilentForest_Pentagram_Event_Tile_4:
# 52 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_2, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_1

SilentForest_Pentagram_Event_Tile_5:
# 53 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_3, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_1

SilentForest_Pentagram_Event_Tile_8:
# 59 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_4, SilentForest_Pentagram_Event_Tile_Text_5, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_6

SilentForest_Pentagram_Event_Tile_9:
# 60 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_4, SilentForest_Pentagram_Event_Tile_Text_6, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_6

SilentForest_Pentagram_Event_Tile_10:
# 61 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_4, SilentForest_Pentagram_Event_Tile_Text_7, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_6

SilentForest_Pentagram_Event_Tile_13:
# 66 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_8, SilentForest_Pentagram_Event_Tile_Text_9, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_11

SilentForest_Pentagram_Event_Tile_14:
# 67 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_8, SilentForest_Pentagram_Event_Tile_Text_10, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_11

SilentForest_Pentagram_Event_Tile_15:
# 68 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_8, SilentForest_Pentagram_Event_Tile_Text_11, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_11

SilentForest_Pentagram_Event_Tile_18:
# 73 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_12, SilentForest_Pentagram_Event_Tile_Text_13, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_16

SilentForest_Pentagram_Event_Tile_19:
# 74 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_12, SilentForest_Pentagram_Event_Tile_Text_14, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_16

SilentForest_Pentagram_Event_Tile_20:
# 75 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_12, SilentForest_Pentagram_Event_Tile_Text_15, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_16

SilentForest_Pentagram_Event_Tile_23:
# 80 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_16, SilentForest_Pentagram_Event_Tile_Text_17, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_21

SilentForest_Pentagram_Event_Tile_24:
# 81 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_16, SilentForest_Pentagram_Event_Tile_Text_18, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_21

SilentForest_Pentagram_Event_Tile_25:
# 82 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_16, SilentForest_Pentagram_Event_Tile_Text_19, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_21

SilentForest_Pentagram_Event_Tile_28:
# 87 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_20, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_26

SilentForest_Pentagram_Event_Tile_29:
# 88 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_21, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_26

SilentForest_Pentagram_Event_Tile_30:
# 89 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_22, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_26

SilentForest_Pentagram_Event_Tile_33:
# 93 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_23, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_31

SilentForest_Pentagram_Event_Tile_34:
# 94 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_24, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_31

SilentForest_Pentagram_Event_Tile_35:
# 95 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_25, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_31

SilentForest_Pentagram_Event_Tile_38:
# 99 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_26, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_36

SilentForest_Pentagram_Event_Tile_39:
# 100 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_27, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_36

SilentForest_Pentagram_Event_Tile_40:
# 101 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_28, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_36

SilentForest_Pentagram_Event_Tile_43:
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_29, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_41

SilentForest_Pentagram_Event_Tile_44:
# 106 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_30, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_41

SilentForest_Pentagram_Event_Tile_45:
# 107 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_31, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_41

SilentForest_Pentagram_Event_Tile_48:
# 184 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_32
	goto SilentForest_Pentagram_Event_Tile_46

SilentForest_Pentagram_Event_Tile_49:
# 185 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_33
	goto SilentForest_Pentagram_Event_Tile_46

SilentForest_Pentagram_Event_Tile_50:
# 186 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_34
	goto SilentForest_Pentagram_Event_Tile_46

SilentForest_Pentagram_Event_Tile_53:
# 192 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_35
	goto SilentForest_Pentagram_Event_Tile_51

SilentForest_Pentagram_Event_Tile_54:
# 193 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_36
	goto SilentForest_Pentagram_Event_Tile_51

SilentForest_Pentagram_Event_Tile_55:
# 194 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_37
	goto SilentForest_Pentagram_Event_Tile_51

SilentForest_Pentagram_Event_Tile_58:
# 204 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_38
	goto SilentForest_Pentagram_Event_Tile_56

SilentForest_Pentagram_Event_Tile_59:
# 205 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_39
	goto SilentForest_Pentagram_Event_Tile_56

SilentForest_Pentagram_Event_Tile_60:
# 206 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_40
	goto SilentForest_Pentagram_Event_Tile_56

SilentForest_Pentagram_Event_Tile_63:
# 218 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_41
	goto SilentForest_Pentagram_Event_Tile_61

SilentForest_Pentagram_Event_Tile_64:
# 219 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_42
	goto SilentForest_Pentagram_Event_Tile_61

SilentForest_Pentagram_Event_Tile_65:
# 220 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_43
	goto SilentForest_Pentagram_Event_Tile_61

SilentForest_Pentagram_Event_Tile_68:
# 235 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_44, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_66

SilentForest_Pentagram_Event_Tile_69:
# 236 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_45, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_66

SilentForest_Pentagram_Event_Tile_70:
# 237 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_0, SilentForest_Pentagram_Event_Tile_Text_46, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_66

SilentForest_Pentagram_Event_Tile_73:
# 272 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_48, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_71

SilentForest_Pentagram_Event_Tile_74:
# 273 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_49, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_71

SilentForest_Pentagram_Event_Tile_75:
# 274 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_50, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_71

SilentForest_Pentagram_Event_Tile_78:
# 281 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_51, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_76

SilentForest_Pentagram_Event_Tile_79:
# 282 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_52, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_76

SilentForest_Pentagram_Event_Tile_80:
# 283 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_53, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_76

SilentForest_Pentagram_Event_Tile_83:
# 290 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_54, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_81

SilentForest_Pentagram_Event_Tile_84:
# 291 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_55, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_81

SilentForest_Pentagram_Event_Tile_85:
# 292 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_56, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_81

SilentForest_Pentagram_Event_Tile_88:
# 298 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_57, SilentForest_Pentagram_Event_Tile_Text_58, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_86

SilentForest_Pentagram_Event_Tile_89:
# 299 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_57, SilentForest_Pentagram_Event_Tile_Text_59, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_86

SilentForest_Pentagram_Event_Tile_90:
# 300 "data/maps/SILENT_FOREST/scripts.pory"
	msgminibox PSS_ICON_SORCERER, SilentForest_Pentagram_Event_Tile_Text_57, SilentForest_Pentagram_Event_Tile_Text_60, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_86

SilentForest_Pentagram_Event_Tile_93:
# 339 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_61, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_91

SilentForest_Pentagram_Event_Tile_94:
# 340 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_62, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_91

SilentForest_Pentagram_Event_Tile_95:
# 341 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_63, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_91

SilentForest_Pentagram_Event_Tile_98:
# 350 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_64, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_96

SilentForest_Pentagram_Event_Tile_99:
# 351 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_65, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_96

SilentForest_Pentagram_Event_Tile_100:
# 352 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_66, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_96

SilentForest_Pentagram_Event_Tile_103:
# 359 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_67, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_101

SilentForest_Pentagram_Event_Tile_104:
# 360 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_68, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_101

SilentForest_Pentagram_Event_Tile_105:
# 361 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_69, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_101

SilentForest_Pentagram_Event_Tile_108:
# 373 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_71, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_106

SilentForest_Pentagram_Event_Tile_109:
# 374 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_72, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_106

SilentForest_Pentagram_Event_Tile_110:
# 375 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_73, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_106

SilentForest_Pentagram_Event_Tile_113:
# 382 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_74, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_111

SilentForest_Pentagram_Event_Tile_114:
# 383 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_75, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_111

SilentForest_Pentagram_Event_Tile_115:
# 384 "data/maps/SILENT_FOREST/scripts.pory"
	msgbox SilentForest_Pentagram_Event_Tile_Text_76, MSGBOX_AUTOCLOSE
	goto SilentForest_Pentagram_Event_Tile_111

SilentForest_Pentagram_Event_Tile_118:
# 396 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_77
	goto SilentForest_Pentagram_Event_Tile_116

SilentForest_Pentagram_Event_Tile_119:
# 397 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_78
	goto SilentForest_Pentagram_Event_Tile_116

SilentForest_Pentagram_Event_Tile_120:
# 398 "data/maps/SILENT_FOREST/scripts.pory"
	blackmessage SilentForest_Pentagram_Event_Tile_Text_79
	goto SilentForest_Pentagram_Event_Tile_116


SetWalkingScript::
# 408 "data/maps/SILENT_FOREST/scripts.pory"
	compare VAR_DEFAULT_WALKING_SCRIPT, 1
	goto_if_eq SetWalkingScript_2
# 413 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 1
# 414 "data/maps/SILENT_FOREST/scripts.pory"
	release
	end

SetWalkingScript_2:
# 410 "data/maps/SILENT_FOREST/scripts.pory"
	release
	end


SilentForest_whisper_1::
# 419 "data/maps/SILENT_FOREST/scripts.pory"
	lockall
# 420 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_TO_BLACK
# 421 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_MSGBOXONMIDDLE
# 422 "data/maps/SILENT_FOREST/scripts.pory"
	callnative CheckGenderString3
# 423 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 424 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_whisper_1_3
# 425 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_whisper_1_4
# 426 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_whisper_1_5
SilentForest_whisper_1_1:
# 428 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 2
# 429 "data/maps/SILENT_FOREST/scripts.pory"
	goto SilentForest_whisper_Continue
	return

SilentForest_whisper_1_3:
# 424 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_1_Text_0
	goto SilentForest_whisper_1_1

SilentForest_whisper_1_4:
# 425 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_1_Text_1
	goto SilentForest_whisper_1_1

SilentForest_whisper_1_5:
# 426 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_1_Text_2
	goto SilentForest_whisper_1_1


SilentForest_whisper_2::
# 433 "data/maps/SILENT_FOREST/scripts.pory"
	lockall
# 434 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_TO_BLACK
# 435 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_MSGBOXONMIDDLE
# 436 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 437 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_whisper_2_3
# 438 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_whisper_2_4
# 439 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_whisper_2_5
SilentForest_whisper_2_1:
# 441 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 3
# 442 "data/maps/SILENT_FOREST/scripts.pory"
	goto SilentForest_whisper_Continue
	return

SilentForest_whisper_2_3:
# 437 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_2_Text_0
	goto SilentForest_whisper_2_1

SilentForest_whisper_2_4:
# 438 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_2_Text_1
	goto SilentForest_whisper_2_1

SilentForest_whisper_2_5:
# 439 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_2_Text_2
	goto SilentForest_whisper_2_1


SilentForest_whisper_3::
# 446 "data/maps/SILENT_FOREST/scripts.pory"
	lockall
# 447 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_TO_BLACK
# 448 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_MSGBOXONMIDDLE
# 449 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 450 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_whisper_3_3
# 451 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_whisper_3_4
# 452 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_whisper_3_5
SilentForest_whisper_3_1:
# 454 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 4
# 455 "data/maps/SILENT_FOREST/scripts.pory"
	goto SilentForest_whisper_Continue
	return

SilentForest_whisper_3_3:
# 450 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_3_Text_0
	goto SilentForest_whisper_3_1

SilentForest_whisper_3_4:
# 451 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_3_Text_1
	goto SilentForest_whisper_3_1

SilentForest_whisper_3_5:
# 452 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_3_Text_2
	goto SilentForest_whisper_3_1


SilentForest_whisper_Continue::
# 459 "data/maps/SILENT_FOREST/scripts.pory"
	clearflag FLAG_MSGBOXONMIDDLE
# 460 "data/maps/SILENT_FOREST/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 461 "data/maps/SILENT_FOREST/scripts.pory"
	callnative SavePlayerFacing
# 462 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_FOREST_WHISPER_STATE, 0
# 463 "data/maps/SILENT_FOREST/scripts.pory"
	warpsilent MAP_SILENT_FOREST, VAR_TEMP_0, VAR_TEMP_1
# 464 "data/maps/SILENT_FOREST/scripts.pory"
	release
	end


SilentForest_whisper_4::
# 469 "data/maps/SILENT_FOREST/scripts.pory"
	lockall
# 470 "data/maps/SILENT_FOREST/scripts.pory"
	fadescreen FADE_TO_BLACK
# 471 "data/maps/SILENT_FOREST/scripts.pory"
	setflag FLAG_MSGBOXONMIDDLE
# 472 "data/maps/SILENT_FOREST/scripts.pory"
	switch VAR_LANGUAGE
# 473 "data/maps/SILENT_FOREST/scripts.pory"
	case PT, SilentForest_whisper_4_3
# 474 "data/maps/SILENT_FOREST/scripts.pory"
	case EN, SilentForest_whisper_4_4
# 475 "data/maps/SILENT_FOREST/scripts.pory"
	case ES, SilentForest_whisper_4_5
SilentForest_whisper_4_1:
# 477 "data/maps/SILENT_FOREST/scripts.pory"
	setvar VAR_DEFAULT_WALKING_SCRIPT, 0
# 478 "data/maps/SILENT_FOREST/scripts.pory"
	goto SilentForest_whisper_Continue
	return

SilentForest_whisper_4_3:
# 473 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_4_Text_0
	goto SilentForest_whisper_4_1

SilentForest_whisper_4_4:
# 474 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_4_Text_1
	goto SilentForest_whisper_4_1

SilentForest_whisper_4_5:
# 475 "data/maps/SILENT_FOREST/scripts.pory"
	transbox SilentForest_whisper_4_Text_2
	goto SilentForest_whisper_4_1


# 481 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Chien_Pao_GoToPlayer:
# 482 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 483 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 486 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Chien_Pao_JumpInPlace:
# 487 "data/maps/SILENT_FOREST/scripts.pory"
	jump_in_place_down
# 487 "data/maps/SILENT_FOREST/scripts.pory"
	jump_in_place_down
# 487 "data/maps/SILENT_FOREST/scripts.pory"
	jump_in_place_down
	step_end

# 490 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_GoNextChienPao:
# 491 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 491 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 492 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 495 "data/maps/SILENT_FOREST/scripts.pory"
Movement_CameraShowChienPao:
# 496 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 496 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 496 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 496 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 496 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
	step_end

# 499 "data/maps/SILENT_FOREST/scripts.pory"
Movement_CameraGoBackPlayer:
# 500 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 500 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 500 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 500 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 500 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
	step_end

# 503 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Chien_Pao_GoDown:
# 504 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 504 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 504 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 504 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 505 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 508 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_GoToRight:
# 509 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 510 "data/maps/SILENT_FOREST/scripts.pory"
	face_left
	step_end

# 513 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_GoToLeft:
# 514 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 515 "data/maps/SILENT_FOREST/scripts.pory"
	face_right
	step_end

# 518 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_GoToRight3:
# 519 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 519 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 519 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 520 "data/maps/SILENT_FOREST/scripts.pory"
	face_left
	step_end

# 523 "data/maps/SILENT_FOREST/scripts.pory"
MovementClock_S1:
# 524 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 525 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 525 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 526 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 529 "data/maps/SILENT_FOREST/scripts.pory"
MovementClock_S2:
# 530 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 530 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 531 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 532 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 535 "data/maps/SILENT_FOREST/scripts.pory"
MovementClock_S3:
# 536 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 537 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 537 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 538 "data/maps/SILENT_FOREST/scripts.pory"
	face_left
	step_end

# 541 "data/maps/SILENT_FOREST/scripts.pory"
MovementClock_S4:
# 542 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 542 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 543 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 544 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 547 "data/maps/SILENT_FOREST/scripts.pory"
MovementClock_S5:
# 548 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 549 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 549 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 550 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 553 "data/maps/SILENT_FOREST/scripts.pory"
MovementClock_S6:
# 554 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 554 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 555 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 556 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 559 "data/maps/SILENT_FOREST/scripts.pory"
MovementClock_S7:
# 560 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 561 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 561 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 562 "data/maps/SILENT_FOREST/scripts.pory"
	face_right
	step_end

# 565 "data/maps/SILENT_FOREST/scripts.pory"
MovementClock_S8:
# 566 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 566 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 567 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 568 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 571 "data/maps/SILENT_FOREST/scripts.pory"
MovementSorcererStepLeftDown2:
# 572 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 573 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 573 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 574 "data/maps/SILENT_FOREST/scripts.pory"
	face_right
	step_end

# 577 "data/maps/SILENT_FOREST/scripts.pory"
MovementSorcererStepDown2Right:
# 578 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 578 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 579 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 580 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 583 "data/maps/SILENT_FOREST/scripts.pory"
MovementSorcererStepDownRight2:
# 584 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 585 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 585 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 586 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 589 "data/maps/SILENT_FOREST/scripts.pory"
MovementSorcererStepRight2Up:
# 590 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 590 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 591 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 592 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 595 "data/maps/SILENT_FOREST/scripts.pory"
MovementSorcererStepRightUp2:
# 596 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 597 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 597 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 598 "data/maps/SILENT_FOREST/scripts.pory"
	face_left
	step_end

# 601 "data/maps/SILENT_FOREST/scripts.pory"
MovementSorcererStepUp2Left:
# 602 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 602 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 603 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 604 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 607 "data/maps/SILENT_FOREST/scripts.pory"
MovementSorcererStepLeft2Down:
# 608 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 608 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 609 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 610 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 613 "data/maps/SILENT_FOREST/scripts.pory"
MovementSorcererStepUpLeft2:
# 614 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 615 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 615 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 616 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 619 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_WalkNextToPlayer:
# 620 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 620 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 621 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 624 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_StepBackFromPlayer:
# 625 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 625 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 626 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 629 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_WalkDown3:
# 630 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 630 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 630 "data/maps/SILENT_FOREST/scripts.pory"
	walk_down
# 631 "data/maps/SILENT_FOREST/scripts.pory"
	face_down
	step_end

# 634 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_WalkLeft6:
# 635 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 635 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 635 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 635 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 635 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 635 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 636 "data/maps/SILENT_FOREST/scripts.pory"
	face_left
	step_end

# 639 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_WalkLeftUp5:
# 640 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 640 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 640 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 640 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 640 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 641 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 642 "data/maps/SILENT_FOREST/scripts.pory"
	face_left
	step_end

# 645 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_WalkLeft6LUp:
# 646 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 646 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 646 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 646 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 646 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 646 "data/maps/SILENT_FOREST/scripts.pory"
	walk_left
# 647 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 650 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_WalkUp3:
# 651 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 651 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 651 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 652 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 655 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_WalkRight6LUp:
# 656 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 656 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 656 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 656 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 656 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 656 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 657 "data/maps/SILENT_FOREST/scripts.pory"
	face_up
	step_end

# 660 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_WalkRightUp5:
# 661 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 661 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 661 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 661 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 661 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 662 "data/maps/SILENT_FOREST/scripts.pory"
	walk_up
# 663 "data/maps/SILENT_FOREST/scripts.pory"
	face_right
	step_end

# 666 "data/maps/SILENT_FOREST/scripts.pory"
Movement_Sorcerer_WalkRight6:
# 667 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 667 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 667 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 667 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 667 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 667 "data/maps/SILENT_FOREST/scripts.pory"
	walk_right
# 668 "data/maps/SILENT_FOREST/scripts.pory"
	face_right
	step_end

SilentForest_Pentagram_Event_Tile_Text_0:
# 51 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Aethros$"

SilentForest_Pentagram_Event_Tile_Text_1:
# 51 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pEntão… você ainda respira.\pCurioso.\pMesmo sem a marca… você encontrou\no símbolo.\pOu talvez…\pEle tenha encontrado você.\pDepois de tanto tempo… ainda há um\neco.\pDiga-me…\pVocê sente isso?\pEssa ausência… onde algo deveria\nestar.\pNão tema.\pA Eclipse Mark nunca desaparece.\pEla apenas… espera.\pE nós…\pCumprimos o chamado.\p{PAUSE_UNTIL_PRESS}\pPermaneça imóvel.\pNão resista.\pO que foi negado a você… será\nrestaurado.$"

SilentForest_Pentagram_Event_Tile_Text_2:
# 52 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pSo… you still breathe.\pCurious.\pEven without the mark… you found\nthe symbol.\pOr perhaps…\pIt found you.\pAfter all this time… there is\nstill an echo.\pTell me…\pDo you feel it?\pThat absence… where something\nshould be.\pDo not fear.\pThe Eclipse Mark never disappears.\pIt merely… waits.\pAnd we…\pAnswer the call.\p{PAUSE_UNTIL_PRESS}\pRemain still.\pDo not resist.\pWhat was denied to you… will be\nrestored.$"

SilentForest_Pentagram_Event_Tile_Text_3:
# 53 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pAsí que… aún respiras.\pCurioso.\pIncluso sin la marca… encontraste\nel símbolo.\pO tal vez…\pÉl te encontró a ti.\pDespués de tanto tiempo… aún queda\nun eco.\pDime…\p¿Lo sientes?\pEsa ausencia… donde debería haber\nalgo.\pNo temas.\pLa Marca Eclipse nunca desaparece.\pSolo… espera.\pY nosotros…\pRespondemos al llamado.\p{PAUSE_UNTIL_PRESS}\pPermanece inmóvil.\pNo te resistas.\pLo que te fue negado… será\nrestaurado.$"

SilentForest_Pentagram_Event_Tile_Text_4:
# 59 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Luke$"

SilentForest_Pentagram_Event_Tile_Text_5:
# 59 "data/maps/SILENT_FOREST/scripts.pory"
	.string "É el{STR_VAR_1}…$"

SilentForest_Pentagram_Event_Tile_Text_6:
# 60 "data/maps/SILENT_FOREST/scripts.pory"
	.string "It is {STR_VAR_1}…$"

SilentForest_Pentagram_Event_Tile_Text_7:
# 61 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Es {STR_VAR_1}…$"

SilentForest_Pentagram_Event_Tile_Text_8:
# 66 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Dhenos$"

SilentForest_Pentagram_Event_Tile_Text_9:
# 66 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Não… algo está faltando.$"

SilentForest_Pentagram_Event_Tile_Text_10:
# 67 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No… something is missing.$"

SilentForest_Pentagram_Event_Tile_Text_11:
# 68 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No… falta algo.$"

SilentForest_Pentagram_Event_Tile_Text_12:
# 73 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Zion$"

SilentForest_Pentagram_Event_Tile_Text_13:
# 73 "data/maps/SILENT_FOREST/scripts.pory"
	.string "A marca deveria estar aqui…$"

SilentForest_Pentagram_Event_Tile_Text_14:
# 74 "data/maps/SILENT_FOREST/scripts.pory"
	.string "The mark should already be there…$"

SilentForest_Pentagram_Event_Tile_Text_15:
# 75 "data/maps/SILENT_FOREST/scripts.pory"
	.string "La marca ya debería estar…$"

SilentForest_Pentagram_Event_Tile_Text_16:
# 80 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Trohn$"

SilentForest_Pentagram_Event_Tile_Text_17:
# 80 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Desapareceu… assim como antes…\nVocê não lembra de nós…?$"

SilentForest_Pentagram_Event_Tile_Text_18:
# 81 "data/maps/SILENT_FOREST/scripts.pory"
	.string "It faded… just like before…\nDo you not remember us…?$"

SilentForest_Pentagram_Event_Tile_Text_19:
# 82 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Se desvaneció… como antes…\n¿No nos recuerdas…?$"

SilentForest_Pentagram_Event_Tile_Text_20:
# 87 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pEles ainda escutam.\pMesmo agora… ainda te reconhecem.\pMas você…\pVocê está vazio.\pA marca foi arrancada… ou\nesquecida.\pNão importa.\pO símbolo não erra.\pEle nunca erra.\pSe ele respondeu…\pEntão você ainda pertence a isto.\pE isto… pertence a você.$"

SilentForest_Pentagram_Event_Tile_Text_21:
# 88 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pThey still hear it.\pEven now… they still recognize\nyou.\pBut you…\pYou are empty.\pThe mark was torn away… or\nforgotten.\pIt doesn't matter.\pThe symbol does not err.\pIt never errs.\pIf it responded…\pThen you still belong to this.\pAnd this… belongs to you.$"

SilentForest_Pentagram_Event_Tile_Text_22:
# 89 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pAún lo escuchan.\pIncluso ahora… aún te reconocen.\pPero tú…\pEstás vacío.\pLa marca fue arrancada… o\nolvidada.\pNo importa.\pEl símbolo no se equivoca.\pNunca se equivoca.\pSi respondió…\pEntonces aún perteneces a esto.\pY esto… te pertenece.$"

SilentForest_Pentagram_Event_Tile_Text_23:
# 93 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Escute com atenção.\pO que vamos devolver…\pnão é apenas poder.\pÉ memória.\pÉ peso.\pÉ ligação.$"

SilentForest_Pentagram_Event_Tile_Text_24:
# 94 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Listen carefully.\pWhat we are about to return…\pis not just power.\pIt is memory.\pIt is weight.\pIt is connection.$"

SilentForest_Pentagram_Event_Tile_Text_25:
# 95 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Escucha con atención.\pLo que vamos a devolver…\pno es solo poder.\pEs memoria.\pEs peso.\pEs vínculo.$"

SilentForest_Pentagram_Event_Tile_Text_26:
# 99 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Quando despertar…\nvocê não será mais o mesmo.$"

SilentForest_Pentagram_Event_Tile_Text_27:
# 100 "data/maps/SILENT_FOREST/scripts.pory"
	.string "When you awaken…\nyou will not be the same.$"

SilentForest_Pentagram_Event_Tile_Text_28:
# 101 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Cuando despiertes…\nya no serás el mismo.$"

SilentForest_Pentagram_Event_Tile_Text_29:
# 105 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Mas… talvez…\nnunca tenha sido.$"

SilentForest_Pentagram_Event_Tile_Text_30:
# 106 "data/maps/SILENT_FOREST/scripts.pory"
	.string "But… perhaps…\nyou never were.$"

SilentForest_Pentagram_Event_Tile_Text_31:
# 107 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Pero… quizás…\nnunca lo fuiste.$"

SilentForest_Pentagram_Event_Tile_Text_32:
# 184 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pVocê sente algo… pressionando seu\npeito.\p$"

SilentForest_Pentagram_Event_Tile_Text_33:
# 185 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pYou feel something… pressing\nagainst your chest.\p$"

SilentForest_Pentagram_Event_Tile_Text_34:
# 186 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pSientes algo… presionando tu\npecho.\p$"

SilentForest_Pentagram_Event_Tile_Text_35:
# 192 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Sua visão… oscila.\p$"

SilentForest_Pentagram_Event_Tile_Text_36:
# 193 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Your vision… wavers.\p$"

SilentForest_Pentagram_Event_Tile_Text_37:
# 194 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Tu visión… oscila.\p$"

SilentForest_Pentagram_Event_Tile_Text_38:
# 204 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Algo foi gravado em você.\pAlgo… despertou.\p$"

SilentForest_Pentagram_Event_Tile_Text_39:
# 205 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Something was etched into you.\pSomething… awakened.\p$"

SilentForest_Pentagram_Event_Tile_Text_40:
# 206 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Algo fue grabado en ti.\pAlgo… despertó.\p$"

SilentForest_Pentagram_Event_Tile_Text_41:
# 218 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pSeu corpo está… diferente.\p$"

SilentForest_Pentagram_Event_Tile_Text_42:
# 219 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pYour body feels… different.\p$"

SilentForest_Pentagram_Event_Tile_Text_43:
# 220 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pTu cuerpo se siente… diferente.\p$"

SilentForest_Pentagram_Event_Tile_Text_44:
# 235 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\nIsto… não deveria acontecer.$"

SilentForest_Pentagram_Event_Tile_Text_45:
# 236 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\nThis… shouldn't be happening.$"

SilentForest_Pentagram_Event_Tile_Text_46:
# 237 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\nEsto… no debería estar pasando.$"

SilentForest_Pentagram_Event_Tile_Text_47:
# 270 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Chien-Pao$"

SilentForest_Pentagram_Event_Tile_Text_48:
# 272 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pVocê…\pEles tocaram você.\pErrado.\pEles não deveriam.\pEles sempre fazem isso…\pChamam.\pTomam.\pEsquecem o preço.$"

SilentForest_Pentagram_Event_Tile_Text_49:
# 273 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pYou…\pThey touched you.\pWrong.\pThey shouldn't have.\pThey always do this…\pThey call.\pThey take.\pThey forget the cost.$"

SilentForest_Pentagram_Event_Tile_Text_50:
# 274 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\pTú…\pEllos te tocaron.\pMal.\pNo deberían.\pSiempre hacen esto…\pLlaman.\pToman.\pOlvidan el precio.$"

SilentForest_Pentagram_Event_Tile_Text_51:
# 281 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Você não pertence a eles.\nNunca pertenceu.$"

SilentForest_Pentagram_Event_Tile_Text_52:
# 282 "data/maps/SILENT_FOREST/scripts.pory"
	.string "You do not belong to them.\nYou never did.$"

SilentForest_Pentagram_Event_Tile_Text_53:
# 283 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No perteneces a ellos.\nNunca perteneciste.$"

SilentForest_Pentagram_Event_Tile_Text_54:
# 290 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Mas agora…\nVocê carrega o sinal.$"

SilentForest_Pentagram_Event_Tile_Text_55:
# 291 "data/maps/SILENT_FOREST/scripts.pory"
	.string "But now…\nYou carry the mark.$"

SilentForest_Pentagram_Event_Tile_Text_56:
# 292 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Pero ahora…\nLlevas la marca.$"

SilentForest_Pentagram_Event_Tile_Text_57:
# 298 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Zoth$"

SilentForest_Pentagram_Event_Tile_Text_58:
# 298 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Mestre-$"

SilentForest_Pentagram_Event_Tile_Text_59:
# 299 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Master-$"

SilentForest_Pentagram_Event_Tile_Text_60:
# 300 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Maestro-$"

SilentForest_Pentagram_Event_Tile_Text_61:
# 339 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Fracos.\nEles não mudam.$"

SilentForest_Pentagram_Event_Tile_Text_62:
# 340 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Weak.\nThey do not change.$"

SilentForest_Pentagram_Event_Tile_Text_63:
# 341 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Débiles.\nNo cambian.$"

SilentForest_Pentagram_Event_Tile_Text_64:
# 350 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Escute.\nIsso não é um pedido.$"

SilentForest_Pentagram_Event_Tile_Text_65:
# 351 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Listen.\nThis is not a request.$"

SilentForest_Pentagram_Event_Tile_Text_66:
# 352 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Escucha.\nEsto no es una petición.$"

SilentForest_Pentagram_Event_Tile_Text_67:
# 359 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Meus irmãos…\nEstão sendo caçados.$"

SilentForest_Pentagram_Event_Tile_Text_68:
# 360 "data/maps/SILENT_FOREST/scripts.pory"
	.string "My brothers…\nAre being hunted.$"

SilentForest_Pentagram_Event_Tile_Text_69:
# 361 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Mis hermanos…\nEstán siendo cazados.$"

SilentForest_Pentagram_Event_Tile_Text_70:
# 367 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Ting-Lu.\pWo-Chien.\pChi-Yu.$"

SilentForest_Pentagram_Event_Tile_Text_71:
# 373 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Selados… corrompidos…\nenfraquecidos.\pSe caírem…\nIsso também cairá.\pVocê carrega a marca.\nEles vão encontrá-lo.$"

SilentForest_Pentagram_Event_Tile_Text_72:
# 374 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Sealed… corrupted…\nweakened.\pIf they fall…\nThis will fall as well.\pYou carry the mark.\nThey will find you.$"

SilentForest_Pentagram_Event_Tile_Text_73:
# 375 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Sellados… corrompidos…\ndebilitados.\pSi caen…\nEsto también caerá.\pLlevas la marca.\nTe encontrarán.$"

SilentForest_Pentagram_Event_Tile_Text_74:
# 382 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Quando isso acontecer…\nNão falhe.$"

SilentForest_Pentagram_Event_Tile_Text_75:
# 383 "data/maps/SILENT_FOREST/scripts.pory"
	.string "When that happens…\nDo not fail.$"

SilentForest_Pentagram_Event_Tile_Text_76:
# 384 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Cuando eso ocurra…\nNo falles.$"

SilentForest_Pentagram_Event_Tile_Text_77:
# 396 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Acorde!\p$"

SilentForest_Pentagram_Event_Tile_Text_78:
# 397 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Wake up!\p$"

SilentForest_Pentagram_Event_Tile_Text_79:
# 398 "data/maps/SILENT_FOREST/scripts.pory"
	.string "¡Despierta!\p$"

SilentForest_whisper_1_Text_0:
# 424 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\nEl{STR_VAR_1} chegou…$"

SilentForest_whisper_1_Text_1:
# 425 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\n{STR_VAR_1} arrived…$"

SilentForest_whisper_1_Text_2:
# 426 "data/maps/SILENT_FOREST/scripts.pory"
	.string "...\n{STR_VAR_1} llegó…$"

SilentForest_whisper_2_Text_0:
# 437 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Não olhe para trás…$"

SilentForest_whisper_2_Text_1:
# 438 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Don't look back…$"

SilentForest_whisper_2_Text_2:
# 439 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No mires atrás…$"

SilentForest_whisper_3_Text_0:
# 450 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Ainda não…\pAinda não…$"

SilentForest_whisper_3_Text_1:
# 451 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Not yet…\pNot yet…$"

SilentForest_whisper_3_Text_2:
# 452 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Aún no…\pAún no…$"

SilentForest_whisper_4_Text_0:
# 473 "data/maps/SILENT_FOREST/scripts.pory"
	.string "Você não deveria estar aqui.$"

SilentForest_whisper_4_Text_1:
# 474 "data/maps/SILENT_FOREST/scripts.pory"
	.string "You shouldn't be here.$"

SilentForest_whisper_4_Text_2:
# 475 "data/maps/SILENT_FOREST/scripts.pory"
	.string "No deberías estar aquí.$"
