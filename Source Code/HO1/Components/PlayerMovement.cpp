#include "PlayerMovement.h"
#include "PlayerInputController.h"
#include "../AirplanePlayer.h"
#include <iostream>

PlayerMovement::PlayerMovement(std::string name) : AComponent(name, Script){

}


void PlayerMovement::perform() {
	AirplanePlayer* airplanePlayer = (AirplanePlayer*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)airplanePlayer->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* playerTransform = airplanePlayer->getTransformable();
	
	if (playerTransform == NULL || inputController == NULL) {
		std::cout << "playerTransformable not found" << std::endl;
	}

	/*sf::Vector2f offset(0.f, 0.f);
	if (inputController->isUp()) {
		offset.y -= this->SPEED_MULTIPLIER;
		playerTransform->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isDown()) {
		offset.y += this->SPEED_MULTIPLIER;
		playerTransform->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isLeft()) {
		offset.x -= this->SPEED_MULTIPLIER;
		playerTransform->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isRight()) {
		offset.x += this->SPEED_MULTIPLIER;
		playerTransform->move(offset * deltaTime.asSeconds());
	}*/

}
