cd src
gcc paddle.c -c -I./
gcc ball.c -c -I./
gcc main.c ball.o paddle.o -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -I./ -o ../pong