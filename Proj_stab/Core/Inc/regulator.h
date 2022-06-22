/*
 * regulator.h
 *
 *  Created on: 21 juin 2022
 *      Author: be06
 */

#ifndef INC_REGULATOR_H_
#define INC_REGULATOR_H_

#include <stdio.h>


#define setpoint 	0
#define Kp			0.008


typedef struct
{
	uint32_t speed_periode;
	uint32_t speed_direction;
} REGULATOR_commands;



REGULATOR_commands Proportional(float);



#endif /* INC_REGULATOR_H_ */
