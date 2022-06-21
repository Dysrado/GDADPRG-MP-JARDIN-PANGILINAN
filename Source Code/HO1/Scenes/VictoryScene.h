#pragma once
#include "AScene.h"
class VictoryScene : public AScene
{
public:
	VictoryScene();
	~VictoryScene();

	void onLoadResources();
	void onLoadObjects();

	void OnUnloadResources();

};


