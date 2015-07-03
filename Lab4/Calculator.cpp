#include "lab4.h"

Calculator::Calculator(string input_filename, string output_filename) {
	loadFormulaList(input_filename);
	Calculator::output_filename = output_filename;
}

void Calculator::loadFormulaList(string input_filename) {
	ifstream inputFile(input_filename);
	if (!inputFile.is_open()) {
		cout << "Open " << input_filename << " error. Maybe it does not exist." << endl;
		exit(0);
	}
	string inputLine;
	getline(inputFile, inputLine); // Skip the number of formulas.
	while (getline(inputFile, inputLine)) {
		formulaList.push_back(inputLine);
	}
	inputFile.close();
}

void Calculator::startCalculate() {
	ifstream outputFile(output_filename);
	if (!outputFile.is_open()) {
		cout << "Open " << output_filename << " error. Maybe it does not exist." << endl;
		exit(0);
	}
	for (int i = 0; i < formulaList.size(); ++i) {
		Bignum firstBignum, secondBignum;
		char op;
		istringstream iss(formulaList[i]);
		iss >> firstBignum;
		cout << firstBignum << endl;
		while (iss >> op) {
			iss >> secondBignum;
			cout << op << " " << secondBignum << endl;
		}
	}
	outputFile.close();
}