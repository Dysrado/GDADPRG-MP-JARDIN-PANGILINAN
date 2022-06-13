#pragma once
#include "AComponent.h"
#include "../ObjectPooling/GameObjectPool.h"
class EnemySwarmHandler : public AComponent
{
public:
	EnemySwarmHandler(int numEnemies, std::string name, AGameObject* parent);
	~EnemySwarmHandler();
	void perform();
private:
	GameObjectPool* enemyPool;
	const float SPAWN_INTERVAL = 0.01f;
	float ticks = 0.0f;
};

