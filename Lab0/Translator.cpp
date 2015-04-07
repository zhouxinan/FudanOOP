#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	string s;
	int index;
	ifstream dict("dict.txt");
	ifstream cipher("result.txt");
	if (!dict.is_open()) {
        	cout << "Open dict.txt error. Maybe it does not exist.";
		exit(0);
	}
	if (!cipher.is_open()) {
        	cout << "Open result.txt error. Maybe it does not exist.";
		exit(0);
	}
	ofstream answer("answer.txt");
	getline(dict, s);
	while (cipher >> index) {
		cout << s[index];
		answer << s[index];
	}
	dict.close();
	cipher.close();
	answer.close();
}
