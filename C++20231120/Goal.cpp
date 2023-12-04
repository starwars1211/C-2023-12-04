#include "Goal.h"

AGoal::AGoal()
{
	Shape = 'G';
	X = 10;
	Y = 10;
	SortOrder = 200;
}

AGoal::AGoal(int NewX, int NewY, char NewShape, int NewSortOrder, SDL_Color NewColor)
{
	Shape = NewShape;
	X = NewX;
	Y = NewY;
	SortOrder = NewSortOrder;
	Color = NewColor;
	LoadBMP("Data/coin.bmp");
}

AGoal::~AGoal()
{
}
