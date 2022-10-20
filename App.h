/*
 * App.h
 *
 * Created: 9/12/2022 4:50:47 PM
 *  Author: ME
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/LED DRIVER/LED.h"
#include "../ECUAL/BUTTON DRIVER/BUTTON.h"
#include "../MCAL/Interrupt/interrupt.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../MCAL/Timer Driver/timer2.h"
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2



typedef enum EN_Modes_t
{
	NORMAL, PEDESTRIAN
}EN_Modes_t;



typedef enum EN_States_t
{
	FIRST, SECOND , THIRD , FOURTH
}EN_States_t;



typedef enum EN_pressState_t
{
	SHORT_PRESS, LONG_PRESS
}EN_pressState_t;




typedef enum EN_carsLedsFlowDirection_t
{
	DOWN, UP
}EN_carsLedsFlowDirection_t;



// functions prototypes

void APP_init(void);
void APP_start();
EN_pressState_t checkPress(uint8_t buttonPin,uint8_t buttonPort);
void toggleYellowLed();
void blink(uint8_t led1_pin , uint8_t led1_port , uint8_t led2_pin , uint8_t led2_port);






#endif /* APP_H_ */