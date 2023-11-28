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
	Init();
}

SimpleEngin::~SimpleEngin()
{

	Term();
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
		Input(); ///Input
		Tick(); //Tick
		//Clear Screen
		system("Cls");
		Render(); //Render
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
		while (getline(file, line))///getline 한줄 읽어라
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
	KeyCode = _getch();
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
