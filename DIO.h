/*
 * DIO.h
 *
 *  Created on: Dec 30, 2016
 *      Author: Ahmed HAmdy
 */

#ifndef DIO_H_
#define DIO_H_

/* This header file contains prototypes of functions and pre-processing directives
 * to define addresses of registers for I/O ports.
 */

/* There are three I/O memory address locations are allocated for each port in ATmega32
 * Data Register : PORTx (Read & Write)
 * Data Direction Register : DDRx (Read & Write)
 * Port Input Pins Register : PINx (Read only)
 * x : represent for the number of port
 */

/* Addresses of Registers for Port A */
#define DDRA (*((volatile u8 *) 0x3A))
#define PORTA (*((volatile u8 *) 0x3B))
#define PINA (*((volatile u8 *) 0X39))

/* Addresses of Registers for Port B */
#define DDRB (*((volatile u8 *) 0X37))
#define PORTB (*((volatile u8 *) 0x38))
#define PINB (*((volatile u8 *) 0x36))

/* Addresses of Registers for Port C */
#define DDRC (*((volatile u8 *) 0x34))
#define PORTC (*((volatile u8 *) 0x35))
#define PINC (*((volatile u8 *) 0X33))

/* Addresses of Registers for Port D */
#define DDRD (*((volatile u8 *) 0x31))
#define PORTD (*((volatile u8 *) 0x32))
#define PIND (*((volatile u8 *) 0X30))


/* This function to set direction for any pin in any port through DDR */
void Dio_vidSetDirection (u8 Port,u8 Pin,u8 Value);

/* This function to set value for any pin in any port through PORT register */
void Dio_vidSetPinValue (u8 Port,u8 Pin,u8 Value);

/* This function to get value for any pin in any port through PIN register */
u8 Dio_u8GetPinValue (u8 Port,u8 Pin);

/* This function to set value for any port through PORT register */
void Dio_vidSetPortValue (u8 Port,u8 Value);

/* This function to get value for any port through PIN register */
u8 Dio_u8GetPortValue (u8 Port);

#endif /* DIO_H_ */
