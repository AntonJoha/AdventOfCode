#include "run.h"
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

//FIRST PROBLEM HERE
#ifdef FIRST

unsigned int calc(char c){

	switch(c){
		case(')'): return 3; break;
		case(']'): return 57; break;
		case('>'): return 25137; break;
		default: return 1197; break;

	}

}

unsigned int pushDown(std::string line){
	std::list<char> stack; 

	for (int i = 0; i < line.size(); ++i){
		
		char curr = line[i];

		switch(curr){
			case '(':
				stack.push_front(')');
				break;
			case '[':
				stack.push_front(']');
				break;
			case '{':
				stack.push_front('}');
				break;
			case '<':
				stack.push_front('>');
				break;
			default:
				char comp = stack.front();
				stack.pop_front();
				if (comp != curr) return calc(curr);

		}
	}

	return 0;

}

std::string run::solve(std::ifstream* file){
	
	std::string line;
	unsigned int result = 0;
	
	while(*file >> line) result += pushDown(line);

	return std::to_string(result);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND

unsigned long calc(std::list<char> stack){
	
	unsigned long count = 0;
	while(stack.size() != 0){

		count *= 5;

		char c = stack.front();
		stack.pop_front();

		switch (c){
			case ')': count += 1; break;
			case ']': count += 2; break;
			case '}': count += 3; break;
			case '>': count += 4; break;
			default: break;
		}
	}
	return count;
}

unsigned long pushDown(std::string line){
	std::list<char> stack; 

	for (int i = 0; i < line.size(); ++i){
		
		char curr = line[i];

		switch(curr){
			case '(':
				stack.push_front(')');
				break;
			case '[':
				stack.push_front(']');
				break;
			case '{':
				stack.push_front('}');
				break;
			case '<':
				stack.push_front('>');
				break;
			default:
				char comp = stack.front();
				stack.pop_front();
				if (comp != curr) return 0;

		}
	}

	return calc(stack);

}

std::string run::solve(std::ifstream* file){
	
	std::string line;
	std::vector<unsigned long> scores;
	while(*file >> line) {
		unsigned long val = pushDown(line);
		if (val != 0) scores.push_back(val);
	}
	std::sort(scores.begin(), scores.end());

	size_t pos = scores.size() /2;
	return std::to_string(scores[pos]);
}

#endif







