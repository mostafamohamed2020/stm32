/********************************************************/
/* AUTHOR  : MUSTAFA MUHAMMED                           */
/* DATE    : 19 SEP 2021                                */
/* VERSION : V01                                        */
/********************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/* DMA CHANNELS  */
#define CHANNEL_1                        0
#define CHANNEL_2                        1
#define CHANNEL_3                        2
#define CHANNEL_4                        3
#define CHANNEL_5                        4
#define CHANNEL_6                        5
#define CHANNEL_7                        6

/* CHANNEL PRIORITY LEVELS */
#define LOW_PRIORITY                     0
#define MEDUIM_PRIORITY                  1
#define HIGH_PRIORITY                    2
#define VERY_HIGH_PRIORITY               3

/* PREPHIRAL INCREMENT && DECREMENT */
#define ENABLE_PREPHIRAL_INCREMENT       0
#define DISABLE_PREPHIRAL_INCREMENT      1

/* MEMORY INCREMENT && DECREMENT  */
#define ENABLE_MEMORY_INCREMENT          0
#define DISABLE_MEMORY_INCREMENT         1

/* MEMORY SIZE */
#define MEMORY_SIZE_8BIT                 0
#define MEMORY_SIZE_16BIT                1
#define MEMORY_SIZE_32BIT                2

/* PREPHIRAL SIZE */
#define PREPHIRAL_SIZE_8BIT              0
#define PREPHIRAL_SIZE_16BIT             1
#define PREPHIRAL_SIZE_32BIT             2

/* CIRCULAR MODE */
#define ENABLE_CIRCULAR_MODE             0
#define DISABLE_CIRCULAR_MODE            1

/* DATA TRANSFER DIRECTION */
#define FROM_MEMORY_TO_PREPHIRAL         0
#define FROM_PREPHIRAL_TO_MEMORY         1
#define FROM_MEMORY_TO_MEMORY            2

/* COMPLETE TRANSFER INTERRUPT */
#define ENABLE_COMPLETE_TRANSFER_INTERRUPT         0
#define DISABLE_COMPLETE_TRANSFER_INTERRUPT        1

/* HALF TRANSFER INTERRUPT */
#define ENABLE_HALF_TRANSFER_INTERRUPT             0
#define DISABLE_HALF_TRANSFER_INTERRUPT            1

/* ERROR INTERRUPT */
#define ENABLE_TRANSFER_ERROR__INTERRUPT           0
#define DISABLE_TRANSFER_ERROR__INTERRUPT          1


/* FUNCTION TO ENABLE DMA CHANNEL */
void MDMA_voidChannelInit(void);

/* FUNCTION TO SET SOURCE / DISTINATION ADDRESSES */
void MDMA_voidSetAddresses(u32 * Copy_ptru32SourceAddress , u32 * Copy_ptru32DestinationAddress , u16 Copy_u16BlockSize);


#endif