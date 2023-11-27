#include "SimpleEngin.h"
#include "World.h"
#include <conio.h>
#include "Player.h"
#include "Map.h"
#include "Monster.h"
#include "Floar.h"
#include "Goal.h"

SimpleEngin::SimpleEngin()
{
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
		int KeyCode = Input(); //input
		Tick(KeyCode);//Tick
		//Render
		//Clear Screen
		system("Cls");
		Render();
	}
}

void SimpleEngin::Stop()
{
	IsRunning = false;
}

void SimpleEngin::Term()
{
	IsRunning = false;
	delete  World;
}

void SimpleEngin::LoadLevel(std::string Filename)
{
	//Save
	//Memory -> Disk L Ssrialize , Text(JSON, csv), binary(umap)
	//Disk -> Memory : Deserialize

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
	
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			
			if (Map[Y][X] == '*')
			{
				//Wall
				GetWorld()->SpawnActor(new AMap(X, Y));
			}
			
			else if (Map[Y][X] == 'P')
			{
				//Player
				GetWorld()->SpawnActor(new APlayer(X, Y));
			}
			
			else if (Map[Y][X] == 'M')
			{
				//Monster
				GetWorld()->SpawnActor(new AMonster(X, Y));
			}
			else if (Map[Y][X] == 'G')
			{
				//Goal
				GetWorld()->SpawnActor(new AGoal(X, Y));
			}
			
			else if (Map[Y][X] == ' ')
			{
				//Floar
				GetWorld()->SpawnActor(new AFloar(X, Y));
			}
			//Floor
			//GetWorld()->SpawnActor(new AFloar(X, Y));
			
		}

	}
	
}
int SimpleEngin::Input()
{
	int KeyCode = _getch();

	return KeyCode;
}
void SimpleEngin::Tick(int KeyCode)
{
	GetWorld()->Tick(KeyCode);
}
void SimpleEngin::Render()
{
	GetWorld()->Render();
}