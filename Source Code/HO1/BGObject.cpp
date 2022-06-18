#include "BGObject.h"
#include "Components/Renderer.h"
#include "Components/BGMovement.h"
#include "Components/PlayerInputController.h"
#include "Components/EnemyInputController.h"

BGObject::BGObject(std::string name) : AGameObject(name){}

void BGObject::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	sprite = new sf::Sprite();

	sprite->setTexture(*TextureManager::getInstance()->GetTexture("ground"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	sprite->setTextureRect(sf::IntRect(0, 0, textureSize.x * 4, textureSize.y));

	sprite->setOrigin(textureSize.x, 0);
	
	sprite->setPosition(0, -10);

	sprite->setScale(1.65,1.65);

	Renderer* render = new Renderer("BackgroundSprite");
	render->assignDrawable(sprite);
	this->attachComponent(render);

	EnemyInputController* inputController = new EnemyInputController("GroundInput");
	this->attachComponent(inputController);

	BGMovement* movement = new BGMovement("myBGMovement");
	this->attachComponent(movement);
}


