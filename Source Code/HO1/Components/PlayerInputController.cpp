#include "PlayerInputController.h"
#include "../Managers/ApplicationManager.h"
PlayerInputController::PlayerInputController(std::string name, float displacement) : GenericInputController(name) {
	this->displacement = displacement;
	
}

PlayerInputController::~PlayerInputController() {
	GenericInputController::~GenericInputController();
}

void PlayerInputController::perform() {
	bool keyFlag = false;
	if (event.type == sf::Event::KeyPressed) {
		keyFlag = true;
	}
	else if (event.type == sf::Event::KeyReleased) {
		keyFlag = false;
	}
	
	switch (event.key.code) {
	// up movement
	case sf::Keyboard::Space: 
		this->moveUp = keyFlag;

			
		break;

	// down
	case sf::Keyboard::S:
		this->moveDown = keyFlag;
		break;

	// left
	case sf::Keyboard::A:
		this->moveLeft = keyFlag;
		break;
	// right
	case sf::Keyboard::D:
		this->moveRight = keyFlag;
		break;


	}
}

bool PlayerInputController::isUp()
{
	return this->moveUp;
}

bool PlayerInputController::isDown()
{
	return this->moveDown;
}

bool PlayerInputController::isLeft()
{
	return this->moveLeft;
}

bool PlayerInputController::isRight()
{
	return this->moveRight;
}
