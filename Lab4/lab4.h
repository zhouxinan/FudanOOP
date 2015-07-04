#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

const int BIGNUM_INPUT_MAXLEN = 100;
// A Bignum can have at most 300 digits according to the lab requirement, considering the cube of an extremely big Bignum input.
const int BIGNUM_MAXLEN = 3 * BIGNUM_INPUT_MAXLEN;

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
	void resetLength();
	string toString();
	friend istream& operator>>(istream& is, Bignum& bignum);
	friend ostream& operator<<(ostream& os, Bignum& bignum);
	friend Bignum operator+(const Bignum& a, const Bignum& b);
	friend Bignum operator-(const Bignum& a, const Bignum& b);
	friend Bignum operator*(const Bignum& a, const Bignum& b);
	friend Bignum operator/(const Bignum& a, const Bignum& b);
	friend int compare(const Bignum& a, const Bignum& b);
};

bool isTooLong(const string& str);

Bignum operator+(const Bignum& a, const Bignum& b);
Bignum operator-(const Bignum& a, const Bignum& b);
Bignum operator*(const Bignum& a, const Bignum& b);
Bignum operator/(const Bignum& a, const Bignum& b);