/***********************************************************
*      AUTHOR : MOSTAFA MOHAMED                            *
*      DATE   : 12 MAY 2021                                *
*      VERSION : V01                                       *
***********************************************************/


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Registers Definitions of RCC prephiral */
/* base address of RCC is 0x40021000 */

#define RCC_CR        *((u32 *) 0x40021000) 

#define RCC_CFGR      *((u32 *) 0x40021004)

#define RCC_CIR       *((u32 *) 0x40021008)

#define RCC_APB2RSTR  *((u32 *) 0x4002100C)

#define RCC_APB1RSTR  *((u32 *) 0x40021010)

#define RCC_AHBENR    *((u32 *) 0x40021014)

#define RCC_APB2ENR   *((u32 *) 0x40021018)

#define RCC_APB1ENR   *((u32 *) 0x4002101C)

#define RCC_BDCR      *((u32 *) 0x40021020)

#define RCC_CSR       *((u32 *) 0x40021024)

/************************************************************/
/*       THREE AVAILABLE BUSES IN THE CONTROLLER            */
/*          1 - AHB (ADVANCED HIGH SPEED BUS)               */
/*          2 - APB1(ADVANCED PERIPHIRAL BUS 1)             */
/*          3 - APB2(ADVANCED PERIPHIRAL BUS 2)             */
/************************************************************/
#define RCC_AHB           0
#define RCC_APB1          1
#define RCC_APB2          2


/*                  APB2 BUS PERIPHERALS                   */
#define APB2_GPIOA        2
#define APB2_GPIOB        3
#define APB2_GPIOC        4


/***********************************************************/
/*            AVAILABLE CLOCK SOURCES                      */
/*               1 - HIGH SPEED EXTERNAL (HSE)             */
/*               2 - HIGH SPEED INTERNAL (HSI)             */
/*               3 - PHASE LOCKED LOOP   (PLL)             */
/*               4 - EXTERNAL RC CLOCK SYSTEM              */
/***********************************************************/
#define RCC_HSE                       0
#define RCC_HSI                       1
#define RCC_PLL                       2
#define RCC_HSE_BYPASS                3

/***********************************************************/
/*          IN CASE PLL IS CHOOSEN ITS INPUT CAN BE        */
/*                  3.1 - HSE DIVIDDED BY 2                */
/*                  3.2 - HSI DIVIDDED BY 2                */
/*                  3.2 - HSE WITHOUT DIVISION             */
/***********************************************************/
#define RCC_PLL_HSI_DIVIDED_BY_2      0
#define RCC_PLL_HSE_DIVIDED_BY_2      1
#define RCC_PLL_HSE                   2

/**********************************************************/
/*        AVAILABLE MULTIBLE FACTORS OF PLL               */
/*            OUTPUT OF PLL CIRCUIT :                     */
/*                  1 - NO MULTIPLICATION FACTOR          */
/*                  2 - MULTIPLE BY 2                     */
/*                  3 - MULTIPLE BY 3                     */
/*                  4 - MULTIPLE BY 4                     */
/*                  4 - MULTIPLE BY 5                     */
/*                  4 - MULTIPLE BY 6                     */
/*                  4 - MULTIPLE BY 7                     */
/*                  4 - MULTIPLE BY 8                     */
/*                  4 - MULTIPLE BY 9                     */
/*                  4 - MULTIPLE BY 10                    */
/*                  4 - MULTIPLE BY 11                    */
/*                  4 - MULTIPLE BY 12                    */
/*                  4 - MULTIPLE BY 13                    */
/*                  4 - MULTIPLE BY 14                    */
/*                  4 - MULTIPLE BY 15                    */
/*                  4 - MULTIPLE BY 16                    */
/**********************************************************/
#define PLL_NO_CLOCK_FACTOR   0
#define PLL_MULTIPLE_2        2
#define PLL_MULTIPLE_3        3
#define PLL_MULTIPLE_4        4  
#define PLL_MULTIPLE_5        5
#define PLL_MULTIPLE_6        6 
#define PLL_MULTIPLE_7        7
#define PLL_MULTIPLE_8        8
#define PLL_MULTIPLE_9        9 
#define PLL_MULTIPLE_10       10
#define PLL_MULTIPLE_11       11
#define PLL_MULTIPLE_12       12
#define PLL_MULTIPLE_13       13
#define PLL_MULTIPLE_14       14
#define PLL_MULTIPLE_15       15
#define PLL_MULTIPLE_16       16

/*********************************************************/
/*        PRESCALLER VALUES OF APB1                      */
/*                 1 -  HCLK not divided                 */
/*                 2 -  HCLK divided by 2                */
/*                 3 -  HCLK divided by 4                */
/*                 4 -  HCLK divided by 8                */
/*                 5 -  HCLK divided by 16               */
/*********************************************************/
#define APB1_WITH_NO_PRESCALLER   0
#define APB1_WITH_2_PRESCALLER    1
#define APB1_WITH_4_PRESCALLER    2
#define APB1_WITH_8_PRESCALLER    3
#define APB1_WITH_16_PRESCALLER   4

/*********************************************************/
/*        PRESCALLER VALUES OF APB2                      */
/*                 1 -  HCLK not divided                 */
/*                 2 -  HCLK divided by 2                */
/*                 3 -  HCLK divided by 4                */
/*                 4 -  HCLK divided by 8                */
/*                 5 -  HCLK divided by 16               */
/*********************************************************/
#define APB2_WITH_NO_PRESCALLER   0
#define APB2_WITH_2_PRESCALLER    1
#define APB2_WITH_4_PRESCALLER    2
#define APB2_WITH_8_PRESCALLER    3
#define APB2_WITH_16_PRESCALLER   4

/*********************************************************/
/*        PRESCALLER VALUES OF AHB                       */
/*                 1 -  SYSCLK not divided               */
/*                 2 -  SYSCLK divided by 2              */
/*                 3 -  SYSCLK divided by 4              */
/*                 4 -  SYSCLK divided by 8              */
/*                 5 -  SYSCLK divided by 16             */
/*                 6 -  SYSCLK divided by 64             */
/*                 7 -  SYSCLK divided by 128            */
/*                 8 -  SYSCLK divided by 256            */
/*                 9 - SYSCLK divided by 512             */
/*********************************************************/
#define AHB_WITH_NO_PRESCALLER    0
#define AHB_WITH_2_PRESCALLER     1
#define AHB_WITH_4_PRESCALLER     2
#define AHB_WITH_8_PRESCALLER     3
#define AHB_WITH_16_PRESCALLER    4
#define AHB_WITH_64_PRESCALLER    5
#define AHB_WITH_128_PRESCALLER   6
#define AHB_WITH_256_PRESCALLER   7
#define AHB_WITH_512_PRESCALLER   8

/*********************************************************/
/*    CLOCK SECURITY SYSTEM IS USED FOR SECURITY         */
/*    IF THERE IS AN ISSUE WITH THE HSE YOU ENABLED      */
/*    THIS FEATURE IS AUTOMATICALLY BY H.W WILL DISABLE  */
/*    THE EXTERNAL CLOCK SOURCE AND ENABLE THE INTERNAL  */
/*    HSI                                                */
/*********************************************************/
#define RCC_ENABLE_SECURITY_SYSTEM   0
#define RCC_DISABLE_SECURITY_SYSTEM  1

#endif