#include "FamilyMart.h"
using namespace std;

vector<string> calendar;

void loadCalendar(string calendarFilename);

int main() {
	loadCalendar("date.txt");
	Store familyMart("purchase.txt", "sell.txt");
	familyMart.startOperate();
	cout << "Total revenue: " << familyMart.getRevenue() << endl;
}

void loadCalendar(string calendarFilename) {
	ifstream calendarFile(calendarFilename);
	if (!calendarFile.is_open()) {
        cout << "Open " << calendarFilename << " error. Maybe it does not exist.";
		exit(0);
	}
	string date;
	while (getline(calendarFile, date)) {
		calendar.push_back(date);
	}
	calendarFile.close();
}
