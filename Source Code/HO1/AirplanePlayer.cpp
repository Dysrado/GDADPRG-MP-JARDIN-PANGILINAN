#include "AirplanePlayer.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "Components/PlayerInputController.h"
#include "Components/PlayerMovement.h"
#include "Components/Renderer.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

AirplanePlayer::AirplanePlayer(std::string name) : AGameObject(name) {}

void AirplanePlayer::initialize(){

	std::cout << "Declared as " << this->getName() << std::endl;

	this->setEnabled(true);
	FILE* file = fopen("Media/Textures/Spritesheet/dino_final_sheet.json", "rb");

	sf::IntRect frame;
	sf::Vector2u textureSize;
	//assert(file != 0);
	if (file == 0) {
		std::cout << "Could not open file\n";
	}
	else {
		char readBuffer[65536];
		rapidjson::FileReadStream is(file, readBuffer, sizeof(readBuffer));
		rapidjson::Document doc;

		doc.ParseStream(is);
		fclose(file);

		rapidjson::Value& icon = doc["frames"];
		for (int i = 1; i <= 4; i++) {
			std::string index_str = "dino-" + std::to_string(i) + ".png";
			frame.left = icon[index_str.c_str()]["frame"]["x"].GetInt();
			frame.top = icon[index_str.c_str()]["frame"]["y"].GetInt();
			frame.width = icon[index_str.c_str()]["frame"]["w"].GetInt();
			frame.height = icon[index_str.c_str()]["frame"]["h"].GetInt();
			textureSize.x = icon[index_str.c_str()]["sourceSize"]["w"].GetInt();
			textureSize.y = icon[index_str.c_str()]["sourceSize"]["h"].GetInt();
			frames.push_back(frame);
		}
	}
	sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("dino_sheet"));
	sprite->setTextureRect(frame);
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, (Game::WINDOW_HEIGHT / 2) + 150.f);

	Renderer* render = new Renderer("PlayerSprite");
	render->assignDrawable(sprite);
	this->attachComponent(render);

	PlayerInputController* inputController = new PlayerInputController("MyPlayerInput",this->transformable.getPosition().y);
	this->attachComponent(inputController);

	PlayerMovement* movement = new PlayerMovement("myMovement");
	this->attachComponent(movement);

}

void AirplanePlayer::update(sf::Time deltaTime) {
	PlayerInputController* inputController = new PlayerInputController("MyPlayerInput", this->transformable.getPosition().y);
	if (inputController->isLeft() || inputController->isRight()) {
		if (this->animClock.getElapsedTime().asSeconds() >= 0.2f) {
			this->frameCtr += 1;
			if (this->frameCtr >= 4) {
				this->frameCtr = 0;
			}
			this->animClock.restart();
			this->sprite->setTextureRect(this->frames[frameCtr]);
		}
	}
	AGameObject::update(deltaTime);
}


