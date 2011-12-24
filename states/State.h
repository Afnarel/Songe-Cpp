#ifndef __STATE__
#define __STATE__

#include "../utils/Globals.h"

class State {
	private:
	protected:
		State();
		sf::RenderWindow *_app;
	public:
		virtual void init() = 0;
		virtual void simpleEvents(const sf::Event &event) = 0;
		virtual void complexEvents() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
};

#endif