#include "MainMenu.h"

using namespace std;
using namespace sf;

MainMenu* MainMenu::_instance = NULL;

MainMenu::MainMenu() : State() {
	
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

/* ************ *
 * Main methods *
 * ************ */

void MainMenu::init() {
	// Chargement à partir d'un fichier sur le disque
	if(!_font.LoadFromFile(Globals::getInstance()->getFont("sansation")))
		exit(EXIT_SUCCESS);
	
	_text.SetString("MainMenu");
	_text.SetFont(_font);
	_text.SetCharacterSize(50);
	_text.SetColor(Color::Red);
}

void MainMenu::simpleEvents(const sf::Event &event) {
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

void MainMenu::complexEvents() {
	
}

void MainMenu::update() {
	
}

void MainMenu::render() {
	_app->Draw(_text);
}