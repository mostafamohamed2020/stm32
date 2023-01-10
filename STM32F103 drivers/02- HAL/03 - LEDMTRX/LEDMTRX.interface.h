/****************************************************************/
/*   AUTHOR  : MUSTAFA MUHAMMED                                 */
/*   DATE    : 7 SEP 2021                                       */
/*   VERSION : V01                                              */
/****************************************************************/
#ifndef LEDMTRX_INTERFACE_H
#define LEDMTRX_INTERFACE_H

/* FUNCTION TO INITIALIZE LEDS */
void HLEDMTRX_voidInit();

/* FUNCTION TO DISPLAY FORM   */
/* TAKES ARRAY OF ROWS VALUES */
void HLEDMTRX_voidDisplay(u8 *Copy_u8Data);

#endif