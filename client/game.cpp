/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "wall.h"
#include "wall.cpp"
//#include "bot.cpp"
#include "bot.h"
#include "dot.cpp"
#include "dot.h"
//#include "common.h"
using namespace std;

//The dimensions of the level
/*const int LEVEL_WIDTH = 4704;
const int LEVEL_HEIGHT = 5632;*/

//Screen dimension constants
/*const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;*/


//creating wall
Wall_Array wallArray;



	
//*************************************************************************************************************************//

//*************************************************************************************************************************//

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();



//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
//####SDL_Renderer* gRenderer = NULL;

//Walking animation
const int WALKING_ANIMATION_FRAMES = 4;
SDL_Rect gSpriteClips[ WALKING_ANIMATION_FRAMES ];
SDL_Rect gSpriteClips_right[ WALKING_ANIMATION_FRAMES ];
SDL_Rect gSpriteClips_left[ WALKING_ANIMATION_FRAMES ];
SDL_Rect gSpriteClips_up[ WALKING_ANIMATION_FRAMES ];
SDL_Rect gSpriteClips_down[ WALKING_ANIMATION_FRAMES ];

//Scene textures
//####LTexture gDotTexture;
LTexture gBGTexture;
//####LTexture gBotTexture;





//*************************************************************************************************************************//

