#include <avr/io.h>
#include <stdio.h>
#include "Nokia5110Driver.h"
#include "KeypadDriver.h"
#include "WorldDriver.h"
#include "SnakeManager.h"
#include "FoodProcessor.h"
#include "FlashDriver.h"
#include "Bitmaps.h"
#include <stdlib.h>
#include <time.h>
#include <avr/cpufunc.h>
#define F_CPU 16000000
#include <util/delay.h>

void ResetGame();

// The world width and height in pixels
#define WORLD_WIDTH 83
#define WORLD_HEIGHT 47

// The game states for the game (either the snake is alive or dead)
#define GAME_STATE_ALIVE 1
#define GAME_STATE_DEAD 0

// The movement speed for the snake at the beginning of a new round
#define GAME_INITIAL_SPEED 60

// The length of the snake (in snake body parts) at the beginning of the round
#define GAME_INITIAL_SNAKE_LENGTH 4

unsigned char worldImage[504];

// The array used to contain the snake during the entire game
struct SnakeBodyPart snake[100];

// The position of the currently displayed food of the game
struct Position currentFoodPosition;
int snakeBodyLength = GAME_INITIAL_SNAKE_LENGTH;
int gameState = GAME_STATE_ALIVE;
int gameSpeed = GAME_INITIAL_SPEED;

int scoreOnesCounter = 0;
int scoreTensCounter = 0;
int scoreHundredsCounter = 0;
int playerHighscoreTextOffset = 60;
int storedHighscoreTextOffset = 0;

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

			// Detect if the snake has hit a piece of food in the world
			struct SnakeBodyPart snakeHead = snake[0];
			if (snakeHead.x < (currentFoodPosition.x + 3) &&
			(snakeHead.x + 2) > currentFoodPosition.x &&
			snakeHead.y < (currentFoodPosition.y + 2) &&
			(2 + snakeHead.y) > (currentFoodPosition.y -1))
			{
				// Generate a new position for a new piece of food
				currentFoodPosition = GenerateFoodPosition(WORLD_WIDTH, WORLD_HEIGHT);
				snakeBodyLength++;
				
				// Increase the movement speed of the snake to make the game harder
				// This is done by decreasing the update interval between each frame
				if(gameSpeed !=  0)
					gameSpeed--;
				
				// Grow the snake by two body parts
				GrowSnake(snake, snakeBodyLength);
				snakeBodyLength++;
				GrowSnake(snake, snakeBodyLength);
				
				// Increase the user score
				if (scoreOnesCounter != 9)
				{
					scoreOnesCounter += 1;
				} else if (scoreTensCounter != 9)
				{
					scoreTensCounter += 1;
					scoreOnesCounter = 0;
				} else if (scoreHundredsCounter != 9)
				{
					scoreOnesCounter = 0;
					scoreTensCounter = 0;
					scoreHundredsCounter += 1;
				}
			}

			// Draw the newly generated food, which is the next food that the
			// User has to get
			DrawFood(currentFoodPosition.x ,currentFoodPosition.y, worldImage);

			// Draw the entire snake
			for(int i = 0; i < snakeBodyLength; i++)
			{
				DrawDot(snake[i].x, snake[i].y, worldImage);
			}
					
			// Check if the snake has collided with itself
			// And if this is the case, set the game state to be lost
			if (SnakeHitSelf() == 1)
			{
				gameState = GAME_STATE_DEAD;
			}

			// Render the entire frame of the world in its current state
			RenderWorld(worldImage);
		} else if (gameState == GAME_STATE_DEAD)
		{
			DrawHighscoreText(HighscoreText);
			
			// Draw player's current score
			DrawCharacter(CharacterMapper[scoreOnesCounter], playerHighscoreTextOffset + 16, 3, 8);
			DrawCharacter(CharacterMapper[scoreTensCounter], playerHighscoreTextOffset + 8, 3, 8);
			
			// Read stored player scores
			unsigned char storedScores[3];
			FlashRead(storedScores);
			
			unsigned char currentPlayerScore = (scoreTensCounter * 10) + scoreOnesCounter;
			
			// Check if current score should be in stored scores
			unsigned char highscoreComparer = currentPlayerScore;
			for (int x = 0; x < 3; x++)
			{
				if (storedScores[x] >= 100 || storedScores[x] < 0)
				{
					storedScores[x] = 0;
				}
				
				if (highscoreComparer > storedScores[x])
				{
					unsigned char currentHighscoreInSpot = storedScores[x];
					storedScores[x] = highscoreComparer;
					highscoreComparer = currentHighscoreInSpot;
				}
			}
			
			unsigned char onesDigit = 0;
			unsigned char tensDigit = 0;
	
			// Draw 1. highscore
			char scoreString[10];
			sprintf(scoreString, "%02d", storedScores[0]);
			
			onesDigit = scoreString[1] - 48;
			tensDigit = scoreString[0] - 48;
			
			DrawCharacter(CharacterMapper[1], storedHighscoreTextOffset, 2, 8);
			DrawCharacter(Dot, storedHighscoreTextOffset + 8, 2, 8);
			DrawCharacter(CharacterMapper[tensDigit], storedHighscoreTextOffset + 16, 2, 8);
			DrawCharacter(CharacterMapper[onesDigit], storedHighscoreTextOffset + 24, 2, 8);
		
			// Draw 2. highscore
			sprintf(scoreString, "%02d", storedScores[1]);
			
			onesDigit = scoreString[1] - 48;
			tensDigit = scoreString[0] - 48;
						
			DrawCharacter(CharacterMapper[2], storedHighscoreTextOffset, 3, 8);
			DrawCharacter(Dot, storedHighscoreTextOffset + 8, 3, 8);
			DrawCharacter(CharacterMapper[tensDigit], storedHighscoreTextOffset + 16, 3, 8);
			DrawCharacter(CharacterMapper[onesDigit], storedHighscoreTextOffset + 24, 3, 8);
			
			// Draw 3. highscore
			sprintf(scoreString, "%02d", storedScores[2]);
						
			onesDigit = scoreString[1] - 48;
			tensDigit = scoreString[0] - 48;
						
			DrawCharacter(CharacterMapper[3], storedHighscoreTextOffset, 4, 8);
			DrawCharacter(Dot, storedHighscoreTextOffset + 8, 4, 8);
			DrawCharacter(CharacterMapper[tensDigit], storedHighscoreTextOffset + 16, 4, 8);
			DrawCharacter(CharacterMapper[onesDigit], storedHighscoreTextOffset + 24, 4, 8);
			
			FlashWrite(storedScores);
			
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
	snakeBodyLength = GAME_INITIAL_SNAKE_LENGTH;
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