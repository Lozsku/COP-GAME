CC=g++

CFLAGS=-c -Wall

SDL_PATH=/usr/include/SDL2/

all : main 

main :  game.o dot.o wall.o bot.o LTexture.o
	g++ game.cpp -w -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -I $(SDL_PATH) -L $(SDL_PATH) -o main
	
game.o : game.cpp
	$(CC) $(CFLAGS) game.cpp
	
dot.o : dot.cpp
	$(CC) $(CFLAGS) dot.cpp
	
wall.o : wall.cpp
	$(CC) $(CFLAGS) wall.cpp
	
bot.o : bot.cpp
	$(CC) $(CFLAGS) bot.cpp
	
LTexture.o : LTexture.cpp
	$(CC) $(CFLAGS) LTexture.cpp

clean:
	rm -rf *o main
