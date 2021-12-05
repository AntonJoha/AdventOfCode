#include "run.h"
#include <list>
#include <iostream>
#define DONE 2555

bool board::addNum(unsigned int sougth){

	for (size_t i = 0; i < 5; ++i){
		for (size_t j = 0; j < 5; ++j){
			
			if (values[i][j] == sougth){

				values[i][j] = DONE;
			}
		}
	}

	return checkDone();
}

unsigned board::getVal(){

	unsigned int total = 0; 
	
	for (size_t i = 0; i < 5; ++i){
		for (size_t j = 0; j < 5; ++j){
				unsigned int c = values[i][j];

				if (c != DONE) total += c;
				std::cout << c << " ";
		}
		std::cout << "\n";
	}
	
	return total;
}

board::board(std::ifstream* file){
	
	for (size_t i = 0; i < 5; ++i){
		
		for (size_t j = 0; j < 5; ++j){
			*file >> values[i][j];

			std::cout << values[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
	
bool board::checkDone(){

	for (size_t i = 0; i < 5; ++i){
		
		bool done = true;

		for (size_t j = 0; j < 5; ++j){
			
			if (values[i][j] != DONE){
				done = false;
			}
		}
		
		if (done) return true; 
	}
	for (size_t i = 0; i < 5; ++i){
		
		bool done = true;

		for (size_t j = 0; j < 5; ++j){
			
			if (values[j][i] != DONE){
				done = false;
			}

		}
		
		if (done) return true; 
	}
	return false;
}


//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
	
	std::list<unsigned int> val;
	unsigned int curr;

	while (*file >> curr){
		val.push_back(curr);

		if(file->peek() != ',') break;
		file->ignore();
	}
	
	
	std::list<board*> boards;

	while(!file->eof())
	boards.push_front(new board(file));
	
	boards.pop_front();

	while (true){
		unsigned count = 1;
		unsigned int curr = val.front();
		val.pop_front();
		
		std::cout << curr << ",";

		for (board* b : boards){
			

			bool ret = b->addNum(curr);

			if (ret){
				unsigned int sum = b->getVal();
				return std::to_string(sum*curr);
			}
			
			count++;
		}
		
		std::cout << "Max " << count << "\n";
	}
	
	return "";
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND
std::string run::solve(std::ifstream* file){
	
	std::list<unsigned int> val;
	unsigned int curr;

	while (*file >> curr){
		val.push_back(curr);

		if(file->peek() != ',') break;
		file->ignore();
	}
	
	
	std::list<board*> boards;

	while(!file->eof())
	boards.push_front(new board(file));
	
	boards.pop_front();

	while (true){
		int count = 0;
		unsigned int curr = val.front();
		val.pop_front();
		
		std::cout << curr << ",";
		
		std::list<unsigned int> toRemove;

		for (board* b : boards){

			bool ret = b->addNum(curr);

			if (ret){
				toRemove.push_front(count);
				if (boards.size() == 1){
					unsigned int v = b->getVal();
					std::cout << v << " " << curr;
					return std::to_string(v*curr);
				}
			}
			count++;
		}
		for (int i : toRemove){
			auto a = boards.begin();
			for (int j = 0; j < i; ++j) ++a;
			boards.erase( a);
		}
		std::cout << boards.size() << "\n";
	}
	
	return "";
}


#endif







