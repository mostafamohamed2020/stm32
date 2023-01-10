/***********************************************************
*      AUTHOR  : MOSTAFA MOHAMED                           *
*      DATE    : 12 MAY 2021                               *
*      VERSION : V01                                       *
***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/* Functio TO Enable Clock For Specific Periphiral */
void RCC_VoidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{

	if(Copy_u8PerId <= 31) 
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  :
			SET_BIT(RCC_AHBENR , Copy_u8PerId);
			break;
			case RCC_APB1 :
			SET_BIT(RCC_APB1ENR , Copy_u8PerId);
			break;
			case RCC_APB2 :
			SET_BIT(RCC_APB2ENR , Copy_u8PerId);
			break;
			default       : /* Return Error */
			break;
		}  

	}

	else 
	{
		/* Return Error */
	}
}

/* Function TO Disable Specific Periphiral */
void RCC_VoidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{

	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  :
			CLR_BIT(RCC_AHBENR , Copy_u8PerId);
			break;
			case RCC_APB1 :
			CLR_BIT(RCC_APB1ENR , Copy_u8PerId);
			break;
			case RCC_APB2 :
			CLR_BIT(RCC_APB2ENR , Copy_u8PerId);
			break;
			default       : /* Return Error */
			break;
		}

	}

	else 
	{
		/* Return Error */
	}
}

