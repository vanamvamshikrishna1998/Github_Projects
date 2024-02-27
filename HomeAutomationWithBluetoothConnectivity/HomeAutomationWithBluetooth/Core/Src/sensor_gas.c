/*
 * sensor_gas.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */

#include "sensor_gas.h"

void Read_GasSensor(uint32_t *gas,ADC_HandleTypeDef hadc1){
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);
	gas = HAL_ADC_GetValue(&hadc1);
}
