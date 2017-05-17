/*
 * LCD_LMB162.h
 *
 *  Created on: May 13, 2017
 *      Author: Ahmed HAmdy
 */

#ifndef LCD_2X16_INTERFACE_H_
#define LCD_2X16_INTERFACE_H_


/*
 * Function Name:			LCD_vidSendCommand
 * Prototype: 				void LCD_vidSendCommand	(u8 Command)
 * Behavior description:	Sends LCD Command to microcontroller.
 * Input parameter:			Command
 * Output parameter:		None
 * Required preconditions:	The software has to initialize the LCD before calling this function.
 */
void LCD_vidSendCommand	(u8 Command);
/*
 * Function Name:			LCD_vidInitialize
 * Prototype: 				void LCD_vidInitialize (void)
 * Behavior description:	Intialize the modes of operation of LCD.
 * Input parameter:			None
 * Output parameter:		None
 * Required preconditions:	The software has to initialize DIO pins which are connected to LCD before calling this function.
 */
void LCD_vidInitialize (void);
/*
 * Function Name:			LCD_vidSendCharacter
 * Prototype: 				void LCD_vidSendCharacter(u8 Character)
 * Behavior description:	Sends the character to dispaly on LCD.
 * Input parameter:			Character
 * Output parameter:		None
 * Required preconditions:	None
 */
void LCD_vidSendCharacter(u8 Character);
/*
 * Function Name:			LCD_vidSendString
 * Prototype: 				void LCD_vidSendString (u8 * String)
 * Behavior description:	Sends the string to dispaly on LCD.
 * Input parameter:			Pointer to string which will be display on LCD.
 * Output parameter:		None
 * Required preconditions:	None
 */
void LCD_vidSendString (u8 * String);
/*
 * Function Name:			LCD_vidSetLocation
 * Prototype: 				void LCD_vidSetLocation (u8 Row,u8 Column)
 * Behavior description:	Set a location of cursor on LCD .
 * Input parameter:			Row (from 0 to 1) and Column (from 0 to 15)
 * Output parameter:		None
 * Required preconditions:	None
 */
void LCD_vidSetLocation (u8 Row,u8 Column);


#endif /* LCD_2X16_INTERFACE_H_ */
