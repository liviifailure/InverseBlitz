RustboroCity_Gym_Viola_Edition_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Viola::
	setvar VAR_FORCEANIM, 1
	faceplayer
	specialvar VAR_RESULT, Script_CheckPartyBelowLevelCap
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_Roxanne_NotReady
	call_if_eq VAR_BADGE_COUNT, 0, RustboroCity_Gym_EventScript_Viola_Trainer1
	call_if_eq VAR_BADGE_COUNT, 1, RustboroCity_Gym_EventScript_Viola_Trainer2
	call_if_eq VAR_BADGE_COUNT, 2, RustboroCity_Gym_EventScript_Viola_Trainer3
	call_if_eq VAR_BADGE_COUNT, 3, RustboroCity_Gym_EventScript_Viola_Trainer4
	call_if_eq VAR_BADGE_COUNT, 4, RustboroCity_Gym_EventScript_Viola_Trainer5
	call_if_eq VAR_BADGE_COUNT, 5, RustboroCity_Gym_EventScript_Viola_Trainer6
	call_if_eq VAR_BADGE_COUNT, 6, RustboroCity_Gym_EventScript_Viola_Trainer7
	call_if_eq VAR_BADGE_COUNT, 7, RustboroCity_Gym_EventScript_Viola_Trainer8

	RustboroCity_Gym_EventScript_Viola_Trainer1::
        trainerbattle_single TRAINER_VIOLA_1, RustboroCity_Gym_Text_ViolaIntro, RustboroCity_Gym_Text_ViolaDefeat, RustboroCity_Gym_EventScript_ViolaDefeated, NO_MUSIC
        goto RustboroCity_Gym_EventScript_Viola_PostBattle 

	RustboroCity_Gym_EventScript_Viola_Trainer2::
        trainerbattle_single TRAINER_VIOLA_2, RustboroCity_Gym_Text_ViolaIntro, RustboroCity_Gym_Text_ViolaDefeat, RustboroCity_Gym_EventScript_ViolaDefeated, NO_MUSIC
        goto RustboroCity_Gym_EventScript_Viola_PostBattle 

	RustboroCity_Gym_EventScript_Viola_Trainer3::
        trainerbattle_single TRAINER_VIOLA_3, RustboroCity_Gym_Text_ViolaIntro, RustboroCity_Gym_Text_ViolaDefeat, RustboroCity_Gym_EventScript_ViolaDefeated, NO_MUSIC
        goto RustboroCity_Gym_EventScript_Viola_PostBattle 

	RustboroCity_Gym_EventScript_Viola_Trainer4::
        trainerbattle_single TRAINER_VIOLA_4, RustboroCity_Gym_Text_ViolaIntro, RustboroCity_Gym_Text_ViolaDefeat, RustboroCity_Gym_EventScript_ViolaDefeated, NO_MUSIC
        goto RustboroCity_Gym_EventScript_Viola_PostBattle 

	RustboroCity_Gym_EventScript_Viola_Trainer5::
        trainerbattle_single TRAINER_VIOLA_5, RustboroCity_Gym_Text_ViolaIntro, RustboroCity_Gym_Text_ViolaDefeat, RustboroCity_Gym_EventScript_ViolaDefeated, NO_MUSIC
        goto RustboroCity_Gym_EventScript_Viola_PostBattle 

	RustboroCity_Gym_EventScript_Viola_Trainer6::
        trainerbattle_single TRAINER_VIOLA_6, RustboroCity_Gym_Text_ViolaIntro, RustboroCity_Gym_Text_ViolaDefeat, RustboroCity_Gym_EventScript_ViolaDefeated, NO_MUSIC
        goto RustboroCity_Gym_EventScript_Viola_PostBattle 

	RustboroCity_Gym_EventScript_Viola_Trainer7::
        trainerbattle_single TRAINER_VIOLA_7, RustboroCity_Gym_Text_ViolaIntro, RustboroCity_Gym_Text_ViolaDefeat, RustboroCity_Gym_EventScript_ViolaDefeated, NO_MUSIC
        goto RustboroCity_Gym_EventScript_Viola_PostBattle 

	RustboroCity_Gym_EventScript_Viola_Trainer8::
        trainerbattle_single TRAINER_VIOLA_8, RustboroCity_Gym_Text_ViolaIntro, RustboroCity_Gym_Text_ViolaDefeat, RustboroCity_Gym_EventScript_ViolaDefeated, NO_MUSIC
        goto RustboroCity_Gym_EventScript_Viola_PostBattle 

RustboroCity_Gym_EventScript_Viola_PostBattle::
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_ViolaRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb @ Label in Roxanne's file
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT @ Text is generic
	release
	end

RustboroCity_Gym_EventScript_ViolaDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge @ Label in Roxanne's file
	waitmessage
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT @ Label in Roxanne's file
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_0x8008, 1
	setvar VAR_FORCEANIM, 0
	recordtrainerwin TRAINER_VIOLA_1
	call Common_EventScript_SetGymTrainers
	goto RustboroCity_Gym_EventScript_GiveRockTomb @ Label in Roxanne's file
	end

RustboroCity_Gym_EventScript_ViolaRematch::
	trainerbattle_rematch_double TRAINER_VIOLA_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Viola_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory @ Label in Roxanne's file
	msgbox RustboroCity_Viola_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Viola_Gym_Text_GymGuideAdvice:
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
	.string "VIOLA, the GYM LEADER, is a user\n"
	.string "of BUG-type POKéMON.\p"
	.string "BUG-type POKéMON are fragile, but\n"
	.string "they can be quite tricky. They\l"
	.string "can't stand FIRE, FLYING, or\l"
	.string "ROCK-type moves.\p"
	.string "Come see me afterwards, if you beat\n"
	.string "the GYM LEADER.$"

RustboroCity_Gym_Text_ViolaIntro:
	.string "Hiya! Bet you weren't expecting me!\n"
	.string "I'm VIOLA, from the Kalos region!\p"
	.string "ROXANNE is on vacation, and\n"
	.string "she asked me to step in while I was\l"
	.string "here on research. Now check out these\l"
	.string "new BUG-type POKéMON I found!$"

RustboroCity_Gym_Text_ViolaDefeat:
	.string "Wowza! You sure are strong! Here, I\n"
	.string "was told that if I lost, I was supposed\l"
	.string "to give you this GYM BADGE.$"
