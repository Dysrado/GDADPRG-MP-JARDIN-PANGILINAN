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
#include <string>
#include "Components/EnemyInputController.h"

EnemyBird::EnemyBird(std::string name) : APoolable(name), CollisionListener() {

}


EnemyBird::~EnemyBird() {
	delete this->sprite;
}


void EnemyBird::initialize() {
	// Opens the JSON File
	FILE* file = fopen("Media/Textures/Spritesheet/dino_final_sheet.json", "rb");

	sf::IntRect frame;
	sf::Vector2u textureSize;
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
		for (int i = 1; i <= 2; i++) { // Creates a list of coordinates for the textures in the sprite sheet
			std::string index_str = "bird-" + std::to_string(i) + ".png";
			frame.left = icon[index_str.c_str()]["frame"]["x"].GetInt();
			frame.top = icon[index_str.c_str()]["frame"]["y"].GetInt();
			frame.width = icon[index_str.c_str()]["frame"]["w"].GetInt();
			frame.height = icon[index_str.c_str()]["frame"]["h"].GetInt();
			textureSize.x = icon[index_str.c_str()]["sourceSize"]["w"].GetInt();
			textureSize.y = icon[index_str.c_str()]["sourceSize"]["h"].GetInt();
			frames.push_back(frame);
		}
		
	}
	this->sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("dino_sheet"));
	sprite->setTextureRect(frames[0]);
	sprite->setOrigin(textureSize.x / 2, textureSize.y);
	this->setPosition(Game::WINDOW_WIDTH / 2, 0);

	int random = 1 + rand() % 2;
	if (random == 1) { // Randomizes it if it spawns in a up or down position
		LOCATION = 100;
	}
	else{
		LOCATION = 225;
	}

	this->getTransformable()->move(LOCATION, 0);

	Renderer* renderer = new Renderer("EnemyBirdSprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	EnemyInputController* inputController = new EnemyInputController("EnemyBirdInput");
	this->attachComponent(inputController);

	EnemyBehaviour* behaviour = new EnemyBehaviour("EnemyBirdBehaviour");
	this->attachComponent(behaviour);
	behaviour->configure(0.f);

	this->animClock.restart();
	this->collider = new Collider("BirdCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	collider->setCollisionListener(this);
	this->attachComponent(collider);
}

void EnemyBird::onRelease() {

}

void EnemyBird::onActivate() {
	EnemyBehaviour* behaviour = (EnemyBehaviour*)this->findComponentByName("EnemyBirdBehaviour");
	behaviour->reset();
	PhysicsManager::getInstance()->trackObject(this->collider);

	this->setPosition(0, Game::WINDOW_HEIGHT / 2);
	int random = 1 + rand() % 2;
	if (random == 1) { // Randomizes it if it spawns in a up or down position
		LOCATION = 100;
	}
	else {
		LOCATION = 225;
	}
	this->getTransformable()->move(Game::WINDOW_WIDTH + 100, LOCATION);
}

APoolable* EnemyBird::clone()
{
	APoolable* copyObj = new EnemyBird(this->name);
	return copyObj;
}


void EnemyBird::update(sf::Time deltaTime) {
	// Animates the EnemyBird
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

void EnemyBird::onCollisionEnter(AGameObject* contact)
{
}

void EnemyBird::onCollisionExit(AGameObject* contact)
{
}
