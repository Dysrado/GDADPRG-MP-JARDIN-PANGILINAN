#include "EnemyBehaviour.h"
#include "../Game.h"

EnemyBehaviour::EnemyBehaviour(std::string name) : AComponent(name, Script) {
	this->reset();
}

void EnemyBehaviour::perform() {
	this->ticks += this->deltaTime.asSeconds();
	sf::Transformable* transformable = this->getOwner()->getTransformable();

	if (this->ticks > this->forwardDuration && this->movementType != Side) {
		int counter = (this->movementType + 1) % EnemMovementType::Side + 1;
		this->movementType = (EnemMovementType)counter;
	}

	if (this->movementType == Forward) {
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
	}
}


void EnemyBehaviour::configure(float delay) {
	this->delay = delay;
}

void EnemyBehaviour::reset() {
	this->movementType = Forward;
	this->forwardDuration = (rand() % 3) + 1.f;
	this->ticks = 0.0f;
}


