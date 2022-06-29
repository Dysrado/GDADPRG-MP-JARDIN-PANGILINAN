#include "GoalPoint.h"
#include "TextureManager.h"
#include "Components/Renderer.h"
#include "Components/EnemyInputController.h"
#include "Components/GoalMovement.h"

GoalPoint::GoalPoint(std::string name) : AGameObject(name)
{

}

void GoalPoint::initialize()
{
	this->setEnabled(true);

	sprite = new sf::Sprite();

	sprite->setTexture(*TextureManager::getInstance()->GetTexture("coin"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	sprite->setTextureRect(sf::IntRect(0, 0, textureSize.x /4, textureSize.y));

	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	sprite->setScale(4, 4);

	sprite->setPosition((1024 * 6), 550);

	Renderer* render = new Renderer("Coin");
	render->assignDrawable(sprite);
	this->attachComponent(render);

	EnemyInputController* inputController = new EnemyInputController("CoinInput");
	this->attachComponent(inputController);

	GoalMovement* movement = new GoalMovement("coinMovement");
	this->attachComponent(movement);
}

