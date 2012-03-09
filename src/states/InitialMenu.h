#ifndef __INITIAL_MENU__
#define __INITIAL_MENU__

#include "TextMenu.h"
#include "StateManager.h"

class InitialMenu : public TextMenu {
	private:
		static InitialMenu *_instance;
		InitialMenu();

		// Redefinition des methodes virtuelles de Menu
		std::vector<sf::String> initOptions();
		std::vector<std::string> initOptionsVoices();

	public:
		static InitialMenu* getInstance(bool reinit = false);

		// Surcharge des methodes de Menu
		void simpleEvents(const sf::Event &event);
};

#endif