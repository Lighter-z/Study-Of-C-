#pragma once

#pragma once

#include <iostream>
#include <string>

using namespace std;
template<class T1, class T2>

class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson();

	T1 m_Name;
	T2 m_Age;
};

//#include "Person.h"


template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Age = age;
	this->m_Name = name;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "Ãû×Ö£º" << this->m_Name << "ÄêÁä£º" << this->m_Age << endl;
}


