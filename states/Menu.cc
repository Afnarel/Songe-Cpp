#include "Menu.h"

using namespace std;
using namespace sf;

Menu::Menu() : State() {
	
}

/* ************ *
 * Main methods *
 * ************ */

void Menu::init() {
	/*
	// Chargement à partir d'un fichier sur le disque
	if(!_font.LoadFromFile(Globals::getInstance()->getFont("sansation")))
		exit(EXIT_SUCCESS);
	
	_text.SetString("MainMenu");
	_text.SetFont(_font);
	_text.SetCharacterSize(50);
	_text.SetColor(Color::Red);
	*/
}

void Menu::simpleEvents(const sf::Event &event) {
	/*
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
	*/
}

void Menu::complexEvents() {
	
}

void Menu::update() {
	
}

void Menu::render() {
	//_app->Draw(_text);
}