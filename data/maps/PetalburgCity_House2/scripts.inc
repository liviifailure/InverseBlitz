PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	lock
	faceplayer
	msgbox PetalburgCity_House2_Text_DebugModePrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_House2_EventScript_EnableDebugMode
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_DEFAULT
	release
	end

PetalburgCity_House2_EventScript_EnableDebugMode::
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setvar VAR_BADGE_COUNT, 8
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	release
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN became our town's new\n"
	.string "GYM LEADER.\p"
	.string "I think he called his family over from\n"
	.string "somewhere far away.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "I battled NORMAN once, but, whew,\n"
	.string "he was way too strong.\p"
	.string "How would I put it?\p"
	.string "I just got the feeling that he\n"
	.string "lives for POKéMON.$"

PetalburgCity_House2_Text_DebugModePrompt:
	.string "Turn on debug mode? This will end your\n"
	.string "run, but allow you to test for bugs\l"
	.string "quickly.$"
