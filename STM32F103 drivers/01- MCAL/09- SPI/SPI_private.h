/****************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                  */
/* DATE     : 22 SEP 2021                                       */
/* VERSION  : V01                                               */
/****************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* SPI REGISTERS */ 
typedef struct
{
	volatile u32 CR1     ;
	volatile u32 CR2     ;
	volatile u32 SR      ;
	volatile u32 DR      ;
	volatile u32 CRCPR   ;
	volatile u32 RXCRCR  ;
	volatile u32 TXCRCR  ;
	volatile u32 I2SCFGR ;
	volatile u32 I2SPR   ;

	
}SPI_t;

#define SPI (volatile SPI_t * (0x40013000))
#endif