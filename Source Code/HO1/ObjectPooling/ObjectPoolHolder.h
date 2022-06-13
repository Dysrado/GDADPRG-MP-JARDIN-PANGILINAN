#pragma once
#include <vector>
#include <unordered_map>
#include "GameObjectPool.h"

typedef std::unordered_map<std::string, GameObjectPool*> PoolMap;

class ObjectPoolHolder : sf::NonCopyable
{
public:
	static std::string ENEMY_POOL_TAG;

	static ObjectPoolHolder* getInstance();

	void registerObjectPool(GameObjectPool* pool);
	void unregisterObjectPool(GameObjectPool* pool);
	GameObjectPool* getPool(std::string tag);

private:
	ObjectPoolHolder() {};

	static ObjectPoolHolder* sharedInstance;

	PoolMap PoolMap;
};

