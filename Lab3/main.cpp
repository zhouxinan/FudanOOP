#include "Supermarket.h"

int main(int argc, char const *argv[]) {
	if (argc != 5) {
		cout << "Usage: lab3 [commodity_filename] [vip_filename] [shopping_card_filename] [purchase_filename]" << endl;
		return 0;
	}
	Cashier cashier(argv[1], argv[2], argv[3], argv[4]);
	cashier.startOperate();
	return 0;
}