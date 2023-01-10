/**************************************************************/
/* AUTHOR   : MUSTAFA MUHAMMED                                */
/* DATE     : 25 AUGUST 2021                                  */
/* VERSION  : V01                                             */
/**************************************************************/
#ifndef LED_H
#define LED_H

/* FUNCTION TO MAKE LEDS ON */
void Void_LedOn(u8 Copy_u8PortId , u8 Copy_u8PinId);

/* FUNCTION TO MAKE LEDS OFF */
void Void_LedOff(u8 Copy_u8PortId , u8 Copy_u8PinId);

/* FUNCTION TO TOGGLE LEDS */
void Void_LedToggle(u8 Copy_u8PortId , u8 Copy_u8PinId);

/* FUNCTION TO BLINK 8 LEDS ON ANY PORT */
void void_LedBlinker(u8 Copy_u8Port);

/* FUNCTION TO BKINK 8 LEDS FROM INNER TO EDGE */
void void_BlinkInOut();

/* FUNCTION TO BKINK 8 LEDS FROM EDGE TO INNER */
void void_BlinkRow()



#endif 