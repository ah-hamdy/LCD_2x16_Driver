/*
 * LCD_LMB162_config.h
 *
 *  Created on: May 13, 2017
 *      Author: Ahmed HAmdy
 */

#ifndef LCD_2X16_CONFIG_H_
#define LCD_2X16_CONFIG_H_

/* Define the ports of ATmega 32 */
#define		PORT_A     0
#define		PORT_B	   1
#define		PORT_C	   2
#define		PORT_D	   3

/* Define the pins of any port in ATmega 32 */
#define 	PIN_0 	   0
#define		PIN_1	   1
#define		PIN_2	   2
#define		PIN_3	   3
#define		PIN_4	   4
#define		PIN_5	   5
#define		PIN_6	   6
#define		PIN_7	   7

/* Define the ports which are connecting with LCD */
#define     LCD_PORT				PORT_A
#define     LCD_CONTROL_PORT		PORT_B

/* Define the control pins of LCD which are connecting to control port in ATmega 32 */
#define     RESET_SIGNAL			PIN_0
#define     READ_WRITE_SIGNAL		PIN_1
#define     ENABLE_SIGNAL			PIN_2



#endif /* LCD_2X16_CONFIG_H_ */
