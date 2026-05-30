EverGrandeCity_Hall1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_Hall1_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall1_OnWarp
	.byte 0

EverGrandeCity_Hall1_OnTransition:
	random 2
	copyvar VAR_TEMP_0, VAR_RESULT
	goto_if_eq VAR_TEMP_0, 0, EverGrandeCity_Hall1_EventScript_SetPhoebe
	setdynamicwarp MAP_EVER_GRANDE_CITY_LUCYS_ROOM, 255, 6, 13
	end

EverGrandeCity_Hall1_EventScript_SetPhoebe:
	setdynamicwarp MAP_EVER_GRANDE_CITY_PHOEBES_ROOM, 255, 6, 13
	end

EverGrandeCity_Hall1_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall1_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall1_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end
