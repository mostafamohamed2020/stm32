/******************************************************/
/* AUTHOR    : MUSTAFA MUHAMMED                       */
/* DATE      : 29 AUGUST 2021                         */
/* VERSION   : V01                                    */
/******************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

/* GLOBAL POINTER TO EXTI0 */
static void (*EXTI0CallBack)(void);


/* FUNCTION TO INITIALIZE PIN FOR EXTERNAL INTERRUPT */
void MEXTI_voidInitExtrnalInt()
{
	
    #if EXTI_MODE == RISING_EDGE 
     SET_BIT(EXTI -> RTSR , EXTI_LINE);

    #elif EXTI_MODE == FALLING_EDGE
     SET_BIT(EXTI -> FTSR , EXTI_LINE);

    #elif EXTI_MODE == ANY_CHANGE
     SET_BIT(EXTI -> FTSR , EXTI_LINE);
     SET_BIT(EXTI -> RTSR , EXTI_LINE);

    #else  
    #error" Wrong Trigger Action";

    #endif
    
    /* DISABLE THE INTERRUPT */ 
    CLR_BIT(EXTI -> IMR , Copy_u8EXTILine );

}

/* FUNCTION TO ENABLE EXTERNAL INTERRUPT */
void MEXTI_voidEnableExtI(u8 Copy_u8EXTILine)
{
	
	 SET_BIT(EXTI -> IMR , Copy_u8EXTILine );
}

/* FUNCTION TO DISABLE EXTERNAL INTERRUPT */
void MEXTI_voidDisableExtI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI -> IMR , Copy_u8EXTILine );
}

/* INITIATE SOFTWARE TRIGGER */ 
void MEXTI_voidSWTrigger(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> SWIER , Copy_u8EXTILine);
}

/* FUNCTION TO CHANGE THE INTERRUPT EVENT IN RUN TIME */
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING_EDGE  : 
		 SET_BIT(EXTI -> RTSR , Copy_u8EXTILine);
		break ;
		case FALLING_EDGE :
		 SET_BIT(EXTI -> FTSR , Copy_u8EXTILine); 
		break ;
		case ANY_CHANGE   : 
		 SET_BIT(EXTI -> RTSR , Copy_u8EXTILine);
		 SET_BIT(EXTI -> FTSR , Copy_u8EXTILine);
		break ;

		default :
		break ;
	}
}

void MEXTI_voidSetCallBack(void (*ptr) (void))
{
	EXTI0CallBack = ptr ; 
}

void EXTI0_IRQHandler(void)
{
	EXTI0CallBack();

	/* CLEAR THE PENDING FLAG OF INT0 BY WRITING 1 TO THE PENDING FLAG */
	SET_BIT(EXTI -> PR , LINE0);
}