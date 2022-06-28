#include "LevelSelectorScene.h"
#include "../Screens/LevelSelectorScreen.h"

LevelSelectorScene::LevelSelectorScene() : AScene("LevelSelectorScene")
{
}

LevelSelectorScene::~LevelSelectorScene()
{
}

void LevelSelectorScene::onLoadResources()
{
}

void LevelSelectorScene::onLoadObjects()
{
	// Instantiates the Level Selector along with the Audio
	LevelSelectorScreen* levelScreen = new LevelSelectorScreen("LevelSelectorScreen");
	this->registerObject(levelScreen);
	
}

void LevelSelectorScene::OnUnloadResources()
{
}
