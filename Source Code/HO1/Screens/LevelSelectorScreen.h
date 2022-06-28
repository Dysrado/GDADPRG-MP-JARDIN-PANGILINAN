#pragma once

#include "../AGameObject.h"
#include "../UI/UIButton.h"
#include "../UI/UIText.h"
#include "../Managers/AudioManager.h"
class LevelSelectorScreen : public AGameObject, public ButtonListener
{
public:
	LevelSelectorScreen(std::string name);
	~LevelSelectorScreen();
	void initialize();

private:
	UIButton* button1;
	UIButton* button2;
	UIButton* button3;
	UIButton* button4;
	UIText* button_1text;
	UIText* button_2text;
	UIText* button_3text;
	UIText* button_4text;

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);
	sf::Music music;
};



