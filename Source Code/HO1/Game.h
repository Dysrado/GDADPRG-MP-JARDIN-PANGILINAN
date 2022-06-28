#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <vector>
#include "TextureManager.h"
#include "Managers/GameObjectManager.h"
#include "Managers/AudioManager.h"
#include "BGObject.h"
#include "AirplanePlayer.h"

class Game
{
public:
	Game();
	void Run();
	float PlayerSpeed = 300.0f;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	static const int WINDOW_WIDTH = 1024;
	static const int WINDOW_HEIGHT = 768;

private:
	void ProcessEvents();
	void Update(sf::Time);
	void Render();

	//void createEntity(std::string key, float x, float y);

	sf::RenderWindow myWindow;

};

