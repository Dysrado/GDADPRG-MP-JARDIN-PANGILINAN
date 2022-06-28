#pragma once
#include "AComponent.h"


class EnemyBehaviour : public AComponent
{
public:
	

	EnemyBehaviour(std::string name);
	void perform();
	void configure(float delay);
	void reset();

private:
	const float SPEED_MULTIPLIER = 150.f;
	bool isStatic = false;
	
};

