#include "SnakeManager.h"
#include "KeypadDriver.h"
#include <string.h>

int xDirection = 1;
int yDirection = 0;
int hitSelf = 0;

void GoLeft()
{
	if (xDirection == 1)
		return;
	
	yDirection = 0;
	xDirection = -1;
}

void GoRight()
{
	if (xDirection == -1)
		return;
	
	yDirection = 0;
	xDirection = 1;
}

void GoUp()
{
	if (yDirection == 1)
	return;
	
	yDirection = -1;
	xDirection = 0;
}

void GoDown()
{
	if (yDirection == -1)
	return;
	
	xDirection = 0;
	yDirection = 1;
}

void CheckInput()
{
	if (GetKey() == '8')
	{
		GoDown();
	}

	if (GetKey() == '2')
	{
		GoUp();
	}

	if (GetKey() == '6')
	{
		GoRight();
	}

	if (GetKey() == '4')
	{
		GoLeft();
	}
}

void CheckSnakeBodyCollision(struct SnakeBodyPart snakeArray[], int snakeLength)
{
	struct SnakeBodyPart snakeHead = snakeArray[0];
	
	for (int bodyPartIndex = 1; bodyPartIndex < snakeLength; bodyPartIndex++)
	{
		struct SnakeBodyPart currentBodyPart = snakeArray[bodyPartIndex];
		
		if (snakeHead.x < (currentBodyPart.x + 2) &&
		(snakeHead.x + 2) > currentBodyPart.x &&
		snakeHead.y < (currentBodyPart.y + 2) &&
		(2 + snakeHead.y) > currentBodyPart.y)
		{
			hitSelf = 1;
		}
	}
}

void InitSnake(struct SnakeBodyPart snakeArray[], int snakeLength)
{
	if (snakeLength <= 0)
		return;
		
	// Clear Array
	memset(snakeArray, 0, snakeLength);
	hitSelf = 0;
	
	xDirection = 1;
	yDirection = 0;
		
	struct SnakeBodyPart head;
	head.x = 0;
	head.y = 0;
	head.prevX = 0;
	head.prevY = 0;
	head.headPointer = 0;
	snakeArray[0] = head;
	
	for (int snakeBodyIndex = 1; snakeBodyIndex < (snakeLength); snakeBodyIndex++)
	{
		struct SnakeBodyPart newBodyPart;
		newBodyPart.x = -2;
		newBodyPart.y = -2;
		newBodyPart.headPointer = &snakeArray[snakeBodyIndex - 1];
		snakeArray[snakeBodyIndex] = newBodyPart;
	}
}

void UpdateSnake(struct SnakeBodyPart snakeArray[], int snakeLength, int worldWidth, int worldHeight)
{
	CheckInput();
	
	for (int bodyPartIndex = 0; bodyPartIndex < snakeLength; bodyPartIndex++)
	{
		// Check for head
		if (snakeArray[bodyPartIndex].headPointer == 0)
		{
			snakeArray[bodyPartIndex].prevX = snakeArray[bodyPartIndex].x;
			snakeArray[bodyPartIndex].prevY = snakeArray[bodyPartIndex].y;
					
			if ((snakeArray[bodyPartIndex].x + 1) > worldWidth)
			{
				snakeArray[bodyPartIndex].x = 0;
				snakeArray[bodyPartIndex].y += 2 * yDirection;
			}
			else if ((snakeArray[bodyPartIndex].x) < 0) {
				snakeArray[bodyPartIndex].x = worldWidth - 1;
				snakeArray[bodyPartIndex].y += 2 * yDirection;
				} else if ((snakeArray[bodyPartIndex].y + 1) > worldHeight) {
				snakeArray[bodyPartIndex].y = 0;
				snakeArray[bodyPartIndex].x += 2 * xDirection;
				} else if ((snakeArray[bodyPartIndex].y) < 0) {
				snakeArray[bodyPartIndex].y = worldHeight - 1;
				snakeArray[bodyPartIndex].x += 2 * xDirection;
			}
			else
			{
				snakeArray[bodyPartIndex].x += 2 * xDirection;
				snakeArray[bodyPartIndex].y += 2 * yDirection;
			}
		}
		else
		{
			snakeArray[bodyPartIndex].prevX = snakeArray[bodyPartIndex].x;
			snakeArray[bodyPartIndex].prevY = snakeArray[bodyPartIndex].y;
			snakeArray[bodyPartIndex].x = snakeArray[bodyPartIndex].headPointer->prevX;
			snakeArray[bodyPartIndex].y = snakeArray[bodyPartIndex].headPointer->prevY;
		}
	}
	
	CheckSnakeBodyCollision(snakeArray, snakeLength);
}

void GrowSnake(struct SnakeBodyPart snakeArray[], int snakeBodyLength)
{
	struct SnakeBodyPart previousBodyPart = snakeArray[snakeBodyLength - 2]; 
	
	struct SnakeBodyPart newBodyPart;
	newBodyPart.x = previousBodyPart.prevX;
	newBodyPart.y = previousBodyPart.prevY;
	newBodyPart.headPointer = &snakeArray[snakeBodyLength - 2];
	snakeArray[snakeBodyLength - 1] = newBodyPart;
}

int SnakeHitSelf()
{
	return hitSelf;
}
