#include <iostream>

using namespace std;

class Person {
public:
	//构造函数写法：
	//与类名相同，没有返回值 不写void  可以发生重载（可以有参数）
	Person()  //构造函数由编译器自动调用  只调用一次
	{
		cout << "构造函数" << endl;
	}
	Person(int a)  //构造函数由编译器自动调用  只调用一次
	{
		cout << "构造函数 a = " << a << endl;
	}

	//析构函数
	//与类名相同 在类名前面加~   也没有返回值 不写void  不可以重载（不能有参数）
	~Person()  //析构函数由编译器自动调用  只调用一次     释放时候调用析构函数
	{
		cout << "析构函数" << endl;
	}
};

void test01() {
	Person p1;
	Person p2(2);
}

int main() {
	
	test01();
	return 0;
}

