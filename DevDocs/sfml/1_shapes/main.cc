#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
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

        // L'origine est en haut a gauche, l'axe y vers le bas et l'axe x vers la droite

        Shape forme;
        forme.AddPoint(Vector2f(100, 100), Color(128, 0, 0), Color(0, 0, 128)); // position (x,y), couleur, couleur de bordure du point
        forme.EnableOutline(true); // Afficher la bordure

        /*
        // Modification d'un point de la forme (l'index du point est donne comme premier parametre)
        forme.SetPointPosition(1, Vector2f(50, 100));
		forme.SetPointColor(1, Color::Black);
		forme.SetPointOutlineColor(1, Color(0, 128, 128));
		
		// Modification des proprietes de la forme entiere
		polygone.SetOutlineThickness(10);
		polygone.EnableFill(false);
		polygone.EnableOutline(true);
		*/

		app.Draw(forme);


		/* *************** *
		 * Tracer un carre *
		 * *************** */
		 Shape carre;
		 carre.AddPoint(Vector2f(200,200), Color(Color::Yellow), Color(Color::White)); // haut gauche
		 carre.AddPoint(Vector2f(400,200), Color(Color::Yellow), Color(Color::Red)); // haut droit
		 carre.AddPoint(Vector2f(400,400), Color(Color::Cyan), Color(Color::Green)); // bas droit
		 carre.AddPoint(Vector2f(200,400), Color(Color::Cyan), Color(Color::Blue)); // bas gauche
		 carre.SetOutlineThickness(20);
		 carre.EnableOutline(true);
		 carre.EnableFill(true);
		 app.Draw(carre);


        /* **************** */

        app.Display();
    }
    return EXIT_SUCCESS;
}