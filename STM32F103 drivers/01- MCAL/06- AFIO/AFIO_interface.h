/******************************************************/
/* AUTHOR    : MUSTAFA MUHAMMED                       */
/* DATE      : 29 AUGUST 2021                         */
/* VERSION   : V01                                    */
/******************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#define EXTI0          0 
#define EXTI1          1 
#define EXTI2          2 
#define EXTI3          3 
#define EXTI4          4 
#define EXTI5          5 
#define EXTI6          6 
#define EXTI7          7 
#define EXTI8          8 
#define EXTI9          9 
#define EXTI10         10 
#define EXTI11         11
#define EXTI12         12
#define EXTI13         13
#define EXTI14         14
#define EXTI15         15


#define EXTI_A         0b0000
#define EXTI_B         0b0001
#define EXTI_C         0b0010

void MAFIO_voidSetExtrnalConfiguration(u8 Copy_u8Line , u8 Copy_u8PortMap);
#endif