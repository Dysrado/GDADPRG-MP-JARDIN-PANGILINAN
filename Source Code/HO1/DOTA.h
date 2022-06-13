#pragma once
#include "AGameObject.h"
#include "Components/PlayerInputController.h"
class DOTA : public AGameObject
{
public:
	DOTA(std::string name);
	void initialize();

	void update();

private:
	std::vector<sf::IntRect> frameList;
	int offset = 0;
	int index = 0;
	sf::Clock cooldownClock;
	PlayerInputController* inputController;
};

