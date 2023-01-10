/*****************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                   */
/* DATE     : 23 SEP 2021                                        */
/* VERSION  : V01                                                */
/*****************************************************************/
#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

/* TFT COMMANDS */
#define SLEEP_OUT_COMMAND           0x11
#define COLOR_MODE_COMMAND          0x3A
#define DISPLAY_ON_COMMAND          0x29
#define SET_X_ADDRESS_COMMAND       0x2A
#define SET_Y_ADDRESS_COMMAND       0x2B  
#define RAM_WRITE_COMMAND           0x2C



/* AVAILABLE COLORS MODES */
#define COLOR_RGB_444       0x03
#define COLOR_RGB_565       0x05
#define COLOR_RGB_666       0x06




/* FUNCTION TO WRITE COMMAND */
static void HTFT_WriteCommand(u8 Copy_u8Command);

/* FUNCTION TO WRITE DATA */
static void HTFT_WriteData(u8 Copy_u8Data);

#endif