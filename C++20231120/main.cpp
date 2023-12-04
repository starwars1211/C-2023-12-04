#include "SimpleEngin.h"
#include <iostream>
#include <fstream>

using namespace std;

int SDL_main(int argc, char* argv[])
{
	SimpleEngin* MyEngine = SimpleEngin::GetInstance();

	MyEngine->LoadLevel("Data/level01.smap");
	MyEngine->Run();

	delete MyEngine;
    
    /*
    string line;
    ifstream file("level01.smap");
    if (file.is_open())
    {
        while (getline(file, line))///getline 한줄 읽어라
        {
            cout << line << endl;
        }
        file.close();
    }
    */

	return 0;
}