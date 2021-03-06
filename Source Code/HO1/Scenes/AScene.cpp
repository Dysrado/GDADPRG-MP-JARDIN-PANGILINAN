#include "AScene.h"
#include "../Managers/GameObjectManager.h"

AScene::AScene(std::string sceneName)
{
	this->sceneName = sceneName;
}

AScene::~AScene()
{

}

void AScene::OnUnloadObjects() {
	GameObjectManager::getInstance()->deleteAllObjectsInScene();
}

std::string AScene::getSceneName() {
	return this->sceneName;
}


void AScene::registerObject(AGameObject* object) {
	GameObjectManager::getInstance()->addObject(object);
}