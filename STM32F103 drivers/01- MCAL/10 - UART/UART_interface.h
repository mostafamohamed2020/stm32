/*******************************************************************/
/* AUTHOR  : MUSTAFA MUHAMMED                                      */
/* DATE    : 24 SEP 2021                                           */
/* VERSION : V01                                                   */
/*******************************************************************/ 
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/* UART MODES */
#define SYNCRONOUS_MODE   0
#define ASYNCRONOUS_MODE  1

/* STOP BITS CONFIGURATION */
#define ONE_STOP_BIT      0
#define TWO_STOP_BITS     1

/* DATA BITS CONFIGURATION */
#define DATA_8BITS        0
#define DATA_9BITS        1

/* BAUD RATE CONFIGURATION */
#define BR_9600           0
#define BR_4800           1
#define BR_115200         2

/* PARITY BIT CONFIGURATION */
#define EVEN_PARITY       0
#define ODD_PARITY        1
#define NO_PARITY         2

/* CLOCK POLARITY */
#define IDLE_LOW          0
#define IDLE_HIGH         1

/* CLOCK PHASE    */
#define READ_THEN_WRITE   0
#define WRITE_THEN_READ   1

/* UART MODES */
#define ENABLE_UART_INTERRUPT    0
#define DISABLE_UART_INTERRUPT   1

/* MULTI PROCESSOR MODE */
#define ENABLE_MULTI_PROCESSOR   0
#define DISABLE_MULTI_PROCESSOR  1


/* FUNCTION TO INITIALIZE UART */
void MUART_voidInit(void);

/* FUNCTION TO SEND DATA */
void MUART_voidSendData(u8 * Copy_u8Data);

/* FUNCTION TO RECEIVE DATA */
u8 MUART_u8ReceiveData(void);

#endif