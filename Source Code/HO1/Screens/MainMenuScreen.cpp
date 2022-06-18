#include "MainMenuScreen.h"
#include "../TextureManager.h"
#include "../Game.h"
#include "../Components/Renderer.h"

MainMenuScreen::MainMenuScreen(std::string name) : AGameObject(name), ButtonListener()
{

}

MainMenuScreen::~MainMenuScreen()
{
	/*delete this->button1;
	delete this->button_1text;
	delete this->button2;
	delete this->button_2text;*/
	AGameObject::~AGameObject();
}

void MainMenuScreen::initialize()
{
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("ui_bg"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x/2, textureSize.y/2);

	Renderer* renderer = new Renderer("MainMenuScreen");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->setPosition(Game::WINDOW_WIDTH/2, Game::WINDOW_HEIGHT/2);


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
	button_1text->setText("OPEN");
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

void MainMenuScreen::onButtonClick(UIButton* button)
{
	std::cout << button->getName() << std::endl;
}

void MainMenuScreen::onButtonReleased(UIButton* button)
{
	std::cout << button->getName() << std::endl;
}
