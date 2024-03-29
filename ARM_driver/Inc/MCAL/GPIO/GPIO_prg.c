/*
 * GPIO_prg.c
 *
 *  Created on: Mar 22, 2023
 *      Author: HAGER
 */

#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"GPIO_config.h"
#include	"GPIO_int.h"


void	M_GPIO_void_SetPinDir(u8 PortId, u8 PinId, u8 Direction)
{
	/*	Range Check						*/
	if(PortId<3 && PinId < 16 && Direction < 16)
	{
		if(PinId < 8) /*	Pin0 : Pin7 ==> CRL	*/
		{
			switch(PortId)
			{
			case PORTA	:	GPIOA_CRL &=	~(0b1111<<(PinId * 4));		/*Clear the 4 bits */
			GPIOA_CRL |=	((Direction)<<(PinId * 4));	/*Assign the 4 bits */
			break;

			case PORTB	:	GPIOB_CRL &=	~(0b1111<<(PinId * 4));		/*Clear the 4 bits */
			GPIOB_CRL |=	((Direction)<<(PinId * 4));	/*Assign the 4 bits */
			break;

			case PORTC	:	GPIOC_CRL &=	~(0b1111<<(PinId * 4));		/*Clear the 4 bits */
			GPIOC_CRL |=	((Direction)<<(PinId * 4));	/*Assign the 4 bits */
			break;
			}
		}else if(PinId < 16) /*	Pin8 : Pin15 ==> CRH	*/
		{
			PinId -= 8 ;
			switch(PortId)
			{
			case PORTA	:	GPIOA_CRH &=	~(0b1111<<(PinId * 4));		/*Clear the 4 bits */
			GPIOA_CRH |=	((Direction)<<(PinId * 4));	/*Assign the 4 bits */
			break;

			case PORTB	:	GPIOB_CRH &=	~(0b1111<<(PinId * 4));		/*Clear the 4 bits */
			GPIOB_CRH |=	((Direction)<<(PinId * 4));	/*Assign the 4 bits */
			break;

			case PORTC	:	GPIOC_CRH &=	~(0b1111<<(PinId * 4));		/*Clear the 4 bits */
			GPIOC_CRH |=	((Direction)<<(PinId * 4));	/*Assign the 4 bits */
			break;
			}
		}
		else{/*	Display Error Out of Range*/	}
	}
	else
	{/*	Display Error */}
}
void	M_GPIO_void_SetPinValue(u8 PortId, u8 PinId, u8 Value)
{
	/*	Range Check						*/
	if(PortId<3 && PinId < 16)
	{
		if(Value == DIO_LOW)
		{
			switch(PortId)
			{
			case PORTA	:	CLR_BIT(GPIOA_ODR ,PinId);	break;
			case PORTB	:	CLR_BIT(GPIOB_ODR ,PinId);	break;
			case PORTC	:	CLR_BIT(GPIOC_ODR ,PinId);	break;
			}
		}else if(Value == DIO_HIGH)
		{
			switch(PortId)
			{
			case PORTA	:	SET_BIT(GPIOA_ODR ,PinId);	break;
			case PORTB	:	SET_BIT(GPIOB_ODR ,PinId);	break;
			case PORTC	:	SET_BIT(GPIOC_ODR ,PinId);	break;
			}
		}
		else{/*		Report Error Out of Range			*/	}
	}
	else
	{/*	Display Error*/}
}
void	M_GPIO_void_GetPinValue(u8 PortId, u8 PinId, u8 * Value)
{
	/*	Range Check						*/
	if(PortId<3 && PinId < 16)
	{
		switch(PortId)
		{
		case PORTA	:	*Value = GET_BIT(GPIOA_IDR ,PinId);	break;
		case PORTB	:	*Value = GET_BIT(GPIOB_IDR ,PinId);	break;
		case PORTC	:	*Value = GET_BIT(GPIOC_IDR ,PinId);	break;
		}
	}
	else
	{/*	Display Error */}
}



void	MDIO_voidTogPinValue(u8 PortId, u8 PinId)
{
	/*	Check Range 	*/
	if(PortId<3 && PinId < 16)
	{
		switch(PortId)
		{
		case PORTA	:	TOG_BIT(GPIOA_ODR ,PinId);	break;
		case PORTB	:	TOG_BIT(GPIOA_ODR ,PinId);	break;
		case PORTC	:	TOG_BIT(GPIOA_ODR ,PinId);	break;
		}
	}
	else
	{/*	Display Error */}
}

