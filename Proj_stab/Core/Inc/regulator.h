/*
 * regulator.h
 *
 *  Created on: 21 juin 2022
 *      Author: be06
 */

#ifndef INC_REGULATOR_H_
#define INC_REGULATOR_H_

#include <stdio.h>


#define max_period		100000000000
#define min_period		2

#define Kp			0.03  //0.04
#define Ki 			0.0000001
#define Kd			0.001




typedef struct
{
	uint32_t speed_period;
	uint32_t speed_direction;
}REGULATOR_commands;

typedef struct
{
	float mesure;
	float consigne;
}REGULATOR_inputs;


typedef struct
{
	float error;
	float command;
	float period;
}REGULATOR_P_controls;


typedef struct
{
	float error;
	float error_sum;
	float command;
	float period;
}REGULATOR_PI_controls;


typedef struct
{
	float error;
	float error_sum;
	float last_error;
	float command;
	float error_variation;
	float period;
}REGULATOR_PID_controls;



void Proportional(void);
void PI(void);
void PID(void);

#endif /* INC_REGULATOR_H_ */
