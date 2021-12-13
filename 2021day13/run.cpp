#include "run.h"
#include <iostream>
#include <string>

#define STARTX 1311
#define STARTY 894


//FIRST PROBLEM HERE
#ifdef FIRST

bool ** xSplit(bool ** table, size_t pos, size_t xSize, size_t ySize){

	bool ** toReturn = (bool**) malloc(sizeof(bool*)*pos);

	for(size_t i = 0; i < pos; ++i){
		toReturn[i] = (bool*)malloc(sizeof(bool)*ySize);
		for(size_t j = 0; j < ySize; ++j) toReturn[i][j] = false; 
	}
	
	for(size_t i = 0; i < pos; ++i){
		for (size_t j = 0; j < ySize; ++j){
			toReturn[i][j] =  (table[i][j] || table[xSize - i - 1][j]);
		}
		free(table[i]);
		free(table[xSize - i - 1]);
	}
	
	free(table);

	return toReturn;
}


bool ** ySplit(bool ** table, size_t pos, size_t xSize, size_t ySize){

	bool ** toReturn = (bool**) malloc(sizeof(bool*)*xSize);

	for(size_t i = 0; i < xSize; ++i){
		toReturn[i] = (bool*)malloc(sizeof(bool)*pos);
		for(size_t j = 0; j < pos; ++j) toReturn[i][j] = false; 
	}
	
	for(size_t i = 0; i < xSize; ++i){
		for (size_t j = 0; j < pos; ++j){
			toReturn[i][j] = (table[i][j] || table[i][ySize - 1 - j]);
		}
		free(table[i]);
	}
	
	free(table);

	return toReturn;
}


std::string run::solve(std::ifstream* file){
	
	unsigned int xPos = 1311;
	unsigned int yPos = 895;
	
	bool ** table = (bool**) malloc(sizeof(bool*) * xPos);

	for(unsigned int i = 0; i < xPos; ++i){
		table[i] = (bool*) malloc(sizeof(bool)*yPos);
		for(unsigned int j = 0; j < yPos; ++j) table[i][j] = false;
	}
	

	std::string xString;
	std::string yString;

	while(*file >> xString){
		if(xString == "c") break;
		*file >> yString;

		unsigned int x = stoul(xString);
		unsigned int y = stoul(yString);

		table[x][y] = true;
	}
	
	table = xSplit(table, 655, xPos, yPos);
	unsigned int count = 0;

	for(size_t i = 0; i < 655; ++i){
		for(size_t j = 0; j < yPos; ++j){
			if(table[i][j]) ++count;
		}
	}

	return std::to_string(count);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND

bool ** xSplit(bool ** table, size_t pos, size_t xSize, size_t ySize){

	bool ** toReturn = (bool**) malloc(sizeof(bool*)*pos);

	for(size_t i = 0; i < pos; ++i){
		toReturn[i] = (bool*)malloc(sizeof(bool)*ySize);
		for(size_t j = 0; j < ySize; ++j) toReturn[i][j] = false; 
	}
	
	for(size_t i = 0; i < pos; ++i){
		for (size_t j = 0; j < ySize; ++j){
			toReturn[i][j] =  (table[i][j] || table[xSize - i - 1][j]);
		}
		free(table[i]);
		free(table[xSize - i - 1]);
	}
	
	free(table);

	return toReturn;
}


bool ** ySplit(bool ** table, size_t pos, size_t xSize, size_t ySize){

	bool ** toReturn = (bool**) malloc(sizeof(bool*)*xSize);

	for(size_t i = 0; i < xSize; ++i){
		toReturn[i] = (bool*)malloc(sizeof(bool)*pos);
		for(size_t j = 0; j < pos; ++j) toReturn[i][j] = false; 
	}
	
	for(size_t i = 0; i < xSize; ++i){
		for (size_t j = 0; j < pos; ++j){
			toReturn[i][j] = (table[i][j] || table[i][ySize - 1 - j]);
		}
		free(table[i]);
	}
	
	free(table);

	return toReturn;
}


std::string run::solve(std::ifstream* file){
	
	unsigned int xPos = 1311;
	unsigned int yPos = 895;
	
	bool ** table = (bool**) malloc(sizeof(bool*) * xPos);

	for(unsigned int i = 0; i < xPos; ++i){
		table[i] = (bool*) malloc(sizeof(bool)*yPos);
		for(unsigned int j = 0; j < yPos; ++j) table[i][j] = false;
	}
	

	std::string xString;
	std::string yString;

	while(*file >> xString){
		if(xString == "c") break;
		*file >> yString;

		unsigned int x = stoul(xString);
		unsigned int y = stoul(yString);

		table[x][y] = true;
	}
	
	std::string type;
	std::string pos;

	while(*file >> type){
		
		*file >> pos;
		unsigned int position = stoul(pos);
		if (type == "y"){
			table = ySplit(table, position, xPos, yPos);
			yPos = position;
		}
		else{
			table = xSplit(table, position, xPos, yPos);
			xPos = position;
		}
	}

	for(size_t i = 0; i < xPos; ++i){
		for(size_t j = 0; j < yPos; ++j){
			if(table[xPos - 1 - i][j]) std::cout << "#";
			else std::cout << ".";
		}
		std::cout << "\n";
	}

	return "";
}


#endif







