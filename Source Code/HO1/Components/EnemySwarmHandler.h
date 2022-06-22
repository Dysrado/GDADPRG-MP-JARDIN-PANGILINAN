#pragma once
#include "AComponent.h"
#include "../ObjectPooling/GameObjectPool.h"
class EnemySwarmHandler : public AComponent
{
public:
	EnemySwarmHandler(int numEnemies, std::string name, AGameObject* parent, int type);
	~EnemySwarmHandler();
	void perform();

private:
	void randomizeInterval();
	GameObjectPool* enemyPool;
	const float SPAWN_INTERVAL = 3.f;
	float ticks = 0.0f;
};

