#ifndef GFX_H
#define GFX_H

#include <stdbool.h>
#include <SFML/Graphics.h>

// Some macros for the setting up the window
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 480
#define FPS 60
#define PATH_TO_FONT "assets/pong_font.TTF"

#define BALL_RADIUS 10
#define BALL_VELOCITY_X 15
#define BALL_VELOCITY_Y 5

#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 100
#define PADDLE_XOFFSET 50
#define PADDLE_YOFFSET 50
#define PADDLE_VELOCITY 10


typedef struct {
	sfRenderWindow* sfmlWindow;
	sfFont* font;
} pongWindow;

pongWindow pongWindow_Create(sfVideoMode mode);


typedef struct {

	int radius, x, y;

	short velocityX;
	short velocityY;

	sfCircleShape* shape;


} pongBall;

pongBall pongBall_Create(int x, int y);
void pongBall_UpdatePosition(pongBall* pong);
void pongBall_SetColor(pongBall* ball, unsigned char red, unsigned char green, unsigned char blue);


typedef struct {

	int width, height, x, y;

	short velocity;

	sfRectangleShape* shape;


} pongPaddle;

pongPaddle pongPaddle_Create(int x, int y);
void pongPaddle_UpdatePosition(pongPaddle* pong);
void pongPaddle_SetColor(pongPaddle* rect, unsigned char red, unsigned char green, unsigned char blue);


// *************
// * GUI STUFF *
// *************

typedef struct {

	int x, y, width, height;

	sfRectangleShape* shape;

} pongGuiButton;

pongGuiButton pongGuiButton_Create(int x, int y, int width, int height);
bool pongGuiButton_CheckHover(pongWindow* window, pongGuiButton* button, sfColor color);
bool pongGuiButton_CheckClick(pongWindow* window, pongGuiButton* button, sfColor color);
void pongGuiButton_SetColor(pongGuiButton* button, unsigned char red, unsigned char green, unsigned char blue);

#endif