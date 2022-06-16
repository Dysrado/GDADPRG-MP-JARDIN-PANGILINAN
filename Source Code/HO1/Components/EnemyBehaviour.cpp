#include "EnemyBehaviour.h"
#include "../Game.h"
#include "../EnemyAirplane.h"

EnemyBehaviour::EnemyBehaviour(std::string name) : AComponent(name, Script) {
	this->reset();
}

void EnemyBehaviour::perform() {
	//ticks += this->deltaTime.asSeconds();
	sf::Transformable* transformable = this->getOwner()->getTransformable();
	PlayerInputController* inputController = (PlayerInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];

	// Force Moves it to the left
	if (isStatic == 0) {
		transformable->move(-this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
	}

	if (inputController->isLeft()) {
		transformable->move(this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
	}
	else if (inputController->isRight()) {
		transformable->move(-this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
	}
	
	/*if (this->ticks > this->forwardDuration && this->movementType != Side) {
		int counter = (this->movementType + 1) % EnemMovementType::Side + 1;
		this->movementType = (EnemMovementType)counter;
	}*/

	/*if (this->movementType == Forward) {
		transformable->move(0, this->deltaTime.asSeconds() * SPEED_MULTIPLIER);
	}
	else if (this->movementType == SlowForward) {
		transformable->move(0, this->deltaTime.asSeconds() * (SPEED_MULTIPLIER / 2.f));
	}
	else if (this->movementType == Side) {
		if (transformable->getPosition().x > Game::WINDOW_WIDTH / 2) {
			transformable->move(this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
		}
		else {
			transformable->move(-this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
		}
	}*/
	
}


void EnemyBehaviour::configure(float delay) {
	/*this->delay = delay;*/
	//this->ticks = 0.0f;
	if (delay == 1) {
		isStatic = true;
	}
	else {
		isStatic = false;
	}
}

void EnemyBehaviour::reset() {
	/*this->movementType = Forward;
	this->forwardDuration = (rand() % 3) + 1.f;*/
	//this->ticks = 0.0f;
}


