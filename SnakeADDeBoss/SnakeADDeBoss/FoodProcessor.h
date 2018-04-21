/*
 * FoodProcessor.h
 *
 * Created: 21-Apr-18 2:33:30 PM
 *  Author: mpkon
 */ 


#ifndef FOODPROCESSOR_H_
#define FOODPROCESSOR_H_

struct Position
{
	int x;
	int y;	
};

struct Position GenerateFoodPosition(int worldWidth, int worldHeight);

#endif /* FOODPROCESSOR_H_ */