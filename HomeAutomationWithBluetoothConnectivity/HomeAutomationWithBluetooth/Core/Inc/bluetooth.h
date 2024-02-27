/*
 * bluetooth.h
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */

#ifndef INC_BLUETOOTH_H_
#define INC_BLUETOOTH_H_

#include "string.h"
#include "stdio.h"
#include "main.h"
void SendToBluetooth(int state, UART_HandleTypeDef huart2);
void ReceivedFromBluetooth(char *rx_data);

#endif /* INC_BLUETOOTH_H_ */
