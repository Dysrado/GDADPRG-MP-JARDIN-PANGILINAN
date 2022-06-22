#pragma once
#include "AScene.h"
#include "../Managers/AudioManager.h"

class Level1 : public AScene
{
public:
	Level1();
	~Level1();

	void onLoadResources();
	void onLoadObjects();

	void OnUnloadResources();
private:
	sf::Music music;
};

