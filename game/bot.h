#include <vector>
using namespace std;

#ifndef BOT_H
#define BOT_H
class Bot
{
    public:
		//The dimensions of the dot
		static const int BOT_WIDTH = 20;
		static const int BOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int BOT_VEL = 10;

		//Initializes the variables
		Bot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent(  );

		//Moves the dot
		void move(vector<SDL_Rect> wall);

		//Shows the dot on the screen relative to the camera
		void render( int camX, int camY );

		//Position accessors
		int getPosX();
		int getPosY();

    private:
		//The X and Y offsets of the dot
		int botPosX, botPosY;

		//The velocity of the dot
		int botVelX, botVelY;
		
		//Dot's collision box
		SDL_Rect mCollider;
};
#endif
