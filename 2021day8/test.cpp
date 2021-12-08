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
	return testMain("test1.1", "26");
}

void addTest(){

	testcases.push_front(testOne);

}

#endif 

#ifdef SECOND


bool testOne(){
	return testMain("test1.1", "61229");
}

bool testTwo(){
	return testMain("test2.1", "5353");
}

bool testThree(){
	return testMain("test3.1", std::to_string(1625 + 8717));
}

bool testFour(){
	return testMain("test4.1", "1043697");
}

void addTest(){
	//testcases.push_front(testTwo);
	//testcases.push_front(testOne);
	//testcases.push_front(testThree);

	testcases.push_front(testFour);
}

#endif

int main(){
	
	addTest();
	testRun();

}
