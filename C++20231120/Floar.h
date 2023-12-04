#pragma once
#include "Actor.h"
class AFloar : public AActor
{
public:
	AFloar();
	AFloar(int NewX, int NewY, char NewShape = ' ', int NewSortOrder = 1, SDL_Color NewColor = SDL_Color{ 128,128,10,0 });
	virtual ~AFloar();
};

