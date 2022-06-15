/*
 * drv8311.c
 *
 *  Created on: 2 mai 2022
 *      Author: be06
 */
#include "main.h"
#include <string.h>
#include <stdio.h>
#include "drv8311.h"
#include "pwm_driver.h"



void DRV_Init(void){
	//Init CS pin should default high
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(nSleep_GPIO_Port, nSleep_Pin, GPIO_PIN_SET);
	HAL_Delay(1);

	//Set PWM freq (reset = 0x0000 )
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x00;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_PERIOD <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0xFF;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	//Read settings_____________________________________________________________
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x80;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_PERIOD <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);

	//Set PWM duty_cycle A   (reset = 0x0000 )
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x00;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_A_DUTY <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	//Read settings_____________________________________________________________
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x80;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_A_DUTY <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);

	//Set PWM duty_cycle B  (reset = 0x0000 )
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x00;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_B_DUTY <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	//Read settings_____________________________________________________________
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x80;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_B_DUTY <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);

	//Set PWM duty_cycle C (reset = 0x0000 )
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x00 ;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_C_DUTY <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	//Read settings_____________________________________________________________
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x80;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_C_DUTY <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);

	/*//insert deadtime (avoid pic current)
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x00 | 0x01;               					//cmd
	buf_SPI_TX[1] = 0x00 | (0x02<<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00 | 0x01<<4;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	//Read settings_____________________________________________________________
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x80 | 0x01;               					//cmd
	buf_SPI_TX[1] = 0x00 | (0x02<<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	HAL_Delay(1);*/


	//counter mode
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x00;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_CTRL <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00 | (0x01);						//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	//Read settings_____________________________________________________________
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x80;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_CTRL <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);

	//pwm state
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x00;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWM_STATE <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x07;						//data (si read osf)
	buf_SPI_TX[3] = 0x77;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	//Read settings_____________________________________________________________
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x80;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWM_STATE <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);


	//Enable PWM Generation  (reset = 0x0000 ) + synchro
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x00;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_CTRL <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00 | (0x01<<2);						//data (si read osf)
	buf_SPI_TX[3] = 0x00 | (0x05<<5);									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);
	//Read settings_____________________________________________________________
	//fill TX buffer for SPI--------------------------------------------
	buf_SPI_TX[0] = 0x80;               					//cmd
	buf_SPI_TX[1] = 0x00 | (DRV8311_REG_PWMG_CTRL <<3);  	//reg adr + cmd
	buf_SPI_TX[2] = 0x00;									//data (si read osf)
	buf_SPI_TX[3] = 0x00;									//data (si read osf)
	//Send/Read Datas---------------------------------------------------
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)buf_SPI_TX, (uint8_t *)buf_SPI_RX, 4, HAL_MAX_DELAY);  //trame de 32bits=4octets
	HAL_GPIO_WritePin(SPI2_SS_GPIO_Port, SPI2_SS_Pin, GPIO_PIN_SET);

}
