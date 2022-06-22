#pragma once
#include "AScene.h"
class DefeatScene : public AScene
{
public:
	DefeatScene();
	~DefeatScene();

	void onLoadResources();
	void onLoadObjects();

	void OnUnloadResources();
};

