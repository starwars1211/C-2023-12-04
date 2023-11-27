#include "Player.h"
#include "SimpleEngin.h"
#include "World.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 10;
	Y = 10;
	SortOrder = 500;
}

APlayer::APlayer(int NewX,int NewY, char NewShape, int NewSortOrder)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
}



APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	//AActor::Tick(KeyCode);
	__super::Tick();
	int KeyCode = SimpleEngin::KeyCode;

	if (KeyCode == 'A' || KeyCode == 'a')
	{	
		
			//GEngine->GetWorld()->GetallActors();
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}
	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
	if (KeyCode == 27)
	{
		GEngine->Stop();
	}

}

bool APlayer::IsCollide(int NewX, int NewY)
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
