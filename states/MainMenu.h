#ifndef __MAIN_MENU__
#define __MAIN_MENU__

#include "Menu.h"
#include "StateManager.h"

class MainMenu : public Menu {
	private:
		static MainMenu *_instance;
		MainMenu();

	public:
		static MainMenu* getInstance(bool reinit = false);
};

#endif