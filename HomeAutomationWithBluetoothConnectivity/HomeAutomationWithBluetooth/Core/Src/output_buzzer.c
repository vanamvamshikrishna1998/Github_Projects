/*
 * control_buzzer.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */
#include "output_buzzer.h"

void Control_Buzzer(uint32_t gas){
	if(gas>200){
		HAL_GPIO_WritePin(Sensor_Buzzer_Out_GPIO_Port, Sensor_Buzzer_Out_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(Sensor_Buzzer_Out_GPIO_Port, Sensor_Buzzer_Out_Pin, GPIO_PIN_RESET);

	}

}
