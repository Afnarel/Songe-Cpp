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
				case Event::KeyPressed:
					switch(event.Key.Code) {
						case Keyboard::Escape:
							app.Close();
							break;
					}
			}
		}

		Font font;
		// Chargement à partir d'un fichier sur le disque
		if(!font.LoadFromFile("sansation.ttf"))
			return EXIT_SUCCESS;
		
		Text text("Hello SFML", font, 50);
 		text.SetColor(Color::Red);

 		/*
 		text.Move(Vector2f(x, y)); // Translation
		text.Scale(Vector2f(x, y)); // Redimensionnement
		text.SetColor(Color(r, g, b, a)); // Coloration
		text.Rotate(degré); // Rotation
		*/
		

		app.Clear();
		app.Draw(text);
		app.Display();
	}
	return EXIT_SUCCESS;
}