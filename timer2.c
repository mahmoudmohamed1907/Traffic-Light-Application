/*
 * timer2.c
 *
 * Created: 9/14/2022 5:57:31 AM
 *  Author: ME
 */ 
#include "timer2.h"
#include "../../registers.h"

//this function initializes the timer
void timer2_init()
{
	TCCR2 &= ~( (1<<6) | (1<<3) );   // normal mode
	TCCR2 &= ~( (1<<4) | (1<<5) );   // disconnect PIN OC0
}


// this function maker the timer start the delay
void timer2_start()
{
	TCCR2 |= ((1<<0) | (1<<1) | (1<<2));           
	TCNT2 = 110;
}



//this function stops the timer
void timer2_stop()
{
	TCCR2 &= ~((1<<0) | (1<<1) | (1<<2));             //disable timer
}


//this functions clear overflow flag

void timer2_clearOverFlowFlag()
{
	TIFR |= (1<<6);           
}




// this function sets timer current value

void timer2_setCurrentValue(uint8_t value)
{
	TCNT2 = value;
}


// this function checks if there is overflow or not
EN_timer2_OverFlowState_t timer2_checkOverFlow()
{
	return ((((TIFR & (1<<6) )>>6) == 1) ? TIMER2_OVERFLOW : TIMER2_NOTOVERFLOW);
}


// this function returns current value in timer2

uint8_t timer2_getCurrnetValue()
{
	return TCNT2;
}