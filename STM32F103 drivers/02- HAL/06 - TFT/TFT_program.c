/*****************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                   */
/* DATE     : 23 SEP 2021                                        */
/* VERSION  : V01                                                */
/*****************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include"SYSTICK_interface.h"
#include"SPI_interface.h"

#include"TFT_interface.h"
#include"TFT_private.h"
#include"TFT_config.h"


/* FUNCTION TO INITIALIZE TFT DISPLAY */
void HTFT_voidInit(void)
{
/*************************************************************************************************************/
/******************************************* TFT INIT SEQUENCE ***********************************************/
/* ------------        --------------        ---------------        ---------------        ---------------   */
/*| RESET PUSLE | --> | SLEEP OUT COM | --> | 150 MSEC DELAY | --> | COLOR MODE COM | --> | DISPLAY ON COM | */
/* ------------        --------------        ---------------        ---------------        ---------------   */
/*************************************************************************************************************/	     

    /* RESET PULSE */
	GPIO_voidSetPinVal(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	GPIO_voidSetPinVal(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_LOW);
    MSTK_voidSetBusyWait(1);
    GPIO_voidSetPinVal(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_HIGH);
    MSTK_voidSetBusyWait(100);
    GPIO_voidSetPinVal(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_LOW);
    MSTK_voidSetBusyWait(100);
    GPIO_voidSetPinVal(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_HIGH);
    MSTK_voidSetBusyWait(120000);

	/* SLEEP OUT COMMAND */
    HTFT_WriteCommand(SLEEP_OUT_COMMAND);

    /* DELAY 150 MSEC */
    MSTK_voidSetBusyWait(150);

    /* COLOR MODE COMMAND */
    HTFT_WriteCommand(COLOR_MODE_COMMAND);

    /* COLOR AS DATA */
    HTFT_WriteData(COLOR_RGB_565);

    /* DISPLAY ON COMMAND */
    HTFT_WriteCommand(DISPLAY_ON_COMMAND);

}

/* FUNCTION TO DISPLAY IMAGE */
void HTFT_voidDisplayImage(const u16* Copy_u16_Image)
{
	u8 Img_counter = 0 ;
	/* SET X BOARDERS THAT WILL BE USED */
	HTFT_WriteCommand(SET_X_ADDRESS_COMMAND);
	/* PREVIOUS COMMAND PARAMETERS */
	/* TWO BYTES START */
    HTFT_WriteData(0);
    HTFT_WriteData(0);
    /* TWO BYTES END */
    HTFT_WriteData(0);
    HTFT_WriteData(127);


    /* SET X BOARDERS THAT WILL BE USED */
    HTFT_WriteCommand(SET_Y_ADDRESS_COMMAND);
	/* PREVIOUS COMMAND PARAMETERS */
	/* TWO BYTES START */
    HTFT_WriteData(0);
    HTFT_WriteData(0);
    /* TWO BYTES END */
    HTFT_WriteData(0);
    HTFT_WriteData(159);

    /* COMMAND TO START WRITE TO LCD (TFT) */
    HTFT_WriteCommand(RAM_WRITE_COMMAND);

	for (Img_counter = 0; Img_counter < ( NO_OF_ROWS * NO_OF_COL ) ; Img_counter++)
	{
		/* SEND THE HIGH BYTE (MSB) */
		HTFT_WriteData( Copy_u16_Image[Img_counter] >> 8 );
        
        /* SEND THE LOW BYTE (LSB) */
        HTFT_WriteData( Copy_u16_Image[Img_counter] & 0x00ff );
	}
}

/* FUNCTION TO DISPLAY SPECIFIC COLOR */
void HTFT_voidFillColor(u16 Copy_u16Color)
{
	u8 Color_counter = 0 ;

	/* SET X BOARDERS THAT WILL BE USED */
	HTFT_WriteCommand(SET_X_ADDRESS_COMMAND);
	/* PREVIOUS COMMAND PARAMETERS */
	/* TWO BYTES START */
    HTFT_WriteData(0);
    HTFT_WriteData(0);
    /* TWO BYTES END */
    HTFT_WriteData(0);
    HTFT_WriteData(127);


    /* SET X BOARDERS THAT WILL BE USED */
    HTFT_WriteCommand(SET_Y_ADDRESS_COMMAND);
	/* PREVIOUS COMMAND PARAMETERS */
	/* TWO BYTES START */
    HTFT_WriteData(0);
    HTFT_WriteData(0);
    /* TWO BYTES END */
    HTFT_WriteData(0);
    HTFT_WriteData(159);

    /* COMMAND TO START WRITE TO LCD (TFT) */
    HTFT_WriteCommand(RAM_WRITE_COMMAND);

	for (Color_counter = 0; Color_counter < ( NO_OF_ROWS * NO_OF_COL ) ; Color_counter++)
	{
		/* SEND THE HIGH BYTE (MSB) */
		HTFT_WriteData( Copy_u16Color >> 8 );
        
        /* SEND THE LOW BYTE (LSB) */
        HTFT_WriteData( Copy_u16Color & 0x00ff );
	}

}


/* FUNCTION TO DISPLAY RECTANGLE */
void HTFT_voidDrawRect(u16 Copy_u16Color , u16 Copy_u16X1 , u16 Copy_u16X2 , u16 Copy_u16Y1 , u16 Copy_u16Y2 )
{
	u8 Color_counter = 0 ;

	u16 Rec_size = (Copy_u16X2 - Copy_u16X1) * (Copy_u16Y2 - Copy_u16Y1) ;

	/* SET X BOARDERS THAT WILL BE USED */
	HTFT_WriteCommand(SET_X_ADDRESS_COMMAND);
	/* PREVIOUS COMMAND PARAMETERS */
	/* TWO BYTES START */
    HTFT_WriteData(0);
    HTFT_WriteData(0);
    /* TWO BYTES END */
    HTFT_WriteData(Copy_u16X1);
    HTFT_WriteData(Copy_u16X2);


    /* SET X BOARDERS THAT WILL BE USED */
    HTFT_WriteCommand(SET_Y_ADDRESS_COMMAND);
	/* PREVIOUS COMMAND PARAMETERS */
	/* TWO BYTES START */
    HTFT_WriteData(0);
    HTFT_WriteData(0);
    /* TWO BYTES END */
    HTFT_WriteData(Copy_u16Y1);
    HTFT_WriteData(Copy_u16Y2);

    /* COMMAND TO START WRITE TO LCD (TFT) */
    HTFT_WriteCommand(RAM_WRITE_COMMAND);

	for (Color_counter = 0; Color_counter < Rec_size ; Color_counter++)
	{
		/* SEND THE HIGH BYTE (MSB) */
		HTFT_WriteData( Copy_u16Color >> 8 );
        
        /* SEND THE LOW BYTE (LSB) */
        HTFT_WriteData( Copy_u16Color & 0x00ff );
	}

}




/* FUNCTION TO WRITE COMMAND */
static void HTFT_WriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp ; 

	/* SET A0 PIN OF TFT TO LOW */
	GPIO_voidSetPinVal(TFT_A0_PORT , TFT_A0_PIN , GPIO_LOW);

	/* SEND COMMAND OVER SPI */
	void MSPI_voidSpiSendReceiveByte(Copy_u8Command , &Local_u8Temp);
}

/* FUNCTION TO WRITE DATA */
static void HTFT_WriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp ; 

	/* SET A0 PIN OF TFT TO HIGH */
	GPIO_voidSetPinVal(TFT_A0_PORT , TFT_A0_PIN , GPIO_HIGH);

	/* SEND DATA OVER SPI */
	void MSPI_voidSpiSendReceiveByte(Copy_u8Data , &Local_u8Temp);

}

