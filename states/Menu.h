#ifndef __MENU__
#define __MENU__

#include "State.h"

class Menu : public State {
	protected:
		Menu(sf::String title, std::string titleVoice, std::string musicFile);

		const sf::Color TITLE_TEXT_COLOR;
		const sf::Color ITEM_TEXT_COLOR;
		const sf::Color SEL_ITEM_TEXT_COLOR;

		int _titleHeight;
		int _titleWidth;
		int _itemHeight;
		int _itemWidth;
		int _selItemHeight;
		int _selItemWidth;

		const int VOLUME_WHEN_PLAYING;

		const std::string FONT_NAME;
		const int FONT_SIZE;
		sf::Font _font;

		int _selected;

		int _fontSize;

		// Background music
		std::string _musicFile;
		sf::Music _music;

		// Title
		sf::String _title;
		std::string _titleVoice;
		sf::Music _titleSound;
		sf::Text _titleText;

		// Options
		std::vector<std::string> _options;
		std::vector<std::string> _optionsVoices;
		std::vector<sf::Music*> _optionsSounds;
		std::vector<sf::Text*> _optionsTexts;

		bool _firstPlayedOnce;

		// Virtual methods
		virtual std::vector<std::string> initOptions() = 0;
		virtual std::vector<std::string> initOptionsVoices() = 0;

		// Other methods
		void createTitleText();
		void createItemText(int index, sf::Text* text);
		virtual void setSelected(int i);

	public:
		virtual void init();
		virtual void reset();
		virtual void onEnter();
		virtual void onLeave();
		virtual void simpleEvents(const sf::Event &event);
		virtual void complexEvents();
		virtual void update();
		virtual void render();
};

#endif