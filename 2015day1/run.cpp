#include "run.h"
#include <iostream>


//FIRST IMPLEMENTATION HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	
	int level = 0;
	while (true)
	{

		char c = file->get();

		if(c == EOF) break;

		if (c == '(') ++level;
		else if (c == ')') --level;

	}
	
	return std::to_string(level);
}

#endif

//SECOND IMPLEMENTATION HERE
#ifdef SECOND

std::string run::solve(std::ifstream* file){

	
	int level = 0; 
	int pos = 1;
	while (true)
	{
		char c = file->get();
		
		if (c == EOF) break;

		
		if (c == '(') ++level;
		else if (c == ')') --level;

		if (level < 0) break;

		++pos;
	}


	return std::to_string(pos);
}

#endif


