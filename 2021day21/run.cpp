#include "run.h"
#include <iostream>
#define STARTONE 1
#define STARTTWO 7

//FIRST PROBLEM HERE
#ifdef FIRST
#define MAXSIZE 10
#define WINNING 1000



std::string run::solve(std::ifstream* file){
	
	unsigned int point1 = 0;
	unsigned int point2 = 0;
	unsigned int pos1 = STARTONE;
	unsigned int pos2 = STARTTWO;
	unsigned int count = 1;
	while (true){

		for (size_t i = 0; i < 3; ++i){
			pos1 = ((count%100) + pos1) % 10;
			++count;
		}
		point1 += 1 + pos1;

		if (point1 >= WINNING){
			return std::to_string( (count - 1)*point2);
		}
		
		for (size_t i = 0; i < 3; ++i){
			pos2 = ((count%100) + pos2) % 10;
			++count;
		}
		point2 += 1 + pos2;

		if (point2 >= WINNING){
			return std::to_string( (count - 1)*point1);
		}

	}

	return "";
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND

#define WINNING 21

unsigned long points(unsigned int val1, unsigned int val2, unsigned int pos1, unsigned int pos2, bool turnP1, bool retP1);

unsigned long callNew(unsigned int val1, unsigned int val2, unsigned int pos1, unsigned int pos2, bool turnP1, bool retP1, unsigned int add){
	
	if (turnP1){
		pos1 = (pos1 + add)%10;
		val1 += pos1 + 1;
	}
	else{
		pos2 = (pos2 + add)%10;
		val2 += pos2 + 1;
	}
	return points(val1, val2, pos1, pos2, !turnP1, retP1);
}

unsigned long points(unsigned int val1, unsigned int val2, unsigned int pos1, unsigned int pos2, bool turnP1, bool retP1){
	
	if (val1 >= WINNING){
		if (retP1) return 1;
		else return 0;
	}
	if (val2 >= WINNING){
		if (retP1) return 0;
		else return 1;
	}


	unsigned long toReturn = 0;
	
#define MORE(x, y, z) x += y*callNew(val1, val2, pos1, pos2, turnP1, retP1, z)

	//There are 21 different combinations 
	// 3 3 3 one time 9
	//9 , 1  
	
	MORE(toReturn, 1, 9);

	// 3 3 2 three times 8
	// 8, 3

	MORE(toReturn, 3, 8);

	// 3 3 1 three times 7
	// 2 2 3 three times 7
	// 7, 6

	MORE(toReturn, 6, 7);

	// 2 2 2 one time 6 
	// 3 2 1 six times 6
	// 6, 7

	MORE(toReturn, 7, 6);

	// 2 2 1 three times 5
	// 1 1 3 three times 5
	// 5, 6
	
	MORE(toReturn, 6, 5);

	// 1 1 2 three times 4
	// 4, 3
	
	MORE(toReturn, 3, 4);

	// 1 1 1 one time 3 
	// 3, 1
	
	MORE(toReturn, 1, 3);

	return toReturn;
				
}


std::string run::solve(std::ifstream* file){
	
	unsigned long first =  points(0,0,  STARTONE, STARTTWO, true, true);
	unsigned long second = points(0,0, STARTONE, STARTTWO, true, false);

	if (first < second) return std::to_string(second);



	return std::to_string(first);
}


#endif







