#include "DefeatScene.h"
#include "../Screens/DefeatScreen.h"

DefeatScene::DefeatScene() : AScene("DefeatScene")
{
}

DefeatScene::~DefeatScene()
{
}

void DefeatScene::onLoadResources()
{
}

void DefeatScene::onLoadObjects()
{
	//Loads the defeat screen to the scene
	DefeatScreen* defeatScreen = new DefeatScreen("DefeatScreen");
	this->registerObject(defeatScreen);
}

void DefeatScene::OnUnloadResources()
{
}
