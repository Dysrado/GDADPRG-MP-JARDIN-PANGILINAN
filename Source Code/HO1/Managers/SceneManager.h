#pragma once
#include "../Scenes/AScene.h"
#include <unordered_map>
typedef std::unordered_map < std::string, AScene* > SceneTable;
typedef std::vector<std::string> SceneList;
	const std::string MAIN_MENU_SCENE_NAME = "MainMenuScene";
	const std::string GAME_SCENE_NAME = "GameScene";
class SceneManager : sf::NonCopyable
{
public:

	static SceneManager* getInstance();
	void registerScene(AScene* scene);
	void loadScene(std::string name);
	void unloadScene();
	void checkLoadScene();
	bool isSceneLoaded(std::string name);
private:
	SceneManager() {};
	static SceneManager* sharedInstance;
	SceneTable storedScenes;
	AScene* activeScene = NULL;

	bool isLoading = false;
	std::string toLoadSceneName;
};

