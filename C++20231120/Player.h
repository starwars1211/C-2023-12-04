#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape = 'P', int NewSortOrder = 500);
	virtual	~APlayer();

	virtual void Tick() override;
	bool IsCollide(int NewX, int NewY);

};
