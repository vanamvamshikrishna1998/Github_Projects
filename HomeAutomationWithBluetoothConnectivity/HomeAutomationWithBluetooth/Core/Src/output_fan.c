/*
 * output_fan.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */


#include "output_fan.h"

int temp;

void Control_Fan(DHT_Data dht_data, TIM_HandleTypeDef htim3){
	temp= dht_data.temperature;
	TIM3->CCR1 = temp * 20;
	if(temp>50){
		TIM3->CCR1 = 1000;
	}
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}
