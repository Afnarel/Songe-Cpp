#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	/* ***************** *
	 * Creer une fenetre *
	 * ***************** */
	 // Solution 1
	RenderWindow app(VideoMode(800, 600, 32), "Ma premiere fenetre SFML !");
	app.SetFramerateLimit(60); // Limite la fenêtre à 60 images par seconde
	/*
	 // Solution 2
	RenderWindow app;
	app.Create(VideoMode(800, 600, 32), "Ma premiere fenetre SFML !");
	*/

	/* ***** *
	 * Flags *
	 * ***** */
	 /*
	 RenderWindow app(VideoMode(800, 600, 32), "Ma premiere fenetre SFML ! ", Style::Close | Style::Titlebar );

	 Redimensionnement = Style::Resize ;
	 Barre de titre = Style::Titlebar ;
	 Bouton de fermeture = Style::Close ;
	 Mode plein écran = Style::Fullscreen

	 Dans le cas du plein ecran, VideoMode(...) devient VideoMode::GetMode(0)
	 lors de la creation de la fenetre.

	 */

	/* ***************** *
	 * Boucle principale *
	 * ***************** */

    while (app.IsOpened())
    {
        Event event;
        
        while (app.PollEvent(event))
        {
            if (event.Type == Event::Closed)
                app.Close();
        }

        // Remplissage de l'écran (couleur noire par défaut)
        app.Clear();

        // Affichage de la fenêtre à l'écran
        app.Display();
    }
    return EXIT_SUCCESS;
}