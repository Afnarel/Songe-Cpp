#ifndef __MENU__
#define __MENU__

#include "State.h"

class Menu : public State {
	protected:
		Menu();
	public:
		void init();
		void simpleEvents(const sf::Event &event);
		void complexEvents();
		void update();
		void render();
};

#endif