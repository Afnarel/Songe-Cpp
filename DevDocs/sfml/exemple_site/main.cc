#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf; 

int main() {
 // Create the main window
 RenderWindow window(VideoMode(800, 600), "SFML window");

 SoundBuffer soundBuffer;
 Sound son;
 if (!soundBuffer.LoadFromFile("bienvenue.ogg"))
     return EXIT_FAILURE;
son.SetBuffer(soundBuffer);
//Sound son(soundBuffer);
son.Play();

 // Load a sprite to display
 Texture texture;
 if (!texture.LoadFromFile("background.jpg"))
     return EXIT_FAILURE;
 Sprite sprite(texture);

 // Create a graphical text to display
 Font font;
 if (!font.LoadFromFile("sansation.ttf"))
     return EXIT_FAILURE;
 Text text("Hello SFML", font, 50);
 text.SetColor(Color::Black);

 // Load a music to play
 Music music;
 if (!music.OpenFromFile("orchestral.ogg"))
     return EXIT_FAILURE;

 // Play the music
 music.Play();

 // Start the game loop
 while (window.IsOpened())
 {
     // Process events
     Event event;
     while (window.PollEvent(event))
     {
         // Close window : exit
         if (event.Type == Event::Closed)
             window.Close();
     }

     // Clear screen
     window.Clear();

     // Draw the sprite
     window.Draw(sprite);

     // Draw the string
     window.Draw(text);

     // Update the window
     window.Display();
 }

 return EXIT_SUCCESS;
}