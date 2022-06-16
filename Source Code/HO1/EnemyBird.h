#pragma once
#include "AGameObject.h"
#include "ObjectPooling/APoolable.h"
class EnemyBird : public APoolable
{
public:
	EnemyBird(std::string name);
	~EnemyBird();
	void initialize();

	void onRelease();
	void onActivate();
	APoolable* clone();

	void update(sf::Time deltaTime);

private:
	sf::Sprite* sprite = new sf::Sprite();
	//const int SPAWN_RANGE = 300;
	int LOCATION = 225;
	int counter = 0;
	std::vector<sf::IntRect> frames;
	int frameCtr = 0; // index for the frame lise
	sf::Clock animClock; // clock time for the animation
};

