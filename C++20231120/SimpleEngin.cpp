#include "SimpleEngin.h"
#include "World.h"
#include <conio.h>
#include "Player.h"
#include "Map.h"
#include "Monster.h"
#include "Floar.h"
#include "Goal.h"
#include "GameMode.h"
#include "GameState.h"
#include <iostream>
#include <fstream>


SimpleEngin* SimpleEngin::Instance = nullptr;
int SimpleEngin::KeyCode = 0;

SimpleEngin::SimpleEngin()
{
	GameMode = nullptr;
	GameState = nullptr;
	SDL_Init(SDL_INIT_EVERYTHING);
	MyWindow = SDL_CreateWindow("HelloWorld", 100, 100, 1000, 800, SDL_WINDOW_OPENGL); // â ����� ��
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED); // �� ����� �� (������â, ù��°, ����)

	Init();
}

SimpleEngin::~SimpleEngin()
{
	Term();

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
}

void SimpleEngin::Init()
{
	IsRunning = true;
	World = new UWorld();
}

void SimpleEngin::Run()
{
	while (IsRunning)
	{
		DeltaSeconds = SDL_GetTicks64() - LastTime;// �ʱ� �ð����� ������ �ð��� ����
		LastTime = SDL_GetTicks64();

		Input();

		switch (MyEvent.type) //// tick
		{
		case SDL_QUIT:
			IsRunning = false;
			break;
		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE) // Ű���� ���� ���ؼ� 
			{
				IsRunning = false;
			}
			break;
		}
		//Input(); ///Input
		Tick(); //Tick
		//Clear Screen
		//system("cls");
		SDL_SetRenderDrawColor(GEngine->MyRenderer, 0, 0, 0, 0);
		SDL_RenderClear(GEngine->MyRenderer);
		
		Render(); //Render

		SDL_RenderPresent(GEngine->MyRenderer);//�׷���
	}
}

void SimpleEngin::Stop()
{
	IsRunning = false;
}

void SimpleEngin::Term()
{
	GameMode = nullptr;
	GameState = nullptr;
	IsRunning = false;
	delete  World;
}

void SimpleEngin::LoadLevel(std::string Filename)
{
	Term();
	Init();
	//Save
	//Memory -> Disk L Ssrialize , Text(JSON, csv), binary(umap)
	//Disk -> Memory : Deserialize
	/*
	std::string Map[10] = {
		"**********",
		"*      P *",
		"*        *",
		"*        *",
		"*       M*",
		"*        *",
		"*        *",
		"*        *",
		"*       G*",
		"**********",
	};
	*/

	int Y = 0;
	std::string line;
    std::ifstream file(Filename);
	if (file.is_open())
	{
		while (getline(file, line))///getline ���� �о��
		{
			for (int X = 0; X < line.length(); ++X)
			{
				LoadActor(X, Y, line[X]);
			}
			Y++;
		}
		file.close();
	}
	else
	{
		Stop();
	}

	GetWorld()->SortRenderOrder();

	GameMode = new AGameMode();
	GetWorld()->SpawnActor(GameMode);
	GameState = new AGameState();
	GetWorld()->SpawnActor(GameState);
	
}

void SimpleEngin::Input()
{
	//KeyCode = MyEvent.key.keysym.sym;
	SDL_PollEvent(&MyEvent);
}

void SimpleEngin::Tick()
{
	GetWorld()->Tick();
}

void SimpleEngin::Render()
{
	GetWorld()->Render();
}

void SimpleEngin::LoadActor(int NewX, int NewY, char Actor)
{
	if (Actor == '*')
	{
		//Wall=AMap
		GetWorld()->SpawnActor(new AMap(NewX, NewY));
	}

	else if (Actor == 'P')
	{
		//Player
		GetWorld()->SpawnActor(new APlayer(NewX, NewY));
	}

	else if (Actor == 'M')
	{
		//Monster
		GetWorld()->SpawnActor(new AMonster(NewX, NewY));
	}
	else if (Actor == 'G')
	{
		//Goal
		GetWorld()->SpawnActor(new AGoal(NewX, NewY));
	}

	else if (Actor == ' ')
	{
		//Floar
		//GetWorld()->SpawnActor(new AFloar(X, Y));
	}
	//Floor
	GetWorld()->SpawnActor(new AFloar(NewX, NewY));

}
