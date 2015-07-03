#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

const int BIGNUM_MAXLEN = 1000; // 1000 is a test value

class Calculator {
	vector<string> formulaList;
	string output_filename;
public:
	Calculator(string input_filename, string output_filename);
	void loadFormulaList(string input_filename);
	void startCalculate();
};

class Bignum {
	int length;
	int digit[BIGNUM_MAXLEN];
public:
	Bignum();
	Bignum(const string& str);
	void setNumber(const string& str);
	string toString();
};

bool isTooLong(const string& str);