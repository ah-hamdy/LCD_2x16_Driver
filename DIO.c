/*
 * DIO.c
 * This source file DIO.c contains implementation of interfaces that
 * can access the registers of I/O ports of microcontroller
 * and this file belongs to MCAL.
 *
 *  Created on: Dec 30, 2016
 *      Author: Ahmed HAmdy
 */

#include "STD_TYPES.h"					/* include type definitions header file */
#include "Macro.h"						/* include all functions like macros 	*/
#include "DIO.h"						/* include prototypes for all functions */



/* This function to set direction for any pin in any port through Data Direction
 * Register DDR
 * Port : Port A,Port B,Port C,Port D.
 * Pin	: from pin 0 to pin 7.
 * Value: if value = 0, This pin configured as Input pin
 * 		  if value = 1, This pin configured as Output pin.
 */
void Dio_vidSetDirection (u8 Port,u8 Pin,u8 Value)
{
	switch (Port)						/* switch for all ports	A,B,C and D */
	{
	case 0:								/* in case of port A */
		if (Value == 1)
		{
			SET_BIT (DDRA,Pin);			/* This pin works as Output pin */
		}
		else
		{
			CLEAR_BIT (DDRA,Pin);		/* This pin works as Input pin */
		}
		break;
	case 1:								/* in case of port B */
		if (Value == 1)
		{
			SET_BIT (DDRB,Pin);			/* This pin works as Output pin */
		}
		else
		{
			CLEAR_BIT (DDRB,Pin);		/* This pin works as Input pin */
		}
		break;
	case 2:								/* in case of port C */
		if (Value == 1)
		{
			SET_BIT (DDRC,Pin);			/* This pin works as Output pin */
		}
		else
		{
			CLEAR_BIT (DDRC,Pin);		/* This pin works as Input pin */
		}
		break;
	case 3:								/* in case of port D */
		if (Value == 1)
		{
			SET_BIT (DDRD,Pin);			/* This pin works as Output pin */
		}
		else
		{
			CLEAR_BIT (DDRD,Pin);		/* This pin works as Input pin */
		}
		break;
	default :							/* Initial value of DDR = 0x00 */
		break;
	}
}


/*This function to set value for any pin in any port through Data OUT Register PORT
 * Port : Port A,Port B,Port C,Port D.
 * Pin	: from pin 0 to pin 7.
 * Value: based on value of DDR
 * if value of PORT = 1 and pin configured as Input , Pull up resistor is actived.
 * if value of PORT = 0 or pin configured as Output , Pull up resistor is deactived.
 * if value of PORT = 1 and pin configured as Output , Pin connected to Vcc (5v).
 * if value of PORT = 0 and pin configured as Output , Pin connected to GND (0v).
 */
void Dio_vidSetPinValue (u8 Port,u8 Pin,u8 Value)
{
	switch (Port)						/* switch for all ports	A,B,C and D */
	{
	case 0:								/* in case of port A */
		if (Value == 1)
		{
			SET_BIT (PORTA,Pin);		/* Pull up resistor active or pin connected to Vcc */
		}
		else
		{
			CLEAR_BIT (PORTA,Pin);		/* Pull up resistor deactive or pin connected to GND */
		}
		break;
	case 1:								/* in case of port B */
		if (Value == 1)
		{
			SET_BIT (PORTB,Pin);		/* Pull up resistor active or pin connected to Vcc */
		}
		else
		{
			CLEAR_BIT(PORTB, Pin);		/* Pull up resistor deactive or pin connected to GND */
		}
		break;
	case 2:								/* in case of port C */
		if (Value == 1)
		{
			SET_BIT (PORTC,Pin);		/* Pull up resistor active or pin connected to Vcc */
		}
		else
		{
			CLEAR_BIT (PORTC,Pin);		/* Pull up resistor deactive or pin connected to GND */
		}
		break;
	case 3:								/* in case of port C */
		if (Value == 1)
		{
			SET_BIT (PORTD,Pin);		/* Pull up resistor active or pin connected to Vcc */
		}
		else
		{
			CLEAR_BIT (PORTD,Pin);		/* Pull up resistor deactive or pin connected to GND */
		}
		break;
	default :							/* Initial value of PORT = 0x00 */
		break;
	}
}

/* This function to get value from any pin in any port through Data Input Register PIN
 * Port : Port A,Port B,Port C,Port D.
 * Pin  : from pin 0 to pin 7.
 */
u8 Dio_u8GetPinValue (u8 Port,u8 Pin)
{
	u8 Return;							/* this variable to save reading value from pin */

	switch (Port)						/* switch for all ports	A,B,C and D */
	{
	case 0:								/* in case of port A */
		Return = GET_BIT (PINA,Pin);	/* read the value applied to this pin */
			break;
	case 1:								/* in case of port B */
		Return = GET_BIT (PINB,Pin);	/* read the value applied to this pin */
			break;
	case 2:								/* in case of port C */
		Return = GET_BIT (PINC,Pin);	/* read the value applied to this pin */
			break;
	case 3:								/* in case of port D */
		Return = GET_BIT (PIND,Pin);	/* read the value applied to this pin */
			break;
	default :							/* Initial value of PIN = N/A */
			break;
	}
	return Return;						/* return value to store it in variable (Return) */
}

/*This function to set any value to any port through Data OUT Register PORT */
void Dio_vidSetPortValue (u8 Port,u8 Value)
{
	switch (Port)						/* switch for all ports	A,B,C and D */
	{
	case 0: PORTA = Value;				/* in case of port A , set the value */
			break;
	case 1: PORTB = Value;				/* in case of port B , set the value */
			break;
	case 2: PORTC = Value;				/* in case of port C , set the value */
			break;
	case 3: PORTD = Value;				/* in case of port D , set the value */
			break;
	default:							/* Initial value of PORT = 0x00 */
			break;

	}
}

/* This function to get any value from any port through PIN register */
u8 Dio_u8GetPortValue (u8 Port)
{
	u8 Return;							/* this variable to save reading value from port */
	switch (Port)
	{
	case 0: Return = PINA;				/* read the value applied to Port A */
			break;
	case 1: Return = PINB;				/* read the value applied to Port B */
			break;
	case 2: Return = PINC;				/* read the value applied to Port C */
			break;
	case 3: Return = PIND;				/* read the value applied to Port D */
			break;
	default: 							/* Initial value of PIN = N/A */
			break;
	}
	return Return;						/* return value to store it in variable (Return) */
}
