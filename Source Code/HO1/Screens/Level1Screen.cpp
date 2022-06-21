#include "Level1Screen.h"

Level1Screen::Level1Screen(std::string name) : AGameObject(name)
{
}

Level1Screen::~Level1Screen()
{
	AGameObject::~AGameObject();
}

void Level1Screen::initialize()
{
	bgObject = new BGObject("BGObject");
	GameObjectManager::getInstance()->addObject(bgObject);

	planeObject = new AirplanePlayer("PlaneObject");
	GameObjectManager::getInstance()->addObject(planeObject);


	srand(time(NULL)); // controls randomness of the enemy spawns
	enemiesManager = new EmptyGameObject("EnemiesManager");
	EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(5, "SwarmHandler", enemiesManager, 1);
	// last parameter for the EnemySwarmHandler is for the enemy type from range of 1 - 3
	enemiesManager->attachComponent(swarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);
	hud = new HUD("HUD");
	GameObjectManager::getInstance()->addObject(hud);
	
	
}

void Level1Screen::levelClear()
{

}
