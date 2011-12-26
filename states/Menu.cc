#include "Menu.h"

using namespace std;
using namespace sf;

Menu::Menu(string title, string titleVoice, string musicFile) : 
	State(),
	FONT_NAME("sansation"),
	TITLE_COLOR(Color(250,240,240)),
	TITLE_BORDER_COLOR(Color(255,255,255)),
	ITEM_COLOR(Color(0,0,200)),
	ITEM_BORDER_COLOR(Color(0,0,220)),
	SEL_ITEM_COLOR(Color(250,240,240)),
	SEL_ITEM_BORDER_COLOR(Color(255,255,255)) {

	_selected = 0;
	_titleHeight = Globals::getInstance()->getApp()->GetHeight()/7;
	_titleWidth = 4 * Globals::getInstance()->getApp()->GetWidth()/5;
	_itemHeight = Globals::getInstance()->getApp()->GetHeight()/7;
	_itemWidth = 4 * Globals::getInstance()->getApp()->GetWidth()/5;
	_selItemHeight = Globals::getInstance()->getApp()->GetHeight()/7;
	_selItemWidth = 9 * Globals::getInstance()->getApp()->GetWidth()/10;

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

	// Font
	if(!_font.LoadFromFile(Globals::getInstance()->getFont(FONT_NAME))) {
		Globals::getInstance()->error("Font " + FONT_NAME + " could not be found.");
	}

	// Title shape
	createTitleShape();

	// Options shapes
	for(size_t i=0; i<_options.size(); i++) {
		Shape* rectangle = new Shape();
		createItemShape(i, rectangle);

		_optionsShapes.push_back(rectangle);
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
	setSelected(0);
}

void Menu::onEnter() {
	_titleSound.Play();
	_music.Play();
}

void Menu::onLeave() {
	_music.Stop();
}

void Menu::simpleEvents(const sf::Event &event) {
	switch(event.Type) {
		case Event::KeyPressed:
			switch(event.Key.Code) {
				case Keyboard::Up:
					if(_selected - 1 >= 0) {
						setSelected(_selected-1);
					}
					else {
						setSelected(_options.size()-1);
					}
					_optionsSounds[_selected]->Play();
					break;
				case Keyboard::Down:
					if(_selected + 1 <= _options.size()-1) {
						setSelected(_selected+1);
					}
					else {
						setSelected(0);
					}
					_optionsSounds[_selected]->Play();
					break;
				/*
				case Keyboard::A:
					cout << "On est dans MainMenu" << endl;
					break;
				case Keyboard::S:
					cout << "On change pour Gameplay" << endl;
					StateManager::enterState(StateManager::GAMEPLAY);
					break;
				*/
			}
		default: break;
	}
}

void Menu::complexEvents() {
	
}

void Menu::update() {

}

void Menu::render() {
	// Title shape
	_app->Draw(_titleShape);

	// Item shapes
	for(size_t i=0; i<_optionsShapes.size(); i++) {
		if(i != _selected)
			_app->Draw(*_optionsShapes[i]);
	}
	_app->Draw(*_optionsShapes[_selected]);
}

void Menu::createTitleShape() {
	int x = Globals::getInstance()->getApp()->GetWidth()/2 - _titleWidth / 2;
	int y = Globals::getInstance()->getApp()->GetHeight()/10;
	createRectangle(&_titleShape, x, y, _titleWidth, _titleHeight,
		TITLE_COLOR, TITLE_BORDER_COLOR);

	_titleShape.SetOutlineThickness(20);
	_titleShape.EnableOutline(true);
	_titleShape.EnableFill(true);
}

void Menu::createItemShape(int i, Shape* rectangle) {
	if(i == _selected) {
		int x = Globals::getInstance()->getApp()->GetWidth()/2 - _selItemWidth / 2;
		int y = Globals::getInstance()->getApp()->GetHeight()/3 + _selItemHeight * i;
		createRectangle(rectangle, x, y, _selItemWidth, _selItemHeight,
			SEL_ITEM_COLOR, SEL_ITEM_BORDER_COLOR);
	}
	else {
		int x = Globals::getInstance()->getApp()->GetWidth()/2 - _itemWidth / 2;
		int y = Globals::getInstance()->getApp()->GetHeight()/3 + _itemHeight * i;
		createRectangle(rectangle, x, y, _itemWidth, _itemHeight, 
			ITEM_COLOR, ITEM_BORDER_COLOR);
	}

	rectangle->SetOutlineThickness(20);
	rectangle->EnableOutline(true);
	rectangle->EnableFill(true);
}

void Menu::createRectangle(Shape* rectangle, int x, int y, int w, int h,
	const Color &color, const Color &borderColor) {
	rectangle->AddPoint(Vector2f(x,y), color, borderColor); // haut gauche
	rectangle->AddPoint(Vector2f(x+w,y), color, borderColor); // haut droit
	rectangle->AddPoint(Vector2f(x+w,y+h), color, borderColor); // bas droit
	rectangle->AddPoint(Vector2f(x,y+h), color, borderColor); // bas gauche
}

void Menu::setSelected(int i) {
	// Delete unused pointers to shapes
	// and create new shapes in their place
	delete _optionsShapes[_selected];
	delete _optionsShapes[i];
	_optionsShapes[_selected] = new Shape();
	_optionsShapes[i] = new Shape();
	
	int old_selected = _selected;
	_selected = i;

	// Set the new properties of the two shapes that changed
	createItemShape(old_selected, _optionsShapes[old_selected]);
	createItemShape(_selected, _optionsShapes[_selected]);
}