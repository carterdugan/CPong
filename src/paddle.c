#include "paddle.h"

pongPaddle pongPaddle_Create(int x, int y) {

	sfRectangleShape *shape = sfRectangleShape_create();
	sfRectangleShape_setSize(shape, (sfVector2f){PADDLE_WIDTH, PADDLE_HEIGHT});

	return (pongPaddle){
		PADDLE_WIDTH, PADDLE_HEIGHT,
		x, y,
		PADDLE_VELOCITY,
		shape
	};
}
void pongPaddle_UpdatePosition(pongPaddle* pad) {
	sfRectangleShape_setPosition(pad->shape, (sfVector2f){pad->x, pad->y});
}

void pongPaddle_SetColor(unsigned char red, unsigned char green, unsigned char blue) {
	
}