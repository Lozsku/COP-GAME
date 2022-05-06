using namespace std;

#ifndef WALL_H
#define WALL_H
class Wall_Array {
public:

	Wall_Array();	
	vector<SDL_Rect> wall;
	vector<SDL_Rect> portwall;
	vector<SDL_Rect> easterwall;
	
};
#endif
