/*********************************************************/
/*       AUTHOR : MUSTAFA MOHAMED                        */
/*       DATE   : 16 MAY 2021                            */
/*       @ 1:48 AM                                       */
/*       VERSION : V01                                   */
/*********************************************************/
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

/* FUNCTION TO SET THE MODE OF ANY PIN IN ANY PORT */
void GPIO_voidSetPinDir(u8 Copy_u8_PORT , u8 Copy_u8_PIN , u8 Copy_u8_Mode)
{
	switch(Copy_u8_PORT)
	{
		/* IN CASE OF HANDLING PORTA PINS */
		case GPIOA :
		       if(Copy_u8_PIN <= 7)
		       { 
		       	/* CLEARING THE INTENDED FOUR BITS */
		       	 GPIOA_CRL &= ~((0b1111) << (Copy_u8_PIN * 4));
		       	/* STORING THE MODE IN THE PREVIOUSLY CLEARED BITS */
		       	 GPIOA_CRL |= (Copy_u8_Mode << (Copy_u8_PIN * 4));
		       }
		       else if(Copy_u8_PIN >= 8 && Copy_u8_PIN <= 15)
		       { 
		       	/* EVALUATING THE PIN FROM 0 TO 8 */
		       	 Copy_u8_PIN = Copy_u8_PIN - 8 ;
		       	/* CLEARING THE INTENDED FOUR BITS */
		       	 GPIOA_CRH &= ~((0b1111) << (Copy_u8_PIN * 4));
		       	/* STORING THE MODE IN THE PREVIOUSLY CLEARED BITS */
		       	 GPIOA_CRH |= (Copy_u8_Mode << (Copy_u8_PIN * 4));
		       }
		break ;
        
        /* IN CASE OF HANDLING PORTB PINS */
		case GPIOB :

		       if(Copy_u8_PIN <= 7)
		       { 
		       	/* CLEARING THE INTENDED FOUR BITS */
		       	 GPIOB_CRL &= ~((0b1111) << (Copy_u8_PIN * 4));
		       	/* STORING THE MODE IN THE PREVIOUSLY CLEARED BITS */
		       	 GPIOB_CRL |= (Copy_u8_Mode << (Copy_u8_PIN * 4));
		       }
		       else if(Copy_u8_PIN >= 8 && Copy_u8_PIN <= 15)
		       { 
		       	/* EVALUATING THE PIN FROM 0 TO 8 */
		       	 Copy_u8_PIN = Copy_u8_PIN - 8 ;
		       	/* CLEARING THE INTENDED FOUR BITS */
		       	 GPIOB_CRH &= ~((0b1111) << (Copy_u8_PIN * 4));
		       	/* STORING THE MODE IN THE PREVIOUSLY CLEARED BITS */
		       	 GPIOB_CRH |= (Copy_u8_Mode << (Copy_u8_PIN * 4));
		       }
		break ;

        /* IN CASE OF HANDLING PORTC PINS */
		case GPIOC :
               
             if(Copy_u8_PIN <= 7)
		       { 
		       	/* CLEARING THE INTENDED FOUR BITS */
		       	 GPIOB_CRL &= ~((0b1111) << (Copy_u8_PIN * 4));
		       	/* STORING THE MODE IN THE PREVIOUSLY CLEARED BITS */
		       	 GPIOB_CRL |= (Copy_u8_Mode << (Copy_u8_PIN * 4));
		       }
		       else if(Copy_u8_PIN >= 8 && Copy_u8_PIN <= 15)
		       { 
		       	/* EVALUATING THE PIN FROM 0 TO 8 */
		       	 Copy_u8_PIN = Copy_u8_PIN - 8 ;
		       	/* CLEARING THE INTENDED FOUR BITS */
		       	 GPIOB_CRH &= ~((0b1111) << (Copy_u8_PIN * 4));
		       	/* STORING THE MODE IN THE PREVIOUSLY CLEARED BITS */
		       	 GPIOB_CRH |= (Copy_u8_Mode << (Copy_u8_PIN * 4));
		       }
		break ;
        
        /* DEFAULT CASE */
		default :
		break ;
	}
}

/* FUNCTION THAT SET THE VALUE OF ANY PIN IN ANY PORT */
void GPIO_voidSetPinVal(u8 Copy_u8_PORT , u8 Copy_u8_PIN , u8 Copy_u8_Value)
{
   switch(Copy_u8_PORT)
   {
   	case GPIOA :  
   	 switch(Copy_u8_Value)
   	 {
   	 	case GPIO_LOW :
   	 	 /* CLEAR THE ENTENDED PIN */
   	 	 CLR_BIT(GPIOA_ODR , Copy_u8_PIN);
   	 	break ;

   	 	case GPIO_HIGH :
   	 	 /* SET THE INTENDED PIN */
   	 	 SET_BIT(GPIOA_ODR , Copy_u8_PIN);
   	 	break ;

   	 	default :
   	 	break ;
   	 }
   	break ;

   	case GPIOB :
   	 switch(Copy_u8_Value)
   	 {
   	 	case GPIO_LOW :
   	 	 /* CLEAR THE ENTENDED PIN */
   	 	 CLR_BIT(GPIOB_ODR , Copy_u8_PIN);
   	 	break ;

   	 	case GPIO_HIGH :
   	 	 /* SET THE INTENDED PIN */
   	 	 SET_BIT(GPIOB_ODR , Copy_u8_PIN);
   	 	break ;

   	 	default :
   	 	break ;
   	 }
   	break ;

   	case GPIOC :
   	 switch(Copy_u8_Value)
   	 {
   	 	case GPIO_LOW :
   	 	 /* CLEAR THE ENTENDED PIN */
   	 	 CLR_BIT(GPIOC_ODR , Copy_u8_PIN);
   	 	break ;

   	 	case GPIO_HIGH :
   	 	 /* SET THE INTENDED PIN */
   	 	 SET_BIT(GPIOC_ODR , Copy_u8_PIN);
   	 	break ;

   	 	default :
   	 	break ;
   	 }
   	break ;

   	default :
   	break ;

   }
}

