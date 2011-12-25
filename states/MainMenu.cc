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

	return options;
}

vector<string> MainMenu::initOptionsVoices() {
	vector<string> optionsVoices;

	return optionsVoices;
}