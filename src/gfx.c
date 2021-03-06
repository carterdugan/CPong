#include "gfx.h"

pongWindow pongWindow_Create(sfVideoMode mode) {
	pongWindow win = {
		sfRenderWindow_create(mode, "Pong", sfClose | sfResize, NULL),
		sfFont_createFromFile(PATH_TO_FONT)
	};
	sfRenderWindow_setFramerateLimit(win.sfmlWindow, FPS);
	return win;
}


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

void pongBall_SetColor(pongBall* ball, unsigned char red, unsigned char green, unsigned char blue) {
	sfCircleShape_setFillColor(ball->shape, (sfColor){red, green, blue, 255});
}


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

void pongPaddle_SetColor(pongPaddle* rect, unsigned char red, unsigned char green, unsigned char blue) {
	sfRectangleShape_setFillColor(rect->shape, (sfColor){red, green, blue, 255});	
}


pongGuiButton pongGuiButton_Create(int x, int y, int width, int height) {
	pongGuiButton button = {
		x, y, width, height,
		sfRectangleShape_create()
	};

	sfRectangleShape_setPosition(button.shape, (sfVector2f){x, y});
	sfRectangleShape_setSize(button.shape, (sfVector2f){width, height});

	return button;
}

bool pongGuiButton_CheckHover(pongWindow* window, pongGuiButton* button, sfColor color) {
	int x = sfMouse_getPosition((sfWindow*)window->sfmlWindow).x;
	int y = sfMouse_getPosition((sfWindow*)window->sfmlWindow).y;

	return (x >= button->x && x <= button->x + button->width
		&& y >= button->y && y <= button->y + button->height);
}

bool pongGuiButton_CheckClick(pongWindow* window, pongGuiButton* button, sfColor color) {
	return(pongGuiButton_CheckHover(window, button, color)
		&& sfMouse_isButtonPressed(sfMouseLeft));
}

void pongGuiButton_SetColor(pongGuiButton* button, unsigned char red, unsigned char green, unsigned char blue) {
	sfRectangleShape_setFillColor(button->shape, (sfColor){red, green, blue, 255});
}