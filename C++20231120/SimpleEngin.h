#pragma once
#include "World.h"
#include <string>
#include "SDL.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")


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

	 static SDL_Keycode KeyCode;

	 static AGameState* GetGameState()
	 {
		 return GetInstance()->GameState;
	 }

	 static AGameMode* GetGameMode()
	 {
		 return GetInstance()->GameMode;

	 }

	 static Uint64 GetWorldDeltaSeconds()
	 {
		 return GetInstance()->DeltaSeconds;
	 }

	 SDL_Window* MyWindow;
	 SDL_Renderer* MyRenderer;
	 SDL_Event MyEvent;
	 Uint64 DeltaSeconds;
	 Uint64 LastTime;
	 

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


