/*
 * main.c
 *
 *  Created on: May 13, 2017
 *      Author: Ahmed HAmdy
 */


#include "STD_TYPES.h"
#include "Macro.h"

#include "DIO.h"
#include "LCD_2x16_config.h"
#include "LCD_2x16_private.h"
#include "LCD_2x16_interface.h"

int main (void)
{

	u8 index;
	u8 Name [] = "Hamdy";
	for (index = 0;index < 8;index ++)
	{
		Dio_vidSetDirection(LCD_PORT,index,1);
	}
	for (index = 0;index < 3;index ++)
	{
		Dio_vidSetDirection(LCD_CONTROL_PORT,index,1);
	}

	LCD_vidInitialize();

	//	LCD_vidSendCommand(SET_DDRAM_LOCATION_40 + 2);

	//	LCD_vidSendCommand(SHIFT_CURSOR_RIGHT);
	LCD_vidGoTo(1,5);
	LCD_vidSendCharacter('A');
	//	LCD_vidSendString(Name);
	while (1)
	{


	}

	return (0);
}
