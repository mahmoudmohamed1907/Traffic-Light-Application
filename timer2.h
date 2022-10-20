/*
 * timer2.h
 *
 * Created: 9/14/2022 5:58:04 AM
 *  Author: ME
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "../../typedefs.h"

typedef enum EN_timer2_OverFlowState_t
{
TIMER2_NOTOVERFLOW , TIMER2_OVERFLOW
}EN_timer2_OverFlowState_t;


// functions prototypes
void timer2_init();
void timer2_start();
void timer2_stop();
void timer2_clearOverFlowFlag();
void timer2_setCurrentValue(uint8_t value);
EN_timer2_OverFlowState_t timer2_checkOverFlow();
uint8_t timer2_getCurrnetValue();





#endif /* TIMER2_H_ */