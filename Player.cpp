#include "Player.h"
#include <windows.h>
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

void APlayer::Tick(int KeyCode)
{
	//AActor::Tick(KeyCode);
	__super::Tick(KeyCode);

	if (KeyCode == 'A' || KeyCode == 'a')
	{	
		
			//GEngine->GetWorld()->GetallActors();
			X--;
		
	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		X++;
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		Y--;
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
		Y++;
	}

}

bool APlayer::IsCollide(int NewX, int NewY)
{
	for (const auto& Actor : GEngine->GetWorld()->GetallActors())
	{
		if (this == Actor)
		{
			continue;
		}

		if (Actor->bCollide == true &&
			Actor->GetX() == NewX &&
			Actor->GetY == NewY)
		{
			return true;
		}

	}
}
