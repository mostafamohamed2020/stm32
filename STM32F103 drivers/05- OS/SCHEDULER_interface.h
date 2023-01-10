/*********************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                           */
/* DATE     : 12 SEP 2021                                */
/* VERSION  : V01                                        */
/*********************************************************/

#ifndef SCHEDULER_INTERFACE_H
#define SCHEDULER_INTERFACE_H

/* FUNCTION TO CREATE TASK */
void SCHEDULER_VoidCreateTask(void(*task_ptr)(void) , u16 Copy_u16periodicity ,u8 Copy_u8Periority , u8 Copy_u8FirstDelay);

/* FUNCTION TO START SCHEDULING */
void SCHEDULER_VoidSchedulerStart(void);

/* FUNCTION TO DELETE TASK */
void SCHEDULER_VoidDeleteTask(void(*task_ptr)(void) , u16 Copy_u16periodicity ,u8 Copy_u8Periority);
#endif