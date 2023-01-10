/*****************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                   */
/* DATE     : 23 SEP 2021                                        */
/* VERSION  : V01                                                */
/*****************************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H


/* FUNCTION TO INITIALIZE TFT DISPLAY */
void HTFT_voidInit(void);

/* FUNCTION TO DISPLAY IMAGE */
void HTFT_voidDisplayImage(const u16* Copy_u16_Image);

/* FUNCTION TO DISPLAY SPECIFIC COLOR */
void HTFT_voidFillColor(u16 Copy_u16Color);

/* FUNCTION TO DISPLAY RECTANGLE */
void HTFT_voidDrawRect(u16 Copy_u16Color , u16 Copy_u16X1 , u16 Copy_u16X2 , u16 Copy_u16Y1 , u16 Copy_u16Y2 );

#endif