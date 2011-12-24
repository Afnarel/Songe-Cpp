#include "MainMenu.h"

using namespace std;
using namespace sf;

MainMenu* MainMenu::_instance = NULL;

MainMenu::MainMenu() : Menu() {
	
}

MainMenu* MainMenu::getInstance(bool reinit) {
	if(_instance == NULL) {
		_instance = new MainMenu();
		reinit = true;
	}
	if(reinit) {
		_instance->init();
	}
	return _instance;
}