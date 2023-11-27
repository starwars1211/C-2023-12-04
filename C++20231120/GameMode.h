#pragma once
#include "Actor.h"
class AGameMode :
    public AActor
{
public:
    AGameMode();
   virtual ~AGameMode();

   virtual    void Tick();
   virtual     void Render() override{}
};

