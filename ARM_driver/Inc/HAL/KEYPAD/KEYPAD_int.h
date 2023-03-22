/*
 * KEYPAD_int.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_


#define NO_PRESSED_KEY   0xff
#define ACTIVE_LOW_PRESSED  0
void H_KEYPAD_void_init();
u8 H_KEYPAD_void_getPressedKey();

#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
