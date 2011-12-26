#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

void init_game(Sprite &ball, Sprite &lbar, Sprite &rbar, const RenderWindow &app);
void init_ball(Sprite &ball, const RenderWindow &app);
void move_bar_up(int &top);
void move_bar_down(int &top);

// Const
const int W_WIDTH = 800, W_HEIGHT = 600;
const int BAR_WIDTH = 12, BAR_HEIGHT = 45;
const int BALL_DIAMETER = 12;
const int FROM_SIDE = 40;

int SPEED_X = 8, SPEED_Y = 8;
int BAR_SPEED = 10;

const int LBAR_INIT_X = FROM_SIDE - BAR_WIDTH/2;
const int LBAR_INIT_Y = W_HEIGHT/2 - BAR_HEIGHT/2;
const int RBAR_INIT_X = W_WIDTH - FROM_SIDE - BAR_WIDTH/2;
const int RBAR_INIT_Y = LBAR_INIT_Y;
int lbar_x = LBAR_INIT_X;
int lbar_y = LBAR_INIT_Y;
int rbar_x = RBAR_INIT_X;
int rbar_y = RBAR_INIT_Y;

bool paused;

int main() {

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

	Sprite rbar(texture_sprites);
	rbar.SetSubRect(IntRect(15,0,BAR_WIDTH,BAR_HEIGHT));

	Sprite ball(texture_sprites);
	ball.SetSubRect(IntRect(29,0,BALL_DIAMETER,BALL_DIAMETER));

	init_game(ball, lbar, rbar, app);


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
			switch(event.Type) {
				case Event::Closed:
					app.Close();
					break;
				case Event::KeyPressed:
					switch(event.Key.Code) {
						case Keyboard::Escape:
							app.Close();
							break;
						case Keyboard::Space:
							paused = false;
							break;
					}
					break;
			}
		}

		if(Keyboard::IsKeyPressed(Keyboard::Up)) {
			move_bar_up(rbar_y);
			// On pourrait utiliser un move plutot mais c'est pour l'exemple
			rbar.SetPosition(Vector2f(rbar_x,rbar_y));
		}
		if(Keyboard::IsKeyPressed(Keyboard::Z)) {
			move_bar_up(lbar_y);
			lbar.SetPosition(Vector2f(lbar_x,lbar_y));
		}
		if(Keyboard::IsKeyPressed(Keyboard::Down)) {
			move_bar_down(rbar_y);
			rbar.SetPosition(Vector2f(rbar_x,rbar_y));
		}
		if(Keyboard::IsKeyPressed(Keyboard::S)) {
			move_bar_down(lbar_y);
			lbar.SetPosition(Vector2f(lbar_x,lbar_y));
		}

		/* ****** *
		 * UPDATE *
		 * ****** */
		if(!paused) {
			 ball.Move(SPEED_X, SPEED_Y);

			 Vector2f pos = ball.GetPosition();

			 // Collision with window
			 if(pos.x > W_WIDTH || pos.x < 0) { // Right & Left
			 	SPEED_X *= -1;
			 	init_game(ball, lbar, rbar, app);
			 }
			 if(pos.y > W_HEIGHT || pos.y < 0) { // Bottom & Top
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

void init_game(Sprite &ball, Sprite &lbar, Sprite &rbar, const RenderWindow &app) {
	paused = true;
	init_ball(ball, app);
	lbar_x = LBAR_INIT_X;
	lbar_y = LBAR_INIT_Y;
	rbar_x = RBAR_INIT_X;
	rbar_y = RBAR_INIT_Y;
	lbar.SetPosition(Vector2f(LBAR_INIT_X,LBAR_INIT_Y));
	rbar.SetPosition(Vector2f(RBAR_INIT_X,RBAR_INIT_Y));
}

void init_ball(Sprite &ball, const RenderWindow &app) {
	int bx = app.GetWidth()/2 - BALL_DIAMETER/2;
	int by = app.GetHeight()/2 - BALL_DIAMETER/2;
	ball.SetPosition(Vector2f(bx, by));
}

void move_bar_up(int &top) {
	top -= BAR_SPEED;
	if(top < 0)
		top = 0;
}

void move_bar_down(int &top) {
	top += BAR_SPEED;
	int bottom = top + BAR_HEIGHT;
	if(bottom > W_HEIGHT)
		top = W_HEIGHT - BAR_HEIGHT;
}