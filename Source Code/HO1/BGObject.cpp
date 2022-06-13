#include "BGObject.h"
#include "Components/Renderer.h"
#include "Components/BGMovement.h"

BGObject::BGObject(std::string name) : AGameObject(name){}

void BGObject::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	sprite = new sf::Sprite();

	sprite->setTexture(*TextureManager::getInstance()->GetTexture("desert_bg"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	
	sprite->setTextureRect(sf::IntRect(0, 0, Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT * 8));
	sprite->setPosition(0, -Game::WINDOW_HEIGHT * 7);

	Renderer* render = new Renderer("BackgroundSprite");
	render->assignDrawable(sprite);
	this->attachComponent(render);

	BGMovement* movement = new BGMovement("myBGMovement");
	this->attachComponent(movement);
}


