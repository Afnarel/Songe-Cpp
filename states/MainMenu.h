#ifndef __MAIN_MENU__
#define __MAIN_MENU__

#include "Menu.h"
#include "StateManager.h"

class MainMenu : public Menu {
	private:
		static MainMenu *_instance;
		MainMenu();

		// Redefinition des methodes virtuelles de Menu
		std::vector<std::string> initOptions();
		std::vector<std::string> initOptionsVoices();

	public:
		static MainMenu* getInstance(bool reinit = false);

		// Surcharge des methodes de Menu
		void simpleEvents(const sf::Event &event);
};

#endif