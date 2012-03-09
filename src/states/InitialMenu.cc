#include "InitialMenu.h"

using namespace std;
using namespace sf;

InitialMenu* InitialMenu::_instance = NULL;

InitialMenu::InitialMenu() : TextMenu(
	sf::String(L"Avez-vous déjà joué au jeu ?"), // Title
	Globals::getInstance()->getVoice("deja_joue"),
	""
) {}

InitialMenu* InitialMenu::getInstance(bool reinit) {
	if(_instance == NULL) {
		_instance = new InitialMenu();
		_instance->init();
	}
	if(reinit) {
		_instance->reset();
	}
	return _instance;
}

vector<String> InitialMenu::initOptions() {
	vector<String> options;
	options.push_back(sf::String(L"Non"));
	options.push_back(sf::String(L"Oui"));
	return options;
}

vector<string> InitialMenu::initOptionsVoices() {
	vector<string> voices;
	voices.push_back(Globals::getInstance()->getVoice("non"));
	voices.push_back(Globals::getInstance()->getVoice("oui"));
	return voices;
}

void InitialMenu::simpleEvents(const sf::Event &event) {
	TextMenu::simpleEvents(event);
	switch(event.Type) {
		case Event::KeyPressed:
			switch(event.Key.Code) {
				case Keyboard::Escape:
					exit(EXIT_SUCCESS);
				case Keyboard::Return:
					switch(_selected) {
						case 0:
							Globals::getInstance()->setHasAlreadyPlayed(false);
							break;
						case 1:
							Globals::getInstance()->setHasAlreadyPlayed(true);
							break;
						default: break;
					}
					StateManager::enterState(StateManager::MAINMENU);
					break;
			}
		default: break;
	}
}