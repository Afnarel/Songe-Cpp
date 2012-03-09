#include "StateManager.h"

using namespace std;

State* StateManager::_currentState = NULL;

void StateManager::enterState(StateName name, bool reinit) {
	if(_currentState != NULL)
		_currentState->onLeave();

	switch(name) {
		case INITIALMENU:
			_currentState = InitialMenu::getInstance(reinit);
			break;
		case MAINMENU:
			_currentState = MainMenu::getInstance(reinit);
			break;
		case CHOICEPERSOMENU:
			_currentState = ChoicePersoMenu::getInstance(reinit);
			break;
		case GAMEPLAY:
			_currentState = Gameplay::getInstance(reinit);
			break;
		default:
			ostringstream oss;
			oss << "StateName " << name << " doesn't exist!";
			Globals::getInstance()->error(oss.str());
			break;
	}
	_currentState->onEnter();
}

State* StateManager::getCurrentState() {
	return _currentState;
}