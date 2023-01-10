/*********************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                           */
/* DATE     : 12 SEP 2021                                */
/* VERSION  : V01                                        */
/*********************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SYSTICK_interface.h"

#include"SCHEDULER_interface.h"
#include"SCHEDULER_private.h"
#include"SCHEDULER_config.h"

#define NULL        (void *)0 

/* ARRAY OF STRUCT TASK TO STORE TASKS */
static TASK ARR_OF_TASKS[NO_OF_TASKS] = { NULL };

/* FUNCTION TO CREATE TASK */
void SCHEDULER_VoidCreateTask(void(*task_ptr)(void) , u16 Copy_u16periodicity ,u8 Copy_u8Periority , u8 Copy_u8FirstDelay)
{
	/* SET THE PERIODICITY OF TASK */
  ARR_OF_TASKS[Copy_u8Periority].periodicity = Copy_u16periodicity ;

    /* POINT TO THE FUNCTION */
  ARR_OF_TASKS[Copy_u8Periority].ptr_2_task  = task_ptr ;

    /* SET THE FIRST DELAY */
  ARR_OF_TASKS[Copy_u8Periority].FirstDelay  = Copy_u8FirstDelay ;

}

/* FUNCTION TO START SCHEDULING */ 
void SCHEDULER_VoidSchedulerStart(void)
{
	/* INITIALIZATION */
	
	/* INITIALIZE THE TIMER */
	MSTK_voidInit(); 

	/* TICK TIME IS 1msec = 1000 MICRO SEC*/
	MSTK_voidSetIntervalPeriodic(1000 , Scheduler);
}


/* ORDER THE TASKS */
static void Scheduler(void)
{
	
	for (u8 i = 0; i < NO_OF_TASKS; i++)
	{
		/* IF THE FIRST DELAY IS 0 THEN EXECUTE THE TASK */
		if (ARR_OF_TASKS[i].FirstDelay == 0)
		{
			ARR_OF_TASKS[i].FirstDelay = ARR_OF_TASKS[i].periodicity-1 ;
			ARR_OF_TASKS[i].ptr_2_task(); 
		}
		/* IF THE FIRST DELAY IS NOT 0 DECREMENT IT THEN CHECK LATER */
		else
		{
			ARR_OF_TASKS[i].FirstDelay--;
		}
	}
}