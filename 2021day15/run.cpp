#include "run.h"
#include <climits>
#include <iostream>

#ifdef FIRST
#define SIZE 100
#endif

#ifdef SECOND
#define SIZE 50
#endif

typedef struct pos_t{

	int x;
	int y;
}pos_t;

unsigned long table[SIZE][SIZE];
unsigned long weigth[SIZE][SIZE];


bool allowedPos(pos_t pos){

	if (pos.x < 0 || pos.x >= SIZE) return false;
	if (pos.y < 0 || pos.y >= SIZE) return false;
	else return true;
}

pos_t findPos(bool visited[SIZE][SIZE]){
	
	pos_t toReturn;
	toReturn.x = 0;
	toReturn.y = 0;
	if (visited[0][0] == false) return toReturn;
	unsigned int current = UINT_MAX;
	for (size_t i = 0; i < SIZE; ++i){
		for (size_t j = 0; j < SIZE; ++j){
			
			if (!visited[i][j] && weigth[i][j] < current){
				toReturn.x = i;
				toReturn.y = j;
				current = weigth[i][j];
			}

		}
	}
	return toReturn;
}

void updateVal(pos_t pos, pos_t copy){
	
	if(weigth[copy.x][copy.y] == UINT_MAX){ 
		weigth[copy.x][copy.y] = weigth[pos.x][pos.y] + table[copy.x][copy.y];
	}
	else if (weigth[copy.x][copy.y] > weigth[pos.x][pos.y] + table[copy.x][copy.y]){
		weigth[copy.x][copy.y] = weigth[pos.x][pos.y] + table[copy.x][copy.y];
	}

}

bool done(bool visited[SIZE][SIZE]){
	
	for (size_t i = 0; i < SIZE; ++i){
		for (size_t j = 0; j < SIZE; ++j){
			if (!visited[i][j]) return false;
		}
	}
	return true;
}

unsigned int dijkstra(){
	
	bool visited[SIZE][SIZE];
	unsigned long count = 0;
	for (size_t i = 0; i < SIZE; ++i){
		for (size_t j = 0; j < SIZE; ++j) visited[i][j] = false;
	}
	while(!done(visited)){
		
		pos_t pos = findPos(visited);	
		pos_t copy = pos;

		for( int i = -1; i <= 2; i += 2){
			
			copy.x = pos.x + i;
			copy.y = pos.y;
			if(allowedPos(copy) && !visited[copy.x][copy.y]){
				updateVal(pos, copy);
			}
			copy.x = pos.x;
			copy.y = pos.y + i;
			if(allowedPos(copy) && !visited[copy.x][copy.y]){
				updateVal(pos, copy);
			}
			std::cout << count << " " << pos.x << " x " << pos.y << " y\n" ;
			std::cout << visited[pos.x][pos.y] << "\n";
			visited[pos.x][pos.y] = true;
		}
		
		count++;
	}
	std::cout << weigth[SIZE-1][SIZE-1] << "\n";
	return weigth[SIZE -1][SIZE - 1];
}

//FIRST PROBLEM HERE
#ifdef FIRST
std::string run::solve(std::ifstream* file){
		

		std::string input;
		size_t count = 0;
		while(*file >> input){
			
			for (size_t i = 0; i < input.size(); ++i){
				table[count][i] = input[i] - 48;
				weigth[count][i] = UINT_MAX;
			}
			count++;
		}
		weigth[0][0] = 0;


		return std::to_string(dijkstra());
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND
std::string run::solve(std::ifstream* file){
	
	std::string input;
	size_t count = 0;
	while(*file >> input){
	
		for (size_t i = 0; i < input.size(); ++i){
			unsigned value = input[i] - 48;
			for (size_t j = 0; j < 5; ++j){
				
				unsigned int temp = (value + j)%10;
				if (temp < value) ++temp;
				table[count + (SIZE/5)*j][i] = temp;
				weigth[count + (SIZE/5)*j][i] = UINT_MAX;

				for (size_t k = 1; k < 5; ++k){
					value = table[count + (SIZE/5)*j][i + (SIZE/5)*(k - 1)];
					temp = (value + 1)%10;
					if (temp < value) temp++;
					
					table[count + (SIZE/5)*j][i + (SIZE/5)*k] = temp;
					weigth[count + (SIZE/5)*j][i + (SIZE/5)*k] = UINT_MAX;
				}
			}
		}
		count++;
	}
	
	for (int i = 0; i < SIZE; ++i){
		for(int j = 0; j < SIZE; ++j){
			std::cout << table[i][j];
		}
		std::cout << "\n";
	}

	weigth[0][0] = 0;

	return std::to_string(dijkstra());
}


#endif







