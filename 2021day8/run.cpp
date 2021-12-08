#include "run.h"
#include <algorithm>
#include <iostream>

//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	
	
	std::string values;
	unsigned int count = 0;
	while (*file >> values){

		for (size_t i = 1; i < 10; ++i){
			
			*file >> values;
		}

		std::string curr;

		*file >> curr;

		for (size_t i = 0; i < 4; ++i){
			
			*file >> curr;

			if (curr.size() == 2 || curr.size() == 3 || curr.size() == 4 || curr.size() == 7){	
					++count;
			}
		}
	}

	return std::to_string(count);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND
std::string findSize(std::string values[10], size_t size){
	

	for (size_t i = 0; i < 10; ++i){
		if (values[i].size() == size) return values[i];
	}
	return "";
}

void setTable(std::string list[10]){
	
	for (size_t i = 0; i < 10; ++i){
		list[i] = "abcdefg";
	}

}

char exclude(std::string from, std::string source){
	for (size_t i = 0; i < source.size(); ++i){
		from.erase(std::remove(from.begin(), from.end(), source[i]), from.end());
	}
	if (from.size() == 0) return 0;
	return from[0];
}

std::string findThree(std::string values[10], std::string seven){

	std::string potential[3];
	unsigned int count = 0;
	for (size_t i = 0; i < 10; ++i){
		if (values[i].size() == 5){
			potential[count] = values[i];
			count++;
		}
	}
	for (int i = 0; i < 3; ++i){
		if (exclude(seven, potential[i]) == 0) return potential[i];
	}
	return "";
}

std::string findNine(std::string values[10], std::string four){

	std::string potential[3];
	unsigned int count = 0;
	for (size_t i = 0; i < 10; ++i){
		if (values[i].size() == 6){
			potential[count] = values[i];
			count++;
		}
	}
	for (size_t i = 0; i < 3; ++i){
		if (exclude(four, potential[i]) == 0) return potential[i];
	}

	return "";
}

std::string findFive(std::string values[10], std::string six){
	std::string potential[3];
	unsigned int count = 0;
	for (size_t i = 0; i < 10; ++i){
		if (values[i].size() == 5){
			potential[count] = values[i];
			count++;
		}
	}
	for (int i = 0; i < 3; ++i){
		if (exclude(potential[i], six) == 0) return potential[i];
	}
	return "";

}

std::string findSix(std::string values[10], std::string one){
	std::string potential[3];
	unsigned int count = 0;
	for (size_t i = 0; i < 10; ++i){
		if (values[i].size() == 6){
			potential[count] = values[i];
			count++;
		}
	}
	for (size_t i = 0; i < 3; ++i){
		if (exclude(one, potential[i]) != 0) return potential[i];
	}

	return "";

}

std::string findZero(std::string values[10], std::string six, std::string nine){
	
	std::string potential[3];
	unsigned int count = 0;
	for (size_t i = 0; i < 10; ++i){
		if (values[i].size() == 6){
			potential[count] = values[i];
			count++;
		}
	}
	
	for (size_t i = 0; i < 3; ++i){
		
		std::string p = potential[i];
		if (p != six && p != nine) return p;
	}
	return "";
}

std::string findTwo(std::string values[10], std::string six, std::string nine){
	
	std::string potential[3];
	unsigned int count = 0;
	for (size_t i = 0; i < 10; ++i){
		if (values[i].size() == 5){
			potential[count] = values[i];
			count++;
		}
	}
	
	for (size_t i = 0; i < 3; ++i){
		
		std::string p = potential[i];
		if (p != six && p != nine) return p;
	}
	return "";
}


void solveTable(std::string table[10], std::string values[10]){
	
	table[1] = findSize(values, 2);
	table[4] = findSize(values, 4);
	table[7] = findSize(values, 3);
	table[3] = findThree(values, table[7]);
	table[9] = findNine(values, table[4]);
	table[6] = findSix(values, table[1]);
	table[5] = findFive(values, table[6]);
	
	table[0] = findZero(values, table[6], table[9]);
	table[2] = findTwo(values, table[3], table[5]);
	
	//Stämmer:
	//1 4 7 2 
}

std::string run::solve(std::ifstream* file){
	
	
	std::string values[10];
	std::string table[10];

	unsigned long long count = 0;
	
	unsigned hits = 0;
	unsigned total = 0;

	for (size_t i = 0; i < 10; ++i) std::sort(table[i].begin(), table[i].end());

	while (*file >> values[0]){

		for (size_t i = 1; i < 10; ++i){
			
			*file >> values[i];
		}
		
		setTable(table);
		
		
		solveTable(table, values);
		
		for (size_t i = 0; i < 10; ++i) std::sort(table[i].begin(), table[i].end());

		std::string curr;

		*file >> curr;

		for (size_t i = 0; i < 4; ++i){
			
			*file >> curr;
			
			++total;

			std::sort(curr.begin(), curr.end());

			for (size_t j = 0; j < 10; ++j){
				
				if (curr == table[j]){
					
					hits++;
					unsigned long mult[4] = {1000, 100, 10, 1};
					count += j*mult[i];
				}
			}
		}
	}
	
	std::cout << count << "\n";
	std::cout << hits << " " << total << "\n";
	return std::to_string(count);
}


#endif







