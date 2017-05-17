/*
 * LCD_LMB162_private.h
 *
 *  Created on: May 13, 2017
 *      Author: Ahmed HAmdy
 */

#ifndef LCD_2X16_PRIVATE_H_
#define LCD_2X16_PRIVATE_H_

/* Define the most used commands of LCD which will be send to ATmega32 to control LCD
 * Default Mode: 	8 bits mode
 * 					Two lines
 *  				8 dots format
 */

#define  CLEAR_DISPLAY			        0x01
#define  CURSOR_RETURN_HOME		        0x02
#define  SHIFT_CURSOR_LEFT		        0x04
#define  SHIFT_CURSOR_RIGHT		        0x06
#define  SHIFT_DISPLAY_LEFT		        0x05
#define  SHIFT_DISPLAY_RIGHT		    0x07
#define  DISPLAY_OFF				    0x08
#define  DISPLAY_ON_CURSOR_OFF	        0x0C
#define  DISPLAY_ON_CURSOR_ON	        0x0E
#define  DISPLAY_ON_CURSOR_ON_BLINK	    0x0F

#define  MODE_8_BITS				    0x30
#define  MODE_4_BITS				    0x20

#define  DISPLAY_ONE_LINE				0x30
#define  DISPLAY_TWO_LINE				0x38

#define  FORMAT_8_DOTS					0x38
#define  FORMAT_11_DOTS					0x3C

/* Define CG RAM Locations to generate eight customize characters */
#define  SET_CGRAM_LOCATION_0			0x40
#define  SET_CGRAM_LOCATION_1			0x48
#define  SET_CGRAM_LOCATION_2			0x50
#define  SET_CGRAM_LOCATION_3			0x58
#define  SET_CGRAM_LOCATION_4			0x60
#define  SET_CGRAM_LOCATION_5			0x68
#define  SET_CGRAM_LOCATION_6			0x70
#define  SET_CGRAM_LOCATION_7			0x78

/* Define the boundary Locations of DD RAM to display any characters on LCD */
#define  SET_DDRAM_LOCATION_0			0x80
#define  SET_DDRAM_LOCATION_15			0x95
#define  SET_DDRAM_LOCATION_40			0xC0
#define  SET_DDRAM_LOCATION_55			0xD5

#endif /* LCD_2X16_PRIVATE_H_ */
