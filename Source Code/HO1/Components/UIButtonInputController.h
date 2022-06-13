#pragma once
#include "GenericInputController.h"
#include "../UI/ButtonListener.h"
#include "../UI/UIButton.h"
class UIButtonInputController : public GenericInputController
{
public:
	UIButtonInputController(std::string name, ButtonListener* buttonListener);
	~UIButtonInputController();

	void perform();

private:
	ButtonListener* buttonListener;
	bool pressed = false;
};

