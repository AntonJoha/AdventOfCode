#include "run.h"
#include <vector>
#include <iostream>

#define LENGTH 12

void setZero(int * l, size_t n) {
	
	for (size_t i = 0; i < n; ++i) l[i] = 0; 
}

//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	
	
	std::string in;

	int list[LENGTH];
		
	setZero(list, LENGTH);


	while(*file >> in){
		
		for (int i = 0; i < LENGTH; ++i){
		
			if (in[i] == '1') list[i]++;
			else list[i]--;
		}

	}
	
	unsigned int gamma = 0, epsilon = 0;

	for (size_t i = 0; i < LENGTH; ++i){
		
		gamma = gamma << 1;
		epsilon = epsilon << 1;
		
		if (list[i] > 0){
			gamma += 1;
		}
		else {
			epsilon += 1;
		}

	}
	return std::to_string(gamma*epsilon);
}


#endif

void removeIf(std::vector<std::string>* list, size_t pos, bool one){
	
	std::vector<std::string> copy = *list;
	char c = one ? '1' : '0';
	for (int i = list->size() - 1; i >= 0; --i){
		if (copy[i][pos] != c){
			
			list->erase(list->begin() + i);
		
		}
	}

}


//SECOND PROBLEM HERE
#ifdef SECOND
std::string run::solve(std::ifstream* file){
	

	std::vector<std::string> ox;
	std::vector<std::string> co;

	std::string in;

	while(*file >> in){
		ox.push_back(in);
		co.push_back(in);
	}

	for (size_t i = 0; i < LENGTH; ++i){
		
		bool res = true;
		int count = 0;
		for (std::string val : ox){
			if (val[i] == '1') count++;
			else count--;
		}
		res = count >= 0;
		removeIf(&ox, i, res);

		count = 0;
		for (std::string val : co){
			if (val[i] == '1') count++;
			else count--;
		}

		res = count < 0;
		removeIf(&co, i, res);

	}

	unsigned int cu = 0, ou = 0;
	std::string cs = co[0];
	std::string os = ox[0];
	for (unsigned int i = 0; i < LENGTH; ++i){
		cu = cu << 1;
		ou = ou << 1;
		
		if (cs[i] == '1') cu++;
		if (os[i] == '1') ou++;
	}
	
	std::cout << cu*ou <<"\n" <<cs << " " << os;
	return std::to_string(cu*ou);
}


#endif







