#include "VictoryScene.h"
#include "../Screens/VictoryScreen.h"

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
	VictoryScreen* victoryScreen = new VictoryScreen("VictoryScreen");
	//MainMenuScreen* menuScreen = new MainMenuScreen("MainMenuScreen");
	this->registerObject(victoryScreen);
}

void VictoryScene::OnUnloadResources()
{

}
