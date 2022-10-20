/*
 * DIO.h
 *
 * Created: 9/10/2022 5:14:22 PM
 *  Author: ME
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../registers.h"
#include "../../typedefs.h"


#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// direction
#define IN 0
#define OUT 1

//value
#define LOW 0
#define HIGH 1

void DIO_init(uint8_t portNumber,uint8_t pinNumber , uint8_t direction );
void DIO_write(uint8_t portNumber,uint8_t pinNumber , uint8_t value);
void DIO_read(uint8_t portNumber,uint8_t pinNumber , uint8_t* value);
void DIO_Toggle(uint8_t portNumber,uint8_t pinNumber);


#endif /* DIO_H_ */