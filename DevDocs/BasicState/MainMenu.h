#ifndef __MAIN_MENU__
#define __MAIN_MENU__

#include "StateManager.h"

class MainMenu : public State {
	private:
		static MainMenu *_instance;
		MainMenu();

		sf::Font _font;
		sf::Text _text;
	public:
		static MainMenu* getInstance(bool reinit = false);
		void init();
		void simpleEvents(const sf::Event &event);
		void complexEvents();
		void update();
		void render();
};

#endif