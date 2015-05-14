#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Commodity {
	int id;
	string name;
	double price;
public:
	Commodity(int id, string name, double price);
	int getID();
	double getPrice();
};

class VIP {
	int id;
	string name;
	string gender;
	string telephone;
	int level;
	double point;
public:
	VIP(int id, string name, string gender, string telephone, int level, double point);
};

class ShoppingCard {
	int id;
	double balance;
public:
	ShoppingCard(int id, double balance);
	int getID();
	double getBalance();
};

class Cashier {
	vector<VIP> VIPList;
	vector<ShoppingCard> shoppingCardList;
	vector<Commodity> commodityList;
	string purchase_filename;
// 	double revenue;
	// string bill
	// vector<Commodity> commodityList;
// 	vector<Commodity> onShelfCommodity;
// 	vector<string> sellList;

public:
	Cashier(string commodity_filename, string vip_filename, string shopping_card_filename, string purchase_filename);
	void loadCommodityList(string commodity_filename);
	void loadVIPList(string vip_filename);
	void loadShoppingCardList(string shopping_card_filename);
// 	double getRevenue();
// 	void sell(int calendarIndex);
// 	void product(int calendarIndex);
// 	void dropProduct(int calendarIndex);
	// void loadProductList(string productListFilename);
// 	void loadSellList(string sellListFilename);
	// void startOperate();
// 	double sellCommodityWithDiscount(string commodity_name, double discount = 1.0);
};