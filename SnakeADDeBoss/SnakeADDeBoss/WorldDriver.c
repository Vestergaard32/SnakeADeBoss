/*
 * WorldDriver.c
 *
 * Created: 12-04-2018 09:03:26
 *  Author: CodingBeagle
 */ 

 void DrawDot(unsigned char x, unsigned char y, unsigned char* world)
 {
	DrawPixel(x, y, &world);
	DrawPixel(x + 1, y, &world);
	DrawPixel(x, y + 1, &world);
	DrawPixel(x + 1, y + 1, &world);
 }

 void DrawPixel(unsigned char x, unsigned char y, unsigned char** world)
 {
	unsigned int baselineOffset = 0;
	unsigned int verticalBitOffset = 0;

	if (y > 7)
	{
		baselineOffset = ((y / 7) - 1) * 84;
		verticalBitOffset = y - (((y/7)-1) * 8);
	} 
	else
	{
		baselineOffset = 0;
		verticalBitOffset = y;
	}

	(**world)[baselineOffset + x] |= (1 << verticalBitOffset); 
 }