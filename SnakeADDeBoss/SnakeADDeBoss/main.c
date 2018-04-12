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

struct SnakeBodyPart {
	int x;
	int y;
	SnakeBodyPart* headPointer;
};

SnakeBodyPart snake[100];
int snakeBodyLength = 1;
int xDirection = 1;
int yDirection = 0;

int main(void)
{
	initDisplay();

	for (int x = 0; x < 504; x++)
	{
		worldRender[x] = 0x00;
	}

	struct SnakeBodyPart head;
	head.x = 0;
	head.y = 0;
	head.headPointer = NULL; 
	snake[0] = head;

    while (1) 
	{
		clearDisplay();

		for (int bodyPartIndex = 0; bodyPartIndex < snakeBodyLength; bodyPartIndex++)
		{
			// Check for head
			if (snake[bodyPartIndex].headPointer == NULL)
			{
				snake[bodyPartIndex].x += 2 * xDirection;
				snake[bodyPartIndex].y += 2 * yDirection;
			}
			else
			{
				snake[bodyPartIndex].x = snake[bodyPartIndex].headPointer->x;
				snake[bodyPartIndex].y = snake[bodyPartIndex].headPointer->y;
			}
		}

		for(int x = 0; x < snakeBodyLength; x++)
		{
			DrawDot(snake[x].x, snake[x].y, worldRender);
		}

		RenderWorld(worldRender);

		_delay_ms(50);
    }
}

