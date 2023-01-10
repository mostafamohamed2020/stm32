/********************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                          */
/* DATE     : 14 SEP 2021                               */
/* VERSION  : V01                                       */
/********************************************************/

/* FILE THAT CONTAINS THE SONG SAMPLES */
#include"Song.h"

/* VOLATILE IS MANDATORY BECAUSE THE VARIABLE CHANGE IN THE ISR */
volatile u32 Song_counter ;

void DAC_CALLBACK()
{
	    /* EQUALS THE DAC_PORT TO SAMPLE VALUE */
	    GPIO_voidSetPortVal(DAC_PORT , Amaren_raw[Song_counter]);
    
        /* MOVE TO THE NEXT SAMPLE */
	    Song_counter++ ;

	if (Song_counter == Song_Length) 
	{
		Song_counter = 0 ;
	}
	
}

/* FUNCTION TO INITIATE THE DAC */
void MDAC_voidInit()
{
	/* INITIATE THE DAC PINS AS OUTPUT PINS */
	GPIO_voidSetPortDir(DAC_PORT , DAC_POSITION , GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL);

	/* INITIATE THE SYSTICK */
	MSTK_voidInit();

}

/* FUNCTION TO PLAY THE SONG */
void MDAC_voidPlay()
{
	
	/* TAKE A DELAY WITH 125 MICRI SEC (8000 SAMPLE/SEC) */
	MSTK_voidSetIntervalPeriodic(125 , DAC_CALLBACK);

}