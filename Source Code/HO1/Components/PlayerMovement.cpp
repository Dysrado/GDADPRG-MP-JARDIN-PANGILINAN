#include "PlayerMovement.h"
#include "PlayerInputController.h"
#include "../AirplanePlayer.h"
#include <iostream>
#include "../Game.h"

PlayerMovement::PlayerMovement(std::string name) : AComponent(name, Script){
	//elapsed = sf::seconds(2.0f);
	soundBuffer = AudioManager::getInstance()->getBuffer("jump");
	sound.setBuffer(*soundBuffer);
}


void PlayerMovement::perform() {
	elapsed = clock.getElapsedTime();
	AirplanePlayer* airplanePlayer = (AirplanePlayer*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)airplanePlayer->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* playerTransform = airplanePlayer->getTransformable();
	
	if (playerTransform == NULL || inputController == NULL) {
		std::cout << "playerTransformable not found" << std::endl;
	}

	sf::Vector2f offset(0.f, 0.f);
	if (inputController->isUp() && playerTransform->getPosition().y == (Game::WINDOW_HEIGHT / 2) + 150.f) {
		clock.restart();
		jump = true;
		sound.play();

	}
	if (elapsed.asSeconds() < 1.0f && jump == true ) {
		offset.y -= this->SPEED_MULTIPLIER;
		playerTransform->move(offset * deltaTime.asSeconds());
	}
	if (elapsed.asSeconds() > 1.0f && jump == true){
		
		elapsed = clock.getElapsedTime();
	}

	if (/*jump == false &&*/ playerTransform->getPosition().y != (Game::WINDOW_HEIGHT / 2) + 150.f) {
		offset.y += this->SPEED_MULTIPLIER;
		playerTransform->move(offset * deltaTime.asSeconds());
		
	}
	/*if (playerTransform->getPosition().y == (Game::WINDOW_HEIGHT / 2) + 150.f) {
		jump = false;
	}*/
	/*
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
