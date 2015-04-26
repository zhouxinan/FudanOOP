#include "FamilyMart.h"
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
		istringstream iss(sellList[i]);
		string commodity_name;
		iss >> commodity_name;
		if (sellList[i].find(".") != string::npos) {
			double discount;
			iss >> discount;
			todayRevenue += sellCommodityWithDiscount(commodity_name, discount);
		} else {
			todayRevenue += sellCommodityWithDiscount(commodity_name);
		}
	}
	revenue += todayRevenue;
	cout << calendar[calendarIndex] << " Today revenue: " << todayRevenue << " Total revenue: " << revenue << endl;
}

double Store::sellCommodityWithDiscount(string commodity_name, double discount) {
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
		double productRevenue = onShelfCommodity[oldestProductIndex].getPrice() * discount;
		onShelfCommodity.erase(onShelfCommodity.begin() + oldestProductIndex);
		return productRevenue;
	}
	return 0;	
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
			Commodity toBeDroppedCommodity = onShelfCommodity[j];
			toBeDroppedCommodity.setDropMessage();
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
		if (commodityList.size() == 0 && onShelfCommodity.size() == 0) {
			break;
		}
		product(i);
		sell(i);
		dropProduct(i);
	}
	cout << "Store closed!" << endl;
}
