#include "EnemySwarmHandler.h"
#include "../ObjectPooling/ObjectPoolHolder.h"
#include "../EnemyAirplane.h"

EnemySwarmHandler::EnemySwarmHandler(int numEnemies, std::string name, AGameObject* parent) : AComponent(name, Script)
{
	enemyPool = new GameObjectPool(
		ObjectPoolHolder::ENEMY_POOL_TAG, 
		new EnemyAirplane("enemy"), 
		numEnemies, 
		parent);
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

	if (this->ticks > SPAWN_INTERVAL) {
		this->ticks = 0.0f;
		enemyPool->requestPoolable();
	}
}
