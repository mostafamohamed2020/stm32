/******************************************************/
/* AUTHOR    : MUSTAFA MUHAMMED                       */
/* DATE      : 29 AUGUST 2021                         */
/* VERSION   : V01                                    */
/******************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* FUNCTION TO INITIALIZE PIN FOR EXTERNAL INTERRUPT */
void MEXTI_voidInitExtrnalInt(void);

/* FUNCTION TO ENABLE EXTERNAL INTERRUPT */
void MEXTI_voidEnableExtI(u8 Copy_u8EXTILine);

/* FUNCTION TO DISABLE EXTERNAL INTERRUPT */
void MEXTI_voidDisableExtI(u8 Copy_u8EXTILine);

/* FUNCTION TO INITIATE SOFTWARE TRIGGER */ 
void MEXTI_voidSWTrigger(u8 Copy_u8EXTILine);

/* FUNCTION TO CHANGE THE INTERRUPT EVENT IN RUN TIME */
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8Mode);

/* FUNCTION TO SET THE CALLBACK FUNCTION */
void MEXTI_voidSetCallBack(void (*ptr) (void));
 
#endif