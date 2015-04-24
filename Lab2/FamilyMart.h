#include <string>
using namespace std;

class Commodity {
	string name;
	double price;
	int life;
	string product_date;
public:
	Commodity(string commodity_name, double commodity_price, int commodity_life, string commodity_product_date);
	~Commodity();
};
