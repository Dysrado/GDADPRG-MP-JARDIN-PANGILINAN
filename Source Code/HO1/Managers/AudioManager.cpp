#include "AudioManager.h"
#include <stddef.h>
#include <iostream>

AudioManager* AudioManager::sharedInstance = NULL;

AudioManager* AudioManager::getInstance() {
	if (sharedInstance == NULL) {
		sharedInstance = new AudioManager();
	}
	return sharedInstance;
}

void AudioManager::loadAll() {
	loadBuffer("hit", "Media/Audio/hit.wav");
	loadBuffer("jump", "Media/Audio/jump.wav");
	loadBuffer("reach", "Media/Audio/reach.wav");
}

void AudioManager::loadBuffer(std::string key, std::string path) {
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	buffer->loadFromFile(path);
	bufferMap[key] = buffer;
}

sf::SoundBuffer* AudioManager::getBuffer(std::string key) {
	if (bufferMap[key] != NULL) {
		return bufferMap[key];
	}
	else {
		std::cout << "No buffer for " << key;
		return NULL;
	}
}
