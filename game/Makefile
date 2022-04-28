CC=g++

CFLAGS=-c -Wall

SDL_PATH=/usr/include/SDL2/

all : main 

main :  game.o
	g++ game.cpp -w -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -I $(SDL_PATH) -L $(SDL_PATH) -o main
	
03_event_driven_programming.o : game.cpp
	$(CC) $(CFLAGS) game.cpp

clean:
	rm -rf *o main
