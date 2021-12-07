#include "run.h"
#include <vector>
#include <algorithm>
#include <iostream> 


//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	
	std::vector<unsigned int> values;

	unsigned int curr;

	while (*file >> curr){

		if (file->peek() == ',') file->ignore();
		values.push_back(curr);
	}
	
	std::sort(values.begin(), values.end());

	
	size_t val = values[values.size()/2];
	
	unsigned int res = 0;
	for (unsigned int i : values){
		
		res += (val < i) ? i - val : val - i;
	}

	return std::to_string(res);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND

unsigned int calc(unsigned int val, std::vector<unsigned int>* list){
	
	unsigned int size = list->size();
	unsigned int toReturn = 0;
	for (size_t i = 0; i < size; ++i){

		unsigned int res = (val < list->at(i)) ? list->at(i) - val : val - list->at(i);

		toReturn += res*(res + 1)/2;

	}
	return toReturn;
}

std::string run::solve(std::ifstream* file){
	
	std::vector<unsigned int> values;

	unsigned int curr;
	unsigned int total = 0;
	while (*file >> curr){

		if (file->peek() == ',') file->ignore();
		values.push_back(curr);
		total += curr;
	}
	

	unsigned int average = total/values.size();
	
	unsigned lower = calc(average -1, &values);
	unsigned on = calc(average, &values);
	unsigned over = calc(average + 1, &values);
	
	if (on < lower) lower = on;
	if (over < lower) lower = over;

	return std::to_string(lower);
}


#endif







