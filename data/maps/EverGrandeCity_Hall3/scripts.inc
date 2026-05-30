EverGrandeCity_Hall3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_Hall3_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall3_OnWarp
	.byte 0

EverGrandeCity_Hall3_OnTransition:
	random 2
	copyvar VAR_TEMP_0, VAR_RESULT
	goto_if_eq VAR_TEMP_0, 0, EverGrandeCity_Hall3_EventScript_SetDrake
	setdynamicwarp MAP_EVER_GRANDE_CITY_BRANDONS_ROOM, 255, 6, 13
	end

EverGrandeCity_Hall3_EventScript_SetDrake:
	setdynamicwarp MAP_EVER_GRANDE_CITY_DRAKES_ROOM, 255, 6, 13
	end

EverGrandeCity_Hall3_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall3_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall3_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end
