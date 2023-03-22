/*
 * SPI_int.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Delta Store
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_


void M_SPI_void_MasterInit();
void M_SPI_void_MasterTransmit(u8 copy_u8Data);
void M_SPI_void_SlaveInit();
u8 M_SPI_void_SlaveReceive();

#endif /* MCAL_SPI_SPI_INT_H_ */
