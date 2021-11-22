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


bool testMain(const char* filename, std::string result){
	
	std::ifstream fs;
	fs.open(filename);
	if (!fs.is_open()) return false;
	std::string output = run::solve(&fs);
	fs.close();
	return result == output;
}


//WRITE TEST FOR FIRST PART HERE
#ifdef FIRST
bool testOne(){
	return testMain("test1", "0");
}

bool testTwo(){
	return testMain("test2", "3");
}


bool testThree(){
	return testMain("test3", "3");
}


bool testFour(){
	return testMain("test4", "-3");
}


void addTest()
{
	testcases.push_front(testOne);
	testcases.push_front(testTwo);
	testcases.push_front(testThree);
	testcases.push_front(testFour);
}


#endif

//WRITE TEST FOR SECOND PART HERE
#ifdef SECOND
bool testOne(){
	return testMain("test12", "1");
}

bool testTwo(){
	return testMain("test22", "5");
}


void addTest(){

	testcases.push_front(testOne);
	testcases.push_front(testTwo);
}

#endif
int main(){
	
	addTest();
	testRun();

}
