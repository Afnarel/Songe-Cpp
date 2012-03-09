#ifndef __TEXT_MENU__
#define __TEXT_MENU__

#include "Menu.h"

class TextMenu : public Menu {
	protected:
		TextMenu(sf::String title, std::string titleVoice, std::string musicFile);

		const int BORDER_THICKNESS;

		const sf::Color TITLE_COLOR;
		const sf::Color TITLE_BORDER_COLOR;
		const sf::Color ITEM_COLOR;
		const sf::Color ITEM_BORDER_COLOR;
		const sf::Color SEL_ITEM_COLOR;
		const sf::Color SEL_ITEM_BORDER_COLOR;

		// Title
		sf::RectangleShape _titleShape;

		// Options
		std::vector<sf::RectangleShape*> _optionsShapes;

		// Methods
		void createTitleShape();
		void createItemShape(int index, sf::RectangleShape* rectangle);
		void createRectangle(sf::RectangleShape* rectangle, int x, int y, int w, int h,
			const sf::Color &color, const sf::Color &borderColor);
		virtual void setSelected(int i);

	public:
		virtual void init();
		virtual void render();
};

#endif