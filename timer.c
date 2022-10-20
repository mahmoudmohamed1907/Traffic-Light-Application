/*
 * timer.c
 *
 * Created: 9/11/2022 6:18:03 AM
 *  Author: ME
 */ 
#include "timer.h"

uint16_t elapsed_time_ms = 0;  
void (*fCallBack)(void);               

//this function initializes the timer
void timer0_init(void){
	
	TCCR0 = 0x00; //normal mode
	
}
// this function maker the timer start the delay
void timer0_start(void){
	
	TCCR0 |= 0x5;  //set prescaler 1024 (1 0 1)
}
//this function stops the timer
void timer0_stop(void){
	TCCR0 = 0x00;
}
//breaking busy wait delay by assign max value of unsigned int to variable elapsed_time_ms
void timer0_overCome()
{
	elapsed_time_ms = MAX_16;
}


//this function increases elapsed time
void increaseElapsedTime(uint16_t value)
{
	elapsed_time_ms += value;
}




//this function takes seconds and generate the delay
//By controlling the value of variable elapsed_time_ms , the delay will be stopped
void timer0_delay_seconds(uint8_t seconds)       
{
	TCNT0 = 12;                              // make 12 in timer0 is 0
	elapsed_time_ms = 0;
	timer0_start();
	while(elapsed_time_ms < seconds*1000)
	{
		if( (TIFR & (1<<0) ) == 1)      
		{
			elapsed_time_ms += 250;      //increment elapsed_time by 250
			TIFR |= (1<<0);              // clear overflow flag
			TCNT0 = 12;                  // make 12 in timer0 is 0
		}
	}
	timer0_stop();
}




//this function takes quarter of seconds and generate the delay
//By controlling the value of variable elapsed_time_ms , the delay will be stopped
void timer0_delay_qS(uint16_t times)    
{
		TCNT0 = 12;                              // make 12 in timer0 is 0
		elapsed_time_ms = 0;
		timer0_start();
		while(elapsed_time_ms < times*250)
		{
			if( (TIFR & (1<<0) ) == 1)
			{
				elapsed_time_ms += 250;      //increment elapsed_time by 250
				TIFR |= (1<<0);              // clear overflow flag
				TCNT0 = 12;                  // make 12 in timer0 is 0
			}
		}
		timer0_stop();


}



// this function sets callback
void setfCallBack(void (*callBack)(void))
{
	fCallBack = callBack;
}



/*
this function used to call function  pointed by fCallBack as times as you want
*/
void callFunctionEachQuarterSecond(uint16_t times)
{
	TCNT0 = 12;                              // make 12 in timer0 is 0
	elapsed_time_ms = 0;
	timer0_start();
	while(elapsed_time_ms < times*1000)
	{
		if( (TIFR & (1<<0) ) == 1)
		{
			elapsed_time_ms += 250;      //increment elapsed_time by 250
			TIFR |= (1<<0);              // clear overflow flag
			TCNT0 = 12;                  // make 12 in timer0 is 0
			fCallBack();                 // call function which is pointed by fCallBack
		}
	}
	timer0_stop();

}



// this function checks if there is overflow or not
EN_timer0_OverFlowState_t timer0_checkOverFlow()
{
	return (((TIFR & (1<<0) ) == 1) ? 1 : 0);
}




// this function returns current value of the timer
uint8_t timer0_CurrnetValue()
{
	return TCNT0;
}




//this function clears overflow flag

void timer0_clearOverFlowFlag()
{
	TIFR |= (1<<0);            // clear overflow flag
}


//this function sets timer current value
void timer0_setCurrentValue(uint8_t value)
{
	TCNT0 = value;
}