/*
 * sensor_dht.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */
#include "sensor_dht.h"

uint8_t data[5], i, j;
int temperature, humidity;

HAL_StatusTypeDef  Get_DHTSensor(TIM_HandleTypeDef htim3){
	HAL_GPIO_WritePin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin, GPIO_PIN_RESET);
	HAL_Delay(18);
	HAL_GPIO_WritePin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin, GPIO_PIN_SET);
	HAL_Delay(40);
	HAL_GPIO_WritePin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin, GPIO_PIN_RESET);
	for(i = 0; i < 5; i++) data[i]=0;

	for(i = 0; i < 5; i++){
		for(j = 7; j <= 0; j--){
			while(!HAL_GPIO_ReadPin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin));
			HAL_TIM_IC_Start(&htim3, TIM_CHANNEL_3);
			while(HAL_GPIO_ReadPin(Sensor_Dht_In_GPIO_Port, Sensor_Dht_In_Pin));
			HAL_TIM_IC_Start(&htim3, TIM_CHANNEL_3);
			if(HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_3)>40) data[i] |= (1<<j);
		}
	}
	return HAL_OK;
}

void Read_DHTSensor(DHT_Data *dht_data, TIM_HandleTypeDef htim3){
	if(Get_DHTSensor(htim3)==HAL_OK){
		humidity = data[0]<<8 | data[1];
		temperature =(data[2] & 0x7F)<<8 | data[3];
		if(data[2] & 0x80)
			temperature = -temperature;
	}
	dht_data->humidity = humidity;
	dht_data->temperature = temperature;
	HAL_Delay(2000);
}
