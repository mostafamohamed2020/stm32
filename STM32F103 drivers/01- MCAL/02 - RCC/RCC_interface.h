/***********************************************************
*      AUTHOR : MOSTAFA MOHAMED                            *
*      DATE   : 12 MAY 2021                                *
*      VERSION : V01                                       *
***********************************************************/



#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void RCC_VoidInitSysClock(void);

void RCC_VoidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);

void RCC_VoidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);


#endif