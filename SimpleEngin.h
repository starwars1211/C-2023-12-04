#pragma once
#include "World.h"
#include <string>

class UWorld;
class AActor;

class SimpleEngin
{
	SimpleEngin();

public:
	
	virtual ~SimpleEngin();

	 void Init();

	 void Run();

	 void Stop();

	 void Term();

	 void LoadLevel(std::string Filename );

	 inline UWorld* GetWorld() const{ return World; };

	 static const SimpleEngin* GetInstance()
	 {
		 if (Instance == nullptr)
		 {
			 Instance = new SimpleEngin();
		 }
		 return Instance;
	 }



protected:
	 UWorld* World;
	 bool IsRunning;

	 int Input();
	 void Tick(int KeyCode);
	 void Render();

	 static SimpleEngin* Instance;

};
#define GEngine SimpleEngin::GetInstance()


