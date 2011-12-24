#ifndef __STATE_MANAGER__
#define __STATE_MANAGER__

#include "State.h"
#include "MainMenu.h"
#include "Gameplay.h"

class StateManager {
	private:
		static State* currentState;

	public:
		enum StateName {
			MAINMENU,
			GAMEPLAY
		};

		static void enterState(StateName name);
		static State* getCurrentState();
};

#endif