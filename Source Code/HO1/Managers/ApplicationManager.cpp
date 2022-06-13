#include "ApplicationManager.h"


ApplicationManager* ApplicationManager::sharedInstance = NULL;

void ApplicationManager::initialize(sf::RenderWindow* window)
{
	this->window = window;
}

ApplicationManager* ApplicationManager::getInstance()
{
	if (sharedInstance == NULL) {
		sharedInstance = new ApplicationManager();
	}

	return sharedInstance;
}

void ApplicationManager::applicationQuit()
{
	this->window->close();
}

void ApplicationManager::pauseApplication()
{
	this->state = GameState::Paused;
}

void ApplicationManager::resumeApplication()
{
	this->state = GameState::Running;
}

bool ApplicationManager::isPaused()
{
	return this->state == GameState::Paused;
}

ApplicationManager::~ApplicationManager()
{
	delete this->window;
}
