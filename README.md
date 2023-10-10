# Include_zWater_Samp

Sorry for my English, I'm not fluent or an expert

PT/BR 🇧🇷
e quem disse qua pinguim não voa

Functions

IsPlayerInWater(playerid)
// Returns whether the player is in the water or not.

GetPlayerNivelWater(playerid)

this function returns 3 values.
 
// 1 - return if the player is swimming or sailing in a boat.

// 2 - return if the player is diving to the bottom of the sea.

//0 - return if the player is not in the water.

IsVehicleInWater(vehicleid)
//returns if the vehicle is in water.


This callback will be called when the player enters the water, or when the player is in the water

public OnPlayerEnterWater(playerid)
{
  return 1;
}
