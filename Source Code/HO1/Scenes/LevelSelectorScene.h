#pragma once
#include "AScene.h"
class LevelSelectorScene
	: public AScene
{
public:
	LevelSelectorScene();
	~LevelSelectorScene();

	void onLoadResources();
	void onLoadObjects();

	void OnUnloadResources();

};

