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

private:
	sf::Sprite* sprite = new sf::Sprite();
	//const int SPAWN_RANGE = 300;
	const int LOCATION = 225;
	int counter = 0;

};

