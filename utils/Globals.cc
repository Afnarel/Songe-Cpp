#include "Globals.h"

using namespace std;
using namespace sf;

Globals* Globals::_instance = NULL;

Globals::Globals() {
	
}

Globals* Globals::getInstance() {
	if(_instance == NULL)
		_instance = new Globals();
	return _instance;
}

RenderWindow * Globals::getApp() {
	return &_app;
}


string Globals::getVoice(string name) {
	return Conf::SND_VOIX_PATH + name + ".ogg";
}

string Globals::getFont(string name) {
	return Conf::FONT_PATH + name + ".ttf";
}