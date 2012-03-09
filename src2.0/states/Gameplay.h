#ifndef __GAMEPLAY__
#define __GAMEPLAY__

#include "StateManager.h"

class Gameplay : public State {
	private:
		static Gameplay *_instance;
		Gameplay();

		sf::Font _font;
		sf::Text _text;
	public:
		static Gameplay* getInstance(bool reinit = false);
		void init();
		void reset();
		void onEnter();
		void onLeave();
		void simpleEvents(const sf::Event &event);
		void complexEvents();
		void update();
		void render();
};

#endif