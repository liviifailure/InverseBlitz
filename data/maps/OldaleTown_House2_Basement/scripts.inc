OldaleTown_House2_Basement_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OldaleTown_House2_Basement_OnFrame
	.byte 0

OldaleTown_House2_Basement_OnFrame:
	map_script_2 VAR_TEMP_0, 0, OldaleTown_House2_Basement_EventScript_LightUpRoom
	.2byte 0

OldaleTown_House2_Basement_EventScript_LightUpRoom::
	lockall
	setvar VAR_TEMP_0, 1
	animateflash 0
	setflashlevel 0
	releaseall
	end

OldaleTown_House2_EventScript_LevelCapNPC::
	lock
	faceplayer
	message OldaleTown_House2_Text_LevelCapIntro
	waitmessage
	dynmultipush OldaleTown_House2_Text_LevelCaps0, 0
	dynmultipush OldaleTown_House2_Text_LevelCaps1, 1
	dynmultipush OldaleTown_House2_Text_LevelCaps2, 2
	dynmultipush OldaleTown_House2_Text_LevelCaps3, 3
	dynmultipush OldaleTown_House2_Text_LevelCaps4, 4
	dynmultipush OldaleTown_House2_Text_LevelCaps5, 5
	dynmultipush OldaleTown_House2_Text_LevelCaps6, 6
	dynmultipush OldaleTown_House2_Text_LevelCaps7, 7
	dynmultipush OldaleTown_House2_Text_LevelCaps8, 8
	dynmultipush gText_Exit, 9
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, OldaleTown_House2_EventScript_Set0Badges
	case 1, OldaleTown_House2_EventScript_Set1Badge
	case 2, OldaleTown_House2_EventScript_Set2Badges
	case 3, OldaleTown_House2_EventScript_Set3Badges
	case 4, OldaleTown_House2_EventScript_Set4Badges
	case 5, OldaleTown_House2_EventScript_Set5Badges
	case 6, OldaleTown_House2_EventScript_Set6Badges
	case 7, OldaleTown_House2_EventScript_Set7Badges
	case 8, OldaleTown_House2_EventScript_Set8Badges
	goto OldaleTown_House2_EventScript_LevelCapCancel
	end

OldaleTown_House2_EventScript_Set0Badges::
	call OldaleTown_House2_EventScript_ClearAllBadges
	goto OldaleTown_House2_EventScript_LevelCapEnd

OldaleTown_House2_EventScript_Set1Badge::
	call OldaleTown_House2_EventScript_ClearAllBadges
	setflag FLAG_BADGE01_GET
	goto OldaleTown_House2_EventScript_LevelCapEnd

OldaleTown_House2_EventScript_Set2Badges::
	call OldaleTown_House2_EventScript_ClearAllBadges
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	goto OldaleTown_House2_EventScript_LevelCapEnd

OldaleTown_House2_EventScript_Set3Badges::
	call OldaleTown_House2_EventScript_ClearAllBadges
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	goto OldaleTown_House2_EventScript_LevelCapEnd

OldaleTown_House2_EventScript_Set4Badges::
	call OldaleTown_House2_EventScript_ClearAllBadges
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	goto OldaleTown_House2_EventScript_LevelCapEnd

OldaleTown_House2_EventScript_Set5Badges::
	call OldaleTown_House2_EventScript_ClearAllBadges
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	goto OldaleTown_House2_EventScript_LevelCapEnd

OldaleTown_House2_EventScript_Set6Badges::
	call OldaleTown_House2_EventScript_ClearAllBadges
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	goto OldaleTown_House2_EventScript_LevelCapEnd

OldaleTown_House2_EventScript_Set7Badges::
	call OldaleTown_House2_EventScript_ClearAllBadges
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	goto OldaleTown_House2_EventScript_LevelCapEnd

OldaleTown_House2_EventScript_Set8Badges::
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	goto OldaleTown_House2_EventScript_LevelCapEnd

OldaleTown_House2_EventScript_ClearAllBadges::
	clearflag FLAG_BADGE01_GET
	clearflag FLAG_BADGE02_GET
	clearflag FLAG_BADGE03_GET
	clearflag FLAG_BADGE04_GET
	clearflag FLAG_BADGE05_GET
	clearflag FLAG_BADGE06_GET
	clearflag FLAG_BADGE07_GET
	clearflag FLAG_BADGE08_GET
	return

OldaleTown_House2_EventScript_LevelCapEnd::
	msgbox OldaleTown_House2_Text_LevelCapUpdated, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_LevelCapCancel::
	msgbox OldaleTown_House2_Text_LevelCapCancel, MSGBOX_DEFAULT
	release
	end


OldaleTown_House2_Text_LevelCapIntro:
	.string "I can help you adjust your level cap.\n"
	.string "How many badges should you have?$"

OldaleTown_House2_Text_LevelCapUpdated:
	.string "Done! Your level cap has been updated.$"

OldaleTown_House2_Text_LevelCapCancel:
	.string "Come back if you change your mind.$"

OldaleTown_House2_Text_LevelCaps0:
	.string "0 Badges (Lv 15)$"
