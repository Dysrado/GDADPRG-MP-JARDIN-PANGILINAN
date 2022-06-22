#pragma once

#include "../AGameObject.h"
#include "../UI/UIButton.h"
#include "../UI/UIText.h"

class VictoryScreen : public AGameObject, public ButtonListener
{
public:
	VictoryScreen(std::string name);
	~VictoryScreen();
	void initialize();

private:
	UIButton* button1;
	UIButton* button2;
	UIText* button_1text;
	UIText* button_2text;

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);
};

