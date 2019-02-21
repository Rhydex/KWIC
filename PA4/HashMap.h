#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "HashNode.h"
#include "DeletedNode.h"

using namespace std;

class HashMap {

private:
	HashNode **table;

public:
	HashMap(int);
	HashMap(int, int);
	~HashMap();
	int Msize;
	int Rsize;
	int totalProbe = 0;
	int elements = 0;
	int opCalled = 0;
	int maxProbe = 0;
	int HashFunc(int);
	int HashFunc2(int);
	void InsertChain(int);
	void InsertLinear(int);
	void InsertQuadratic(int, int, int);
	void InsertDouble(int);
	void RemoveChain(int);
	void RemoveLinear(int);
	void RemoveQuadratic(int, int, int);
	void RemoveDouble(int);
	void DisplayHash();
};

HashMap::HashMap(int Msize) {
	this->Msize = Msize;
	table = new HashNode*[Msize];
	for (int i = 0; i < Msize; i++) {
		table[i] = NULL;
	}
}

HashMap::HashMap(int Msize, int Rsize) {
	this->Msize = Msize;
	this->Rsize = Rsize;
	table = new HashNode*[Msize];
	for (int i = 0; i < Msize; i++) {
		table[i] = NULL;
	}
}

HashMap::~HashMap() {
	for (int i = 0; i < Msize; i++) {
		if (table[i] != NULL
				&& table[i] != DeletedNode::getNode()
			) {
			delete table[i];
		}
	}
	delete[] table;
}

int HashMap::HashFunc(int key) {
	return key % Msize;
}

int HashMap::HashFunc2(int key) {
	return Rsize - (key % Rsize);
}

void HashMap::InsertChain(int key) {
	opCalled++;
	int tempMax = 0;
	int hVal = HashFunc(key);
	HashNode* prev = NULL;
	HashNode* entry = table[hVal];
	while (entry != NULL)
	{
		if (entry->key == key) {
			tempMax++;
			totalProbe++;
			break;
		}
		prev = entry;
		entry = entry->next;
		totalProbe++;
		tempMax++;
	}
	if (entry == NULL)
	{
		totalProbe++;
		tempMax++;
		if (tempMax > maxProbe) {
			maxProbe = tempMax;
		}
		elements++;
		entry = new HashNode(key, hVal);
		if (prev == NULL)
		{
			table[hVal] = entry;
		}
		else
		{
			prev->next = entry;
		}
	}
	else
	{
		entry->value = hVal;
	}
}

void HashMap::InsertLinear(int key) {
	opCalled++;
	int tempMax = 0;
	int hVal = HashFunc(key);
	int position = -1;
	bool keepGoing = true;

	if (table[hVal] == NULL || table[hVal] == DeletedNode::getNode()) {
		totalProbe++;
		tempMax++;
		if (tempMax > maxProbe) {
			maxProbe = tempMax;
		}
		elements++;
		table[hVal] = new HashNode(key, hVal);
	}
	else if (table[hVal]->key == key) {
		return;
	}
	else {
		position = hVal + 1;
		position %= Msize;
		totalProbe++;
		tempMax++;
		while (keepGoing)
		{
			if (this->table[position] == NULL) {
				if (tempMax > maxProbe) {
					maxProbe = tempMax;
				}
				elements++;
				table[position] = new HashNode(key, position);
				keepGoing = false;
			}
			else if (this->table[position] == DeletedNode::getNode()) {
				if (tempMax > maxProbe) {
					maxProbe = tempMax;
				}
				elements++;
				table[position] = new HashNode(key, position);
				keepGoing = false;
			}
			else {
				if (this->table[position]->key == key) {
					if (tempMax > maxProbe) {
						maxProbe = tempMax;
					}
					keepGoing = false;
				}
				position++;
				totalProbe++;
				tempMax++;
				position %= Msize;
			}
		}
	}
}

void HashMap::InsertQuadratic(int key, int cOne, int cTwo) {
	opCalled++;
	int tempMax = 0;
	int hVal = HashFunc(key);
	int position = -1;
	int limiter = 100;
	int i = 1;

	if (this->table[hVal] == NULL 
			|| this->table[hVal] == DeletedNode::getNode()) {
		totalProbe++;
		tempMax++;
		if (tempMax > maxProbe) {
			maxProbe = tempMax;
		}
		elements++;
		table[hVal] = new HashNode(key, hVal);
	}
	else if (this->table[hVal]->key == key) {
		totalProbe++;
		tempMax++;
		if (tempMax > maxProbe) {
			maxProbe = tempMax;
		}
		return;
	}
	else {
		while (i <= limiter) {
			position = hVal + (cOne*i + cTwo * i*i);
			position %= Msize;
			tempMax++;
			totalProbe++;
			if (this->table[position] == NULL
					|| this->table[position] == DeletedNode::getNode()) {
				if (tempMax > maxProbe) {
					maxProbe = tempMax;
				}
				elements++;
				table[position] = new HashNode(key, position);
				break;
			}
			i++;
		}
	}
}

