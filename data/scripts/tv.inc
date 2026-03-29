EventScript_TV::
	lockall
	goto_if_set FLAG_SYS_SOLO_MODE, EventScript_SoloModeToggleOff

	incrementgamestat GAME_STAT_WATCHED_TV
	special ResetTVShowState
	specialvar VAR_RESULT, CheckForPlayersHouseNews
	goto_if_eq VAR_RESULT, PLAYERS_HOUSE_TV_MOVIE, EventScript_PlayersHouseMovie
	goto_if_eq VAR_RESULT, PLAYERS_HOUSE_TV_LATI, EventScript_PlayersHouseLatiNewsFlash
	goto_if_unset FLAG_SYS_TV_START, EventScript_MomDadMightLikeThis1
	goto_if_set FLAG_SYS_TV_WATCH, EventScript_MomDadMightLikeThis1
	specialvar VAR_RESULT, IsGabbyAndTyShowOnTheAir
	goto_if_eq VAR_RESULT, TRUE, EventScript_DoInSearchOfTrainers
	goto EventScript_TryDoPokeNews
	end

EventScript_TryDoTVShow::
	specialvar VAR_0x8004, GetRandomActiveShowIdx
	goto_if_eq VAR_0x8004, 255, EventScript_MomDadMightLikeThis2
	specialvar VAR_RESULT, GetNextActiveShowIfMassOutbreak
	goto_if_eq VAR_RESULT, 255, EventScript_MomDadMightLikeThis2
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, GetSelectedTVShow
	goto_if_ne VAR_RESULT, 0, EventScript_DoTVShow
	end

EventScript_MomDadMightLikeThis1::
	goto_if_set FLAG_SYS_SOLO_MODE, EventScript_SoloModeToggleOff @ Should not be reached
	msgbox PlayersHouse_2F_Text_SoloModeIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_TurnOnSoloMode
	goto EventScript_MomDadMightLikeThis1_Generic

EventScript_SoloModeToggleOff::
	msgbox PlayersHouse_2F_Text_SoloModeTurnOff, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_JustRelease
	goto EventScript_TurnOffSoloMode
EventScript_MomDadMightLikeThis1_Generic:
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_TurnOnSoloMode::
	callnative ScriptMenu_SetupSoloMode
	msgbox PlayersHouse_2F_Text_SoloModeActivated, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_TurnOffSoloMode::
	callnative ScriptMenu_DisableSoloMode
	msgbox PlayersHouse_2F_Text_SoloModeDeactivated, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_JustRelease::
	special TurnOffTVScreen
	releaseall
	end

EventScript_PlayersHouseMovie::
	msgbox PlayersHouse_1F_Text_TheresAMovieOnTV, MSGBOX_DEFAULT
	releaseall
	end

@ special InitRoamer is a junk call. Its input var (VAR_0x8004) hasn't been set, and
@ It's called again when Mom actually asks for the color, overwriting
@ whatever it does here.
EventScript_PlayersHouseLatiNewsFlash::
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
	special InitRoamer
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	releaseall
	end

@ The following is a loop for the TV show messages
@ VAR_RESULT is set to TRUE when the show has printed its final message
EventScript_DoTVShow::
	special DoTVShow
	waitmessage
	waitbuttonpress
	goto_if_ne VAR_RESULT, TRUE, EventScript_DoTVShow
	goto EventScript_TurnOffTV
	end

EventScript_TurnOffTV::
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_WATCH
	releaseall
	end

EventScript_MomDadMightLikeThis2::
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	goto EventScript_TurnOffTV
	end

EventScript_TryDoPokeNews::
	special DoPokeNews
	goto_if_eq VAR_RESULT, FALSE, EventScript_TryDoTVShow
	waitmessage
	waitbuttonpress
	goto EventScript_TurnOffTV
	end

EventScript_DoInSearchOfTrainers::
	special DoTVShowInSearchOfTrainers
	waitmessage
	waitbuttonpress
	goto_if_eq VAR_RESULT, 0, EventScript_DoInSearchOfTrainers
	goto EventScript_TurnOffTV
	end

PlayersHouse_2F_Text_SoloModeIntro:
	.string "Welcome to SOLO MODE! In this mode,\p"
	.string "Pokémon cost points to select\n"
	.string "and have neutral IVs and natures.\p"
	.string "It also sets your Eevee's IVs to\n"
	.string "15 and its nature to Hardy.\p"
	.string "Additionally, this mode adds 8\n"
	.string "ability capsules to your bag, which\l"
	.string "you can use to choose your Pokémon's\l"
	.string "starting abilities.\p"
	.string "After choosing, you should toss\n"
	.string "your extras.\p"
	.string "Would you like to enable SOLO MODE?$"

PlayersHouse_2F_Text_SoloModeActivated:
	.string "Solo Mode has been activated!$"

PlayersHouse_2F_Text_SoloModeTurnOff:
	.string "SOLO MODE is currently active.\n"
	.string "Would you like to disable it?$"

PlayersHouse_2F_Text_SoloModeDeactivated:
	.string "Solo Mode has been deactivated!$"
