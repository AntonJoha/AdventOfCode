#include <fstream>
#include <iostream>
#include <list>
#include "run.h"


typedef bool (*test)();

std::list<test> testcases;

void testRun(){
	
	int i = 1;
	for (test t : testcases){
		if (t())
		{
			std::cout << "Passed test: " << i << "\n";
		}
		else
		{
			std::cout << "Didn't pass test: " << i << "\n"; 
		}
		++i;
	}
}


bool testOne(){
	
	std::fstream fs;
	fs.open("test1", std::fread);
	if (!fs.is_open()) return false;
	std::string result = run::solve(&fs);
	fs.close();
	return "" == result;
}


void addTest()
{
	testcases.push_front(testOne);
}

int main(){
	
	addTest();
	testRun();

}
