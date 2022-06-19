#include "BGMovement.h"
#include "PlayerInputController.h"
#include "EnemyInputController.h"

BGMovement::BGMovement(std::string name) : AComponent(name, Script)
{
}

void BGMovement::perform()
{
	BGObject* bgObject = (BGObject*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)bgObject->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* bgObjectTransform = bgObject->getTransformable();
	//displacement = inputController->displacement
	if (bgObjectTransform == NULL) {
		std::cout << "bgObjectTransform not found" << std::endl;
	}
	else {
		sf::Vector2f offset(0.f, 0.f);

		if (inputController->isLeft() && displacement > 0) {
			displacement -= 0.01f;
			offset.x += this->SPEED_MULTIPLIER;
			bgObjectTransform->move(offset * deltaTime.asSeconds());
		}
		else if (inputController->isRight()) {
			displacement += 0.01f;
			offset.x -= this->SPEED_MULTIPLIER;
			bgObjectTransform->move(offset * deltaTime.asSeconds());
		}

		/*sf::Vector2f localPos = bgObjectTransform->getPosition();
		if (localPos.x >= Game::WINDOW_WIDTH) {
			bgObjectTransform->setPosition(0, 0);
		}*/
	}
	if (displacement >= 2.f) {
		std::cout << "YOU WIN!!!\n";
	}
}
