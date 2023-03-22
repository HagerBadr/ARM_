/*
 * LCD_int.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

void H_LCD_void_Init(void);   //done
void H_LCD_void_sendData(u8 copy_u8data);//done
void H_LCD_void_sendCommand(u8 copy_u8Command);//done
void H_LCD_void_sendString(const s8 * pstr);//done
void H_LCD_void_clear(void);//done
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_LCD_void_gotXY(u8 copy_u8Row,u8 copy_u8Col);
void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode);
void H_LCD_void_displayCustomChar(u8 copy_u8charCode);

#endif /* HAL_LCD_LCD_INT_H_ */
