/*********************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                           */
/* DATE     : 12 SEP 2021                                */
/* VERSION  : V01                                        */
/*********************************************************/
#ifndef SCHEDULER_PRIVATE_H
#define SCHEDULER_PRIVATE_H

/********************************************/
/* CREATE TASK TYPE CONSISTS OF             */
/*   1 - POINTER TO THE FUNCTION(TASK)      */
/*   2 - TASK PERIOD                        */
/********************************************/
typedef struct 
{
	u16 periodicity ;
	void (*ptr_2_task)(void);
	u8 FirstDelay ; 
}TASK;

/* PRIVATE SCHEDULER */
static void Scheduler(void);

#endif