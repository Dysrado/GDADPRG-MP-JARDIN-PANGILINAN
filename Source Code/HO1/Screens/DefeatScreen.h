#pragma once
#include "../AGameObject.h"
#include "../UI/UIButton.h"
#include "../UI/UIText.h"
class DefeatScreen : public AGameObject, public ButtonListener
{
public:
	DefeatScreen(std::string name);
	~DefeatScreen();
	void initialize();

private:
	UIButton* button1;
	UIButton* button2;
	UIText* button_1text;
	UIText* button_2text;

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);
};

