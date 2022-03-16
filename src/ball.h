#ifndef BALL_HEADER
#define BALL_HEADER

#include <SFML/Graphics.h>

#define BALL_RADIUS 10
#define BALL_VELOCITY_X 10
#define BALL_VELOCITY_Y 5

typedef struct {

	int radius, x, y;

	short velocityX;
	short velocityY;

	sfCircleShape* shape;


} pongBall;

pongBall pongBall_Create(int x, int y);
void pongBall_UpdatePosition(pongBall* pong);
void pongBall_SetColor(unsigned char red, unsigned char green, unsigned char blue);

#endif