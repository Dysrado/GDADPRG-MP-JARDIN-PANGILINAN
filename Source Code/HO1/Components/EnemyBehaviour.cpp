#include "EnemyBehaviour.h"
#include "../Game.h"
#include "../EnemyCactus.h"
#include "EnemyInputController.h"

EnemyBehaviour::EnemyBehaviour(std::string name) : AComponent(name, Script) {
}

void EnemyBehaviour::perform() {
	sf::Transformable* transformable = this->getOwner()->getTransformable();
	EnemyInputController* inputController = (EnemyInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];

	// Force Moves it to the left
	if (isStatic == 0) {
		transformable->move(-this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
	}

	// Moves the Cactus depending on the players input
	if (inputController->isLeft()) {
		transformable->move(this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
	}
	else if (inputController->isRight()) {
		transformable->move(-this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
	}
	
}


void EnemyBehaviour::configure(float delay) {
	if (delay == 1) { // sets if the object should be forced to move left
		isStatic = true;
	}
	else {
		isStatic = false;
	}
}

void EnemyBehaviour::reset() {

}


