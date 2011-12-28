#include "ChoicePersoMenu.h"

using namespace std;
using namespace sf;

ChoicePersoMenu* ChoicePersoMenu::_instance = NULL;

ChoicePersoMenu::ChoicePersoMenu() : ImageMenu(
		sf::String(L""),
		Globals::getInstance()->getVoice("title_choiceperso"),
		""
	) {}

ChoicePersoMenu* ChoicePersoMenu::getInstance(bool reinit) {
	if(_instance == NULL) {
		_instance = new ChoicePersoMenu();
		_instance->init();
	}
	if(reinit) {
		_instance->reset();
	}
	return _instance;
}

vector<String> ChoicePersoMenu::initOptions() {
	vector<String> options;
	options.push_back(sf::String(L"Aurore"));
	options.push_back(sf::String(L"Timéo"));
	options.push_back(sf::String(L"Tux"));
	options.push_back(sf::String(L"Lamasticot"));
	return options;
}

vector<string> ChoicePersoMenu::initOptionsVoices() {
	vector<string> voices;
	voices.push_back(Globals::getInstance()->getVoice("aurore"));
	voices.push_back(Globals::getInstance()->getVoice("timeo"));
	voices.push_back(Globals::getInstance()->getVoice("tux"));
	voices.push_back(Globals::getInstance()->getVoice("lamasticot"));
	return voices;
}

void ChoicePersoMenu::simpleEvents(const sf::Event &event) {
	ImageMenu::simpleEvents(event);
	switch(event.Type) {
		case Event::KeyPressed:
			switch(event.Key.Code) {
				case Keyboard::Escape:
					StateManager::enterState(StateManager::MAINMENU);
					break;
				case Keyboard::Return:
					switch(_selected) {
						case 0:
							break;
						case 1:
							break;
						case 2:
							break;
						case 3:
						default: break;
					}
					StateManager::enterState(StateManager::GAMEPLAY);
					break;
			}
		default: break;
	}
}