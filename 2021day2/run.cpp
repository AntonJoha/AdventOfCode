#include "run.h"

//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	unsigned int depth = 0;
	unsigned int horiz = 0; 
	
	char s[10];
	unsigned int amount;
	while (*file >> s){
		
		*file >> amount;
		
		switch(s[0]){
			case 'd':
			depth += amount;
			break;
			case 'f':
			horiz += amount;
			break;
			default:
			depth -= amount;
			break;
		}

	}

	return std::to_string(depth*horiz);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND
std::string run::solve(std::ifstream* file){
	unsigned int depth = 0;
	unsigned int horiz = 0; 
	unsigned int aim = 0;
	char s[10];
	unsigned int amount;
	while (*file >> s){
		
		*file >> amount;
		
		switch(s[0]){
			case 'd':
			aim += amount;
			break;
			case 'f':
			horiz += amount;
			depth += aim*amount;
			break;
			default:
			aim -= amount;
			break;
		}

	}

	return std::to_string(depth*horiz);
}

#endif







