#pragma once
#include "Actor.h"
#include "SDL.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape = 'P', int NewSortOrder = 500,SDL_Color NewColor = SDL_Color{250,0,0,0});
	virtual	~APlayer();

	virtual void Tick() override;
	virtual void Render();
	bool IsCollide(int NewX, int NewY);

	Uint64 ProcessTime;

	Uint64 ElaspedTime;

	Uint8 SpriteIndex;
	Uint8 SpriteDirection;

};
