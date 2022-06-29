#pragma once
#include "../AGameObject.h"
#include "../Managers/GameObjectManager.h"
#include "../Components/EnemySwarmHandler.h"
#include "../UI/HUD.h"
#include "../EmptyGameObject.h"
#include "../DinoPlayer.h"
#include "../BGObject.h"
#include "../Managers/AudioManager.h"


class Level1Screen : public AGameObject
{
public:
	Level1Screen(std::string name);
	~Level1Screen();

	void initialize();
	void levelClear();

private:
	BGObject* bgObject;

	DinoPlayer* planeObject;

	HUD* hud;

	EmptyGameObject* enemiesManager;
	EmptyGameObject* physicsManager;
	sf::Music music;
};

