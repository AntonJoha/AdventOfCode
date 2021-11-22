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

bool test1(){
	return testMain("test1.1", "26");
}

bool test2(){
	return testMain("test2.1", "437");
}


bool test3(){
	return testMain("test3.1", "12240");
}


bool test4(){
	return testMain("test4.1", "13632");
}


bool test5(){
	return testMain("test5.1", "26335");
}


void addTest(){

	testcases.push_front(test5);
	testcases.push_front(test4);
	testcases.push_front(test3);
	testcases.push_front(test2);
	testcases.push_front(test1);
}

#endif 

#ifdef SECOND


bool test1(){
	return testMain("test1.2", "51");
}

bool test2(){
	
	return testMain("test2.2", "46");

}

bool test3(){
	
	return testMain("test3.2", "1445");

}

bool test4(){

	return testMain("test4.2", "669060");

}

bool test5(){
	return testMain("test5.2", "23340");
}

void addTest(){
	
	testcases.push_front(test5);
	testcases.push_front(test4);
	testcases.push_front(test3);
	testcases.push_front(test2);
	testcases.push_front(test1);
	
}

#endif

int main(){
	
	addTest();
	testRun();

}
