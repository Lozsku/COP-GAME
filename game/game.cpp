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
using namespace std;

//The dimensions of the level
const int LEVEL_WIDTH = 4704;
const int LEVEL_HEIGHT = 5632;

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;

//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );
		
		#if defined(SDL_TTF_MAJOR_VERSION)
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

//The dot that will move around on the screen
class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move(vector<SDL_Rect> wall);

		//Shows the dot on the screen relative to the camera
		void render( int camX, int camY );

		//Position accessors
		int getPosX();
		int getPosY();

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
		
		//Dot's collision box
		SDL_Rect mCollider;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Box collision detector
bool checkCollision( SDL_Rect a, vector<SDL_Rect> wall );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
LTexture gDotTexture;
LTexture gBGTexture;

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

#if defined(SDL_TTF_MAJOR_VERSION)

#endif

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}
		
void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

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
	if( !gDotTexture.loadFromFile( "dot.bmp" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	//Load background texture
	if( !gBGTexture.loadFromFile( "map.png" ) )
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
{	for (int i = 0; i < wall.size(); i++){
		if(checksingle(a,wall[i])){
			return true;
		}
	}
	return false;
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

			//The dot that will be moving around on the screen
			Dot dot;
			
			//***********************************************//
			vector<SDL_Rect> wall;
			//Set the wall
			SDL_Rect wall1;
			wall1.x = 12;
			wall1.y = 428;
			wall1.w = 3060;
			wall1.h = 104;
			
			SDL_Rect wall2;
			wall2.x = 364;
			wall2.y = 12;
			wall2.w = 72;
			wall2.h = 430;
			
			SDL_Rect wall3;
			wall3.x = 224;
			wall3.y = 320;
			wall3.w = 160;
			wall3.h = 96;
			
			SDL_Rect wall4;
			wall4.x = 1196;
			wall4.y = 448;
			wall4.w = 104;
			wall4.h = 4084;
			
			SDL_Rect wall5;
			wall5.x = 1196;
			wall5.y = 4428;
			wall5.w = 3124;
			wall5.h = 104;
			
			SDL_Rect wall6;
			wall6.x = 3340;
			wall6.y = 4448;
			wall6.w = 104;
			wall6.h = 1184;
			//Nilagiri left entrance (NM)
			SDL_Rect wall7;
			wall7.x = 1216;
			wall7.y = 3980;
			wall7.w = 1620;
			wall7.h = 72;
			//Nilagiri entrance wall
			SDL_Rect wall8;
			wall8.x = 812;
			wall8.y = 1036;
			wall8.w = 1736;
			wall8.h = 72;
			//Kara entrance wall
			SDL_Rect wall9;
			wall9.x = 2476;
			wall9.y = 480;
			wall9.w = 72;
			wall9.h = 628;
			//Aravali entrance wall
			SDL_Rect wall10;
			wall10.x = 908;
			wall10.y = 480;
			wall10.w = 40;
			wall10.h = 608;
			//Jwala entrance wall
			SDL_Rect wall11;
			wall11.x = 492;
			wall11.y = 1516;
			wall11.w = 1620;
			wall11.h = 40;
			//Inter hostel walls
			//nilagiri
			SDL_Rect wall12;
			wall12.x = 2092;
			wall12.y = 1056;
			wall12.w = 40;
			wall12.h = 980;
			//kara
			SDL_Rect wall13;
			wall13.x = 2816;
			wall13.y = 4012;
			wall13.w = 596;
			wall13.h = 40;
			//aravali
			SDL_Rect wall14;
			wall14.x = 3372;
			wall14.y = 4032;
			wall14.w = 40;
			wall14.h = 416;
			//jwala
			SDL_Rect wall15;
			wall15.x = 2796;
			wall15.y = 4032;
			wall15.w = 40;
			wall15.h = 416;
			//top road of nalanda grounds
			SDL_Rect wall16;
			wall16.x = 2220;
			wall16.y = 4032;
			wall16.w = 40;
			wall16.h = 416;
			
			SDL_Rect wall17;
			wall17.x = 1740;
			wall17.y = 4032;
			wall17.w = 40;
			wall17.h = 416;
			
			SDL_Rect wall18;
			wall18.x = 3392;
			wall18.y = 5388;
			wall18.w = 1216;
			wall18.h = 72;
			
			SDL_Rect wall19;
			wall19.x = 1280;
			wall19.y = 3468;
			wall19.w = 480;
			wall19.h = 40;
			
			SDL_Rect wall20;
			wall20.x = 1740;
			wall20.y = 3276;
			wall20.w = 40;
			wall20.h = 724;
			
			SDL_Rect wall21;
			wall21.x = 1280;
			wall21.y = 2028;
			wall21.w = 288;
			wall21.h = 40;
			
			SDL_Rect wall22;
			wall22.x = 1984;
			wall22.y = 1996;
			wall22.w = 128;
			wall22.h = 40;
			
			SDL_Rect wall23;
			wall23.x = 1996;
			wall23.y = 2016;
			wall23.w = 40;
			wall23.h = 256	;
			//pushing into vector
			wall.push_back(wall1);
			wall.push_back(wall2);
			wall.push_back(wall3);
			wall.push_back(wall4);
			wall.push_back(wall5);
			wall.push_back(wall6);
			wall.push_back(wall7);
			wall.push_back(wall8);
			wall.push_back(wall9);
			wall.push_back(wall10);
			wall.push_back(wall11);
			wall.push_back(wall12);
			wall.push_back(wall13);
			wall.push_back(wall14);
			wall.push_back(wall15);
			wall.push_back(wall16);
			wall.push_back(wall17);
			wall.push_back(wall18);
			wall.push_back(wall19);
			wall.push_back(wall20);
			wall.push_back(wall21);
			wall.push_back(wall22);
			wall.push_back(wall23);
			//***********************************************//
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

					//Handle input for the dot
					dot.handleEvent( e );
				}

				//Move the dot
				dot.move(wall);

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
				dot.render( camera.x, camera.y );

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
