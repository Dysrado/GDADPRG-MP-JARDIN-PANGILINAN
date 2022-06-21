#include "VictoryScene.h"
#include "../Screens/MainMenuScreen.h"

VictoryScene::VictoryScene() : AScene("VictoryScene")
{

}

VictoryScene::~VictoryScene()
{

}

void VictoryScene::onLoadResources()
{

}

void VictoryScene::onLoadObjects()
{
	MainMenuScreen* menuScreen = new MainMenuScreen("MainMenuScreen");
	this->registerObject(menuScreen);
}

void VictoryScene::OnUnloadResources()
{

}
