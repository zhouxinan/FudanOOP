#include "dict.h"
#include <iostream>
using namespace std;

bool Dict::add(const word &w){
	// Your code here
	return false;
}

string Dict::search(const string &key){
	// Your code here
	return "";
}

string Dict::remove(const string &key){
	// Your code here
	return "";
}

string Dict::update(const word &w){
	// Your code here
	return "";
}

void Dict::printDict(){
	cout << "Now the dict is:\n";
	for (int i = 0; i < size; ++i)
		cout << dict[i].key << ": " << dict[i].value << endl;
}