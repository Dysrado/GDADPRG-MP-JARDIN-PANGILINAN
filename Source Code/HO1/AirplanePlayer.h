#pragma once
#include "AGameObject.h"
#include "Components/PlayerInputController.h"
#include "Physics/Collider.h"
#include "Physics/PhysicsManager.h"
#include "Game.h"

class AirplanePlayer : public AGameObject, public CollisionListener
{
public:
	AirplanePlayer(std::string name);
	void initialize();

	void update(sf::Time deltaTime);
	void onCollisionEnter(AGameObject* contact);
	void onCollisionExit(AGameObject* contact);
	Collider* collider;

private:
	sf::Sprite* sprite = new sf::Sprite();
	
	std::vector<sf::IntRect> frames;
	int frameCtr = 0; // index for the frame lise
	sf::Clock animClock; // clock time for the animation
	float displacement = 0.f;
	PlayerInputController* inputController;
	bool isCollided = false;
	sf::SoundBuffer* soundBuffer;
	sf::Sound sound;
	
};

