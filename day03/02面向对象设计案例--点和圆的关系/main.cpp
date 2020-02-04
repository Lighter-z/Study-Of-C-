#include <iostream>
#include "Point.h"
#include "circle.h"
using namespace std;





void isInCircle(Circle &c, Point &p) {
	int distance = (c.getCenter().getPointX() - p.getPointX()) * (c.getCenter().getPointX() - p.getPointX()) + (c.getCenter().getPointY() - p.getPointY()) * (c.getCenter().getPointY() - p.getPointY());
	int r_distance = c.getR() * c.getR();
	if (distance == r_distance) {
		cout << "在园上" << endl;
	}
	else if (distance < r_distance) {
		cout << "在园内" << endl;
	}
	else if (distance > r_distance) {
		cout << "在园外" << endl;
	}
}

void test01() {
	Point p;
	p.setPointX(10);
	p.setPointY(10);

	Circle c;
	Point circle;
	circle.setPointX(10);
	circle.setPointY(0);
	c.setCenter(circle);
	c.setR(10);

	isInCircle(c,p);
}

int main() {
	test01();
	return 0;
}
