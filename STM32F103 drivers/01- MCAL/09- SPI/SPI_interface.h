/****************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                  */
/* DATE     : 22 SEP 2021                                       */
/* VERSION  : V01                                               */
/****************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/* MODE */
#define MASTER_MODE                0
#define SLAVE_MODE                 1

/* CLOCK POLARITY CONFIGURATION */
#define CLK_POLARITY_HIGH          0
#define CLK_POLARITY_LOW           1

/* CLOCK PHASE CONFIGURATION */
#define CLK_PHASE_READ_WRITE       0
#define CLK_PHASE_WRITE_READ       1

/* DATA SIZE CONFIGURATION */
#define DATA_8BIT                  0
#define DATA_16BIT                 1

/* DATA ORDERING CONFIGURATION */
#define MSB_FIRST                  0
#define LSB_FIRST                  1

/* RECEIVE ONLY MODE */
#define ENABLE_RECEIVE_ONLY        0
#define DISABLE_RECEIVE_ONLY       1

/* NSS PIN */
#define ENABLE_NSS_PIN             0
#define DISABLE_NSS_PIN            1

/* SPI PRESCALLER VALUES */
#define PRESCALLER_2               0
#define PRESCALLER_4               1
#define PRESCALLER_8               2
#define PRESCALLER_16              3
#define PRESCALLER_32              4
#define PRESCALLER_64              5
#define PRESCALLER_128             6
#define PRESCALLER_256             7


void MSPI_voidSpiInitMaster(void);

void MSPI_voidSpiInitSlave(void);

void MSPI_voidSpiSendReceiveByte(u8 Copy_u8DataToSend , u8 *Copy_u8Received);


#endif