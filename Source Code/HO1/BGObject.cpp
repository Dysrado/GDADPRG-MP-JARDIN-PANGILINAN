#include "BGObject.h"
#include "Components/Renderer.h"
#include "Components/BGMovement.h"
#include "Components/PlayerInputController.h"
#include "Components/EnemyInputController.h"
#include "Managers/SceneManager.h"

BGObject::BGObject(std::string name) : AGameObject(name){}

void BGObject::initialize()
{

	sprite = new sf::Sprite();
	
	// Chooses which Background texture to use
	if (SceneManager::getInstance()->getActiveSceneName() == "Level1") {
		sprite->setTexture(*TextureManager::getInstance()->GetTexture("ground"));
	}
	else if (SceneManager::getInstance()->getActiveSceneName() == "Level2") {
		sprite->setTexture(*TextureManager::getInstance()->GetTexture("ground3"));
	}
	else if (SceneManager::getInstance()->getActiveSceneName() == "Level3") {
		sprite->setTexture(*TextureManager::getInstance()->GetTexture("ground2"));
	}
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


