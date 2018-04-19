/*
 * SnakeADDeBoss.c
 *
 * Created: 22-Mar-18 8:26:43 AM
 * Author : mpkon
 */ 

#include <avr/io.h>
#include "Nokia5110Driver.h"
#include "KeypadDriver.h"
#include "WorldDriver.h"
#include <avr/cpufunc.h>
#define F_CPU 16000000
#include <util/delay.h>

unsigned char worldRender[504];

struct SnakeBodyPart {
	int x;
	int y;

	int prevX;
	int prevY;

	struct SnakeBodyPart* headPointer;
};


struct SnakeBodyPart snake[100];
int snakeBodyLength =3;
int xDirection = 1;
int yDirection = 0;


int main(void)
{
	InitKeypad();
	//initDisplay();

	for (int x = 0; x < 504; x++)
	{
		worldRender[x] = 0x00;
	}
	
	struct SnakeBodyPart head;
	head.x = 0;
	head.y = 0;
	head.prevX = 0;
	head.prevY = 0;
	head.headPointer = 0;
	snake[0] = head;

	struct SnakeBodyPart middle;
	middle.x = 0;
	middle.y = 0;
	middle.headPointer = &snake[0];
	snake[1] = middle;

	struct SnakeBodyPart middle1;
	middle1.x = 0;
	middle1.y = 0;
	middle1.prevX = 0;
	middle1.prevY = 0;
	middle1.headPointer = &snake[1];
	snake[2] = middle1;
	
	struct SnakeBodyPart end;
	end.x = 0;
	end.y = 0;
	end.headPointer = &snake[2];
	snake[3] = end;

    while (1) 
	{
	/*
		clearDisplay();
		
		for (int bodyPartIndex = 0; bodyPartIndex < snakeBodyLength; bodyPartIndex++)
		{
			// Check for head
			if (snake[bodyPartIndex].headPointer == 0)
			{
				snake[bodyPartIndex].prevX = snake[bodyPartIndex].x;
				snake[bodyPartIndex].prevY = snake[bodyPartIndex].y;
				snake[bodyPartIndex].x += 2 * xDirection;
				snake[bodyPartIndex].y += 2 * yDirection;
			}
			else
			{
				snake[bodyPartIndex].prevX = snake[bodyPartIndex].x;
				snake[bodyPartIndex].prevY = snake[bodyPartIndex].y;
				snake[bodyPartIndex].x = snake[bodyPartIndex].headPointer->prevX;
				snake[bodyPartIndex].y = snake[bodyPartIndex].headPointer->prevY;
			}
		}
		*/

		if (GetKey() == 1)
		{
			yDirection = 1;
			xDirection = 0;
		}

		/*
		if (GetKey() == 0)
		{
			yDirection = 0;
			xDirection = -1;
		}*/

		/*
		for(int x = 0; x < snakeBodyLength; x++)
		{
			DrawDot(snake[x].x, snake[x].y, worldRender);
		}
		
		RenderWorld(worldRender);
		*/

		_delay_ms(100);
    }
}

