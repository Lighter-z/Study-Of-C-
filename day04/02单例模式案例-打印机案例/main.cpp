#include <iostream>
#include <string>

using namespace std;

class Printer {
private:
	Printer() {
		count = 0;
	}
	Printer(const Printer & p) {}
	static Printer * singlePrinter;
	int count;
public:
	static Printer *getInstance() {
		return singlePrinter;
	}
	void printerTest(string text) {
		count++;
		cout << text << endl;
	}
	void useNumber() {
		cout << "调用次数" << count << endl;
	}
};

Printer * Printer::singlePrinter = new Printer;

void test0() {
	Printer *p1 = Printer::getInstance();
	Printer *p2 = Printer::getInstance();
	p1->printerTest("1");
	p2->printerTest("2");
	p1->useNumber();
}

int main() {
	test0();
	return 0;
}
