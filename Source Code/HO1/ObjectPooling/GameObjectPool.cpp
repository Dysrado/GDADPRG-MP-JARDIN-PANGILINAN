#include "GameObjectPool.h"
#include "../Managers/GameObjectManager.h"
#include <iostream>

GameObjectPool::GameObjectPool(std::string tag, APoolable* poolableCopy, int poolableSize, AGameObject* parent)
{
	this->_tag = tag;
	this->_objectCopy = poolableCopy;
	this->_maxPoolSize = poolableSize;
	this->_parent = parent;
}

GameObjectPool::~GameObjectPool()
{
	delete this->_objectCopy;
	this->_objectCopy = NULL;
	this->_parent = NULL;
}

void GameObjectPool::initialize()
{
	for (int i = 0; i < this->_maxPoolSize; i++) {
		APoolable* poolableObject = this->_objectCopy->clone();

		if (this->_parent != NULL) {
			this->_parent->attachChild(poolableObject);
		}
		else {
			GameObjectManager::getInstance()->addObject(poolableObject);
		}

		poolableObject->setEnabled(false);
		this->availableObjects.push_back(poolableObject);
	}
}

bool GameObjectPool::hasObjectAvailable(int requestSize)
{
	return requestSize <= this->availableObjects.size();
}

APoolable* GameObjectPool::requestPoolable()
{
	if (this->hasObjectAvailable(1)) {
		APoolable* poolableObject = this->availableObjects[this->availableObjects.size() - 1];
		this->availableObjects.erase(this->availableObjects.begin() + this->availableObjects.size() - 1);
		this->usedObjects.push_back(poolableObject);
		std::cout << "Requested Object. Available: " << this->availableObjects.size()
			<< "Used: " << this->availableObjects.size() << std::endl;
		this->setEnabled(poolableObject, true);

		return poolableObject;
	}
	else {
		releasePoolable(this->usedObjects[0]);
		std::cout << "No more poolable " << this->_objectCopy->getName() << " available!\n";
		//releasePoolableBatch(usedObjects);
		return NULL;
	}
}

ObjectList GameObjectPool::requestPoolableBatch(int size)
{
	ObjectList returnList;
	if(this->hasObjectAvailable(size)){
		for (int i = 0; i < size; i++) {
			returnList.push_back(this->requestPoolable());
		}
	}
	else {
		std::cout << "Insufficient " << this->_objectCopy->getName() << " available in pool."
			<< " Count is" << this->availableObjects.size() << " while request is " << size << std::endl;
	}

	return returnList;
}

void GameObjectPool::releasePoolable(APoolable* poolableObject)
{
	ObjectList::iterator it = std::find(usedObjects.begin(), usedObjects.end(), poolableObject);
	if (it != usedObjects.end()) {
		this->availableObjects.push_back(poolableObject);
		this->usedObjects.erase(it);
		this->setEnabled(poolableObject, false);
	}
}

void GameObjectPool::releasePoolableBatch(ObjectList objectList)
{
	std::cout << "Releasing Batch!\n";

	for (int i = 0; i < objectList.size(); i++) {
		this->releasePoolable(objectList[i]);
	}
}

std::string GameObjectPool::getTag()
{
	return this->_tag;
}

void GameObjectPool::setEnabled(APoolable* poolableObject, bool flag)
{
	if (flag) {
		poolableObject->setEnabled(true);
		poolableObject->onActivate();
	}
	else {
		poolableObject->setEnabled(false);
		poolableObject->onRelease();
	}
}
