#pragma once

#include "../AGameObject.h"
#include "UIButton.h"
#include "UIText.h"
#include "../Components/BGMovement.h"

class HUD : public AGameObject, public ButtonListener
{
public:
	HUD(std::string name);
	~HUD();
	void initialize();
	void update(sf::Time deltaTime);
	void levelCleared();
private:
	BGMovement* movement;
	UIButton* quitButton;
	UIText* quitButton_text;
	UIText* distance_text;

	UIText* score_text;

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);

};

