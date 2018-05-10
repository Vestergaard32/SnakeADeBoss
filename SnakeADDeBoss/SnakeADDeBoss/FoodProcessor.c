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