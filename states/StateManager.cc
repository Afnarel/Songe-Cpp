#include "StateManager.h"

using namespace std;

State* StateManager::currentState = NULL;

void StateManager::enterState(StateName name) {
	if(currentState != NULL)
		currentState->onLeave();

	switch(name) {
		case MAINMENU:
			currentState = MainMenu::getInstance();
			break;
		case GAMEPLAY:
			currentState = Gameplay::getInstance();
			break;
		default:
			ostringstream oss;
			oss << "StateName " << name << " doesn't exist!";
			Globals::getInstance()->error(oss.str());
			break;
	}
	currentState->onEnter();
}

State* StateManager::getCurrentState() {
	return currentState;
}