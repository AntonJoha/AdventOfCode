#include "run.h"
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>


//FIRST PROBLEM HERE
#ifdef FIRST

std::string expand(std::string input, std::map<std::string, std::string> relations){
	
	std::string toReturn = "";
	toReturn += input[0];
	unsigned long count = 0;
	for(size_t i = 1; i < input.size(); ++i){
		if (relations[input.substr(i-1, 2)] != ""){
			count++;
			toReturn += relations[input.substr(i-1, 2)];
		}
		toReturn += input[i];
	}
	return toReturn;
}

std::string run::solve(std::ifstream* file){
	
	std::map<std::string, std::string> relations;
	std::map<std::string, unsigned long> pairCount;
	std::vector<char> seen;
	std::string input;
	*file >> input;
	std::string name;
	std::string result;
	while(*file >> name){
		//Get rid of ->
		*file >> result;
		
		*file >> result;

		relations[name] = result;
		seen.push_back(result[0]);
	}
	
	std::sort(seen.begin(), seen.end());
	auto u = std::unique(seen.begin(), seen.end());
	seen.erase(u, seen.end());
	for(size_t i = 0; i < 10; ++i){
		input = expand(input, relations);
	}
	
	unsigned long low = UINT_MAX - 1;
	unsigned long high = 0;
	for (char c : seen){
		unsigned long current = 0;

		for (size_t i = 0; i < input.size(); ++i){
			if (input[i] == c) ++current;
		}
		if (current < low) low = current;
		if (current > high) high = current;
	}
	return std::to_string(high - low);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND

std::map<std::string, unsigned long> expand(std::map<std::string, unsigned long> input, std::map<std::string, std::string> relations){
	
	std::map<std::string, unsigned long> toReturn;
	
	for(auto i = relations.begin(); i != relations.end(); ++i) toReturn[i->first] = 0;

	for(auto i = input.begin(); i != input.end(); ++i){
		
		std::string s = relations[i->first];
		std::string name = i->first[0] + s;
		toReturn[name] += i->second;
		name = s + i->first[1];
		toReturn[name] += i->second;

	}

	return toReturn;
}

std::map<std::string, unsigned long> makeInput(std::string s){
	
	std::map<std::string, unsigned long> toReturn;
	
	for(size_t i = 1; i < s.size(); ++i){
		
		std::string a = s.substr(i - 1, 2);
		toReturn[a]++;
	}
	return toReturn;
}

std::string run::solve(std::ifstream* file){
	
	std::map<std::string, std::string> relations;
	std::vector<char> seen;
	std::string input;
	*file >> input;
	std::string name;
	std::string result;
	
	std::map<std::string, unsigned long> amount = makeInput(input);
	 

	char start = input[0];
	char end = input[input.size() - 1];

		while(*file >> name){
		//Get rid of ->
		*file >> result;
		*file >> result;

		relations[name] = result;
		seen.push_back(result[0]);
	}
	
	std::sort(seen.begin(), seen.end());
	auto u = std::unique(seen.begin(), seen.end());
	seen.erase(u, seen.end());
	
	std::map<char, unsigned long> charCount;
	for (char c : seen){
		charCount[c] = 0;
	}

	for(size_t i = 0; i < 40; ++i){
		amount = expand(amount, relations);
	}
	

	unsigned long high = 0;
	unsigned long low = ULONG_MAX;
	charCount[start]++;
	charCount[end]++;
	for (auto i = amount.begin(); i != amount.end(); ++i){

		for (size_t j = 0; j < 2; ++j){
			char c = i->first[j];
			charCount[c] += i->second;
		}
	}
	
	for (auto i = charCount.begin(); i != charCount.end(); ++i){
		unsigned long count = i->second/2;
		if (count > high) high = count;
		if (count < low) low = count;
	}
	return std::to_string(high - low);
}

#endif







