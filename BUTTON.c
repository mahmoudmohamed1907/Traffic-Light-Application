/*
 * BUTTON.c
 *
 * Created: 9/11/2022 4:34:57 AM
 *  Author: ME
 */ 

#include "BUTTON.h"

//this function Initializes button configuration
void Button_init(uint8_t buttonport,uint8_t buttonpin ){
	
	DIO_init(buttonport,buttonpin,IN);
}

//this function checks if the button pressed or not
void Button_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *value ){
	
	DIO_read(buttonport,buttonpin, value);
	
}