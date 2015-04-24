#include "FamilyMart.h"
#include <string>
#include <iostream>
using namespace std;

Commodity::Commodity(string commodity_name, double commodity_price, int commodity_life, string commodity_product_date) {
	name = commodity_name;
	price = commodity_price;
	life = commodity_life;
	product_date = commodity_product_date;
}

Commodity::~Commodity() {
	cout << name << " dropped" << endl;
}
