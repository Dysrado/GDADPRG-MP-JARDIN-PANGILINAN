#pragma once
#include "APoolable.h"
#include <vector>

typedef std::vector<APoolable*> ObjectList;

class GameObjectPool
{
public:
	GameObjectPool(std::string tag, APoolable* poolableCopy, int poolableSize, AGameObject* parent);
	~GameObjectPool();
	void initialize();
	bool hasObjectAvailable(int requestSize);
	APoolable* requestPoolable();
	ObjectList requestPoolableBatch(int size);

	void releasePoolable(APoolable* poolableObject);
	void releasePoolableBatch(ObjectList objectList);

	std::string getTag();

private:
	std::string _tag;
	APoolable* _objectCopy = NULL;
	AGameObject* _parent = NULL;
	int _maxPoolSize = 20;
	ObjectList availableObjects;
	ObjectList usedObjects;

	void setEnabled(APoolable* poolableObject, bool flag);
};

