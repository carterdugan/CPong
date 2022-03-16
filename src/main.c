#include <SFML/Graphics.h>

#include "game.h"

int main(void) {

	// Creating the video mode for the window
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
	pongWindow win = pongWindow_Create(mode);

	pongGame_Game(&win);

	return 0;
}