#include "Phone.h"

Phone::Phone() {
	cout << "Phone构造函数" << endl;
}

Phone::Phone(string n) {
	m_name = n;
	cout << "Phone有参构造函数" << endl;
}

//Phone::~Phone() {
//	cout << "Game析构函数" << endl;
//}

