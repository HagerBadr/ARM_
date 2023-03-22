/*
 * SPI_prg.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */



#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_int.h"
#include"SPI_priv.h"
#include"SPI_config.h"
#include"SPI_int.h"

void M_SPI_void_MasterInit(void)
{

	SPI1->SPI_CR1 = 0x0347 ;

	/* Enable SPI, Master, set clock rate fck/8 */

  /*
  // ENABLE MC AS MASTER
	SET_BIT(SPI1->SPI_CR1,  2);
	// SELECT BAUD RATE  ( fPCLK/8)
	CLR_BIT(SPI1->SPI_CR1,3);
	SET_BIT(SPI1->SPI_CR1, 4);
	CLR_BIT(SPI1->SPI_CR1,5);
	// ENABLE SPI(SPE BIT)
	SET_BIT(SPI1->SPI_CR1, 6); */

}
void M_SPI_void_MasterTransmit(u8 copy_u8Data)
{
	/* Start transmission */
	M_GPIO_void_SetPinValue(PORTA_ID, PIN0_ID, LOW);

	SPI1->SPI_DR = copy_u8Data;

	/* Wait for transmission complete */
	//while((SPI1->SPI_SR & (1<<7)))

	while( GET_BIT(SPI1->SPI_SR,1) == 0 )
	{
		asm("NOP") ;
	}

	M_GPIO_void_SetPinValue(PORTA_ID, PIN0_ID, HIGH);


}
void M_SPI_void_SlaveInit()
{

	SPI1->SPI_CR1 = 0x0343 ;


	//FOR SLAVE MANAGEMENT(SSM BIT)

	//SET_BIT(SPI1->SPI_CR1, 9);

	/* Enable SPI */

	//SET_BIT(SPI1->SPI_CR1, 6);
}
u8 M_SPI_void_SlaveReceive()
{
	/* Wait for reception complete */
	while((SPI1->SPI_SR & (1<<7)));
	/* Return data register */
	return SPI1->SPI_DR;

}
