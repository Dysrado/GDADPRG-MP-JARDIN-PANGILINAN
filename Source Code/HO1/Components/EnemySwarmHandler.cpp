#include "EnemySwarmHandler.h"
#include "../ObjectPooling/ObjectPoolHolder.h"
#include "../EnemyCactus.h"
#include "../EnemyDino.h"
#include "../EnemyBird.h"
#include "../Managers/GameObjectManager.h"
#include "BGMovement.h"
#include <cmath>

EnemySwarmHandler::EnemySwarmHandler(int numEnemies, std::string name, AGameObject* parent, int type) : AComponent(name, Script)
{
	// Depending on the parameter "type" it chooses which enemy to use for the enemyPool
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
			new EnemyCactus("cactus"), 
			numEnemies,
			parent);
	}
	
	enemyPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);
}

EnemySwarmHandler::~EnemySwarmHandler()
{
	delete this->enemyPool;
};

void EnemySwarmHandler::perform()
{
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	this->ticks += this->deltaTime.asSeconds();

	if (this->ticks > SPAWN_INTERVAL) { // Spawns each enemies on a time interval
		this->ticks = 0.0f;
		randomizeInterval();
		enemyPool->requestPoolable();
	}

}

void EnemySwarmHandler::randomizeInterval()
{
	// Randomizes the Spawn Pattern
	float random = 1 + rand() % 2;

	if (random == 2) {
		enemyPool->requestPoolable();
		enemyPool->requestPoolable();
		enemyPool->requestPoolable();
	}
}
