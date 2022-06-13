#include "AirplaneSupport.h"
#include "TextureManager.h"
#include "Components/AirplaneSupportMovement.h"
#include <iostream>
#include "Components/Renderer.h"

AirplaneSupport::AirplaneSupport(std::string name) : AGameObject(name){}

void AirplaneSupport::initialize()
{
	/*std::cout << "Declared as " << this->getName() << std::endl;
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->GetTexture("raptor"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	this->sprite->setPosition(0, 0);*/

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("raptor"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
	sprite->setPosition(0, 0);

	Renderer* renderer = new Renderer("AirplaneSupportRenderer");
	renderer->assignDrawable(sprite);
	attachComponent(renderer);

	AirplaneSupportMovement* logicComponent = new AirplaneSupportMovement("AirplaneSupportMovement_1");
	this->attachComponent(logicComponent);

}



