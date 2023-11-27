#include "GameMode.h"
#include "Player.h"
#include "Goal.h"
#include "SimpleEngin.h"
#include "World.h"
#include <iostream>
#include "GameState.h"

AGameMode::AGameMode()
{
	SortOrder = 0;
	SortOrder = 1000;
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick() //Server
{
	AActor::Tick();

	if (SimpleEngin::GetGameState()->IsNextLevel)
	{
		std::cout << "Complete" << std::endl;
		GEngine->Stop();
	}

	if (SimpleEngin::GetGameState()->IsGameOver)
	{
		std::cout << "GameOver" << std::endl;
		GEngine->Stop();
	}

}