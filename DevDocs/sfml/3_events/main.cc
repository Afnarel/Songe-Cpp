#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow app(VideoMode(800, 600, 32), "Ma premiere fenetre SFML !");
	app.SetFramerateLimit(60); // Limite la fenêtre à 60 images par seconde

	while (app.IsOpened()) {
		Event event;
		while (app.PollEvent(event)) {
			switch(event.Type) {
				case Event::Closed:
					app.Close();
					break;
				/* ******* *
				 * Clavier *
				 * ******* */
				case Event::KeyPressed: // $$$$$$$$$$$ KeyPressed, KeyReleased $$$$$$$$$$$
					switch(event.Key.Code) {
						case Keyboard::Escape:
							app.Close();
							break;
					}

					if(event.Key.Alt) { // $$$$$$$$$$$ Alt, Control, Shift, System $$$$$$$$$$$
						switch(event.Key.Code) {
							case Keyboard::W:
								std::cout << "Alt+W" << std::endl;
								break;
						}
					}
				/* ****** *
				 * Souris *
				 * ****** */
				case Event::MouseMoved:
					//int mouse_x = event.MouseMove.X;
					//int mouse_y = event.MouseMove.Y;
					break;
				case Event::MouseButtonPressed:
					switch(event.MouseButton.Button) {
						using namespace std;
						case Mouse::Left:
							cout << "Left button" << endl;
							break;
						case Mouse::Middle:
							cout << "Middle button" << endl;
							break;
						case Mouse::Right:
							cout << "Right button" << endl;
							break;
					}
				break;
				case Event::MouseButtonReleased:
					// Comme MouseButtonPressed
					break;
				case Event::MouseWheelMoved:
					// mouvement positif si on tourne la molette vers l'avant, et négatif vers l'arrière
					//int wheelMove = event.MouseWheel.Delta; 
					break;
			}
		}

		/* **************************** *
		 * Avec la methode IsKeyPressed *
		 * **************************** */

		if(Keyboard::IsKeyPressed(Keyboard::Left)) {
			using namespace std;
			cout << "Left" << endl;
		}
		if(Keyboard::IsKeyPressed(Keyboard::Right)) {
			using namespace std;
			cout << "Right" << endl;
		}

		/* ******************************* *
		 * Avec la methode IsButtonPressed *
		 * ******************************* */
		
		if(Mouse::IsButtonPressed(Mouse::Left)) {
			
		}
		else if(Mouse::IsButtonPressed(Mouse::Right)) {
			// GET position of the mouse
			using namespace std;
			Vector2i desk_pos = Mouse::GetPosition(); // Desktop coordinates
			Vector2i win_pos = Mouse::GetPosition(app); // Window coordinates
			cout << "Relative to Desktop: (" << desk_pos.x << "," << desk_pos.y << ")" << endl;
			cout << "Relative to Window: (" << win_pos.x << "," << win_pos.y << ")" << endl;
		}
		else if(Mouse::IsButtonPressed(Mouse::Middle)) {
			// SET position of the mouse
			using namespace std;

			if(Keyboard::IsKeyPressed(Keyboard::W)) {
				// Centre la souris par rapport a la fenetre
				cout << "Dimensions de la fenetre : " << app.GetWidth() << " " << app.GetHeight() << endl;
				Mouse::SetPosition(Vector2i(app.GetWidth()/2, app.GetHeight()/2), app); // Window coordinates
			}
			else {
				// Centre la souris par rapport au bureau
				VideoMode d = VideoMode::GetDesktopMode();
				cout << "Dimensions du bureau : " << d.Width << " " << d.Height << endl;
				Mouse::SetPosition(Vector2i(d.Width/2, d.Height/2)); // Desktop coordinates
			}
		}


		app.Clear();

		/* **************** */

		Image image_boutons;
		if (!image_boutons.LoadFromFile("boutons.png"))
			return EXIT_FAILURE;
		image_boutons.CreateMaskFromColor(Color(181, 230, 29));

		Texture texture_boutons;
		if (!texture_boutons.LoadFromImage(image_boutons))
			return EXIT_FAILURE;
		Sprite boutons(texture_boutons);
		app.Draw(boutons);

		/* **************** */

		app.Display();
	}
	return EXIT_SUCCESS;
}