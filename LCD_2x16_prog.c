/*
 * LCD_LMB162.c
 *
 *  Created on: May 13, 2017
 *      Author: Ahmed HAmdy
 */

#include "Macro.h"
#include "STD_TYPES.h"

#include "util/delay.h"
#include "DIO.h"
#include "LCD_2x16_config.h"
#include "LCD_2x16_interface.h"
#include "LCD_2x16_private.h"

/* Define status of control pins of LCD */
enum ControlPins
{
	Low = 0,		// Low equals to 0
	High			// High equals to 1
};

/* This function is responsable for Sending LCD Command to microcontroller */
void LCD_vidSendCommand(u8 Command)
{
	// Set RESET Signal to low to  send command
	Dio_vidSetPinValue(LCD_CONTROL_PORT, RESET_SIGNAL, Low);

	// Set READ WRITE Signal to low to write mode
	Dio_vidSetPinValue(LCD_CONTROL_PORT, READ_WRITE_SIGNAL, Low);

	// Set ENABLE Signal with high to begin sending the command
	Dio_vidSetPinValue(LCD_CONTROL_PORT, ENABLE_SIGNAL, High);

	// Set LCD Port with Commmand
	Dio_vidSetPortValue(LCD_PORT, Command);
	_delay_ms(2);

	// Set ENABLE Signal with low after sending the command
	Dio_vidSetPinValue(LCD_CONTROL_PORT, ENABLE_SIGNAL, Low);
	_delay_ms(5);

	// Set ENABLE Signal with high to send the next command
	Dio_vidSetPinValue(LCD_CONTROL_PORT, ENABLE_SIGNAL, High);
	_delay_ms(10);
}


/* This function is responsable for intializing the modes of operation of LCD */
void LCD_vidInitialize(void)
{
	// Wait for response time of LCD in the beginning
	_delay_ms(100);

	// Send command to clear LCD
	LCD_vidSendCommand(CLEAR_DISPLAY);

	// Send command to return the cursor to default location
	LCD_vidSendCommand(CURSOR_RETURN_HOME);

	// Send command to shift cursot to right
	LCD_vidSendCommand(SHIFT_CURSOR_RIGHT);

	// Send command to turn on the LCD and turn off the cursor
	LCD_vidSendCommand(DISPLAY_ON_CURSOR_OFF);

	// Send command to configure LCD to work with 8 bit mode
	LCD_vidSendCommand(MODE_8_BITS);

	// Send command to configure LCD to work on two lines
	LCD_vidSendCommand(DISPLAY_TWO_LINE);

	// Send command to configure format of display character in 5*8 dots
	LCD_vidSendCommand(FORMAT_8_DOTS);
}

/* This function is responsable for Sending the character to dispaly on LCD */
void LCD_vidSendCharacter(u8 Character)
{
	// Set RESET Signal to high to send data
	Dio_vidSetPinValue(LCD_CONTROL_PORT, RESET_SIGNAL, High);

	// Set READ WRITE Signal to low to write mode
	Dio_vidSetPinValue(LCD_CONTROL_PORT, READ_WRITE_SIGNAL, Low);

	// Set ENABLE Signal with high to begin sending the data
	Dio_vidSetPinValue(LCD_CONTROL_PORT, ENABLE_SIGNAL, High);

	// Set LCD Port with data
	Dio_vidSetPortValue(LCD_PORT, Character);
	_delay_ms(2);

	// Set ENABLE Signal with low after sending the data
	Dio_vidSetPinValue(LCD_CONTROL_PORT, ENABLE_SIGNAL, Low);
	_delay_ms(5);

	// Set ENABLE Signal with high to send the next data
	Dio_vidSetPinValue(LCD_CONTROL_PORT, ENABLE_SIGNAL, High);
	_delay_ms(10);

}

/* This function is responsable for Sending the string to dispaly on LCD */
void LCD_vidSendString(u8 * String)
{
	// index of string
	u8 index = 0;
	// Wait until index of string equal null terminator
	while (String[index] != '\0')
	{
		// Send Character of corresponding index of string
		LCD_vidSendCharacter(String[index]);

		// Increment the index to dispaly the next character
		index++;
		_delay_ms(2);
	}
}

/* This function is responsable for Setting a location of cursor on LCD  */
void LCD_vidSetLocation (u8 Row,u8 Column)
{
	// if row equal to zero which is the first row of LCD
	if (Row == 0)
	{
		// Send command of set location of DD RAM at first row
		LCD_vidSendCommand(SET_DDRAM_LOCATION_0 + Column);
	}
	else
	{
		// Send command of set location of DD RAM at second row
		LCD_vidSendCommand(SET_DDRAM_LOCATION_40 + Column);
	}
}
