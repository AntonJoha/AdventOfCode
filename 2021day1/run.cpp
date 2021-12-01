#include "run.h"

//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	
	unsigned int count = 0;
	int last;
	*file >> last;
	int val;
	while(*file >> val)
	{

		if (last < val) count++;
		last = val;

	}
	return std::to_string(count);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND
std::string run::solve(std::ifstream* file){
	
	int a;
	int b;
	int c; 
	
	unsigned int count = 0;
	
	*file >> a;
	*file >> b;
	*file >> c;

	
	int n;

	while (*file >> n){
		
		if (a < n) count++;

		a = b;
		b = c;
		c = n;
	}

	return std::to_string(count);
}


#endif