OldaleTown_House2_Text_LevelCaps1:
	.string "1 Badge (Lv 19)$"
OldaleTown_House2_Text_LevelCaps2:
	.string "2 Badges (Lv 24)$"
OldaleTown_House2_Text_LevelCaps3:
	.string "3 Badges (Lv 29)$"
OldaleTown_House2_Text_LevelCaps4:
	.string "4 Badges (Lv 32)$"
OldaleTown_House2_Text_LevelCaps5:
	.string "5 Badges (Lv 35)$"
OldaleTown_House2_Text_LevelCaps6:
	.string "6 Badges (Lv 42)$"
OldaleTown_House2_Text_LevelCaps7:
	.string "7 Badges (Lv 48)$"
OldaleTown_House2_Text_LevelCaps8:
	.string "8 Badges (Lv 58)$"

OldaleTown_House2_Basement_EventScript_GiftPokemonNPC::
	lock
	faceplayer
	call EventScript_ChooseGiftPokemon
	release
	end

OldaleTown_House2_Basement_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	checkflag FLAG_SYS_BATTLE_DEBUG
	goto_if_set FLAG_SYS_BATTLE_DEBUG, OldaleTown_House2_Basement_EventScript_MiltankDisable
	msgbox OldaleTown_House2_Basement_Text_MiltankIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_House2_Basement_EventScript_EnableDebug
	release
	end

OldaleTown_House2_Basement_EventScript_EnableDebug::
	setflag FLAG_SYS_BATTLE_DEBUG
	msgbox OldaleTown_House2_Basement_Text_MiltankYes, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_Basement_EventScript_MiltankDisable::
	msgbox OldaleTown_House2_Basement_Text_MiltankDisable, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_House2_Basement_EventScript_DisableDebug
	release
	end

OldaleTown_House2_Basement_EventScript_DisableDebug::
	clearflag FLAG_SYS_BATTLE_DEBUG
	msgbox OldaleTown_House2_Basement_Text_MiltankNo, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_Basement_Text_MiltankIntro:
	.string "Moooo! Would you like to enable\n"
	.string "debug mode?$"

OldaleTown_House2_Basement_Text_MiltankYes:
	.string "Moo! (Battle Debug active.\n"
	.string "Press SELECT during move selection.)$"

OldaleTown_House2_Basement_Text_MiltankDisable:
	.string "Moo? (Would you like to disable\n"
	.string "debug mode?)$"

OldaleTown_House2_Basement_Text_MiltankNo:
	.string "Moo... (Debug mode disabled.)$"


OldaleTown_House2_Basement_EventScript_TM_Clerk::
	lock
	faceplayer
	message OldaleTown_House2_Basement_Text_HowMayIHelpYou
	waitmessage
	setflag FLAG_FREE_SHOP
	pokemart OldaleTown_House2_Basement_Mart_TMs
	clearflag FLAG_FREE_SHOP
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_House2_Basement_Mart_TMs:
	.hword ITEM_TM_HONE_CLAWS
	.hword ITEM_TM_DRAGON_CLAW
	.hword ITEM_TM_WATER_PULSE
	.hword ITEM_TM_CALM_MIND
	.hword ITEM_TM_X_SCISSOR
	.hword ITEM_TM_SNARL
	.hword ITEM_TM_HAIL
	.hword ITEM_TM_BULK_UP
	.hword ITEM_TM_BULLET_SEED
	.hword ITEM_TM_ROCK_SLIDE
	.hword ITEM_TM_SUNNY_DAY
	.hword ITEM_TM_TAUNT
	.hword ITEM_TM_ICE_BEAM
	.hword ITEM_TM_BLIZZARD
	.hword ITEM_TM_HYPER_BEAM
	.hword ITEM_TM_LIGHT_SCREEN
	.hword ITEM_TM_PROTECT
	.hword ITEM_TM_RAIN_DANCE
	.hword ITEM_TM_GIGA_DRAIN
	.hword ITEM_TM_SAFEGUARD
	.hword ITEM_TM_DAZZLING_GLEAM
	.hword ITEM_TM_SOLAR_BEAM
	.hword ITEM_TM_IRON_TAIL
	.hword ITEM_TM_THUNDERBOLT
	.hword ITEM_TM_THUNDER
	.hword ITEM_TM_EARTHQUAKE
	.hword ITEM_TM_RETURN
	.hword ITEM_TM_DIG
	.hword ITEM_TM_PSYCHIC
	.hword ITEM_TM_SHADOW_BALL
	.hword ITEM_TM_BRICK_BREAK
	.hword ITEM_TM_DOUBLE_TEAM
	.hword ITEM_TM_REFLECT
	.hword ITEM_TM_SHOCK_WAVE
	.hword ITEM_TM_FLAMETHROWER
	.hword ITEM_TM_SLUDGE_BOMB
	.hword ITEM_TM_SANDSTORM
	.hword ITEM_TM_FIRE_BLAST
	.hword ITEM_TM_ROCK_TOMB
	.hword ITEM_TM_AERIAL_ACE
	.hword ITEM_TM_TORMENT
	.hword ITEM_TM_FACADE
	.hword ITEM_TM_SECRET_POWER
	.hword ITEM_TM_REST
	.hword ITEM_TM_ATTRACT
	.hword ITEM_TM_THIEF
	.hword ITEM_TM_STEEL_WING
	.hword ITEM_TM_SKILL_SWAP
	.hword ITEM_TM_TRICK_ROOM
	.hword ITEM_TM_OVERHEAT
	.hword ITEM_NONE

