#include "EnemySwarmHandler.h"
#include "../ObjectPooling/ObjectPoolHolder.h"
#include "../EnemyAirplane.h"
#include "../EnemyDino.h"
#include "../EnemyBird.h"
#include "../Managers/GameObjectManager.h"
#include "BGMovement.h"
#include <cmath>

EnemySwarmHandler::EnemySwarmHandler(int numEnemies, std::string name, AGameObject* parent, int type) : AComponent(name, Script)
{
	if (type == 3) {
		enemyPool = new GameObjectPool(
			ObjectPoolHolder::ENEMY_POOL_TAG,
			new EnemyBird("EnemyBird"),
			numEnemies,
			parent);
	}
	else if(type == 2){
		enemyPool = new GameObjectPool(
			ObjectPoolHolder::ENEMY_POOL_TAG,
			new EnemyDino("EnemyDino"),
			numEnemies,
			parent);
	}
	else {
		enemyPool = new GameObjectPool(
			ObjectPoolHolder::ENEMY_POOL_TAG,
			new EnemyAirplane("cactus"), 
			numEnemies,
			parent);
	}
	
	enemyPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);
	//enemyPool->requestPoolableBatch(numEnemies);
}

EnemySwarmHandler::~EnemySwarmHandler()
{
	delete this->enemyPool;
};

void EnemySwarmHandler::perform()
{
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	//BGMovement* movement = (BGMovement*)GameObjectManager::getInstance()->findObjectByName("BGObject")->findComponentByName("myBGMovement");
	//float displacement = movement->getDisplacement();
	this->ticks += this->deltaTime.asSeconds();

	if (this->ticks > SPAWN_INTERVAL) {
		this->ticks = 0.0f;
		randomizeInterval();
		enemyPool->requestPoolable();
	}

	/*if (std::remainder(displacement, 0.7) == 0) {
		enemyPool->requestPoolable();
		std::cout << "BOOOOOOOOOOOOOOM" << std::endl;
	}*/
	//std::cout << displacement << std::endl;

}

void EnemySwarmHandler::randomizeInterval()
{
	float random = 1 + rand() % 2;
	SPAWN_INTERVAL = random;
}
