#ifndef __MENU__
#define __MENU__

#include "State.h"

class Menu : public State {
	protected:
		Menu(std::string title, std::string titleVoice, std::string _musicFile);

		sf::Font _font;

		int _selected;
		int _itemWidth;
		int _selectedItemWidth;

		// Background music
		std::string _musicFile;
		sf::Music _music;

		// Title
		std::string _title;
		std::string _titleVoice;
		sf::Music _titleSound;

		// Options
		std::vector<std::string> _options;
		std::vector<std::string> _optionsVoices;
		std::vector<sf::Music*> _optionsSounds;

		// Methodes virtuelles
		virtual std::vector<std::string> initOptions() = 0;
		virtual std::vector<std::string> initOptionsVoices() = 0;

	public:
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