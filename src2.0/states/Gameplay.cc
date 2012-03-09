#include "Gameplay.h"

using namespace std;
using namespace sf;

Gameplay* Gameplay::_instance = NULL;

Gameplay::Gameplay() : State() {
	
}

Gameplay* Gameplay::getInstance(bool reinit) {
	if(_instance == NULL) {
		_instance = new Gameplay();
		_instance->init();
	}
	if(reinit) {
		_instance->reset();
	}
	return _instance;
}

void Gameplay::init() {
	// Chargement à partir d'un fichier sur le disque
	if(!_font.LoadFromFile(Globals::getInstance()->getFont("sansation")))
		exit(EXIT_SUCCESS);
	
	_text.SetString("Gameplay");
	_text.SetFont(_font);
	_text.SetCharacterSize(50);
	_text.SetColor(Color::Red);
}

void Gameplay::reset() {
	
}

void Gameplay::onEnter() {

}

void Gameplay::onLeave() {
	
}

void Gameplay::simpleEvents(const sf::Event &event) {
	switch(event.Type) {
		case Event::KeyPressed:
			switch(event.Key.Code) {
				case Keyboard::Escape:
					StateManager::enterState(StateManager::MAINMENU, true);
					break;
			}
		default: break;
	}
}

void Gameplay::complexEvents() {
	
}

void Gameplay::update() {
	
}

void Gameplay::render() {
	_app->Draw(_text);
}