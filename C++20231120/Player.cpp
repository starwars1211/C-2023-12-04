#include "Player.h"
#include "SimpleEngin.h"
#include "World.h"
#include "Goal.h"
#include "GameState.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 10;
	Y = 10;
	SortOrder = 500;
}

APlayer::APlayer(int NewX,int NewY, char NewShape, int NewSortOrder, SDL_Color NewColor)
{
	Shape = NewShape;
	SetX(NewX);
	SetY(NewY);
	SortOrder = NewSortOrder;
	Color = NewColor;
	LoadBMP("Data/Player.bmp", SDL_Color{255,0,255,0});
	bIsSprite = true;
	SpriteSizeX = 5;
	SpriteSizeY = 5;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	//AActor::Tick(KeyCode);
	__super::Tick();
	//int KeyCode = SimpleEngine::KeyCode;
	int KeyCode = GEngine -> MyEvent.key.keysym.sym;

	if (GEngine->MyEvent.type == SDL_KEYDOWN)
	{
		return;
	}
	
	if (SimpleEngin::GetGameState()->IsGameOver)
	{
		return;
	}
	
	if (KeyCode == SDLK_a)
	{	
		
			//GEngine->GetWorld()->GetallActors();
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}
	}
	if (KeyCode == SDLK_d)
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
	}
	if (KeyCode == SDLK_w)
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}
	}
	if (KeyCode == SDLK_s)
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
	if (KeyCode == SDLK_ESCAPE)
	{
		GEngine->Stop();
	}

	AGoal* MyGoal = nullptr;
	for (auto Actor : GEngine->GetWorld()->GetAllActors())
	{
		MyGoal = dynamic_cast<AGoal*>(Actor);
		if (MyGoal &&
			MyGoal->GetX() == X &&
			MyGoal->GetY() == Y)
		{
			SimpleEngin::GetGameState()->IsNextLevel = true;
			break;
		}
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