OldaleTown_House2_Basement_EventScript_MegaStone_Clerk::
	lock
	faceplayer
	message OldaleTown_House2_Basement_Text_HowMayIHelpYou
	waitmessage
	setflag FLAG_FREE_SHOP
	pokemart OldaleTown_House2_Basement_Mart_MegaStones
	clearflag FLAG_FREE_SHOP
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_House2_Basement_Mart_MegaStones:
	.hword ITEM_ABOMASITE
	.hword ITEM_AGGRONITE
	.hword ITEM_AMPHAROSITE
	.hword ITEM_BANETTITE
	.hword ITEM_BARBARACITE
	.hword ITEM_BAXCALIBRITE
	.hword ITEM_BEEDRILLITE
	.hword ITEM_BLASTOISINITE
	.hword ITEM_BLAZIKENITE
	.hword ITEM_CAMERUPTITE
	.hword ITEM_CHANDELURITE
	.hword ITEM_CHARIZARDITE_X
	.hword ITEM_CHESNAUGHTITE
	.hword ITEM_CHIMECHITE
	.hword ITEM_CLEFABLITE
	.hword ITEM_DELPHOXITE
	.hword ITEM_DRAGALGITE
	.hword ITEM_EELEKTROSSITE
	.hword ITEM_EXCADRITE
	.hword ITEM_FERALIGITE
	.hword ITEM_FROSLASSITE
	.hword ITEM_GALLADITE
	.hword ITEM_GARCHOMPITE
	.hword ITEM_GARDEVOIRITE
	.hword ITEM_GENGARITE
	.hword ITEM_GLALITITE
	.hword ITEM_GRENINJITE
	.hword ITEM_HOUNDOOMINITE
	.hword ITEM_LOPUNNITE
	.hword ITEM_LUCARIONITE
	.hword ITEM_MALAMARITE
	.hword ITEM_MANECTITE
	.hword ITEM_MAWILITE
	.hword ITEM_MEDICHAMITE
	.hword ITEM_MEOWSTICITE
	.hword ITEM_METAGROSSITE
	.hword ITEM_PYROARITE
	.hword ITEM_RAICHUNITE_X
	.hword ITEM_SABLENITE
	.hword ITEM_SALAMENCITE
	.hword ITEM_SCEPTILITE
	.hword ITEM_SCIZORITE
	.hword ITEM_SCOLIPITE
	.hword ITEM_SCRAFTINITE
	.hword ITEM_SHARPEDONITE
	.hword ITEM_STARAPTITE
	.hword ITEM_STARMINITE
	.hword ITEM_STEELIXITE
	.hword ITEM_SWAMPERTITE
	.hword ITEM_TYRANITARITE
	.hword ITEM_VENUSAURITE
	.hword ITEM_NONE

OldaleTown_House2_Basement_EventScript_Evo_Clerk::
	lock
	faceplayer
	message OldaleTown_House2_Basement_Text_HowMayIHelpYou
	waitmessage
	setflag FLAG_FREE_SHOP
	pokemart OldaleTown_House2_Basement_Mart_EvoItems
	clearflag FLAG_FREE_SHOP
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_House2_Basement_Mart_EvoItems:
	.hword ITEM_FIRE_STONE
	.hword ITEM_WATER_STONE
	.hword ITEM_THUNDER_STONE
	.hword ITEM_LEAF_STONE
	.hword ITEM_ICE_STONE
	.hword ITEM_SUN_STONE
	.hword ITEM_MOON_STONE
	.hword ITEM_SHINY_STONE
	.hword ITEM_DUSK_STONE
	.hword ITEM_DAWN_STONE
	.hword ITEM_SOOTHE_BELL
	.hword ITEM_DRAGON_SCALE
	.hword ITEM_KINGS_ROCK
	.hword ITEM_METAL_COAT
	.hword ITEM_LINKING_CORD
	.hword ITEM_ROTOM_CATALOG
	.hword ITEM_BURMY_BINDER
	.hword ITEM_NONE

