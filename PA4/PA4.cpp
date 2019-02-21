#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "utility.h"
#include "HashMap.h"

using namespace std;

int main()
{
	
	string method = "";
	string input = "";
	string Msize = "";
	string Rsize = "";
	string cOne = "";
	string cTwo = "";
	while (method != "x") {
		cout << endl << "Choose which Method : ";
		cout << endl << "1. Chaining";
		cout << endl << "2. Linear Probing";
		cout << endl << "3. Quadratic Probing";
		cout << endl << "4. Double Hashing";
		cout << endl << "x. Exit the Program" << endl;
		getline(cin, method);

		if (method == "x") {
			break;
		}
			cout << "What will M the size of the hash table be: " << endl;
			getline(cin, Msize);
		if (method == "3") {
			cout << "What will be the value of c1: " << endl;
			getline(cin, cOne);
			cout << "What will be the value of c2: " << endl;
			getline(cin, cTwo);
		}
		if (method == "4") {
			cout << "What will R the size of the second hash be: " << endl;
			getline(cin, Rsize);
		}
		HashMap *htable = new HashMap(string_to_int(Msize), string_to_int(Rsize));
		cout << endl << "Enter Insertion File Name:" << endl;
		getline(cin, input);

		ifstream insertion_file;
		insertion_file.open(input.c_str());
		if (!insertion_file.fail()) {
			while (!insertion_file.fail() && !insertion_file.eof()) {
				getline(insertion_file, input);
				if (input.size() == 0) {
					continue;
				}
				char firstLetter = input.at(0);
				try {
					if (firstLetter == 'i') {
						if (method == "1") {
							htable->InsertChain(hash_string_to_int(input));
						}
						else if (method == "2") {
							htable->InsertLinear(hash_string_to_int(input));
						}
						else if (method == "3") {
							htable->InsertQuadratic(hash_string_to_int(input), string_to_int(cOne), string_to_int(cTwo));
						}
						else if (method == "4") {
							htable->InsertDouble(hash_string_to_int(input));
						}
					}
					else if (firstLetter == 'r') {
						if (method == "1") {
							htable->RemoveChain(hash_string_to_int(input));
						}
						else if (method == "2") {
							htable->RemoveLinear(hash_string_to_int(input));
						}
						else if (method == "3") {
							htable->RemoveQuadratic(hash_string_to_int(input), string_to_int(cOne), string_to_int(cTwo));
						}
						else if (method == "4") {
							htable->RemoveDouble(hash_string_to_int(input));
						}
					}
				}
				catch (const exception& e) {
					cout << e.what();
				}
			}
			htable->DisplayHash();
		}
		else
			cout << "Invalid file name." << endl;

	}
	return -1;
}

