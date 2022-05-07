#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "bot.h"
#include "common.h"
#include "LTexture.h"
#include "LTexture.cpp"
using namespace std;

LTexture gBotTexture;

//Box collision detector
bool checkCollision( SDL_Rect a, vector<SDL_Rect> wall );
bool checkCollision_Out( SDL_Rect a, vector<SDL_Rect> wall );
bool checksingle_Out( SDL_Rect a, SDL_Rect b );

Bot::Bot()
{
    //Initialize the offsets
    botPosX = 32;
    botPosY = 448;
    
    //Set collision box dimension
	mCollider.w = BOT_WIDTH;
	mCollider.h = BOT_HEIGHT;


    //Initialize the velocity
    botVelX = 0;
    botVelY = 0;
}


void Bot::handleEvent(int playerX, int playerY,SDL_Rect dot)
{	
    counter++;
    if (checksingle_Out( dot, mCollider)) counter = 0;
    if (counter > 1000 && abs(botPosX - playerX) + abs(botPosY - playerY) <= 1000){
        if (playerX < botPosX) botVelX = -3;
        else if(playerX == botPosX) botVelX=0;
        else botVelX = 3;

        if (playerY < botPosY) botVelY = -3;
        else if(playerY == botPosY) botVelY=0;
        else botVelY = 3;
    }
    else{
        int arr[10] = {-4,-3,-2,-1,0,1,2,3,4,5};
        //If a key was pressed
        srand(time(0));
        if(rand()%2==0){
            botVelX=arr[rand() % 10];
            botVelY=0;
        }
        else{
            botVelY=arr[rand() % 10];
            botVelX=0;
        }
    }
    	//cout<<botVelX<<" X "<<botVelY<<" Y "<<endl;

	
}

void Bot::move(vector<SDL_Rect> wall)
{
    //Move the dot left or right
    botPosX += botVelX;
    mCollider.x = botPosX;	
    																					

    //If the dot went too far to the left or right
    if( ( botPosX < 0 ) || ( botPosX + BOT_WIDTH > LEVEL_WIDTH )  || !checkCollision( mCollider, wall )  )
    {
        //Move back
        botPosX -= botVelX;
        mCollider.x = botPosX;
    }

    //Move the dot up or down
    botPosY += botVelY;
    mCollider.y = botPosY;

    //If the dot went too far up or down
    if( ( botPosY < 0 ) || ( botPosY + BOT_HEIGHT > LEVEL_HEIGHT )  || !checkCollision( mCollider, wall ) )
    {
        //Move back
        botPosY -= botVelY;
        mCollider.y = botPosY;
    }
    
    
}

void Bot::render( int camX, int camY )
{
    //Show the dot relative to the camera
	gBotTexture.render( botPosX - camX, botPosY - camY );
}

int Bot::getPosX()
{
	return botPosX;
}

int Bot::getPosY()
{
	return botPosY;
}


bool checksingle( SDL_Rect a, SDL_Rect b )
{	//cout<<"p";
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( topA < topB )
    {
        return false;
    }

    if( bottomA > bottomB )
    {
        return false;
    }

    if( leftA < leftB )
    {
        return false;
    }

    if( rightA > rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

bool checkCollision( SDL_Rect a, vector<SDL_Rect> wall )
{	for (int i = 0; i < static_cast<int>(wall.size()); i++){
		if(checksingle(a,wall[i])){
			return true;
		}
	}
	return false;
}

bool checksingle_Out( SDL_Rect a, SDL_Rect b )
{	//cout<<"p";
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

bool checkCollision_Out( SDL_Rect a, vector<SDL_Rect> wall )
{	for (int i = 0; i < static_cast<int>(wall.size()); i++){
		if(checksingle_Out(a,wall[i])){
			return true;
		}
	}
	return false;
}