OldaleTown_House2_Basement_EventScript_AbilityMint_Clerk::
	lock
	faceplayer
	message OldaleTown_House2_Basement_Text_HowMayIHelpYou
	waitmessage
	setflag FLAG_FREE_SHOP
	pokemart OldaleTown_House2_Basement_Mart_AbilitiesMints
	clearflag FLAG_FREE_SHOP
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_House2_Basement_Mart_AbilitiesMints:
	.hword ITEM_ABILITY_CAPSULE
	.hword ITEM_ABILITY_PATCH
	.hword ITEM_CHARCOAL
	.hword ITEM_MYSTIC_WATER
	.hword ITEM_MIRACLE_SEED
	.hword ITEM_SOFT_SAND
	.hword ITEM_BLACK_GLASSES
	.hword ITEM_NEVER_MELT_ICE
	.hword ITEM_LONELY_MINT
	.hword ITEM_ADAMANT_MINT
	.hword ITEM_NAUGHTY_MINT
	.hword ITEM_BRAVE_MINT
	.hword ITEM_BOLD_MINT
	.hword ITEM_IMPISH_MINT
	.hword ITEM_LAX_MINT
	.hword ITEM_RELAXED_MINT
	.hword ITEM_MODEST_MINT
	.hword ITEM_MILD_MINT
	.hword ITEM_RASH_MINT
	.hword ITEM_QUIET_MINT
	.hword ITEM_CALM_MINT
	.hword ITEM_GENTLE_MINT
	.hword ITEM_CAREFUL_MINT
	.hword ITEM_SASSY_MINT
	.hword ITEM_TIMID_MINT
	.hword ITEM_HASTY_MINT
	.hword ITEM_JOLLY_MINT
	.hword ITEM_NAIVE_MINT
	.hword ITEM_SERIOUS_MINT
	.hword ITEM_MAX_REVIVE
	.hword ITEM_NONE

OldaleTown_House2_Basement_Text_HowMayIHelpYou:
	.string "Welcome to the basement!\n"
	.string "How may I help you today?$"


OldaleTown_House2_Basement_EventScript_MoveRelearner::
	lock
	faceplayer
	msgbox OldaleTown_House2_Basement_Text_MoveRelearnerIntro, MSGBOX_DEFAULT
	goto OldaleTown_House2_Basement_EventScript_ChooseMon
	end

OldaleTown_House2_Basement_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_House2_Basement_EventScript_End
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_House2_Basement_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, OldaleTown_House2_Basement_EventScript_NoMoveToTeachMon
	goto OldaleTown_House2_Basement_EventScript_ChooseMove
	end

OldaleTown_House2_Basement_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, OldaleTown_House2_Basement_EventScript_ChooseMon
	release
	end

OldaleTown_House2_Basement_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto OldaleTown_House2_Basement_EventScript_ChooseMon
	end

OldaleTown_House2_Basement_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto OldaleTown_House2_Basement_EventScript_ChooseMon
	end

OldaleTown_House2_Basement_EventScript_End::
	release
	end

OldaleTown_House2_Basement_Text_MoveRelearnerIntro:
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.$"

OldaleTown_House2_Basement_EventScript_BossRushClerk::
	lock
	faceplayer
	message OldaleTown_House2_Basement_Text_BossRushIntro
	waitmessage
	call OldaleTown_House2_Basement_EventScript_CountBadges
	compare VAR_TEMP_0, 8
	goto_if_eq OldaleTown_House2_Basement_EventScript_Elite8Menu
	goto OldaleTown_House2_Basement_EventScript_GymLeaderMenu
	end

OldaleTown_House2_Basement_EventScript_GymLeaderMenu::
	dynmultipush OldaleTown_House2_Basement_Text_Viola, 0
	dynmultipush OldaleTown_House2_Basement_Text_Roxanne, 1
	dynmultipush OldaleTown_House2_Basement_Text_Brawly, 2
	dynmultipush OldaleTown_House2_Basement_Text_Wattson, 3
	dynmultipush OldaleTown_House2_Basement_Text_Flannery, 4
	dynmultipush OldaleTown_House2_Basement_Text_Norman, 5
	dynmultipush OldaleTown_House2_Basement_Text_Winona, 6
	dynmultipush OldaleTown_House2_Basement_Text_TateLiza, 7
	dynmultipush OldaleTown_House2_Basement_Text_JuanWallace, 8
	compare VAR_TEMP_0, 7
	call_if_eq OldaleTown_House2_Basement_EventScript_AddMaxieArchie
	dynmultipush gText_Exit, 11
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	compare VAR_RESULT, 11
	call_if_ne VAR_RESULT, 11, OldaleTown_House2_Basement_EventScript_CloseMessage
	goto_if_eq OldaleTown_House2_Basement_EventScript_End
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, OldaleTown_House2_Basement_EventScript_FightViola
	case 1, OldaleTown_House2_Basement_EventScript_FightRoxanne
	case 2, OldaleTown_House2_Basement_EventScript_FightBrawly
	case 3, OldaleTown_House2_Basement_EventScript_FightWattson
	case 4, OldaleTown_House2_Basement_EventScript_FightFlannery
	case 5, OldaleTown_House2_Basement_EventScript_FightNorman
	case 6, OldaleTown_House2_Basement_EventScript_FightWinona
	case 7, OldaleTown_House2_Basement_EventScript_FightTateLiza
	case 8, OldaleTown_House2_Basement_EventScript_FightJuanWallace
	case 9, OldaleTown_House2_Basement_EventScript_FightMaxie
	case 10, OldaleTown_House2_Basement_EventScript_FightArchie
	release
	end

OldaleTown_House2_Basement_EventScript_AddMaxieArchie::
	dynmultipush OldaleTown_House2_Basement_Text_Maxie, 9
	dynmultipush OldaleTown_House2_Basement_Text_Archie, 10
	return

