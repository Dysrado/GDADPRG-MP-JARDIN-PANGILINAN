#include "Level3.h"
#include "../Screens/Level3Screen.h"

Level3::Level3() : AScene("Level3")
{
}

Level3::~Level3()
{
}

void Level3::onLoadResources()
{
}

void Level3::onLoadObjects()
{
	// Instantiates the Screen/Level along with the Audio
	Level3Screen* screen = new Level3Screen("Level3Screen");
	this->registerObject(screen);

}

void Level3::OnUnloadResources()
{
}
