#pragma once
#include "AComponent.h"
#include "../Game.h"

class BGMovement :
    public AComponent
{
public:
    BGMovement(std::string name);
    void perform();
    float getDisplacement();

private:
    const float SPEED_MULTIPLIER = 100.f;
    float displacement;
};

