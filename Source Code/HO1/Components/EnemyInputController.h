#pragma once
#include "GenericInputController.h"

class EnemyInputController :
    public GenericInputController
{

public:
    EnemyInputController(std::string name);
    ~EnemyInputController();

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
};


