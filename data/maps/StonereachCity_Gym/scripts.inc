StonereachCity_Gym_MapScripts::
	.byte 0

StonereachCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, StonereachCity_Gym_Text_RoxanneIntro, StonereachCity_Gym_Text_RoxanneDefeat, StonereachCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, StonereachCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, StonereachCity_Gym_EventScript_GiveRockTomb
	msgbox StonereachCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

StonereachCity_Gym_EventScript_RoxanneDefeated::
	message StonereachCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox StonereachCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_STONEREACH_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_STONEREACH_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto StonereachCity_Gym_EventScript_GiveRockTomb
	end

StonereachCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox StonereachCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

StonereachCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, StonereachCity_Gym_Text_RoxannePreRematch, StonereachCity_Gym_Text_RoxanneRematchDefeat, StonereachCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox StonereachCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

StonereachCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, StonereachCity_Gym_Text_JoshIntro, StonereachCity_Gym_Text_JoshDefeat
	msgbox StonereachCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

StonereachCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, StonereachCity_Gym_Text_TommyIntro, StonereachCity_Gym_Text_TommyDefeat
	msgbox StonereachCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

StonereachCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, StonereachCity_Gym_Text_MarcIntro, StonereachCity_Gym_Text_MarcDefeat
	msgbox StonereachCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

StonereachCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_STONEREACH_GYM, StonereachCity_Gym_EventScript_GymGuidePostVictory
	msgbox StonereachCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

StonereachCity_Gym_EventScript_GymGuidePostVictory::
	msgbox StonereachCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

StonereachCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, StonereachCity_Gym_EventScript_GymStatueCertified
	goto StonereachCity_Gym_EventScript_GymStatue
	end

StonereachCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, StonereachCity_Gym_EventScript_GymStatueCertified
	goto StonereachCity_Gym_EventScript_GymStatue
	end

StonereachCity_Gym_EventScript_GymStatueCertified::
	msgbox StonereachCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

StonereachCity_Gym_EventScript_GymStatue::
	msgbox StonereachCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

StonereachCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall StonereachCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox StonereachCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

StonereachCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "Would you like to become the CHAMPION?\p"
	.string "I'm no TRAINER, not me, but I can\n"
	.string "sure give you winning advice.\p"
	.string "That's settled, then! We'll aim for the\n"
	.string "POKéMON CHAMPIONSHIP together!\p"
	.string "It's your job as a TRAINER to collect\n"
	.string "GYM BADGES, am I right?\p"
	.string "But GYM LEADERS aren't pushovers!\p"
	.string "And that's where I come in!\n"
	.string "I'm here to provide expert advice!\p"
	.string "ROXANNE, the GYM LEADER, is a user\n"
	.string "of ROCK-type POKéMON.\p"
	.string "The ROCK type is very durable, but\n"
	.string "it can't stand WATER-type and\l"
	.string "GRASS-type moves.\p"
	.string "Come see me afterwards, if you beat\n"
	.string "the GYM LEADER.\p"
	.string "Well, go for it!$"

StonereachCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa! What a breathtaking victory!\n"
	.string "My cheering must've worked!\p"
	.string "Great!\n"
	.string "Check your TRAINER CARD.\p"
	.string "The STONE BADGE you got should be\n"
	.string "properly recorded on it.\p"
	.string "In other words…\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the CHAMPIONSHIP!\p"
	.string "That's got to feel awesome!$"

StonereachCity_Gym_Text_JoshIntro:
	.string "Don't take us GYM TRAINERS lightly!\n"
	.string "I'll show you why we're better!$"

StonereachCity_Gym_Text_JoshDefeat:
	.string "You were too good for me…$"

StonereachCity_Gym_Text_JoshPostBattle:
	.string "You haven't seen anything of the ROCK\n"
	.string "type's terrifying power!$"

StonereachCity_Gym_Text_TommyIntro:
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against ROXANNE!$"

