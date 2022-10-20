/*
 * LED.h
 *
 * Created: 9/11/2022 4:23:34 AM
 *  Author: ME
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO DRIVER/DIO.h"
#include "../../MCAL/Timer Driver/timer.h"

void LED_init(uint8_t ledport,uint8_t ledpin );
void LED_ON(uint8_t ledport,uint8_t ledpin );
void LED_OFF(uint8_t ledport,uint8_t ledpin );
void LED_Toggle(uint8_t ledport,uint8_t ledpin );





#endif /* LED_H_ */