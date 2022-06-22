#pragma once
#include "../AGameObject.h"
class PlayerHearts :
    public AGameObject
{
public:
	PlayerHearts(std::string name);
	~PlayerHearts();
	void initialize();
private:
	sf::Texture* normalTexture;
	sf::Texture* pressedTexture;
	sf::Sprite* sprite;
};

