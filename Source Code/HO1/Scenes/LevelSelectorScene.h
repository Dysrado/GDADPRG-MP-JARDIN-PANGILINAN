#pragma once
#include "AScene.h"
#include "../Managers/AudioManager.h"
class LevelSelectorScene
	: public AScene
{
public:
	LevelSelectorScene();
	~LevelSelectorScene();

	void onLoadResources();
	void onLoadObjects();

	void OnUnloadResources();
private:
	sf::Music music;
};

