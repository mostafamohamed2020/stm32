/********************************************************/
/* AUTHOR  : MUSTAFA MUHAMMED                           */
/* DATE    : 19 SEP 2021                                */
/* VERSION : V01                                        */
/********************************************************/

void (* DMA_Channel1_CallBack)(void) ;

/* FUNCTION TO ENABLE DMA CHANNEL */
void MDMA_voidChannelInit()
{
	/* ENABLE THE CONFIGURED CHANNEL */
	#if   CHANNEL_ID  == CHANNEL_1
	 SET_BIT(DMA -> Channel[CHANNEL_1].CCR , 0);

	#elif CHANNEL_ID  == CHANNEL_2
	 SET_BIT(DMA -> Channel[CHANNEL_2].CCR , 0);

	#elif CHANNEL_ID  == CHANNEL_3
	 SET_BIT(DMA -> Channel[CHANNEL_3].CCR , 0);

	#elif CHANNEL_ID  == CHANNEL_4
	 SET_BIT(DMA -> Channel[CHANNEL_4].CCR , 0);

	#elif CHANNEL_ID  == CHANNEL_5
	 SET_BIT(DMA -> Channel[CHANNEL_5].CCR , 0);

	#elif CHANNEL_ID  == CHANNEL_6
	 SET_BIT(DMA -> Channel[CHANNEL_6].CCR , 0);

	#elif CHANNEL_ID  == CHANNEL_7
	 SET_BIT(DMA -> Channel[CHANNEL_7].CCR , 0);
	#endif

	/* SET THE PRIORITY LEVEL */
	#if   CHANNEL_SOFTWARE_PRIORITY == LOW_PRIORITY
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 12);
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 13);

	#elif CHANNEL_SOFTWARE_PRIORITY == MEDUIM_PRIORITY
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 12);
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 13);

	#elif CHANNEL_SOFTWARE_PRIORITY == HIGH_PRIORITY 
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 12);
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 13);

	#elif CHANNEL_SOFTWARE_PRIORITY == VERY_HIGH_PRIORITY
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 12);
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 13);
	#endif 

	/* SET THE MEMORY SIZE */
	#if   MEMORY_SIZE == MEMORY_SIZE_8BIT
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 10);
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 11);

	#elif MEMORY_SIZE == MEMORY_SIZE_16BIT
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 10);
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 11);

	#elif MEMORY_SIZE == MEMORY_SIZE_32BIT
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 10);
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 11);
	#endif

	/* SET THE PREPHIRAL SIZE */
	#if   PREPHIRAL_SIZE == PREPHIRAL_SIZE_8BIT
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 8);
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 9);

	#elif PREPHIRAL_SIZE == PREPHIRAL_SIZE_16BIT
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 8);
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 9);

	#elif PREPHIRAL_SIZE == PREPHIRAL_SIZE_32BIT
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 8);
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 9);
	#endif

	/* MEMORY INCREMENT MODE */
	#if   MEMORY_INCREMENT_MODE == ENABLE_MEMORY_INCREMENT
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 7);

	#elif MEMORY_INCREMENT_MODE == DISABLE_MEMORY_INCREMENT
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 7);
	#endif

	/* PREPHIRAL INCREMENT MODE */
	 #if   PREPHIRAL_INCREMENT_MODE == ENABLE_PREPHIRAL_INCREMENT
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 6);

	#elif PREPHIRAL_INCREMENT_MODE == DISABLE_PREPHIRAL_INCREMENT
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 6);
	#endif

	/* CIRCULAR MODE */
	#if   CIRCULAR_MODE == ENABLE_CIRCULAR_MODE
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 5);

	#elif CIRCULAR_MODE == DISABLE_CIRCULAR_MODE
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 5);
	#endif

    /* DATA TRANSFER DIRECTION */
	#if   TRANSFER_DIRECTION == FROM_MEMORY_TO_MEMORY
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 4);

	#elif TRANSFER_DIRECTION == FROM_PREPHIRAL_TO_MEMORY
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 4);

	#elif TRANSFER_DIRECTION == FROM_MEMORY_TO_PREPHIRAL
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 4);
	 #endif

	/* COMPLETE DATA TRANSFER INTERRUPT */
	#if   TRANSFER_INTERRUPT_MODE == ENABLE_COMPLETE_TRANSFER_INTERRUPT
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 1);

	#elif TRANSFER_INTERRUPT_MODE == DISABLE_COMPLETE_TRANSFER_INTERRUPT
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 1);
    #endif

	/* HALF DATA TRANSFER INTERRUPT */
	#if   HALF_TRANSFER_INTERRUPT_MODE == ENABLE_HALF_TRANSFER_INTERRUPT
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 2);

	#elif HALF_TRANSFER_INTERRUPT_MODE == DISABLE_HALF_TRANSFER_INTERRUPT
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 2);
    #endif

	/* TRANSFER ERROR INTERRUPT */
	#if   ERROR_INTERRUPT_MODE == DISABLE_TRANSFER_ERROR__INTERRUPT
	 SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 3);

	#elif TRANSFER_INTERRUPT_MODE == ENABLE_TRANSFER_ERROR__INTERRUPT
	 CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 3);
    #endif


}

/* FUNCTION TO SET SOURCE / DISTINATION ADDRESSES */
void MDMA_voidSetAddresses(u32 * Copy_ptru32SourceAddress , u32 * Copy_ptru32DestinationAddress , u16 Copy_u16BlockSize)
{
	/* CHANNEL MUST BE BLOCKED UNTILL THE ADDRESSES ASSIGNED */
	CLR_BIT(DMA -> Channel[CHANNEL_ID].CCR , 0);
    
    /* ASSIGN THE ADDRESSES TO CHANNEL REGISTERS */
    DMA -> Channel[CHANNEL_ID].CPAR = Copy_ptru32SourceAddress ;
    DMA -> Channel[CHANNEL_ID].CMAR = Copy_ptru32DestinationAddress ;

    /* ASSIGN THE BLOCK LENGTH */
    DMA -> Channel[CHANNEL_ID].CNDTR = Copy_u16BlockSize ;

    /* ENABLE THE CHANNEL AGAIN */
	SET_BIT(DMA -> Channel[CHANNEL_ID].CCR , 0);
}

void MDMA_voidSetDMACallBack(void (*ptr)(void))
{
	DMA_Channel1_CallBack = ptr ;
}


void DMA1_Channel1_IRQHandler(void)
{
	DMA_Channel1_CallBack();
}