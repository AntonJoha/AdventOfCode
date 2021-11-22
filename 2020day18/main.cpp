#include <iostream>
#include <fstream>
#include "run.h"


int main(){

	std::ifstream fs;
	fs.open("input");
	if (!fs) return -1;
	std::string result = run::solve(&fs);
	
	fs.close();
	std::cout << result << '\n';
}
