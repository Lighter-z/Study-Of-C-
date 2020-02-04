#include <iostream>

using namespace std;

void test01() {
	//int &ref = 10;  //报错 没有合法的内存空间
	const int &ref = 10;  //相当于 int temp = 10; const int &ref = temp;
//	ref = 10;  // 不能直接修改

	//只要有合法的内存空间就可以修改
	int *p = (int *)&ref;
	*p = 100;
	cout << ref << endl;

}

int main() {
	test01();


	return 0;
}
