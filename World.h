#pragma once
#include <vector>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void SpawnActor(AActor* NewActor);

	void Tick(int KeyCode);
	void Render();

	void SortRenderOrder();

	const std::vector<AActor*>& GetallActors()
	{
		return Actors;
	}
protected:

	std::vector<AActor*> Actors;
};
