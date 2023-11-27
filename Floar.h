#pragma once
#include "Actor.h"
class AFloar : public AActor
{
public:
	AFloar();
	AFloar(int NewX, int NewY, char NewShape = ' ', int NewSortOrder = 1);
	virtual ~AFloar();
};

