#pragma once
#include "AComponent.h"
#include <SFML/Window.hpp>
class GenericInputController :
    public AComponent
{
public:
    GenericInputController(std::string);
    ~GenericInputController();

    void perform();
    void assignEvent(sf::Event event);

protected:
    sf::Event event;


};

