#include "run.h"
#include <vector>
#include <algorithm>
#include <iostream>

#define SIZE 100

char map[SIZE][SIZE];

void setZero(char m[SIZE][SIZE]){

	for (size_t i = 0; i < SIZE; ++i){
		for (size_t j  = 0; j < SIZE; ++j){
			map[i][j] = 0;
		}
	}
}

bool tryPos(size_t i, size_t j){
	if (i >= SIZE || i < 0) return false;
	if (j >= SIZE || j < 0) return false;
	return true;
}

#define CHECK(x, y, val, m) if(tryPos(x, y)){ \
	if (val >= m[x][y]) return false;}

bool checkLowest(size_t i, size_t j, char m[SIZE][SIZE]){
	
	size_t x = i, y = j -1;
	char val = m[i][j];
	
	CHECK(x, y, val, m);

	y = j + 1;
	CHECK(x, y, val, m);

	y = j;
	x = i - 1;
	CHECK(x, y, val, m);

	x = i + 1;
	CHECK(x, y, val, m);

	return true;
}

#undef CHECK

//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	
	setZero(map);
	
	size_t count = 0;
	std::string line;

	while (*file >> line){
		for (size_t i = 0; i < SIZE; ++i){
			
			map[count][i] = line[i];
		}

		++count;

	}
	
	count = 0;

	for (size_t i = 0; i < SIZE; ++i){
		for (size_t j = 0; j < SIZE; ++j){
		
			if (checkLowest(i, j, map)) count += map[i][j] - 47;
		}
	}

	return std::to_string(count);
}


#endif



unsigned int basinSize(size_t i, size_t j, char m[SIZE][SIZE]){
	
	if (!tryPos(i, j)) return 0;
	if (m[i][j] == '9') return 0;
	if (m[i][j] == 'a') return 0;
	unsigned int toReturn = 1; 
	m[i][j] = 'a';
	
	toReturn += basinSize(i + 1, j, m);
	toReturn += basinSize(i - 1, j, m);
	toReturn += basinSize(i, j + 1, m);
	toReturn += basinSize(i, j - 1, m);
	return toReturn;
}

//SECOND PROBLEM HERE
#ifdef SECOND

std::string run::solve(std::ifstream* file){
	

	setZero(map);

	size_t count = 0;
	std::string line;

	while (*file >> line){
		for (size_t i = 0; i < SIZE; ++i){
			
			map[count][i] = line[i];
		}

		++count;

	}
	

	std::vector<unsigned int> area;

	for (size_t i = 0; i < SIZE; ++i){
		for (size_t j = 0; j < SIZE; ++j){
			if (map[i][j] == 'a') continue;
			
			if (checkLowest(i, j, map)) area.push_back(basinSize(i, j, map));
		}
	}
	
	std::sort(area.begin(), area.end());
	
	unsigned int res = 1;

	for (size_t i = 1; i < 4; ++i) res *= area[area.size() - i];
	

	return std::to_string(res);
}



#endif







