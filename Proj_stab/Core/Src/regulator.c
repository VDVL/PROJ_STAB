/*
 * regulator.c
 *
 *  Created on: 21 juin 2022
 *      Author: be06
 */

#include "regulator.h"
#include <stdlib.h>
#include "main.h"


float error = 0;
float periode = 0;
float command =0;

REGULATOR_commands Proportional(float mesure){

	REGULATOR_commands commands;

	if(Flag_compute_PID == 1){
		Flag_compute_PID =0;

		error = setpoint - mesure;
		command = Kp * error;

		if(command ==0){
			periode = 1000000;
		}
		else{
			periode = (1/command) ;
		}


		//cannot be less than 1 or more than 1000000
		if(abs(periode)<8){
			periode =8;
		}
		else if(abs(periode) >1000000){
			periode =1000000;
		}

		commands.speed_periode = (uint32_t) abs(periode);

		if(error >0){
			commands.speed_direction =0;
		}
		else{
			commands.speed_direction =1;
		}


		//STOP Motor when 0.0° deg
		/*if(mesure<=0.1 && mesure >= -0.1)
		{
			commands.speed_direction =2;
		}*/

		return commands;
	}


}
