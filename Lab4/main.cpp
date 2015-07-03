#include "lab4.h"

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		cout << "Usage: lab4 [input_filename] [output_filename]" << endl;
		return 0;
	}
	Calculator calculator(argv[1], argv[2]);
	calculator.startCalculate();
	return 0;
}