#pragma once
#include "AGameObject.h"
#include "ObjectPooling/APoolable.h"
#include "Physics/CollisionListener.h"
#include "Physics/Collider.h"


class EnemyCactus : public APoolable, public CollisionListener
{
public:
	EnemyCactus(std::string name);
	~EnemyCactus();
	void initialize();

	void onRelease();
	void onActivate();
	APoolable* clone();
	void onCollisionEnter(AGameObject* contact);
	void onCollisionExit(AGameObject* contact);
	
private:
	sf::Sprite* sprite = new sf::Sprite();
	const int LOCATION = 200;
	int counter = 0;
	Collider* collider;
	

};

