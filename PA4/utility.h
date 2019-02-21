#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int hash_string_to_int(string s) {
	if(s.size() > 2)
		s.erase(0, 1);
	istringstream instr(s);
	int n;
	instr >> n;
	return n;
}

int string_to_int(string s) {
	istringstream instr(s);
	int n;
	instr >> n;
	return n;
}