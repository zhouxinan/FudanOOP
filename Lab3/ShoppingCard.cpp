#include "Supermarket.h"

ShoppingCard::ShoppingCard(int id, double balance) {
	ShoppingCard::id = id;
	ShoppingCard::balance = balance;
}

int ShoppingCard::getID() {
	return id;
}

double ShoppingCard::getBalance() {
	return balance;
}

void ShoppingCard::pay(double bill) {
	balance -= bill;
}