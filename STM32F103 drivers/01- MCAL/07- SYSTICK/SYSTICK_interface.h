/*************************************************/
/* AUTHOR    : MUSTAFA MUHAMMED                  */
/* DATE      : 3 SEPTEMTER 2021                  */
/* VERSION   : V01                               */
/*************************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

/* FUNCTION TO CONFIGURE THE CLOCK SOURCE OF SYSTICK */
void MSTK_voidInit(void);
    /*  APPLY SOURCE CLOCK  
        DISABLE SYSTICK INTERRUPT  
        DISABLE SYSTICK               */

/* FUNCTION FOR SYNCRONOUS CALL */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks); 

/* INTERRUPT ONLY FOR SINGLE TIME (ASYNCRONOUS) */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*ptr) (void));

/* INTERRUPT FOR PERIODIC TIMES (ASYNCRONOUS) */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*ptr) (void));

/* FUNCTION TO STOP THE TIMERS */
void MSTK_voidStopTimer(void);

/* FUNCTION TO GET COUNTED TIME  */
u32 MSTK_u32GetElapsedTime(void);

/* FUNCTION TO GET REMAINING TIME */
u32 MSTK_u32GetRemainingTimed(void);

#endif 