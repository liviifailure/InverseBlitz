.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call EverGrandeCity_ChampionsRoom_EventScript_SetupWallyScene
	end

EverGrandeCity_ChampionsRoom_EventScript_SetupWallyScene::
	setobjectxyperm LOCALID_WALLACE, 3, 6 @ Steven on Left
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_RIVAL, 9, 6 @ Wally on Right
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WALLY
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	clearflag FLAG_HIDE_CHAMPIONS_ROOM_WALLY
	@ Setup Pokemon
	setobjectxyperm LOCALID_METAGROSS, 5, 6 @ 2 tiles in front of Steven
	setobjectmovementtype LOCALID_METAGROSS, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES(METAGROSS_MEGA)
	setobjectxyperm LOCALID_GALLADE, 7, 6 @ Across from Metagross
	setobjectmovementtype LOCALID_GALLADE, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES(GALLADE_MEGA)
	return

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp2
	waitmovement 0
	delay 40
	goto_if_set FLAG_WALLY_IS_CHAMPION, EverGrandeCity_ChampionsRoom_EventScript_WallyChampionScene
	goto EverGrandeCity_ChampionsRoom_EventScript_StevenChampionScene
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_WallyChampionScene::
	@ Player walks up to watch
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 20
	@ Battle Scene
	msgbox EverGrandeCity_ChampionsRoom_Text_WallyGalladeUseCloseCombat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GALLADE, EverGrandeCity_ChampionsRoom_Movement_GalladeAttack
	waitmovement 0
	playse SE_SUPER_EFFECTIVE
	removeobject LOCALID_METAGROSS
	waitse
	delay 30
	applymovement LOCALID_GALLADE, Common_Movement_FaceRight
	waitmovement 0
	playmoncry SPECIES_GALLADE, CRY_MODE_NORMAL
	waitmoncry
	playse SE_BALL_OPEN
	removeobject LOCALID_GALLADE
	@ Dialogue
	msgbox EverGrandeCity_ChampionsRoom_Text_WallyIWon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_StevenStepIn
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_WallyStepIn
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenCongrats, MSGBOX_DEFAULT
	msgbox EverGrandeCity_ChampionsRoom_Text_WallyMeChampion, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_FaceDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenDefendTitle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	@ Wally notices player
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_WallyApproachPlayer
	waitmovement 0
	setvar VAR_FORCEANIM, 1
	msgbox EverGrandeCity_ChampionsRoom_Text_WallyChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY, EverGrandeCity_ChampionsRoom_Text_WallyDefeat
	@ Post Battle
	setvar VAR_FORCEANIM, 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_WallyPostBattle, MSGBOX_DEFAULT
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenHonors, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_WallyStepAside
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_WalkRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_StevenExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_COOL_PAINTING_MADE
	setflag FLAG_BEAUTY_PAINTING_MADE
	setflag FLAG_CUTE_PAINTING_MADE
	setflag FLAG_SMART_PAINTING_MADE
	setflag FLAG_TOUGH_PAINTING_MADE
	clearflag FLAG_RECEIVED_BIKE
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_StevenChampionScene::
	@ Player walks up to watch
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	delay 20
	@ Battle Scene
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenMetagrossUseMeteorMash, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METAGROSS, EverGrandeCity_ChampionsRoom_Movement_MetagrossAttack
	waitmovement 0
	playse SE_SUPER_EFFECTIVE
	removeobject LOCALID_GALLADE
	waitse
	delay 30
	applymovement LOCALID_METAGROSS, Common_Movement_FaceLeft
	waitmovement 0
	playmoncry SPECIES_METAGROSS, CRY_MODE_NORMAL
	waitmoncry
	playse SE_BALL_OPEN
	removeobject LOCALID_METAGROSS
	@ Dialogue
	msgbox EverGrandeCity_ChampionsRoom_Text_WallyILost, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_StevenStepIn
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_WallyStepIn
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenGoodFight, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	@ Wally notices player
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	msgbox EverGrandeCity_ChampionsRoom_Text_WallyEncourage, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_StevenApproachPlayer
	waitmovement 0
	setvar VAR_FORCEANIM, 1
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, EverGrandeCity_ChampionsRoom_Text_Defeat
	@ Post Battle
	setvar VAR_FORCEANIM, 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_StevenExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_COOL_PAINTING_MADE
	setflag FLAG_BEAUTY_PAINTING_MADE
	setflag FLAG_CUTE_PAINTING_MADE
	setflag FLAG_SMART_PAINTING_MADE
	setflag FLAG_TOUGH_PAINTING_MADE
	clearflag FLAG_RECEIVED_BIKE
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_GalladeAttack:
	walk_left
	step_end

EverGrandeCity_ChampionsRoom_Movement_MetagrossAttack:
	walk_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallyApproachPlayer:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_StevenApproachPlayer:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallyStepAside:
	walk_right
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	setvar VAR_FORCEANIM, 1
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	setvar VAR_FORCEANIM, 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_COOL_PAINTING_MADE
	setflag FLAG_BEAUTY_PAINTING_MADE
	setflag FLAG_CUTE_PAINTING_MADE
	setflag FLAG_SMART_PAINTING_MADE
	setflag FLAG_TOUGH_PAINTING_MADE
	clearflag FLAG_RECEIVED_BIKE
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_WallyStepIn:
	walk_left
	walk_left
	step_end

