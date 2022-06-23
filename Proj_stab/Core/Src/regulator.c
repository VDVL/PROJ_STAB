/*
 * regulator.c
 *
 *  Created on: 21 juin 2022
 *      Author: be06
 */

#include "regulator.h"
#include <stdlib.h>
#include "main.h"

REGULATOR_commands 		commands;
REGULATOR_P_controls 	P_param;
REGULATOR_PI_controls 	PI_param;
REGULATOR_PID_controls 	PID_param;

void Init_PID(void){
	PID_param.last_error =0;
}

/* This function apply proportionnal control:
 * */
void Proportional(void){
	//Compute P control  (commande = Kp * erreur)
	P_param.error = Regulator_inputs.consigne - Regulator_inputs.mesure;								//Compute error
	P_param.command = Kp * P_param.error;							//Compute P command

	//Invert command because control with a period, not a speed
	if(P_param.command ==0){										//Cannot be divided by zero (if completly stable)
		P_param.period = max_period;
	}
	else{
		P_param.period = (1/P_param.command) ;						//invert command give period
	}

	//Check for MIN and MAX period exceeding
	if(abs(P_param.period)<min_period){
		P_param.period =min_period;
	}
	else if(abs(P_param.period) >max_period){
		P_param.period =max_period;
	}

	//Take absolute value of period
	commands.speed_period = (uint32_t) abs(P_param.period);

	//Give direction of motor
	if(P_param.error >0){
		commands.speed_direction =1; 								//0 = Counter Clockwise
	}
	else{
		commands.speed_direction =0;								//1 = Clockwise
	}

	//Copy values to global var
	comand_speed_period = commands.speed_period;
	command_direction = commands.speed_direction;
}



void PI(void){
	//Compute PI control  (commande =  Kp * erreur + Ki * somme_erreurs)
	PI_param.error = Regulator_inputs.consigne - Regulator_inputs.mesure ;								//Compute error
	PI_param.error_sum += PI_param.error;
	PI_param.command = Kp * PI_param.error + Ki * PI_param.error_sum;									//Compute PI command

	//Invert command because control with a period, not a speed
	if(PI_param.command ==0){										//Cannot be divided by zero (if completly stable)
		PI_param.period = max_period;
	}
	else{
		PI_param.period = (1/PI_param.command) ;						//invert command give period
	}

	//Check for MIN and MAX period exceeding
	if(abs(PI_param.period)<min_period){
		PI_param.period =min_period;
	}
	else if(abs(PI_param.period) >max_period){
		PI_param.period =max_period;
	}

	//Take absolute value of period
	commands.speed_period = (uint32_t) abs(PI_param.period);

	//Give direction of motor
	if(PI_param.error >0){
		commands.speed_direction =1; 								//0 = Counter Clockwise
	}
	else{
		commands.speed_direction =0;								//1 = Clockwise
	}

	//Copy values to global var
	comand_speed_period = commands.speed_period;
	command_direction = commands.speed_direction;
}




void PID(void){
	//Compute PID control (commande = Kp * erreur + Ki * somme_erreurs + Kd * (erreur - erreur_précédente)
	PID_param.error = Regulator_inputs.consigne - Regulator_inputs.mesure ;								//Compute error
	PID_param.error_sum += PID_param.error;
	PID_param.error_variation = PID_param.error - PID_param.last_error;
	PID_param.command = Kp * PID_param.error + Ki * PID_param.error_sum + Kd * PID_param.error_variation;									//Compute PID command
	PID_param.last_error = PID_param.error;

	//Invert command because control with a period, not a speed
	if(PID_param.command ==0){										//Cannot be divided by zero (if completly stable)
		PID_param.period = max_period;
	}
	else{
		PID_param.period = (1/PID_param.command) ;						//invert command give period
	}

	//Check for MIN and MAX period exceeding
	if(abs(PID_param.period)<min_period){
		PID_param.period =min_period;
	}
	else if(abs(PID_param.period) >max_period){
		PID_param.period =max_period;
	}

	//Take absolute value of period
	commands.speed_period = (uint32_t) abs(PID_param.period);

	//Give direction of motor
	if(PID_param.command >0){
		commands.speed_direction =1; 								//0 = Counter Clockwise
	}
	else{
		commands.speed_direction =0;								//1 = Clockwise
	}

	//Copy values to global var
	comand_speed_period = commands.speed_period;
	command_direction = commands.speed_direction;
}

