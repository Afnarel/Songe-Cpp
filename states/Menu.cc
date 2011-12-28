#include "Menu.h"

using namespace std;
using namespace sf;

Menu::Menu(String title, string titleVoice, string musicFile) : 
	State(),
	FONT_NAME("sansation"), //nv
	FONT_SIZE(40),
	VOLUME_WHEN_PLAYING(0),
	TITLE_TEXT_COLOR(Color::Black),
	ITEM_TEXT_COLOR(Color::White),
	SEL_ITEM_TEXT_COLOR(Color::Black) {

	_titleHeight = Globals::getInstance()->getApp()->GetHeight()/7;
	_titleWidth = 4 * Globals::getInstance()->getApp()->GetWidth()/5;
	_itemHeight = Globals::getInstance()->getApp()->GetHeight()/7;
	_itemWidth = 4 * Globals::getInstance()->getApp()->GetWidth()/5;
	_selItemHeight = Globals::getInstance()->getApp()->GetHeight()/7;
	_selItemWidth = 9 * Globals::getInstance()->getApp()->GetWidth()/10;

	_selected = 0;

	_fontSize = FONT_SIZE;

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
	_firstPlayedOnce = false;

	// Load background music
	if(_musicFile != "") {
		if(!_music.OpenFromFile(_musicFile)) {
			Globals::getInstance()->error("File " + _musicFile + " could not be found.");
		}
		_music.SetLoop(true);
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

	// Title text
	createTitleText();

	// Options texts
	for(size_t i=0; i<_options.size(); i++) {
		Text* text = new Text();
		createItemText(i, text);

		_optionsTexts.push_back(text);
	}
}

void Menu::reset() {
	setSelected(0);
	_firstPlayedOnce = false;
	if(_musicFile != "") {
		_music.SetVolume(100);
	}
}

void Menu::onEnter() {
	_titleSound.Play();
	if(_musicFile != "") {
		_music.Play();
	}
}

void Menu::onLeave() {
	if(_musicFile != "") {
		_music.Stop();
	}
}

void Menu::simpleEvents(const sf::Event &event) {
	switch(event.Type) {
		case Event::KeyPressed:
			switch(event.Key.Code) {
				case Keyboard::Up:
				case Keyboard::Left:
					if(_selected - 1 >= 0) {
						setSelected(_selected-1);
					}
					else {
						setSelected(_options.size()-1);
					}
					if(_titleSound.GetStatus() != SoundSource::Playing) {
						if(_musicFile != "") {
							_music.SetVolume(VOLUME_WHEN_PLAYING);
						}
						_optionsSounds[_selected]->Play();
					}
					break;
				case Keyboard::Down:
				case Keyboard::Right:
					if(_selected + 1 <= _options.size()-1) {
						setSelected(_selected+1);
					}
					else {
						setSelected(0);
					}
					if(_titleSound.GetStatus() != SoundSource::Playing) {
						if(_musicFile != "") {
							_music.SetVolume(VOLUME_WHEN_PLAYING);
						}
						_optionsSounds[_selected]->Play();
					}
					break;
			}
		default: break;
	}
}

void Menu::complexEvents() {
	
}

void Menu::update() {
	if(_titleSound.GetStatus() != SoundSource::Playing && !_firstPlayedOnce) {
		_optionsSounds[_selected]->Play();
		_firstPlayedOnce = true;
	}

	if(_musicFile != "" && _music.GetVolume() < 100) {
		bool playing = false;
		for(size_t i=0; i<_options.size() && !playing; i++) {
			if(_optionsSounds[i]->GetStatus() == SoundSource::Playing)
				playing = true;
		}
		if(!playing)
			_music.SetVolume(_music.GetVolume() + 1);
	}
}

void Menu::render() {
	// Title
	_app->Draw(_titleText);

	// Items
	for(size_t i=0; i<_options.size(); i++) {
		_app->Draw(*_optionsTexts[i]);
	}
}

void Menu::createTitleText() {
	int x = Globals::getInstance()->getApp()->GetWidth()/2;
	int y = Globals::getInstance()->getApp()->GetHeight()/10 + _titleHeight/2;

	_titleText.SetString(_title);
	_titleText.SetFont(_font);
	_titleText.SetCharacterSize(_fontSize);

	if(!_title.IsEmpty()) {
		// Auto adapt the font
		while(_titleText.GetRect().Width < _titleWidth) {
			_fontSize++;
			_titleText.SetCharacterSize(_fontSize);
		}
		while(_titleText.GetRect().Width > _titleWidth) {
			_fontSize--;
			_titleText.SetCharacterSize(_fontSize);
		}
	}

	_titleText.SetOrigin(_titleText.GetRect().Width/2, _titleText.GetRect().Height/2);
	_titleText.SetColor(TITLE_TEXT_COLOR);
	_titleText.Move(x,y);
}

void Menu::createItemText(int i, Text* text) {
	text->SetString(_options[i]);
	text->SetFont(_font);
	text->SetCharacterSize(_fontSize);

	text->SetOrigin(text->GetRect().Width/2, 0);

	int x = Globals::getInstance()->getApp()->GetWidth()/2;
	int y;
	if(i == _selected) {
		y = Globals::getInstance()->getApp()->GetHeight()/3 + _selItemHeight * i;
		text->SetColor(SEL_ITEM_TEXT_COLOR);
	}
	else {
		y = Globals::getInstance()->getApp()->GetHeight()/3 + _itemHeight * i;
		text->SetColor(ITEM_TEXT_COLOR);
	}
	text->Move(x,y);
}

void Menu::setSelected(int i) {
	if(i != _selected) {
		// Delete unused pointers to texts
		// and create new texts in their place
		delete _optionsTexts[_selected];
		delete _optionsTexts[i];
		_optionsTexts[_selected] = new Text();
		_optionsTexts[i] = new Text();

		int old_selected = _selected;
		_selected = i;

		// Set the new properties of the two texts that changed
		createItemText(old_selected, _optionsTexts[old_selected]);
		createItemText(_selected, _optionsTexts[_selected]);
	}
}