#pragma once
#include "AGameObject.h"
#include "ObjectPooling/APoolable.h"
#include "Physics/CollisionListener.h"
#include "Physics//Collider.h"

class EnemyBird : public APoolable, public CollisionListener
{
public:
	EnemyBird(std::string name);
	~EnemyBird();
	void initialize();

	void onRelease();
	void onActivate();
	APoolable* clone();

	void update(sf::Time deltaTime);
	void onCollisionEnter(AGameObject* contact);
	void onCollisionExit(AGameObject* contact);
private:
	sf::Sprite* sprite = new sf::Sprite();
	int LOCATION = 225;
	int counter = 0;
	std::vector<sf::IntRect> frames;
	int frameCtr = 0; // index for the frame lise
	sf::Clock animClock; // clock time for the animation
	Collider* collider;
};

