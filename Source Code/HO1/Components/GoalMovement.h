#pragma once
#include "AComponent.h"
#include "../Game.h"
class GoalMovement : public AComponent
{
public:
    GoalMovement(std::string name);
    void perform();

private:
    const float SPEED_MULTIPLIER = 100.f;
    float displacement;
};

