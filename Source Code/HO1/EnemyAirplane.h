#pragma once
#include "AGameObject.h"
#include "ObjectPooling/APoolable.h"
#include "Physics/CollisionListener.h"
#include "Physics/Collider.h"


class EnemyAirplane : public APoolable, public CollisionListener
{
public:
	EnemyAirplane(std::string name);
	~EnemyAirplane();
	void initialize();

	void onRelease();
	void onActivate();
	APoolable* clone();
	void onCollisionEnter(AGameObject* contact);
	void onCollisionExit(AGameObject* contact);
	
private:
	sf::Sprite* sprite = new sf::Sprite();
	//const int SPAWN_RANGE = 300;
	const int LOCATION = 200;
	int counter = 0;
	Collider* collider;
	

};

