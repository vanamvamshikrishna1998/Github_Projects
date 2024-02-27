/*
 * lcd.c
 *
 *  Created on: Feb 26, 2024
 *      Author: vanam
 */
#include "lcd.h"

char *lcd_status;
float temps;
void Lcd_Display(int sensor_state,DHT_Data sensor_dht_data)
{
    // Initialize LCD
	LCD_Init();

    // Clear LCD
    LCD_Clear();

    char lcd_buffer[16]; // Buffer for LCD string

    // Display "temp: {temperature}" on the first line
    temps  = sensor_dht_data.temperature;
    sprintf(lcd_buffer, "temp: %.1f", temps);
    LCD_SetCursor(0, 0);
    LCD_SendString(lcd_buffer);

    // Display "led: {led_status}" on the second line
    if(sensor_state == 1 ){
    	lcd_status = "ON";
    }
    else{
    	lcd_status = "OFF";
    }
    sprintf(lcd_buffer, "led: %s", lcd_status);
    LCD_SetCursor(1, 0);
    LCD_SendString(lcd_buffer);

    HAL_Delay(1000); // Delay for readability


}

void LCD_Init(void)
{
    // Initialization sequence
    HAL_Delay(50); // Wait for LCD to power up

    // Initial commands
    LCD_SendCommand(0x33);
    LCD_SendCommand(0x32);
    LCD_SendCommand(0x28); // Function set: 4-bit mode, 2 lines, 5x8 font
    LCD_SendCommand(0x0C); // Display ON/OFF Control: Display ON, Cursor OFF, Blink OFF
    LCD_SendCommand(0x06); // Entry Mode Set: Increment Cursor, No Shift
    LCD_Clear();
}

void LCD_SendCommand(uint8_t cmd)
{
    HAL_GPIO_WritePin(Lcd_Rs_Out_GPIO_Port, Lcd_Rs_Out_Pin, GPIO_PIN_RESET); // RS low for command mode
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_RESET); // EN low

    // Send high nibble
    HAL_GPIO_WritePin(Lcd_D4_Out_GPIO_Port, Lcd_D4_Out_Pin, (cmd >> 4) & 0x01);
    HAL_GPIO_WritePin(Lcd_D5_Out_GPIO_Port, Lcd_D5_Out_Pin, (cmd >> 5) & 0x01);
    HAL_GPIO_WritePin(Lcd_D6_Out_GPIO_Port, Lcd_D6_Out_Pin, (cmd >> 6) & 0x01);
    HAL_GPIO_WritePin(Lcd_D7_Out_GPIO_Port, Lcd_D7_Out_Pin, (cmd >> 7) & 0x01);
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_SET); // EN high
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_RESET); // EN low

    // Send low nibble
    HAL_GPIO_WritePin(Lcd_D4_Out_GPIO_Port, Lcd_D4_Out_Pin, cmd & 0x01);
    HAL_GPIO_WritePin(Lcd_D5_Out_GPIO_Port, Lcd_D5_Out_Pin, (cmd >> 1) & 0x01);
    HAL_GPIO_WritePin(Lcd_D6_Out_GPIO_Port, Lcd_D6_Out_Pin, (cmd >> 2) & 0x01);
    HAL_GPIO_WritePin(Lcd_D7_Out_GPIO_Port, Lcd_D7_Out_Pin, (cmd >> 3) & 0x01);
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_SET); // EN high
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_RESET); // EN low


    HAL_Delay(1); // Delay for command execution
}

void LCD_SendData(uint8_t data)
{
    HAL_GPIO_WritePin(Lcd_Rs_Out_GPIO_Port, Lcd_Rs_Out_Pin, GPIO_PIN_SET); // RS high for data mode
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_RESET); // EN low

    // Send high nibble
    HAL_GPIO_WritePin(Lcd_D4_Out_GPIO_Port, Lcd_D4_Out_Pin, (data >> 4) & 0x01);
    HAL_GPIO_WritePin(Lcd_D5_Out_GPIO_Port, Lcd_D5_Out_Pin, (data >> 5) & 0x01);
    HAL_GPIO_WritePin(Lcd_D6_Out_GPIO_Port, Lcd_D6_Out_Pin, (data >> 6) & 0x01);
    HAL_GPIO_WritePin(Lcd_D7_Out_GPIO_Port, Lcd_D7_Out_Pin, (data >> 7) & 0x01);
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_SET); // EN high
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_RESET); // EN low

    // Send low nibble
    HAL_GPIO_WritePin(Lcd_D4_Out_GPIO_Port, Lcd_D4_Out_Pin, data & 0x01);
    HAL_GPIO_WritePin(Lcd_D5_Out_GPIO_Port, Lcd_D5_Out_Pin, (data >> 1) & 0x01);
    HAL_GPIO_WritePin(Lcd_D6_Out_GPIO_Port, Lcd_D6_Out_Pin, (data >> 2) & 0x01);
    HAL_GPIO_WritePin(Lcd_D7_Out_GPIO_Port, Lcd_D7_Out_Pin, (data >> 3) & 0x01);
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_SET); // EN high
    HAL_GPIO_WritePin(Lcd_En_Out_GPIO_Port, Lcd_En_Out_Pin, GPIO_PIN_RESET); // EN low

    HAL_Delay(1); // Delay for data write
}

void LCD_SendString(char *str)
{
    while (*str)
    {
        LCD_SendData(*str++);
    }
}

void LCD_Clear(void)
{
    LCD_SendCommand(0x01); // Clear display command
    HAL_Delay(2); // Delay to allow for clear operation
}

void LCD_SetCursor(uint8_t row, uint8_t col)
{
    uint8_t address;
    if (row == 0)
    {
        address = 0x80 + col; // Address for the first row
    }
    else
    {
        address = 0x00 + col; // Address for the second row
    }
    LCD_SendCommand(address);
}

