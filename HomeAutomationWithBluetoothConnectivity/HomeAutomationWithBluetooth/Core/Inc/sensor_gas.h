/*
 * sensor_gas.h
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */

#ifndef INC_SENSOR_GAS_H_
#define INC_SENSOR_GAS_H_

#include "main.h"

//uint32_t gas;

void Read_GasSensor(uint32_t *gas,ADC_HandleTypeDef hadc1);

#endif /* INC_SENSOR_GAS_H_ */
