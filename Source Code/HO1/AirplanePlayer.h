#pragma once
#include "AGameObject.h"

class AirplanePlayer : public AGameObject
{
public:
	AirplanePlayer(std::string name);
	void initialize();

	void update(sf::Time deltaTime);

private:
	sf::Sprite* sprite = new sf::Sprite();
	std::vector<sf::IntRect> frames;
	int frameCtr = 0; // index for the frame lise
	sf::Clock animClock; // clock time for the animation
	

};

