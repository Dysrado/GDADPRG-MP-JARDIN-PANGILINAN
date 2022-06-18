#pragma once
#include "GenericInputController.h"

class PlayerInputController :
    public GenericInputController
{

public:
    PlayerInputController(std::string name, float ground);
    ~PlayerInputController();

    void perform();
    bool isUp();
    bool isDown();
    bool isLeft();
    bool isRight();

private:
    const float SPEED_MULTIPLIER = 300.f;
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    float floor;
    sf::Clock clock1;
    sf::Time elapse;
};

