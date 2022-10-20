/*
 * App.c
 *
 * Created: 9/12/2022 4:50:04 PM
 *  Author: ME
 */ 
#include "App.h"

#define LONG_PRESS_TIME_ms 300

uint8_t mode;    // variable to store current mode
uint8_t state;	 // variable to store current state
uint8_t flow;	 // variable to determine which led will be turning on after blinking cars yellow led
EN_pressState_t checkPress(uint8_t buttonPin,uint8_t buttonPort)
{
	uint8_t read;
	uint8_t overFlows;
	overFlows = 0;        
	timer2_start();
	while(1)
	{
		Button_read(buttonPin,buttonPort,&read);
		if( timer2_checkOverFlow() == TIMER2_OVERFLOW)
		{
			overFlows++;
			timer2_clearOverFlowFlag();
			timer2_setCurrentValue(110);
		}
		if(overFlows == 2)break;
		if(read == 0)break;
	}
	timer2_stop();
	return ((overFlows<= 1) ? SHORT_PRESS : LONG_PRESS);
}
void APP_init(void){
	LED_init(PORT_A,PIN_0);
	LED_init(PORT_A,PIN_1);
	LED_init(PORT_A,PIN_2);
	LED_init(PORT_B,PIN_0);
	LED_init(PORT_B,PIN_1);
	LED_init(PORT_B,PIN_2);	
	Button_init(Button_1,PIN_2);
	INT0_init();
	timer0_init();
	timer2_init();
	mode = NORMAL;                                              // set mode to normal
	state = FIRST;                                              // set state to FIRST
	setfCallBack(toggleYellowLed);
	

}
void toggleYellowLed()
{
	LED_Toggle(PORT_A,PIN_1);   // toggle cars yellow led
}
void blink(uint8_t led1_pin , uint8_t led1_port , uint8_t led2_pin , uint8_t led2_port)
{
	int i = 0;
	for(i = 0 ; i < 10 ; i++)
	{
		LED_Toggle(PORT_A,PIN_1);			 // toggle yellow for cars  
		LED_Toggle(PORT_B,PIN_1);             // toggle yellow for pedestrian
		timer0_delay_qS(2);                          // delay for 0.5 second
	}
}
/*
the traffic light system starts here
1- check pedestrian or normal mode
2- if normal :
   A- check state
   B- if First : turn on GREEN LED
   C- if Second : Blink YELLOW LED
   D- if third : Turn on RED LED
3- if pedestrian :
   A- check state : 
   B- if Fourth : 
      - turn off CAR YELLOW LED
	  - turn on pedestrian RED LED
	  - Blink Yellow LEDs
	  - turn off Pedestrian YELLOW LED
	  - turn off Pedestrian RED LED
	  - turn on CAR RED LED
	  - turn on pedestrian GREEN LED
	  - delay for 5 seconds
	  - turn off car RED LED
	  - Blink Yellow LEDs
	  - turn off pedestrian GREEN LED
	  - turn on CAR GREEN LED
	  - turn on pedestrian RED LED 
	  - delay for 5 seconds
	  - turn off car RED LED
	  - turn off PEDESTRIAN RED LED
	  - switch mode to normal
	  - switch state to Second
*/
void APP_start()
{
	switch(mode)
	{
		
		case NORMAL:        switch(state)
		{
			case FIRST:		
			LED_ON(PORT_A,PIN_0);                    //GREEN LED ON	 
			timer0_delay_seconds(5);                 // delay for 5 seconds
			LED_OFF(PORT_A,PIN_0);                   //GREEN LED OFF
			
			if(mode == PEDESTRIAN)                 // if interrupt switches mode to PEDESTRIAN
			state =FOURTH;                         // switch state to Fourth
			else								   // no interrupt
			state = SECOND;                        // switch state to second
			flow = DOWN;						   // set flow to down
			
			break;
			
			case SECOND:	
			
			callFunctionEachQuarterSecond(5);			//blinking cars yellow led for 5 seconds
			
			if(mode == PEDESTRIAN)					    // if interrupt switches mode to PEDESTRIAN
			state =FOURTH;					        	// switch state to Fourth
			
			else if(flow == DOWN)				    	// if flow is down
			state = THIRD;						        // switch state to third
			
			else if(flow == UP)					    	// if flow is up
			state = FIRST;						        // switch state to first
			
			break;
			
			case THIRD:     
			
			LED_ON(PORT_A,PIN_2);                     //RED LED	ON	
			timer0_delay_seconds(5);                  // delay for 5 seconds
			LED_OFF(PORT_A,PIN_2);                    //RED LED OFF     
			
			if(mode == NORMAL)						  // if mode is normal
			{
				state = SECOND;						  // switch state to second
				flow = UP;							  // switch flow to up
			}
			
			break;
		}
		break;
		
		
		
		case PEDESTRIAN:	if(state == FOURTH)
		{
			
			LED_OFF(PORT_A,PIN_1);                     //YELLOW LED OFF										    
			LED_ON(PORT_B,PIN_2);                      //RED LED ON                                        
			blink(PIN_1,PORT_B,PIN_1,PORT_A);          // blink YELLOW LEDS
			
			LED_OFF(PORT_B,PIN_2);	                   //RED LED OFF 
			LED_OFF(PORT_B,PIN_1);					   //YELLOW LED OFF  
		}
		
		LED_ON(PORT_A,PIN_2);                     //RED LED ON
		LED_ON(PORT_B,PIN_0);                     // GREEN LED ON
		timer0_delay_seconds(5);				 // delay for 5 seconds
		LED_OFF(PORT_A,PIN_2);                   // RED LED OFF
		
		
		blink(PIN_1,PORT_B,PIN_1,PORT_A);        // blink YELLOW LEDS
		
		LED_OFF(PORT_B,PIN_0);	                 // GREEN LED OFF
		
		
		LED_ON(PORT_A,PIN_0);                    // GREEN LED ON
		LED_ON(PORT_B,PIN_2);                   // RED LED ON
		timer0_delay_seconds(5);               // delay for 5 seconds
		LED_OFF(PORT_A,PIN_0);               // RED LED OFF
		LED_OFF(PORT_B,PIN_2);              // RED LED OFF
		
		mode = NORMAL;		                // switch mode to normal
		state = SECOND;		               // switch state to second
		break;
	}
}
ISR(EXT_INT_0)
{
	if(mode == NORMAL)       // if button is pressed in normal mode
	{
		timer0_stop();       // stop timer0
		if(checkPress(PIN_2,Button_1) == SHORT_PRESS)     // check long press or short press
		{
			timer0_overCome();       // overcome timer
			mode = PEDESTRIAN;       // set mode to PEDESTRIAN
		}
		else if(checkPress(PIN_2,Button_1) == LONG_PRESS)
		{

			increaseElapsedTime(LONG_PRESS_TIME_ms);
			timer0_start();			                       // start timer0
		}
	}
}