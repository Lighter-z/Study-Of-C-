#pragma once
#include <iostream>
#include "point.h"
using namespace std;

class Circle {
private:
	int circle_r;
	Point circle_p;
public:
	void setR(int r);
	//{
	//	circle_r = r;
	//}
	int getR();
	//{
	//	return circle_r;
	//}

	void setCenter(Point p);
	//{
	//	circle_p = p;
	//}
	Point getCenter();
	//{
	//	return circle_p;
	//}
};

