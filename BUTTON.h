/*
 * BUTTON.h
 *
 * Created: 9/11/2022 4:35:11 AM
 *  Author: ME
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define Button_1 PORT_D

#include "../../MCAL/DIO DRIVER/DIO.h"

void Button_init(uint8_t buttonport,uint8_t buttonpin );
void Button_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *value );






#endif /* BUTTON_H_ */