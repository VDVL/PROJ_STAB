/*
 * pwm_driver.c
 *
 *  Created on: 10 mai 2022
 *      Author: be06
 */


#include "pwm_driver.h"
#include "main.h"
#include "drv8311.h"
#include "stm32l4xx_hal.h"

unsigned int cpt_pwm = 0;
unsigned int cpt_deg = 0;

uint8_t phase_A[] = {val_phase_A};
uint8_t phase_B[] = {val_phase_B};
uint8_t phase_C[] = {val_phase_C};


#define pas_deg sizeof phase_A / sizeof phase_A[0]

void pwm_sine(void)
{
	if(cpt_pwm >= 10)   				//correspond to 2800us (28*100us)
	{
		cpt_pwm =0;//reset

		//Set PWM duty_cycle A   (reset = 0x0000 )
		//fill TX buffer for SPI--------------------------------------------
		buf_SPI_TX[0] = 0x00;               					//cmd
		buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_A_DUTY <<3);  	//reg adr + cmd
		buf_SPI_TX[2] = 0x00;				//data (si read osf)
		buf_SPI_TX[3] = phase_A[cpt_deg];									//data (si read osf)
		//Send/Read Datas---------------------------------------------------
		HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
		HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
		//Set PWM duty_cycle B   (reset = 0x0000 )
		//fill TX buffer for SPI--------------------------------------------
		buf_SPI_TX[0] = 0x00;               					//cmd
		buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_B_DUTY <<3);  	//reg adr + cmd
		buf_SPI_TX[2] = 0x00;				//data (si read osf)
		buf_SPI_TX[3] = phase_B[cpt_deg];									//data (si read osf)
		//Send/Read Datas---------------------------------------------------
		HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
		HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);

		//Set PWM duty_cycle C   (reset = 0x0000 )
		//fill TX buffer for SPI--------------------------------------------
		buf_SPI_TX[0] = 0x00;               					//cmd
		buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_C_DUTY <<3);  	//reg adr + cmd
		buf_SPI_TX[2] = 0x00;				//data (si read osf)
		buf_SPI_TX[3] = phase_C[cpt_deg];									//data (si read osf)
		//Send/Read Datas---------------------------------------------------
		HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
		HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);


		//if button not pressed: clockwise else counter clockwise
		if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 1)
		{
			//clockwise direction
			if(cpt_deg>=pas_deg-1)			//360°
			{
				cpt_deg =0;					//reset cpt °
			}
			else
			{
				cpt_deg++;					//+1°
			}
		}
		else
		{

			/*
			//counter clockwise
			if(cpt_deg<=0)					//0°
			{
				cpt_deg = pas_deg-1;		//reset cpt °
			}
			else
			{
				cpt_deg--;					//-1°
			}*/

		}
	}
	else
	{
		cpt_pwm++;
	}
	//HAL_GPIO_TogglePin(PWM_timer_GPIO_Port, PWM_timer_Pin);
}

