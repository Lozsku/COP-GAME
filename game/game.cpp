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
//intial screen
LTexture gPromptTexture;
//current mainTexture

LTexture gcurrentTexture1;
//####LTexture gBotTexture;

//The music that will be played
Mix_Music *gMusic = NULL;


//The sound effects that will be used
Mix_Chunk *gKeycollect = NULL;
Mix_Chunk *gHealth = NULL;
Mix_Chunk *gHealthkit = NULL;
Mix_Chunk *gPointsinc = NULL;
Mix_Chunk *gFoodeaten = NULL;
Mix_Chunk *gBark = NULL;
Mix_Chunk *gWinsound = NULL;
Mix_Chunk *gYulu = NULL;

//*************************************************************************************************************************//

//*************************************************************************************************************************//

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 )
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
				
				//Initialize SDL_mixer
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
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
	
	if( !gBotTexture.loadFromFile( "images/evildog.png" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}
	
	//Load initial background texture
	if( !gPromptTexture.loadFromFile( "images/initialdisplay.png" ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	
	//Load background texture
	if( !gBGTexture.loadFromFile( "images/map.png" ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	
	//Load music
	gMusic = Mix_LoadMUS( "music and sounds/beatmusic.wav" );
	if( gMusic == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	
	//Load sound effects
	gKeycollect = Mix_LoadWAV( "music and sounds/keycollect.wav" );
	if( gKeycollect == NULL )
	{
		printf( "Failed to load keycollect sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	
	gHealthkit = Mix_LoadWAV( "music and sounds/Healthkit.wav" );
	if( gHealthkit == NULL )
	{
		printf( "Failed to load Healthkit sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	
	gHealth = Mix_LoadWAV( "music and sounds/Health.wav" );
	if( gHealth == NULL )
	{
		printf( "Failed to load Health sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	
	gPointsinc = Mix_LoadWAV( "music and sounds/pointsinc.wav" );
	if( gPointsinc == NULL )
	{
		printf( "Failed to pointsinc sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	
	gFoodeaten = Mix_LoadWAV( "music and sounds/foodeaten.wav" );
	if( gFoodeaten == NULL )
	{
		printf( "Failed to load Foodeaten sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	
	gBark = Mix_LoadWAV( "music and sounds/Bark.wav" );
	if( gBark == NULL )
	{
		printf( "Failed to load Bark sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	
	gWinsound = Mix_LoadWAV( "music and sounds/winsound.wav" );
	if( gBark == NULL )
	{
		printf( "Failed to load Win sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	
	
	gYulu = Mix_LoadWAV( "music and sounds/Yulu.wav" );
	if( gYulu == NULL )
	{
		printf( "Failed to load yulu sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
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
	gPromptTexture.free();
	gcurrentTexture1.free();
	
	//Free the sound effects
	Mix_FreeChunk( gKeycollect );
	Mix_FreeChunk( gHealth );
	Mix_FreeChunk( gHealthkit );
	Mix_FreeChunk( gPointsinc );
	Mix_FreeChunk( gFoodeaten );
	Mix_FreeChunk( gBark );
	Mix_FreeChunk( gWinsound );
	Mix_FreeChunk( gYulu );
	gKeycollect = NULL;
	gHealth = NULL;
	gHealthkit = NULL;
	gPointsinc = NULL;
	gFoodeaten = NULL;
	gBark = NULL;
	gWinsound = NULL;
	gYulu = NULL;
	
	//Free the music
	Mix_FreeMusic( gMusic );
	gMusic = NULL;
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
	//Playing the music
	Mix_PlayMusic( gMusic, -1 );
	//Framerate setting
	int p=0;
	const int FPS = 60;
	const int frameDelay = 1000/FPS;
	Uint32 frameStart;
	int frameTime;
	
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
					frameStart = SDL_GetTicks();
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
							case SDLK_p:
							gcurrentTexture1 = gDotTexture;
							p=1;
							case SDLK_m:
							//If there is no music playing
							if( Mix_PlayingMusic() == 0 )
							{
								//Play the music
								Mix_PlayMusic( gMusic, -1 );
							}
							//If music is being played
							else
							{
								//If the music is paused
								if( Mix_PausedMusic() == 1 )
								{
									//Resume the music
									Mix_ResumeMusic();
								}
								//If the music is playing
								else
								{
									//Pause the music
									Mix_PauseMusic();
								}
							}
							break;
							
							case SDLK_UP:
							gSpriteClips[0]=gSpriteClips_up[0];
							gSpriteClips[1]=gSpriteClips_up[1];
							gSpriteClips[2]=gSpriteClips_up[2];
							gSpriteClips[3]=gSpriteClips_up[3];
							if(dot.yulu == 1)
								Mix_PlayChannel( -1, gYulu, 0 );
							break;

							case SDLK_DOWN:
							gSpriteClips[0]=gSpriteClips_down[0];
							gSpriteClips[1]=gSpriteClips_down[1];
							gSpriteClips[2]=gSpriteClips_down[2];
							gSpriteClips[3]=gSpriteClips_down[3];
							if(dot.yulu == 1)
								Mix_PlayChannel( -1, gYulu, 0 );
							break;

							case SDLK_LEFT:
							gSpriteClips[0]=gSpriteClips_left[0];
							gSpriteClips[1]=gSpriteClips_left[1];
							gSpriteClips[2]=gSpriteClips_left[2];
							gSpriteClips[3]=gSpriteClips_left[3];
							if(dot.yulu == 1)
								Mix_PlayChannel( -1, gYulu, 0 );
							break;

							case SDLK_RIGHT:
							gSpriteClips[0]=gSpriteClips_right[0];
							gSpriteClips[1]=gSpriteClips_right[1];
							gSpriteClips[2]=gSpriteClips_right[2];
							gSpriteClips[3]=gSpriteClips_right[3];
							if(dot.yulu == 1)
								Mix_PlayChannel( -1, gYulu, 0 );
							break;
							
							case SDLK_h:
								if(dot.healthkit==1 && dot.lives<5){dot.up_life();Mix_PlayChannel( -1, gHealth, 0 );}
							break;

							case SDLK_y:
								dot.ReturnYuluRender(wallArray.wall);
									
							break;

							case SDLK_r:
								if(dot.food==1){
									if(dot.lives<5) dot.lives+=1;
									dot.food=0;
									dot.foodRajadhani=0;
									dot.foodMasala=0;
									dot.foodDelhi16=0;
									dot.foodShuru=0;
									dot.foodAmul=0;
									dot.foodNescafe=0;
									dot.foodHimadri=0;
									dot.hungry=0;
								}
							break;
							
							case SDLK_RETURN:
							SDL_Rect h_wall;
							h_wall.x = 1312;
							h_wall.y = 2028;
							h_wall.w = 256;
							h_wall.h = 40;
							if(checksingle_Out(dot.mCollider,h_wall)){
								if(dot.money>=50 && dot.healthkit==0){
									dot.healthkit=1;
									dot.money-=50;
									Mix_PlayChannel( -1, gHealthkit, 0 );
								}
							}

							if(checksingle_Out(dot.mCollider,wallArray.wall[115])){
								if(dot.money>=50 && dot.easteregg==0 && dot.keystate==4){
									dot.easteregg=1;
								}
							}

							if(checksingle_Out(dot.mCollider,wallArray.wall[27])){
								dot.ID_card=1;	
							}
							if(checksingle_Out(dot.mCollider,wallArray.wall[97])){
								if(dot.ID_card==1 && dot.mask==1){dot.attendence=1;	
											dot.keystate=1;
								}
							}
							if(checksingle_Out(dot.mCollider,wallArray.wall[37])){
								if(dot.ID_card==1)dot.mask=1;	
							}
							if(checksingle_Out(dot.mCollider,wallArray.wall[98])){
								if(dot.keystate==1){   dot.keystate=2;
											Mix_PlayChannel( -1, gKeycollect, 0 );
											dot.hungry=1;
											Mix_PlayChannel( -1, gPointsinc, 0 );
											dot.money+=100;}	
							}
							if(checksingle_Out(dot.mCollider,wallArray.wall[111])){
								if(dot.keystate==2 && dot.hungry==0){
													Mix_PlayChannel( -1, gKeycollect, 0 );
													dot.keystate=3;
													dot.money+=200;
													Mix_PlayChannel( -1, gPointsinc, 0 );}	
							}
							if(checksingle_Out(dot.mCollider,wallArray.wall[112])){
								if(dot.keystate==3 && dot.girinaryulu==1){
													Mix_PlayChannel( -1, gKeycollect, 0 );
													dot.keystate=4;
													dot.money+=300;
													Mix_PlayChannel( -1, gPointsinc, 0 );}	
							}


							if(checksingle_Out(dot.mCollider,wallArray.wall[104]) && dot.relaystate==0){
								dot.relaystate=1;
							}
							else if(checksingle_Out(dot.mCollider,wallArray.wall[105]) && dot.relaystate==1){
								dot.relaystate=2;
							}
							else if(checksingle_Out(dot.mCollider,wallArray.wall[106]) && dot.relaystate==2){
								dot.relaystate=3;
							}
							else if(checksingle_Out(dot.mCollider,wallArray.wall[107]) && dot.relaystate==3){
								dot.relaystate=4;
							}
							else if(checksingle_Out(dot.mCollider,wallArray.wall[108]) && dot.relaystate==4){
								dot.relaystate=5;
							}
							else if(checksingle_Out(dot.mCollider,wallArray.wall[105]) && dot.relaystate==5){
								dot.relaystate=0;
								dot.money+=10;
							}

							dot.ReturnFoodRender(wallArray.wall);
							if(dot.food == 1){
								Mix_PlayChannel( -1, gFoodeaten, 0 );
							}

							break;

							default:
							gSpriteClips[0]=gSpriteClips_down[0];
							gSpriteClips[1]=gSpriteClips_down[0];
							gSpriteClips[2]=gSpriteClips_down[0];
							gSpriteClips[3]=gSpriteClips_down[0];
							break;
						}
					}
					/*else if(e.type == SDL_KEYUP && e.key.repeat == 0)
					{	switch( e.key.keysym.sym )
        					{	default:
							gSpriteClips[0]=gSpriteClips_down[0];
							gSpriteClips[1]=gSpriteClips_down[0];
							gSpriteClips[2]=gSpriteClips_down[0];
							gSpriteClips[3]=gSpriteClips_down[0];
							break;	
        					}
					
					
					}*/
					//***********************************************************??
					

					//Handle input for the dot
					if(p==1)
						dot.handleEvent( e );
				}
				//update life
				vector<SDL_Rect> bots;
      				bots.push_back(bot.mCollider);
				dot.update_life(bots);
				if(dot.dog == 1){
					Mix_PlayChannel( -1, gBark, 0 );dot.dog = 0;}
					
				
				bot.handleEvent(dot.getPosX(),dot.getPosY(),dot.mCollider);
				
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
				if(p==1)
					gBGTexture.render( 0, 0, &camera );

				//Render objects
				//dot.render( camera.x, camera.y );
				//********************************************************??
				//Render current frame
				SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];
				


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
				
				//render life
				dot.LivesRender();
				
				//powers render
				dot.PowersRender(camera.x,camera.y,wallArray.wall);
				if(dot.easteregg == 1){
					Mix_PlayChannel( -1, gWinsound, 0 );
				}
				dot.FoodRender(camera.x,camera.y,wallArray.wall);
				dot.YuluRender(camera.x,camera.y,wallArray.wall);
				dot.relayMoney(camera.x,camera.y);
				dot.MoneyRender();

				gcurrentTexture1.render( dot.getPosX() - camera.x, dot.getPosY() - camera.y, currentClip );

				if(p==0)
					gPromptTexture.render( 0, 0 );
				//Update screen
				SDL_RenderPresent( gRenderer );
				
				//Delay of frames if needed
				frameTime = SDL_GetTicks() - frameStart;
				if(frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
