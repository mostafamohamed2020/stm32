/***********************************************************
*      AUTHOR : MOSTAFA MOHAMED                            *
*      DATE   : 12 MAY 2021                                *
*      VERSION : V01                                       *
***********************************************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


#define RCC_CLOCK_SOURCE  RCC_HSE

/* ENABLE THESE CONFIGURATION ONLY WHEN PLL SELECTED */
#if RCC_CLOCK_SOURCE == RCC_PLL

#define PLL_ENTRY_CLOCK RCC_PLL_HSE

#define PLL_MULTIPLICATION_FACTOR PLL_MULTIPLE_16
#endif

/* ENABLE / DISABLE CLOCK SECURITY */
#define RCC_SECURITY_STATUS RCC_ENABLE_SECURITY_SYSTEM

/* SELECT THE PRESCALLER VALUE OF AHB */
#define RCC_AHB_PRESCALLER  AHB_WITH_NO_PRESCALLER

/* SELECT THE PRESCALLER VALUE OF APB1 */
#define RCC_APB1_PRESCALLER APB1_WITH_NO_PRESCALLER

/* SELECT THE PRESCALLER VALUE OF APB2 */
#define RCC_APB2_PRESCALLER APB2_WITH_NO_PRESCALLER


#endif