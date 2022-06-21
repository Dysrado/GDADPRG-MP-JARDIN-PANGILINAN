#pragma once
#include "../Components/AComponent.h"
#include "Collider.h"
#include <unordered_map>
#include <vector>
#include "../AGameObject.h"
typedef std::vector<Collider*> CollisionList;
class PhysicsManager : public AComponent {
public:
	static void initialize(std::string name, AGameObject* parent);
	static void destroy();
	static PhysicsManager* getInstance();
	~PhysicsManager();

	void trackObject(Collider* object);
	void untrackObject(Collider* object);
	void perform();

private:
	PhysicsManager(std::string name) : AComponent(name, Script) {};
	static PhysicsManager* sharedInstance;

	CollisionList trackedObjects;
	CollisionList forCleaningObjects;

	void cleanUpObjects();
};

