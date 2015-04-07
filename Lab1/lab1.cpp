#include <iostream>
#include <fstream>
#include "dict.h"

using namespace std;

/**
 * add a word to dictionary
 */
void addWord(Dict &d, const string &key, const string &value){
	word w = {key, value};
	if (!d.add(w))
		cout << "Add failed.\n";
	d.printDict();
}

void searchWord(Dict &d, const string &description, const string &key){
	cout << description  <<  d.search(key) << endl;
	d.printDict();
}

void removeWord(Dict &d, const string &key){
	d.remove(key);
	d.printDict();
}

void updateWord(Dict &d, const word &w){
	d.update(w);
	d.printDict();
}

int main(int argc, char const *argv[])
{
	Dict d;

	/*******************
	 * Add some words
	 *******************/
	addWord(d, "oop", "object-oriented programming");
	addWord(d, "ics", "introduction to computer system");
	addWord(d, "ds", "data structure");
	addWord(d, "cse", "computer system engineering");

	searchWord(d, "oop is ", "oop");
	searchWord(d, "cse is ", "cse");

	/********************
	 * Delete some words
	 ********************/
	removeWord(d, "oop");

	/*******************
	 * update some words
	 *******************/
	word w = {"cse", "computer science English"};
	updateWord(d, w);

	return 0;
}