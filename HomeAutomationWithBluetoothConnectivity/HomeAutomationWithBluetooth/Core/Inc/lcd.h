/*
 * lcd.h
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */
#include "main.h"
#include "string.h"
#include "stdio.h"
#include "output_fan.h"
#include "output_led.h"
#include "stm32f4xx_hal.h"

void LCD_Init(void);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_SendString(char *str);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);
void Lcd_Display(int sensor_state,DHT_Data sensor_dht_data);

