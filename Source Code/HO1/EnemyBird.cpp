#include "EnemyBird.h"
#include "TextureManager.h"
#include "Game.h"
#include "Components/Renderer.h"
#include "Components/EnemyBehaviour.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <cstdlib>

EnemyBird::EnemyBird(std::string name) : APoolable(name) {

}


EnemyBird::~EnemyBird() {
	delete this->sprite;
}


void EnemyBird::initialize() {

	FILE* file = fopen("Media/Textures/Spritesheet/dino_sheet.json", "rb");

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
		frame.left = icon["enemy-bird.png"]["frame"]["x"].GetInt();
		frame.top = icon["enemy-bird.png"]["frame"]["y"].GetInt();
		frame.width = icon["enemy-bird.png"]["frame"]["w"].GetInt() / 2;
		frame.height = icon["enemy-bird.png"]["frame"]["h"].GetInt();
		textureSize.x = icon["enemy-bird.png"]["sourceSize"]["w"].GetInt() / 2;
		textureSize.y = icon["enemy-bird.png"]["sourceSize"]["h"].GetInt();

		frames.push_back(frame);

		frame.left = icon["enemy-bird.png"]["frame"]["x"].GetInt() + 92;
		frame.top = icon["enemy-bird.png"]["frame"]["y"].GetInt();
		frame.width = icon["enemy-bird.png"]["frame"]["w"].GetInt() / 2;
		frame.height = icon["enemy-bird.png"]["frame"]["h"].GetInt();

		frames.push_back(frame);
	}
	this->sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("dino_sheet"));
	sprite->setTextureRect(frames[0]);
	sprite->setOrigin(textureSize.x / 2, textureSize.y);
	this->setPosition(Game::WINDOW_WIDTH / 2, 0);

	int random = 1 + rand() % 2;
	if (random == 1) {
		LOCATION = 100;
	}
	else{
		LOCATION = 225;
	}
	//this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
	this->getTransformable()->move(LOCATION, 0);
	//this->getTransformable()->setRotation(180);

	Renderer* renderer = new Renderer("EnemyBirdSprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	PlayerInputController* inputController = new PlayerInputController("EnemyBirdInput", this->transformable.getPosition().x);
	this->attachComponent(inputController);

	EnemyBehaviour* behaviour = new EnemyBehaviour("EnemyBirdBehaviour");
	this->attachComponent(behaviour);
	behaviour->configure(0.f);

	this->animClock.restart();
}

void EnemyBird::onRelease() {

}

void EnemyBird::onActivate() {
	EnemyBehaviour* behaviour = (EnemyBehaviour*)this->findComponentByName("EnemyBirdBehaviour");
	behaviour->reset();

	this->setPosition(0, Game::WINDOW_HEIGHT / 2);
	//this->getTransformable()->move(Game::WINDOW_WIDTH, rand() % SPAWN_RANGE - rand() % SPAWN_RANGE);
	int random = 1 + rand() % 2;
	if (random == 1) {
		LOCATION = 100;
	}
	else {
		LOCATION = 225;
	}
	this->getTransformable()->move(Game::WINDOW_WIDTH, LOCATION);
}

APoolable* EnemyBird::clone()
{
	APoolable* copyObj = new EnemyBird(this->name);
	return copyObj;
}


void EnemyBird::update(sf::Time deltaTime) {
	if (this->animClock.getElapsedTime().asSeconds() >= 0.3f) {
		this->frameCtr += 1;
		if (this->frameCtr >= 2) {
			this->frameCtr = 0;
		}
		this->animClock.restart();
		this->sprite->setTextureRect(this->frames[frameCtr]);
	}
	AGameObject::update(deltaTime);
}