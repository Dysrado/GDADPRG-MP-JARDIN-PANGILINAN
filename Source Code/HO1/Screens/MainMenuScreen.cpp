#include "MainMenuScreen.h"
#include "../TextureManager.h"
#include "../Game.h"
#include "../Components/Renderer.h"
#include "../Managers/ApplicationManager.h"
#include "../Managers/SceneManager.h"
#include "../UI/PauseMenu.h"
#include "../Managers/GameObjectManager.h"

MainMenuScreen::MainMenuScreen(std::string name) : AGameObject(name), ButtonListener()
{

}

MainMenuScreen::~MainMenuScreen()
{
	
	AGameObject::~AGameObject();
}

void MainMenuScreen::initialize()
{
	

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("mainMenu"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x/2, textureSize.y/2);

	Renderer* renderer = new Renderer("MainMenuScreen");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->setPosition(Game::WINDOW_WIDTH/2, Game::WINDOW_HEIGHT/2);

	sf::Texture* btnNormal = TextureManager::getInstance()->GetTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->GetTexture("btn_pressed");

	this->button1 = new UIButton("button_1", btnNormal, btnPressed);
	this->attachChild(this->button1);
	button1->setPosition(-150, 50);
	button1->getTransformable()->setScale(0.7f, 0.7f);


	this->button_1text = new UIText("text_1"); 
	this->button1->attachChild(button_1text);
	this->button_1text->setPosition(0, -20);
	this->button_1text->setSize(64);
	button_1text->setText("PLAY");
	this->button1->setButtonListener(this);
	
	this->button2 = new UIButton("button_2", btnNormal, btnPressed);
	this->attachChild(this->button2);
	button2->setPosition(150, 50);
	button2->getTransformable()->setScale(0.7f, 0.7f);

	this->button_2text = new UIText("text_2"); 
	this->button2->attachChild(button_2text);
	this->button_2text->setPosition(0, -20);
	this->button_2text->setSize(64);
	button_2text->setText("EXIT");
	this->button2->setButtonListener(this);
	if (music.openFromFile("Media/Audio/Title.ogg"))
		music.setVolume(5.f);
	music.play();
	PauseMenu* pauseMenu = new PauseMenu("PauseMenu");
	GameObjectManager::getInstance()->addObject(pauseMenu);
	GameObjectManager::getInstance()->findObjectByName("PauseMenu")->setEnabled(false);
}

void MainMenuScreen::onButtonClick(UIButton* button)
{
	if (button->getName() == "button_2") { // Quits the game
		
		//GameObjectManager::getInstance()->findObjectByName("PauseMenu2")->setEnabled(false);
		GameObjectManager::getInstance()->findObjectByName("PauseMenu")->setEnabled(true);

	}
	else if (button->getName() == "button_1") { // Goes to the Level Selector Scene
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_SELECTOR_SCENE_NAME);
		music.stop();
	}
}

void MainMenuScreen::onButtonReleased(UIButton* button)
{
}