OldaleTown_House2_Basement_EventScript_Elite8Menu::
	dynmultipush OldaleTown_House2_Basement_Text_Sidney, 0
	dynmultipush OldaleTown_House2_Basement_Text_Spenser, 1
	dynmultipush OldaleTown_House2_Basement_Text_Phoebe, 2
	dynmultipush OldaleTown_House2_Basement_Text_Lucy, 3
	dynmultipush OldaleTown_House2_Basement_Text_Glacia, 4
	dynmultipush OldaleTown_House2_Basement_Text_Tucker, 5
	dynmultipush OldaleTown_House2_Basement_Text_Drake, 6
	dynmultipush OldaleTown_House2_Basement_Text_Brandon, 7
	dynmultipush OldaleTown_House2_Basement_Text_Wally, 8
	dynmultipush OldaleTown_House2_Basement_Text_Steven, 9
	dynmultipush gText_Exit, 10
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	call_if_ne VAR_RESULT, 10, OldaleTown_House2_Basement_EventScript_CloseMessage
	compare VAR_RESULT, 10
	goto_if_eq OldaleTown_House2_Basement_EventScript_End
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, OldaleTown_House2_Basement_EventScript_FightSidney
	case 1, OldaleTown_House2_Basement_EventScript_FightSpenser
	case 2, OldaleTown_House2_Basement_EventScript_FightPhoebe
	case 3, OldaleTown_House2_Basement_EventScript_FightLucy
	case 4, OldaleTown_House2_Basement_EventScript_FightGlacia
	case 5, OldaleTown_House2_Basement_EventScript_FightTucker
	case 6, OldaleTown_House2_Basement_EventScript_FightDrake
	case 7, OldaleTown_House2_Basement_EventScript_FightBrandon
	case 8, OldaleTown_House2_Basement_EventScript_FightWally
	case 9, OldaleTown_House2_Basement_EventScript_FightSteven
	release
	end

OldaleTown_House2_Basement_EventScript_CloseMessage::
	closemessage
	return

@ Gym Battle Setup
OldaleTown_House2_Basement_EventScript_FightViola::
	switch VAR_TEMP_0
	case 0, OldaleTown_House2_Basement_EventScript_FightViola1
	case 1, OldaleTown_House2_Basement_EventScript_FightViola2
	case 2, OldaleTown_House2_Basement_EventScript_FightViola3
	case 3, OldaleTown_House2_Basement_EventScript_FightViola4
	case 4, OldaleTown_House2_Basement_EventScript_FightViola5
	case 5, OldaleTown_House2_Basement_EventScript_FightViola6
	case 6, OldaleTown_House2_Basement_EventScript_FightViola7
	case 7, OldaleTown_House2_Basement_EventScript_FightViola8
	end

OldaleTown_House2_Basement_EventScript_FightViola1::
	trainerbattle_no_intro TRAINER_VIOLA_1, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightViola2::
	trainerbattle_no_intro TRAINER_VIOLA_2, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightViola3::
	trainerbattle_no_intro TRAINER_VIOLA_3, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightViola4::
	trainerbattle_no_intro TRAINER_VIOLA_4, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightViola5::
	trainerbattle_no_intro TRAINER_VIOLA_5, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightViola6::
	trainerbattle_no_intro TRAINER_VIOLA_6, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightViola7::
	trainerbattle_no_intro TRAINER_VIOLA_7, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightViola8::
	trainerbattle_no_intro TRAINER_VIOLA_8, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightRoxanne::
	switch VAR_TEMP_0
	case 0, OldaleTown_House2_Basement_EventScript_FightRoxanne1
	case 1, OldaleTown_House2_Basement_EventScript_FightRoxanne2
	case 2, OldaleTown_House2_Basement_EventScript_FightRoxanne3
	case 3, OldaleTown_House2_Basement_EventScript_FightRoxanne4
	case 4, OldaleTown_House2_Basement_EventScript_FightRoxanne5
	case 5, OldaleTown_House2_Basement_EventScript_FightRoxanne6
	case 6, OldaleTown_House2_Basement_EventScript_FightRoxanne7
	case 7, OldaleTown_House2_Basement_EventScript_FightRoxanne8
	end

OldaleTown_House2_Basement_EventScript_FightRoxanne1::
	trainerbattle_no_intro TRAINER_ROXANNE_1, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightRoxanne2::
	trainerbattle_no_intro TRAINER_ROXANNE_2, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightRoxanne3::
	trainerbattle_no_intro TRAINER_ROXANNE_3, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightRoxanne4::
	trainerbattle_no_intro TRAINER_ROXANNE_4, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightRoxanne5::
	trainerbattle_no_intro TRAINER_ROXANNE_5, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightRoxanne6::
	trainerbattle_no_intro TRAINER_ROXANNE_6, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightRoxanne7::
	trainerbattle_no_intro TRAINER_ROXANNE_7, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightRoxanne8::
	trainerbattle_no_intro TRAINER_ROXANNE_8, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightBrawly::
	switch VAR_TEMP_0
	case 0, OldaleTown_House2_Basement_EventScript_FightBrawly1
	case 1, OldaleTown_House2_Basement_EventScript_FightBrawly2
	case 2, OldaleTown_House2_Basement_EventScript_FightBrawly3
	case 3, OldaleTown_House2_Basement_EventScript_FightBrawly4
	case 4, OldaleTown_House2_Basement_EventScript_FightBrawly5
	case 5, OldaleTown_House2_Basement_EventScript_FightBrawly6
	case 6, OldaleTown_House2_Basement_EventScript_FightBrawly7
	case 7, OldaleTown_House2_Basement_EventScript_FightBrawly8
	end

