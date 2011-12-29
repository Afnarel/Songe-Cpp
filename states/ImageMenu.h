#ifndef __IMAGE_MENU__
#define __IMAGE_MENU__

#include "Menu.h"

class ImageMenu : public Menu {
	protected:

		sf::Sprite _mainSprite;

		std::vector<std::string> _images;
		std::vector<sf::Texture*> _optionsTextures;
		std::vector<sf::Sprite*> _optionsSprites;

		ImageMenu(sf::String title, std::string titleVoice, std::string musicFile);
		virtual void createItemText(int index, sf::Text* text);
		void createItemSprite(int index, sf::Sprite* sprite);
		virtual void setSelected(int i);

		virtual std::vector<std::string> initImages() = 0;

	public:
		virtual void init();
		virtual void render();
};

#endif