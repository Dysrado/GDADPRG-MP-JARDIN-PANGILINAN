#include "AirplanePlayer.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "Components/PlayerInputController.h"
#include "Components/PlayerMovement.h"
#include "Components/Renderer.h"

AirplanePlayer::AirplanePlayer(std::string name) : AGameObject(name) {}

void AirplanePlayer::initialize(){

	std::cout << "Declared as " << this->getName() << std::endl;

	this->setEnabled(true);

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("eagle"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);

	Renderer* render = new Renderer("PlayerSprite");
	render->assignDrawable(sprite);
	this->attachComponent(render);

	PlayerInputController* inputController = new PlayerInputController("MyPlayerInput");
	this->attachComponent(inputController);

	PlayerMovement* movement = new PlayerMovement("myMovement");
	this->attachComponent(movement);

}




