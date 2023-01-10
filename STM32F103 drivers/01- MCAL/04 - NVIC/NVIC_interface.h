/*********************************************************/
/*       AUTHOR : MOSTAFA MOHAMED                        */
/*       DATE   : 23 MAY 2021                            */
/*       VERSION : V01                                   */
/*********************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*************************************************************/
/*     AVAILABLE PRIORITY SYSTEMS                            */
/*       1 - 4 BITS FOR GROUP WITHOUT SUB PRIORITY           */
/*       2 - 3 BITS FOR GROUP WITH 1 BIT FOR SUB PRIORITY    */
/*       3 - 2 BITS FOR GROUP WITH 2 BITS FOR SUB PRIORITY   */
/*       4 - 1 BIT FOR GROUP WITH 3 BITS FOR SUB PRIORITY    */
/*       5 - NO GRUPS WITH 4 BITS FOR SUB PRIORITY           */
/*************************************************************/
#define FOUR_BITS_GROUP_NOSUB  0x05FA0300 
#define THREE_BITS_GROUP_1SUB  0x05FA0400 
#define TWO_BITS_GROUP_2SUB    0x05FA0500 
#define ONE_BITS_GROUP_3SUB    0x05FA0600 
#define NO_GROUP_4SUB          0x05FA0700

/* AT THE MAXIMUM GROUP PRIORITIES THERE IS 16 AVAILABLE LEVELS */
#define GROUP_PRIORITY_0       0b0000
#define GROUP_PRIORITY_1       0b0001
#define GROUP_PRIORITY_2       0b0010
#define GROUP_PRIORITY_3       0b0011
#define GROUP_PRIORITY_4       0b0100
#define GROUP_PRIORITY_5       0b0101
#define GROUP_PRIORITY_6       0b0110
#define GROUP_PRIORITY_7       0b0111
#define GROUP_PRIORITY_8       0b1000
#define GROUP_PRIORITY_9       0b1001
#define GROUP_PRIORITY_10      0b1010
#define GROUP_PRIORITY_11      0b1011
#define GROUP_PRIORITY_12      0b1100
#define GROUP_PRIORITY_13      0b1101
#define GROUP_PRIORITY_14      0b1110
#define GROUP_PRIORITY_15      0b1111

/* AT THE MAXIMUM SUB PRIORITIES THERE IS 16 AVAILABLE LEVELS */
#define SUB_PRIORITY_0         0b0000
#define SUB_PRIORITY_1         0b0001
#define SUB_PRIORITY_2         0b0010
#define SUB_PRIORITY_3         0b0011
#define SUB_PRIORITY_4         0b0100
#define SUB_PRIORITY_5         0b0101
#define SUB_PRIORITY_6         0b0110
#define SUB_PRIORITY_7         0b0111
#define SUB_PRIORITY_8         0b1000
#define SUB_PRIORITY_9         0b1001
#define SUB_PRIORITY_10        0b1010
#define SUB_PRIORITY_11        0b1011
#define SUB_PRIORITY_12        0b1100
#define SUB_PRIORITY_13        0b1101
#define SUB_PRIORITY_14        0b1110
#define SUB_PRIORITY_15        0b1111


void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber);

void MNVIC_VoidSetpendingFlag(u8 Copy_u8IntNumber);
void MNVIC_VoidClearPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);

void MNVIC_VoidSetPririty(u8 Copy_u8IntId , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority )



#endif