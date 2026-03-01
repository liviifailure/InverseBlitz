EverGrandeCity_Hall5_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall5_OnWarp
	.byte 0

EverGrandeCity_Hall5_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall5_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall5_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	clearflag FLAG_BOSS_FLIP  @ This shouldn't be necessary since it should be impossible for this flag to be set. That said, it seems it is somehow possible…
	special SwapRegisteredKit
	end

