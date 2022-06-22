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

void TextureManager::TestFunction() {
	std::cout << "Hellow mr simpleton\n";
}

void TextureManager::loadAll() {
	//loadTexture("desert_bg", "Media/Textures/Desert.png");
	//loadTexture("eagle", "Media/Textures/Eagle.png");
	//loadTexture("raptor", "Media/Textures/Raptor.png");
	loadTexture("ui_bg", "Media/Textures/UI/f2.png");
	loadTexture("btn_normal", "Media/Textures/UI/b_normal.png");
	loadTexture("btn_pressed", "Media/Textures/UI/b_pressed.png");
	loadTexture("bar", "Media/Textures/UI/bar_3.png");
	//loadTexture("avenger", "Media/Textures/Avenger.png");
	//loadTexture("dota2_sheet", "Media/Textures/Dota2 Atlas.png");
	loadTexture("dino_sheet", "Media/Textures/Spritesheet/dino_final_sheet.png");
	loadTexture("coin", "Media/Textures/Spritesheet/coin_sheet.png");
	loadTexture("ground", "Media/Textures/Dino/ground.png");
	loadTexture("ground2", "Media/Textures/Dino/ground2.png");
	loadTexture("ground3", "Media/Textures/Dino/ground3.png");
	loadTexture("mainMenu", "Media/Textures/Dino/MainMenu.png");
	loadTexture("dino", "Media/Textures/Dino/dino-idle.png");
	loadTexture("heart", "Media/Textures/UI/bigHeart.png");
	sf::Texture* bgTex;
	bgTex = GetTexture("ground");
	bgTex->setRepeated(true);
	
}

void TextureManager::loadTexture(std::string key, std::string path) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

sf::Texture* TextureManager::GetTexture(std::string key) {
	if(textureMap[key] != NULL){
		return textureMap[key];
	}
	else {
		std::cout << "No texture found for " << key << std::endl;
		return NULL;
	}

}