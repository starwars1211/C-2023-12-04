#pragma once
#include "Actor.h"

class AMap : public AActor
{
public:
	AMap();
	AMap(int NewX, int NewY, char NewShape = '*', int NewSortOrder = 100, SDL_Color NewColor = SDL_Color{ 255, 102, 100, 0 });
	virtual ~AMap();
};

