/********************************************************/
/* AUTHOR  : MUSTAFA MUHAMMED                           */
/* DATE    : 19 SEP 2021                                */
/* VERSION : V01                                        */
/********************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
	volatile u32 CCR ;
	volatile u32 CNDTR ;
	volatile u32 CPAR ;
	volatile u32 CMAR ;
	volatile u32 Reserved ;
}DMA_Channel;


typedef struct 
{
	volatile u32 ISR ; 
	volatile u32 IFCR ;
	/* 7 CHANNELS EACH ONE CONTAINS BUNCH OF REGISTERS */
    DMA_Channel Channel[7];
	 
}DMA_t;
 
#define DMA ((volatile sDMA_t) * 0x40020000)

#endif