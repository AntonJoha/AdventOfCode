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


bool testMain(const char* filename, std::string expected){
	
	std::ifstream fs;
	fs.open(filename);
	if (!fs.is_open()) return false;
	std::string result = run::solve(&fs);
	fs.close();
	return expected == result;
}

#ifdef FIRST

bool testOne(){
	return testMain("test1.1", "4512");
}

bool testTwo(){
	return testMain("test1.2", "");
}

void addTest(){

	testcases.push_front(testOne);
	testcases.push_front(testTwo);

}

#endif 

#ifdef SECOND


bool testOne(){
	return testMain("test1.1", "1924");
}

void addTest(){

	testcases.push_front(testOne);
	
}

#endif

int main(){
	
	addTest();
	testRun();

}
