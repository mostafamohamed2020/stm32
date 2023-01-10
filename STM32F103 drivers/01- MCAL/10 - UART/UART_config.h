/*******************************************************************/
/* AUTHOR  : MUSTAFA MUHAMMED                                      */
/* DATE    : 24 SEP 2021                                           */
/* VERSION : V01                                                   */
/*******************************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define UART_MODE               ASYNCRONOUS_MODE 

#define UART_INTERRUPT          DISABLE_UART_INTERRUPT

/* THESE CONFIGURATIONS IS ALLOWED ONLY IN SYNCRONOUS MODE */
#if UART_MODE == SYNCRONOUS_MODE

#define UART_CLOCK_POLARITY     IDLE_HIGH 
#define UART_UART_CLOCK_PHASE   WRITE_THEN_READ

#endif

#define BAUD_RATE               BR_9600
 
#define STOP_BITS_NO            ONE_STOP_BIT

#define PARITY_BIT_STATE        NO_PARITY

#define DATA_BITS               DATA_8BITS

#define MULTI_PROCESSORS_MODE   DISABLE_MULTI_PROCESSOR
#endif