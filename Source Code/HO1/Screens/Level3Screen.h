#pragma once
#include "../AGameObject.h"
#include "../Managers/GameObjectManager.h"
#include "../Components/EnemySwarmHandler.h"
#include "../UI/HUD.h"
#include "../EmptyGameObject.h"
#include "../AirplaneSupport.h"
#include "../AirplanePlayer.h"
#include "../BGObject.h"
class Level3Screen : public AGameObject
{
public:
	Level3Screen(std::string name);
	~Level3Screen();

	void initialize();

private:
	BGObject* bgObject;

	AirplanePlayer* planeObject;

	HUD* hud;

	EmptyGameObject* enemiesManager;
};

