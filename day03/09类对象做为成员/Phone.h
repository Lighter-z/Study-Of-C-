#pragma once
#include <iostream>
#include <string>

using namespace std;

class Phone
{
public:
	string m_name;
	Phone();
	Phone(string n);
	~Phone() {
		cout << "Phone��������" << endl;
	}
};

