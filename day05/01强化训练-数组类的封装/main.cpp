#include <iostream>
#include "MyArray.h"
using namespace std;

void test01(){
	//堆区创建数组
	MyArray * array = new MyArray(30);
	MyArray array2(*array);    //拷贝构造
	MyArray * array3 = new MyArray(*array);//拷贝构造
	MyArray array4 = *array;//拷贝构造

	//delete array;
	for (int i = 0; i < 10; i++) {
		array2.pushBack(i);
	}
	for (int i = 0; i < 10; i++) {
		cout << "数组【"<< i << "】 = " << array2.getData(i) <<endl;
	}

	array2.setData(1, 90);
	for (int i = 0; i < 10; i++) {
		cout << "数组【" << i << "】 = " << array2.getData(i) << endl;
	}
	cout << array2[0] << endl;
	array2[0] = 10;
	cout << array2[0] << endl;
}

int main() {
	test01();
	return 0;
}
