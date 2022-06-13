#pragma once
#include "AComponent.h"


class AirplaneSupportMovement : public AComponent
{
public:
	AirplaneSupportMovement(std::string name);
	void perform();
	bool isLeft = false;
	bool isRight = false;

private:
	const float SPEED_MULTIPLIER = 50.f;
};

