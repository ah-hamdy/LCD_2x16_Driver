/*
 * Macro.h
 *
 *  Created on: Dec 30, 2016
 *      Author: Ahmed HAmdy
 */

#ifndef MACRO_H_
#define MACRO_H_

#define SET_BIT(BYTE,BIT) (BYTE = (BYTE | (1 << BIT)))
#define CLEAR_BIT(BYTE,BIT) (BYTE = (BYTE & (~(1 << BIT))))
#define TOGGLE_BIT(BYTE,BIT) (BYTE = (BYTE ^ (1 << BIT)))
#define GET_BIT(BYTE,BIT) ((BYTE & (1 << BIT)) >> BIT)

#endif /* MACRO_H_ */
