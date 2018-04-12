/*
 * SnakeADDeBoss.c
 *
 * Created: 22-Mar-18 8:26:43 AM
 * Author : mpkon
 */ 

#include <avr/io.h>
#include "Nokia5110Driver.h"
#include "WorldDriver.h"
#include <avr/cpufunc.h>
#define F_CPU 16000000
#include <util/delay.h>

unsigned char worldRender[504];

int main(void)
{
	initDisplay();

	for (int x = 0; x < 504; x++)
	{
		worldRender[x] = 0;
	}

	DrawDot(42, 24, worldRender);
	
	for (int x = 0; x < 504; x++)
	{
		sendData(worldRender[x]);
	}

    while (1) 
    {
    }
}

