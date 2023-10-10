#include <a_samp>

#if defined _INC_zWater
	#endinput
#endif
#define _INC_zWater
#define zwater_included

/*

|	     by: Rzn                |
|       Discord: int_rzn       |
|       Version: 0.2           |
|       Não Retire os Créditos |

*/

/******************************************************************************

Copyright © RZN. Todos os direitos reservados.

Redistribuição e uso em formato de código-fonte e binário, com ou sem
modificações, são permitidos, desde que as seguintes condições sejam cumpridas:

1. As redistribuições do código devem manter este aviso de direitos autorais
   intacto e visível.

2. Não é permitido o uso deste código para fins comerciais, incluindo, mas não
   se limitando a, vendas de produtos ou serviços que utilizem este código.

3. Qualquer redistribuição ou uso do código que modifique este software de forma
   a torná-lo irreconhecível em relação à versão original deve incluir uma
   declaração clara de que as modificações foram feitas, juntamente com a data
   das modificações.

eu não me responsabilizo por qualquer uso indevido
ou danos decorrentes do uso deste software.

Este software é fornecido "no estado em que se encontra", sem garantias de
qualquer tipo, expressas ou implícitas, incluindo, mas não se limitando a,
garantias de comercialização, adequação a um propósito específico e não
violação.

******************************************************************************/

#define CHECK_WATER_INTERVAL 5000

#define LoopWater()  SetTimer("CheckWater", CHECK_WATER_INTERVAL, 1)


forward OnPlayerEnterWater(playerid);

stock IsPlayerInWater(playerid) {
   if (IsPlayerConnected(playerid) ) {
      new Float:PosPlayer[3];
      GetPlayerPos(playerid, PosPlayer[0], PosPlayer[1], PosPlayer[2]);
      if (PosPlayer[2] <= 0.0) {
         return true;
      }else{
         return false;
      }
   }
   return false; 
}

stock GetPlayerNivelWater(playerid) {
   if (IsPlayerConnected(playerid)) {
         new Float:x, Float:y, Float:z;
         GetPlayerPos(playerid, x, y, z);
         if(z <= 0.0 && z > -4.0) {
            return 1; 
         } else if(z <= -3.9) {
            return 2;
         } else {
            return 0;
         }
   }
   return 0;
}

forward CheckWater();
public CheckWater()
{
	for(new i=0;i<MAX_PLAYERS;i++)
	{
		if(IsPlayerConnected(i))
		{
			if(IsPlayerInWater(i) == 1)
			{
				CallRemoteFunction("OnPlayerEnterWater", "d", i);
			}
		}
	}
	return 1;
}

stock IsVehicleInWater(vehicleid) 
{
   if(IsValidVehicle(vehicleid))
   {
      new Float:PosVeh[3];
      GetVehiclePos(vehicleid, PosVeh[0], PosVeh[1], PosVeh[2]);
      if(PosVeh[2] <= 0.0){
         return true;
      }else{
         return false;
      }
   }
   return false;
}

