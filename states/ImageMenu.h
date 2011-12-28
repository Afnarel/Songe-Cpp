#ifndef __IMAGE_MENU__
#define __IMAGE_MENU__

#include "Menu.h"

class ImageMenu : public Menu {
	protected:
		ImageMenu(sf::String title, std::string titleVoice, std::string musicFile);
	public:
		virtual void init();
		virtual void render();
};

#endif