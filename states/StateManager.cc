#include "StateManager.h"

using namespace std;

State* StateManager::currentState = NULL;

void StateManager::enterState(StateName name) {
	switch(name) {
		case MAINMENU:
			currentState = MainMenu::getInstance();
			break;
		case GAMEPLAY:
			currentState = Gameplay::getInstance();
			break;
		default:
			cerr << "StateName " << name << " doesn't exist!" << endl;
			break;
	}
}

State* StateManager::getCurrentState() {
	return currentState;
}