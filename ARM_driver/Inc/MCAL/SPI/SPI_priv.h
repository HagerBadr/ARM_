/*
 * SPI_priv.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */

#ifndef MCAL_SPI_SPI_PRIV_H_
#define MCAL_SPI_SPI_PRIV_H_


typedef	struct
{
	u16 u16_Periodicity;
	u16 u16_FirstDelay;
	void	(*pf)	(void);
}Task_TCB;

static void RTOS_voidScheduler(void);

#endif /* MCAL_SPI_SPI_PRIV_H_ */
