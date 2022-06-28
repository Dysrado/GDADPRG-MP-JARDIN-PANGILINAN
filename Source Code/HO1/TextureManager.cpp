#include <stddef.h>
#include <iostream>
#include "TextureManager.h"

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance() {
	if (sharedInstance == NULL) {
		sharedInstance = new TextureManager();
	}
	return sharedInstance;
}


void TextureManager::loadAll() {
	// Loads all of the Textures
	loadTexture("ui_bg", "Media/Textures/UI/f2.png");
	loadTexture("btn_normal", "Media/Textures/UI/b_normal.png");
	loadTexture("btn_pressed", "Media/Textures/UI/b_pressed.png");
	loadTexture("bar", "Media/Textures/UI/bar_3.png");
	loadTexture("dino_sheet", "Media/Textures/Spritesheet/dino_final_sheet.png");
	loadTexture("coin", "Media/Textures/Spritesheet/coin_sheet.png");
	loadTexture("ground", "Media/Textures/Dino/ground.png");
	loadTexture("ground2", "Media/Textures/Dino/ground2.png");
	loadTexture("ground3", "Media/Textures/Dino/ground3.png");
	loadTexture("mainMenu", "Media/Textures/Dino/MainMenu.png");
	loadTexture("dino", "Media/Textures/Dino/dino-idle.png");
	loadTexture("victory", "Media/Textures/Dino/Victory.png");
	loadTexture("heart", "Media/Textures/UI/bigHeart.png");
	loadTexture("black", "Media/Textures/Dino/LevelSelect.png");
	loadTexture("gameover", "Media/Textures/Dino/game-over.png");
	loadTexture("gray", "Media/Textures/Dino/gray.png");

	// Sets the backgrounds to repeated to make it look seamless
	sf::Texture* bgTex;
	bgTex = GetTexture("ground");
	bgTex->setRepeated(true);
	sf::Texture* bgTex2;
	bgTex = GetTexture("ground2");
	bgTex->setRepeated(true);
	sf::Texture* bgTex3;
	bgTex = GetTexture("ground3");
	bgTex->setRepeated(true);
	
}

void TextureManager::loadTexture(std::string key, std::string path) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

sf::Texture* TextureManager::GetTexture(std::string key) {
	if(textureMap[key] != NULL){ // Finds the texture in the texture HashMap
		return textureMap[key];
	}
	else {
		std::cout << "No texture found for " << key << std::endl;
		return NULL;
	}

}