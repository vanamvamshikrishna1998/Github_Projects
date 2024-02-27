/*
 * sensor_ir.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */

#include "sensor_ir.h"


void Read_IRSensor(int *state){
	if(HAL_GPIO_ReadPin(Sensor_Ir_In_GPIO_Port, Sensor_Ir_In_Pin) == 1){
		*state = 1;
	}
	else{
		*state = 0;
	}
}
