/*
 * DIO.c
 *
 * Created: 9/10/2022 5:14:08 PM
 *  Author: ME
 */ 
#include "DIO.h"
// this function initializes port pin to be accessed
/*
1- select port name and its pin
2- choose input or output direction
3- if input , set 0 in pin number of DDRA register
4- if output , set 1 in pin number of DDRA register
*/
void DIO_init(uint8_t portNumber,uint8_t pinNumber , uint8_t direction ){
	
	switch(portNumber){
		
		case PORT_A:
		if(direction==IN){
			DDRA &= ~(1<<pinNumber);
		}
		else if (direction==OUT){
		DDRA |= (1<<pinNumber);
		}
		break;
		
		case PORT_B:
		if(direction==IN){
			DDRB &= ~(1<<pinNumber);
		}
		else if (direction==OUT){
			DDRB |= (1<<pinNumber);
		}
		break;
		
		case PORT_C:
		if(direction==IN){
			DDRC &= ~(1<<pinNumber);
		}
		else if (direction==OUT){
			DDRC |= (1<<pinNumber);
		}
		break;

		case PORT_D:
		if(direction==IN){
			DDRD &= ~(1<<pinNumber);
		}
		else if (direction==OUT){
			DDRD |= (1<<pinNumber);
		}
		break;
	}
}
/*
this function sets value of the port
1- select port name and its pin
2- choose value LOW or HIGH
3- if LOW , set 0 in pin number of PORTA register
4- if HIGH , set 1 in pin number of PORTA register
*/
void DIO_write(uint8_t portNumber,uint8_t pinNumber , uint8_t value){
	
	switch(portNumber){
		
		case PORT_A:
		if(value==LOW){
			PORTA &= ~(1<<pinNumber);
		}
		else if (value==HIGH){
			PORTA |= (1<<pinNumber);
		}
		break;
		
		case PORT_B:
		if(value==LOW){
			PORTB &= ~(1<<pinNumber);
		}
		else if (value==HIGH){
			PORTB |= (1<<pinNumber);
		}
		break;
		
		case PORT_C:
		if(value==LOW){
			PORTC &= ~(1<<pinNumber);
		}
		else if (value==HIGH){
			PORTC |= (1<<pinNumber);
		}
		break;

		case PORT_D:
		if(value==LOW){
			PORTD &= ~(1<<pinNumber);
		}
		else if (value==HIGH){
			PORTD |= (1<<pinNumber);
		}
		break;
	}
}

/*
this function read status of the port
1- select port name and its pin
2- if the value is 1 , the port is on 
3- if the value is 0 , the port is off
*/
void DIO_read(uint8_t portNumber,uint8_t pinNumber , uint8_t *value){
	
	switch(portNumber){
		case PORT_A:
		*value =(PINA & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_B:
		*value =(PINB & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_C:
		*value =(PINC & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_D:
		*value =(PIND & (1<<pinNumber))>>pinNumber;
		break;
		
		
	}
	
}

// this function toggles the LED that connected to the port
void DIO_Toggle(uint8_t portNumber,uint8_t pinNumber){
switch(portNumber){
	
	case PORT_A:
		PORTA ^= (1<<pinNumber);
	break;
	
	case PORT_B:
		PORTB ^= (1<<pinNumber);
	break;
	
	case PORT_C:
		PORTC ^= (1<<pinNumber);
	break;

	case PORT_D:
		PORTD ^= (1<<pinNumber);
	break;
}
}






