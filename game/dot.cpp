#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "dot.h"
#include "bot.cpp"
//#include "common.h"
#include "LTexture.h"
//#include "LTexture.cpp"
using namespace std;

LTexture gDotTexture;
LTexture gLivesTexture;



Dot::Dot()
{
    //Initialize the offsets
    mPosX = 32;
    mPosY = 448;
    
    //Set collision box dimension
	mCollider.w = DOT_WIDTH;
	mCollider.h = DOT_HEIGHT;


    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL; break;
            case SDLK_DOWN: mVelY += DOT_VEL; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_DOWN: mVelY -= DOT_VEL; break;
            case SDLK_LEFT: mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}

void Dot::move( vector<SDL_Rect> wall )
{
    //Move the dot left or right
    mPosX += mVelX;
	mCollider.x = mPosX;

    //If the dot collided or went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) || !checkCollision( mCollider, wall ) )
    {
        //Move back
        int i=abs(mVelX);
        while(i>=0){
        	
        	if(!checkCollision(mCollider,wall)){
        		if(mVelX>0){mPosX -= 1;}
        		else if(mVelX<0){mPosX+=1;}
        		mCollider.x=mPosX;
        	}
        	i-=1;
        }
        
        	//mPosX-=mVelX;
		mCollider.x = mPosX;
    }

    //Move the dot up or down
    mPosY += mVelY;
	mCollider.y = mPosY;

    //If the dot collided or went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) || !checkCollision( mCollider, wall ) )
    {
        //Move back
        int i=abs(mVelY);
        while(i>=0){
        	
        	if(!checkCollision(mCollider,wall)==true){
        		if(mVelY>0){mPosY -= 1;}
        		else if(mVelY<0){mPosY+=1;}
        		mCollider.y=mPosY;
        		
        	}
        	i-=1;
        }
        	//mPosY-=mVelY;
		mCollider.y = mPosY;
    }
}

void Dot::render( int camX, int camY )
{
    //Show the dot relative to the camera
	gDotTexture.render( mPosX - camX, mPosY - camY );
}

int Dot::getPosX()
{
	return mPosX;
}

int Dot::getPosY()
{
	return mPosY;
}

void Dot::LivesRender(int camX,int camY)
{	
	if(lives==0){
		gLivesTexture.loadFromFile( "images/dore.png" );
	}
	else if(lives==1){
		gLivesTexture.loadFromFile( "images/dore.png" );
	}
	else if(lives==2){
		gLivesTexture.loadFromFile( "images/dore.png" );
	}
	else if(lives==3){
		gLivesTexture.loadFromFile( "images/dore.png" );
	}
	else if(lives==4){
		gLivesTexture.loadFromFile( "images/dore.png" );
	}
	else if(lives==5){
		gLivesTexture.loadFromFile( "images/dore.png" );
	}
	gLivesTexture.render(camX,camY);	

}



