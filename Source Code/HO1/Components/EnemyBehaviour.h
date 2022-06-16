#pragma once
#include "AComponent.h"


class EnemyBehaviour : public AComponent
{
public:
	//enum EnemMovementType {Delay = 0, Forward = 1, SlowForward = 2, Side = 3};

	EnemyBehaviour(std::string name);
	void perform();
	void configure(float delay);
	void reset();

private:
	const float SPEED_MULTIPLIER = 150.f;
	//float ticks = 0.f;
	//EnemMovementType movementType = Forward;
	/*float delay = 0.f;
	float forwardDuration = 0.f;*/
};

