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
        cout << "Open " << commodity_filename << " error. Maybe it does not exist." << endl;
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
        cout << "Open " << vip_filename << " error. Maybe it does not exist." << endl;
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
        cout << "Open " << shopping_card_filename << " error. Maybe it does not exist." << endl;
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

void Cashier::startOperate() {
	ifstream purchaseFile(purchase_filename);
	if (!purchaseFile.is_open()) {
        cout << "Open " << purchase_filename << " error. Maybe it does not exist." << endl;
		exit(0);
	}
	string inputLine;
	while (getline(purchaseFile, inputLine)) {
		int VIPID;
		int shoppingCardID;
		int commodityLineCount;
		int currentVIPLevel = 0;
		int currentVIPIndex = -1;
		double originalBill = 0;
		double discountedBill = 0;
		double point = 0;
		int commodityID;
		int commodityCount;
		double VIPPoint = 0;
		istringstream(inputLine) >> VIPID;
		getline(purchaseFile, inputLine);
		istringstream(inputLine) >> commodityLineCount;
		if (VIPID != -1) {
			for (int i = 0; i < VIPList.size(); ++i) {
				if (VIPList[i].getID() == VIPID) {
					currentVIPLevel = VIPList[i].getLevel();
					currentVIPIndex = i;
					break;
				}
			}
		}
		for (int i = 0; i < commodityLineCount; ++i) {
			getline(purchaseFile, inputLine);
			istringstream iss(inputLine);
			iss >> commodityID;
			iss >> commodityCount;
			for (int i = 0; i < commodityList.size(); ++i) {
				if (commodityList[i].getID() == commodityID) {
					double commodityPrice = commodityList[i].getPrice();
					double originalTotal = commodityPrice * commodityCount;
					if (currentVIPLevel == 3) {
						if (commodityPrice > 20) {
							originalBill += originalTotal * 0.9;
						} else if (commodityPrice > 10) {
							originalBill += originalTotal * 0.95;
						} else {
							originalBill += originalTotal;
						}
					} else {
						originalBill += originalTotal;
					}
					break;
				}
			}
		}
		double discountedBillCopy;
		switch (currentVIPLevel) {
			case 1:
				if (originalBill > 5000) {
					discountedBill += (originalBill - 5000) * 0.9;
					originalBill = 5000;
				}
				if (originalBill > 2000) {
					discountedBill += (originalBill - 2000) * 0.95;
					originalBill = 2000;
				}
				discountedBill += originalBill;
				point = discountedBill * 0.5;
				break;
			case 2:
				if (originalBill > 2000) {
					discountedBill += (originalBill - 2000) * 0.85;
					originalBill = 2000;
				}
				if (originalBill > 1000) {
					discountedBill += (originalBill - 1000) * 0.9;
					originalBill = 1000;
				}
				discountedBill += originalBill * 0.95;
				discountedBillCopy = discountedBill;
				if (discountedBillCopy > 5000) {
					point += (discountedBillCopy - 5000) * 1.8;
					discountedBillCopy = 5000;
				}
				if (discountedBillCopy > 2000) {
					point += (discountedBillCopy - 2000) * 1.5;
					discountedBillCopy = 2000;
				}
				point += discountedBillCopy * 1.2;
				break;
			case 3:
				discountedBill = originalBill;
				if (discountedBill > 5000) {
					point += (discountedBill - 5000) * 2;
					discountedBill = 5000;
				}
				if (discountedBill > 1000) {
					point += (discountedBill - 1000) * 1.8;
					discountedBill = 1000;
				}
				point += discountedBill * 1.5;
			default:
				discountedBill = originalBill;
		}
		if (currentVIPIndex != -1) {
			VIPList[currentVIPIndex].addPoint(point);
			VIPPoint = VIPList[currentVIPIndex].getPoint();
		}
		getline(purchaseFile, inputLine);
		istringstream(inputLine) >> shoppingCardID;
		if (!checkOut(shoppingCardID, discountedBill)) {
			cout << "shoppingCardID: " << shoppingCardID << " does not exist!" << endl;
		}
		printf("\e[1;31m%d\t\e[1;32m%f\t\e[1;33m%f\t\e[1;34m%d\e[0m\n", VIPID, discountedBill, VIPPoint, shoppingCardID);
	}
	purchaseFile.close();
}

bool Cashier::checkOut(int shoppingCardID, double bill) {
	if (shoppingCardID != -1) {
		for (int i = 0; i < shoppingCardList.size(); ++i) {
			if (shoppingCardList[i].getID() == shoppingCardID) {
				shoppingCardList[i].pay(bill);
				return true;
			}
		}
		return false;
	}
	return true;
}