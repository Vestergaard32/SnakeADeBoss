#ifndef SNAKEMANAGER_H_
#define SNAKEMANAGER_H_

struct SnakeBodyPart {
	int x;
	int y;

	int prevX;
	int prevY;

	struct SnakeBodyPart* headPointer;
};

void InitSnake(struct SnakeBodyPart snakeArray[], int snakeLength);
void UpdateSnake(struct SnakeBodyPart snakeArray[], int snakeLength, int worldWidth, int worldHeight);
void GrowSnake(struct SnakeBodyPart snakeArray[], int snakeBodyLength);
int SnakeHitSelf();

#endif /* SNAKEMANAGER_H_ */