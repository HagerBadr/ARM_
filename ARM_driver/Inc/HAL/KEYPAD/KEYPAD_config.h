/*
 * KEYPAD_config.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define KEYPAD_ROW_PORTS  PORTB_ID
#define KEYPAD_COLS_PORTS    PORTA_ID

#define KEYPAD_R0_PORT PORTB_ID
#define KEYPAD_R0_PIN  PIN4_ID

#define KEYPAD_R1_PORT  PORTB_ID
#define KEYPAD_R1_PIN   PIN5_ID

#define KEYPAD_R2_PORT  PORTB_ID
#define KEYPAD_R2_PIN   PIN6_ID

#define KEYPAD_R3_PORT  PORTB_ID
#define KEYPAD_R3_PIN   PIN7_ID


#define KEYPAD_C0_PORT  PORTA_ID
#define KEYPAD_C0_PIN   PIN9_ID

#define KEYPAD_C1_PORT  PORTA_ID
#define KEYPAD_C1_PIN   PIN10_ID

#define KEYPAD_C2_PORT  PORTA_ID
#define KEYPAD_C2_PIN   PIN11_ID

#define KEYPAD_C3_PORT  PORTA_ID
#define KEYPAD_C3_PIN   PIN12_ID

#define KEYPAD_ARR_1     {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
#define KEYPAD_ARR_2     {{'7','8','9','+'},{'4','5','6','-'},{'1','2','3','*'},{'A','0','/','='}}
#define KEYPAD_ARR_MAP    KEYPAD_ARR_2

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
