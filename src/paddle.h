#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include <SFML/Graphics.h>

#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 100
#define PADDLE_XOFFSET 50
#define PADDLE_YOFFSET 50
#define PADDLE_VELOCITY 10

typedef struct {

	int width, height, x, y;

	short velocity;

	sfRectangleShape* shape;


} pongPaddle;

pongPaddle pongPaddle_Create(int x, int y);
void pongPaddle_UpdatePosition(pongPaddle* pong);
void pongPaddle_SetColor(unsigned char red, unsigned char green, unsigned char blue);

#endif