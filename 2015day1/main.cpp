#include <iostream>
#include <fstream>
#include "run.h"


int main(){

	std::fstream fs;
	fs.open("input");
	if (!fs) return -1;
	std::string result = run::solve(&fs);
	
	fs.close();
	std::cout << result << '\n';
	std::cout << "aaaaaa\n";
}
