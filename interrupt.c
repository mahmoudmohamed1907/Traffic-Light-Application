/*
 * interrupt.c
 *
 * Created: 9/14/2022 3:56:26 AM
 *  Author: ME
 */ 
#include "interrupt.h"

// this function initializes INT0 configuration
void INT0_init(void){
		sei(); //enable global interrupt
		
		MCUCR |= (1<<0) | (1<<1); //rising edge sense change
		
		GICR |=(1<<6); //enable external interrupt 0 - INT0
}