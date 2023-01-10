/****************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                  */
/* DATE     : 22 SEP 2021                                       */
/* VERSION  : V01                                               */
/****************************************************************/
void MSPI_voidSpiInit(void)
{
	/* SET PHASE    */
	#if   SPI_CLK_PHASE == CLK_PHASE_WRITE_READ
	 SET_BIT(SPI -> CR1 , 0);

	#elif SPI_CLK_PHASE == CLK_PHASE_READ_WRITE
	 CLR_BIT(SPI -> CR1 , 0);
	#endif

	/* SET POLARITY */
	#if   SPI_CLK_POLARITY == CLK_POLARITY_LOW
	 CLR_BIT(SPI -> CR1 , 1);

	#elif SPI_CLK_POLARITY   CLK_POLARITY_HIGH
	 SET_BIT(SPI -> CR1 , 1);
	#endif

    /* SET AS MASTER */
	#if SPI_MODE   == MASTER_MODE
	 SET_BIT(SPI -> CR1 , 2);

	 /* ENABLE SSM */
	 SET_BIT(SPI -> CR1 , 9);

	 /* DERIVE SSM TO HIGH ( PIN NOT ACTIVATED )*/
     SET_BIT(SPI -> CR1 , 8);

	#elif SPI_MODE   == SLAVE_MODE
	 CLR_BIT(SPI -> CR1 , 2);

	 /* ENABLE SSM */
	 SET_BIT(SPI -> CR1 , 9);

	 /* DERIVE SSM TO LOW ( PIN ACTIVATED )*/
     CLR_BIT(SPI -> CR1 , 8);

	#endif

    /* SET THE PRESCALLER VALUE */
    #if   SPI_PRESCALLER  == PRESCALLER_2
	 CLR_BIT(SPI -> CR1 , 3);
	 CLR_BIT(SPI -> CR1 , 4);
	 CLR_BIT(SPI -> CR1 , 5);

    #elif SPI_PRESCALLER  == PRESCALLER_4
	 SET_BIT(SPI -> CR1 , 3);
	 CLR_BIT(SPI -> CR1 , 4);
	 CLR_BIT(SPI -> CR1 , 5);

    #elif SPI_PRESCALLER  == PRESCALLER_8
	 CLR_BIT(SPI -> CR1 , 3);
	 SET_BIT(SPI -> CR1 , 4);
	 CLR_BIT(SPI -> CR1 , 5);

    #elif SPI_PRESCALLER  == PRESCALLER_16
	 SET_BIT(SPI -> CR1 , 3);
	 SET_BIT(SPI -> CR1 , 4);
	 CLR_BIT(SPI -> CR1 , 5);

    #elif SPI_PRESCALLER  == PRESCALLER_32
	 CLR_BIT(SPI -> CR1 , 3);
	 CLR_BIT(SPI -> CR1 , 4);
	 SET_BIT(SPI -> CR1 , 5);

    #elif SPI_PRESCALLER  == PRESCALLER_64
	 SET_BIT(SPI -> CR1 , 3);
	 CLR_BIT(SPI -> CR1 , 4);
	 SET_BIT(SPI -> CR1 , 5);

    #elif SPI_PRESCALLER  == PRESCALLER_128
	 CLR_BIT(SPI -> CR1 , 3);
	 SET_BIT(SPI -> CR1 , 4);
	 SET_BIT(SPI -> CR1 , 5);

	#elif SPI_PRESCALLER  == PRESCALLER_256
	 SET_BIT(SPI -> CR1 , 3);
	 SET_BIT(SPI -> CR1 , 4);
	 SET_BIT(SPI -> CR1 , 5);
    #endif
    
    /* SET DATA ORDER */
    #if   SPI_DATA_ORDER  == LSB_FIRST
	 SET_BIT(SPI -> CR1 , 7);

    #elif SPI_DATA_ORDER  == MSB_FIRST
	 CLR_BIT(SPI -> CR1 , 7);
    #endif
    
    /* SELECT RECEIVE ONLY MODE OR NOT */
    #if   RECEIVE_ONLY_MODE == DISABLE_RECEIVE_ONLY
	 CLR_BIT(SPI -> CR1 , 10);

    #elif RECEIVE_ONLY_MODE == ENABLE_RECEIVE_ONLY
	 SET_BIT(SPI -> CR1 , 10);
	#endif

	/* SET DATA SIZE */
    #if   SPI_DATA_SIZE == DATA_8BIT
	 CLR_BIT(SPI -> CR1 , 11);

    #elif SPI_DATA_SIZE == DATA_16BIT
	 SET_BIT(SPI -> CR1 , 9);
    #endif
	
	/* ENABLE SPI */
	SET_BIT(SPI -> CR1 , 6);
}


void MSPI_voidSpiSendReceiveByte(u8 Copy_u8DataToSend , u8 *Copy_u8Received)
{
	
	/* DERIVE THE SS PIN TO LOW */
	GPIO_voidSetPinVal(SLAVE_PORT , SLAVE_PIN , GPIO_LOW);

	/* COPY DATA IN THE SPI REGISTER TO BE SENT */
	SPI -> DR = Copy_u8DataToSend ;

	/* WAIT UNTILL THE SPI IS NOT BUSY */
    while(GET_BIT(SPI -> SR , 7) == 1);

    *Copy_u8Received = SPI -> DR ;
    
    /* DERIVE THE SS PIN TO HIGH */
	GPIO_voidSetPinVal(SLAVE_PORT , SLAVE_PIN , GPIO_HIGH);

}