StonereachCity_Gym_Text_TommyDefeat:
	.string "Wow! You've got some potential!$"

StonereachCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE is stronger than me by\n"
	.string "several times.\p"
	.string "You'd better be on your guard!$"

StonereachCity_Gym_Text_MarcIntro:
	.string "We might be in the middle of town,\n"
	.string "but so what?\p"
	.string "My ROCK POKéMON need room to\n"
	.string "rampage!$"

StonereachCity_Gym_Text_MarcDefeat:
	.string "Oh, man oh man!\n"
	.string "Our challenger is one feisty customer!$"

StonereachCity_Gym_Text_MarcPostBattle:
	.string "I have to hand it to our LEADER.\p"
	.string "It took smarts and sense for her to\n"
	.string "pick the ROCK type at her young age.$"

StonereachCity_Gym_Text_RoxanneIntro:
	.string "Hello, I am ROXANNE, the STONEREACH\n"
	.string "POKéMON GYM LEADER.\p"
	.string "I became a GYM LEADER so that I might\n"
	.string "apply what I learned at the POKéMON\l"
	.string "TRAINER'S SCHOOL in battle.\p"
	.string "Would you kindly demonstrate how you\n"
	.string "battle, and with which POKéMON?$"

StonereachCity_Gym_Text_RoxanneDefeat:
	.string "So…\n"
	.string "I lost…\p"
	.string "It seems that I still have much more\n"
	.string "to learn…\p"
	.string "I understand.\p"
	.string "The POKéMON LEAGUE's rules state\n"
	.string "that TRAINERS are to be given this\l"
	.string "if they defeat a GYM LEADER.\p"
	.string "Please accept the official POKéMON\n"
	.string "LEAGUE STONE BADGE.$"

StonereachCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} received the STONE BADGE\n"
	.string "from ROXANNE.$"

StonereachCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "The STONE BADGE heightens the ATTACK\n"
	.string "power of your POKéMON.\p"
	.string "It also enables them to use the HM move\n"
	.string "CUT outside of battle.\p"
	.string "Please take this with you, too.$"

StonereachCity_Gym_Text_ExplainRockTomb:
	.string "That TECHNICAL MACHINE, TM39,\n"
	.string "contains ROCK TOMB.\p"
	.string "It not only inflicts damage by dropping\n"
	.string "rocks, it also lowers SPEED.\p"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a POKéMON.\p"
	.string "Remember, a TM can be used only once,\n"
	.string "so think before you use it.$"

StonereachCity_Gym_Text_RoxannePostBattle:
	.string "Since you are so strong, you should\n"
	.string "challenge other GYM LEADERS.\p"
	.string "By battling many TRAINERS, you should\n"
	.string "learn many things.$"

StonereachCity_Gym_Text_GymStatue:
	.string "STONEREACH CITY POKéMON GYM$"

StonereachCity_Gym_Text_GymStatueCertified:
	.string "STONEREACH CITY POKéMON GYM\p"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

StonereachCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
	.string "This is ROXANNE of STONEREACH CITY.\p"
	.string "I heard from BRAWLY that you're\n"
	.string "moving up through the ranks of\l"
	.string "TRAINERS at an incredible clip.\p"
	.string "Well, I'd rather not think that\n"
	.string "I can't beat you.\p"
	.string "I promise, I will shape up my GYM\n"
	.string "so that you may challenge us again.\p"
	.string "I hope you'll be looking forward to\n"
	.string "that occasion as much as me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

StonereachCity_Gym_Text_RegisteredRoxanne:
	.string "Registered GYM LEADER ROXANNE\n"
	.string "in the POKéNAV.$"

StonereachCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"

StonereachCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Again, I have lost…$"

StonereachCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: I still have much to learn\n"
	.string "when it comes to battling POKéMON.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

StonereachCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one POKéMON with you?\p"
	.string "Please return with at least one more\n"
	.string "POKéMON.$"
