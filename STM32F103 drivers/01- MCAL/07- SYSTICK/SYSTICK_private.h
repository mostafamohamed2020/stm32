/*************************************************/
/* AUTHOR    : MUSTAFA MUHAMMED                  */
/* DATE      : 3 SEPTEMTER 2021                  */
/* VERSION   : V01                               */
/*************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

/* STRUCT TO DEFINE TIMER REGISTERS */
typedef struct {
	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL ;
	volatile u32 CALIB ;  
}STK_t ;

/* BASE ADDRESS OF TIMER REGISTERS */
#define SYSTICK (volatile STK_t * ) 0xE000E010 


#define SYSTICK_AHB_CLK         0
#define SYSTICK_AHB_BY8_CLK     1

#define SINGLE_INTERVAL         0
#define PERIODIC_INTERVAL       1

#endif