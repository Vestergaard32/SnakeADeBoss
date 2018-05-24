#ifndef SNAKEMANAGER_H_
#define SNAKEMANAGER_H_

/*
	The SnakeBodyPart struct is used to
	for each individual part of the snake
*/
struct SnakeBodyPart {
	// The x position in the world
	int x;

	// The y position in the world
	int y;

	// The x position of the previous frame
	int prevX;

	// The y position of the previous frame
	int prevY;

	// A pointer to a chained up snake body part
	struct SnakeBodyPart* headPointer;
};

// Create a snake in the passed snakeArray, with a given length in snake body parts
void InitSnake(struct SnakeBodyPart snakeArray[], int snakeLength);

// Update movement of the snake to advance it one frame
void UpdateSnake(struct SnakeBodyPart snakeArray[], int snakeLength, int worldWidth, int worldHeight);

// Grow the snake by one snake body part
void GrowSnake(struct SnakeBodyPart snakeArray[], int snakeBodyLength);

// Get a number indicating if the snake has collided with itself (1 = true, 0 = false)
int SnakeHitSelf();

#endif /* SNAKEMANAGER_H_ */