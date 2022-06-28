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
	// Instantiates the Victory Screen along with the Audio
	VictoryScreen* victoryScreen = new VictoryScreen("VictoryScreen");
	this->registerObject(victoryScreen);
}

void VictoryScene::OnUnloadResources()
{

}
