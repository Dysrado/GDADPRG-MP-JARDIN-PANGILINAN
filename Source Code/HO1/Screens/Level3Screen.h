#pragma once
#include "../AGameObject.h"
#include "../Managers/GameObjectManager.h"
#include "../Components/EnemySwarmHandler.h"
#include "../UI/HUD.h"
#include "../EmptyGameObject.h"
#include "../DinoPlayer.h"
#include "../BGObject.h"
#include "../Managers/AudioManager.h"

class Level3Screen : public AGameObject
{
public:
	Level3Screen(std::string name);
	~Level3Screen();

	void initialize();

private:
	BGObject* bgObject;

	DinoPlayer* planeObject;

	HUD* hud;

	EmptyGameObject* enemiesManager;
	EmptyGameObject* physicsManager;
	sf::Music music;
};

