/**************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                */
/* DATE     : 25 AUGUST 2021                                  */
/* VERSION  : V01                                             */
/**************************************************************/

#include "SEG.h"

u8 GLOBAL_SegNum[] = {0b00111111 , 0b00000110 , 0b01011001 , 0b01001111 , 0b01100110 ,
                      0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111};

void void_Display(u8 Copy_PortId , u8 Copy_Number)
{
	switch(Copy_PortId)
	{
		case GPIOA :
		  /* SET 8 PINS AS OUTPUT */ 
          GPIO_voidSetPinDir(GPIOA , GPIO_PIN0 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOA , GPIO_PIN1 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOA , GPIO_PIN2 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOA , GPIO_PIN3 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOA , GPIO_PIN4 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOA , GPIO_PIN5 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOA , GPIO_PIN6 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOA , GPIO_PIN7 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          
          /* ASSIGN THE NUMBER TO PORTA */
          GPIO_voidSetPortVal(GPIOA , GLOBAL_SegNum[Copy_Number]);

		break ; 

		case GPIOB :
		  /* SET 8 PINS AS OUTPUT */
		  GPIO_voidSetPinDir(GPIOB , GPIO_PIN0 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOB , GPIO_PIN1 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOB , GPIO_PIN2 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOB , GPIO_PIN3 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOB , GPIO_PIN4 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOB , GPIO_PIN5 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOB , GPIO_PIN6 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          GPIO_voidSetPinDir(GPIOB , GPIO_PIN7 , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);
          
          /* ASSIGN THE NUMBER TO PORTB */
          GPIO_voidSetPortVal(GPIOB , GLOBAL_SegNum[Copy_Number]);
		break ; 

		default :
		break ; 
	}
}
