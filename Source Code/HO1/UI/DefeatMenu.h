
#pragma once

#include "../AGameObject.h"
#include "UIButton.h"
#include "UIText.h"

class DefeatMenu : public AGameObject, public ButtonListener
{
public:
	DefeatMenu(std::string name);
	~DefeatMenu();
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
