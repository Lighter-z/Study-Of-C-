#include <iostream>
#include "MyArray.h"
using namespace std;

void test01(){
	//������������
	MyArray * array = new MyArray(30);
	MyArray array2(*array);    //��������
	MyArray * array3 = new MyArray(*array);//��������
	MyArray array4 = *array;//��������

	//delete array;
	for (int i = 0; i < 10; i++) {
		array2.pushBack(i);
	}
	for (int i = 0; i < 10; i++) {
		cout << "���顾"<< i << "�� = " << array2.getData(i) <<endl;
	}

	array2.setData(1, 90);
	for (int i = 0; i < 10; i++) {
		cout << "���顾" << i << "�� = " << array2.getData(i) << endl;
	}
	cout << array2[0] << endl;
	array2[0] = 10;
	cout << array2[0] << endl;
}

int main() {
	test01();
	return 0;
}
