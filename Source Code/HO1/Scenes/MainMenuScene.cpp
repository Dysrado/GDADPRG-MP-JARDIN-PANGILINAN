#include "MainMenuScene.h"
#include "../Screens/MainMenuScreen.h"

MainMenuScene::MainMenuScene() : AScene("MainMenuScene")
{

}

MainMenuScene::~MainMenuScene()
{

}

void MainMenuScene::onLoadResources()
{

}

void MainMenuScene::onLoadObjects()
{
	MainMenuScreen* menuScreen = new MainMenuScreen("MainMenuScreen");
	this->registerObject(menuScreen);
}

void MainMenuScene::OnUnloadResources()
{

}
