#include <cstdlib>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "conf.h"
#include "Globals.h"
#include "StateManager.h"

using namespace sf;

int main() {

	RenderWindow * app = Globals::getInstance()->getApp();
	
	if(FULLSCREEN) {
		std::vector<VideoMode> modes = VideoMode::GetFullscreenModes();
		app.Create(modes[0], WINDOW_TITLE, Style::Fullscreen);
	}
	else {
		app.Create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), WINDOW_TITLE, Style::Close | Style::Titlebar);
	}
	app.SetFramerateLimit(FRAMERATE_LIMIT);

	StateManager::enterState(StateManager::MAINMENU);

	while (app.IsOpened()) {
		State *state = StateManager::getCurrentState();

		Event event;
		while (app.PollEvent(event)) {
			switch(event.Type) {
				case Event::Closed:
					app.Close();
					break;

				case Event::KeyPressed:
					switch(event.Key.Code) {
						case Keyboard::Escape:
							app.Close();
							break;
					}
				default: break;
			}
			state->simpleEvents(app, event);
		}

		state->complexEvents(app);

		state->update(app);


		app.Clear();
		state->render(app);
		app.Display();
	}
	return EXIT_SUCCESS;
}