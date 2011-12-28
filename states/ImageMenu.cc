#include "ImageMenu.h"

using namespace std;
using namespace sf;

ImageMenu::ImageMenu(sf::String title, std::string titleVoice, std::string musicFile) : 
	Menu(title, titleVoice, musicFile) {
		
}

void ImageMenu::init() {
	Menu::init();
	//cout << "ImageMenu::init" << endl;
}

void ImageMenu::render() {
	//cout << "ImageMenu::render" << endl;
	Menu::render();
}