/*********************************************************/
/*       AUTHOR : MOSTAFA MOHAMED                        */
/*       DATE   : 23 MAY 2021                            */
/*       VERSION : V01                                   */
/*********************************************************/

/* M --> MCAL LAYER */
void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber)
{
	/* EXTERNAL INTERRUPTS 0 --> 31 */
	if( Copy_u8IntNumber <= 31)
	{
		/* SET THE BIT FOR PASSED INTERRUPT SOURCE */
		NVIC_ISRE0 = (1 << Copy_u8IntNumber);
	}
	/* EXTERNAL INTERRUPTS 32 --> 59 */
	else if (Copy_u8IntNumber <= 59) 
	{
		/* EVALUATING THE BIT NUMBER */
		Copy_u8IntNumber -= 32 ;
		/* SET THE BIT FOR PASSED INTERRUPT SOURCE */
		NVIC_ISRE1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* RETURN ERROR */
	}
}

void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber)
{
	/* EXTERNAL INTERRUPTS 0 --> 31 */
	if( Copy_u8IntNumber <= 31)
	{
		/* DISABLE THE  INTERRUPT SOURCE */
		NVIC_ICRE0 = (1 << Copy_u8IntNumber);
	}
	/* EXTERNAL INTERRUPTS 32 --> 59 */
	else if ( Copy_u8IntNumber <= 59)
	{
		/* EVALUATING THE BIT NUMBER */
		Copy_u8IntNumber -= 32 ;
		/* DISABLE THE INTERRUPT SOURCE */
		NVIC_ICRE1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* RETURN ERROR */
	}
}

void MNVIC_VoidSetpendingFlag(u8 Copy_u8IntNumber)
{
	/* EXTERNAL INTERRUPTS 0 --> 31 */
	if( Copy_u8IntNumber <= 31)
	{
		/* SET THE PENDING FLAG */
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	/* EXTERNAL INTERRUPTS 32 --> 59 */
	else if ( Copy_u8IntNumber <= 59)
	{
		/* EVALUATING THE BIT NUMBER */
		Copy_u8IntNumber -= 32 ;
		/* SET THE PENDING FLAG */
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* RETURN ERROR */
	}
}

void MNVIC_VoidClearPendingFlag(u8 Copy_u8IntNumber)
{
	/* EXTERNAL INTERRUPTS 0 --> 31 */
	if( Copy_u8IntNumber <= 31)
	{
		/* CLEAR THE PENDING FLAG */
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	/* EXTERNAL INTERRUPTS 32 --> 59 */
	else if ( Copy_u8IntNumber <= 59)
	{
		/* EVALUATING THE BIT NUMBER */
		Copy_u8IntNumber -= 32 ;
		/* CLEAR THE PENDING FLAG */
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* RETURN ERROR */
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_Result ; 

	/* EXTERNAL INTERRUPTS 0 --> 31 */
	if( Copy_u8IntNumber <= 31)
	{
		/* GET INTERRUPT STATUS */
		Local_Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
	}
	/* EXTERNAL INTERRUPTS 32 --> 59 */
	else if ( Copy_u8IntNumber <= 59)
	{
		/* EVALUATING THE BIT NUMBER */
		Copy_u8IntNumber -= 32 ;
		/* GET INTERRUPT STATUS */
		Local_Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
	}
	else
	{
		/* RETURN ERROR */ 
	}
	
	return Local_Result ;
}

void MNVIC_VoidSetPririty(u8 Copy_u8IntId , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority )
{
	/* EVALUATE THE VALUE OF PRIORITY SYSTEM  */
	SCB_AIRCR = NVIC_PRIORITY_DISTRIBUTION ;

	#if (NVIC_PRIORITY_DISTRIBUTION == FOUR_BITS_GROUP_NOSUB)
	{
		/* STORING THE VALUE OF INTERRUPT PRIORITY IN THE MSB */
		NVIC_IPR[Copy_u8IntId] = ((Copy_u8GroupPriority) << 4);

	}
	#elif (NVIC_PRIORITY_DISTRIBUTION == THREE_BITS_GROUP_1SUB)
	{
		/* *************************************************************/
		/*   WE NEED TO SHIFT THE GROUP PRIORITY TO LEFT BY 1          */
		/*   THEN ORRING THE RESULT WITH THE ONE BIT OF SUB PRIORITY   */
		/*   THE LAST OPERATION IS TO STORE THE VALUE IN THE MSB       */
		/***************************************************************/
		NVIC_IPR[Copy_u8IntId] = ((((Copy_u8GroupPriority) << 1) | Copy_u8SubPriority) << 4);
	}
	#elif (NVIC_PRIORITY_DISTRIBUTION == TWO_BITS_GROUP_2SUB)
	{
		/* *************************************************************/
		/*   WE NEED TO SHIFT THE GROUP PRIORITY TO LEFT BY 2          */
		/*   THEN ORRING THE RESULT WITH THE TWO BIT OF SUB PRIORITY   */
		/*   THE LAST OPERATION IS TO STORE THE VALUE IN THE MSB       */
		/***************************************************************/
		NVIC_IPR[Copy_u8IntId] = ((((Copy_u8GroupPriority) << 2) | Copy_u8SubPriority) << 4);
		
	}
	#elif (NVIC_PRIORITY_DISTRIBUTION == ONE_BITS_GROUP_3SUB)
	{
		/* *************************************************************/
		/*   WE NEED TO SHIFT THE GROUP PRIORITY TO LEFT BY 3          */
		/*   THEN ORRING THE RESULT WITH THE THREE BIT OF SUB PRIORITY */
		/*   THE LAST OPERATION IS TO STORE THE VALUE IN THE MSB       */
		/***************************************************************/
		NVIC_IPR[Copy_u8IntId] = ((((Copy_u8GroupPriority) << 3) | Copy_u8SubPriority) << 4);
	}
	#elif (NVIC_PRIORITY_DISTRIBUTION == NO_GROUP_4SUB)
	{
		/* STORING THE VALUE OF INTERRUPT PRIORITY IN THE MSB */
		NVIC_IPR[Copy_u8IntId] = ((Copy_u8SubPriority) << 4);

	}
	#else
	{
		/* DO NOTHING */
	}
	#endif
}