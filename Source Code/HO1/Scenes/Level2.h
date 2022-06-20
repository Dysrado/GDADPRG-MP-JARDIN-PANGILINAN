#pragma once
#include "AScene.h"
class Level2 : public AScene
{
public:
	Level2();
	~Level2();

	void onLoadResources();
	void onLoadObjects();

	void OnUnloadResources();

};

