#pragma once

#include "../AGameObject.h"
#include "../UI/UIButton.h"
#include "../UI/UIText.h"

class MainMenuScreen : public AGameObject, public ButtonListener
{
public:
	MainMenuScreen(std::string name);
	~MainMenuScreen();
	void initialize();

private:
	UIButton* button1;
	UIButton* button2;
	UIText* button_1text;
	UIText* button_2text;

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);
};

