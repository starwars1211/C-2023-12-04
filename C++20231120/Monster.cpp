#include "Monster.h"
#include "SimpleEngin.h"
#include "World.h"
#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GameMode.h"
#include "GameState.h"


AMonster::AMonster()
{
	Shape = 'M';
	X = 10;
	Y = 10;
	SortOrder = 300;
	bCollide = false;
	srand((unsigned int)time(nullptr));
}

AMonster::AMonster(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
}

AMonster::~AMonster()
{
}



void AMonster::Tick()
{ 
	__super::Tick();
	for (const auto& Actor : GEngine->GetWorld()->GetAllActors())
	{
		APlayer* MyPlayer = dynamic_cast<APlayer*>(Actor);
		if (MyPlayer &&
			MyPlayer->GetX() == X &&
			MyPlayer->GetY() == Y)
		{
			SimpleEngin::GetGameState()->IsGameOver = true;
			return;
		}
	}

	//random 4 direction, up, down, left, right

	int Direction = rand() % 4;
	if (Direction == (int)EMonsterDirection::Left)
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}
	}
	if (Direction == (int)EMonsterDirection::Right)
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
	}
	if (Direction == (int)EMonsterDirection::Up)
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}
	}
	if (Direction == (int)EMonsterDirection::Down)
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
}

bool AMonster::IsCollide(int NewX, int NewY)
{
	for (const auto& Actor : GEngine->GetWorld()->GetAllActors())
	{
		if (this == Actor)
		{
			continue;
		}
		if (Actor->bCollide == true &&
			Actor->GetX() == NewX &&
			Actor->GetY() == NewY)
		{
			return true;
		}
	}
	return false;
}
	/*
	srand(time(NULL));
	{
		



		int Randome = rand()%5;//01234까지 쓰겠다는 뜻
		
				if (Randome == 0)
				{
					X++;
				}
				if (Randome == 1)
				{
					X--;
				}
				if (Randome == 2)
				{
					Y=Y+1;
				}
				if (Randome == 3)
				{
					Y--;
				}
				if (Randome == 4)
				{

				};
	}
	*/



