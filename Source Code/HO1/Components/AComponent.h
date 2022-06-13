#pragma once
#include <iostream>
#include <SFML/System.hpp>

class AGameObject;

class AComponent
{
public:
	enum ComponentType {NotSet = -1, Script = 0, Renderer = 1, Input = 2};
	AComponent(std::string, ComponentType type);
	virtual ~AComponent();

	void attachOwner(AGameObject* object);
	void detatchOwner();
	AGameObject* getOwner();
	ComponentType getType();
	std::string getName();

	void setDeltaTime(sf::Time deltaTime);
	virtual void perform() = 0;

protected:
	AGameObject* owner;
	ComponentType type;
	std::string name;
	sf::Time deltaTime;
};

