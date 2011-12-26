#include "MainMenu.h"

using namespace std;
using namespace sf;

MainMenu* MainMenu::_instance = NULL;

MainMenu::MainMenu() : Menu(
	"Bienvenue dans l'univers de Songe", // Title
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

vector<string> MainMenu::initOptions() {
	vector<string> options;
	options.push_back("Jouer");
	options.push_back("Scores");
	options.push_back("Minijeux");
	options.push_back("Quitter");
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
	Menu::simpleEvents(event);
	switch(event.Type) {
		case Event::KeyPressed:
			switch(event.Key.Code) {
				case Keyboard::A:
					cout << "On est dans MainMenu" << endl;
					break;
				case Keyboard::S:
					cout << "On change pour Gameplay" << endl;
					StateManager::enterState(StateManager::GAMEPLAY);
					break;
			}
		default: break;
	}
}