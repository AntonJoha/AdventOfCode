#include "run.h"
#include <iostream>
#define YLOW -126
#define YHIGH -69
#define NEGYLOW 126
#define XLOW 217
#define XHIGH 240

typedef struct vector2{
	int x;
	int y;

} vector2;

bool overShot(vector2 pos){
	if (pos.x > XHIGH) return true;
	if (pos.y < YLOW) return true;
	return false;

}

bool hit(vector2 pos){
	if (pos.y < YLOW || pos.y > YHIGH) return false;
	if (pos.x > XHIGH || pos.x < XLOW) return false;
	return true;
}

vector2 newPos(vector2 pos, vector2 vel){
	pos.x += vel.x;
	pos.y += vel.y;
	return pos;

}

vector2 newVel(vector2 vel){
	vel.y--;

	if (vel.x > 0) vel.x--;
	else if (vel.x < 0) vel.x++;

	return vel;

}

//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	
	//No code needed

	return "";
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND
std::string run::solve(std::ifstream* file){
	
	unsigned int count = 0;

	//20 came FROM THE POWER OF MATH
	
	for (int x = 20; x < XHIGH + 1; ++x){
		for (int y = YLOW; y < YLOW*(-1); ++y){
			vector2 pos;
			pos.x = 0;
			pos.y = 0;
			vector2 vel;
			vel.x = x;
			vel.y = y;
			std::cout << x << " " << y << "\n";
			while(!overShot(pos)){
				
				pos = newPos(pos, vel);
				vel = newVel(vel);

				if (hit(pos)){
					count++;
					break;
				}
			}
		}
	}

	
	return std::to_string(count);
}


#endif







