#pragma once
#include<SFML/Graphics.hpp>
#include "TextureManager.h"

class Entity
{
public:
	Entity();
	void SetTexture(sf::Texture texture);
	sf::Sprite* GetSprite();
	void move(float moveAmt);

	void update();
	std::string rootTexName;
	int frames;

private:
	sf::Texture myTexture;
	sf::Sprite mySprite;

	sf::Clock clock;
	int ctr = 0;
};

