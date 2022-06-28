#pragma once
#include "AGameObject.h"

class GoalPoint : public AGameObject
{
public:
	GoalPoint(std::string name);
	void initialize();

private:
	sf::Sprite* sprite;

};

