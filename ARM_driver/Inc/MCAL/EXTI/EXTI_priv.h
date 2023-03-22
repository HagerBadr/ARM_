/*
 * EXTI_priv.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_


typedef	struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RSTR;
	volatile	u32		FSTR;
	volatile	u32		SWIER;
	volatile	u32		PR;
}EXTI_Type;

/**************	EXTI -> EMR = xxxx;	******************/
#define		EXTI	((EXTI_Type *)0x40010400)


#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
