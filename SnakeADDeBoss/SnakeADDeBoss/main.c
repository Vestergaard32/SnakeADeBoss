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
#include "SnakeManager.h"
#include "FoodProcessor.h"
#include <stdlib.h>
#include <time.h>
#include <avr/cpufunc.h>
#define F_CPU 16000000
#include <util/delay.h>

#define WORLD_WIDTH 83
#define WORLD_HEIGHT 47
unsigned char worldRender[504];

struct SnakeBodyPart snake[100];
struct Position currentFoodPosition;
int snakeBodyLength = 3;

int main(void)
{
	InitKeypad();
	initDisplay();
	
	// Seed number generator
	srand(time(NULL));

	for (int x = 0; x < 504; x++)
	{
		worldRender[x] = 0x00;
	}
	
	InitSnake(snake, snakeBodyLength);
	
	currentFoodPosition = GenerateFoodPosition(WORLD_WIDTH, WORLD_HEIGHT);

    while (1) 
	{
		UpdateSnake(snake, snakeBodyLength, WORLD_WIDTH, WORLD_HEIGHT);

		struct SnakeBodyPart snakeHead = snake[0];
		if (snakeHead.x < (currentFoodPosition.x + 3) &&
		(snakeHead.x + 2) > currentFoodPosition.x &&
		snakeHead.y < (currentFoodPosition.y + 3) &&
		(2 + snakeHead.y) > currentFoodPosition.y)
		{
			currentFoodPosition = GenerateFoodPosition(WORLD_WIDTH, WORLD_HEIGHT);
			snakeBodyLength++;
			GrowSnake(snake, snakeBodyLength);
		}

		DrawFood(currentFoodPosition.x ,currentFoodPosition.y, worldRender);

		for(int x = 0; x < snakeBodyLength; x++)
		{
			DrawDot(snake[x].x, snake[x].y, worldRender);
		}
		
		RenderWorld(worldRender);
		
		if (SnakeHitSelf() == 1)
		{
			break;
		}

		_delay_ms(25);
    }
}