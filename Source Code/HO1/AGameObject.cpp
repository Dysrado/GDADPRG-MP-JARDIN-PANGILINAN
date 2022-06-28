#include "AGameObject.h"
#include "Components/GenericInputController.h"
#include "Components/Renderer.h"

AGameObject::AGameObject(std::string name)
{
	this->name = name;
}

AGameObject::~AGameObject()
{
	
	for (int i = 0; i < this->componentList.size(); i++) {
		delete this->componentList[i];
	}

	for (int i = 0; i < this->childList.size(); i++) {
		delete this->childList[i];
	}

	this->componentList.clear();
	this->componentList.shrink_to_fit();

	this->childList.clear();
	this->childList.shrink_to_fit();

	if (this->mParent != NULL) {
		this->mParent = NULL;
	}
}

void AGameObject::draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates)
{
	if (!this->isEnabled()) {
		return;
	}

	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Renderer);

	renderStates.transform = renderStates.transform * this->transformable.getTransform();

	for (int j = 0; j < componentList.size(); j++) {
		Renderer* renderer = (Renderer*)componentList[j];
		renderer->assignTargetWindow(targetWindow);
		renderer->setRenderStates(renderStates);
		renderer->perform();
	}

	for (int i = 0; i < this->childList.size(); i++) {
		AGameObject* child = this->childList[i];
		child->draw(targetWindow, renderStates);
	}
}

std::string AGameObject::getName()
{
	return this->name;
}

void AGameObject::attachChild(AGameObject* child)
{
	this->childList.push_back(child); 
	child->setParent(this);
	child->initialize();
}

void AGameObject::detachChild(AGameObject* child)
{
	int index = -1;
	
	for (int i = 0; i < this->childList.size(); i++) {
		index = i;
		break;
	}

	if (index != -1) {
		this->childList.erase(this->childList.begin() + index);
	}
}

void AGameObject::setPosition(float x, float y)
{
	this->transformable.setPosition(x, y);
}

void AGameObject::setEnabled(bool flag)
{
	this->enabled = flag;
}

bool AGameObject::isEnabled()
{
	return this->enabled;
}


void AGameObject::processInput(sf::Event ev) {
	// process input here
	if (!this->isEnabled()) {
		return;
	}

	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Input);
	for (int j = 0; j < componentList.size(); j++) {
		((GenericInputController*)componentList[j])->assignEvent(ev);
		componentList[j]->perform();
	}

	for (int i = 0; i < this->childList.size(); i++) {
		childList[i]->processInput(ev);
	}
}

void AGameObject::update(sf::Time deltaTime) {
	if (!this->isEnabled()) {
		return;
	}

	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Script);

	for (int j = 0; j < componentList.size(); j++) {
		componentList[j]->setDeltaTime(deltaTime);
		componentList[j]->perform();
	}

	for (int i = 0; i < this->childList.size(); i++) {
		childList[i]->update(deltaTime);
	}
}

void AGameObject::attachComponent(AComponent* component) {
	this->componentList.push_back(component);
	component->attachOwner(this);
}

void AGameObject::detachComponent(AComponent* component) {
	int index = -1;
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i] == component) {
			index = i;
			this->componentList[i]->detatchOwner();
			break;
		}
	}

	if (index != -1) {
		this->componentList.erase(this->componentList.begin() + index);
	}
}

AComponent* AGameObject::findComponentByName(std::string name)
{
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getName() == name) {
			return this->componentList[i];
		}
	}
	return NULL;
}

AComponent* AGameObject::findComponentOfType(AComponent::ComponentType type, std::string name)
{
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getName() == name && this->componentList[i]->getType() == type) {
			return this->componentList[i];
		}
	}
	return NULL;
}

std::vector<AComponent*> AGameObject::getComponentsOfType(AComponent::ComponentType type)
{
	std::vector<AComponent*> foundList;
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getType() == type) {
			foundList.push_back(this->componentList[i]);
		}
	}
	return foundList;
}




sf::Transformable* AGameObject::getTransformable() {
	return &this->transformable;
}

sf::Transform AGameObject::getGlobalTransform()
{
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
	return transform;
}

AGameObject* AGameObject::getParent()
{
	return this->mParent;
}

//sf::Transformable AGameObject::getTransform()
//{
//	return this->sprite;
//}

void AGameObject::setParent(AGameObject* parent)
{
	this->mParent = parent;
}