OldaleTown_House2_Basement_EventScript_FightBrawly1::
	trainerbattle_no_intro TRAINER_BRAWLY_1, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightBrawly2::
	trainerbattle_no_intro TRAINER_BRAWLY_2, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightBrawly3::
	trainerbattle_no_intro TRAINER_BRAWLY_3, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightBrawly4::
	trainerbattle_no_intro TRAINER_BRAWLY_4, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightBrawly5::
	trainerbattle_no_intro TRAINER_BRAWLY_5, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightBrawly6::
	trainerbattle_no_intro TRAINER_BRAWLY_6, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightBrawly7::
	trainerbattle_no_intro TRAINER_BRAWLY_7, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightBrawly8::
	trainerbattle_no_intro TRAINER_BRAWLY_8, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWattson::
	switch VAR_TEMP_0
	case 0, OldaleTown_House2_Basement_EventScript_FightWattson1
	case 1, OldaleTown_House2_Basement_EventScript_FightWattson2
	case 2, OldaleTown_House2_Basement_EventScript_FightWattson3
	case 3, OldaleTown_House2_Basement_EventScript_FightWattson4
	case 4, OldaleTown_House2_Basement_EventScript_FightWattson5
	case 5, OldaleTown_House2_Basement_EventScript_FightWattson6
	case 6, OldaleTown_House2_Basement_EventScript_FightWattson7
	case 7, OldaleTown_House2_Basement_EventScript_FightWattson8
	end

OldaleTown_House2_Basement_EventScript_FightWattson1::
	trainerbattle_no_intro TRAINER_WATTSON_1, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWattson2::
	trainerbattle_no_intro TRAINER_WATTSON_2, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWattson3::
	trainerbattle_no_intro TRAINER_WATTSON_3, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWattson4::
	trainerbattle_no_intro TRAINER_WATTSON_4, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWattson5::
	trainerbattle_no_intro TRAINER_WATTSON_5, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWattson6::
	trainerbattle_no_intro TRAINER_WATTSON_6, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWattson7::
	trainerbattle_no_intro TRAINER_WATTSON_7, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWattson8::
	trainerbattle_no_intro TRAINER_WATTSON_8, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightFlannery::
	switch VAR_TEMP_0
	case 0, OldaleTown_House2_Basement_EventScript_FightFlannery1
	case 1, OldaleTown_House2_Basement_EventScript_FightFlannery2
	case 2, OldaleTown_House2_Basement_EventScript_FightFlannery3
	case 3, OldaleTown_House2_Basement_EventScript_FightFlannery4
	case 4, OldaleTown_House2_Basement_EventScript_FightFlannery5
	case 5, OldaleTown_House2_Basement_EventScript_FightFlannery6
	case 6, OldaleTown_House2_Basement_EventScript_FightFlannery7
	case 7, OldaleTown_House2_Basement_EventScript_FightFlannery8
	end

OldaleTown_House2_Basement_EventScript_FightFlannery1::
	trainerbattle_no_intro TRAINER_FLANNERY_1, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightFlannery2::
	trainerbattle_no_intro TRAINER_FLANNERY_2, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightFlannery3::
	trainerbattle_no_intro TRAINER_FLANNERY_3, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightFlannery4::
	trainerbattle_no_intro TRAINER_FLANNERY_4, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightFlannery5::
	trainerbattle_no_intro TRAINER_FLANNERY_5, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightFlannery6::
	trainerbattle_no_intro TRAINER_FLANNERY_6, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightFlannery7::
	trainerbattle_no_intro TRAINER_FLANNERY_7, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightFlannery8::
	trainerbattle_no_intro TRAINER_FLANNERY_8, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightNorman::
	switch VAR_TEMP_0
	case 0, OldaleTown_House2_Basement_EventScript_FightNorman1
	case 1, OldaleTown_House2_Basement_EventScript_FightNorman2
	case 2, OldaleTown_House2_Basement_EventScript_FightNorman3
	case 3, OldaleTown_House2_Basement_EventScript_FightNorman4
	case 4, OldaleTown_House2_Basement_EventScript_FightNorman5
	case 5, OldaleTown_House2_Basement_EventScript_FightNorman6
	case 6, OldaleTown_House2_Basement_EventScript_FightNorman7
	case 7, OldaleTown_House2_Basement_EventScript_FightNorman8
	end

