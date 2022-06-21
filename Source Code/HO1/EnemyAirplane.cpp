#include "EnemyAirplane.h"
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

EnemyAirplane::EnemyAirplane(std::string name) : APoolable(name), CollisionListener() {

}


EnemyAirplane::~EnemyAirplane() {
	delete this->sprite;
}


void EnemyAirplane::initialize() {

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
		int random = rand() % 2;
		if (random == 1) {
			frame.left = icon["cactuses_big_3.png"]["frame"]["x"].GetInt();
			frame.top = icon["cactuses_big_3.png"]["frame"]["y"].GetInt();
			frame.width = icon["cactuses_big_3.png"]["frame"]["w"].GetInt();
			frame.height = icon["cactuses_big_3.png"]["frame"]["h"].GetInt();
			textureSize.x = icon["cactuses_big_3.png"]["sourceSize"]["w"].GetInt();
			textureSize.y = icon["cactuses_big_3.png"]["sourceSize"]["h"].GetInt();
		}
		else {
			frame.left = icon["cactuses_small_3.png"]["frame"]["x"].GetInt();
			frame.top = icon["cactuses_small_3.png"]["frame"]["y"].GetInt();
			frame.width = icon["cactuses_small_3.png"]["frame"]["w"].GetInt();
			frame.height = icon["cactuses_small_3.png"]["frame"]["h"].GetInt();
			textureSize.x = icon["cactuses_small_3.png"]["sourceSize"]["w"].GetInt();
			textureSize.y = icon["cactuses_small_3.png"]["sourceSize"]["h"].GetInt();
		}
		
	}
	this->sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("dino_sheet"));
	sprite->setTextureRect(frame);
	sprite->setOrigin(textureSize.x / 2, textureSize.y);
	this->setPosition(Game::WINDOW_WIDTH / 2 + 20, 0);

	//this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
	this->getTransformable()->move(LOCATION, 0);
	//this->getTransformable()->setRotation(180);

	Renderer* renderer = new Renderer("EnemySprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	EnemyInputController* inputController = new EnemyInputController("SmallCactusInput");
	this->attachComponent(inputController);

	EnemyBehaviour* behaviour = new EnemyBehaviour("EnemyBehaviour");
	this->attachComponent(behaviour);
	behaviour->configure(1.f);

	this->collider = new Collider("CactusCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	collider->setCollisionListener(this);
	this->attachComponent(collider);
}

void EnemyAirplane::onRelease() {

}

void EnemyAirplane::onActivate() {
	EnemyBehaviour* behaviour = (EnemyBehaviour*)this->findComponentByName("EnemyBehaviour");
	behaviour->reset();
	
	this->setPosition(0, Game::WINDOW_HEIGHT / 2);
	//this->getTransformable()->move(Game::WINDOW_WIDTH, rand() % SPAWN_RANGE - rand() % SPAWN_RANGE);
	PhysicsManager::getInstance()->trackObject(this->collider);
	this->getTransformable()->move(Game::WINDOW_WIDTH, LOCATION);
	//PhysicsManager::getInstance()->trackObject(collider);
}

APoolable* EnemyAirplane::clone()
{
	APoolable* copyObj = new EnemyAirplane(this->name);
	return copyObj;
}

void EnemyAirplane::onCollisionEnter(AGameObject* contact)
{
	/*if (contact->getName().find("PlaneObject") != std::string::npos) {
		std::cout << "COLLIDING\n";

	}*/
	
}

void EnemyAirplane::onCollisionExit(AGameObject* contact)
{
}




