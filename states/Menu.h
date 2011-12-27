#ifndef __MENU__
#define __MENU__

#include "State.h"

class Menu : public State {
	protected:
		Menu(sf::String title, std::string titleVoice, std::string _musicFile);

		const int BORDER_THICKNESS;

		const sf::Color TITLE_COLOR;
		const sf::Color TITLE_BORDER_COLOR;
		const sf::Color TITLE_TEXT_COLOR;
		const sf::Color ITEM_COLOR;
		const sf::Color ITEM_BORDER_COLOR;
		const sf::Color ITEM_TEXT_COLOR;
		const sf::Color SEL_ITEM_COLOR;
		const sf::Color SEL_ITEM_BORDER_COLOR;
		const sf::Color SEL_ITEM_TEXT_COLOR;

		const int VOLUME_WHEN_PLAYING;

		const std::string FONT_NAME;
		sf::Font _font;

		int _selected;
		int _titleHeight;
		int _titleWidth;
		int _itemHeight;
		int _itemWidth;
		int _selItemHeight;
		int _selItemWidth;

		int _fontSize;

		// Background music
		std::string _musicFile;
		sf::Music _music;

		// Title
		sf::String _title;
		std::string _titleVoice;
		sf::Music _titleSound;
		sf::Shape _titleShape;
		sf::Text _titleText;

		// Options
		std::vector<std::string> _options;
		std::vector<std::string> _optionsVoices;
		std::vector<sf::Music*> _optionsSounds;
		std::vector<sf::Shape*> _optionsShapes;
		std::vector<sf::Text*> _optionsTexts;

		bool _firstPlayedOnce;

		// Virtual methods
		virtual std::vector<std::string> initOptions() = 0;
		virtual std::vector<std::string> initOptionsVoices() = 0;

		// Other methods
		void createTitleShape();
		void createTitleText();
		void createItemShape(int index, sf::Shape* rectangle);
		void createRectangle(sf::Shape* rectangle, int x, int y, int w, int h,
			const sf::Color &color, const sf::Color &borderColor);
		void createItemText(int index, sf::Text* text);
		void setSelected(int i);

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