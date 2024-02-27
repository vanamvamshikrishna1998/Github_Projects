/*
 * sensor_dht.h
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */

#ifndef INC_SENSOR_DHT_H_
#define INC_SENSOR_DHT_H_

#include "main.h"
#include "stm32f4xx_hal.h"

typedef struct{
	int temperature;
	int humidity;
}DHT_Data;

void Read_DHTSensor(DHT_Data *dht_data, TIM_HandleTypeDef htim3);
HAL_StatusTypeDef  Get_DHTSensor(TIM_HandleTypeDef htim3);

#endif /* INC_SENSOR_DHT_H_ */
