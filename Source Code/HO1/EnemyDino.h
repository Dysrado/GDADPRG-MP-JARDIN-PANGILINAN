#pragma once
#include "AGameObject.h"
#include "ObjectPooling/APoolable.h"
class EnemyDino : public APoolable
{
public:
	EnemyDino(std::string name);
	~EnemyDino();
	void initialize();

	void onRelease();
	void onActivate();
	APoolable* clone();

	void update(sf::Time deltaTime);

private:
	sf::Sprite* sprite = new sf::Sprite();
	//const int SPAWN_RANGE = 300;
	const int LOCATION = 225;
	int counter = 0;
	std::vector<sf::IntRect> frames;
	int frameCtr = 0; // index for the frame lise
	sf::Clock animClock; // clock time for the animation
};

