#include "run.h"
#include <iostream>
#include <stdlib.h>


//FIRST PROBLEM HERE
#ifdef FIRST

long calc(std::string*);

long  handle(long left, long right, char op){

	switch (op){
		case '+':
		return left + right;
		break;
		case '*':
		return left * right;
		break;
		default:
		return right;

	}

}

long calc(std::string *line){

	long sum = 0;
	char op = 0;

	while(true){

		char c = (*line)[0];
		line->erase(0, 1);
		

		if (c == 0) return sum;
		long right;

		switch(c){
			case ' ':
			break;
			case '+':
			op = '+';
			break;
			case '*':
			op = '*';
			break;
			case '(':
			right = calc(line);
			sum = handle(sum, right, op);
			break;
			case ')':
			return sum;
			default:
			sum = handle(sum, c - 48, op);
			break;
		}

	}

}

long init(std::string line){
	return calc(&line);

}


std::string run::solve(std::ifstream* file){
	
	long sum = 0;
	std::string line;
	while(std::getline(*file, line)){
		if (line.length() == 0) break;
		sum += init(line);
		std::cout << sum << '\n';
	}

	std::cout << sum << " IS RESULT\n";
	return std::to_string(sum);
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND


long init(std::string* line){


}

std::string run::solve(std::ifstream* file){
	
	long sum = 0;
	std::string line;
	while(std::getline(*file, line)){
		if (line.length() == 0) break;
		sum += init(line);
		std::cout << sum << '\n';
	}

	std::cout << sum << " IS RESULT\n";
	return std::to_string(sum);
}



#endif







