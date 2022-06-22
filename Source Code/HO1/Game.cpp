// Textures and sfx from https://codeburst.io/create-a-secret-dino-chrome-game-in-1-hour-with-js-and-phaser-3-2caebb1abe2a

#include "Game.h"
#include <iostream>

#include "AirplaneSupport.h"
#include "Screens/MainMenuScreen.h"
#include "Managers/FontManager.h"
#include "Managers/ApplicationManager.h"
#include "UI/HUD.h"
#include "EnemyAirplane.h"
#include "EnemyDino.h"
#include "EmptyGameObject.h"
#include "Components/EnemySwarmHandler.h"
#include "Managers/SceneManager.h"
#include "Scenes/MainMenuScene.h"
#include "Scenes/Level1.h"
#include "Scenes/Level2.h"
#include "Scenes/Level3.h"
#include "Scenes/LevelSelectorScene.h"
#include "Scenes/DefeatScene.h"
#include "Scenes/VictoryScene.h"
#include "Physics/PhysicsManager.h"



/* Constructures and Deconstructures */
Game::Game() : myWindow(sf::VideoMode(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT), "Jardin - Pangilinan")
{	
	srand(time(NULL));
	myWindow.setFramerateLimit(60);
	//int AirplanePlayer::playerLives = 4;
	TextureManager::getInstance()->loadAll();
	FontManager::getInstance()->loadAll();
	AudioManager::getInstance()->loadAll();
	ApplicationManager::getInstance()->initialize(&myWindow);
	/*EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
		this->*/
	SceneManager::getInstance()->registerScene(new MainMenuScene());

	SceneManager::getInstance()->registerScene(new Level1());
	SceneManager::getInstance()->registerScene(new Level2());
	SceneManager::getInstance()->registerScene(new Level3());
	SceneManager::getInstance()->registerScene(new VictoryScene());
	SceneManager::getInstance()->registerScene(new DefeatScene());
	SceneManager::getInstance()->registerScene(new LevelSelectorScene());

	SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
	//SceneManager::getInstance()->loadScene(SceneManager::LEVEL_SELECTOR_SCENE_NAME);
	//SceneManager::getInstance()->loadScene(SceneManager::VICTORY_MENU_SCENE_NAME);
	//SceneManager::getInstance()->loadScene(SceneManager::DEFEAT_SCENE_NAME);

	//SceneManager::getInstance()->loadScene(SceneManager::LEVEL_1_NAME);
	//SceneManager::getInstance()->loadScene(SceneManager::LEVEL_2_NAME);
	//SceneManager::getInstance()->loadScene(SceneManager::LEVEL_3_NAME);



	//AirplaneSupport* support1 = new AirplaneSupport("AirSupport_1");
	//planeObject->attachChild(support1);
	//support1->setPosition(50, 100);

	//AirplaneSupport* support2 = new AirplaneSupport("AirSupport_2");
	//planeObject->attachChild(support2);
	//support2->setPosition(-50, 100);
	//BGObject* bgObject = new BGObject("BGObject");
	//GameObjectManager::getInstance()->addObject(bgObject);

	//this->planeObject = new AirplanePlayer("PlaneObject");
	//GameObjectManager::getInstance()->addObject(planeObject);

	//HUD* hud = new HUD("HUD");
	//GameObjectManager::getInstance()->addObject(hud);

	//srand(time(NULL)); // controls randomness of the enemy spawns
	//EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
	//EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(5, "SwarmHandler", enemiesManager, 2); 
	//// last parameter for the EnemySwarmHandler is for the enemy type from range of 1 - 3
	//enemiesManager->attachComponent(swarmHandler);
	//GameObjectManager::getInstance()->addObject(enemiesManager);
	/*soundBuffer = AudioManager::getInstance()->getBuffer("jump");
	sound.setBuffer(*soundBuffer);*/

	// for JSON
	/*dota = new DOTA("Dota");
	GameObjectManager::getInstance()->addObject(dota);*/



	/*MainMenuScreen* mainMenuScreen = new MainMenuScreen("MainMenuScreen");
	GameObjectManager::getInstance()->addObject(mainMenuScreen);*/
}

/* Public Functions */

void Game::Run()
{
	sf::Clock		clock;
	sf::Time		timeSinceLastUpdate = sf::Time::Zero;

	while (myWindow.isOpen()) {
		ProcessEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			ProcessEvents();
			Update(TimePerFrame);
		}
		Render();
		SceneManager::getInstance()->checkLoadScene();
	}
}

/* Private Functions */
void Game::ProcessEvents()
{
	sf::Event event;
	while (this->myWindow.pollEvent(event)) {
		switch (event.type) {
		/* Close Window */
		case sf::Event::Closed:
			this->myWindow.close();
			break;

		default:
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
				//GameObjectManager::getInstance()->addObject(new EnemyDino("EnemyDino"));
				//this->planeObject->setEnabled(!this->planeObject->isEnabled());
				//sound.play();
			}
			
			GameObjectManager::getInstance()->processInput(event);
			break;
		}
	}
}

void Game::Update(sf::Time deltaTime)
{
	if (!ApplicationManager::getInstance()->isPaused()) {
		GameObjectManager::getInstance()->update(deltaTime);
	}

}

void Game::Render()
{
	this->myWindow.clear();
	GameObjectManager::getInstance()->draw(&myWindow);

	this->myWindow.display();
}

//
//void Game::createEntity(std::string key, float x, float y)
//{
//	Entity* entity = new Entity();
//
//	sf::Texture* myTexture;
//	myTexture = TextureManager::getInstance()->GetTexture(key);
//	entity->SetTexture(*myTexture);
//	entity->GetSprite()->setPosition(x, y);
//	entity->rootTexName = key;
//	entity->frames = 7;
//	myEntityList.push_back(entity);
//}


