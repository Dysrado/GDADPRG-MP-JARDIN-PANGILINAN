#pragma once
#include "../AGameObject.h"
#include "../Managers/GameObjectManager.h"
#include "../Components/EnemySwarmHandler.h"
#include "../UI/HUD.h"
#include "../EmptyGameObject.h"
#include "../AirplanePlayer.h"
#include "../BGObject.h"
#include "../Managers/AudioManager.h"

class Level2Screen : public AGameObject
{
public:
	Level2Screen(std::string name);
	~Level2Screen();

	void initialize();

private:
	BGObject* bgObject;

	AirplanePlayer* planeObject;

	HUD* hud;

	EmptyGameObject* enemiesManager;
	EmptyGameObject* physicsManager;
	sf::Music music;
};

