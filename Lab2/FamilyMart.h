#include <string>
#include <vector>
using namespace std;

class Commodity {
	string name;
	double price;
	int life;
	string productDate;
	int dropDateIndex;
public:
	Commodity(string commodity_name, double commodity_price, int commodity_life, string commodity_productDate);
	~Commodity();
	string dropMessage;
	string getName();
	double getPrice();
	int getLife();
	string getProductDate();
	int getDropDateIndex();
};

class Store {
	double revenue;
	vector<Commodity> commodityList;
	vector<Commodity> onShelfCommodity;
	vector<string> sellList;
public:
	Store(string productListFilename, string sellListFilename);
	double getRevenue();
	void sell(int calendarIndex);
	void product(int calendarIndex);
	void dropProduct(int calendarIndex);
	void loadProductList(string productListFilename);
	void loadSellList(string sellListFilename);
	void startOperate();
	void printProductList();
};
