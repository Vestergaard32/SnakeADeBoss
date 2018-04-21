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
unsigned char worldImage[504];

struct SnakeBodyPart snake[100];
struct Position currentFoodPosition;
int snakeBodyLength = 3;

unsigned char crossImage[112] = {
	 '0', '0', '0', '1', '1', '0', '0', '0', 
	 '0', '0', '1', '1', '1', '1', '0', '0',
	 '0', '0', '1', '0', '0', '1', '0', '0',
	 '0', '0', '1', '0', '0', '1', '0', '0',
	 '0', '0', '1', '0', '0', '1', '0', '0',
	 '0', '0', '1', '0', '0', '1', '0', '0',
	 '0', '0', '1', '0', '0', '1', '0', '0',
	 '0', '0', '1', '0', '0', '1', '0', '0',
	 '0', '0', '1', '0', '0', '1', '0', '0',
	 '0', '1', '1', '0', '0', '1', '1', '0',
	 '1', '0', '0', '1', '1', '0', '0', '1',
	 '1', '0', '0', '1', '1', '0', '0', '1',
	 '0', '1', '1', '0', '0', '1', '1', '0',
	 '0', '0', '0', '0', '0', '0', '0', '0'
};

unsigned char lol[6] = {
	'1', '1',
	'0', '1',
	'0', '1'
};

unsigned char IntroScreenImage[]=
{
	/*------------------------------------------------------------------------------
	; If font display distortion, please check Fonts format of setup.
	; Source file / text :SNAKE A De BoSS
	; Width x Height (pixels) :84X48
	;  Font Format/Size : Monochrome LCD Fonts ,Horizontal scan ,Big endian order/528Byte
	;  Font make date  : 21-04-2018 15:51:55
	------------------------------------------------------------------------------*/
	0x00,0x70,0xF8,0xD8,0x98,0x00,0xF0,0xF8,0x18,0xF8,0xF0,0x00,0x00,0xF0,0xF8,0x98,
	0xF8,0xF0,0x00,0x00,0xF8,0xF8,0x40,0xF0,0xF8,0x18,0x08,0x00,0xF0,0xF8,0xD8,0xD8,
	0x00,0x00,0x00,0x00,0x00,0xF0,0xF8,0x98,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x06,0x06,0x06,0x03,0x03,0x00,0x07,0x07,0x00,0x07,0x07,0x00,
	0x00,0x07,0x07,0x01,0x07,0x07,0x00,0x00,0x07,0x07,0x00,0x03,0x07,0x07,0x04,0x00,
	0x03,0x07,0x06,0x06,0x00,0x00,0x00,0x00,0x00,0x87,0x87,0x81,0x87,0x87,0x80,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
	0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,
	0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x01,
	0x61,0x61,0x73,0x3F,0x1E,0x3C,0x7E,0x66,0x6E,0x6E,0x0C,0x00,0x00,0x00,0x00,0x00,
	0x7F,0x7F,0x01,0x6D,0x7F,0x3B,0x3C,0x7E,0x66,0x66,0x7E,0x3C,0x00,0x60,0x67,0x6F,
	0x3D,0x39,0x60,0x67,0x6F,0x3D,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,
	0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
	0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
	0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,
	0xE0,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7E,0x7E,0x06,0x06,0x06,
	0x06,0x06,0x06,0x00,0x00,0x00,0x00,0x02,0x05,0x02,0x00,0x00,0xFF,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x26,
	0x26,0x26,0x26,0x27,0x27,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

int main(void)
{
	InitKeypad();
	initDisplay();
	
	// Seed number generator
	srand(time(NULL));

	InitSnake(snake, snakeBodyLength);
	
	currentFoodPosition = GenerateFoodPosition(WORLD_WIDTH, WORLD_HEIGHT);

	DrawIntroScreen(IntroScreenImage);
	
	while (GetKey() != '*')
	{
	}

	// Main Game Loop
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

		DrawFood(currentFoodPosition.x ,currentFoodPosition.y, worldImage);

		for(int x = 0; x < snakeBodyLength; x++)
		{
			DrawDot(snake[x].x, snake[x].y, worldImage);
		}
		
		if (SnakeHitSelf() == 1)
		{
			break;
		}
		
		RenderWorld(worldImage);

		_delay_ms(25);
    }
}