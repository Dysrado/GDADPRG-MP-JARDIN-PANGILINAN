#include "BGMovement.h"
#include "PlayerInputController.h"
#include "EnemyInputController.h"
#include "../GoalPoint.h"
#include "../Managers/ApplicationManager.h"
#include "../UI/VictoryMenu.h"

BGMovement::BGMovement(std::string name) : AComponent(name, Script)
{
	std::cout << "Goal Created\n";
	GoalPoint* goal = new GoalPoint("goal");
	GameObjectManager::getInstance()->addObject(goal);
}

bool BGMovement::goalPoint()
{
	if (displacement >= GOAL_POINT) {
		std::cout << "YOU WIN!!!\n";
		return true;
	}
		//ApplicationManager::getInstance()->pauseApplication();\
	return false;
	return false;
}
void BGMovement::perform()
{
	BGObject* bgObject = (BGObject*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)bgObject->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* bgObjectTransform = bgObject->getTransformable();
	//displacement = inputController->displacement
	if (bgObjectTransform == NULL) {
		std::cout << "bgObjectTransform not found" << std::endl;
	}
	else {
		sf::Vector2f offset(0.f, 0.f);

		if (inputController->isLeft() && displacement > 0) {
			displacement -= 0.01f;
			offset.x += this->SPEED_MULTIPLIER;
			bgObjectTransform->move(offset * deltaTime.asSeconds());
		}
		else if (inputController->isRight()) {
			displacement += 0.01f;
			offset.x -= this->SPEED_MULTIPLIER;
			bgObjectTransform->move(offset * deltaTime.asSeconds());
		}

		/*sf::Vector2f localPos = bgObjectTransform->getPosition();
		if (localPos.x >= Game::WINDOW_WIDTH) {
			bgObjectTransform->setPosition(0, 0);
		}*/
	}
	//levelCleared = this->goalPoint();
	if (displacement >= GOAL_POINT) {
		std::cout << "YOU WIN!!!\n";
		VictoryMenu* victoryMenu = new VictoryMenu("VictoryMenu");
		GameObjectManager::getInstance()->addObject(victoryMenu);
		ApplicationManager::getInstance()->pauseApplication();
	}
}

float BGMovement::getDisplacement()
{
	return displacement;
}


