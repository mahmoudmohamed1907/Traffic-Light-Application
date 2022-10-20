/*
 * timer.h
 *
 * Created: 9/11/2022 6:17:50 AM
 *  Author: ME
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../registers.h"
#include "../../typedefs.h"

typedef enum EN_timer0_OverFlowState_t
{
	TIMER0_NOTOVERFLOW , TIMER0_OVERFLOW
}EN_timer0_OverFlowState_t;


#define MAX_16	65535


void timer0_init(void);
void timer0_start(void);
void timer0_stop(void);
void timer0_clearOverFlowFlag();
void timer0_setCurrentValue(uint8_t value);
EN_timer0_OverFlowState_t timer0_checkOverFlow();
uint8_t timer0_CurrnetValue();
void timer0_overCome();
void timer0_delay_seconds(uint8_t seconds);
void timer0_delay_qS(uint16_t times);
void setfCallBack(void (*callBack)(void));
void callFunctionEachQuarterSecond(uint16_t times);
void increaseElapsedTime(uint16_t value);



#endif /* TIMER_H_ */