OldaleTown_House2_Basement_EventScript_FightNorman1::
	trainerbattle_no_intro TRAINER_NORMAN_1, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightNorman2::
	trainerbattle_no_intro TRAINER_NORMAN_2, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightNorman3::
	trainerbattle_no_intro TRAINER_NORMAN_3, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightNorman4::
	trainerbattle_no_intro TRAINER_NORMAN_4, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightNorman5::
	trainerbattle_no_intro TRAINER_NORMAN_5, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightNorman6::
	trainerbattle_no_intro TRAINER_NORMAN_6, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightNorman7::
	trainerbattle_no_intro TRAINER_NORMAN_7, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightNorman8::
	trainerbattle_no_intro TRAINER_NORMAN_8, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWinona::
	switch VAR_TEMP_0
	case 0, OldaleTown_House2_Basement_EventScript_FightWinona1
	case 1, OldaleTown_House2_Basement_EventScript_FightWinona2
	case 2, OldaleTown_House2_Basement_EventScript_FightWinona3
	case 3, OldaleTown_House2_Basement_EventScript_FightWinona4
	case 4, OldaleTown_House2_Basement_EventScript_FightWinona5
	case 5, OldaleTown_House2_Basement_EventScript_FightWinona6
	case 6, OldaleTown_House2_Basement_EventScript_FightWinona7
	case 7, OldaleTown_House2_Basement_EventScript_FightWinona8
	end

OldaleTown_House2_Basement_EventScript_FightWinona1::
	trainerbattle_no_intro TRAINER_WINONA_1, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWinona2::
	trainerbattle_no_intro TRAINER_WINONA_2, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWinona3::
	trainerbattle_no_intro TRAINER_WINONA_3, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWinona4::
	trainerbattle_no_intro TRAINER_WINONA_4, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWinona5::
	trainerbattle_no_intro TRAINER_WINONA_5, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWinona6::
	trainerbattle_no_intro TRAINER_WINONA_6, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWinona7::
	trainerbattle_no_intro TRAINER_WINONA_7, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightWinona8::
	trainerbattle_no_intro TRAINER_WINONA_8, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_FightTateLiza::
	switch VAR_TEMP_0
	case 0, OldaleTown_House2_Basement_EventScript_FightTateLiza1
	case 1, OldaleTown_House2_Basement_EventScript_FightTateLiza2
	case 2, OldaleTown_House2_Basement_EventScript_FightTateLiza3
	case 3, OldaleTown_House2_Basement_EventScript_FightTateLiza4
	case 4, OldaleTown_House2_Basement_EventScript_FightTateLiza5
	case 5, OldaleTown_House2_Basement_EventScript_FightTateLiza6
	case 6, OldaleTown_House2_Basement_EventScript_FightTateLiza7
	case 7, OldaleTown_House2_Basement_EventScript_FightTateLiza8
	end

OldaleTown_House2_Basement_EventScript_FightTateLiza1::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightTateLiza2::
	trainerbattle_double TRAINER_TATE_AND_LIZA_2, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightTateLiza3::
	trainerbattle_double TRAINER_TATE_AND_LIZA_3, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightTateLiza4::
	trainerbattle_double TRAINER_TATE_AND_LIZA_4, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightTateLiza5::
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightTateLiza6::
	trainerbattle_double TRAINER_TATE_AND_LIZA_6, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightTateLiza7::
	trainerbattle_double TRAINER_TATE_AND_LIZA_7, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightTateLiza8::
	trainerbattle_double TRAINER_TATE_AND_LIZA_8, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightJuanWallace::
	switch VAR_TEMP_0
	case 0, OldaleTown_House2_Basement_EventScript_FightJuanWallace1
	case 1, OldaleTown_House2_Basement_EventScript_FightJuanWallace2
	case 2, OldaleTown_House2_Basement_EventScript_FightJuanWallace3
	case 3, OldaleTown_House2_Basement_EventScript_FightJuanWallace4
	case 4, OldaleTown_House2_Basement_EventScript_FightJuanWallace5
	case 5, OldaleTown_House2_Basement_EventScript_FightJuanWallace6
	case 6, OldaleTown_House2_Basement_EventScript_FightJuanWallace7
	case 7, OldaleTown_House2_Basement_EventScript_FightJuanWallace8
	end

OldaleTown_House2_Basement_EventScript_FightJuanWallace1::
	trainerbattle_double TRAINER_JUAN_1, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightJuanWallace2::
	trainerbattle_double TRAINER_JUAN_2, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightJuanWallace3::
	trainerbattle_double TRAINER_JUAN_3, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightJuanWallace4::
	trainerbattle_double TRAINER_JUAN_4, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightJuanWallace5::
	trainerbattle_double TRAINER_JUAN_5, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightJuanWallace6::
	trainerbattle_double TRAINER_JUAN_6, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightJuanWallace7::
	trainerbattle_double TRAINER_JUAN_7, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

