/****************************************************************/
/*   AUTHOR  : MUSTAFA MUHAMMED                                 */
/*   DATE    : 7 SEP 2021                                       */
/*   VERSION : V01                                              */
/****************************************************************/
#ifndef LEDMTRX_CONFIG_H
#define LEDMTRX_CONFIG_H

/* COULUMNS PORT */
#define LEDMTRX_COL_PORT     GPIOB

/* ROWS PORT */
#define LEDMTRX_ROW_PORT     GPIOA


/* ROWS OF DOT MATRIX CONNECTED TO PORTA */
#define LEDMTRX_ROW0_PIN     GPIO_PIN0
#define LEDMTRX_ROW1_PIN     GPIO_PIN1
#define LEDMTRX_ROW2_PIN     GPIO_PIN2
#define LEDMTRX_ROW3_PIN     GPIO_PIN3
#define LEDMTRX_ROW4_PIN     GPIO_PIN4
#define LEDMTRX_ROW5_PIN     GPIO_PIN5
#define LEDMTRX_ROW6_PIN     GPIO_PIN6
#define LEDMTRX_ROW7_PIN     GPIO_PIN7


/* COULUMNS OF DOT MATRIX CONNECTED TO PORTA */
#define LEDMTRX_COL0_PIN     GPIO_PIN0
#define LEDMTRX_COL1_PIN     GPIO_PIN1
#define LEDMTRX_COL2_PIN     GPIO_PIN5
#define LEDMTRX_COL3_PIN     GPIO_PIN6
#define LEDMTRX_COL4_PIN     GPIO_PIN7
#define LEDMTRX_COL5_PIN     GPIO_PIN8
#define LEDMTRX_COL6_PIN     GPIO_PIN9
#define LEDMTRX_COL7_PIN     GPIO_PIN10

/* NUMBER OF COLUMNS */
#define NO_OF_COLUMNS        8



#endif 