void RCC_VoidInitSysClock(void)
{

	#if RCC_CLOCK_SOURCE == RCC_HSE
	/* ENABLE EXTERNAL CRYSTAL WITHOUT BYPASS */
     RCC_CR = 0X00010000 ; 
	 //SET_BIT(RCC_CR , 16);

	 RCC_CFGR = 0X00000001 ; 
	 //SET_BIT(RCC_CFGR , 0);
	 //CLR_BIT(RCC_CFGR , 1);

	#elif RCC_CLOCK_SOURCE == RCC_HSI
     /* ENABLE INTERNAL RC + TRIMING VALUE IS THE DEFAULT 16 */
     RCC_CR = 0X00000101 ;
     //SET_BIT(RCC_CR , 0);

     RCC_CFGR = 0X00000000;
     //CLR_BIT(RCC_CFGR , 0);
     //CLR_BIT(RCC_CFGR , 1); 

	#elif RCC_CLOCK_SOURCE == RCC_PLL
     
	 #if PLL_ENTRY_CLOCK == RCC_PLL_HSI_DIVIDED_BY_2
	 /*********************************/
	 /*     1 - ENABLE HSI FIRST      */
	 /*     2 - SELECT DEVISION BY 2  */
	 /*********************************/
	 RCC_CR = 0X00000001 ;
     //SET_BIT(RCC_CR , 0);
     RCC_CFGR = 0X00000000 ;
     //CLR_BIT(RCC_CFGR , 17);

	 #elif PLL_ENTRY_CLOCK == RCC_PLL_HSE_DIVIDED_BY_2
	 /*********************************/
	 /*     1 - ENABLE HSE FIRST      */
	 /*     2 - SELECT DEVISION BY 2  */
	 /*********************************/
	 RCC_CR = 0X00010000 ; 
	 //SET_BIT(RCC_CR , 16);
	 RCC_CFGR = 0X00020000 ; 
	 //SET_BIT(RCC_CFGR , 17);

	 #elif PLL_ENTRY_CLOCK == RCC_PLL_HSE
	 /*********************************/
	 /*     1 - ENABLE HSE FIRST      */
	 /*     2 - SELECT NO DEVISION    */
	 /*********************************/
	 RCC_CR = 0X00010000 ; 
	 //SET_BIT(RCC_CR , 16);
	 RCC_CFGR = 0X00010000 ; 
	 //SET_BIT(RCC_CFGR , 16);
	 #endif
	 #if PLL_MULTIPLICATION_FACTOR == PLL_NO_CLOCK_FACTOR
	  
	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_2
	  CLR_BIT(RCC_CFGR , 18);
	  CLR_BIT(RCC_CFGR , 19);
	  CLR_BIT(RCC_CFGR , 20);
	  CLR_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_3
	  SET_BIT(RCC_CFGR , 18);
	  CLR_BIT(RCC_CFGR , 19);
	  CLR_BIT(RCC_CFGR , 20);
	  CLR_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_4
	  CLR_BIT(RCC_CFGR , 18);
	  SET_BIT(RCC_CFGR , 19);
	  CLR_BIT(RCC_CFGR , 20);
	  CLR_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_5
	  SET_BIT(RCC_CFGR , 18);
	  SET_BIT(RCC_CFGR , 19);
	  CLR_BIT(RCC_CFGR , 20);
	  CLR_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_6
	  CLR_BIT(RCC_CFGR , 18);
	  CLR_BIT(RCC_CFGR , 19);
	  SET_BIT(RCC_CFGR , 20);
	  CLR_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_7
	  SET_BIT(RCC_CFGR , 18);
	  CLR_BIT(RCC_CFGR , 19);
	  SET_BIT(RCC_CFGR , 20);
	  CLR_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_8
	  CLR_BIT(RCC_CFGR , 18);
	  SET_BIT(RCC_CFGR , 19);
	  SET_BIT(RCC_CFGR , 20);
	  CLR_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_9
	  SET_BIT(RCC_CFGR , 18);
	  SET_BIT(RCC_CFGR , 19);
	  SET_BIT(RCC_CFGR , 20);
	  CLR_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_10
	  CLR_BIT(RCC_CFGR , 18);
	  CLR_BIT(RCC_CFGR , 19);
	  CLR_BIT(RCC_CFGR , 20);
	  SET_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_11
	  SET_BIT(RCC_CFGR , 18);
	  CLR_BIT(RCC_CFGR , 19);
	  CLR_BIT(RCC_CFGR , 20);
	  SET_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_12
	  CLR_BIT(RCC_CFGR , 18);
	  SET_BIT(RCC_CFGR , 19);
	  CLR_BIT(RCC_CFGR , 20);
	  SET_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_13
	  SET_BIT(RCC_CFGR , 18);
	  SET_BIT(RCC_CFGR , 19);
	  CLR_BIT(RCC_CFGR , 20);
	  SET_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_14
	  CLR_BIT(RCC_CFGR , 18);
	  CLR_BIT(RCC_CFGR , 19);
	  SET_BIT(RCC_CFGR , 20);
	  SET_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_15
	  SET_BIT(RCC_CFGR , 18);
	  CLR_BIT(RCC_CFGR , 19);
	  SET_BIT(RCC_CFGR , 20);
	  SET_BIT(RCC_CFGR , 21);

	 #elif PLL_MULTIPLICATION_FACTOR == PLL_MULTIPLE_16
	  CLR_BIT(RCC_CFGR , 18);
	  SET_BIT(RCC_CFGR , 19);
	  SET_BIT(RCC_CFGR , 20);
	  SET_BIT(RCC_CFGR , 21);

	 #endif
	  /* JUST ENABLE THE PLL AFTER SETTING ITS SPECIFICATIONS */
     RCC_CR = 0X01000000 ;
     //SET_BIT(RCC_CR , 24);

	#elif RCC_CLOCK_SOURCE == RCC_HSE_BYPASS
     /* ENABLE EXTERNAL RCC CLOCK SYSTEM */
     RCC_CR = 0X00050000 ;
     //SET_BIT(RCC_CR , 18);

     RCC_CFGR = 0X00000001 ; 
	 //SET_BIT(RCC_CFGR , 0);
	 //CLR_BIT(RCC_CFGR , 1);

	#else
	#error("you choose unavailable configuration")
	#endif 

	#if RCC_SECURITY_STATUS == RCC_ENABLE_SECURITY_SYSTEM
     RCC_CR = 0X00080000 ; 
	 //SET_BIT(RCC_CR , 19); 
    #elif RCC_SECURITY_STATUS == RCC_DISABLE_SECURITY_SYSTEM
     RCC_CR = 0X00000000;
     //CLR_BIT(RCC_CR , 19);
    #endif

    #if RCC_AHB_PRESCALLER   == AHB_WITH_NO_PRESCALLER
     RCC_CFGR = 0x00000000 ; 

    #elif RCC_AHB_PRESCALLER == AHB_WITH_2_PRESCALLER
     RCC_CFGR = 0x00000080 ;

    #elif RCC_AHB_PRESCALLER == AHB_WITH_4_PRESCALLER
     RCC_CFGR = 0x00000090 ; 

    #elif RCC_AHB_PRESCALLER == AHB_WITH_8_PRESCALLER
     RCC_CFGR = 0x000000A0;

    #elif RCC_AHB_PRESCALLER == AHB_WITH_16_PRESCALLER
     RCC_CFGR = 0x000000B0 ;

    #elif RCC_AHB_PRESCALLER == AHB_WITH_64_PRESCALLER
     RCC_CFGR = 0x000000C0 ;

    #elif RCC_AHB_PRESCALLER == AHB_WITH_128_PRESCALLER
     RCC_CFGR = 0x000000D0 ;

    #elif RCC_AHB_PRESCALLER == AHB_WITH_256_PRESCALLER
     RCC_CFGR = 0x000000E0 ;

    #elif RCC_AHB_PRESCALLER == AHB_WITH_512_PRESCALLER
     RCC_CFGR = 0x000000F0 ;
    #endif

    #if RCC_APB1_PRESCALLER   == APB1_WITH_NO_PRESCALLER
     CLR_BIT(RCC_CFGR , 8);
     CLR_BIT(RCC_CFGR , 9);
     CLR_BIT(RCC_CFGR , 10);

    #elif RCC_APB1_PRESCALLER == APB1_WITH_2_PRESCALLER
     CLR_BIT(RCC_CFGR , 8);
     CLR_BIT(RCC_CFGR , 9);
     SET_BIT(RCC_CFGR , 10);

    #elif RCC_APB1_PRESCALLER == APB1_WITH_4_PRESCALLER
     SET_BIT(RCC_CFGR , 8);
     CLR_BIT(RCC_CFGR , 9);
     SET_BIT(RCC_CFGR , 10);

    #elif RCC_APB1_PRESCALLER == APB1_WITH_8_PRESCALLER
     CLR_BIT(RCC_CFGR , 8);
     SET_BIT(RCC_CFGR , 9);
     SET_BIT(RCC_CFGR , 10);

    #elif RCC_APB1_PRESCALLER == APB1_WITH_16_PRESCALLER
     SET_BIT(RCC_CFGR , 8);
     SET_BIT(RCC_CFGR , 9);
     SET_BIT(RCC_CFGR , 10);
    #endif

    #if RCC_APB2_PRESCALLER    == APB2_WITH_NO_PRESCALLER
     CLR_BIT(RCC_CFGR , 11);
     CLR_BIT(RCC_CFGR , 12);
     CLR_BIT(RCC_CFGR , 13);

    #elif RCC_APB2_PRESCALLER  == APB2_WITH_2_PRESCALLER
     CLR_BIT(RCC_CFGR , 11);
     CLR_BIT(RCC_CFGR , 12);
     SET_BIT(RCC_CFGR , 13);

    #elif RCC_APB2_PRESCALLER  == APB2_WITH_4_PRESCALLER
     SET_BIT(RCC_CFGR , 11);
     CLR_BIT(RCC_CFGR , 12);
     SET_BIT(RCC_CFGR , 13);

    #elif RCC_APB2_PRESCALLER  == APB2_WITH_8_PRESCALLER
     CLR_BIT(RCC_CFGR , 11);
     SET_BIT(RCC_CFGR , 12);
     SET_BIT(RCC_CFGR , 13);

    #elif RCC_APB2_PRESCALLER  == APB2_WITH_16_PRESCALLER
     SET_BIT(RCC_CFGR , 11);
     SET_BIT(RCC_CFGR , 12);
     SET_BIT(RCC_CFGR , 13);
    #endif

}