OldaleTown_House2_Basement_EventScript_FightJuanWallace8::
	trainerbattle_double TRAINER_JUAN_8, NULL, OldaleTown_House2_Basement_Text_TrainerDefeated, OldaleTown_House2_Basement_Text_NotEnoughMons
	release
	end

@ Elite 8 and Specials (No version scaling requested for these)
OldaleTown_House2_Basement_EventScript_FightMaxie::
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightArchie::
	trainerbattle_no_intro TRAINER_ARCHIE, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightSidney::
	trainerbattle_no_intro TRAINER_SIDNEY, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightSpenser::
	trainerbattle_no_intro TRAINER_SPENSER, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightPhoebe::
	trainerbattle_no_intro TRAINER_PHOEBE, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightLucy::
	trainerbattle_no_intro TRAINER_LUCY, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightGlacia::
	trainerbattle_no_intro TRAINER_GLACIA, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightTucker::
	trainerbattle_no_intro TRAINER_TUCKER, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightDrake::
	trainerbattle_no_intro TRAINER_DRAKE, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightBrandon::
	trainerbattle_no_intro TRAINER_BRANDON, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightWally::
	trainerbattle_no_intro TRAINER_WALLY, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end
OldaleTown_House2_Basement_EventScript_FightSteven::
	trainerbattle_no_intro TRAINER_STEVEN, OldaleTown_House2_Basement_Text_TrainerDefeated
	release
	end

OldaleTown_House2_Basement_EventScript_CountBadges::
	setvar VAR_TEMP_0, 0
	checkflag FLAG_BADGE01_GET
	call_if_eq VAR_RESULT, TRUE, OldaleTown_House2_Basement_EventScript_IncrementBadges
	checkflag FLAG_BADGE02_GET
	call_if_eq VAR_RESULT, TRUE, OldaleTown_House2_Basement_EventScript_IncrementBadges
	checkflag FLAG_BADGE03_GET
	call_if_eq VAR_RESULT, TRUE, OldaleTown_House2_Basement_EventScript_IncrementBadges
	checkflag FLAG_BADGE04_GET
	call_if_eq VAR_RESULT, TRUE, OldaleTown_House2_Basement_EventScript_IncrementBadges
	checkflag FLAG_BADGE05_GET
	call_if_eq VAR_RESULT, TRUE, OldaleTown_House2_Basement_EventScript_IncrementBadges
	checkflag FLAG_BADGE06_GET
	call_if_eq VAR_RESULT, TRUE, OldaleTown_House2_Basement_EventScript_IncrementBadges
	checkflag FLAG_BADGE07_GET
	call_if_eq VAR_RESULT, TRUE, OldaleTown_House2_Basement_EventScript_IncrementBadges
	checkflag FLAG_BADGE08_GET
	call_if_eq VAR_RESULT, TRUE, OldaleTown_House2_Basement_EventScript_IncrementBadges
	return

OldaleTown_House2_Basement_EventScript_IncrementBadges::
	addvar VAR_TEMP_0, 1
	return

OldaleTown_House2_Basement_Text_BossRushIntro:
	.string "I can summon strong projections of\n"
	.string "trainers for you to battle.\p"
	.string "Who would you like to fight?$"

OldaleTown_House2_Basement_Text_TrainerDefeated:
	.string "An impressive display of strength.$"

OldaleTown_House2_Basement_Text_NotEnoughMons:
	.string "You need more than one Pokémon for\n"
	.string "a double battle!$"

OldaleTown_House2_Basement_Text_Viola: .string "VIOLA$"
OldaleTown_House2_Basement_Text_Roxanne: .string "ROXANNE$"
OldaleTown_House2_Basement_Text_Brawly: .string "BRAWLY$"
OldaleTown_House2_Basement_Text_Wattson: .string "WATTSON$"
OldaleTown_House2_Basement_Text_Flannery: .string "FLANNERY$"
OldaleTown_House2_Basement_Text_Norman: .string "NORMAN$"
OldaleTown_House2_Basement_Text_Winona: .string "WINONA$"
OldaleTown_House2_Basement_Text_TateLiza: .string "TATE AND LIZA$"
OldaleTown_House2_Basement_Text_JuanWallace: .string "JUAN AND WALLACE$"
OldaleTown_House2_Basement_Text_Maxie: .string "MAXIE$"
OldaleTown_House2_Basement_Text_Archie: .string "ARCHIE$"
OldaleTown_House2_Basement_Text_Sidney: .string "SIDNEY$"
OldaleTown_House2_Basement_Text_Spenser: .string "SPENSER$"
OldaleTown_House2_Basement_Text_Phoebe: .string "PHOEBE$"
OldaleTown_House2_Basement_Text_Lucy: .string "LUCY$"
OldaleTown_House2_Basement_Text_Glacia: .string "GLACIA$"
OldaleTown_House2_Basement_Text_Tucker: .string "TUCKER$"
OldaleTown_House2_Basement_Text_Drake: .string "DRAKE$"
OldaleTown_House2_Basement_Text_Brandon: .string "BRANDON$"
OldaleTown_House2_Basement_Text_Wally: .string "WALLY$"
OldaleTown_House2_Basement_Text_Steven: .string "STEVEN$"