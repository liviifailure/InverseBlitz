EventScript_ChooseGiftPokemon_Basement::
	msgbox Text_PeeredIntoBox, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	hideplayer
	hidefollower
	hideobjectat LOCALID_BOX_2, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	hideobjectat LOCALID_BOX_1, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	hideobjectat LOCALID_HIDDEN_POWER_NPC, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	// Free object event sprite palettes before opening the gift menu.
	special ReleaseObjectEventSpritePalettes
	fadescreen FADE_FROM_BLACK
	goto EventScript_ChooseGiftPokemon_NoMsg


EventScript_ChooseGiftPokemon2_Basement::
	msgbox Text_PeeredIntoBox, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	closemessage
	hideplayer
	hidefollower
	hideobjectat LOCALID_BOX_2, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	hideobjectat LOCALID_BOX_1, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	hideobjectat LOCALID_HIDDEN_POWER_NPC, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	// Free object event sprite palettes before opening the gift menu.
	special ReleaseObjectEventSpritePalettes
	fadescreen FADE_FROM_BLACK
	goto EventScript_ChooseGiftPokemon2_NoMsg

EventScript_ChooseGiftPokemon::
	faceplayer
	msgbox Text_ChooseAGiftPokemon, MSGBOX_DEFAULT
	closemessage
EventScript_ChooseGiftPokemon_NoMsg::
	special BuildGiftPokemonMenu
	special SetIsGiftPokemonMenu
	// This custom command from your original script displays the dynamic multichoice menu.
	// The max items shown before scrolling is set to 8 to fit on the screen.
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, NULL
EventScript_EndGiftPokemon::
	showplayer
	updatefollowingmon
	showobjectat LOCALID_BOX_2, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	showobjectat LOCALID_BOX_1, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	showobjectat LOCALID_HIDDEN_POWER_NPC, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	return

EventScript_ChooseGiftPokemon2_NoMsg::
	special BuildGiftPokemonMenu2
	special SetIsGiftPokemonMenu
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, NULL
	showplayer
	updatefollowingmon
	showobjectat LOCALID_BOX_2, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	showobjectat LOCALID_BOX_1, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	showobjectat LOCALID_HIDDEN_POWER_NPC, MAP_OLDALE_TOWN_HOUSE2_BASEMENT
	return

Text_ChooseAGiftPokemon:
	.string "{PLAYER} checked their notes…\n"
	.string "Let's see which POKéMON they drafted!$"

gText_ReceivedGiftMon::
	.string "{PLAYER} received a {STR_VAR_1}!$"

Text_PeeredIntoBox:
	.string "{PLAYER} peered into the box…\n"
	.string "It's full of POKéMON!$"
