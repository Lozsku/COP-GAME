#include <SDL2/SDL.h>
#include <vector>
#include "wall.h"
using namespace std;

Wall_Array::Wall_Array(){

			SDL_Rect wall1;
			wall1.x = 12;
			wall1.y = 428;
			wall1.w = 3060+96;
			wall1.h = 104;
			
			SDL_Rect wall2;
			wall2.x = 364;
			wall2.y = 12;
			wall2.w = 72;
			wall2.h = 448;
			
			SDL_Rect wall3;
			wall3.x = 224+32;
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
			wall5.w = 3124+96;
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
			wall18.w = 1216+96-12;
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
			
			SDL_Rect wall24;
			wall24.x = 69*32+12;
			wall24.y = 141*32;
			wall24.w = 40;
			wall24.h = 3*32-12;	;
			
			SDL_Rect wall25;
			wall25.x = 87*32+12;
			wall25.y = 141*32;
			wall25.w = 40;
			wall25.h = 3*32-12;
			
			SDL_Rect wall26;
			wall26.x = 69*32+12;
			wall26.y = 142*32+12;
			wall26.w = 20*32-24;
			wall26.h = 40;
			
			SDL_Rect wall27;
			wall27.x = 77*32+12;
			wall27.y = 143*32;
			wall27.w = 40;
			wall27.h = 13*32;
			
			SDL_Rect wall28;
			wall28.x = 85*32;
			wall28.y = 134*32+12;
			wall28.w = 96;
			wall28.h = 40;
			
			SDL_Rect wall29;
			wall29.x = 94*32+12;
			wall29.y = 168*32+12;
			wall29.w = 11*32-12;
			wall29.h = 40;
			
			SDL_Rect wall30;
			wall30.x = 94*32+12;
			wall30.y = 163*32;
			wall30.w = 40;
			wall30.h = 6*32;
			
			SDL_Rect wall31;
			wall31.x = 94*32;
			wall31.y = 161*32;
			wall31.w = 64;
			wall31.h = 84;
			
			SDL_Rect wall32;
			wall32.x = 30*32;
			wall32.y = 119*32+12;
			wall32.w = 8*32;
			wall32.h = 40;
			
			SDL_Rect wall33;
			wall33.x = 30*32;
			wall33.y = 121*32+12;
			wall33.w = 8*32;
			wall33.h = 40;
			
			SDL_Rect wall34;
			wall34.x = 17*32;
			wall34.y = 32*32+12;
			wall34.w = 9*32;
			wall34.h = 40;
			
			SDL_Rect wall35;
			wall35.x = 25*32;
			wall35.y = 29*32;
			wall35.w = 4*32;
			wall35.h = 3*32;
			
			//hostel1
			
			SDL_Rect wall36;
			wall36.x = 14*32;
			wall36.y = 10*32;
			wall36.w = 6*32;
			wall36.h = 2*32;
			
			SDL_Rect wall37;
			wall37.x = 19*32+12;
			wall37.y = 11*32;
			wall37.w = 40;
			wall37.h = 3*32;
			
			SDL_Rect wall38;
			wall38.x = 20*32;
			wall38.y = 10*32;
			wall38.w = 5*32;
			wall38.h = 2*32;
			
			SDL_Rect wall39;
			wall39.x = 19*32;
			wall39.y = 4*32;
			wall39.w = 2*32;
			wall39.h = 8*32;
			
			//hostel2
			
			SDL_Rect wall40;
			wall40.x = 32*32;
			wall40.y = 10*32;
			wall40.w = 6*32;
			wall40.h = 2*32;
			
			SDL_Rect wall41;
			wall41.x = 37*32+12;
			wall41.y = 11*32;
			wall41.w = 40;
			wall41.h = 3*32;
			
			SDL_Rect wall42;
			wall42.x = 38*32;
			wall42.y = 10*32;
			wall42.w = 5*32;
			wall42.h = 2*32;
			
			SDL_Rect wall43;
			wall43.x = 37*32;
			wall43.y = 4*32;
			wall43.w = 2*32;
			wall43.h = 8*32;
			
			//hostel3
			
			SDL_Rect wall44;
			wall44.x = 50*32;
			wall44.y = 10*32;
			wall44.w = 6*32;
			wall44.h = 2*32;
			
			SDL_Rect wall45;
			wall45.x = 55*32+12;
			wall45.y = 11*32;
			wall45.w = 40;
			wall45.h = 3*32;
			
			SDL_Rect wall46;
			wall46.x = 56*32;
			wall46.y = 10*32;
			wall46.w = 5*32;
			wall46.h = 2*32;
			
			SDL_Rect wall47;
			wall47.x = 55*32;
			wall47.y = 4*32;
			wall47.w = 2*32;
			wall47.h = 8*32;
			
			//hostel4
			
			SDL_Rect wall48;
			wall48.x = 68*32;
			wall48.y = 10*32;
			wall48.w = 6*32;
			wall48.h = 2*32;
			
			SDL_Rect wall49;
			wall49.x = 73*32+12;
			wall49.y = 11*32;
			wall49.w = 40;
			wall49.h = 3*32;
			
			SDL_Rect wall50;
			wall50.x = 74*32;
			wall50.y = 10*32;
			wall50.w = 5*32;
			wall50.h = 2*32;
			
			SDL_Rect wall51;
			wall51.x = 73*32;
			wall51.y = 4*32;
			wall51.w = 2*32;
			wall51.h = 8*32;
			
			//end hostels
			
			SDL_Rect wall52;
			wall52.x = 86*32+12;
			wall52.y = 10*32;
			wall52.w = 4*32-24;
			wall52.h = 5*32;
			
			SDL_Rect wall53;
			wall53.x = 86*32+12;
			wall53.y = 16*32;
			wall53.w = 2*32-24;
			wall53.h = 2*32;
			
			SDL_Rect wall54;
			wall54.x = 79*32;
			wall54.y = 22*32+12;
			wall54.w = 3*32;
			wall54.h = 2*32-24;
			
			SDL_Rect wall55;
			wall55.x = 58*32+12;
			wall55.y = 16*32;
			wall55.w = 40;
			wall55.h = 3*32;
			
			SDL_Rect wall56;
			wall56.x = 40*32;
			wall56.y = 21*32-12;
			wall56.w = 4*32;
			wall56.h = 1*32+12;
			
			SDL_Rect wall57;
			wall57.x = 43*32;
			wall57.y = 19*32;
			wall57.w = 8*32;
			wall57.h = 10*32;
			
			SDL_Rect wall58;
			wall58.x = 29*32+12;
			wall58.y = 34*32;
			wall58.w = 40;
			wall58.h = 6*32-12;
			
			SDL_Rect wall59;
			wall59.x = 20*32;
			wall59.y = 38*32;
			wall59.w = 10*32;
			wall59.h = 2*32;
			
			SDL_Rect wall60;
			wall60.x = 45*32+12;
			wall60.y = 34*32;
			wall60.w = 40;
			wall60.h = 2*32;
			
			SDL_Rect wall61;
			wall61.x = 54*32+12;
			wall61.y = 34*32;
			wall61.w = 40;
			wall61.h = 2*32;
			
			SDL_Rect wall62;
			wall62.x = 72*32+12;
			wall62.y = 34*32;
			wall62.w = 40;
			wall62.h = 2*32;
			
			SDL_Rect wall63;
			wall63.x = 49*32;
			wall63.y = 46*32;
			wall63.w = 52;
			wall63.h = 2*32;
			
			SDL_Rect wall64;
			wall64.x = 60*32;
			wall64.y = 46*32;
			wall64.w = 3*32;
			wall64.h = 2*32;
			
			SDL_Rect wall65;
			wall65.x = 66*32;
			wall65.y = 55*32+12;
			wall65.w = 7*32;
			wall65.h = 40;
			
			SDL_Rect wall66;
			wall66.x = 44*32+12;
			wall66.y = 48*32;
			wall66.w = 40;
			wall66.h = 5*32-12;
			
			SDL_Rect wall67;
			wall67.x = 50*32+12;
			wall67.y = 48*32;
			wall67.w = 40;
			wall67.h = 5*32-12;
			
			SDL_Rect wall68;
			wall68.x = 44*32+12;
			wall68.y = 51*32;
			wall68.w = 11*32;
			wall68.h = 64;
			
			SDL_Rect wall69;
			wall69.x = 34*32;
			wall69.y = 49*32;
			wall69.w = 4*32;
			wall69.h = 3*32;
			
			SDL_Rect wall70;
			wall70.x = 59*32;
			wall70.y = 62*32+12;
			wall70.w = 4*32;
			wall70.h = 3*32-12;
			
			SDL_Rect wall71;
			wall71.x = 34*32;
			wall71.y = 75*32;
			wall71.w = 4*32;
			wall71.h = 3*32;
			
			SDL_Rect wall72;
			wall72.x = 40*32;
			wall72.y = 69*32;
			wall72.w = 4*32;
			wall72.h = 3*32;
			
			SDL_Rect wall73;
			wall73.x = 40*32;
			wall73.y = 78*32;
			wall73.w = 4*32;
			wall73.h = 3*32;
			
			SDL_Rect wall74;
			wall74.x = 43*32;
			wall74.y = 68*32;
			wall74.w = 3*32;
			wall74.h = 14*32;
			
			SDL_Rect wall75;
			wall75.x = 61*32+12;
			wall75.y = 123*32;
			wall75.w = 40;
			wall75.h = 2*32;
			
			SDL_Rect wall76;
			wall76.x = 69*32;
			wall76.y = 123*32;
			wall76.w = 40;
			wall76.h = 2*32;
			
			
			SDL_Rect wall77;
			wall77.x = 58*32+12;
			wall77.y = 126*32;
			wall77.w = 40;
			wall77.h = 2*32;
			
			SDL_Rect wall78;
			wall78.x = 66*32+12;
			wall78.y = 126*32;
			wall78.w = 40;
			wall78.h = 2*32;
			
			SDL_Rect wall79;
			wall79.x = 68*32+15;
			wall79.y = 134*32;
			wall79.w = 2*32;
			wall79.h = 40;
			
			SDL_Rect wall80;
			wall80.x = 65*32;
			wall80.y = 132*32-12;
			wall80.w = 5*32;
			wall80.h = 1*32+12;
			
			SDL_Rect wall81;
			wall81.x =74*32+12;
			wall81.y = 122*32;
			wall81.w = 40;
			wall81.h = 3*32;
			
			SDL_Rect wall82;
			wall82.x =76*32+12;
			wall82.y = 126*32;
			wall82.w = 40;
			wall82.h = 2*32;
			
			SDL_Rect wall83;
			wall83.x =87*32+12;
			wall83.y = 121*32+12;
			wall83.w = 40;
			wall83.h = 5*32;
			
			SDL_Rect wall84;
			wall84.x =93*32+12;
			wall84.y = 124*32;
			wall84.w = 40;
			wall84.h = 2*32;
			
			SDL_Rect wall85;
			wall85.x =89*32;
			wall85.y = 118*32;
			wall85.w = 11*32;
			wall85.h = 7*32;
			
			SDL_Rect wall86;
			wall86.x =74*32;
			wall86.y = 144*32+12;
			wall86.w = 4*32;
			wall86.h = 3*32-12;
			
			SDL_Rect wall87;
			wall87.x =126*32+12;
			wall87.y = 135*32;
			wall87.w = 4*32-24;
			wall87.h = 4*32;
			
			SDL_Rect wall88;
			wall88.x =107*32;
			wall88.y = 156*32+12;
			wall88.w = 2*32;
			wall88.h = 40;
			
			SDL_Rect wall89;
			wall89.x =122*32+12;
			wall89.y = 166*32;
			wall89.w = 40;
			wall89.h = 3*32;
			
			SDL_Rect wall90;
			wall90.x =127*32+12;
			wall90.y = 165*32;
			wall90.w = 4*32-24;
			wall90.h = 4*32;
			
			SDL_Rect wall91;
			wall91.x =138*32+12;
			wall91.y = 166*32;
			wall91.w = 40;
			wall91.h = 3*32;
			
			SDL_Rect wall92;
			wall92.x =132*32;
			wall92.y = 167*32;
			wall92.w = 64;
			wall92.h = 2*32;
			
			SDL_Rect wall93;
			wall93.x = 56*32;
			wall93.y = 111*32;
			wall93.w = 16*32;
			wall93.h = 13*32;
			
			SDL_Rect wall94;
			wall94.x = 0*32;
			wall94.y = 31*32;
			wall94.w = 12*32;
			wall94.h = 2*32;
			
			SDL_Rect wall95;
			wall95.x = 10*32;
			wall95.y = 31*32;
			wall95.w = 2*32;
			wall95.h = 7*32;
			
			SDL_Rect wall96;
			wall96.x = 7*32;
			wall96.y = 37*32;
			wall96.w = 8*32;
			wall96.h = 12*32;

			SDL_Rect wall97;
			wall97.x = 75*32;
			wall97.y = 163*32;
			wall97.w = 6*32;
			wall97.h = 1*32;

			SDL_Rect wall98;
			wall98.x = 77*32;
			wall98.y = 161*32;
			wall98.w = 2*32;
			wall98.h = 3*32;

			SDL_Rect wall99;
			wall99.x=13*32;
			wall99.y=47*32;
			wall99.w=64;
			wall99.h=64;
			
			SDL_Rect wall100;
			wall100.x = 30*32;
			wall100.y = 122*32;
			wall100.w = 2*32;
			wall100.h = 4*32;
			
			SDL_Rect wall101;
			wall101.x = 15*32;
			wall101.y = 125*32;
			wall101.w = 22*32;
			wall101.h = 14*32;
			
			SDL_Rect wall102;
			wall102.x = 30*32;
			wall102.y = 118*32;
			wall102.w = 2*32;
			wall102.h = 3*32-12;
			
			SDL_Rect wall103;
			wall103.x = 30*32;
			wall103.y = 114*32;
			wall103.w = 7*32;
			wall103.h = 5*32;
			
			SDL_Rect wall104;
			wall104.x = 15*32;
			wall104.y = 78*32;
			wall104.w = (37-15)*32;
			wall104.h = (116-78)*32;
			
			SDL_Rect wall105;
			wall105.x = 25*32;
			wall105.y = 131*32;
			wall105.w = 2*32;
			wall105.h = 2*32;
			
			SDL_Rect wall106;
			wall106.x = 17*32;
			wall106.y = 125*32;
			wall106.w = 1*32;
			wall106.h = 1*32;
			
			SDL_Rect wall107;
			wall107.x = 17*32;
			wall107.y = 137*32;
			wall107.w = 1*32;
			wall107.h = 1*32;
			
			SDL_Rect wall108;
			wall108.x = 34*32;
			wall108.y = 137*32;
			wall108.w = 1*32;
			wall108.h = 1*32;
			
			SDL_Rect wall109;
			wall109.x = 34*32;
			wall109.y = 125*32;
			wall109.w = 1*32;
			wall109.h = 1*32;
			
			SDL_Rect wall110;
			wall110.x = 56*32;
			wall110.y = 131*32;
			wall110.w = 9*32;
			wall110.h = 5*32;
			
			SDL_Rect wall111;
			wall111.x = 71*32+12;
			wall111.y = 134*32;
			wall111.w = 9*32-24;
			wall111.h = 2*32;
			
			SDL_Rect wall112;
			wall112.x = 59*32;
			wall112.y = 132*32;
			wall112.w = 32;
			wall112.h = 32;
			
			SDL_Rect wall113;
			wall113.x = 94*32;
			wall113.y = 119*32;
			wall113.w = 32;
			wall113.h = 32;
			
			SDL_Rect wall114;
			wall114.x = 101*32;
			wall114.y = 80*32;
			wall114.w = 19*32;
			wall114.h = 11*32;

			SDL_Rect wall115;
			wall115.x = 94*32;
			wall115.y = 161*32;
			wall115.w = 64;
			wall115.h = 1;

			SDL_Rect wall116;
			wall116.x = 110*32-16;
			wall116.y = 84*32;
			wall116.w = 64;
			wall116.h = 90;
			

			
			
			


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
			wall.push_back(wall24);
			wall.push_back(wall25);
			wall.push_back(wall26);
			wall.push_back(wall27);
			wall.push_back(wall28);
			wall.push_back(wall29);
			wall.push_back(wall30);
			wall.push_back(wall31);
			wall.push_back(wall32);
			wall.push_back(wall33);
			wall.push_back(wall34);
			wall.push_back(wall35);
			wall.push_back(wall36);
			wall.push_back(wall37);
			wall.push_back(wall38);
			wall.push_back(wall39);
			wall.push_back(wall40);
			wall.push_back(wall41);
			wall.push_back(wall42);
			wall.push_back(wall43);
			wall.push_back(wall44);
			wall.push_back(wall45);
			wall.push_back(wall46);
			wall.push_back(wall47);
			wall.push_back(wall48);
			wall.push_back(wall49);
			wall.push_back(wall50);
			wall.push_back(wall51);
			wall.push_back(wall52);
			wall.push_back(wall53);
			wall.push_back(wall54);
			wall.push_back(wall55);
			wall.push_back(wall56);
			wall.push_back(wall57);
			wall.push_back(wall58);
			wall.push_back(wall59);
			wall.push_back(wall60);
			wall.push_back(wall61);
			wall.push_back(wall62);
			wall.push_back(wall63);
			wall.push_back(wall64);
			wall.push_back(wall65);
			wall.push_back(wall66);
			wall.push_back(wall67);
			wall.push_back(wall68);
			wall.push_back(wall69);
			wall.push_back(wall70);
			wall.push_back(wall71);
			wall.push_back(wall72);
			wall.push_back(wall73);
			wall.push_back(wall74);
			wall.push_back(wall75);
			wall.push_back(wall76);
			wall.push_back(wall77);
			wall.push_back(wall78);
			wall.push_back(wall79);
			wall.push_back(wall80);
			wall.push_back(wall81);
			wall.push_back(wall82);
			wall.push_back(wall83);
			wall.push_back(wall84);
			wall.push_back(wall85);
			wall.push_back(wall86);
			wall.push_back(wall87);
			wall.push_back(wall88);
			wall.push_back(wall89);
			wall.push_back(wall90);
			wall.push_back(wall91);
			wall.push_back(wall92);
			wall.push_back(wall93);
			wall.push_back(wall94);
			wall.push_back(wall95);
			wall.push_back(wall96);
			wall.push_back(wall97);
			wall.push_back(wall98);
			wall.push_back(wall99);
			wall.push_back(wall100);
			wall.push_back(wall101);
			wall.push_back(wall102);
			wall.push_back(wall103);
			wall.push_back(wall104);
			wall.push_back(wall105);
			wall.push_back(wall106);
			wall.push_back(wall107);
			wall.push_back(wall108);
			wall.push_back(wall109);
			wall.push_back(wall110);
			wall.push_back(wall111);
			wall.push_back(wall112);
			wall.push_back(wall113);
			wall.push_back(wall114);
			wall.push_back(wall115);
			wall.push_back(wall116);
			
			//wall.push_back(wall52);
			
			
			
			
			
			
			SDL_Rect wall_p1;
			wall_p1.x = 17*32;
			wall_p1.y = 32*32;
			wall_p1.w = 1;
			wall_p1.h = 64;
			
			SDL_Rect wall_p2;
			wall_p2.x = 11*32+31;
			wall_p2.y = 32*32;
			wall_p2.w = 1;
			wall_p2.h = 32;

			SDL_Rect wall_p3;
			wall_p3.x = 77*32;
			wall_p3.y = 156*32-1;
			wall_p3.w = 64;
			wall_p3.h = 1;

			SDL_Rect wall_p4;
			wall_p4.x = 77*32;
			wall_p4.y = 161*32;
			wall_p4.w = 64;
			wall_p4.h = 1;
			
			SDL_Rect wall_p5;
			wall_p5.x = 65*32;
			wall_p5.y = 132*32;
			wall_p5.w = 1;
			wall_p5.h = 32;
			
			SDL_Rect wall_p6;
			wall_p6.x = 65*32-1;
			wall_p6.y = 132*32;
			wall_p6.w = 1;
			wall_p6.h = 32;
			
			SDL_Rect wall_p7;
			wall_p7.x = 76*32;
			wall_p7.y = 128*32-1;
			wall_p7.w = 32;
			wall_p7.h = 1;
			
			SDL_Rect wall_p8;
			wall_p8.x = 79*32-13;
			wall_p8.y = 135*32;
			wall_p8.w = 1;
			wall_p8.h = 32;
			
			portwall.push_back(wall_p1);
			portwall.push_back(wall_p2);
			portwall.push_back(wall_p3);
			portwall.push_back(wall_p4);
			portwall.push_back(wall_p5);
			portwall.push_back(wall_p6);
			portwall.push_back(wall_p7);
			portwall.push_back(wall_p8);
			
			
}
