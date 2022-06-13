#pragma once
#include "AGameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class BGObject : public AGameObject
{
public:
	BGObject(std::string name);
	void initialize();

};

