#include "Supermarket.h"

VIP::VIP(int id, string name, string gender, string telephone, int level, double point) {
	VIP::id = id;
	VIP::name = name;
	VIP::gender = gender;
	VIP::telephone = telephone;
	VIP::level = level;
	VIP::point = point;
}

int VIP::getLevel() {
	return level;
}

int VIP::getID() {
	return id;
}

void VIP::addPoint(double point) {
	VIP::point += point;
}

double VIP::getPoint() {
	return point;
}