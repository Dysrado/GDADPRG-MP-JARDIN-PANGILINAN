#include "PlayerHearts.h"
#include "../TextureManager.h"
#include <iostream>
#include "../Components/Renderer.h"

PlayerHearts::PlayerHearts(std::string name) : AGameObject(name)
{

}

PlayerHearts::~PlayerHearts()
{
	AGameObject::~AGameObject();
}

void PlayerHearts::initialize()
{
	this->sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("heart"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	sprite->setScale(.6f, .6f);
	Renderer* renderer = new Renderer("Heart");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}
