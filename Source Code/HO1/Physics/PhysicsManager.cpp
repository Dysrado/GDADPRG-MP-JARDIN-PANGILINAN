#include "PhysicsManager.h"
#include <iostream>

PhysicsManager* PhysicsManager::sharedInstance = NULL;

void PhysicsManager::initialize(std::string name, AGameObject* parent) {
	sharedInstance = new PhysicsManager(name);
	parent->attachComponent(sharedInstance);
}

void PhysicsManager::destroy() {
	delete sharedInstance;
}

PhysicsManager* PhysicsManager:: getInstance() {
	return sharedInstance;
}

PhysicsManager::~PhysicsManager() {
	
}
void PhysicsManager::trackObject(Collider* object) {
	object->setAlreadyCollided(false);
	this->trackedObjects.push_back(object);
}

void PhysicsManager::untrackObject(Collider* object) {
	this->forCleaningObjects.push_back(object);
}

void PhysicsManager::cleanUpObjects() {
	for (int i = 0; i < this->forCleaningObjects.size(); i++) {
		this->trackedObjects.erase(this->trackedObjects.begin() + i);
	}
	this->forCleaningObjects.clear(); 
}

void PhysicsManager::perform() {
	for (int i = 0; i < this->trackedObjects.size(); i++) {
		for (int j = 0; j < this->trackedObjects.size(); j++) {
			if (this->trackedObjects[i] != this->trackedObjects[j] &&
				this->trackedObjects[i]->getOwner()->isEnabled() &&
				this->trackedObjects[j]->getOwner()->isEnabled()) {
				if (this->trackedObjects[i]->willCollide(this->trackedObjects[j]) &&
					!this->trackedObjects[i]->alreadyCollided() &&
					!this->trackedObjects[j]->alreadyCollided()) {
					this->trackedObjects[i]->collisionEnter(this->trackedObjects[j]->getOwner());
					this->trackedObjects[j]->collisionEnter(this->trackedObjects[i]->getOwner());
				}
				else if (this->trackedObjects[i]->willCollide(this->trackedObjects[j]) &&
					this->trackedObjects[i]->alreadyCollided() &&
					this->trackedObjects[j]->alreadyCollided()) {
					
					
					this->trackedObjects[i]->setAlreadyCollided(false);
					this->trackedObjects[j]->setAlreadyCollided(false);
				}

			}
		}
	}

	std::cout << "---" << std::endl;
	for (int i = 0; i < this->trackedObjects.size(); i++) {
		std::cout << this->trackedObjects[i]->getOwner()->isEnabled() << std::endl;
		this->trackedObjects[i]->setChecked(false);
	}
	this->cleanUpObjects();
}

