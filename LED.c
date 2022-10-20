/*
 * LED.c
 *
 * Created: 9/11/2022 4:23:17 AM
 *  Author: ME
 */ 
#include "LED.h"

//this function initializes LED configuration
void LED_init(uint8_t ledport,uint8_t ledpin ){
	DIO_init(ledport,ledpin,OUT);
}

//this function enables LED by giving value 1 to it
void LED_ON(uint8_t ledport,uint8_t ledpin ){
	DIO_write(ledport,ledpin,HIGH);
}

//this function disables LED by giving value 0 to it
void LED_OFF(uint8_t ledport,uint8_t ledpin ){
	DIO_write(ledport,ledpin,LOW);
}

//this function toggles LED
void LED_Toggle(uint8_t ledport,uint8_t ledpin ){
	
	DIO_Toggle(ledport,ledpin);
}