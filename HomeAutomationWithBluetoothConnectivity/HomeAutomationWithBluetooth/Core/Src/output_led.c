/*
 * output_led.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */


#include "output_led.h"

void Control_Led(int state){
	if(state == 1){
		HAL_GPIO_WritePin(Sensor_Ir_In_GPIO_Port, Sensor_Ir_In_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(Sensor_Ir_In_GPIO_Port, Sensor_Ir_In_Pin, GPIO_PIN_RESET);
	}
}
