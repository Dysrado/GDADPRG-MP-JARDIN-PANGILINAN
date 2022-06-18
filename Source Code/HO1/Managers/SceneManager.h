#pragma once
#include <unordered_map>
#include "../Scenes/AScene.h"

typedef std::unordered_map<std::string, AScene*> SceneTable;
typedef std::vector<std::string> SceneList;

class SceneManager
{
public:
	static std::string MAIN_MENU_SCENE_NAME;
	static std::string GAME_SCENE_NAME;

	static SceneManager* getInstance();

	void registerScene(AScene* scene);
	void loadScene(std::string name);
	void unloadScene();
	void checkLoadScene();
	bool isSceneLoaded(std::string name);

private:
	SceneManager() {};
	SceneManager(SceneManager const&) {};
	SceneManager& operator=(SceneManager const&) {};

	static SceneManager* sharedInstance;

	SceneTable storedScenes;
	AScene* activeScene = NULL;

	bool isLoading = false;
	std::string toLoadSceneName;

};

