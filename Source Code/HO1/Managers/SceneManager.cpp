#include "SceneManager.h"

std::string SceneManager::MAIN_MENU_SCENE_NAME = "MainMenuScene";
std::string SceneManager::GAME_SCENE_NAME = "GameScene";

SceneManager* SceneManager::sharedInstance = NULL;

SceneManager* SceneManager::getInstance() {
	if (sharedInstance == NULL) {
		sharedInstance = new SceneManager();
	}

	return sharedInstance;
}

void SceneManager::registerScene(AScene* scene) {
	std::cout << scene->getSceneName() << " registered!\n";
	this->storedScenes[scene->getSceneName()] = scene;
}

void SceneManager::checkLoadScene() {
	if (this->isLoading) {
		this->unloadScene();
		this->activeScene = this->storedScenes[this->toLoadSceneName];
		this->activeScene->onLoadResources();
		this->activeScene->onLoadObjects();
		this->isLoading = false;
	}
}

void SceneManager::loadScene(std::string name) {
	this->isLoading = true;
	this->toLoadSceneName = name;
}

void SceneManager::unloadScene() {
	if (this->activeScene != NULL) {
		this->activeScene->OnUnloadObjects();
		this->activeScene->OnUnloadResources();
	}
}
bool SceneManager::isSceneLoaded(std::string name) {
	return this->activeScene->getSceneName() == name;
}