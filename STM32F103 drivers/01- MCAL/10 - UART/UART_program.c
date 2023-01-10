/*******************************************************************/
/* AUTHOR  : MUSTAFA MUHAMMED                                      */
/* DATE    : 24 SEP 2021                                           */
/* VERSION : V01                                                   */
/*******************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"UART_interface.h"

/* FUNCTION TO INITIALIZE UART */
void MUART_voidInit(void)
{
	
	/* BAUD RATE VALUE */
	/* HINT : THIS VALUES WHEN FCPU IS 8 MEGA */
	/******************************************/
	/*   BRR_VALUE  = (F_CPU)/(BR * 16)       */
	/******************************************/

	#if   BAUD_RATE == BR_9600
	 (UART -> BRR) = ((0x034 << 4) | (0x0001));

	#elif BAUD_RATE == BR_4800
	 (UART -> BRR) = ((0x068 << 4) | (0x0003));

	#elif BAUD_RATE == BR_115200
	 (UART -> BRR) = ((0x02B << 4) | (0x0008));
    #endif

	/* ENABLE TRANSMITTER */
    SET_BIT(UART -> CR1 , 3);

	/* ENABLE RECEIVER */
    SET_BIT(UART -> CR1 , 2);

	/* ENABLE UART */
	SET_BIT(UART -> CR1 , 13);

	/* UART INTERRUPT */
	#if   UART_INTERRUPT == DISABLE_UART_INTERRUPT
	 CLR_BIT(UART -> CR1 , 8); /* DISABLE PEIE */
	 CLR_BIT(UART -> CR1 , 7); /* DISABLE TXE  */
	 CLR_BIT(UART -> CR1 , 6); /* DIASBLE TCE  */
	 CLR_BIT(UART -> CR1 , 5); /* DISABLE RXE  */

	#elif UART_INTERRUPT == ENABLE_UART_INTERRUPT
	 SET_BIT(UART -> CR1 , 8); /* ENABLE PEIE */
	 SET_BIT(UART -> CR1 , 7); /* ENABLE TXE  */
	 SET_BIT(UART -> CR1 , 6); /* ENABLE TCE  */
	 SET_BIT(UART -> CR1 , 5); /* ENABLE RXE  */
	#endif
    
    /* STOP BITS CONFIGURATION */
	#if  STOP_BITS_NO  == ONE_STOP_BIT
	 CLR_BIT(UART -> CR2 , 12);
	 CLR_BIT(UART -> CR2 , 13);

	#elif STOP_BITS_NO == TWO_STOP_BIT
	 CLR_BIT(UART -> CR2 , 12);
	 SET_BIT(UART -> CR2 , 13);
	#endif

	/* CLOCK ENABLE */
	#if   UART_MODE == ASYNCRONOUS_MODE
	 CLR_BIT(UART -> CR2 , 11);

	#elif UART_MODE == SYNCRONOUS_MODE
	 set_BIT(UART -> CR2 , 11);

	 /* CLOCK POLARITY */
	 #if   UART_CLOCK_POLARITY == IDLE_HIGH
	  SET_BIT(UART -> CR2 , 10);

	 #elif UART_CLOCK_POLARITY == IDLE_LOW
	  CLR_BIT(UART -> CR2 , 10);
	 #endif
	 /* CLOCK PHASE */
	 #if   UART_UART_CLOCK_PHASE == WRITE_THEN_READ
	  SET_BIT(UART -> CR2 , 9);

	 #elif UART_UART_CLOCK_PHASE == READ_THEN_WRITE
	  CLR_BIT(UART -> CR2 , 9);
     #endif 
	#endif 
	
	/* MULTI PROCESSORS MODE */ 
    
	/* PARITY ENABLE */
	#if   PARITY_BIT_STATE == NO_PARITY
	 CLR_BIT(UART -> CR1 , 10);

	#elif PARITY_BIT_STATE == EVEN_PARITY 
	 SET_BIT(UART -> CR1 , 10);
	 CLR_BIT(UART -> CR1 , 9); 

	#elif PARITY_BIT_STATE == ODD_PARITY 
     SET_BIT(UART -> CR1 , 10);
     SET_BIT(UART -> CR1 , 9);
	#endif 

    /* WORD LENGTH */
    #if   DATA_BITS == DATA_8BITS
     CLR_BIT(UART -> CR1 , 12);

    #elif DATA_BITS == DATA_9BITS
     SET_BIT(UART -> CR1 , 12);
    #endif
}

/* FUNCTION TO SEND DATA */
void MUART_voidSendData(u8 *Copy_u8Data)
{
	u8 Local_DataCounter = 0 ;

   /* SEND DATA BYTE BY BYTE  */
   while(Copy_u8Data[Local_DataCounter] != '\0')
   {

   	UART -> DR = Copy_u8Data[Local_DataCounter] ;

   	/* WAIT UNTILL TRANSMISION COMPLETE */
   	while( GET_BIT((UART -> SR) , 6) == 0);
    
    CLR_BIT(UART -> SR , 6); /* CLAER THE FLAG */
    Local_DataCounter++ ;
   } 
}

/* FUNCTION TO RECEIVE DATA */
u8 MUART_u8ReceiveData(void)
{ 
	/* WAIT UNTILL THE RECEIVE COMPLETE */
	while(GET_BIT((UART -> SR ) , 5) == 0);

    CLR_BIT(UART -> SR , 6); /* CLAER THE FLAG */

    return (0xFF && (UART -> DR));

}