void HashMap::InsertDouble(int key) {
	opCalled++;
	int tempMax = 0;
	int jumpSize = HashFunc2(key);
	int hVal = HashFunc(key);
	int position = -1;
	bool keepGoing = true;

	if (table[hVal] == NULL || table[hVal] == DeletedNode::getNode()) {
		totalProbe++;
		tempMax++;
		if (tempMax > maxProbe) {
			maxProbe = tempMax;
		}
		elements++;
		table[hVal] = new HashNode(key, hVal);
	}
	else if (table[hVal]->key == key) {
		totalProbe++;
		tempMax++;
		if (tempMax > maxProbe) {
			maxProbe = tempMax;
		}
		return;
	}
	else {
		position = hVal + jumpSize;
		position %= Msize;
		while (keepGoing)
		{
			totalProbe++;
			tempMax++;
			if (this->table[position] != NULL) {
				if (this->table[position]->key == key) {
					keepGoing = false;
				}
			}
			if (this->table[position] == NULL) {
				if (tempMax > maxProbe) {
					maxProbe = tempMax;
				}
				elements++;
				table[position] = new HashNode(key, position);
				keepGoing = false;
			}
			else if (this->table[position] == DeletedNode::getNode()) {
				if (tempMax > maxProbe) {
					maxProbe = tempMax;
				}
				elements++;
				table[position] = new HashNode(key, position);
				keepGoing = false;
			}
			else {
				position += jumpSize;
				position %= Msize;
			}
		}
	}
}

void HashMap::RemoveChain(int key) {
	opCalled++;
	int hVal = HashFunc(key);
	HashNode* entry = table[hVal];
	HashNode* prev = NULL;
	if (entry == NULL 
		|| entry == DeletedNode::getNode())
	{
		return;
	}
	while (entry->next != NULL)
	{
		totalProbe++;
		if (entry->key != key) {
			prev = entry;
			entry = entry->next;
		}
		else {
			break;
		}
	}
	if (prev != NULL)
	{
		prev->next = entry->next;
	}
	elements--;
	delete entry;
	table[hVal] = DeletedNode::getNode();
}

void HashMap::RemoveLinear(int key) {
	opCalled++;
	int hVal = HashFunc(key);
	int position = -1;
	while (hVal != position
		&& (table[hVal] == DeletedNode::getNode()
			|| table[hVal] != NULL
			&& table[hVal]->key != key
			)
		) 
	{
		if (position == -1) {
			position = hVal;
		}
		hVal = HashFunc(hVal + 1);
		totalProbe++;
	}
	if (hVal != position && table[hVal] != NULL) {
		elements--;
		delete table[hVal];
		table[hVal] = DeletedNode::getNode();
	}
}

void HashMap::RemoveQuadratic(int key, int cOne, int cTwo) {
	opCalled++;
	int hVal = HashFunc(key);
	int position = -1;
	int limiter = 100;
	int i = 1;
	int x = 0;

	if (this->table[hVal] == NULL
			|| this->table[hVal] == DeletedNode::getNode()) 
	{
		x++;
	} 
	else {
		if (this->table[hVal]->key == key) {
			totalProbe++;
			elements--;
			delete table[hVal];
			table[hVal] = DeletedNode::getNode();
		}
	}
	while (i <= limiter) {
		position = hVal + (cOne*i + cTwo * i*i);
		position %= Msize;
		totalProbe++;
		if (this->table[position] == DeletedNode::getNode()
			|| table[position] == NULL) {
			i++;
		}
		else {
			if (this->table[position]->key == key) {
				elements--;
				delete table[position];
				table[position] = DeletedNode::getNode();
				break;
			}
			i++;
		}
	}
}

void HashMap::RemoveDouble(int key) {
	opCalled++;
	int hVal = HashFunc(key);
	int jumpSize = HashFunc2(key);
	int position = -1;
	while (hVal != position
		&& (table[hVal] == DeletedNode::getNode()
			|| table[hVal] != NULL
			&& table[hVal]->key != key
			)
		)
	{
		totalProbe++;
		if (position == -1) {
			position = hVal;
		}
		hVal = HashFunc(hVal + jumpSize);
	}
	if (hVal != position && table[hVal] != NULL) {
		elements--;
		delete table[hVal];
		table[hVal] = DeletedNode::getNode();
	}
}

void HashMap::DisplayHash() {
	for (int i = 0; i < Msize; i++) {
		cout << i;
		if (table[i]) {
			HashNode* entry = table[i];
			while (entry != NULL)
			{
				if (table[i]->key != -1) {
					cout << " ---> " << entry->key;
				}
				entry = entry->next;
			}
		}
		cout << endl;
	}
	cout << "Number of probes: " << totalProbe << endl;
	cout << "Max number of probes: " << maxProbe << endl;
	cout << "Number of elements: " << elements << endl;
	cout << "Number of operations called: " << opCalled << endl;
	cout << "Average number of probes: " << (double)totalProbe / (double)opCalled << endl;
	cout << "Capacity of Table: " << Msize << endl;
	cout << "Load Factor is: " << (double)elements / (double)Msize << endl;
}