//*************************************************************************************************************************//

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if( !gDotTexture.loadFromFile( "images/dore.png" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips Right
		gSpriteClips_right[ 0 ].x =   1;
		gSpriteClips_right[ 0 ].y =  69;
		gSpriteClips_right[ 0 ].w =  21;
		gSpriteClips_right[ 0 ].h =  34;

		gSpriteClips_right[ 1 ].x =  23;
		gSpriteClips_right[ 1 ].y =  69;
		gSpriteClips_right[ 1 ].w =  21;
		gSpriteClips_right[ 1 ].h =  34;
		
		gSpriteClips_right[ 2 ].x =  46;
		gSpriteClips_right[ 2 ].y =  69;
		gSpriteClips_right[ 2 ].w =  21;
		gSpriteClips_right[ 2 ].h =  34;

		gSpriteClips_right[ 3 ].x =  68;
		gSpriteClips_right[ 3 ].y =  69;
		gSpriteClips_right[ 3 ].w =  21;
		gSpriteClips_right[ 3 ].h =  34;
		
		//Set sprite clips Left
		gSpriteClips_left[ 0 ].x =   1;
		gSpriteClips_left[ 0 ].y =  34;
		gSpriteClips_left[ 0 ].w =  21;
		gSpriteClips_left[ 0 ].h =  34;

		gSpriteClips_left[ 1 ].x =  23;
		gSpriteClips_left[ 1 ].y =  34;
		gSpriteClips_left[ 1 ].w =  21;
		gSpriteClips_left[ 1 ].h =  34;
		
		gSpriteClips_left[ 2 ].x =  46;
		gSpriteClips_left[ 2 ].y =  34;
		gSpriteClips_left[ 2 ].w =  21;
		gSpriteClips_left[ 2 ].h =  34;

		gSpriteClips_left[ 3 ].x =  68;
		gSpriteClips_left[ 3 ].y =  34;
		gSpriteClips_left[ 3 ].w =  21;
		gSpriteClips_left[ 3 ].h =  34;
		
		//Set sprite clips UP
		gSpriteClips_up[ 0 ].x =   1;
		gSpriteClips_up[ 0 ].y = 104;
		gSpriteClips_up[ 0 ].w =  21;
		gSpriteClips_up[ 0 ].h =  34;

		gSpriteClips_up[ 1 ].x =  23;
		gSpriteClips_up[ 1 ].y = 104;
		gSpriteClips_up[ 1 ].w =  21;
		gSpriteClips_up[ 1 ].h =  34;
		
		gSpriteClips_up[ 2 ].x =  46;
		gSpriteClips_up[ 2 ].y = 104;
		gSpriteClips_up[ 2 ].w =  21;
		gSpriteClips_up[ 2 ].h =  34;

		gSpriteClips_up[ 3 ].x =  68;
		gSpriteClips_up[ 3 ].y = 104;
		gSpriteClips_up[ 3 ].w =  21;
		gSpriteClips_up[ 3 ].h =  34;
		
		//Set sprite clips Down
		gSpriteClips_down[ 0 ].x =   1;
		gSpriteClips_down[ 0 ].y =   0;
		gSpriteClips_down[ 0 ].w =  21;
		gSpriteClips_down[ 0 ].h =  34;

		gSpriteClips_down[ 1 ].x =  23;
		gSpriteClips_down[ 1 ].y =  00;
		gSpriteClips_down[ 1 ].w =  21;
		gSpriteClips_down[ 1 ].h =  34;
		
		gSpriteClips_down[ 2 ].x =  46;
		gSpriteClips_down[ 2 ].y =  00;
		gSpriteClips_down[ 2 ].w =  21;
		gSpriteClips_down[ 2 ].h =  34;

		gSpriteClips_down[ 3 ].x =  68;
		gSpriteClips_down[ 3 ].y =  00;
		gSpriteClips_down[ 3 ].w =  21;
		gSpriteClips_down[ 3 ].h =  34;
		
		gSpriteClips[0]=gSpriteClips_down[0];
		gSpriteClips[1]=gSpriteClips_down[0];
		gSpriteClips[2]=gSpriteClips_down[0];
		gSpriteClips[3]=gSpriteClips_down[0];
	}
	
	if( !gBotTexture.loadFromFile( "images/dot.bmp" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	//Load background texture
	if( !gBGTexture.loadFromFile( "images/map.png" ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gDotTexture.free();
	gBotTexture.free();
	gBGTexture.free();

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}



int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Current animation frame
			int frame = 0;


			//The dot that will be moving around on the screen
			Dot dot;
			Bot bot;
			
			
			
			
			//The camera area
			SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					
					
					//**********************************************************??
					//User presses a key
					else if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{
							case SDLK_UP:
							gSpriteClips[0]=gSpriteClips_up[0];
							gSpriteClips[1]=gSpriteClips_up[1];
							gSpriteClips[2]=gSpriteClips_up[2];
							gSpriteClips[3]=gSpriteClips_up[3];
							break;

							case SDLK_DOWN:
							gSpriteClips[0]=gSpriteClips_down[0];
							gSpriteClips[1]=gSpriteClips_down[1];
							gSpriteClips[2]=gSpriteClips_down[2];
							gSpriteClips[3]=gSpriteClips_down[3];
							break;

							case SDLK_LEFT:
							gSpriteClips[0]=gSpriteClips_left[0];
							gSpriteClips[1]=gSpriteClips_left[1];
							gSpriteClips[2]=gSpriteClips_left[2];
							gSpriteClips[3]=gSpriteClips_left[3];
							break;

							case SDLK_RIGHT:
							gSpriteClips[0]=gSpriteClips_right[0];
							gSpriteClips[1]=gSpriteClips_right[1];
							gSpriteClips[2]=gSpriteClips_right[2];
							gSpriteClips[3]=gSpriteClips_right[3];
							break;

							default:
							gSpriteClips[0]=gSpriteClips_down[0];
							gSpriteClips[1]=gSpriteClips_down[0];
							gSpriteClips[2]=gSpriteClips_down[0];
							gSpriteClips[3]=gSpriteClips_down[0];
							break;
						}
					}
					//***********************************************************??
					

					//Handle input for the dot
					dot.handleEvent( e );
				}
				bot.handleEvent();
				//Move the dot
				dot.move(wallArray.wall);
				
				//Move the boy
				bot.move(wallArray.wall);

				//Center the camera over the dot
				camera.x = ( dot.getPosX() + Dot::DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2;
				camera.y = ( dot.getPosY() + Dot::DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

				//Keep the camera in bounds
				if( camera.x < 0 )
				{ 
					camera.x = 0;
				}
				if( camera.y < 0 )
				{
					camera.y = 0;
				}
				if( camera.x > LEVEL_WIDTH - camera.w )
				{
					camera.x = LEVEL_WIDTH - camera.w;
				}
				if( camera.y > LEVEL_HEIGHT - camera.h )
				{
					camera.y = LEVEL_HEIGHT - camera.h;
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render background
				gBGTexture.render( 0, 0, &camera );

				//Render objects
				//dot.render( camera.x, camera.y );
				//********************************************************??
				//Render current frame
				SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];
				gDotTexture.render( dot.getPosX() - camera.x, dot.getPosY() - camera.y, currentClip );


				//Go to next frame
				++frame;

				//Cycle animation
				if( frame / 4 >= WALKING_ANIMATION_FRAMES )
				{
					frame = 0;
				}
				//*********************************************************??
				
				
				//Render objects
				//dot.render( camera.x, camera.y );
				
				//Render bot
				bot.render(camera.x,camera.y);

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
