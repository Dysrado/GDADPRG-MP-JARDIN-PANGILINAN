#pragma once
#include "AComponent.h"
class PlayerMovement :
    public AComponent
{
public:
    PlayerMovement(std::string name);
    void perform();

private:
    const float SPEED_MULTIPLIER = 300.f;
};

