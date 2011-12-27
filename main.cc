#include "states/StateManager.h"

using namespace std;
using namespace sf;

int main() {

	RenderWindow * app = Globals::getInstance()->getApp();
	
	if(Conf::FULLSCREEN) {
		std::vector<VideoMode> modes = VideoMode::GetFullscreenModes();
		app->Create(modes[0], Conf::WINDOW_TITLE, Style::Fullscreen);
	}
	else {
		app->Create(VideoMode(Conf::WINDOW_WIDTH, Conf::WINDOW_HEIGHT, 32), 
		Conf::WINDOW_TITLE, Style::Close | Style::Titlebar);
		VideoMode d = VideoMode::GetDesktopMode();
		app->SetPosition(d.Width/2 - Conf::WINDOW_WIDTH/2, d.Height/2 - Conf::WINDOW_HEIGHT/2);
	}
	app->SetFramerateLimit(Conf::FRAMERATE_LIMIT);
	app->EnableVerticalSync(Conf::ENABLE_VSYNC);
	app->ShowMouseCursor(Conf::SHOW_CURSOR);

	StateManager::enterState(StateManager::INITIALMENU);

	while (app->IsOpened()) {
		State *state = StateManager::getCurrentState();

		Event event;
		while (app->PollEvent(event)) {
			switch(event.Type) {
				case Event::Closed:
					app->Close();
					break;

				case Event::KeyPressed:
					switch(event.Key.Code) {
						case Keyboard::Escape:
							app->Close();
							break;
					}
				default: break;
			}
			state->simpleEvents(event);
		}

		state->complexEvents();

		state->update();


		app->Clear();
		state->render();
		app->Display();
	}
	return EXIT_SUCCESS;
}