/*
 * bluetooth.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */


#include "bluetooth.h"

void ReceivedFromBluetooth(char *rx_data){
	if(strcmp(rx_data,"LON\r\n")==0){
		HAL_GPIO_WritePin(Led_Out_GPIO_Port, Led_Out_Pin, GPIO_PIN_SET);
	}
	else if(strcmp(rx_data,"LOFF\r\n")==0){
		HAL_GPIO_WritePin(Led_Out_GPIO_Port, Led_Out_Pin, GPIO_PIN_RESET);
	}
	else if(strcmp(rx_data,"FOFF\r\n")==0){
		HAL_GPIO_WritePin(Fan_Out_GPIO_Port, Fan_Out_Pin, GPIO_PIN_RESET);
	}
	else if(strcmp(rx_data,"FON\r\n")==0){
		HAL_GPIO_WritePin(Fan_Out_GPIO_Port, Fan_Out_Pin, GPIO_PIN_SET);
	}
}
void SendToBluetooth(int state, UART_HandleTypeDef huart2){
	if(state==1){
		char *tx_data = "person found";
		HAL_UART_Transmit(&huart2, (uint8_t *)tx_data , strlen(tx_data), HAL_MAX_DELAY);
	}
	else{
		char *tx_data = "person not found";
		HAL_UART_Transmit(&huart2, (uint8_t *)tx_data , strlen(tx_data), HAL_MAX_DELAY);
	}
}
