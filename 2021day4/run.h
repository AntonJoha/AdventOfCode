#ifndef RUN_PROGRAM_H
#define RUN_PROGRAM_H
#include <string>
#include <fstream>

class board{

public: 
	bool addNum(unsigned int);
	unsigned getVal();
	board(std::ifstream*);
	
private: 
	unsigned int values[5][5];
	bool checkDone();


};


class run{
public:

	static std::string solve(std::ifstream *input);

};

#endif
