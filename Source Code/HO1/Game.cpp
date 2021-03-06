// Textures and sfx from https://codeburst.io/create-a-secret-dino-chrome-game-in-1-hour-with-js-and-phaser-3-2caebb1abe2a
// bgm for main menu from https://www.youtube.com/watch?v=jCQ_5Gj6jlg
// bgm for level selection menu from https://www.youtube.com/watch?v=7r0Z3NxhZ10&t=24s
// bgm for level 1 from https://www.youtube.com/watch?v=9BXpRzVBi5s
// bgm for level 2 from https://www.youtube.com/watch?v=zF7Mb6fnfhw
// bgm for level 3 from https://www.youtube.com/watch?v=wDgQdr8ZkTw&t=14s

#include "Game.h"
#include <iostream>

#include "Screens/MainMenuScreen.h"
#include "Managers/FontManager.h"
#include "Managers/ApplicationManager.h"
#include "UI/HUD.h"
#include "EnemyCactus.h"
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


/* Constructure */
Game::Game() : myWindow(sf::VideoMode(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT), "Dino++")
{	
	srand(time(NULL));
	myWindow.setFramerateLimit(60);

	// Loads all of the needed media files
	TextureManager::getInstance()->loadAll();
	FontManager::getInstance()->loadAll();
	AudioManager::getInstance()->loadAll();
	ApplicationManager::getInstance()->initialize(&myWindow);

	// Registers all of the Scenes
	SceneManager::getInstance()->registerScene(new MainMenuScene());
	SceneManager::getInstance()->registerScene(new Level1());
	SceneManager::getInstance()->registerScene(new Level2());
	SceneManager::getInstance()->registerScene(new Level3());
	SceneManager::getInstance()->registerScene(new VictoryScene());
	SceneManager::getInstance()->registerScene(new DefeatScene());
	SceneManager::getInstance()->registerScene(new LevelSelectorScene());

	// Loads the Main Menu
	SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
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




