/******************************************************/
/* AUTHOR    : MUSTAFA MUHAMMED                       */
/* DATE      : 29 AUGUST 2021                         */
/* VERSION   : V01                                    */
/******************************************************/

void MAFIO_voidSetExtrnalConfiguration(u8 Copy_u8Line , u8 Copy_u8PortMap)
{
     
    if (Copy_u8Line <= 3 )
    {
    	AFIO -> EXTICR1 &= ~((0b1111) << (Copy_u8Line * 4));
    	AFIO -> EXTICR1 |= ( Copy_u8PortMap << (Copy_u8Line * 4));

    }
    else if (Copy_u8Line <= 7)
    {
    	Copy_u8Line -= 4 ;
    	AFIO -> EXTICR2 &= ~((0b1111) << (Copy_u8Line * 4));
    	AFIO -> EXTICR2 |= ( Copy_u8PortMap << (Copy_u8Line * 4));
    }
    else if (Copy_u8Line <= 11)
    {
    	Copy_u8Line -= 8 ;
    	AFIO -> EXTICR3 &= ~((0b1111) << (Copy_u8Line * 4));
    	AFIO -> EXTICR3 |= ( Copy_u8PortMap << (Copy_u8Line * 4));
    }
    else if (Copy_u8Line <= 15)
    {
    	Copy_u8Line -= 12 ; 
    	AFIO -> EXTICR4 &= ~((0b1111) << (Copy_u8Line * 4));
    	AFIO -> EXTICR4 |= ( Copy_u8PortMap << (Copy_u8Line * 4));
    }


}