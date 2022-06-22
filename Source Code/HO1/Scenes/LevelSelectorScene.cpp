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
	LevelSelectorScreen* levelScreen = new LevelSelectorScreen("LevelSelectorScreen");
	this->registerObject(levelScreen);
}

void LevelSelectorScene::OnUnloadResources()
{
}
