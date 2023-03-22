/*
 * KEYPAD_prg.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */

#include "Delay.h"
#include "STD_TYPES.h"
#include "DIO_int.h"

#include"KEYPAD_priv.h"
#include"KEYPAD_config.h"
#include"KEYPAD_int.h"

void H_KEYPAD_void_init()
{
  //set all rows  direction as output
	M_GPIO_void_SetPinDir(KEYPAD_R0_PORT, KEYPAD_R0_PIN, OUT_2MHZ_PP);
	M_GPIO_void_SetPinDir(KEYPAD_R1_PORT, KEYPAD_R1_PIN, OUT_2MHZ_PP);
	M_GPIO_void_SetPinDir(KEYPAD_R2_PORT, KEYPAD_R2_PIN, OUT_2MHZ_PP);
	M_GPIO_void_SetPinDir(KEYPAD_R3_PORT, KEYPAD_R3_PIN, OUT_2MHZ_PP);

	//set all collums direction as input
	M_GPIO_void_SetPinDir(KEYPAD_C0_PORT,KEYPAD_C0_PIN, IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinDir(KEYPAD_C1_PORT, KEYPAD_C1_PIN, IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinDir(KEYPAD_C2_PORT, KEYPAD_C2_PIN, IN_PULL_UP_DOWN);
	M_GPIO_void_SetPinDir(KEYPAD_C3_PORT, KEYPAD_C3_PIN, IN_PULL_UP_DOWN);

	M_GPIO_void_SetPinValue(KEYPAD_C0_PORT,KEYPAD_C0_PIN,HIGH);
	M_GPIO_void_SetPinValue(KEYPAD_C1_PORT,KEYPAD_C1_PIN,HIGH);
	M_GPIO_void_SetPinValue(KEYPAD_C2_PORT,KEYPAD_C2_PIN,HIGH);
	M_GPIO_void_SetPinValue(KEYPAD_C3_PORT,KEYPAD_C3_PIN,HIGH);

	//deactivate rows (high)
	M_GPIO_void_SetPinValue(KEYPAD_R0_PORT,KEYPAD_R0_PIN,HIGH);
	M_GPIO_void_SetPinValue(KEYPAD_R1_PORT,KEYPAD_R1_PIN,HIGH);
	M_GPIO_void_SetPinValue(KEYPAD_R2_PORT,KEYPAD_R2_PIN,HIGH);
	M_GPIO_void_SetPinValue(KEYPAD_R3_PORT,KEYPAD_R3_PIN,HIGH);

  }
u8 H_KEYPAD_void_getPressedKey()
{
	u8 loc_state= NO_PRESSED_KEY ;
	u8 loc_row_indx;
	u8 loc_col_indx;
	u8 loc_keypad_arr [4][4]=KEYPAD_ARR_MAP;
	u8 read;
	 for(loc_row_indx=KEYPAD_R0_PIN;loc_row_indx<=KEYPAD_R3_PIN;loc_row_indx++)
	{
		 M_GPIO_void_SetPinValue(KEYPAD_ROW_PORTS,loc_row_indx,LOW);
		   for (loc_col_indx=KEYPAD_C0_PIN;loc_col_indx<=KEYPAD_C3_PIN;loc_col_indx ++)
		   {
			   M_GPIO_void_GetPinValue(KEYPAD_COLS_PORTS, loc_col_indx, &read);
			   if(read==ACTIVE_LOW_PRESSED)
			   {
				   //debouncing delay
				   _delay_ms(100);
				  M_GPIO_void_GetPinValue(KEYPAD_COLS_PORTS, loc_col_indx, &read);
			 if(read==ACTIVE_LOW_PRESSED)
			 {


				 while(read==ACTIVE_LOW_PRESSED)
					 {
					 M_GPIO_void_GetPinValue(KEYPAD_COLS_PORTS, loc_col_indx, &read);
					 }
					 read= loc_keypad_arr[loc_row_indx - KEYPAD_R0_PIN ][ loc_col_indx -  KEYPAD_C0_PIN ];
					 	return read;

			 }

		 }
	  }//deactivate rows
		   M_GPIO_void_SetPinValue(KEYPAD_ROW_PORTS,loc_row_indx,HIGH);


	}
	 return  loc_state;
}
