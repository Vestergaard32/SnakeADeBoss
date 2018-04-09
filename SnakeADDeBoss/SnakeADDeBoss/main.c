/*
 * SnakeADDeBoss.c
 *
 * Created: 22-Mar-18 8:26:43 AM
 * Author : mpkon
 */ 

#include <avr/io.h>
#include "Nokia5110Driver.h"

int main(void)
{
	initDisplay();

	sendData(0xFF);

    while (1) 
    {
    }
}

