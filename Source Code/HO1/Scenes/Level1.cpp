#include "Level1.h"
#include "../Screens/Level1Screen.h"

Level1::Level1() : AScene("Level1")
{
}

Level1::~Level1()
{
}

void Level1::onLoadResources()
{
}

void Level1::onLoadObjects()
{
	Level1Screen* screen = new Level1Screen("Level1Screen");
	this->registerObject(screen);
}

void Level1::OnUnloadResources()
{
}
