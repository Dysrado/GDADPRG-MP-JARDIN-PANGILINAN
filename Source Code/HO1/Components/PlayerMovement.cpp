#include "PlayerMovement.h"
#include "PlayerInputController.h"
#include "../DinoPlayer.h"
#include <iostream>
#include "../Game.h"

PlayerMovement::PlayerMovement(std::string name) : AComponent(name, Script){
	//sets sound buffers
	soundBuffer = AudioManager::getInstance()->getBuffer("jump");
	sound.setBuffer(*soundBuffer);
}


void PlayerMovement::perform() {
	elapsed = clock.getElapsedTime();
	DinoPlayer* dinoPlayer = (DinoPlayer*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)dinoPlayer->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* playerTransform = dinoPlayer->getTransformable();
	
	if (playerTransform == NULL || inputController == NULL) {
		std::cout << "playerTransformable not found" << std::endl;
	}

	sf::Vector2f offset(0.f, 0.f);
	//can only jump if the player is on the ground
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
	//moves player back down
	if (playerTransform->getPosition().y != (Game::WINDOW_HEIGHT / 2) + 150.f) {
		offset.y += this->SPEED_MULTIPLIER;
		playerTransform->move(offset * deltaTime.asSeconds());
		
	}

}
