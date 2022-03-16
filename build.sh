cd src
gcc gfx.c -c -I./
gcc game.c -c -I./
gcc main.c game.o gfx.o -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -I./ -o ../pong