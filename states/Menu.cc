#include "Menu.h"

using namespace std;
using namespace sf;

Menu::Menu(string title, string titleVoice, string musicFile) : State() {
	_title = title;
	_titleVoice = titleVoice;
	_musicFile = musicFile;

}

/* ************ *
 * Main methods *
 * ************ */

void Menu::init() {
	_options = initOptions();
	_optionsVoices = initOptionsVoices();

	// Load background music
	if(!_music.OpenFromFile(_musicFile)) {
		Globals::getInstance()->error("File " + _musicFile + " could not be found.");
	}

	// Load title sound
	if(!_titleSound.OpenFromFile(_titleVoice)) {
		Globals::getInstance()->error("File " + _titleVoice + " could not be found.");
	}

	// Load options sounds
	for(size_t i=0; i<_optionsVoices.size(); i++) {
		Music *m = new Music();
		if(!m->OpenFromFile(_optionsVoices[i])) {
			Globals::getInstance()->error("File " + _optionsVoices[i] + " could not be found.");
		}
		_optionsSounds.push_back(m);
	}


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

void Menu::reset() {
	
}

void Menu::onEnter() {
	_music.Play();
}

void Menu::onLeave() {
	
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