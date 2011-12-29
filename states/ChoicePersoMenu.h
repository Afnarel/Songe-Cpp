#ifndef __CHOICE_PERSO_MENU__
#define __CHOICE_PERSO_MENU__

#include "ImageMenu.h"
#include "StateManager.h"

class ChoicePersoMenu : public ImageMenu {
	private:
		static ChoicePersoMenu *_instance;
		ChoicePersoMenu();

		// Redefinition des methodes virtuelles de Menu
		std::vector<sf::String> initOptions();
		std::vector<std::string> initOptionsVoices();

		// Redefinition des methodes virtuelles de ImageMenu
		std::vector<std::string> initImages();

	public:
		static ChoicePersoMenu* getInstance(bool reinit = false);

		// Surcharge des methodes de Menu
		void simpleEvents(const sf::Event &event);
};

#endif