EverGrandeCity_ChampionsRoom_Movement_StevenStepIn:
	walk_right
	walk_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "STEVEN: Welcome, {PLAYER}{KUN}.\p"
	.string "I was looking forward to seeing you\n"
	.string "here one day.\p"
	.string "You… What did you see on your\n"
	.string "journey with POKéMON?\p"
	.string "What did you feel, meeting so many\n"
	.string "other TRAINERS like you?\p"
	.string "What has awoken in you?\n"
	.string "I want you to hit me with it all!\p"
	.string "Now, bring it!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "I, the CHAMPION, fall in defeat…\p"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
	.string "You are a truly noble POKéMON\n"
	.string "TRAINER!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "STEVEN: Congratulations!\p"
	.string "The feelings you have for your\n"
	.string "POKéMON…\p"
	.string "And the POKéMON that responded to\n"
	.string "those feelings with all their might…\p"
	.string "They came together as one, and created\n"
	.string "an even greater power.\p"
	.string "And thus, you were able to grasp\n"
	.string "victory today!\p"
	.string "You are rightfully the HOENN region's\n"
	.string "new…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "Here's some advice before you challenge\n"
	.string "the CHAMPION…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "MAY: Huh?\n"
	.string "What, what, what?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Could it be that…\l"
	.string "It's already over?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRENDAN: {PLAYER}!\p"
	.string "How would you like some advice before\n"
	.string "you challenge the CHAMPION?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRENDAN: {PLAYER}…\p"
	.string "Are you trying to tell me…\n"
	.string "You've beaten the CHAMPION?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. BIRCH: See?\n"
	.string "What did I tell you, {RIVAL}?\p"
	.string "Didn't I tell you that you don't need\n"
	.string "to worry about {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
	.string "When I heard that you defeated your\n"
	.string "own father at the PETALBURG GYM,\l"
	.string "I thought perhaps you had a chance…\p"
	.string "But to think you've actually become\n"
	.string "the CHAMPION!\p"
	.string "Ah, yes!\p"
	.string "What became of your POKéDEX?\n"
	.string "Here, let me see.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. BIRCH: Anyways,\n"
	.string "congratulations!\p"
	.string "Now, go proudly into the final room!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "STEVEN: {PLAYER}{KUN}…\p"
	.string "No, let me rephrase that properly.\p"
	.string "The new CHAMPION!\p"
	.string "Come with me.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "STEVEN: I'm sorry, but…\p"
	.string "From here on, only those TRAINERS who\n"
	.string "have become CHAMPIONS may enter.\p"
	.string "You'll have to wait outside with\n"
	.string "PROF. BIRCH.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "MAY: Groan…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "I'm just joking! That's okay!\n"
	.string "That's the rule!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Honestly, congratulations!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRENDAN: Whaaaat?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "It can't be helped if that's the rule.\p"
	.string "{PLAYER}, way to go!\n"
	.string "Congratulations!$"

EverGrandeCity_ChampionsRoom_Text_WallyGalladeUseCloseCombat:
	.string "WALLY: GALLADE, use CLOSE COMBAT!$"

EverGrandeCity_ChampionsRoom_Text_WallyIWon:
	.string "WALLY: I... I won? I won!?$"

EverGrandeCity_ChampionsRoom_Text_StevenCongrats:
	.string "STEVEN: A battle well fought!\n"
	.string "Congratulations WALLY, you are the\l"
	.string "new CHAMPION of HOENN!$"

EverGrandeCity_ChampionsRoom_Text_WallyMeChampion:
	.string "WALLY: Me... the CHAMPION!? I did it!\n"
	.string "My POKéMON and I did it!!$"

EverGrandeCity_ChampionsRoom_Text_StevenDefendTitle:
	.string "STEVEN: Don't look now WALLY, but it\n"
	.string "looks like it's already time to\l"
	.string "defend your title.$"

EverGrandeCity_ChampionsRoom_Text_WallyChallenge:
	.string "WALLY: {PLAYER}, did you hear that!?\n"
	.string "My POKéMON and I defeated STEVEN,\l"
	.string "and we did it in record time!\p"
	.string "I bet you weren't expecting that!\p"
	.string "Well, I guess it's just between you\n"
	.string "and me now...\p"
	.string "Let's find out the true CHAMPION\n"
	.string "of HOENN!$"

EverGrandeCity_ChampionsRoom_Text_WallyDefeat:
	.string "I... I lost?$"

EverGrandeCity_ChampionsRoom_Text_WallyPostBattle:
	.string "WALLY: Ah! And to think, I was\n"
	.string "CHAMPION for only a few minutes!\p"
	.string "But {PLAYER}, you deserve it!\n"
	.string "So... now what?$"

EverGrandeCity_ChampionsRoom_Text_StevenHonors:
	.string "STEVEN: I suppose I'll do the honors.\n"
	.string "WALLY, wait right here.\p"
	.string "{PLAYER}, come with me.$"

EverGrandeCity_ChampionsRoom_Text_StevenMetagrossUseMeteorMash:
	.string "STEVEN: METAGROSS, use METEOR MASH!$"

EverGrandeCity_ChampionsRoom_Text_WallyILost:
	.string "WALLY: I... I lost?$"

EverGrandeCity_ChampionsRoom_Text_StevenGoodFight:
	.string "STEVEN: That was a good match, WALLY.\n"
	.string "You have grown strong.\p"
	.string "But to stand at the top, you need\n"
	.string "more than just strength.$"

EverGrandeCity_ChampionsRoom_Text_WallyEncourage:
	.string "WALLY: Look, it's {PLAYER}!\p"
	.string "I couldn't defeat STEVEN...\n"
	.string "But I know you can do it, {PLAYER}!\l"
	.string "Win it for both of us!$"
