#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Components/AComponent.h"

class AGameObject
{
public:
	AGameObject(std::string name);
	virtual ~AGameObject();
	virtual void initialize() = 0;
	virtual void processInput(sf::Event ev);
	virtual void update(sf::Time deltaTime);
	virtual void draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates);
	std::string getName();
	void attachChild(AGameObject* child);
	void detachChild(AGameObject* child);
	void setPosition(float x, float y);

	void setEnabled(bool flag);
	bool isEnabled();

	void attachComponent(AComponent* component);
	void detachComponent(AComponent* component);

	AComponent* findComponentByName(std::string name);
	AComponent* findComponentOfType(AComponent::ComponentType type, std::string name);

	std::vector <AComponent*> getComponentsOfType(AComponent::ComponentType type);
	/*std::vector <AComponent*> getComponentsOfTypeRecursive(AComponent::ComponentType type);*/

	sf::Transformable* getTransformable();

	sf::Transform getGlobalTransform();
	AGameObject* getParent();
	//sf::Sprite* getSprite();
	

protected:
	sf::Sprite* sprite;
	void setParent(AGameObject* gameObject);

	sf::Transformable transformable;
	std::string name;
	sf::Texture* texture;
	std::vector<AGameObject*> childList;
	std::vector<AComponent*> componentList;

private:
	AGameObject* mParent;
	bool enabled = true;
};

