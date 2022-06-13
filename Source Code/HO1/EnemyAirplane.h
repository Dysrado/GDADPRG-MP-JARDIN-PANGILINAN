#pragma once
#include "AGameObject.h"
#include "ObjectPooling/APoolable.h"

class EnemyAirplane : public APoolable
{
public:
	EnemyAirplane(std::string name);
	~EnemyAirplane();
	void initialize();

	void onRelease();
	void onActivate();
	APoolable* clone();

private:
	sf::Sprite* sprite = new sf::Sprite();
	const int SPAWN_RANGE = 300;
	int counter = 0;

};

