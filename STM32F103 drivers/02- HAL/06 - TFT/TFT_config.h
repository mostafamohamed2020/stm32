/*****************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                   */
/* DATE     : 23 SEP 2021                                        */
/* VERSION  : V01                                                */
/*****************************************************************/
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

/*****************************************************************/
/*                   TFT CONFIGURATION                           */
/* 1 - IDEAL HIGH POLARITY                                       */
/* 2 - WRITE THEN RAED                                           */
/* 3 - MSB SENT FIRST                                            */
/* 4 - MAXIMUM SPEED 15 MEGA HZ                                  */
/*****************************************************************/

/* TFT PIN WHICH DECIDE TO WRITE COMMAND OR DATA */
#define TFT_A0_PORT         GPIOA
#define TFT_A0_PIN          GPIO_PIN3

/* TFT RESET PIN */
#define TFT_RESET_PORT      GPIOB
#define TFT_RESET_PIN       GPIO_PIN0

/* NUMBER OF ROWS AND COLUMNS */
#define NO_OF_ROWS          160
#define NO_OF_COL           128

#endif