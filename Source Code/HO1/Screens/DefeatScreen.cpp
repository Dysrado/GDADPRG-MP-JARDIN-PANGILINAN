#include "DefeatScreen.h"
#include "../TextureManager.h"
#include "../Game.h"
#include "../Components/Renderer.h"
#include "../Managers/ApplicationManager.h"
#include "../Managers/SceneManager.h"

DefeatScreen::DefeatScreen(std::string name) : AGameObject(name), ButtonListener()
{
}

DefeatScreen::~DefeatScreen()
{
	AGameObject::~AGameObject();

}

void DefeatScreen::initialize()
{
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("gameover"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("defeatScreen");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);


	// scales the whole menu
	//this->getTransformable()->setScale(0.5f, 0.5f);

	sf::Texture* btnNormal = TextureManager::getInstance()->GetTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->GetTexture("btn_pressed");

	this->button1 = new UIButton("button_1", btnNormal, btnPressed);
	this->attachChild(this->button1);
	button1->setPosition(-150, 150);
	button1->getTransformable()->setScale(0.7f, 0.7f);


	this->button_1text = new UIText("text_1");
	this->button1->attachChild(button_1text);
	this->button_1text->setPosition(0, -20);
	this->button_1text->setSize(64);
	button_1text->setText("RETRY");
	this->button1->setButtonListener(this);

	this->button2 = new UIButton("button_2", btnNormal, btnPressed);
	this->attachChild(this->button2);
	button2->setPosition(150, 150);
	button2->getTransformable()->setScale(0.7f, 0.7f);

	this->button_2text = new UIText("text_2");
	this->button2->attachChild(button_2text);
	this->button_2text->setPosition(0, -20);
	this->button_2text->setSize(64);
	button_2text->setText("EXIT");
	this->button2->setButtonListener(this);
}

void DefeatScreen::onButtonClick(UIButton* button)
{
	if (button->getName() == "button_1") {
		SceneManager::getInstance()->unloadScene();
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_SELECTOR_SCENE_NAME);
		SceneManager::getInstance()->resetLives();

	}
	else if (button->getName() == "button_2") {
		SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
	}
}

void DefeatScreen::onButtonReleased(UIButton* button)
{
}
