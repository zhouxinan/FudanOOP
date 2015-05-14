#include "Supermarket.h"

Commodity::Commodity(int id, string name, double price) {
	Commodity::id = id;
	Commodity::name = name;
	Commodity::price = price;
}

int Commodity::getID() {
	return id;
}

double Commodity::getPrice() {
	return price;
}