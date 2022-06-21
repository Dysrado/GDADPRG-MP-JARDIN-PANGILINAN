#pragma once
#include "../Components/AComponent.h"
#include "CollisionListener.h"
#include "../AGameObject.h"
class Collider : public AComponent
{
public:
	void setAlreadyCollided(bool flag);

	Collider(std::string name);
	void setCollisionListener(CollisionListener* listener);
	void setChecked(bool flag);
	bool isChecked();

	bool willCollide(Collider* another);
	bool alreadyCollided();
	
	sf::FloatRect getGlobalBounds();
	void setLocalBounds(sf::FloatRect localBounds);
	void collisionEnter(AGameObject* gameObjects);
	void collisionExit(AGameObject* gameObjects);
	void perform();

private:
	bool collided = false;
	bool checked = false;
	sf::FloatRect localBounds;
	CollisionListener* listener;
};

