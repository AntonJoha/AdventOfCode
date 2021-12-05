#include "run.h"
#include <iostream>
#include <list>

typedef struct pos{

	unsigned int x, y;
}pos;

typedef struct movement{
	pos start,end;
}movement;


bool notDiagonal(movement* m){
	
	unsigned int count = 0;

	if (m->end.x != m->start.x) ++count;
	if (m->end.y != m->start.y) ++count;

	return count == 1;

}

#define LAZY(x, y) if(x > y) y = x



//FIRST PROBLEM HERE
#ifdef FIRST

#define LAZY(x, y) if(x > y) y = x

std::string run::solve(std::ifstream* file){
	
	unsigned val;
	
	std::list<movement*> moves;
	unsigned maxY = 0, maxX = 0;
	while (*file >> val){
		
		movement *m = new movement();

		m->start.x = val;

		file->ignore();

		*file >> m->start.y; 

		for(int i = 0; i < 3; ++i) file->ignore();

		*file >> m->end.x;
		file->ignore();
		*file >> m->end.y;

		moves.push_back(m);

		LAZY(m->end.x, maxX);
		LAZY(m->start.x, maxX);
		LAZY(m->end.y, maxY);
		LAZY(m->start.y, maxY);
	}

	unsigned int board[maxX + 1][maxY + 1];
	
	for (size_t i = 0; i < maxX + 1; ++i){
		for (size_t j = 0; j < maxY + 1; ++j) board[i][j] = 0; 

	}

	for (movement * m : moves){
		
		if(!notDiagonal(m)) continue;
		
		unsigned xLow = m->start.x, xHigh = m->end.x;
		unsigned yLow = m->start.y, yHigh = m->end.y;

		if (xLow > xHigh){
			unsigned temp = xLow;
			xLow = xHigh;
			xHigh = temp;
		}
		if (yLow > yHigh){
			unsigned temp = yLow;
			yLow = yHigh;
			yHigh = temp;
		}
		
		for (size_t x = xLow; x <= xHigh; ++x){
			for (size_t y = yLow; y <= yHigh; ++y) ++board[x][y];
		}
	}
	unsigned int count = 0;

	for (size_t i = 0; i < maxX + 1; ++i){
		for (size_t j = 0; j < maxY +1; ++j){
			if (board[i][j] > 1) count++;
		}

	}

	return std::to_string(count);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND

std::string run::solve(std::ifstream* file){
	
	unsigned val;
	
	std::list<movement*> moves;
	unsigned maxY = 0, maxX = 0;
	while (*file >> val){
		
		movement *m = new movement();

		m->start.x = val;

		file->ignore();

		*file >> m->start.y; 

		for(int i = 0; i < 3; ++i) file->ignore();

		*file >> m->end.x;
		file->ignore();
		*file >> m->end.y;

		moves.push_back(m);

		LAZY(m->end.x, maxX);
		LAZY(m->start.x, maxX);
		LAZY(m->end.y, maxY);
		LAZY(m->start.y, maxY);
	}

	unsigned int board[maxX + 1][maxY + 1];
	
	for (size_t i = 0; i < maxX + 1; ++i){
		for (size_t j = 0; j < maxY + 1; ++j) board[i][j] = 0; 

	}

	for (movement * m : moves){
		
		if(!notDiagonal(m)){
			
			unsigned xLow = m->start.x, xHigh = m->end.x;
			unsigned yLow = m->start.y, yHigh = m->end.y;
			unsigned steps = xHigh - xLow;
			bool xInvert = false;
			if (xLow > xHigh){
				steps = xLow - xHigh;
				xInvert = true;
			}
			bool yInvert = false;
			if (yLow > yHigh){
				yInvert = true;
			}

			for (unsigned i = 0; i <= steps; ++i){
				unsigned xPos = xLow;
				xPos += xInvert ? -i : i;
				unsigned yPos = yLow;
				yPos += yInvert ? -i : i; 
				board[xPos][yPos]++;
			}
			continue;
		}
		
		unsigned xLow = m->start.x, xHigh = m->end.x;
		unsigned yLow = m->start.y, yHigh = m->end.y;

		if (xLow > xHigh){
			unsigned temp = xLow;
			xLow = xHigh;
			xHigh = temp;
		}
		if (yLow > yHigh){
			unsigned temp = yLow;
			yLow = yHigh;
			yHigh = temp;
		}
		
		for (size_t x = xLow; x <= xHigh; ++x){
			for (size_t y = yLow; y <= yHigh; ++y) ++board[x][y];
		}
	}
	unsigned int count = 0;

	for (size_t i = 0; i < maxX + 1; ++i){
		for (size_t j = 0; j < maxY +1; ++j){
			if (board[i][j] > 1) count++;
		}

	}
	std::cout << count << "\n";
	return std::to_string(count);
}
#endif







