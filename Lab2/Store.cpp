#include "FamilyMart.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

extern vector<string> calendar;

Store::Store(string productListFilename, string sellListFilename) {
	loadProductList(productListFilename);
	loadSellList(sellListFilename);
	revenue = 0;
}

double Store::getRevenue() {
	return revenue;
}

void Store::sell(int calendarIndex) {
	double todayRevenue = 0;
	for (int i = 0; i < sellList.size(); i++) {
		string commodity_name;
		double discount = 1; // no discount as default
		istringstream iss(sellList[i]);
		iss >> commodity_name;
		iss >> discount;
		int oldestProductIndex = -1;
		for (int j = 0; j < onShelfCommodity.size(); j++) {
			if (onShelfCommodity[j].getName() == commodity_name) {
				if (oldestProductIndex >= 0) {
					if (onShelfCommodity[oldestProductIndex].getDropDateIndex() > onShelfCommodity[j].getDropDateIndex()) {
						oldestProductIndex = j;
					}
				} else {
					oldestProductIndex = j;
				}
			}
		}
		if (oldestProductIndex >= 0) {
			todayRevenue += onShelfCommodity[oldestProductIndex].getPrice() * discount;
			onShelfCommodity.erase(onShelfCommodity.begin() + oldestProductIndex);
		}
	}
	revenue += todayRevenue;
	cout << calendar[calendarIndex] << " Today revenue: " << todayRevenue << " Total revenue: " << revenue << endl;
}

void Store::product(int calendarIndex) {
	for (int j = 0; j < commodityList.size(); j++) {
		if (calendar[calendarIndex] == commodityList[j].getProductDate()) {
			onShelfCommodity.push_back(commodityList[j]);
			commodityList.erase(commodityList.begin() + j);
			j--;
		}
	}
}

void Store::dropProduct(int calendarIndex) {
	for (int j = 0; j < onShelfCommodity.size(); j++) {
		if (calendarIndex == onShelfCommodity[j].getDropDateIndex()) {
			onShelfCommodity[j].dropMessage = onShelfCommodity[j].getName() + " dropped";
			onShelfCommodity.erase(onShelfCommodity.begin() + j);
			j--;
		}
	}
}

void Store::loadProductList(string productListFilename) {
	ifstream productListFile(productListFilename);
	if (!productListFile.is_open()) {
        	cout << "Open " << productListFilename << " error. Maybe it does not exist.";
		exit(0);
	}
	string s;
	getline(productListFile, s);
	string commodity_name;
	double commodity_price;
	int commodity_life;
	string commodity_product_date;
	while (getline(productListFile, s)) {
		istringstream iss(s);
		iss >> commodity_name;
		iss >> commodity_price;
		iss >> commodity_life;
		iss >> commodity_product_date;
		Commodity newCommodity(commodity_name, commodity_price, commodity_life, commodity_product_date);
		commodityList.push_back(newCommodity);
	}
	productListFile.close();
}

void Store::loadSellList(string sellListFilename) {
	ifstream sellListFile(sellListFilename);
	if (!sellListFile.is_open()) {
        	cout << "Open " << sellListFilename << " error. Maybe it does not exist.";
		exit(0);
	}
	string sellRequest;
	getline(sellListFile, sellRequest);
	while (getline(sellListFile, sellRequest)) {
		sellList.push_back(sellRequest);
	}
	sellListFile.close();
}

void Store::startOperate() {
	for (int i = 0; i < calendar.size(); i++) {
		if (commodityList.size() == 0) {
			break;
		}
		product(i);
		sell(i);
		dropProduct(i);
	}
	cout << "Store closed!" << endl;
	
}

void Store::printProductList() {
	for (int i = 0; i < commodityList.size(); i++) {
		cout << commodityList[i].getName() << endl;
	}
}


