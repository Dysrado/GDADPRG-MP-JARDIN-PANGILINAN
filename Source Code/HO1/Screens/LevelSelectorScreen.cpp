#include "LevelSelectorScreen.h"
#include "../TextureManager.h"
#include "../Game.h"
#include "../Components/Renderer.h"
#include "../Managers/ApplicationManager.h"
#include "../Managers/SceneManager.h"

LevelSelectorScreen::LevelSelectorScreen(std::string name) : AGameObject(name), ButtonListener()
{
}

LevelSelectorScreen::~LevelSelectorScreen()
{
	AGameObject::~AGameObject();
}

void LevelSelectorScreen::initialize()
{
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("black"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("LevelSelect");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
	
	sf::Texture* btnNormal = TextureManager::getInstance()->GetTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->GetTexture("btn_pressed");

	this->button1 = new UIButton("button_1", btnNormal, btnPressed);
	this->attachChild(this->button1);
	button1->setPosition(-200, 0);
	button1->getTransformable()->setScale(0.7f, 0.7f);


	this->button_1text = new UIText("text_1");
	this->button1->attachChild(button_1text);
	this->button_1text->setPosition(0, -20);
	this->button_1text->setSize(64);
	button_1text->setText("L1");
	this->button1->setButtonListener(this);

	this->button2 = new UIButton("button_2", btnNormal, btnPressed);
	this->attachChild(this->button2);
	
	button2->getTransformable()->setScale(0.7f, 0.7f);

	this->button_2text = new UIText("text_2");
	this->button2->attachChild(button_2text);
	this->button_2text->setPosition(0, -20);
	this->button_2text->setSize(64);
	button_2text->setText("L2");
	this->button2->setButtonListener(this);
	
	this->button3 = new UIButton("button_3", btnNormal, btnPressed);
	this->attachChild(this->button3);
	button3->setPosition(200, 0);
	button3->getTransformable()->setScale(0.7f, 0.7f);

	this->button_3text = new UIText("text_3");
	this->button3->attachChild(button_3text);
	this->button_3text->setPosition(0, -20);
	this->button_3text->setSize(64);
	button_3text->setText("L3");
	this->button3->setButtonListener(this);

	this->button4 = new UIButton("button_4", btnNormal, btnPressed);
	this->attachChild(this->button4);
	button4->setPosition(0, 150);
	button4->getTransformable()->setScale(0.7f, 0.7f);

	this->button_4text = new UIText("text_4");
	this->button4->attachChild(button_4text);
	this->button_4text->setPosition(0, -20);
	this->button_4text->setSize(64);
	button_4text->setText("EXIT");
	this->button4->setButtonListener(this);
	if (music.openFromFile("Media/Audio/LevelSelectBGM.ogg"))
		music.setVolume(5.f);
	music.play();
	music.setLoop(true);
}

void LevelSelectorScreen::onButtonClick(UIButton* button)
{
	if (button->getName() == "button_1") {
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_1_NAME);
	}
	else if (button->getName() == "button_2") {
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_2_NAME);
	}
	else if (button->getName() == "button_3") {
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_3_NAME);
	}
	else if (button->getName() == "button_4") {
		SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
	}
}

void LevelSelectorScreen::onButtonReleased(UIButton* button)
{
}
