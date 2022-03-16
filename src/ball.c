#include "ball.h"

pongBall pongBall_Create(int x, int y) {
	sfCircleShape *shape = sfCircleShape_create();
	sfCircleShape_setRadius(shape, BALL_RADIUS);
	sfCircleShape_setOrigin(shape, (sfVector2f){BALL_RADIUS, BALL_RADIUS});

	return (pongBall){
		BALL_RADIUS,
		x, y,
		BALL_VELOCITY_X, -BALL_VELOCITY_Y,
		shape
	};
}

void pongBall_UpdatePosition(pongBall* pong) {
	pong->x += pong->velocityX;
	pong->y += pong->velocityY;
	sfCircleShape_setPosition(pong->shape, (sfVector2f){pong->x, pong->y});
}

void pongBall_SetColor(unsigned char red, unsigned char green, unsigned char blue) {

}