#include "SceneManager.h"

std::string SceneManager::MAIN_MENU_SCENE_NAME = "MainMenuScene";
std::string SceneManager::VICTORY_MENU_SCENE_NAME = "VictoryScene";
std::string SceneManager::LEVEL_SELECTOR_SCENE_NAME = "LevelSelectorScene";
std::string SceneManager::DEFEAT_SCENE_NAME = "DefeatScene";
std::string SceneManager::LEVEL_1_NAME = "Level1";
std::string SceneManager::LEVEL_2_NAME = "Level2";
std::string SceneManager::LEVEL_3_NAME = "Level3";

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

std::string SceneManager::getActiveSceneName()
{
	return this->activeScene->getSceneName();
}

int SceneManager::getLives()
{
	return playerLives;
}

void SceneManager::reduceLives()
{
	playerLives -= 1;;
}

void SceneManager::resetLives()
{
	playerLives = 4;
}
