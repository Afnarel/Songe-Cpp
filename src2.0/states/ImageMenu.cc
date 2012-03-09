#include "ImageMenu.h"

using namespace std;
using namespace sf;

ImageMenu::ImageMenu(sf::String title, std::string titleVoice, std::string musicFile) : 
	Menu(title, titleVoice, musicFile) {

}

void ImageMenu::init() {
	Menu::init();

	_images = initImages();

	for(size_t i = 0; i<_images.size(); i++) {
		Texture * texture = new Texture();
		if(!texture->LoadFromFile(_images[i]))
			Globals::getInstance()->error("File " + _images[i] + " could not be found.");

		_optionsTextures.push_back(texture);


		Sprite * sprite = new Sprite(*texture);
		createItemSprite(i, sprite);
		_optionsSprites.push_back(sprite);
	}
}

void ImageMenu::render() {
	//cout << "ImageMenu::render" << endl;
	if(!_title.IsEmpty()) {
		_app->Draw(_titleText);
	}
	_app->Draw(*_optionsTexts[_selected]);

	for(size_t i=0; i<_optionsSprites.size(); i++) {
		_app->Draw(*_optionsSprites[i]);
	}

	_app->Draw(_mainSprite);
}

void ImageMenu::createItemText(int i, Text* text) {
	text->SetString(_options[i]);
	text->SetFont(_font);
	text->SetCharacterSize(_fontSize);
	text->SetColor(ITEM_TEXT_COLOR);

	text->SetOrigin(text->GetLocalBounds().Width/2, text->GetLocalBounds().Height/2);

	int x = Globals::getInstance()->getApp()->GetWidth()/2;
	int y = Globals::getInstance()->getApp()->GetHeight()/2;

	text->Move(x,y);
}

void ImageMenu::createItemSprite(int i, Sprite* sprite) {

	float margin = 100;
	float ww = Globals::getInstance()->getApp()->GetWidth() - margin;
	float wh = Globals::getInstance()->getApp()->GetHeight();

	// All sprites have the same width ; height auto-adapts itself
	float w = ww / _images.size();
	float h = (w * sprite->GetPosition().y) / sprite->GetPosition().x;

	float aff_w = w;

	// Use the center of the image for transformations
	sprite->SetOrigin(sprite->GetLocalBounds().Width/2, sprite->GetLocalBounds().Height/2);

	float y = 3 * wh/4;
	float x =  i*aff_w + aff_w/2;

	sprite->SetPosition(x,y);

	// If selected, zoom
	if(i != _selected) {
		sprite->SetScale(0.5, 0.5);
	}
	else {
		sprite->SetScale(1, 1);
	}

/*
	// If selected, zoom
	if(i != _selected) {
		float scale = 0.5;
		w *= scale;
		h *= scale;
	}
	else {
		_mainSprite.SetTexture(*_optionsTextures[i]);
		float msh = 3 * wh / 8;
		float msw = (msh * _mainSprite.GetPosition().x) / _mainSprite.GetPosition().y;
		//_mainSprite.Resize(msw, msh);
		_mainSprite.SetPosition(ww/2 - msw/2, 0);
	}

	//sprite->Resize(w, h);

	// Use the center of the image for transformations
	sprite->SetOrigin(sprite->GetPosition().x/2, sprite->GetPosition().y/2);

	float y = 3 * wh/4;
	float x =  i*aff_w + aff_w/2;

	sprite->SetPosition(x,y);
*/
}

void ImageMenu::setSelected(int i) {
	int old_selected = _selected;
	Menu::setSelected(i);
	createItemSprite(old_selected, _optionsSprites[old_selected]);
	createItemSprite(_selected, _optionsSprites[_selected]);
}