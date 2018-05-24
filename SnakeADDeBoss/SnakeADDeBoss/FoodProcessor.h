#ifndef FOODPROCESSOR_H_
#define FOODPROCESSOR_H_

/*
	Position struct is used to describe the x, y position of
	a piece of food in the world
*/
struct Position
{
	int x;
	int y;	
};

// Generate a new food position
// worldwidth = The width of the world in pixels
// worldheight = The height of the world in pixels
struct Position GenerateFoodPosition(int worldWidth, int worldHeight);

#endif /* FOODPROCESSOR_H_ */