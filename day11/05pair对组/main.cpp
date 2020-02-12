#include <iostream>
#include <string>
using namespace std;

void test01(void) {
	//第一种创建方式
	pair<string, int> p("张三", 5);
	cout << "名字：" << p.first << endl;
	cout << "年龄：" << p.second << endl;

	//pair第二种创建方式
	pair<string, int> p2 = make_pair("李四", 80);
	cout << "名字：" << p2.first << endl;
	cout << "年龄：" << p2.second << endl;

}

int main() {
	test01();
	return 0;
}
