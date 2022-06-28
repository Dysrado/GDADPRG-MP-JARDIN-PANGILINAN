#include "DefeatMenu.h"


#include "../TextureManager.h"
#include "../Game.h"
#include "../Components/Renderer.h"
#include "../Managers/ApplicationManager.h"
#include "../Managers/SceneManager.h"


DefeatMenu::DefeatMenu(std::string name) : AGameObject(name), ButtonListener()
{
}

DefeatMenu::~DefeatMenu()
{
	AGameObject::~AGameObject();
}

void DefeatMenu::initialize()
{
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->GetTexture("ui_bg"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("DefeatMenu");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);


	// scales the whole menu
	//this->getTransformable()->setScale(0.5f, 0.5f);

	sf::Texture* btnNormal = TextureManager::getInstance()->GetTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->GetTexture("btn_pressed");

	this->buttonYes = new UIButton("button_yes", btnNormal, btnPressed);
	this->attachChild(this->buttonYes);
	buttonYes->setPosition(-150, 150);
	buttonYes->getTransformable()->setScale(0.7f, 0.7f);


	this->button_YText = new UIText("text_yes");
	this->buttonYes->attachChild(button_YText);
	this->button_YText->setPosition(0, -20);
	this->button_YText->setSize(64);
	button_YText->setText("RETRY");
	this->buttonYes->setButtonListener(this);

	this->buttonNo = new UIButton("button_no", btnNormal, btnPressed);
	this->attachChild(this->buttonNo);
	buttonNo->setPosition(150, 150);
	buttonNo->getTransformable()->setScale(0.7f, 0.7f);

	this->button_NText = new UIText("text_no");
	this->buttonNo->attachChild(button_NText);
	this->button_NText->setPosition(0, -20);
	this->button_NText->setSize(64);
	button_NText->setText("EXIT");
	this->buttonNo->setButtonListener(this);

	this->main_text = new UIText("defeat_text");
	this->attachChild(main_text);
	this->main_text->setPosition(0, -20);
	this->main_text->setSize(50);
	main_text->setText("LEVEL FAILED");
}

void DefeatMenu::onButtonClick(UIButton* button)
{
	if (button->getName() == "button_yes") {
		/*std::cout << "Moved to level 2\n";

	//SceneManager::getInstance()->unloadScene();*/
		if (SceneManager::getInstance()->getActiveSceneName() == "Level1") {
			SceneManager::getInstance()->unloadScene();
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL_1_NAME);
		}
		else if (SceneManager::getInstance()->getActiveSceneName() == "Level2") {
			SceneManager::getInstance()->unloadScene();
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL_2_NAME);
		}
		else if (SceneManager::getInstance()->getActiveSceneName() == "Level3") {
			SceneManager::getInstance()->unloadScene();
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL_3_NAME);
		}

	}
	else if (button->getName() == "button_no") {
		SceneManager::getInstance()->loadScene(SceneManager::LEVEL_SELECTOR_SCENE_NAME);
	}
}

void DefeatMenu::onButtonReleased(UIButton* button)
{
}