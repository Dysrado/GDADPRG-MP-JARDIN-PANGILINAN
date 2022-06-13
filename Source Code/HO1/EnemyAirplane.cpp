#include "EnemyAirplane.h"
#include "TextureManager.h"
#include "Game.h"
#include "Components/Renderer.h"
#include "Components/EnemyBehaviour.h"


EnemyAirplane::EnemyAirplane(std::string name) : APoolable(name) {

}


EnemyAirplane::~EnemyAirplane() {
	delete this->sprite;
}


void EnemyAirplane::initialize() {
	this->sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("avenger"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->setPosition(Game::WINDOW_WIDTH / 2, -30);

	this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
	this->getTransformable()->setRotation(180);

	Renderer* renderer = new Renderer("EnemySprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	EnemyBehaviour* behaviour = new EnemyBehaviour("EnemyBehaviour");
	this->attachComponent(behaviour);
	behaviour->configure(1.f);

}

void EnemyAirplane::onRelease() {

}

void EnemyAirplane::onActivate() {
	EnemyBehaviour* behaviour = (EnemyBehaviour*)this->findComponentByName("EnemyBehaviour");
	behaviour->reset();
	
	this->setPosition(Game::WINDOW_WIDTH/ 2, -30);
	this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
}

APoolable* EnemyAirplane::clone()
{
	APoolable* copyObj = new EnemyAirplane(this->name);
	return copyObj;
}
