#include "Level1Screen.h"
#include "../Physics/PhysicsManager.h"
#include "../Managers/ApplicationManager.h"

Level1Screen::Level1Screen(std::string name) : AGameObject(name)
{
}

Level1Screen::~Level1Screen()
{
	AGameObject::~AGameObject();
}

void Level1Screen::initialize()
{
	physicsManager = new EmptyGameObject("PhysicsManager");
	GameObjectManager::getInstance()->addObject(physicsManager);
	PhysicsManager::initialize("PhysicsManager", physicsManager);
	
	bgObject = new BGObject("BGObject");
	GameObjectManager::getInstance()->addObject(bgObject);

	planeObject = new DinoPlayer("PlaneObject");
	GameObjectManager::getInstance()->addObject(planeObject);

	srand(time(NULL)); // controls randomness of the enemy spawns
	enemiesManager = new EmptyGameObject("EnemiesManager");
	EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(5, "SwarmHandler", enemiesManager, 1);
	// last parameter for the EnemySwarmHandler is for the enemy type from range of 1 - 3
	enemiesManager->attachComponent(swarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);
	hud = new HUD("HUD");
	GameObjectManager::getInstance()->addObject(hud);
	
	ApplicationManager::getInstance()->resumeApplication();

	if (music.openFromFile("Media/Audio/BGM1.ogg"))
		music.setVolume(5.f);
	music.play();
	music.setLoop(true);

	
}

void Level1Screen::levelClear()
{
	
}
