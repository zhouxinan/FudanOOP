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
	int getLevel();
	int getID();
	void addPoint(double point);
	double getPoint();
};

class ShoppingCard {
	int id;
	double balance;
public:
	ShoppingCard(int id, double balance);
	int getID();
	double getBalance();
	void pay(double bill);
};

class Cashier {
	vector<VIP> VIPList;
	vector<ShoppingCard> shoppingCardList;
	vector<Commodity> commodityList;
	string purchase_filename;
public:
	Cashier(string commodity_filename, string vip_filename, string shopping_card_filename, string purchase_filename);
	void loadCommodityList(string commodity_filename);
	void loadVIPList(string vip_filename);
	void loadShoppingCardList(string shopping_card_filename);
	void startOperate();
	bool checkOut(int shoppingCardID, double bill);
};