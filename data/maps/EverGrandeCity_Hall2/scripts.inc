EverGrandeCity_Hall2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_Hall2_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall2_OnWarp
	.byte 0

EverGrandeCity_Hall2_OnTransition:
	random 2
	copyvar VAR_TEMP_0, VAR_RESULT
	goto_if_eq VAR_TEMP_0, 0, EverGrandeCity_Hall2_EventScript_SetGlacia
	setdynamicwarp MAP_EVER_GRANDE_CITY_TUCKERS_ROOM, 255, 6, 13
	end

EverGrandeCity_Hall2_EventScript_SetGlacia:
	setdynamicwarp MAP_EVER_GRANDE_CITY_GLACIAS_ROOM, 255, 6, 13
	end

EverGrandeCity_Hall2_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall2_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall2_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end
