#include "DinoPlayer.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "Components/PlayerMovement.h"
#include "Components/Renderer.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "UI/DefeatMenu.h"
#include "Managers/ApplicationManager.h"
#include "Managers/SceneManager.h"

DinoPlayer::DinoPlayer(std::string name) : AGameObject(name), CollisionListener()
{
	soundBuffer = AudioManager::getInstance()->getBuffer("hit");
	sound.setBuffer(*soundBuffer);
}

void DinoPlayer::initialize(){
	this->setEnabled(true);
	// Gets the JSON file for the spritesheet
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

	inputController = new PlayerInputController("MyPlayerInput",displacement);
	this->attachComponent(inputController);
	
	PlayerMovement* movement = new PlayerMovement("myMovement");
	this->attachComponent(movement);
	this->frameCtr = 0;
	this->sprite->setTextureRect(this->frames[frameCtr]);


	this->collider = new Collider("PlayerCollider");
	collider->setLocalBounds(sprite->getGlobalBounds());
	collider->setCollisionListener(this);
	this->attachComponent(collider);
	
	PhysicsManager::getInstance()->trackObject(this->collider);
}

void DinoPlayer::update(sf::Time deltaTime) {
	
	// Animates the player if the player moves left or right
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
	// If player jumps use this specific frame
	if (this->transformable.getPosition().y != (Game::WINDOW_HEIGHT / 2) + 150.f) {
		this->frameCtr = 2;
		this->sprite->setTextureRect(this->frames[frameCtr]);
	}
	AGameObject::update(deltaTime);
	
}

void DinoPlayer::onCollisionEnter(AGameObject* contact)
{
	// Collision Check for when the player collides with an enemy
	if ((contact->getName().find("cactus") != std::string::npos ||
		contact->getName().find("EnemyDino") != std::string::npos ||
		contact->getName().find("EnemyBird") != std::string::npos) && isCollided == false) {
		isCollided = true;
		sound.play();
		DefeatMenu* defeatMenu = new DefeatMenu("DefeatMenu");
		GameObjectManager::getInstance()->addObject(defeatMenu);
		

		
		ApplicationManager::getInstance()->pauseApplication();
		SceneManager::getInstance()->reduceLives();
		if (SceneManager::getInstance()->getLives() == 0) {
		
			SceneManager::getInstance()->loadScene(SceneManager::DEFEAT_SCENE_NAME);

		}
	
	}
	
}

void DinoPlayer::onCollisionExit(AGameObject* contact)
{
}



