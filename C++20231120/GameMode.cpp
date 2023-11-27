#include "GameMode.h"
#include "Player.h"
#include "Goal.h"
#include "SimpleEngin.h"
#include "World.h"
#include <iostream>

AGameMode::AGameMode()
{
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick() /// Server
{
	AActor::Tick();
	static APlayer* MyPlayer = nullptr;
	static AGoal* MyGoal = nullptr;
	if (!MyGoal || !MyPlayer)
		for (auto Actor : GEngine->GetWorld()->GetAllActors())
		{
			APlayer* TempMyPlayer = dynamic_cast<APlayer*>(Actor);
			if (TempMyPlayer)
			{
				MyPlayer = TempMyPlayer;
			}
			AGoal* TempMyGoal = dynamic_cast<AGoal*>(Actor);
			if (TempMyGoal)
			{
				MyGoal = TempMyGoal;
			}
		};
	if (MyPlayer && MyGoal &&
		MyGoal->GetX() == MyPlayer->GetX() &&
		MyGoal->GetY() == MyPlayer->GetY())
	{
		std::cout << "Complete" << std::endl;
		GEngine->Stop();
	};
}
