#include "Supermarket.h"

Cashier::Cashier(string commodity_filename, string vip_filename, string shopping_card_filename, string purchase_filename) {
	loadCommodityList(commodity_filename);
	loadVIPList(vip_filename);
	loadShoppingCardList(shopping_card_filename);
	Cashier::purchase_filename = purchase_filename;
}

void Cashier::loadCommodityList(string commodity_filename) {
	ifstream commodityFile(commodity_filename);
	if (!commodityFile.is_open()) {
        cout << "Open " << commodity_filename << " error. Maybe it does not exist.";
		exit(0);
	}
	string inputLine;
	int id;
	string name;
	double price;
	while (getline(commodityFile, inputLine)) {
		istringstream iss(inputLine);
		iss >> id;
		iss >> name;
		iss >> price;
		Commodity newCommodity(id, name, price);
		commodityList.push_back(newCommodity);
	}
	commodityFile.close();
}

void Cashier::loadVIPList(string vip_filename) {
	ifstream vipFile(vip_filename);
	if (!vipFile.is_open()) {
        cout << "Open " << vip_filename << " error. Maybe it does not exist.";
		exit(0);
	}
	string inputLine;
	int id;
	string name;
	string gender;
	string telephone;
	int level;
	double point;
	while (getline(vipFile, inputLine)) {
		istringstream iss(inputLine);
		iss >> id;
		iss >> name;
		iss >> gender;
		iss >> telephone;
		iss >> level;
		iss >> point;
		VIP newVIP(id, name, gender, telephone, level, point);
		VIPList.push_back(newVIP);
	}
	vipFile.close();
}

void Cashier::loadShoppingCardList(string shopping_card_filename) {
	ifstream shoppingCardFile(shopping_card_filename);
	if (!shoppingCardFile.is_open()) {
        cout << "Open " << shopping_card_filename << " error. Maybe it does not exist.";
		exit(0);
	}
	string inputLine;
	int id;
	double balance;
	while (getline(shoppingCardFile, inputLine)) {
		istringstream iss(inputLine);
		iss >> id;
		iss >> balance;
		ShoppingCard newShoppingCard(id, balance);
		shoppingCardList.push_back(newShoppingCard);
	}
	shoppingCardFile.close();
}