#pragma once
#include "World.h"
#include <string>

class UWorld;
class AActor;

class SimpleEngin
{
private:
	SimpleEngin();

public:
	
	virtual ~SimpleEngin();

	 void Init();

	 void Run();

	 void Stop();

	 void Term();

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

protected:
	 UWorld* World;
	 bool IsRunning;

	 void Input();
	 void Tick();
	 void Render();

	 static SimpleEngin* Instance;

};
#define GEngine SimpleEngin::GetInstance()


