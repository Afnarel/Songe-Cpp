#include "TextMenu.h"

using namespace std;
using namespace sf;

TextMenu::TextMenu(sf::String title, std::string titleVoice, std::string musicFile) : 
	Menu(title, titleVoice, musicFile),
	BORDER_THICKNESS(10),
	TITLE_COLOR(Color(250,240,240)),
	TITLE_BORDER_COLOR(Color(255,255,255)),
	ITEM_COLOR(Color(0,0,200)),
	ITEM_BORDER_COLOR(Color(0,0,220)), 
	SEL_ITEM_COLOR(Color(250,240,240)),
	SEL_ITEM_BORDER_COLOR(Color(255,255,255)) {
	
	_fontSize = _itemHeight / 2;

}

void TextMenu::init() {
	Menu::init();

	// Title shape
	createTitleShape();

	// Options shapes
	for(size_t i=0; i<_options.size(); i++) {
		RectangleShape* rectangle = new RectangleShape();
		createItemShape(i, rectangle);

		_optionsShapes.push_back(rectangle);
	}
}

void TextMenu::render() {
	// Title
	_app->Draw(_titleShape);

	// Items
	for(size_t i=0; i<_options.size(); i++) {
		_app->Draw(*_optionsShapes[i]);
	}

	/*
	// Selected above all
	for(size_t i=0; i<_options.size(); i++) {
		if(i != _selected) {
			_app->Draw(*_optionsShapes[i]);
			_app->Draw(*_optionsTexts[i]);
		}
	}
	_app->Draw(*_optionsShapes[_selected]);
	_app->Draw(*_optionsTexts[_selected]);
	*/

	Menu::render();
}

void TextMenu::createTitleShape() {
	int x = Globals::getInstance()->getApp()->GetWidth()/2 - _titleWidth / 2;
	int y = Globals::getInstance()->getApp()->GetHeight()/10;
	createRectangle(&_titleShape, x, y, _titleWidth, _titleHeight,
		TITLE_COLOR, TITLE_BORDER_COLOR);

	_titleShape.SetOutlineThickness(BORDER_THICKNESS);
}

void TextMenu::createItemShape(int i, RectangleShape* rectangle) {
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

	rectangle->SetOutlineThickness(BORDER_THICKNESS);
}

void TextMenu::createRectangle(RectangleShape* rectangle, int x, int y, int w, int h,
	const Color &color, const Color &borderColor) {
	rectangle->SetFillColor(color);
	rectangle->SetOutlineColor(borderColor);
	rectangle->SetSize(Vector2f(w,h));
	rectangle->SetPosition(x,y);
}

void TextMenu::setSelected(int i) {
	if(i != _selected) {
		// Delete unused pointers to shapes
		// and create new shapes in their place
		delete _optionsShapes[_selected];
		delete _optionsShapes[i];
		_optionsShapes[_selected] = new RectangleShape();
		_optionsShapes[i] = new RectangleShape();

		// Delete unused pointers to texts
		// and create new texts in their place
		delete _optionsTexts[_selected];
		delete _optionsTexts[i];
		_optionsTexts[_selected] = new Text();
		_optionsTexts[i] = new Text();

		int old_selected = _selected;
		_selected = i;

		// Set the new properties of the two shapes that changed
		createItemShape(old_selected, _optionsShapes[old_selected]);
		createItemShape(_selected, _optionsShapes[_selected]);

		// Set the new properties of the two texts that changed
		createItemText(old_selected, _optionsTexts[old_selected]);
		createItemText(_selected, _optionsTexts[_selected]);
	}
}