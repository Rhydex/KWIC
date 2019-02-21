#ifndef HashNode_Header
#define HashNode_Header



#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class HashNode {
	
public:
	int key;
	int value;
	HashNode* next;
	HashNode(int, int);
};

HashNode::HashNode(int key, int value) {

	this->key = key;
	this->value = value;
	this->next = NULL;
};


#endif // !HashNode_Header