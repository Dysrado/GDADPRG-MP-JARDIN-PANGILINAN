#include "HUD.h"
#include "../TextureManager.h"
#include "../Components/Renderer.h"
#include "../Game.h"
#include "../Managers/ApplicationManager.h"
#include "PauseMenu.h"
#include "../Components/BGMovement.h"

HUD::HUD(std::string name) : AGameObject(name), ButtonListener()
{
}

HUD::~HUD()
{
	AGameObject::~AGameObject();
}

void HUD::initialize()
{
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("bar"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x, textureSize.y);

	Renderer* renderer = new Renderer("HUD");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->setPosition(Game::WINDOW_WIDTH - 10, Game::WINDOW_HEIGHT - 10);

	sf::Texture* btnNormal = TextureManager::getInstance()->GetTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->GetTexture("btn_pressed");

	this->quitButton = new UIButton("button_quit", btnNormal, btnPressed);
	this->attachChild(this->quitButton);
	quitButton->setPosition(-70, -35);
	quitButton->getTransformable()->setScale(0.4f, 0.4f);


	this->quitButton_text = new UIText("text_quit");
	this->quitButton->attachChild(quitButton_text);
	this->quitButton_text->setPosition(0, -0);
	this->quitButton_text->setSize(40);
	quitButton_text->setText("QUIT");
	this->quitButton->setButtonListener(this);

	distance_text = new UIText("distance");
	this->attachChild(distance_text);
	distance_text->setPosition(-Game::WINDOW_WIDTH + 145,-25);

	PauseMenu* pauseMenu = new PauseMenu("PauseMenu");
	GameObjectManager::getInstance()->addObject(pauseMenu);
	GameObjectManager::getInstance()->findObjectByName("PauseMenu")->setEnabled(false);
}

void HUD::update(sf::Time deltaTime)
{
	BGMovement* movement = (BGMovement*)GameObjectManager::getInstance()->findObjectByName("BGObject")->findComponentByName("myBGMovement");
	float displacement = movement->getDisplacement();

	distance_text->setText("M: " + std::to_string(displacement));

	AGameObject::update(deltaTime);
}

void HUD::onButtonClick(UIButton* button)
{
	if (!ApplicationManager::getInstance()->isPaused()) {
		//std::cout << button->getName() << " has been pressed" << std::endl;
		GameObjectManager::getInstance()->findObjectByName("PauseMenu")->setEnabled(true);
		ApplicationManager::getInstance()->pauseApplication();
	}
}

void HUD::onButtonReleased(UIButton* button)
{
	//std::cout << button->getName() << std::endl;
}
