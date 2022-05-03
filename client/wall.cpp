#include <SDL2/SDL.h>
#include <vector>
#include "wall.h"
using namespace std;

Wall_Array::Wall_Array(){

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

			SDL_Rect wall7;
			wall7.x = 1216;
			wall7.y = 3980;
			wall7.w = 1620;
			wall7.h = 72;

			SDL_Rect wall8;
			wall8.x = 812;
			wall8.y = 1036;
			wall8.w = 1736;
			wall8.h = 72;

			SDL_Rect wall9;
			wall9.x = 2476;
			wall9.y = 480;
			wall9.w = 72;
			wall9.h = 628;

			SDL_Rect wall10;
			wall10.x = 908;
			wall10.y = 480;
			wall10.w = 40;
			wall10.h = 608;

			SDL_Rect wall11;
			wall11.x = 492;
			wall11.y = 1516;
			wall11.w = 1620;
			wall11.h = 40;


			SDL_Rect wall12;
			wall12.x = 2092;
			wall12.y = 1056;
			wall12.w = 40;
			wall12.h = 980;

			SDL_Rect wall13;
			wall13.x = 2816;
			wall13.y = 4012;
			wall13.w = 596;
			wall13.h = 40;

			SDL_Rect wall14;
			wall14.x = 3372;
			wall14.y = 4032;
			wall14.w = 40;
			wall14.h = 416;

			SDL_Rect wall15;
			wall15.x = 2796;
			wall15.y = 4032;
			wall15.w = 40;
			wall15.h = 416;

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
}
