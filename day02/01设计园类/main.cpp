#include <iostream>

using namespace std;

const double pi = 3.14;

//1.设计一个类 求圆的周长
struct Circle {
public:
	int circle_r;
	double CacluateZC() {
		return 2 * pi * circle_r;
	}
	void SetR(int r) {
		circle_r = r;
	}
};

void test01() {
	Circle c1;
	//c1.circle_r = 10;
	c1.SetR(10);
	cout << c1.CacluateZC() << endl;
}

int main() {
	test01();
	return 0;
}
