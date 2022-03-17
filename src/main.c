#include <SFML/Graphics.h>

#include "game.h"

int main(void) {

	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
	pongWindow win = pongWindow_Create(mode);

	pongGame_MainMenu(&win);

	return 0;
}