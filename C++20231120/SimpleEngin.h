#pragma once
#include "World.h"
#include <string>

class UWorld;
class AActor;
class AGameState;
class AGameMode;

class SimpleEngin
{
private:
	SimpleEngin();

public:
	
	virtual ~SimpleEngin();

	 void Init();

	 void Run();

	 void Stop();

	 void Term();//// ÃÊ±âÈ­

	 void LoadLevel(std::string Filename);

	 inline UWorld* GetWorld() const{ return World; };

	 static SimpleEngin* GetInstance()
	 {
		 if (Instance == nullptr)
		 {
			 Instance = new SimpleEngin();
		 }
		 return Instance;
	 }

	 static int KeyCode;

	 static AGameState* GetGameState()
	 {
		 return GetInstance()->GameState;
	 }

	 static AGameMode* GetGameMode()
	 {
		 return GetInstance()->GameMode;

	 }

protected:
	 UWorld* World;
	 bool IsRunning;

	 void Input();
	 void Tick();
	 void Render();

	 static SimpleEngin* Instance;

	 class AGameMode* GameMode;
	 class AGameState* GameState;

	 void LoadActor(int NewX, int NewY, char Actor);
};
#define GEngine SimpleEngin::GetInstance()


