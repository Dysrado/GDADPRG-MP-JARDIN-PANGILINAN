#pragma once
#include "AScene.h"
class Level3 : public AScene
{
public:
	Level3();
	~Level3();

	void onLoadResources();
	void onLoadObjects();

	void OnUnloadResources();
};

