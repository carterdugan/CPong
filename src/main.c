#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

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

		// Check for collision between ball and the paddles
		// This is an incredibly flawed way of doing this, but
		// it works for the sake of this demonstration as it is
		// simple and works... for the most part. The alternative
		// way of doing this would be to have actual collision
		// detection between the ball and each paddle.
		if(pong.y + pong.radius >= WINDOW_HEIGHT || pong.y - pong.radius <= 0)
			pong.velocityY = - pong.velocityY;
		if (pong.x + pong.radius >= player2.x) {
			if(pong.y + pong.radius >= player2.y && pong.y - pong.radius <= player2.y + player2.height) {
				pong.velocityX = - pong.velocityX;
			}
		}
		else if (pong.x - pong.radius <= player1.x + player1.width) {
			if(pong.y + pong.radius >= player1.y && pong.y - pong.radius <= player1.y + player1.height) {
				pong.velocityX = - pong.velocityX;
			}
		}

		// Update the window
		sfRenderWindow_display(window);
	}

	return 0;
}