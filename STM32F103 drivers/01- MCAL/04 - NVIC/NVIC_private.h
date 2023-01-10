/*********************************************************/
/*       AUTHOR : MOSTAFA MOHAMED                        */
/*       DATE   : 23 MAY 2021                            */
/*       VERSION : V01                                   */
/*********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* BASE ADDRESS OF NVIC  0XE000E100 */
#define NVIC_BASE_ADDRESS   0XE000E100

#define NVIC_ISRE0  *((u32*) 0XE000E100) /* ENABLE EXTERNAL INTERRUPTS 0 ... 31 */
#define NVIC_ISRE1  *((u32*) 0XE000E104) /* ENABLE EXTERNAL INTERRUPTS 32 ... 63 */

#define NVIC_ICRE0  *((u32*) 0XE000E180) /* DISABLE EXTERNAL INTERRUPT 0 --> 31 */
#define NVIC_ICER1  *((u32*) 0XE000E184) /* DISABLE EXTERNAL INTERRUPT 32 --> 63 */

#define NVIC_ISPR0  *((u32*) 0XE000E200) /* SET PENDING FLAG 0 --> 31 */
#define NVIC_ISPR1  *((u32*) 0XE000E204) /* SET PENDING FLAG 32 --> 63 */

#define NVIC_ICPR0  *((u32*) 0XE000E280) /* CLEAR PENDING FLAG 0 --> 31 */
#define NVIC_ICPR1  *((u32*) 0XE000E284) /* CLEAR PENDING FLAG 0 --> 31 */

#define NVIC_IABR0  *((volatile u32*) 0XE000E300) /* READ ONLY REGISTER TO GET ACTIVE INTERRUPTS 0 --> 31 */
#define NVIC_IABR1  *((volatile u32*) 0XE000E304)  /* READ ONLY REGISTER TO GET ACTIVE INTERRUPTS 32 --> 64 */

#define NVIC_IPR     ((volatile u8 *) 0XE000E400) /* ACCESSING THE PRIORITY REGISTER AS BYTES */

#define SCB_AIRCR   *((u32 *) 0xE000ED0C) /* ADDRESS OF SCB_AIRCR */ 




#endif