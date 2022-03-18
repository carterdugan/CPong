LIBS=-lm -lcsfml-graphics -lcsfml-window -lcsfml-system

all: gfx game pong

gfx:
	gcc src/gfx.c -c -I./

game:
	gcc src/game.c -c -I./

pong: game.o gfx.o
	gcc src/main.c game.o gfx.o $(LIBS) -o pong -I./

clean:
	rm *.o
	rm pong