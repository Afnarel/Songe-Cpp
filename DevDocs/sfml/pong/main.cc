#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {

	// Const
	const int W_WIDTH = 800, W_HEIGHT = 600;
	const int BAR_WIDTH = 12, BAR_HEIGHT = 45;
	const int BALL_DIAMETER = 12;
	const int FROM_SIDE = 20;

	int SPEED_X = 8, SPEED_Y = 8;

	int lbar_x = FROM_SIDE - BAR_WIDTH/2;
	int lbar_y = W_HEIGHT/2 - BAR_HEIGHT/2;
	int rbar_x = W_WIDTH - FROM_SIDE - BAR_WIDTH/2;
	int rbar_y = lbar_y;

	RenderWindow app(VideoMode(W_WIDTH, W_HEIGHT, 32), "Pong !");
	app.SetFramerateLimit(60); // Limite la fenêtre à 60 images par seconde

	// Init objects
	Image img_sprites;
	if (!img_sprites.LoadFromFile("sprites.png"))
		return EXIT_FAILURE;
	img_sprites.CreateMaskFromColor(Color::White);

	Texture texture_sprites;
	if (!texture_sprites.LoadFromImage(img_sprites))
		return EXIT_FAILURE;

	Sprite lbar(texture_sprites);
	lbar.SetSubRect(IntRect(0,0,BAR_WIDTH,BAR_HEIGHT));
	lbar.SetPosition(Vector2f(lbar_x,lbar_y));

	Sprite rbar(texture_sprites);
	rbar.SetSubRect(IntRect(15,0,BAR_WIDTH,BAR_HEIGHT));
	rbar.SetPosition(Vector2f(rbar_x,rbar_y));

	Sprite ball(texture_sprites);
	ball.SetSubRect(IntRect(29,0,BALL_DIAMETER,BALL_DIAMETER));


	Texture texture_background;
	if (!texture_background.LoadFromFile("background.png"))
		return EXIT_FAILURE;
	Sprite background(texture_background);

	// -- END init

	while (app.IsOpened()) {
		/* ****** *
		 * EVENTS *
		 * ****** */
		Event event;
		while (app.PollEvent(event)) {
			if (event.Type == Event::Closed)
				app.Close();
		}

		/* ****** *
		 * UPDATE *
		 * ****** */

		 ball.Move(SPEED_X, SPEED_Y);

		 Vector2f pos = ball.GetPosition();
		 // Collision with window
		 if(pos.x > W_WIDTH || pos.x < 0) {
		 	SPEED_X *= -1;
		 }
		 if(pos.y > W_HEIGHT || pos.y < 0) {
		 	SPEED_Y *= -1;
		 }

		 // Collision with bars
		 if( !(pos.x >= lbar_x + BAR_WIDTH || pos.x + BALL_DIAMETER <= lbar_x || 
		 pos.y >= lbar_y  + BAR_HEIGHT || pos.y + BALL_DIAMETER <= lbar_y) ) {
		 	SPEED_X *= -1;
		 	ball.Move(SPEED_X, SPEED_Y);
		 }
		 if( !(pos.x >= rbar_x + BAR_WIDTH || pos.x + BALL_DIAMETER <= rbar_x || 
		 pos.y >= rbar_y  + BAR_HEIGHT || pos.y + BALL_DIAMETER <= rbar_y) ) {
		 	SPEED_X *= -1;
		 	ball.Move(SPEED_X, SPEED_Y);
		 }

		/* ****** *
		 * RENDER *
		 * ****** */
		app.Clear();

		app.Draw(background);
		app.Draw(lbar);
		app.Draw(rbar);
		app.Draw(ball);

		app.Display();
	}
	return EXIT_SUCCESS;
}