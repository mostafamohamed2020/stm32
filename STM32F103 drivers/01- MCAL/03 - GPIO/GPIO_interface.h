/*********************************************************/
/*       AUTHOR : MOSTAFA MOHAMED                        */
/*       DATE   : 16 MAY 2021                            */
/*       @ 1:48 AM                                       */
/*       VERSION : V01                                   */
/*********************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*********************************************************/
/*      THREE PORTS IN STM32F10 CONTROLLER               */
/*         1 - PORTA (16 PINS)                           */
/*         2 - PORTB (16 PINS)                           */
/*         3 - PORTC (3 PINS)                            */
/*********************************************************/
#define GPIOA        0
#define GPIOB        1
#define GPIOC        2

#define GPIO_PIN0    0
#define GPIO_PIN1    1
#define GPIO_PIN2    2
#define GPIO_PIN3    3
#define GPIO_PIN4    4
#define GPIO_PIN5    5
#define GPIO_PIN6    6
#define GPIO_PIN7    7
#define GPIO_PIN8    8
#define GPIO_PIN9    9
#define GPIO_PIN10   10
#define GPIO_PIN11   11
#define GPIO_PIN12   12
#define GPIO_PIN13   13
#define GPIO_PIN14   14
#define GPIO_PIN15   15

/****************************************************************/
/*      AVAILABLE MODES FOR EACH PIN                            */
/*         1 - OUTPUT PIN @ 2MHZ                                */
/*             1.1 - OUTPUT PIN PUSH-PULL                       */
/*             1.2 - OUTPUT PIN OPEN DRAIN                      */
/*             1.3 - OUTPUT PIN ALTERNATIVE PUSH-PULL           */
/*             1.4 - OUTPUT PIN ALTERNATIVE OPEN DRAIN          */
/*         2 - OUTPUT PIN @ 10MHZ                               */
/*             2.1 - OUTPUT PIN PUSH-PULL                       */
/*             2.2 - OUTPUT PIN OPEN DRAIN                      */
/*             2.3 - OUTPUT PIN ALTERNATIVE PUSH-PULL           */
/*             2.4 - OUTPUT PIN ALTERNATIVE OPEN DRAIN          */
/*         3 - OUTPUT PIN @ 50MHZ                               */
/*             3.1 - OUTPUT PIN PUSH-PULL                       */
/*             3.2 - OUTPUT PIN OPEN DRAIN                      */
/*             3.3 - OUTPUT PIN ALTERNATIVE PUSH-PULL           */
/*             3.4 - OUTPUT PIN ALTERNATIVE OPEN DRAIN          */
/*         4 - INPUT PIN                                        */
/*             4.1 - INPUT PIN ANALOG                           */
/*             4.2 - OUTPUT PIN FLOATING                        */
/*             4.3 - OUTPUT PIN WITH PULL UP                    */
/*                                                              */
/*   EACH PIN HAS FOUR BITS FOR CONFIGURATION                   */
/*             TWO LOW PINS FOR INPUT OR OUTPUT                 */
/*             TWO HIGH PINS FOR CONFIGURATION                  */
/****************************************************************/
#define GPIO_INPUT_PIN_ANALOG                        0b0000
#define GPIO_INPUT_PIN_FLOATING                      0b0100
#define GPIO_INPUT_PIN_WITH_PULLUP                   0b1000

#define GPIO_OUTPUT_PIN_2MHZ_PUSH_PULL               0b0010
#define GPIO_OUTPUT_PIN_2MHZ_OPEN_DRAIN              0b0110 
#define GPIO_OUTPUT_PIN_2MHZ_ALTERNATIVE_PUSH_PULL   0b1010
#define GPIO_OUTPUT_PIN_2MHZ_ALTERNATIVE_OPEN_DRAIN  0b1110

#define GPIO_OUTPUT_PIN_10MHZ_PUSH_PULL              0b0001
#define GPIO_OUTPUT_PIN_10MHZ_OPEN_DRAIN             0b0101
#define GPIO_OUTPUT_PIN_10MHZ_ALTERNATIVE_PUSH_PULL  0b1001
#define GPIO_OUTPUT_PIN_10MHZ_ALTERNATIVE_OPEN_DRAIN 0b1101

#define GPIO_OUTPUT_PIN_50MHZ_PUSH_PULL              0b0011
#define GPIO_OUTPUT_PIN_50MHZ_OPEN_DRAIN             0b0111
#define GPIO_OUTPUT_PIN_50MHZ_ALTERNATIVE_PUSH_PULL  0b1011
#define GPIO_OUTPUT_PIN_50MHZ_ALTERNATIVE_OPEN_DRAIN 0b1111

/************************************************************/
/*     AVAILABLE OUTPUT ON EACH PIN                         */
/*               1 - HIGH 3.3 VOLT                          */
/*               2 - LOW  0   VOLT                          */
/************************************************************/
#define GPIO_HIGH  1
#define GPIO_LOW   0


/* FUNCTION TO SET THE MODE OF ANY PIN IN ANY PORT */
void GPIO_voidSetPinDir(u8 Copy_u8_PORT , u8 Copy_u8_PIN , u8 Copy_u8_Mode);

/* FUNCTION THAT SET THE VALUE OF ANY PIN IN ANY PORT */
void GPIO_voidSetPinVal(u8 Copy_u8_PORT , u8 Copy_u8_PIN , u8 Copy_u8_Value);

/* FUNCTION THAT SET THE DIRECTION OF ANY PIN IN ANY PORT */
void GPIO_voidSetPortDir(u8 Copy_u8_PORT , u16 Copy_u8_Value);

/* FUNCTION THAT SET THE VALUE OF ANY PIN IN ANY PORT */
void GPIO_voidSetPortVal(u8 Copy_u8_PORT , u16 Copy_u8_Value);

/* FUNCTION TO GET THE STATUS OF ANY PIN */
u8 GPIO_u8GetPinValue(u8 Copy_u8_PORT , u8 Copy_u8_PIN );

/* FUNCTION TO ENABLE THE INTERNAL PULL-UP RESISTOR */
void GPIO_VoidSetPullUp(u8 Copy_u8_PORT , u8 Copy_u8_PIN);

/* FUNCTION TO ENABLE THE INTERNAL PULL-DOWN RESISTOR */
void GPIO_VoidSetPullDown(u8 Copy_u8_PORT , u8 Copy_u8_PIN);

#endif