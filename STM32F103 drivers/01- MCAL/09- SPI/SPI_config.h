/****************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                  */
/* DATE     : 22 SEP 2021                                       */
/* VERSION  : V01                                               */
/****************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define SPI_MODE           MASTER_MODE

#define SPI_CLK_POLARITY   CLK_POLARITY_HIGH  

#define SPI_CLK_PHASE      CLK_PHASE_WRITE_READ

#define SPI_DATA_SIZE      DATA_8BIT

#define SPI_DATA_ORDER     MSB_FIRST

#define RECEIVE_ONLY_MODE  DISABLE_RECEIVE_ONLY

#define NSS_PIN_MODE       ENABLE_NSS_PIN

#define SLAVE_PORT         GPIOA       

#define SLAVE_PIN          GPIO_PIN2 

#define SPI_PRESCALLER     PRESCALLER_2

#endif