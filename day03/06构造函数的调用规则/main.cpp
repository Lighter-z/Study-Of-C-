#include <iostream>

using namespace std;

//分类
//按照参数分类  无参构造函数（默认构造函数）  有参构造函数
//按照类型分类  普通构造函数    拷贝构造函数

class MyClass {
public:
	MyClass() {
		cout << "默认构造函数" << endl;
	}

	MyClass(int a) {
		cout << "有参构造函数" << endl;
	}

	//MyClass(const MyClass & my) {
	//	
	//}

	int a;

};

//系统会默认提供 默认构造  拷贝构造  析构函数

//1.当我们提供有参构造函数时候，系统不会再给我们提供构造函数  所以要写默认构造函数  不写就会报错
//但是系统会提供默认的拷贝构造函数，进行简单的值拷贝  
void test01() {
	MyClass c1;
	c1.a = 10;
	MyClass c2(c1);
	cout << "c2.a = " << c2.a << endl;
}

//2.当我们提供拷贝构造函数 系统不会提供其他函数   
//其他函数要自己写  不然会报错
class MyClass2 {
public:
	/*MyClass2() {
		cout << "默认构造函数" << endl;
	}

	MyClass2(int a) {
		cout << "有参构造函数" << endl;
	}*/

	MyClass2(const MyClass & my) {
		
	}

	int a;

};

void test02() {
	MyClass2 c2;
}

int main() {
	test01();
	return 0;
}

