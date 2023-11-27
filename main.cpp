#include "SimpleEngin.h"

int main()
{
	SimpleEngin* MyEngine = SimpleEngin::GetInstance();


	MyEngine->LoadLevel("a.smap");
	MyEngine->Run();

	delete MyEngine;

	return 0;
}