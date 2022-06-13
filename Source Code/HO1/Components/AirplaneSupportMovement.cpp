#include "AirplaneSupportMovement.h"
#include "../AirplaneSupport.h"

AirplaneSupportMovement::AirplaneSupportMovement(std::string name) : AComponent(name, Script)
{
}

void AirplaneSupportMovement::perform()
{
	AirplaneSupport* airplaneSupport = (AirplaneSupport*)this->getOwner();
	sf::Transformable* supportTransform = airplaneSupport->getTransformable();

	sf::Vector2f pos = supportTransform->getPosition();

	if (pos.x >= 50.f) {
		isLeft	= true;
		isRight = false;
	}
	else if (pos.x <= -50.f) {
		isLeft	= false;
		isRight = true;
	}

	if (isLeft) {
		supportTransform->move(-1 * SPEED_MULTIPLIER * deltaTime.asSeconds(), 0.f);
	}
	else if (isRight) {
		supportTransform->move(1 * SPEED_MULTIPLIER * deltaTime.asSeconds(), 0.f);
	}
}
