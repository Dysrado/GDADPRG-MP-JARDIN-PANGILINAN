#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

class FontManager : sf::NonCopyable
{
public:
	static FontManager* getInstance();

	void loadAll();
	sf::Font* getFont(std::string);

private:
	FontManager() {};
	static FontManager* sharedInstance;

	void loadFont(std::string, std::string);
	std::unordered_map<std::string, sf::Font*> fontMap;
};

