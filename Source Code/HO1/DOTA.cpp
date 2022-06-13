#include "DOTA.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"

#include "Components/PlayerMovement.h"
#include "Components/Renderer.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include <string>
#include <cstdlib>


DOTA::DOTA(std::string name) : AGameObject(name) {}

void DOTA::initialize() {
	srand(time(NULL));
	std::cout << "Declared as " << this->getName() << std::endl;

	sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("dota2_sheet"));
	sf::IntRect frame = sf::IntRect(0, 0, 1, 1);
	sprite->setTextureRect(frame);
	sf::Vector2u textureSize(150, 84);
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);

	Renderer* render = new Renderer("dota2Sprite");
	render->assignDrawable(sprite);
	this->attachComponent(render);

	inputController = new PlayerInputController("MyPlayerInput");
	this->attachComponent(inputController);

	PlayerMovement* movement = new PlayerMovement("myMovement");
	this->attachComponent(movement);

	FILE* file = fopen("Media/Textures/Dota2_JSON.json", "rb");

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

		for (int i = 0; i <= 38; i++) {
			sf::IntRect temp(0, 0, 0, 0);
			std::string index_str = std::to_string(i);
			temp.left = icon[index_str.c_str()]["frame"]["x"].GetInt();
			temp.top = icon[index_str.c_str()]["frame"]["y"].GetInt();
			temp.width = icon[index_str.c_str()]["frame"]["w"].GetInt();
			temp.height = icon[index_str.c_str()]["frame"]["h"].GetInt();

			frameList.push_back(temp);
		}

		// for testing if the values were saved into the vector
		/*for (auto temp : frameList) {
			std::cout << temp.left << ", " << temp.top << ", " << temp.width << ", " << temp.height << std::endl;
		}*/

		index = rand() % 38;
	}
	this->cooldownClock.restart();
}

void DOTA::update()
{
	if (cooldownClock.getElapsedTime().asSeconds() >= .25f) {
		if (inputController->isLeft()) {
			index--;
			if (index < 0) {
				index = frameList.size() - 1;
			}
			cooldownClock.restart();
		}
		else if (inputController->isRight()) {
			index++;
			if (index >= frameList.size()) {
				index = 0;
			}
			cooldownClock.restart();
		}
		sprite->setTextureRect(frameList[index]);
	}

}


