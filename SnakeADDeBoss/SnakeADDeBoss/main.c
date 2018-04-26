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
#include "Bitmaps.h"
#include <stdlib.h>
#include <time.h>
#include <avr/cpufunc.h>
#define F_CPU 16000000
#include <util/delay.h>

void ResetGame();

#define WORLD_WIDTH 83
#define WORLD_HEIGHT 47

#define GAME_STATE_ALIVE 1
#define GAME_STATE_DEAD 0

#define GAME_INITIAL_SPEED 60

unsigned char worldImage[504];

struct SnakeBodyPart snake[100];
struct Position currentFoodPosition;
int snakeBodyLength = 25;
int gameState = GAME_STATE_ALIVE;
int gameSpeed = GAME_INITIAL_SPEED;

int scoreOnesCounter = 0;
int scoreTensCounter = 0;
int scoreHundredsCounter = 0;
int playerHighscoreTextOffset = 50;

int main(void)
{
	InitKeypad();
	initDisplay();
	
	// Seed number generator
	srand(time(NULL));
	
	ResetGame();

	DrawIntroScreen(IntroScreenImage);
	
	// Busy Wait until user press star button
	while (GetKey() != '*')
	{
	}

	// Main Game Loop
    while (1) 
	{
		if (gameState == GAME_STATE_ALIVE)
		{
			UpdateSnake(snake, snakeBodyLength, WORLD_WIDTH, WORLD_HEIGHT);

			struct SnakeBodyPart snakeHead = snake[0];
			if (snakeHead.x < (currentFoodPosition.x + 3) &&
			(snakeHead.x + 2) > currentFoodPosition.x &&
			snakeHead.y < (currentFoodPosition.y + 2) &&
			(2 + snakeHead.y) > (currentFoodPosition.y -1))
			{
				currentFoodPosition = GenerateFoodPosition(WORLD_WIDTH, WORLD_HEIGHT);
				snakeBodyLength++;
				
				if(gameSpeed !=  0)
					gameSpeed--;
					
				GrowSnake(snake, snakeBodyLength);
				
				if (scoreOnesCounter != 9)
				{
					scoreOnesCounter += 1;
				} else if (scoreTensCounter != 9)
				{
					scoreTensCounter += 1;
					scoreOnesCounter = 0;
				} else if (scoreHundredsCounter != 9)
				{
					scoreTensCounter = 0;
					scoreHundredsCounter += 1;
				}
			}

			DrawFood(currentFoodPosition.x ,currentFoodPosition.y, worldImage);

			for(int x = 0; x < snakeBodyLength; x++)
			{
				DrawDot(snake[x].x, snake[x].y, worldImage);
			}
					
			if (SnakeHitSelf() == 1)
			{
				gameState = GAME_STATE_DEAD;
			}
					
			RenderWorld(worldImage);
		} else if (gameState == GAME_STATE_DEAD)
		{
			DrawHighscoreText(HighscoreText);
			
			// Draw player's current score
			DrawCharacter(CharacterMapper[scoreOnesCounter], playerHighscoreTextOffset + 20, 3, 8);
			DrawCharacter(CharacterMapper[scoreTensCounter], playerHighscoreTextOffset + 10, 3, 8);
			DrawCharacter(CharacterMapper[scoreHundredsCounter], playerHighscoreTextOffset, 3, 8);
			
			// Busy Wait until user press star button
			while (GetKey() != '*')
			{
			}
			
			ResetGame();
		}

		_delay_ms(gameSpeed);
    }
}

void ResetGame()
{
	gameState = GAME_STATE_ALIVE;
	setCursor(0, 0);
	clearDisplay();
	setCursor(0, 0);
	InitSnake(snake, snakeBodyLength);
	currentFoodPosition = GenerateFoodPosition(WORLD_WIDTH, WORLD_HEIGHT);
	
	scoreOnesCounter = 0;
	scoreTensCounter = 0;
	scoreHundredsCounter = 0;
	
	gameSpeed = GAME_INITIAL_SPEED;
}