#ifndef __GLOBALS__
#define __GLOBALS__

#include "conf.h"

class Globals {
	private:
		static Globals *_instance;
		Globals();
		sf::RenderWindow _app;

	public:
		static Globals* getInstance();
		sf::RenderWindow * getApp();

		std::string getVoice(std::string name);
		std::string getFont(std::string name);
};

#endif