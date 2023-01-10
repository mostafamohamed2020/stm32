/*************************************************/
/* AUTHOR    : MUSTAFA MUHAMMED                  */
/* DATE      : 3 SEPTEMTER 2021                  */
/* VERSION   : V01                               */
/*************************************************/

/* GLOBAL POINTER TO FUNCTION */
static void (*MSYSTICK_CALL_BACK) (void)

static u8 INTERVAL_MODE ; 

/* FUNCTION TO CONFIGURE THE CLOCK SOURCE OF SYSTICK */
void MSTK_voidInit(void)
{
    /*  APPLY SOURCE CLOCK  
        DISABLE SYSTICK INTERRUPT  
        DISABLE SYSTICK               */

	#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_CLK
	  SET_BIT(SYSTICK->CTRL , 2);

	#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_BY8_CLK
	  CLR_BIT(SYSTICK->CTRL , 2);
	#else
	  #error"WRONG CLOCK SOURCE";
	#endif
    
    /* DISABLE INTERRUPT */
	CLR_BIT(SYSTICK->CTRL , 1);
    
    /* DISABLE SYSTICK */
	CLR_BIT(SYSTICK->CTRL , 0);
}

/* FUNCTION FOR SYNCRONOUS CALL */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{ 
	/* STORE THE VALUE IN LOAD REGISTER */
	SYSTICK->LOAD = Copy_u32Ticks ;

	/* ENABLE SYSTICK */
	SET_BIT(SYSTICK->CTRL , 0);

    /* (POLLING) WAIT UNTILL THE FLAG RAISED */
	while(GET_BIT(SYSTICK->CTRL , 16) == 0);

	/* STOP THE TIMER AGAIN */
	CLR_BIT(SYSTICK->CTRL , 0);
 
    /* RESTART LOAD AND VALUE REGISTERS */
	SYSTICK->LOAD = 0 ;
	SYSTICK->VAL  = 0 ;
}

/* INTERRUPT ONLY FOR SINGLE TIME (ASYNCRONOUS) */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_ptr) (void))
{
	/* STORE THE VALUE IN LOAD REGISTER */
	SYSTICK->LOAD = Copy_u32Ticks ;

	/* ENABLE SYSTICK */
	SET_BIT(SYSTICK->CTRL , 0);

    /* SET INTERVAL MODE TO SINGLE */
    INTERVAL_MODE = SINGLE_INTERVAL ;

    /* POINTS TO THE INTERRUPT FUNCTION*/
    MSYSTICK_CALL_BACK = Copy_ptr ;

    /* ENABLE INTERRUPT */
	SET_BIT(SYSTICK->CTRL , 1); 
}

/* INTERRUPT FOR PERIODIC TIMES (ASYNCRONOUS) */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr) (void))
{
    /* STORE THE VALUE IN LOAD REGISTER */
	SYSTICK->LOAD = Copy_u32Ticks ;
    
    /* ENABLE SYSTICK */
	SET_BIT(SYSTICK->CTRL , 0);

	/* SET INTERVAL MODE TO SINGLE */
    INTERVAL_MODE = PERIODIC_INTERVAL ;
    
    /* MAKE CALL BACK POINTS TO THE PASSED FUNCTION */
    MSYSTICK_CALL_BACK = Copy_ptr ;

    /* ENABLE INTERRUPT */
	SET_BIT(SYSTICK->CTRL , 1);
}

/* FUNCTION TO STOP THE TIMERS */
void MSTK_voidStopTimer()
{
    /* ENABLE SYSTICK */
	CLR_BIT(SYSTICK->CTRL , 0);

	/* ENABLE INTERRUPT */
	CLR_BIT(SYSTICK->CTRL , 1);

    /* RESTART LOAD AND VALUE REGISTERS */
    SYSTICK->LOAD = 0 ;
    SYSTICK->VAL  = 0 ;
}

/* FUNCTION TO GET COUNTED TIME  */
u32 MSTK_u32GetElapsedTime(void)
{
   u32 Local_Elapsed_Val = 0 ;

   Local_Elapsed_Val = SYSTICK->LOAD - SYSTICK->VAL ;

   return Local_Elapsed_Val ;
}

/* FUNCTION TO GET REMAINING TIME */
u32 MSTK_u32GetRemainingTimed(void)
{
   u32 Local_Remain_Time = 0 ;

   Local_Remain_Time = SYSTICK->VAL ;

   return Local_Remain_Time ;
}

/* SYSTICK HANDLER */
void SysTick_Handler(void)
{
	if (INTERVAL_MODE == SINGLE_INTERVAL)
	{
	   /* DISABLE INTERRUPT */
	   CLR_BIT(SYSTICK->CTRL , 1);
	   
	   /* DISABLE TIMER     */
       CLR_BIT(SYSTICK->CTRL , 0);
	   
	   /* CLEAR LOAD AND VALUE REGISTERS */
       SYSTICK->LOAD = 0 ;
	   SYSTICK->VAL  = 0 ;
	}

	MSYSTICK_CALL_BACK();
}