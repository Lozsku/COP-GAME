#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "dot.h"
#include "wall.h"
#include "bot.cpp"
//#include "common.h"
#include "LTexture.h"
//#include "LTexture.cpp"
using namespace std;

LTexture gDotTexture;
LTexture gLivesTexture;
LTexture gHealthTexture;
LTexture gIdTexture;
LTexture gKeyTexture;
LTexture gKey2Texture;
LTexture gKey3Texture;
LTexture gMaskTexture;
LTexture gAttendenceTexture;

LTexture gScore1Texture;
LTexture gScore2Texture;
LTexture gScore3Texture;

vector<int> portal(SDL_Rect a,vector<SDL_Rect> portwall,int x,int y);

/*SDL_Rect wall_p1;
	wall_p1.x = 17*32;
	wall_p1.y = 32*32;
	wall_p1.w = 1;
	wall_p1.h = 64;
	
vector<SDL_Rect> portwall;
portwall.push_back(wall_p1);*/


Dot::Dot()
{
    //Initialize the offsets
    mPosX = 135*32;
    mPosY = 139*32;
    
    //Set collision box dimension
	mCollider.w = DOT_WIDTH;
	mCollider.h = DOT_HEIGHT;

	
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

	easteregg=0;

	instructions=0;
    
    //initialising lives
    lives=5;
    DOT_VEL=10;
    
    //initialising state of life (0-5)
    state_life=0;
    
    //handle event state
    handle_state=0;
	direc=0;
    
    //Special Powers/badges
    healthkit=0;
    ID_card=0;
    key=0;
	attendence=0;
	mask=0;
	keystate=0;
	money=50;
	hungry=0;
	relaystate=0;

	food=0;
	foodRajadhani=0;
	foodMasala=0;
	foodDelhi16=0;
	foodShuru=0;
	foodAmul=0;
	foodNescafe=0;
	foodHimadri=0;
	girinaryulu=0;

	yulu=0;
    
	dog=0;	
}

void Dot::handleEvent( SDL_Event& e )
{	
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {	
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY = -DOT_VEL;direc=0; break;
            case SDLK_DOWN: mVelY = DOT_VEL;direc=1; break;
            case SDLK_LEFT: mVelX = -DOT_VEL;direc=2; break;
            case SDLK_RIGHT: mVelX = DOT_VEL;direc=3; break;
        }
        
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {	
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {	
            case SDLK_UP: mVelY = 0; break;
            case SDLK_DOWN: mVelY = 0; break;
            case SDLK_LEFT: mVelX = 0; break;
            case SDLK_RIGHT: mVelX = 0; break;
        }
    }
}

