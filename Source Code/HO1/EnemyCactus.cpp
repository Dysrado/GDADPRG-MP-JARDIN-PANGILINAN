#include "EnemyCactus.h"
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

EnemyCactus::EnemyCactus(std::string name) : APoolable(name), CollisionListener() {

}


EnemyCactus::~EnemyCactus() {
	delete this->sprite;
}


void EnemyCactus::initialize() {
	// Reads the JSON file
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
		int random = rand() % 2;
		if (random == 1) { // Randomizes the Cactus Texture
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
	this->setPosition(Game::WINDOW_WIDTH / 2 + 60, 0);


	this->getTransformable()->move(LOCATION, 0);

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

void EnemyCactus::onRelease() {

}

void EnemyCactus::onActivate() {
	// Places it on the right side off screen
	EnemyBehaviour* behaviour = (EnemyBehaviour*)this->findComponentByName("EnemyBehaviour");
	behaviour->reset();
	
	this->setPosition(0, Game::WINDOW_HEIGHT / 2);
	PhysicsManager::getInstance()->trackObject(this->collider);
	this->getTransformable()->move(Game::WINDOW_WIDTH + 100, LOCATION);
}

APoolable* EnemyCactus::clone()
{
	APoolable* copyObj = new EnemyCactus(this->name);
	return copyObj;
}

void EnemyCactus::onCollisionEnter(AGameObject* contact)
{
	
	
}

void EnemyCactus::onCollisionExit(AGameObject* contact)
{
}




