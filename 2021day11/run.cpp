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
#ifdef FIRST

bool increasePos(const int i,const int j){
	
	if (!validPos(i, j)) return false;
	if (table[i][j] == '0') return false;

	table[i][j]++;
	
	std::cout << "NEW" << " " << table[i][j] << "\n";[i][j] << "\n";

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
	

	const int diff[12] = {-1, -1,
		0, -1,
		-1, 0,
		1, 1,
		0, 1,
		1, 0};

	for (int x = 0; x < 6; ++x){
		if (increasePos(i + diff[2*x], j + diff[2*x + 1])){
			std::cout << "FOUND\n";
			toReturn += flash(i + diff[2*x], j + diff[2*x + 1]);
		}
	}

	/*
	for (int x = 0; x < 3; ++x){
		
		if (increasePos(i - 1 + x, j - 1)){
			toReturn += flash(i - 1 + x, j - 1);
		}
		if (increasePos(i - 1 + x, j  + 1)){
			toReturn += flash(i - 1 + x, j  + 1);
		}
	}
	
	for (int x = -1; x < 2; x += 2){
		
		if (increasePos(i, j + x)){
			toReturn += flash(i, j + x);
		}
	}

	*/
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

	for (int i = 0; i < 10; ++i){
		res += update();
		std::cout << res << "\n";
		
		printAll();

	}
	std::cout << res;
	return std::to_string(res);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND
std::string run::solve(std::ifstream* file){
	

	return "";
}


#endif







