#pragma once
#include "AComponent.h"
#include "../Game.h"

class BGMovement :
    public AComponent
{
public:
    BGMovement(std::string name);
    bool goalPoint();
    void perform();
    float getDisplacement();
    bool levelCleared;

private:
    const float SPEED_MULTIPLIER = 100.f;
    float displacement;
    const float GOAL_POINT = 60.f;
};

