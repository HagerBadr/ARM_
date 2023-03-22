/*
 * Delay.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */

#include "STD_TYPES.h"
#include "Delay.h"

void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}
