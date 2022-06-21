#include "EnemyDino.h"
#include "TextureManager.h"
#include "Game.h"
#include "Components/Renderer.h"
#include "Components/EnemyBehaviour.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <cstdlib>
#include "Components/EnemyInputController.h"


EnemyDino::EnemyDino(std::string name) : APoolable(name), CollisionListener() {

}


EnemyDino::~EnemyDino() {
	delete this->sprite;
}


void EnemyDino::initialize() {

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
		for (int i = 1; i <= 2; i++) {
			std::string index_str = "ddown-" + std::to_string(i) + ".png";
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
	sprite->setTextureRect(frame);
	sprite->setOrigin(textureSize.x / 2, textureSize.y);
	sprite->setScale(-1, 1); // flips the image
	this->setPosition(Game::WINDOW_WIDTH / 2, 0);

	//this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
	this->getTransformable()->move(LOCATION, 0);
	//this->getTransformable()->setRotation(180);

	Renderer* renderer = new Renderer("EnemyDinoSprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	EnemyInputController* inputController = new EnemyInputController("EnemyDinoInput");
	this->attachComponent(inputController);

	EnemyBehaviour* behaviour = new EnemyBehaviour("EnemyDinoBehaviour");
	this->attachComponent(behaviour);
	behaviour->configure(0.f);
	this->collider = new Collider("DinoCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	collider->setCollisionListener(this);
	this->attachComponent(collider);
}

void EnemyDino::onRelease() {

}

void EnemyDino::onActivate() {
	EnemyBehaviour* behaviour = (EnemyBehaviour*)this->findComponentByName("EnemyDinoBehaviour");
	behaviour->reset();
	PhysicsManager::getInstance()->trackObject(this->collider);

	this->setPosition(0, Game::WINDOW_HEIGHT / 2);
	//this->getTransformable()->move(Game::WINDOW_WIDTH, rand() % SPAWN_RANGE - rand() % SPAWN_RANGE);
	this->getTransformable()->move(Game::WINDOW_WIDTH, LOCATION);
}

APoolable* EnemyDino::clone()
{
	APoolable* copyObj = new EnemyDino(this->name);
	return copyObj;
}

void EnemyDino::update(sf::Time deltaTime) {
	if (this->animClock.getElapsedTime().asSeconds() >= 0.2f) {
		this->frameCtr += 1;
		if (this->frameCtr >= 2) {
			this->frameCtr = 0;
		}
		this->animClock.restart();
		this->sprite->setTextureRect(this->frames[frameCtr]);
	}
	AGameObject::update(deltaTime);
}

void EnemyDino::onCollisionEnter(AGameObject* contact)
{
}

void EnemyDino::onCollisionExit(AGameObject* contact)
{
}