void Dot::update_life(vector<SDL_Rect> bots){
	//Check collison with bots
	//cout<<checkCollision_Out(mCollider,bots);
	if(checkCollision_Out(mCollider,bots)){
		if(state_life==0 ){
			if(lives>0){
			lives-=1;
			DOT_VEL-=1;}
			handle_state=1;
			cout<<lives;}    	
		state_life=1;
		dog = 1;
        }
        else{
        	state_life=0;
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
    
    Wall_Array port;
    
    vector<int> cor=portal(mCollider,port.portwall,mPosX,mPosY);
    mPosX=cor[0];
    mPosY=cor[1];
    mCollider.x=mPosX;
    mCollider.y=mPosY;

	if(checksingle_Out(mCollider,port.wall[114]) && keystate==4){
		mPosX=110*32;
		mPosY=90*32;
		mCollider.x=mPosX;
		mCollider.y=mPosY;
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

void Dot::up_life()
{
	lives=5;
	healthkit=0;
	DOT_VEL=10;
}

void Dot::collect(int C)
{
	if(C==0){ID_card=1;}
}

void Dot::LivesRender()
{	
	if(lives==0){
		gLivesTexture.loadFromFile( "images/life1.png" );
	}
	else if(lives==1){
		gLivesTexture.loadFromFile( "images/life2.png" );
	}
	else if(lives==2){
		gLivesTexture.loadFromFile( "images/life3.png" );
	}
	else if(lives==3){
		gLivesTexture.loadFromFile( "images/life4.png" );
	}
	else if(lives==4){
		gLivesTexture.loadFromFile( "images/life5.png" );
	}
	else if(lives==5){
		gLivesTexture.loadFromFile( "images/life6.png" );
	}
	gLivesTexture.render(2,2);	

}

void Dot::PowersRender(int camX, int camY,vector<SDL_Rect> wall)
{
	LTexture gEastereggTexture;
	LTexture gBoardTexture;
	gHealthTexture.loadFromFile("images/healthkit.png");
	gIdTexture.loadFromFile("images/ID.png");
	gMaskTexture.loadFromFile("images/mask.png");
	gKeyTexture.loadFromFile("images/key1.png");
	gKey2Texture.loadFromFile("images/key2.png");
	gKey3Texture.loadFromFile("images/key3.png");
	gEastereggTexture.loadFromFile("images/easteregg.png");
	gBoardTexture.loadFromFile("images/board.png");
	gBoardTexture.render(800-231,0);
	

	if(attendence==0){
		gAttendenceTexture.loadFromFile("images/atten_notrec.png");
	}
	else {
		gAttendenceTexture.loadFromFile("images/atten_rec.png");
	}
	
	//gHealthTexture.render(0,0);
	if(healthkit==0){
		gHealthTexture.render(47*32+10-camX,63*32+14-camY);
	}
	else if(healthkit==1){
		gHealthTexture.render(250,-12);
	}

	if(easteregg==0){
		gEastereggTexture.render(110*32-16-camX,84*32-camY);
	}
	else if(easteregg==1){
		gEastereggTexture.render(766,18);
	}
	
	if(ID_card==0 && checksingle_Out(mCollider,wall[27])){
		gIdTexture.render(85*32-camX,134*32-camY);
	}
	else if(ID_card==1 ){
		gIdTexture.render(300,2);
	}

	if(attendence==0 ){
		gAttendenceTexture.render(38*32,2);
	}
	else{
		gAttendenceTexture.render(38*32,2);
	}

	if(mask==0 && checksingle_Out(mCollider,wall[37]) ){
		gMaskTexture.render(23*32-camX,7*32-camY);
	}
	else if(mask==1){
		gMaskTexture.render(380,2);
	}

	if(keystate==1 && checksingle_Out(mCollider,wall[98]) ){
		gKeyTexture.render(14*32-camX,47*32-camY);
	}
	else if(keystate>=2){
		gKeyTexture.render(460+150-10,10);
	}

	if(keystate==2 && hungry==0 && checksingle_Out(mCollider,wall[111]) ){
		gKey2Texture.render(59*32-camX,132*32-camY);
	}
	else if(keystate>=3){
		gKey2Texture.render(500+150,10);
	}

	if(keystate==3 && girinaryulu==1 && checksingle_Out(mCollider,wall[112]) ){
		gKey3Texture.render(94*32-camX,119*32-16-camY);
	}
	else if(keystate>=4){
		gKey3Texture.render(540+150+10,10);
	}
}

void Dot::enemykeys(int key){
	LTexture geKeyTexture;
	LTexture geKey2Texture;
	LTexture geKey3Texture;
	geKeyTexture.loadFromFile("images/key1.png");
	geKey2Texture.loadFromFile("images/key2.png");
	geKey3Texture.loadFromFile("images/key3.png");
	if(key>=2){
		geKeyTexture.render(460+150+250+20-10,10);
	}

	if(key>=3){
		geKey2Texture.render(500+150+250+20,10);
	}

	if(key>=4){
		geKey3Texture.render(540+150+10+250+20,10);
	}
}

void Dot::InstructionsRender()
{
	LTexture gInstrTexture;
	if(ID_card==0){
		gInstrTexture.loadFromFile("images/instruction1.png");
	}
	else if(mask==0){
		gInstrTexture.loadFromFile("images/instruction2.png");
	}
	else if(attendence==0){
		gInstrTexture.loadFromFile("images/instruction3.png");
	}
	else if(keystate==1){
		gInstrTexture.loadFromFile("images/instruction4.png");
	}
	else if(keystate==2 && hungry==1){
		gInstrTexture.loadFromFile("images/instruction5.png");
	}
	else if(keystate==2 && hungry==0){
		gInstrTexture.loadFromFile("images/instruction6.png");
	}
	else if(keystate==3){
		gInstrTexture.loadFromFile("images/instruction7.png");
	}
	else if(keystate==4){
		gInstrTexture.loadFromFile("images/instruction8.png");
	}

	gInstrTexture.render(320,200);
	
	
}

void Dot::FoodRender(int camX,int camY,vector<SDL_Rect> wall){
	LTexture gFTexture;
	LTexture gRTexture;
	LTexture gMTexture;
	LTexture gDTexture;
	LTexture gATexture;
	LTexture gNTexture;
	LTexture gSTexture;
	LTexture gHTexture;
	
	gFTexture.loadFromFile("images/food.png");
	gRTexture.loadFromFile("images/chawmin.png");
	gMTexture.loadFromFile("images/masala.png");
	gDTexture.loadFromFile("images/samosa.png");
	gATexture.loadFromFile("images/milk.png");
	gNTexture.loadFromFile("images/cofee.png");
	gSTexture.loadFromFile("images/drink.png");
	gHTexture.loadFromFile("images/parata.png");
	if(foodRajadhani==0 && checksingle_Out(mCollider,wall[63])){
		gRTexture.render(60*32-camX,42*32-camY);
	}
	else if(foodRajadhani==1 ){
		gFTexture.render(2,80);
	}
	if(foodMasala==0 && checksingle_Out(mCollider,wall[62])){
		gMTexture.render(48*32-camX,43*32-camY);
	}
	else if(foodMasala==1 ){
		gFTexture.render(2,80);
	}
	if(foodDelhi16==0 && checksingle_Out(mCollider,wall[54])){
		gDTexture.render(58*32-camX,22*32-32-camY);
	}
	else if(foodDelhi16==1 ){
		gFTexture.render(2,80);
	}
	if(foodAmul==0 && checksingle_Out(mCollider,wall[77])){
		gATexture.render(66*32-camX,129*32-camY);
	}
	else if(foodAmul==1 ){
		gFTexture.render(2,80);
	}
	if(foodNescafe==0 && checksingle_Out(mCollider,wall[78])){
		gNTexture.render(66*32-camX,134*32-camY);
	}
	else if(foodNescafe==1 ){
		gFTexture.render(2,80);
	}
	if(foodShuru==0 && checksingle_Out(mCollider,wall[76])){
		gSTexture.render(58*32-camX,128*32-camY);
	}
	else if(foodShuru==1 ){
		gFTexture.render(2,80);
	}
	if(foodHimadri==0 && checksingle_Out(mCollider,wall[91])){
		gHTexture.render(133*32-camX,165*32-camY);
	}
	else if(foodHimadri==1 ){
		gFTexture.render(2,80);
	}
}

void Dot::ReturnFoodRender(vector<SDL_Rect> wall){
	if(money>=20){
		if(foodRajadhani==0 && checksingle_Out(mCollider,wall[63]) && food==0){
			food=1;
			foodRajadhani=1;
			money-=20;
		}
		if(foodMasala==0 && checksingle_Out(mCollider,wall[62]) && food==0){
			food=1;
			foodMasala=1;
			money-=20;
		}
		
		if(foodDelhi16==0 && checksingle_Out(mCollider,wall[54]) && food==0){
			food=1;
			foodDelhi16=1;
			money-=20;
		}
		
		if(foodAmul==0 && checksingle_Out(mCollider,wall[77]) && food==0){
			food=1;
			foodAmul=1;
			money-=20;
		}
		
		if(foodNescafe==0 && checksingle_Out(mCollider,wall[78]) && food==0){
			food=1;
			foodNescafe=1;
			money-=20;
		}
		
		if(foodShuru==0 && checksingle_Out(mCollider,wall[76]) && food==0){
			food=1;
			foodShuru=1;
			money-=20;
		}
		
		if(foodHimadri==0 && checksingle_Out(mCollider,wall[91]) && food==0){
			food=1;
			foodHimadri=1;
			money-=20;
		}
	}
	
}

void Dot::YuluRender(int camX,int camY,vector<SDL_Rect> wall){
	counterdot++;
	if(counterdot>200){
		counterdot=0;
		if(yulu==1)money-=1;
	}
	if(money==0){yulu=0;DOT_VEL=5+lives;}

	LTexture gYTexture;
	LTexture gYNTexture;
	LTexture gYJTexture;
	LTexture gYSTexture;
	LTexture gYGTexture;
	LTexture gYRTexture;
	LTexture gYMTexture;
	LTexture gYLHCTexture;
	LTexture gYHTexture;
	LTexture gYMainTexture;
	gYTexture.loadFromFile("images/yulu.png");
	gYNTexture.loadFromFile("images/yulu.png");
	gYJTexture.loadFromFile("images/yulu.png");
	gYSTexture.loadFromFile("images/yulu.png");
	gYGTexture.loadFromFile("images/yulu.png");
	gYRTexture.loadFromFile("images/yulu.png");
	gYMTexture.loadFromFile("images/yulu.png");
	gYLHCTexture.loadFromFile("images/yulu.png");
	gYHTexture.loadFromFile("images/yulu.png");
	gYMainTexture.loadFromFile("images/yulu.png");
	if( checksingle_Out(mCollider,wall[2]) && yulu==0){
		gYNTexture.render(8*32-10-camX,10*32+5-camY);
	}
	
	else if(checksingle_Out(mCollider,wall[51]) && yulu==0){
		gYJTexture.render(87*32-10-camX,10*32+5-camY);
	}
	
	else if(checksingle_Out(mCollider,wall[34]) && yulu==0){
		gYSTexture.render(25*32-10-camX,29*32+5-camY);
	}
	
	else if(checksingle_Out(mCollider,wall[69]) && yulu==0){
		gYGTexture.render(59*32-10-camX,62*32+5-camY);
	}
	
	else if(checksingle_Out(mCollider,wall[68]) && yulu==0){
		gYRTexture.render(34*32-10-camX,49*32+5-camY);
	}
	
	else if(checksingle_Out(mCollider,wall[70]) && yulu==0){
		gYMTexture.render(34*32-10-camX,75*32+5-camY);
	}
	
	else if(checksingle_Out(mCollider,wall[85]) && yulu==0){
		gYLHCTexture.render(74*32-10-camX,144*32+5-camY);
	}
	
	else if(checksingle_Out(mCollider,wall[89]) && yulu==0){
		gYHTexture.render(128*32-10-camX,165*32+5-camY);
	}
	
	else if(checksingle_Out(mCollider,wall[86]) && yulu==0){
		gYMainTexture.render(127*32-10-camX,135*32+5-camY);
	}
	else if(yulu==1){
		gYTexture.render(70,80);
	}


}

void Dot::ReturnYuluRender(vector<SDL_Rect> wall){

	if( checksingle_Out(mCollider,wall[2]) && yulu==0){
		yulu=1;
		DOT_VEL=15;
	}
	else if( checksingle_Out(mCollider,wall[2]) && yulu==1){
		yulu=0;
		DOT_VEL=5+lives;
		girinaryulu=0;
	}
	
	if(checksingle_Out(mCollider,wall[51]) && yulu==0){
		yulu=1;
		DOT_VEL=15;
	}
	else if(checksingle_Out(mCollider,wall[51]) && yulu==1){
		yulu=0;
		DOT_VEL=5+lives;
		girinaryulu=0;
	}
	
	if(checksingle_Out(mCollider,wall[34]) && yulu==0){
		yulu=1;
		DOT_VEL=15;
	}
	else if(checksingle_Out(mCollider,wall[34]) && yulu==1){
		yulu=0;
		DOT_VEL=5+lives;
		girinaryulu=0;
	}
	
	if(checksingle_Out(mCollider,wall[69]) && yulu==0){
		yulu=1;
		DOT_VEL=15;
		girinaryulu=1;
		
	}
	else if(checksingle_Out(mCollider,wall[69]) && yulu==1){
		yulu=0;
		DOT_VEL=5+lives;
		girinaryulu=0;
	}
	
	if(checksingle_Out(mCollider,wall[68]) && yulu==0){
		yulu=1;
		DOT_VEL=15;
	}
	else if(checksingle_Out(mCollider,wall[68]) && yulu==1){
		yulu=0;
		DOT_VEL=5+lives;
		girinaryulu=0;
	}
	
	if(checksingle_Out(mCollider,wall[70]) && yulu==0){
		yulu=1;
		DOT_VEL=15;
	}
	else if(checksingle_Out(mCollider,wall[70]) && yulu==1){
		yulu=0;
		DOT_VEL=5+lives;
		girinaryulu=0;
	}
	
	if(checksingle_Out(mCollider,wall[85]) && yulu==0){
		yulu=1;
		DOT_VEL=15;
	}
	else if(checksingle_Out(mCollider,wall[85]) && yulu==1){
		yulu=0;
		DOT_VEL=5+lives;
		girinaryulu=0;
	}
	
	if(checksingle_Out(mCollider,wall[89]) && yulu==0){
		yulu=1;
		DOT_VEL=15;
	}
	else if(checksingle_Out(mCollider,wall[89]) && yulu==1){
		yulu=0;
		DOT_VEL=10;
		girinaryulu=0;
	}
	
	if(checksingle_Out(mCollider,wall[86]) && yulu==0){
		yulu=1;
		DOT_VEL=15;
	}
	else if(checksingle_Out(mCollider,wall[86]) && yulu==1){
		yulu=0;
		DOT_VEL=5+lives;
		girinaryulu=0;
	}
	
	


}

void Dot::MoneyRender(){
	SDL_Rect moneysprites[10];

		moneysprites[ 1 ].x =   20;
		moneysprites[ 1 ].y =   50;
		moneysprites[ 1 ].w =  72;
		moneysprites[ 1 ].h =  98;

		moneysprites[ 2 ].x =  20+72;
		moneysprites[ 2 ].y =  50;
		moneysprites[ 2 ].w =  72;
		moneysprites[ 2 ].h =  98;
		
		moneysprites[ 3 ].x =  20+72*2;
		moneysprites[ 3 ].y =  50;
		moneysprites[ 3 ].w =  72;
		moneysprites[ 3 ].h =  98;

		moneysprites[ 4 ].x =  20+72*3;
		moneysprites[ 4 ].y =  50;
		moneysprites[ 4 ].w =  72;
		moneysprites[ 4 ].h =  98;

		moneysprites[ 5 ].x =   20+72*4;
		moneysprites[ 5 ].y =  50;
		moneysprites[ 5 ].w =  72;
		moneysprites[ 5 ].h =  98;

		moneysprites[ 6 ].x =   20;
		moneysprites[ 6 ].y =  169;
		moneysprites[ 6 ].w =  72;
		moneysprites[ 6 ].h =  98;

		moneysprites[ 7 ].x =  20+72;
		moneysprites[ 7 ].y =  169;
		moneysprites[ 7 ].w =  72;
		moneysprites[ 7 ].h =  98;
		
		moneysprites[ 8 ].x =  20+72*2;
		moneysprites[ 8 ].y =  169;
		moneysprites[ 8 ].w =  72;
		moneysprites[ 8 ].h =  98;

		moneysprites[ 9 ].x =  20+72*3;
		moneysprites[ 9 ].y =  169;
		moneysprites[ 9 ].w =  72;
		moneysprites[ 9 ].h =  98;

		moneysprites[ 0 ].x =   20+72*4;
		moneysprites[ 0 ].y =  169;
		moneysprites[ 0 ].w =  72;
		moneysprites[ 0 ].h =  98;

		gScore1Texture.loadFromFile("images/score.png");
		gScore2Texture.loadFromFile("images/score.png");
		gScore3Texture.loadFromFile("images/score.png");
		LTexture gMiconTexture;
		gMiconTexture.loadFromFile("images/micon.png");

		int money1=money/10;
		int money2=money/100;
		SDL_Rect* scoreClip1 = &moneysprites[money % 10];
		SDL_Rect* scoreClip2 = &moneysprites[money1 % 10];
		SDL_Rect* scoreClip3 = &moneysprites[money2 % 10];
		gMiconTexture.render(40*32,2);
		gScore3Texture.render( 43*32,2, scoreClip3);
		gScore2Texture.render( 43*32+72,2, scoreClip2);
		gScore1Texture.render( 43*32+72*2,2, scoreClip1);

		

	
}

void Dot::relayMoney(int camX, int camY){
	LTexture gRelayTexture;
	LTexture gRedtileTexture;
	gRelayTexture.loadFromFile("images/relay.png");
	gRedtileTexture.loadFromFile("images/redtile.png");
	if(relaystate==0){
		gRelayTexture.render(26*32-15-camX,131*32-camY);
	}
	else if(relaystate==1){
		gRelayTexture.render(180,80);
		gRedtileTexture.render(17*32-camX,125*32-camY);
	}
	else if(relaystate==2){
		gRelayTexture.render(180,80);
		gRedtileTexture.render(17*32-camX,137*32-camY);
	}
	else if(relaystate==3){
		gRelayTexture.render(180,80);
		gRedtileTexture.render(34*32-camX,137*32-camY);
	}
	else if(relaystate==4){
		gRelayTexture.render(180,80);
		gRedtileTexture.render(34*32-camX,125*32-camY);
	}
	else if(relaystate==5){
		gRelayTexture.render(180,80);
		gRedtileTexture.render(17*32-camX,125*32-camY);
	}
}




vector<int> portal(SDL_Rect a,vector<SDL_Rect> portwall,int x,int y){
	//int X[]={11*32};
	//int Y[]={32*32};
	vector<int> cor;
	cor.push_back(x);
	cor.push_back(y);
	for (int i = 0; i < static_cast<int>(portwall.size()); i++){
		if(checksingle_Out(a,portwall[i])){
			cor[0]=X[i];
			cor[1]=Y[i];
			return cor;
		}
	}
	return cor;

}






