#pragma once

#include "../AGameObject.h"
#include "UIButton.h"
#include "UIText.h"

class VictoryMenu : public AGameObject, public ButtonListener
{
public:
	VictoryMenu(std::string name);
	~VictoryMenu();
	void initialize();

private:
	UIButton* buttonYes;
	UIButton* buttonNo;
	UIText* main_text;
	UIText* button_YText;
	UIText* button_NText;

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);

};

