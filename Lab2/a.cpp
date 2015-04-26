#include "FamilyMart.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
void loadCalendar(string calendarFilename);
void printList();
vector<string> calendar;

vector<Commodity> v;
int main(int argc, char const *argv[])
{
	loadCalendar("date.txt");
	Commodity a("milk1", 3.1, 4, "2015/1/1");
	// if (calendar[0].find("/") != string::npos) {
	// 	cout << "find!" << endl;
	// }
	//cout << calendar[0].find(".") << endl;
	//Commodity b("milk2", 3.2, 4, "2015/1/1");
	//Commodity c("milk3", 3.3, 4, "2015/1/1");
	//Commodity d("milk4", 3.4, 4, "2015/1/1");
	v.push_back(a);
	//a.dropMessage = "milk'1";
	//v.erase(v.begin() + 0);
	//a.
	//v.push_back(b);
	//v.push_back(c);
	//v.push_back(d);
	//v.erase(v.begin() + 0); //erase will drop it.
	//printList();
	return 0;
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

void printList() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].getName() << endl;
	}
}