#include "Collider.h"
#include <iostream>
#include "PhysicsManager.h"

Collider::Collider(std::string name) : AComponent(name, AComponent::Physics)
{
}
