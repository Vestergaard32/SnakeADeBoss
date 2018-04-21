/*
 * WorldDriver.c
 *
 * Created: 12-04-2018 09:03:26
 *  Author: CodingBeagle
 */ 
#include "WorldDriver.h"
#include "Nokia5110Driver.h"

void DrawPixel(unsigned char x, unsigned char y, unsigned char* world)
{
	if (x < 0 || x > 83)
		return;

	if (y < 0 || y > 47)
		return;

	unsigned int baselineOffset = 0;
	unsigned int verticalBitOffset = 0;

	if (y >= 0 && y <= 7)
	{
		baselineOffset = 0;
		verticalBitOffset = y;
	} 
	else if (y >= 8 && y <= 15)
	{
		baselineOffset = 84;
		verticalBitOffset = y - 8;
	} 
	else if (y >= 16 && y <= 23)
	{
		baselineOffset = 84 * 2;
		verticalBitOffset = y - (8 * 2);
	} 
	else if (y >= 24 && y <= 31)
	{
		baselineOffset = 84 * 3;
		verticalBitOffset = y - (8 * 3);
	}
	else if (y >= 32 && y <= 39)
	{
		baselineOffset = 84 * 4;
		verticalBitOffset = y - (8 * 4);
	}
	else if (y >= 40 && y <= 47)
	{
		baselineOffset = 84 * 5;
		verticalBitOffset = y - (8 * 5);
	}

	world[baselineOffset + x] |= (1 << verticalBitOffset);
}

 void DrawDot(unsigned char x, unsigned char y, unsigned char* world)
 {
	DrawPixel(x, y, world);
	DrawPixel(x + 1, y, world);
	DrawPixel(x, y + 1, world);
	DrawPixel(x + 1, y + 1, world);
 }
 
 void DrawFood(unsigned char x, unsigned char y, unsigned char* world)
 {
	DrawPixel(x, y, world);
	DrawPixel(x + 2, y, world);
	DrawPixel(x + 1, y + 1, world);
	DrawPixel(x + 1, y - 1, world);
 }
 

 void RenderWorld(unsigned char* world)
 {
	for (int x = 0; x < 504; x++)
	{
		sendData(world[x]);
	}

	for (int x = 0; x < 504; x++)
	{
		world[x] = 0x00;
	}
 }