#ifndef __INITIAL_MENU__
#define __INITIAL_MENU__

#include "Menu.h"
#include "StateManager.h"

class InitialMenu : public Menu {
	private:
		static InitialMenu *_instance;
		InitialMenu();

		// Redefinition des methodes virtuelles de Menu
		std::vector<std::string> initOptions();
		std::vector<std::string> initOptionsVoices();

	public:
		static InitialMenu* getInstance(bool reinit = false);

		// Surcharge des methodes de Menu
		void simpleEvents(const sf::Event &event);
};

#endif