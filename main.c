/*
 * Traffic light.c
 *
 * Created: 9/10/2022 4:44:32 PM
 * Author : ME
 */ 

//#include <avr/io.h>
//#include "MCAL/DIO DRIVER/DIO.h"
#include "ECUAL/LED DRIVER/LED.h"
#include "ECUAL/BUTTON DRIVER/BUTTON.h"
#include "MCAL/Timer Driver/timer.h"
#include "Application/App.h"

int main(void)
{
	APP_init();
		while(1)
		{
			APP_start();
		}

return 0;
}

