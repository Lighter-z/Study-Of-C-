#include <iostream>
using namespace std;

class MyInterger {
	friend ostream & operator<<(ostream &c, MyInterger &m);
	//friend ostream & operator<<(ostream &cout, MyInterger m);
public:
	MyInterger() {
		m_Num = 0;
	}
	MyInterger & operator++() {
		this->m_Num++;
		return *this;
	}

	//∫Û÷√++
	MyInterger operator++(int) {
		MyInterger temp = *this;
		m_Num++;
		return temp;
	}
	int m_Num;
};

//ostream & operator<<(ostream &cout, MyInterger m) {
//	cout << m.m_Num;
//	return cout;
//}
ostream & operator<<(ostream &cout, MyInterger &m) {
	cout << m.m_Num;
	return cout;
}

void test01() {
	MyInterger myInt;
	/*++myInt;
	myInt++;*/

	cout << ++myInt << endl;
	//cout << myInt++ << endl;
}

int main() {
	test01();
	return 0;
}
