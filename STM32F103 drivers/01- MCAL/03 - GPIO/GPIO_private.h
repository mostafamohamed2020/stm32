/*********************************************************/
/*       AUTHOR : MOSTAFA MOHAMED                        */
/*       DATE   : 16 MAY 2021                            */
/*       @ 1:48 AM                                       */
/*       VERSION : V01                                   */
/*********************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* BASE ADDRESS OF PORTA REGISTERS */
#define GPIO_PORTA_BASE_ADDRESS  0x40010800

/* BASE ADDRESS OF PORTB REGISTERS */
#define GPIO_PORTB_BASE_ADDRESS  0x40010C00

/* BASE ADDRESS OF PORTC REGISTERS */
#define GPIO_PORTC_BASE_ADDRESS  0x40011000  

/************************************************************/
/*          PORTA REGISTERS' DEFINITION                     */
/*              1 - PORTA_CRL                               */
/*              2 - PORTA_CRH                               */
/*              3 - PORTA_IDR                               */
/*              4 - PORTA_ODR                               */
/*              5 - PORTA_BSRR                              */
/*              6 - PORTA_BBR                               */
/*              7 - PORTA_LCKR                              */
/************************************************************/
#define GPIOA_CRL  *(u32 *) (GPIO_PORTA_BASE_ADDRESS + 0X00) 
#define GPIOA_CRH  *(u32 *) (GPIO_PORTA_BASE_ADDRESS + 0X04)
#define GPIOA_IDR  *(u32 *) (GPIO_PORTA_BASE_ADDRESS + 0X08)
#define GPIOA_ODR  *(u32 *) (GPIO_PORTA_BASE_ADDRESS + 0X0C)
#define GPIOA_BSRR *(u32 *) (GPIO_PORTA_BASE_ADDRESS + 0X10)
#define GPIOA_BRR  *(u32 *) (GPIO_PORTA_BASE_ADDRESS + 0X14)
#define GPIOA_LCKR *(u32 *) (GPIO_PORTA_BASE_ADDRESS + 0X18)

/************************************************************/
/*          PORTB REGISTERS' DEFINITION                     */
/*              1 - PORTB_CRL                               */
/*              2 - PORTB_CRH                               */
/*              3 - PORTB_IDR                               */
/*              4 - PORTB_ODR                               */
/*              5 - PORTB_BSRR                              */
/*              6 - PORTB_BBR                               */
/*              7 - PORTB_LCKR                              */
/************************************************************/
#define GPIOB_CRL  *(u32 *) (GPIO_PORTB_BASE_ADDRESS + 0X00) 
#define GPIOB_CRH  *(u32 *) (GPIO_PORTB_BASE_ADDRESS + 0X04)
#define GPIOB_IDR  *(u32 *) (GPIO_PORTB_BASE_ADDRESS + 0X08)
#define GPIOB_ODR  *(u32 *) (GPIO_PORTB_BASE_ADDRESS + 0X0C)
#define GPIOB_BSRR *(u32 *) (GPIO_PORTB_BASE_ADDRESS + 0X10)
#define GPIOB_BRR  *(u32 *) (GPIO_PORTB_BASE_ADDRESS + 0X14)
#define GPIOB_LCKR *(u32 *) (GPIO_PORTB_BASE_ADDRESS + 0X18)

/************************************************************/
/*          PORTC REGISTERS' DEFINITION                     */
/*              1 - PORTC_CRL                               */
/*              2 - PORTC_CRH                               */
/*              3 - PORTC_IDR                               */
/*              4 - PORTC_ODR                               */
/*              5 - PORTC_BSRR                              */
/*              6 - PORTC_BBR                               */
/*              7 - PORTC_LCKR                              */
/************************************************************/
#define GPIOC_CRL  *(u32 *) (GPIO_PORTC_BASE_ADDRESS + 0X00) 
#define GPIOC_CRH  *(u32 *) (GPIO_PORTC_BASE_ADDRESS + 0X04)
#define GPIOC_IDR  *(u32 *) (GPIO_PORTC_BASE_ADDRESS + 0X08)
#define GPIOC_ODR  *(u32 *) (GPIO_PORTC_BASE_ADDRESS + 0X0C)
#define GPIOC_BSRR *(u32 *) (GPIO_PORTC_BASE_ADDRESS + 0X10)
#define GPIOC_BRR  *(u32 *) (GPIO_PORTC_BASE_ADDRESS + 0X14)
#define GPIOC_LCKR *(u32 *) (GPIO_PORTC_BASE_ADDRESS + 0X18)


#endif