/**************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                */
/* DATE     : 25 AUGUST 2021                                  */
/* VERSION  : V01                                             */
/**************************************************************/

#include "LED.h"

/* FUNCTION TO MAKE LEDS ON */
void Void_LedOn(u8 Copy_u8PortId , u8 Copy_u8PinId)
{
	SET_BIT(Copy_u8PortId , Copy_u8PinId);
}

/* FUNCTION TO MAKE LEDS OFF */
void Void_LedOff(u8 Copy_u8PortId , u8 Copy_u8PinId)
{
	CLR_BTI(Copy_u8PortId , Copy_u8PinId);
}

/* FUNCTION TO TOGGLE LEDS */
void Void_LedToggle(u8 Copy_u8PortId , u8 Copy_u8PinId)
{
	TOGGLE_BIT(Copy_u8PortId , Copy_u8PinId);
}

/***************************************************/ 
/*      FUNCTION TO BLINK 8 LEDS ON ANY PORT       */
/*      BLINK THE FIRST 8 BITS FOR 1 SEC           */
/***************************************************/
void void_LedBlinker(u8 Copy_u8Port)
{
	switch(Copy_u8Port)
	{
		case GPIOA : 
		GPIO_voidSetPortVal(GPIOA , 0x00FF);
        MSTK_voidSetBusyWait(1000000);
        GPIO_voidSetPortVal(GPIOA , 0x00FF);
        MSTK_voidSetBusyWait(1000000);
		break ;

		case GPIOB :
		GPIO_voidSetPortVal(GPIOB , 0x00FF);
        MSTK_voidSetBusyWait(1000000);
        GPIO_voidSetPortVal(GPIOB , 0x00FF);
        MSTK_voidSetBusyWait(1000000);
		break ;

		case GPIOC :
		GPIO_voidSetPortVal(GPIOC , 0x00FF);
        MSTK_voidSetBusyWait(1000000);
        GPIO_voidSetPortVal(GPIOC , 0x00FF);
        MSTK_voidSetBusyWait(1000000);
		break ;

		default :
		break ;

	}
}

/* FUNCTION TO BKINK 8 LEDS FROM INNER TO EDGE */
void void_BlinkInOut()
{
	/* ASSUME THAT WE USE PORTA PINS */

	/* LOCAL VARIABLE TO HOLD 1st FORM */
	u8 Local_Form1 = 0x0018 ;

	/* LOCAL VARIABLE TO HOLD 2nd FORM */
	u8 Local_Form2 = 0x0024 ;

	/* LOCAL VARIABLE TO HOLD 3rd FORM */
	u8 Local_Form3 = 0x0042 ;

	/* LOCAL VARIABLE TO HOLD 4th FORM */
	u8 Local_Form4 = 0x0081 ;
    
    /* DELAY FOR 200 ms BETWEEN EACH FORM */
	GPIO_voidSetPortVal(GPIOA , Local_Form1);
	MSTK_voidSetBusyWait(200000);

	GPIO_voidSetPortVal(GPIOA , Local_Form2);
	MSTK_voidSetBusyWait(200000);

	GPIO_voidSetPortVal(GPIOA , Local_Form3);
	MSTK_voidSetBusyWait(200000);

	GPIO_voidSetPortVal(GPIOA , Local_Form4);
	MSTK_voidSetBusyWait(200000);

}

/* FUNCTION TO BKINK 8 LEDS FROM IN SUCCESSION */
void void_BlinkRow()
{
	/* ASSUME THAT WE USE PORTA PINS */
	GPIOA_BSRR = 0X0080 ; 

	for (int i = 0; i < 7; ++i)
	{
		/* SHIFT THE REGISTER VALUE BY ONE TO ILLUMINATE THE NEXT LED */
		GPIOA_BSRR = (GPIOA_BSRR >> 1);
	}
}