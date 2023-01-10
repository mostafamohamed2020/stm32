/***************************************************************/
/* AUTHOR  : MUSTAFA MUHAMMED                                  */
/* DATE    : 22 SEP 2021                                       */
/* VERSION : V01                                               */
/***************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include"SYSTICK_interface.h"


/* SYNCRONOUS FUNCTION TO SEND DATA */
void HSTP_voidSendSyncronous(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter ; 

	u8 Local_u8Bit ; 

	/* THESE FOR LOOP USED TO SHIFT THE BITS */
	for (Local_u8Counter = 7 ; Local_u8Counter >= 0 ; Local_u8Counter--)
	{
		/* GET THE CORRESPONDING BIT TO BE SENT */
		Local_u8Bit = GET_BIT(Copy_u8DataToSend , Local_u8Counter);

		/* SEND BIT BY BIT STARTING FROM MSB */
		GPIO_voidSetPinVal(HSTP_SERIAL_DATA , Local_u8Bit);

		/* GENERATE PULSE ON SHIFT CLOCK */
		GPIO_voidSetPinVal(HSTP_SHIFT_CLOCK , GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		GPIO_voidSetPinVal(HSTP_SHIFT_CLOCK , GPIO_LOW);
        MSTK_voidSetBusyWait(1);
	}

	/* GENERATE CLOCK ON STORE CLOCK TO SEND DATA TO PHYSICAL PINS */
	GPIO_voidSetPinVal(HSTP_STORAGE_CLOCK , GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	GPIO_voidSetPinVal(HSTP_STORAGE_CLOCK , GPIO_LOW);
    MSTK_voidSetBusyWait(1);

	
}

