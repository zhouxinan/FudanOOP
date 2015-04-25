#include "FamilyMart.h"
#include <string>
#include <iostream>
using namespace std;

extern vector<string> calendar;

Commodity::Commodity(string commodity_name, double commodity_price, int commodity_life, string commodity_productDate) {
	name = commodity_name;
	price = commodity_price;
	life = commodity_life;
	productDate = commodity_productDate;
	dropDateIndex = getDropDateIndex();
}

Commodity::~Commodity() {
	if (dropMessage != "") {
		cout << dropMessage << endl;
		dropMessage = "";
	}
}

string Commodity::getName() {
	return name;
}

double Commodity::getPrice() {
	return price;
}

int Commodity::getLife() {
	return life;
}

string Commodity::getProductDate() {
	return productDate;
}

int Commodity::getDropDateIndex() {
	for (int i = 0; i < calendar.size(); i++) {
		if (calendar[i] == productDate) {
			return i + life - 1;
		}
	}
	return -1;
}
