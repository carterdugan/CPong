#include <SFML/Graphics.h>
#include <math.h>

#include "paddle.h"
#include "ball.h"

// Some macros for the setting up the window
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 480
#define FPS 60

int main(void) {

	// Creating the video mode for the window
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
	sfRenderWindow* window;

	// The event for polling user input
	sfEvent event;

	// Create and setup window
	window = sfRenderWindow_create(mode, "Pong", sfClose | sfResize, NULL);
	sfRenderWindow_setFramerateLimit(window, FPS);

	// Create and setup players (paddles)
	pongPaddle player1 = pongPaddle_Create(PADDLE_XOFFSET, PADDLE_YOFFSET);
	pongPaddle player2 = pongPaddle_Create(WINDOW_WIDTH - PADDLE_WIDTH - PADDLE_XOFFSET, PADDLE_YOFFSET);

	// Create and setup the ball
	pongBall pong = pongBall_Create(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	// Main loop is oriented around whether or not the window
	// is open.
	while(sfRenderWindow_isOpen(window)) {

		// Check if the user closes the window
		while(sfRenderWindow_pollEvent(window, &event)) {
			if(event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}

		// Handle the users input for moving paddles
		if(sfKeyboard_isKeyPressed(sfKeyW))
			player1.y -= player1.velocity;
		if(sfKeyboard_isKeyPressed(sfKeyS))
			player1.y += player1.velocity;

		if(sfKeyboard_isKeyPressed(sfKeyUp))
			player2.y -= player2.velocity;
		if(sfKeyboard_isKeyPressed(sfKeyDown))
			player2.y += player2.velocity;

		// Clear the screen
		sfRenderWindow_clear(window, sfBlack);

		// Draw the paddles and the ball
		sfRenderWindow_drawRectangleShape(window, player1.shape, NULL);
		sfRenderWindow_drawRectangleShape(window, player2.shape, NULL);
		sfRenderWindow_drawCircleShape(window, pong.shape, NULL);

		// Update positions of paddle and ball
		pongPaddle_UpdatePosition(&player1);
		pongPaddle_UpdatePosition(&player2);
		pongBall_UpdatePosition(&pong);

		// **************************************************
		// Check for collision between ball and the paddles *
		// **************************************************

		// Tests are for finding what edges to test against
		float testX  = pong.x;
		float testY = pong.y;

		// Distances between X and Y of circle vs rectangle
		float dx;
		float dy;

		// Distance between closest points between rect vs circle
		float distance;

		// Check against rectangles depending on which direction the circle is traveling
		// Left rectangle
		if(pong.velocityX < 0) {
			if(pong.x < player1.x)
				testX = player1.x;
			else if(pong.x > player1.x + player1.width)
				testX = player1.x + player1.width;

			if(pong.y < player1.y)
				testY = player1.y;
			else if(pong.y > player1.y + player1.height)
				testY = player1.y + player1.height;
		}
		// Right triangle
		else {
			if(pong.x < player2.x)
				testX = player2.x;
			else if(pong.x > player2.x + player2.width)
				testX = player2.x + player2.width;

			if(pong.y < player2.y)
				testY = player2.y;
			else if(pong.y > player2.y + player2.height)
				testY = player2.y + player2.height;
		}

		dx = pong.x - testX;
		dy = pong.y - testY;
		distance = sqrt(dx*dx + dy*dy);

		// Check for collision with rectangles
		if(distance <= pong.radius)
			pong.velocityX = -pong.velocityX;

		// Check for collisions with walls
		if(pong.y + pong.radius >= WINDOW_HEIGHT || pong.y - pong.radius <= 0)
			pong.velocityY = -pong.velocityY;

		// Update the window
		sfRenderWindow_display(window);
	}

	return 0;
}