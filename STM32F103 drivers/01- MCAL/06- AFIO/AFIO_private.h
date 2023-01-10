/******************************************************/
/* AUTHOR    : MUSTAFA MUHAMMED                       */
/* DATE      : 29 AUGUST 2021                         */
/* VERSION   : V01                                    */
/******************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/* STRUCT FOR AFIO REGISTERS */
typedef struct 
{
	volatile u32 EVCR ;
	volatile u32 MAPR ;
	volatile u32 EXTICR1 ;
	volatile u32 EXTICR2 ;
	volatile u32 EXTICR3 ;
	volatile u32 EXTICR4 ;
	volatile u32 MAPR2 ;

}AFIO_t ;

#define AFIO ((volatile AFIO_t *) 0x40010000)
#endif 
