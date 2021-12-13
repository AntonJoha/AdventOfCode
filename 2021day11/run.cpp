#include "run.h"
#include <iostream>
#define SIZE 10

char table[10][10];

bool validPos(int i, int j){
	
	if ( i < 0 || i >= 10) return false;
	if (j < 0 || j>= 10) return false;

	return true;

}

//FIRST PROBLEM HERE
bool increasePos(const int i,const int j){
	
	if (!validPos(i, j)) return false;
	if (table[i][j] == '0') return false;

	table[i][j]++;
	

	return table[i][j] > '9';
}

void increase(){

	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			table[i][j]++;
		}
	}
}

unsigned int flash(int i, int j){
	
	if (!validPos(i, j)) return 0;
	
	table[i][j] = '0';

	unsigned int toReturn = 1;
	

	for (int x = -1; x < 2; ++x){
		for (int y = -1; y < 2; ++y){

			if (increasePos(i + x, j + y)){
				toReturn += flash(i + x, j + y);
			}

		}

	}
	return toReturn;
}


unsigned int calcFlashes(){
	
	unsigned int toReturn = 0;
	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
				
			if (table[i][j] > '9'){
				
				toReturn += flash(i, j);
			}
		}

	}
	return toReturn;
}



unsigned int update(){
	
	increase();
	
	return calcFlashes();

}


void printAll(){
	
	for (int i = 0; i < SIZE; ++i){
		for( int j = 0; j < SIZE; ++j){
			std::cout << table[i][j];

		}
		std::cout << "\n";
	}

}

#ifdef FIRST


std::string run::solve(std::ifstream* file){
	
	std::string line;
	unsigned int count = 0;

	while (*file >> line){
		
		for (int i = 0; i < SIZE; ++i){
			table[count][i] = line[i];
		}
		++count;
	}
	
	unsigned int res = 0;

	for (int i = 0; i < 100; ++i){
		res += update();
	}
	return std::to_string(res);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND

std::string run::solve(std::ifstream* file){
	
	std::string line;
	unsigned int count = 0;

	while (*file >> line){
		
		for (int i = 0; i < SIZE; ++i){
			table[count][i] = line[i];
		}
		++count;
	}
	
	count = 1;

	while (true){
		unsigned int res = update();
		if (res == 100) return std::to_string(count);
		++count;
	}

	return "";
}


#endif







