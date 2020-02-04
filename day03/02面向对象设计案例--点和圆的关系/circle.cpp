#include "circle.h"

void Circle::setR(int r) {
	circle_r = r;
}
int Circle::getR() {
	return circle_r;
}

void Circle::setCenter(Point p) {
	circle_p = p;
}
Point Circle::getCenter() {
	return circle_p;
}
