/********************************************************/
/* AUTHOR  : MUSTAFA MUHAMMED                           */
/* DATE    : 19 SEP 2021                                */
/* VERSION : V01                                        */
/********************************************************/

#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

#define CHANNEL_ID                      CHANNEL_1           

#define CHANNEL_SOFTWARE_PRIORITY       VERY_HIGH_PRIORITY

#define MEMORY_INCREMENT_MODE           ENABLE_MEMORY_INCREMENT

#define PREPHIRAL_INCREMENT_MODE        ENABLE_PREPHIRAL_INCREMENT
  
#define MEMORY_SIZE                     MEMORY_SIZE_8BIT

#define PREPHIRAL_SIZE                  PREPHIRAL_SIZE_8BIT

#define CIRCULAR_MODE                   DISABLE_CIRCULAR_MODE

#define TRANSFER_DIRECTION              FROM_MEMORY_TO_MEMORY

#define TRANSFER_INTERRUPT_MODE         ENABLE_COMPLETE_TRANSFER_INTERRUPT

#define HALF_TRANSFER_INTERRUPT_MODE    DISABLE_HALF_TRANSFER_INTERRUPT

#define ERROR_INTERRUPT_MODE            DISABLE_TRANSFER_ERROR__INTERRUPT

#endif