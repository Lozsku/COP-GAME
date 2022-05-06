#include <vector>
using namespace std;

#ifndef DOT_H
#define DOT_H
//The dot that will move around on the screen
class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Number of Lives
		int lives;		
		
		//Maximum axis velocity of the dot
		int DOT_VEL;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move(vector<SDL_Rect> wall);
		
		//updates life
		void update_life(vector<SDL_Rect> bots);
		
		void up_life();

		//Shows the dot on the screen relative to the camera
		void render( int camX, int camY );
		
		//Shows number of lives
		void LivesRender();

		


		//Position accessors
		int getPosX();
		int getPosY();
		
		//Dot's collision box
		SDL_Rect mCollider;
		
		//Special Powers/badges
		int healthkit;
		int ID_card;
		int attendence;
		int mask;
		int key;
		int keystate;
		int money;
		int hungry;
		int food;
		int foodRajadhani;
		int foodMasala;
		int foodDelhi16;
		int foodShuru;
		int foodAmul;
		int foodNescafe;
		int foodHimadri;
		int relaystate;
		void collect(int C);
		
		void PowersRender(int camX,int camY,vector<SDL_Rect> wall);
		//earn money in relay 10
		void relayMoney(int camX, int camY);
		void FoodRender(int camX,int camY,vector<SDL_Rect> wall);
		void YuluRender(int camX,int camY,vector<SDL_Rect> wall);
		void MoneyRender();
		
		
		

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
		
		
		
		
		
		//To update State of lives
		int state_life;
		
		//handle event
		int handle_state;
};

#endif
