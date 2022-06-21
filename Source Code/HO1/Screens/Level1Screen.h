#pragma once
#include "../AGameObject.h"
#include "../Managers/GameObjectManager.h"
#include "../Components/EnemySwarmHandler.h"
#include "../UI/HUD.h"
#include "../EmptyGameObject.h"
#include "../AirplaneSupport.h"
#include "../AirplanePlayer.h"
#include "../BGObject.h"
class Level1Screen : public AGameObject
{
public:
	Level1Screen(std::string name);
	~Level1Screen();

	void initialize();
	void levelClear();

private:
	BGObject* bgObject;

	AirplanePlayer* planeObject;

	HUD* hud;

	EmptyGameObject* enemiesManager;

};

