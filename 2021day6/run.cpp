#include "run.h"
#include <iostream>

//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	
	unsigned list[10];

	for (size_t i= 0; i < 10; ++i) list[i] = 0;

	unsigned temp;

	while(*file >> temp){
		
		list[temp]++;

		if (file->peek() == ',') file->ignore();
	}
	
	for (size_t i = 0; i < 10; ++i){
		
		std::cout << i << " " << list[i] << "\n";

	}

	for (size_t i = 0; i < 80; ++i){
		
		list[9] += list[0];
		list[7] += list[0];

		for (size_t j = 1; j < 10; ++j) list[j-1] = list[j];
		list[9] = 0;
		

	}

	unsigned int count = 0;

	for (size_t i = 0; i<10; ++i) count += list[i];
	


	return std::to_string(count);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND
std::string run::solve(std::ifstream* file){
	
	unsigned long list[10];

	for (size_t i= 0; i < 10; ++i) list[i] = 0;

	unsigned temp;

	while(*file >> temp){
		
		list[temp]++;

		if (file->peek() == ',') file->ignore();
	}
	
	for (size_t i = 0; i < 10; ++i){
		
		std::cout << i << " " << list[i] << "\n";

	}

	for (size_t i = 0; i < 256; ++i){
		
		list[9] += list[0];
		list[7] += list[0];

		for (size_t j = 1; j < 10; ++j) list[j-1] = list[j];
		list[9] = 0;
		

	}

	unsigned long count = 0;

	for (size_t i = 0; i<10; ++i) count += list[i];
	


	return std::to_string(count);
}



#endif







