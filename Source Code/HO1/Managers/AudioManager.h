#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>

class AudioManager
{
public:
	static AudioManager* getInstance();

	void loadAll();
	sf::SoundBuffer* getBuffer(std::string);

private:
	AudioManager() {};
	AudioManager(AudioManager const&) {};

	AudioManager& operator=(AudioManager const&) {};
	static AudioManager* sharedInstance;

	void loadBuffer(std::string, std::string);

	std::unordered_map<std::string, sf::SoundBuffer*> bufferMap;

};

