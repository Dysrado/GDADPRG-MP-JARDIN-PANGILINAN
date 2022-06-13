#include "Entity.h"

Entity::Entity() {};

void Entity::SetTexture(sf::Texture texture)
{
	myTexture = texture;
	mySprite.setTexture(myTexture);
}

sf::Sprite* Entity::GetSprite()
{
	return &mySprite;
}

void Entity::move(float moveAmt)
{
	mySprite.move(sf::Vector2f(moveAmt, 0));
}

void Entity::update()
{
	if (clock.getElapsedTime().asMicroseconds() > 100) {
		sf::Texture* texture;
		std::string key = rootTexName + std::to_string(ctr);
		texture = TextureManager::getInstance()->GetTexture(key);
		SetTexture(*texture);

		ctr++;
		ctr %= frames + 1;
		clock.restart();
	}
}


