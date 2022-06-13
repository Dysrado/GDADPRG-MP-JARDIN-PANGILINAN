#include "EmptyGameObject.h"

EmptyGameObject::EmptyGameObject(std::string name) : AGameObject(name)
{
}

EmptyGameObject::~EmptyGameObject()
{
	AGameObject::~AGameObject();
}

void EmptyGameObject::initialize()
{
}