/* FUNCTION THAT SET THE DIRECTION OF ANY PIN IN ANY PORT */
void GPIO_voidSetPortDir(u8 Copy_u8_PORT , u8 Copy_u8_Position ,  u8 Copy_u8_Mode)
{
	switch(Copy_u8_PORT)
	{
		case GPIOA :
		 if (Copy_u8_Position == LOW)
		  {
		  	 /* FROM PIN0 TO PIN7 */
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN0 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN1 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN2 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN3 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN4 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN5 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN6 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN7 , Copy_u8_Mode);

		  } 
		 else if (Copy_u8_Position == HIGH)
		 {
		 	/* FROM PIN8 TO PIN15 */
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN8  , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN9  , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN10 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN11 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN12 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN13 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN14 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOA , GPIO_PIN15 , Copy_u8_Mode);
		 }
		break ;

		case GPIOB :
		if (Copy_u8_Position == LOW)
		  {
		  	 /* FROM PIN0 TO PIN7 */
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN0 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN1 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN2 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN3 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN4 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN5 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN6 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN7 , Copy_u8_Mode);

		  } 
		 else if (Copy_u8_Position == HIGH)
		 {
		 	/* FROM PIN8 TO PIN15 */
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN8  , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN9  , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN10 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN11 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN12 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN13 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN14 , Copy_u8_Mode);
		  	GPIO_voidSetPinDir(GPIOB , GPIO_PIN15 , Copy_u8_Mode);
		 }
		break ;

		break ;
	}

	
}

/* FUNCTION THAT SET THE VALUE OF ANY PIN IN ANY PORT */
void GPIO_voidSetPortVal(u8 Copy_u8_PORT , u16 Copy_u16_Value)
{
	switch(Copy_u8_PORT)
	{
		case GPIOA :
		 GPIOA_ODR = Copy_u8_Value ;
		break ;

		case GPIOB :
		 GPIOB_ODR = Copy_u8_Value ;
		break ;
		default :
		break ; 

	}
}

/* FUNCTION TO GET THE STATUS OF ANY PIN */
u8 GPIO_u8GetPinValue(u8 Copy_u8_PORT , u8 Copy_u8_PIN )
{ 
	/* LOCAL VARIABLE TO HOLD THE PIN VALUE */
	u8 LOC_U8PinVal = 0 ;

	switch(Copy_u8_PORT)
	{
		case GPIOA :
		 LOC_U8PinVal = GET_BIT(GPIOA_IDR ,Copy_u8_PIN);
		break ;

		case GPIOB :
		 LOC_U8PinVal = GET_BIT(GPIOB_IDR ,Copy_u8_PIN);
		break ;

		case GPIOC :
		 LOC_U8PinVal = GET_BIT(GPIOC_IDR ,Copy_u8_PIN);
		break ;

		default :
		break ;
	}
    
    /* RETURN THE VALUE */
	return LOC_U8PinVal ;
}

/* FUNCTION TO ENABLE THE INTERNAL PULL-UP RESISTOR */
void GPIO_VoidSetPullUp(u8 Copy_u8_PORT , u8 Copy_u8_PIN)
{
	switch(Copy_u8_PORT)
	{
		case GPIOA :
		 CLR_BIT(GPIOA_ODR , Copy_u8_PIN);
		break ;

		case GPIOB :
		 CLR_BIT(GPIOB_ODR , Copy_u8_PIN);
		break ;

		case GPIOC :
		 CLR_BIT(GPIOC_ODR , Copy_u8_PIN);
		break ;

		default :
		break ;
	}

}

/* FUNCTION TO ENABLE THE INTERNAL PULL-DOWN RESISTOR */
void GPIO_VoidSetPullDown(u8 Copy_u8_PORT , u8 Copy_u8_PIN)
{
	switch(Copy_u8_PORT)
	{
		case GPIOA :
		 SET_BIT(GPIOA_ODR , Copy_u8_PIN);
		break ;

		case GPIOB :
		 SET_BIT(GPIOB_ODR , Copy_u8_PIN);
		break ;

		case GPIOC :
		 SET_BIT(GPIOC_ODR , Copy_u8_PIN);
		break ;

		default :
		break ;
	}

}