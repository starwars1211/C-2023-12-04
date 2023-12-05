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
	SpriteIndex = 0;
	SpriteDirection = 0;
	ElaspedTime = 0;
	ProcessTime = 400;

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
	SpriteIndex = 0;
	SpriteDirection = 0;
	ElaspedTime = 0;
	ProcessTime = 400;
}

APlayer::~APlayer()
{
}


void APlayer::Tick()
{
	//AActor::Tick(KeyCode);
	__super::Tick();
	//int KeyCode = SimpleEngine::KeyCode;
	ElaspedTime += GEngine->GetWorldDeltaSeconds(); // 시간 계산
	if (ElaspedTime >= ProcessTime)
	{
		SpriteIndex++;
		SpriteIndex = SpriteIndex % SpriteSizeX;
		//SDL_Rect SrcRect = SDL_Rect{ 0,0,MySurface->w / SpriteSizeX,MySurface->h / SpriteSizeY };
		ElaspedTime = 0;
		return;
	}

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
			SpriteDirection = 0;
			X--;
		}
	}
	if (KeyCode == SDLK_d)
	{
		if (!IsCollide(X + 1, Y))
		{
			SpriteDirection = 1;
			X++;
		}
	}
	if (KeyCode == SDLK_w)
	{
		if (!IsCollide(X, Y - 1))
		{	
			SpriteDirection = 2;
			Y--;
		}
	}
	if (KeyCode == SDLK_s)
	{
		if (!IsCollide(X, Y + 1))
		{
			SpriteDirection = 3;
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

void APlayer::Render()
{
	//SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	/*for (int j = 0; j < Size; ++j)
	{
		for (int i = 0; i < Size; ++i)
		{
			SDL_RenderDrawPoint(GEngine->MyRenderer, X + i, Y + j);
		}

	}

	//SDL_RenderDrawPoint(GEngine->MyRenderer, X, Y);
	//SDL_RenderFillRect(GEngine->MyRenderer,new SDL_Rect{ X * Size, Y * Size,Size,Size });
	SDL_RenderCopy(GEngine->MyRenderer,
		MyTexture,
		new SDL_Rect{ 0,0,MySurface->w / 5,MySurface->h / 5 },
		new SDL_Rect{ X * Size, Y * Size,Size,Size });
		*/

		//SDL_RenderCopy(GEngine->MyRenderer,
			//MyTexture,
			//new SDL_Rect{ 0, 0, MySurface->w / SpriteSizeX, MySurface->h / SpriteSizeY },
			//new SDL_Rect{ X * Size, Y * Size, Size, Size });
	__super::Render();

	int SpriteWidth = MySurface->w / SpriteSizeX;
	int SpriteHeight = MySurface->h / SpriteSizeY;
	int StartX = SpriteIndex * SpriteWidth;
	int StartY = SpriteDirection * SpriteHeight;

	SDL_RenderCopy(GEngine->MyRenderer,
		MyTexture,
		//nullptr
		new SDL_Rect{ StartX, StartY,SpriteWidth,SpriteHeight },
		new SDL_Rect{ X * Size, Y * Size, Size, Size });

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