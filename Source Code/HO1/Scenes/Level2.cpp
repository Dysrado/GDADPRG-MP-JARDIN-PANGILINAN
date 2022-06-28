#include "Level2.h"
#include "../Screens/Level2Screen.h"

Level2::Level2() : AScene("Level2")
{
}

Level2::~Level2()
{
}

void Level2::onLoadResources()
{
}

void Level2::onLoadObjects()
{
	// Instantiates the Screen/Level along with the Audio
	Level2Screen* screen = new Level2Screen("Level2Screen");
	this->registerObject(screen);
	
}

void Level2::OnUnloadResources()
{
}
