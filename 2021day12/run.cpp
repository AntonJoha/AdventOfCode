#include "run.h"
#include <map>
#include <vector>
#include <iostream>
#include <list>

typedef struct node_t{

	std::string name;
	std::vector<std::string> connections;
	bool small;

} node_t;

std::map<const std::string, node_t*> nodes; 


void makeNode(std::string name){

	node_t * toAdd = (node_t*) malloc(sizeof(node_t));
	toAdd->name = name;
	toAdd->small = std::islower(name[0]);
	nodes[name] = toAdd;
}


void addRelationship(std::string left, std::string right){
	
	if (nodes[left] == NULL) makeNode(left);
	if (nodes[right] == NULL) makeNode(right);
	
	nodes[left]->connections.push_back(right);
	nodes[right]->connections.push_back(left);

}



//FIRST PROBLEM HERE
#ifdef FIRST


unsigned int traverse(std::string nodeName, std::list<std::string> *history){
	
	if (nodeName == "end") return 1;

	node_t* node = nodes[nodeName];
	//Check if it's been visited before
	if (node->small){
		for (auto i = history->cbegin(); i != history->cend(); ++i){
			if (*i == nodeName) return 0;
		}
	}
	
	history->push_front(nodeName);

	std::vector<std::string> connections = node->connections;
	
	unsigned int count = 0;

	for (std::string s : connections){
		
		count += traverse(s, history);	
	}
		
	history->pop_front();

	return count;
}

std::string run::solve(std::ifstream* file){

	std::string right;
	std::string left;

	while (*file >> left){
		
		*file >> right;
		addRelationship(left, right);

	}

	
	std::list<std::string>* history = new std::list<std::string>();
	

	return std::to_string(traverse("start", history));
}


#endif


//SECOND PROBLEM HERE
#ifdef SECOND


unsigned int traverse(std::string nodeName, std::list<std::string> *history, bool twice){
	
	if (nodeName == "end") return 1;

	node_t* node = nodes[nodeName];
	//Check if it's been visited before
	if (node->small){
		for (auto i = history->cbegin(); i != history->cend(); ++i){
			if (*i == nodeName && twice) return 0;
			if (*i == nodeName && !twice) twice = true;
		}
	}
	
	history->push_front(nodeName);

	std::vector<std::string> connections = node->connections;
	
	unsigned int count = 0;

	for (std::string s : connections){
		if (s != "start")	
		count += traverse(s, history, twice);	
	}
		
	history->pop_front();

	return count;
}

std::string run::solve(std::ifstream* file){

	std::string right;
	std::string left;

	while (*file >> left){
		
		*file >> right;
		addRelationship(left, right);

	}

	
	std::list<std::string>* history = new std::list<std::string>();
	

	return std::to_string(traverse("start", history, false));
}

#endif







