#include "MainMenu.h"

using namespace std;
using namespace sf;

MainMenu* MainMenu::_instance = NULL;

MainMenu::MainMenu() : TextMenu(
	sf::String(L"Bienvenue dans l'univers de Songe"), // Title
	Globals::getInstance()->getVoice("bienvenue"),
	Globals::getInstance()->getMusic("fond")
) {}

MainMenu* MainMenu::getInstance(bool reinit) {
	if(_instance == NULL) {
		_instance = new MainMenu();
		_instance->init();
	}
	if(reinit) {
		_instance->reset();
	}
	return _instance;
}

vector<String> MainMenu::initOptions() {
	vector<String> options;
	options.push_back(sf::String(L"Jouer"));
	options.push_back(sf::String(L"Scores"));
	options.push_back(sf::String(L"Minijeux"));
	options.push_back(sf::String(L"Quitter"));
	return options;
}

vector<string> MainMenu::initOptionsVoices() {
	vector<string> voices;
	voices.push_back(Globals::getInstance()->getVoice("jouer"));
	voices.push_back(Globals::getInstance()->getVoice("scores"));
	voices.push_back(Globals::getInstance()->getVoice("minijeux"));
	voices.push_back(Globals::getInstance()->getVoice("quitter"));
	return voices;
}

void MainMenu::simpleEvents(const sf::Event &event) {
	TextMenu::simpleEvents(event);
	switch(event.Type) {
		case Event::KeyPressed:
			switch(event.Key.Code) {
				case Keyboard::Escape:
					StateManager::enterState(StateManager::INITIALMENU);
					break;
				case Keyboard::Return:
					switch(_selected) {
						case 0:
							StateManager::enterState(StateManager::CHOICEPERSOMENU, true);
							break;
						case 1:
						break;
						case 2:
						break;
						case 3:
							exit(EXIT_SUCCESS);
						default: break;
					}
					break;
			}
		default: break;
	}
}