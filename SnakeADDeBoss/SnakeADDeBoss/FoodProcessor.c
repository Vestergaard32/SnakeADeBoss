/*
 * FoodProcessor.c
 *
 * Created: 21-Apr-18 2:43:28 PM
 *  Author: mpkon
 */ 

#include "FoodProcessor.h"
#include <stdlib.h>
#include <time.h>

struct Position GenerateFoodPosition(int worldWidth, int worldHeight)
{	
	int newXPos = rand() % (worldWidth-2);
	int newYPos = rand() & (worldHeight-2);
	
	struct Position newPosition;
	newPosition.x = newXPos;
	newPosition.y = newYPos;
		
	return newPosition;
}