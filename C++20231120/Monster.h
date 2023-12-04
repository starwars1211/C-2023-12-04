#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public: 
	AMonster();
	AMonster(int NewX, int NewY, char NewShape = 'M', int NewSortOrder = 300, SDL_Color NewColor = SDL_Color{ 0, 0, 255, 0 });
	virtual ~AMonster();

	virtual void Tick() override;
	bool IsCollide(int NewX, int NewY);

	Uint64 ProcessTime;

	Uint64 ElaspedTime;

	enum class EMonsterDirection
	{
		Left = 0,
		Right = 1,
		Down,
		Up
	};
};

