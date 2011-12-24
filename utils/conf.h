#ifndef __CONF__
#define __CONF__

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

namespace Conf {
	const bool FULLSCREEN = false;

	// If not in fullscreen mode
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	const int FRAMERATE_LIMIT = 60; // Number of images per second

	const std::string WINDOW_TITLE = "Songe";

	// Paths
	const std::string RESS_PATH = "./ressources/";

	// Images
	const std::string IMG_PATH = RESS_PATH+"images/";
	const std::string IMG_SPRITES_PATH = IMG_PATH+"sprites/";
	const std::string IMG_TEXTURES_PATH = IMG_PATH+"textures/";
	const std::string IMG_TILES_PATH = IMG_PATH+"tiles/";

	// Sounds
	const std::string SND_PATH = RESS_PATH+"sons/";
	const std::string SND_DEPLACEMENT_PATH = SND_PATH+"deplacement/";
	const std::string SND_ENVIRONEMENT_PATH = SND_PATH+"environement/";
	const std::string SND_BIP_PATH = SND_PATH+"bip/";
	const std::string SND_VOIX_PATH = SND_PATH+"voix/julie/";
	const std::string SND_MUSIC_PATH = SND_PATH+"musiques/";
	const std::string SND_PERSOS_PATH = SND_PATH+"persos/";

	// Fonts
	const std::string FONT_PATH = RESS_PATH+"fonts/";

	// Emitters
	const std::string EMITTERS_PATH = RESS_PATH+"emitters/";
}

#endif