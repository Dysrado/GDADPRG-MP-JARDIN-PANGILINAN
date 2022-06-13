#include "BGMovement.h"

BGMovement::BGMovement(std::string name) : AComponent(name, Script)
{
}

void BGMovement::perform()
{
	BGObject* bgObject = (BGObject*)this->getOwner();
	sf::Transformable* bgObjectTransform = bgObject->getTransformable();

	if (bgObjectTransform == NULL) {
		std::cout << "bgObjectTransform not found" << std::endl;
	}
	else {
		sf::Vector2f offset(0.f, 0.f);

		offset.y += SPEED_MULTIPLIER;
		bgObjectTransform->move(offset * deltaTime.asSeconds());

		sf::Vector2f localPos = bgObjectTransform->getPosition();
		if (localPos.y >= Game::WINDOW_HEIGHT * 7) {
			bgObjectTransform->setPosition(0, Game::WINDOW_HEIGHT);
		}
	}
}
