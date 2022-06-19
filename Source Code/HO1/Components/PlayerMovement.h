#pragma once
#include "AComponent.h"
#include "../Managers/AudioManager.h"
class PlayerMovement :
    public AComponent
{
public:
    PlayerMovement(std::string name);
    void perform();

private:
    const float SPEED_MULTIPLIER = 300.f;
    sf::Clock clock;
    sf::Time elapsed;
    bool jump = false;

    sf::SoundBuffer* soundBuffer;
    sf::Sound sound;
};

