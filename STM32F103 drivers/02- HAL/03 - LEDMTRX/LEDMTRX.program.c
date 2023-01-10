/****************************************************************/
/*   AUTHOR  : MUSTAFA MUHAMMED                                 */
/*   DATE    : 7 SEP 2021                                       */
/*   VERSION : V01                                              */
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICk_interface.h"

#include "LEDMTRX_interface.h"
#include "LEDMTRX_private.h"
#include "LEDMTRX_config.h"

static COL_ARRAY[] = {LEDMTRX_COL0_PIN , LEDMTRX_COL1_PIN , LEDMTRX_COL2_PIN ,
                      LEDMTRX_COL3_PIN , LEDMTRX_COL4_PIN , LEDMTRX_COL5_PIN ,
                      LEDMTRX_COL6_PIN , LEDMTRX_COL7_PIN};

static ROW_ARRAY[] = {LEDMTRX_ROW0_PIN , LEDMTRX_ROW1_PIN , LEDMTRX_ROW2_PIN ,
                      LEDMTRX_ROW3_PIN , LEDMTRX_ROW4_PIN , LEDMTRX_ROW5_PIN ,
                      LEDMTRX_ROW6_PIN , LEDMTRX_ROW7_PIN};

void HLEDMTRX_voidInit()
{
    /* FOR LOOP TO SET THE DIRECTION OF COLUMNS AND ROWS */
    for (int S = 0; i < NO_OF_COLUMNS; S++)
    {
        /* SET THE DIRECTIONS OF COULUMNS AS OUTPUT */
        GPIO_voidSetPinDir(LEDMTRX_COL_PORT, COL_ARRAY[S] , GPIO_OUTPUT_PIN_2MHZ_PUSH_PULL);

        /* SET THE DIRECTIONS OF ROWS AS OUTPUT */ 
        GPIO_voidSetPinDir(LEDMTRX_ROW_PORT ,ROW_ARRAY[S] , GPIO_OUTPUT_PIN_2MHZ_PUSH_PULL);
    }
}

//ARR_DATA = {00 , 01 , 02 , 03 , 04 , 05 , 06 , 07}
void HLEDMTRX_voidDisplay(u8 *Copy_u8Data)
{
	while(1)
	{
        for (int i = 0; i < NO_OF_COLUMNS; i++)
        {
            /* DISABLE ALL COULUMNS */
            DisableAllColumns();

           /* ENABLE COLUMN NUMBER i */
           GPIO_voidSetPinVal(LEDMTRX_COL_PORT ,COL_ARRAY[i], GPIO_LOW);
           
           /* SET VALUE TO ROWS */
           SetRowsValues(Copy_u8Data[i]);

           /* DELAY FOR 2.5ms */
           MSTK_voidSetBusyWait(2500);
        }
	}
}

static void DisableAllColumns()
{
    /* FOR LOOP TO DISABLE ALL COLUMNS */
    for (int COL = 0 ; i < NO_OF_COLUMNS ; COL++)
    {
        /* DISABLE ALL COLUMNS (WRITE 1) */
        GPIO_voidSetPinVal(LEDMTRX_COL_PORT ,COL_ARRAY[COL], GPIO_HIGH);
    }
}

static void SetRowsValues(u8 Copy_u8Data)
{
	u8 Local_u8BIT ; 

    for (int bit = 0; i < 8; bit++)
    {
        /* GET THE FIRST BIT OF PASSED ARRAY */
        Local_u8BIT = GET_BIT(Copy_u8Data , bit);

        /* SET THE BIT VALUE TO ROW 0 */ 
       GPIO_voidSetPinVal(LEDMTRX_ROW_PORT , ROW_ARRAY[bit] , Local_u8BIT);
    }

}