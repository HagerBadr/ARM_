/*
 * STK_int.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */

#ifndef MCAL_STK_STK_INT_H_
#define MCAL_STK_STK_INT_H_

void	STK_voidInit				(void);
void	STK_voidBusyWait			(u32 Ticks);
void	STK_voidSetIntervalSingle	(u32 Ticks,void (*Pf)(void));
void	STK_voidSetIntervalPeriodic	(u32 Ticks,void (*Pf)(void));
void	STK_voidStopInterval		(void);
u32		STK_u32GetElapsedTime		(void);
u32		STK_u32GetRemainingTime		(void);

#endif /* MCAL_STK_STK_INT_H_ */
