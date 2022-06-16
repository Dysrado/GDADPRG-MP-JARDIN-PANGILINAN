#include "EnemySwarmHandler.h"
#include "../ObjectPooling/ObjectPoolHolder.h"
#include "../EnemyAirplane.h"
#include "../EnemyDino.h"
#include "../EnemyBird.h"

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
	enemyPool->requestPoolableBatch(5);
}

EnemySwarmHandler::~EnemySwarmHandler()
{
	delete this->enemyPool;
};

void EnemySwarmHandler::perform()
{
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	this->ticks += this->deltaTime.asSeconds();

	if (this->ticks > SPAWN_INTERVAL) {
		this->ticks = 0.0f;
		randomizeInterval();
		enemyPool->requestPoolable();
	}
}

void EnemySwarmHandler::randomizeInterval()
{
	float random = 1 + rand() % 2;
	SPAWN_INTERVAL = random;
}
