#ifndef __GLOBALS__
#define __GLOBALS__

#include "conf.h"

class Globals {
	private:
		static Globals *_instance;
		Globals();
		sf::RenderWindow _app;

		// Global variables
		bool _hasAlreadyPlayed;

	public:
		static Globals* getInstance();
		sf::RenderWindow * getApp();

		std::string getVoice(std::string name);
		std::string getMusic(std::string name);
		std::string getFont(std::string name);
		void error(std::string error);

		// Setters
		void setHasAlreadyPlayed(bool val);

		// Getters
		bool getHasAlreadyPlayed();

		/*
		template <typename T>
		std::string toString(T t);
		*/
};

#endif