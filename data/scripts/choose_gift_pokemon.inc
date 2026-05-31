EventScript_ChooseGiftPokemon_Basement::
	msgbox Text_PeeredIntoBox, MSGBOX_DEFAULT
	closemessage
	goto EventScript_ChooseGiftPokemon_NoMsg

EventScript_ChooseGiftPokemon2_Basement::
	msgbox Text_PeeredIntoBox, MSGBOX_DEFAULT
	goto EventScript_ChooseGiftPokemon2_NoMsg

EventScript_ChooseGiftPokemon::
	faceplayer
	msgbox Text_ChooseAGiftPokemon, MSGBOX_DEFAULT
EventScript_ChooseGiftPokemon_NoMsg::
	closemessage
	special BuildGiftPokemonMenu
	special SetIsGiftPokemonMenu
	// This custom command from your original script displays the dynamic multichoice menu.
	// The max items shown before scrolling is set to 8 to fit on the screen.
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, NULL
EventScript_EndGiftPokemon::
	return

EventScript_ChooseGiftPokemon2_NoMsg::
	closemessage
	special BuildGiftPokemonMenu2
	special SetIsGiftPokemonMenu
	dynmultistack 0, 0, FALSE, 8, FALSE, 0, NULL
	return

Text_ChooseAGiftPokemon:
	.string "{PLAYER} checked their notes…\n"
	.string "Let's see which POKéMON they drafted!$"

gText_ReceivedGiftMon::
	.string "{PLAYER} received a {STR_VAR_1}!$"

Text_PeeredIntoBox:
	.string "{PLAYER} peered into the box…\n"
	.string "It's full of POKéMON!$"
