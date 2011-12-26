#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow app(VideoMode(800, 600, 32), "Ma premiere fenetre SFML !");
	app.SetFramerateLimit(60); // Limite la fenêtre à 60 images par seconde

    while (app.IsOpened())
    {
        Event event;
        while (app.PollEvent(event))
        {
            if (event.Type == Event::Closed)
                app.Close();
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
		/*
		// Transformations possibles
		mon_sprite.SetPosition(Vector2f(x, y)); // Positionnement
		mon_sprite.Move(Vector2f(x, y)); 		// Translation
		mon_sprite.Scale(Vector2f(x, y)); 		// Redimensionnement
		mon_sprite.SetColor(Color(r, g, b, a)); // Coloration
		mon_sprite.Rotate(degrés); 				// Rotation (anti-clockwise)

		// Accesseurs
		Vector2f pos = mon_sprite.GetPosition();

		// Associer un sprite a une partie d'une image seulement
		// (on peut aussi le faire directement dans le constructeur de Texture)
		mon_sprite.SetSubRect(IntRect(x1, y1, x_offset, y_offset));

		// Appliquer un masque de couleur a une *image* (rend la couleur donee transparente)
		image.CreateMaskFromColor(Color(r, g, b));

		// Rendre un sprite transparent
		sprite.SetColor(Color(255,255,255,<alpha>)); // alpha : 255=opaque / 0=invisible
		*/

		Texture texture_zozor;
		if(!texture_zozor.LoadFromFile("zozor.png"))
			return EXIT_FAILURE;
		Sprite zozor(texture_zozor);

		zozor.SetSubRect(IntRect(0,0,95,320));
		zozor.SetPosition(Vector2f(150,150));
		app.Draw(zozor);

		zozor.SetSubRect(IntRect(95,0,95,320));
		zozor.SetPosition(Vector2f(245,200));
		app.Draw(zozor);

		zozor.SetSubRect(IntRect(190,0,95,320));
		zozor.SetPosition(Vector2f(340,50));
		app.Draw(zozor);

        /* **************** */

        app.Display();
    }
    return EXIT_SUCCESS;
}