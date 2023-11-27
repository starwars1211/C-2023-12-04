#pragma once
#include "Actor.h"

class AMap : public AActor
{
public:
	AMap();
	AMap(int NewX, int NewY, char NewShape = '*', int NewSortOrder = 100);
	virtual ~AMap();
};

