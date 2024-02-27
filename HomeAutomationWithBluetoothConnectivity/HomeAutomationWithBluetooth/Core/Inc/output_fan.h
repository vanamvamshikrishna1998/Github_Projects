/*
 * output_fan.h
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */

#ifndef INC_OUTPUT_FAN_H_
#define INC_OUTPUT_FAN_H_

#include "main.h"
#include "sensor_dht.h"
#include "stm32f4xx_hal.h"

void Control_Fan(DHT_Data dht_data, TIM_HandleTypeDef htim3);


#endif /* INC_OUTPUT_FAN_H_ */
