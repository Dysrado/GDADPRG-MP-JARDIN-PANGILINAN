#include "EnemyInputController.h"

#include "../Managers/ApplicationManager.h"
EnemyInputController::EnemyInputController(std::string name) : GenericInputController(name) {

}

EnemyInputController::~EnemyInputController() {
	GenericInputController::~GenericInputController();
}

void EnemyInputController::perform() {
	bool keyFlag = false;
	if (event.type == sf::Event::KeyPressed) {
		keyFlag = true;
	}
	else if (event.type == sf::Event::KeyReleased) {
		keyFlag = false;
	}

	switch (event.key.code) {
		// up movement
	case sf::Keyboard::W:
		this->moveUp = keyFlag;
		break;

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

bool EnemyInputController::isUp()
{
	return this->moveUp;
}

bool EnemyInputController::isDown()
{
	return this->moveDown;
}

bool EnemyInputController::isLeft()
{
	return this->moveLeft;
}

bool EnemyInputController::isRight()
{
	return this->moveRight;
}
