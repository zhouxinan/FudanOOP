#include "dict.h"
#include <iostream>
#include <string>
using namespace std;

bool Dict::add(const word &w){
	bool replace_old_value = false;
	for (int i = 0; i < size; i++){
		if (dict[i].key == w.key){
			dict[i].value = w.value;
			replace_old_value = true;
			break;
		}
	}
	if (!replace_old_value){
		if (size >= 5000) return false;
		dict[size] = w;
		size++;
	}
	return true;
}

string Dict::search(const string &key){
	for (int i = 0; i < size; i++){
		if (dict[i].key == key)
			return dict[i].value;
	}
	return "";
}

string Dict::remove(const string &key){
	for (int i = 0; i < size; i++){
		if (dict[i].key == key){
			string value_of_key = dict[i].value;
			size--;
			for (int j = i; j < size; j++)
				dict[j] = dict[j+1];
			dict[size].key = "";
			dict[size].value = "";
			return value_of_key;
		}
	}
	return "";
}

string Dict::update(const word &w){
	for (int i = 0; i < size; i++){
		if (dict[i].key == w.key){
			string previous_value = dict[i].value;
			dict[i].value = w.value;
			return previous_value;
		}
	}	
	return "";
}

void Dict::printDict(){
	cout << "Now the dict is:\n";
	for (int i = 0; i < size; ++i)
		cout << dict[i].key << ": " << dict[i].value << endl;
}
