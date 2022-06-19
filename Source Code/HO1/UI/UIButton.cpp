#include "UIButton.h"
#include "../TextureManager.h"
#include <iostream>
#include "../Components/Renderer.h"
#include "../Components/UIButtonInputController.h"

UIButton::UIButton(std::string name, sf::Texture* normalTexture, sf::Texture* pressedTexture) : AGameObject(name)
{
	this->normalTexture = normalTexture;
	this->pressedTexture = pressedTexture;
}

UIButton::~UIButton()
{
	AGameObject::~AGameObject();
}

void UIButton::initialize()
{
	this->sprite = new sf::Sprite();
	sprite->setTexture(*this->normalTexture);
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x/2, textureSize.y/2);
	sprite->setScale(3.f,2.f);
	Renderer* renderer = new Renderer("Button");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}

void UIButton::changeButtonToNormal()
{
	this->sprite->setTexture(*this->normalTexture);
}

void UIButton::changeButtonToPressed()
{
	this->sprite->setTexture(*this->pressedTexture);
}

sf::FloatRect UIButton::getLocalBounds()
{
	return this->sprite->getLocalBounds();
}

sf::FloatRect UIButton::getGlobalBounds()
{
	sf::FloatRect bounds = this->sprite->getGlobalBounds();
	
	AGameObject* parentObj = this;
	std::vector<AGameObject*> parentList;
	while (parentObj != NULL) {
		parentList.push_back(parentObj);
		parentObj = parentObj->getParent();
	}

	sf::Transform transform = sf::Transform::Identity;
	int startIdx = parentList.size() - 1;

	for (int i = startIdx; i >= 0; i--) {
		transform = transform * parentList[i]->getTransformable()->getTransform();
	}

	bounds = transform.transformRect(bounds);

	return bounds;
}

void UIButton::setButtonListener(ButtonListener* listener)
{
	this->listener = listener;
	UIButtonInputController* inputController = new UIButtonInputController("UI_InputController", this->listener);
	this->attachComponent(inputController);
}
